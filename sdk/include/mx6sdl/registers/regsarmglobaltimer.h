/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_ARMGLOBALTIMER_REGISTERS_H__
#define __HW_ARMGLOBALTIMER_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SDL ARMGLOBALTIMER registers defined in this header file.
 *
 * - HW_ARMGLOBALTIMER_COUNTER0 - Global Timer Counter Registers
 * - HW_ARMGLOBALTIMER_COUNTER1 - Global Timer Counter Registers
 * - HW_ARMGLOBALTIMER_CONTROL - Global Timer Control Register
 * - HW_ARMGLOBALTIMER_IRQSTATUS - Global Timer Interrupt Status Register
 * - HW_ARMGLOBALTIMER_COMPARATOR0 - Global Timer Comparator Value Registers
 * - HW_ARMGLOBALTIMER_COMPARATOR1 - Global Timer Comparator Value Registers
 * - HW_ARMGLOBALTIMER_AUTOINCREMENT - Global Timer Auto-increment Register
 *
 * - hw_armglobaltimer_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ARMGLOBALTIMER_BASE
#define HW_ARMGLOBALTIMER_INSTANCE_COUNT (0) //!< Number of instances of the ARMGLOBALTIMER module.
#define REGS_ARMGLOBALTIMER_BASE (0x00000000) //!< Base address for ARMGLOBALTIMER.
#endif
//@}


//-------------------------------------------------------------------------------------------
// HW_ARMGLOBALTIMER_COUNTER0 - Global Timer Counter Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ARMGLOBALTIMER_COUNTER0 - Global Timer Counter Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * There are two timer counter registers. They are the lower 32-bit timer counter at offset 0x00 and
 * the upper 32-bit timer counter at offset 0x04.
 */
typedef union _hw_armglobaltimer_counter0
{
    reg32_t U;
    struct _hw_armglobaltimer_counter0_bitfields
    {
        unsigned VALUE : 32; //!< [31:0] 32-bits of the counter value.
    } B;
} hw_armglobaltimer_counter0_t;
#endif

/*
 * constants & macros for entire ARMGLOBALTIMER_COUNTER0 register
 */
#define HW_ARMGLOBALTIMER_COUNTER0_ADDR      (REGS_ARMGLOBALTIMER_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_ARMGLOBALTIMER_COUNTER0           (*(volatile hw_armglobaltimer_counter0_t *) HW_ARMGLOBALTIMER_COUNTER0_ADDR)
#define HW_ARMGLOBALTIMER_COUNTER0_RD()      (HW_ARMGLOBALTIMER_COUNTER0.U)
#define HW_ARMGLOBALTIMER_COUNTER0_WR(v)     (HW_ARMGLOBALTIMER_COUNTER0.U = (v))
#define HW_ARMGLOBALTIMER_COUNTER0_SET(v)    (HW_ARMGLOBALTIMER_COUNTER0_WR(HW_ARMGLOBALTIMER_COUNTER0_RD() |  (v)))
#define HW_ARMGLOBALTIMER_COUNTER0_CLR(v)    (HW_ARMGLOBALTIMER_COUNTER0_WR(HW_ARMGLOBALTIMER_COUNTER0_RD() & ~(v)))
#define HW_ARMGLOBALTIMER_COUNTER0_TOG(v)    (HW_ARMGLOBALTIMER_COUNTER0_WR(HW_ARMGLOBALTIMER_COUNTER0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ARMGLOBALTIMER_COUNTER0 bitfields
 */

/* --- Register HW_ARMGLOBALTIMER_COUNTER0, field VALUE[31:0] (RW)
 *
 * 32-bits of the counter value.
 */

#define BP_ARMGLOBALTIMER_COUNTER0_VALUE      (0)      //!< Bit position for ARMGLOBALTIMER_COUNTER0_VALUE.
#define BM_ARMGLOBALTIMER_COUNTER0_VALUE      (0xffffffff)  //!< Bit mask for ARMGLOBALTIMER_COUNTER0_VALUE.

//! @brief Get value of ARMGLOBALTIMER_COUNTER0_VALUE from a register value.
#define BG_ARMGLOBALTIMER_COUNTER0_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_COUNTER0_VALUE) >> BP_ARMGLOBALTIMER_COUNTER0_VALUE)

