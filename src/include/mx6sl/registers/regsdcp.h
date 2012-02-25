/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _DCP_H
#define _DCP_H

#include "regs.h"

/*
 * Registers defined in this header file.
 *
 * - HW_DCP_CTRL - DCP Control Register 0
 * - HW_DCP_STAT - DCP Status Register
 * - HW_DCP_CHANNELCTRL - DCP Channel Control Register
 * - HW_DCP_CAPABILITY0 - DCP Capability 0 Register
 * - HW_DCP_CAPABILITY1 - DCP Capability 1 Register
 * - HW_DCP_CONTEXT - DCP Context Buffer Pointer
 * - HW_DCP_KEY - DCP Key Index
 * - HW_DCP_KEYDATA - DCP Key Data
 * - HW_DCP_PACKET0 - DCP Work Packet 0 Status Register
 * - HW_DCP_PACKET1 - DCP Work Packet 1 Status Register
 * - HW_DCP_PACKET2 - DCP Work Packet 2 Status Register
 * - HW_DCP_PACKET3 - DCP Work Packet 3 Status Register
 * - HW_DCP_PACKET4 - DCP Work Packet 4 Status Register
 * - HW_DCP_PACKET5 - DCP Work Packet 5 Status Register
 * - HW_DCP_PACKET6 - DCP Work Packet 6 Status Register
 * - HW_DCP_CH0CMDPTR - DCP Channel 0 Command Pointer Address Register
 * - HW_DCP_CH0SEMA - DCP Channel 0 Semaphore Register
 * - HW_DCP_CH0STAT - DCP Channel 0 Status Register
 * - HW_DCP_CH0OPTS - DCP Channel 0 Options Register
 * - HW_DCP_CH1CMDPTR - DCP Channel 1 Command Pointer Address Register
 * - HW_DCP_CH1SEMA - DCP Channel 1 Semaphore Register
 * - HW_DCP_CH1STAT - DCP Channel 1 Status Register
 * - HW_DCP_CH1OPTS - DCP Channel 1 Options Register
 * - HW_DCP_CH2CMDPTR - DCP Channel 2 Command Pointer Address Register
 * - HW_DCP_CH2SEMA - DCP Channel 2 Semaphore Register
 * - HW_DCP_CH2STAT - DCP Channel 2 Status Register
 * - HW_DCP_CH2OPTS - DCP Channel 2 Options Register
 * - HW_DCP_CH3CMDPTR - DCP Channel 3 Command Pointer Address Register
 * - HW_DCP_CH3SEMA - DCP Channel 3 Semaphore Register
 * - HW_DCP_CH3STAT - DCP Channel 3 Status Register
 * - HW_DCP_CH3OPTS - DCP Channel 3 Options Register
 * - HW_DCP_DBGSELECT - DCP Debug Select Register
 * - HW_DCP_DBGDATA - DCP Debug Data Register
 * - HW_DCP_PAGETABLE - DCP Page Table Register
 * - HW_DCP_VERSION - DCP Version Register
 *
 * hw_dcp_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_DCP_BASE
#define REGS_DCP_BASE (0x020fc000) //!< Base address for DCP.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CTRL - DCP Control Register 0 (RW)
 *
 * The CTRL register contains controls for the DCP module.  CTRL: 0x000  CTRL_SET: 0x004  CTRL_CLR:
 * 0x008  CTRL_TOG: 0x00C  The Control register contains the primary controls for the DCP block. The
 * present bits indicate which of the sub-features of the block are present in the hardware. The
 * context control bits control how the DCP utilizes it's context buffer and the gather residual
 * writes bit controls how the master handles writing misaligned data to the bus. Each channel and
 * the color-space converter contains an independent interrupt enable.   EXAMPLE
 * DCP_CTRL_SET(BM_DCP_CTRL_SFTRST); DCP_CTRL_CLR(BM_DCP_CTRL_SFTRST | BM_DCP_CTRL_CLKGATE);
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CHANNEL_INTERRUPT_ENABLE : 8; //!< Per-channel interrupt enable bit. When set, the channel's interrupt will get routed to the interrupt controller. Channel 0 is routed to the dcp_vmi_irq signal and the other channels are combined (along with the CRC interrupt) into the dcp_irq signal.
        unsigned RESERVED0 : 1; //!< Reserved, always set to zero.
        unsigned RESERVED1 : 12; //!< Reserved, always set to zero.
        unsigned ENABLE_CONTEXT_SWITCHING : 1; //!< Enable automatic context switching for the channels. Software should set this bit if more than one channel is doing hashing or cipher operations that require context to be saved (for instance, when CBC mode is enabled). By disabling context switching, software can save the 208 bytes used for the context buffer.
        unsigned ENABLE_CONTEXT_CACHING : 1; //!< Software should set this bit to enable caching of contexts between operations. If only a single channel is used for encryption/hashing, enabling caching causes the context to not be reloaded if the channel was the last to be used.
        unsigned GATHER_RESIDUAL_WRITES : 1; //!< Software should set this bit to enable ragged writes to unaligned buffers to be gathered between multiple write operations. This improves performance by removing several byte operations between write bursts. Trailing byte writes are held in a residual write data buffer and combined with a subsequent write to the buffer to form a word write.
        unsigned RESERVED2 : 4; //!< Reserved, always set to zero.
        unsigned PRESENT_SHA : 1; //!< Indicates whether the SHA1/SHA2 functions are present.
        unsigned PRESENT_CRYPTO : 1; //!< Indicates whether the crypto (Cipher/Hash) functions are present.
        unsigned CLKGATE : 1; //!< This bit must be set to zero for normal operation. When set to one it gates off the clocks to the block.
        unsigned SFTRST : 1; //!< Set this bit to zero to enable normal DCP operation. Set this bit to one (default) to disable clocking with the DCP and hold it in its reset (lowest power) state. This bit can be turned on and then off to reset the DCP block to its default state.
    } B;
} hw_dcp_ctrl_t;
#endif

/*
 * constants & macros for entire DCP_CTRL register
 */
#define HW_DCP_CTRL_ADDR      (REGS_DCP_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CTRL           (*(volatile hw_dcp_ctrl_t *) HW_DCP_CTRL_ADDR)
#define HW_DCP_CTRL_RD()      (HW_DCP_CTRL.U)
#define HW_DCP_CTRL_WR(v)     (HW_DCP_CTRL.U = (v))
#define HW_DCP_CTRL_SET(v)    (HW_DCP_CTRL_WR(HW_DCP_CTRL_RD() |  (v)))
#define HW_DCP_CTRL_CLR(v)    (HW_DCP_CTRL_WR(HW_DCP_CTRL_RD() & ~(v)))
#define HW_DCP_CTRL_TOG(v)    (HW_DCP_CTRL_WR(HW_DCP_CTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CTRL bitfields
 */

/* --- Register HW_DCP_CTRL, field CHANNEL_INTERRUPT_ENABLE[7:0] (RW)
 *
 * Per-channel interrupt enable bit. When set, the channel's interrupt will get routed to the
 * interrupt controller. Channel 0 is routed to the dcp_vmi_irq signal and the other channels are
 * combined (along with the CRC interrupt) into the dcp_irq signal.
 *
 * Values:
 * CH0 = 0x01 - 
 * CH1 = 0x02 - 
 * CH2 = 0x04 - 
 * CH3 = 0x08 - 
 */

#define BP_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE      (0)
#define BM_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE(v)   ((((reg32_t) v) << 0) & BM_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE)
#else
#define BF_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE(v)   (((v) << 0) & BM_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CHANNEL_INTERRUPT_ENABLE field to a new value.
#define BW_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE(v)   BF_CS1(DCP_CTRL, CHANNEL_INTERRUPT_ENABLE, v)
#endif

#define BV_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE__CH0 (0x1) //!< 
#define BV_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE__CH1 (0x2) //!< 
#define BV_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE__CH2 (0x4) //!< 
#define BV_DCP_CTRL_CHANNEL_INTERRUPT_ENABLE__CH3 (0x8) //!< 

/* --- Register HW_DCP_CTRL, field ENABLE_CONTEXT_SWITCHING[21:21] (RW)
 *
 * Enable automatic context switching for the channels. Software should set this bit if more than
 * one channel is doing hashing or cipher operations that require context to be saved (for instance,
 * when CBC mode is enabled). By disabling context switching, software can save the 208 bytes used
 * for the context buffer.
 */

#define BP_DCP_CTRL_ENABLE_CONTEXT_SWITCHING      (21)
#define BM_DCP_CTRL_ENABLE_CONTEXT_SWITCHING      (0x00200000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CTRL_ENABLE_CONTEXT_SWITCHING(v)   ((((reg32_t) v) << 21) & BM_DCP_CTRL_ENABLE_CONTEXT_SWITCHING)
#else
#define BF_DCP_CTRL_ENABLE_CONTEXT_SWITCHING(v)   (((v) << 21) & BM_DCP_CTRL_ENABLE_CONTEXT_SWITCHING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_CONTEXT_SWITCHING field to a new value.
#define BW_DCP_CTRL_ENABLE_CONTEXT_SWITCHING(v)   BF_CS1(DCP_CTRL, ENABLE_CONTEXT_SWITCHING, v)
#endif

/* --- Register HW_DCP_CTRL, field ENABLE_CONTEXT_CACHING[22:22] (RW)
 *
 * Software should set this bit to enable caching of contexts between operations. If only a single
 * channel is used for encryption/hashing, enabling caching causes the context to not be reloaded if
 * the channel was the last to be used.
 */

#define BP_DCP_CTRL_ENABLE_CONTEXT_CACHING      (22)
#define BM_DCP_CTRL_ENABLE_CONTEXT_CACHING      (0x00400000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CTRL_ENABLE_CONTEXT_CACHING(v)   ((((reg32_t) v) << 22) & BM_DCP_CTRL_ENABLE_CONTEXT_CACHING)
#else
#define BF_DCP_CTRL_ENABLE_CONTEXT_CACHING(v)   (((v) << 22) & BM_DCP_CTRL_ENABLE_CONTEXT_CACHING)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_CONTEXT_CACHING field to a new value.
#define BW_DCP_CTRL_ENABLE_CONTEXT_CACHING(v)   BF_CS1(DCP_CTRL, ENABLE_CONTEXT_CACHING, v)
#endif

/* --- Register HW_DCP_CTRL, field GATHER_RESIDUAL_WRITES[23:23] (RW)
 *
 * Software should set this bit to enable ragged writes to unaligned buffers to be gathered between
 * multiple write operations. This improves performance by removing several byte operations between
 * write bursts. Trailing byte writes are held in a residual write data buffer and combined with a
 * subsequent write to the buffer to form a word write.
 */

#define BP_DCP_CTRL_GATHER_RESIDUAL_WRITES      (23)
#define BM_DCP_CTRL_GATHER_RESIDUAL_WRITES      (0x00800000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CTRL_GATHER_RESIDUAL_WRITES(v)   ((((reg32_t) v) << 23) & BM_DCP_CTRL_GATHER_RESIDUAL_WRITES)
#else
#define BF_DCP_CTRL_GATHER_RESIDUAL_WRITES(v)   (((v) << 23) & BM_DCP_CTRL_GATHER_RESIDUAL_WRITES)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the GATHER_RESIDUAL_WRITES field to a new value.
#define BW_DCP_CTRL_GATHER_RESIDUAL_WRITES(v)   BF_CS1(DCP_CTRL, GATHER_RESIDUAL_WRITES, v)
#endif

/* --- Register HW_DCP_CTRL, field PRESENT_SHA[28:28] (RO)
 *
 * Indicates whether the SHA1/SHA2 functions are present.
 *
 * Values:
 * Absent = 0x0 - 
 * Present = 0x1 - 
 */

#define BP_DCP_CTRL_PRESENT_SHA      (28)
#define BM_DCP_CTRL_PRESENT_SHA      (0x10000000)

#define BV_DCP_CTRL_PRESENT_SHA__Absent (0x0) //!< 
#define BV_DCP_CTRL_PRESENT_SHA__Present (0x1) //!< 

/* --- Register HW_DCP_CTRL, field PRESENT_CRYPTO[29:29] (RO)
 *
 * Indicates whether the crypto (Cipher/Hash) functions are present.
 *
 * Values:
 * Absent = 0x0 - 
 * Present = 0x1 - 
 */

#define BP_DCP_CTRL_PRESENT_CRYPTO      (29)
#define BM_DCP_CTRL_PRESENT_CRYPTO      (0x20000000)

#define BV_DCP_CTRL_PRESENT_CRYPTO__Absent (0x0) //!< 
#define BV_DCP_CTRL_PRESENT_CRYPTO__Present (0x1) //!< 

/* --- Register HW_DCP_CTRL, field CLKGATE[30:30] (RW)
 *
 * This bit must be set to zero for normal operation. When set to one it gates off the clocks to the
 * block.
 */

#define BP_DCP_CTRL_CLKGATE      (30)
#define BM_DCP_CTRL_CLKGATE      (0x40000000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CTRL_CLKGATE(v)   ((((reg32_t) v) << 30) & BM_DCP_CTRL_CLKGATE)
#else
#define BF_DCP_CTRL_CLKGATE(v)   (((v) << 30) & BM_DCP_CTRL_CLKGATE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_DCP_CTRL_CLKGATE(v)   BF_CS1(DCP_CTRL, CLKGATE, v)
#endif

/* --- Register HW_DCP_CTRL, field SFTRST[31:31] (RW)
 *
 * Set this bit to zero to enable normal DCP operation. Set this bit to one (default) to disable
 * clocking with the DCP and hold it in its reset (lowest power) state. This bit can be turned on
 * and then off to reset the DCP block to its default state.
 */

#define BP_DCP_CTRL_SFTRST      (31)
#define BM_DCP_CTRL_SFTRST      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CTRL_SFTRST(v)   ((((reg32_t) v) << 31) & BM_DCP_CTRL_SFTRST)
#else
#define BF_DCP_CTRL_SFTRST(v)   (((v) << 31) & BM_DCP_CTRL_SFTRST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_DCP_CTRL_SFTRST(v)   BF_CS1(DCP_CTRL, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_STAT - DCP Status Register (RW)
 *
 * The DCP Interrupt Status register provides channel interrupt status information.  STAT: 0x010
 * STAT_SET: 0x014  STAT_CLR: 0x018  STAT_TOG: 0x01C  This register provides status feedback
 * indicating the channel currently performing an operation and which channels have pending
 * operations.   EXAMPLE
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned IRQ : 4; //!< Indicates which channels have pending interrupt requests. Channel 0's interrupt is routed through the dcp_vmi_irq and the other interrupt bits are routed through the dcp_irq.
        unsigned RESERVED0 : 4; //!< Reserved, always set to zero.
        unsigned RESERVED1 : 1; //!< Reserved, always set to zero.
        unsigned RESERVED2 : 7; //!< Reserved, always set to zero.
        unsigned READY_CHANNELS : 8; //!< Indicates which channels are ready to proceed with a transfer (active channel also included). Each bit is a one-hot indicating the request status for the associated channel.
        unsigned CUR_CHANNEL : 4; //!< Current (active) channel (encoded).
        unsigned OTP_KEY_READY : 1; //!< When set, indicates that the OTP key has been shifted from the fuse block and is ready for use.
        unsigned RESERVED3 : 3; //!< Reserved, always set to zero.
    } B;
} hw_dcp_stat_t;
#endif

/*
 * constants & macros for entire DCP_STAT register
 */
#define HW_DCP_STAT_ADDR      (REGS_DCP_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_STAT           (*(volatile hw_dcp_stat_t *) HW_DCP_STAT_ADDR)
#define HW_DCP_STAT_RD()      (HW_DCP_STAT.U)
#define HW_DCP_STAT_WR(v)     (HW_DCP_STAT.U = (v))
#define HW_DCP_STAT_SET(v)    (HW_DCP_STAT_WR(HW_DCP_STAT_RD() |  (v)))
#define HW_DCP_STAT_CLR(v)    (HW_DCP_STAT_WR(HW_DCP_STAT_RD() & ~(v)))
#define HW_DCP_STAT_TOG(v)    (HW_DCP_STAT_WR(HW_DCP_STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_STAT bitfields
 */

/* --- Register HW_DCP_STAT, field IRQ[3:0] (RW)
 *
 * Indicates which channels have pending interrupt requests. Channel 0's interrupt is routed through
 * the dcp_vmi_irq and the other interrupt bits are routed through the dcp_irq.
 */

#define BP_DCP_STAT_IRQ      (0)
#define BM_DCP_STAT_IRQ      (0x0000000f)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_STAT_IRQ(v)   ((((reg32_t) v) << 0) & BM_DCP_STAT_IRQ)
#else
#define BF_DCP_STAT_IRQ(v)   (((v) << 0) & BM_DCP_STAT_IRQ)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the IRQ field to a new value.
#define BW_DCP_STAT_IRQ(v)   BF_CS1(DCP_STAT, IRQ, v)
#endif

/* --- Register HW_DCP_STAT, field READY_CHANNELS[23:16] (RO)
 *
 * Indicates which channels are ready to proceed with a transfer (active channel also included).
 * Each bit is a one-hot indicating the request status for the associated channel.
 *
 * Values:
 * CH0 = 0x01 - 
 * CH1 = 0x02 - 
 * CH2 = 0x04 - 
 * CH3 = 0x08 - 
 */

#define BP_DCP_STAT_READY_CHANNELS      (16)
#define BM_DCP_STAT_READY_CHANNELS      (0x00ff0000)

#define BV_DCP_STAT_READY_CHANNELS__CH0 (0x1) //!< 
#define BV_DCP_STAT_READY_CHANNELS__CH1 (0x2) //!< 
#define BV_DCP_STAT_READY_CHANNELS__CH2 (0x4) //!< 
#define BV_DCP_STAT_READY_CHANNELS__CH3 (0x8) //!< 

/* --- Register HW_DCP_STAT, field CUR_CHANNEL[27:24] (RO)
 *
 * Current (active) channel (encoded).
 *
 * Values:
 * None = 0x0 - 
 * CH0 = 0x1 - 
 * CH1 = 0x2 - 
 * CH2 = 0x3 - 
 * CH3 = 0x4 - 
 */

#define BP_DCP_STAT_CUR_CHANNEL      (24)
#define BM_DCP_STAT_CUR_CHANNEL      (0x0f000000)

#define BV_DCP_STAT_CUR_CHANNEL__None (0x0) //!< 
#define BV_DCP_STAT_CUR_CHANNEL__CH0 (0x1) //!< 
#define BV_DCP_STAT_CUR_CHANNEL__CH1 (0x2) //!< 
#define BV_DCP_STAT_CUR_CHANNEL__CH2 (0x3) //!< 
#define BV_DCP_STAT_CUR_CHANNEL__CH3 (0x4) //!< 

/* --- Register HW_DCP_STAT, field OTP_KEY_READY[28:28] (RO)
 *
 * When set, indicates that the OTP key has been shifted from the fuse block and is ready for use.
 */

#define BP_DCP_STAT_OTP_KEY_READY      (28)
#define BM_DCP_STAT_OTP_KEY_READY      (0x10000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CHANNELCTRL - DCP Channel Control Register (RW)
 *
 * The DCP Channel Control register provides controls for channel arbitration and channel enables.
 * CHANNELCTRL: 0x020  CHANNELCTRL_SET: 0x024  CHANNELCTRL_CLR: 0x028  CHANNELCTRL_TOG: 0x02C  This
 * register provides status feedback indicating the channel currently performing an operation and
 * which channels have pending operations.   EXAMPLE
 * BW_DCP_CHANNELCTRL_ENABLE_CHANNEL(BV_DCP_CHANNELCTRL_ENABLE_CHANNEL__CH0); // enable channel 0
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLE_CHANNEL : 8; //!< Setting a bit in this field will enabled the DMA channel associated with it. This field is a direct input to the DMA channel arbiter. When not enabled, the channel is denied access to the central DMA resources.
        unsigned HIGH_PRIORITY_CHANNEL : 8; //!< Setting a bit in this field causes the corresponding channel to have high-priority arbitration. High priority channels will be arbitrated round-robin and will take precedence over other channels that are not marked as high priority.
        unsigned CH0_IRQ_MERGED : 1; //!< Indicates that the interrupt for channel 0 should be merged with the other interrupts on the shared dcp_irq interrupt. When set to 0, channel 0's interrupt will be routed to the separate dcp_vmi_irq. When set to 1, the interrupt will be routed to the shared DCP interrupt.
        unsigned RESERVED0 : 15; //!< Reserved, always set to zero.
    } B;
} hw_dcp_channelctrl_t;
#endif

