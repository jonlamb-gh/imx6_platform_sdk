/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef __HW_AIPSTZ_REGISTERS_H__
#define __HW_AIPSTZ_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6DQ AIPSTZ registers defined in this header file.
 *
 * - HW_AIPSTZ_MPR - Master Priviledge Registers
 * - HW_AIPSTZ_OPACR - Off-Platform Peripheral Access Control Registers
 * - HW_AIPSTZ_OPACR1 - Off-Platform Peripheral Access Control Registers
 * - HW_AIPSTZ_OPACR2 - Off-Platform Peripheral Access Control Registers
 * - HW_AIPSTZ_OPACR3 - Off-Platform Peripheral Access Control Registers
 * - HW_AIPSTZ_OPACR4 - Off-Platform Peripheral Access Control Registers
 *
 * - hw_aipstz_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_AIPSTZ_BASE
#define HW_AIPSTZ_INSTANCE_COUNT (2) //!< Number of instances of the AIPSTZ module.
#define HW_AIPSTZ1 (1) //!< Instance number for AIPSTZ1.
#define HW_AIPSTZ2 (2) //!< Instance number for AIPSTZ2.

#define REGS_AIPSTZ1_BASE (0x02000000) //!< Base address for AIPSTZ instance number 1.
#define REGS_AIPSTZ2_BASE (0x02100000) //!< Base address for AIPSTZ instance number 2.

//! @brief Get the base address of AIPSTZ by instance number.
//! @param x AIPSTZ instance number, from 1 through 2.
#define REGS_AIPSTZ_BASE(x) ( (x) == HW_AIPSTZ1 ? REGS_AIPSTZ1_BASE : (x) == HW_AIPSTZ2 ? REGS_AIPSTZ2_BASE : 0x00d00000)

//! @brief Get the instance number given a base address.
//! @param b Base address for an instance of AIPSTZ.
#define REGS_AIPSTZ_INSTANCE(b) ( (b) == REGS_AIPSTZ1_BASE ? HW_AIPSTZ1 : (b) == REGS_AIPSTZ2_BASE ? HW_AIPSTZ2 : 0)
#endif
//@}


//-------------------------------------------------------------------------------------------
// HW_AIPSTZ_MPR - Master Priviledge Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AIPSTZ_MPR - Master Priviledge Registers (RW)
 *
 * Reset value: 0x0496ed40
 *
 * Each AIPSTZ_MPR specifies eight 4-bit fields defining the access privilege level associated with
 * a bus master in the platform, as well as specifying whether write accesses from this master are
 * bufferable shown in  The registers provide one field per bus master, where field 15 corresponds
 * to master 15, field 14 to master 14,... field 0 to master 0 (typically the processor core). The
 * master index allocation is shown in   MPROT Field         Bit    Field    Description        3
 * MBW    Master Buffer Writes - This bit determines whether the AIPSTZ is enabled to buffer writes
 * from this master.      2    MTR    Master Trusted for Reads - This bit determines whether the
 * master is trusted for read accesses.      1    MTW    Master Trusted for Writes - This bit
 * determines whether the master is trusted for write accesses.      0    MPL    Master Privilege
 * Level - This bit determines how the privilege level of the master is determined.       The reset
 * value is set to 0000_0000_7700_0000, which makes master 0 and master 1 (ARM CORE) the trusted
 * masters. Trusted software can change the settings after reset.   Master Index Allocation
 * Master Index    Master Name    Comments        Master 0    All masters excluding ARM core , SDMA
 * and CAAM    Share the same number allocation.      Master 1    ARM CORE         Master 2    CAAM
 * Master 3    SDMA         Master 4-15    Reserved
 */
typedef union _hw_aipstz_mpr
{
    reg32_t U;
    struct _hw_aipstz_mpr_bitfields
    {
        unsigned RESERVED0 : 16; //!< [15:0] Reserved
        unsigned MPROT3 : 4; //!< [19:16] Master 3 Priviledge, Buffer, Read, Write Control.
        unsigned MPROT2 : 4; //!< [23:20] Master 2 Priviledge, Buffer, Read, Write Control
        unsigned MPROT1 : 4; //!< [27:24] Master 1 Priviledge, Buffer, Read, Write Control
        unsigned MPROT0 : 4; //!< [31:28] Master 0 Priviledge, Buffer, Read, Write Control
    } B;
} hw_aipstz_mpr_t;
#endif

/*
 * constants & macros for entire multi-block AIPSTZ_MPR register
 */
#define HW_AIPSTZ_MPR_ADDR(x)      (REGS_AIPSTZ_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_AIPSTZ_MPR(x)           (*(volatile hw_aipstz_mpr_t *) HW_AIPSTZ_MPR_ADDR(x))
#define HW_AIPSTZ_MPR_RD(x)        (HW_AIPSTZ_MPR(x).U)
#define HW_AIPSTZ_MPR_WR(x, v)     (HW_AIPSTZ_MPR(x).U = (v))
#define HW_AIPSTZ_MPR_SET(x, v)    (HW_AIPSTZ_MPR_WR(x, HW_AIPSTZ_MPR_RD(x) |  (v)))
#define HW_AIPSTZ_MPR_CLR(x, v)    (HW_AIPSTZ_MPR_WR(x, HW_AIPSTZ_MPR_RD(x) & ~(v)))
#define HW_AIPSTZ_MPR_TOG(x, v)    (HW_AIPSTZ_MPR_WR(x, HW_AIPSTZ_MPR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual AIPSTZ_MPR bitfields
 */

/* --- Register HW_AIPSTZ_MPR, field MPROT3[19:16] (RW)
 *
 * Master 3 Priviledge, Buffer, Read, Write Control.
 *
 * Values:
 * MPL = xxx0 - Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero)
 *     regardless of the hprot[1] access attribute.
 * MTW = xx0x - This master is not trusted for write accesses.
 * MTR = x0xx - This master is not trusted for read accesses.
 * MBW = 0xxx - Write accesses from this master are not bufferable
 * MPL = xxx1 - Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used
 *     directly to determine ips_supervisor_access.
 * MTW = xx1x - This master is trusted for write accesses.
 * MTR = x1xx - This master is trusted for read accesses.
 * MBW = 1xxx - Write accesses from this master are allowed to be buffered
 */

#define BP_AIPSTZ_MPR_MPROT3      (16)      //!< Bit position for AIPSTZ_MPR_MPROT3.
#define BM_AIPSTZ_MPR_MPROT3      (0x000f0000)  //!< Bit mask for AIPSTZ_MPR_MPROT3.

//! @brief Get value of AIPSTZ_MPR_MPROT3 from a register value.
#define BG_AIPSTZ_MPR_MPROT3(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_MPR_MPROT3) >> BP_AIPSTZ_MPR_MPROT3)

//! @brief Format value for bitfield AIPSTZ_MPR_MPROT3.
#define BF_AIPSTZ_MPR_MPROT3(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_MPR_MPROT3) & BM_AIPSTZ_MPR_MPROT3)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPROT3 field to a new value.
#define BW_AIPSTZ_MPR_MPROT3(x, v)   (HW_AIPSTZ_MPR_WR(x, (HW_AIPSTZ_MPR_RD(x) & ~BM_AIPSTZ_MPR_MPROT3) | BF_AIPSTZ_MPR_MPROT3(v)))
#endif

#define BV_AIPSTZ_MPR_MPROT3__MPL (0x0) //!< Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
#define BV_AIPSTZ_MPR_MPROT3__MTW (0x0) //!< This master is not trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT3__MTR (0x0) //!< This master is not trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT3__MBW (0x0) //!< Write accesses from this master are not bufferable
#define BV_AIPSTZ_MPR_MPROT3__MPL (0x1) //!< Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
#define BV_AIPSTZ_MPR_MPROT3__MTW (0x2) //!< This master is trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT3__MTR (0x4) //!< This master is trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT3__MBW (0x8) //!< Write accesses from this master are allowed to be buffered

