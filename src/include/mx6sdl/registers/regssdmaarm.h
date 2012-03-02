/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SDMAARM_H
#define _SDMAARM_H

#include "regs.h"

/*
 * i.MX6SDL SDMAARM registers defined in this header file.
 *
 * - HW_SDMAARM_MC0PTR - ARM platform Channel 0 Pointer
 * - HW_SDMAARM_INTR - Channel Interrupts
 * - HW_SDMAARM_STOP_STAT - Channel Stop/Channel Status
 * - HW_SDMAARM_HSTART - Channel Start
 * - HW_SDMAARM_EVTOVR - Channel Event Override
 * - HW_SDMAARM_DSPOVR - Channel BP Override
 * - HW_SDMAARM_HOSTOVR - Channel ARM platform Override
 * - HW_SDMAARM_EVTPEND - Channel Event Pending
 * - HW_SDMAARM_RESET - Reset Register
 * - HW_SDMAARM_EVTERR - DMA Request Error Register
 * - HW_SDMAARM_INTRMASK - Channel ARM platform Interrupt Mask
 * - HW_SDMAARM_PSW - Schedule Status
 * - HW_SDMAARM_EVTERRDBG - DMA Request Error Register
 * - HW_SDMAARM_CONFIG - Configuration Register
 * - HW_SDMAARM_SDMA_LOCK - SDMA LOCK
 * - HW_SDMAARM_ONCE_ENB - OnCE Enable
 * - HW_SDMAARM_ONCE_DATA - OnCE Data Register
 * - HW_SDMAARM_ONCE_INSTR - OnCE Instruction Register
 * - HW_SDMAARM_ONCE_STAT - OnCE Status Register
 * - HW_SDMAARM_ONCE_CMD - OnCE Command Register
 * - HW_SDMAARM_ILLINSTADDR - Illegal Instruction Trap Address
 * - HW_SDMAARM_CHN0ADDR - Channel 0 Boot Address
 * - HW_SDMAARM_EVT_MIRROR - DMA Requests
 * - HW_SDMAARM_EVT_MIRROR2 - DMA Requests 2
 * - HW_SDMAARM_XTRIG_CONF1 - Cross-Trigger Events Configuration Register 1
 * - HW_SDMAARM_XTRIG_CONF2 - Cross-Trigger Events Configuration Register 2
 * - HW_SDMAARM_SDMA_CHNPRI0 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI1 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI2 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI3 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI4 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI5 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI6 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI7 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI8 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI9 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI10 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI11 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI12 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI13 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI14 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI15 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI16 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI17 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI18 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI19 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI20 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI21 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI22 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI23 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI24 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI25 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI26 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI27 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI28 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI29 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI30 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNPRI31 - Channel Priority Registers
 * - HW_SDMAARM_SDMA_CHNENBL0 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL1 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL2 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL3 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL4 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL5 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL6 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL7 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL8 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL9 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL10 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL11 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL12 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL13 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL14 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL15 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL16 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL17 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL18 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL19 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL20 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL21 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL22 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL23 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL24 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL25 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL26 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL27 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL28 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL29 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL30 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL31 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL32 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL33 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL34 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL35 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL36 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL37 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL38 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL39 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL40 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL41 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL42 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL43 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL44 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL45 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL46 - Channel Enable RAM
 * - HW_SDMAARM_SDMA_CHNENBL47 - Channel Enable RAM
 *
 * hw_sdmaarm_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_SDMAARM_BASE
#define REGS_SDMAARM_BASE (0x020ec000) //!< Base address for SDMAARM.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_MC0PTR - ARM platform Channel 0 Pointer (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_mc0ptr
{
    reg32_t U;
    struct _hw_sdmaarm_mc0ptr_bitfields
    {
        unsigned MC0PTR : 32; //!< [31:0] Channel 0 Pointer contains the 32-bit address, in ARM platform memory, of channel 0 control block (the boot channel). Appendix A fully describes the SDMA Application Programming Interface (API). The ARM platform has a read/write access and the SDMA has a read-only access.
    } B;
} hw_sdmaarm_mc0ptr_t;
#endif

/*
 * constants & macros for entire SDMAARM_MC0PTR register
 */
#define HW_SDMAARM_MC0PTR_ADDR      (REGS_SDMAARM_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_MC0PTR           (*(volatile hw_sdmaarm_mc0ptr_t *) HW_SDMAARM_MC0PTR_ADDR)
#define HW_SDMAARM_MC0PTR_RD()      (HW_SDMAARM_MC0PTR.U)
#define HW_SDMAARM_MC0PTR_WR(v)     (HW_SDMAARM_MC0PTR.U = (v))
#define HW_SDMAARM_MC0PTR_SET(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() |  (v)))
#define HW_SDMAARM_MC0PTR_CLR(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() & ~(v)))
#define HW_SDMAARM_MC0PTR_TOG(v)    (HW_SDMAARM_MC0PTR_WR(HW_SDMAARM_MC0PTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_MC0PTR bitfields
 */

/* --- Register HW_SDMAARM_MC0PTR, field MC0PTR[31:0] (RW)
 *
 * Channel 0 Pointer contains the 32-bit address, in ARM platform memory, of channel 0 control block
 * (the boot channel). Appendix A fully describes the SDMA Application Programming Interface (API).
 * The ARM platform has a read/write access and the SDMA has a read-only access.
 */

#define BP_SDMAARM_MC0PTR_MC0PTR      (0)      //!< Bit position for SDMAARM_MC0PTR_MC0PTR.
#define BM_SDMAARM_MC0PTR_MC0PTR      (0xffffffff)  //!< Bit mask for SDMAARM_MC0PTR_MC0PTR.

//! @brief Get value of SDMAARM_MC0PTR_MC0PTR from a register value.
#define BG_SDMAARM_MC0PTR_MC0PTR(r)   (((r) & BM_SDMAARM_MC0PTR_MC0PTR) >> BP_SDMAARM_MC0PTR_MC0PTR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_MC0PTR_MC0PTR.
#define BF_SDMAARM_MC0PTR_MC0PTR(v)   ((((reg32_t) v) << BP_SDMAARM_MC0PTR_MC0PTR) & BM_SDMAARM_MC0PTR_MC0PTR)
#else
//! @brief Format value for bitfield SDMAARM_MC0PTR_MC0PTR.
#define BF_SDMAARM_MC0PTR_MC0PTR(v)   (((v) << BP_SDMAARM_MC0PTR_MC0PTR) & BM_SDMAARM_MC0PTR_MC0PTR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MC0PTR field to a new value.
#define BW_SDMAARM_MC0PTR_MC0PTR(v)   (HW_SDMAARM_MC0PTR_WR((HW_SDMAARM_MC0PTR_RD() & ~BM_SDMAARM_MC0PTR_MC0PTR) | BF_SDMAARM_MC0PTR_MC0PTR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_INTR - Channel Interrupts (W1C)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_intr
{
    reg32_t U;
    struct _hw_sdmaarm_intr_bitfields
    {
        unsigned HI : 32; //!< [31:0] The ARM platform Interrupts register contains the 32 HI[i] bits. If any bit is set, it will cause an interrupt to the ARM platform. This register is a "write-ones" register to the ARM platform. When the ARM platform sets a bit in this register the corresponding HI[i] bit is cleared. The interrupt service routine should clear individual channel bits when their interrupts are serviced, failure to do so will cause continuous interrupts. The SDMA is responsible for setting the HI[i] bit corresponding to the current channel when the corresponding done instruction is executed.
    } B;
} hw_sdmaarm_intr_t;
#endif

/*
 * constants & macros for entire SDMAARM_INTR register
 */
#define HW_SDMAARM_INTR_ADDR      (REGS_SDMAARM_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_INTR           (*(volatile hw_sdmaarm_intr_t *) HW_SDMAARM_INTR_ADDR)
#define HW_SDMAARM_INTR_RD()      (HW_SDMAARM_INTR.U)
#define HW_SDMAARM_INTR_WR(v)     (HW_SDMAARM_INTR.U = (v))
#define HW_SDMAARM_INTR_SET(v)    (HW_SDMAARM_INTR_WR(HW_SDMAARM_INTR_RD() |  (v)))
#define HW_SDMAARM_INTR_CLR(v)    (HW_SDMAARM_INTR_WR(HW_SDMAARM_INTR_RD() & ~(v)))
#define HW_SDMAARM_INTR_TOG(v)    (HW_SDMAARM_INTR_WR(HW_SDMAARM_INTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_INTR bitfields
 */

/* --- Register HW_SDMAARM_INTR, field HI[31:0] (W1C)
 *
 * The ARM platform Interrupts register contains the 32 HI[i] bits. If any bit is set, it will cause
 * an interrupt to the ARM platform. This register is a "write-ones" register to the ARM platform.
 * When the ARM platform sets a bit in this register the corresponding HI[i] bit is cleared. The
 * interrupt service routine should clear individual channel bits when their interrupts are
 * serviced, failure to do so will cause continuous interrupts. The SDMA is responsible for setting
 * the HI[i] bit corresponding to the current channel when the corresponding done instruction is
 * executed.
 */

#define BP_SDMAARM_INTR_HI      (0)      //!< Bit position for SDMAARM_INTR_HI.
#define BM_SDMAARM_INTR_HI      (0xffffffff)  //!< Bit mask for SDMAARM_INTR_HI.

//! @brief Get value of SDMAARM_INTR_HI from a register value.
#define BG_SDMAARM_INTR_HI(r)   (((r) & BM_SDMAARM_INTR_HI) >> BP_SDMAARM_INTR_HI)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_INTR_HI.
#define BF_SDMAARM_INTR_HI(v)   ((((reg32_t) v) << BP_SDMAARM_INTR_HI) & BM_SDMAARM_INTR_HI)
#else
//! @brief Format value for bitfield SDMAARM_INTR_HI.
#define BF_SDMAARM_INTR_HI(v)   (((v) << BP_SDMAARM_INTR_HI) & BM_SDMAARM_INTR_HI)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HI field to a new value.
#define BW_SDMAARM_INTR_HI(v)   (HW_SDMAARM_INTR_WR((HW_SDMAARM_INTR_RD() & ~BM_SDMAARM_INTR_HI) | BF_SDMAARM_INTR_HI(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_STOP_STAT - Channel Stop/Channel Status (W1C)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_stop_stat
{
    reg32_t U;
    struct _hw_sdmaarm_stop_stat_bitfields
    {
        unsigned HE : 32; //!< [31:0] This 32-bit register gives access to the ARM platform Enable bits. There is one bit for every channel. This register is a "write-ones" register to the ARM platform. When the ARM platform writes 1 in bit i of this register, it clears the HE[i] and HSTART[i] bits. Reading this register yields the current state of the HE[i] bits.
    } B;
} hw_sdmaarm_stop_stat_t;
#endif

/*
 * constants & macros for entire SDMAARM_STOP_STAT register
 */
#define HW_SDMAARM_STOP_STAT_ADDR      (REGS_SDMAARM_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_STOP_STAT           (*(volatile hw_sdmaarm_stop_stat_t *) HW_SDMAARM_STOP_STAT_ADDR)
#define HW_SDMAARM_STOP_STAT_RD()      (HW_SDMAARM_STOP_STAT.U)
#define HW_SDMAARM_STOP_STAT_WR(v)     (HW_SDMAARM_STOP_STAT.U = (v))
#define HW_SDMAARM_STOP_STAT_SET(v)    (HW_SDMAARM_STOP_STAT_WR(HW_SDMAARM_STOP_STAT_RD() |  (v)))
#define HW_SDMAARM_STOP_STAT_CLR(v)    (HW_SDMAARM_STOP_STAT_WR(HW_SDMAARM_STOP_STAT_RD() & ~(v)))
#define HW_SDMAARM_STOP_STAT_TOG(v)    (HW_SDMAARM_STOP_STAT_WR(HW_SDMAARM_STOP_STAT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_STOP_STAT bitfields
 */

/* --- Register HW_SDMAARM_STOP_STAT, field HE[31:0] (W1C)
 *
 * This 32-bit register gives access to the ARM platform Enable bits. There is one bit for every
 * channel. This register is a "write-ones" register to the ARM platform. When the ARM platform
 * writes 1 in bit i of this register, it clears the HE[i] and HSTART[i] bits. Reading this register
 * yields the current state of the HE[i] bits.
 */

#define BP_SDMAARM_STOP_STAT_HE      (0)      //!< Bit position for SDMAARM_STOP_STAT_HE.
#define BM_SDMAARM_STOP_STAT_HE      (0xffffffff)  //!< Bit mask for SDMAARM_STOP_STAT_HE.

//! @brief Get value of SDMAARM_STOP_STAT_HE from a register value.
#define BG_SDMAARM_STOP_STAT_HE(r)   (((r) & BM_SDMAARM_STOP_STAT_HE) >> BP_SDMAARM_STOP_STAT_HE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_STOP_STAT_HE.
#define BF_SDMAARM_STOP_STAT_HE(v)   ((((reg32_t) v) << BP_SDMAARM_STOP_STAT_HE) & BM_SDMAARM_STOP_STAT_HE)
#else
//! @brief Format value for bitfield SDMAARM_STOP_STAT_HE.
#define BF_SDMAARM_STOP_STAT_HE(v)   (((v) << BP_SDMAARM_STOP_STAT_HE) & BM_SDMAARM_STOP_STAT_HE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HE field to a new value.
#define BW_SDMAARM_STOP_STAT_HE(v)   (HW_SDMAARM_STOP_STAT_WR((HW_SDMAARM_STOP_STAT_RD() & ~BM_SDMAARM_STOP_STAT_HE) | BF_SDMAARM_STOP_STAT_HE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_HSTART - Channel Start (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_hstart
{
    reg32_t U;
    struct _hw_sdmaarm_hstart_bitfields
    {
        unsigned HSTART : 32; //!< [31:0] The HSTART/HE registers are 32 bits wide with one bit for every channel. When a bit is written to 1, it enables the corresponding channel. Two physical registers are accessed with that address (HSTART and HE), which enables the ARM platform to trigger a channel a second time before the first trigger is processed. This register is a "write-ones" register to the ARM platform. Neither HSTART[i] bit can be set while the corresponding HE[i] bit is cleared. When the ARM platform tries to set the HSTART[i] bit by writing a one (if the corresponding HE[i] bit is clear), the bit in the HSTART[i] register will remain cleared and the HE[i] bit will be set. If the corresponding HE[i] bit was already set, the HSTART[i] bit will be set. The next time the SDMA channel i attempts to clear the HE[i] bit by means of a done instruction, the bit in the HSTART[i] register will be cleared and the HE[i] bit will take the old value of the HSTART[i] bit. Reading this register yields the current state of the HSTART[i] bits. This mechanism enables the ARM platform to pipeline two HSTART commands per channel.
    } B;
} hw_sdmaarm_hstart_t;
#endif

/*
 * constants & macros for entire SDMAARM_HSTART register
 */
#define HW_SDMAARM_HSTART_ADDR      (REGS_SDMAARM_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_HSTART           (*(volatile hw_sdmaarm_hstart_t *) HW_SDMAARM_HSTART_ADDR)
#define HW_SDMAARM_HSTART_RD()      (HW_SDMAARM_HSTART.U)
#define HW_SDMAARM_HSTART_WR(v)     (HW_SDMAARM_HSTART.U = (v))
#define HW_SDMAARM_HSTART_SET(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() |  (v)))
#define HW_SDMAARM_HSTART_CLR(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() & ~(v)))
#define HW_SDMAARM_HSTART_TOG(v)    (HW_SDMAARM_HSTART_WR(HW_SDMAARM_HSTART_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_HSTART bitfields
 */

/* --- Register HW_SDMAARM_HSTART, field HSTART[31:0] (W1C)
 *
 * The HSTART/HE registers are 32 bits wide with one bit for every channel. When a bit is written to
 * 1, it enables the corresponding channel. Two physical registers are accessed with that address
 * (HSTART and HE), which enables the ARM platform to trigger a channel a second time before the
 * first trigger is processed. This register is a "write-ones" register to the ARM platform. Neither
 * HSTART[i] bit can be set while the corresponding HE[i] bit is cleared. When the ARM platform
 * tries to set the HSTART[i] bit by writing a one (if the corresponding HE[i] bit is clear), the
 * bit in the HSTART[i] register will remain cleared and the HE[i] bit will be set. If the
 * corresponding HE[i] bit was already set, the HSTART[i] bit will be set. The next time the SDMA
 * channel i attempts to clear the HE[i] bit by means of a done instruction, the bit in the
 * HSTART[i] register will be cleared and the HE[i] bit will take the old value of the HSTART[i]
 * bit. Reading this register yields the current state of the HSTART[i] bits. This mechanism enables
 * the ARM platform to pipeline two HSTART commands per channel.
 */

#define BP_SDMAARM_HSTART_HSTART      (0)      //!< Bit position for SDMAARM_HSTART_HSTART.
#define BM_SDMAARM_HSTART_HSTART      (0xffffffff)  //!< Bit mask for SDMAARM_HSTART_HSTART.

//! @brief Get value of SDMAARM_HSTART_HSTART from a register value.
#define BG_SDMAARM_HSTART_HSTART(r)   (((r) & BM_SDMAARM_HSTART_HSTART) >> BP_SDMAARM_HSTART_HSTART)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_HSTART_HSTART.
#define BF_SDMAARM_HSTART_HSTART(v)   ((((reg32_t) v) << BP_SDMAARM_HSTART_HSTART) & BM_SDMAARM_HSTART_HSTART)
#else
//! @brief Format value for bitfield SDMAARM_HSTART_HSTART.
#define BF_SDMAARM_HSTART_HSTART(v)   (((v) << BP_SDMAARM_HSTART_HSTART) & BM_SDMAARM_HSTART_HSTART)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSTART field to a new value.
#define BW_SDMAARM_HSTART_HSTART(v)   (HW_SDMAARM_HSTART_WR((HW_SDMAARM_HSTART_RD() & ~BM_SDMAARM_HSTART_HSTART) | BF_SDMAARM_HSTART_HSTART(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTOVR - Channel Event Override (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_evtovr
{
    reg32_t U;
    struct _hw_sdmaarm_evtovr_bitfields
    {
        unsigned EO : 32; //!< [31:0] The Channel Event Override register contains the 32 EO[i] bits. A bit set in this register causes the SDMA to ignore DMA requests when scheduling the corresponding channel.
    } B;
} hw_sdmaarm_evtovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTOVR register
 */
#define HW_SDMAARM_EVTOVR_ADDR      (REGS_SDMAARM_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTOVR           (*(volatile hw_sdmaarm_evtovr_t *) HW_SDMAARM_EVTOVR_ADDR)
#define HW_SDMAARM_EVTOVR_RD()      (HW_SDMAARM_EVTOVR.U)
#define HW_SDMAARM_EVTOVR_WR(v)     (HW_SDMAARM_EVTOVR.U = (v))
#define HW_SDMAARM_EVTOVR_SET(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() |  (v)))
#define HW_SDMAARM_EVTOVR_CLR(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() & ~(v)))
#define HW_SDMAARM_EVTOVR_TOG(v)    (HW_SDMAARM_EVTOVR_WR(HW_SDMAARM_EVTOVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_EVTOVR bitfields
 */

/* --- Register HW_SDMAARM_EVTOVR, field EO[31:0] (RW)
 *
 * The Channel Event Override register contains the 32 EO[i] bits. A bit set in this register causes
 * the SDMA to ignore DMA requests when scheduling the corresponding channel.
 */

#define BP_SDMAARM_EVTOVR_EO      (0)      //!< Bit position for SDMAARM_EVTOVR_EO.
#define BM_SDMAARM_EVTOVR_EO      (0xffffffff)  //!< Bit mask for SDMAARM_EVTOVR_EO.

//! @brief Get value of SDMAARM_EVTOVR_EO from a register value.
#define BG_SDMAARM_EVTOVR_EO(r)   (((r) & BM_SDMAARM_EVTOVR_EO) >> BP_SDMAARM_EVTOVR_EO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_EVTOVR_EO.
#define BF_SDMAARM_EVTOVR_EO(v)   ((((reg32_t) v) << BP_SDMAARM_EVTOVR_EO) & BM_SDMAARM_EVTOVR_EO)
#else
//! @brief Format value for bitfield SDMAARM_EVTOVR_EO.
#define BF_SDMAARM_EVTOVR_EO(v)   (((v) << BP_SDMAARM_EVTOVR_EO) & BM_SDMAARM_EVTOVR_EO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EO field to a new value.
#define BW_SDMAARM_EVTOVR_EO(v)   (HW_SDMAARM_EVTOVR_WR((HW_SDMAARM_EVTOVR_RD() & ~BM_SDMAARM_EVTOVR_EO) | BF_SDMAARM_EVTOVR_EO(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_DSPOVR - Channel BP Override (RW)
 *
 * Reset value: 0xffffffff
 *

 */
typedef union _hw_sdmaarm_dspovr
{
    reg32_t U;
    struct _hw_sdmaarm_dspovr_bitfields
    {
        unsigned DO : 32; //!< [31:0] The Channel BP Override register contains the 32 DO[i] bits. A bit set in this register causes the SDMA to ignore a BP enable condition when scheduling the corresponding channel. By default, all DO[i] bits are set to 1, which means that register can be ignored when the BP connections are not used. This register is reserved. All DO bits should be set to the reset value of 1. A setting of 0 will prevent SDMA channels from starting according to the condition described in .
    } B;
} hw_sdmaarm_dspovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_DSPOVR register
 */
#define HW_SDMAARM_DSPOVR_ADDR      (REGS_SDMAARM_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_DSPOVR           (*(volatile hw_sdmaarm_dspovr_t *) HW_SDMAARM_DSPOVR_ADDR)
#define HW_SDMAARM_DSPOVR_RD()      (HW_SDMAARM_DSPOVR.U)
#define HW_SDMAARM_DSPOVR_WR(v)     (HW_SDMAARM_DSPOVR.U = (v))
#define HW_SDMAARM_DSPOVR_SET(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() |  (v)))
#define HW_SDMAARM_DSPOVR_CLR(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() & ~(v)))
#define HW_SDMAARM_DSPOVR_TOG(v)    (HW_SDMAARM_DSPOVR_WR(HW_SDMAARM_DSPOVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_DSPOVR bitfields
 */

/* --- Register HW_SDMAARM_DSPOVR, field DO[31:0] (RW)
 *
 * The Channel BP Override register contains the 32 DO[i] bits. A bit set in this register causes
 * the SDMA to ignore a BP enable condition when scheduling the corresponding channel. By default,
 * all DO[i] bits are set to 1, which means that register can be ignored when the BP connections are
 * not used. This register is reserved. All DO bits should be set to the reset value of 1. A setting
 * of 0 will prevent SDMA channels from starting according to the condition described in .
 *
 * Values:
 * 0 - - Reserved
 * 1 - - Reset value.
 */

#define BP_SDMAARM_DSPOVR_DO      (0)      //!< Bit position for SDMAARM_DSPOVR_DO.
#define BM_SDMAARM_DSPOVR_DO      (0xffffffff)  //!< Bit mask for SDMAARM_DSPOVR_DO.

//! @brief Get value of SDMAARM_DSPOVR_DO from a register value.
#define BG_SDMAARM_DSPOVR_DO(r)   (((r) & BM_SDMAARM_DSPOVR_DO) >> BP_SDMAARM_DSPOVR_DO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_DSPOVR_DO.
#define BF_SDMAARM_DSPOVR_DO(v)   ((((reg32_t) v) << BP_SDMAARM_DSPOVR_DO) & BM_SDMAARM_DSPOVR_DO)
#else
//! @brief Format value for bitfield SDMAARM_DSPOVR_DO.
#define BF_SDMAARM_DSPOVR_DO(v)   (((v) << BP_SDMAARM_DSPOVR_DO) & BM_SDMAARM_DSPOVR_DO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DO field to a new value.
#define BW_SDMAARM_DSPOVR_DO(v)   (HW_SDMAARM_DSPOVR_WR((HW_SDMAARM_DSPOVR_RD() & ~BM_SDMAARM_DSPOVR_DO) | BF_SDMAARM_DSPOVR_DO(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_HOSTOVR - Channel ARM platform Override (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_hostovr
{
    reg32_t U;
    struct _hw_sdmaarm_hostovr_bitfields
    {
        unsigned HO : 32; //!< [31:0] The Channel ARM platform Override register contains the 32 HO[i] bits. A bit set in this register causes the SDMA to ignore the ARM platform enable bit (HE) when scheduling the corresponding channel.
    } B;
} hw_sdmaarm_hostovr_t;
#endif

/*
 * constants & macros for entire SDMAARM_HOSTOVR register
 */
#define HW_SDMAARM_HOSTOVR_ADDR      (REGS_SDMAARM_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_HOSTOVR           (*(volatile hw_sdmaarm_hostovr_t *) HW_SDMAARM_HOSTOVR_ADDR)
#define HW_SDMAARM_HOSTOVR_RD()      (HW_SDMAARM_HOSTOVR.U)
#define HW_SDMAARM_HOSTOVR_WR(v)     (HW_SDMAARM_HOSTOVR.U = (v))
#define HW_SDMAARM_HOSTOVR_SET(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() |  (v)))
#define HW_SDMAARM_HOSTOVR_CLR(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() & ~(v)))
#define HW_SDMAARM_HOSTOVR_TOG(v)    (HW_SDMAARM_HOSTOVR_WR(HW_SDMAARM_HOSTOVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_HOSTOVR bitfields
 */

/* --- Register HW_SDMAARM_HOSTOVR, field HO[31:0] (RW)
 *
 * The Channel ARM platform Override register contains the 32 HO[i] bits. A bit set in this register
 * causes the SDMA to ignore the ARM platform enable bit (HE) when scheduling the corresponding
 * channel.
 */

#define BP_SDMAARM_HOSTOVR_HO      (0)      //!< Bit position for SDMAARM_HOSTOVR_HO.
#define BM_SDMAARM_HOSTOVR_HO      (0xffffffff)  //!< Bit mask for SDMAARM_HOSTOVR_HO.

//! @brief Get value of SDMAARM_HOSTOVR_HO from a register value.
#define BG_SDMAARM_HOSTOVR_HO(r)   (((r) & BM_SDMAARM_HOSTOVR_HO) >> BP_SDMAARM_HOSTOVR_HO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_HOSTOVR_HO.
#define BF_SDMAARM_HOSTOVR_HO(v)   ((((reg32_t) v) << BP_SDMAARM_HOSTOVR_HO) & BM_SDMAARM_HOSTOVR_HO)
#else
//! @brief Format value for bitfield SDMAARM_HOSTOVR_HO.
#define BF_SDMAARM_HOSTOVR_HO(v)   (((v) << BP_SDMAARM_HOSTOVR_HO) & BM_SDMAARM_HOSTOVR_HO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HO field to a new value.
#define BW_SDMAARM_HOSTOVR_HO(v)   (HW_SDMAARM_HOSTOVR_WR((HW_SDMAARM_HOSTOVR_RD() & ~BM_SDMAARM_HOSTOVR_HO) | BF_SDMAARM_HOSTOVR_HO(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTPEND - Channel Event Pending (W1C)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_evtpend
{
    reg32_t U;
    struct _hw_sdmaarm_evtpend_bitfields
    {
        unsigned EP : 32; //!< [31:0] The Channel Event Pending register contains the 32 EP[i] bits. Reading this register enables the ARM platform to determine what channels are pending after the reception of a DMA request. Setting a bit in this register causes the SDMA to reevaluate scheduling as if a DMA request mapped on this channel had occurred. This is useful for starting up channels, so that initialization is done before awaiting the first request. The scheduler can also set bits in the EVTPEND register according to the received DMA requests. The EP[i] bit may be cleared by the done instruction when running the channel i script. This a "write-ones" mechanism: Writing a '0' does not clear the corresponding bit.
    } B;
} hw_sdmaarm_evtpend_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTPEND register
 */
#define HW_SDMAARM_EVTPEND_ADDR      (REGS_SDMAARM_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTPEND           (*(volatile hw_sdmaarm_evtpend_t *) HW_SDMAARM_EVTPEND_ADDR)
#define HW_SDMAARM_EVTPEND_RD()      (HW_SDMAARM_EVTPEND.U)
#define HW_SDMAARM_EVTPEND_WR(v)     (HW_SDMAARM_EVTPEND.U = (v))
#define HW_SDMAARM_EVTPEND_SET(v)    (HW_SDMAARM_EVTPEND_WR(HW_SDMAARM_EVTPEND_RD() |  (v)))
#define HW_SDMAARM_EVTPEND_CLR(v)    (HW_SDMAARM_EVTPEND_WR(HW_SDMAARM_EVTPEND_RD() & ~(v)))
#define HW_SDMAARM_EVTPEND_TOG(v)    (HW_SDMAARM_EVTPEND_WR(HW_SDMAARM_EVTPEND_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_EVTPEND bitfields
 */

/* --- Register HW_SDMAARM_EVTPEND, field EP[31:0] (W1C)
 *
 * The Channel Event Pending register contains the 32 EP[i] bits. Reading this register enables the
 * ARM platform to determine what channels are pending after the reception of a DMA request. Setting
 * a bit in this register causes the SDMA to reevaluate scheduling as if a DMA request mapped on
 * this channel had occurred. This is useful for starting up channels, so that initialization is
 * done before awaiting the first request. The scheduler can also set bits in the EVTPEND register
 * according to the received DMA requests. The EP[i] bit may be cleared by the done instruction when
 * running the channel i script. This a "write-ones" mechanism: Writing a '0' does not clear the
 * corresponding bit.
 */

