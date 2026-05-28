/**
* @file hi_io.h
*
* Copyright (c) Hisilicon Technologies Co., Ltd. 2019-2019. All rights reserved.  \n
* Description: I/O configuration.  \n
* Author: Hisilicon  \n
* Create: 2019-07-13
*/

/**
 * @defgroup iot_io IO
 * @ingroup drivers
 */

#ifndef __HI_IO_H__
#define __HI_IO_H__

#include <hi_types_base.h>

/**
 * @ingroup iot_io
 *
 * GPIO pin ID. CNcomment:IOӲ���ܽű�š�CNend
 */
typedef enum {
    HI_IO_NAME_GPIO_0,     /**< GPIO0 */
    HI_IO_NAME_GPIO_1,     /**< GPIO1 */
    HI_IO_NAME_GPIO_2,     /**< GPIO2 */
    HI_IO_NAME_GPIO_3,     /**< GPIO3 */
    HI_IO_NAME_GPIO_4,     /**< GPIO4 */
    HI_IO_NAME_GPIO_5,     /**< GPIO5 */
    HI_IO_NAME_GPIO_6,     /**< GPIO6 */
    HI_IO_NAME_GPIO_7,     /**< GPIO7 */
    HI_IO_NAME_GPIO_8,     /**< GPIO8 */
    HI_IO_NAME_GPIO_9,     /**< GPIO9 */
    HI_IO_NAME_GPIO_10,    /**< GPIO10 */
    HI_IO_NAME_GPIO_11,    /**< GPIO11 */
    HI_IO_NAME_GPIO_12,    /**< GPIO12 */
    HI_IO_NAME_GPIO_13,    /**< GPIO13 */
    HI_IO_NAME_GPIO_14,    /**< GPIO14 */
    HI_IO_NAME_SFC_CSN,    /**< SFC_CSN */
    HI_IO_NAME_SFC_IO1,    /**< SFC_IO1 */
    HI_IO_NAME_SFC_IO2,    /**< SFC_IO2 */
    HI_IO_NAME_SFC_IO0,    /**< SFC_IO0 */
    HI_IO_NAME_SFC_CLK,    /**< SFC_CLK */
    HI_IO_NAME_SFC_IO3,    /**< SFC_IO3 */
    HI_IO_NAME_MAX,
} hi_io_name;

/**
 * @ingroup iot_io
 *
 * GPIO_0 pin function.CNcomment:GPIO_0�ܽŹ��ܡ�CNend
 */
typedef enum {
    HI_IO_FUNC_GPIO_0_GPIO,
    HI_IO_FUNC_GPIO_0_UART1_TXD = 2,
    HI_IO_FUNC_GPIO_0_SPI1_CK,
    HI_IO_FUNC_GPIO_0_JTAG_TDO,
    HI_IO_FUNC_GPIO_0_PWM3_OUT,
    HI_IO_FUNC_GPIO_0_I2C1_SDA,
} hi_io_func_gpio_0;