/*
 * constants & macros for entire DCP_CHANNELCTRL register
 */
#define HW_DCP_CHANNELCTRL_ADDR      (REGS_DCP_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CHANNELCTRL           (*(volatile hw_dcp_channelctrl_t *) HW_DCP_CHANNELCTRL_ADDR)
#define HW_DCP_CHANNELCTRL_RD()      (HW_DCP_CHANNELCTRL.U)
#define HW_DCP_CHANNELCTRL_WR(v)     (HW_DCP_CHANNELCTRL.U = (v))
#define HW_DCP_CHANNELCTRL_SET(v)    (HW_DCP_CHANNELCTRL_WR(HW_DCP_CHANNELCTRL_RD() |  (v)))
#define HW_DCP_CHANNELCTRL_CLR(v)    (HW_DCP_CHANNELCTRL_WR(HW_DCP_CHANNELCTRL_RD() & ~(v)))
#define HW_DCP_CHANNELCTRL_TOG(v)    (HW_DCP_CHANNELCTRL_WR(HW_DCP_CHANNELCTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CHANNELCTRL bitfields
 */

/* --- Register HW_DCP_CHANNELCTRL, field ENABLE_CHANNEL[7:0] (RW)
 *
 * Setting a bit in this field will enabled the DMA channel associated with it. This field is a
 * direct input to the DMA channel arbiter. When not enabled, the channel is denied access to the
 * central DMA resources.
 *
 * Values:
 * CH0 = 0x01 - 
 * CH1 = 0x02 - 
 * CH2 = 0x04 - 
 * CH3 = 0x08 - 
 */

#define BP_DCP_CHANNELCTRL_ENABLE_CHANNEL      (0)
#define BM_DCP_CHANNELCTRL_ENABLE_CHANNEL      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CHANNELCTRL_ENABLE_CHANNEL(v)   ((((reg32_t) v) << 0) & BM_DCP_CHANNELCTRL_ENABLE_CHANNEL)
#else
#define BF_DCP_CHANNELCTRL_ENABLE_CHANNEL(v)   (((v) << 0) & BM_DCP_CHANNELCTRL_ENABLE_CHANNEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE_CHANNEL field to a new value.
#define BW_DCP_CHANNELCTRL_ENABLE_CHANNEL(v)   BF_CS1(DCP_CHANNELCTRL, ENABLE_CHANNEL, v)
#endif

#define BV_DCP_CHANNELCTRL_ENABLE_CHANNEL__CH0 (0x1) //!< 
#define BV_DCP_CHANNELCTRL_ENABLE_CHANNEL__CH1 (0x2) //!< 
#define BV_DCP_CHANNELCTRL_ENABLE_CHANNEL__CH2 (0x4) //!< 
#define BV_DCP_CHANNELCTRL_ENABLE_CHANNEL__CH3 (0x8) //!< 

/* --- Register HW_DCP_CHANNELCTRL, field HIGH_PRIORITY_CHANNEL[15:8] (RW)
 *
 * Setting a bit in this field causes the corresponding channel to have high-priority arbitration.
 * High priority channels will be arbitrated round-robin and will take precedence over other
 * channels that are not marked as high priority.
 *
 * Values:
 * CH0 = 0x01 - 
 * CH1 = 0x02 - 
 * CH2 = 0x04 - 
 * CH3 = 0x08 - 
 */

#define BP_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL      (8)
#define BM_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL      (0x0000ff00)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL(v)   ((((reg32_t) v) << 8) & BM_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL)
#else
#define BF_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL(v)   (((v) << 8) & BM_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HIGH_PRIORITY_CHANNEL field to a new value.
#define BW_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL(v)   BF_CS1(DCP_CHANNELCTRL, HIGH_PRIORITY_CHANNEL, v)
#endif

#define BV_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL__CH0 (0x1) //!< 
#define BV_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL__CH1 (0x2) //!< 
#define BV_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL__CH2 (0x4) //!< 
#define BV_DCP_CHANNELCTRL_HIGH_PRIORITY_CHANNEL__CH3 (0x8) //!< 

/* --- Register HW_DCP_CHANNELCTRL, field CH0_IRQ_MERGED[16:16] (RW)
 *
 * Indicates that the interrupt for channel 0 should be merged with the other interrupts on the
 * shared dcp_irq interrupt. When set to 0, channel 0's interrupt will be routed to the separate
 * dcp_vmi_irq. When set to 1, the interrupt will be routed to the shared DCP interrupt.
 */

#define BP_DCP_CHANNELCTRL_CH0_IRQ_MERGED      (16)
#define BM_DCP_CHANNELCTRL_CH0_IRQ_MERGED      (0x00010000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CHANNELCTRL_CH0_IRQ_MERGED(v)   ((((reg32_t) v) << 16) & BM_DCP_CHANNELCTRL_CH0_IRQ_MERGED)
#else
#define BF_DCP_CHANNELCTRL_CH0_IRQ_MERGED(v)   (((v) << 16) & BM_DCP_CHANNELCTRL_CH0_IRQ_MERGED)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the CH0_IRQ_MERGED field to a new value.
#define BW_DCP_CHANNELCTRL_CH0_IRQ_MERGED(v)   BF_CS1(DCP_CHANNELCTRL, CH0_IRQ_MERGED, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CAPABILITY0 - DCP Capability 0 Register (RW)
 *
 * This register contains additional information about the DCP module implementation parameters.
 * This register provides capability information for the DCP block. It indicates the number of
 * channels implemented as well as the number of key storage locations available for software use.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned NUM_KEYS : 8; //!< Encoded value indicating the number of key storage locations implemented in the design.
        unsigned NUM_CHANNELS : 4; //!< Encoded value indicating the number of channels implemented in the design.
        unsigned RESERVED0 : 17; //!< Reserved, always set to zero.
        unsigned DISABLE_UNIQUE_KEY : 1; //!< Write to a 1 disable the per-device unique key. The device-specific hardware key may be selected by using a value of 0xFE in the key select field.
        unsigned RESERVED1 : 1; //!< -
        unsigned DISABLE_DECRYPT : 1; //!< Write to a 1 to disable decryption. This bit can only be written by secure software and the value can only be cleared by a reset.
    } B;
} hw_dcp_capability0_t;
#endif

/*
 * constants & macros for entire DCP_CAPABILITY0 register
 */
#define HW_DCP_CAPABILITY0_ADDR      (REGS_DCP_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CAPABILITY0           (*(volatile hw_dcp_capability0_t *) HW_DCP_CAPABILITY0_ADDR)
#define HW_DCP_CAPABILITY0_RD()      (HW_DCP_CAPABILITY0.U)
#define HW_DCP_CAPABILITY0_WR(v)     (HW_DCP_CAPABILITY0.U = (v))
#define HW_DCP_CAPABILITY0_SET(v)    (HW_DCP_CAPABILITY0_WR(HW_DCP_CAPABILITY0_RD() |  (v)))
#define HW_DCP_CAPABILITY0_CLR(v)    (HW_DCP_CAPABILITY0_WR(HW_DCP_CAPABILITY0_RD() & ~(v)))
#define HW_DCP_CAPABILITY0_TOG(v)    (HW_DCP_CAPABILITY0_WR(HW_DCP_CAPABILITY0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CAPABILITY0 bitfields
 */

/* --- Register HW_DCP_CAPABILITY0, field NUM_KEYS[7:0] (RO)
 *
 * Encoded value indicating the number of key storage locations implemented in the design.
 */

#define BP_DCP_CAPABILITY0_NUM_KEYS      (0)
#define BM_DCP_CAPABILITY0_NUM_KEYS      (0x000000ff)

/* --- Register HW_DCP_CAPABILITY0, field NUM_CHANNELS[11:8] (RO)
 *
 * Encoded value indicating the number of channels implemented in the design.
 */

#define BP_DCP_CAPABILITY0_NUM_CHANNELS      (8)
#define BM_DCP_CAPABILITY0_NUM_CHANNELS      (0x00000f00)

/* --- Register HW_DCP_CAPABILITY0, field DISABLE_UNIQUE_KEY[29:29] (RW)
 *
 * Write to a 1 disable the per-device unique key. The device-specific hardware key may be selected
 * by using a value of 0xFE in the key select field.
 */

#define BP_DCP_CAPABILITY0_DISABLE_UNIQUE_KEY      (29)
#define BM_DCP_CAPABILITY0_DISABLE_UNIQUE_KEY      (0x20000000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CAPABILITY0_DISABLE_UNIQUE_KEY(v)   ((((reg32_t) v) << 29) & BM_DCP_CAPABILITY0_DISABLE_UNIQUE_KEY)
#else
#define BF_DCP_CAPABILITY0_DISABLE_UNIQUE_KEY(v)   (((v) << 29) & BM_DCP_CAPABILITY0_DISABLE_UNIQUE_KEY)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISABLE_UNIQUE_KEY field to a new value.
#define BW_DCP_CAPABILITY0_DISABLE_UNIQUE_KEY(v)   BF_CS1(DCP_CAPABILITY0, DISABLE_UNIQUE_KEY, v)
#endif

/* --- Register HW_DCP_CAPABILITY0, field DISABLE_DECRYPT[31:31] (RW)
 *
 * Write to a 1 to disable decryption. This bit can only be written by secure software and the value
 * can only be cleared by a reset.
 */

#define BP_DCP_CAPABILITY0_DISABLE_DECRYPT      (31)
#define BM_DCP_CAPABILITY0_DISABLE_DECRYPT      (0x80000000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CAPABILITY0_DISABLE_DECRYPT(v)   ((((reg32_t) v) << 31) & BM_DCP_CAPABILITY0_DISABLE_DECRYPT)
#else
#define BF_DCP_CAPABILITY0_DISABLE_DECRYPT(v)   (((v) << 31) & BM_DCP_CAPABILITY0_DISABLE_DECRYPT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DISABLE_DECRYPT field to a new value.
#define BW_DCP_CAPABILITY0_DISABLE_DECRYPT(v)   BF_CS1(DCP_CAPABILITY0, DISABLE_DECRYPT, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CAPABILITY1 - DCP Capability 1 Register (RO)
 *
 * This register contains information about the algorithms available on the implementation.  This
 * register provides capability information for the DCP block. It contains two fields indicating
 * which encryption and hashing algorithms are present in the design. Each bit set indicates that
 * support for the associated function is present.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CIPHER_ALGORITHMS : 16; //!< One-hot field indicating which cipher algorithms are available.
        unsigned HASH_ALGORITHMS : 16; //!< One-hot field indicating which hashing features are implemented in HW.
    } B;
} hw_dcp_capability1_t;
#endif

/*
 * constants & macros for entire DCP_CAPABILITY1 register
 */
#define HW_DCP_CAPABILITY1_ADDR      (REGS_DCP_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CAPABILITY1           (*(volatile hw_dcp_capability1_t *) HW_DCP_CAPABILITY1_ADDR)
#define HW_DCP_CAPABILITY1_RD()      (HW_DCP_CAPABILITY1.U)
#endif

/*
 * constants & macros for individual DCP_CAPABILITY1 bitfields
 */

/* --- Register HW_DCP_CAPABILITY1, field CIPHER_ALGORITHMS[15:0] (RO)
 *
 * One-hot field indicating which cipher algorithms are available.
 *
 * Values:
 * AES128 = 0x0001 - 
 */

#define BP_DCP_CAPABILITY1_CIPHER_ALGORITHMS      (0)
#define BM_DCP_CAPABILITY1_CIPHER_ALGORITHMS      (0x0000ffff)

#define BV_DCP_CAPABILITY1_CIPHER_ALGORITHMS__AES128 (0x1) //!< 

/* --- Register HW_DCP_CAPABILITY1, field HASH_ALGORITHMS[31:16] (RO)
 *
 * One-hot field indicating which hashing features are implemented in HW.
 *
 * Values:
 * SHA1 = 0x0001 - 
 * CRC32 = 0x0002 - 
 * SHA256 = 0x0004 - 
 */

#define BP_DCP_CAPABILITY1_HASH_ALGORITHMS      (16)
#define BM_DCP_CAPABILITY1_HASH_ALGORITHMS      (0xffff0000)

#define BV_DCP_CAPABILITY1_HASH_ALGORITHMS__SHA1 (0x1) //!< 
#define BV_DCP_CAPABILITY1_HASH_ALGORITHMS__CRC32 (0x2) //!< 
#define BV_DCP_CAPABILITY1_HASH_ALGORITHMS__SHA256 (0x4) //!< 

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CONTEXT - DCP Context Buffer Pointer (RW)
 *
 * This register contains a pointer to the memory region to be used for DCP context swap operations.
 * This register contains a pointer to the start of the context pointer memory in on-chip SRAM or
 * off-chip SDRAM. This buffer will be used to store state information when the DCP module changes
 * from one channel to another.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Context pointer address. Address should be located in system RAM and should be word-aligned for optimal performance.
    } B;
} hw_dcp_context_t;
#endif

/*
 * constants & macros for entire DCP_CONTEXT register
 */
#define HW_DCP_CONTEXT_ADDR      (REGS_DCP_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CONTEXT           (*(volatile hw_dcp_context_t *) HW_DCP_CONTEXT_ADDR)
#define HW_DCP_CONTEXT_RD()      (HW_DCP_CONTEXT.U)
#define HW_DCP_CONTEXT_WR(v)     (HW_DCP_CONTEXT.U = (v))
#define HW_DCP_CONTEXT_SET(v)    (HW_DCP_CONTEXT_WR(HW_DCP_CONTEXT_RD() |  (v)))
#define HW_DCP_CONTEXT_CLR(v)    (HW_DCP_CONTEXT_WR(HW_DCP_CONTEXT_RD() & ~(v)))
#define HW_DCP_CONTEXT_TOG(v)    (HW_DCP_CONTEXT_WR(HW_DCP_CONTEXT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CONTEXT bitfields
 */

/* --- Register HW_DCP_CONTEXT, field ADDR[31:0] (RW)
 *
 * Context pointer address. Address should be located in system RAM and should be word-aligned for
 * optimal performance.
 */

#define BP_DCP_CONTEXT_ADDR      (0)
#define BM_DCP_CONTEXT_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CONTEXT_ADDR(v)   ((((reg32_t) v) << 0) & BM_DCP_CONTEXT_ADDR)
#else
#define BF_DCP_CONTEXT_ADDR(v)   (((v) << 0) & BM_DCP_CONTEXT_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_DCP_CONTEXT_ADDR(v)   BF_CS1(DCP_CONTEXT, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_KEY - DCP Key Index (RW)
 *
 * This register contains a pointer to the key location to be written.  The DCP module maintains a
 * set of write-only keys that may be used by software. To write a key, software must first write
 * the desired key index/subword to this register and then write the key values to the key registers
 * (below). After each write to the key data register, the SUBWORD field will increment to allow
 * software to write the subsequent key to be written without having to rewrite the key index.
 * EXAMPLE   // write key 0 to 0x00112233_44556677_8899aabb_ccddeeff DCP_KEY_WR(BF_DCP_KEY_INDEX(0)
 * | BF_DCP_KEY_SUBWORD(0)); // set key index to key 0, subword 0 DCP_KEYDATA_WR(0xccddeeff); //
 * write key values (subword 0) DCP_KEYDATA_WR(0x8899aabb); // write key values (subword 1)
 * DCP_KEYDATA_WR(0x44556677); // write key values (subword 2) DCP_KEYDATA_WR(0x00112233); // write
 * key values (subword 3)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned SUBWORD : 2; //!< Key subword pointer. Valid indices are 0-3. After each write to the key data register, this field will increment.
        unsigned RESERVED0 : 2; //!< Reserved, always set to zero.
        unsigned INDEX : 2; //!< Key index pointer. Valid indices are 0-[number_keys].
        unsigned RESERVED1 : 2; //!< Reserved, always set to zero.
        unsigned RESERVED2 : 24; //!< Reserved, always set to zero.
    } B;
} hw_dcp_key_t;
#endif

/*
 * constants & macros for entire DCP_KEY register
 */
#define HW_DCP_KEY_ADDR      (REGS_DCP_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_KEY           (*(volatile hw_dcp_key_t *) HW_DCP_KEY_ADDR)
#define HW_DCP_KEY_RD()      (HW_DCP_KEY.U)
#define HW_DCP_KEY_WR(v)     (HW_DCP_KEY.U = (v))
#define HW_DCP_KEY_SET(v)    (HW_DCP_KEY_WR(HW_DCP_KEY_RD() |  (v)))
#define HW_DCP_KEY_CLR(v)    (HW_DCP_KEY_WR(HW_DCP_KEY_RD() & ~(v)))
#define HW_DCP_KEY_TOG(v)    (HW_DCP_KEY_WR(HW_DCP_KEY_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_KEY bitfields
 */

/* --- Register HW_DCP_KEY, field SUBWORD[1:0] (RW)
 *
 * Key subword pointer. Valid indices are 0-3. After each write to the key data register, this field
 * will increment.
 */

#define BP_DCP_KEY_SUBWORD      (0)
#define BM_DCP_KEY_SUBWORD      (0x00000003)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_KEY_SUBWORD(v)   ((((reg32_t) v) << 0) & BM_DCP_KEY_SUBWORD)
#else
#define BF_DCP_KEY_SUBWORD(v)   (((v) << 0) & BM_DCP_KEY_SUBWORD)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the SUBWORD field to a new value.
#define BW_DCP_KEY_SUBWORD(v)   BF_CS1(DCP_KEY, SUBWORD, v)
#endif

/* --- Register HW_DCP_KEY, field INDEX[5:4] (RW)
 *
 * Key index pointer. Valid indices are 0-[number_keys].
 */

#define BP_DCP_KEY_INDEX      (4)
#define BM_DCP_KEY_INDEX      (0x00000030)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_KEY_INDEX(v)   ((((reg32_t) v) << 4) & BM_DCP_KEY_INDEX)
#else
#define BF_DCP_KEY_INDEX(v)   (((v) << 4) & BM_DCP_KEY_INDEX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INDEX field to a new value.
#define BW_DCP_KEY_INDEX(v)   BF_CS1(DCP_KEY, INDEX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_KEYDATA - DCP Key Data (RW)
 *
 * This register provides write access to the key/key subword specified by the Key Index Register.
 * Writing this location updates the selected subword for the key located at the index specified by
 * the Key Index Register. A write also triggers the SUBWORD field of the KEY register to increment
 * to the next higher word in the key.   EXAMPLE   // write key 0 to
 * 0x00112233_44556677_8899aabb_ccddeeff DCP_KEY_WR(BF_DCP_KEY_INDEX(0) | BF_DCP_KEY_SUBWORD(0)); //
 * set key index to key 0, subword 0 DCP_KEYDATA_WR(0xccddeeff); // write key values (subword 0)
 * DCP_KEYDATA_WR(0x8899aabb); // write key values (subword 1) DCP_KEYDATA_WR(0x44556677); // write
 * key values (subword 2) DCP_KEYDATA_WR(0x00112233); // write key values (subword 3)
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< Word 0 data for key. This is the least-significant word.
    } B;
} hw_dcp_keydata_t;
#endif

/*
 * constants & macros for entire DCP_KEYDATA register
 */
#define HW_DCP_KEYDATA_ADDR      (REGS_DCP_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_KEYDATA           (*(volatile hw_dcp_keydata_t *) HW_DCP_KEYDATA_ADDR)
#define HW_DCP_KEYDATA_RD()      (HW_DCP_KEYDATA.U)
#define HW_DCP_KEYDATA_WR(v)     (HW_DCP_KEYDATA.U = (v))
#define HW_DCP_KEYDATA_SET(v)    (HW_DCP_KEYDATA_WR(HW_DCP_KEYDATA_RD() |  (v)))
#define HW_DCP_KEYDATA_CLR(v)    (HW_DCP_KEYDATA_WR(HW_DCP_KEYDATA_RD() & ~(v)))
#define HW_DCP_KEYDATA_TOG(v)    (HW_DCP_KEYDATA_WR(HW_DCP_KEYDATA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_KEYDATA bitfields
 */

/* --- Register HW_DCP_KEYDATA, field DATA[31:0] (RW)
 *
 * Word 0 data for key. This is the least-significant word.
 */

