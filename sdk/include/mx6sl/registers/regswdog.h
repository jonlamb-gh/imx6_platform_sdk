/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_WDOG_REGISTERS_H__
#define __HW_WDOG_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SL WDOG
 *
 * WDOG
 *
 * Registers defined in this header file:
 * - HW_WDOG_WCR - Watchdog Control Register
 * - HW_WDOG_WSR - Watchdog Service Register
 * - HW_WDOG_WRSR - Watchdog Reset Status Register
 * - HW_WDOG_WICR - Watchdog Interrupt Control Register
 * - HW_WDOG_WMCR - Watchdog Miscellaneous Control Register
 *
 * - hw_wdog_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_WDOG_BASE
#define HW_WDOG_INSTANCE_COUNT (2) //!< Number of instances of the WDOG module.
#define HW_WDOG1 (1) //!< Instance number for WDOG1.
#define HW_WDOG2 (2) //!< Instance number for WDOG2.
#define REGS_WDOG1_BASE (0x020bc000) //!< Base address for WDOG instance number 1.
#define REGS_WDOG2_BASE (0x020c0000) //!< Base address for WDOG instance number 2.

//! @brief Get the base address of WDOG by instance number.
//! @param x WDOG instance number, from 1 through 2.
#define REGS_WDOG_BASE(x) ( (x) == HW_WDOG1 ? REGS_WDOG1_BASE : (x) == HW_WDOG2 ? REGS_WDOG2_BASE : 0x00d00000)

//! @brief Get the instance number given a base address.
//! @param b Base address for an instance of WDOG.
#define REGS_WDOG_INSTANCE(b) ( (b) == REGS_WDOG1_BASE ? HW_WDOG1 : (b) == REGS_WDOG2_BASE ? HW_WDOG2 : 0)
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_WDOG_WCR - Watchdog Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WCR - Watchdog Control Register (RW)
 *
 * Reset value: 0x0030
 *
 * The Watchdog Control Register (WDOG_WCR) controls the WDOG operation. WDZST, WDBG and WDW bits
 * are write-once only bits. Once the software does a write access to these bits, all these bits
 * will get locked and cannot be reprogrammed until the next system reset assertion. WDE is a write
 * one once only bit. Once software performs a write "1" operation to this bit it cannot be
 * reset/cleared until the next system reset. WDT is also a write one once only bit. Once software
 * performs a write "1" operation to this bit it cannot be reset/cleared until the next POR. This
 * bit does not gets reset/cleared due to any system reset.
 */
typedef union _hw_wdog_wcr
{
    reg16_t U;
    struct _hw_wdog_wcr_bitfields
    {
        unsigned short WDZST : 1; //!< [0] Watchdog Low Power.
        unsigned short WDBG : 1; //!< [1] Watchdog DEBUG Enable.
        unsigned short WDE : 1; //!< [2] Watchdog Enable.
        unsigned short WDT : 1; //!< [3] WDOG Time-out assertion.
        unsigned short SRS : 1; //!< [4] Software Reset Signal.
        unsigned short WDA : 1; //!< [5] WDOG assertion.
        unsigned short SRE : 1; //!< [6] software reset extension, an option way to generate software reset
        unsigned short WDW : 1; //!< [7] Watchdog Disable for Wait.
        unsigned short WT : 8; //!< [15:8] Watchdog Time-out Field.
    } B;
} hw_wdog_wcr_t;
#endif

/*!
 * @name Constants and macros for entire WDOG_WCR register
 */
//@{
#define HW_WDOG_WCR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WCR(x)           (*(volatile hw_wdog_wcr_t *) HW_WDOG_WCR_ADDR(x))
#define HW_WDOG_WCR_RD(x)        (HW_WDOG_WCR(x).U)
#define HW_WDOG_WCR_WR(x, v)     (HW_WDOG_WCR(x).U = (v))
#define HW_WDOG_WCR_SET(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) |  (v)))
#define HW_WDOG_WCR_CLR(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) & ~(v)))
#define HW_WDOG_WCR_TOG(x, v)    (HW_WDOG_WCR_WR(x, HW_WDOG_WCR_RD(x) ^  (v)))
#endif
//@}