#define BP_SDMAARM_EVTPEND_EP      (0)      //!< Bit position for SDMAARM_EVTPEND_EP.
#define BM_SDMAARM_EVTPEND_EP      (0xffffffff)  //!< Bit mask for SDMAARM_EVTPEND_EP.

//! @brief Get value of SDMAARM_EVTPEND_EP from a register value.
#define BG_SDMAARM_EVTPEND_EP(r)   (((r) & BM_SDMAARM_EVTPEND_EP) >> BP_SDMAARM_EVTPEND_EP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_EVTPEND_EP.
#define BF_SDMAARM_EVTPEND_EP(v)   ((((reg32_t) v) << BP_SDMAARM_EVTPEND_EP) & BM_SDMAARM_EVTPEND_EP)
#else
//! @brief Format value for bitfield SDMAARM_EVTPEND_EP.
#define BF_SDMAARM_EVTPEND_EP(v)   (((v) << BP_SDMAARM_EVTPEND_EP) & BM_SDMAARM_EVTPEND_EP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EP field to a new value.
#define BW_SDMAARM_EVTPEND_EP(v)   (HW_SDMAARM_EVTPEND_WR((HW_SDMAARM_EVTPEND_RD() & ~BM_SDMAARM_EVTPEND_EP) | BF_SDMAARM_EVTPEND_EP(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_RESET - Reset Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_reset
{
    reg32_t U;
    struct _hw_sdmaarm_reset_bitfields
    {
        unsigned RESET : 1; //!< [0] When set, this bit causes the SDMA to be held in a software reset. The internal reset signal is held low 16 cycles; the RESET bit is automatically cleared when the internal reset signal rises.
        unsigned RESCHED : 1; //!< [1] When set, this bit forces the SDMA to reschedule as if a script had executed a done instruction. This enables the ARM platform to recover from a runaway script on a channel by clearing its HE[i] bit via the STOP register, and then forcing a reschedule via the RESCHED bit. The RESCHED bit is cleared when the context switch starts.
        unsigned RESERVED0 : 30; //!< [31:2] Reserved
    } B;
} hw_sdmaarm_reset_t;
#endif

/*
 * constants & macros for entire SDMAARM_RESET register
 */
#define HW_SDMAARM_RESET_ADDR      (REGS_SDMAARM_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_RESET           (*(volatile hw_sdmaarm_reset_t *) HW_SDMAARM_RESET_ADDR)
#define HW_SDMAARM_RESET_RD()      (HW_SDMAARM_RESET.U)
#endif

/*
 * constants & macros for individual SDMAARM_RESET bitfields
 */

/* --- Register HW_SDMAARM_RESET, field RESET[0] (RO)
 *
 * When set, this bit causes the SDMA to be held in a software reset. The internal reset signal is
 * held low 16 cycles; the RESET bit is automatically cleared when the internal reset signal rises.
 */

#define BP_SDMAARM_RESET_RESET      (0)      //!< Bit position for SDMAARM_RESET_RESET.
#define BM_SDMAARM_RESET_RESET      (0x00000001)  //!< Bit mask for SDMAARM_RESET_RESET.

//! @brief Get value of SDMAARM_RESET_RESET from a register value.
#define BG_SDMAARM_RESET_RESET(r)   (((r) & BM_SDMAARM_RESET_RESET) >> BP_SDMAARM_RESET_RESET)

/* --- Register HW_SDMAARM_RESET, field RESCHED[1] (RO)
 *
 * When set, this bit forces the SDMA to reschedule as if a script had executed a done instruction.
 * This enables the ARM platform to recover from a runaway script on a channel by clearing its HE[i]
 * bit via the STOP register, and then forcing a reschedule via the RESCHED bit. The RESCHED bit is
 * cleared when the context switch starts.
 */

#define BP_SDMAARM_RESET_RESCHED      (1)      //!< Bit position for SDMAARM_RESET_RESCHED.
#define BM_SDMAARM_RESET_RESCHED      (0x00000002)  //!< Bit mask for SDMAARM_RESET_RESCHED.

//! @brief Get value of SDMAARM_RESET_RESCHED from a register value.
#define BG_SDMAARM_RESET_RESCHED(r)   (((r) & BM_SDMAARM_RESET_RESCHED) >> BP_SDMAARM_RESET_RESCHED)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTERR - DMA Request Error Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_evterr
{
    reg32_t U;
    struct _hw_sdmaarm_evterr_bitfields
    {
        unsigned CHNERR : 32; //!< [31:0] This register is used by the SDMA to warn the ARM platform when an incoming DMA request was detected and it triggers a channel that is already pending or being serviced. This probably means there is an overflow of data for that channel. An interrupt is sent to the ARM platform if the corresponding channel bit is set in the INTRMASK register. This is a "write-ones" register for the scheduler. It is only able to set the flags. The flags are cleared when the register is read by the ARM platform or during SDMA reset. The CHNERR[i] bit is set when a DMA request that triggers channel i is received through the corresponding input pins and the EP[i] bit is already set; the EVTERR[i] bit is unaffected if the ARM platform tries to set the EP[i] bit, whereas, that EP[i] bit is already set.
    } B;
} hw_sdmaarm_evterr_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTERR register
 */
#define HW_SDMAARM_EVTERR_ADDR      (REGS_SDMAARM_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTERR           (*(volatile hw_sdmaarm_evterr_t *) HW_SDMAARM_EVTERR_ADDR)
#define HW_SDMAARM_EVTERR_RD()      (HW_SDMAARM_EVTERR.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVTERR bitfields
 */

/* --- Register HW_SDMAARM_EVTERR, field CHNERR[31:0] (RO)
 *
 * This register is used by the SDMA to warn the ARM platform when an incoming DMA request was
 * detected and it triggers a channel that is already pending or being serviced. This probably means
 * there is an overflow of data for that channel. An interrupt is sent to the ARM platform if the
 * corresponding channel bit is set in the INTRMASK register. This is a "write-ones" register for
 * the scheduler. It is only able to set the flags. The flags are cleared when the register is read
 * by the ARM platform or during SDMA reset. The CHNERR[i] bit is set when a DMA request that
 * triggers channel i is received through the corresponding input pins and the EP[i] bit is already
 * set; the EVTERR[i] bit is unaffected if the ARM platform tries to set the EP[i] bit, whereas,
 * that EP[i] bit is already set.
 */

#define BP_SDMAARM_EVTERR_CHNERR      (0)      //!< Bit position for SDMAARM_EVTERR_CHNERR.
#define BM_SDMAARM_EVTERR_CHNERR      (0xffffffff)  //!< Bit mask for SDMAARM_EVTERR_CHNERR.

//! @brief Get value of SDMAARM_EVTERR_CHNERR from a register value.
#define BG_SDMAARM_EVTERR_CHNERR(r)   (((r) & BM_SDMAARM_EVTERR_CHNERR) >> BP_SDMAARM_EVTERR_CHNERR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_INTRMASK - Channel ARM platform Interrupt Mask (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_intrmask
{
    reg32_t U;
    struct _hw_sdmaarm_intrmask_bitfields
    {
        unsigned HIMASK : 32; //!< [31:0] The Interrupt Mask Register contains 32 interrupt generation mask bits. If bit HIMASK[i] is set, the HI[i] bit is set and an interrupt is sent to the ARM platform when a DMA request error is detected on channel i (for example, EVTERR[i] is set).
    } B;
} hw_sdmaarm_intrmask_t;
#endif

/*
 * constants & macros for entire SDMAARM_INTRMASK register
 */
#define HW_SDMAARM_INTRMASK_ADDR      (REGS_SDMAARM_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_INTRMASK           (*(volatile hw_sdmaarm_intrmask_t *) HW_SDMAARM_INTRMASK_ADDR)
#define HW_SDMAARM_INTRMASK_RD()      (HW_SDMAARM_INTRMASK.U)
#define HW_SDMAARM_INTRMASK_WR(v)     (HW_SDMAARM_INTRMASK.U = (v))
#define HW_SDMAARM_INTRMASK_SET(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() |  (v)))
#define HW_SDMAARM_INTRMASK_CLR(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() & ~(v)))
#define HW_SDMAARM_INTRMASK_TOG(v)    (HW_SDMAARM_INTRMASK_WR(HW_SDMAARM_INTRMASK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_INTRMASK bitfields
 */

/* --- Register HW_SDMAARM_INTRMASK, field HIMASK[31:0] (RW)
 *
 * The Interrupt Mask Register contains 32 interrupt generation mask bits. If bit HIMASK[i] is set,
 * the HI[i] bit is set and an interrupt is sent to the ARM platform when a DMA request error is
 * detected on channel i (for example, EVTERR[i] is set).
 */

#define BP_SDMAARM_INTRMASK_HIMASK      (0)      //!< Bit position for SDMAARM_INTRMASK_HIMASK.
#define BM_SDMAARM_INTRMASK_HIMASK      (0xffffffff)  //!< Bit mask for SDMAARM_INTRMASK_HIMASK.

