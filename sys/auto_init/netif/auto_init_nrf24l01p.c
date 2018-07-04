/*
 * Copyright (C) 2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 *
 */

/*
 * @ingroup sys_auto_init_gnrc_netif
 * @{
 *
 * @file
 * @brief   Auto initialization for nrf24l01p network interfaces
 *
 * @author  Huy Pham <huypq6@outlook.com.vn>
 */

#ifdef MODULE_NRF24L01P

#include "log.h"
#include "debug.h"
#include "board.h"
#include "gnrc_netif_cc110x.h"
#include "nrf24l01p-netdev.h"
#include "net/gnrc.h"

#include "nrf24l01p.h"
#include "nrf24l01p_params.h"

/**
 * @brief   Define stack parameters for the MAC layer thread
 * @{
 */
#define NRF24L01P_MAC_STACKSIZE     (THREAD_STACKSIZE_DEFAULT + DEBUG_EXTRA_STACKSIZE)
#ifndef NRF24L01P_MAC_PRIO
#define NRF24L01P_MAC_PRIO          (GNRC_NETIF_PRIO)
#endif

#define NRF24L01P_NUM (sizeof(nrf24l01p_params)/sizeof(nrf24l01p_params[0]))

static netdev_nrf24l01p_t nrf24l01p_devs[CC110X_NUM];
static char _stacks[NRF24L01P_NUM][NRF24L01P_MAC_STACKSIZE];

void auto_init_nrf24l01p(void)
{
    for (unsigned i = 0; i < NRF24L01P_NUM; i++) {
        const nrf24l01p_params_t *p = &nrf24l01p_params[i];

        LOG_DEBUG("[auto_init_netif] initializing nrf24l01p #%u\n", i);

        int res = netdev_nrf24l01p_setup(&nrf24l01p_devs[i], p);
        if (res < 0) {
            LOG_ERROR("[auto_init_netif] error initializing nrf24l01p #%u\n", i);
        }
        else {
            gnrc_netif_nrf24l01p_create(_stacks[i], NRF24L01P_MAC_STACKSIZE,
                                     NRF24L01P_MAC_PRIO, "nrf24l01p",
                                     (netdev_t *)&nrf24l01p_devs[i]);
        }
    }
}
#else
typedef int dont_be_pedantic;
#endif /* MODULE_CC110X */

/** @} */