/**
* @ingroup iot_io
*
* GPIO_1 pin function.CNcomment:GPIO_1�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_1_GPIO,
    HI_IO_FUNC_GPIO_1_UART1_RXD = 2,
    HI_IO_FUNC_GPIO_1_SPI1_RXD,
    HI_IO_FUNC_GPIO_1_JTAG_TCK,
    HI_IO_FUNC_GPIO_1_PWM4_OUT,
    HI_IO_FUNC_GPIO_1_I2C1_SCL,
    HI_IO_FUNC_GPIO_1_BT_FREQ,
} hi_io_func_gpio_1;

/**
* @ingroup iot_io
*
* GPIO_2 pin function.CNcomment:GPIO_2�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_2_GPIO,
    HI_IO_FUNC_GPIO_2_UART1_RTS_N = 2,
    HI_IO_FUNC_GPIO_2_SPI1_TXD,
    HI_IO_FUNC_GPIO_2_JTAG_TRSTN,
    HI_IO_FUNC_GPIO_2_PWM2_OUT,
    HI_IO_FUNC_GPIO_2_SSI_CLK = 7,
} hi_io_func_gpio_2;

/**
* @ingroup iot_io
*
* GPIO_3 pin function.CNcomment:GPIO_3�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_3_GPIO,
    HI_IO_FUNC_GPIO_3_UART0_TXD,
    HI_IO_FUNC_GPIO_3_UART1_CTS_N,
    HI_IO_FUNC_GPIO_3_SPI1_CSN,
    HI_IO_FUNC_GPIO_3_JTAG_TDI,
    HI_IO_FUNC_GPIO_3_PWM5_OUT,
    HI_IO_FUNC_GPIO_3_I2C1_SDA,
    HI_IO_FUNC_GPIO_3_SSI_DATA,
} hi_io_func_gpio_3;

/**
* @ingroup iot_io
*
* GPIO_4 pin function.CNcomment:GPIO_4�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_4_GPIO,
    HI_IO_FUNC_GPIO_4_UART0_RXD = 2,
    HI_IO_FUNC_GPIO_4_JTAG_TMS = 4,
    HI_IO_FUNC_GPIO_4_PWM1_OUT,
    HI_IO_FUNC_GPIO_4_I2C1_SCL,
} hi_io_func_gpio_4;

/**
* @ingroup iot_io
*
* GPIO_5 pin function.CNcomment:GPIO_5�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_5_GPIO,
    HI_IO_FUNC_GPIO_5_UART1_RXD = 2,
    HI_IO_FUNC_GPIO_5_SPI0_CSN,
    HI_IO_FUNC_GPIO_5_PWM2_OUT = 5,
    HI_IO_FUNC_GPIO_5_I2S0_MCLK,
    HI_IO_FUNC_GPIO_5_BT_STATUS,
} hi_io_func_gpio_5;

/**
* @ingroup iot_io
*
* GPIO_6 pin function.CNcomment:GPIO_6�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_6_GPIO,
    HI_IO_FUNC_GPIO_6_UART1_TXD = 2,
    HI_IO_FUNC_GPIO_6_SPI0_CK,
    HI_IO_FUNC_GPIO_6_PWM3_OUT = 5,
    HI_IO_FUNC_GPIO_6_I2S0_TX,
    HI_IO_FUNC_GPIO_6_COEX_SWITCH,
} hi_io_func_gpio_6;

/**
* @ingroup iot_io
*
* GPIO_7 pin function.CNcomment:GPIO_7�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_7_GPIO,
    HI_IO_FUNC_GPIO_7_UART1_CTS_N = 2,
    HI_IO_FUNC_GPIO_7_SPI0_RXD,
    HI_IO_FUNC_GPIO_7_PWM0_OUT = 5,
    HI_IO_FUNC_GPIO_7_I2S0_BCLK,
    HI_IO_FUNC_GPIO_7_BT_ACTIVE,
} hi_io_func_gpio_7;

/**
* @ingroup iot_io
*
* GPIO_8 pin function.CNcomment:GPIO_8�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_8_GPIO,
    HI_IO_FUNC_GPIO_8_UART1_RTS_N = 2,
    HI_IO_FUNC_GPIO_8_SPI0_TXD,
    HI_IO_FUNC_GPIO_8_PWM1_OUT = 5,
    HI_IO_FUNC_GPIO_8_I2S0_WS,
    HI_IO_FUNC_GPIO_8_WLAN_ACTIVE,
} hi_io_func_gpio_8;

/**
* @ingroup iot_io
*
* GPIO_9 pin function.CNcomment:GPIO_9�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_9_GPIO,
    HI_IO_FUNC_GPIO_9_I2C0_SCL,
    HI_IO_FUNC_GPIO_9_UART2_RTS_N,
    HI_IO_FUNC_GPIO_9_SDIO_D2,
    HI_IO_FUNC_GPIO_9_SPI0_TXD,
    HI_IO_FUNC_GPIO_9_PWM0_OUT,
    HI_IO_FUNC_GPIO_9_I2S0_MCLK = 7,
} hi_io_func_gpio_9;

/**
* @ingroup iot_io
*
* GPIO_10 pin function.CNcomment:GPIO_10�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_10_GPIO,
    HI_IO_FUNC_GPIO_10_I2C0_SDA,
    HI_IO_FUNC_GPIO_10_UART2_CTS_N,
    HI_IO_FUNC_GPIO_10_SDIO_D3,
    HI_IO_FUNC_GPIO_10_SPI0_CK,
    HI_IO_FUNC_GPIO_10_PWM1_OUT,
    HI_IO_FUNC_GPIO_10_I2S0_TX = 7,
} hi_io_func_gpio_10;

/**
* @ingroup iot_io
*
* GPIO_11 pin function.CNcomment:GPIO_11�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_11_GPIO,
    HI_IO_FUNC_GPIO_11_UART2_TXD = 2,
    HI_IO_FUNC_GPIO_11_SDIO_CMD,
    HI_IO_FUNC_GPIO_11_SPI0_RXD,
    HI_IO_FUNC_GPIO_11_PWM2_OUT,
    HI_IO_FUNC_GPIO_11_RF_TX_EN_EXT,
    HI_IO_FUNC_GPIO_11_I2S0_RX,
} hi_io_func_gpio_11;

/**
* @ingroup iot_io
*
* GPIO_12 pin function.CNcomment:GPIO_12�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_12_GPIO,
    HI_IO_FUNC_GPIO_12_UART2_RXD = 2,
    HI_IO_FUNC_GPIO_12_SDIO_CLK,
    HI_IO_FUNC_GPIO_12_SPI0_CSN,
    HI_IO_FUNC_GPIO_12_PWM3_OUT,
    HI_IO_FUNC_GPIO_12_RF_RX_EN_EXT,
    HI_IO_FUNC_GPIO_12_I2S0_BCLK,
} hi_io_func_gpio_12;

/**
* @ingroup iot_io
*
* GPIO_13 pin function.CNcomment:GPIO_13�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_13_SSI_DATA,
    HI_IO_FUNC_GPIO_13_UART0_TXD,
    HI_IO_FUNC_GPIO_13_UART2_RTS_N,
    HI_IO_FUNC_GPIO_13_SDIO_D0,
    HI_IO_FUNC_GPIO_13_GPIO,
    HI_IO_FUNC_GPIO_13_PWM4_OUT,
    HI_IO_FUNC_GPIO_13_I2C0_SDA,
    HI_IO_FUNC_GPIO_13_I2S0_WS,
} hi_io_func_gpio_13;

/**
* @ingroup iot_io
*
* GPIO_14 pin function.CNcomment:GPIO_14�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_GPIO_14_SSI_CLK,
    HI_IO_FUNC_GPIO_14_UART0_RXD,
    HI_IO_FUNC_GPIO_14_UART2_CTS_N,
    HI_IO_FUNC_GPIO_14_SDIO_D1,
    HI_IO_FUNC_GPIO_14_GPIO,
    HI_IO_FUNC_GPIO_14_PWM5_OUT,
    HI_IO_FUNC_GPIO_14_I2C0_SCL,
} hi_io_func_gpio_14;

/**
* @ingroup iot_io
*
* SFC_CSN pin function.CNcomment:SFC_CSN�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_SFC_CSN_SFC_CSN,
    HI_IO_FUNC_SFC_CSN_SDIO_D2,
    HI_IO_FUNC_SFC_CSN_GPIO9,
    HI_IO_FUNC_SFC_CSN_SPI1_TXD = 4,
} hi_io_func_sfc_csn;

/**
* @ingroup iot_io
*
* SFC_DO pin function.CNcomment:SFC_DO�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_SFC_IO_1_SFC_DO,
    HI_IO_FUNC_SFC_IO_1_SDIO_D3,
    HI_IO_FUNC_SFC_IO_1_GPIO10,
    HI_IO_FUNC_SFC_IO_1_SPI0_CK = 4,
} hi_io_func_sfc_io_1;

/**
* @ingroup iot_io
*
* SFC_WPN pin function.CNcomment:SFC_WPN�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_SFC_IO_2_SFC_WPN,
    HI_IO_FUNC_SFC_IO_2_SDIO_CMD,
    HI_IO_FUNC_SFC_IO_2_GPIO11,
    HI_IO_FUNC_SFC_IO_2_RF_TX_EN_EXT,
    HI_IO_FUNC_SFC_IO_1_SPI0_RXD,
} hi_io_func_sfc_io_2;

/**
* @ingroup iot_io
*
* SFC_DI pin function.CNcomment:SFC_DI�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_SFC_IO_0_SFC_DI,
    HI_IO_FUNC_SFC_IO_0_SDIO_CLK,
    HI_IO_FUNC_SFC_IO_0_GPIO12,
    HI_IO_FUNC_SFC_IO_0_RF_RX_EN_EXT,
    HI_IO_FUNC_SFC_IO_1_SPI0_CSN,
} hi_io_func_sfc_io_0;

/**
* @ingroup iot_io
*
* SFC_CLK pin function.CNcomment:SFC_CLK�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_SFC_CLK_SFC_CLK,
    HI_IO_FUNC_SFC_CLK_SDIO_D0,
    HI_IO_FUNC_SFC_CLK_GPIO13,
    HI_IO_FUNC_SFC_CLK_SSI_DATA = 4,
} hi_io_func_sfc_clk;

/**
* @ingroup iot_io
*
* SFC_HOLDN pin function.CNcomment:SFC_HOLDN�ܽŹ��ܡ�CNend
*/
typedef enum {
    HI_IO_FUNC_SFC_IO_3_SFC_HOLDN,
    HI_IO_FUNC_SFC_IO_3_SDIO_D1,
    HI_IO_FUNC_SFC_IO_3_GPIO14,
    HI_IO_FUNC_SFC_IO_3_SSI_CLK = 4,
} hi_io_func_sfc_io_3;