//! @brief Get value of SDMAARM_INTRMASK_HIMASK from a register value.
#define BG_SDMAARM_INTRMASK_HIMASK(r)   (((r) & BM_SDMAARM_INTRMASK_HIMASK) >> BP_SDMAARM_INTRMASK_HIMASK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_INTRMASK_HIMASK.
#define BF_SDMAARM_INTRMASK_HIMASK(v)   ((((reg32_t) v) << BP_SDMAARM_INTRMASK_HIMASK) & BM_SDMAARM_INTRMASK_HIMASK)
#else
//! @brief Format value for bitfield SDMAARM_INTRMASK_HIMASK.
#define BF_SDMAARM_INTRMASK_HIMASK(v)   (((v) << BP_SDMAARM_INTRMASK_HIMASK) & BM_SDMAARM_INTRMASK_HIMASK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HIMASK field to a new value.
#define BW_SDMAARM_INTRMASK_HIMASK(v)   (HW_SDMAARM_INTRMASK_WR((HW_SDMAARM_INTRMASK_RD() & ~BM_SDMAARM_INTRMASK_HIMASK) | BF_SDMAARM_INTRMASK_HIMASK(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_PSW - Schedule Status (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_psw
{
    reg32_t U;
    struct _hw_sdmaarm_psw_bitfields
    {
        unsigned CCR : 4; //!< [3:0] The Current Channel Register indicates the number of the channel that is being executed by the SDMA. SDMA. In the case that the SDMA has finished running the channel and has entered sleep state, CCR will indicate the previous running channel.
        unsigned CCP : 4; //!< [7:4] The Current Channel Priority indicates the priority of the current active channel. When the priority is 0, no channel is running: The SDMA is idle and the CCR value has no meaning. In the case that the SDMA has finished running the channel and has entered sleep state, CCP will indicate the priority of previous running channel.
        unsigned NCR : 5; //!< [12:8] The Next Channel Register indicates the number of the next scheduled pending channel with the highest priority.
        unsigned NCP : 3; //!< [15:13] The Next Channel Priority gives the next pending channel priority. When the priority is 0, it means there is no pending channel and the NCR value has no meaning.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_sdmaarm_psw_t;
#endif

/*
 * constants & macros for entire SDMAARM_PSW register
 */
#define HW_SDMAARM_PSW_ADDR      (REGS_SDMAARM_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_PSW           (*(volatile hw_sdmaarm_psw_t *) HW_SDMAARM_PSW_ADDR)
#define HW_SDMAARM_PSW_RD()      (HW_SDMAARM_PSW.U)
#endif

/*
 * constants & macros for individual SDMAARM_PSW bitfields
 */

/* --- Register HW_SDMAARM_PSW, field CCR[3:0] (RO)
 *
 * The Current Channel Register indicates the number of the channel that is being executed by the
 * SDMA. SDMA. In the case that the SDMA has finished running the channel and has entered sleep
 * state, CCR will indicate the previous running channel.
 */

#define BP_SDMAARM_PSW_CCR      (0)      //!< Bit position for SDMAARM_PSW_CCR.
#define BM_SDMAARM_PSW_CCR      (0x0000000f)  //!< Bit mask for SDMAARM_PSW_CCR.

//! @brief Get value of SDMAARM_PSW_CCR from a register value.
#define BG_SDMAARM_PSW_CCR(r)   (((r) & BM_SDMAARM_PSW_CCR) >> BP_SDMAARM_PSW_CCR)

/* --- Register HW_SDMAARM_PSW, field CCP[7:4] (RO)
 *
 * The Current Channel Priority indicates the priority of the current active channel. When the
 * priority is 0, no channel is running: The SDMA is idle and the CCR value has no meaning. In the
 * case that the SDMA has finished running the channel and has entered sleep state, CCP will
 * indicate the priority of previous running channel.
 *
 * Values:
 * 0 - No running channel
 * 1 - Active channel priority
 */

#define BP_SDMAARM_PSW_CCP      (4)      //!< Bit position for SDMAARM_PSW_CCP.
#define BM_SDMAARM_PSW_CCP      (0x000000f0)  //!< Bit mask for SDMAARM_PSW_CCP.

//! @brief Get value of SDMAARM_PSW_CCP from a register value.
#define BG_SDMAARM_PSW_CCP(r)   (((r) & BM_SDMAARM_PSW_CCP) >> BP_SDMAARM_PSW_CCP)


/* --- Register HW_SDMAARM_PSW, field NCR[12:8] (RO)
 *
 * The Next Channel Register indicates the number of the next scheduled pending channel with the
 * highest priority.
 */

#define BP_SDMAARM_PSW_NCR      (8)      //!< Bit position for SDMAARM_PSW_NCR.
#define BM_SDMAARM_PSW_NCR      (0x00001f00)  //!< Bit mask for SDMAARM_PSW_NCR.

//! @brief Get value of SDMAARM_PSW_NCR from a register value.
#define BG_SDMAARM_PSW_NCR(r)   (((r) & BM_SDMAARM_PSW_NCR) >> BP_SDMAARM_PSW_NCR)

/* --- Register HW_SDMAARM_PSW, field NCP[15:13] (RO)
 *
 * The Next Channel Priority gives the next pending channel priority. When the priority is 0, it
 * means there is no pending channel and the NCR value has no meaning.
 *
 * Values:
 * 0 - No running channel
 * 1 - Active channel priority
 */

#define BP_SDMAARM_PSW_NCP      (13)      //!< Bit position for SDMAARM_PSW_NCP.
#define BM_SDMAARM_PSW_NCP      (0x0000e000)  //!< Bit mask for SDMAARM_PSW_NCP.

//! @brief Get value of SDMAARM_PSW_NCP from a register value.
#define BG_SDMAARM_PSW_NCP(r)   (((r) & BM_SDMAARM_PSW_NCP) >> BP_SDMAARM_PSW_NCP)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVTERRDBG - DMA Request Error Register (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_evterrdbg
{
    reg32_t U;
    struct _hw_sdmaarm_evterrdbg_bitfields
    {
        unsigned CHNERR : 32; //!< [31:0] This register is the same as EVTERR, except reading it does not clear its contents. This address is meant to be used in debug mode. The ARM platform OnCE may check this register value without modifying it.
    } B;
} hw_sdmaarm_evterrdbg_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVTERRDBG register
 */
#define HW_SDMAARM_EVTERRDBG_ADDR      (REGS_SDMAARM_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVTERRDBG           (*(volatile hw_sdmaarm_evterrdbg_t *) HW_SDMAARM_EVTERRDBG_ADDR)
#define HW_SDMAARM_EVTERRDBG_RD()      (HW_SDMAARM_EVTERRDBG.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVTERRDBG bitfields
 */

/* --- Register HW_SDMAARM_EVTERRDBG, field CHNERR[31:0] (RO)
 *
 * This register is the same as EVTERR, except reading it does not clear its contents. This address
 * is meant to be used in debug mode. The ARM platform OnCE may check this register value without
 * modifying it.
 */

#define BP_SDMAARM_EVTERRDBG_CHNERR      (0)      //!< Bit position for SDMAARM_EVTERRDBG_CHNERR.
#define BM_SDMAARM_EVTERRDBG_CHNERR      (0xffffffff)  //!< Bit mask for SDMAARM_EVTERRDBG_CHNERR.

//! @brief Get value of SDMAARM_EVTERRDBG_CHNERR from a register value.
#define BG_SDMAARM_EVTERRDBG_CHNERR(r)   (((r) & BM_SDMAARM_EVTERRDBG_CHNERR) >> BP_SDMAARM_EVTERRDBG_CHNERR)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_CONFIG - Configuration Register (RW)
 *
 * Reset value: 0x00000003
 *

 */
typedef union _hw_sdmaarm_config
{
    reg32_t U;
    struct _hw_sdmaarm_config_bitfields
    {
        unsigned CSM : 2; //!< [1:0] Selects the Context Switch Mode. The ARM platform has a read/write access. The SDMA cannot modify that register. The value at reset is 3, which selects the dynamic context switch by default. That register can be modified at anytime but the new context switch configuration will only be taken into account at the start of the next restore phase. NOTE: The first call to SDMA's channel 0 Bootload script after reset should use static context switch mode to ensure the context RAM for channel 0 is initialized in the channel SAVE Phase. After Channel 0 is run once, then any of the dynamic context modes can be used.
        unsigned RESERVED0 : 2; //!< [3:2] Reserved
        unsigned ACR : 1; //!< [4] ARM platform DMA / SDMA Core Clock Ratio. Selects the clock ratio between ARM platform DMA interfaces (burst DMA and burst DMA2 and peripheral DMA ) and the internal SDMA core clock. The frequency selection is determined separately by the chip clock controller. This bit has to match the configuration of the chip clock controller that generates the clocks used in the SDMA.
        unsigned RESERVED1 : 6; //!< [10:5] Reserved
        unsigned RTDOBS : 1; //!< [11] Indicates if Real-Time Debug pins are used: They do not toggle by default in order to reduce power consumption.
        unsigned DSPDMA : 1; //!< [12] This bit's function is reserved and should be configured as zero.
        unsigned RESERVED2 : 19; //!< [31:13] Reserved
    } B;
} hw_sdmaarm_config_t;
#endif

/*
 * constants & macros for entire SDMAARM_CONFIG register
 */
#define HW_SDMAARM_CONFIG_ADDR      (REGS_SDMAARM_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_CONFIG           (*(volatile hw_sdmaarm_config_t *) HW_SDMAARM_CONFIG_ADDR)
#define HW_SDMAARM_CONFIG_RD()      (HW_SDMAARM_CONFIG.U)
#define HW_SDMAARM_CONFIG_WR(v)     (HW_SDMAARM_CONFIG.U = (v))
#define HW_SDMAARM_CONFIG_SET(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() |  (v)))
#define HW_SDMAARM_CONFIG_CLR(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() & ~(v)))
#define HW_SDMAARM_CONFIG_TOG(v)    (HW_SDMAARM_CONFIG_WR(HW_SDMAARM_CONFIG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_CONFIG bitfields
 */

/* --- Register HW_SDMAARM_CONFIG, field CSM[1:0] (RW)
 *
 * Selects the Context Switch Mode. The ARM platform has a read/write access. The SDMA cannot modify
 * that register. The value at reset is 3, which selects the dynamic context switch by default. That
 * register can be modified at anytime but the new context switch configuration will only be taken
 * into account at the start of the next restore phase. NOTE: The first call to SDMA's channel 0
 * Bootload script after reset should use static context switch mode to ensure the context RAM for
 * channel 0 is initialized in the channel SAVE Phase. After Channel 0 is run once, then any of the
 * dynamic context modes can be used.
 *
 * Values:
 * 0 - static
 * 1 - dynamic low power
 * 2 - dynamic with no loop
 * 3 - dynamic
 */

#define BP_SDMAARM_CONFIG_CSM      (0)      //!< Bit position for SDMAARM_CONFIG_CSM.
#define BM_SDMAARM_CONFIG_CSM      (0x00000003)  //!< Bit mask for SDMAARM_CONFIG_CSM.

//! @brief Get value of SDMAARM_CONFIG_CSM from a register value.
#define BG_SDMAARM_CONFIG_CSM(r)   (((r) & BM_SDMAARM_CONFIG_CSM) >> BP_SDMAARM_CONFIG_CSM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_CONFIG_CSM.
#define BF_SDMAARM_CONFIG_CSM(v)   ((((reg32_t) v) << BP_SDMAARM_CONFIG_CSM) & BM_SDMAARM_CONFIG_CSM)
#else
//! @brief Format value for bitfield SDMAARM_CONFIG_CSM.
#define BF_SDMAARM_CONFIG_CSM(v)   (((v) << BP_SDMAARM_CONFIG_CSM) & BM_SDMAARM_CONFIG_CSM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CSM field to a new value.
#define BW_SDMAARM_CONFIG_CSM(v)   (HW_SDMAARM_CONFIG_WR((HW_SDMAARM_CONFIG_RD() & ~BM_SDMAARM_CONFIG_CSM) | BF_SDMAARM_CONFIG_CSM(v)))
#endif


/* --- Register HW_SDMAARM_CONFIG, field ACR[4] (RW)
 *
 * ARM platform DMA / SDMA Core Clock Ratio. Selects the clock ratio between ARM platform DMA
 * interfaces (burst DMA and burst DMA2 and peripheral DMA ) and the internal SDMA core clock. The
 * frequency selection is determined separately by the chip clock controller. This bit has to match
 * the configuration of the chip clock controller that generates the clocks used in the SDMA.
 *
 * Values:
 * 0 - ARM platform DMA interface frequency equals twice core frequency
 * 1 - ARM platform DMA interface frequency equals core frequency
 */

#define BP_SDMAARM_CONFIG_ACR      (4)      //!< Bit position for SDMAARM_CONFIG_ACR.
#define BM_SDMAARM_CONFIG_ACR      (0x00000010)  //!< Bit mask for SDMAARM_CONFIG_ACR.

//! @brief Get value of SDMAARM_CONFIG_ACR from a register value.
#define BG_SDMAARM_CONFIG_ACR(r)   (((r) & BM_SDMAARM_CONFIG_ACR) >> BP_SDMAARM_CONFIG_ACR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_CONFIG_ACR.
#define BF_SDMAARM_CONFIG_ACR(v)   ((((reg32_t) v) << BP_SDMAARM_CONFIG_ACR) & BM_SDMAARM_CONFIG_ACR)
#else
//! @brief Format value for bitfield SDMAARM_CONFIG_ACR.
#define BF_SDMAARM_CONFIG_ACR(v)   (((v) << BP_SDMAARM_CONFIG_ACR) & BM_SDMAARM_CONFIG_ACR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ACR field to a new value.
#define BW_SDMAARM_CONFIG_ACR(v)   (HW_SDMAARM_CONFIG_WR((HW_SDMAARM_CONFIG_RD() & ~BM_SDMAARM_CONFIG_ACR) | BF_SDMAARM_CONFIG_ACR(v)))
#endif


/* --- Register HW_SDMAARM_CONFIG, field RTDOBS[11] (RW)
 *
 * Indicates if Real-Time Debug pins are used: They do not toggle by default in order to reduce
 * power consumption.
 *
 * Values:
 * 0 - RTD pins disabled
 * 1 - RTD pins enabled
 */

#define BP_SDMAARM_CONFIG_RTDOBS      (11)      //!< Bit position for SDMAARM_CONFIG_RTDOBS.
#define BM_SDMAARM_CONFIG_RTDOBS      (0x00000800)  //!< Bit mask for SDMAARM_CONFIG_RTDOBS.

//! @brief Get value of SDMAARM_CONFIG_RTDOBS from a register value.
#define BG_SDMAARM_CONFIG_RTDOBS(r)   (((r) & BM_SDMAARM_CONFIG_RTDOBS) >> BP_SDMAARM_CONFIG_RTDOBS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_CONFIG_RTDOBS.
#define BF_SDMAARM_CONFIG_RTDOBS(v)   ((((reg32_t) v) << BP_SDMAARM_CONFIG_RTDOBS) & BM_SDMAARM_CONFIG_RTDOBS)
#else
//! @brief Format value for bitfield SDMAARM_CONFIG_RTDOBS.
#define BF_SDMAARM_CONFIG_RTDOBS(v)   (((v) << BP_SDMAARM_CONFIG_RTDOBS) & BM_SDMAARM_CONFIG_RTDOBS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RTDOBS field to a new value.
#define BW_SDMAARM_CONFIG_RTDOBS(v)   (HW_SDMAARM_CONFIG_WR((HW_SDMAARM_CONFIG_RD() & ~BM_SDMAARM_CONFIG_RTDOBS) | BF_SDMAARM_CONFIG_RTDOBS(v)))
#endif


/* --- Register HW_SDMAARM_CONFIG, field DSPDMA[12] (RW)
 *
 * This bit's function is reserved and should be configured as zero.
 *
 * Values:
 * 0 - - Reset Value
 * 1 - - Reserved
 */

#define BP_SDMAARM_CONFIG_DSPDMA      (12)      //!< Bit position for SDMAARM_CONFIG_DSPDMA.
#define BM_SDMAARM_CONFIG_DSPDMA      (0x00001000)  //!< Bit mask for SDMAARM_CONFIG_DSPDMA.

//! @brief Get value of SDMAARM_CONFIG_DSPDMA from a register value.
#define BG_SDMAARM_CONFIG_DSPDMA(r)   (((r) & BM_SDMAARM_CONFIG_DSPDMA) >> BP_SDMAARM_CONFIG_DSPDMA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_CONFIG_DSPDMA.
#define BF_SDMAARM_CONFIG_DSPDMA(v)   ((((reg32_t) v) << BP_SDMAARM_CONFIG_DSPDMA) & BM_SDMAARM_CONFIG_DSPDMA)
#else
//! @brief Format value for bitfield SDMAARM_CONFIG_DSPDMA.
#define BF_SDMAARM_CONFIG_DSPDMA(v)   (((v) << BP_SDMAARM_CONFIG_DSPDMA) & BM_SDMAARM_CONFIG_DSPDMA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DSPDMA field to a new value.
#define BW_SDMAARM_CONFIG_DSPDMA(v)   (HW_SDMAARM_CONFIG_WR((HW_SDMAARM_CONFIG_RD() & ~BM_SDMAARM_CONFIG_DSPDMA) | BF_SDMAARM_CONFIG_DSPDMA(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_LOCK - SDMA LOCK (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_lock
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_lock_bitfields
    {
        unsigned LOCK : 1; //!< [0] The LOCK bit is used to restrict access to update SDMA script memory through ROM channel zero scripts and through the OnCE interface under ARM platform control. The LOCK bit is set: The SDMA_LOCK, ONCE_ENB,CH0ADDR, and ILLINSTADDR registers cannot be written. These registers can be read, but writes are ignored. SDMA software executing out of ROM or RAM may check the LOCK bit in the LOCK register to determine if certain operations are allowed, such as up-loading new scripts. Once the LOCK bit is set to 1, only a reset can clear it. The LOCK bit is cleared by a hardware reset. LOCK is cleared by a software reset only if SRESET_LOCK_CLR is set.
        unsigned SRESET_LOCK_CLR : 1; //!< [1] The SRESET_LOCK_CLR bit determine if the LOCK bit is cleared on a software reset triggered by writing to the RESET register. This bit cannot be changed if LOCK=1. SREST_LOCK_CLR is cleared by conditions that clear the LOCK bit.
        unsigned RESERVED0 : 30; //!< [31:2] Reserved
    } B;
} hw_sdmaarm_sdma_lock_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_LOCK register
 */
#define HW_SDMAARM_SDMA_LOCK_ADDR      (REGS_SDMAARM_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_LOCK           (*(volatile hw_sdmaarm_sdma_lock_t *) HW_SDMAARM_SDMA_LOCK_ADDR)
#define HW_SDMAARM_SDMA_LOCK_RD()      (HW_SDMAARM_SDMA_LOCK.U)
#define HW_SDMAARM_SDMA_LOCK_WR(v)     (HW_SDMAARM_SDMA_LOCK.U = (v))
#define HW_SDMAARM_SDMA_LOCK_SET(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() |  (v)))
#define HW_SDMAARM_SDMA_LOCK_CLR(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() & ~(v)))
#define HW_SDMAARM_SDMA_LOCK_TOG(v)    (HW_SDMAARM_SDMA_LOCK_WR(HW_SDMAARM_SDMA_LOCK_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_LOCK bitfields
 */

/* --- Register HW_SDMAARM_SDMA_LOCK, field LOCK[0] (RW)
 *
 * The LOCK bit is used to restrict access to update SDMA script memory through ROM channel zero
 * scripts and through the OnCE interface under ARM platform control. The LOCK bit is set: The
 * SDMA_LOCK, ONCE_ENB,CH0ADDR, and ILLINSTADDR registers cannot be written. These registers can be
 * read, but writes are ignored. SDMA software executing out of ROM or RAM may check the LOCK bit in
 * the LOCK register to determine if certain operations are allowed, such as up-loading new scripts.
 * Once the LOCK bit is set to 1, only a reset can clear it. The LOCK bit is cleared by a hardware
 * reset. LOCK is cleared by a software reset only if SRESET_LOCK_CLR is set.
 *
 * Values:
 * 0 - LOCK disengaged.
 * 1 - LOCK enabled.
 */

#define BP_SDMAARM_SDMA_LOCK_LOCK      (0)      //!< Bit position for SDMAARM_SDMA_LOCK_LOCK.
#define BM_SDMAARM_SDMA_LOCK_LOCK      (0x00000001)  //!< Bit mask for SDMAARM_SDMA_LOCK_LOCK.

//! @brief Get value of SDMAARM_SDMA_LOCK_LOCK from a register value.
#define BG_SDMAARM_SDMA_LOCK_LOCK(r)   (((r) & BM_SDMAARM_SDMA_LOCK_LOCK) >> BP_SDMAARM_SDMA_LOCK_LOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_LOCK_LOCK.
#define BF_SDMAARM_SDMA_LOCK_LOCK(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_LOCK_LOCK) & BM_SDMAARM_SDMA_LOCK_LOCK)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_LOCK_LOCK.
#define BF_SDMAARM_SDMA_LOCK_LOCK(v)   (((v) << BP_SDMAARM_SDMA_LOCK_LOCK) & BM_SDMAARM_SDMA_LOCK_LOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOCK field to a new value.
#define BW_SDMAARM_SDMA_LOCK_LOCK(v)   (HW_SDMAARM_SDMA_LOCK_WR((HW_SDMAARM_SDMA_LOCK_RD() & ~BM_SDMAARM_SDMA_LOCK_LOCK) | BF_SDMAARM_SDMA_LOCK_LOCK(v)))
#endif


/* --- Register HW_SDMAARM_SDMA_LOCK, field SRESET_LOCK_CLR[1] (RW)
 *
 * The SRESET_LOCK_CLR bit determine if the LOCK bit is cleared on a software reset triggered by
 * writing to the RESET register. This bit cannot be changed if LOCK=1. SREST_LOCK_CLR is cleared by
 * conditions that clear the LOCK bit.
 *
 * Values:
 * 0 - Software Reset does not clear the LOCK bit.
 * 1 - Software Reset clears the LOCK bit.
 */

#define BP_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR      (1)      //!< Bit position for SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR.
#define BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR      (0x00000002)  //!< Bit mask for SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR.

//! @brief Get value of SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR from a register value.
#define BG_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(r)   (((r) & BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR) >> BP_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR.
#define BF_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR) & BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR.
#define BF_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   (((v) << BP_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR) & BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRESET_LOCK_CLR field to a new value.
#define BW_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)   (HW_SDMAARM_SDMA_LOCK_WR((HW_SDMAARM_SDMA_LOCK_RD() & ~BM_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR) | BF_SDMAARM_SDMA_LOCK_SRESET_LOCK_CLR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_ENB - OnCE Enable (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_once_enb
{
    reg32_t U;
    struct _hw_sdmaarm_once_enb_bitfields
    {
        unsigned ENB : 1; //!< [0] The OnCE Enable register selects the OnCE control source: When cleared (0), the OnCE registers are accessed through the JTAG interface; when set (1), the OnCE registers may be accessed by the ARM platform through the addresses described, as follows. After reset, the OnCE registers are accessed through the JTAG interface. Writing a 1 to ENB enables the ARM platform to access the ONCE_* as any other SDMA control register. When cleared (0), all the ONCE_xxx registers cannot be written. The value of ENB cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned RESERVED0 : 31; //!< [31:1] Reserved
    } B;
} hw_sdmaarm_once_enb_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_ENB register
 */
#define HW_SDMAARM_ONCE_ENB_ADDR      (REGS_SDMAARM_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_ENB           (*(volatile hw_sdmaarm_once_enb_t *) HW_SDMAARM_ONCE_ENB_ADDR)
#define HW_SDMAARM_ONCE_ENB_RD()      (HW_SDMAARM_ONCE_ENB.U)
#define HW_SDMAARM_ONCE_ENB_WR(v)     (HW_SDMAARM_ONCE_ENB.U = (v))
#define HW_SDMAARM_ONCE_ENB_SET(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() |  (v)))
#define HW_SDMAARM_ONCE_ENB_CLR(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() & ~(v)))
#define HW_SDMAARM_ONCE_ENB_TOG(v)    (HW_SDMAARM_ONCE_ENB_WR(HW_SDMAARM_ONCE_ENB_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_ENB bitfields
 */

/* --- Register HW_SDMAARM_ONCE_ENB, field ENB[0] (RW)
 *
 * The OnCE Enable register selects the OnCE control source: When cleared (0), the OnCE registers
 * are accessed through the JTAG interface; when set (1), the OnCE registers may be accessed by the
 * ARM platform through the addresses described, as follows. After reset, the OnCE registers are
 * accessed through the JTAG interface. Writing a 1 to ENB enables the ARM platform to access the
 * ONCE_* as any other SDMA control register. When cleared (0), all the ONCE_xxx registers cannot be
 * written. The value of ENB cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
 */

#define BP_SDMAARM_ONCE_ENB_ENB      (0)      //!< Bit position for SDMAARM_ONCE_ENB_ENB.
#define BM_SDMAARM_ONCE_ENB_ENB      (0x00000001)  //!< Bit mask for SDMAARM_ONCE_ENB_ENB.

//! @brief Get value of SDMAARM_ONCE_ENB_ENB from a register value.
#define BG_SDMAARM_ONCE_ENB_ENB(r)   (((r) & BM_SDMAARM_ONCE_ENB_ENB) >> BP_SDMAARM_ONCE_ENB_ENB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_ONCE_ENB_ENB.
#define BF_SDMAARM_ONCE_ENB_ENB(v)   ((((reg32_t) v) << BP_SDMAARM_ONCE_ENB_ENB) & BM_SDMAARM_ONCE_ENB_ENB)
#else
//! @brief Format value for bitfield SDMAARM_ONCE_ENB_ENB.
#define BF_SDMAARM_ONCE_ENB_ENB(v)   (((v) << BP_SDMAARM_ONCE_ENB_ENB) & BM_SDMAARM_ONCE_ENB_ENB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENB field to a new value.
#define BW_SDMAARM_ONCE_ENB_ENB(v)   (HW_SDMAARM_ONCE_ENB_WR((HW_SDMAARM_ONCE_ENB_RD() & ~BM_SDMAARM_ONCE_ENB_ENB) | BF_SDMAARM_ONCE_ENB_ENB(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_DATA - OnCE Data Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_once_data
{
    reg32_t U;
    struct _hw_sdmaarm_once_data_bitfields
    {
        unsigned DATA : 32; //!< [31:0] Data register of the OnCE JTAG controller. Refer to for information on this register.
    } B;
} hw_sdmaarm_once_data_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_DATA register
 */
#define HW_SDMAARM_ONCE_DATA_ADDR      (REGS_SDMAARM_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_DATA           (*(volatile hw_sdmaarm_once_data_t *) HW_SDMAARM_ONCE_DATA_ADDR)
#define HW_SDMAARM_ONCE_DATA_RD()      (HW_SDMAARM_ONCE_DATA.U)
#define HW_SDMAARM_ONCE_DATA_WR(v)     (HW_SDMAARM_ONCE_DATA.U = (v))
#define HW_SDMAARM_ONCE_DATA_SET(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() |  (v)))
#define HW_SDMAARM_ONCE_DATA_CLR(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() & ~(v)))
#define HW_SDMAARM_ONCE_DATA_TOG(v)    (HW_SDMAARM_ONCE_DATA_WR(HW_SDMAARM_ONCE_DATA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_DATA bitfields
 */

/* --- Register HW_SDMAARM_ONCE_DATA, field DATA[31:0] (RW)
 *
 * Data register of the OnCE JTAG controller. Refer to for information on this register.
 */

#define BP_SDMAARM_ONCE_DATA_DATA      (0)      //!< Bit position for SDMAARM_ONCE_DATA_DATA.
#define BM_SDMAARM_ONCE_DATA_DATA      (0xffffffff)  //!< Bit mask for SDMAARM_ONCE_DATA_DATA.

//! @brief Get value of SDMAARM_ONCE_DATA_DATA from a register value.
#define BG_SDMAARM_ONCE_DATA_DATA(r)   (((r) & BM_SDMAARM_ONCE_DATA_DATA) >> BP_SDMAARM_ONCE_DATA_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_ONCE_DATA_DATA.
#define BF_SDMAARM_ONCE_DATA_DATA(v)   ((((reg32_t) v) << BP_SDMAARM_ONCE_DATA_DATA) & BM_SDMAARM_ONCE_DATA_DATA)
#else
//! @brief Format value for bitfield SDMAARM_ONCE_DATA_DATA.
#define BF_SDMAARM_ONCE_DATA_DATA(v)   (((v) << BP_SDMAARM_ONCE_DATA_DATA) & BM_SDMAARM_ONCE_DATA_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_SDMAARM_ONCE_DATA_DATA(v)   (HW_SDMAARM_ONCE_DATA_WR((HW_SDMAARM_ONCE_DATA_RD() & ~BM_SDMAARM_ONCE_DATA_DATA) | BF_SDMAARM_ONCE_DATA_DATA(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_INSTR - OnCE Instruction Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_once_instr
{
    reg32_t U;
    struct _hw_sdmaarm_once_instr_bitfields
    {
        unsigned INSTR : 16; //!< [15:0] Instruction register of the OnCE JTAG controller. Refer to for information on this register.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_sdmaarm_once_instr_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_INSTR register
 */
#define HW_SDMAARM_ONCE_INSTR_ADDR      (REGS_SDMAARM_BASE + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_INSTR           (*(volatile hw_sdmaarm_once_instr_t *) HW_SDMAARM_ONCE_INSTR_ADDR)
#define HW_SDMAARM_ONCE_INSTR_RD()      (HW_SDMAARM_ONCE_INSTR.U)
#define HW_SDMAARM_ONCE_INSTR_WR(v)     (HW_SDMAARM_ONCE_INSTR.U = (v))
#define HW_SDMAARM_ONCE_INSTR_SET(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() |  (v)))
#define HW_SDMAARM_ONCE_INSTR_CLR(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() & ~(v)))
#define HW_SDMAARM_ONCE_INSTR_TOG(v)    (HW_SDMAARM_ONCE_INSTR_WR(HW_SDMAARM_ONCE_INSTR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_INSTR bitfields
 */

/* --- Register HW_SDMAARM_ONCE_INSTR, field INSTR[15:0] (RW)
 *
 * Instruction register of the OnCE JTAG controller. Refer to for information on this register.
 */

#define BP_SDMAARM_ONCE_INSTR_INSTR      (0)      //!< Bit position for SDMAARM_ONCE_INSTR_INSTR.
#define BM_SDMAARM_ONCE_INSTR_INSTR      (0x0000ffff)  //!< Bit mask for SDMAARM_ONCE_INSTR_INSTR.

//! @brief Get value of SDMAARM_ONCE_INSTR_INSTR from a register value.
#define BG_SDMAARM_ONCE_INSTR_INSTR(r)   (((r) & BM_SDMAARM_ONCE_INSTR_INSTR) >> BP_SDMAARM_ONCE_INSTR_INSTR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_ONCE_INSTR_INSTR.
#define BF_SDMAARM_ONCE_INSTR_INSTR(v)   ((((reg32_t) v) << BP_SDMAARM_ONCE_INSTR_INSTR) & BM_SDMAARM_ONCE_INSTR_INSTR)
#else
//! @brief Format value for bitfield SDMAARM_ONCE_INSTR_INSTR.
#define BF_SDMAARM_ONCE_INSTR_INSTR(v)   (((v) << BP_SDMAARM_ONCE_INSTR_INSTR) & BM_SDMAARM_ONCE_INSTR_INSTR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INSTR field to a new value.
#define BW_SDMAARM_ONCE_INSTR_INSTR(v)   (HW_SDMAARM_ONCE_INSTR_WR((HW_SDMAARM_ONCE_INSTR_RD() & ~BM_SDMAARM_ONCE_INSTR_INSTR) | BF_SDMAARM_ONCE_INSTR_INSTR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_STAT - OnCE Status Register (RO)
 *
 * Reset value: 0x0000e000
 *

 */
typedef union _hw_sdmaarm_once_stat
{
    reg32_t U;
    struct _hw_sdmaarm_once_stat_bitfields
    {
        unsigned ECDR : 3; //!< [2:0] Event Cell Debug Request. If the debug request comes from the event cell, the reason for entering debug mode is given by the EDR bits. If all three bits of the EDR are reset, then it did not generate any debug request. If the cell did generate a debug request, then at least one of the EDR bits is set (the meaning of the encoding is given below). The encoding of the EDR bits is useful to find out more precisely why the debug request was generated. A debug request from an event cell is generated for a specific combination of the addra_cond, addrb_cond, and data_cond conditions. The value of those fields is given by the EDR bits.
        unsigned RESERVED0 : 4; //!< [6:3] Reserved
        unsigned MST : 1; //!< [7] This flag is raised when the OnCE is controlled from the ARM platform peripheral interface.
        unsigned SWB : 1; //!< [8] This flag is raised when the SDMA has entered debug mode after a software breakpoint.
        unsigned ODR : 1; //!< [9] This flag is raised when the SDMA has entered debug mode after a OnCE debug request.
        unsigned EDR : 1; //!< [10] This flag is raised when the SDMA has entered debug mode after an external debug request.
        unsigned RCV : 1; //!< [11] After each write access to the real time buffer (RTB), the RCV bit is set. This bit is cleared after execution of an rbuffer command and on a JTAG reset.
        unsigned PST : 4; //!< [15:12] The Processor Status bits reflect the state of the SDMA RISC engine. Its states are as follows: The "Program" state is the usual instruction execution cycle. The "Data" state is inserted when there are wait-states during a load or a store on the data bus (ld or st). The "Change of Flow" state is the second cycle of any instruction that breaks the sequence of instructions (jumps and channel switching instructions). The "Change of Flow in Loop" state is used when an error causes a hardware loop exit. The "Debug" state means the SDMA is in debug mode. The "Functional Unit" state is inserted when there are wait-states during a load or a store on the functional units bus (ldf or stf). In "Sleep" modes, no script is running (this is the RISC engine idle state). The "after Reset" is slightly different because no context restoring phase will happen when a channel is triggered: The script located at address 0 will be executed (boot operation). The "in Sleep" states are the same as above except they do not have any corresponding channel: They are used when entering debug mode after reset. The reason is that it is necessary to return to the "Sleep after Reset" state when leaving debug mode.
        unsigned RESERVED1 : 16; //!< [31:16] Reserved
    } B;
} hw_sdmaarm_once_stat_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_STAT register
 */
#define HW_SDMAARM_ONCE_STAT_ADDR      (REGS_SDMAARM_BASE + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_STAT           (*(volatile hw_sdmaarm_once_stat_t *) HW_SDMAARM_ONCE_STAT_ADDR)
#define HW_SDMAARM_ONCE_STAT_RD()      (HW_SDMAARM_ONCE_STAT.U)
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_STAT bitfields
 */

/* --- Register HW_SDMAARM_ONCE_STAT, field ECDR[2:0] (RO)
 *
 * Event Cell Debug Request. If the debug request comes from the event cell, the reason for entering
 * debug mode is given by the EDR bits. If all three bits of the EDR are reset, then it did not
 * generate any debug request. If the cell did generate a debug request, then at least one of the
 * EDR bits is set (the meaning of the encoding is given below). The encoding of the EDR bits is
 * useful to find out more precisely why the debug request was generated. A debug request from an
 * event cell is generated for a specific combination of the addra_cond, addrb_cond, and data_cond
 * conditions. The value of those fields is given by the EDR bits.
 *
 * Values:
 * 0 - 1 matched addra_cond
 * 1 - 1 matched addrb_cond
 * 2 - 1 matched data_cond
 */

#define BP_SDMAARM_ONCE_STAT_ECDR      (0)      //!< Bit position for SDMAARM_ONCE_STAT_ECDR.
#define BM_SDMAARM_ONCE_STAT_ECDR      (0x00000007)  //!< Bit mask for SDMAARM_ONCE_STAT_ECDR.

//! @brief Get value of SDMAARM_ONCE_STAT_ECDR from a register value.
#define BG_SDMAARM_ONCE_STAT_ECDR(r)   (((r) & BM_SDMAARM_ONCE_STAT_ECDR) >> BP_SDMAARM_ONCE_STAT_ECDR)


/* --- Register HW_SDMAARM_ONCE_STAT, field MST[7] (RO)
 *
 * This flag is raised when the OnCE is controlled from the ARM platform peripheral interface.
 *
 * Values:
 * 0 - The JTAG interface controls the OnCE.
 * 1 - The ARM platform peripheral interface controls the OnCE.
 */

#define BP_SDMAARM_ONCE_STAT_MST      (7)      //!< Bit position for SDMAARM_ONCE_STAT_MST.
#define BM_SDMAARM_ONCE_STAT_MST      (0x00000080)  //!< Bit mask for SDMAARM_ONCE_STAT_MST.

//! @brief Get value of SDMAARM_ONCE_STAT_MST from a register value.
#define BG_SDMAARM_ONCE_STAT_MST(r)   (((r) & BM_SDMAARM_ONCE_STAT_MST) >> BP_SDMAARM_ONCE_STAT_MST)


/* --- Register HW_SDMAARM_ONCE_STAT, field SWB[8] (RO)
 *
 * This flag is raised when the SDMA has entered debug mode after a software breakpoint.
 */

#define BP_SDMAARM_ONCE_STAT_SWB      (8)      //!< Bit position for SDMAARM_ONCE_STAT_SWB.
#define BM_SDMAARM_ONCE_STAT_SWB      (0x00000100)  //!< Bit mask for SDMAARM_ONCE_STAT_SWB.

//! @brief Get value of SDMAARM_ONCE_STAT_SWB from a register value.
#define BG_SDMAARM_ONCE_STAT_SWB(r)   (((r) & BM_SDMAARM_ONCE_STAT_SWB) >> BP_SDMAARM_ONCE_STAT_SWB)

/* --- Register HW_SDMAARM_ONCE_STAT, field ODR[9] (RO)
 *
 * This flag is raised when the SDMA has entered debug mode after a OnCE debug request.
 */

#define BP_SDMAARM_ONCE_STAT_ODR      (9)      //!< Bit position for SDMAARM_ONCE_STAT_ODR.
#define BM_SDMAARM_ONCE_STAT_ODR      (0x00000200)  //!< Bit mask for SDMAARM_ONCE_STAT_ODR.

//! @brief Get value of SDMAARM_ONCE_STAT_ODR from a register value.
#define BG_SDMAARM_ONCE_STAT_ODR(r)   (((r) & BM_SDMAARM_ONCE_STAT_ODR) >> BP_SDMAARM_ONCE_STAT_ODR)

/* --- Register HW_SDMAARM_ONCE_STAT, field EDR[10] (RO)
 *
 * This flag is raised when the SDMA has entered debug mode after an external debug request.
 */

#define BP_SDMAARM_ONCE_STAT_EDR      (10)      //!< Bit position for SDMAARM_ONCE_STAT_EDR.
#define BM_SDMAARM_ONCE_STAT_EDR      (0x00000400)  //!< Bit mask for SDMAARM_ONCE_STAT_EDR.

//! @brief Get value of SDMAARM_ONCE_STAT_EDR from a register value.
#define BG_SDMAARM_ONCE_STAT_EDR(r)   (((r) & BM_SDMAARM_ONCE_STAT_EDR) >> BP_SDMAARM_ONCE_STAT_EDR)

/* --- Register HW_SDMAARM_ONCE_STAT, field RCV[11] (RO)
 *
 * After each write access to the real time buffer (RTB), the RCV bit is set. This bit is cleared
 * after execution of an rbuffer command and on a JTAG reset.
 */

#define BP_SDMAARM_ONCE_STAT_RCV      (11)      //!< Bit position for SDMAARM_ONCE_STAT_RCV.
#define BM_SDMAARM_ONCE_STAT_RCV      (0x00000800)  //!< Bit mask for SDMAARM_ONCE_STAT_RCV.

//! @brief Get value of SDMAARM_ONCE_STAT_RCV from a register value.
#define BG_SDMAARM_ONCE_STAT_RCV(r)   (((r) & BM_SDMAARM_ONCE_STAT_RCV) >> BP_SDMAARM_ONCE_STAT_RCV)

/* --- Register HW_SDMAARM_ONCE_STAT, field PST[15:12] (RO)
 *
 * The Processor Status bits reflect the state of the SDMA RISC engine. Its states are as follows:
 * The "Program" state is the usual instruction execution cycle. The "Data" state is inserted when
 * there are wait-states during a load or a store on the data bus (ld or st). The "Change of Flow"
 * state is the second cycle of any instruction that breaks the sequence of instructions (jumps and
 * channel switching instructions). The "Change of Flow in Loop" state is used when an error causes
 * a hardware loop exit. The "Debug" state means the SDMA is in debug mode. The "Functional Unit"
 * state is inserted when there are wait-states during a load or a store on the functional units bus
 * (ldf or stf). In "Sleep" modes, no script is running (this is the RISC engine idle state). The
 * "after Reset" is slightly different because no context restoring phase will happen when a channel
 * is triggered: The script located at address 0 will be executed (boot operation). The "in Sleep"
 * states are the same as above except they do not have any corresponding channel: They are used
 * when entering debug mode after reset. The reason is that it is necessary to return to the "Sleep
 * after Reset" state when leaving debug mode.
 *
 * Values:
 * 0 - Program
 * 1 - Data
 * 2 - Change of Flow
 * 3 - Change of Flow in Loop
 * 4 - Debug
 * 5 - Functional Unit
 * 6 - Sleep
 * 7 - Save
 * 8 - Program in Sleep
 * 9 - Data in Sleep
 * 10 - Change of Flow in Sleep
 * 11 - Change Flow in Loop in Sleep
 * 12 - Debug in Sleep
 * 13 - Functional Unit in Sleep
 * 14 - Sleep after Reset
 * 15 - Restore
 */

#define BP_SDMAARM_ONCE_STAT_PST      (12)      //!< Bit position for SDMAARM_ONCE_STAT_PST.
#define BM_SDMAARM_ONCE_STAT_PST      (0x0000f000)  //!< Bit mask for SDMAARM_ONCE_STAT_PST.

//! @brief Get value of SDMAARM_ONCE_STAT_PST from a register value.
#define BG_SDMAARM_ONCE_STAT_PST(r)   (((r) & BM_SDMAARM_ONCE_STAT_PST) >> BP_SDMAARM_ONCE_STAT_PST)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ONCE_CMD - OnCE Command Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_once_cmd
{
    reg32_t U;
    struct _hw_sdmaarm_once_cmd_bitfields
    {
        unsigned CMD : 4; //!< [3:0] Writing to this register will cause the OnCE to execute the command that is written. When needed, the ONCE_DATA and ONCE_INSTR registers should be loaded with the correct value before writing the command to that register. For a list of the OnCE commands and their usage, see . 7-15 reserved
        unsigned RESERVED0 : 28; //!< [31:4] Reserved
    } B;
} hw_sdmaarm_once_cmd_t;
#endif

/*
 * constants & macros for entire SDMAARM_ONCE_CMD register
 */
#define HW_SDMAARM_ONCE_CMD_ADDR      (REGS_SDMAARM_BASE + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ONCE_CMD           (*(volatile hw_sdmaarm_once_cmd_t *) HW_SDMAARM_ONCE_CMD_ADDR)
#define HW_SDMAARM_ONCE_CMD_RD()      (HW_SDMAARM_ONCE_CMD.U)
#define HW_SDMAARM_ONCE_CMD_WR(v)     (HW_SDMAARM_ONCE_CMD.U = (v))
#define HW_SDMAARM_ONCE_CMD_SET(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() |  (v)))
#define HW_SDMAARM_ONCE_CMD_CLR(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() & ~(v)))
#define HW_SDMAARM_ONCE_CMD_TOG(v)    (HW_SDMAARM_ONCE_CMD_WR(HW_SDMAARM_ONCE_CMD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ONCE_CMD bitfields
 */

/* --- Register HW_SDMAARM_ONCE_CMD, field CMD[3:0] (RW)
 *
 * Writing to this register will cause the OnCE to execute the command that is written. When needed,
 * the ONCE_DATA and ONCE_INSTR registers should be loaded with the correct value before writing the
 * command to that register. For a list of the OnCE commands and their usage, see . 7-15 reserved
 *
 * Values:
 * 0 - rstatus
 * 1 - dmov
 * 2 - exec_once
 * 3 - run_core
 * 4 - exec_core
 * 5 - debug_rqst
 * 6 - rbuffer
 */

#define BP_SDMAARM_ONCE_CMD_CMD      (0)      //!< Bit position for SDMAARM_ONCE_CMD_CMD.
#define BM_SDMAARM_ONCE_CMD_CMD      (0x0000000f)  //!< Bit mask for SDMAARM_ONCE_CMD_CMD.

//! @brief Get value of SDMAARM_ONCE_CMD_CMD from a register value.
#define BG_SDMAARM_ONCE_CMD_CMD(r)   (((r) & BM_SDMAARM_ONCE_CMD_CMD) >> BP_SDMAARM_ONCE_CMD_CMD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_ONCE_CMD_CMD.
#define BF_SDMAARM_ONCE_CMD_CMD(v)   ((((reg32_t) v) << BP_SDMAARM_ONCE_CMD_CMD) & BM_SDMAARM_ONCE_CMD_CMD)
#else
//! @brief Format value for bitfield SDMAARM_ONCE_CMD_CMD.
#define BF_SDMAARM_ONCE_CMD_CMD(v)   (((v) << BP_SDMAARM_ONCE_CMD_CMD) & BM_SDMAARM_ONCE_CMD_CMD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CMD field to a new value.
#define BW_SDMAARM_ONCE_CMD_CMD(v)   (HW_SDMAARM_ONCE_CMD_WR((HW_SDMAARM_ONCE_CMD_RD() & ~BM_SDMAARM_ONCE_CMD_CMD) | BF_SDMAARM_ONCE_CMD_CMD(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_ILLINSTADDR - Illegal Instruction Trap Address (RW)
 *
 * Reset value: 0x00000001
 *

 */
typedef union _hw_sdmaarm_illinstaddr
{
    reg32_t U;
    struct _hw_sdmaarm_illinstaddr_bitfields
    {
        unsigned ILLINSTADDR : 14; //!< [13:0] The Illegal Instruction Trap Address is the address where the SDMA jumps when an illegal instruction is executed. It is 0x0001 after reset. The value of ILLINSTADDR cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned RESERVED0 : 18; //!< [31:14] Reserved
    } B;
} hw_sdmaarm_illinstaddr_t;
#endif

/*
 * constants & macros for entire SDMAARM_ILLINSTADDR register
 */
#define HW_SDMAARM_ILLINSTADDR_ADDR      (REGS_SDMAARM_BASE + 0x58)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_ILLINSTADDR           (*(volatile hw_sdmaarm_illinstaddr_t *) HW_SDMAARM_ILLINSTADDR_ADDR)
#define HW_SDMAARM_ILLINSTADDR_RD()      (HW_SDMAARM_ILLINSTADDR.U)
#define HW_SDMAARM_ILLINSTADDR_WR(v)     (HW_SDMAARM_ILLINSTADDR.U = (v))
#define HW_SDMAARM_ILLINSTADDR_SET(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() |  (v)))
#define HW_SDMAARM_ILLINSTADDR_CLR(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() & ~(v)))
#define HW_SDMAARM_ILLINSTADDR_TOG(v)    (HW_SDMAARM_ILLINSTADDR_WR(HW_SDMAARM_ILLINSTADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_ILLINSTADDR bitfields
 */

/* --- Register HW_SDMAARM_ILLINSTADDR, field ILLINSTADDR[13:0] (RW)
 *
 * The Illegal Instruction Trap Address is the address where the SDMA jumps when an illegal
 * instruction is executed. It is 0x0001 after reset. The value of ILLINSTADDR cannot be changed if
 * the LOCK bit in the SDMA_LOCK register is set.
 */

#define BP_SDMAARM_ILLINSTADDR_ILLINSTADDR      (0)      //!< Bit position for SDMAARM_ILLINSTADDR_ILLINSTADDR.
#define BM_SDMAARM_ILLINSTADDR_ILLINSTADDR      (0x00003fff)  //!< Bit mask for SDMAARM_ILLINSTADDR_ILLINSTADDR.

//! @brief Get value of SDMAARM_ILLINSTADDR_ILLINSTADDR from a register value.
#define BG_SDMAARM_ILLINSTADDR_ILLINSTADDR(r)   (((r) & BM_SDMAARM_ILLINSTADDR_ILLINSTADDR) >> BP_SDMAARM_ILLINSTADDR_ILLINSTADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_ILLINSTADDR_ILLINSTADDR.
#define BF_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   ((((reg32_t) v) << BP_SDMAARM_ILLINSTADDR_ILLINSTADDR) & BM_SDMAARM_ILLINSTADDR_ILLINSTADDR)
#else
//! @brief Format value for bitfield SDMAARM_ILLINSTADDR_ILLINSTADDR.
#define BF_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   (((v) << BP_SDMAARM_ILLINSTADDR_ILLINSTADDR) & BM_SDMAARM_ILLINSTADDR_ILLINSTADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ILLINSTADDR field to a new value.
#define BW_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)   (HW_SDMAARM_ILLINSTADDR_WR((HW_SDMAARM_ILLINSTADDR_RD() & ~BM_SDMAARM_ILLINSTADDR_ILLINSTADDR) | BF_SDMAARM_ILLINSTADDR_ILLINSTADDR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_CHN0ADDR - Channel 0 Boot Address (RW)
 *
 * Reset value: 0x00000050
 *

 */
typedef union _hw_sdmaarm_chn0addr
{
    reg32_t U;
    struct _hw_sdmaarm_chn0addr_bitfields
    {
        unsigned CHN0ADDR : 14; //!< [13:0] This 14-bit register is used by the boot code of the SDMA. After reset, it points to the standard boot routine in ROM (channel 0 routine). By changing this address, you can perform a boot sequence with your own routine. The very first instructions of the boot code fetch the contents of this register (it is also mapped in the SDMA memory space) and jump to the given address. The reset value is 0x0050 (decimal 80). The value of CHN0ADDR cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned SMSZ : 1; //!< [14] The bit 14 (Scratch Memory Size) determines if scratch memory must be available after every channel context. After reset, it is equal to 0, which defines a RAM space of 24 words for each channel. All of this area stores the channel context. By setting this bit, 32 words are reserved for every channel context, which gives eight additional words that can be used by the channel script to store any type of data. Those words are never erased by the context switching mechanism. The value of SMSZ cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
        unsigned RESERVED0 : 17; //!< [31:15] Reserved
    } B;
} hw_sdmaarm_chn0addr_t;
#endif

/*
 * constants & macros for entire SDMAARM_CHN0ADDR register
 */
#define HW_SDMAARM_CHN0ADDR_ADDR      (REGS_SDMAARM_BASE + 0x5c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_CHN0ADDR           (*(volatile hw_sdmaarm_chn0addr_t *) HW_SDMAARM_CHN0ADDR_ADDR)
#define HW_SDMAARM_CHN0ADDR_RD()      (HW_SDMAARM_CHN0ADDR.U)
#define HW_SDMAARM_CHN0ADDR_WR(v)     (HW_SDMAARM_CHN0ADDR.U = (v))
#define HW_SDMAARM_CHN0ADDR_SET(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() |  (v)))
#define HW_SDMAARM_CHN0ADDR_CLR(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() & ~(v)))
#define HW_SDMAARM_CHN0ADDR_TOG(v)    (HW_SDMAARM_CHN0ADDR_WR(HW_SDMAARM_CHN0ADDR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_CHN0ADDR bitfields
 */

/* --- Register HW_SDMAARM_CHN0ADDR, field CHN0ADDR[13:0] (RW)
 *
 * This 14-bit register is used by the boot code of the SDMA. After reset, it points to the standard
 * boot routine in ROM (channel 0 routine). By changing this address, you can perform a boot
 * sequence with your own routine. The very first instructions of the boot code fetch the contents
 * of this register (it is also mapped in the SDMA memory space) and jump to the given address. The
 * reset value is 0x0050 (decimal 80). The value of CHN0ADDR cannot be changed if the LOCK bit in
 * the SDMA_LOCK register is set.
 */

#define BP_SDMAARM_CHN0ADDR_CHN0ADDR      (0)      //!< Bit position for SDMAARM_CHN0ADDR_CHN0ADDR.
#define BM_SDMAARM_CHN0ADDR_CHN0ADDR      (0x00003fff)  //!< Bit mask for SDMAARM_CHN0ADDR_CHN0ADDR.

//! @brief Get value of SDMAARM_CHN0ADDR_CHN0ADDR from a register value.
#define BG_SDMAARM_CHN0ADDR_CHN0ADDR(r)   (((r) & BM_SDMAARM_CHN0ADDR_CHN0ADDR) >> BP_SDMAARM_CHN0ADDR_CHN0ADDR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_CHN0ADDR_CHN0ADDR.
#define BF_SDMAARM_CHN0ADDR_CHN0ADDR(v)   ((((reg32_t) v) << BP_SDMAARM_CHN0ADDR_CHN0ADDR) & BM_SDMAARM_CHN0ADDR_CHN0ADDR)
#else
//! @brief Format value for bitfield SDMAARM_CHN0ADDR_CHN0ADDR.
#define BF_SDMAARM_CHN0ADDR_CHN0ADDR(v)   (((v) << BP_SDMAARM_CHN0ADDR_CHN0ADDR) & BM_SDMAARM_CHN0ADDR_CHN0ADDR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHN0ADDR field to a new value.
#define BW_SDMAARM_CHN0ADDR_CHN0ADDR(v)   (HW_SDMAARM_CHN0ADDR_WR((HW_SDMAARM_CHN0ADDR_RD() & ~BM_SDMAARM_CHN0ADDR_CHN0ADDR) | BF_SDMAARM_CHN0ADDR_CHN0ADDR(v)))
#endif

/* --- Register HW_SDMAARM_CHN0ADDR, field SMSZ[14] (RW)
 *
 * The bit 14 (Scratch Memory Size) determines if scratch memory must be available after every
 * channel context. After reset, it is equal to 0, which defines a RAM space of 24 words for each
 * channel. All of this area stores the channel context. By setting this bit, 32 words are reserved
 * for every channel context, which gives eight additional words that can be used by the channel
 * script to store any type of data. Those words are never erased by the context switching
 * mechanism. The value of SMSZ cannot be changed if the LOCK bit in the SDMA_LOCK register is set.
 *
 * Values:
 * 0 - 24 words per context
 * 1 - 32 words per context
 */

#define BP_SDMAARM_CHN0ADDR_SMSZ      (14)      //!< Bit position for SDMAARM_CHN0ADDR_SMSZ.
#define BM_SDMAARM_CHN0ADDR_SMSZ      (0x00004000)  //!< Bit mask for SDMAARM_CHN0ADDR_SMSZ.

//! @brief Get value of SDMAARM_CHN0ADDR_SMSZ from a register value.
#define BG_SDMAARM_CHN0ADDR_SMSZ(r)   (((r) & BM_SDMAARM_CHN0ADDR_SMSZ) >> BP_SDMAARM_CHN0ADDR_SMSZ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_CHN0ADDR_SMSZ.
#define BF_SDMAARM_CHN0ADDR_SMSZ(v)   ((((reg32_t) v) << BP_SDMAARM_CHN0ADDR_SMSZ) & BM_SDMAARM_CHN0ADDR_SMSZ)
#else
//! @brief Format value for bitfield SDMAARM_CHN0ADDR_SMSZ.
#define BF_SDMAARM_CHN0ADDR_SMSZ(v)   (((v) << BP_SDMAARM_CHN0ADDR_SMSZ) & BM_SDMAARM_CHN0ADDR_SMSZ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SMSZ field to a new value.
#define BW_SDMAARM_CHN0ADDR_SMSZ(v)   (HW_SDMAARM_CHN0ADDR_WR((HW_SDMAARM_CHN0ADDR_RD() & ~BM_SDMAARM_CHN0ADDR_SMSZ) | BF_SDMAARM_CHN0ADDR_SMSZ(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVT_MIRROR - DMA Requests (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_evt_mirror
{
    reg32_t U;
    struct _hw_sdmaarm_evt_mirror_bitfields
    {
        unsigned EVENTS : 32; //!< [31:0] This register reflects the DMA requests received by the SDMA for events 31-0. The ARM platform and the SDMA have a read-only access. There is one bit associated with each of 32 DMA request events. This information may be useful during debug of the blocks that generate the DMA requests. The EVT_MIRROR register is cleared following read access.
    } B;
} hw_sdmaarm_evt_mirror_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVT_MIRROR register
 */
#define HW_SDMAARM_EVT_MIRROR_ADDR      (REGS_SDMAARM_BASE + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVT_MIRROR           (*(volatile hw_sdmaarm_evt_mirror_t *) HW_SDMAARM_EVT_MIRROR_ADDR)
#define HW_SDMAARM_EVT_MIRROR_RD()      (HW_SDMAARM_EVT_MIRROR.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVT_MIRROR bitfields
 */

/* --- Register HW_SDMAARM_EVT_MIRROR, field EVENTS[31:0] (RO)
 *
 * This register reflects the DMA requests received by the SDMA for events 31-0. The ARM platform
 * and the SDMA have a read-only access. There is one bit associated with each of 32 DMA request
 * events. This information may be useful during debug of the blocks that generate the DMA requests.
 * The EVT_MIRROR register is cleared following read access.
 *
 * Values:
 * 0 - DMA request event not pending
 * 1 - DMA request event pending
 */

#define BP_SDMAARM_EVT_MIRROR_EVENTS      (0)      //!< Bit position for SDMAARM_EVT_MIRROR_EVENTS.
#define BM_SDMAARM_EVT_MIRROR_EVENTS      (0xffffffff)  //!< Bit mask for SDMAARM_EVT_MIRROR_EVENTS.

//! @brief Get value of SDMAARM_EVT_MIRROR_EVENTS from a register value.
#define BG_SDMAARM_EVT_MIRROR_EVENTS(r)   (((r) & BM_SDMAARM_EVT_MIRROR_EVENTS) >> BP_SDMAARM_EVT_MIRROR_EVENTS)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_EVT_MIRROR2 - DMA Requests 2 (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_evt_mirror2
{
    reg32_t U;
    struct _hw_sdmaarm_evt_mirror2_bitfields
    {
        unsigned EVENTS : 16; //!< [15:0] This register reflects the DMA requests received by the SDMA for events 47-32. The ARM platform and the SDMA have a read-only access. There is one bit associated with each of DMA request events. This information may be useful during debug of the blocks that generate the DMA requests. The EVT_MIRROR2 register is cleared following read access.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved
    } B;
} hw_sdmaarm_evt_mirror2_t;
#endif

/*
 * constants & macros for entire SDMAARM_EVT_MIRROR2 register
 */
#define HW_SDMAARM_EVT_MIRROR2_ADDR      (REGS_SDMAARM_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_EVT_MIRROR2           (*(volatile hw_sdmaarm_evt_mirror2_t *) HW_SDMAARM_EVT_MIRROR2_ADDR)
#define HW_SDMAARM_EVT_MIRROR2_RD()      (HW_SDMAARM_EVT_MIRROR2.U)
#endif

/*
 * constants & macros for individual SDMAARM_EVT_MIRROR2 bitfields
 */

/* --- Register HW_SDMAARM_EVT_MIRROR2, field EVENTS[15:0] (RO)
 *
 * This register reflects the DMA requests received by the SDMA for events 47-32. The ARM platform
 * and the SDMA have a read-only access. There is one bit associated with each of DMA request
 * events. This information may be useful during debug of the blocks that generate the DMA requests.
 * The EVT_MIRROR2 register is cleared following read access.
 *
 * Values:
 * 0 - - DMA request event not pending
 * 1- - DMA request event pending
 */

#define BP_SDMAARM_EVT_MIRROR2_EVENTS      (0)      //!< Bit position for SDMAARM_EVT_MIRROR2_EVENTS.
#define BM_SDMAARM_EVT_MIRROR2_EVENTS      (0x0000ffff)  //!< Bit mask for SDMAARM_EVT_MIRROR2_EVENTS.

//! @brief Get value of SDMAARM_EVT_MIRROR2_EVENTS from a register value.
#define BG_SDMAARM_EVT_MIRROR2_EVENTS(r)   (((r) & BM_SDMAARM_EVT_MIRROR2_EVENTS) >> BP_SDMAARM_EVT_MIRROR2_EVENTS)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_XTRIG_CONF1 - Cross-Trigger Events Configuration Register 1 (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_xtrig_conf1
{
    reg32_t U;
    struct _hw_sdmaarm_xtrig_conf1_bitfields
    {
        unsigned NUM0 : 6; //!< [5:0] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF0 : 1; //!< [6] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED0 : 1; //!< [7] Reserved
        unsigned NUM1 : 6; //!< [13:8] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF1 : 1; //!< [14] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED1 : 1; //!< [15] Reserved
        unsigned NUM2 : 6; //!< [21:16] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF2 : 1; //!< [22] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED2 : 1; //!< [23] Reserved
        unsigned NUM3 : 6; //!< [29:24] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF3 : 1; //!< [30] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by the reception of a DMA request or by the starting of a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED3 : 1; //!< [31] Reserved
    } B;
} hw_sdmaarm_xtrig_conf1_t;
#endif

/*
 * constants & macros for entire SDMAARM_XTRIG_CONF1 register
 */
#define HW_SDMAARM_XTRIG_CONF1_ADDR      (REGS_SDMAARM_BASE + 0x70)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_XTRIG_CONF1           (*(volatile hw_sdmaarm_xtrig_conf1_t *) HW_SDMAARM_XTRIG_CONF1_ADDR)
#define HW_SDMAARM_XTRIG_CONF1_RD()      (HW_SDMAARM_XTRIG_CONF1.U)
#define HW_SDMAARM_XTRIG_CONF1_WR(v)     (HW_SDMAARM_XTRIG_CONF1.U = (v))
#define HW_SDMAARM_XTRIG_CONF1_SET(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() |  (v)))
#define HW_SDMAARM_XTRIG_CONF1_CLR(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() & ~(v)))
#define HW_SDMAARM_XTRIG_CONF1_TOG(v)    (HW_SDMAARM_XTRIG_CONF1_WR(HW_SDMAARM_XTRIG_CONF1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_XTRIG_CONF1 bitfields
 */

/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM0[5:0] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM0      (0)      //!< Bit position for SDMAARM_XTRIG_CONF1_NUM0.
#define BM_SDMAARM_XTRIG_CONF1_NUM0      (0x0000003f)  //!< Bit mask for SDMAARM_XTRIG_CONF1_NUM0.

//! @brief Get value of SDMAARM_XTRIG_CONF1_NUM0 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_NUM0(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_NUM0) >> BP_SDMAARM_XTRIG_CONF1_NUM0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM0.
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_NUM0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM0.
#define BF_SDMAARM_XTRIG_CONF1_NUM0(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_NUM0) & BM_SDMAARM_XTRIG_CONF1_NUM0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM0 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM0(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_NUM0) | BF_SDMAARM_XTRIG_CONF1_NUM0(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF0[6] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF0      (6)      //!< Bit position for SDMAARM_XTRIG_CONF1_CNF0.
#define BM_SDMAARM_XTRIG_CONF1_CNF0      (0x00000040)  //!< Bit mask for SDMAARM_XTRIG_CONF1_CNF0.

//! @brief Get value of SDMAARM_XTRIG_CONF1_CNF0 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_CNF0(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_CNF0) >> BP_SDMAARM_XTRIG_CONF1_CNF0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF0.
#define BF_SDMAARM_XTRIG_CONF1_CNF0(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_CNF0) & BM_SDMAARM_XTRIG_CONF1_CNF0)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF0.
#define BF_SDMAARM_XTRIG_CONF1_CNF0(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_CNF0) & BM_SDMAARM_XTRIG_CONF1_CNF0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF0 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF0(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_CNF0) | BF_SDMAARM_XTRIG_CONF1_CNF0(v)))
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM1[13:8] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM1      (8)      //!< Bit position for SDMAARM_XTRIG_CONF1_NUM1.
#define BM_SDMAARM_XTRIG_CONF1_NUM1      (0x00003f00)  //!< Bit mask for SDMAARM_XTRIG_CONF1_NUM1.

//! @brief Get value of SDMAARM_XTRIG_CONF1_NUM1 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_NUM1(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_NUM1) >> BP_SDMAARM_XTRIG_CONF1_NUM1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM1.
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_NUM1) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM1.
#define BF_SDMAARM_XTRIG_CONF1_NUM1(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_NUM1) & BM_SDMAARM_XTRIG_CONF1_NUM1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM1 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM1(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_NUM1) | BF_SDMAARM_XTRIG_CONF1_NUM1(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF1[14] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF1      (14)      //!< Bit position for SDMAARM_XTRIG_CONF1_CNF1.
#define BM_SDMAARM_XTRIG_CONF1_CNF1      (0x00004000)  //!< Bit mask for SDMAARM_XTRIG_CONF1_CNF1.

//! @brief Get value of SDMAARM_XTRIG_CONF1_CNF1 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_CNF1(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_CNF1) >> BP_SDMAARM_XTRIG_CONF1_CNF1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF1.
#define BF_SDMAARM_XTRIG_CONF1_CNF1(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_CNF1) & BM_SDMAARM_XTRIG_CONF1_CNF1)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF1.
#define BF_SDMAARM_XTRIG_CONF1_CNF1(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_CNF1) & BM_SDMAARM_XTRIG_CONF1_CNF1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF1 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF1(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_CNF1) | BF_SDMAARM_XTRIG_CONF1_CNF1(v)))
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM2[21:16] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM2      (16)      //!< Bit position for SDMAARM_XTRIG_CONF1_NUM2.
#define BM_SDMAARM_XTRIG_CONF1_NUM2      (0x003f0000)  //!< Bit mask for SDMAARM_XTRIG_CONF1_NUM2.

//! @brief Get value of SDMAARM_XTRIG_CONF1_NUM2 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_NUM2(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_NUM2) >> BP_SDMAARM_XTRIG_CONF1_NUM2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM2.
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_NUM2) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM2.
#define BF_SDMAARM_XTRIG_CONF1_NUM2(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_NUM2) & BM_SDMAARM_XTRIG_CONF1_NUM2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM2 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM2(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_NUM2) | BF_SDMAARM_XTRIG_CONF1_NUM2(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF2[22] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF2      (22)      //!< Bit position for SDMAARM_XTRIG_CONF1_CNF2.
#define BM_SDMAARM_XTRIG_CONF1_CNF2      (0x00400000)  //!< Bit mask for SDMAARM_XTRIG_CONF1_CNF2.

//! @brief Get value of SDMAARM_XTRIG_CONF1_CNF2 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_CNF2(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_CNF2) >> BP_SDMAARM_XTRIG_CONF1_CNF2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF2.
#define BF_SDMAARM_XTRIG_CONF1_CNF2(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_CNF2) & BM_SDMAARM_XTRIG_CONF1_CNF2)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF2.
#define BF_SDMAARM_XTRIG_CONF1_CNF2(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_CNF2) & BM_SDMAARM_XTRIG_CONF1_CNF2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF2 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF2(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_CNF2) | BF_SDMAARM_XTRIG_CONF1_CNF2(v)))
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF1, field NUM3[29:24] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF1_NUM3      (24)      //!< Bit position for SDMAARM_XTRIG_CONF1_NUM3.
#define BM_SDMAARM_XTRIG_CONF1_NUM3      (0x3f000000)  //!< Bit mask for SDMAARM_XTRIG_CONF1_NUM3.

//! @brief Get value of SDMAARM_XTRIG_CONF1_NUM3 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_NUM3(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_NUM3) >> BP_SDMAARM_XTRIG_CONF1_NUM3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM3.
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_NUM3) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_NUM3.
#define BF_SDMAARM_XTRIG_CONF1_NUM3(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_NUM3) & BM_SDMAARM_XTRIG_CONF1_NUM3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM3 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_NUM3(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_NUM3) | BF_SDMAARM_XTRIG_CONF1_NUM3(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF1, field CNF3[30] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by the reception of a DMA request or by the
 * starting of a channel script execution. When a pulse is generated by starting of a channel script
 * execution, it is in fact generated by the restore part of the context switch mechanism.
 * Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset
 * (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF1_CNF3      (30)      //!< Bit position for SDMAARM_XTRIG_CONF1_CNF3.
#define BM_SDMAARM_XTRIG_CONF1_CNF3      (0x40000000)  //!< Bit mask for SDMAARM_XTRIG_CONF1_CNF3.

//! @brief Get value of SDMAARM_XTRIG_CONF1_CNF3 from a register value.
#define BG_SDMAARM_XTRIG_CONF1_CNF3(r)   (((r) & BM_SDMAARM_XTRIG_CONF1_CNF3) >> BP_SDMAARM_XTRIG_CONF1_CNF3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF3.
#define BF_SDMAARM_XTRIG_CONF1_CNF3(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF1_CNF3) & BM_SDMAARM_XTRIG_CONF1_CNF3)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF1_CNF3.
#define BF_SDMAARM_XTRIG_CONF1_CNF3(v)   (((v) << BP_SDMAARM_XTRIG_CONF1_CNF3) & BM_SDMAARM_XTRIG_CONF1_CNF3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF3 field to a new value.
#define BW_SDMAARM_XTRIG_CONF1_CNF3(v)   (HW_SDMAARM_XTRIG_CONF1_WR((HW_SDMAARM_XTRIG_CONF1_RD() & ~BM_SDMAARM_XTRIG_CONF1_CNF3) | BF_SDMAARM_XTRIG_CONF1_CNF3(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_XTRIG_CONF2 - Cross-Trigger Events Configuration Register 2 (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_xtrig_conf2
{
    reg32_t U;
    struct _hw_sdmaarm_xtrig_conf2_bitfields
    {
        unsigned NUM4 : 6; //!< [5:0] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF4 : 1; //!< [6] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED0 : 1; //!< [7] Reserved
        unsigned NUM5 : 6; //!< [13:8] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF5 : 1; //!< [14] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution . When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED1 : 1; //!< [15] Reserved
        unsigned NUM6 : 6; //!< [21:16] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF6 : 1; //!< [22] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED2 : 1; //!< [23] Reserved
        unsigned NUM7 : 6; //!< [29:24] Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger event line number i .
        unsigned CNF7 : 1; //!< [30] Configuration of the SDMA event line number i that is connected to the cross-trigger. It determines whether the event line pulse is generated by receiving a DMA request or by starting a channel script execution. When a pulse is generated by starting of a channel script execution, it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
        unsigned RESERVED3 : 1; //!< [31] Reserved
    } B;
} hw_sdmaarm_xtrig_conf2_t;
#endif

/*
 * constants & macros for entire SDMAARM_XTRIG_CONF2 register
 */
#define HW_SDMAARM_XTRIG_CONF2_ADDR      (REGS_SDMAARM_BASE + 0x74)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_XTRIG_CONF2           (*(volatile hw_sdmaarm_xtrig_conf2_t *) HW_SDMAARM_XTRIG_CONF2_ADDR)
#define HW_SDMAARM_XTRIG_CONF2_RD()      (HW_SDMAARM_XTRIG_CONF2.U)
#define HW_SDMAARM_XTRIG_CONF2_WR(v)     (HW_SDMAARM_XTRIG_CONF2.U = (v))
#define HW_SDMAARM_XTRIG_CONF2_SET(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() |  (v)))
#define HW_SDMAARM_XTRIG_CONF2_CLR(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() & ~(v)))
#define HW_SDMAARM_XTRIG_CONF2_TOG(v)    (HW_SDMAARM_XTRIG_CONF2_WR(HW_SDMAARM_XTRIG_CONF2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_XTRIG_CONF2 bitfields
 */

/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM4[5:0] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM4      (0)      //!< Bit position for SDMAARM_XTRIG_CONF2_NUM4.
#define BM_SDMAARM_XTRIG_CONF2_NUM4      (0x0000003f)  //!< Bit mask for SDMAARM_XTRIG_CONF2_NUM4.

//! @brief Get value of SDMAARM_XTRIG_CONF2_NUM4 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_NUM4(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_NUM4) >> BP_SDMAARM_XTRIG_CONF2_NUM4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM4.
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_NUM4) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM4.
#define BF_SDMAARM_XTRIG_CONF2_NUM4(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_NUM4) & BM_SDMAARM_XTRIG_CONF2_NUM4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM4 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM4(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_NUM4) | BF_SDMAARM_XTRIG_CONF2_NUM4(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF4[6] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF4      (6)      //!< Bit position for SDMAARM_XTRIG_CONF2_CNF4.
#define BM_SDMAARM_XTRIG_CONF2_CNF4      (0x00000040)  //!< Bit mask for SDMAARM_XTRIG_CONF2_CNF4.