/* --- Register HW_AIPSTZ_MPR, field MPROT2[23:20] (RW)
 *
 * Master 2 Priviledge, Buffer, Read, Write Control
 *
 * Values:
 * MPL = xxx0 - Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero)
 *     regardless of the hprot[1] access attribute.
 * MTW = xx0x - This master is not trusted for write accesses.
 * MTR = x0xx - This master is not trusted for read accesses.
 * MBW = 0xxx - Write accesses from this master are not bufferable
 * MPL = xxx1 - Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used
 *     directly to determine ips_supervisor_access.
 * MTW = xx1x - This master is trusted for write accesses.
 * MTR = x1xx - This master is trusted for read accesses.
 * MBW = 1xxx - Write accesses from this master are allowed to be buffered
 */

#define BP_AIPSTZ_MPR_MPROT2      (20)      //!< Bit position for AIPSTZ_MPR_MPROT2.
#define BM_AIPSTZ_MPR_MPROT2      (0x00f00000)  //!< Bit mask for AIPSTZ_MPR_MPROT2.

//! @brief Get value of AIPSTZ_MPR_MPROT2 from a register value.
#define BG_AIPSTZ_MPR_MPROT2(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_MPR_MPROT2) >> BP_AIPSTZ_MPR_MPROT2)

//! @brief Format value for bitfield AIPSTZ_MPR_MPROT2.
#define BF_AIPSTZ_MPR_MPROT2(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_MPR_MPROT2) & BM_AIPSTZ_MPR_MPROT2)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPROT2 field to a new value.
#define BW_AIPSTZ_MPR_MPROT2(x, v)   (HW_AIPSTZ_MPR_WR(x, (HW_AIPSTZ_MPR_RD(x) & ~BM_AIPSTZ_MPR_MPROT2) | BF_AIPSTZ_MPR_MPROT2(v)))
#endif

#define BV_AIPSTZ_MPR_MPROT2__MPL (0x0) //!< Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
#define BV_AIPSTZ_MPR_MPROT2__MTW (0x0) //!< This master is not trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT2__MTR (0x0) //!< This master is not trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT2__MBW (0x0) //!< Write accesses from this master are not bufferable
#define BV_AIPSTZ_MPR_MPROT2__MPL (0x1) //!< Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
#define BV_AIPSTZ_MPR_MPROT2__MTW (0x2) //!< This master is trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT2__MTR (0x4) //!< This master is trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT2__MBW (0x8) //!< Write accesses from this master are allowed to be buffered

/* --- Register HW_AIPSTZ_MPR, field MPROT1[27:24] (RW)
 *
 * Master 1 Priviledge, Buffer, Read, Write Control
 *
 * Values:
 * MPL = xxx0 - Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero)
 *     regardless of the hprot[1] access attribute.
 * MTW = xx0x - This master is not trusted for write accesses.
 * MTR = x0xx - This master is not trusted for read accesses.
 * MBW = 0xxx - Write accesses from this master are not bufferable
 * MPL = xxx1 - Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used
 *     directly to determine ips_supervisor_access.
 * MTW = xx1x - This master is trusted for write accesses.
 * MTR = x1xx - This master is trusted for read accesses.
 * MBW = 1xxx - Write accesses from this master are allowed to be buffered
 */

#define BP_AIPSTZ_MPR_MPROT1      (24)      //!< Bit position for AIPSTZ_MPR_MPROT1.
#define BM_AIPSTZ_MPR_MPROT1      (0x0f000000)  //!< Bit mask for AIPSTZ_MPR_MPROT1.

//! @brief Get value of AIPSTZ_MPR_MPROT1 from a register value.
#define BG_AIPSTZ_MPR_MPROT1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_MPR_MPROT1) >> BP_AIPSTZ_MPR_MPROT1)

//! @brief Format value for bitfield AIPSTZ_MPR_MPROT1.
#define BF_AIPSTZ_MPR_MPROT1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_MPR_MPROT1) & BM_AIPSTZ_MPR_MPROT1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPROT1 field to a new value.
#define BW_AIPSTZ_MPR_MPROT1(x, v)   (HW_AIPSTZ_MPR_WR(x, (HW_AIPSTZ_MPR_RD(x) & ~BM_AIPSTZ_MPR_MPROT1) | BF_AIPSTZ_MPR_MPROT1(v)))
#endif

#define BV_AIPSTZ_MPR_MPROT1__MPL (0x0) //!< Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
#define BV_AIPSTZ_MPR_MPROT1__MTW (0x0) //!< This master is not trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT1__MTR (0x0) //!< This master is not trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT1__MBW (0x0) //!< Write accesses from this master are not bufferable
#define BV_AIPSTZ_MPR_MPROT1__MPL (0x1) //!< Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
#define BV_AIPSTZ_MPR_MPROT1__MTW (0x2) //!< This master is trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT1__MTR (0x4) //!< This master is trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT1__MBW (0x8) //!< Write accesses from this master are allowed to be buffered

/* --- Register HW_AIPSTZ_MPR, field MPROT0[31:28] (RW)
 *
 * Master 0 Priviledge, Buffer, Read, Write Control
 *
 * Values:
 * MPL = xxx0 - Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero)
 *     regardless of the hprot[1] access attribute.
 * MTW = xx0x - This master is not trusted for write accesses.
 * MTR = x0xx - This master is not trusted for read accesses.
 * MBW = 0xxx - Write accesses from this master are not bufferable
 * MPL = xxx1 - Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used
 *     directly to determine ips_supervisor_access.
 * MTW = xx1x - This master is trusted for write accesses.
 * MTR = x1xx - This master is trusted for read accesses.
 * MBW = 1xxx - Write accesses from this master are allowed to be buffered
 */

#define BP_AIPSTZ_MPR_MPROT0      (28)      //!< Bit position for AIPSTZ_MPR_MPROT0.
#define BM_AIPSTZ_MPR_MPROT0      (0xf0000000)  //!< Bit mask for AIPSTZ_MPR_MPROT0.

//! @brief Get value of AIPSTZ_MPR_MPROT0 from a register value.
#define BG_AIPSTZ_MPR_MPROT0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_MPR_MPROT0) >> BP_AIPSTZ_MPR_MPROT0)

//! @brief Format value for bitfield AIPSTZ_MPR_MPROT0.
#define BF_AIPSTZ_MPR_MPROT0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_MPR_MPROT0) & BM_AIPSTZ_MPR_MPROT0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MPROT0 field to a new value.
#define BW_AIPSTZ_MPR_MPROT0(x, v)   (HW_AIPSTZ_MPR_WR(x, (HW_AIPSTZ_MPR_RD(x) & ~BM_AIPSTZ_MPR_MPROT0) | BF_AIPSTZ_MPR_MPROT0(v)))
#endif

#define BV_AIPSTZ_MPR_MPROT0__MPL (0x0) //!< Accesses from this master are forced to user-mode (ips_supervisor_access is forced to zero) regardless of the hprot[1] access attribute.
#define BV_AIPSTZ_MPR_MPROT0__MTW (0x0) //!< This master is not trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT0__MTR (0x0) //!< This master is not trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT0__MBW (0x0) //!< Write accesses from this master are not bufferable
#define BV_AIPSTZ_MPR_MPROT0__MPL (0x1) //!< Accesses from this master are not forced to user-mode. The hprot[1] access attribute is used directly to determine ips_supervisor_access.
#define BV_AIPSTZ_MPR_MPROT0__MTW (0x2) //!< This master is trusted for write accesses.
#define BV_AIPSTZ_MPR_MPROT0__MTR (0x4) //!< This master is trusted for read accesses.
#define BV_AIPSTZ_MPR_MPROT0__MBW (0x8) //!< Write accesses from this master are allowed to be buffered

//-------------------------------------------------------------------------------------------
// HW_AIPSTZ_OPACR - Off-Platform Peripheral Access Control Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AIPSTZ_OPACR - Off-Platform Peripheral Access Control Registers (RW)
 *
 * Reset value: 0x44444444
 *
 * Each of the off-platform peripherals have an Off-platform Peripheral Access Control Register
 * (AIPSTZ_OPACR) which defines the access levels supported by the given block.  Each AIPSTZ_OPACR
 * has the following format shown in   OPAC Field         Bit    Field    Description        3    BW
 * Buffer Writes - This bit determines whether write accesses to this peripheral are allowed to be
 * buffered. Buffered writes are not available for AIPSTZ. This bit should be set to '0'.      2
 * SP    Supervisor Protect - This bit determines whether the peripheral requires supervisor
 * privilege level for access.      1    WP    Write Protect - This bit determines whether the
 * peripheral allows write accesses.      0    TP    Trusted Protect - This bit determines whether
 * the peripheral allows accesses from an untrusted master.
 */