/*
 * constants & macros for individual WDOG_WCR bitfields
 */

/*! @name Register WDOG_WCR, field WDZST[0] (RW)
 *
 * Watchdog Low Power. Determines the operation of the WDOG during low-power modes. This bit is
 * write once-only. The WDOG can continue/suspend the timer operation in the low-power modes (STOP
 * and DOZE mode).
 *
 * Values:
 * - 0 - Continue timer operation (Default).
 * - 1 - Suspend the watchdog timer.
 */
//@{

#define BP_WDOG_WCR_WDZST      (0)      //!< Bit position for WDOG_WCR_WDZST.
#define BM_WDOG_WCR_WDZST      (0x00000001)  //!< Bit mask for WDOG_WCR_WDZST.

//! @brief Get value of WDOG_WCR_WDZST from a register value.
#define BG_WDOG_WCR_WDZST(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_WDZST) >> BP_WDOG_WCR_WDZST)

//! @brief Format value for bitfield WDOG_WCR_WDZST.
#define BF_WDOG_WCR_WDZST(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_WDZST) & BM_WDOG_WCR_WDZST)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDZST field to a new value.
#define BW_WDOG_WCR_WDZST(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDZST) | BF_WDOG_WCR_WDZST(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field WDBG[1] (RW)
 *
 * Watchdog DEBUG Enable. Determines the operation of the WDOG during DEBUG mode. This bit is write
 * once-only.
 *
 * Values:
 * - 0 - Continue WDOG timer operation (Default).
 * - 1 - Suspend the watchdog timer.
 */
//@{

#define BP_WDOG_WCR_WDBG      (1)      //!< Bit position for WDOG_WCR_WDBG.
#define BM_WDOG_WCR_WDBG      (0x00000002)  //!< Bit mask for WDOG_WCR_WDBG.

//! @brief Get value of WDOG_WCR_WDBG from a register value.
#define BG_WDOG_WCR_WDBG(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_WDBG) >> BP_WDOG_WCR_WDBG)

//! @brief Format value for bitfield WDOG_WCR_WDBG.
#define BF_WDOG_WCR_WDBG(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_WDBG) & BM_WDOG_WCR_WDBG)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDBG field to a new value.
#define BW_WDOG_WCR_WDBG(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDBG) | BF_WDOG_WCR_WDBG(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field WDE[2] (RW)
 *
 * Watchdog Enable. Enables or disables the WDOG block. This is a write one once only bit. It is not
 * possible to clear this bit by a software write, once the bit is set. This bit can be set/reset in
 * debug mode (exception).
 *
 * Values:
 * - 0 - Disable the Watchdog (Default).
 * - 1 - Enable the Watchdog.
 */
//@{

#define BP_WDOG_WCR_WDE      (2)      //!< Bit position for WDOG_WCR_WDE.
#define BM_WDOG_WCR_WDE      (0x00000004)  //!< Bit mask for WDOG_WCR_WDE.

//! @brief Get value of WDOG_WCR_WDE from a register value.
#define BG_WDOG_WCR_WDE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_WDE) >> BP_WDOG_WCR_WDE)

//! @brief Format value for bitfield WDOG_WCR_WDE.
#define BF_WDOG_WCR_WDE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_WDE) & BM_WDOG_WCR_WDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDE field to a new value.
#define BW_WDOG_WCR_WDE(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDE) | BF_WDOG_WCR_WDE(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field WDT[3] (RW)
 *
 * WDOG Time-out assertion. Determines if the WDOG gets asserted upon a Watchdog Time-out Event.
 * This is a write-one once only bit. There is no effect on wdog_rst (WDOG Reset) upon writing on
 * this bit. WDOG gets asserted along with wdog_rst if this bit is set.
 *
 * Values:
 * - 0 - No effect on WDOG (Default).
 * - 1 - Assert WDOG upon a Watchdog Time-out event.
 */
