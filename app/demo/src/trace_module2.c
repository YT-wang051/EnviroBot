#include <trace_module2.h>
#include <hi_timer.h>
extern hi_u8   g_car_control_mode;
extern hi_u8   g_led_control_module;
extern hi_u16  g_car_modular_control_module;
extern hi_u16  g_car_direction_control_module;

extern hi_void  car_stop(hi_void);
extern hi_float car_get_distance(hi_void);
extern hi_void  car_go_back(hi_void);
extern hi_void  car_turn_left(hi_void);
extern hi_void  car_turn_right(hi_void);
extern hi_void  car_go_forward(hi_void);




#define car_speed_left2 100
#define car_speed_right2 100

hi_u32 g_car_speed_left2 = car_speed_left2;
hi_u32 g_car_speed_right2 = car_speed_right2;
hi_float distance2=1000;
hi_u8 count2 = 0;
hi_u8 flag2 = 0;
hi_u8 dis = 1;
hi_u8 xian = 1;
hi_gpio_value io_status_left2;
hi_gpio_value io_status_right2;



/*
init gpio11/12 as a input io
GPIO 11 connects the left tracking module
GPIO 11 connects the right tracking module
*/
hi_void trace_module_init2(hi_void)
{
    gpio_control(HI_IO_NAME_GPIO_0, HI_GPIO_IDX_0, HI_GPIO_DIR_OUT, HI_GPIO_VALUE1, HI_IO_FUNC_GPIO_0_GPIO);
    pwm_control(HI_IO_NAME_GPIO_1,HI_IO_FUNC_GPIO_1_PWM4_OUT,HI_PWM_PORT_PWM4, g_car_speed_left2);
    gpio_control(HI_IO_NAME_GPIO_9, HI_GPIO_IDX_9, HI_GPIO_DIR_OUT, HI_GPIO_VALUE1, HI_IO_FUNC_GPIO_9_GPIO);
    pwm_control(HI_IO_NAME_GPIO_10,HI_IO_FUNC_GPIO_10_PWM1_OUT,HI_PWM_PORT_PWM1, g_car_speed_right2);
    hi_u32 g_car_speed_left2 = car_speed_left2;
    hi_u32 g_car_speed_right2 = car_speed_right2;
}
hi_void timer3_callback(hi_u32 arg)
{
    hi_gpio_value io_status2;
    if(g_car_speed_left2 != car_speed_left2)   
    {
        count2++;
        if(count2 >=2)
        {
            hi_gpio_get_input_val(HI_GPIO_IDX_11,&io_status2);
            if(io_status2 != HI_GPIO_VALUE0){
                g_car_speed_left2 = car_speed_left2;
                printf("left speed change \r\n");
                count2 = 0;
            }
        }

    }

    if(g_car_speed_right2 != car_speed_right2)   
    {
        count2++;
        if(count2 >=2)
        {
            hi_gpio_get_input_val(HI_GPIO_IDX_12,&io_status2);
            if(io_status2 != HI_GPIO_VALUE0){
                g_car_speed_right2 = car_speed_right2;
                printf("right speed change \r\n");
                count2 = 0;
            }
        }
    }
    if(g_car_speed_left2 != car_speed_left2 && g_car_speed_right2 != car_speed_right2)
    {
        g_car_speed_left2 = car_speed_left2;
        g_car_speed_right2 = car_speed_right2;
    }
    hi_gpio_get_input_val(HI_GPIO_IDX_11,&io_status_left2);
    hi_gpio_get_input_val(HI_GPIO_IDX_12,&io_status_right2);
    if(io_status_right2 == HI_GPIO_VALUE0 && io_status_left2 != HI_GPIO_VALUE0)
    {
        g_car_speed_left2 = car_speed_left2;
        g_car_speed_right2 = 700;
    } 
    if(io_status_right2 != HI_GPIO_VALUE0 && io_status_left2 == HI_GPIO_VALUE0)
    {
        g_car_speed_left2 = 700;
        g_car_speed_right2 = car_speed_right2;
    }
    if(distance2 < 20 ){
        if(io_status_right2 == HI_GPIO_VALUE0 && io_status_left2 == HI_GPIO_VALUE0){
            xian=0;
        }
        else
        {
            xian=1;
        }
        
        dis=0;
    }
    else
    {
        dis=1;
    }

}
hi_void timer4_callback(hi_u32 arg){
    distance2 = car_get_distance();   
}

hi_void  trace_module2(hi_void)
{

    hi_u8 current_car_modular_control_module2 = g_car_modular_control_module;
    hi_u8 current_car_control_mode2 = g_car_control_mode;
    hi_gpio_value m_left_value2  = HI_GPIO_VALUE0;
    hi_gpio_value m_right_value2 = HI_GPIO_VALUE0;
    
    hi_u32 timer_id3;
    hi_timer_create(&timer_id3);
    hi_timer_start(timer_id3, HI_TIMER_TYPE_PERIOD, 2, timer3_callback, 0);
    hi_u32 timer_id4;
    hi_timer_create(&timer_id4);
    hi_timer_start(timer_id4, HI_TIMER_TYPE_PERIOD, 50, timer4_callback, 0);
    trace_module_init();
    while (1) {
        if ((current_car_modular_control_module2 != g_car_modular_control_module)
             || (current_car_control_mode2 != g_car_control_mode)) {
            break;
        }
        if(dis==0){
            car_stop();
            car_go_back();
            hi_sleep(750);
            car_stop();
            if(xian==0){
                car_turn_left();
            }else{
                car_turn_right();
            }
            hi_sleep(750);
            car_stop();
            hi_watchdog_feed();
            hi_sleep(20);
            trace_module_init2();
        }else{
            hi_pwm_start(HI_PWM_PORT_PWM4, g_car_speed_left2, 700);
            hi_pwm_start(HI_PWM_PORT_PWM1, g_car_speed_right2, 700);
            hi_udelay(2);
        }
    }
    hi_timer_delete(timer_id3);
    hi_timer_delete(timer_id4);
}