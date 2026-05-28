#include <stdio.h>
#include <unistd.h>
#include <hi_io.h>
#include <hi_gpio.h>
#include <hi_task.h>
#include "hi_i2c.h"
#include "hi_time.h"
#include "hi_watchdog.h"
#include "bme280.h"


static hi_u32 g_bme280_task_id = 0; 

hi_float g_temperature = 0.0; 
hi_float g_humidity = 0.0;
hi_float g_pressure = 0.0;


// BME280 校准参数结构体
typedef struct {
    hi_u16 dig_T1; hi_s16 dig_T2; hi_s16 dig_T3;
    hi_u16 dig_P1; hi_s16 dig_P2; hi_s16 dig_P3;
    hi_s16 dig_P4; hi_s16 dig_P5; hi_s16 dig_P6;
    hi_s16 dig_P7; hi_s16 dig_P8; hi_s16 dig_P9;
    hi_u8  dig_H1; hi_s16 dig_H2; hi_u8  dig_H3;
    hi_s16 dig_H4; hi_s16 dig_H5; hi_s8  dig_H6;
} bme280_calib_data;

static bme280_calib_data g_calib; // 存放读取到的校准系数
static hi_s32 g_t_fine = 0;       // 温度微细值，用于气压和湿度的补偿计算

// ==========================================
// 3. 底层 I2C 通信函数
// ==========================================

// 写一个字节到 BME280 寄存器
static hi_u32 bme280_write_byte(hi_u8 reg_addr, hi_u8 data) {
    hi_u32 status = 0;
    hi_i2c_data i2c_data = {0};
    hi_u8 send_buf[2] = {reg_addr, data};

    i2c_data.send_buf = send_buf;
    i2c_data.send_len = 2;
    
    status = hi_i2c_write(0, BME280_I2C_ADDR&0xFE, &i2c_data);
    return status;
}

// 读取一个字节
static hi_u32 bme280_read_byte(hi_u8 reg_addr, hi_u8 *data) {
    hi_u32 status = 0;
    hi_i2c_data i2c_data = {0};
    hi_u8 send_buf[1] = {reg_addr};

    // 步骤1: 发送寄存器地址
    i2c_data.send_buf = send_buf;
    i2c_data.send_len = 1;
    status = hi_i2c_write(0, BME280_I2C_ADDR&0xFE, &i2c_data);
    if (status != HI_ERR_SUCCESS) goto error;

    // 步骤2: 读取数据
    i2c_data.send_buf = HI_NULL;
    i2c_data.send_len = 0;
    i2c_data.receive_buf = data;
    i2c_data.receive_len = 1;
    status = hi_i2c_read(0, BME280_I2C_ADDR, &i2c_data);

error:
    return status;
}

// ==========================================
// 4. BME280 核心算法 (校准与补偿)
// ==========================================

// 读取 BME280 的校准参数
static void bme280_read_calibration(void) {
    hi_u8 buffer[32];
    // 连续读取温度与气压校准参数 (地址 0x88 ~ 0xA1)
    for (int i = 0; i < 24; i++) bme280_read_byte(0x88 + i, &buffer[i]);
    // 读取湿度校准参数第一段 (地址 0xA1)
    bme280_read_byte(0xA1, &buffer[24]);
    // 读取湿度校准参数第二段 (地址 0xE1 ~ 0xE7)
    for (int i = 0; i < 7; i++) bme280_read_byte(0xE1 + i, &buffer[25 + i]);

    // 将读取到的字节按官方手册拼接成校准参数
    g_calib.dig_T1 = (buffer[1] << 8) | buffer[0];
    g_calib.dig_T2 = (buffer[3] << 8) | buffer[2];
    g_calib.dig_T3 = (buffer[5] << 8) | buffer[4];
    g_calib.dig_P1 = (buffer[7] << 8) | buffer[6];
    g_calib.dig_P2 = (buffer[9] << 8) | buffer[8];
    g_calib.dig_P3 = (buffer[11] << 8) | buffer[10];
    g_calib.dig_P4 = (buffer[13] << 8) | buffer[12];
    g_calib.dig_P5 = (buffer[15] << 8) | buffer[14];
    g_calib.dig_P6 = (buffer[17] << 8) | buffer[16];
    g_calib.dig_P7 = (buffer[19] << 8) | buffer[18];
    g_calib.dig_P8 = (buffer[21] << 8) | buffer[20];
    g_calib.dig_P9 = (buffer[23] << 8) | buffer[22];
    g_calib.dig_H1 = buffer[24];
    g_calib.dig_H2 = (buffer[26] << 8) | buffer[25];
    g_calib.dig_H3 = buffer[27];
    g_calib.dig_H4 = (buffer[28] << 4) | (buffer[29] & 0x0F);
    g_calib.dig_H5 = (buffer[30] << 4) | ((buffer[29] >> 4) & 0x0F);
    g_calib.dig_H6 = (hi_s8)buffer[31];
}

