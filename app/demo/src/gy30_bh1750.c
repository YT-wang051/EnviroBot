#include <stdio.h>
// --- 补充缺失的头文件 ---
#include "hi_i2c.h"
#include "hi_timer.h"
#include "hi_io.h"       // 解决 hi_io_set_func 隐式声明警告
#include "hi_gpio.h"     // 引入 GPIO 基础定义
#include "hi_task.h"     // 解决 hi_sleep 隐式声明警告
#include "gy30_bh1750.h"
#include "hi_time.h"     // 【新增】解决 hi_udelay 隐式声明警告
#include "hi_watchdog.h" // 【新增】解决 hi_watchdog_feed 隐式声明警告

#define BH1750_SLAVE_ADDR   0x23
#define BH1750_CON_H        0x10

hi_float g_gy30_light_lx = 52.0;
hi_u16 g_raw_value = 0;
hi_u8 g_gy30_init_flag = 0;

hi_void gy30_module_init(hi_void)
{
    // 初始化 I2C0
    hi_i2c_init(HI_I2C_IDX_0, 100000); 
    // 2. 给传感器上电后的稳定时间
    hi_sleep(100);
    g_gy30_init_flag = 1;
    printf("GY-30 Module Init Success!\r\n");
}

hi_void gy30_timer_callback(hi_u32 arg)
{
    hi_u32 ret;
    hi_u8 send_data = BH1750_CON_H;
    hi_u8 read_data[2] = {0};

    if (g_gy30_init_flag == 0) {
        return;
    }

    // --- 适配 hi_i2c_data 结构体写法 ---
    hi_i2c_data i2c_write_data = {0};
    i2c_write_data.send_buf = &send_data;
    i2c_write_data.send_len = 1;

    // 发送测量指令
    ret = hi_i2c_write(HI_I2C_IDX_0, BH1750_SLAVE_ADDR << 1, &i2c_write_data);
    if (ret != HI_ERR_SUCCESS) {
        printf("GY-30 write failed!\r\n");
        return;
    }

    // 延时等待测量完成
    hi_udelay(180 * 1000); 

    // 准备读取数据
    hi_i2c_data i2c_read_data = {0};
    i2c_read_data.receive_buf = read_data;
    i2c_read_data.receive_len = 2;

    // 读取数据 (注意：BH1750 读操作时，SDK底层通常会自动处理读写位，直接使用 7位地址左移即可)
    ret = hi_i2c_read(HI_I2C_IDX_0, BH1750_SLAVE_ADDR << 1, &i2c_read_data);
    if (ret != HI_ERR_SUCCESS) {
        printf("GY-30 read failed!\r\n");
        return;
    }

    // 数据合成与换算
    g_raw_value = (read_data[0] << 8) | read_data[1];
    g_gy30_light_lx = (hi_float)g_raw_value / 1.2f;
}

hi_void gy30_bh1750_task(hi_void)
{
    hi_u32 timer_id;
    
    gy30_module_init();

    // 创建并启动周期定时器
    hi_timer_create(&timer_id);
    hi_timer_start(timer_id, HI_TIMER_TYPE_PERIOD, 200, gy30_timer_callback, 0);

    while (1) {
        printf("当前光照强度: %.2f lx\r\n", g_gy30_light_lx);
        
        // 喂狗
        hi_watchdog_feed(); 
        
        // 适当休眠
        hi_sleep(500); 
    }

    hi_timer_delete(timer_id);
}