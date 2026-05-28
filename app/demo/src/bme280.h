#ifndef BME280_H
#define BME280_H

#include <hi_types.h>

// BME280 I2C 地址
#define BME280_I2C_ADDR         0x76 << 1  // 如果ADDR引脚接VCC则改为0x77

// 任务配置
#define BME280_TASK_STACK_SIZE  4096
#define BME280_TASK_PRIORITY    25
#define BME280_TASK_NAME        "BME280_Task"

// 全局变量（供外部访问）
extern hi_float g_temperature;
extern hi_float g_humidity;
extern hi_float g_pressure;

// 函数声明

hi_u32 app_bme280_task(hi_void);

#endif // BME280_H