//! @brief Format value for bitfield ARMGLOBALTIMER_COUNTER0_VALUE.
#define BF_ARMGLOBALTIMER_COUNTER0_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_COUNTER0_VALUE) & BM_ARMGLOBALTIMER_COUNTER0_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE field to a new value.
#define BW_ARMGLOBALTIMER_COUNTER0_VALUE(v)   (HW_ARMGLOBALTIMER_COUNTER0_WR((HW_ARMGLOBALTIMER_COUNTER0_RD() & ~BM_ARMGLOBALTIMER_COUNTER0_VALUE) | BF_ARMGLOBALTIMER_COUNTER0_VALUE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ARMGLOBALTIMER_COUNTER1 - Global Timer Counter Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ARMGLOBALTIMER_COUNTER1 - Global Timer Counter Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * There are two timer counter registers. They are the lower 32-bit timer counter at offset 0x00 and
 * the upper 32-bit timer counter at offset 0x04.
 */
typedef union _hw_armglobaltimer_counter1
{
    reg32_t U;
    struct _hw_armglobaltimer_counter1_bitfields
    {
        unsigned VALUE : 32; //!< [31:0] 32-bits of the counter value.
    } B;
} hw_armglobaltimer_counter1_t;
#endif

/*
 * constants & macros for entire ARMGLOBALTIMER_COUNTER1 register
 */
#define HW_ARMGLOBALTIMER_COUNTER1_ADDR      (REGS_ARMGLOBALTIMER_BASE + 0x204)

#ifndef __LANGUAGE_ASM__
#define HW_ARMGLOBALTIMER_COUNTER1           (*(volatile hw_armglobaltimer_counter1_t *) HW_ARMGLOBALTIMER_COUNTER1_ADDR)
#define HW_ARMGLOBALTIMER_COUNTER1_RD()      (HW_ARMGLOBALTIMER_COUNTER1.U)
#define HW_ARMGLOBALTIMER_COUNTER1_WR(v)     (HW_ARMGLOBALTIMER_COUNTER1.U = (v))
#define HW_ARMGLOBALTIMER_COUNTER1_SET(v)    (HW_ARMGLOBALTIMER_COUNTER1_WR(HW_ARMGLOBALTIMER_COUNTER1_RD() |  (v)))
#define HW_ARMGLOBALTIMER_COUNTER1_CLR(v)    (HW_ARMGLOBALTIMER_COUNTER1_WR(HW_ARMGLOBALTIMER_COUNTER1_RD() & ~(v)))
#define HW_ARMGLOBALTIMER_COUNTER1_TOG(v)    (HW_ARMGLOBALTIMER_COUNTER1_WR(HW_ARMGLOBALTIMER_COUNTER1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ARMGLOBALTIMER_COUNTER1 bitfields
 */

/* --- Register HW_ARMGLOBALTIMER_COUNTER1, field VALUE[31:0] (RW)
 *
 * 32-bits of the counter value.
 */

#define BP_ARMGLOBALTIMER_COUNTER1_VALUE      (0)      //!< Bit position for ARMGLOBALTIMER_COUNTER1_VALUE.
#define BM_ARMGLOBALTIMER_COUNTER1_VALUE      (0xffffffff)  //!< Bit mask for ARMGLOBALTIMER_COUNTER1_VALUE.

//! @brief Get value of ARMGLOBALTIMER_COUNTER1_VALUE from a register value.
#define BG_ARMGLOBALTIMER_COUNTER1_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_COUNTER1_VALUE) >> BP_ARMGLOBALTIMER_COUNTER1_VALUE)

//! @brief Format value for bitfield ARMGLOBALTIMER_COUNTER1_VALUE.
#define BF_ARMGLOBALTIMER_COUNTER1_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_COUNTER1_VALUE) & BM_ARMGLOBALTIMER_COUNTER1_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE field to a new value.
#define BW_ARMGLOBALTIMER_COUNTER1_VALUE(v)   (HW_ARMGLOBALTIMER_COUNTER1_WR((HW_ARMGLOBALTIMER_COUNTER1_RD() & ~BM_ARMGLOBALTIMER_COUNTER1_VALUE) | BF_ARMGLOBALTIMER_COUNTER1_VALUE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ARMGLOBALTIMER_CONTROL - Global Timer Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ARMGLOBALTIMER_CONTROL - Global Timer Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Configuration and control of the Global Timer.
 */
