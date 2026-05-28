#include <trace_module.h>
#include <hi_timer.h>
extern hi_u8   g_car_control_mode;
extern hi_u8   g_led_control_module;
extern hi_u16  g_car_modular_control_module;
extern hi_u16  g_car_direction_control_module;

extern hi_void  car_stop(hi_void);
extern hi_float car_get_distance(hi_void);

#define car_speed_left 10
#define car_speed_right 10

hi_u32 g_car_speed_left = car_speed_left;
hi_u32 g_car_speed_right = car_speed_right;
hi_float distance=1000;
hi_u8 count = 0;
hi_u8 flag = 0;
hi_gpio_value io_status_left;
hi_gpio_value io_status_right;



/*
init gpio11/12 as a input io
GPIO 11 connects the left tracking module
GPIO 11 connects the right tracking module
*/
hi_void trace_module_init(hi_void)
{
    gpio_control(HI_IO_NAME_GPIO_0, HI_GPIO_IDX_0, HI_GPIO_DIR_OUT, HI_GPIO_VALUE1, HI_IO_FUNC_GPIO_0_GPIO);
    pwm_control(HI_IO_NAME_GPIO_1,HI_IO_FUNC_GPIO_1_PWM4_OUT,HI_PWM_PORT_PWM4, g_car_speed_left);
    gpio_control(HI_IO_NAME_GPIO_9, HI_GPIO_IDX_9, HI_GPIO_DIR_OUT, HI_GPIO_VALUE1, HI_IO_FUNC_GPIO_9_GPIO);
    pwm_control(HI_IO_NAME_GPIO_10,HI_IO_FUNC_GPIO_10_PWM1_OUT,HI_PWM_PORT_PWM1, g_car_speed_right);
}
hi_void timer1_callback(hi_u32 arg)
{
    hi_gpio_value io_status;
    if(g_car_speed_left != car_speed_left)   
    {
        count++;
        if(count >=2)
        {
            hi_gpio_get_input_val(HI_GPIO_IDX_11,&io_status);
            if(io_status != HI_GPIO_VALUE0){
                g_car_speed_left = car_speed_left;
                count = 0;
            }
        }

    }

    if(g_car_speed_right != car_speed_right)   
    {
        count++;
        if(count >=2)
        {
            hi_gpio_get_input_val(HI_GPIO_IDX_12,&io_status);
            if(io_status != HI_GPIO_VALUE0){
                g_car_speed_right = car_speed_right;
                count = 0;
            }
        }
    }
    if(g_car_speed_left != car_speed_left && g_car_speed_right != car_speed_right)
    {
        g_car_speed_left = car_speed_left;
        g_car_speed_right = car_speed_right;
    }
    hi_gpio_get_input_val(HI_GPIO_IDX_11,&io_status_left);
    hi_gpio_get_input_val(HI_GPIO_IDX_12,&io_status_right);
    if(io_status_right == HI_GPIO_VALUE0 && io_status_left != HI_GPIO_VALUE0)
    {
        g_car_speed_left = car_speed_left;
        g_car_speed_right = 1500;
    } 
    if(io_status_right != HI_GPIO_VALUE0 && io_status_left == HI_GPIO_VALUE0)
    {
        g_car_speed_left = 1500;
        g_car_speed_right = car_speed_right;
    }
    if(io_status_right == HI_GPIO_VALUE0 && io_status_left == HI_GPIO_VALUE0){
        g_car_speed_left = car_speed_left;
        g_car_speed_right = car_speed_right;
    }
    if(distance< 20 ){
        if (flag==0){
            pwm_control(HI_IO_NAME_GPIO_0,HI_IO_FUNC_GPIO_0_PWM3_OUT,HI_PWM_PORT_PWM3, 0); 
            gpio_control(HI_IO_NAME_GPIO_1, HI_GPIO_IDX_1, HI_GPIO_DIR_OUT, HI_GPIO_VALUE0, HI_IO_FUNC_GPIO_1_GPIO);
            pwm_control(HI_IO_NAME_GPIO_9,HI_IO_FUNC_GPIO_9_PWM0_OUT,HI_PWM_PORT_PWM0, 0);
            gpio_control(HI_IO_NAME_GPIO_10, HI_GPIO_IDX_10, HI_GPIO_DIR_OUT, HI_GPIO_VALUE0, HI_IO_FUNC_GPIO_10_GPIO);
            flag=1;
        }
    }else{
        if (flag==1){
            trace_module_init();
            flag=0;
        }
    }
}

hi_void timer2_callback(hi_u32 arg){
    distance = car_get_distance();
}

hi_void  trace_module(hi_void)
{

    hi_u8 current_car_modular_control_module = g_car_modular_control_module;
    hi_u8 current_car_control_mode = g_car_control_mode;
    hi_gpio_value m_left_value  = HI_GPIO_VALUE0;
    hi_gpio_value m_right_value = HI_GPIO_VALUE0;
    
    hi_u32 timer_id1;
    hi_timer_create(&timer_id1);
    hi_timer_start(timer_id1, HI_TIMER_TYPE_PERIOD, 2, timer1_callback, 0);
    hi_u32 timer_id2;
    hi_timer_create(&timer_id2);
    hi_timer_start(timer_id2, HI_TIMER_TYPE_PERIOD, 50, timer2_callback, 0);
    trace_module_init();
    while (1) {
        if ((current_car_modular_control_module != g_car_modular_control_module)
             || (current_car_control_mode != g_car_control_mode)) {
            break;
        }
        hi_pwm_start(HI_PWM_PORT_PWM4, g_car_speed_left, 1500);
        hi_pwm_start(HI_PWM_PORT_PWM1, g_car_speed_right, 1500);
        hi_udelay(2);
    }
    hi_timer_delete(timer_id1);
    hi_timer_delete(timer_id2);
}