typedef union _hw_aipstz_opacr
{
    reg32_t U;
    struct _hw_aipstz_opacr_bitfields
    {
        unsigned OPAC7 : 4; //!< [3:0] Off-platform Peripheral Access Control 7
        unsigned OPAC6 : 4; //!< [7:4] Off-platform Peripheral Access Control 6
        unsigned OPAC5 : 4; //!< [11:8] Off-platform Peripheral Access Control 5
        unsigned OPAC4 : 4; //!< [15:12] Off-platform Peripheral Access Control 4
        unsigned OPAC3 : 4; //!< [19:16] Off-platform Peripheral Access Control 3
        unsigned OPAC2 : 4; //!< [23:20] Off-platform Peripheral Access Control 2
        unsigned OPAC1 : 4; //!< [27:24] Off-platform Peripheral Access Control 1
        unsigned OPAC0 : 4; //!< [31:28] Off-platform Peripheral Access Control 0
    } B;
} hw_aipstz_opacr_t;
#endif

/*
 * constants & macros for entire multi-block AIPSTZ_OPACR register
 */
#define HW_AIPSTZ_OPACR_ADDR(x)      (REGS_AIPSTZ_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_AIPSTZ_OPACR(x)           (*(volatile hw_aipstz_opacr_t *) HW_AIPSTZ_OPACR_ADDR(x))
#define HW_AIPSTZ_OPACR_RD(x)        (HW_AIPSTZ_OPACR(x).U)
#define HW_AIPSTZ_OPACR_WR(x, v)     (HW_AIPSTZ_OPACR(x).U = (v))
#define HW_AIPSTZ_OPACR_SET(x, v)    (HW_AIPSTZ_OPACR_WR(x, HW_AIPSTZ_OPACR_RD(x) |  (v)))
#define HW_AIPSTZ_OPACR_CLR(x, v)    (HW_AIPSTZ_OPACR_WR(x, HW_AIPSTZ_OPACR_RD(x) & ~(v)))
#define HW_AIPSTZ_OPACR_TOG(x, v)    (HW_AIPSTZ_OPACR_WR(x, HW_AIPSTZ_OPACR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual AIPSTZ_OPACR bitfields
 */

/* --- Register HW_AIPSTZ_OPACR, field OPAC7[3:0] (RW)
 *
 * Off-platform Peripheral Access Control 7
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC7      (0)      //!< Bit position for AIPSTZ_OPACR_OPAC7.
#define BM_AIPSTZ_OPACR_OPAC7      (0x0000000f)  //!< Bit mask for AIPSTZ_OPACR_OPAC7.

//! @brief Get value of AIPSTZ_OPACR_OPAC7 from a register value.
#define BG_AIPSTZ_OPACR_OPAC7(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC7) >> BP_AIPSTZ_OPACR_OPAC7)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC7.
#define BF_AIPSTZ_OPACR_OPAC7(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC7) & BM_AIPSTZ_OPACR_OPAC7)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC7 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC7(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC7) | BF_AIPSTZ_OPACR_OPAC7(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC7__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC7__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC7__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC7__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC7__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC7__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC7__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC7__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR, field OPAC6[7:4] (RW)
 *
 * Off-platform Peripheral Access Control 6
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC6      (4)      //!< Bit position for AIPSTZ_OPACR_OPAC6.
#define BM_AIPSTZ_OPACR_OPAC6      (0x000000f0)  //!< Bit mask for AIPSTZ_OPACR_OPAC6.

//! @brief Get value of AIPSTZ_OPACR_OPAC6 from a register value.
#define BG_AIPSTZ_OPACR_OPAC6(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC6) >> BP_AIPSTZ_OPACR_OPAC6)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC6.
#define BF_AIPSTZ_OPACR_OPAC6(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC6) & BM_AIPSTZ_OPACR_OPAC6)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC6 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC6(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC6) | BF_AIPSTZ_OPACR_OPAC6(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC6__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC6__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC6__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC6__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC6__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC6__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC6__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC6__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR, field OPAC5[11:8] (RW)
 *
 * Off-platform Peripheral Access Control 5
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC5      (8)      //!< Bit position for AIPSTZ_OPACR_OPAC5.
#define BM_AIPSTZ_OPACR_OPAC5      (0x00000f00)  //!< Bit mask for AIPSTZ_OPACR_OPAC5.

//! @brief Get value of AIPSTZ_OPACR_OPAC5 from a register value.
#define BG_AIPSTZ_OPACR_OPAC5(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC5) >> BP_AIPSTZ_OPACR_OPAC5)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC5.
#define BF_AIPSTZ_OPACR_OPAC5(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC5) & BM_AIPSTZ_OPACR_OPAC5)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC5 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC5(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC5) | BF_AIPSTZ_OPACR_OPAC5(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC5__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC5__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC5__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC5__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC5__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC5__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC5__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC5__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR, field OPAC4[15:12] (RW)
 *
 * Off-platform Peripheral Access Control 4
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC4      (12)      //!< Bit position for AIPSTZ_OPACR_OPAC4.
#define BM_AIPSTZ_OPACR_OPAC4      (0x0000f000)  //!< Bit mask for AIPSTZ_OPACR_OPAC4.

//! @brief Get value of AIPSTZ_OPACR_OPAC4 from a register value.
#define BG_AIPSTZ_OPACR_OPAC4(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC4) >> BP_AIPSTZ_OPACR_OPAC4)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC4.
#define BF_AIPSTZ_OPACR_OPAC4(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC4) & BM_AIPSTZ_OPACR_OPAC4)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC4 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC4(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC4) | BF_AIPSTZ_OPACR_OPAC4(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC4__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC4__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC4__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC4__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC4__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC4__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC4__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC4__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR, field OPAC3[19:16] (RW)
 *
 * Off-platform Peripheral Access Control 3
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC3      (16)      //!< Bit position for AIPSTZ_OPACR_OPAC3.
#define BM_AIPSTZ_OPACR_OPAC3      (0x000f0000)  //!< Bit mask for AIPSTZ_OPACR_OPAC3.

//! @brief Get value of AIPSTZ_OPACR_OPAC3 from a register value.
#define BG_AIPSTZ_OPACR_OPAC3(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC3) >> BP_AIPSTZ_OPACR_OPAC3)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC3.
#define BF_AIPSTZ_OPACR_OPAC3(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC3) & BM_AIPSTZ_OPACR_OPAC3)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC3 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC3(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC3) | BF_AIPSTZ_OPACR_OPAC3(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC3__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC3__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC3__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC3__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC3__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC3__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC3__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC3__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR, field OPAC2[23:20] (RW)
 *
 * Off-platform Peripheral Access Control 2
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC2      (20)      //!< Bit position for AIPSTZ_OPACR_OPAC2.
#define BM_AIPSTZ_OPACR_OPAC2      (0x00f00000)  //!< Bit mask for AIPSTZ_OPACR_OPAC2.

//! @brief Get value of AIPSTZ_OPACR_OPAC2 from a register value.
#define BG_AIPSTZ_OPACR_OPAC2(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC2) >> BP_AIPSTZ_OPACR_OPAC2)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC2.
#define BF_AIPSTZ_OPACR_OPAC2(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC2) & BM_AIPSTZ_OPACR_OPAC2)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC2 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC2(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC2) | BF_AIPSTZ_OPACR_OPAC2(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC2__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC2__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC2__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC2__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC2__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC2__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC2__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC2__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR, field OPAC1[27:24] (RW)
 *
 * Off-platform Peripheral Access Control 1
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC1      (24)      //!< Bit position for AIPSTZ_OPACR_OPAC1.
#define BM_AIPSTZ_OPACR_OPAC1      (0x0f000000)  //!< Bit mask for AIPSTZ_OPACR_OPAC1.

//! @brief Get value of AIPSTZ_OPACR_OPAC1 from a register value.
#define BG_AIPSTZ_OPACR_OPAC1(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC1) >> BP_AIPSTZ_OPACR_OPAC1)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC1.
#define BF_AIPSTZ_OPACR_OPAC1(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC1) & BM_AIPSTZ_OPACR_OPAC1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC1 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC1(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC1) | BF_AIPSTZ_OPACR_OPAC1(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC1__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC1__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC1__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC1__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC1__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC1__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC1__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC1__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR, field OPAC0[31:28] (RW)
 *
 * Off-platform Peripheral Access Control 0
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR_OPAC0      (28)      //!< Bit position for AIPSTZ_OPACR_OPAC0.
#define BM_AIPSTZ_OPACR_OPAC0      (0xf0000000)  //!< Bit mask for AIPSTZ_OPACR_OPAC0.

//! @brief Get value of AIPSTZ_OPACR_OPAC0 from a register value.
#define BG_AIPSTZ_OPACR_OPAC0(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR_OPAC0) >> BP_AIPSTZ_OPACR_OPAC0)

//! @brief Format value for bitfield AIPSTZ_OPACR_OPAC0.
#define BF_AIPSTZ_OPACR_OPAC0(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR_OPAC0) & BM_AIPSTZ_OPACR_OPAC0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC0 field to a new value.
#define BW_AIPSTZ_OPACR_OPAC0(x, v)   (HW_AIPSTZ_OPACR_WR(x, (HW_AIPSTZ_OPACR_RD(x) & ~BM_AIPSTZ_OPACR_OPAC0) | BF_AIPSTZ_OPACR_OPAC0(v)))
#endif

#define BV_AIPSTZ_OPACR_OPAC0__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR_OPAC0__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR_OPAC0__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR_OPAC0__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR_OPAC0__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC0__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC0__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR_OPAC0__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

//-------------------------------------------------------------------------------------------
// HW_AIPSTZ_OPACR1 - Off-Platform Peripheral Access Control Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AIPSTZ_OPACR1 - Off-Platform Peripheral Access Control Registers (RW)
 *
 * Reset value: 0x44444444
 *
 * Each of the off-platform peripherals have an Off-platform Peripheral Access Control Register
 * (AIPSTZ_OPACR) which defines the access levels supported by the given block.  Each AIPSTZ_OPACR
 * has the following format shown in
 */
