/*
 * Copyright (C) 2014 Freie Universität Berlin
 *               2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_cc110x
 * @{
 *
 * @file
 * @brief       Variables for the cc110x netdev interface
 *
 * @author      Fabian Nack <nack@inf.fu-berlin.de>
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 */

#ifndef NRF24L01P_NETDEV_H
#define NRF24L01P_NETDEV_H

#include "periph/gpio.h"
#include "periph/spi.h"
#include "net/netdev.h"
#include "nrf24l01p.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Implementation of netdev_driver_t for CC110X device
 */
extern const netdev_driver_t netdev_nrf24l01p_driver;

/**
 * @brief nrf24l01p netdev struct
 */
typedef struct netdev_nrf24l01p {
    netdev_t netdev;        /**< writing obious */
    nrf24l01p_t nrf24l01p;        /**< documentation here */
} netdev_nrf24l01p_t;

/**
 * @brief   Received packet status information for cc110x radios
 */
typedef struct netdev_radio_rx_info netdev_nrf24l01p_rx_info_t;

/**
 * @brief netdev <-> cc110x glue code initialization function
 *
 * @param[out]      netdev_cc110x  ptr to netdev_cc110x struct ti initialize
 * @param[in]       params          cc110x IO parameter struct to use
 *
 * @return          0               on success
 * @return          -1              on error
 */
int netdev_nrf24l01p_setup(netdev_nrf24l01p_t *netdev_nrf24l01p, const nrf24l01p_params_t *params);

#ifdef __cplusplus
}
#endif

#endif /* CC110X_NETDEV_H */
/** @} */
