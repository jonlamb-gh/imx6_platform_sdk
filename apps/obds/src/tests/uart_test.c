/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file uart_test.c
 * @brief UART driver unit test.
 * @ingroup diag_uart
 */

#include <stdio.h>
#include "obds.h"
#include "soc_memory_map.h"
#include "irq_numbers.h"
#include "uart/imx_uart.h"

void uart_interrupt_handler(void);

/* UART3 port is free for i.MX6DQ/SDL and i.MX53 platforms */
static hw_module_t uart_port = {
    "UART3 for test",
    3,
    UART3_BASE_ADDR,
    27000000,
    IMX_INT_UART3,
    &uart_interrupt_handler,
};

static volatile uint8_t g_wait_for_irq;

static const char * const uart_test_name = "UART Test";

/*! 
 * UART interrupt handler.
 *
 * @return  none
 */
void uart_interrupt_handler(void)
{
    uint8_t read_char;

    read_char = uart_getchar(&uart_port);
    printf("IRQ subroutine of tested UART - Read char is %c\n", read_char);
    g_wait_for_irq = 0;
}

/*! 
 * UART test. The tested port is configured to generate an IRQ everytime
 * a data is received. The port is configured in loopback.
 * The debug/console port is used to receive a character typed in a terminal.
 * This character is sent to the tested UART Tx FIFO, and the IRQ routine
 * triggered when the data is received display this character to the terminal.
 * It is like an echo test which uses the tested UART for the echo.
 * 
 * @return TEST_PASSED or TEST_FAILED
 */
menu_action_t uart_test(const menu_context_t* const context, void* const param)
{
    uint8_t sel;
    
	const char* const indent = menu_get_indent(context);

    if ( prompt_run_test(uart_test_name, indent) != TEST_CONTINUE )
    {
    	*(test_return_t*)param = TEST_BYPASSED;
    	return MENU_CONTINUE;
    }

    printf("\n%s---- Running UART test, type 'x' to exit.\n", indent);

    /* Initialize the UART port */
    uart_init(&uart_port, 115200, PARITY_NONE, STOPBITS_ONE, EIGHTBITS, FLOWCTRL_OFF);
    /* Set the IRQ mode for the Rx FIFO */
    uart_set_FIFO_mode(&uart_port, RX_FIFO, 1, IRQ_MODE);
    /* Enable loopback mode */
    uart_set_loopback_mode(&uart_port, TRUE);
    /* Set the ISR and enable the interrupts for UART3 */
    uart_setup_interrupt(&uart_port, TRUE);

    do {
        g_wait_for_irq = 1;
        printf("%sPlease type a character - x to exit:\n", indent);
        do {
            sel = getchar();
        } while (sel == (uint8_t) 0xFF);

        if (sel == 'x') {
            printf("%s\nTest exit.\n", indent);
            /* Disable the interrupts for UART3 */
            uart_setup_interrupt(&uart_port, FALSE);
            break;
        }

        /* send the character to the tested UART */
        /* it will be displayed once read in the tested UART ISR */
        uart_putchar(&uart_port, &sel);
        /* wait for ISR to clear the flag before continuing */
        while (g_wait_for_irq == 1) ;

    } while (1);

    return 0;
}