typedef union _hw_armglobaltimer_control
{
    reg32_t U;
    struct _hw_armglobaltimer_control_bitfields
    {
        unsigned TIMER_ENABLE : 1; //!< [0] Timer enable.
        unsigned COMP_ENABLE : 1; //!< [1] This bit is banked per Cortex-A9 processor.
        unsigned IRQ_ENABLE : 1; //!< [2] This bit is banked per Cortex-A9 processor.
        unsigned AUTO_INCREMENT : 1; //!< [3] This bit is banked per Cortex-A9 processor.
        unsigned RESERVED0 : 4; //!< [7:4] Reserved
        unsigned PRESCALER : 8; //!< [15:8] The prescaler modifies the clock period for the decrementing event for the Counter Register.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved.
    } B;
} hw_armglobaltimer_control_t;
#endif

/*
 * constants & macros for entire ARMGLOBALTIMER_CONTROL register
 */
#define HW_ARMGLOBALTIMER_CONTROL_ADDR      (REGS_ARMGLOBALTIMER_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_ARMGLOBALTIMER_CONTROL           (*(volatile hw_armglobaltimer_control_t *) HW_ARMGLOBALTIMER_CONTROL_ADDR)
#define HW_ARMGLOBALTIMER_CONTROL_RD()      (HW_ARMGLOBALTIMER_CONTROL.U)
#define HW_ARMGLOBALTIMER_CONTROL_WR(v)     (HW_ARMGLOBALTIMER_CONTROL.U = (v))
#define HW_ARMGLOBALTIMER_CONTROL_SET(v)    (HW_ARMGLOBALTIMER_CONTROL_WR(HW_ARMGLOBALTIMER_CONTROL_RD() |  (v)))
#define HW_ARMGLOBALTIMER_CONTROL_CLR(v)    (HW_ARMGLOBALTIMER_CONTROL_WR(HW_ARMGLOBALTIMER_CONTROL_RD() & ~(v)))
#define HW_ARMGLOBALTIMER_CONTROL_TOG(v)    (HW_ARMGLOBALTIMER_CONTROL_WR(HW_ARMGLOBALTIMER_CONTROL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ARMGLOBALTIMER_CONTROL bitfields
 */

/* --- Register HW_ARMGLOBALTIMER_CONTROL, field TIMER_ENABLE[0] (RW)
 *
 * Timer enable.
 *
 * Values:
 * DISABLED = 0 - Timer is disabled and the counter does not increment. All registers can still be read and written.
 * ENABLED = 1 - Timer is enabled and the counter increments normally.
 */

#define BP_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE      (0)      //!< Bit position for ARMGLOBALTIMER_CONTROL_TIMER_ENABLE.
#define BM_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE      (0x00000001)  //!< Bit mask for ARMGLOBALTIMER_CONTROL_TIMER_ENABLE.

//! @brief Get value of ARMGLOBALTIMER_CONTROL_TIMER_ENABLE from a register value.
#define BG_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE) >> BP_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE)

//! @brief Format value for bitfield ARMGLOBALTIMER_CONTROL_TIMER_ENABLE.
#define BF_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE) & BM_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIMER_ENABLE field to a new value.
#define BW_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE(v)   (HW_ARMGLOBALTIMER_CONTROL_WR((HW_ARMGLOBALTIMER_CONTROL_RD() & ~BM_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE) | BF_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE(v)))
#endif

#define BV_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE__DISABLED (0x0) //!< Timer is disabled and the counter does not increment. All registers can still be read and written.
#define BV_ARMGLOBALTIMER_CONTROL_TIMER_ENABLE__ENABLED (0x1) //!< Timer is enabled and the counter increments normally.

/* --- Register HW_ARMGLOBALTIMER_CONTROL, field COMP_ENABLE[1] (RW)
 *
 * This bit is banked per Cortex-A9 processor. If set, it enables the comparison between the 64-bit
 * Timer Counter and the related 64-bit Comparator Register. When the Auto-increment and Comp enable
 * bits are set, an IRQ is generated every auto-increment register value.
 *
 * Values:
 * DISABLED = 0 - Comparison is disabled.
 * ENABLED = 1 - Comparison is enabled.
 */

#define BP_ARMGLOBALTIMER_CONTROL_COMP_ENABLE      (1)      //!< Bit position for ARMGLOBALTIMER_CONTROL_COMP_ENABLE.
#define BM_ARMGLOBALTIMER_CONTROL_COMP_ENABLE      (0x00000002)  //!< Bit mask for ARMGLOBALTIMER_CONTROL_COMP_ENABLE.

//! @brief Get value of ARMGLOBALTIMER_CONTROL_COMP_ENABLE from a register value.
#define BG_ARMGLOBALTIMER_CONTROL_COMP_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_CONTROL_COMP_ENABLE) >> BP_ARMGLOBALTIMER_CONTROL_COMP_ENABLE)