//@{

#define BP_WDOG_WCR_WDT      (3)      //!< Bit position for WDOG_WCR_WDT.
#define BM_WDOG_WCR_WDT      (0x00000008)  //!< Bit mask for WDOG_WCR_WDT.

//! @brief Get value of WDOG_WCR_WDT from a register value.
#define BG_WDOG_WCR_WDT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_WDT) >> BP_WDOG_WCR_WDT)

//! @brief Format value for bitfield WDOG_WCR_WDT.
#define BF_WDOG_WCR_WDT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_WDT) & BM_WDOG_WCR_WDT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDT field to a new value.
#define BW_WDOG_WCR_WDT(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDT) | BF_WDOG_WCR_WDT(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field SRS[4] (RW)
 *
 * Software Reset Signal. Controls the software assertion of the WDOG-generated reset signal
 * wdog_rst . This bit automatically resets to "1" after it has been asserted to "0". This bit does
 * not generate the software reset to the block.
 *
 * Values:
 * - 0 - Assert system reset signal.
 * - 1 - No effect on the system (Default).
 */
//@{

#define BP_WDOG_WCR_SRS      (4)      //!< Bit position for WDOG_WCR_SRS.
#define BM_WDOG_WCR_SRS      (0x00000010)  //!< Bit mask for WDOG_WCR_SRS.

//! @brief Get value of WDOG_WCR_SRS from a register value.
#define BG_WDOG_WCR_SRS(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_SRS) >> BP_WDOG_WCR_SRS)

//! @brief Format value for bitfield WDOG_WCR_SRS.
#define BF_WDOG_WCR_SRS(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_SRS) & BM_WDOG_WCR_SRS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRS field to a new value.
#define BW_WDOG_WCR_SRS(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_SRS) | BF_WDOG_WCR_SRS(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field WDA[5] (RW)
 *
 * WDOG assertion. Controls the software assertion of the WDOG signal.
 *
 * Values:
 * - 0 - Assert WDOG output.
 * - 1 - No effect on system (Default).
 */
//@{

#define BP_WDOG_WCR_WDA      (5)      //!< Bit position for WDOG_WCR_WDA.
#define BM_WDOG_WCR_WDA      (0x00000020)  //!< Bit mask for WDOG_WCR_WDA.

//! @brief Get value of WDOG_WCR_WDA from a register value.
#define BG_WDOG_WCR_WDA(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_WDA) >> BP_WDOG_WCR_WDA)

//! @brief Format value for bitfield WDOG_WCR_WDA.
#define BF_WDOG_WCR_WDA(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_WDA) & BM_WDOG_WCR_WDA)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDA field to a new value.
#define BW_WDOG_WCR_WDA(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDA) | BF_WDOG_WCR_WDA(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field SRE[6] (RW)
 *
 * adopt a new way to generate a more robust software reset. This bit can be set/clear with IP bus
 * and will be reset with power-on reset .
 *
 * Values:
 * - 0 - using original way to generate software reset (default)
 * - 1 - using new way to generate software reset.
 */
//@{

#define BP_WDOG_WCR_SRE      (6)      //!< Bit position for WDOG_WCR_SRE.
#define BM_WDOG_WCR_SRE      (0x00000040)  //!< Bit mask for WDOG_WCR_SRE.

//! @brief Get value of WDOG_WCR_SRE from a register value.
#define BG_WDOG_WCR_SRE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_SRE) >> BP_WDOG_WCR_SRE)

//! @brief Format value for bitfield WDOG_WCR_SRE.
#define BF_WDOG_WCR_SRE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_SRE) & BM_WDOG_WCR_SRE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SRE field to a new value.
#define BW_WDOG_WCR_SRE(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_SRE) | BF_WDOG_WCR_SRE(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field WDW[7] (RW)
 *
 * Watchdog Disable for Wait. This bit determines the operation of WDOG during Low Power WAIT mode.
 * This is a write once only bit.
 *
 * Values:
 * - 0 - Continue WDOG timer operation (Default).
 * - 1 - Suspend WDOG timer operation.
 */