typedef union _hw_aipstz_opacr1
{
    reg32_t U;
    struct _hw_aipstz_opacr1_bitfields
    {
        unsigned OPAC15 : 4; //!< [3:0] Off-platform Peripheral Access Control 15
        unsigned OPAC14 : 4; //!< [7:4] Off-platform Peripheral Access Control 14
        unsigned OPAC13 : 4; //!< [11:8] Off-platform Peripheral Access Control 13
        unsigned OPAC12 : 4; //!< [15:12] Off-platform Peripheral Access Control 12
        unsigned OPAC11 : 4; //!< [19:16] Off-platform Peripheral Access Control 11
        unsigned OPAC10 : 4; //!< [23:20] Off-platform Peripheral Access Control 10
        unsigned OPAC9 : 4; //!< [27:24] Off-platform Peripheral Access Control 9
        unsigned OPAC8 : 4; //!< [31:28] Off-platform Peripheral Access Control 8
    } B;
} hw_aipstz_opacr1_t;
#endif

/*
 * constants & macros for entire multi-block AIPSTZ_OPACR1 register
 */
#define HW_AIPSTZ_OPACR1_ADDR(x)      (REGS_AIPSTZ_BASE(x) + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_AIPSTZ_OPACR1(x)           (*(volatile hw_aipstz_opacr1_t *) HW_AIPSTZ_OPACR1_ADDR(x))
#define HW_AIPSTZ_OPACR1_RD(x)        (HW_AIPSTZ_OPACR1(x).U)
#define HW_AIPSTZ_OPACR1_WR(x, v)     (HW_AIPSTZ_OPACR1(x).U = (v))
#define HW_AIPSTZ_OPACR1_SET(x, v)    (HW_AIPSTZ_OPACR1_WR(x, HW_AIPSTZ_OPACR1_RD(x) |  (v)))
#define HW_AIPSTZ_OPACR1_CLR(x, v)    (HW_AIPSTZ_OPACR1_WR(x, HW_AIPSTZ_OPACR1_RD(x) & ~(v)))
#define HW_AIPSTZ_OPACR1_TOG(x, v)    (HW_AIPSTZ_OPACR1_WR(x, HW_AIPSTZ_OPACR1_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual AIPSTZ_OPACR1 bitfields
 */