//! @brief Format value for bitfield ARMGLOBALTIMER_CONTROL_COMP_ENABLE.
#define BF_ARMGLOBALTIMER_CONTROL_COMP_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_CONTROL_COMP_ENABLE) & BM_ARMGLOBALTIMER_CONTROL_COMP_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the COMP_ENABLE field to a new value.
#define BW_ARMGLOBALTIMER_CONTROL_COMP_ENABLE(v)   (HW_ARMGLOBALTIMER_CONTROL_WR((HW_ARMGLOBALTIMER_CONTROL_RD() & ~BM_ARMGLOBALTIMER_CONTROL_COMP_ENABLE) | BF_ARMGLOBALTIMER_CONTROL_COMP_ENABLE(v)))
#endif

#define BV_ARMGLOBALTIMER_CONTROL_COMP_ENABLE__DISABLED (0x0) //!< Comparison is disabled.
#define BV_ARMGLOBALTIMER_CONTROL_COMP_ENABLE__ENABLED (0x1) //!< Comparison is enabled.

/* --- Register HW_ARMGLOBALTIMER_CONTROL, field IRQ_ENABLE[2] (RW)
 *
 * This bit is banked per Cortex-A9 processor. If set, the interrupt ID 27 is set as pending in the
 * Interrupt Distributor when the event flag is set in the Timer Status Register.
 *
 * Values:
 * DISABLED = 0 - Interrupts are disabled.
 * ENABLED = 1 - Interrupts are enabled.
 */

#define BP_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE      (2)      //!< Bit position for ARMGLOBALTIMER_CONTROL_IRQ_ENABLE.
#define BM_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE      (0x00000004)  //!< Bit mask for ARMGLOBALTIMER_CONTROL_IRQ_ENABLE.

//! @brief Get value of ARMGLOBALTIMER_CONTROL_IRQ_ENABLE from a register value.
#define BG_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE) >> BP_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE)

//! @brief Format value for bitfield ARMGLOBALTIMER_CONTROL_IRQ_ENABLE.
#define BF_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE) & BM_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ_ENABLE field to a new value.
#define BW_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE(v)   (HW_ARMGLOBALTIMER_CONTROL_WR((HW_ARMGLOBALTIMER_CONTROL_RD() & ~BM_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE) | BF_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE(v)))
#endif

#define BV_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE__DISABLED (0x0) //!< Interrupts are disabled.
#define BV_ARMGLOBALTIMER_CONTROL_IRQ_ENABLE__ENABLED (0x1) //!< Interrupts are enabled.

/* --- Register HW_ARMGLOBALTIMER_CONTROL, field AUTO_INCREMENT[3] (RW)
 *
 * This bit is banked per Cortex-A9 processor.
 *
 * Values:
 * SINGLE_SHOT_MODE = 0 - When the counter reaches the comparator value, sets the event flag. It is the responsibility of
 *     software to update the comparator value to get more events.
 * AUTO_INCREMENT_MODE = 1 - Each time the counter reaches the comparator value, the comparator register is incremented with the
 *     auto-increment register, so that more events can be set periodically without any software
 *     updates.
 */

#define BP_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT      (3)      //!< Bit position for ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT.
#define BM_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT      (0x00000008)  //!< Bit mask for ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT.

//! @brief Get value of ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT from a register value.
#define BG_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT) >> BP_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT)

//! @brief Format value for bitfield ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT.
#define BF_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT) & BM_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the AUTO_INCREMENT field to a new value.
#define BW_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT(v)   (HW_ARMGLOBALTIMER_CONTROL_WR((HW_ARMGLOBALTIMER_CONTROL_RD() & ~BM_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT) | BF_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT(v)))
#endif

#define BV_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT__SINGLE_SHOT_MODE (0x0) //!< When the counter reaches the comparator value, sets the event flag. It is the responsibility of software to update the comparator value to get more events.
#define BV_ARMGLOBALTIMER_CONTROL_AUTO_INCREMENT__AUTO_INCREMENT_MODE (0x1) //!< Each time the counter reaches the comparator value, the comparator register is incremented with the auto-increment register, so that more events can be set periodically without any software updates.

/* --- Register HW_ARMGLOBALTIMER_CONTROL, field PRESCALER[15:8] (RW)
 *
 * The prescaler modifies the clock period for the decrementing event for the Counter Register.
 */

