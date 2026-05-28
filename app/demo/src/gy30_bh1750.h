#ifndef __GY30_BH1750_H__
#define __GY30_BH1750_H__

#include <hi_types_base.h>

#ifdef __cplusplus
extern "C" {
#endif

// 声明全局变量，方便在其他地方获取光照数据
extern hi_float g_gy30_light_lx;

// 声明任务入口函数
hi_void gy30_bh1750_task(hi_void);

#ifdef __cplusplus
}
#endif
#endif