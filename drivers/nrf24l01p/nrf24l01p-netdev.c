/*
 * Copyright (C) 2018 Huy Pham <huypq6@outlook.com.vn>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_nrf24l01p
 * @{
 * @file
 * @brief       Implementation of netdev interface for cc110x
 *
 * @author      Huy Pham <huypq6@outlook.com.vn>
 * @}
 */

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "nrf24l01p.h"
#include "nrf24l01p_settings.h"
#include "nrf24l01p-netdev.h"
#include "net/eui64.h"

#include "xtimer.h"
#include "thread.h"
#include "msg.h"

#include "periph/gpio.h"
#include "net/netdev.h"
#include "net/gnrc/nettype.h"

#define ENABLE_DEBUG    (1)
#include "debug.h"

#define DELAY_CS_TOGGLE_TICKS       (xtimer_ticks_from_usec(DELAY_CS_TOGGLE_US))
#define DELAY_AFTER_FUNC_TICKS      (xtimer_ticks_from_usec(DELAY_AFTER_FUNC_US))
#define DELAY_CHANGE_TXRX_TICKS     (xtimer_ticks_from_usec(DELAY_CHANGE_TXRX_US))

#define SPI_MODE            SPI_MODE_0
#define SPI_CLK             SPI_CLK_400KHZ

static int _send(netdev_t *netdev, const iolist_t *iolist);
static int _recv(netdev_t *netdev, void *buf, size_t len, void *info);
static int _init(netdev_t *netdev);
static void _isr(netdev_t *netdev);
static int _get(netdev_t *netdev, netopt_t opt, void *val, size_t max_len);
static int _set(netdev_t *netdev, netopt_t opt, const void *val, size_t len);

const netdev_driver_t netdev_nrf24l01p_driver = {
    .send = _send,
    .recv = _recv,
    .init = _init,
    .isr = _isr,
    .get = _get,
    .set = _set,
};

static int _send(netdev_t *dev, const iolist_t *iolist)
{
    DEBUG("%s:%u\n", __func__, __LINE__);
    (void)dev;
    (void)iolist;

//     // netdev_nrf24l01p_t *netdev_nrf24l01p = (netdev_nrf24l01p_t *)dev;
//     // cc110x_pkt_t *cc110x_pkt = iolist->iol_base;

//     // return cc110x_send(&netdev_nrf24l01p->nrf24l01p, cc110x_pkt);
    return 0;
}

static int _recv(netdev_t *dev, void *buf, size_t len, void *info)
{
    DEBUG("%s:%u\n", __func__, __LINE__);
    (void) dev;
    (void)buf;
    (void)len;
    (void)info;
//     // cc110x_t *cc110x = &((netdev_nrf24l01p_t*) dev)->cc110x;

//     // cc110x_pkt_t *cc110x_pkt = &cc110x->pkt_buf.packet;
//     // if (cc110x_pkt->length > len) {
//     //     return -ENOSPC;
//     // }

//     // memcpy(buf, (void*)cc110x_pkt, cc110x_pkt->length);
//     // if (info != NULL) {
//     //     netdev_cc110x_rx_info_t *cc110x_info = info;

//     //     cc110x_info->rssi = (int16_t)cc110x->pkt_buf.rssi/2 - CC110X_RSSI_OFFSET;
//     //     cc110x_info->lqi = cc110x->pkt_buf.lqi;
//     // }
//     // return cc110x_pkt->length;
    return 0;
}

// static inline int _get_iid(netdev_t *netdev, eui64_t *value, size_t max_len)
// {
//     // cc110x_t *cc110x = &((netdev_nrf24l01p_t*) netdev)->cc110x;
//     // uint8_t *eui64 = (uint8_t*) value;

//     // if (max_len < sizeof(eui64_t)) {
//     //     return -EOVERFLOW;
//     // }

//     /* make address compatible to https://tools.ietf.org/html/rfc6282#section-3.2.2*/
//     // memset(eui64, 0, sizeof(eui64_t));
//     // eui64[3] = 0xff;
//     // eui64[4] = 0xfe;
//     // eui64[7] = cc110x->radio_address;

//     // return sizeof(eui64_t);
// }