#define BP_DCP_KEYDATA_DATA      (0)
#define BM_DCP_KEYDATA_DATA      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_KEYDATA_DATA(v)   ((((reg32_t) v) << 0) & BM_DCP_KEYDATA_DATA)
#else
#define BF_DCP_KEYDATA_DATA(v)   (((v) << 0) & BM_DCP_KEYDATA_DATA)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_DCP_KEYDATA_DATA(v)   BF_CS1(DCP_KEYDATA, DATA, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PACKET0 - DCP Work Packet 0 Status Register (RO)
 *
 * This register displays the values for the current work packet offset 0x00 (Next Command) field.
 * The Work Packet Status Registers show the contents of the currently executing packet. When the
 * channels are inactive, the packet status register return 0. The register bits are fully
 * documented here to document the packet structure in memory.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Next Pointer Register,
    } B;
} hw_dcp_packet0_t;
#endif

/*
 * constants & macros for entire DCP_PACKET0 register
 */
#define HW_DCP_PACKET0_ADDR      (REGS_DCP_BASE + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PACKET0           (*(volatile hw_dcp_packet0_t *) HW_DCP_PACKET0_ADDR)
#define HW_DCP_PACKET0_RD()      (HW_DCP_PACKET0.U)
#endif

/*
 * constants & macros for individual DCP_PACKET0 bitfields
 */

/* --- Register HW_DCP_PACKET0, field ADDR[31:0] (RO)
 *
 * Next Pointer Register,
 */

#define BP_DCP_PACKET0_ADDR      (0)
#define BM_DCP_PACKET0_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PACKET1 - DCP Work Packet 1 Status Register (RO)
 *
 * This register displays the values for the current work packet offset 0x04 (control) field.  This
 * register shows the contents of the Control0 register from the packet being processed.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INTERRUPT : 1; //!< Reflects whether the channel should issue an interrupt upon completion of the packet.
        unsigned DECR_SEMAPHORE : 1; //!< Reflects whether the channel's semaphore should be decremented at the end of the current operation. When the semaphore reaches a value of zero, no more operations will be issued from the channel.
        unsigned CHAIN : 1; //!< Reflects whether the next command pointer register should be loaded into the channel's current descriptor pointer.
        unsigned CHAIN_CONTIGUOUS : 1; //!< Reflects whether the next packet's address is located following this packet's payload.
        unsigned ENABLE_MEMCOPY : 1; //!< Reflects whether the selected hashing function should be enabled for this operation.
        unsigned ENABLE_CIPHER : 1; //!< Reflects whether the selected cipher function should be enabled for this operation.
        unsigned ENABLE_HASH : 1; //!< Reflects whether the selected hashing function should be enabled for this operation.
        unsigned ENABLE_BLIT : 1; //!< Reflects whether the DCP should perform a blit operation. Source data is always continuous and the destination buffer is written in run/stride format. When set, the BUFFER_SIZE field is treated as two 16-bit values for the X-Y extents of the blit operation.
        unsigned CIPHER_ENCRYPT : 1; //!< When the cipher block is enabled, this bit indicates whether the operation is encryption or decryption.
        unsigned CIPHER_INIT : 1; //!< Reflects whether the cipher block should load the initialization vector from the payload for this operation.
        unsigned OTP_KEY : 1; //!< Reflects whether a hardware-based key should be used. The KEY_SELECT field from the Control1 field is used to select from multiple hardware keys. The PAYLOAD_KEY bit takes precedence over the OTP_KEY bit.
        unsigned PAYLOAD_KEY : 1; //!< When set, indicates the payload contains the key. This bit takes precedence over the OTP_KEY control
        unsigned HASH_INIT : 1; //!< Reflects whether the current hashing block is the initial block in the hashing operation, so the hash registers should be initialized before the operation.
        unsigned HASH_TERM : 1; //!< Reflects whether the current hashing block is the final block in the hashing operation, so the hash padding should be applied by hardware.
        unsigned CHECK_HASH : 1; //!< Reflects whether the calculated hash value should be compared against the hash provided in the payload.
        unsigned HASH_OUTPUT : 1; //!< When hashing is enabled, this bit controls whether the input or output data is hashed.
        unsigned CONSTANT_FILL : 1; //!< When this bit is set (MEMCOPY and BLIT modes only), the DCP will simply fill the destination buffer with the value found in the Source Address field.
        unsigned TEST_SEMA_IRQ : 1; //!< This bit is used to test the channel semaphore transition to 0. FOR TEST USE ONLY!
        unsigned KEY_BYTESWAP : 1; //!< Reflects whether the DCP engine will swap key bytes (big-endian key).
        unsigned KEY_WORDSWAP : 1; //!< Reflects whether the DCP engine will swap key words (big-endian key).
        unsigned INPUT_BYTESWAP : 1; //!< Reflects whether the DCP engine will byteswap input data (big-endian data).
        unsigned INPUT_WORDSWAP : 1; //!< Reflects whether the DCP engine will wordswap input data (big-endian data).
        unsigned OUTPUT_BYTESWAP : 1; //!< Reflects whether the DCP engine will byteswap output data (big-endian data).
        unsigned OUTPUT_WORDSWAP : 1; //!< Reflects whether the DCP engine will wordswap output data (big-endian data).
        unsigned TAG : 8; //!< Packet Tag
    } B;
} hw_dcp_packet1_t;
#endif

/*
 * constants & macros for entire DCP_PACKET1 register
 */
#define HW_DCP_PACKET1_ADDR      (REGS_DCP_BASE + 0x90)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PACKET1           (*(volatile hw_dcp_packet1_t *) HW_DCP_PACKET1_ADDR)
#define HW_DCP_PACKET1_RD()      (HW_DCP_PACKET1.U)
#endif

/*
 * constants & macros for individual DCP_PACKET1 bitfields
 */

/* --- Register HW_DCP_PACKET1, field INTERRUPT[0:0] (RO)
 *
 * Reflects whether the channel should issue an interrupt upon completion of the packet.
 */

#define BP_DCP_PACKET1_INTERRUPT      (0)
#define BM_DCP_PACKET1_INTERRUPT      (0x00000001)

/* --- Register HW_DCP_PACKET1, field DECR_SEMAPHORE[1:1] (RO)
 *
 * Reflects whether the channel's semaphore should be decremented at the end of the current
 * operation. When the semaphore reaches a value of zero, no more operations will be issued from the
 * channel.
 */

#define BP_DCP_PACKET1_DECR_SEMAPHORE      (1)
#define BM_DCP_PACKET1_DECR_SEMAPHORE      (0x00000002)

/* --- Register HW_DCP_PACKET1, field CHAIN[2:2] (RO)
 *
 * Reflects whether the next command pointer register should be loaded into the channel's current
 * descriptor pointer.
 */

#define BP_DCP_PACKET1_CHAIN      (2)
#define BM_DCP_PACKET1_CHAIN      (0x00000004)

/* --- Register HW_DCP_PACKET1, field CHAIN_CONTIGUOUS[3:3] (RO)
 *
 * Reflects whether the next packet's address is located following this packet's payload.
 */

#define BP_DCP_PACKET1_CHAIN_CONTIGUOUS      (3)
#define BM_DCP_PACKET1_CHAIN_CONTIGUOUS      (0x00000008)

/* --- Register HW_DCP_PACKET1, field ENABLE_MEMCOPY[4:4] (RO)
 *
 * Reflects whether the selected hashing function should be enabled for this operation.
 */

#define BP_DCP_PACKET1_ENABLE_MEMCOPY      (4)
#define BM_DCP_PACKET1_ENABLE_MEMCOPY      (0x00000010)

/* --- Register HW_DCP_PACKET1, field ENABLE_CIPHER[5:5] (RO)
 *
 * Reflects whether the selected cipher function should be enabled for this operation.
 */

#define BP_DCP_PACKET1_ENABLE_CIPHER      (5)
#define BM_DCP_PACKET1_ENABLE_CIPHER      (0x00000020)

/* --- Register HW_DCP_PACKET1, field ENABLE_HASH[6:6] (RO)
 *
 * Reflects whether the selected hashing function should be enabled for this operation.
 */

#define BP_DCP_PACKET1_ENABLE_HASH      (6)
#define BM_DCP_PACKET1_ENABLE_HASH      (0x00000040)

/* --- Register HW_DCP_PACKET1, field ENABLE_BLIT[7:7] (RO)
 *
 * Reflects whether the DCP should perform a blit operation. Source data is always continuous and
 * the destination buffer is written in run/stride format. When set, the BUFFER_SIZE field is
 * treated as two 16-bit values for the X-Y extents of the blit operation.
 */

#define BP_DCP_PACKET1_ENABLE_BLIT      (7)
#define BM_DCP_PACKET1_ENABLE_BLIT      (0x00000080)

/* --- Register HW_DCP_PACKET1, field CIPHER_ENCRYPT[8:8] (RO)
 *
 * When the cipher block is enabled, this bit indicates whether the operation is encryption or
 * decryption.
 *
 * Values:
 * DECRYPT = 0 - 
 * ENCRYPT = 1 - 
 */

#define BP_DCP_PACKET1_CIPHER_ENCRYPT      (8)
#define BM_DCP_PACKET1_CIPHER_ENCRYPT      (0x00000100)

#define BV_DCP_PACKET1_CIPHER_ENCRYPT__DECRYPT (0x0) //!< 
#define BV_DCP_PACKET1_CIPHER_ENCRYPT__ENCRYPT (0x1) //!< 

/* --- Register HW_DCP_PACKET1, field CIPHER_INIT[9:9] (RO)
 *
 * Reflects whether the cipher block should load the initialization vector from the payload for this
 * operation.
 */

#define BP_DCP_PACKET1_CIPHER_INIT      (9)
#define BM_DCP_PACKET1_CIPHER_INIT      (0x00000200)

/* --- Register HW_DCP_PACKET1, field OTP_KEY[10:10] (RO)
 *
 * Reflects whether a hardware-based key should be used. The KEY_SELECT field from the Control1
 * field is used to select from multiple hardware keys. The PAYLOAD_KEY bit takes precedence over
 * the OTP_KEY bit.
 */

#define BP_DCP_PACKET1_OTP_KEY      (10)
#define BM_DCP_PACKET1_OTP_KEY      (0x00000400)

/* --- Register HW_DCP_PACKET1, field PAYLOAD_KEY[11:11] (RO)
 *
 * When set, indicates the payload contains the key. This bit takes precedence over the OTP_KEY
 * control
 */

#define BP_DCP_PACKET1_PAYLOAD_KEY      (11)
#define BM_DCP_PACKET1_PAYLOAD_KEY      (0x00000800)

/* --- Register HW_DCP_PACKET1, field HASH_INIT[12:12] (RO)
 *
 * Reflects whether the current hashing block is the initial block in the hashing operation, so the
 * hash registers should be initialized before the operation.
 */

#define BP_DCP_PACKET1_HASH_INIT      (12)
#define BM_DCP_PACKET1_HASH_INIT      (0x00001000)

/* --- Register HW_DCP_PACKET1, field HASH_TERM[13:13] (RO)
 *
 * Reflects whether the current hashing block is the final block in the hashing operation, so the
 * hash padding should be applied by hardware.
 */

#define BP_DCP_PACKET1_HASH_TERM      (13)
#define BM_DCP_PACKET1_HASH_TERM      (0x00002000)

/* --- Register HW_DCP_PACKET1, field CHECK_HASH[14:14] (RO)
 *
 * Reflects whether the calculated hash value should be compared against the hash provided in the
 * payload.
 */

#define BP_DCP_PACKET1_CHECK_HASH      (14)
#define BM_DCP_PACKET1_CHECK_HASH      (0x00004000)

/* --- Register HW_DCP_PACKET1, field HASH_OUTPUT[15:15] (RO)
 *
 * When hashing is enabled, this bit controls whether the input or output data is hashed.
 *
 * Values:
 * INPUT = 0 - 
 * OUTPUT = 1 - 
 */

#define BP_DCP_PACKET1_HASH_OUTPUT      (15)
#define BM_DCP_PACKET1_HASH_OUTPUT      (0x00008000)

#define BV_DCP_PACKET1_HASH_OUTPUT__INPUT (0x0) //!< 
#define BV_DCP_PACKET1_HASH_OUTPUT__OUTPUT (0x1) //!< 

/* --- Register HW_DCP_PACKET1, field CONSTANT_FILL[16:16] (RO)
 *
 * When this bit is set (MEMCOPY and BLIT modes only), the DCP will simply fill the destination
 * buffer with the value found in the Source Address field.
 */

#define BP_DCP_PACKET1_CONSTANT_FILL      (16)
#define BM_DCP_PACKET1_CONSTANT_FILL      (0x00010000)

/* --- Register HW_DCP_PACKET1, field TEST_SEMA_IRQ[17:17] (RO)
 *
 * This bit is used to test the channel semaphore transition to 0. FOR TEST USE ONLY!
 */

#define BP_DCP_PACKET1_TEST_SEMA_IRQ      (17)
#define BM_DCP_PACKET1_TEST_SEMA_IRQ      (0x00020000)

/* --- Register HW_DCP_PACKET1, field KEY_BYTESWAP[18:18] (RO)
 *
 * Reflects whether the DCP engine will swap key bytes (big-endian key).
 */

#define BP_DCP_PACKET1_KEY_BYTESWAP      (18)
#define BM_DCP_PACKET1_KEY_BYTESWAP      (0x00040000)

/* --- Register HW_DCP_PACKET1, field KEY_WORDSWAP[19:19] (RO)
 *
 * Reflects whether the DCP engine will swap key words (big-endian key).
 */

#define BP_DCP_PACKET1_KEY_WORDSWAP      (19)
#define BM_DCP_PACKET1_KEY_WORDSWAP      (0x00080000)

/* --- Register HW_DCP_PACKET1, field INPUT_BYTESWAP[20:20] (RO)
 *
 * Reflects whether the DCP engine will byteswap input data (big-endian data).
 */

#define BP_DCP_PACKET1_INPUT_BYTESWAP      (20)
#define BM_DCP_PACKET1_INPUT_BYTESWAP      (0x00100000)

/* --- Register HW_DCP_PACKET1, field INPUT_WORDSWAP[21:21] (RO)
 *
 * Reflects whether the DCP engine will wordswap input data (big-endian data).
 */

#define BP_DCP_PACKET1_INPUT_WORDSWAP      (21)
#define BM_DCP_PACKET1_INPUT_WORDSWAP      (0x00200000)

/* --- Register HW_DCP_PACKET1, field OUTPUT_BYTESWAP[22:22] (RO)
 *
 * Reflects whether the DCP engine will byteswap output data (big-endian data).
 */

#define BP_DCP_PACKET1_OUTPUT_BYTESWAP      (22)
#define BM_DCP_PACKET1_OUTPUT_BYTESWAP      (0x00400000)

/* --- Register HW_DCP_PACKET1, field OUTPUT_WORDSWAP[23:23] (RO)
 *
 * Reflects whether the DCP engine will wordswap output data (big-endian data).
 */

#define BP_DCP_PACKET1_OUTPUT_WORDSWAP      (23)
#define BM_DCP_PACKET1_OUTPUT_WORDSWAP      (0x00800000)

/* --- Register HW_DCP_PACKET1, field TAG[31:24] (RO)
 *
 * Packet Tag
 */

#define BP_DCP_PACKET1_TAG      (24)
#define BM_DCP_PACKET1_TAG      (0xff000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PACKET2 - DCP Work Packet 2 Status Register (RO)
 *
 * This register displays the values for the current work packet offset 0x08 (Control1) field.  This
 * register shows the contents of the Control0 register from the packet being processed.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned CIPHER_SELECT : 4; //!< Cipher Selection Field
        unsigned CIPHER_MODE : 4; //!< Cipher Mode Selection Field. Reflects the mode of operation for cipher operations.
        unsigned KEY_SELECT : 8; //!< Key Selection Field. The value here reflects the key index for the cipher operation. Values 0-3 refer to the software keys that can be written to the key RAM. The OTP key or the unique device-specific key may also be selected with a value of 0xFF (OTP key) or 0xFE (unique key).
        unsigned HASH_SELECT : 4; //!< Hash Selection Field
        unsigned RESERVED0 : 4; //!< Reserved, always set to zero.
        unsigned CIPHER_CFG : 8; //!< Cipher configuration bits. Optional configuration bits required for ciphers
    } B;
} hw_dcp_packet2_t;
#endif

/*
 * constants & macros for entire DCP_PACKET2 register
 */
#define HW_DCP_PACKET2_ADDR      (REGS_DCP_BASE + 0xa0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PACKET2           (*(volatile hw_dcp_packet2_t *) HW_DCP_PACKET2_ADDR)
#define HW_DCP_PACKET2_RD()      (HW_DCP_PACKET2.U)
#endif

/*
 * constants & macros for individual DCP_PACKET2 bitfields
 */

/* --- Register HW_DCP_PACKET2, field CIPHER_SELECT[3:0] (RO)
 *
 * Cipher Selection Field
 *
 * Values:
 * AES128 = 0x00 - 
 */

#define BP_DCP_PACKET2_CIPHER_SELECT      (0)
#define BM_DCP_PACKET2_CIPHER_SELECT      (0x0000000f)

#define BV_DCP_PACKET2_CIPHER_SELECT__AES128 (0x0) //!< 

/* --- Register HW_DCP_PACKET2, field CIPHER_MODE[7:4] (RO)
 *
 * Cipher Mode Selection Field. Reflects the mode of operation for cipher operations.
 *
 * Values:
 * ECB = 0x00 - 
 * CBC = 0x01 - 
 */

#define BP_DCP_PACKET2_CIPHER_MODE      (4)
#define BM_DCP_PACKET2_CIPHER_MODE      (0x000000f0)

#define BV_DCP_PACKET2_CIPHER_MODE__ECB (0x0) //!< 
#define BV_DCP_PACKET2_CIPHER_MODE__CBC (0x1) //!< 

/* --- Register HW_DCP_PACKET2, field KEY_SELECT[15:8] (RO)
 *
 * Key Selection Field. The value here reflects the key index for the cipher operation. Values 0-3
 * refer to the software keys that can be written to the key RAM. The OTP key or the unique device-
 * specific key may also be selected with a value of 0xFF (OTP key) or 0xFE (unique key).
 *
 * Values:
 * KEY0 = 0x00 - 
 * KEY1 = 0x01 - 
 * KEY2 = 0x02 - 
 * KEY3 = 0x03 - 
 * UNIQUE_KEY = 0xFE - 
 * OTP_KEY = 0xFF - 
 */

#define BP_DCP_PACKET2_KEY_SELECT      (8)
#define BM_DCP_PACKET2_KEY_SELECT      (0x0000ff00)

#define BV_DCP_PACKET2_KEY_SELECT__KEY0 (0x0) //!< 
#define BV_DCP_PACKET2_KEY_SELECT__KEY1 (0x1) //!< 
#define BV_DCP_PACKET2_KEY_SELECT__KEY2 (0x2) //!< 
#define BV_DCP_PACKET2_KEY_SELECT__KEY3 (0x3) //!< 
#define BV_DCP_PACKET2_KEY_SELECT__UNIQUE_KEY (0xfe) //!< 
#define BV_DCP_PACKET2_KEY_SELECT__OTP_KEY (0xff) //!< 

/* --- Register HW_DCP_PACKET2, field HASH_SELECT[19:16] (RO)
 *
 * Hash Selection Field
 *
 * Values:
 * SHA1 = 0x00 - 
 * CRC32 = 0x01 - 
 * SHA256 = 0x02 - 
 */

#define BP_DCP_PACKET2_HASH_SELECT      (16)
#define BM_DCP_PACKET2_HASH_SELECT      (0x000f0000)

#define BV_DCP_PACKET2_HASH_SELECT__SHA1 (0x0) //!< 
#define BV_DCP_PACKET2_HASH_SELECT__CRC32 (0x1) //!< 
#define BV_DCP_PACKET2_HASH_SELECT__SHA256 (0x2) //!< 

/* --- Register HW_DCP_PACKET2, field CIPHER_CFG[31:24] (RO)
 *
 * Cipher configuration bits. Optional configuration bits required for ciphers
 */