/**
* @ingroup iot_io
*
* I/O drive capability.CNcomment:IO����������CNend
* Note: The HI_IO_NAME_GPIO_0~HI_IO_NAME_GPIO_11 and HI_IO_NAME_GPIO_13~HI_IO_NAME_GPIO_14 driver capabilities are
*       optional.The value range is HI_IO_DRIVER_STRENGTH_0~HI_IO_DRIVER_STRENGTH_3, and the other I/O ranges are
*       HI_IO_DRIVER_STRENGTH_0~HI_IO_DRIVER_STRENGTH_7.CNcomment:ע��:HI_IO_NAME_GPIO_0~HI_IO_NAME_GPIO_11��
*       HI_IO_NAME_GPIO_13~HI_IO_NAME_GPIO_14����������ѡ��Χ��HI_IO_DRIVER_STRENGTH_0~HI_IO_DRIVER_STRENGTH_3��
*       ����IO��Χ��HI_IO_DRIVER_STRENGTH_0~HI_IO_DRIVER_STRENGTH_7��CNend
*/
typedef enum {
    HI_IO_DRIVER_STRENGTH_0 = 0,      /**< Drive strength level 0 (highest).
                                         CNcomment:��������0���������������CNend */
    HI_IO_DRIVER_STRENGTH_1,          /**< Drive strength level 1.CNcomment:��������1��CNend */
    HI_IO_DRIVER_STRENGTH_2,          /**< Drive strength level 2.CNcomment:��������2��CNend */
    HI_IO_DRIVER_STRENGTH_3,          /**< Drive strength level 3.CNcomment:��������3��CNend */
    HI_IO_DRIVER_STRENGTH_4,          /**< Drive strength level 4.CNcomment:��������4��CNend */
    HI_IO_DRIVER_STRENGTH_5,          /**< Drive strength level 5.CNcomment:��������5��CNend */
    HI_IO_DRIVER_STRENGTH_6,          /**< Drive strength level 6.CNcomment:��������6��CNend */
    HI_IO_DRIVER_STRENGTH_7,          /**< Drive strength level 7 (lowest).
                                         CNcomment:��������7���������������CNend */
    HI_IO_DRIVER_STRENGTH_MAX,
} hi_io_driver_strength;