/* --- Register HW_AIPSTZ_OPACR1, field OPAC15[3:0] (RW)
 *
 * Off-platform Peripheral Access Control 15
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC15      (0)      //!< Bit position for AIPSTZ_OPACR1_OPAC15.
#define BM_AIPSTZ_OPACR1_OPAC15      (0x0000000f)  //!< Bit mask for AIPSTZ_OPACR1_OPAC15.

//! @brief Get value of AIPSTZ_OPACR1_OPAC15 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC15(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC15) >> BP_AIPSTZ_OPACR1_OPAC15)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC15.
#define BF_AIPSTZ_OPACR1_OPAC15(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC15) & BM_AIPSTZ_OPACR1_OPAC15)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC15 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC15(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC15) | BF_AIPSTZ_OPACR1_OPAC15(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC15__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC15__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC15__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC15__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC15__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC15__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC15__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC15__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR1, field OPAC14[7:4] (RW)
 *
 * Off-platform Peripheral Access Control 14
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC14      (4)      //!< Bit position for AIPSTZ_OPACR1_OPAC14.
#define BM_AIPSTZ_OPACR1_OPAC14      (0x000000f0)  //!< Bit mask for AIPSTZ_OPACR1_OPAC14.

//! @brief Get value of AIPSTZ_OPACR1_OPAC14 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC14(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC14) >> BP_AIPSTZ_OPACR1_OPAC14)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC14.
#define BF_AIPSTZ_OPACR1_OPAC14(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC14) & BM_AIPSTZ_OPACR1_OPAC14)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC14 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC14(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC14) | BF_AIPSTZ_OPACR1_OPAC14(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC14__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC14__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC14__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC14__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC14__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC14__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC14__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC14__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR1, field OPAC13[11:8] (RW)
 *
 * Off-platform Peripheral Access Control 13
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC13      (8)      //!< Bit position for AIPSTZ_OPACR1_OPAC13.
#define BM_AIPSTZ_OPACR1_OPAC13      (0x00000f00)  //!< Bit mask for AIPSTZ_OPACR1_OPAC13.

//! @brief Get value of AIPSTZ_OPACR1_OPAC13 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC13(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC13) >> BP_AIPSTZ_OPACR1_OPAC13)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC13.
#define BF_AIPSTZ_OPACR1_OPAC13(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC13) & BM_AIPSTZ_OPACR1_OPAC13)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC13 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC13(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC13) | BF_AIPSTZ_OPACR1_OPAC13(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC13__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC13__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC13__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC13__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC13__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC13__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC13__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC13__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR1, field OPAC12[15:12] (RW)
 *
 * Off-platform Peripheral Access Control 12
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC12      (12)      //!< Bit position for AIPSTZ_OPACR1_OPAC12.
#define BM_AIPSTZ_OPACR1_OPAC12      (0x0000f000)  //!< Bit mask for AIPSTZ_OPACR1_OPAC12.

//! @brief Get value of AIPSTZ_OPACR1_OPAC12 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC12(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC12) >> BP_AIPSTZ_OPACR1_OPAC12)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC12.
#define BF_AIPSTZ_OPACR1_OPAC12(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC12) & BM_AIPSTZ_OPACR1_OPAC12)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC12 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC12(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC12) | BF_AIPSTZ_OPACR1_OPAC12(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC12__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC12__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC12__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC12__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC12__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC12__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC12__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC12__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR1, field OPAC11[19:16] (RW)
 *
 * Off-platform Peripheral Access Control 11
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC11      (16)      //!< Bit position for AIPSTZ_OPACR1_OPAC11.
#define BM_AIPSTZ_OPACR1_OPAC11      (0x000f0000)  //!< Bit mask for AIPSTZ_OPACR1_OPAC11.

//! @brief Get value of AIPSTZ_OPACR1_OPAC11 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC11(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC11) >> BP_AIPSTZ_OPACR1_OPAC11)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC11.
#define BF_AIPSTZ_OPACR1_OPAC11(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC11) & BM_AIPSTZ_OPACR1_OPAC11)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC11 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC11(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC11) | BF_AIPSTZ_OPACR1_OPAC11(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC11__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC11__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC11__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC11__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC11__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC11__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC11__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC11__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR1, field OPAC10[23:20] (RW)
 *
 * Off-platform Peripheral Access Control 10
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC10      (20)      //!< Bit position for AIPSTZ_OPACR1_OPAC10.
#define BM_AIPSTZ_OPACR1_OPAC10      (0x00f00000)  //!< Bit mask for AIPSTZ_OPACR1_OPAC10.

//! @brief Get value of AIPSTZ_OPACR1_OPAC10 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC10(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC10) >> BP_AIPSTZ_OPACR1_OPAC10)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC10.
#define BF_AIPSTZ_OPACR1_OPAC10(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC10) & BM_AIPSTZ_OPACR1_OPAC10)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC10 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC10(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC10) | BF_AIPSTZ_OPACR1_OPAC10(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC10__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC10__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC10__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC10__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC10__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC10__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC10__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC10__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR1, field OPAC9[27:24] (RW)
 *
 * Off-platform Peripheral Access Control 9
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC9      (24)      //!< Bit position for AIPSTZ_OPACR1_OPAC9.
#define BM_AIPSTZ_OPACR1_OPAC9      (0x0f000000)  //!< Bit mask for AIPSTZ_OPACR1_OPAC9.

//! @brief Get value of AIPSTZ_OPACR1_OPAC9 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC9(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC9) >> BP_AIPSTZ_OPACR1_OPAC9)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC9.
#define BF_AIPSTZ_OPACR1_OPAC9(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC9) & BM_AIPSTZ_OPACR1_OPAC9)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC9 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC9(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC9) | BF_AIPSTZ_OPACR1_OPAC9(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC9__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC9__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC9__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC9__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC9__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC9__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC9__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC9__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR1, field OPAC8[31:28] (RW)
 *
 * Off-platform Peripheral Access Control 8
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR1_OPAC8      (28)      //!< Bit position for AIPSTZ_OPACR1_OPAC8.
#define BM_AIPSTZ_OPACR1_OPAC8      (0xf0000000)  //!< Bit mask for AIPSTZ_OPACR1_OPAC8.

//! @brief Get value of AIPSTZ_OPACR1_OPAC8 from a register value.
#define BG_AIPSTZ_OPACR1_OPAC8(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR1_OPAC8) >> BP_AIPSTZ_OPACR1_OPAC8)

//! @brief Format value for bitfield AIPSTZ_OPACR1_OPAC8.
#define BF_AIPSTZ_OPACR1_OPAC8(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR1_OPAC8) & BM_AIPSTZ_OPACR1_OPAC8)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC8 field to a new value.
#define BW_AIPSTZ_OPACR1_OPAC8(x, v)   (HW_AIPSTZ_OPACR1_WR(x, (HW_AIPSTZ_OPACR1_RD(x) & ~BM_AIPSTZ_OPACR1_OPAC8) | BF_AIPSTZ_OPACR1_OPAC8(v)))
#endif

#define BV_AIPSTZ_OPACR1_OPAC8__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR1_OPAC8__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR1_OPAC8__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR1_OPAC8__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR1_OPAC8__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC8__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC8__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR1_OPAC8__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

//-------------------------------------------------------------------------------------------
// HW_AIPSTZ_OPACR2 - Off-Platform Peripheral Access Control Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AIPSTZ_OPACR2 - Off-Platform Peripheral Access Control Registers (RW)
 *
 * Reset value: 0x44444444
 *
 * Each of the off-platform peripherals have an Off-platform Peripheral Access Control Register
 * (AIPSTZ_OPACR) which defines the access levels supported by the given block.  Each AIPSTZ_OPACR
 * has the following format shown in
 */
typedef union _hw_aipstz_opacr2
{
    reg32_t U;
    struct _hw_aipstz_opacr2_bitfields
    {
        unsigned OPAC23 : 4; //!< [3:0] Off-platform Peripheral Access Control 23
        unsigned OPAC22 : 4; //!< [7:4] Off-platform Peripheral Access Control 22
        unsigned OPAC21 : 4; //!< [11:8] Off-platform Peripheral Access Control 21
        unsigned OPAC20 : 4; //!< [15:12] Off-platform Peripheral Access Control 20
        unsigned OPAC19 : 4; //!< [19:16] Off-platform Peripheral Access Control 19
        unsigned OPAC18 : 4; //!< [23:20] Off-platform Peripheral Access Control 18
        unsigned OPAC17 : 4; //!< [27:24] Off-platform Peripheral Access Control 17
        unsigned OPAC16 : 4; //!< [31:28] Off-platform Peripheral Access Control 16
    } B;
} hw_aipstz_opacr2_t;
#endif

/*
 * constants & macros for entire multi-block AIPSTZ_OPACR2 register
 */
#define HW_AIPSTZ_OPACR2_ADDR(x)      (REGS_AIPSTZ_BASE(x) + 0x48)

#ifndef __LANGUAGE_ASM__
#define HW_AIPSTZ_OPACR2(x)           (*(volatile hw_aipstz_opacr2_t *) HW_AIPSTZ_OPACR2_ADDR(x))
#define HW_AIPSTZ_OPACR2_RD(x)        (HW_AIPSTZ_OPACR2(x).U)
#define HW_AIPSTZ_OPACR2_WR(x, v)     (HW_AIPSTZ_OPACR2(x).U = (v))
#define HW_AIPSTZ_OPACR2_SET(x, v)    (HW_AIPSTZ_OPACR2_WR(x, HW_AIPSTZ_OPACR2_RD(x) |  (v)))
#define HW_AIPSTZ_OPACR2_CLR(x, v)    (HW_AIPSTZ_OPACR2_WR(x, HW_AIPSTZ_OPACR2_RD(x) & ~(v)))
#define HW_AIPSTZ_OPACR2_TOG(x, v)    (HW_AIPSTZ_OPACR2_WR(x, HW_AIPSTZ_OPACR2_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual AIPSTZ_OPACR2 bitfields
 */