#define BP_DCP_PACKET2_CIPHER_CFG      (24)
#define BM_DCP_PACKET2_CIPHER_CFG      (0xff000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PACKET3 - DCP Work Packet 3 Status Register (RO)
 *
 * This register displays the values for the current work packet offset 0x0C (Source Address) field.
 * This register shows the contents of the Source Address register from the packet being processed.
 * When the CONSTANT_FILL bit in the Control 0 field is set, this field contains the data written to
 * the destination buffer.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Source Buffer Address Pointer. This value is the working value and will update as the operation proceeds.
    } B;
} hw_dcp_packet3_t;
#endif

/*
 * constants & macros for entire DCP_PACKET3 register
 */
#define HW_DCP_PACKET3_ADDR      (REGS_DCP_BASE + 0xb0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PACKET3           (*(volatile hw_dcp_packet3_t *) HW_DCP_PACKET3_ADDR)
#define HW_DCP_PACKET3_RD()      (HW_DCP_PACKET3.U)
#endif

/*
 * constants & macros for individual DCP_PACKET3 bitfields
 */

/* --- Register HW_DCP_PACKET3, field ADDR[31:0] (RO)
 *
 * Source Buffer Address Pointer. This value is the working value and will update as the operation
 * proceeds.
 */

#define BP_DCP_PACKET3_ADDR      (0)
#define BM_DCP_PACKET3_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PACKET4 - DCP Work Packet 4 Status Register (RO)
 *
 * This register displays the values for the current work packet offset 0x10 (Destination Address)
 * field.  This register shows the contents of the Destination Address register from the packet
 * being processed.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Destination Buffer Address Pointer. This value is the working value and will update as the operation proceeds.
    } B;
} hw_dcp_packet4_t;
#endif

/*
 * constants & macros for entire DCP_PACKET4 register
 */
#define HW_DCP_PACKET4_ADDR      (REGS_DCP_BASE + 0xc0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PACKET4           (*(volatile hw_dcp_packet4_t *) HW_DCP_PACKET4_ADDR)
#define HW_DCP_PACKET4_RD()      (HW_DCP_PACKET4.U)
#endif

/*
 * constants & macros for individual DCP_PACKET4 bitfields
 */

/* --- Register HW_DCP_PACKET4, field ADDR[31:0] (RO)
 *
 * Destination Buffer Address Pointer. This value is the working value and will update as the
 * operation proceeds.
 */

#define BP_DCP_PACKET4_ADDR      (0)
#define BM_DCP_PACKET4_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PACKET5 - DCP Work Packet 5 Status Register (RO)
 *
 * This register displays the values for the current work packet offset 0x14 (Buffer Size) field.
 * This register shows the contents of the bytecount register from the packet being processed. The
 * field can be considered either a byte count or a buffer size. The logic treats this as a
 * decrmenting count of bytes from the buffer size programmed into the field. As the transaction
 * proceeds, the logic will decrement the bytecount as data is written to the destination buffer.
 * For blit operations, the top 16-bits of this field represents the number of lines (y size) in the
 * blit and the lower 16-bits represent the number of bytes in a line (x size).
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned COUNT : 32; //!< Byte Count register. This value is the working value and will update as the operation proceeds.
    } B;
} hw_dcp_packet5_t;
#endif

/*
 * constants & macros for entire DCP_PACKET5 register
 */
#define HW_DCP_PACKET5_ADDR      (REGS_DCP_BASE + 0xd0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PACKET5           (*(volatile hw_dcp_packet5_t *) HW_DCP_PACKET5_ADDR)
#define HW_DCP_PACKET5_RD()      (HW_DCP_PACKET5.U)
#endif

/*
 * constants & macros for individual DCP_PACKET5 bitfields
 */

/* --- Register HW_DCP_PACKET5, field COUNT[31:0] (RO)
 *
 * Byte Count register. This value is the working value and will update as the operation proceeds.
 */

#define BP_DCP_PACKET5_COUNT      (0)
#define BM_DCP_PACKET5_COUNT      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PACKET6 - DCP Work Packet 6 Status Register (RO)
 *
 * This register displays the values for the current work packet offset 0x1C (Payload Pointer)
 * field.  This register shows the contents of the payload pointer fieldr from the packet being
 * processed.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< This regiser reflects the payload pointer for the current control packet.
    } B;
} hw_dcp_packet6_t;
#endif

/*
 * constants & macros for entire DCP_PACKET6 register
 */
#define HW_DCP_PACKET6_ADDR      (REGS_DCP_BASE + 0xe0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PACKET6           (*(volatile hw_dcp_packet6_t *) HW_DCP_PACKET6_ADDR)
#define HW_DCP_PACKET6_RD()      (HW_DCP_PACKET6.U)
#endif

/*
 * constants & macros for individual DCP_PACKET6 bitfields
 */

/* --- Register HW_DCP_PACKET6, field ADDR[31:0] (RO)
 *
 * This regiser reflects the payload pointer for the current control packet.
 */

#define BP_DCP_PACKET6_ADDR      (0)
#define BM_DCP_PACKET6_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH0CMDPTR - DCP Channel 0 Command Pointer Address Register (RW)
 *
 * The DCP channel 0 current command address register points to the multiword descriptor that is to
 * be executed (or currently being executed). The channel may be activated by writing the command
 * pointer address to a valid descriptor in memory and then updating the semaphore to a non-zero
 * value. After the engine completes processing of a descriptor, the "next_ptr" field from the
 * descriptor is moved into this register to enable processing of the next descriptor. All channels
 * with a non-zero semaphore value will arbitrate for access to the engine for the subsequent
 * operation.  DCP Channel 0 is controlled by a variable sized command structure. This register
 * points to the command structure to be executed.   EXAMPLE   DCP_CHnCMDPTR_WR(0, v); // Write
 * channel 0 command pointer pCurptr = (DCP_chncmdptr_t *) DCP_CHnCMDPTR_RD(0); // Read current
 * command pointer
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Pointer to descriptor structure to be processed for channel 0.
    } B;
} hw_dcp_ch0cmdptr_t;
#endif

/*
 * constants & macros for entire DCP_CH0CMDPTR register
 */
#define HW_DCP_CH0CMDPTR_ADDR      (REGS_DCP_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH0CMDPTR           (*(volatile hw_dcp_ch0cmdptr_t *) HW_DCP_CH0CMDPTR_ADDR)
#define HW_DCP_CH0CMDPTR_RD()      (HW_DCP_CH0CMDPTR.U)
#define HW_DCP_CH0CMDPTR_WR(v)     (HW_DCP_CH0CMDPTR.U = (v))
#define HW_DCP_CH0CMDPTR_SET(v)    (HW_DCP_CH0CMDPTR_WR(HW_DCP_CH0CMDPTR_RD() |  (v)))
#define HW_DCP_CH0CMDPTR_CLR(v)    (HW_DCP_CH0CMDPTR_WR(HW_DCP_CH0CMDPTR_RD() & ~(v)))
#define HW_DCP_CH0CMDPTR_TOG(v)    (HW_DCP_CH0CMDPTR_WR(HW_DCP_CH0CMDPTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH0CMDPTR bitfields
 */

/* --- Register HW_DCP_CH0CMDPTR, field ADDR[31:0] (RW)
 *
 * Pointer to descriptor structure to be processed for channel 0.
 */

#define BP_DCP_CH0CMDPTR_ADDR      (0)
#define BM_DCP_CH0CMDPTR_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0CMDPTR_ADDR(v)   ((((reg32_t) v) << 0) & BM_DCP_CH0CMDPTR_ADDR)
#else
#define BF_DCP_CH0CMDPTR_ADDR(v)   (((v) << 0) & BM_DCP_CH0CMDPTR_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_DCP_CH0CMDPTR_ADDR(v)   BF_CS1(DCP_CH0CMDPTR, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH0SEMA - DCP Channel 0 Semaphore Register (RW)
 *
 * The DCP Channel 0 semaphore register is used to synchronize the ARM platform instruction stream
 * and the DMA chain processing state. After a command chain has been generated in memory, software
 * should write the address of the first command descriptor to the CMDPTR register and then write a
 * non-zero value to the semaphore register to indicate that the channel is active. Each command
 * packet has a chaining bit which indicates that another descriptor should be loaded into the
 * channel upon completion of the current descriptor. If the chaining bit is not set, the next
 * address will not be loaded into the CMDPTR register. Each packet also contains a "decrement
 * semaphore" bit, which indicates that the counting semaphore should be decremented after the
 * operation. A channel is considered active when the semaphore is a non-zero value. When
 * programming a series operations, software must properly program the semaphore values in
 * conjuction with the "decrement_semaphore" bits in the control packets to ensure that the proper
 * number of descriptors are activated. A semaphore may be cleared by software by writing 0xFF to
 * the DCP_CHnSEMA_CLR register. The logic will also clear the semaphore if an error has occurred.
 * Each DCP channel has an 8 bit counting semaphore that is used to synchronize between the program
 * stream and and the DCP chain processing. After processing each control packet, the DCP decrements
 * the semaphore if it is non-zero. The channel will continue processing packets as long as the
 * semaphore contains a non-zero value and the CHAIN or CHAIN_CONTIGOUS control bits in the Control0
 * field are set.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INCREMENT : 8; //!< The value written to this field is added to the semaphore count in an atomic way such that simultaneous software adds and DCP hardware substracts happening on the same clock are protected. This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count by two, unless the DCP channel decrements the count on the same clock, then the count is incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR register.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
        unsigned VALUE : 8; //!< This read-only field shows the current (instantaneous) value of the semaphore counter.
        unsigned RESERVED1 : 8; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch0sema_t;
#endif

/*
 * constants & macros for entire DCP_CH0SEMA register
 */
#define HW_DCP_CH0SEMA_ADDR      (REGS_DCP_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH0SEMA           (*(volatile hw_dcp_ch0sema_t *) HW_DCP_CH0SEMA_ADDR)
#define HW_DCP_CH0SEMA_RD()      (HW_DCP_CH0SEMA.U)
#define HW_DCP_CH0SEMA_WR(v)     (HW_DCP_CH0SEMA.U = (v))
#define HW_DCP_CH0SEMA_SET(v)    (HW_DCP_CH0SEMA_WR(HW_DCP_CH0SEMA_RD() |  (v)))
#define HW_DCP_CH0SEMA_CLR(v)    (HW_DCP_CH0SEMA_WR(HW_DCP_CH0SEMA_RD() & ~(v)))
#define HW_DCP_CH0SEMA_TOG(v)    (HW_DCP_CH0SEMA_WR(HW_DCP_CH0SEMA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH0SEMA bitfields
 */

/* --- Register HW_DCP_CH0SEMA, field INCREMENT[7:0] (RW)
 *
 * The value written to this field is added to the semaphore count in an atomic way such that
 * simultaneous software adds and DCP hardware substracts happening on the same clock are protected.
 * This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count
 * by two, unless the DCP channel decrements the count on the same clock, then the count is
 * incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR
 * register.
 */

#define BP_DCP_CH0SEMA_INCREMENT      (0)
#define BM_DCP_CH0SEMA_INCREMENT      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0SEMA_INCREMENT(v)   ((((reg32_t) v) << 0) & BM_DCP_CH0SEMA_INCREMENT)
#else
#define BF_DCP_CH0SEMA_INCREMENT(v)   (((v) << 0) & BM_DCP_CH0SEMA_INCREMENT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INCREMENT field to a new value.
#define BW_DCP_CH0SEMA_INCREMENT(v)   BF_CS1(DCP_CH0SEMA, INCREMENT, v)
#endif

/* --- Register HW_DCP_CH0SEMA, field VALUE[23:16] (RO)
 *
 * This read-only field shows the current (instantaneous) value of the semaphore counter.
 */

#define BP_DCP_CH0SEMA_VALUE      (16)
#define BM_DCP_CH0SEMA_VALUE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH0STAT - DCP Channel 0 Status Register (RW)
 *
 * The DCP Channel 0 Interrupt Status register contains the interrupt status bit and the tag of the
 * last completed operation from the command chain. If an error occurs during processing, the ERROR
 * bit is set and an interrupt is generated.  DCP_CH0STAT: 0x120  CH0STAT_SET: 0x124  CH0STAT_CLR:
 * 0x128  CH0STAT_TOG: 0x12C  The interrupt status register is updated at the end of each work
 * packet. If the interrupt bit is set in the command packet's command field, an interrupt will be
 * generated once the packet has completed. In addition, the tag value from the command is stored in
 * the TAG field so that software can identify which command structure was the last to complete. If
 * an error occurs, the ERROR bit is set and processing of the command chain is halted.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< This bit will always read 0 in the status register, but will be set to 1 in the packet status field after processing of the packet has completed. This was done so that software can verify that each packet completed properly in a chain of commands for cases when an interrupt is issued only for the last item in a packet. The completion bit for the channel is effectively the channel interrupt status bit.
        unsigned HASH_MISMATCH : 1; //!< The bit indicates that a hashing check operation mismatched for control packets that enable the HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SETUP : 1; //!< This bit indicates that the hardware has detected an invalid programming configuration such as a buffer length that is not a multiple of the natural data size for the operation. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_PACKET : 1; //!< This bit indicates that a a bus error occurred when reading the packet or payload or when writing status back to the packet payload. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SRC : 1; //!< This bit indicates a bus error occurred when reading from the source buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_DST : 1; //!< This bit indicates a bus error occurred when storing to the destination buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_PAGEFAULT : 1; //!< This bit indicates a page fault occurred while converting a virtual address to a physical address.. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned RESERVED1 : 9; //!< Reserved, always set to zero.
        unsigned ERROR_CODE : 8; //!< Indicates additional error codes for some error conditions.
        unsigned TAG : 8; //!< Indicates the tag from the last completed packet in the command structure
    } B;
} hw_dcp_ch0stat_t;
#endif

/*
 * constants & macros for entire DCP_CH0STAT register
 */
#define HW_DCP_CH0STAT_ADDR      (REGS_DCP_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH0STAT           (*(volatile hw_dcp_ch0stat_t *) HW_DCP_CH0STAT_ADDR)
#define HW_DCP_CH0STAT_RD()      (HW_DCP_CH0STAT.U)
#define HW_DCP_CH0STAT_WR(v)     (HW_DCP_CH0STAT.U = (v))
#define HW_DCP_CH0STAT_SET(v)    (HW_DCP_CH0STAT_WR(HW_DCP_CH0STAT_RD() |  (v)))
#define HW_DCP_CH0STAT_CLR(v)    (HW_DCP_CH0STAT_WR(HW_DCP_CH0STAT_RD() & ~(v)))
#define HW_DCP_CH0STAT_TOG(v)    (HW_DCP_CH0STAT_WR(HW_DCP_CH0STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH0STAT bitfields
 */

/* --- Register HW_DCP_CH0STAT, field HASH_MISMATCH[1:1] (RW)
 *
 * The bit indicates that a hashing check operation mismatched for control packets that enable the
 * HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is
 * handled by software.
 */

#define BP_DCP_CH0STAT_HASH_MISMATCH      (1)
#define BM_DCP_CH0STAT_HASH_MISMATCH      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0STAT_HASH_MISMATCH(v)   ((((reg32_t) v) << 1) & BM_DCP_CH0STAT_HASH_MISMATCH)
#else
#define BF_DCP_CH0STAT_HASH_MISMATCH(v)   (((v) << 1) & BM_DCP_CH0STAT_HASH_MISMATCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HASH_MISMATCH field to a new value.
#define BW_DCP_CH0STAT_HASH_MISMATCH(v)   BF_CS1(DCP_CH0STAT, HASH_MISMATCH, v)
#endif

/* --- Register HW_DCP_CH0STAT, field ERROR_SETUP[2:2] (RW)
 *
 * This bit indicates that the hardware has detected an invalid programming configuration such as a
 * buffer length that is not a multiple of the natural data size for the operation. When an error is
 * detected, the channel's processing will stop until the error is handled by software.
 */

#define BP_DCP_CH0STAT_ERROR_SETUP      (2)
#define BM_DCP_CH0STAT_ERROR_SETUP      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0STAT_ERROR_SETUP(v)   ((((reg32_t) v) << 2) & BM_DCP_CH0STAT_ERROR_SETUP)
#else
#define BF_DCP_CH0STAT_ERROR_SETUP(v)   (((v) << 2) & BM_DCP_CH0STAT_ERROR_SETUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SETUP field to a new value.
#define BW_DCP_CH0STAT_ERROR_SETUP(v)   BF_CS1(DCP_CH0STAT, ERROR_SETUP, v)
#endif

/* --- Register HW_DCP_CH0STAT, field ERROR_PACKET[3:3] (RW)
 *
 * This bit indicates that a a bus error occurred when reading the packet or payload or when writing
 * status back to the packet payload. When an error is detected, the channel's processing will stop
 * until the error is handled by software.
 */

#define BP_DCP_CH0STAT_ERROR_PACKET      (3)
#define BM_DCP_CH0STAT_ERROR_PACKET      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0STAT_ERROR_PACKET(v)   ((((reg32_t) v) << 3) & BM_DCP_CH0STAT_ERROR_PACKET)
#else
#define BF_DCP_CH0STAT_ERROR_PACKET(v)   (((v) << 3) & BM_DCP_CH0STAT_ERROR_PACKET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PACKET field to a new value.
#define BW_DCP_CH0STAT_ERROR_PACKET(v)   BF_CS1(DCP_CH0STAT, ERROR_PACKET, v)
#endif

/* --- Register HW_DCP_CH0STAT, field ERROR_SRC[4:4] (RW)
 *
 * This bit indicates a bus error occurred when reading from the source buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH0STAT_ERROR_SRC      (4)
#define BM_DCP_CH0STAT_ERROR_SRC      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0STAT_ERROR_SRC(v)   ((((reg32_t) v) << 4) & BM_DCP_CH0STAT_ERROR_SRC)
#else
#define BF_DCP_CH0STAT_ERROR_SRC(v)   (((v) << 4) & BM_DCP_CH0STAT_ERROR_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SRC field to a new value.
#define BW_DCP_CH0STAT_ERROR_SRC(v)   BF_CS1(DCP_CH0STAT, ERROR_SRC, v)
#endif

/* --- Register HW_DCP_CH0STAT, field ERROR_DST[5:5] (RW)
 *
 * This bit indicates a bus error occurred when storing to the destination buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH0STAT_ERROR_DST      (5)
#define BM_DCP_CH0STAT_ERROR_DST      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0STAT_ERROR_DST(v)   ((((reg32_t) v) << 5) & BM_DCP_CH0STAT_ERROR_DST)
#else
#define BF_DCP_CH0STAT_ERROR_DST(v)   (((v) << 5) & BM_DCP_CH0STAT_ERROR_DST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_DST field to a new value.
#define BW_DCP_CH0STAT_ERROR_DST(v)   BF_CS1(DCP_CH0STAT, ERROR_DST, v)
#endif

/* --- Register HW_DCP_CH0STAT, field ERROR_PAGEFAULT[6:6] (RW)
 *
 * This bit indicates a page fault occurred while converting a virtual address to a physical
 * address.. When an error is detected, the channel's processing will stop until the error handled
 * by software.
 */

#define BP_DCP_CH0STAT_ERROR_PAGEFAULT      (6)
#define BM_DCP_CH0STAT_ERROR_PAGEFAULT      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0STAT_ERROR_PAGEFAULT(v)   ((((reg32_t) v) << 6) & BM_DCP_CH0STAT_ERROR_PAGEFAULT)
#else
#define BF_DCP_CH0STAT_ERROR_PAGEFAULT(v)   (((v) << 6) & BM_DCP_CH0STAT_ERROR_PAGEFAULT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PAGEFAULT field to a new value.
#define BW_DCP_CH0STAT_ERROR_PAGEFAULT(v)   BF_CS1(DCP_CH0STAT, ERROR_PAGEFAULT, v)
#endif

/* --- Register HW_DCP_CH0STAT, field ERROR_CODE[23:16] (RW)
 *
 * Indicates additional error codes for some error conditions.
 *
 * Values:
 * NEXT_CHAIN_IS_0 = 0x01 - Error signalled because the next pointer is 0x00000000
 * NO_CHAIN = 0x02 - Error signalled because the semaphore is nonzero and neither chain bit is set
 * CONTEXT_ERROR = 0x03 - Error signalled because an error was reported reading/writing the context buffer
 * PAYLOAD_ERROR = 0x04 - Error signalled because an error was reported reading/writing the payload
 * INVALID_MODE = 0x05 - Error signalled because the control packet specifies an invalid mode select (for instance, blit +
 *     hash)
 */