#define BP_ARMGLOBALTIMER_CONTROL_PRESCALER      (8)      //!< Bit position for ARMGLOBALTIMER_CONTROL_PRESCALER.
#define BM_ARMGLOBALTIMER_CONTROL_PRESCALER      (0x0000ff00)  //!< Bit mask for ARMGLOBALTIMER_CONTROL_PRESCALER.

//! @brief Get value of ARMGLOBALTIMER_CONTROL_PRESCALER from a register value.
#define BG_ARMGLOBALTIMER_CONTROL_PRESCALER(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_CONTROL_PRESCALER) >> BP_ARMGLOBALTIMER_CONTROL_PRESCALER)

//! @brief Format value for bitfield ARMGLOBALTIMER_CONTROL_PRESCALER.
#define BF_ARMGLOBALTIMER_CONTROL_PRESCALER(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_CONTROL_PRESCALER) & BM_ARMGLOBALTIMER_CONTROL_PRESCALER)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRESCALER field to a new value.
#define BW_ARMGLOBALTIMER_CONTROL_PRESCALER(v)   (HW_ARMGLOBALTIMER_CONTROL_WR((HW_ARMGLOBALTIMER_CONTROL_RD() & ~BM_ARMGLOBALTIMER_CONTROL_PRESCALER) | BF_ARMGLOBALTIMER_CONTROL_PRESCALER(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ARMGLOBALTIMER_IRQSTATUS - Global Timer Interrupt Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ARMGLOBALTIMER_IRQSTATUS - Global Timer Interrupt Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This is a banked register for all Cortex-A9 processors present.
 */
typedef union _hw_armglobaltimer_irqstatus
{
    reg32_t U;
    struct _hw_armglobaltimer_irqstatus_bitfields
    {
        unsigned EVENT_FLAG : 1; //!< [0] The event flag is a sticky bit that is automatically set when the Counter Register reaches the Comparator Register value.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved.
    } B;
} hw_armglobaltimer_irqstatus_t;
#endif

/*
 * constants & macros for entire ARMGLOBALTIMER_IRQSTATUS register
 */
#define HW_ARMGLOBALTIMER_IRQSTATUS_ADDR      (REGS_ARMGLOBALTIMER_BASE + 0x20c)

#ifndef __LANGUAGE_ASM__
#define HW_ARMGLOBALTIMER_IRQSTATUS           (*(volatile hw_armglobaltimer_irqstatus_t *) HW_ARMGLOBALTIMER_IRQSTATUS_ADDR)
#define HW_ARMGLOBALTIMER_IRQSTATUS_RD()      (HW_ARMGLOBALTIMER_IRQSTATUS.U)
#define HW_ARMGLOBALTIMER_IRQSTATUS_WR(v)     (HW_ARMGLOBALTIMER_IRQSTATUS.U = (v))
#define HW_ARMGLOBALTIMER_IRQSTATUS_SET(v)    (HW_ARMGLOBALTIMER_IRQSTATUS_WR(HW_ARMGLOBALTIMER_IRQSTATUS_RD() |  (v)))
#define HW_ARMGLOBALTIMER_IRQSTATUS_CLR(v)    (HW_ARMGLOBALTIMER_IRQSTATUS_WR(HW_ARMGLOBALTIMER_IRQSTATUS_RD() & ~(v)))
#define HW_ARMGLOBALTIMER_IRQSTATUS_TOG(v)    (HW_ARMGLOBALTIMER_IRQSTATUS_WR(HW_ARMGLOBALTIMER_IRQSTATUS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ARMGLOBALTIMER_IRQSTATUS bitfields
 */

/* --- Register HW_ARMGLOBALTIMER_IRQSTATUS, field EVENT_FLAG[0] (W1C)
 *
 * The event flag is a sticky bit that is automatically set when the Counter Register reaches the
 * Comparator Register value. If the timer interrupt is enabled, Interrupt ID 27 is set as pending
 * in the Interrupt Distributor after the event flag is set. The event flag is cleared when written
 * to 1.
 */

#define BP_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG      (0)      //!< Bit position for ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG.
#define BM_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG      (0x00000001)  //!< Bit mask for ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG.

//! @brief Get value of ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG from a register value.
#define BG_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG) >> BP_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG)

//! @brief Format value for bitfield ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG.
#define BF_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG) & BM_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG)