// 补偿计算真实温度 (单位: 摄氏度)
static float bme280_compensate_temperature(hi_s32 adc_T) {
    hi_s32 var1, var2;
    var1 = ((((adc_T >> 3) - ((hi_s32)g_calib.dig_T1 << 1))) * ((hi_s32)g_calib.dig_T2)) >> 11;
    var2 = (((((adc_T >> 4) - ((hi_s32)g_calib.dig_T1)) * ((adc_T >> 4) - ((hi_s32)g_calib.dig_T1))) >> 12) * ((hi_s32)g_calib.dig_T3)) >> 14;
    g_t_fine = var1 + var2;
    return ((g_t_fine * 5 + 128) >> 8) / 100.0f;
}

// 补偿计算真实气压 (单位: hPa)
static float bme280_compensate_pressure(hi_s32 adc_P) {
    hi_s64 var1, var2, p;
    var1 = ((hi_s64)g_t_fine) - 128000;
    var2 = var1 * var1 * (hi_s64)g_calib.dig_P6;
    var2 = var2 + ((var1 * (hi_s64)g_calib.dig_P5) << 17);
    var2 = var2 + (((hi_s64)g_calib.dig_P4) << 35);
    var1 = ((var1 * var1 * (hi_s64)g_calib.dig_P3) >> 8) + ((var1 * (hi_s64)g_calib.dig_P2) << 12);
    var1 = (((((hi_s64)1) << 47) + var1)) * ((hi_s64)g_calib.dig_P1) >> 33;
    if (var1 == 0) return 0;
    p = 1048576 - adc_P;
    p = (((p << 31) - var2) * 3125) / var1;
    var1 = (((hi_s64)g_calib.dig_P9) * (p >> 13) * (p >> 13)) >> 25;
    var2 = (((hi_s64)g_calib.dig_P8) * p) >> 19;
    p = ((p + var1 + var2) >> 8) + (((hi_s64)g_calib.dig_P7) << 4);
    return (float)p / 256.0f;
}

// 补偿计算真实湿度 (单位: %RH)
static float bme280_compensate_humidity(hi_s32 adc_H) {
    hi_s32 v_x1_u32r;
    v_x1_u32r = (g_t_fine - ((hi_s32)76800));
    v_x1_u32r = (((((adc_H << 14) - (((hi_s32)g_calib.dig_H4) << 20) - (((hi_s32)g_calib.dig_H5) * v_x1_u32r)) +
                  ((hi_s32)16384)) >> 15) * (((((((v_x1_u32r * ((hi_s32)g_calib.dig_H6)) >> 10) *
                  (((v_x1_u32r * ((hi_s32)g_calib.dig_H3)) >> 11) + ((hi_s32)32768))) >> 10) + ((hi_s32)2097152)) *
                  ((hi_s32)g_calib.dig_H2) + 8192) >> 14));
    v_x1_u32r = (v_x1_u32r - (((((v_x1_u32r >> 15) * (v_x1_u32r >> 15)) >> 7) * ((hi_s32)g_calib.dig_H1)) >> 4));
    v_x1_u32r = (v_x1_u32r < 0 ? 0 : v_x1_u32r);
    v_x1_u32r = (v_x1_u32r > 419430400 ? 419430400 : v_x1_u32r);
    return (float)(v_x1_u32r >> 12) / 1024.0f;
}