#define BP_DCP_CH0STAT_ERROR_CODE      (16)
#define BM_DCP_CH0STAT_ERROR_CODE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0STAT_ERROR_CODE(v)   ((((reg32_t) v) << 16) & BM_DCP_CH0STAT_ERROR_CODE)
#else
#define BF_DCP_CH0STAT_ERROR_CODE(v)   (((v) << 16) & BM_DCP_CH0STAT_ERROR_CODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_CODE field to a new value.
#define BW_DCP_CH0STAT_ERROR_CODE(v)   BF_CS1(DCP_CH0STAT, ERROR_CODE, v)
#endif

#define BV_DCP_CH0STAT_ERROR_CODE__NEXT_CHAIN_IS_0 (0x1) //!< Error signalled because the next pointer is 0x00000000
#define BV_DCP_CH0STAT_ERROR_CODE__NO_CHAIN (0x2) //!< Error signalled because the semaphore is nonzero and neither chain bit is set
#define BV_DCP_CH0STAT_ERROR_CODE__CONTEXT_ERROR (0x3) //!< Error signalled because an error was reported reading/writing the context buffer
#define BV_DCP_CH0STAT_ERROR_CODE__PAYLOAD_ERROR (0x4) //!< Error signalled because an error was reported reading/writing the payload
#define BV_DCP_CH0STAT_ERROR_CODE__INVALID_MODE (0x5) //!< Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)

/* --- Register HW_DCP_CH0STAT, field TAG[31:24] (RO)
 *
 * Indicates the tag from the last completed packet in the command structure
 */

#define BP_DCP_CH0STAT_TAG      (24)
#define BM_DCP_CH0STAT_TAG      (0xff000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH0OPTS - DCP Channel 0 Options Register (RW)
 *
 * The DCP Channel 0 Options Status register contains optional control information that may be used
 * to further tune the behavior of the channel.  DCP_CH0OPTS: 0x130  CH0OPTS_SET: 0x134
 * CH0OPTS_CLR: 0x138  CH0OPTS_TOG: 0x13C  The options register can be used to control optional
 * features of the channels.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RECOVERY_TIMER : 16; //!< This field indicates the recovery time for the channel. After each operation, the recover timer for the channel is initiallized with this value and then decremented until the timer reaches zero. The channel will not initiate another operation for the next packet in the chain until the recovery time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles, providing a range of 0ns to 8.3ms at 133 MHz operation.
        unsigned RESERVED0 : 16; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch0opts_t;
#endif

/*
 * constants & macros for entire DCP_CH0OPTS register
 */
#define HW_DCP_CH0OPTS_ADDR      (REGS_DCP_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH0OPTS           (*(volatile hw_dcp_ch0opts_t *) HW_DCP_CH0OPTS_ADDR)
#define HW_DCP_CH0OPTS_RD()      (HW_DCP_CH0OPTS.U)
#define HW_DCP_CH0OPTS_WR(v)     (HW_DCP_CH0OPTS.U = (v))
#define HW_DCP_CH0OPTS_SET(v)    (HW_DCP_CH0OPTS_WR(HW_DCP_CH0OPTS_RD() |  (v)))
#define HW_DCP_CH0OPTS_CLR(v)    (HW_DCP_CH0OPTS_WR(HW_DCP_CH0OPTS_RD() & ~(v)))
#define HW_DCP_CH0OPTS_TOG(v)    (HW_DCP_CH0OPTS_WR(HW_DCP_CH0OPTS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH0OPTS bitfields
 */

/* --- Register HW_DCP_CH0OPTS, field RECOVERY_TIMER[15:0] (RW)
 *
 * This field indicates the recovery time for the channel. After each operation, the recover timer
 * for the channel is initiallized with this value and then decremented until the timer reaches
 * zero. The channel will not initiate another operation for the next packet in the chain until the
 * recovery time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles,
 * providing a range of 0ns to 8.3ms at 133 MHz operation.
 */

#define BP_DCP_CH0OPTS_RECOVERY_TIMER      (0)
#define BM_DCP_CH0OPTS_RECOVERY_TIMER      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH0OPTS_RECOVERY_TIMER(v)   ((((reg32_t) v) << 0) & BM_DCP_CH0OPTS_RECOVERY_TIMER)
#else
#define BF_DCP_CH0OPTS_RECOVERY_TIMER(v)   (((v) << 0) & BM_DCP_CH0OPTS_RECOVERY_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RECOVERY_TIMER field to a new value.
#define BW_DCP_CH0OPTS_RECOVERY_TIMER(v)   BF_CS1(DCP_CH0OPTS, RECOVERY_TIMER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH1CMDPTR - DCP Channel 1 Command Pointer Address Register (RW)
 *
 * The DCP channel 1 current command address register points to the multiword descriptor that is to
 * be executed (or currently being executed). The channel may be activated by writing the command
 * pointer address to a valid descriptor in memory and then updating the semaphore to a non-zero
 * value. After the engine completes processing of a descriptor, the "next_ptr" field from the
 * descriptor is moved into this register to enable processing of the next descriptor. All channels
 * with a non-zero semaphore value will arbitrate for access to the engine for the subsequent
 * operation.  DCP Channel 1 is controlled by a variable sized command structure. This register
 * points to the command structure to be executed.   EXAMPLE   DCP_CHn_CMDPTR_WR(1, v); // Write
 * channel 1 command pointer pCurptr = (DCP_chn_cmdptr_t *) DCP_CHn_CMDPTR_RD(1); // Read current
 * command pointer
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Pointer to descriptor structure to be processed for channel 1.
    } B;
} hw_dcp_ch1cmdptr_t;
#endif

/*
 * constants & macros for entire DCP_CH1CMDPTR register
 */
#define HW_DCP_CH1CMDPTR_ADDR      (REGS_DCP_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH1CMDPTR           (*(volatile hw_dcp_ch1cmdptr_t *) HW_DCP_CH1CMDPTR_ADDR)
#define HW_DCP_CH1CMDPTR_RD()      (HW_DCP_CH1CMDPTR.U)
#define HW_DCP_CH1CMDPTR_WR(v)     (HW_DCP_CH1CMDPTR.U = (v))
#define HW_DCP_CH1CMDPTR_SET(v)    (HW_DCP_CH1CMDPTR_WR(HW_DCP_CH1CMDPTR_RD() |  (v)))
#define HW_DCP_CH1CMDPTR_CLR(v)    (HW_DCP_CH1CMDPTR_WR(HW_DCP_CH1CMDPTR_RD() & ~(v)))
#define HW_DCP_CH1CMDPTR_TOG(v)    (HW_DCP_CH1CMDPTR_WR(HW_DCP_CH1CMDPTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH1CMDPTR bitfields
 */

/* --- Register HW_DCP_CH1CMDPTR, field ADDR[31:0] (RW)
 *
 * Pointer to descriptor structure to be processed for channel 1.
 */

#define BP_DCP_CH1CMDPTR_ADDR      (0)
#define BM_DCP_CH1CMDPTR_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1CMDPTR_ADDR(v)   ((((reg32_t) v) << 0) & BM_DCP_CH1CMDPTR_ADDR)
#else
#define BF_DCP_CH1CMDPTR_ADDR(v)   (((v) << 0) & BM_DCP_CH1CMDPTR_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_DCP_CH1CMDPTR_ADDR(v)   BF_CS1(DCP_CH1CMDPTR, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH1SEMA - DCP Channel 1 Semaphore Register (RW)
 *
 * The DCP Channel 1 semaphore register is used to synchronize the ARM platform instruction stream
 * and the DMA chain processing state. After a command chain has been generated in memory, software
 * should write the address of the first command descriptor to the CMDPTR register and then write a
 * non-zero value to the semaphore register to indicate that the channel is active. Each command
 * packet has a chaining bit which indicates that another descriptor should be loaded into the
 * channel upon completion of the current descriptor. If the chaining bit is not set, the next
 * address will not be loaded into the CMDPTR register. Each packet also contains a "decrement
 * semaphore" bit, which indicates that the counting semaphore should be decremented after the
 * operation. A channel is considered active when the semaphore is a non-zero value. When
 * programming a series operations, software must properly program the semaphore values in
 * conjuction with the "decrement_semaphore" bits in the control packets to ensure that the proper
 * number of descriptors are activated. A semaphore may be cleared by software by writing 0xFF to
 * the DCP_CHnSEMA_CLR register. The logic will also clear the semaphore if an error has occurred.
 * Each DCP channel has an 8 bit counting semaphore that is used to synchronize between the program
 * stream and and the DCP chain processing. DCP processing continues until the engine attempts to
 * decrement a semaphore that has already reached a value of zero. When the attempt is made, the DCP
 * channel is stalled until software increments the semaphore count.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INCREMENT : 8; //!< The value written to this field is added to the semaphore count in an atomic way such that simultaneous software adds and DCP hardware substracts happening on the same clock are protected. This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count by two, unless the DCP channel decrements the count on the same clock, then the count is incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR register.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
        unsigned VALUE : 8; //!< This read-only field shows the current (instantaneous) value of the semaphore counter.
        unsigned RESERVED1 : 8; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch1sema_t;
#endif

/*
 * constants & macros for entire DCP_CH1SEMA register
 */
#define HW_DCP_CH1SEMA_ADDR      (REGS_DCP_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH1SEMA           (*(volatile hw_dcp_ch1sema_t *) HW_DCP_CH1SEMA_ADDR)
#define HW_DCP_CH1SEMA_RD()      (HW_DCP_CH1SEMA.U)
#define HW_DCP_CH1SEMA_WR(v)     (HW_DCP_CH1SEMA.U = (v))
#define HW_DCP_CH1SEMA_SET(v)    (HW_DCP_CH1SEMA_WR(HW_DCP_CH1SEMA_RD() |  (v)))
#define HW_DCP_CH1SEMA_CLR(v)    (HW_DCP_CH1SEMA_WR(HW_DCP_CH1SEMA_RD() & ~(v)))
#define HW_DCP_CH1SEMA_TOG(v)    (HW_DCP_CH1SEMA_WR(HW_DCP_CH1SEMA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH1SEMA bitfields
 */

/* --- Register HW_DCP_CH1SEMA, field INCREMENT[7:0] (RW)
 *
 * The value written to this field is added to the semaphore count in an atomic way such that
 * simultaneous software adds and DCP hardware substracts happening on the same clock are protected.
 * This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count
 * by two, unless the DCP channel decrements the count on the same clock, then the count is
 * incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR
 * register.
 */

#define BP_DCP_CH1SEMA_INCREMENT      (0)
#define BM_DCP_CH1SEMA_INCREMENT      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1SEMA_INCREMENT(v)   ((((reg32_t) v) << 0) & BM_DCP_CH1SEMA_INCREMENT)
#else
#define BF_DCP_CH1SEMA_INCREMENT(v)   (((v) << 0) & BM_DCP_CH1SEMA_INCREMENT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INCREMENT field to a new value.
#define BW_DCP_CH1SEMA_INCREMENT(v)   BF_CS1(DCP_CH1SEMA, INCREMENT, v)
#endif

/* --- Register HW_DCP_CH1SEMA, field VALUE[23:16] (RO)
 *
 * This read-only field shows the current (instantaneous) value of the semaphore counter.
 */

#define BP_DCP_CH1SEMA_VALUE      (16)
#define BM_DCP_CH1SEMA_VALUE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH1STAT - DCP Channel 1 Status Register (RW)
 *
 * The DCP Channel 1 Interrupt Status register contains the interrupt status bit and the tag of the
 * last completed operation from the command chain. If an error occurs during processing, the ERROR
 * bit is set and an interrupt is generated.  CH1STAT: 0x160  CH1STAT_SET: 0x164  CH1STAT_CLR: 0x168
 * CH1STAT_TOG: 0x16C  The interrupt status register is updated at the end of each work packet. If
 * the interrupt bit is set in the command packet's command field, an interrupt will be generated
 * once the packet has completed. In addition, the tag value from the command is stored in the TAG
 * field so that software can identify which command structure was the last to complete. If an error
 * occurs, the ERROR bit is set and processing of the command chain is halted.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< This bit will always read 0 in the status register, but will be set to 1 in the packet status field after processing of the packet has completed. This was done so that software can verify that each packet completed properly in a chain of commands for cases when an interrupt is issued only for the last item in a packet. The completion bit for the channel is effectively the channel interrupt status bit.
        unsigned HASH_MISMATCH : 1; //!< The bit indicates that a hashing check operation mismatched for control packets that enable the HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SETUP : 1; //!< This bit indicates that the hardware detected an invalid programming configuration such as a buffer length that is not a multiple of the natural data size for the operation. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_PACKET : 1; //!< This bit indicates that a bus error occurs when reading the packet or payload or when writing status back to the packet paylaod. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SRC : 1; //!< This bit indicates a bus error occurred when reading from the source buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_DST : 1; //!< This bit indicates a bus error occurred when storing to the destination buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_PAGEFAULT : 1; //!< This bit indicates a page fault occurred while converting a virtual address to a physical address.. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned RESERVED1 : 9; //!< Reserved, always set to zero.
        unsigned ERROR_CODE : 8; //!< Indicates additional error codes for some error conditions.
        unsigned TAG : 8; //!< Indicates the tag from the last completed packet in the command structure
    } B;
} hw_dcp_ch1stat_t;
#endif

/*
 * constants & macros for entire DCP_CH1STAT register
 */
#define HW_DCP_CH1STAT_ADDR      (REGS_DCP_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH1STAT           (*(volatile hw_dcp_ch1stat_t *) HW_DCP_CH1STAT_ADDR)
#define HW_DCP_CH1STAT_RD()      (HW_DCP_CH1STAT.U)
#define HW_DCP_CH1STAT_WR(v)     (HW_DCP_CH1STAT.U = (v))
#define HW_DCP_CH1STAT_SET(v)    (HW_DCP_CH1STAT_WR(HW_DCP_CH1STAT_RD() |  (v)))
#define HW_DCP_CH1STAT_CLR(v)    (HW_DCP_CH1STAT_WR(HW_DCP_CH1STAT_RD() & ~(v)))
#define HW_DCP_CH1STAT_TOG(v)    (HW_DCP_CH1STAT_WR(HW_DCP_CH1STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH1STAT bitfields
 */

/* --- Register HW_DCP_CH1STAT, field HASH_MISMATCH[1:1] (RW)
 *
 * The bit indicates that a hashing check operation mismatched for control packets that enable the
 * HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is
 * handled by software.
 */

#define BP_DCP_CH1STAT_HASH_MISMATCH      (1)
#define BM_DCP_CH1STAT_HASH_MISMATCH      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1STAT_HASH_MISMATCH(v)   ((((reg32_t) v) << 1) & BM_DCP_CH1STAT_HASH_MISMATCH)
#else
#define BF_DCP_CH1STAT_HASH_MISMATCH(v)   (((v) << 1) & BM_DCP_CH1STAT_HASH_MISMATCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HASH_MISMATCH field to a new value.
#define BW_DCP_CH1STAT_HASH_MISMATCH(v)   BF_CS1(DCP_CH1STAT, HASH_MISMATCH, v)
#endif

/* --- Register HW_DCP_CH1STAT, field ERROR_SETUP[2:2] (RW)
 *
 * This bit indicates that the hardware detected an invalid programming configuration such as a
 * buffer length that is not a multiple of the natural data size for the operation. When an error is
 * detected, the channel's processing will stop until the error is handled by software.
 */

#define BP_DCP_CH1STAT_ERROR_SETUP      (2)
#define BM_DCP_CH1STAT_ERROR_SETUP      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1STAT_ERROR_SETUP(v)   ((((reg32_t) v) << 2) & BM_DCP_CH1STAT_ERROR_SETUP)
#else
#define BF_DCP_CH1STAT_ERROR_SETUP(v)   (((v) << 2) & BM_DCP_CH1STAT_ERROR_SETUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SETUP field to a new value.
#define BW_DCP_CH1STAT_ERROR_SETUP(v)   BF_CS1(DCP_CH1STAT, ERROR_SETUP, v)
#endif

/* --- Register HW_DCP_CH1STAT, field ERROR_PACKET[3:3] (RW)
 *
 * This bit indicates that a bus error occurs when reading the packet or payload or when writing
 * status back to the packet paylaod. When an error is detected, the channel's processing will stop
 * until the error is handled by software.
 */

#define BP_DCP_CH1STAT_ERROR_PACKET      (3)
#define BM_DCP_CH1STAT_ERROR_PACKET      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1STAT_ERROR_PACKET(v)   ((((reg32_t) v) << 3) & BM_DCP_CH1STAT_ERROR_PACKET)
#else
#define BF_DCP_CH1STAT_ERROR_PACKET(v)   (((v) << 3) & BM_DCP_CH1STAT_ERROR_PACKET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PACKET field to a new value.
#define BW_DCP_CH1STAT_ERROR_PACKET(v)   BF_CS1(DCP_CH1STAT, ERROR_PACKET, v)
#endif

/* --- Register HW_DCP_CH1STAT, field ERROR_SRC[4:4] (RW)
 *
 * This bit indicates a bus error occurred when reading from the source buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH1STAT_ERROR_SRC      (4)
#define BM_DCP_CH1STAT_ERROR_SRC      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1STAT_ERROR_SRC(v)   ((((reg32_t) v) << 4) & BM_DCP_CH1STAT_ERROR_SRC)
#else
#define BF_DCP_CH1STAT_ERROR_SRC(v)   (((v) << 4) & BM_DCP_CH1STAT_ERROR_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SRC field to a new value.
#define BW_DCP_CH1STAT_ERROR_SRC(v)   BF_CS1(DCP_CH1STAT, ERROR_SRC, v)
#endif

/* --- Register HW_DCP_CH1STAT, field ERROR_DST[5:5] (RW)
 *
 * This bit indicates a bus error occurred when storing to the destination buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH1STAT_ERROR_DST      (5)
#define BM_DCP_CH1STAT_ERROR_DST      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1STAT_ERROR_DST(v)   ((((reg32_t) v) << 5) & BM_DCP_CH1STAT_ERROR_DST)
#else
#define BF_DCP_CH1STAT_ERROR_DST(v)   (((v) << 5) & BM_DCP_CH1STAT_ERROR_DST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_DST field to a new value.
#define BW_DCP_CH1STAT_ERROR_DST(v)   BF_CS1(DCP_CH1STAT, ERROR_DST, v)
#endif

/* --- Register HW_DCP_CH1STAT, field ERROR_PAGEFAULT[6:6] (RW)
 *
 * This bit indicates a page fault occurred while converting a virtual address to a physical
 * address.. When an error is detected, the channel's processing will stop until the error handled
 * by software.
 */

#define BP_DCP_CH1STAT_ERROR_PAGEFAULT      (6)
#define BM_DCP_CH1STAT_ERROR_PAGEFAULT      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1STAT_ERROR_PAGEFAULT(v)   ((((reg32_t) v) << 6) & BM_DCP_CH1STAT_ERROR_PAGEFAULT)
#else
#define BF_DCP_CH1STAT_ERROR_PAGEFAULT(v)   (((v) << 6) & BM_DCP_CH1STAT_ERROR_PAGEFAULT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PAGEFAULT field to a new value.
#define BW_DCP_CH1STAT_ERROR_PAGEFAULT(v)   BF_CS1(DCP_CH1STAT, ERROR_PAGEFAULT, v)
#endif

/* --- Register HW_DCP_CH1STAT, field ERROR_CODE[23:16] (RW)
 *
 * Indicates additional error codes for some error conditions.
 *
 * Values:
 * NEXT_CHAIN_IS_0 = 0x01 - Error signalled because the next pointer is 0x00000000
 * NO_CHAIN = 0x02 - Error signalled because the semaphore is nonzero and neither chain bit is set
 * CONTEXT_ERROR = 0x03 - Error signalled because an error was reported reading/writing the context buffer
 * PAYLOAD_ERROR = 0x04 - Error signalled because an error was reported reading/writing the payload
 * INVALID_MODE = 0x05 - Error signalled because the control packet specifies an invalid mode select (for instance, blit +
 *     hash)
 */

#define BP_DCP_CH1STAT_ERROR_CODE      (16)
#define BM_DCP_CH1STAT_ERROR_CODE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1STAT_ERROR_CODE(v)   ((((reg32_t) v) << 16) & BM_DCP_CH1STAT_ERROR_CODE)
#else
#define BF_DCP_CH1STAT_ERROR_CODE(v)   (((v) << 16) & BM_DCP_CH1STAT_ERROR_CODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_CODE field to a new value.
#define BW_DCP_CH1STAT_ERROR_CODE(v)   BF_CS1(DCP_CH1STAT, ERROR_CODE, v)
#endif