//@{

#define BP_WDOG_WCR_WDW      (7)      //!< Bit position for WDOG_WCR_WDW.
#define BM_WDOG_WCR_WDW      (0x00000080)  //!< Bit mask for WDOG_WCR_WDW.

//! @brief Get value of WDOG_WCR_WDW from a register value.
#define BG_WDOG_WCR_WDW(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_WDW) >> BP_WDOG_WCR_WDW)

//! @brief Format value for bitfield WDOG_WCR_WDW.
#define BF_WDOG_WCR_WDW(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_WDW) & BM_WDOG_WCR_WDW)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WDW field to a new value.
#define BW_WDOG_WCR_WDW(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WDW) | BF_WDOG_WCR_WDW(v)))
#endif

//@}

/*! @name Register WDOG_WCR, field WT[15:8] (RW)
 *
 * Watchdog Time-out Field. This 8-bit field contains the time-out value that is loaded into the
 * Watchdog counter after the service routine has been performed or after the Watchdog is enabled.
 * After reset, WT[7:0] must have a value written to it before enabling the Watchdog otherwise count
 * value of zero which is 0.5 seconds is loaded into the counter. The time-out value can be written
 * at any point of time but it is loaded to the counter at the time when WDOG is enabled or after
 * the service routine has been performed. For more information see .
 *
 * Values:
 * - 0x00 - - 0.5 Seconds (Default).
 * - 0x01 - - 1.0 Seconds.
 * - 0x02 - - 1.5 Seconds.
 * - 0x03 - - 2.0 Seconds.
 * - 0xff - - 128 Seconds.
 */
//@{

#define BP_WDOG_WCR_WT      (8)      //!< Bit position for WDOG_WCR_WT.
#define BM_WDOG_WCR_WT      (0x0000ff00)  //!< Bit mask for WDOG_WCR_WT.

//! @brief Get value of WDOG_WCR_WT from a register value.
#define BG_WDOG_WCR_WT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WCR_WT) >> BP_WDOG_WCR_WT)

//! @brief Format value for bitfield WDOG_WCR_WT.
#define BF_WDOG_WCR_WT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WCR_WT) & BM_WDOG_WCR_WT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WT field to a new value.
#define BW_WDOG_WCR_WT(x, v)   (HW_WDOG_WCR_WR(x, (HW_WDOG_WCR_RD(x) & ~BM_WDOG_WCR_WT) | BF_WDOG_WCR_WT(v)))
#endif

//@}

//-------------------------------------------------------------------------------------------
// HW_WDOG_WSR - Watchdog Service Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WSR - Watchdog Service Register (RW)
 *
 * Reset value: 0x0000
 *
 * When enabled, the WDOG requires that a service sequence be written to the Watchdog Service
 * Register (WSR) to prevent the timeout condition. Executing the service sequence will reload the
 * WDOG timeout counter.
 */
typedef union _hw_wdog_wsr
{
    reg16_t U;
    struct _hw_wdog_wsr_bitfields
    {
        unsigned short WSR : 16; //!< [15:0] Watchdog Service Register.
    } B;
} hw_wdog_wsr_t;
#endif

/*!
 * @name Constants and macros for entire WDOG_WSR register
 */
//@{
#define HW_WDOG_WSR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WSR(x)           (*(volatile hw_wdog_wsr_t *) HW_WDOG_WSR_ADDR(x))
#define HW_WDOG_WSR_RD(x)        (HW_WDOG_WSR(x).U)
#define HW_WDOG_WSR_WR(x, v)     (HW_WDOG_WSR(x).U = (v))
#define HW_WDOG_WSR_SET(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) |  (v)))
#define HW_WDOG_WSR_CLR(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) & ~(v)))
#define HW_WDOG_WSR_TOG(x, v)    (HW_WDOG_WSR_WR(x, HW_WDOG_WSR_RD(x) ^  (v)))
#endif
//@}

/*
 * constants & macros for individual WDOG_WSR bitfields
 */