/* --- Register HW_AIPSTZ_OPACR2, field OPAC23[3:0] (RW)
 *
 * Off-platform Peripheral Access Control 23
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC23      (0)      //!< Bit position for AIPSTZ_OPACR2_OPAC23.
#define BM_AIPSTZ_OPACR2_OPAC23      (0x0000000f)  //!< Bit mask for AIPSTZ_OPACR2_OPAC23.

//! @brief Get value of AIPSTZ_OPACR2_OPAC23 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC23(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC23) >> BP_AIPSTZ_OPACR2_OPAC23)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC23.
#define BF_AIPSTZ_OPACR2_OPAC23(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC23) & BM_AIPSTZ_OPACR2_OPAC23)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC23 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC23(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC23) | BF_AIPSTZ_OPACR2_OPAC23(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC23__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC23__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC23__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC23__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC23__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC23__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC23__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC23__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR2, field OPAC22[7:4] (RW)
 *
 * Off-platform Peripheral Access Control 22
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC22      (4)      //!< Bit position for AIPSTZ_OPACR2_OPAC22.
#define BM_AIPSTZ_OPACR2_OPAC22      (0x000000f0)  //!< Bit mask for AIPSTZ_OPACR2_OPAC22.

//! @brief Get value of AIPSTZ_OPACR2_OPAC22 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC22(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC22) >> BP_AIPSTZ_OPACR2_OPAC22)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC22.
#define BF_AIPSTZ_OPACR2_OPAC22(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC22) & BM_AIPSTZ_OPACR2_OPAC22)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC22 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC22(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC22) | BF_AIPSTZ_OPACR2_OPAC22(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC22__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC22__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC22__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC22__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC22__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC22__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC22__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC22__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR2, field OPAC21[11:8] (RW)
 *
 * Off-platform Peripheral Access Control 21
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC21      (8)      //!< Bit position for AIPSTZ_OPACR2_OPAC21.
#define BM_AIPSTZ_OPACR2_OPAC21      (0x00000f00)  //!< Bit mask for AIPSTZ_OPACR2_OPAC21.

//! @brief Get value of AIPSTZ_OPACR2_OPAC21 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC21(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC21) >> BP_AIPSTZ_OPACR2_OPAC21)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC21.
#define BF_AIPSTZ_OPACR2_OPAC21(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC21) & BM_AIPSTZ_OPACR2_OPAC21)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC21 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC21(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC21) | BF_AIPSTZ_OPACR2_OPAC21(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC21__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC21__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC21__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC21__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC21__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC21__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC21__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC21__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR2, field OPAC20[15:12] (RW)
 *
 * Off-platform Peripheral Access Control 20
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC20      (12)      //!< Bit position for AIPSTZ_OPACR2_OPAC20.
#define BM_AIPSTZ_OPACR2_OPAC20      (0x0000f000)  //!< Bit mask for AIPSTZ_OPACR2_OPAC20.

//! @brief Get value of AIPSTZ_OPACR2_OPAC20 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC20(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC20) >> BP_AIPSTZ_OPACR2_OPAC20)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC20.
#define BF_AIPSTZ_OPACR2_OPAC20(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC20) & BM_AIPSTZ_OPACR2_OPAC20)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC20 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC20(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC20) | BF_AIPSTZ_OPACR2_OPAC20(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC20__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC20__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC20__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC20__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC20__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC20__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC20__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC20__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR2, field OPAC19[19:16] (RW)
 *
 * Off-platform Peripheral Access Control 19
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC19      (16)      //!< Bit position for AIPSTZ_OPACR2_OPAC19.
#define BM_AIPSTZ_OPACR2_OPAC19      (0x000f0000)  //!< Bit mask for AIPSTZ_OPACR2_OPAC19.

//! @brief Get value of AIPSTZ_OPACR2_OPAC19 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC19(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC19) >> BP_AIPSTZ_OPACR2_OPAC19)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC19.
#define BF_AIPSTZ_OPACR2_OPAC19(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC19) & BM_AIPSTZ_OPACR2_OPAC19)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC19 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC19(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC19) | BF_AIPSTZ_OPACR2_OPAC19(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC19__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC19__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC19__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC19__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC19__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC19__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC19__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC19__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR2, field OPAC18[23:20] (RW)
 *
 * Off-platform Peripheral Access Control 18
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC18      (20)      //!< Bit position for AIPSTZ_OPACR2_OPAC18.
#define BM_AIPSTZ_OPACR2_OPAC18      (0x00f00000)  //!< Bit mask for AIPSTZ_OPACR2_OPAC18.

//! @brief Get value of AIPSTZ_OPACR2_OPAC18 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC18(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC18) >> BP_AIPSTZ_OPACR2_OPAC18)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC18.
#define BF_AIPSTZ_OPACR2_OPAC18(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC18) & BM_AIPSTZ_OPACR2_OPAC18)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC18 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC18(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC18) | BF_AIPSTZ_OPACR2_OPAC18(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC18__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC18__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC18__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC18__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC18__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC18__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC18__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC18__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR2, field OPAC17[27:24] (RW)
 *
 * Off-platform Peripheral Access Control 17
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC17      (24)      //!< Bit position for AIPSTZ_OPACR2_OPAC17.
#define BM_AIPSTZ_OPACR2_OPAC17      (0x0f000000)  //!< Bit mask for AIPSTZ_OPACR2_OPAC17.

//! @brief Get value of AIPSTZ_OPACR2_OPAC17 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC17(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC17) >> BP_AIPSTZ_OPACR2_OPAC17)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC17.
#define BF_AIPSTZ_OPACR2_OPAC17(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC17) & BM_AIPSTZ_OPACR2_OPAC17)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC17 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC17(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC17) | BF_AIPSTZ_OPACR2_OPAC17(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC17__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC17__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC17__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC17__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC17__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC17__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC17__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC17__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR2, field OPAC16[31:28] (RW)
 *
 * Off-platform Peripheral Access Control 16
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR2_OPAC16      (28)      //!< Bit position for AIPSTZ_OPACR2_OPAC16.
#define BM_AIPSTZ_OPACR2_OPAC16      (0xf0000000)  //!< Bit mask for AIPSTZ_OPACR2_OPAC16.

//! @brief Get value of AIPSTZ_OPACR2_OPAC16 from a register value.
#define BG_AIPSTZ_OPACR2_OPAC16(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR2_OPAC16) >> BP_AIPSTZ_OPACR2_OPAC16)

//! @brief Format value for bitfield AIPSTZ_OPACR2_OPAC16.
#define BF_AIPSTZ_OPACR2_OPAC16(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR2_OPAC16) & BM_AIPSTZ_OPACR2_OPAC16)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC16 field to a new value.
#define BW_AIPSTZ_OPACR2_OPAC16(x, v)   (HW_AIPSTZ_OPACR2_WR(x, (HW_AIPSTZ_OPACR2_RD(x) & ~BM_AIPSTZ_OPACR2_OPAC16) | BF_AIPSTZ_OPACR2_OPAC16(v)))
#endif

#define BV_AIPSTZ_OPACR2_OPAC16__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR2_OPAC16__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR2_OPAC16__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR2_OPAC16__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR2_OPAC16__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC16__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC16__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR2_OPAC16__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

//-------------------------------------------------------------------------------------------
// HW_AIPSTZ_OPACR3 - Off-Platform Peripheral Access Control Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AIPSTZ_OPACR3 - Off-Platform Peripheral Access Control Registers (RW)
 *
 * Reset value: 0x44444444
 *
 * Each of the off-platform peripherals have an Off-platform Peripheral Access Control Register
 * (AIPSTZ_OPACR) which defines the access levels supported by the given block.  Each AIPSTZ_OPACR
 * has the following format shown in
 */
typedef union _hw_aipstz_opacr3
{
    reg32_t U;
    struct _hw_aipstz_opacr3_bitfields
    {
        unsigned OPAC31 : 4; //!< [3:0] Off-platform Peripheral Access Control 31
        unsigned OPAC30 : 4; //!< [7:4] Off-platform Peripheral Access Control 30
        unsigned OPAC29 : 4; //!< [11:8] Off-platform Peripheral Access Control 29
        unsigned OPAC28 : 4; //!< [15:12] Off-platform Peripheral Access Control 28
        unsigned OPAC27 : 4; //!< [19:16] Off-platform Peripheral Access Control 27
        unsigned OPAC26 : 4; //!< [23:20] Off-platform Peripheral Access Control 26
        unsigned OPAC25 : 4; //!< [27:24] Off-platform Peripheral Access Control 25
        unsigned OPAC24 : 4; //!< [31:28] Off-platform Peripheral Access Control 24
    } B;
} hw_aipstz_opacr3_t;
#endif

/*
 * constants & macros for entire multi-block AIPSTZ_OPACR3 register
 */
#define HW_AIPSTZ_OPACR3_ADDR(x)      (REGS_AIPSTZ_BASE(x) + 0x4c)

#ifndef __LANGUAGE_ASM__
#define HW_AIPSTZ_OPACR3(x)           (*(volatile hw_aipstz_opacr3_t *) HW_AIPSTZ_OPACR3_ADDR(x))
#define HW_AIPSTZ_OPACR3_RD(x)        (HW_AIPSTZ_OPACR3(x).U)
#define HW_AIPSTZ_OPACR3_WR(x, v)     (HW_AIPSTZ_OPACR3(x).U = (v))
#define HW_AIPSTZ_OPACR3_SET(x, v)    (HW_AIPSTZ_OPACR3_WR(x, HW_AIPSTZ_OPACR3_RD(x) |  (v)))
#define HW_AIPSTZ_OPACR3_CLR(x, v)    (HW_AIPSTZ_OPACR3_WR(x, HW_AIPSTZ_OPACR3_RD(x) & ~(v)))
#define HW_AIPSTZ_OPACR3_TOG(x, v)    (HW_AIPSTZ_OPACR3_WR(x, HW_AIPSTZ_OPACR3_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual AIPSTZ_OPACR3 bitfields
 */