//! @brief Get value of SDMAARM_XTRIG_CONF2_CNF4 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_CNF4(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_CNF4) >> BP_SDMAARM_XTRIG_CONF2_CNF4)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF4.
#define BF_SDMAARM_XTRIG_CONF2_CNF4(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_CNF4) & BM_SDMAARM_XTRIG_CONF2_CNF4)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF4.
#define BF_SDMAARM_XTRIG_CONF2_CNF4(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_CNF4) & BM_SDMAARM_XTRIG_CONF2_CNF4)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF4 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF4(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_CNF4) | BF_SDMAARM_XTRIG_CONF2_CNF4(v)))
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM5[13:8] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM5      (8)      //!< Bit position for SDMAARM_XTRIG_CONF2_NUM5.
#define BM_SDMAARM_XTRIG_CONF2_NUM5      (0x00003f00)  //!< Bit mask for SDMAARM_XTRIG_CONF2_NUM5.

//! @brief Get value of SDMAARM_XTRIG_CONF2_NUM5 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_NUM5(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_NUM5) >> BP_SDMAARM_XTRIG_CONF2_NUM5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM5.
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_NUM5) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM5.
#define BF_SDMAARM_XTRIG_CONF2_NUM5(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_NUM5) & BM_SDMAARM_XTRIG_CONF2_NUM5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM5 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM5(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_NUM5) | BF_SDMAARM_XTRIG_CONF2_NUM5(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF5[14] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution . When a pulse is generated by starting of a channel script execution,
 * it is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse
 * is generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF5      (14)      //!< Bit position for SDMAARM_XTRIG_CONF2_CNF5.
#define BM_SDMAARM_XTRIG_CONF2_CNF5      (0x00004000)  //!< Bit mask for SDMAARM_XTRIG_CONF2_CNF5.

//! @brief Get value of SDMAARM_XTRIG_CONF2_CNF5 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_CNF5(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_CNF5) >> BP_SDMAARM_XTRIG_CONF2_CNF5)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF5.
#define BF_SDMAARM_XTRIG_CONF2_CNF5(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_CNF5) & BM_SDMAARM_XTRIG_CONF2_CNF5)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF5.
#define BF_SDMAARM_XTRIG_CONF2_CNF5(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_CNF5) & BM_SDMAARM_XTRIG_CONF2_CNF5)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF5 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF5(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_CNF5) | BF_SDMAARM_XTRIG_CONF2_CNF5(v)))
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM6[21:16] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM6      (16)      //!< Bit position for SDMAARM_XTRIG_CONF2_NUM6.
#define BM_SDMAARM_XTRIG_CONF2_NUM6      (0x003f0000)  //!< Bit mask for SDMAARM_XTRIG_CONF2_NUM6.

//! @brief Get value of SDMAARM_XTRIG_CONF2_NUM6 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_NUM6(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_NUM6) >> BP_SDMAARM_XTRIG_CONF2_NUM6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM6.
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_NUM6) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM6.
#define BF_SDMAARM_XTRIG_CONF2_NUM6(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_NUM6) & BM_SDMAARM_XTRIG_CONF2_NUM6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM6 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM6(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_NUM6) | BF_SDMAARM_XTRIG_CONF2_NUM6(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF6[22] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF6      (22)      //!< Bit position for SDMAARM_XTRIG_CONF2_CNF6.
#define BM_SDMAARM_XTRIG_CONF2_CNF6      (0x00400000)  //!< Bit mask for SDMAARM_XTRIG_CONF2_CNF6.

//! @brief Get value of SDMAARM_XTRIG_CONF2_CNF6 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_CNF6(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_CNF6) >> BP_SDMAARM_XTRIG_CONF2_CNF6)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF6.
#define BF_SDMAARM_XTRIG_CONF2_CNF6(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_CNF6) & BM_SDMAARM_XTRIG_CONF2_CNF6)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF6.
#define BF_SDMAARM_XTRIG_CONF2_CNF6(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_CNF6) & BM_SDMAARM_XTRIG_CONF2_CNF6)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF6 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF6(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_CNF6) | BF_SDMAARM_XTRIG_CONF2_CNF6(v)))
#endif


/* --- Register HW_SDMAARM_XTRIG_CONF2, field NUM7[29:24] (RW)
 *
 * Contains the number of the DMA request or channel that triggers the pulse on the cross-trigger
 * event line number i .
 */

#define BP_SDMAARM_XTRIG_CONF2_NUM7      (24)      //!< Bit position for SDMAARM_XTRIG_CONF2_NUM7.
#define BM_SDMAARM_XTRIG_CONF2_NUM7      (0x3f000000)  //!< Bit mask for SDMAARM_XTRIG_CONF2_NUM7.

//! @brief Get value of SDMAARM_XTRIG_CONF2_NUM7 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_NUM7(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_NUM7) >> BP_SDMAARM_XTRIG_CONF2_NUM7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM7.
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_NUM7) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_NUM7.
#define BF_SDMAARM_XTRIG_CONF2_NUM7(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_NUM7) & BM_SDMAARM_XTRIG_CONF2_NUM7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NUM7 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_NUM7(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_NUM7) | BF_SDMAARM_XTRIG_CONF2_NUM7(v)))
#endif

/* --- Register HW_SDMAARM_XTRIG_CONF2, field CNF7[30] (RW)
 *
 * Configuration of the SDMA event line number i that is connected to the cross-trigger. It
 * determines whether the event line pulse is generated by receiving a DMA request or by starting a
 * channel script execution. When a pulse is generated by starting of a channel script execution, it
 * is in fact generated by the restore part of the context switch mechanism. Therefore, no pulse is
 * generated the first time channel 0 (boot channel) is executed after reset (on AP demand).
 *
 * Values:
 * 0 - channel
 * 1 - DMA request
 */

#define BP_SDMAARM_XTRIG_CONF2_CNF7      (30)      //!< Bit position for SDMAARM_XTRIG_CONF2_CNF7.
#define BM_SDMAARM_XTRIG_CONF2_CNF7      (0x40000000)  //!< Bit mask for SDMAARM_XTRIG_CONF2_CNF7.