/*! @name Register WDOG_WSR, field WSR[15:0] (RW)
 *
 * Watchdog Service Register. This 16-bit field contains the Watchdog service sequence. Both writes
 * must occur in the order listed prior to the time-out, but any number of instructions can be
 * executed between the two writes. The service sequence must be performed as follows:
 *
 * Values:
 * - 0x5555 - Write to the Watchdog Service Register (WDOG_WSR).
 * - 0xAAAA - Write to the Watchdog Service Register (WDOG_WSR).
 */
//@{

#define BP_WDOG_WSR_WSR      (0)      //!< Bit position for WDOG_WSR_WSR.
#define BM_WDOG_WSR_WSR      (0x0000ffff)  //!< Bit mask for WDOG_WSR_WSR.

//! @brief Get value of WDOG_WSR_WSR from a register value.
#define BG_WDOG_WSR_WSR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WSR_WSR) >> BP_WDOG_WSR_WSR)

//! @brief Format value for bitfield WDOG_WSR_WSR.
#define BF_WDOG_WSR_WSR(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WSR_WSR) & BM_WDOG_WSR_WSR)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WSR field to a new value.
#define BW_WDOG_WSR_WSR(x, v)   (HW_WDOG_WSR_WR(x, (HW_WDOG_WSR_RD(x) & ~BM_WDOG_WSR_WSR) | BF_WDOG_WSR_WSR(v)))
#endif

//@}

//-------------------------------------------------------------------------------------------
// HW_WDOG_WRSR - Watchdog Reset Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WRSR - Watchdog Reset Status Register (RO)
 *
 * Reset value: 0x0000
 *
 * The WRSR is a read-only register that records the source of the output reset assertion. It is not
 * cleared by a hard reset. Therefore, only one bit in the WRSR will always be asserted high. The
 * register will always indicate the source of the last reset generated due to WDOG. Read access to
 * this register is with one wait state. Any write performed on this register will generate a
 * Peripheral Bus Error . A reset can be generated by the following sources, as listed in priority
 * from highest to lowest: Watchdog Time-out Software Reset
 */
typedef union _hw_wdog_wrsr
{
    reg16_t U;
    struct _hw_wdog_wrsr_bitfields
    {
        unsigned short SFTW : 1; //!< [0] Software Reset.
        unsigned short TOUT : 1; //!< [1] Timeout.
        unsigned short RESERVED0 : 2; //!< [3:2] Reserved.
        unsigned short POR : 1; //!< [4] Power On Reset.
        unsigned short RESERVED1 : 11; //!< [15:5] Reserved.
    } B;
} hw_wdog_wrsr_t;
#endif

/*!
 * @name Constants and macros for entire WDOG_WRSR register
 */
//@{
#define HW_WDOG_WRSR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WRSR(x)           (*(volatile hw_wdog_wrsr_t *) HW_WDOG_WRSR_ADDR(x))
#define HW_WDOG_WRSR_RD(x)        (HW_WDOG_WRSR(x).U)
#endif
//@}

/*
 * constants & macros for individual WDOG_WRSR bitfields
 */

/*! @name Register WDOG_WRSR, field SFTW[0] (RO)
 *
 * Software Reset. Indicates whether the reset is the result of a WDOG software reset by asserting
 * SRS bit
 *
 * Values:
 * - 0 - Reset is not the result of a software reset.
 * - 1 - Reset is the result of a software reset.
 */
//@{

#define BP_WDOG_WRSR_SFTW      (0)      //!< Bit position for WDOG_WRSR_SFTW.
#define BM_WDOG_WRSR_SFTW      (0x00000001)  //!< Bit mask for WDOG_WRSR_SFTW.

//! @brief Get value of WDOG_WRSR_SFTW from a register value.
#define BG_WDOG_WRSR_SFTW(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WRSR_SFTW) >> BP_WDOG_WRSR_SFTW)

//@}