#define BV_DCP_CH1STAT_ERROR_CODE__NEXT_CHAIN_IS_0 (0x1) //!< Error signalled because the next pointer is 0x00000000
#define BV_DCP_CH1STAT_ERROR_CODE__NO_CHAIN (0x2) //!< Error signalled because the semaphore is nonzero and neither chain bit is set
#define BV_DCP_CH1STAT_ERROR_CODE__CONTEXT_ERROR (0x3) //!< Error signalled because an error was reported reading/writing the context buffer
#define BV_DCP_CH1STAT_ERROR_CODE__PAYLOAD_ERROR (0x4) //!< Error signalled because an error was reported reading/writing the payload
#define BV_DCP_CH1STAT_ERROR_CODE__INVALID_MODE (0x5) //!< Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)

/* --- Register HW_DCP_CH1STAT, field TAG[31:24] (RO)
 *
 * Indicates the tag from the last completed packet in the command structure
 */

#define BP_DCP_CH1STAT_TAG      (24)
#define BM_DCP_CH1STAT_TAG      (0xff000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH1OPTS - DCP Channel 1 Options Register (RW)
 *
 * The DCP Channel 1 Options Status register contains optional control information that may be used
 * to further tune the behavior of the channel.  DCP_CH1OPTS: 0x170  DCP_CH1OPTS_SET: 0x174
 * CH1OPTS_CLR: 0x178  CH1OPTS_TOG: 0x17C  The options register can be used to control optional
 * features of the channels.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RECOVERY_TIMER : 16; //!< This field indicates the recovery time for the channel. After each operation, the recover timer for the channel is initiallized with this value and then decremented until the timer reaches zero. The channel will not initiate operation on the next packet in the chain until the recovery time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles, providing a range of 0ns to 8.3ms at 133 MHz operation.
        unsigned RESERVED0 : 16; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch1opts_t;
#endif

/*
 * constants & macros for entire DCP_CH1OPTS register
 */
#define HW_DCP_CH1OPTS_ADDR      (REGS_DCP_BASE + 0x170)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH1OPTS           (*(volatile hw_dcp_ch1opts_t *) HW_DCP_CH1OPTS_ADDR)
#define HW_DCP_CH1OPTS_RD()      (HW_DCP_CH1OPTS.U)
#define HW_DCP_CH1OPTS_WR(v)     (HW_DCP_CH1OPTS.U = (v))
#define HW_DCP_CH1OPTS_SET(v)    (HW_DCP_CH1OPTS_WR(HW_DCP_CH1OPTS_RD() |  (v)))
#define HW_DCP_CH1OPTS_CLR(v)    (HW_DCP_CH1OPTS_WR(HW_DCP_CH1OPTS_RD() & ~(v)))
#define HW_DCP_CH1OPTS_TOG(v)    (HW_DCP_CH1OPTS_WR(HW_DCP_CH1OPTS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH1OPTS bitfields
 */

/* --- Register HW_DCP_CH1OPTS, field RECOVERY_TIMER[15:0] (RW)
 *
 * This field indicates the recovery time for the channel. After each operation, the recover timer
 * for the channel is initiallized with this value and then decremented until the timer reaches
 * zero. The channel will not initiate operation on the next packet in the chain until the recovery
 * time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles, providing a
 * range of 0ns to 8.3ms at 133 MHz operation.
 */

#define BP_DCP_CH1OPTS_RECOVERY_TIMER      (0)
#define BM_DCP_CH1OPTS_RECOVERY_TIMER      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH1OPTS_RECOVERY_TIMER(v)   ((((reg32_t) v) << 0) & BM_DCP_CH1OPTS_RECOVERY_TIMER)
#else
#define BF_DCP_CH1OPTS_RECOVERY_TIMER(v)   (((v) << 0) & BM_DCP_CH1OPTS_RECOVERY_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RECOVERY_TIMER field to a new value.
#define BW_DCP_CH1OPTS_RECOVERY_TIMER(v)   BF_CS1(DCP_CH1OPTS, RECOVERY_TIMER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH2CMDPTR - DCP Channel 2 Command Pointer Address Register (RW)
 *
 * The DCP channel 2 current command address register points to the multiword descriptor that is to
 * be executed (or currently being executed). The channel may be activated by writing the command
 * pointer address to a valid descriptor in memory and then updating the semaphore to a non-zero
 * value. After the engine completes processing of a descriptor, the "next_ptr" field from the
 * descriptor is moved into this register to enable processing of the next descriptor. All channels
 * with a non-zero semaphore value will arbitrate for access to the engine for the subsequent
 * operation.  DCP Channel 2 is controlled by a variable sized command structure. This register
 * points to the command structure to be executed.   EXAMPLE   DCP_CHn_CMDPTR_WR(2, v); // Write
 * channel 2 command pointer pCurptr = (DCP_chn_cmdptr_t *) DCP_CHn_CMDPTR_RD(2); // Read current
 * command pointer
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Pointer to descriptor structure to be processed for channel 2.
    } B;
} hw_dcp_ch2cmdptr_t;
#endif

/*
 * constants & macros for entire DCP_CH2CMDPTR register
 */
#define HW_DCP_CH2CMDPTR_ADDR      (REGS_DCP_BASE + 0x180)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH2CMDPTR           (*(volatile hw_dcp_ch2cmdptr_t *) HW_DCP_CH2CMDPTR_ADDR)
#define HW_DCP_CH2CMDPTR_RD()      (HW_DCP_CH2CMDPTR.U)
#define HW_DCP_CH2CMDPTR_WR(v)     (HW_DCP_CH2CMDPTR.U = (v))
#define HW_DCP_CH2CMDPTR_SET(v)    (HW_DCP_CH2CMDPTR_WR(HW_DCP_CH2CMDPTR_RD() |  (v)))
#define HW_DCP_CH2CMDPTR_CLR(v)    (HW_DCP_CH2CMDPTR_WR(HW_DCP_CH2CMDPTR_RD() & ~(v)))
#define HW_DCP_CH2CMDPTR_TOG(v)    (HW_DCP_CH2CMDPTR_WR(HW_DCP_CH2CMDPTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH2CMDPTR bitfields
 */

/* --- Register HW_DCP_CH2CMDPTR, field ADDR[31:0] (RW)
 *
 * Pointer to descriptor structure to be processed for channel 2.
 */

#define BP_DCP_CH2CMDPTR_ADDR      (0)
#define BM_DCP_CH2CMDPTR_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2CMDPTR_ADDR(v)   ((((reg32_t) v) << 0) & BM_DCP_CH2CMDPTR_ADDR)
#else
#define BF_DCP_CH2CMDPTR_ADDR(v)   (((v) << 0) & BM_DCP_CH2CMDPTR_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_DCP_CH2CMDPTR_ADDR(v)   BF_CS1(DCP_CH2CMDPTR, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH2SEMA - DCP Channel 2 Semaphore Register (RW)
 *
 * The DCP Channel 2 semaphore register is used to synchronize the ARM platform instruction stream
 * and the DMA chain processing state. After a command chain has been generated in memory, software
 * should write the address of the first command descriptor to the CMDPTR register and then write a
 * non-zero value to the semaphore register to indicate that the channel is active. Each command
 * packet has a chaining bit which indicates that another descriptor should be loaded into the
 * channel upon completion of the current descriptor. If the chaining bit is not set, the next
 * address will not be loaded into the CMDPTR register. Each packet also contains a "decrement
 * semaphore" bit, which indicates that the counting semaphore should be decremented after the
 * operation. A channel is considered active when the semaphore is a non-zero value. When
 * programming a series operations, software must properly program the semaphore values in
 * conjuction with the "decrement_semaphore" bits in the control packets to ensure that the proper
 * number of descriptors are activated. A semaphore may be cleared by software by writing 0xFF to
 * the DCP_CHnSEMA_CLR register. The logic will also clear the semaphore if an error has occurred.
 * Each DCP channel has an 8 bit counting semaphore that is used to synchronize between the program
 * stream and and the DCP chain processing. DCP processing continues until the engine attempts to
 * decrement a semaphore that has already reached a value of zero. When the attempt is made, the DCP
 * channel is stalled until software increments the semaphore count.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INCREMENT : 8; //!< The value written to this field is added to the semaphore count in an atomic way such that simultaneous software adds and DCP hardware substracts happening on the same clock are protected. This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count by two, unless the DCP channel decrements the count on the same clock, then the count is incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR register.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
        unsigned VALUE : 8; //!< This read-only field shows the current (instantaneous) value of the semaphore counter.
        unsigned RESERVED1 : 8; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch2sema_t;
#endif

/*
 * constants & macros for entire DCP_CH2SEMA register
 */
#define HW_DCP_CH2SEMA_ADDR      (REGS_DCP_BASE + 0x190)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH2SEMA           (*(volatile hw_dcp_ch2sema_t *) HW_DCP_CH2SEMA_ADDR)
#define HW_DCP_CH2SEMA_RD()      (HW_DCP_CH2SEMA.U)
#define HW_DCP_CH2SEMA_WR(v)     (HW_DCP_CH2SEMA.U = (v))
#define HW_DCP_CH2SEMA_SET(v)    (HW_DCP_CH2SEMA_WR(HW_DCP_CH2SEMA_RD() |  (v)))
#define HW_DCP_CH2SEMA_CLR(v)    (HW_DCP_CH2SEMA_WR(HW_DCP_CH2SEMA_RD() & ~(v)))
#define HW_DCP_CH2SEMA_TOG(v)    (HW_DCP_CH2SEMA_WR(HW_DCP_CH2SEMA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH2SEMA bitfields
 */

/* --- Register HW_DCP_CH2SEMA, field INCREMENT[7:0] (RW)
 *
 * The value written to this field is added to the semaphore count in an atomic way such that
 * simultaneous software adds and DCP hardware substracts happening on the same clock are protected.
 * This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count
 * by two, unless the DCP channel decrements the count on the same clock, then the count is
 * incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR
 * register.
 */

#define BP_DCP_CH2SEMA_INCREMENT      (0)
#define BM_DCP_CH2SEMA_INCREMENT      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2SEMA_INCREMENT(v)   ((((reg32_t) v) << 0) & BM_DCP_CH2SEMA_INCREMENT)
#else
#define BF_DCP_CH2SEMA_INCREMENT(v)   (((v) << 0) & BM_DCP_CH2SEMA_INCREMENT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INCREMENT field to a new value.
#define BW_DCP_CH2SEMA_INCREMENT(v)   BF_CS1(DCP_CH2SEMA, INCREMENT, v)
#endif

/* --- Register HW_DCP_CH2SEMA, field VALUE[23:16] (RO)
 *
 * This read-only field shows the current (instantaneous) value of the semaphore counter.
 */

#define BP_DCP_CH2SEMA_VALUE      (16)
#define BM_DCP_CH2SEMA_VALUE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH2STAT - DCP Channel 2 Status Register (RW)
 *
 * The DCP Channel 2 Interrupt Status register contains the interrupt status bit and the tag of the
 * last completed operation from the command chain. If an error occurs during processing, the ERROR
 * bit is set and an interrupt is generated.  CH2STAT: 0x1A0  CH2STAT_SET: 0x1A4  CH2STAT_CLR: 0x1A8
 * CH2STAT_TOG: 0x1AC  The interrupt status register is updated at the end of each work packet. If
 * the interrupt bit is set in the command packet's command field, an interrupt will be generated
 * once the packet has completed. In addition, the tag value from the command is stored in the TAG
 * field so that software can identify which command structure was the last to complete. If an error
 * occurs, the ERROR bit is set and processing of the command chain is halted.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< This bit will always read 0 in the status register, but will be set to 1 in the packet status field after processing of the packet has completed. This was done so that software can verify that each packet completed properly in a chain of commands for cases when an interrupt is issued only for the last item in a packet. The completion bit for the channel is effectively the channel interrupt status bit.
        unsigned HASH_MISMATCH : 1; //!< The bit indicates that a hashing check operation mismatched for control packets that enable the HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SETUP : 1; //!< This bit indicates that the hardware detected an invalid programming configuration such as a buffer length that is not a multiple of the natural data size for the operation. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_PACKET : 1; //!< This bit indicates that a bus error occurred when reading the packet or payload or when writing status back to the packet paylaod. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SRC : 1; //!< This bit indicates a bus error occurred when reading from the source buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_DST : 1; //!< This bit indicates a bus error occurred when storing to the destination buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_PAGEFAULT : 1; //!< This bit indicates a page fault occurred while converting a virtual address to a physical address.. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned RESERVED1 : 9; //!< Reserved, always set to zero.
        unsigned ERROR_CODE : 8; //!< Indicates additional error codes for some error conditions.
        unsigned TAG : 8; //!< Indicates the tag from the last completed packet in the command structure
    } B;
} hw_dcp_ch2stat_t;
#endif

/*
 * constants & macros for entire DCP_CH2STAT register
 */
#define HW_DCP_CH2STAT_ADDR      (REGS_DCP_BASE + 0x1a0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH2STAT           (*(volatile hw_dcp_ch2stat_t *) HW_DCP_CH2STAT_ADDR)
#define HW_DCP_CH2STAT_RD()      (HW_DCP_CH2STAT.U)
#define HW_DCP_CH2STAT_WR(v)     (HW_DCP_CH2STAT.U = (v))
#define HW_DCP_CH2STAT_SET(v)    (HW_DCP_CH2STAT_WR(HW_DCP_CH2STAT_RD() |  (v)))
#define HW_DCP_CH2STAT_CLR(v)    (HW_DCP_CH2STAT_WR(HW_DCP_CH2STAT_RD() & ~(v)))
#define HW_DCP_CH2STAT_TOG(v)    (HW_DCP_CH2STAT_WR(HW_DCP_CH2STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH2STAT bitfields
 */

/* --- Register HW_DCP_CH2STAT, field HASH_MISMATCH[1:1] (RW)
 *
 * The bit indicates that a hashing check operation mismatched for control packets that enable the
 * HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is
 * handled by software.
 */

#define BP_DCP_CH2STAT_HASH_MISMATCH      (1)
#define BM_DCP_CH2STAT_HASH_MISMATCH      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2STAT_HASH_MISMATCH(v)   ((((reg32_t) v) << 1) & BM_DCP_CH2STAT_HASH_MISMATCH)
#else
#define BF_DCP_CH2STAT_HASH_MISMATCH(v)   (((v) << 1) & BM_DCP_CH2STAT_HASH_MISMATCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HASH_MISMATCH field to a new value.
#define BW_DCP_CH2STAT_HASH_MISMATCH(v)   BF_CS1(DCP_CH2STAT, HASH_MISMATCH, v)
#endif

/* --- Register HW_DCP_CH2STAT, field ERROR_SETUP[2:2] (RW)
 *
 * This bit indicates that the hardware detected an invalid programming configuration such as a
 * buffer length that is not a multiple of the natural data size for the operation. When an error is
 * detected, the channel's processing will stop until the error is handled by software.
 */

#define BP_DCP_CH2STAT_ERROR_SETUP      (2)
#define BM_DCP_CH2STAT_ERROR_SETUP      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2STAT_ERROR_SETUP(v)   ((((reg32_t) v) << 2) & BM_DCP_CH2STAT_ERROR_SETUP)
#else
#define BF_DCP_CH2STAT_ERROR_SETUP(v)   (((v) << 2) & BM_DCP_CH2STAT_ERROR_SETUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SETUP field to a new value.
#define BW_DCP_CH2STAT_ERROR_SETUP(v)   BF_CS1(DCP_CH2STAT, ERROR_SETUP, v)
#endif

/* --- Register HW_DCP_CH2STAT, field ERROR_PACKET[3:3] (RW)
 *
 * This bit indicates that a bus error occurred when reading the packet or payload or when writing
 * status back to the packet paylaod. When an error is detected, the channel's processing will stop
 * until the error is handled by software.
 */

#define BP_DCP_CH2STAT_ERROR_PACKET      (3)
#define BM_DCP_CH2STAT_ERROR_PACKET      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2STAT_ERROR_PACKET(v)   ((((reg32_t) v) << 3) & BM_DCP_CH2STAT_ERROR_PACKET)
#else
#define BF_DCP_CH2STAT_ERROR_PACKET(v)   (((v) << 3) & BM_DCP_CH2STAT_ERROR_PACKET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PACKET field to a new value.
#define BW_DCP_CH2STAT_ERROR_PACKET(v)   BF_CS1(DCP_CH2STAT, ERROR_PACKET, v)
#endif

/* --- Register HW_DCP_CH2STAT, field ERROR_SRC[4:4] (RW)
 *
 * This bit indicates a bus error occurred when reading from the source buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH2STAT_ERROR_SRC      (4)
#define BM_DCP_CH2STAT_ERROR_SRC      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2STAT_ERROR_SRC(v)   ((((reg32_t) v) << 4) & BM_DCP_CH2STAT_ERROR_SRC)
#else
#define BF_DCP_CH2STAT_ERROR_SRC(v)   (((v) << 4) & BM_DCP_CH2STAT_ERROR_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SRC field to a new value.
#define BW_DCP_CH2STAT_ERROR_SRC(v)   BF_CS1(DCP_CH2STAT, ERROR_SRC, v)
#endif

/* --- Register HW_DCP_CH2STAT, field ERROR_DST[5:5] (RW)
 *
 * This bit indicates a bus error occurred when storing to the destination buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH2STAT_ERROR_DST      (5)
#define BM_DCP_CH2STAT_ERROR_DST      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2STAT_ERROR_DST(v)   ((((reg32_t) v) << 5) & BM_DCP_CH2STAT_ERROR_DST)
#else
#define BF_DCP_CH2STAT_ERROR_DST(v)   (((v) << 5) & BM_DCP_CH2STAT_ERROR_DST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_DST field to a new value.
#define BW_DCP_CH2STAT_ERROR_DST(v)   BF_CS1(DCP_CH2STAT, ERROR_DST, v)
#endif

/* --- Register HW_DCP_CH2STAT, field ERROR_PAGEFAULT[6:6] (RW)
 *
 * This bit indicates a page fault occurred while converting a virtual address to a physical
 * address.. When an error is detected, the channel's processing will stop until the error handled
 * by software.
 */

#define BP_DCP_CH2STAT_ERROR_PAGEFAULT      (6)
#define BM_DCP_CH2STAT_ERROR_PAGEFAULT      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2STAT_ERROR_PAGEFAULT(v)   ((((reg32_t) v) << 6) & BM_DCP_CH2STAT_ERROR_PAGEFAULT)
#else
#define BF_DCP_CH2STAT_ERROR_PAGEFAULT(v)   (((v) << 6) & BM_DCP_CH2STAT_ERROR_PAGEFAULT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PAGEFAULT field to a new value.
#define BW_DCP_CH2STAT_ERROR_PAGEFAULT(v)   BF_CS1(DCP_CH2STAT, ERROR_PAGEFAULT, v)
#endif

/* --- Register HW_DCP_CH2STAT, field ERROR_CODE[23:16] (RW)
 *
 * Indicates additional error codes for some error conditions.
 *
 * Values:
 * NEXT_CHAIN_IS_0 = 0x01 - Error signalled because the next pointer is 0x00000000
 * NO_CHAIN = 0x02 - Error signalled because the semaphore is nonzero and neither chain bit is set
 * CONTEXT_ERROR = 0x03 - Error signalled because an error was reported reading/writing the context buffer
 * PAYLOAD_ERROR = 0x04 - Error signalled because an error was reported reading/writing the payload
 * INVALID_MODE = 0x05 - Error signalled because the control packet specifies an invalid mode select (for instance, blit +
 *     hash)
 */

#define BP_DCP_CH2STAT_ERROR_CODE      (16)
#define BM_DCP_CH2STAT_ERROR_CODE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2STAT_ERROR_CODE(v)   ((((reg32_t) v) << 16) & BM_DCP_CH2STAT_ERROR_CODE)
#else
#define BF_DCP_CH2STAT_ERROR_CODE(v)   (((v) << 16) & BM_DCP_CH2STAT_ERROR_CODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_CODE field to a new value.
#define BW_DCP_CH2STAT_ERROR_CODE(v)   BF_CS1(DCP_CH2STAT, ERROR_CODE, v)
#endif