//! @brief Get value of SDMAARM_XTRIG_CONF2_CNF7 from a register value.
#define BG_SDMAARM_XTRIG_CONF2_CNF7(r)   (((r) & BM_SDMAARM_XTRIG_CONF2_CNF7) >> BP_SDMAARM_XTRIG_CONF2_CNF7)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF7.
#define BF_SDMAARM_XTRIG_CONF2_CNF7(v)   ((((reg32_t) v) << BP_SDMAARM_XTRIG_CONF2_CNF7) & BM_SDMAARM_XTRIG_CONF2_CNF7)
#else
//! @brief Format value for bitfield SDMAARM_XTRIG_CONF2_CNF7.
#define BF_SDMAARM_XTRIG_CONF2_CNF7(v)   (((v) << BP_SDMAARM_XTRIG_CONF2_CNF7) & BM_SDMAARM_XTRIG_CONF2_CNF7)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CNF7 field to a new value.
#define BW_SDMAARM_XTRIG_CONF2_CNF7(v)   (HW_SDMAARM_XTRIG_CONF2_WR((HW_SDMAARM_XTRIG_CONF2_RD() & ~BM_SDMAARM_XTRIG_CONF2_CNF7) | BF_SDMAARM_XTRIG_CONF2_CNF7(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI0 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri0
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri0_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri0_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI0 register
 */
#define HW_SDMAARM_SDMA_CHNPRI0_ADDR      (REGS_SDMAARM_BASE + 0x100)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI0           (*(volatile hw_sdmaarm_sdma_chnpri0_t *) HW_SDMAARM_SDMA_CHNPRI0_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI0_RD()      (HW_SDMAARM_SDMA_CHNPRI0.U)
#define HW_SDMAARM_SDMA_CHNPRI0_WR(v)     (HW_SDMAARM_SDMA_CHNPRI0.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI0_SET(v)    (HW_SDMAARM_SDMA_CHNPRI0_WR(HW_SDMAARM_SDMA_CHNPRI0_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI0_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI0_WR(HW_SDMAARM_SDMA_CHNPRI0_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI0_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI0_WR(HW_SDMAARM_SDMA_CHNPRI0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI0 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI0, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI0_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI0_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI0_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI0_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI0_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI0_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI0_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI0_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI0_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI0_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI0_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI0_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI0_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI0_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI0_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI0_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI0_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI0_WR((HW_SDMAARM_SDMA_CHNPRI0_RD() & ~BM_SDMAARM_SDMA_CHNPRI0_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI0_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI1 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri1
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri1_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri1_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI1 register
 */
#define HW_SDMAARM_SDMA_CHNPRI1_ADDR      (REGS_SDMAARM_BASE + 0x104)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI1           (*(volatile hw_sdmaarm_sdma_chnpri1_t *) HW_SDMAARM_SDMA_CHNPRI1_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI1_RD()      (HW_SDMAARM_SDMA_CHNPRI1.U)
#define HW_SDMAARM_SDMA_CHNPRI1_WR(v)     (HW_SDMAARM_SDMA_CHNPRI1.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI1_SET(v)    (HW_SDMAARM_SDMA_CHNPRI1_WR(HW_SDMAARM_SDMA_CHNPRI1_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI1_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI1_WR(HW_SDMAARM_SDMA_CHNPRI1_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI1_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI1_WR(HW_SDMAARM_SDMA_CHNPRI1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI1 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI1, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI1_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI1_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI1_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI1_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI1_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI1_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI1_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI1_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI1_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI1_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI1_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI1_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI1_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI1_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI1_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI1_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI1_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI1_WR((HW_SDMAARM_SDMA_CHNPRI1_RD() & ~BM_SDMAARM_SDMA_CHNPRI1_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI1_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI2 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri2
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri2_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri2_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI2 register
 */
#define HW_SDMAARM_SDMA_CHNPRI2_ADDR      (REGS_SDMAARM_BASE + 0x108)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI2           (*(volatile hw_sdmaarm_sdma_chnpri2_t *) HW_SDMAARM_SDMA_CHNPRI2_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI2_RD()      (HW_SDMAARM_SDMA_CHNPRI2.U)
#define HW_SDMAARM_SDMA_CHNPRI2_WR(v)     (HW_SDMAARM_SDMA_CHNPRI2.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI2_SET(v)    (HW_SDMAARM_SDMA_CHNPRI2_WR(HW_SDMAARM_SDMA_CHNPRI2_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI2_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI2_WR(HW_SDMAARM_SDMA_CHNPRI2_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI2_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI2_WR(HW_SDMAARM_SDMA_CHNPRI2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI2 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI2, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI2_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI2_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI2_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI2_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI2_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI2_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI2_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI2_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI2_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI2_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI2_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI2_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI2_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI2_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI2_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI2_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI2_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI2_WR((HW_SDMAARM_SDMA_CHNPRI2_RD() & ~BM_SDMAARM_SDMA_CHNPRI2_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI2_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI3 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri3
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri3_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri3_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI3 register
 */
#define HW_SDMAARM_SDMA_CHNPRI3_ADDR      (REGS_SDMAARM_BASE + 0x10c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI3           (*(volatile hw_sdmaarm_sdma_chnpri3_t *) HW_SDMAARM_SDMA_CHNPRI3_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI3_RD()      (HW_SDMAARM_SDMA_CHNPRI3.U)
#define HW_SDMAARM_SDMA_CHNPRI3_WR(v)     (HW_SDMAARM_SDMA_CHNPRI3.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI3_SET(v)    (HW_SDMAARM_SDMA_CHNPRI3_WR(HW_SDMAARM_SDMA_CHNPRI3_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI3_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI3_WR(HW_SDMAARM_SDMA_CHNPRI3_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI3_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI3_WR(HW_SDMAARM_SDMA_CHNPRI3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI3 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI3, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI3_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI3_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI3_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI3_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI3_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI3_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI3_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI3_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI3_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI3_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI3_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI3_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI3_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI3_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI3_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI3_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI3_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI3_WR((HW_SDMAARM_SDMA_CHNPRI3_RD() & ~BM_SDMAARM_SDMA_CHNPRI3_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI3_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI4 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri4
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri4_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri4_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI4 register
 */
#define HW_SDMAARM_SDMA_CHNPRI4_ADDR      (REGS_SDMAARM_BASE + 0x110)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI4           (*(volatile hw_sdmaarm_sdma_chnpri4_t *) HW_SDMAARM_SDMA_CHNPRI4_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI4_RD()      (HW_SDMAARM_SDMA_CHNPRI4.U)
#define HW_SDMAARM_SDMA_CHNPRI4_WR(v)     (HW_SDMAARM_SDMA_CHNPRI4.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI4_SET(v)    (HW_SDMAARM_SDMA_CHNPRI4_WR(HW_SDMAARM_SDMA_CHNPRI4_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI4_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI4_WR(HW_SDMAARM_SDMA_CHNPRI4_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI4_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI4_WR(HW_SDMAARM_SDMA_CHNPRI4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI4 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI4, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI4_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI4_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI4_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI4_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI4_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI4_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI4_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI4_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI4_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI4_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI4_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI4_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI4_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI4_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI4_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI4_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI4_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI4_WR((HW_SDMAARM_SDMA_CHNPRI4_RD() & ~BM_SDMAARM_SDMA_CHNPRI4_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI4_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI5 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri5
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri5_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri5_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI5 register
 */
#define HW_SDMAARM_SDMA_CHNPRI5_ADDR      (REGS_SDMAARM_BASE + 0x114)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI5           (*(volatile hw_sdmaarm_sdma_chnpri5_t *) HW_SDMAARM_SDMA_CHNPRI5_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI5_RD()      (HW_SDMAARM_SDMA_CHNPRI5.U)
#define HW_SDMAARM_SDMA_CHNPRI5_WR(v)     (HW_SDMAARM_SDMA_CHNPRI5.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI5_SET(v)    (HW_SDMAARM_SDMA_CHNPRI5_WR(HW_SDMAARM_SDMA_CHNPRI5_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI5_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI5_WR(HW_SDMAARM_SDMA_CHNPRI5_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI5_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI5_WR(HW_SDMAARM_SDMA_CHNPRI5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI5 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI5, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI5_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI5_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI5_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI5_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI5_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI5_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI5_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI5_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI5_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI5_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI5_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI5_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI5_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI5_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI5_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI5_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI5_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI5_WR((HW_SDMAARM_SDMA_CHNPRI5_RD() & ~BM_SDMAARM_SDMA_CHNPRI5_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI5_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI6 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri6
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri6_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri6_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI6 register
 */
#define HW_SDMAARM_SDMA_CHNPRI6_ADDR      (REGS_SDMAARM_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI6           (*(volatile hw_sdmaarm_sdma_chnpri6_t *) HW_SDMAARM_SDMA_CHNPRI6_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI6_RD()      (HW_SDMAARM_SDMA_CHNPRI6.U)
#define HW_SDMAARM_SDMA_CHNPRI6_WR(v)     (HW_SDMAARM_SDMA_CHNPRI6.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI6_SET(v)    (HW_SDMAARM_SDMA_CHNPRI6_WR(HW_SDMAARM_SDMA_CHNPRI6_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI6_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI6_WR(HW_SDMAARM_SDMA_CHNPRI6_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI6_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI6_WR(HW_SDMAARM_SDMA_CHNPRI6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI6 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI6, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI6_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI6_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI6_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI6_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI6_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI6_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI6_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI6_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI6_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI6_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI6_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI6_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI6_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI6_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI6_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI6_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI6_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI6_WR((HW_SDMAARM_SDMA_CHNPRI6_RD() & ~BM_SDMAARM_SDMA_CHNPRI6_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI6_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI7 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri7
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri7_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri7_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI7 register
 */
#define HW_SDMAARM_SDMA_CHNPRI7_ADDR      (REGS_SDMAARM_BASE + 0x11c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI7           (*(volatile hw_sdmaarm_sdma_chnpri7_t *) HW_SDMAARM_SDMA_CHNPRI7_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI7_RD()      (HW_SDMAARM_SDMA_CHNPRI7.U)
#define HW_SDMAARM_SDMA_CHNPRI7_WR(v)     (HW_SDMAARM_SDMA_CHNPRI7.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI7_SET(v)    (HW_SDMAARM_SDMA_CHNPRI7_WR(HW_SDMAARM_SDMA_CHNPRI7_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI7_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI7_WR(HW_SDMAARM_SDMA_CHNPRI7_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI7_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI7_WR(HW_SDMAARM_SDMA_CHNPRI7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI7 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI7, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI7_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI7_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI7_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI7_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI7_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI7_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI7_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI7_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI7_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI7_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI7_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI7_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI7_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI7_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI7_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI7_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI7_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI7_WR((HW_SDMAARM_SDMA_CHNPRI7_RD() & ~BM_SDMAARM_SDMA_CHNPRI7_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI7_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI8 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri8
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri8_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri8_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI8 register
 */
#define HW_SDMAARM_SDMA_CHNPRI8_ADDR      (REGS_SDMAARM_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI8           (*(volatile hw_sdmaarm_sdma_chnpri8_t *) HW_SDMAARM_SDMA_CHNPRI8_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI8_RD()      (HW_SDMAARM_SDMA_CHNPRI8.U)
#define HW_SDMAARM_SDMA_CHNPRI8_WR(v)     (HW_SDMAARM_SDMA_CHNPRI8.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI8_SET(v)    (HW_SDMAARM_SDMA_CHNPRI8_WR(HW_SDMAARM_SDMA_CHNPRI8_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI8_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI8_WR(HW_SDMAARM_SDMA_CHNPRI8_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI8_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI8_WR(HW_SDMAARM_SDMA_CHNPRI8_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI8 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI8, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI8_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI8_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI8_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI8_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI8_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI8_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI8_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI8_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI8_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI8_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI8_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI8_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI8_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI8_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI8_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI8_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI8_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI8_WR((HW_SDMAARM_SDMA_CHNPRI8_RD() & ~BM_SDMAARM_SDMA_CHNPRI8_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI8_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI9 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri9
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri9_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri9_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI9 register
 */
#define HW_SDMAARM_SDMA_CHNPRI9_ADDR      (REGS_SDMAARM_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI9           (*(volatile hw_sdmaarm_sdma_chnpri9_t *) HW_SDMAARM_SDMA_CHNPRI9_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI9_RD()      (HW_SDMAARM_SDMA_CHNPRI9.U)
#define HW_SDMAARM_SDMA_CHNPRI9_WR(v)     (HW_SDMAARM_SDMA_CHNPRI9.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI9_SET(v)    (HW_SDMAARM_SDMA_CHNPRI9_WR(HW_SDMAARM_SDMA_CHNPRI9_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI9_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI9_WR(HW_SDMAARM_SDMA_CHNPRI9_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI9_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI9_WR(HW_SDMAARM_SDMA_CHNPRI9_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI9 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI9, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI9_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI9_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI9_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI9_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI9_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI9_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI9_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI9_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI9_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI9_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI9_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI9_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI9_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI9_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI9_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI9_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI9_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI9_WR((HW_SDMAARM_SDMA_CHNPRI9_RD() & ~BM_SDMAARM_SDMA_CHNPRI9_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI9_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI10 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri10
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri10_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri10_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI10 register
 */
#define HW_SDMAARM_SDMA_CHNPRI10_ADDR      (REGS_SDMAARM_BASE + 0x128)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI10           (*(volatile hw_sdmaarm_sdma_chnpri10_t *) HW_SDMAARM_SDMA_CHNPRI10_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI10_RD()      (HW_SDMAARM_SDMA_CHNPRI10.U)
#define HW_SDMAARM_SDMA_CHNPRI10_WR(v)     (HW_SDMAARM_SDMA_CHNPRI10.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI10_SET(v)    (HW_SDMAARM_SDMA_CHNPRI10_WR(HW_SDMAARM_SDMA_CHNPRI10_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI10_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI10_WR(HW_SDMAARM_SDMA_CHNPRI10_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI10_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI10_WR(HW_SDMAARM_SDMA_CHNPRI10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI10 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI10, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI10_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI10_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI10_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI10_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI10_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI10_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI10_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI10_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI10_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI10_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI10_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI10_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI10_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI10_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI10_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI10_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI10_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI10_WR((HW_SDMAARM_SDMA_CHNPRI10_RD() & ~BM_SDMAARM_SDMA_CHNPRI10_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI10_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI11 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri11
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri11_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri11_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI11 register
 */
#define HW_SDMAARM_SDMA_CHNPRI11_ADDR      (REGS_SDMAARM_BASE + 0x12c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI11           (*(volatile hw_sdmaarm_sdma_chnpri11_t *) HW_SDMAARM_SDMA_CHNPRI11_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI11_RD()      (HW_SDMAARM_SDMA_CHNPRI11.U)
#define HW_SDMAARM_SDMA_CHNPRI11_WR(v)     (HW_SDMAARM_SDMA_CHNPRI11.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI11_SET(v)    (HW_SDMAARM_SDMA_CHNPRI11_WR(HW_SDMAARM_SDMA_CHNPRI11_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI11_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI11_WR(HW_SDMAARM_SDMA_CHNPRI11_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI11_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI11_WR(HW_SDMAARM_SDMA_CHNPRI11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI11 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI11, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI11_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI11_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI11_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI11_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI11_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI11_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI11_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI11_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI11_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI11_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI11_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI11_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI11_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI11_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI11_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI11_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI11_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI11_WR((HW_SDMAARM_SDMA_CHNPRI11_RD() & ~BM_SDMAARM_SDMA_CHNPRI11_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI11_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI12 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri12
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri12_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri12_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI12 register
 */
#define HW_SDMAARM_SDMA_CHNPRI12_ADDR      (REGS_SDMAARM_BASE + 0x130)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI12           (*(volatile hw_sdmaarm_sdma_chnpri12_t *) HW_SDMAARM_SDMA_CHNPRI12_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI12_RD()      (HW_SDMAARM_SDMA_CHNPRI12.U)
#define HW_SDMAARM_SDMA_CHNPRI12_WR(v)     (HW_SDMAARM_SDMA_CHNPRI12.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI12_SET(v)    (HW_SDMAARM_SDMA_CHNPRI12_WR(HW_SDMAARM_SDMA_CHNPRI12_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI12_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI12_WR(HW_SDMAARM_SDMA_CHNPRI12_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI12_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI12_WR(HW_SDMAARM_SDMA_CHNPRI12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI12 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI12, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI12_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI12_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI12_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI12_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI12_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI12_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI12_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI12_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI12_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI12_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI12_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI12_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI12_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI12_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI12_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI12_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI12_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI12_WR((HW_SDMAARM_SDMA_CHNPRI12_RD() & ~BM_SDMAARM_SDMA_CHNPRI12_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI12_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI13 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri13
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri13_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri13_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI13 register
 */
#define HW_SDMAARM_SDMA_CHNPRI13_ADDR      (REGS_SDMAARM_BASE + 0x134)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI13           (*(volatile hw_sdmaarm_sdma_chnpri13_t *) HW_SDMAARM_SDMA_CHNPRI13_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI13_RD()      (HW_SDMAARM_SDMA_CHNPRI13.U)
#define HW_SDMAARM_SDMA_CHNPRI13_WR(v)     (HW_SDMAARM_SDMA_CHNPRI13.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI13_SET(v)    (HW_SDMAARM_SDMA_CHNPRI13_WR(HW_SDMAARM_SDMA_CHNPRI13_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI13_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI13_WR(HW_SDMAARM_SDMA_CHNPRI13_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI13_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI13_WR(HW_SDMAARM_SDMA_CHNPRI13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI13 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI13, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI13_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI13_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI13_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI13_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI13_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI13_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI13_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI13_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI13_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI13_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI13_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI13_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI13_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI13_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI13_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI13_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI13_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI13_WR((HW_SDMAARM_SDMA_CHNPRI13_RD() & ~BM_SDMAARM_SDMA_CHNPRI13_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI13_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI14 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri14
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri14_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri14_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI14 register
 */
#define HW_SDMAARM_SDMA_CHNPRI14_ADDR      (REGS_SDMAARM_BASE + 0x138)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI14           (*(volatile hw_sdmaarm_sdma_chnpri14_t *) HW_SDMAARM_SDMA_CHNPRI14_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI14_RD()      (HW_SDMAARM_SDMA_CHNPRI14.U)
#define HW_SDMAARM_SDMA_CHNPRI14_WR(v)     (HW_SDMAARM_SDMA_CHNPRI14.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI14_SET(v)    (HW_SDMAARM_SDMA_CHNPRI14_WR(HW_SDMAARM_SDMA_CHNPRI14_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI14_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI14_WR(HW_SDMAARM_SDMA_CHNPRI14_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI14_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI14_WR(HW_SDMAARM_SDMA_CHNPRI14_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI14 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI14, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI14_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI14_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI14_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI14_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI14_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI14_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI14_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI14_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI14_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI14_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI14_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI14_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI14_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI14_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI14_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI14_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI14_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI14_WR((HW_SDMAARM_SDMA_CHNPRI14_RD() & ~BM_SDMAARM_SDMA_CHNPRI14_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI14_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI15 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri15
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri15_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri15_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI15 register
 */
#define HW_SDMAARM_SDMA_CHNPRI15_ADDR      (REGS_SDMAARM_BASE + 0x13c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI15           (*(volatile hw_sdmaarm_sdma_chnpri15_t *) HW_SDMAARM_SDMA_CHNPRI15_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI15_RD()      (HW_SDMAARM_SDMA_CHNPRI15.U)
#define HW_SDMAARM_SDMA_CHNPRI15_WR(v)     (HW_SDMAARM_SDMA_CHNPRI15.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI15_SET(v)    (HW_SDMAARM_SDMA_CHNPRI15_WR(HW_SDMAARM_SDMA_CHNPRI15_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI15_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI15_WR(HW_SDMAARM_SDMA_CHNPRI15_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI15_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI15_WR(HW_SDMAARM_SDMA_CHNPRI15_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI15 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI15, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI15_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI15_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI15_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI15_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI15_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI15_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI15_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI15_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI15_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI15_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI15_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI15_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI15_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI15_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI15_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI15_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI15_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI15_WR((HW_SDMAARM_SDMA_CHNPRI15_RD() & ~BM_SDMAARM_SDMA_CHNPRI15_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI15_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI16 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri16
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri16_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri16_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI16 register
 */
#define HW_SDMAARM_SDMA_CHNPRI16_ADDR      (REGS_SDMAARM_BASE + 0x140)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI16           (*(volatile hw_sdmaarm_sdma_chnpri16_t *) HW_SDMAARM_SDMA_CHNPRI16_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI16_RD()      (HW_SDMAARM_SDMA_CHNPRI16.U)
#define HW_SDMAARM_SDMA_CHNPRI16_WR(v)     (HW_SDMAARM_SDMA_CHNPRI16.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI16_SET(v)    (HW_SDMAARM_SDMA_CHNPRI16_WR(HW_SDMAARM_SDMA_CHNPRI16_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI16_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI16_WR(HW_SDMAARM_SDMA_CHNPRI16_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI16_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI16_WR(HW_SDMAARM_SDMA_CHNPRI16_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI16 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI16, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI16_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI16_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI16_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI16_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI16_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI16_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI16_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI16_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI16_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI16_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI16_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI16_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI16_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI16_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI16_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI16_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI16_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI16_WR((HW_SDMAARM_SDMA_CHNPRI16_RD() & ~BM_SDMAARM_SDMA_CHNPRI16_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI16_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI17 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri17
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri17_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri17_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI17 register
 */
#define HW_SDMAARM_SDMA_CHNPRI17_ADDR      (REGS_SDMAARM_BASE + 0x144)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI17           (*(volatile hw_sdmaarm_sdma_chnpri17_t *) HW_SDMAARM_SDMA_CHNPRI17_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI17_RD()      (HW_SDMAARM_SDMA_CHNPRI17.U)
#define HW_SDMAARM_SDMA_CHNPRI17_WR(v)     (HW_SDMAARM_SDMA_CHNPRI17.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI17_SET(v)    (HW_SDMAARM_SDMA_CHNPRI17_WR(HW_SDMAARM_SDMA_CHNPRI17_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI17_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI17_WR(HW_SDMAARM_SDMA_CHNPRI17_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI17_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI17_WR(HW_SDMAARM_SDMA_CHNPRI17_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI17 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI17, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI17_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI17_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI17_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI17_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI17_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI17_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI17_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI17_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI17_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI17_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI17_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI17_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI17_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI17_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI17_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI17_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI17_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI17_WR((HW_SDMAARM_SDMA_CHNPRI17_RD() & ~BM_SDMAARM_SDMA_CHNPRI17_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI17_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI18 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri18
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri18_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri18_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI18 register
 */
#define HW_SDMAARM_SDMA_CHNPRI18_ADDR      (REGS_SDMAARM_BASE + 0x148)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI18           (*(volatile hw_sdmaarm_sdma_chnpri18_t *) HW_SDMAARM_SDMA_CHNPRI18_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI18_RD()      (HW_SDMAARM_SDMA_CHNPRI18.U)
#define HW_SDMAARM_SDMA_CHNPRI18_WR(v)     (HW_SDMAARM_SDMA_CHNPRI18.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI18_SET(v)    (HW_SDMAARM_SDMA_CHNPRI18_WR(HW_SDMAARM_SDMA_CHNPRI18_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI18_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI18_WR(HW_SDMAARM_SDMA_CHNPRI18_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI18_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI18_WR(HW_SDMAARM_SDMA_CHNPRI18_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI18 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI18, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI18_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI18_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI18_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI18_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI18_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI18_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI18_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI18_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI18_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI18_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI18_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI18_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI18_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI18_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI18_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI18_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI18_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI18_WR((HW_SDMAARM_SDMA_CHNPRI18_RD() & ~BM_SDMAARM_SDMA_CHNPRI18_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI18_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI19 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri19
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri19_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri19_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI19 register
 */
#define HW_SDMAARM_SDMA_CHNPRI19_ADDR      (REGS_SDMAARM_BASE + 0x14c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI19           (*(volatile hw_sdmaarm_sdma_chnpri19_t *) HW_SDMAARM_SDMA_CHNPRI19_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI19_RD()      (HW_SDMAARM_SDMA_CHNPRI19.U)
#define HW_SDMAARM_SDMA_CHNPRI19_WR(v)     (HW_SDMAARM_SDMA_CHNPRI19.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI19_SET(v)    (HW_SDMAARM_SDMA_CHNPRI19_WR(HW_SDMAARM_SDMA_CHNPRI19_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI19_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI19_WR(HW_SDMAARM_SDMA_CHNPRI19_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI19_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI19_WR(HW_SDMAARM_SDMA_CHNPRI19_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI19 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI19, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI19_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI19_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI19_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI19_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI19_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI19_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI19_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI19_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI19_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI19_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI19_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI19_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI19_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI19_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI19_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI19_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI19_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI19_WR((HW_SDMAARM_SDMA_CHNPRI19_RD() & ~BM_SDMAARM_SDMA_CHNPRI19_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI19_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI20 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri20
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri20_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri20_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI20 register
 */
#define HW_SDMAARM_SDMA_CHNPRI20_ADDR      (REGS_SDMAARM_BASE + 0x150)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI20           (*(volatile hw_sdmaarm_sdma_chnpri20_t *) HW_SDMAARM_SDMA_CHNPRI20_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI20_RD()      (HW_SDMAARM_SDMA_CHNPRI20.U)
#define HW_SDMAARM_SDMA_CHNPRI20_WR(v)     (HW_SDMAARM_SDMA_CHNPRI20.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI20_SET(v)    (HW_SDMAARM_SDMA_CHNPRI20_WR(HW_SDMAARM_SDMA_CHNPRI20_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI20_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI20_WR(HW_SDMAARM_SDMA_CHNPRI20_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI20_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI20_WR(HW_SDMAARM_SDMA_CHNPRI20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI20 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI20, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI20_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI20_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI20_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI20_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI20_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI20_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI20_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI20_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI20_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI20_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI20_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI20_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI20_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI20_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI20_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI20_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI20_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI20_WR((HW_SDMAARM_SDMA_CHNPRI20_RD() & ~BM_SDMAARM_SDMA_CHNPRI20_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI20_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI21 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri21
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri21_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri21_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI21 register
 */
#define HW_SDMAARM_SDMA_CHNPRI21_ADDR      (REGS_SDMAARM_BASE + 0x154)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI21           (*(volatile hw_sdmaarm_sdma_chnpri21_t *) HW_SDMAARM_SDMA_CHNPRI21_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI21_RD()      (HW_SDMAARM_SDMA_CHNPRI21.U)
#define HW_SDMAARM_SDMA_CHNPRI21_WR(v)     (HW_SDMAARM_SDMA_CHNPRI21.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI21_SET(v)    (HW_SDMAARM_SDMA_CHNPRI21_WR(HW_SDMAARM_SDMA_CHNPRI21_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI21_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI21_WR(HW_SDMAARM_SDMA_CHNPRI21_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI21_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI21_WR(HW_SDMAARM_SDMA_CHNPRI21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI21 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI21, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI21_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI21_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI21_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI21_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI21_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI21_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI21_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI21_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI21_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI21_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI21_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI21_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI21_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI21_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI21_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI21_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI21_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI21_WR((HW_SDMAARM_SDMA_CHNPRI21_RD() & ~BM_SDMAARM_SDMA_CHNPRI21_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI21_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI22 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri22
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri22_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri22_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI22 register
 */
#define HW_SDMAARM_SDMA_CHNPRI22_ADDR      (REGS_SDMAARM_BASE + 0x158)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI22           (*(volatile hw_sdmaarm_sdma_chnpri22_t *) HW_SDMAARM_SDMA_CHNPRI22_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI22_RD()      (HW_SDMAARM_SDMA_CHNPRI22.U)
#define HW_SDMAARM_SDMA_CHNPRI22_WR(v)     (HW_SDMAARM_SDMA_CHNPRI22.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI22_SET(v)    (HW_SDMAARM_SDMA_CHNPRI22_WR(HW_SDMAARM_SDMA_CHNPRI22_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI22_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI22_WR(HW_SDMAARM_SDMA_CHNPRI22_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI22_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI22_WR(HW_SDMAARM_SDMA_CHNPRI22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI22 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI22, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI22_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI22_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI22_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI22_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI22_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI22_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI22_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI22_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI22_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI22_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI22_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI22_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI22_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI22_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI22_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI22_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI22_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI22_WR((HW_SDMAARM_SDMA_CHNPRI22_RD() & ~BM_SDMAARM_SDMA_CHNPRI22_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI22_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI23 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri23
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri23_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri23_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI23 register
 */
#define HW_SDMAARM_SDMA_CHNPRI23_ADDR      (REGS_SDMAARM_BASE + 0x15c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI23           (*(volatile hw_sdmaarm_sdma_chnpri23_t *) HW_SDMAARM_SDMA_CHNPRI23_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI23_RD()      (HW_SDMAARM_SDMA_CHNPRI23.U)
#define HW_SDMAARM_SDMA_CHNPRI23_WR(v)     (HW_SDMAARM_SDMA_CHNPRI23.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI23_SET(v)    (HW_SDMAARM_SDMA_CHNPRI23_WR(HW_SDMAARM_SDMA_CHNPRI23_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI23_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI23_WR(HW_SDMAARM_SDMA_CHNPRI23_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI23_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI23_WR(HW_SDMAARM_SDMA_CHNPRI23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI23 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI23, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI23_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI23_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI23_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI23_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI23_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI23_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI23_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI23_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI23_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI23_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI23_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI23_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI23_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI23_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI23_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI23_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI23_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI23_WR((HW_SDMAARM_SDMA_CHNPRI23_RD() & ~BM_SDMAARM_SDMA_CHNPRI23_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI23_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI24 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri24
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri24_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri24_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI24 register
 */
