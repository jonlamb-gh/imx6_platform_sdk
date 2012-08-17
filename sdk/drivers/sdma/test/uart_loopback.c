/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include <string.h>
#include <stdio.h>

#include "sdma/sdma.h"
#include "sdma_event.h"
#include "sdma_test.h"
#include "hardware.h"

#define UART_LOOPBACK_TEST_BUF_SZ 	1024
#define UART_REF_FREQ 			27000000

#define TX_FIFO_WATERMARK_LEVEL 4
#define RX_FIFO_WATERMARK_LEVEL 16

/* Uncacheable & unbufferable area start */
static uint32_t tx_buf[UART_LOOPBACK_TEST_BUF_SZ];
static uint32_t rx_buf[UART_LOOPBACK_TEST_BUF_SZ];

static char env_buffer[SDMA_ENV_BUF_SIZE];
static sdma_bd_t bd[2];
/* Uncacheable & unbufferable area end */

static void uart_access_config(void)
{
    /* Set all MPROTx to be non-bufferable, trusted for R/W, not forced to user-mode. */
    *(volatile int *)(AIPS1_BASE_ADDR) = 0x77777777;
    *(volatile int *)(AIPS1_BASE_ADDR + 0x04) = 0x77777777;

    *(volatile int *)(AIPS2_BASE_ADDR) = 0x77777777;
    *(volatile int *)(AIPS2_BASE_ADDR + 0x04) = 0x77777777;

    /*Set all OPACRx to be non-buuferable, writable, accessible for non-trusted master */
    *(volatile int *)(AIPS1_BASE_ADDR + 0x40) = 0;
    *(volatile int *)(AIPS1_BASE_ADDR + 0x44) = 0;
    *(volatile int *)(AIPS1_BASE_ADDR + 0x48) = 0;
    *(volatile int *)(AIPS1_BASE_ADDR + 0x4C) = 0;
    *(volatile int *)(AIPS1_BASE_ADDR + 0x50) = 0;

    *(volatile int *)(AIPS2_BASE_ADDR + 0x40) = 0;
    *(volatile int *)(AIPS2_BASE_ADDR + 0x44) = 0;
    *(volatile int *)(AIPS2_BASE_ADDR + 0x48) = 0;
    *(volatile int *)(AIPS2_BASE_ADDR + 0x4C) = 0;
    *(volatile int *)(AIPS2_BASE_ADDR + 0x50) = 0;
}

static void ccm_clock_gates_on(void)
{
    *(volatile int *)(CCM_BASE_ADDR + 0x68) = 0xFFFFFFFF;   /*CCGR0 */
    *(volatile int *)(CCM_BASE_ADDR + 0x68 + 0x04) = 0xFFFFFFFF;
    *(volatile int *)(CCM_BASE_ADDR + 0x68 + 0x08) = 0xFFFFFFFF;
    *(volatile int *)(CCM_BASE_ADDR + 0x68 + 0x0C) = 0xFFFFFFFF;
    *(volatile int *)(CCM_BASE_ADDR + 0x68 + 0x10) = 0xFFFFFFFF;
    *(volatile int *)(CCM_BASE_ADDR + 0x68 + 0x14) = 0xFFFFFFFF;
    *(volatile int *)(CCM_BASE_ADDR + 0x68 + 0x18) = 0xFFFFFFFF;
    *(volatile int *)(CCM_BASE_ADDR + 0x68 + 0x1C) = 0xFFFFFFFF;
}

#ifdef CHIP_MX53
// UART3 port
static hw_module_t uart3_sdma_test = {
    "UART3 for SDMA test",
    3,
    UART3_BASE_ADDR,
    UART_REF_FREQ,
};
#else
// UART1 port
static hw_module_t uart1_sdma_test = {
    "UART1 for SDMA test",
    1,
    UART1_BASE_ADDR,
    UART_REF_FREQ,
};
#endif /* CHIP_MX53 */