#ifndef __LANGUAGE_ASM__
//! @brief Set the EVENT_FLAG field to a new value.
#define BW_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG(v)   (HW_ARMGLOBALTIMER_IRQSTATUS_WR((HW_ARMGLOBALTIMER_IRQSTATUS_RD() & ~BM_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG) | BF_ARMGLOBALTIMER_IRQSTATUS_EVENT_FLAG(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ARMGLOBALTIMER_COMPARATOR0 - Global Timer Comparator Value Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ARMGLOBALTIMER_COMPARATOR0 - Global Timer Comparator Value Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * There are two timer counter registers. They are the lower 32-bit timer counter at offset 0x00 and
 * the upper 32-bit timer counter at offset 0x04.
 */
typedef union _hw_armglobaltimer_comparator0
{
    reg32_t U;
    struct _hw_armglobaltimer_comparator0_bitfields
    {
        unsigned VALUE : 32; //!< [31:0] 32-bits of the comparator value.
    } B;
} hw_armglobaltimer_comparator0_t;
#endif

/*
 * constants & macros for entire ARMGLOBALTIMER_COMPARATOR0 register
 */
#define HW_ARMGLOBALTIMER_COMPARATOR0_ADDR      (REGS_ARMGLOBALTIMER_BASE + 0x210)

#ifndef __LANGUAGE_ASM__
#define HW_ARMGLOBALTIMER_COMPARATOR0           (*(volatile hw_armglobaltimer_comparator0_t *) HW_ARMGLOBALTIMER_COMPARATOR0_ADDR)
#define HW_ARMGLOBALTIMER_COMPARATOR0_RD()      (HW_ARMGLOBALTIMER_COMPARATOR0.U)
#define HW_ARMGLOBALTIMER_COMPARATOR0_WR(v)     (HW_ARMGLOBALTIMER_COMPARATOR0.U = (v))
#define HW_ARMGLOBALTIMER_COMPARATOR0_SET(v)    (HW_ARMGLOBALTIMER_COMPARATOR0_WR(HW_ARMGLOBALTIMER_COMPARATOR0_RD() |  (v)))
#define HW_ARMGLOBALTIMER_COMPARATOR0_CLR(v)    (HW_ARMGLOBALTIMER_COMPARATOR0_WR(HW_ARMGLOBALTIMER_COMPARATOR0_RD() & ~(v)))
#define HW_ARMGLOBALTIMER_COMPARATOR0_TOG(v)    (HW_ARMGLOBALTIMER_COMPARATOR0_WR(HW_ARMGLOBALTIMER_COMPARATOR0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ARMGLOBALTIMER_COMPARATOR0 bitfields
 */

/* --- Register HW_ARMGLOBALTIMER_COMPARATOR0, field VALUE[31:0] (RW)
 *
 * 32-bits of the comparator value.
 */

#define BP_ARMGLOBALTIMER_COMPARATOR0_VALUE      (0)      //!< Bit position for ARMGLOBALTIMER_COMPARATOR0_VALUE.
#define BM_ARMGLOBALTIMER_COMPARATOR0_VALUE      (0xffffffff)  //!< Bit mask for ARMGLOBALTIMER_COMPARATOR0_VALUE.

//! @brief Get value of ARMGLOBALTIMER_COMPARATOR0_VALUE from a register value.
#define BG_ARMGLOBALTIMER_COMPARATOR0_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_COMPARATOR0_VALUE) >> BP_ARMGLOBALTIMER_COMPARATOR0_VALUE)

//! @brief Format value for bitfield ARMGLOBALTIMER_COMPARATOR0_VALUE.
#define BF_ARMGLOBALTIMER_COMPARATOR0_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_COMPARATOR0_VALUE) & BM_ARMGLOBALTIMER_COMPARATOR0_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE field to a new value.
#define BW_ARMGLOBALTIMER_COMPARATOR0_VALUE(v)   (HW_ARMGLOBALTIMER_COMPARATOR0_WR((HW_ARMGLOBALTIMER_COMPARATOR0_RD() & ~BM_ARMGLOBALTIMER_COMPARATOR0_VALUE) | BF_ARMGLOBALTIMER_COMPARATOR0_VALUE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ARMGLOBALTIMER_COMPARATOR1 - Global Timer Comparator Value Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ARMGLOBALTIMER_COMPARATOR1 - Global Timer Comparator Value Registers (RW)
 *
 * Reset value: 0x00000000
 *
 * There are two timer counter registers. They are the lower 32-bit timer counter at offset 0x00 and
 * the upper 32-bit timer counter at offset 0x04.
 */
typedef union _hw_armglobaltimer_comparator1
{
    reg32_t U;
    struct _hw_armglobaltimer_comparator1_bitfields
    {
        unsigned VALUE : 32; //!< [31:0] 32-bits of the comparator value.
    } B;
} hw_armglobaltimer_comparator1_t;
#endif

