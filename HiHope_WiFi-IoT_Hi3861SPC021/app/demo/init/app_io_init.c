/*
 * Copyright (c) 2020 HiHope Community.
 * Description: app io config.
 * Author: HiSpark Product Team.
 * Create: 2019-06-28
 */

#include <hi_io.h>
#include <hi_gpio.h>
#include <hi_pwm.h>

hi_void app_io_init(hi_void)
{
    /* uart0 ���Դ��� */
    hi_io_set_func(HI_IO_NAME_GPIO_3, HI_IO_FUNC_GPIO_3_UART0_TXD); /* uart0 tx */
    hi_io_set_func(HI_IO_NAME_GPIO_4, HI_IO_FUNC_GPIO_4_UART0_RXD); /* uart0 rx */


    /* uart1 AT����� */
    hi_io_set_func(HI_IO_NAME_GPIO_5, HI_IO_FUNC_GPIO_5_UART1_RXD); /* uart1 rx */
    hi_io_set_func(HI_IO_NAME_GPIO_6, HI_IO_FUNC_GPIO_6_UART1_TXD); /* uart1 tx */                              

    /* i2c0 */
    hi_io_set_func(HI_IO_NAME_GPIO_13, HI_IO_FUNC_GPIO_13_I2C0_SDA); /* i2c0 sda */
    hi_io_set_func(HI_IO_NAME_GPIO_14, HI_IO_FUNC_GPIO_14_I2C0_SCL); /* i2c0 scl */       

    /*���gpio��ʼ��*/
    hi_io_set_func(HI_IO_NAME_GPIO_2, HI_IO_FUNC_GPIO_2_GPIO);
    hi_gpio_set_dir(HI_GPIO_IDX_2, HI_GPIO_DIR_OUT);

    /*����A���ת�ٵ�PWM����*/
    hi_io_set_func(HI_IO_NAME_GPIO_0, HI_IO_FUNC_GPIO_0_PWM3_OUT);
    hi_pwm_init(HI_PWM_PORT_PWM3);
    hi_pwm_set_clock(PWM_CLK_160M);
    hi_pwm_start(HI_PWM_PORT_PWM3, 0, 60000);

    /*���Ƶ��A�ķ���*/
    hi_io_set_func(HI_IO_NAME_GPIO_1, HI_IO_FUNC_GPIO_1_GPIO);
    hi_gpio_set_dir(HI_GPIO_IDX_1,HI_GPIO_DIR_OUT);
    hi_gpio_set_ouput_val(HI_GPIO_IDX_1, HI_GPIO_VALUE0);
    
    /*������trig�ڣ�����Ϊ���ģʽ*/
    hi_io_set_func(HI_IO_NAME_GPIO_7, HI_IO_FUNC_GPIO_7_GPIO);
    hi_gpio_set_dir(HI_GPIO_IDX_7, HI_GPIO_DIR_OUT);
    hi_gpio_set_ouput_val(HI_GPIO_IDX_7, HI_GPIO_VALUE0);

    /*������echo�ڣ�������Ϊ���ģʽ����������Ϊ����ģʽ*/
    hi_io_set_func(HI_IO_NAME_GPIO_8, HI_IO_FUNC_GPIO_8_GPIO);
    hi_gpio_set_dir(HI_GPIO_IDX_8, HI_GPIO_DIR_OUT);
    hi_gpio_set_ouput_val(HI_GPIO_IDX_8, HI_GPIO_VALUE0);

    /*���Ƶ��Bת�ٵ�PWM����*/
    hi_io_set_func(HI_IO_NAME_GPIO_9, HI_IO_FUNC_GPIO_9_GPIO);
    hi_gpio_set_dir(HI_GPIO_IDX_9, HI_GPIO_DIR_OUT);
    hi_gpio_set_ouput_val(HI_GPIO_IDX_9, HI_GPIO_VALUE0);

    /*���Ƶ��B�ķ���*/
    hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_FUNC_GPIO_10_GPIO);
    hi_gpio_set_dir(HI_GPIO_IDX_10, HI_GPIO_DIR_OUT);
    hi_gpio_set_ouput_val(HI_GPIO_IDX_10, HI_GPIO_VALUE0);
    
    /* �û������Ӧ�ó���������ѡ��������IO�������ã��˴����г�ʾ�� */

#ifdef CONFIG_UART0_SUPPORT
    /* uart0 ���Դ��� */
    hi_io_set_func(HI_IO_NAME_GPIO_3, HI_IO_FUNC_GPIO_3_UART0_TXD); /* uart0 tx */
    hi_io_set_func(HI_IO_NAME_GPIO_4, HI_IO_FUNC_GPIO_4_UART0_RXD); /* uart0 rx */
#endif