/*! @name Register WDOG_WRSR, field TOUT[1] (RO)
 *
 * Timeout. Indicates whether the reset is the result of a WDOG timeout.
 *
 * Values:
 * - 0 - Reset is not the result of a WDOG timeout.
 * - 1 - Reset is the result of a WDOG timeout.
 */
//@{

#define BP_WDOG_WRSR_TOUT      (1)      //!< Bit position for WDOG_WRSR_TOUT.
#define BM_WDOG_WRSR_TOUT      (0x00000002)  //!< Bit mask for WDOG_WRSR_TOUT.

//! @brief Get value of WDOG_WRSR_TOUT from a register value.
#define BG_WDOG_WRSR_TOUT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WRSR_TOUT) >> BP_WDOG_WRSR_TOUT)

//@}

/*! @name Register WDOG_WRSR, field POR[4] (RO)
 *
 * Power On Reset. Indicates whether the reset is the result of a power on reset.
 *
 * Values:
 * - 0 - Reset is not the result of a power on reset.
 * - 1 - Reset is the result of a power on reset.
 */
//@{

#define BP_WDOG_WRSR_POR      (4)      //!< Bit position for WDOG_WRSR_POR.
#define BM_WDOG_WRSR_POR      (0x00000010)  //!< Bit mask for WDOG_WRSR_POR.

//! @brief Get value of WDOG_WRSR_POR from a register value.
#define BG_WDOG_WRSR_POR(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WRSR_POR) >> BP_WDOG_WRSR_POR)

//@}

//-------------------------------------------------------------------------------------------
// HW_WDOG_WICR - Watchdog Interrupt Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WICR - Watchdog Interrupt Control Register (RW)
 *
 * Reset value: 0x0004
 *
 * The WDOG_WICR controls the WDOG interrupt generation.
 */
typedef union _hw_wdog_wicr
{
    reg16_t U;
    struct _hw_wdog_wicr_bitfields
    {
        unsigned short WICT : 8; //!< [7:0] Watchdog Interrupt Count Time-out (WICT) field determines, how long before the counter time-out must the interrupt occur.
        unsigned short RESERVED0 : 6; //!< [13:8] Reserved.
        unsigned short WTIS : 1; //!< [14] Watchdog TImer Interrupt Status bit will reflect the timer interrupt status, whether interrupt has occurred or not.
        unsigned short WIE : 1; //!< [15] Watchdog Timer Interrupt enable bit.
    } B;
} hw_wdog_wicr_t;
#endif

/*!
 * @name Constants and macros for entire WDOG_WICR register
 */
//@{
#define HW_WDOG_WICR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WICR(x)           (*(volatile hw_wdog_wicr_t *) HW_WDOG_WICR_ADDR(x))
#define HW_WDOG_WICR_RD(x)        (HW_WDOG_WICR(x).U)
#define HW_WDOG_WICR_WR(x, v)     (HW_WDOG_WICR(x).U = (v))
#define HW_WDOG_WICR_SET(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) |  (v)))
#define HW_WDOG_WICR_CLR(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) & ~(v)))
#define HW_WDOG_WICR_TOG(x, v)    (HW_WDOG_WICR_WR(x, HW_WDOG_WICR_RD(x) ^  (v)))
#endif
//@}

/*
 * constants & macros for individual WDOG_WICR bitfields
 */

/*! @name Register WDOG_WICR, field WICT[7:0] (RW)
 *
 * Watchdog Interrupt Count Time-out (WICT) field determines, how long before the counter time-out
 * must the interrupt occur. The reset value is 0x04 implies interrupt will occur 2 seconds before
 * time-out. The maximum value that can be programmed to WICT field is 127.5 seconds with a
 * resolution of 0.5 seconds. This field is write once only. Once the software does a write access
 * to this field, it will get locked and cannot be reprogrammed until the next system reset
 * assertion.
 *
 * Values:
 * - 0x00 - WICT[7:0] = Time duration between interrupt and time-out is 0 seconds.
 * - 0x01 - WICT[7:0] = Time duration between interrupt and time-out is 0.5 seconds.
 * - 0x04 - WICT[7:0] = Time duration between interrupt and time-out is 2 seconds (Default).
 * - 0xff - WICT[7:0] = Time duration between interrupt and time-out is 127.5 seconds.
 */