#define HW_SDMAARM_SDMA_CHNPRI24_ADDR      (REGS_SDMAARM_BASE + 0x160)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI24           (*(volatile hw_sdmaarm_sdma_chnpri24_t *) HW_SDMAARM_SDMA_CHNPRI24_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI24_RD()      (HW_SDMAARM_SDMA_CHNPRI24.U)
#define HW_SDMAARM_SDMA_CHNPRI24_WR(v)     (HW_SDMAARM_SDMA_CHNPRI24.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI24_SET(v)    (HW_SDMAARM_SDMA_CHNPRI24_WR(HW_SDMAARM_SDMA_CHNPRI24_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI24_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI24_WR(HW_SDMAARM_SDMA_CHNPRI24_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI24_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI24_WR(HW_SDMAARM_SDMA_CHNPRI24_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI24 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI24, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI24_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI24_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI24_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI24_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI24_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI24_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI24_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI24_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI24_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI24_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI24_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI24_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI24_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI24_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI24_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI24_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI24_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI24_WR((HW_SDMAARM_SDMA_CHNPRI24_RD() & ~BM_SDMAARM_SDMA_CHNPRI24_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI24_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI25 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri25
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri25_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri25_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI25 register
 */
#define HW_SDMAARM_SDMA_CHNPRI25_ADDR      (REGS_SDMAARM_BASE + 0x164)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI25           (*(volatile hw_sdmaarm_sdma_chnpri25_t *) HW_SDMAARM_SDMA_CHNPRI25_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI25_RD()      (HW_SDMAARM_SDMA_CHNPRI25.U)
#define HW_SDMAARM_SDMA_CHNPRI25_WR(v)     (HW_SDMAARM_SDMA_CHNPRI25.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI25_SET(v)    (HW_SDMAARM_SDMA_CHNPRI25_WR(HW_SDMAARM_SDMA_CHNPRI25_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI25_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI25_WR(HW_SDMAARM_SDMA_CHNPRI25_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI25_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI25_WR(HW_SDMAARM_SDMA_CHNPRI25_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI25 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI25, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI25_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI25_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI25_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI25_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI25_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI25_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI25_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI25_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI25_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI25_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI25_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI25_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI25_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI25_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI25_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI25_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI25_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI25_WR((HW_SDMAARM_SDMA_CHNPRI25_RD() & ~BM_SDMAARM_SDMA_CHNPRI25_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI25_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI26 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri26
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri26_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri26_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI26 register
 */
#define HW_SDMAARM_SDMA_CHNPRI26_ADDR      (REGS_SDMAARM_BASE + 0x168)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI26           (*(volatile hw_sdmaarm_sdma_chnpri26_t *) HW_SDMAARM_SDMA_CHNPRI26_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI26_RD()      (HW_SDMAARM_SDMA_CHNPRI26.U)
#define HW_SDMAARM_SDMA_CHNPRI26_WR(v)     (HW_SDMAARM_SDMA_CHNPRI26.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI26_SET(v)    (HW_SDMAARM_SDMA_CHNPRI26_WR(HW_SDMAARM_SDMA_CHNPRI26_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI26_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI26_WR(HW_SDMAARM_SDMA_CHNPRI26_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI26_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI26_WR(HW_SDMAARM_SDMA_CHNPRI26_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI26 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI26, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI26_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI26_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI26_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI26_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI26_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI26_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI26_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI26_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI26_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI26_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI26_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI26_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI26_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI26_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI26_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI26_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI26_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI26_WR((HW_SDMAARM_SDMA_CHNPRI26_RD() & ~BM_SDMAARM_SDMA_CHNPRI26_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI26_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI27 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri27
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri27_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri27_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI27 register
 */
#define HW_SDMAARM_SDMA_CHNPRI27_ADDR      (REGS_SDMAARM_BASE + 0x16c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI27           (*(volatile hw_sdmaarm_sdma_chnpri27_t *) HW_SDMAARM_SDMA_CHNPRI27_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI27_RD()      (HW_SDMAARM_SDMA_CHNPRI27.U)
#define HW_SDMAARM_SDMA_CHNPRI27_WR(v)     (HW_SDMAARM_SDMA_CHNPRI27.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI27_SET(v)    (HW_SDMAARM_SDMA_CHNPRI27_WR(HW_SDMAARM_SDMA_CHNPRI27_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI27_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI27_WR(HW_SDMAARM_SDMA_CHNPRI27_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI27_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI27_WR(HW_SDMAARM_SDMA_CHNPRI27_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI27 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI27, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI27_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI27_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI27_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI27_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI27_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI27_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI27_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI27_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI27_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI27_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI27_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI27_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI27_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI27_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI27_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI27_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI27_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI27_WR((HW_SDMAARM_SDMA_CHNPRI27_RD() & ~BM_SDMAARM_SDMA_CHNPRI27_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI27_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI28 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri28
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri28_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri28_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI28 register
 */
#define HW_SDMAARM_SDMA_CHNPRI28_ADDR      (REGS_SDMAARM_BASE + 0x170)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI28           (*(volatile hw_sdmaarm_sdma_chnpri28_t *) HW_SDMAARM_SDMA_CHNPRI28_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI28_RD()      (HW_SDMAARM_SDMA_CHNPRI28.U)
#define HW_SDMAARM_SDMA_CHNPRI28_WR(v)     (HW_SDMAARM_SDMA_CHNPRI28.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI28_SET(v)    (HW_SDMAARM_SDMA_CHNPRI28_WR(HW_SDMAARM_SDMA_CHNPRI28_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI28_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI28_WR(HW_SDMAARM_SDMA_CHNPRI28_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI28_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI28_WR(HW_SDMAARM_SDMA_CHNPRI28_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI28 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI28, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI28_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI28_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI28_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI28_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI28_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI28_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI28_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI28_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI28_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI28_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI28_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI28_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI28_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI28_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI28_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI28_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI28_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI28_WR((HW_SDMAARM_SDMA_CHNPRI28_RD() & ~BM_SDMAARM_SDMA_CHNPRI28_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI28_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI29 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri29
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri29_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri29_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI29 register
 */
#define HW_SDMAARM_SDMA_CHNPRI29_ADDR      (REGS_SDMAARM_BASE + 0x174)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI29           (*(volatile hw_sdmaarm_sdma_chnpri29_t *) HW_SDMAARM_SDMA_CHNPRI29_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI29_RD()      (HW_SDMAARM_SDMA_CHNPRI29.U)
#define HW_SDMAARM_SDMA_CHNPRI29_WR(v)     (HW_SDMAARM_SDMA_CHNPRI29.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI29_SET(v)    (HW_SDMAARM_SDMA_CHNPRI29_WR(HW_SDMAARM_SDMA_CHNPRI29_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI29_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI29_WR(HW_SDMAARM_SDMA_CHNPRI29_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI29_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI29_WR(HW_SDMAARM_SDMA_CHNPRI29_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI29 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI29, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI29_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI29_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI29_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI29_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI29_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI29_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI29_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI29_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI29_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI29_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI29_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI29_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI29_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI29_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI29_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI29_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI29_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI29_WR((HW_SDMAARM_SDMA_CHNPRI29_RD() & ~BM_SDMAARM_SDMA_CHNPRI29_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI29_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI30 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri30
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri30_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri30_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI30 register
 */
#define HW_SDMAARM_SDMA_CHNPRI30_ADDR      (REGS_SDMAARM_BASE + 0x178)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI30           (*(volatile hw_sdmaarm_sdma_chnpri30_t *) HW_SDMAARM_SDMA_CHNPRI30_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI30_RD()      (HW_SDMAARM_SDMA_CHNPRI30.U)
#define HW_SDMAARM_SDMA_CHNPRI30_WR(v)     (HW_SDMAARM_SDMA_CHNPRI30.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI30_SET(v)    (HW_SDMAARM_SDMA_CHNPRI30_WR(HW_SDMAARM_SDMA_CHNPRI30_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI30_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI30_WR(HW_SDMAARM_SDMA_CHNPRI30_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI30_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI30_WR(HW_SDMAARM_SDMA_CHNPRI30_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI30 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI30, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI30_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI30_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI30_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI30_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI30_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI30_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI30_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI30_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI30_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI30_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI30_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI30_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI30_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI30_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI30_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI30_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI30_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI30_WR((HW_SDMAARM_SDMA_CHNPRI30_RD() & ~BM_SDMAARM_SDMA_CHNPRI30_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI30_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNPRI31 - Channel Priority Registers (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnpri31
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnpri31_bitfields
    {
        unsigned CHNPRIN : 3; //!< [2:0] This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which prevents the channels from starting.
        unsigned RESERVED0 : 29; //!< [31:3] Reserved
    } B;
} hw_sdmaarm_sdma_chnpri31_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNPRI31 register
 */
#define HW_SDMAARM_SDMA_CHNPRI31_ADDR      (REGS_SDMAARM_BASE + 0x17c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNPRI31           (*(volatile hw_sdmaarm_sdma_chnpri31_t *) HW_SDMAARM_SDMA_CHNPRI31_ADDR)
#define HW_SDMAARM_SDMA_CHNPRI31_RD()      (HW_SDMAARM_SDMA_CHNPRI31.U)
#define HW_SDMAARM_SDMA_CHNPRI31_WR(v)     (HW_SDMAARM_SDMA_CHNPRI31.U = (v))
#define HW_SDMAARM_SDMA_CHNPRI31_SET(v)    (HW_SDMAARM_SDMA_CHNPRI31_WR(HW_SDMAARM_SDMA_CHNPRI31_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNPRI31_CLR(v)    (HW_SDMAARM_SDMA_CHNPRI31_WR(HW_SDMAARM_SDMA_CHNPRI31_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNPRI31_TOG(v)    (HW_SDMAARM_SDMA_CHNPRI31_WR(HW_SDMAARM_SDMA_CHNPRI31_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNPRI31 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNPRI31, field CHNPRIN[2:0] (RW)
 *
 * This contains the priority of channel number n . Useful values are between 1 and 7; 0 is reserved
 * by the SDMA hardware to determine when there is no pending channel. Reset value is 0, which
 * prevents the channels from starting.
 */

#define BP_SDMAARM_SDMA_CHNPRI31_CHNPRIN      (0)      //!< Bit position for SDMAARM_SDMA_CHNPRI31_CHNPRIN.
#define BM_SDMAARM_SDMA_CHNPRI31_CHNPRIN      (0x00000007)  //!< Bit mask for SDMAARM_SDMA_CHNPRI31_CHNPRIN.

//! @brief Get value of SDMAARM_SDMA_CHNPRI31_CHNPRIN from a register value.
#define BG_SDMAARM_SDMA_CHNPRI31_CHNPRIN(r)   (((r) & BM_SDMAARM_SDMA_CHNPRI31_CHNPRIN) >> BP_SDMAARM_SDMA_CHNPRI31_CHNPRIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI31_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI31_CHNPRIN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNPRI31_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI31_CHNPRIN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNPRI31_CHNPRIN.
#define BF_SDMAARM_SDMA_CHNPRI31_CHNPRIN(v)   (((v) << BP_SDMAARM_SDMA_CHNPRI31_CHNPRIN) & BM_SDMAARM_SDMA_CHNPRI31_CHNPRIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CHNPRIN field to a new value.
#define BW_SDMAARM_SDMA_CHNPRI31_CHNPRIN(v)   (HW_SDMAARM_SDMA_CHNPRI31_WR((HW_SDMAARM_SDMA_CHNPRI31_RD() & ~BM_SDMAARM_SDMA_CHNPRI31_CHNPRIN) | BF_SDMAARM_SDMA_CHNPRI31_CHNPRIN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL0 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl0
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl0_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl0_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL0 register
 */
#define HW_SDMAARM_SDMA_CHNENBL0_ADDR      (REGS_SDMAARM_BASE + 0x200)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL0           (*(volatile hw_sdmaarm_sdma_chnenbl0_t *) HW_SDMAARM_SDMA_CHNENBL0_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL0_RD()      (HW_SDMAARM_SDMA_CHNENBL0.U)
#define HW_SDMAARM_SDMA_CHNENBL0_WR(v)     (HW_SDMAARM_SDMA_CHNENBL0.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL0_SET(v)    (HW_SDMAARM_SDMA_CHNENBL0_WR(HW_SDMAARM_SDMA_CHNENBL0_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL0_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL0_WR(HW_SDMAARM_SDMA_CHNENBL0_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL0_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL0_WR(HW_SDMAARM_SDMA_CHNENBL0_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL0 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL0, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL0_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL0_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL0_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL0_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL0_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL0_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL0_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL0_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL0_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL0_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL0_ENBLN) & BM_SDMAARM_SDMA_CHNENBL0_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL0_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL0_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL0_ENBLN) & BM_SDMAARM_SDMA_CHNENBL0_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL0_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL0_WR((HW_SDMAARM_SDMA_CHNENBL0_RD() & ~BM_SDMAARM_SDMA_CHNENBL0_ENBLN) | BF_SDMAARM_SDMA_CHNENBL0_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL1 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl1
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl1_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl1_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL1 register
 */
#define HW_SDMAARM_SDMA_CHNENBL1_ADDR      (REGS_SDMAARM_BASE + 0x204)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL1           (*(volatile hw_sdmaarm_sdma_chnenbl1_t *) HW_SDMAARM_SDMA_CHNENBL1_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL1_RD()      (HW_SDMAARM_SDMA_CHNENBL1.U)
#define HW_SDMAARM_SDMA_CHNENBL1_WR(v)     (HW_SDMAARM_SDMA_CHNENBL1.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL1_SET(v)    (HW_SDMAARM_SDMA_CHNENBL1_WR(HW_SDMAARM_SDMA_CHNENBL1_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL1_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL1_WR(HW_SDMAARM_SDMA_CHNENBL1_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL1_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL1_WR(HW_SDMAARM_SDMA_CHNENBL1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL1 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL1, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL1_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL1_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL1_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL1_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL1_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL1_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL1_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL1_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL1_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL1_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL1_ENBLN) & BM_SDMAARM_SDMA_CHNENBL1_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL1_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL1_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL1_ENBLN) & BM_SDMAARM_SDMA_CHNENBL1_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL1_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL1_WR((HW_SDMAARM_SDMA_CHNENBL1_RD() & ~BM_SDMAARM_SDMA_CHNENBL1_ENBLN) | BF_SDMAARM_SDMA_CHNENBL1_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL2 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl2
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl2_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl2_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL2 register
 */
#define HW_SDMAARM_SDMA_CHNENBL2_ADDR      (REGS_SDMAARM_BASE + 0x208)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL2           (*(volatile hw_sdmaarm_sdma_chnenbl2_t *) HW_SDMAARM_SDMA_CHNENBL2_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL2_RD()      (HW_SDMAARM_SDMA_CHNENBL2.U)
#define HW_SDMAARM_SDMA_CHNENBL2_WR(v)     (HW_SDMAARM_SDMA_CHNENBL2.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL2_SET(v)    (HW_SDMAARM_SDMA_CHNENBL2_WR(HW_SDMAARM_SDMA_CHNENBL2_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL2_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL2_WR(HW_SDMAARM_SDMA_CHNENBL2_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL2_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL2_WR(HW_SDMAARM_SDMA_CHNENBL2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL2 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL2, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL2_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL2_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL2_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL2_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL2_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL2_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL2_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL2_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL2_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL2_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL2_ENBLN) & BM_SDMAARM_SDMA_CHNENBL2_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL2_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL2_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL2_ENBLN) & BM_SDMAARM_SDMA_CHNENBL2_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL2_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL2_WR((HW_SDMAARM_SDMA_CHNENBL2_RD() & ~BM_SDMAARM_SDMA_CHNENBL2_ENBLN) | BF_SDMAARM_SDMA_CHNENBL2_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL3 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl3
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl3_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl3_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL3 register
 */
#define HW_SDMAARM_SDMA_CHNENBL3_ADDR      (REGS_SDMAARM_BASE + 0x20c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL3           (*(volatile hw_sdmaarm_sdma_chnenbl3_t *) HW_SDMAARM_SDMA_CHNENBL3_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL3_RD()      (HW_SDMAARM_SDMA_CHNENBL3.U)
#define HW_SDMAARM_SDMA_CHNENBL3_WR(v)     (HW_SDMAARM_SDMA_CHNENBL3.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL3_SET(v)    (HW_SDMAARM_SDMA_CHNENBL3_WR(HW_SDMAARM_SDMA_CHNENBL3_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL3_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL3_WR(HW_SDMAARM_SDMA_CHNENBL3_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL3_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL3_WR(HW_SDMAARM_SDMA_CHNENBL3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL3 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL3, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL3_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL3_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL3_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL3_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL3_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL3_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL3_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL3_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL3_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL3_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL3_ENBLN) & BM_SDMAARM_SDMA_CHNENBL3_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL3_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL3_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL3_ENBLN) & BM_SDMAARM_SDMA_CHNENBL3_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL3_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL3_WR((HW_SDMAARM_SDMA_CHNENBL3_RD() & ~BM_SDMAARM_SDMA_CHNENBL3_ENBLN) | BF_SDMAARM_SDMA_CHNENBL3_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL4 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl4
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl4_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl4_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL4 register
 */
#define HW_SDMAARM_SDMA_CHNENBL4_ADDR      (REGS_SDMAARM_BASE + 0x210)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL4           (*(volatile hw_sdmaarm_sdma_chnenbl4_t *) HW_SDMAARM_SDMA_CHNENBL4_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL4_RD()      (HW_SDMAARM_SDMA_CHNENBL4.U)
#define HW_SDMAARM_SDMA_CHNENBL4_WR(v)     (HW_SDMAARM_SDMA_CHNENBL4.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL4_SET(v)    (HW_SDMAARM_SDMA_CHNENBL4_WR(HW_SDMAARM_SDMA_CHNENBL4_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL4_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL4_WR(HW_SDMAARM_SDMA_CHNENBL4_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL4_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL4_WR(HW_SDMAARM_SDMA_CHNENBL4_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL4 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL4, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL4_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL4_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL4_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL4_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL4_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL4_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL4_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL4_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL4_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL4_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL4_ENBLN) & BM_SDMAARM_SDMA_CHNENBL4_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL4_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL4_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL4_ENBLN) & BM_SDMAARM_SDMA_CHNENBL4_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL4_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL4_WR((HW_SDMAARM_SDMA_CHNENBL4_RD() & ~BM_SDMAARM_SDMA_CHNENBL4_ENBLN) | BF_SDMAARM_SDMA_CHNENBL4_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL5 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl5
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl5_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl5_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL5 register
 */
#define HW_SDMAARM_SDMA_CHNENBL5_ADDR      (REGS_SDMAARM_BASE + 0x214)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL5           (*(volatile hw_sdmaarm_sdma_chnenbl5_t *) HW_SDMAARM_SDMA_CHNENBL5_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL5_RD()      (HW_SDMAARM_SDMA_CHNENBL5.U)
#define HW_SDMAARM_SDMA_CHNENBL5_WR(v)     (HW_SDMAARM_SDMA_CHNENBL5.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL5_SET(v)    (HW_SDMAARM_SDMA_CHNENBL5_WR(HW_SDMAARM_SDMA_CHNENBL5_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL5_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL5_WR(HW_SDMAARM_SDMA_CHNENBL5_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL5_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL5_WR(HW_SDMAARM_SDMA_CHNENBL5_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL5 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL5, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL5_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL5_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL5_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL5_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL5_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL5_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL5_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL5_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL5_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL5_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL5_ENBLN) & BM_SDMAARM_SDMA_CHNENBL5_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL5_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL5_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL5_ENBLN) & BM_SDMAARM_SDMA_CHNENBL5_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL5_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL5_WR((HW_SDMAARM_SDMA_CHNENBL5_RD() & ~BM_SDMAARM_SDMA_CHNENBL5_ENBLN) | BF_SDMAARM_SDMA_CHNENBL5_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL6 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl6
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl6_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl6_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL6 register
 */
#define HW_SDMAARM_SDMA_CHNENBL6_ADDR      (REGS_SDMAARM_BASE + 0x218)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL6           (*(volatile hw_sdmaarm_sdma_chnenbl6_t *) HW_SDMAARM_SDMA_CHNENBL6_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL6_RD()      (HW_SDMAARM_SDMA_CHNENBL6.U)
#define HW_SDMAARM_SDMA_CHNENBL6_WR(v)     (HW_SDMAARM_SDMA_CHNENBL6.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL6_SET(v)    (HW_SDMAARM_SDMA_CHNENBL6_WR(HW_SDMAARM_SDMA_CHNENBL6_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL6_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL6_WR(HW_SDMAARM_SDMA_CHNENBL6_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL6_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL6_WR(HW_SDMAARM_SDMA_CHNENBL6_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL6 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL6, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL6_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL6_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL6_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL6_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL6_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL6_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL6_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL6_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL6_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL6_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL6_ENBLN) & BM_SDMAARM_SDMA_CHNENBL6_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL6_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL6_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL6_ENBLN) & BM_SDMAARM_SDMA_CHNENBL6_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL6_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL6_WR((HW_SDMAARM_SDMA_CHNENBL6_RD() & ~BM_SDMAARM_SDMA_CHNENBL6_ENBLN) | BF_SDMAARM_SDMA_CHNENBL6_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL7 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl7
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl7_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl7_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL7 register
 */
#define HW_SDMAARM_SDMA_CHNENBL7_ADDR      (REGS_SDMAARM_BASE + 0x21c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL7           (*(volatile hw_sdmaarm_sdma_chnenbl7_t *) HW_SDMAARM_SDMA_CHNENBL7_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL7_RD()      (HW_SDMAARM_SDMA_CHNENBL7.U)
#define HW_SDMAARM_SDMA_CHNENBL7_WR(v)     (HW_SDMAARM_SDMA_CHNENBL7.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL7_SET(v)    (HW_SDMAARM_SDMA_CHNENBL7_WR(HW_SDMAARM_SDMA_CHNENBL7_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL7_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL7_WR(HW_SDMAARM_SDMA_CHNENBL7_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL7_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL7_WR(HW_SDMAARM_SDMA_CHNENBL7_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL7 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL7, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL7_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL7_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL7_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL7_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL7_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL7_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL7_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL7_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL7_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL7_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL7_ENBLN) & BM_SDMAARM_SDMA_CHNENBL7_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL7_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL7_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL7_ENBLN) & BM_SDMAARM_SDMA_CHNENBL7_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL7_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL7_WR((HW_SDMAARM_SDMA_CHNENBL7_RD() & ~BM_SDMAARM_SDMA_CHNENBL7_ENBLN) | BF_SDMAARM_SDMA_CHNENBL7_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL8 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl8
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl8_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl8_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL8 register
 */
#define HW_SDMAARM_SDMA_CHNENBL8_ADDR      (REGS_SDMAARM_BASE + 0x220)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL8           (*(volatile hw_sdmaarm_sdma_chnenbl8_t *) HW_SDMAARM_SDMA_CHNENBL8_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL8_RD()      (HW_SDMAARM_SDMA_CHNENBL8.U)
#define HW_SDMAARM_SDMA_CHNENBL8_WR(v)     (HW_SDMAARM_SDMA_CHNENBL8.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL8_SET(v)    (HW_SDMAARM_SDMA_CHNENBL8_WR(HW_SDMAARM_SDMA_CHNENBL8_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL8_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL8_WR(HW_SDMAARM_SDMA_CHNENBL8_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL8_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL8_WR(HW_SDMAARM_SDMA_CHNENBL8_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL8 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL8, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL8_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL8_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL8_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL8_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL8_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL8_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL8_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL8_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL8_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL8_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL8_ENBLN) & BM_SDMAARM_SDMA_CHNENBL8_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL8_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL8_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL8_ENBLN) & BM_SDMAARM_SDMA_CHNENBL8_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL8_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL8_WR((HW_SDMAARM_SDMA_CHNENBL8_RD() & ~BM_SDMAARM_SDMA_CHNENBL8_ENBLN) | BF_SDMAARM_SDMA_CHNENBL8_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL9 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl9
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl9_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl9_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL9 register
 */
#define HW_SDMAARM_SDMA_CHNENBL9_ADDR      (REGS_SDMAARM_BASE + 0x224)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL9           (*(volatile hw_sdmaarm_sdma_chnenbl9_t *) HW_SDMAARM_SDMA_CHNENBL9_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL9_RD()      (HW_SDMAARM_SDMA_CHNENBL9.U)
#define HW_SDMAARM_SDMA_CHNENBL9_WR(v)     (HW_SDMAARM_SDMA_CHNENBL9.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL9_SET(v)    (HW_SDMAARM_SDMA_CHNENBL9_WR(HW_SDMAARM_SDMA_CHNENBL9_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL9_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL9_WR(HW_SDMAARM_SDMA_CHNENBL9_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL9_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL9_WR(HW_SDMAARM_SDMA_CHNENBL9_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL9 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL9, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL9_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL9_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL9_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL9_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL9_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL9_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL9_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL9_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL9_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL9_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL9_ENBLN) & BM_SDMAARM_SDMA_CHNENBL9_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL9_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL9_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL9_ENBLN) & BM_SDMAARM_SDMA_CHNENBL9_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL9_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL9_WR((HW_SDMAARM_SDMA_CHNENBL9_RD() & ~BM_SDMAARM_SDMA_CHNENBL9_ENBLN) | BF_SDMAARM_SDMA_CHNENBL9_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL10 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl10
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl10_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl10_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL10 register
 */
#define HW_SDMAARM_SDMA_CHNENBL10_ADDR      (REGS_SDMAARM_BASE + 0x228)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL10           (*(volatile hw_sdmaarm_sdma_chnenbl10_t *) HW_SDMAARM_SDMA_CHNENBL10_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL10_RD()      (HW_SDMAARM_SDMA_CHNENBL10.U)
#define HW_SDMAARM_SDMA_CHNENBL10_WR(v)     (HW_SDMAARM_SDMA_CHNENBL10.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL10_SET(v)    (HW_SDMAARM_SDMA_CHNENBL10_WR(HW_SDMAARM_SDMA_CHNENBL10_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL10_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL10_WR(HW_SDMAARM_SDMA_CHNENBL10_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL10_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL10_WR(HW_SDMAARM_SDMA_CHNENBL10_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL10 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL10, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL10_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL10_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL10_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL10_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL10_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL10_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL10_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL10_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL10_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL10_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL10_ENBLN) & BM_SDMAARM_SDMA_CHNENBL10_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL10_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL10_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL10_ENBLN) & BM_SDMAARM_SDMA_CHNENBL10_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL10_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL10_WR((HW_SDMAARM_SDMA_CHNENBL10_RD() & ~BM_SDMAARM_SDMA_CHNENBL10_ENBLN) | BF_SDMAARM_SDMA_CHNENBL10_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL11 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl11
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl11_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl11_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL11 register
 */
#define HW_SDMAARM_SDMA_CHNENBL11_ADDR      (REGS_SDMAARM_BASE + 0x22c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL11           (*(volatile hw_sdmaarm_sdma_chnenbl11_t *) HW_SDMAARM_SDMA_CHNENBL11_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL11_RD()      (HW_SDMAARM_SDMA_CHNENBL11.U)
#define HW_SDMAARM_SDMA_CHNENBL11_WR(v)     (HW_SDMAARM_SDMA_CHNENBL11.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL11_SET(v)    (HW_SDMAARM_SDMA_CHNENBL11_WR(HW_SDMAARM_SDMA_CHNENBL11_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL11_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL11_WR(HW_SDMAARM_SDMA_CHNENBL11_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL11_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL11_WR(HW_SDMAARM_SDMA_CHNENBL11_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL11 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL11, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL11_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL11_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL11_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL11_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL11_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL11_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL11_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL11_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL11_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL11_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL11_ENBLN) & BM_SDMAARM_SDMA_CHNENBL11_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL11_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL11_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL11_ENBLN) & BM_SDMAARM_SDMA_CHNENBL11_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL11_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL11_WR((HW_SDMAARM_SDMA_CHNENBL11_RD() & ~BM_SDMAARM_SDMA_CHNENBL11_ENBLN) | BF_SDMAARM_SDMA_CHNENBL11_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL12 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl12
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl12_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl12_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL12 register
 */
#define HW_SDMAARM_SDMA_CHNENBL12_ADDR      (REGS_SDMAARM_BASE + 0x230)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL12           (*(volatile hw_sdmaarm_sdma_chnenbl12_t *) HW_SDMAARM_SDMA_CHNENBL12_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL12_RD()      (HW_SDMAARM_SDMA_CHNENBL12.U)
#define HW_SDMAARM_SDMA_CHNENBL12_WR(v)     (HW_SDMAARM_SDMA_CHNENBL12.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL12_SET(v)    (HW_SDMAARM_SDMA_CHNENBL12_WR(HW_SDMAARM_SDMA_CHNENBL12_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL12_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL12_WR(HW_SDMAARM_SDMA_CHNENBL12_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL12_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL12_WR(HW_SDMAARM_SDMA_CHNENBL12_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL12 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL12, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL12_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL12_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL12_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL12_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL12_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL12_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL12_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL12_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL12_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL12_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL12_ENBLN) & BM_SDMAARM_SDMA_CHNENBL12_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL12_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL12_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL12_ENBLN) & BM_SDMAARM_SDMA_CHNENBL12_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL12_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL12_WR((HW_SDMAARM_SDMA_CHNENBL12_RD() & ~BM_SDMAARM_SDMA_CHNENBL12_ENBLN) | BF_SDMAARM_SDMA_CHNENBL12_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL13 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl13
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl13_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl13_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL13 register
 */
