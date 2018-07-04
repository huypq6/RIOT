/*
 * Copyright (C) 2018 Huy Pham <huypq6@outlook.com.vn>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup   drivers_nrf24l01p
 * @{
 *
 * @file
 * @brief     nrf24l01p board specific configuration
 *
 * @author    Huy Pham <huypq6@outlook.com.vn>
 */

#ifndef NRF24L01P_PARAMS_H
#define NRF24L01P_PARAMS_H

#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Default parameters for the nrf24l01p driver
 *
 * These values are based on the msba2 board
 * @{
 */
#ifndef NRF24L01P_PARAM_SPI
#define NRF24L01P_PARAM_SPI            	SPI_DEV(0)
#endif

#ifndef NRF24L01P_PARAM_CS
#define NRF24L01P_PARAM_CS             	GPIO_PIN(0, 8)
#endif

#ifndef NRF24L01P_PARAM_CE
#define NRF24L01P_PARAM_CE           	GPIO_PIN(0, 9)
#endif

#ifndef NRF24L01P_PARAM_IRQ
#define NRF24L01P_PARAM_IRQ           	GPIO_PIN(1, 10)
#endif


#ifndef NRF24L01P_PARAMS
#define NRF24L01P_PARAMS               { \
                                        .spi  	= NRF24L01P_PARAM_SPI,  \
                                        .cs   	= NRF24L01P_PARAM_CS,   \
                                        .ce 	= NRF24L01P_PARAM_CE, \
                                        .irq 	= NRF24L01P_PARAM_IRQ, \
                                    }
#endif
/** @} */


/**
 * @name    NRF24L01P configuration
 * @brief   Specifies the SPI bus and GPIOs connected to the NRF24L01P transceiver
 */
const nrf24l01_params_t nrf24l01_params[] = {
    NRF24L01P_PARAMS
};

#ifdef __cplusplus
}
#endif
#endif /* NRF24L01P_PARAMS_H */
/** @} */