/*
 * constants & macros for entire ARMGLOBALTIMER_COMPARATOR1 register
 */
#define HW_ARMGLOBALTIMER_COMPARATOR1_ADDR      (REGS_ARMGLOBALTIMER_BASE + 0x214)

#ifndef __LANGUAGE_ASM__
#define HW_ARMGLOBALTIMER_COMPARATOR1           (*(volatile hw_armglobaltimer_comparator1_t *) HW_ARMGLOBALTIMER_COMPARATOR1_ADDR)
#define HW_ARMGLOBALTIMER_COMPARATOR1_RD()      (HW_ARMGLOBALTIMER_COMPARATOR1.U)
#define HW_ARMGLOBALTIMER_COMPARATOR1_WR(v)     (HW_ARMGLOBALTIMER_COMPARATOR1.U = (v))
#define HW_ARMGLOBALTIMER_COMPARATOR1_SET(v)    (HW_ARMGLOBALTIMER_COMPARATOR1_WR(HW_ARMGLOBALTIMER_COMPARATOR1_RD() |  (v)))
#define HW_ARMGLOBALTIMER_COMPARATOR1_CLR(v)    (HW_ARMGLOBALTIMER_COMPARATOR1_WR(HW_ARMGLOBALTIMER_COMPARATOR1_RD() & ~(v)))
#define HW_ARMGLOBALTIMER_COMPARATOR1_TOG(v)    (HW_ARMGLOBALTIMER_COMPARATOR1_WR(HW_ARMGLOBALTIMER_COMPARATOR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ARMGLOBALTIMER_COMPARATOR1 bitfields
 */

/* --- Register HW_ARMGLOBALTIMER_COMPARATOR1, field VALUE[31:0] (RW)
 *
 * 32-bits of the comparator value.
 */

#define BP_ARMGLOBALTIMER_COMPARATOR1_VALUE      (0)      //!< Bit position for ARMGLOBALTIMER_COMPARATOR1_VALUE.
#define BM_ARMGLOBALTIMER_COMPARATOR1_VALUE      (0xffffffff)  //!< Bit mask for ARMGLOBALTIMER_COMPARATOR1_VALUE.

//! @brief Get value of ARMGLOBALTIMER_COMPARATOR1_VALUE from a register value.
#define BG_ARMGLOBALTIMER_COMPARATOR1_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_COMPARATOR1_VALUE) >> BP_ARMGLOBALTIMER_COMPARATOR1_VALUE)

//! @brief Format value for bitfield ARMGLOBALTIMER_COMPARATOR1_VALUE.
#define BF_ARMGLOBALTIMER_COMPARATOR1_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_COMPARATOR1_VALUE) & BM_ARMGLOBALTIMER_COMPARATOR1_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE field to a new value.
#define BW_ARMGLOBALTIMER_COMPARATOR1_VALUE(v)   (HW_ARMGLOBALTIMER_COMPARATOR1_WR((HW_ARMGLOBALTIMER_COMPARATOR1_RD() & ~BM_ARMGLOBALTIMER_COMPARATOR1_VALUE) | BF_ARMGLOBALTIMER_COMPARATOR1_VALUE(v)))
#endif

//-------------------------------------------------------------------------------------------
// HW_ARMGLOBALTIMER_AUTOINCREMENT - Global Timer Auto-increment Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ARMGLOBALTIMER_AUTOINCREMENT - Global Timer Auto-increment Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This 32-bit register gives the increment value of the Comparator Register when the Auto-increment
 * bit is set in the Timer Control Register. Each Cortex-A9 processor present has its own Auto-
 * increment Register.  If the comp enable and auto-increment bits are set when the global counter
 * reaches the Comparator Register value, the comparator is incremented by the auto-increment value,
 * so that a new event can be set periodically.  The global timer is not affected and goes on
 * incrementing.
 */
typedef union _hw_armglobaltimer_autoincrement
{
    reg32_t U;
    struct _hw_armglobaltimer_autoincrement_bitfields
    {
        unsigned VALUE : 32; //!< [31:0] 32-bit auto-increment value.
    } B;
} hw_armglobaltimer_autoincrement_t;
#endif

/*
 * constants & macros for entire ARMGLOBALTIMER_AUTOINCREMENT register
 */
#define HW_ARMGLOBALTIMER_AUTOINCREMENT_ADDR      (REGS_ARMGLOBALTIMER_BASE + 0x218)