// UART5 port
static hw_module_t uart5_sdma_test = {
    "UART5 for SDMA test",
    5,
    UART5_BASE_ADDR,
    UART_REF_FREQ,
};

static void uart_loopback_init(struct hw_module *port, uint32_t baudrate)
{
    /* Initialize the clock frequency - in i.MX6DQ/SDL, all UART port uses the same source clock */
    port->freq = get_peri_clock(UART1_BAUD);

    /* Initialize the UART port */
    uart_init(port, baudrate, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);

    /* Set the DMA mode for the Tx FIFO */
    uart_set_FIFO_mode(port, TX_FIFO, TX_FIFO_WATERMARK_LEVEL, DMA_MODE);
    /* Set the DMA mode for the Rx FIFO */
    uart_set_FIFO_mode(port, RX_FIFO, RX_FIFO_WATERMARK_LEVEL, DMA_MODE);

    /* Enable loopback mode */
    uart_set_loopback_mode(port, TRUE);

    return;
}

int uart_app_test(void)
{
    int idx, channel[2];
    sdma_chan_desc_t chan_desc[2];

    uart_access_config();
    ccm_clock_gates_on();

    printf("UART5 loopback test starts.\n");

    MEM_VIRTUAL_2_PHYSICAL(tx_buf, sizeof(tx_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(rx_buf, sizeof(tx_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(env_buf, sizeof(env_buffer), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(bd, sizeof(bd), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);

    /* Initialize buffers for testing */
    memset(tx_buf, 0x5A, sizeof(tx_buf));
    memset(rx_buf, 0x00, sizeof(rx_buf));

    /* Initialize SDMA */
    printf("Initialize SDMA environment.\n");
    if (SDMA_RETV_SUCCESS != sdma_init((uint32_t *)env_buffer, SDMA_IPS_HOST_BASE_ADDR)) {
        printf("SDMA initialization failed.\n");
        return FALSE;
    }

    uint32_t script_addr;
    if (SDMA_RETV_SUCCESS != sdma_lookup_script(SDMA_MCU_2_APP, &script_addr)) {
        printf("Invalid script.\n");
        return FALSE;
    }

    /* Setup channel descriptor */
    chan_desc[0].script_addr = script_addr;
    chan_desc[0].dma_mask[0] = chan_desc[0].dma_mask[1] = 0;
    chan_desc[0].dma_mask[SDMA_EVENT_UART5_TX / 32] = 0x01 << (SDMA_EVENT_UART5_TX % 32);   /*uart5 tx fifo event */
    chan_desc[0].priority = SDMA_CHANNEL_PRIORITY_LOW;
    for (idx = 0; idx < 8; idx++) {
        chan_desc[0].gpr[idx] = 0;
    }
    chan_desc[0].gpr[0] = chan_desc[0].dma_mask[1];
    chan_desc[0].gpr[1] = chan_desc[0].dma_mask[0];
    chan_desc[0].gpr[6] = UART5_BASE_ADDR + 0x40;   /*tx fifo address */
    chan_desc[0].gpr[7] = TX_FIFO_WATERMARK_LEVEL;  /*water mark */

    /* Setup buffer descriptors */
    bd[0].mode = SDMA_FLAGS_BUSY | SDMA_FLAGS_WRAP | SDMA_FLAGS_BW8 | sizeof(tx_buf);
    bd[0].buf_addr = (uint32_t)tx_buf;

    /* Open channel */
    printf("Open SDMA channel for transmit.\n");
    channel[0] = sdma_channel_request(&chan_desc[0], (sdma_bd_p) (&bd[0]));
    if (channel[0] < 0) {
        printf("Channel request failed.\n");
        return FALSE;
    }

    if (SDMA_RETV_SUCCESS != sdma_lookup_script(SDMA_APP_2_MCU, &script_addr)) {
        printf("Invalid script.\n");
        return FALSE;
    }

    /* Setup channel descriptor */
    chan_desc[1].script_addr = script_addr;
    chan_desc[1].dma_mask[0] = chan_desc[1].dma_mask[1] = 0;
    chan_desc[1].dma_mask[SDMA_EVENT_UART5_RX / 32] = 0x01 << (SDMA_EVENT_UART5_RX % 32);   /*uart 5 tx fifo event */
    chan_desc[1].priority = SDMA_CHANNEL_PRIORITY_LOW;
    for (idx = 0; idx < 8; idx++) {
        chan_desc[1].gpr[idx] = 0;
    }
    chan_desc[1].gpr[0] = chan_desc[1].dma_mask[1];
    chan_desc[1].gpr[1] = chan_desc[1].dma_mask[0];
    chan_desc[1].gpr[6] = UART5_BASE_ADDR + 0x0;    /*rx fifo address */
    chan_desc[1].gpr[7] = RX_FIFO_WATERMARK_LEVEL;  /*water mark */

    /* Setup buffer descriptor */
    bd[1].mode = SDMA_FLAGS_BUSY | SDMA_FLAGS_WRAP | SDMA_FLAGS_BW8 | sizeof(rx_buf);
    bd[1].buf_addr = (uint32_t)rx_buf;

    /* Open channel */
    printf("Open SDMA channel for receive.\n");
    channel[1] = sdma_channel_request(&chan_desc[1], (sdma_bd_p) (&bd[1]));
    if (channel[1] < 0) {
        printf("Channel request failed.\n");
        return FALSE;
    }

    /* Start channels */
    printf("Channel %d and Channel %d opened, starting transfer...\n", channel[0], channel[1]);
    sdma_channel_start(channel[0]);
    sdma_channel_start(channel[1]);

    uart_loopback_init(&uart5_sdma_test, 115200);

    /* Wait channels stop */
    uint32_t status;
    do {
        sdma_channel_status(channel[0], &status);
    } while (!(status & SDMA_CHANNEL_STATUS_DONE));

    do {
        sdma_channel_status(channel[1], &status);
    } while (!(status & SDMA_CHANNEL_STATUS_DONE));

    /* Stop channels */
    printf("Transfer completed. Stop channels.\n");
    sdma_channel_stop(channel[0]);
    sdma_channel_stop(channel[1]);

    /*Transfer completed. Close channels so they can be used by other applications. */
    sdma_channel_release(channel[0]);
    sdma_channel_release(channel[1]);
    sdma_deinit();

    /* Check data transfered */
    printf("Verify data transfered.\n");
    for (idx = 0; idx < sizeof(tx_buf) / sizeof(tx_buf[0]); idx++) {
        if (tx_buf[idx] != rx_buf[idx]) {
            printf("Word %d mismatch: 0x%x, 0x%x\n", idx + 1, tx_buf[idx], rx_buf[idx]);
            return FALSE;
        }
    }

    return TRUE;
}

int uart_shp_test(void)
{
    int idx, channel[2];
    sdma_chan_desc_t chan_desc[2];

    uart_access_config();
    ccm_clock_gates_on();

#ifdef CHIP_MX53
    printf("UART3 loopback test starts.\n");
#else
    printf("UART1 loopback test starts.\n");
#endif

    MEM_VIRTUAL_2_PHYSICAL(tx_buf, sizeof(tx_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(rx_buf, sizeof(tx_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(env_buf, sizeof(env_buffer), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(bd, sizeof(bd), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);

    /* Initialize buffer for testing */
    memset(tx_buf, 0xA5, sizeof(tx_buf));
    memset(rx_buf, 0x00, sizeof(rx_buf));

    /* Initialize SDMA */
    printf("Initialize SDMA environment.\n");
    if (SDMA_RETV_SUCCESS != sdma_init((uint32_t *)env_buffer, SDMA_IPS_HOST_BASE_ADDR)) {
        printf("SDMA initialization failed.\n");
        return FALSE;
    }

    /* Setup channel descriptor */
    uint32_t script_addr;
    if (SDMA_RETV_SUCCESS != sdma_lookup_script(SDMA_MCU_2_SHP, &script_addr)) {
        printf("Invalid script.\n");
        return FALSE;
    }

    chan_desc[0].script_addr = script_addr;
    chan_desc[0].dma_mask[0] = chan_desc[0].dma_mask[1] = 0;
#ifdef CHIP_MX53
    chan_desc[0].dma_mask[SDMA_EVENT_UART3_TX / 32] = 0x01 << (SDMA_EVENT_UART3_TX % 32);   /*uart 3 tx fifo event */
#else
    chan_desc[0].dma_mask[SDMA_EVENT_UART1_TX / 32] = 0x01 << (SDMA_EVENT_UART1_TX % 32);   /*uart 1 tx fifo event */
#endif
    chan_desc[0].priority = SDMA_CHANNEL_PRIORITY_LOW;
    for (idx = 0; idx < 8; idx++) {
        chan_desc[0].gpr[idx] = 0;
    }
    chan_desc[0].gpr[0] = chan_desc[0].dma_mask[1];
    chan_desc[0].gpr[1] = chan_desc[0].dma_mask[0];
#ifdef CHIP_MX53
    chan_desc[0].gpr[6] = UART3_BASE_ADDR + 0x40;   /*tx fifo address */
#else
    chan_desc[0].gpr[6] = UART1_BASE_ADDR + 0x40;   /*tx fifo address */
#endif
    chan_desc[0].gpr[7] = TX_FIFO_WATERMARK_LEVEL;  /*water mark */

    /* Setup buffer descriptors */
    bd[0].mode = SDMA_FLAGS_BUSY | SDMA_FLAGS_WRAP | SDMA_FLAGS_BW8 | sizeof(tx_buf);
    bd[0].buf_addr = (uint32_t)tx_buf;

    /* Open channel */
    printf("Open SDMA channel for transmit.\n");
    channel[0] = sdma_channel_request(&chan_desc[0], (sdma_bd_p) (&bd[0]));
    if (channel[0] < 0) {
        printf("Channel open failed.\n");
        return FALSE;
    }

    if (SDMA_RETV_SUCCESS != sdma_lookup_script(SDMA_SHP_2_MCU, &script_addr)) {
        printf("Invalid script.\n");
        return FALSE;
    }

    /* Setup channel descriptor */
    chan_desc[1].script_addr = script_addr;
    chan_desc[1].dma_mask[0] = chan_desc[1].dma_mask[1] = 0;
#ifdef CHIP_MX53
    chan_desc[1].dma_mask[SDMA_EVENT_UART3_RX / 32] = 0x01 << (SDMA_EVENT_UART3_RX % 32);   /*uart 3 tx fifo event */
#else
    chan_desc[1].dma_mask[SDMA_EVENT_UART1_RX / 32] = 0x01 << (SDMA_EVENT_UART1_RX % 32);   /*uart 3 tx fifo event */
#endif
    chan_desc[1].priority = SDMA_CHANNEL_PRIORITY_LOW;
    for (idx = 0; idx < 8; idx++) {
        chan_desc[1].gpr[idx] = 0;
    }
    chan_desc[1].gpr[0] = chan_desc[1].dma_mask[1];
    chan_desc[1].gpr[1] = chan_desc[1].dma_mask[0];
#ifdef CHIP_MX53
    chan_desc[1].gpr[6] = UART3_BASE_ADDR + 0x0;    /*rx fifo address */
#else
    chan_desc[1].gpr[6] = UART1_BASE_ADDR + 0x0;    /*rx fifo address */
#endif
    chan_desc[1].gpr[7] = RX_FIFO_WATERMARK_LEVEL;  /*water mark */

    /* Setup buffer descriptors */
    bd[1].mode = SDMA_FLAGS_BUSY | SDMA_FLAGS_WRAP | SDMA_FLAGS_BW8 | sizeof(rx_buf);
    bd[1].buf_addr = (uint32_t)rx_buf;

    /* Open channel */
    printf("Open SDMA channel for receive.\n");
    channel[1] = sdma_channel_request(&chan_desc[1], (sdma_bd_p) (&bd[1]));
    if (channel[1] < 0) {
        printf("Channel open failed.\n");
        return FALSE;
    }

    /* Start channels */
    printf("Channel %d and Channel %d opened, starting transfer...\n", channel[0], channel[1]);
    sdma_channel_start(channel[0]);
    sdma_channel_start(channel[1]);
#ifdef CHIP_MX53
    uart_loopback_init(&uart3_sdma_test, 115200);
#else
    uart_loopback_init(&uart1_sdma_test, 115200);
#endif
    /* Wait channels stop */
    uint32_t status;
    do {
        sdma_channel_status(channel[0], &status);
    } while (!(status & SDMA_CHANNEL_STATUS_DONE));

    do {
        sdma_channel_status(channel[1], &status);
    } while (!(status & SDMA_CHANNEL_STATUS_DONE));

    /* Stop channels */
    printf("Transfer completed. Stop channels.\n");
    sdma_channel_stop(channel[0]);
    sdma_channel_stop(channel[1]);

    /*Transfer completed. Release channels so they can be used by other applications. */
    sdma_channel_release(channel[0]);
    sdma_channel_release(channel[1]);

    sdma_deinit();

    /* Check data transfered */
    printf("Verify data transfered.\n");
    for (idx = 0; idx < sizeof(tx_buf) / sizeof(tx_buf[0]); idx++) {
        if (tx_buf[idx] != rx_buf[idx]) {
            printf("Word %d mismatch: 0x%x, 0x%x\n", idx + 1, tx_buf[idx], rx_buf[idx]);
            return FALSE;
        }
    }

    return TRUE;
}

uint32_t trans_done = FALSE;

void uart5_trans_isr(uint32_t channel)
{
    printf("\ninterrupt occured in channel%d\n\n", channel);
    trans_done = TRUE;
}

int uart_app_interrupt_test(void)
{
    int idx, channel[2];
    sdma_chan_desc_t chan_desc[2];
    trans_done = FALSE;

    /*Setup interrupt */
    sdma_setup_interrupt();

    uart_access_config();
    ccm_clock_gates_on();

    printf("UART5 loopback test with interrupt supported.\n");

    MEM_VIRTUAL_2_PHYSICAL(tx_buf, sizeof(tx_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(rx_buf, sizeof(tx_buf), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(env_buf, sizeof(env_buffer), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);
    MEM_VIRTUAL_2_PHYSICAL(bd, sizeof(bd), MEM_PRO_UNCACHEABLE | MEM_PRO_UNBUFFERABEL);

    /* Initialize buffers for testing */
    memset(tx_buf, 0x5A, sizeof(tx_buf));
    memset(rx_buf, 0x00, sizeof(rx_buf));

    /* Initialize SDMA */
    printf("Initialize SDMA environment.\n");
    if (SDMA_RETV_SUCCESS != sdma_init((uint32_t *)env_buffer, SDMA_IPS_HOST_BASE_ADDR)) {
        printf("SDMA initialization failed.\n");
        return FALSE;
    }

    uint32_t script_addr;
    if (SDMA_RETV_SUCCESS != sdma_lookup_script(SDMA_MCU_2_APP, &script_addr)) {
        printf("Invalid script.\n");
        return FALSE;
    }

    /* Setup channel descriptor */
    chan_desc[0].script_addr = script_addr;
    chan_desc[0].dma_mask[0] = chan_desc[0].dma_mask[1] = 0;
    chan_desc[0].dma_mask[SDMA_EVENT_UART5_TX / 32] = 0x01 << (SDMA_EVENT_UART5_TX % 32);   /*uart5 tx fifo event */
    chan_desc[0].priority = SDMA_CHANNEL_PRIORITY_LOW;
    for (idx = 0; idx < 8; idx++) {
        chan_desc[0].gpr[idx] = 0;
    }
    chan_desc[0].gpr[0] = chan_desc[0].dma_mask[1];
    chan_desc[0].gpr[1] = chan_desc[0].dma_mask[0];
    chan_desc[0].gpr[6] = UART5_BASE_ADDR + 0x40;   /*tx fifo address */
    chan_desc[0].gpr[7] = TX_FIFO_WATERMARK_LEVEL;  /*water mark */

    /* Setup buffer descriptors */
    bd[0].mode = SDMA_FLAGS_BUSY | SDMA_FLAGS_WRAP | SDMA_FLAGS_BW8 | sizeof(tx_buf);
    bd[0].buf_addr = (uint32_t)tx_buf;

    /* Open channel */
    printf("Open SDMA channel for transmit.\n");
    channel[0] = sdma_channel_request(&chan_desc[0], (sdma_bd_p) (&bd[0]));
    if (channel[0] < 0) {
        printf("Channel request failed.\n");
        return FALSE;
    }

    if (SDMA_RETV_SUCCESS != sdma_lookup_script(SDMA_APP_2_MCU, &script_addr)) {
        printf("Invalid script.\n");
        return FALSE;
    }

    /* Setup channel descriptor */
    chan_desc[1].script_addr = script_addr;
    chan_desc[1].dma_mask[0] = chan_desc[1].dma_mask[1] = 0;
    chan_desc[1].dma_mask[SDMA_EVENT_UART5_RX / 32] = 0x01 << (SDMA_EVENT_UART5_RX % 32);   /*uart5 tx fifo event */
    chan_desc[1].priority = SDMA_CHANNEL_PRIORITY_LOW;
    for (idx = 0; idx < 8; idx++) {
        chan_desc[1].gpr[idx] = 0;
    }
    chan_desc[1].gpr[0] = chan_desc[1].dma_mask[1];
    chan_desc[1].gpr[1] = chan_desc[1].dma_mask[0];
    chan_desc[1].gpr[6] = UART5_BASE_ADDR + 0x0;    /*rx fifo address */
    chan_desc[1].gpr[7] = RX_FIFO_WATERMARK_LEVEL;  /*water mark */

    /* Setup buffer descriptor */
    bd[1].mode =
        SDMA_FLAGS_BUSY | SDMA_FLAGS_WRAP | SDMA_FLAGS_INTR | SDMA_FLAGS_BW8 | sizeof(rx_buf);
    bd[1].buf_addr = (uint32_t)rx_buf;

    /* Open channel */
    printf("Open SDMA channel for receive.\n");
    channel[1] = sdma_channel_request(&chan_desc[1], (sdma_bd_p) (&bd[1]));
    if (channel[1] < 0) {
        printf("Channel request failed.\n");
        return FALSE;
    }

    sdma_channel_isr_attach(channel[1], uart5_trans_isr);
    /* Start channels */
    printf("Channel %d and Channel %d opened, starting transfer...\n", channel[0], channel[1]);
    sdma_channel_start(channel[0]);
    sdma_channel_start(channel[1]);

    uart_loopback_init(&uart5_sdma_test, 115200);
    /*Wait transfer finished */
    while (!trans_done) ;

    /* Stop channels */
    printf("Transfer completed. Stop channels.\n");
    sdma_channel_stop(channel[0]);
    sdma_channel_stop(channel[1]);

    /*Transfer completed. Close channels so they can be used by other applications. */
    sdma_channel_release(channel[0]);
    sdma_channel_release(channel[1]);
    sdma_deinit();

    /* Check data transfered */
    printf("Verify data transfered.\n");
    for (idx = 0; idx < sizeof(tx_buf) / sizeof(tx_buf[0]); idx++) {
        if (tx_buf[idx] != rx_buf[idx]) {
            printf("Word %d mismatch: 0x%x, 0x%x\n", idx + 1, tx_buf[idx], rx_buf[idx]);
            return FALSE;
        }
    }

    return TRUE;
}