#define HW_SDMAARM_SDMA_CHNENBL13_ADDR      (REGS_SDMAARM_BASE + 0x234)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL13           (*(volatile hw_sdmaarm_sdma_chnenbl13_t *) HW_SDMAARM_SDMA_CHNENBL13_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL13_RD()      (HW_SDMAARM_SDMA_CHNENBL13.U)
#define HW_SDMAARM_SDMA_CHNENBL13_WR(v)     (HW_SDMAARM_SDMA_CHNENBL13.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL13_SET(v)    (HW_SDMAARM_SDMA_CHNENBL13_WR(HW_SDMAARM_SDMA_CHNENBL13_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL13_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL13_WR(HW_SDMAARM_SDMA_CHNENBL13_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL13_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL13_WR(HW_SDMAARM_SDMA_CHNENBL13_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL13 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL13, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL13_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL13_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL13_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL13_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL13_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL13_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL13_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL13_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL13_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL13_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL13_ENBLN) & BM_SDMAARM_SDMA_CHNENBL13_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL13_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL13_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL13_ENBLN) & BM_SDMAARM_SDMA_CHNENBL13_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL13_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL13_WR((HW_SDMAARM_SDMA_CHNENBL13_RD() & ~BM_SDMAARM_SDMA_CHNENBL13_ENBLN) | BF_SDMAARM_SDMA_CHNENBL13_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL14 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl14
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl14_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl14_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL14 register
 */
#define HW_SDMAARM_SDMA_CHNENBL14_ADDR      (REGS_SDMAARM_BASE + 0x238)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL14           (*(volatile hw_sdmaarm_sdma_chnenbl14_t *) HW_SDMAARM_SDMA_CHNENBL14_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL14_RD()      (HW_SDMAARM_SDMA_CHNENBL14.U)
#define HW_SDMAARM_SDMA_CHNENBL14_WR(v)     (HW_SDMAARM_SDMA_CHNENBL14.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL14_SET(v)    (HW_SDMAARM_SDMA_CHNENBL14_WR(HW_SDMAARM_SDMA_CHNENBL14_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL14_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL14_WR(HW_SDMAARM_SDMA_CHNENBL14_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL14_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL14_WR(HW_SDMAARM_SDMA_CHNENBL14_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL14 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL14, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL14_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL14_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL14_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL14_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL14_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL14_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL14_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL14_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL14_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL14_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL14_ENBLN) & BM_SDMAARM_SDMA_CHNENBL14_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL14_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL14_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL14_ENBLN) & BM_SDMAARM_SDMA_CHNENBL14_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL14_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL14_WR((HW_SDMAARM_SDMA_CHNENBL14_RD() & ~BM_SDMAARM_SDMA_CHNENBL14_ENBLN) | BF_SDMAARM_SDMA_CHNENBL14_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL15 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl15
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl15_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl15_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL15 register
 */
#define HW_SDMAARM_SDMA_CHNENBL15_ADDR      (REGS_SDMAARM_BASE + 0x23c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL15           (*(volatile hw_sdmaarm_sdma_chnenbl15_t *) HW_SDMAARM_SDMA_CHNENBL15_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL15_RD()      (HW_SDMAARM_SDMA_CHNENBL15.U)
#define HW_SDMAARM_SDMA_CHNENBL15_WR(v)     (HW_SDMAARM_SDMA_CHNENBL15.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL15_SET(v)    (HW_SDMAARM_SDMA_CHNENBL15_WR(HW_SDMAARM_SDMA_CHNENBL15_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL15_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL15_WR(HW_SDMAARM_SDMA_CHNENBL15_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL15_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL15_WR(HW_SDMAARM_SDMA_CHNENBL15_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL15 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL15, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL15_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL15_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL15_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL15_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL15_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL15_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL15_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL15_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL15_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL15_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL15_ENBLN) & BM_SDMAARM_SDMA_CHNENBL15_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL15_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL15_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL15_ENBLN) & BM_SDMAARM_SDMA_CHNENBL15_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL15_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL15_WR((HW_SDMAARM_SDMA_CHNENBL15_RD() & ~BM_SDMAARM_SDMA_CHNENBL15_ENBLN) | BF_SDMAARM_SDMA_CHNENBL15_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL16 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl16
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl16_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl16_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL16 register
 */
#define HW_SDMAARM_SDMA_CHNENBL16_ADDR      (REGS_SDMAARM_BASE + 0x240)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL16           (*(volatile hw_sdmaarm_sdma_chnenbl16_t *) HW_SDMAARM_SDMA_CHNENBL16_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL16_RD()      (HW_SDMAARM_SDMA_CHNENBL16.U)
#define HW_SDMAARM_SDMA_CHNENBL16_WR(v)     (HW_SDMAARM_SDMA_CHNENBL16.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL16_SET(v)    (HW_SDMAARM_SDMA_CHNENBL16_WR(HW_SDMAARM_SDMA_CHNENBL16_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL16_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL16_WR(HW_SDMAARM_SDMA_CHNENBL16_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL16_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL16_WR(HW_SDMAARM_SDMA_CHNENBL16_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL16 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL16, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL16_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL16_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL16_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL16_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL16_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL16_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL16_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL16_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL16_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL16_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL16_ENBLN) & BM_SDMAARM_SDMA_CHNENBL16_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL16_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL16_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL16_ENBLN) & BM_SDMAARM_SDMA_CHNENBL16_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL16_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL16_WR((HW_SDMAARM_SDMA_CHNENBL16_RD() & ~BM_SDMAARM_SDMA_CHNENBL16_ENBLN) | BF_SDMAARM_SDMA_CHNENBL16_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL17 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl17
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl17_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl17_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL17 register
 */
#define HW_SDMAARM_SDMA_CHNENBL17_ADDR      (REGS_SDMAARM_BASE + 0x244)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL17           (*(volatile hw_sdmaarm_sdma_chnenbl17_t *) HW_SDMAARM_SDMA_CHNENBL17_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL17_RD()      (HW_SDMAARM_SDMA_CHNENBL17.U)
#define HW_SDMAARM_SDMA_CHNENBL17_WR(v)     (HW_SDMAARM_SDMA_CHNENBL17.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL17_SET(v)    (HW_SDMAARM_SDMA_CHNENBL17_WR(HW_SDMAARM_SDMA_CHNENBL17_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL17_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL17_WR(HW_SDMAARM_SDMA_CHNENBL17_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL17_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL17_WR(HW_SDMAARM_SDMA_CHNENBL17_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL17 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL17, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL17_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL17_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL17_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL17_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL17_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL17_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL17_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL17_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL17_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL17_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL17_ENBLN) & BM_SDMAARM_SDMA_CHNENBL17_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL17_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL17_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL17_ENBLN) & BM_SDMAARM_SDMA_CHNENBL17_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL17_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL17_WR((HW_SDMAARM_SDMA_CHNENBL17_RD() & ~BM_SDMAARM_SDMA_CHNENBL17_ENBLN) | BF_SDMAARM_SDMA_CHNENBL17_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL18 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl18
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl18_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl18_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL18 register
 */
#define HW_SDMAARM_SDMA_CHNENBL18_ADDR      (REGS_SDMAARM_BASE + 0x248)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL18           (*(volatile hw_sdmaarm_sdma_chnenbl18_t *) HW_SDMAARM_SDMA_CHNENBL18_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL18_RD()      (HW_SDMAARM_SDMA_CHNENBL18.U)
#define HW_SDMAARM_SDMA_CHNENBL18_WR(v)     (HW_SDMAARM_SDMA_CHNENBL18.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL18_SET(v)    (HW_SDMAARM_SDMA_CHNENBL18_WR(HW_SDMAARM_SDMA_CHNENBL18_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL18_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL18_WR(HW_SDMAARM_SDMA_CHNENBL18_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL18_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL18_WR(HW_SDMAARM_SDMA_CHNENBL18_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL18 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL18, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL18_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL18_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL18_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL18_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL18_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL18_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL18_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL18_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL18_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL18_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL18_ENBLN) & BM_SDMAARM_SDMA_CHNENBL18_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL18_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL18_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL18_ENBLN) & BM_SDMAARM_SDMA_CHNENBL18_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL18_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL18_WR((HW_SDMAARM_SDMA_CHNENBL18_RD() & ~BM_SDMAARM_SDMA_CHNENBL18_ENBLN) | BF_SDMAARM_SDMA_CHNENBL18_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL19 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl19
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl19_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl19_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL19 register
 */
#define HW_SDMAARM_SDMA_CHNENBL19_ADDR      (REGS_SDMAARM_BASE + 0x24c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL19           (*(volatile hw_sdmaarm_sdma_chnenbl19_t *) HW_SDMAARM_SDMA_CHNENBL19_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL19_RD()      (HW_SDMAARM_SDMA_CHNENBL19.U)
#define HW_SDMAARM_SDMA_CHNENBL19_WR(v)     (HW_SDMAARM_SDMA_CHNENBL19.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL19_SET(v)    (HW_SDMAARM_SDMA_CHNENBL19_WR(HW_SDMAARM_SDMA_CHNENBL19_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL19_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL19_WR(HW_SDMAARM_SDMA_CHNENBL19_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL19_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL19_WR(HW_SDMAARM_SDMA_CHNENBL19_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL19 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL19, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL19_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL19_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL19_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL19_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL19_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL19_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL19_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL19_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL19_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL19_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL19_ENBLN) & BM_SDMAARM_SDMA_CHNENBL19_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL19_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL19_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL19_ENBLN) & BM_SDMAARM_SDMA_CHNENBL19_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL19_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL19_WR((HW_SDMAARM_SDMA_CHNENBL19_RD() & ~BM_SDMAARM_SDMA_CHNENBL19_ENBLN) | BF_SDMAARM_SDMA_CHNENBL19_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL20 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl20
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl20_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl20_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL20 register
 */
#define HW_SDMAARM_SDMA_CHNENBL20_ADDR      (REGS_SDMAARM_BASE + 0x250)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL20           (*(volatile hw_sdmaarm_sdma_chnenbl20_t *) HW_SDMAARM_SDMA_CHNENBL20_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL20_RD()      (HW_SDMAARM_SDMA_CHNENBL20.U)
#define HW_SDMAARM_SDMA_CHNENBL20_WR(v)     (HW_SDMAARM_SDMA_CHNENBL20.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL20_SET(v)    (HW_SDMAARM_SDMA_CHNENBL20_WR(HW_SDMAARM_SDMA_CHNENBL20_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL20_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL20_WR(HW_SDMAARM_SDMA_CHNENBL20_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL20_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL20_WR(HW_SDMAARM_SDMA_CHNENBL20_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL20 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL20, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL20_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL20_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL20_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL20_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL20_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL20_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL20_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL20_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL20_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL20_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL20_ENBLN) & BM_SDMAARM_SDMA_CHNENBL20_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL20_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL20_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL20_ENBLN) & BM_SDMAARM_SDMA_CHNENBL20_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL20_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL20_WR((HW_SDMAARM_SDMA_CHNENBL20_RD() & ~BM_SDMAARM_SDMA_CHNENBL20_ENBLN) | BF_SDMAARM_SDMA_CHNENBL20_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL21 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl21
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl21_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl21_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL21 register
 */
#define HW_SDMAARM_SDMA_CHNENBL21_ADDR      (REGS_SDMAARM_BASE + 0x254)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL21           (*(volatile hw_sdmaarm_sdma_chnenbl21_t *) HW_SDMAARM_SDMA_CHNENBL21_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL21_RD()      (HW_SDMAARM_SDMA_CHNENBL21.U)
#define HW_SDMAARM_SDMA_CHNENBL21_WR(v)     (HW_SDMAARM_SDMA_CHNENBL21.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL21_SET(v)    (HW_SDMAARM_SDMA_CHNENBL21_WR(HW_SDMAARM_SDMA_CHNENBL21_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL21_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL21_WR(HW_SDMAARM_SDMA_CHNENBL21_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL21_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL21_WR(HW_SDMAARM_SDMA_CHNENBL21_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL21 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL21, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL21_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL21_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL21_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL21_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL21_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL21_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL21_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL21_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL21_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL21_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL21_ENBLN) & BM_SDMAARM_SDMA_CHNENBL21_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL21_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL21_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL21_ENBLN) & BM_SDMAARM_SDMA_CHNENBL21_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL21_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL21_WR((HW_SDMAARM_SDMA_CHNENBL21_RD() & ~BM_SDMAARM_SDMA_CHNENBL21_ENBLN) | BF_SDMAARM_SDMA_CHNENBL21_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL22 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl22
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl22_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl22_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL22 register
 */
#define HW_SDMAARM_SDMA_CHNENBL22_ADDR      (REGS_SDMAARM_BASE + 0x258)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL22           (*(volatile hw_sdmaarm_sdma_chnenbl22_t *) HW_SDMAARM_SDMA_CHNENBL22_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL22_RD()      (HW_SDMAARM_SDMA_CHNENBL22.U)
#define HW_SDMAARM_SDMA_CHNENBL22_WR(v)     (HW_SDMAARM_SDMA_CHNENBL22.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL22_SET(v)    (HW_SDMAARM_SDMA_CHNENBL22_WR(HW_SDMAARM_SDMA_CHNENBL22_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL22_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL22_WR(HW_SDMAARM_SDMA_CHNENBL22_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL22_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL22_WR(HW_SDMAARM_SDMA_CHNENBL22_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL22 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL22, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL22_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL22_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL22_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL22_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL22_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL22_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL22_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL22_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL22_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL22_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL22_ENBLN) & BM_SDMAARM_SDMA_CHNENBL22_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL22_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL22_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL22_ENBLN) & BM_SDMAARM_SDMA_CHNENBL22_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL22_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL22_WR((HW_SDMAARM_SDMA_CHNENBL22_RD() & ~BM_SDMAARM_SDMA_CHNENBL22_ENBLN) | BF_SDMAARM_SDMA_CHNENBL22_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL23 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl23
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl23_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl23_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL23 register
 */
#define HW_SDMAARM_SDMA_CHNENBL23_ADDR      (REGS_SDMAARM_BASE + 0x25c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL23           (*(volatile hw_sdmaarm_sdma_chnenbl23_t *) HW_SDMAARM_SDMA_CHNENBL23_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL23_RD()      (HW_SDMAARM_SDMA_CHNENBL23.U)
#define HW_SDMAARM_SDMA_CHNENBL23_WR(v)     (HW_SDMAARM_SDMA_CHNENBL23.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL23_SET(v)    (HW_SDMAARM_SDMA_CHNENBL23_WR(HW_SDMAARM_SDMA_CHNENBL23_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL23_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL23_WR(HW_SDMAARM_SDMA_CHNENBL23_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL23_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL23_WR(HW_SDMAARM_SDMA_CHNENBL23_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL23 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL23, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL23_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL23_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL23_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL23_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL23_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL23_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL23_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL23_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL23_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL23_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL23_ENBLN) & BM_SDMAARM_SDMA_CHNENBL23_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL23_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL23_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL23_ENBLN) & BM_SDMAARM_SDMA_CHNENBL23_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL23_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL23_WR((HW_SDMAARM_SDMA_CHNENBL23_RD() & ~BM_SDMAARM_SDMA_CHNENBL23_ENBLN) | BF_SDMAARM_SDMA_CHNENBL23_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL24 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl24
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl24_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl24_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL24 register
 */
#define HW_SDMAARM_SDMA_CHNENBL24_ADDR      (REGS_SDMAARM_BASE + 0x260)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL24           (*(volatile hw_sdmaarm_sdma_chnenbl24_t *) HW_SDMAARM_SDMA_CHNENBL24_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL24_RD()      (HW_SDMAARM_SDMA_CHNENBL24.U)
#define HW_SDMAARM_SDMA_CHNENBL24_WR(v)     (HW_SDMAARM_SDMA_CHNENBL24.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL24_SET(v)    (HW_SDMAARM_SDMA_CHNENBL24_WR(HW_SDMAARM_SDMA_CHNENBL24_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL24_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL24_WR(HW_SDMAARM_SDMA_CHNENBL24_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL24_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL24_WR(HW_SDMAARM_SDMA_CHNENBL24_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL24 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL24, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL24_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL24_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL24_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL24_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL24_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL24_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL24_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL24_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL24_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL24_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL24_ENBLN) & BM_SDMAARM_SDMA_CHNENBL24_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL24_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL24_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL24_ENBLN) & BM_SDMAARM_SDMA_CHNENBL24_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL24_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL24_WR((HW_SDMAARM_SDMA_CHNENBL24_RD() & ~BM_SDMAARM_SDMA_CHNENBL24_ENBLN) | BF_SDMAARM_SDMA_CHNENBL24_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL25 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl25
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl25_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl25_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL25 register
 */
#define HW_SDMAARM_SDMA_CHNENBL25_ADDR      (REGS_SDMAARM_BASE + 0x264)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL25           (*(volatile hw_sdmaarm_sdma_chnenbl25_t *) HW_SDMAARM_SDMA_CHNENBL25_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL25_RD()      (HW_SDMAARM_SDMA_CHNENBL25.U)
#define HW_SDMAARM_SDMA_CHNENBL25_WR(v)     (HW_SDMAARM_SDMA_CHNENBL25.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL25_SET(v)    (HW_SDMAARM_SDMA_CHNENBL25_WR(HW_SDMAARM_SDMA_CHNENBL25_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL25_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL25_WR(HW_SDMAARM_SDMA_CHNENBL25_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL25_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL25_WR(HW_SDMAARM_SDMA_CHNENBL25_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL25 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL25, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL25_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL25_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL25_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL25_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL25_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL25_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL25_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL25_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL25_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL25_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL25_ENBLN) & BM_SDMAARM_SDMA_CHNENBL25_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL25_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL25_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL25_ENBLN) & BM_SDMAARM_SDMA_CHNENBL25_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL25_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL25_WR((HW_SDMAARM_SDMA_CHNENBL25_RD() & ~BM_SDMAARM_SDMA_CHNENBL25_ENBLN) | BF_SDMAARM_SDMA_CHNENBL25_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL26 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl26
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl26_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl26_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL26 register
 */
#define HW_SDMAARM_SDMA_CHNENBL26_ADDR      (REGS_SDMAARM_BASE + 0x268)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL26           (*(volatile hw_sdmaarm_sdma_chnenbl26_t *) HW_SDMAARM_SDMA_CHNENBL26_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL26_RD()      (HW_SDMAARM_SDMA_CHNENBL26.U)
#define HW_SDMAARM_SDMA_CHNENBL26_WR(v)     (HW_SDMAARM_SDMA_CHNENBL26.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL26_SET(v)    (HW_SDMAARM_SDMA_CHNENBL26_WR(HW_SDMAARM_SDMA_CHNENBL26_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL26_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL26_WR(HW_SDMAARM_SDMA_CHNENBL26_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL26_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL26_WR(HW_SDMAARM_SDMA_CHNENBL26_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL26 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL26, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL26_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL26_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL26_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL26_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL26_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL26_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL26_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL26_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL26_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL26_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL26_ENBLN) & BM_SDMAARM_SDMA_CHNENBL26_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL26_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL26_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL26_ENBLN) & BM_SDMAARM_SDMA_CHNENBL26_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL26_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL26_WR((HW_SDMAARM_SDMA_CHNENBL26_RD() & ~BM_SDMAARM_SDMA_CHNENBL26_ENBLN) | BF_SDMAARM_SDMA_CHNENBL26_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL27 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl27
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl27_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl27_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL27 register
 */
#define HW_SDMAARM_SDMA_CHNENBL27_ADDR      (REGS_SDMAARM_BASE + 0x26c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL27           (*(volatile hw_sdmaarm_sdma_chnenbl27_t *) HW_SDMAARM_SDMA_CHNENBL27_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL27_RD()      (HW_SDMAARM_SDMA_CHNENBL27.U)
#define HW_SDMAARM_SDMA_CHNENBL27_WR(v)     (HW_SDMAARM_SDMA_CHNENBL27.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL27_SET(v)    (HW_SDMAARM_SDMA_CHNENBL27_WR(HW_SDMAARM_SDMA_CHNENBL27_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL27_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL27_WR(HW_SDMAARM_SDMA_CHNENBL27_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL27_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL27_WR(HW_SDMAARM_SDMA_CHNENBL27_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL27 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL27, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL27_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL27_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL27_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL27_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL27_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL27_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL27_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL27_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL27_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL27_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL27_ENBLN) & BM_SDMAARM_SDMA_CHNENBL27_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL27_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL27_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL27_ENBLN) & BM_SDMAARM_SDMA_CHNENBL27_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL27_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL27_WR((HW_SDMAARM_SDMA_CHNENBL27_RD() & ~BM_SDMAARM_SDMA_CHNENBL27_ENBLN) | BF_SDMAARM_SDMA_CHNENBL27_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL28 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl28
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl28_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl28_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL28 register
 */
#define HW_SDMAARM_SDMA_CHNENBL28_ADDR      (REGS_SDMAARM_BASE + 0x270)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL28           (*(volatile hw_sdmaarm_sdma_chnenbl28_t *) HW_SDMAARM_SDMA_CHNENBL28_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL28_RD()      (HW_SDMAARM_SDMA_CHNENBL28.U)
#define HW_SDMAARM_SDMA_CHNENBL28_WR(v)     (HW_SDMAARM_SDMA_CHNENBL28.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL28_SET(v)    (HW_SDMAARM_SDMA_CHNENBL28_WR(HW_SDMAARM_SDMA_CHNENBL28_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL28_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL28_WR(HW_SDMAARM_SDMA_CHNENBL28_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL28_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL28_WR(HW_SDMAARM_SDMA_CHNENBL28_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL28 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL28, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL28_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL28_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL28_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL28_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL28_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL28_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL28_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL28_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL28_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL28_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL28_ENBLN) & BM_SDMAARM_SDMA_CHNENBL28_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL28_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL28_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL28_ENBLN) & BM_SDMAARM_SDMA_CHNENBL28_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL28_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL28_WR((HW_SDMAARM_SDMA_CHNENBL28_RD() & ~BM_SDMAARM_SDMA_CHNENBL28_ENBLN) | BF_SDMAARM_SDMA_CHNENBL28_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL29 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl29
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl29_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl29_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL29 register
 */
#define HW_SDMAARM_SDMA_CHNENBL29_ADDR      (REGS_SDMAARM_BASE + 0x274)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL29           (*(volatile hw_sdmaarm_sdma_chnenbl29_t *) HW_SDMAARM_SDMA_CHNENBL29_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL29_RD()      (HW_SDMAARM_SDMA_CHNENBL29.U)
#define HW_SDMAARM_SDMA_CHNENBL29_WR(v)     (HW_SDMAARM_SDMA_CHNENBL29.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL29_SET(v)    (HW_SDMAARM_SDMA_CHNENBL29_WR(HW_SDMAARM_SDMA_CHNENBL29_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL29_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL29_WR(HW_SDMAARM_SDMA_CHNENBL29_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL29_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL29_WR(HW_SDMAARM_SDMA_CHNENBL29_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL29 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL29, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL29_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL29_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL29_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL29_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL29_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL29_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL29_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL29_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL29_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL29_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL29_ENBLN) & BM_SDMAARM_SDMA_CHNENBL29_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL29_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL29_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL29_ENBLN) & BM_SDMAARM_SDMA_CHNENBL29_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL29_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL29_WR((HW_SDMAARM_SDMA_CHNENBL29_RD() & ~BM_SDMAARM_SDMA_CHNENBL29_ENBLN) | BF_SDMAARM_SDMA_CHNENBL29_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL30 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl30
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl30_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl30_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL30 register
 */
#define HW_SDMAARM_SDMA_CHNENBL30_ADDR      (REGS_SDMAARM_BASE + 0x278)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL30           (*(volatile hw_sdmaarm_sdma_chnenbl30_t *) HW_SDMAARM_SDMA_CHNENBL30_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL30_RD()      (HW_SDMAARM_SDMA_CHNENBL30.U)
#define HW_SDMAARM_SDMA_CHNENBL30_WR(v)     (HW_SDMAARM_SDMA_CHNENBL30.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL30_SET(v)    (HW_SDMAARM_SDMA_CHNENBL30_WR(HW_SDMAARM_SDMA_CHNENBL30_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL30_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL30_WR(HW_SDMAARM_SDMA_CHNENBL30_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL30_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL30_WR(HW_SDMAARM_SDMA_CHNENBL30_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL30 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL30, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL30_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL30_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL30_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL30_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL30_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL30_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL30_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL30_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL30_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL30_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL30_ENBLN) & BM_SDMAARM_SDMA_CHNENBL30_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL30_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL30_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL30_ENBLN) & BM_SDMAARM_SDMA_CHNENBL30_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL30_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL30_WR((HW_SDMAARM_SDMA_CHNENBL30_RD() & ~BM_SDMAARM_SDMA_CHNENBL30_ENBLN) | BF_SDMAARM_SDMA_CHNENBL30_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL31 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl31
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl31_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl31_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL31 register
 */
#define HW_SDMAARM_SDMA_CHNENBL31_ADDR      (REGS_SDMAARM_BASE + 0x27c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL31           (*(volatile hw_sdmaarm_sdma_chnenbl31_t *) HW_SDMAARM_SDMA_CHNENBL31_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL31_RD()      (HW_SDMAARM_SDMA_CHNENBL31.U)
#define HW_SDMAARM_SDMA_CHNENBL31_WR(v)     (HW_SDMAARM_SDMA_CHNENBL31.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL31_SET(v)    (HW_SDMAARM_SDMA_CHNENBL31_WR(HW_SDMAARM_SDMA_CHNENBL31_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL31_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL31_WR(HW_SDMAARM_SDMA_CHNENBL31_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL31_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL31_WR(HW_SDMAARM_SDMA_CHNENBL31_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL31 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL31, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL31_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL31_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL31_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL31_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL31_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL31_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL31_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL31_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL31_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL31_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL31_ENBLN) & BM_SDMAARM_SDMA_CHNENBL31_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL31_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL31_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL31_ENBLN) & BM_SDMAARM_SDMA_CHNENBL31_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL31_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL31_WR((HW_SDMAARM_SDMA_CHNENBL31_RD() & ~BM_SDMAARM_SDMA_CHNENBL31_ENBLN) | BF_SDMAARM_SDMA_CHNENBL31_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL32 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl32
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl32_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl32_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL32 register
 */
#define HW_SDMAARM_SDMA_CHNENBL32_ADDR      (REGS_SDMAARM_BASE + 0x280)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL32           (*(volatile hw_sdmaarm_sdma_chnenbl32_t *) HW_SDMAARM_SDMA_CHNENBL32_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL32_RD()      (HW_SDMAARM_SDMA_CHNENBL32.U)
#define HW_SDMAARM_SDMA_CHNENBL32_WR(v)     (HW_SDMAARM_SDMA_CHNENBL32.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL32_SET(v)    (HW_SDMAARM_SDMA_CHNENBL32_WR(HW_SDMAARM_SDMA_CHNENBL32_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL32_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL32_WR(HW_SDMAARM_SDMA_CHNENBL32_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL32_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL32_WR(HW_SDMAARM_SDMA_CHNENBL32_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL32 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL32, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL32_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL32_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL32_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL32_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL32_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL32_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL32_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL32_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL32_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL32_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL32_ENBLN) & BM_SDMAARM_SDMA_CHNENBL32_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL32_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL32_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL32_ENBLN) & BM_SDMAARM_SDMA_CHNENBL32_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL32_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL32_WR((HW_SDMAARM_SDMA_CHNENBL32_RD() & ~BM_SDMAARM_SDMA_CHNENBL32_ENBLN) | BF_SDMAARM_SDMA_CHNENBL32_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL33 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl33
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl33_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl33_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL33 register
 */
#define HW_SDMAARM_SDMA_CHNENBL33_ADDR      (REGS_SDMAARM_BASE + 0x284)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL33           (*(volatile hw_sdmaarm_sdma_chnenbl33_t *) HW_SDMAARM_SDMA_CHNENBL33_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL33_RD()      (HW_SDMAARM_SDMA_CHNENBL33.U)
#define HW_SDMAARM_SDMA_CHNENBL33_WR(v)     (HW_SDMAARM_SDMA_CHNENBL33.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL33_SET(v)    (HW_SDMAARM_SDMA_CHNENBL33_WR(HW_SDMAARM_SDMA_CHNENBL33_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL33_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL33_WR(HW_SDMAARM_SDMA_CHNENBL33_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL33_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL33_WR(HW_SDMAARM_SDMA_CHNENBL33_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL33 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL33, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL33_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL33_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL33_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL33_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL33_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL33_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL33_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL33_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL33_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL33_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL33_ENBLN) & BM_SDMAARM_SDMA_CHNENBL33_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL33_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL33_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL33_ENBLN) & BM_SDMAARM_SDMA_CHNENBL33_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL33_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL33_WR((HW_SDMAARM_SDMA_CHNENBL33_RD() & ~BM_SDMAARM_SDMA_CHNENBL33_ENBLN) | BF_SDMAARM_SDMA_CHNENBL33_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL34 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl34
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl34_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl34_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL34 register
 */