static int _get(netdev_t *dev, netopt_t opt, void *value, size_t value_len)
{
	(void) dev; 
	(void) opt;
	(void) value;
	(void) value_len;
// //     cc110x_t *cc110x = &((netdev_nrf24l01p_t*) dev)->cc110x;

// //     switch (opt) {
// //         case NETOPT_DEVICE_TYPE:
// //             assert(value_len == 2);
// //             *((uint16_t *) value) = NETDEV_TYPE_CC110X;
// //             return 2;
// // #ifdef MODULE_GNRC_NETIF
// //         case NETOPT_PROTO:
// //             assert(value_len == sizeof(gnrc_nettype_t));
// //             *((gnrc_nettype_t *)value) = cc110x->proto;
// //             return sizeof(gnrc_nettype_t);
// // #endif
// //         case NETOPT_CHANNEL:
// //             assert(value_len > 1);
// //             *((uint16_t *)value) = (uint16_t)cc110x->radio_channel;
// //             return sizeof(uint16_t);
// //         case NETOPT_ADDRESS:
// //             assert(value_len > 0);
// //             *((uint8_t *)value) = cc110x->radio_address;
// //             return sizeof(uint8_t);
// //         case NETOPT_MAX_PACKET_SIZE:
// //             assert(value_len > 0);
// //             *((uint16_t *)value) = CC110X_PACKET_LENGTH;
// //             return sizeof(uint16_t);
// //         case NETOPT_IPV6_IID:
// //             return _get_iid(dev, value, value_len);
// //         case NETOPT_ADDR_LEN:
// //         case NETOPT_SRC_LEN:
// //             *((uint16_t *)value) = sizeof(cc110x->radio_address);
// //             return sizeof(uint16_t);
// //         default:
// //             break;
// //     }

    // return -ENOTSUP;
    return 0;
}

static int _set(netdev_t *dev, netopt_t opt, const void *value, size_t value_len)
{
	(void)dev;
	(void)opt;
	(void)value;
	(void)value_len;
// //     cc110x_t *cc110x = &((netdev_nrf24l01p_t*) dev)->cc110x;

// //     switch (opt) {
// //         case NETOPT_CHANNEL:
// //             {
// //                 const uint16_t *arg = value;
// //                 uint8_t channel = (uint8_t)(*arg);
// //             #if CC110X_MIN_CHANNR
// //                 if (channel < CC110X_MIN_CHANNR) {
// //                     return -EINVAL;
// //                 }
// //             #endif /* CC110X_MIN_CHANNR */
// //                 if (channel > CC110X_MAX_CHANNR) {
// //                     return -EINVAL;
// //                 }
// //                 if (cc110x_set_channel(cc110x, channel) == -1) {
// //                     return -EINVAL;
// //                 }
// //                 return sizeof(uint16_t);
// //             }
// //         case NETOPT_ADDRESS:
// //             if (value_len < 1) {
// //                 return -EINVAL;
// //             }
// //             if (!cc110x_set_address(cc110x, *(const uint8_t*)value)) {
// //                 return -EINVAL;
// //             }
// //             return sizeof(uint8_t);
// // #ifdef MODULE_GNRC_NETIF
// //         case NETOPT_PROTO:
// //             if (value_len != sizeof(gnrc_nettype_t)) {
// //                 return -EINVAL;
// //             }
// //             else {
// //                 cc110x->proto = (gnrc_nettype_t) value;
// //                 return sizeof(gnrc_nettype_t);
// //             }
// //             break;
// // #endif
// //         default:
// //             return -ENOTSUP;
// //     }

    return 0;
}

static void _netdev_nrf24l01p_isr(void *arg)
{
    netdev_t *netdev = (netdev_t*) arg;
    netdev->event_callback(netdev, NETDEV_EVENT_ISR);
}

// static void _netdev_cc110x_rx_callback(void *arg)
// {
//     netdev_t *netdev = (netdev_t*) arg;
//     cc110x_t *cc110x = &((netdev_nrf24l01p_t*) arg)->cc110x;
//     gpio_irq_disable(cc110x->params.gdo2);
//     netdev->event_callback(netdev, NETDEV_EVENT_RX_COMPLETE);
// }

static void _isr(netdev_t *dev)
{
	(void) dev;
    // nrf24l01p_t *nrf24l01p = &((netdev_nrf24l01p_t*) dev)->nrf24l01p;
//     cc110x_isr_handler(cc110x, _netdev_cc110x_rx_callback, (void*)dev);
}

static int _init(netdev_t *dev)
{
    DEBUG("%s:%u\n", __func__, __LINE__);

    nrf24l01p_t *nrf24l01p = &((netdev_nrf24l01p_t*) dev)->nrf24l01p;

    /* Init IRQ pin */
    gpio_init_int(nrf24l01p->params.irq, GPIO_IN_PU, GPIO_FALLING, _netdev_nrf24l01p_isr, nrf24l01p);

   
    nrf24l01p_set_rxmode(nrf24l01p);
    return 0;
}


int netdev_nrf24l01p_setup(netdev_nrf24l01p_t *netdev_nrf24l01p, const nrf24l01p_params_t *params)
{
    DEBUG("netdev_nrf24l01p_setup()\n");
    netdev_nrf24l01p->netdev.driver = &netdev_nrf24l01p_driver;

    /* set default protocol */
#ifdef MODULE_GNRC_NETIF
# ifdef MODULE_GNRC_SIXLOWPAN
    netdev_nrf24l01p->nrf24l01p.proto = GNRC_NETTYPE_SIXLOWPAN;
# else
    netdev_nrf24l01p->nrf24l01p.proto = GNRC_NETTYPE_UNDEF;
# endif
#endif

    return nrf24l01p_setup(&netdev_nrf24l01p->nrf24l01p, params);
}