//@{

#define BP_WDOG_WICR_WICT      (0)      //!< Bit position for WDOG_WICR_WICT.
#define BM_WDOG_WICR_WICT      (0x000000ff)  //!< Bit mask for WDOG_WICR_WICT.

//! @brief Get value of WDOG_WICR_WICT from a register value.
#define BG_WDOG_WICR_WICT(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WICR_WICT) >> BP_WDOG_WICR_WICT)

//! @brief Format value for bitfield WDOG_WICR_WICT.
#define BF_WDOG_WICR_WICT(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WICR_WICT) & BM_WDOG_WICR_WICT)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WICT field to a new value.
#define BW_WDOG_WICR_WICT(x, v)   (HW_WDOG_WICR_WR(x, (HW_WDOG_WICR_RD(x) & ~BM_WDOG_WICR_WICT) | BF_WDOG_WICR_WICT(v)))
#endif

//@}

/*! @name Register WDOG_WICR, field WTIS[14] (W1C)
 *
 * Watchdog TImer Interrupt Status bit will reflect the timer interrupt status, whether interrupt
 * has occurred or not. Once the interrupt has been triggered software must clear this bit by
 * writing 1 to it.
 *
 * Values:
 * - 0 - No interrupt has occurred (Default).
 * - 1 - Interrupt has occurred
 */
//@{

#define BP_WDOG_WICR_WTIS      (14)      //!< Bit position for WDOG_WICR_WTIS.
#define BM_WDOG_WICR_WTIS      (0x00004000)  //!< Bit mask for WDOG_WICR_WTIS.

//! @brief Get value of WDOG_WICR_WTIS from a register value.
#define BG_WDOG_WICR_WTIS(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WICR_WTIS) >> BP_WDOG_WICR_WTIS)

//! @brief Format value for bitfield WDOG_WICR_WTIS.
#define BF_WDOG_WICR_WTIS(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WICR_WTIS) & BM_WDOG_WICR_WTIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WTIS field to a new value.
#define BW_WDOG_WICR_WTIS(x, v)   (HW_WDOG_WICR_WR(x, (HW_WDOG_WICR_RD(x) & ~BM_WDOG_WICR_WTIS) | BF_WDOG_WICR_WTIS(v)))
#endif

//@}

/*! @name Register WDOG_WICR, field WIE[15] (RW)
 *
 * Watchdog Timer Interrupt enable bit. Reset value is 0. This bit is a write once only bit. Once
 * the software does a write access to this bit, it will get locked and cannot be reprogrammed until
 * the next system reset assertion
 *
 * Values:
 * - 0 - Disable Interrupt (Default).
 * - 1 - Enable Interrupt.
 */
//@{

#define BP_WDOG_WICR_WIE      (15)      //!< Bit position for WDOG_WICR_WIE.
#define BM_WDOG_WICR_WIE      (0x00008000)  //!< Bit mask for WDOG_WICR_WIE.

//! @brief Get value of WDOG_WICR_WIE from a register value.
#define BG_WDOG_WICR_WIE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WICR_WIE) >> BP_WDOG_WICR_WIE)

//! @brief Format value for bitfield WDOG_WICR_WIE.
#define BF_WDOG_WICR_WIE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WICR_WIE) & BM_WDOG_WICR_WIE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the WIE field to a new value.
#define BW_WDOG_WICR_WIE(x, v)   (HW_WDOG_WICR_WR(x, (HW_WDOG_WICR_RD(x) & ~BM_WDOG_WICR_WIE) | BF_WDOG_WICR_WIE(v)))
#endif

//@}

//-------------------------------------------------------------------------------------------
// HW_WDOG_WMCR - Watchdog Miscellaneous Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_WDOG_WMCR - Watchdog Miscellaneous Control Register (RW)
 *
 * Reset value: 0x0001
 *
 * WDOG_WMCR Controls the Power Down counter operation.
 */