/* --- Register HW_AIPSTZ_OPACR3, field OPAC31[3:0] (RW)
 *
 * Off-platform Peripheral Access Control 31
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC31      (0)      //!< Bit position for AIPSTZ_OPACR3_OPAC31.
#define BM_AIPSTZ_OPACR3_OPAC31      (0x0000000f)  //!< Bit mask for AIPSTZ_OPACR3_OPAC31.

//! @brief Get value of AIPSTZ_OPACR3_OPAC31 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC31(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC31) >> BP_AIPSTZ_OPACR3_OPAC31)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC31.
#define BF_AIPSTZ_OPACR3_OPAC31(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC31) & BM_AIPSTZ_OPACR3_OPAC31)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC31 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC31(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC31) | BF_AIPSTZ_OPACR3_OPAC31(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC31__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC31__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC31__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC31__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC31__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC31__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC31__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC31__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR3, field OPAC30[7:4] (RW)
 *
 * Off-platform Peripheral Access Control 30
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC30      (4)      //!< Bit position for AIPSTZ_OPACR3_OPAC30.
#define BM_AIPSTZ_OPACR3_OPAC30      (0x000000f0)  //!< Bit mask for AIPSTZ_OPACR3_OPAC30.

//! @brief Get value of AIPSTZ_OPACR3_OPAC30 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC30(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC30) >> BP_AIPSTZ_OPACR3_OPAC30)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC30.
#define BF_AIPSTZ_OPACR3_OPAC30(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC30) & BM_AIPSTZ_OPACR3_OPAC30)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC30 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC30(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC30) | BF_AIPSTZ_OPACR3_OPAC30(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC30__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC30__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC30__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC30__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC30__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC30__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC30__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC30__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR3, field OPAC29[11:8] (RW)
 *
 * Off-platform Peripheral Access Control 29
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC29      (8)      //!< Bit position for AIPSTZ_OPACR3_OPAC29.
#define BM_AIPSTZ_OPACR3_OPAC29      (0x00000f00)  //!< Bit mask for AIPSTZ_OPACR3_OPAC29.

//! @brief Get value of AIPSTZ_OPACR3_OPAC29 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC29(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC29) >> BP_AIPSTZ_OPACR3_OPAC29)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC29.
#define BF_AIPSTZ_OPACR3_OPAC29(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC29) & BM_AIPSTZ_OPACR3_OPAC29)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC29 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC29(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC29) | BF_AIPSTZ_OPACR3_OPAC29(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC29__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC29__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC29__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC29__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC29__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC29__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC29__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC29__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR3, field OPAC28[15:12] (RW)
 *
 * Off-platform Peripheral Access Control 28
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC28      (12)      //!< Bit position for AIPSTZ_OPACR3_OPAC28.
#define BM_AIPSTZ_OPACR3_OPAC28      (0x0000f000)  //!< Bit mask for AIPSTZ_OPACR3_OPAC28.

//! @brief Get value of AIPSTZ_OPACR3_OPAC28 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC28(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC28) >> BP_AIPSTZ_OPACR3_OPAC28)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC28.
#define BF_AIPSTZ_OPACR3_OPAC28(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC28) & BM_AIPSTZ_OPACR3_OPAC28)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC28 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC28(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC28) | BF_AIPSTZ_OPACR3_OPAC28(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC28__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC28__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC28__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC28__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC28__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC28__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC28__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC28__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR3, field OPAC27[19:16] (RW)
 *
 * Off-platform Peripheral Access Control 27
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC27      (16)      //!< Bit position for AIPSTZ_OPACR3_OPAC27.
#define BM_AIPSTZ_OPACR3_OPAC27      (0x000f0000)  //!< Bit mask for AIPSTZ_OPACR3_OPAC27.

//! @brief Get value of AIPSTZ_OPACR3_OPAC27 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC27(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC27) >> BP_AIPSTZ_OPACR3_OPAC27)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC27.
#define BF_AIPSTZ_OPACR3_OPAC27(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC27) & BM_AIPSTZ_OPACR3_OPAC27)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC27 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC27(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC27) | BF_AIPSTZ_OPACR3_OPAC27(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC27__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC27__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC27__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC27__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC27__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC27__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC27__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC27__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR3, field OPAC26[23:20] (RW)
 *
 * Off-platform Peripheral Access Control 26
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC26      (20)      //!< Bit position for AIPSTZ_OPACR3_OPAC26.
#define BM_AIPSTZ_OPACR3_OPAC26      (0x00f00000)  //!< Bit mask for AIPSTZ_OPACR3_OPAC26.

//! @brief Get value of AIPSTZ_OPACR3_OPAC26 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC26(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC26) >> BP_AIPSTZ_OPACR3_OPAC26)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC26.
#define BF_AIPSTZ_OPACR3_OPAC26(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC26) & BM_AIPSTZ_OPACR3_OPAC26)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC26 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC26(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC26) | BF_AIPSTZ_OPACR3_OPAC26(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC26__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC26__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC26__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC26__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC26__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC26__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC26__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC26__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR3, field OPAC25[27:24] (RW)
 *
 * Off-platform Peripheral Access Control 25
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC25      (24)      //!< Bit position for AIPSTZ_OPACR3_OPAC25.
#define BM_AIPSTZ_OPACR3_OPAC25      (0x0f000000)  //!< Bit mask for AIPSTZ_OPACR3_OPAC25.

//! @brief Get value of AIPSTZ_OPACR3_OPAC25 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC25(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC25) >> BP_AIPSTZ_OPACR3_OPAC25)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC25.
#define BF_AIPSTZ_OPACR3_OPAC25(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC25) & BM_AIPSTZ_OPACR3_OPAC25)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC25 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC25(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC25) | BF_AIPSTZ_OPACR3_OPAC25(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC25__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC25__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC25__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC25__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC25__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC25__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC25__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC25__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR3, field OPAC24[31:28] (RW)
 *
 * Off-platform Peripheral Access Control 24
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR3_OPAC24      (28)      //!< Bit position for AIPSTZ_OPACR3_OPAC24.
#define BM_AIPSTZ_OPACR3_OPAC24      (0xf0000000)  //!< Bit mask for AIPSTZ_OPACR3_OPAC24.

//! @brief Get value of AIPSTZ_OPACR3_OPAC24 from a register value.
#define BG_AIPSTZ_OPACR3_OPAC24(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR3_OPAC24) >> BP_AIPSTZ_OPACR3_OPAC24)

//! @brief Format value for bitfield AIPSTZ_OPACR3_OPAC24.
#define BF_AIPSTZ_OPACR3_OPAC24(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR3_OPAC24) & BM_AIPSTZ_OPACR3_OPAC24)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC24 field to a new value.
#define BW_AIPSTZ_OPACR3_OPAC24(x, v)   (HW_AIPSTZ_OPACR3_WR(x, (HW_AIPSTZ_OPACR3_RD(x) & ~BM_AIPSTZ_OPACR3_OPAC24) | BF_AIPSTZ_OPACR3_OPAC24(v)))
#endif

#define BV_AIPSTZ_OPACR3_OPAC24__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR3_OPAC24__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR3_OPAC24__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR3_OPAC24__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR3_OPAC24__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC24__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC24__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR3_OPAC24__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

//-------------------------------------------------------------------------------------------
// HW_AIPSTZ_OPACR4 - Off-Platform Peripheral Access Control Registers
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_AIPSTZ_OPACR4 - Off-Platform Peripheral Access Control Registers (RW)
 *
 * Reset value: 0x44444444
 *
 * Each of the off-platform peripherals have an Off-platform Peripheral Access Control Register
 * (AIPSTZ_OPACR) which defines the access levels supported by the given block.  Each AIPSTZ_OPACR
 * has the following format shown in
 */