// ==========================================
// 5. 任务入口函数 (Worker)
// ==========================================
hi_void *app_i2c_bme280_task(hi_void* param) {
    hi_u8 chip_id = 0;
    hi_u32 ret = 0;

    printf("[BME280] Task Started...\n");


    hi_i2c_init(0, 400000);
    hi_i2c_set_baudrate(0, 400000);

    // --- BME280 自检 ---
    ret = bme280_read_byte(0xD0, &chip_id);
    if (ret == 0 && chip_id == 0x60) {
        printf("[BME280] Found! Chip ID: 0x%02X\n", chip_id);
    } else {
        printf("[BME280] Not Found! Check Wiring. ID:0x%02X\n", chip_id);
        return HI_NULL;
    }

    // --- 读取校准参数 (只需执行一次) ---
    bme280_read_calibration();
    printf("[BME280] Calibration data loaded.\n");

    // --- 配置 BME280 为正常测量模式 (Normal Mode) ---
    bme280_write_byte(0xF2, 0x01); // 湿度过采样 x1
    bme280_write_byte(0xF4, 0x27); // 温压过采样 x1，开启正常模式
    bme280_write_byte(0xF5, 0x00); // 滤波系数和待机时间

    // --- 主循环 ---
        // --- 主循环 ---
    while (1) {
        hi_watchdog_feed(); // 喂狗
        
        hi_u8 raw_data[8] = {0}; // 存放读取到的原始数据
        hi_i2c_data i2c_data = {0};
        hi_u8 reg_addr = 0xF7; // BME280 数据起始寄存器地址

        i2c_data.send_buf = &reg_addr;
        i2c_data.send_len = 1;
        ret = hi_i2c_write(0, BME280_I2C_ADDR, &i2c_data);
        
        if (ret == HI_ERR_SUCCESS) {
            i2c_data.send_buf = HI_NULL;
            i2c_data.send_len = 0;
            i2c_data.receive_buf = raw_data;
            i2c_data.receive_len = 8; 
            ret = hi_i2c_read(0, BME280_I2C_ADDR, &i2c_data);
            
            if (ret == HI_ERR_SUCCESS) {

                hi_s32 adc_P = (hi_s32)(((hi_u32)(raw_data[0]) << 12) | ((hi_u32)(raw_data[1]) << 4) | (raw_data[2] >> 4));
                hi_s32 adc_T = (hi_s32)(((hi_u32)(raw_data[3]) << 12) | ((hi_u32)(raw_data[4]) << 4) | (raw_data[5] >> 4));
                hi_s32 adc_H = (hi_s32)(((hi_u32)(raw_data[6]) << 8) | (hi_u32)(raw_data[7]));

                g_temperature = bme280_compensate_temperature(adc_T);
                g_pressure = bme280_compensate_pressure(adc_P);
                g_humidity = bme280_compensate_humidity(adc_H);

                printf("[BME280] Real Data -> Temp: %.2f C, Hum: %.2f %%, Pres: %.2f hPa\n", 
                       g_temperature, g_humidity, g_pressure);
            } else {
                printf("[BME280] I2C Read Failed!\n");
            }
        } else {
            printf("[BME280] I2C Write Failed!\n");
        }

        hi_sleep(2000); 
    }

    return HI_NULL;
}

// ==========================================
// 6. 任务创建接口 (Creator)
// ==========================================
hi_u32 app_bme280_task(void) {
    hi_u32 ret;
    hi_task_attr attr = {0};

    hi_task_lock();

    attr.stack_size = BME280_TASK_STACK_SIZE;
    attr.task_prio = BME280_TASK_PRIORITY;
    attr.task_name = (hi_char*)BME280_TASK_NAME;

    ret = hi_task_create(&g_bme280_task_id, &attr, app_i2c_bme280_task, HI_NULL);

    if (ret != HI_ERR_SUCCESS) {
        printf("Failed to create BME280 Task!\n");
    } else {
        printf("BME280 Task Created Successfully!\n");
    }

    hi_task_unlock();
    return ret;
}