#ifndef __LANGUAGE_ASM__
#define HW_ARMGLOBALTIMER_AUTOINCREMENT           (*(volatile hw_armglobaltimer_autoincrement_t *) HW_ARMGLOBALTIMER_AUTOINCREMENT_ADDR)
#define HW_ARMGLOBALTIMER_AUTOINCREMENT_RD()      (HW_ARMGLOBALTIMER_AUTOINCREMENT.U)
#define HW_ARMGLOBALTIMER_AUTOINCREMENT_WR(v)     (HW_ARMGLOBALTIMER_AUTOINCREMENT.U = (v))
#define HW_ARMGLOBALTIMER_AUTOINCREMENT_SET(v)    (HW_ARMGLOBALTIMER_AUTOINCREMENT_WR(HW_ARMGLOBALTIMER_AUTOINCREMENT_RD() |  (v)))
#define HW_ARMGLOBALTIMER_AUTOINCREMENT_CLR(v)    (HW_ARMGLOBALTIMER_AUTOINCREMENT_WR(HW_ARMGLOBALTIMER_AUTOINCREMENT_RD() & ~(v)))
#define HW_ARMGLOBALTIMER_AUTOINCREMENT_TOG(v)    (HW_ARMGLOBALTIMER_AUTOINCREMENT_WR(HW_ARMGLOBALTIMER_AUTOINCREMENT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ARMGLOBALTIMER_AUTOINCREMENT bitfields
 */

/* --- Register HW_ARMGLOBALTIMER_AUTOINCREMENT, field VALUE[31:0] (RW)
 *
 * 32-bit auto-increment value.
 */

#define BP_ARMGLOBALTIMER_AUTOINCREMENT_VALUE      (0)      //!< Bit position for ARMGLOBALTIMER_AUTOINCREMENT_VALUE.
#define BM_ARMGLOBALTIMER_AUTOINCREMENT_VALUE      (0xffffffff)  //!< Bit mask for ARMGLOBALTIMER_AUTOINCREMENT_VALUE.

//! @brief Get value of ARMGLOBALTIMER_AUTOINCREMENT_VALUE from a register value.
#define BG_ARMGLOBALTIMER_AUTOINCREMENT_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_ARMGLOBALTIMER_AUTOINCREMENT_VALUE) >> BP_ARMGLOBALTIMER_AUTOINCREMENT_VALUE)

//! @brief Format value for bitfield ARMGLOBALTIMER_AUTOINCREMENT_VALUE.
#define BF_ARMGLOBALTIMER_AUTOINCREMENT_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_ARMGLOBALTIMER_AUTOINCREMENT_VALUE) & BM_ARMGLOBALTIMER_AUTOINCREMENT_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the VALUE field to a new value.
#define BW_ARMGLOBALTIMER_AUTOINCREMENT_VALUE(v)   (HW_ARMGLOBALTIMER_AUTOINCREMENT_WR((HW_ARMGLOBALTIMER_AUTOINCREMENT_RD() & ~BM_ARMGLOBALTIMER_AUTOINCREMENT_VALUE) | BF_ARMGLOBALTIMER_AUTOINCREMENT_VALUE(v)))
#endif


/*!
 * @brief All ARMGLOBALTIMER module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_armglobaltimer
{
    reg32_t _reserved0[128];
    volatile hw_armglobaltimer_counter0_t COUNTER0; //!< Global Timer Counter Registers
    volatile hw_armglobaltimer_counter1_t COUNTER1; //!< Global Timer Counter Registers
    volatile hw_armglobaltimer_control_t CONTROL; //!< Global Timer Control Register
    volatile hw_armglobaltimer_irqstatus_t IRQSTATUS; //!< Global Timer Interrupt Status Register
    volatile hw_armglobaltimer_comparator0_t COMPARATOR0; //!< Global Timer Comparator Value Registers
    volatile hw_armglobaltimer_comparator1_t COMPARATOR1; //!< Global Timer Comparator Value Registers
    volatile hw_armglobaltimer_autoincrement_t AUTOINCREMENT; //!< Global Timer Auto-increment Register
} hw_armglobaltimer_t;
#pragma pack()

//! @brief Macro to access all ARMGLOBALTIMER registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ARMGLOBALTIMER(0)</code>.
#define HW_ARMGLOBALTIMER     (*(volatile hw_armglobaltimer_t *) REGS_ARMGLOBALTIMER_BASE)

#endif


#endif // __HW_ARMGLOBALTIMER_REGISTERS_H__