typedef union _hw_wdog_wmcr
{
    reg16_t U;
    struct _hw_wdog_wmcr_bitfields
    {
        unsigned short PDE : 1; //!< [0] Power Down Enable bit.
        unsigned short RESERVED0 : 15; //!< [15:1] Reserved.
    } B;
} hw_wdog_wmcr_t;
#endif

/*!
 * @name Constants and macros for entire WDOG_WMCR register
 */
//@{
#define HW_WDOG_WMCR_ADDR(x)      (REGS_WDOG_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_WDOG_WMCR(x)           (*(volatile hw_wdog_wmcr_t *) HW_WDOG_WMCR_ADDR(x))
#define HW_WDOG_WMCR_RD(x)        (HW_WDOG_WMCR(x).U)
#define HW_WDOG_WMCR_WR(x, v)     (HW_WDOG_WMCR(x).U = (v))
#define HW_WDOG_WMCR_SET(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) |  (v)))
#define HW_WDOG_WMCR_CLR(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) & ~(v)))
#define HW_WDOG_WMCR_TOG(x, v)    (HW_WDOG_WMCR_WR(x, HW_WDOG_WMCR_RD(x) ^  (v)))
#endif
//@}

/*
 * constants & macros for individual WDOG_WMCR bitfields
 */

/*! @name Register WDOG_WMCR, field PDE[0] (RW)
 *
 * Power Down Enable bit. Reset value of this bit is 1, which means the power down counter inside
 * the WDOG is enabled after reset. The software must write 0 to this bit to disable the counter
 * within 16 seconds of reset de-assertion. Once disabled this counter cannot be enabled again. See
 * for operation of this counter. This bit is write-one once only bit. Once software sets this bit
 * it cannot be reset until the next system reset.
 *
 * Values:
 * - 0 - Power Down Counter of WDOG is disabled.
 * - 1 - Power Down Counter of WDOG is enabled (Default).
 */
//@{

#define BP_WDOG_WMCR_PDE      (0)      //!< Bit position for WDOG_WMCR_PDE.
#define BM_WDOG_WMCR_PDE      (0x00000001)  //!< Bit mask for WDOG_WMCR_PDE.

//! @brief Get value of WDOG_WMCR_PDE from a register value.
#define BG_WDOG_WMCR_PDE(r)   ((__REG_VALUE_TYPE((r), reg16_t) & BM_WDOG_WMCR_PDE) >> BP_WDOG_WMCR_PDE)

//! @brief Format value for bitfield WDOG_WMCR_PDE.
#define BF_WDOG_WMCR_PDE(v)   ((__REG_VALUE_TYPE((v), reg16_t) << BP_WDOG_WMCR_PDE) & BM_WDOG_WMCR_PDE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDE field to a new value.
#define BW_WDOG_WMCR_PDE(x, v)   (HW_WDOG_WMCR_WR(x, (HW_WDOG_WMCR_RD(x) & ~BM_WDOG_WMCR_PDE) | BF_WDOG_WMCR_PDE(v)))
#endif

//@}

//-------------------------------------------------------------------------------------------
// hw_wdog_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All WDOG module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_wdog
{
    volatile hw_wdog_wcr_t WCR; //!< Watchdog Control Register
    volatile hw_wdog_wsr_t WSR; //!< Watchdog Service Register
    volatile hw_wdog_wrsr_t WRSR; //!< Watchdog Reset Status Register
    volatile hw_wdog_wicr_t WICR; //!< Watchdog Interrupt Control Register
    volatile hw_wdog_wmcr_t WMCR; //!< Watchdog Miscellaneous Control Register
} hw_wdog_t;
#pragma pack()

//! @brief Macro to access all WDOG registers.
//! @param x WDOG instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_WDOG(0)</code>.
#define HW_WDOG(x)     (*(hw_wdog_t *) REGS_WDOG_BASE(x))
#endif

#endif // __HW_WDOG_REGISTERS_H__