/**
 * @ingroup iot_io
 *
 * GPIO pull-up configuration.CNcomment:IO����������CNend
 */
typedef enum {
    HI_IO_PULL_NONE,    /**< Disabled.CNcomment:����CNend */
    HI_IO_PULL_UP,      /**< Pull-up enabled.CNcomment:����CNend */
    HI_IO_PULL_DOWN,    /**< Pull-down enabled.CNcomment:����CNend */
    HI_IO_PULL_MAX,     /**< Invalid.CNcomment:��ЧֵCNend */
} hi_io_pull;

/**
* @ingroup  iot_io
* @brief Enables the I/O pull-up.CNcomment:����ĳ��IO���������ܡ�CNend
*
* @par ����:
*           Enables the I/O pull-up.CNcomment:����ĳ��IO���������ܡ�CNend
*
* @attention None
* @param  id  [IN]  type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  val [IN]  type #hi_io_pull��I/O pull-up enable.CNcomment:�����õ�������״̬��CNend
*
* @retval 0       Success
* @retval #HI_ERR_GPIO_INVALID_PARAMETER     Failure. Input invalid.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  hi_io_get_pull��
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_set_pull(hi_io_name id, hi_io_pull val);

/**
* @ingroup  iot_io
* @brief Obtains the GPIO pull-up status.CNcomment:��ȡĳ��GPIO������״̬��CNend
*
* @par ����:
*           Obtains the GPIO pull-up status.CNcomment:��ȡĳ��GPIO������״̬��CNend
*
* @attention None
* @param  id    [IN]  type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  val   [OUT] type #hi_io_pull*��pull-up status.CNcomment:��ȡ����������״̬��CNend.
*
* @retval 0       Success
* @retval #HI_ERR_GPIO_INVALID_PARAMETER     Failure. Input invalid.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  hi_io_set_pull��
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_get_pull(hi_io_name id, hi_io_pull *val);

/**
* @ingroup  iot_io
* @brief Sets the I/O multiplexing.CNcomment:����ĳ��IO�ĸ��ù��ܡ�CNend
*
* @par ����:
*           Sets the I/O multiplexing.CNcomment:����ĳ��IO�ĸ��ù��ܡ�CNend
*
* @attention None
* @param  id  [IN] type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  val [IN] type #hi_u8��I/O multiplexing.See the functions below: CNcomment:IO���ù��ܡ�
���ݴ����õ�Ӳ���ܽţ�������ö����ѡ����Ӧ���ܡ�CNend
                        hi_io_func_gpio_0,
                        hi_io_func_gpio_1,
                        hi_io_func_gpio_2,
                        hi_io_func_gpio_3,
                        hi_io_func_gpio_4,
                        hi_io_func_gpio_5,
                        hi_io_func_gpio_6,
                        hi_io_func_gpio_7,
                        hi_io_func_gpio_8,
                        hi_io_func_gpio_9,
                        hi_io_func_gpio_10,
                        hi_io_func_gpio_11,
                        hi_io_func_gpio_12,
                        hi_io_func_gpio_13,
                        hi_io_func_gpio_14,
                        hi_io_func_sfc_csn,
                        hi_io_func_sfc_io_1,
                        hi_io_func_sfc_io_2,
                        hi_io_func_sfc_io_0,
                        hi_io_func_sfc_clk,
                        hi_io_func_sfc_io_3
*
* @retval 0       Success
* @retval #HI_ERR_GPIO_INVALID_PARAMETER     Failure. Input invalid.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  hi_io_get_func��
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_set_func(hi_io_name id, hi_u8 val);

/**
* @ingroup  iot_io
* @brief Obtains the I/O multiplexing.CNcomment:��ȡĳ��IO���ù��ܡ�CNend
*
* @par ����:
*           Obtains the I/O multiplexing.CNcomment:��ȡĳ��IO���ù��ܡ�CNend
*
* @attention None
* @param  id    [IN]  type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  val   [OUT] type #hi_u8*��I/O multiplexing.CNcomment:IO���ù��ܡ�CNend
*
* @retval 0       Success
* @retval #HI_ERR_GPIO_INVALID_PARAMETER     Failure. Input invalid.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  hi_io_set_func��
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_get_func(hi_io_name id, hi_u8 *val);

/**
* @ingroup  iot_io
* @brief Sets the I/O drive strength.CNcomment:����ĳ��IO����������CNend
*
* @par ����:
*          The I/O drive strength is closely related to hardware design. For details, see SoC data sheet.
CNcomment:����ĳ��IO������������Ӳ�����ǿ��أ���ϸ���òο�оƬ�ֲᡣCNend
*
* @attention None
* @param  id    [IN] type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  level [IN] type #hi_io_driver_strength��I/O drive strength level.CNcomment:IO������������CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  None
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_set_driver_strength(hi_io_name id, hi_io_driver_strength val);

/**
* @ingroup  iot_io
* @brief Obtains the I/O drive strength.CNcomment:��ȡĳ��IO����������CNend
*
* @par ����:
*          Obtains the I/O drive strength.CNcomment:��ȡĳ��IO����������CNend
*
* @attention None
* @param  id    [IN]  type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  val   [OUT] type #hi_io_driver_strength*��I/O drive strength level.CNcomment:IO������������CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  None
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_get_driver_strength(hi_io_name id, hi_io_driver_strength *val);

/**
* @ingroup  iot_io
* @brief Set the I/O input enable status.CNcomment:����ĳ��IO����ʹ�ܵ�״̬��CNend
*
* @par ����:
*          Set the I/O input enable status.CNcomment:����ĳ��IO����ʹ�ܵ�״̬��CNend
*
* @attention If the input enable status of an IO is set to FALSE in the input state, the CPU can't read the IO changes.
CNComment:���ĳ��IO������ʹ������ΪFALSE��CPU����ȡ������IO�ı仯��CNend
* @param  id      [IN] type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  state   [IN] type #hi_bool��IO input enable state.CNcomment:Ҫ���õ�����ʹ��״̬��CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  None
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_set_input_enable(hi_io_name id, hi_bool state);

/**
* @ingroup  iot_io
* @brief Get the I/O input enable status.CNcomment:��ȡĳ��IO����ʹ�ܵ�״̬��CNend
*
* @par ����:
*          Get the I/O input enable status.CNcomment:��ȡĳ��IO����ʹ�ܵ�״̬��CNend
*
* @attention None
* @param  id      [IN]  type #hi_io_name��I/O index.CNcomment:Ӳ���ܽš�CNend
* @param  state   [OUT] type #hi_bool *��IO input enable state.CNcomment:IO������ʹ��״̬��CNend
*
* @retval #0       Success.
* @retval #Other   Failure. For details, see hi_errno.h.
* @par ����:
*           @li hi_io.h��Describes I/O APIs.CNcomment:�ļ���������IO��ؽӿڡ�CNend
* @see  None
* @since Hi3861_V100R001C00
*/
hi_u32 hi_io_get_input_enable(hi_io_name id, hi_bool *state);

#endif