#define BV_DCP_CH2STAT_ERROR_CODE__NEXT_CHAIN_IS_0 (0x1) //!< Error signalled because the next pointer is 0x00000000
#define BV_DCP_CH2STAT_ERROR_CODE__NO_CHAIN (0x2) //!< Error signalled because the semaphore is nonzero and neither chain bit is set
#define BV_DCP_CH2STAT_ERROR_CODE__CONTEXT_ERROR (0x3) //!< Error signalled because an error was reported reading/writing the context buffer
#define BV_DCP_CH2STAT_ERROR_CODE__PAYLOAD_ERROR (0x4) //!< Error signalled because an error was reported reading/writing the payload
#define BV_DCP_CH2STAT_ERROR_CODE__INVALID_MODE (0x5) //!< Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)

/* --- Register HW_DCP_CH2STAT, field TAG[31:24] (RO)
 *
 * Indicates the tag from the last completed packet in the command structure
 */

#define BP_DCP_CH2STAT_TAG      (24)
#define BM_DCP_CH2STAT_TAG      (0xff000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH2OPTS - DCP Channel 2 Options Register (RW)
 *
 * The DCP Channel 2 Options Status register contains optional control information that may be used
 * to further tune the behavior of the channel.  CH2OPTS: 0x1B0  CH2OPTS_SET: 0x1B4  CH2OPTS_CLR:
 * 0x1B8  CH2OPTS_TOG: 0x1BC  The options register can be used to control optional features of the
 * channels.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RECOVERY_TIMER : 16; //!< This field indicates the recovery time for the channel. After each operation, the recover timer for the channel is initiallized with this value and then decremented until the timer reaches zero. The channel will not initiate operation on the next packet in the chain until the recovery time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles, providing a range of 0ns to 8.3ms at 133 MHz operation.
        unsigned RESERVED0 : 16; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch2opts_t;
#endif

/*
 * constants & macros for entire DCP_CH2OPTS register
 */
#define HW_DCP_CH2OPTS_ADDR      (REGS_DCP_BASE + 0x1b0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH2OPTS           (*(volatile hw_dcp_ch2opts_t *) HW_DCP_CH2OPTS_ADDR)
#define HW_DCP_CH2OPTS_RD()      (HW_DCP_CH2OPTS.U)
#define HW_DCP_CH2OPTS_WR(v)     (HW_DCP_CH2OPTS.U = (v))
#define HW_DCP_CH2OPTS_SET(v)    (HW_DCP_CH2OPTS_WR(HW_DCP_CH2OPTS_RD() |  (v)))
#define HW_DCP_CH2OPTS_CLR(v)    (HW_DCP_CH2OPTS_WR(HW_DCP_CH2OPTS_RD() & ~(v)))
#define HW_DCP_CH2OPTS_TOG(v)    (HW_DCP_CH2OPTS_WR(HW_DCP_CH2OPTS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH2OPTS bitfields
 */

/* --- Register HW_DCP_CH2OPTS, field RECOVERY_TIMER[15:0] (RW)
 *
 * This field indicates the recovery time for the channel. After each operation, the recover timer
 * for the channel is initiallized with this value and then decremented until the timer reaches
 * zero. The channel will not initiate operation on the next packet in the chain until the recovery
 * time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles, providing a
 * range of 0ns to 8.3ms at 133 MHz operation.
 */

#define BP_DCP_CH2OPTS_RECOVERY_TIMER      (0)
#define BM_DCP_CH2OPTS_RECOVERY_TIMER      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH2OPTS_RECOVERY_TIMER(v)   ((((reg32_t) v) << 0) & BM_DCP_CH2OPTS_RECOVERY_TIMER)
#else
#define BF_DCP_CH2OPTS_RECOVERY_TIMER(v)   (((v) << 0) & BM_DCP_CH2OPTS_RECOVERY_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RECOVERY_TIMER field to a new value.
#define BW_DCP_CH2OPTS_RECOVERY_TIMER(v)   BF_CS1(DCP_CH2OPTS, RECOVERY_TIMER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH3CMDPTR - DCP Channel 3 Command Pointer Address Register (RW)
 *
 * The DCP channel 3 current command address register points to the multiword descriptor that is to
 * be executed (or currently being executed). The channel may be activated by writing the command
 * pointer address to a valid descriptor in memory and then updating the semaphore to a non-zero
 * value. After the engine completes processing of a descriptor, the "next_ptr" field from the
 * descriptor is moved into this register to enable processing of the next descriptor. All channels
 * with a non-zero semaphore value will arbitrate for access to the engine for the subsequent
 * operation.  DCP Channel 3 is controlled by a variable sized command structure. This register
 * points to the command structure to be executed.   EXAMPLE   DCP_CHn_CMDPTR_WR(3, v); // Write
 * channel 3 command pointer pCurptr = (DCP_chn_cmdptr_t *) DCP_CHn_CMDPTR_RD(3); // Read current
 * command pointer
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ADDR : 32; //!< Pointer to descriptor structure to be processed for channel 3.
    } B;
} hw_dcp_ch3cmdptr_t;
#endif

/*
 * constants & macros for entire DCP_CH3CMDPTR register
 */
#define HW_DCP_CH3CMDPTR_ADDR      (REGS_DCP_BASE + 0x1c0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH3CMDPTR           (*(volatile hw_dcp_ch3cmdptr_t *) HW_DCP_CH3CMDPTR_ADDR)
#define HW_DCP_CH3CMDPTR_RD()      (HW_DCP_CH3CMDPTR.U)
#define HW_DCP_CH3CMDPTR_WR(v)     (HW_DCP_CH3CMDPTR.U = (v))
#define HW_DCP_CH3CMDPTR_SET(v)    (HW_DCP_CH3CMDPTR_WR(HW_DCP_CH3CMDPTR_RD() |  (v)))
#define HW_DCP_CH3CMDPTR_CLR(v)    (HW_DCP_CH3CMDPTR_WR(HW_DCP_CH3CMDPTR_RD() & ~(v)))
#define HW_DCP_CH3CMDPTR_TOG(v)    (HW_DCP_CH3CMDPTR_WR(HW_DCP_CH3CMDPTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH3CMDPTR bitfields
 */

/* --- Register HW_DCP_CH3CMDPTR, field ADDR[31:0] (RW)
 *
 * Pointer to descriptor structure to be processed for channel 3.
 */

#define BP_DCP_CH3CMDPTR_ADDR      (0)
#define BM_DCP_CH3CMDPTR_ADDR      (0xffffffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3CMDPTR_ADDR(v)   ((((reg32_t) v) << 0) & BM_DCP_CH3CMDPTR_ADDR)
#else
#define BF_DCP_CH3CMDPTR_ADDR(v)   (((v) << 0) & BM_DCP_CH3CMDPTR_ADDR)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDR field to a new value.
#define BW_DCP_CH3CMDPTR_ADDR(v)   BF_CS1(DCP_CH3CMDPTR, ADDR, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH3SEMA - DCP Channel 3 Semaphore Register (RW)
 *
 * The DCP Channel 3 semaphore register is used to synchronize the ARM platform instruction stream
 * and the DMA chain processing state. After a command chain has been generated in memory, software
 * should write the address of the first command descriptor to the CMDPTR register and then write a
 * non-zero value to the semaphore register to indicate that the channel is active. Each command
 * packet has a chaining bit which indicates that another descriptor should be loaded into the
 * channel upon completion of the current descriptor. If the chaining bit is not set, the next
 * address will not be loaded into the CMDPTR register. Each packet also contains a "decrement
 * semaphore" bit, which indicates that the counting semaphore should be decremented after the
 * operation. A channel is considered active when the semaphore is a non-zero value. When
 * programming a series operations, software must properly program the semaphore values in
 * conjuction with the "decrement_semaphore" bits in the control packets to ensure that the proper
 * number of descriptors are activated. A semaphore may be cleared by software by writing 0xFF to
 * the DCP_CHnSEMA_CLR register. The logic will also clear the semaphore if an error has occurred.
 * Each DCP channel has an 8 bit counting semaphore that is used to synchronize between the program
 * stream and and the DCP chain processing. DCP processing continues until the engine attempts to
 * decrement a semaphore that has already reached a value of zero. When the attempt is made, the DCP
 * channel is stalled until software increments the semaphore count.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INCREMENT : 8; //!< The value written to this field is added to the semaphore count in an atomic way such that simultaneous software adds and DCP hardware substracts happening on the same clock are protected. This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count by two, unless the DCP channel decrements the count on the same clock, then the count is incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR register.
        unsigned RESERVED0 : 8; //!< Reserved, always set to zero.
        unsigned VALUE : 8; //!< This read-only field shows the current (instantaneous) value of the semaphore counter.
        unsigned RESERVED1 : 8; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch3sema_t;
#endif

/*
 * constants & macros for entire DCP_CH3SEMA register
 */
#define HW_DCP_CH3SEMA_ADDR      (REGS_DCP_BASE + 0x1d0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH3SEMA           (*(volatile hw_dcp_ch3sema_t *) HW_DCP_CH3SEMA_ADDR)
#define HW_DCP_CH3SEMA_RD()      (HW_DCP_CH3SEMA.U)
#define HW_DCP_CH3SEMA_WR(v)     (HW_DCP_CH3SEMA.U = (v))
#define HW_DCP_CH3SEMA_SET(v)    (HW_DCP_CH3SEMA_WR(HW_DCP_CH3SEMA_RD() |  (v)))
#define HW_DCP_CH3SEMA_CLR(v)    (HW_DCP_CH3SEMA_WR(HW_DCP_CH3SEMA_RD() & ~(v)))
#define HW_DCP_CH3SEMA_TOG(v)    (HW_DCP_CH3SEMA_WR(HW_DCP_CH3SEMA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH3SEMA bitfields
 */

/* --- Register HW_DCP_CH3SEMA, field INCREMENT[7:0] (RW)
 *
 * The value written to this field is added to the semaphore count in an atomic way such that
 * simultaneous software adds and DCP hardware substracts happening on the same clock are protected.
 * This bit field reads back a value of 0x00. Writing a value of 0x02 increments the semaphore count
 * by two, unless the DCP channel decrements the count on the same clock, then the count is
 * incremented by a net one. The semaphore may be cleared by writing 0xFF to the DCP_CHnSEMA_CLR
 * register.
 */

#define BP_DCP_CH3SEMA_INCREMENT      (0)
#define BM_DCP_CH3SEMA_INCREMENT      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3SEMA_INCREMENT(v)   ((((reg32_t) v) << 0) & BM_DCP_CH3SEMA_INCREMENT)
#else
#define BF_DCP_CH3SEMA_INCREMENT(v)   (((v) << 0) & BM_DCP_CH3SEMA_INCREMENT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INCREMENT field to a new value.
#define BW_DCP_CH3SEMA_INCREMENT(v)   BF_CS1(DCP_CH3SEMA, INCREMENT, v)
#endif

/* --- Register HW_DCP_CH3SEMA, field VALUE[23:16] (RO)
 *
 * This read-only field shows the current (instantaneous) value of the semaphore counter.
 */

#define BP_DCP_CH3SEMA_VALUE      (16)
#define BM_DCP_CH3SEMA_VALUE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH3STAT - DCP Channel 3 Status Register (RW)
 *
 * The DCP Channel 3 Interrupt Status register contains the interrupt status bit and the tag of the
 * last completed operation from the command chain. If an error occurs during processing, the ERROR
 * bit is set and an interrupt is generated.  DCP_CH3STAT: 0x1E0  CH3STAT_SET: 0x1E4  CH3STAT_CLR:
 * 0x1E8  CH3STAT_TOG: 0x1EC  The interrupt status register is updated at the end of each work
 * packet. If the interrupt bit is set in the command packet's command field, an interrupt will be
 * generated once the packet has completed. In addition, the tag value from the command is stored in
 * the TAG field so that software can identify which command structure was the last to complete. If
 * an error occurs, the ERROR bit is set and processing of the command chain is halted.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RESERVED0 : 1; //!< This bit will always read 0 in the status register, but will be set to 1 in the packet status field after processing of the packet has completed. This was done so that software can verify that each packet completed properly in a chain of commands for cases when an interrupt is issued only for the last item in a packet. The completion bit for the channel is effectively the channel interrupt status bit.
        unsigned HASH_MISMATCH : 1; //!< The bit indicates that a hashing check operation mismatched for control packets that enable the HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SETUP : 1; //!< This bit indicates that the hardware detected an invalid programming configuration such as a buffer length that is not a multiple of the natural data size for the operation. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_PACKET : 1; //!< This bit indicates that a bus error occurred when reading the packet or payload or when writing status back to the packet paylaod. When an error is detected, the channel's processing will stop until the error is handled by software.
        unsigned ERROR_SRC : 1; //!< This bit indicates a bus error occurred when reading from the source buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_DST : 1; //!< This bit indicates a bus error occurred when storing to the destination buffer. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned ERROR_PAGEFAULT : 1; //!< This bit indicates a page fault occurred while converting a virtual address to a physical address.. When an error is detected, the channel's processing will stop until the error handled by software.
        unsigned RESERVED1 : 9; //!< Reserved, always set to zero.
        unsigned ERROR_CODE : 8; //!< Indicates additional error codes for some error conditions.
        unsigned TAG : 8; //!< Indicates the tag from the last completed packet in the command structure
    } B;
} hw_dcp_ch3stat_t;
#endif

/*
 * constants & macros for entire DCP_CH3STAT register
 */
#define HW_DCP_CH3STAT_ADDR      (REGS_DCP_BASE + 0x1e0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH3STAT           (*(volatile hw_dcp_ch3stat_t *) HW_DCP_CH3STAT_ADDR)
#define HW_DCP_CH3STAT_RD()      (HW_DCP_CH3STAT.U)
#define HW_DCP_CH3STAT_WR(v)     (HW_DCP_CH3STAT.U = (v))
#define HW_DCP_CH3STAT_SET(v)    (HW_DCP_CH3STAT_WR(HW_DCP_CH3STAT_RD() |  (v)))
#define HW_DCP_CH3STAT_CLR(v)    (HW_DCP_CH3STAT_WR(HW_DCP_CH3STAT_RD() & ~(v)))
#define HW_DCP_CH3STAT_TOG(v)    (HW_DCP_CH3STAT_WR(HW_DCP_CH3STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH3STAT bitfields
 */

/* --- Register HW_DCP_CH3STAT, field HASH_MISMATCH[1:1] (RW)
 *
 * The bit indicates that a hashing check operation mismatched for control packets that enable the
 * HASH_CHECK bit. When an error is detected, the channel's processing will stop until the error is
 * handled by software.
 */

#define BP_DCP_CH3STAT_HASH_MISMATCH      (1)
#define BM_DCP_CH3STAT_HASH_MISMATCH      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3STAT_HASH_MISMATCH(v)   ((((reg32_t) v) << 1) & BM_DCP_CH3STAT_HASH_MISMATCH)
#else
#define BF_DCP_CH3STAT_HASH_MISMATCH(v)   (((v) << 1) & BM_DCP_CH3STAT_HASH_MISMATCH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the HASH_MISMATCH field to a new value.
#define BW_DCP_CH3STAT_HASH_MISMATCH(v)   BF_CS1(DCP_CH3STAT, HASH_MISMATCH, v)
#endif

/* --- Register HW_DCP_CH3STAT, field ERROR_SETUP[2:2] (RW)
 *
 * This bit indicates that the hardware detected an invalid programming configuration such as a
 * buffer length that is not a multiple of the natural data size for the operation. When an error is
 * detected, the channel's processing will stop until the error is handled by software.
 */

#define BP_DCP_CH3STAT_ERROR_SETUP      (2)
#define BM_DCP_CH3STAT_ERROR_SETUP      (0x00000004)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3STAT_ERROR_SETUP(v)   ((((reg32_t) v) << 2) & BM_DCP_CH3STAT_ERROR_SETUP)
#else
#define BF_DCP_CH3STAT_ERROR_SETUP(v)   (((v) << 2) & BM_DCP_CH3STAT_ERROR_SETUP)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SETUP field to a new value.
#define BW_DCP_CH3STAT_ERROR_SETUP(v)   BF_CS1(DCP_CH3STAT, ERROR_SETUP, v)
#endif

/* --- Register HW_DCP_CH3STAT, field ERROR_PACKET[3:3] (RW)
 *
 * This bit indicates that a bus error occurred when reading the packet or payload or when writing
 * status back to the packet paylaod. When an error is detected, the channel's processing will stop
 * until the error is handled by software.
 */

#define BP_DCP_CH3STAT_ERROR_PACKET      (3)
#define BM_DCP_CH3STAT_ERROR_PACKET      (0x00000008)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3STAT_ERROR_PACKET(v)   ((((reg32_t) v) << 3) & BM_DCP_CH3STAT_ERROR_PACKET)
#else
#define BF_DCP_CH3STAT_ERROR_PACKET(v)   (((v) << 3) & BM_DCP_CH3STAT_ERROR_PACKET)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PACKET field to a new value.
#define BW_DCP_CH3STAT_ERROR_PACKET(v)   BF_CS1(DCP_CH3STAT, ERROR_PACKET, v)
#endif

/* --- Register HW_DCP_CH3STAT, field ERROR_SRC[4:4] (RW)
 *
 * This bit indicates a bus error occurred when reading from the source buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH3STAT_ERROR_SRC      (4)
#define BM_DCP_CH3STAT_ERROR_SRC      (0x00000010)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3STAT_ERROR_SRC(v)   ((((reg32_t) v) << 4) & BM_DCP_CH3STAT_ERROR_SRC)
#else
#define BF_DCP_CH3STAT_ERROR_SRC(v)   (((v) << 4) & BM_DCP_CH3STAT_ERROR_SRC)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_SRC field to a new value.
#define BW_DCP_CH3STAT_ERROR_SRC(v)   BF_CS1(DCP_CH3STAT, ERROR_SRC, v)
#endif

/* --- Register HW_DCP_CH3STAT, field ERROR_DST[5:5] (RW)
 *
 * This bit indicates a bus error occurred when storing to the destination buffer. When an error is
 * detected, the channel's processing will stop until the error handled by software.
 */

#define BP_DCP_CH3STAT_ERROR_DST      (5)
#define BM_DCP_CH3STAT_ERROR_DST      (0x00000020)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3STAT_ERROR_DST(v)   ((((reg32_t) v) << 5) & BM_DCP_CH3STAT_ERROR_DST)
#else
#define BF_DCP_CH3STAT_ERROR_DST(v)   (((v) << 5) & BM_DCP_CH3STAT_ERROR_DST)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_DST field to a new value.
#define BW_DCP_CH3STAT_ERROR_DST(v)   BF_CS1(DCP_CH3STAT, ERROR_DST, v)
#endif

/* --- Register HW_DCP_CH3STAT, field ERROR_PAGEFAULT[6:6] (RW)
 *
 * This bit indicates a page fault occurred while converting a virtual address to a physical
 * address.. When an error is detected, the channel's processing will stop until the error handled
 * by software.
 */

#define BP_DCP_CH3STAT_ERROR_PAGEFAULT      (6)
#define BM_DCP_CH3STAT_ERROR_PAGEFAULT      (0x00000040)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3STAT_ERROR_PAGEFAULT(v)   ((((reg32_t) v) << 6) & BM_DCP_CH3STAT_ERROR_PAGEFAULT)
#else
#define BF_DCP_CH3STAT_ERROR_PAGEFAULT(v)   (((v) << 6) & BM_DCP_CH3STAT_ERROR_PAGEFAULT)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_PAGEFAULT field to a new value.
#define BW_DCP_CH3STAT_ERROR_PAGEFAULT(v)   BF_CS1(DCP_CH3STAT, ERROR_PAGEFAULT, v)
#endif

/* --- Register HW_DCP_CH3STAT, field ERROR_CODE[23:16] (RW)
 *
 * Indicates additional error codes for some error conditions.
 *
 * Values:
 * NEXT_CHAIN_IS_0 = 0x01 - Error signalled because the next pointer is 0x00000000
 * NO_CHAIN = 0x02 - Error signalled because the semaphore is nonzero and neither chain bit is set
 * CONTEXT_ERROR = 0x03 - Error signalled because an error was reported reading/writing the context buffer
 * PAYLOAD_ERROR = 0x04 - Error signalled because an error was reported reading/writing the payload
 * INVALID_MODE = 0x05 - Error signalled because the control packet specifies an invalid mode select (for instance, blit +
 *     hash)
 */