#define HW_SDMAARM_SDMA_CHNENBL34_ADDR      (REGS_SDMAARM_BASE + 0x288)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL34           (*(volatile hw_sdmaarm_sdma_chnenbl34_t *) HW_SDMAARM_SDMA_CHNENBL34_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL34_RD()      (HW_SDMAARM_SDMA_CHNENBL34.U)
#define HW_SDMAARM_SDMA_CHNENBL34_WR(v)     (HW_SDMAARM_SDMA_CHNENBL34.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL34_SET(v)    (HW_SDMAARM_SDMA_CHNENBL34_WR(HW_SDMAARM_SDMA_CHNENBL34_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL34_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL34_WR(HW_SDMAARM_SDMA_CHNENBL34_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL34_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL34_WR(HW_SDMAARM_SDMA_CHNENBL34_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL34 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL34, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL34_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL34_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL34_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL34_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL34_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL34_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL34_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL34_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL34_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL34_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL34_ENBLN) & BM_SDMAARM_SDMA_CHNENBL34_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL34_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL34_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL34_ENBLN) & BM_SDMAARM_SDMA_CHNENBL34_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL34_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL34_WR((HW_SDMAARM_SDMA_CHNENBL34_RD() & ~BM_SDMAARM_SDMA_CHNENBL34_ENBLN) | BF_SDMAARM_SDMA_CHNENBL34_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL35 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl35
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl35_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl35_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL35 register
 */
#define HW_SDMAARM_SDMA_CHNENBL35_ADDR      (REGS_SDMAARM_BASE + 0x28c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL35           (*(volatile hw_sdmaarm_sdma_chnenbl35_t *) HW_SDMAARM_SDMA_CHNENBL35_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL35_RD()      (HW_SDMAARM_SDMA_CHNENBL35.U)
#define HW_SDMAARM_SDMA_CHNENBL35_WR(v)     (HW_SDMAARM_SDMA_CHNENBL35.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL35_SET(v)    (HW_SDMAARM_SDMA_CHNENBL35_WR(HW_SDMAARM_SDMA_CHNENBL35_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL35_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL35_WR(HW_SDMAARM_SDMA_CHNENBL35_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL35_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL35_WR(HW_SDMAARM_SDMA_CHNENBL35_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL35 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL35, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL35_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL35_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL35_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL35_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL35_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL35_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL35_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL35_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL35_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL35_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL35_ENBLN) & BM_SDMAARM_SDMA_CHNENBL35_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL35_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL35_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL35_ENBLN) & BM_SDMAARM_SDMA_CHNENBL35_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL35_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL35_WR((HW_SDMAARM_SDMA_CHNENBL35_RD() & ~BM_SDMAARM_SDMA_CHNENBL35_ENBLN) | BF_SDMAARM_SDMA_CHNENBL35_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL36 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl36
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl36_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl36_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL36 register
 */
#define HW_SDMAARM_SDMA_CHNENBL36_ADDR      (REGS_SDMAARM_BASE + 0x290)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL36           (*(volatile hw_sdmaarm_sdma_chnenbl36_t *) HW_SDMAARM_SDMA_CHNENBL36_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL36_RD()      (HW_SDMAARM_SDMA_CHNENBL36.U)
#define HW_SDMAARM_SDMA_CHNENBL36_WR(v)     (HW_SDMAARM_SDMA_CHNENBL36.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL36_SET(v)    (HW_SDMAARM_SDMA_CHNENBL36_WR(HW_SDMAARM_SDMA_CHNENBL36_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL36_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL36_WR(HW_SDMAARM_SDMA_CHNENBL36_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL36_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL36_WR(HW_SDMAARM_SDMA_CHNENBL36_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL36 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL36, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL36_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL36_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL36_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL36_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL36_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL36_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL36_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL36_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL36_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL36_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL36_ENBLN) & BM_SDMAARM_SDMA_CHNENBL36_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL36_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL36_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL36_ENBLN) & BM_SDMAARM_SDMA_CHNENBL36_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL36_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL36_WR((HW_SDMAARM_SDMA_CHNENBL36_RD() & ~BM_SDMAARM_SDMA_CHNENBL36_ENBLN) | BF_SDMAARM_SDMA_CHNENBL36_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL37 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl37
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl37_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl37_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL37 register
 */
#define HW_SDMAARM_SDMA_CHNENBL37_ADDR      (REGS_SDMAARM_BASE + 0x294)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL37           (*(volatile hw_sdmaarm_sdma_chnenbl37_t *) HW_SDMAARM_SDMA_CHNENBL37_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL37_RD()      (HW_SDMAARM_SDMA_CHNENBL37.U)
#define HW_SDMAARM_SDMA_CHNENBL37_WR(v)     (HW_SDMAARM_SDMA_CHNENBL37.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL37_SET(v)    (HW_SDMAARM_SDMA_CHNENBL37_WR(HW_SDMAARM_SDMA_CHNENBL37_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL37_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL37_WR(HW_SDMAARM_SDMA_CHNENBL37_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL37_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL37_WR(HW_SDMAARM_SDMA_CHNENBL37_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL37 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL37, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL37_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL37_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL37_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL37_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL37_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL37_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL37_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL37_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL37_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL37_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL37_ENBLN) & BM_SDMAARM_SDMA_CHNENBL37_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL37_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL37_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL37_ENBLN) & BM_SDMAARM_SDMA_CHNENBL37_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL37_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL37_WR((HW_SDMAARM_SDMA_CHNENBL37_RD() & ~BM_SDMAARM_SDMA_CHNENBL37_ENBLN) | BF_SDMAARM_SDMA_CHNENBL37_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL38 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl38
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl38_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl38_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL38 register
 */
#define HW_SDMAARM_SDMA_CHNENBL38_ADDR      (REGS_SDMAARM_BASE + 0x298)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL38           (*(volatile hw_sdmaarm_sdma_chnenbl38_t *) HW_SDMAARM_SDMA_CHNENBL38_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL38_RD()      (HW_SDMAARM_SDMA_CHNENBL38.U)
#define HW_SDMAARM_SDMA_CHNENBL38_WR(v)     (HW_SDMAARM_SDMA_CHNENBL38.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL38_SET(v)    (HW_SDMAARM_SDMA_CHNENBL38_WR(HW_SDMAARM_SDMA_CHNENBL38_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL38_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL38_WR(HW_SDMAARM_SDMA_CHNENBL38_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL38_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL38_WR(HW_SDMAARM_SDMA_CHNENBL38_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL38 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL38, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL38_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL38_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL38_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL38_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL38_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL38_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL38_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL38_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL38_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL38_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL38_ENBLN) & BM_SDMAARM_SDMA_CHNENBL38_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL38_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL38_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL38_ENBLN) & BM_SDMAARM_SDMA_CHNENBL38_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL38_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL38_WR((HW_SDMAARM_SDMA_CHNENBL38_RD() & ~BM_SDMAARM_SDMA_CHNENBL38_ENBLN) | BF_SDMAARM_SDMA_CHNENBL38_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL39 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl39
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl39_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl39_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL39 register
 */
#define HW_SDMAARM_SDMA_CHNENBL39_ADDR      (REGS_SDMAARM_BASE + 0x29c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL39           (*(volatile hw_sdmaarm_sdma_chnenbl39_t *) HW_SDMAARM_SDMA_CHNENBL39_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL39_RD()      (HW_SDMAARM_SDMA_CHNENBL39.U)
#define HW_SDMAARM_SDMA_CHNENBL39_WR(v)     (HW_SDMAARM_SDMA_CHNENBL39.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL39_SET(v)    (HW_SDMAARM_SDMA_CHNENBL39_WR(HW_SDMAARM_SDMA_CHNENBL39_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL39_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL39_WR(HW_SDMAARM_SDMA_CHNENBL39_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL39_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL39_WR(HW_SDMAARM_SDMA_CHNENBL39_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL39 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL39, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL39_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL39_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL39_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL39_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL39_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL39_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL39_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL39_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL39_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL39_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL39_ENBLN) & BM_SDMAARM_SDMA_CHNENBL39_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL39_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL39_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL39_ENBLN) & BM_SDMAARM_SDMA_CHNENBL39_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL39_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL39_WR((HW_SDMAARM_SDMA_CHNENBL39_RD() & ~BM_SDMAARM_SDMA_CHNENBL39_ENBLN) | BF_SDMAARM_SDMA_CHNENBL39_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL40 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl40
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl40_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl40_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL40 register
 */
#define HW_SDMAARM_SDMA_CHNENBL40_ADDR      (REGS_SDMAARM_BASE + 0x2a0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL40           (*(volatile hw_sdmaarm_sdma_chnenbl40_t *) HW_SDMAARM_SDMA_CHNENBL40_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL40_RD()      (HW_SDMAARM_SDMA_CHNENBL40.U)
#define HW_SDMAARM_SDMA_CHNENBL40_WR(v)     (HW_SDMAARM_SDMA_CHNENBL40.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL40_SET(v)    (HW_SDMAARM_SDMA_CHNENBL40_WR(HW_SDMAARM_SDMA_CHNENBL40_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL40_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL40_WR(HW_SDMAARM_SDMA_CHNENBL40_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL40_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL40_WR(HW_SDMAARM_SDMA_CHNENBL40_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL40 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL40, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL40_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL40_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL40_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL40_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL40_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL40_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL40_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL40_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL40_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL40_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL40_ENBLN) & BM_SDMAARM_SDMA_CHNENBL40_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL40_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL40_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL40_ENBLN) & BM_SDMAARM_SDMA_CHNENBL40_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL40_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL40_WR((HW_SDMAARM_SDMA_CHNENBL40_RD() & ~BM_SDMAARM_SDMA_CHNENBL40_ENBLN) | BF_SDMAARM_SDMA_CHNENBL40_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL41 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl41
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl41_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl41_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL41 register
 */
#define HW_SDMAARM_SDMA_CHNENBL41_ADDR      (REGS_SDMAARM_BASE + 0x2a4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL41           (*(volatile hw_sdmaarm_sdma_chnenbl41_t *) HW_SDMAARM_SDMA_CHNENBL41_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL41_RD()      (HW_SDMAARM_SDMA_CHNENBL41.U)
#define HW_SDMAARM_SDMA_CHNENBL41_WR(v)     (HW_SDMAARM_SDMA_CHNENBL41.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL41_SET(v)    (HW_SDMAARM_SDMA_CHNENBL41_WR(HW_SDMAARM_SDMA_CHNENBL41_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL41_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL41_WR(HW_SDMAARM_SDMA_CHNENBL41_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL41_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL41_WR(HW_SDMAARM_SDMA_CHNENBL41_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL41 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL41, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL41_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL41_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL41_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL41_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL41_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL41_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL41_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL41_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL41_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL41_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL41_ENBLN) & BM_SDMAARM_SDMA_CHNENBL41_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL41_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL41_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL41_ENBLN) & BM_SDMAARM_SDMA_CHNENBL41_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL41_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL41_WR((HW_SDMAARM_SDMA_CHNENBL41_RD() & ~BM_SDMAARM_SDMA_CHNENBL41_ENBLN) | BF_SDMAARM_SDMA_CHNENBL41_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL42 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl42
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl42_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl42_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL42 register
 */
#define HW_SDMAARM_SDMA_CHNENBL42_ADDR      (REGS_SDMAARM_BASE + 0x2a8)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL42           (*(volatile hw_sdmaarm_sdma_chnenbl42_t *) HW_SDMAARM_SDMA_CHNENBL42_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL42_RD()      (HW_SDMAARM_SDMA_CHNENBL42.U)
#define HW_SDMAARM_SDMA_CHNENBL42_WR(v)     (HW_SDMAARM_SDMA_CHNENBL42.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL42_SET(v)    (HW_SDMAARM_SDMA_CHNENBL42_WR(HW_SDMAARM_SDMA_CHNENBL42_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL42_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL42_WR(HW_SDMAARM_SDMA_CHNENBL42_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL42_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL42_WR(HW_SDMAARM_SDMA_CHNENBL42_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL42 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL42, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL42_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL42_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL42_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL42_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL42_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL42_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL42_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL42_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL42_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL42_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL42_ENBLN) & BM_SDMAARM_SDMA_CHNENBL42_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL42_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL42_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL42_ENBLN) & BM_SDMAARM_SDMA_CHNENBL42_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL42_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL42_WR((HW_SDMAARM_SDMA_CHNENBL42_RD() & ~BM_SDMAARM_SDMA_CHNENBL42_ENBLN) | BF_SDMAARM_SDMA_CHNENBL42_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL43 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl43
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl43_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl43_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL43 register
 */
#define HW_SDMAARM_SDMA_CHNENBL43_ADDR      (REGS_SDMAARM_BASE + 0x2ac)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL43           (*(volatile hw_sdmaarm_sdma_chnenbl43_t *) HW_SDMAARM_SDMA_CHNENBL43_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL43_RD()      (HW_SDMAARM_SDMA_CHNENBL43.U)
#define HW_SDMAARM_SDMA_CHNENBL43_WR(v)     (HW_SDMAARM_SDMA_CHNENBL43.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL43_SET(v)    (HW_SDMAARM_SDMA_CHNENBL43_WR(HW_SDMAARM_SDMA_CHNENBL43_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL43_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL43_WR(HW_SDMAARM_SDMA_CHNENBL43_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL43_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL43_WR(HW_SDMAARM_SDMA_CHNENBL43_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL43 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL43, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL43_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL43_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL43_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL43_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL43_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL43_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL43_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL43_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL43_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL43_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL43_ENBLN) & BM_SDMAARM_SDMA_CHNENBL43_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL43_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL43_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL43_ENBLN) & BM_SDMAARM_SDMA_CHNENBL43_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL43_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL43_WR((HW_SDMAARM_SDMA_CHNENBL43_RD() & ~BM_SDMAARM_SDMA_CHNENBL43_ENBLN) | BF_SDMAARM_SDMA_CHNENBL43_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL44 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl44
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl44_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl44_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL44 register
 */
#define HW_SDMAARM_SDMA_CHNENBL44_ADDR      (REGS_SDMAARM_BASE + 0x2b0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL44           (*(volatile hw_sdmaarm_sdma_chnenbl44_t *) HW_SDMAARM_SDMA_CHNENBL44_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL44_RD()      (HW_SDMAARM_SDMA_CHNENBL44.U)
#define HW_SDMAARM_SDMA_CHNENBL44_WR(v)     (HW_SDMAARM_SDMA_CHNENBL44.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL44_SET(v)    (HW_SDMAARM_SDMA_CHNENBL44_WR(HW_SDMAARM_SDMA_CHNENBL44_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL44_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL44_WR(HW_SDMAARM_SDMA_CHNENBL44_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL44_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL44_WR(HW_SDMAARM_SDMA_CHNENBL44_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL44 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL44, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL44_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL44_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL44_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL44_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL44_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL44_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL44_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL44_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL44_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL44_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL44_ENBLN) & BM_SDMAARM_SDMA_CHNENBL44_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL44_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL44_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL44_ENBLN) & BM_SDMAARM_SDMA_CHNENBL44_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL44_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL44_WR((HW_SDMAARM_SDMA_CHNENBL44_RD() & ~BM_SDMAARM_SDMA_CHNENBL44_ENBLN) | BF_SDMAARM_SDMA_CHNENBL44_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL45 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl45
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl45_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl45_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL45 register
 */
#define HW_SDMAARM_SDMA_CHNENBL45_ADDR      (REGS_SDMAARM_BASE + 0x2b4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL45           (*(volatile hw_sdmaarm_sdma_chnenbl45_t *) HW_SDMAARM_SDMA_CHNENBL45_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL45_RD()      (HW_SDMAARM_SDMA_CHNENBL45.U)
#define HW_SDMAARM_SDMA_CHNENBL45_WR(v)     (HW_SDMAARM_SDMA_CHNENBL45.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL45_SET(v)    (HW_SDMAARM_SDMA_CHNENBL45_WR(HW_SDMAARM_SDMA_CHNENBL45_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL45_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL45_WR(HW_SDMAARM_SDMA_CHNENBL45_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL45_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL45_WR(HW_SDMAARM_SDMA_CHNENBL45_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL45 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL45, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL45_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL45_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL45_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL45_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL45_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL45_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL45_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL45_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL45_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL45_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL45_ENBLN) & BM_SDMAARM_SDMA_CHNENBL45_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL45_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL45_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL45_ENBLN) & BM_SDMAARM_SDMA_CHNENBL45_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL45_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL45_WR((HW_SDMAARM_SDMA_CHNENBL45_RD() & ~BM_SDMAARM_SDMA_CHNENBL45_ENBLN) | BF_SDMAARM_SDMA_CHNENBL45_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL46 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl46
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl46_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl46_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL46 register
 */
#define HW_SDMAARM_SDMA_CHNENBL46_ADDR      (REGS_SDMAARM_BASE + 0x2b8)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL46           (*(volatile hw_sdmaarm_sdma_chnenbl46_t *) HW_SDMAARM_SDMA_CHNENBL46_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL46_RD()      (HW_SDMAARM_SDMA_CHNENBL46.U)
#define HW_SDMAARM_SDMA_CHNENBL46_WR(v)     (HW_SDMAARM_SDMA_CHNENBL46.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL46_SET(v)    (HW_SDMAARM_SDMA_CHNENBL46_WR(HW_SDMAARM_SDMA_CHNENBL46_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL46_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL46_WR(HW_SDMAARM_SDMA_CHNENBL46_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL46_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL46_WR(HW_SDMAARM_SDMA_CHNENBL46_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL46 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL46, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL46_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL46_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL46_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL46_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL46_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL46_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL46_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL46_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL46_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL46_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL46_ENBLN) & BM_SDMAARM_SDMA_CHNENBL46_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL46_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL46_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL46_ENBLN) & BM_SDMAARM_SDMA_CHNENBL46_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL46_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL46_WR((HW_SDMAARM_SDMA_CHNENBL46_RD() & ~BM_SDMAARM_SDMA_CHNENBL46_ENBLN) | BF_SDMAARM_SDMA_CHNENBL46_ENBLN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_SDMAARM_SDMA_CHNENBL47 - Channel Enable RAM (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_sdmaarm_sdma_chnenbl47
{
    reg32_t U;
    struct _hw_sdmaarm_sdma_chnenbl47_bitfields
    {
        unsigned ENBLN : 32; //!< [31:0] This 32-bit value selects the channels that are triggered by the DMA request number n . If ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit registers are physically located in a RAM, with no known reset value. It is thus essential for the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an unpredictable combination of channels may be started.
    } B;
} hw_sdmaarm_sdma_chnenbl47_t;
#endif

/*
 * constants & macros for entire SDMAARM_SDMA_CHNENBL47 register
 */
#define HW_SDMAARM_SDMA_CHNENBL47_ADDR      (REGS_SDMAARM_BASE + 0x2bc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMAARM_SDMA_CHNENBL47           (*(volatile hw_sdmaarm_sdma_chnenbl47_t *) HW_SDMAARM_SDMA_CHNENBL47_ADDR)
#define HW_SDMAARM_SDMA_CHNENBL47_RD()      (HW_SDMAARM_SDMA_CHNENBL47.U)
#define HW_SDMAARM_SDMA_CHNENBL47_WR(v)     (HW_SDMAARM_SDMA_CHNENBL47.U = (v))
#define HW_SDMAARM_SDMA_CHNENBL47_SET(v)    (HW_SDMAARM_SDMA_CHNENBL47_WR(HW_SDMAARM_SDMA_CHNENBL47_RD() |  (v)))
#define HW_SDMAARM_SDMA_CHNENBL47_CLR(v)    (HW_SDMAARM_SDMA_CHNENBL47_WR(HW_SDMAARM_SDMA_CHNENBL47_RD() & ~(v)))
#define HW_SDMAARM_SDMA_CHNENBL47_TOG(v)    (HW_SDMAARM_SDMA_CHNENBL47_WR(HW_SDMAARM_SDMA_CHNENBL47_RD() ^  (v)))
#endif

/*
 * constants & macros for individual SDMAARM_SDMA_CHNENBL47 bitfields
 */

/* --- Register HW_SDMAARM_SDMA_CHNENBL47, field ENBLN[31:0] (RW)
 *
 * This 32-bit value selects the channels that are triggered by the DMA request number n . If
 * ENBLn[i] is set to 1, bit EP[i] will be set when the DMA request n is received. These 48 32-bit
 * registers are physically located in a RAM, with no known reset value. It is thus essential for
 * the ARM platform to program them before any DMA request is triggered to the SDMA, otherwise an
 * unpredictable combination of channels may be started.
 */

#define BP_SDMAARM_SDMA_CHNENBL47_ENBLN      (0)      //!< Bit position for SDMAARM_SDMA_CHNENBL47_ENBLN.
#define BM_SDMAARM_SDMA_CHNENBL47_ENBLN      (0xffffffff)  //!< Bit mask for SDMAARM_SDMA_CHNENBL47_ENBLN.

//! @brief Get value of SDMAARM_SDMA_CHNENBL47_ENBLN from a register value.
#define BG_SDMAARM_SDMA_CHNENBL47_ENBLN(r)   (((r) & BM_SDMAARM_SDMA_CHNENBL47_ENBLN) >> BP_SDMAARM_SDMA_CHNENBL47_ENBLN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL47_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL47_ENBLN(v)   ((((reg32_t) v) << BP_SDMAARM_SDMA_CHNENBL47_ENBLN) & BM_SDMAARM_SDMA_CHNENBL47_ENBLN)
#else
//! @brief Format value for bitfield SDMAARM_SDMA_CHNENBL47_ENBLN.
#define BF_SDMAARM_SDMA_CHNENBL47_ENBLN(v)   (((v) << BP_SDMAARM_SDMA_CHNENBL47_ENBLN) & BM_SDMAARM_SDMA_CHNENBL47_ENBLN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBLN field to a new value.
#define BW_SDMAARM_SDMA_CHNENBL47_ENBLN(v)   (HW_SDMAARM_SDMA_CHNENBL47_WR((HW_SDMAARM_SDMA_CHNENBL47_RD() & ~BM_SDMAARM_SDMA_CHNENBL47_ENBLN) | BF_SDMAARM_SDMA_CHNENBL47_ENBLN(v)))
#endif


/*!
 * @brief All SDMAARM module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_sdmaarm
{
    volatile hw_sdmaarm_mc0ptr_t MC0PTR; //!< ARM platform Channel 0 Pointer
    volatile hw_sdmaarm_intr_t INTR; //!< Channel Interrupts
    volatile hw_sdmaarm_stop_stat_t STOP_STAT; //!< Channel Stop/Channel Status
    volatile hw_sdmaarm_hstart_t HSTART; //!< Channel Start
    volatile hw_sdmaarm_evtovr_t EVTOVR; //!< Channel Event Override
    volatile hw_sdmaarm_dspovr_t DSPOVR; //!< Channel BP Override
    volatile hw_sdmaarm_hostovr_t HOSTOVR; //!< Channel ARM platform Override
    volatile hw_sdmaarm_evtpend_t EVTPEND; //!< Channel Event Pending
    reg32_t _reserved0;
    volatile hw_sdmaarm_reset_t RESET; //!< Reset Register
    volatile hw_sdmaarm_evterr_t EVTERR; //!< DMA Request Error Register
    volatile hw_sdmaarm_intrmask_t INTRMASK; //!< Channel ARM platform Interrupt Mask
    volatile hw_sdmaarm_psw_t PSW; //!< Schedule Status
    volatile hw_sdmaarm_evterrdbg_t EVTERRDBG; //!< DMA Request Error Register
    volatile hw_sdmaarm_config_t CONFIG; //!< Configuration Register
    volatile hw_sdmaarm_sdma_lock_t SDMA_LOCK; //!< SDMA LOCK
    volatile hw_sdmaarm_once_enb_t ONCE_ENB; //!< OnCE Enable
    volatile hw_sdmaarm_once_data_t ONCE_DATA; //!< OnCE Data Register
    volatile hw_sdmaarm_once_instr_t ONCE_INSTR; //!< OnCE Instruction Register
    volatile hw_sdmaarm_once_stat_t ONCE_STAT; //!< OnCE Status Register
    volatile hw_sdmaarm_once_cmd_t ONCE_CMD; //!< OnCE Command Register
    reg32_t _reserved1;
    volatile hw_sdmaarm_illinstaddr_t ILLINSTADDR; //!< Illegal Instruction Trap Address
    volatile hw_sdmaarm_chn0addr_t CHN0ADDR; //!< Channel 0 Boot Address
    volatile hw_sdmaarm_evt_mirror_t EVT_MIRROR; //!< DMA Requests
    volatile hw_sdmaarm_evt_mirror2_t EVT_MIRROR2; //!< DMA Requests 2
    reg32_t _reserved2[2];
    volatile hw_sdmaarm_xtrig_conf1_t XTRIG_CONF1; //!< Cross-Trigger Events Configuration Register 1
    volatile hw_sdmaarm_xtrig_conf2_t XTRIG_CONF2; //!< Cross-Trigger Events Configuration Register 2
    reg32_t _reserved3[34];
    volatile hw_sdmaarm_sdma_chnpri0_t SDMA_CHNPRI0; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri1_t SDMA_CHNPRI1; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri2_t SDMA_CHNPRI2; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri3_t SDMA_CHNPRI3; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri4_t SDMA_CHNPRI4; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri5_t SDMA_CHNPRI5; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri6_t SDMA_CHNPRI6; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri7_t SDMA_CHNPRI7; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri8_t SDMA_CHNPRI8; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri9_t SDMA_CHNPRI9; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri10_t SDMA_CHNPRI10; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri11_t SDMA_CHNPRI11; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri12_t SDMA_CHNPRI12; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri13_t SDMA_CHNPRI13; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri14_t SDMA_CHNPRI14; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri15_t SDMA_CHNPRI15; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri16_t SDMA_CHNPRI16; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri17_t SDMA_CHNPRI17; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri18_t SDMA_CHNPRI18; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri19_t SDMA_CHNPRI19; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri20_t SDMA_CHNPRI20; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri21_t SDMA_CHNPRI21; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri22_t SDMA_CHNPRI22; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri23_t SDMA_CHNPRI23; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri24_t SDMA_CHNPRI24; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri25_t SDMA_CHNPRI25; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri26_t SDMA_CHNPRI26; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri27_t SDMA_CHNPRI27; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri28_t SDMA_CHNPRI28; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri29_t SDMA_CHNPRI29; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri30_t SDMA_CHNPRI30; //!< Channel Priority Registers
    volatile hw_sdmaarm_sdma_chnpri31_t SDMA_CHNPRI31; //!< Channel Priority Registers
    reg32_t _reserved4[32];
    volatile hw_sdmaarm_sdma_chnenbl0_t SDMA_CHNENBL0; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl1_t SDMA_CHNENBL1; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl2_t SDMA_CHNENBL2; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl3_t SDMA_CHNENBL3; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl4_t SDMA_CHNENBL4; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl5_t SDMA_CHNENBL5; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl6_t SDMA_CHNENBL6; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl7_t SDMA_CHNENBL7; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl8_t SDMA_CHNENBL8; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl9_t SDMA_CHNENBL9; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl10_t SDMA_CHNENBL10; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl11_t SDMA_CHNENBL11; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl12_t SDMA_CHNENBL12; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl13_t SDMA_CHNENBL13; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl14_t SDMA_CHNENBL14; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl15_t SDMA_CHNENBL15; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl16_t SDMA_CHNENBL16; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl17_t SDMA_CHNENBL17; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl18_t SDMA_CHNENBL18; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl19_t SDMA_CHNENBL19; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl20_t SDMA_CHNENBL20; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl21_t SDMA_CHNENBL21; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl22_t SDMA_CHNENBL22; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl23_t SDMA_CHNENBL23; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl24_t SDMA_CHNENBL24; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl25_t SDMA_CHNENBL25; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl26_t SDMA_CHNENBL26; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl27_t SDMA_CHNENBL27; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl28_t SDMA_CHNENBL28; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl29_t SDMA_CHNENBL29; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl30_t SDMA_CHNENBL30; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl31_t SDMA_CHNENBL31; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl32_t SDMA_CHNENBL32; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl33_t SDMA_CHNENBL33; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl34_t SDMA_CHNENBL34; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl35_t SDMA_CHNENBL35; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl36_t SDMA_CHNENBL36; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl37_t SDMA_CHNENBL37; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl38_t SDMA_CHNENBL38; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl39_t SDMA_CHNENBL39; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl40_t SDMA_CHNENBL40; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl41_t SDMA_CHNENBL41; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl42_t SDMA_CHNENBL42; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl43_t SDMA_CHNENBL43; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl44_t SDMA_CHNENBL44; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl45_t SDMA_CHNENBL45; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl46_t SDMA_CHNENBL46; //!< Channel Enable RAM
    volatile hw_sdmaarm_sdma_chnenbl47_t SDMA_CHNENBL47; //!< Channel Enable RAM
} hw_sdmaarm_t;
#pragma pack()
#endif

//! @brief Macro to access all SDMAARM registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SDMAARM(0)</code>.
#define HW_SDMAARM     (*(volatile hw_sdmaarm_t *) REGS_SDMAARM_BASE)


#endif // _SDMAARM_H