#ifdef CONFIG_UART1_SUPPORT
    /* uart1 AT����� */
    hi_io_set_func(HI_IO_NAME_GPIO_5, HI_IO_FUNC_GPIO_5_UART1_RXD); /* uart1 rx */
    hi_io_set_func(HI_IO_NAME_GPIO_6, HI_IO_FUNC_GPIO_6_UART1_TXD); /* uart1 tx */
#endif

#ifdef CONFIG_UART2_SUPPORT
    /* uart2 sigma��֤ʹ�ô��� */
    hi_io_set_func(HI_IO_NAME_GPIO_11, HI_IO_FUNC_GPIO_11_UART2_TXD); /* uart2 tx */
    hi_io_set_func(HI_IO_NAME_GPIO_12, HI_IO_FUNC_GPIO_12_UART2_RXD); /* uart2 rx */
#endif

    /* SPI MUX: */
#ifdef CONFIG_SPI_SUPPORT
    /* SPI IO����Ҳ����ѡ��5/6/7/8;0/1/2/3, ���ݲ�Ʒ���ѡ�� */
    hi_io_set_func(HI_IO_NAME_GPIO_9, HI_IO_FUNC_GPIO_9_SPI0_TXD);
    hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_FUNC_GPIO_10_SPI0_CK);
    hi_io_set_func(HI_IO_NAME_GPIO_11, HI_IO_FUNC_GPIO_11_SPI0_RXD);
    hi_io_set_func(HI_IO_NAME_GPIO_12, HI_IO_FUNC_GPIO_12_SPI0_CSN);
    hi_io_set_driver_strength(HI_IO_NAME_GPIO_9, HI_IO_DRIVER_STRENGTH_0);
#endif

    /* I2C MUX: */
//#ifdef CONFIG_I2C_SUPPORT
    /* I2C IO����Ҳ����ѡ��3/4; 9/10�����ݲ�Ʒ���ѡ�� */
    //hi_io_set_func(HI_IO_NAME_GPIO_0, HI_IO_FUNC_GPIO_0_I2C1_SDA);
    //hi_io_set_func(HI_IO_NAME_GPIO_1, HI_IO_FUNC_GPIO_1_I2C1_SCL);
//#endif

    /* PWM MUX: */
#ifdef CONFIG_PWM_SUPPORT
    /* PWM 0/2/3/4/5 ����ͬ�� */
    hi_io_set_func(HI_IO_NAME_GPIO_8, HI_IO_FUNC_GPIO_8_PWM1_OUT);
#endif

    /* I2S MUX: */
#ifdef CONFIG_I2S_SUPPORT
    hi_io_set_func(HI_IO_NAME_GPIO_9, HI_IO_FUNC_GPIO_9_I2S0_MCLK);
    hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_FUNC_GPIO_10_I2S0_TX);
    hi_io_set_func(HI_IO_NAME_GPIO_11, HI_IO_FUNC_GPIO_11_I2S0_RX);
    hi_io_set_func(HI_IO_NAME_GPIO_12, HI_IO_FUNC_GPIO_12_I2S0_BCLK);
    hi_io_set_func(HI_IO_NAME_GPIO_13, HI_IO_FUNC_GPIO_13_I2S0_WS);
#endif

    /* SDIO MUX: */
#ifdef CONFIG_SDIO_SUPPORT
    (hi_void)hi_io_set_func(HI_IO_NAME_GPIO_9, HI_IO_FUNC_GPIO_9_SDIO_D2);
    (hi_void)hi_io_set_func(HI_IO_NAME_GPIO_10, HI_IO_FUNC_GPIO_10_SDIO_D3);
    (hi_void)hi_io_set_func(HI_IO_NAME_GPIO_11, HI_IO_FUNC_GPIO_11_SDIO_CMD);
    (hi_void)hi_io_set_func(HI_IO_NAME_GPIO_12, HI_IO_FUNC_GPIO_12_SDIO_CLK);
    (hi_void)hi_io_set_func(HI_IO_NAME_GPIO_13, HI_IO_FUNC_GPIO_13_SDIO_D0);
    (hi_void)hi_io_set_func(HI_IO_NAME_GPIO_14, HI_IO_FUNC_GPIO_14_SDIO_D1);

    (hi_void)hi_io_set_pull(HI_IO_NAME_GPIO_9, HI_IO_PULL_UP);
    (hi_void)hi_io_set_pull(HI_IO_NAME_GPIO_10, HI_IO_PULL_UP);
    (hi_void)hi_io_set_pull(HI_IO_NAME_GPIO_11, HI_IO_PULL_UP);
    (hi_void)hi_io_set_pull(HI_IO_NAME_GPIO_13, HI_IO_PULL_UP);
    (hi_void)hi_io_set_pull(HI_IO_NAME_GPIO_14, HI_IO_PULL_UP);
#endif
}

