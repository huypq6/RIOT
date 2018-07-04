/*
 * Copyright (C) 2018 Huy Pham <huypq6@outlook.com.vn>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup net_gnrc_netif
 * @{
 *
 * @file
 * @brief   NRF24L01P adaption for @ref net_gnrc_netif
 *
 * @author  Huy Pham <huypq6@outlook.com.vn>
 */
#ifndef GNRC_NETIF_NRF24L01P_H
#define GNRC_NETIF_NRF24L01P_H

#include "net/gnrc/netif.h"

#ifdef __cplusplus
extern "C" {
#endif

gnrc_netif_t *gnrc_netif_nrf24l01p_create(char *stack, int stacksize, char priority,
                                       char *name, netdev_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* GNRC_NETIF_NRF24L01P_H */
/** @} */