typedef union _hw_aipstz_opacr4
{
    reg32_t U;
    struct _hw_aipstz_opacr4_bitfields
    {
        unsigned RESERVED0 : 24; //!< [23:0] Reserved
        unsigned OPAC33 : 4; //!< [27:24] Off-platform Peripheral Access Control 33
        unsigned OPAC32 : 4; //!< [31:28] Off-platform Peripheral Access Control 32
    } B;
} hw_aipstz_opacr4_t;
#endif

/*
 * constants & macros for entire multi-block AIPSTZ_OPACR4 register
 */
#define HW_AIPSTZ_OPACR4_ADDR(x)      (REGS_AIPSTZ_BASE(x) + 0x50)

#ifndef __LANGUAGE_ASM__
#define HW_AIPSTZ_OPACR4(x)           (*(volatile hw_aipstz_opacr4_t *) HW_AIPSTZ_OPACR4_ADDR(x))
#define HW_AIPSTZ_OPACR4_RD(x)        (HW_AIPSTZ_OPACR4(x).U)
#define HW_AIPSTZ_OPACR4_WR(x, v)     (HW_AIPSTZ_OPACR4(x).U = (v))
#define HW_AIPSTZ_OPACR4_SET(x, v)    (HW_AIPSTZ_OPACR4_WR(x, HW_AIPSTZ_OPACR4_RD(x) |  (v)))
#define HW_AIPSTZ_OPACR4_CLR(x, v)    (HW_AIPSTZ_OPACR4_WR(x, HW_AIPSTZ_OPACR4_RD(x) & ~(v)))
#define HW_AIPSTZ_OPACR4_TOG(x, v)    (HW_AIPSTZ_OPACR4_WR(x, HW_AIPSTZ_OPACR4_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual AIPSTZ_OPACR4 bitfields
 */

/* --- Register HW_AIPSTZ_OPACR4, field OPAC33[27:24] (RW)
 *
 * Off-platform Peripheral Access Control 33
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR4_OPAC33      (24)      //!< Bit position for AIPSTZ_OPACR4_OPAC33.
#define BM_AIPSTZ_OPACR4_OPAC33      (0x0f000000)  //!< Bit mask for AIPSTZ_OPACR4_OPAC33.

//! @brief Get value of AIPSTZ_OPACR4_OPAC33 from a register value.
#define BG_AIPSTZ_OPACR4_OPAC33(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR4_OPAC33) >> BP_AIPSTZ_OPACR4_OPAC33)

//! @brief Format value for bitfield AIPSTZ_OPACR4_OPAC33.
#define BF_AIPSTZ_OPACR4_OPAC33(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR4_OPAC33) & BM_AIPSTZ_OPACR4_OPAC33)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC33 field to a new value.
#define BW_AIPSTZ_OPACR4_OPAC33(x, v)   (HW_AIPSTZ_OPACR4_WR(x, (HW_AIPSTZ_OPACR4_RD(x) & ~BM_AIPSTZ_OPACR4_OPAC33) | BF_AIPSTZ_OPACR4_OPAC33(v)))
#endif

#define BV_AIPSTZ_OPACR4_OPAC33__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR4_OPAC33__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR4_OPAC33__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR4_OPAC33__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR4_OPAC33__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR4_OPAC33__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR4_OPAC33__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR4_OPAC33__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.

/* --- Register HW_AIPSTZ_OPACR4, field OPAC32[31:28] (RW)
 *
 * Off-platform Peripheral Access Control 32
 *
 * Values:
 * TP = xxx0 - Accesses from an untrusted master are allowed.
 * WP = xx0x - This peripheral allows write accesses.
 * SP = x0xx - This peripheral does not require supervisor privilege level for accesses.
 * BW = 0xxx - Write accesses to this peripheral are not bufferable by the AIPSTZ.
 * TP = xxx1 - Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master,
 *     the access is terminated with an error response and no peripheral access is initiated on the
 *     IPS bus.
 * WP = xx1x - This peripheral is write protected. If a write access is attempted, the access is terminated with an
 *     error response and no peripheral access is initiated on the IPS bus.
 * SP = x1xx - This peripheral requires supervisor privilege level for accesses. The master privilege level must
 *     indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for
 *     the master must be set. If not, the access is terminated with an error response and no
 *     peripheral access is initiated on the IPS bus.
 * BW = 1xxx - Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.
 */

#define BP_AIPSTZ_OPACR4_OPAC32      (28)      //!< Bit position for AIPSTZ_OPACR4_OPAC32.
#define BM_AIPSTZ_OPACR4_OPAC32      (0xf0000000)  //!< Bit mask for AIPSTZ_OPACR4_OPAC32.

//! @brief Get value of AIPSTZ_OPACR4_OPAC32 from a register value.
#define BG_AIPSTZ_OPACR4_OPAC32(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_AIPSTZ_OPACR4_OPAC32) >> BP_AIPSTZ_OPACR4_OPAC32)

//! @brief Format value for bitfield AIPSTZ_OPACR4_OPAC32.
#define BF_AIPSTZ_OPACR4_OPAC32(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_AIPSTZ_OPACR4_OPAC32) & BM_AIPSTZ_OPACR4_OPAC32)

#ifndef __LANGUAGE_ASM__
//! @brief Set the OPAC32 field to a new value.
#define BW_AIPSTZ_OPACR4_OPAC32(x, v)   (HW_AIPSTZ_OPACR4_WR(x, (HW_AIPSTZ_OPACR4_RD(x) & ~BM_AIPSTZ_OPACR4_OPAC32) | BF_AIPSTZ_OPACR4_OPAC32(v)))
#endif

#define BV_AIPSTZ_OPACR4_OPAC32__TP (0x0) //!< Accesses from an untrusted master are allowed.
#define BV_AIPSTZ_OPACR4_OPAC32__WP (0x0) //!< This peripheral allows write accesses.
#define BV_AIPSTZ_OPACR4_OPAC32__SP (0x0) //!< This peripheral does not require supervisor privilege level for accesses.
#define BV_AIPSTZ_OPACR4_OPAC32__BW (0x0) //!< Write accesses to this peripheral are not bufferable by the AIPSTZ.
#define BV_AIPSTZ_OPACR4_OPAC32__TP (0x1) //!< Accesses from an untrusted master are not allowed. If an access is attempted by an untrusted master, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR4_OPAC32__WP (0x2) //!< This peripheral is write protected. If a write access is attempted, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR4_OPAC32__SP (0x4) //!< This peripheral requires supervisor privilege level for accesses. The master privilege level must indicate supervisor via the hprot[1] access attribute, and the MPROTx[MPL] control bit for the master must be set. If not, the access is terminated with an error response and no peripheral access is initiated on the IPS bus.
#define BV_AIPSTZ_OPACR4_OPAC32__BW (0x8) //!< Write accesses to this peripheral are allowed to be buffered by the AIPSTZ.


/*!
 * @brief All AIPSTZ module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_aipstz
{
    volatile hw_aipstz_mpr_t MPR; //!< Master Priviledge Registers
    reg32_t _reserved0[15];
    volatile hw_aipstz_opacr_t OPACR; //!< Off-Platform Peripheral Access Control Registers
    volatile hw_aipstz_opacr1_t OPACR1; //!< Off-Platform Peripheral Access Control Registers
    volatile hw_aipstz_opacr2_t OPACR2; //!< Off-Platform Peripheral Access Control Registers
    volatile hw_aipstz_opacr3_t OPACR3; //!< Off-Platform Peripheral Access Control Registers
    volatile hw_aipstz_opacr4_t OPACR4; //!< Off-Platform Peripheral Access Control Registers
} hw_aipstz_t;
#pragma pack()

//! @brief Macro to access all AIPSTZ registers.
//! @param x AIPSTZ instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_AIPSTZ(0)</code>.
#define HW_AIPSTZ(x)     (*(volatile hw_aipstz_t *) REGS_AIPSTZ_BASE(x))

#endif


#endif // __HW_AIPSTZ_REGISTERS_H__