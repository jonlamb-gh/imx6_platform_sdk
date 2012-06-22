/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file epit.c
 * @brief EPIT driver source file.
 *
 * @ingroup diag_timer
 */

#include "hardware.h"
#include "timer/epit.h"
#include "timer/timer.h"

/*!
 * @brief Reload the counter with a known value.
 *
 * @param port Pointer to the EPIT module structure.
 * @param load_val Value loaded into the timer counter.
 */
void epit_reload_counter(struct hw_module *port, uint32_t load_val)
{
    struct mx_epit *pepit = (struct mx_epit *)port->base;

    /* set the load register especially if RLD=reload_mode=SET_AND_FORGET=1 */
    pepit->epitlr = load_val;
}

/*!
 * @brief Get the counter value.
 * 
 *
 * @param   port Pointer to the EPIT module structure.
 * @return  Value of the counter register.
 */
uint32_t epit_get_counter_value(struct hw_module *port)
{
    struct mx_epit *pepit = (struct mx_epit *)port->base;

    return pepit->epitcnr;
}

/*!
 * @brief Set the output compare register.
 * 
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   Value of the compare register.
 */
void epit_set_compare_event(struct hw_module *port, uint32_t compare_val)
{
    struct mx_epit *pepit = (struct mx_epit *)port->base;

    pepit->epitcmpr = compare_val;
}

/*!
 * @brief Get the output compare status flag and clear it if set.
 * 
 * This function can typically be used for polling method, but
 * is also used to clear the status compare flag in IRQ mode.
 *
 * @param   port Pointer to the EPIT module structure.
 * @return  Value of the compare event flag.
 */
uint32_t epit_get_compare_event(struct hw_module *port)
{
    struct mx_epit *pepit = (struct mx_epit *)port->base;
    uint32_t status_register;

    /* get the status */
    status_register = pepit->epitsr;
    /* clear it if found set */
    if (status_register == EPITSR_OCIF)
        pepit->epitsr |= EPITSR_OCIF;

    /* return the read value before the bit was cleared */
    return status_register;
}

/*!
 * @brief Disable the counter.
 *
 * It saves energy when not used.
 *
 * @param   port Pointer to the EPIT module structure.
 */
void epit_counter_disable(struct hw_module *port)
{
    struct mx_epit *pepit = (struct mx_epit *)port->base;

    /* temporary workaround for the discovered issue when disabling the
     * counter during end of count/reload/set compare flag ??.
     * Set to the max value so that it ensures that the counter couldn't
     * reach 0 when it is disabled.
     */
    pepit->epitlr = 0xFFFFFFFF;

    /* disable the counter */
    pepit->epitcr &= ~EPITCR_EN;

    /* ensure to leave the counter in a proper state
       by disabling the output compare interrupt */
    pepit->epitcr &= ~EPITCR_OCIEN;
    /* and clearing possible remaining compare event */
    pepit->epitsr |= EPITSR_OCIF;
}

/*!
 * @brief Enable the EPIT module. 
 *
 * Used typically when the epit_init is done, and other interrupt related settings are ready.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   load_val Load value from where the counter starts.
 * @param   irq_mode Interrupt mode: IRQ_MODE or POLLING_MODE.
 */
void epit_counter_enable(struct hw_module *port, uint32_t load_val, uint32_t irq_mode)
{
    struct mx_epit *pepit = (struct mx_epit *)port->base;

    /* set the load register especially if RLD=reload_mode=SET_AND_FORGET=1
       and if the value is different from 0 which is the lowest counter value */
    if(load_val != 0)
        pepit->epitlr = load_val;

    /* ensure to start the counter in a proper state
       by clearing possible remaining compare event */
    pepit->epitsr |= EPITSR_OCIF;

    /* set the mode when the output compare event occur: IRQ or polling */
    if (irq_mode == IRQ_MODE)
        pepit->epitcr |= EPITCR_OCIEN;
    else    /* polling */
        pepit->epitcr &= ~EPITCR_OCIEN;

    /* finally, enable the counter */
    pepit->epitcr |= EPITCR_EN;
}

/*!
 * @brief Setup EPIT interrupt.
 *
 * It enables or disables the related HW module interrupt, and attached the related sub-routine
 * into the vector table.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   state ENABLE or DISABLE the interrupt.
 */
void epit_setup_interrupt(struct hw_module *port, uint8_t state)
{
    if (state == TRUE) {    
        /* register the IRQ sub-routine */
        register_interrupt_routine(port->irq_id, port->irq_subroutine);
        /* enable the IRQ */
        enable_interrupt(port->irq_id, CPU_0, 0);
    }
    else
        /* disable the IRQ */
        disable_interrupt(port->irq_id, CPU_0);
}

/*!
 * @brief Initialize the EPIT timer.
 *
 * @param   port Pointer to the EPIT module structure.
 * @param   clock_src Source clock of the counter: CLKSRC_OFF, CLKSRC_IPG_CLK,
 *                      CLKSRC_PER_CLK, CLKSRC_CKIL.
 * @param   prescaler Prescaler of source clock from 1 to 4096.
 * @param   reload_mode Counter reload mode: FREE_RUNNING or SET_AND_FORGET.
 * @param   load_val Load value from where the counter start.
 * @param   low_power_mode Low power during which the timer is enabled:
 *                           WAIT_MODE_EN and/or STOP_MODE_EN.
 */
void epit_init(struct hw_module *port, uint32_t clock_src, uint32_t prescaler,
               uint32_t reload_mode, uint32_t load_val, uint32_t low_power_mode)
{
    struct mx_epit *pepit = (struct mx_epit *)port->base;
    uint32_t control_reg_tmp = 0;

    /* enable the source clocks to the EPIT port */
    clock_gating_config(port->base, CLOCK_ON);

    /* start with a known state by disabling and reseting the module */
    pepit->epitcr = EPITCR_SWR;
    /* wait for the reset to complete */
    while ((pepit->epitcr & EPITCR_SWR) != 0) ;

    /* set the reference source clock for the counter */
    control_reg_tmp |= EPITCR_CLKSRC(clock_src);

    /* set the counter clock prescaler value - 0 to 4095 */
    control_reg_tmp |= EPITCR_PRESCALAR(prescaler-1);

    /* set the reload mode */
    control_reg_tmp |= reload_mode;

    /* set behavior for low power mode */
    if (low_power_mode & WAIT_MODE_EN)
        control_reg_tmp |= EPITCR_WAITEN;
    if (low_power_mode & STOP_MODE_EN)
        control_reg_tmp |= EPITCR_STOPEN;

    /* make the counter start from a known value when enabled, this is loaded from
       EPITLR register if RLD=reload_mode=1 or 0xFFFFFFFF if RLD=reload_mode=0 */
    control_reg_tmp |= EPITCR_IOVW | EPITCR_ENMOD;

    /* finally write the control register */
    pepit->epitcr = control_reg_tmp;

    /* initialize the load register especially if RLD=reload_mode=SET_AND_FORGET=1 
       and if the value is different from 0 which is the lowest counter value */
    if(load_val != 0)
        pepit->epitlr = load_val;
}