#define BP_DCP_CH3STAT_ERROR_CODE      (16)
#define BM_DCP_CH3STAT_ERROR_CODE      (0x00ff0000)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3STAT_ERROR_CODE(v)   ((((reg32_t) v) << 16) & BM_DCP_CH3STAT_ERROR_CODE)
#else
#define BF_DCP_CH3STAT_ERROR_CODE(v)   (((v) << 16) & BM_DCP_CH3STAT_ERROR_CODE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ERROR_CODE field to a new value.
#define BW_DCP_CH3STAT_ERROR_CODE(v)   BF_CS1(DCP_CH3STAT, ERROR_CODE, v)
#endif

#define BV_DCP_CH3STAT_ERROR_CODE__NEXT_CHAIN_IS_0 (0x1) //!< Error signalled because the next pointer is 0x00000000
#define BV_DCP_CH3STAT_ERROR_CODE__NO_CHAIN (0x2) //!< Error signalled because the semaphore is nonzero and neither chain bit is set
#define BV_DCP_CH3STAT_ERROR_CODE__CONTEXT_ERROR (0x3) //!< Error signalled because an error was reported reading/writing the context buffer
#define BV_DCP_CH3STAT_ERROR_CODE__PAYLOAD_ERROR (0x4) //!< Error signalled because an error was reported reading/writing the payload
#define BV_DCP_CH3STAT_ERROR_CODE__INVALID_MODE (0x5) //!< Error signalled because the control packet specifies an invalid mode select (for instance, blit + hash)

/* --- Register HW_DCP_CH3STAT, field TAG[31:24] (RO)
 *
 * Indicates the tag from the last completed packet in the command structure
 */

#define BP_DCP_CH3STAT_TAG      (24)
#define BM_DCP_CH3STAT_TAG      (0xff000000)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_CH3OPTS - DCP Channel 3 Options Register (RW)
 *
 * The DCP Channel 3 Options Status register contains optional control information that may be used
 * to further tune the behavior of the channel.  DCP_CH3OPTS: 0x1F0  CH3OPTS_SET: 0x1F4
 * CH3OPTS_CLR: 0x1F8  CH3OPTS_TOG: 0x1FC  The options register can be used to control optional
 * features of the channels.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned RECOVERY_TIMER : 16; //!< This field indicates the recovery time for the channel. After each operation, the recover timer for the channel is initiallized with this value and then decremented until the timer reaches zero. The channel will not initiate operation on the next packet in the chain until the recovery time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles, providing a range of 0ns to 8.3ms at 133 MHz operation.
        unsigned RESERVED0 : 16; //!< Reserved, always set to zero.
    } B;
} hw_dcp_ch3opts_t;
#endif

/*
 * constants & macros for entire DCP_CH3OPTS register
 */
#define HW_DCP_CH3OPTS_ADDR      (REGS_DCP_BASE + 0x1f0)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_CH3OPTS           (*(volatile hw_dcp_ch3opts_t *) HW_DCP_CH3OPTS_ADDR)
#define HW_DCP_CH3OPTS_RD()      (HW_DCP_CH3OPTS.U)
#define HW_DCP_CH3OPTS_WR(v)     (HW_DCP_CH3OPTS.U = (v))
#define HW_DCP_CH3OPTS_SET(v)    (HW_DCP_CH3OPTS_WR(HW_DCP_CH3OPTS_RD() |  (v)))
#define HW_DCP_CH3OPTS_CLR(v)    (HW_DCP_CH3OPTS_WR(HW_DCP_CH3OPTS_RD() & ~(v)))
#define HW_DCP_CH3OPTS_TOG(v)    (HW_DCP_CH3OPTS_WR(HW_DCP_CH3OPTS_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_CH3OPTS bitfields
 */

/* --- Register HW_DCP_CH3OPTS, field RECOVERY_TIMER[15:0] (RW)
 *
 * This field indicates the recovery time for the channel. After each operation, the recover timer
 * for the channel is initiallized with this value and then decremented until the timer reaches
 * zero. The channel will not initiate operation on the next packet in the chain until the recovery
 * time has been satisfied. The timebase for the recovery timer is 16 HCLK clock cycles, providing a
 * range of 0ns to 8.3ms at 133 MHz operation.
 */

#define BP_DCP_CH3OPTS_RECOVERY_TIMER      (0)
#define BM_DCP_CH3OPTS_RECOVERY_TIMER      (0x0000ffff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_CH3OPTS_RECOVERY_TIMER(v)   ((((reg32_t) v) << 0) & BM_DCP_CH3OPTS_RECOVERY_TIMER)
#else
#define BF_DCP_CH3OPTS_RECOVERY_TIMER(v)   (((v) << 0) & BM_DCP_CH3OPTS_RECOVERY_TIMER)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the RECOVERY_TIMER field to a new value.
#define BW_DCP_CH3OPTS_RECOVERY_TIMER(v)   BF_CS1(DCP_CH3OPTS, RECOVERY_TIMER, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_DBGSELECT - DCP Debug Select Register (RW)
 *
 * This register selects a debug register to view.  This register selects debug information to
 * return in the debug data register.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned INDEX : 8; //!< Selects a value to read via the debug data register.
        unsigned RESERVED0 : 24; //!< Reserved, always set to zero.
    } B;
} hw_dcp_dbgselect_t;
#endif

/*
 * constants & macros for entire DCP_DBGSELECT register
 */
#define HW_DCP_DBGSELECT_ADDR      (REGS_DCP_BASE + 0x400)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_DBGSELECT           (*(volatile hw_dcp_dbgselect_t *) HW_DCP_DBGSELECT_ADDR)
#define HW_DCP_DBGSELECT_RD()      (HW_DCP_DBGSELECT.U)
#define HW_DCP_DBGSELECT_WR(v)     (HW_DCP_DBGSELECT.U = (v))
#define HW_DCP_DBGSELECT_SET(v)    (HW_DCP_DBGSELECT_WR(HW_DCP_DBGSELECT_RD() |  (v)))
#define HW_DCP_DBGSELECT_CLR(v)    (HW_DCP_DBGSELECT_WR(HW_DCP_DBGSELECT_RD() & ~(v)))
#define HW_DCP_DBGSELECT_TOG(v)    (HW_DCP_DBGSELECT_WR(HW_DCP_DBGSELECT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_DBGSELECT bitfields
 */

/* --- Register HW_DCP_DBGSELECT, field INDEX[7:0] (RW)
 *
 * Selects a value to read via the debug data register.
 *
 * Values:
 * CONTROL = 0x01 - 
 * OTPKEY0 = 0x10 - 
 * OTPKEY1 = 0x11 - 
 * OTPKEY2 = 0x12 - 
 * OTPKEY3 = 0x13 - 
 */

#define BP_DCP_DBGSELECT_INDEX      (0)
#define BM_DCP_DBGSELECT_INDEX      (0x000000ff)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_DBGSELECT_INDEX(v)   ((((reg32_t) v) << 0) & BM_DCP_DBGSELECT_INDEX)
#else
#define BF_DCP_DBGSELECT_INDEX(v)   (((v) << 0) & BM_DCP_DBGSELECT_INDEX)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the INDEX field to a new value.
#define BW_DCP_DBGSELECT_INDEX(v)   BF_CS1(DCP_DBGSELECT, INDEX, v)
#endif

#define BV_DCP_DBGSELECT_INDEX__CONTROL (0x1) //!< 
#define BV_DCP_DBGSELECT_INDEX__OTPKEY0 (0x10) //!< 
#define BV_DCP_DBGSELECT_INDEX__OTPKEY1 (0x11) //!< 
#define BV_DCP_DBGSELECT_INDEX__OTPKEY2 (0x12) //!< 
#define BV_DCP_DBGSELECT_INDEX__OTPKEY3 (0x13) //!< 

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_DBGDATA - DCP Debug Data Register (RO)
 *
 * Reading this register returns the debug data value from the selected index.  This register
 * returns the debug data from the selected debug index source.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned DATA : 32; //!< Debug Data
    } B;
} hw_dcp_dbgdata_t;
#endif

/*
 * constants & macros for entire DCP_DBGDATA register
 */
#define HW_DCP_DBGDATA_ADDR      (REGS_DCP_BASE + 0x410)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_DBGDATA           (*(volatile hw_dcp_dbgdata_t *) HW_DCP_DBGDATA_ADDR)
#define HW_DCP_DBGDATA_RD()      (HW_DCP_DBGDATA.U)
#endif

/*
 * constants & macros for individual DCP_DBGDATA bitfields
 */

/* --- Register HW_DCP_DBGDATA, field DATA[31:0] (RO)
 *
 * Debug Data
 */

#define BP_DCP_DBGDATA_DATA      (0)
#define BM_DCP_DBGDATA_DATA      (0xffffffff)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_PAGETABLE - DCP Page Table Register (RW)
 *
 * The DCP Page Table register controls the virtual memory functionality of the DCP. It provides a
 * base address for the page table as well as an enable/disable bit and the ability to flush the
 * cached page table entries.  This register returns the debug data from the selected debug index
 * source.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned ENABLE : 1; //!< Page Table Enable control. Virtual addressing will only be used when this bit is set to a 1. Disabling the page table will not flush any cached entries, so software should write the FLUSH high and enable LOW when updating page tables.
        unsigned FLUSH : 1; //!< Page Table Flush control. To flush the TLB, write this bit to a 1 then back to a 0.
        unsigned BASE : 30; //!< Page Table Base Address. The page table must be word aligned and the pointer should reference a page table in the standard ARM format.
    } B;
} hw_dcp_pagetable_t;
#endif

/*
 * constants & macros for entire DCP_PAGETABLE register
 */
#define HW_DCP_PAGETABLE_ADDR      (REGS_DCP_BASE + 0x420)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_PAGETABLE           (*(volatile hw_dcp_pagetable_t *) HW_DCP_PAGETABLE_ADDR)
#define HW_DCP_PAGETABLE_RD()      (HW_DCP_PAGETABLE.U)
#define HW_DCP_PAGETABLE_WR(v)     (HW_DCP_PAGETABLE.U = (v))
#define HW_DCP_PAGETABLE_SET(v)    (HW_DCP_PAGETABLE_WR(HW_DCP_PAGETABLE_RD() |  (v)))
#define HW_DCP_PAGETABLE_CLR(v)    (HW_DCP_PAGETABLE_WR(HW_DCP_PAGETABLE_RD() & ~(v)))
#define HW_DCP_PAGETABLE_TOG(v)    (HW_DCP_PAGETABLE_WR(HW_DCP_PAGETABLE_RD() ^  (v)))
#endif

/*
 * constants & macros for individual DCP_PAGETABLE bitfields
 */

/* --- Register HW_DCP_PAGETABLE, field ENABLE[0:0] (RW)
 *
 * Page Table Enable control. Virtual addressing will only be used when this bit is set to a 1.
 * Disabling the page table will not flush any cached entries, so software should write the FLUSH
 * high and enable LOW when updating page tables.
 */

#define BP_DCP_PAGETABLE_ENABLE      (0)
#define BM_DCP_PAGETABLE_ENABLE      (0x00000001)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_PAGETABLE_ENABLE(v)   ((((reg32_t) v) << 0) & BM_DCP_PAGETABLE_ENABLE)
#else
#define BF_DCP_PAGETABLE_ENABLE(v)   (((v) << 0) & BM_DCP_PAGETABLE_ENABLE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the ENABLE field to a new value.
#define BW_DCP_PAGETABLE_ENABLE(v)   BF_CS1(DCP_PAGETABLE, ENABLE, v)
#endif

/* --- Register HW_DCP_PAGETABLE, field FLUSH[1:1] (RW)
 *
 * Page Table Flush control. To flush the TLB, write this bit to a 1 then back to a 0.
 */

#define BP_DCP_PAGETABLE_FLUSH      (1)
#define BM_DCP_PAGETABLE_FLUSH      (0x00000002)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_PAGETABLE_FLUSH(v)   ((((reg32_t) v) << 1) & BM_DCP_PAGETABLE_FLUSH)
#else
#define BF_DCP_PAGETABLE_FLUSH(v)   (((v) << 1) & BM_DCP_PAGETABLE_FLUSH)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the FLUSH field to a new value.
#define BW_DCP_PAGETABLE_FLUSH(v)   BF_CS1(DCP_PAGETABLE, FLUSH, v)
#endif

/* --- Register HW_DCP_PAGETABLE, field BASE[31:2] (RW)
 *
 * Page Table Base Address. The page table must be word aligned and the pointer should reference a
 * page table in the standard ARM format.
 */

#define BP_DCP_PAGETABLE_BASE      (2)
#define BM_DCP_PAGETABLE_BASE      (0xfffffffc)

#ifndef __LANGUAGE_ASM__
#define BF_DCP_PAGETABLE_BASE(v)   ((((reg32_t) v) << 2) & BM_DCP_PAGETABLE_BASE)
#else
#define BF_DCP_PAGETABLE_BASE(v)   (((v) << 2) & BM_DCP_PAGETABLE_BASE)
#endif
#ifndef __LANGUAGE_ASM__
//! @brief Set the BASE field to a new value.
#define BW_DCP_PAGETABLE_BASE(v)   BF_CS1(DCP_PAGETABLE, BASE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DCP_VERSION - DCP Version Register (RO)
 *
 * Read-only register indicating implemented version of the DCP.  This register returns the debug
 * data from the selected debug index source.
 */
typedef union
{
    reg32_t U;
    struct
    {
        unsigned STEP : 16; //!< Fixed read-onlyl value reflecting the stepping of version of the design implementation.
        unsigned MINOR : 8; //!< Fixed read-onlyl value reflecting the MINOR version of the design implementation.
        unsigned MAJOR : 8; //!< Fixed read-onlyl value reflecting the MAJOR version of the design implementation.
    } B;
} hw_dcp_version_t;
#endif

/*
 * constants & macros for entire DCP_VERSION register
 */
#define HW_DCP_VERSION_ADDR      (REGS_DCP_BASE + 0x430)

#ifndef __LANGUAGE_ASM__
#define HW_DCP_VERSION           (*(volatile hw_dcp_version_t *) HW_DCP_VERSION_ADDR)
#define HW_DCP_VERSION_RD()      (HW_DCP_VERSION.U)
#endif

/*
 * constants & macros for individual DCP_VERSION bitfields
 */

/* --- Register HW_DCP_VERSION, field STEP[15:0] (RO)
 *
 * Fixed read-onlyl value reflecting the stepping of version of the design implementation.
 */

#define BP_DCP_VERSION_STEP      (0)
#define BM_DCP_VERSION_STEP      (0x0000ffff)

/* --- Register HW_DCP_VERSION, field MINOR[23:16] (RO)
 *
 * Fixed read-onlyl value reflecting the MINOR version of the design implementation.
 */

#define BP_DCP_VERSION_MINOR      (16)
#define BM_DCP_VERSION_MINOR      (0x00ff0000)

/* --- Register HW_DCP_VERSION, field MAJOR[31:24] (RO)
 *
 * Fixed read-onlyl value reflecting the MAJOR version of the design implementation.
 */

#define BP_DCP_VERSION_MAJOR      (24)
#define BM_DCP_VERSION_MAJOR      (0xff000000)


/*!
 * @brief All DCP module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_dcp_ctrl_t CTRL; //!< DCP Control Register 0
    reg32_t _reserved0[3];
    volatile hw_dcp_stat_t STAT; //!< DCP Status Register
    reg32_t _reserved1[3];
    volatile hw_dcp_channelctrl_t CHANNELCTRL; //!< DCP Channel Control Register
    reg32_t _reserved2[3];
    volatile hw_dcp_capability0_t CAPABILITY0; //!< DCP Capability 0 Register
    reg32_t _reserved3[3];
    volatile hw_dcp_capability1_t CAPABILITY1; //!< DCP Capability 1 Register
    reg32_t _reserved4[3];
    volatile hw_dcp_context_t CONTEXT; //!< DCP Context Buffer Pointer
    reg32_t _reserved5[3];
    volatile hw_dcp_key_t KEY; //!< DCP Key Index
    reg32_t _reserved6[3];
    volatile hw_dcp_keydata_t KEYDATA; //!< DCP Key Data
    reg32_t _reserved7[3];
    volatile hw_dcp_packet0_t PACKET0; //!< DCP Work Packet 0 Status Register
    reg32_t _reserved8[3];
    volatile hw_dcp_packet1_t PACKET1; //!< DCP Work Packet 1 Status Register
    reg32_t _reserved9[3];
    volatile hw_dcp_packet2_t PACKET2; //!< DCP Work Packet 2 Status Register
    reg32_t _reserved10[3];
    volatile hw_dcp_packet3_t PACKET3; //!< DCP Work Packet 3 Status Register
    reg32_t _reserved11[3];
    volatile hw_dcp_packet4_t PACKET4; //!< DCP Work Packet 4 Status Register
    reg32_t _reserved12[3];
    volatile hw_dcp_packet5_t PACKET5; //!< DCP Work Packet 5 Status Register
    reg32_t _reserved13[3];
    volatile hw_dcp_packet6_t PACKET6; //!< DCP Work Packet 6 Status Register
    reg32_t _reserved14[7];
    volatile hw_dcp_ch0cmdptr_t CH0CMDPTR; //!< DCP Channel 0 Command Pointer Address Register
    reg32_t _reserved15[3];
    volatile hw_dcp_ch0sema_t CH0SEMA; //!< DCP Channel 0 Semaphore Register
    reg32_t _reserved16[3];
    volatile hw_dcp_ch0stat_t CH0STAT; //!< DCP Channel 0 Status Register
    reg32_t _reserved17[3];
    volatile hw_dcp_ch0opts_t CH0OPTS; //!< DCP Channel 0 Options Register
    reg32_t _reserved18[3];
    volatile hw_dcp_ch1cmdptr_t CH1CMDPTR; //!< DCP Channel 1 Command Pointer Address Register
    reg32_t _reserved19[3];
    volatile hw_dcp_ch1sema_t CH1SEMA; //!< DCP Channel 1 Semaphore Register
    reg32_t _reserved20[3];
    volatile hw_dcp_ch1stat_t CH1STAT; //!< DCP Channel 1 Status Register
    reg32_t _reserved21[3];
    volatile hw_dcp_ch1opts_t CH1OPTS; //!< DCP Channel 1 Options Register
    reg32_t _reserved22[3];
    volatile hw_dcp_ch2cmdptr_t CH2CMDPTR; //!< DCP Channel 2 Command Pointer Address Register
    reg32_t _reserved23[3];
    volatile hw_dcp_ch2sema_t CH2SEMA; //!< DCP Channel 2 Semaphore Register
    reg32_t _reserved24[3];
    volatile hw_dcp_ch2stat_t CH2STAT; //!< DCP Channel 2 Status Register
    reg32_t _reserved25[3];
    volatile hw_dcp_ch2opts_t CH2OPTS; //!< DCP Channel 2 Options Register
    reg32_t _reserved26[3];
    volatile hw_dcp_ch3cmdptr_t CH3CMDPTR; //!< DCP Channel 3 Command Pointer Address Register
    reg32_t _reserved27[3];
    volatile hw_dcp_ch3sema_t CH3SEMA; //!< DCP Channel 3 Semaphore Register
    reg32_t _reserved28[3];
    volatile hw_dcp_ch3stat_t CH3STAT; //!< DCP Channel 3 Status Register
    reg32_t _reserved29[3];
    volatile hw_dcp_ch3opts_t CH3OPTS; //!< DCP Channel 3 Options Register
    reg32_t _reserved30[131];
    volatile hw_dcp_dbgselect_t DBGSELECT; //!< DCP Debug Select Register
    reg32_t _reserved31[3];
    volatile hw_dcp_dbgdata_t DBGDATA; //!< DCP Debug Data Register
    reg32_t _reserved32[3];
    volatile hw_dcp_pagetable_t PAGETABLE; //!< DCP Page Table Register
    reg32_t _reserved33[3];
    volatile hw_dcp_version_t VERSION; //!< DCP Version Register
} hw_dcp_t;
#endif

//! @brief Macro to access all DCP registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_DCP(0)</code>.
#define HW_DCP     (*(volatile hw_dcp_t *) REGS_DCP_BASE)


#endif // _DCP_H
