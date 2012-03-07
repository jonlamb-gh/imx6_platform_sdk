/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _I2C_H
#define _I2C_H

#include "regs.h"

/*
 * i.MX6SL I2C registers defined in this header file.
 *
 * - HW_I2C_IADR - I2C Address Register
 * - HW_I2C_IFDR - I2C Frequency Divider Register
 * - HW_I2C_I2CR - I2C Control Register
 * - HW_I2C_I2SR - I2C Status Register
 * - HW_I2C_I2DR - I2C Data I/O Register
 *
 * hw_i2c_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_I2C_BASE
#define REGS_I2C1_BASE (0x021a0000) //!< Base address for I2C instance number 1.
#define REGS_I2C2_BASE (0x021a4000) //!< Base address for I2C instance number 2.
#define REGS_I2C3_BASE (0x021a8000) //!< Base address for I2C instance number 3.
#define REGS_I2C4_BASE (0x021f8000) //!< Base address for I2C instance number 4.

//! @brief Get the base address of I2C by instance number.
//! @param x I2C instance number, from 0 through 4.
#define REGS_I2C_BASE(x) ( x == 1 ? REGS_I2C1_BASE : x == 2 ? REGS_I2C2_BASE : x == 3 ? REGS_I2C3_BASE : x == 4 ? REGS_I2C4_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_I2C_IADR - I2C Address Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_i2c_iadr
{
    reg16_t U;
    struct _hw_i2c_iadr_bitfields
    {
        unsigned short RESERVED0 : 1; //!< [0] Reserved
        unsigned short ADR : 7; //!< [7:1] Slave address. Contains the specific slave address to be used by the I2C. Slave mode is the default I2C mode for an address match on the bus. The I2C_IADR holds the address the I2C responds to when addressed as a slave. The slave address is not the address sent on the bus during the address transfer. The register is not reset by a software reset.
        unsigned short RESERVED1 : 8; //!< [15:8] Reserved
    } B;
} hw_i2c_iadr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_IADR register
 */
#define HW_I2C_IADR_ADDR(x)      (REGS_I2C_BASE(x) + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_IADR(x)           (*(volatile hw_i2c_iadr_t *) HW_I2C_IADR_ADDR(x))
#define HW_I2C_IADR_RD(x)        (HW_I2C_IADR(x).U)
#define HW_I2C_IADR_WR(x, v)     (HW_I2C_IADR(x).U = (v))
#define HW_I2C_IADR_SET(x, v)    (HW_I2C_IADR_WR(x, HW_I2C_IADR_RD(x) |  (v)))
#define HW_I2C_IADR_CLR(x, v)    (HW_I2C_IADR_WR(x, HW_I2C_IADR_RD(x) & ~(v)))
#define HW_I2C_IADR_TOG(x, v)    (HW_I2C_IADR_WR(x, HW_I2C_IADR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual I2C_IADR bitfields
 */

/* --- Register HW_I2C_IADR, field ADR[7:1] (RW)
 *
 * Slave address. Contains the specific slave address to be used by the I2C. Slave mode is the
 * default I2C mode for an address match on the bus. The I2C_IADR holds the address the I2C responds
 * to when addressed as a slave. The slave address is not the address sent on the bus during the
 * address transfer. The register is not reset by a software reset.
 */

#define BP_I2C_IADR_ADR      (1)      //!< Bit position for I2C_IADR_ADR.
#define BM_I2C_IADR_ADR      (0x000000fe)  //!< Bit mask for I2C_IADR_ADR.

//! @brief Get value of I2C_IADR_ADR from a register value.
#define BG_I2C_IADR_ADR(r)   (((r) & BM_I2C_IADR_ADR) >> BP_I2C_IADR_ADR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_IADR_ADR.
#define BF_I2C_IADR_ADR(v)   ((((reg16_t) v) << BP_I2C_IADR_ADR) & BM_I2C_IADR_ADR)
#else
//! @brief Format value for bitfield I2C_IADR_ADR.
#define BF_I2C_IADR_ADR(v)   (((v) << BP_I2C_IADR_ADR) & BM_I2C_IADR_ADR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADR field to a new value.
#define BW_I2C_IADR_ADR(x, v)   (HW_I2C_IADR_WR(x, (HW_I2C_IADR_RD(x) & ~BM_I2C_IADR_ADR) | BF_I2C_IADR_ADR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_I2C_IFDR - I2C Frequency Divider Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The I2C_IFDR provides a programmable prescaler to configure the clock for bit-rate selection. The
 * register does not get reset by software reset. The following table describes the Divider values
 * for register field "IC". Table below describes the register values for field "IC".   I2C_IFDR
 * Register Field Values                IC  Divider   IC  Divider   IC  Divider   IC  Divider
 * 0x00  30  0x10  288  0x20  22  0x30  160    0x01  32  0x11  320  0x21  24  0x31  192    0x02  36
 * 0x12  384  0x22  26  0x32  224    0x03  42  0x13  480  0x23  28  0x33  256    0x04  48  0x14  576
 * 0x24  32  0x34  320    0x05  52  0x15  640  0x25  36  0x35  384    0x06  60  0x16  768  0x26  40
 * 0x36  448    0x07  72  0x17  960  0x27  44  0x37  512    0x08  80  0x18  1152  0x28  48  0x38
 * 640    0x09  88  0x19  1280  0x29  56  0x39  768    0x0A  104  0x1A  1536  0x2A  64  0x3A  896
 * 0x0B  128  0x1B  1920  0x2B  72  0x3B  1024    0x0C  144  0x1C  2304  0x2C  80  0x3C  1280
 * 0x0D  160  0x1D  2560  0x2D  96  0x3D  1536    0x0E  192  0x1E  3072  0x2E  112  0x3E  1792
 * 0x0F  240  0x1F  3840  0x2F  128  0x3F  2048
 */
typedef union _hw_i2c_ifdr
{
    reg16_t U;
    struct _hw_i2c_ifdr_bitfields
    {
        unsigned short IC : 6; //!< [5:0] I2C clock rate. Pre scales the clock for bit-rate selection. Due to potentially slow SCL and SDA rise and fall times, bus signals are sampled at the prescaler frequency. The serial bit clock frequency is equal to IPG_CLK_ROOT PG_CLK_PATREF divided by the divider shown in the I2C Data I/O Register. The IC value should not be changed during the data transfer, however, it can be changed before REPEAT START or START programming sequence in I2C. The I2C protocol supports bit rates up to 400 kbps. The IC bits need to be programmed in accordance with this constraint.
        unsigned short RESERVED0 : 10; //!< [15:6] Reserved
    } B;
} hw_i2c_ifdr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_IFDR register
 */
#define HW_I2C_IFDR_ADDR(x)      (REGS_I2C_BASE(x) + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_IFDR(x)           (*(volatile hw_i2c_ifdr_t *) HW_I2C_IFDR_ADDR(x))
#define HW_I2C_IFDR_RD(x)        (HW_I2C_IFDR(x).U)
#define HW_I2C_IFDR_WR(x, v)     (HW_I2C_IFDR(x).U = (v))
#define HW_I2C_IFDR_SET(x, v)    (HW_I2C_IFDR_WR(x, HW_I2C_IFDR_RD(x) |  (v)))
#define HW_I2C_IFDR_CLR(x, v)    (HW_I2C_IFDR_WR(x, HW_I2C_IFDR_RD(x) & ~(v)))
#define HW_I2C_IFDR_TOG(x, v)    (HW_I2C_IFDR_WR(x, HW_I2C_IFDR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual I2C_IFDR bitfields
 */

/* --- Register HW_I2C_IFDR, field IC[5:0] (RW)
 *
 * I2C clock rate. Pre scales the clock for bit-rate selection. Due to potentially slow SCL and SDA
 * rise and fall times, bus signals are sampled at the prescaler frequency. The serial bit clock
 * frequency is equal to IPG_CLK_ROOT PG_CLK_PATREF divided by the divider shown in the I2C Data I/O
 * Register. The IC value should not be changed during the data transfer, however, it can be changed
 * before REPEAT START or START programming sequence in I2C. The I2C protocol supports bit rates up
 * to 400 kbps. The IC bits need to be programmed in accordance with this constraint.
 */

#define BP_I2C_IFDR_IC      (0)      //!< Bit position for I2C_IFDR_IC.
#define BM_I2C_IFDR_IC      (0x0000003f)  //!< Bit mask for I2C_IFDR_IC.

//! @brief Get value of I2C_IFDR_IC from a register value.
#define BG_I2C_IFDR_IC(r)   (((r) & BM_I2C_IFDR_IC) >> BP_I2C_IFDR_IC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_IFDR_IC.
#define BF_I2C_IFDR_IC(v)   ((((reg16_t) v) << BP_I2C_IFDR_IC) & BM_I2C_IFDR_IC)
#else
//! @brief Format value for bitfield I2C_IFDR_IC.
#define BF_I2C_IFDR_IC(v)   (((v) << BP_I2C_IFDR_IC) & BM_I2C_IFDR_IC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IC field to a new value.
#define BW_I2C_IFDR_IC(x, v)   (HW_I2C_IFDR_WR(x, (HW_I2C_IFDR_RD(x) & ~BM_I2C_IFDR_IC) | BF_I2C_IFDR_IC(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_I2C_I2CR - I2C Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The I2C_I2CR is used to enable the I2C and the I2C interrupt. It also contains bits that govern
 * operation as a slave or a master.
 */
typedef union _hw_i2c_i2cr
{
    reg16_t U;
    struct _hw_i2c_i2cr_bitfields
    {
        unsigned short RESERVED0 : 2; //!< [1:0] Reserved
        unsigned short RSTA : 1; //!< [2] Repeat start. Always reads as 0. Attempting a repeat start without bus mastership causes loss of arbitration.
        unsigned short TXAK : 1; //!< [3] Transmit acknowledge enable. Specifies the value driven onto SDA during acknowledge cycles for both master and slave receivers. Writing TXAK applies only when the I2C bus is a receiver.
        unsigned short MTX : 1; //!< [4] Transmit/receive mode select bit. Selects the direction of master and slave transfers.
        unsigned short MSTA : 1; //!< [5] Master/slave mode select bit. If the master loses arbitration, MSTA is cleared without generating a STOP signal. Module clock should be on for writing to the MSTA bit. The MSTA bit is cleared by software to generate a STOP condition; it can also be cleared by hardware when the I2C loses the bus arbitration.
        unsigned short IIEN : 1; //!< [6] I2C interrupt enable. If data is written during the START condition, that is, just after setting the I2C_I2CR[MSTA] and I2C_I2CR[MTX] bits, then the ICF bit is cleared at the falling edge of SCLK after START. If data is written after the START condition and falling edge of SCLK, then ICF bit is cleared as soon as data is written.
        unsigned short IEN : 1; //!< [7] I2C enable. Also controls the software reset of the entire I2C. Resetting the bit generates an internal reset to the block. If the block is enabled in the middle of a byte transfer, slave mode ignores the current bus transfer and starts operating when the next start condition is detected. Master mode is not aware that the bus is busy so initiating a start cycle may corrupt the current bus cycle, ultimately causing either the current master or the I2C to lose arbitration. After which, bus operation returns to normal.
        unsigned short RESERVED1 : 8; //!< [15:8] Reserved
    } B;
} hw_i2c_i2cr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_I2CR register
 */
#define HW_I2C_I2CR_ADDR(x)      (REGS_I2C_BASE(x) + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_I2CR(x)           (*(volatile hw_i2c_i2cr_t *) HW_I2C_I2CR_ADDR(x))
#define HW_I2C_I2CR_RD(x)        (HW_I2C_I2CR(x).U)
#define HW_I2C_I2CR_WR(x, v)     (HW_I2C_I2CR(x).U = (v))
#define HW_I2C_I2CR_SET(x, v)    (HW_I2C_I2CR_WR(x, HW_I2C_I2CR_RD(x) |  (v)))
#define HW_I2C_I2CR_CLR(x, v)    (HW_I2C_I2CR_WR(x, HW_I2C_I2CR_RD(x) & ~(v)))
#define HW_I2C_I2CR_TOG(x, v)    (HW_I2C_I2CR_WR(x, HW_I2C_I2CR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual I2C_I2CR bitfields
 */

/* --- Register HW_I2C_I2CR, field RSTA[2] (WORZ)
 *
 * Repeat start. Always reads as 0. Attempting a repeat start without bus mastership causes loss of
 * arbitration.
 *
 * Values:
 * 0 - No repeat start
 * 1 - Generates a repeated START condition
 */

#define BP_I2C_I2CR_RSTA      (2)      //!< Bit position for I2C_I2CR_RSTA.
#define BM_I2C_I2CR_RSTA      (0x00000004)  //!< Bit mask for I2C_I2CR_RSTA.

//! @brief Get value of I2C_I2CR_RSTA from a register value.
#define BG_I2C_I2CR_RSTA(r)   (((r) & BM_I2C_I2CR_RSTA) >> BP_I2C_I2CR_RSTA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2CR_RSTA.
#define BF_I2C_I2CR_RSTA(v)   ((((reg16_t) v) << BP_I2C_I2CR_RSTA) & BM_I2C_I2CR_RSTA)
#else
//! @brief Format value for bitfield I2C_I2CR_RSTA.
#define BF_I2C_I2CR_RSTA(v)   (((v) << BP_I2C_I2CR_RSTA) & BM_I2C_I2CR_RSTA)
#endif


/* --- Register HW_I2C_I2CR, field TXAK[3] (RW)
 *
 * Transmit acknowledge enable. Specifies the value driven onto SDA during acknowledge cycles for
 * both master and slave receivers. Writing TXAK applies only when the I2C bus is a receiver.
 *
 * Values:
 * 0 - An acknowledge signal is sent to the bus at the ninth clock bit after receiving one byte of data.
 * 1 - No acknowledge signal response is sent (that is, the acknowledge bit = 1).
 */

#define BP_I2C_I2CR_TXAK      (3)      //!< Bit position for I2C_I2CR_TXAK.
#define BM_I2C_I2CR_TXAK      (0x00000008)  //!< Bit mask for I2C_I2CR_TXAK.

//! @brief Get value of I2C_I2CR_TXAK from a register value.
#define BG_I2C_I2CR_TXAK(r)   (((r) & BM_I2C_I2CR_TXAK) >> BP_I2C_I2CR_TXAK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2CR_TXAK.
#define BF_I2C_I2CR_TXAK(v)   ((((reg16_t) v) << BP_I2C_I2CR_TXAK) & BM_I2C_I2CR_TXAK)
#else
//! @brief Format value for bitfield I2C_I2CR_TXAK.
#define BF_I2C_I2CR_TXAK(v)   (((v) << BP_I2C_I2CR_TXAK) & BM_I2C_I2CR_TXAK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXAK field to a new value.
#define BW_I2C_I2CR_TXAK(x, v)   (HW_I2C_I2CR_WR(x, (HW_I2C_I2CR_RD(x) & ~BM_I2C_I2CR_TXAK) | BF_I2C_I2CR_TXAK(v)))
#endif


/* --- Register HW_I2C_I2CR, field MTX[4] (RW)
 *
 * Transmit/receive mode select bit. Selects the direction of master and slave transfers.
 *
 * Values:
 * 0 - Receive. When a slave is addressed, the software should set MTX according to the slave read/write
 *     bit in the I2C status register (I2C_I2SR[SRW]).
 * 1 - Transmit. In master mode, MTX should be set according to the type of transfer required. Therefore,
 *     for address cycles, MTX is always 1.
 */

#define BP_I2C_I2CR_MTX      (4)      //!< Bit position for I2C_I2CR_MTX.
#define BM_I2C_I2CR_MTX      (0x00000010)  //!< Bit mask for I2C_I2CR_MTX.

//! @brief Get value of I2C_I2CR_MTX from a register value.
#define BG_I2C_I2CR_MTX(r)   (((r) & BM_I2C_I2CR_MTX) >> BP_I2C_I2CR_MTX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2CR_MTX.
#define BF_I2C_I2CR_MTX(v)   ((((reg16_t) v) << BP_I2C_I2CR_MTX) & BM_I2C_I2CR_MTX)
#else
//! @brief Format value for bitfield I2C_I2CR_MTX.
#define BF_I2C_I2CR_MTX(v)   (((v) << BP_I2C_I2CR_MTX) & BM_I2C_I2CR_MTX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MTX field to a new value.
#define BW_I2C_I2CR_MTX(x, v)   (HW_I2C_I2CR_WR(x, (HW_I2C_I2CR_RD(x) & ~BM_I2C_I2CR_MTX) | BF_I2C_I2CR_MTX(v)))
#endif


/* --- Register HW_I2C_I2CR, field MSTA[5] (RW)
 *
 * Master/slave mode select bit. If the master loses arbitration, MSTA is cleared without generating
 * a STOP signal. Module clock should be on for writing to the MSTA bit. The MSTA bit is cleared by
 * software to generate a STOP condition; it can also be cleared by hardware when the I2C loses the
 * bus arbitration.
 *
 * Values:
 * 0 - Slave mode. Changing MSTA from 1 to 0 generates a STOP and selects slave mode.
 * 1 - Master mode. Changing MSTA from 0 to 1 signals a START on the bus and selects master mode.
 */

#define BP_I2C_I2CR_MSTA      (5)      //!< Bit position for I2C_I2CR_MSTA.
#define BM_I2C_I2CR_MSTA      (0x00000020)  //!< Bit mask for I2C_I2CR_MSTA.

//! @brief Get value of I2C_I2CR_MSTA from a register value.
#define BG_I2C_I2CR_MSTA(r)   (((r) & BM_I2C_I2CR_MSTA) >> BP_I2C_I2CR_MSTA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2CR_MSTA.
#define BF_I2C_I2CR_MSTA(v)   ((((reg16_t) v) << BP_I2C_I2CR_MSTA) & BM_I2C_I2CR_MSTA)
#else
//! @brief Format value for bitfield I2C_I2CR_MSTA.
#define BF_I2C_I2CR_MSTA(v)   (((v) << BP_I2C_I2CR_MSTA) & BM_I2C_I2CR_MSTA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MSTA field to a new value.
#define BW_I2C_I2CR_MSTA(x, v)   (HW_I2C_I2CR_WR(x, (HW_I2C_I2CR_RD(x) & ~BM_I2C_I2CR_MSTA) | BF_I2C_I2CR_MSTA(v)))
#endif


/* --- Register HW_I2C_I2CR, field IIEN[6] (RW)
 *
 * I2C interrupt enable. If data is written during the START condition, that is, just after setting
 * the I2C_I2CR[MSTA] and I2C_I2CR[MTX] bits, then the ICF bit is cleared at the falling edge of
 * SCLK after START. If data is written after the START condition and falling edge of SCLK, then ICF
 * bit is cleared as soon as data is written.
 *
 * Values:
 * 0 - I2C interrupts are disabled, but the status flag I2C_I2SR[IIF] continues to be set when an interrupt
 *     condition occurs.
 * 1 - I2C interrupts are enabled. An I2C interrupt occurs if I2C_I2SR[IIF] is also set.
 */

#define BP_I2C_I2CR_IIEN      (6)      //!< Bit position for I2C_I2CR_IIEN.
#define BM_I2C_I2CR_IIEN      (0x00000040)  //!< Bit mask for I2C_I2CR_IIEN.

//! @brief Get value of I2C_I2CR_IIEN from a register value.
#define BG_I2C_I2CR_IIEN(r)   (((r) & BM_I2C_I2CR_IIEN) >> BP_I2C_I2CR_IIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2CR_IIEN.
#define BF_I2C_I2CR_IIEN(v)   ((((reg16_t) v) << BP_I2C_I2CR_IIEN) & BM_I2C_I2CR_IIEN)
#else
//! @brief Format value for bitfield I2C_I2CR_IIEN.
#define BF_I2C_I2CR_IIEN(v)   (((v) << BP_I2C_I2CR_IIEN) & BM_I2C_I2CR_IIEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IIEN field to a new value.
#define BW_I2C_I2CR_IIEN(x, v)   (HW_I2C_I2CR_WR(x, (HW_I2C_I2CR_RD(x) & ~BM_I2C_I2CR_IIEN) | BF_I2C_I2CR_IIEN(v)))
#endif


/* --- Register HW_I2C_I2CR, field IEN[7] (RW)
 *
 * I2C enable. Also controls the software reset of the entire I2C. Resetting the bit generates an
 * internal reset to the block. If the block is enabled in the middle of a byte transfer, slave mode
 * ignores the current bus transfer and starts operating when the next start condition is detected.
 * Master mode is not aware that the bus is busy so initiating a start cycle may corrupt the current
 * bus cycle, ultimately causing either the current master or the I2C to lose arbitration. After
 * which, bus operation returns to normal.
 *
 * Values:
 * 0 - The block is disabled, but registers can still be accessed.
 * 1 - The I2C is enabled. This bit must be set before any other I2C_I2CR bits have any effect.
 */

#define BP_I2C_I2CR_IEN      (7)      //!< Bit position for I2C_I2CR_IEN.
#define BM_I2C_I2CR_IEN      (0x00000080)  //!< Bit mask for I2C_I2CR_IEN.

//! @brief Get value of I2C_I2CR_IEN from a register value.
#define BG_I2C_I2CR_IEN(r)   (((r) & BM_I2C_I2CR_IEN) >> BP_I2C_I2CR_IEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2CR_IEN.
#define BF_I2C_I2CR_IEN(v)   ((((reg16_t) v) << BP_I2C_I2CR_IEN) & BM_I2C_I2CR_IEN)
#else
//! @brief Format value for bitfield I2C_I2CR_IEN.
#define BF_I2C_I2CR_IEN(v)   (((v) << BP_I2C_I2CR_IEN) & BM_I2C_I2CR_IEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IEN field to a new value.
#define BW_I2C_I2CR_IEN(x, v)   (HW_I2C_I2CR_WR(x, (HW_I2C_I2CR_RD(x) & ~BM_I2C_I2CR_IEN) | BF_I2C_I2CR_IEN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_I2C_I2SR - I2C Status Register (RW)
 *
 * Reset value: 0x00000081
 *
 * The I2C_I2SR contains bits that indicate transaction direction and status.
 */
typedef union _hw_i2c_i2sr
{
    reg16_t U;
    struct _hw_i2c_i2sr_bitfields
    {
        unsigned short RXAK : 1; //!< [0] Received acknowledge. This is the value received of the SDA input for the acknowledge bit during a bus cycle.
        unsigned short IIF : 1; //!< [1] I2C interrupt. Must be cleared by the software by writing a "0" to it in the interrupt routine. The software cannot set the bit.
        unsigned short SRW : 1; //!< [2] Slave read/write. When the I2C is addressed as a slave, IAAS is set, and the slave read/write bit (SRW) indicates the value of the R/W command bit of the calling address sent from the master. SRW is valid only when a complete transfer has occurred, no other transfers have been initiated, and the I2C is a slave and has an address match.
        unsigned short RESERVED0 : 1; //!< [3] Reserved
        unsigned short IAL : 1; //!< [4] Arbitration lost. Set by hardware in the following circumstances (IAL must be cleared by software by writing a "0" to it at the start of the interrupt service routine): SDA input sampled low when the master drives high during an address or data-transmit cycle. SDA input sampled low when the master drives high during the acknowledge bit of a data-receive cycle. For the above two cases, the bit is set at the falling edge of 9th SCL clock during the ACK cycle. A start cycle is attempted when the bus is busy. A repeated start cycle is requested in slave mode. A stop condition is detected when the master did not request it. Software cannot set the bit.
        unsigned short IBB : 1; //!< [5] I2C bus busy bit. Indicates the status of the bus. When I2C is enabled (I2C_I2CR[IEN] = 1), it continuously polls the bus data (SDAK) and clock (SCLK) signals to determine a START or STOP condition.
        unsigned short IAAS : 1; //!< [6] I2C addressed as a slave bit. The ARM platform is interrupted if the interrupt enable (I2C_I2CR[IIEN]) is set. The ARM platform must check the slave read/write bit (SRW) and set its TX/RX mode accordingly. Writing to I2C_I2CR clears this bit.
        unsigned short ICF : 1; //!< [7] Data transferring bit. While one byte of data is transferred, ICF is cleared.
        unsigned short RESERVED1 : 8; //!< [15:8] Reserved
    } B;
} hw_i2c_i2sr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_I2SR register
 */
#define HW_I2C_I2SR_ADDR(x)      (REGS_I2C_BASE(x) + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_I2SR(x)           (*(volatile hw_i2c_i2sr_t *) HW_I2C_I2SR_ADDR(x))
#define HW_I2C_I2SR_RD(x)        (HW_I2C_I2SR(x).U)
#define HW_I2C_I2SR_WR(x, v)     (HW_I2C_I2SR(x).U = (v))
#define HW_I2C_I2SR_SET(x, v)    (HW_I2C_I2SR_WR(x, HW_I2C_I2SR_RD(x) |  (v)))
#define HW_I2C_I2SR_CLR(x, v)    (HW_I2C_I2SR_WR(x, HW_I2C_I2SR_RD(x) & ~(v)))
#define HW_I2C_I2SR_TOG(x, v)    (HW_I2C_I2SR_WR(x, HW_I2C_I2SR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual I2C_I2SR bitfields
 */

/* --- Register HW_I2C_I2SR, field RXAK[0] (RO)
 *
 * Received acknowledge. This is the value received of the SDA input for the acknowledge bit during
 * a bus cycle.
 *
 * Values:
 * 0 - An "acknowledge" signal was received after the completion of an 8-bit data transmission on the bus.
 * 1 - A "No acknowledge" signal was detected at the ninth clock.
 */

#define BP_I2C_I2SR_RXAK      (0)      //!< Bit position for I2C_I2SR_RXAK.
#define BM_I2C_I2SR_RXAK      (0x00000001)  //!< Bit mask for I2C_I2SR_RXAK.

//! @brief Get value of I2C_I2SR_RXAK from a register value.
#define BG_I2C_I2SR_RXAK(r)   (((r) & BM_I2C_I2SR_RXAK) >> BP_I2C_I2SR_RXAK)


/* --- Register HW_I2C_I2SR, field IIF[1] (RW)
 *
 * I2C interrupt. Must be cleared by the software by writing a "0" to it in the interrupt routine.
 * The software cannot set the bit.
 *
 * Values:
 * 0 - No I2C interrupt pending.
 * 1 - An interrupt is pending. This causes a processor interrupt request (if the interrupt enable is
 *     asserted [IIEN = 1]). The interrupt is set when one of the following occurs:  One byte
 *     transfer is completed (the interrupt is set at the falling edge of the ninth clock).  An
 *     address is received that matches its own specific address in slave-receive mode.  Arbitration
 *     is lost.
 */

#define BP_I2C_I2SR_IIF      (1)      //!< Bit position for I2C_I2SR_IIF.
#define BM_I2C_I2SR_IIF      (0x00000002)  //!< Bit mask for I2C_I2SR_IIF.

//! @brief Get value of I2C_I2SR_IIF from a register value.
#define BG_I2C_I2SR_IIF(r)   (((r) & BM_I2C_I2SR_IIF) >> BP_I2C_I2SR_IIF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2SR_IIF.
#define BF_I2C_I2SR_IIF(v)   ((((reg16_t) v) << BP_I2C_I2SR_IIF) & BM_I2C_I2SR_IIF)
#else
//! @brief Format value for bitfield I2C_I2SR_IIF.
#define BF_I2C_I2SR_IIF(v)   (((v) << BP_I2C_I2SR_IIF) & BM_I2C_I2SR_IIF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IIF field to a new value.
#define BW_I2C_I2SR_IIF(x, v)   (HW_I2C_I2SR_WR(x, (HW_I2C_I2SR_RD(x) & ~BM_I2C_I2SR_IIF) | BF_I2C_I2SR_IIF(v)))
#endif


/* --- Register HW_I2C_I2SR, field SRW[2] (RO)
 *
 * Slave read/write. When the I2C is addressed as a slave, IAAS is set, and the slave read/write bit
 * (SRW) indicates the value of the R/W command bit of the calling address sent from the master. SRW
 * is valid only when a complete transfer has occurred, no other transfers have been initiated, and
 * the I2C is a slave and has an address match.
 *
 * Values:
 * 0 - Slave receive, master writing to slave
 * 1 - Slave transmit, master reading from slave
 */

#define BP_I2C_I2SR_SRW      (2)      //!< Bit position for I2C_I2SR_SRW.
#define BM_I2C_I2SR_SRW      (0x00000004)  //!< Bit mask for I2C_I2SR_SRW.

//! @brief Get value of I2C_I2SR_SRW from a register value.
#define BG_I2C_I2SR_SRW(r)   (((r) & BM_I2C_I2SR_SRW) >> BP_I2C_I2SR_SRW)


/* --- Register HW_I2C_I2SR, field IAL[4] (RW)
 *
 * Arbitration lost. Set by hardware in the following circumstances (IAL must be cleared by software
 * by writing a "0" to it at the start of the interrupt service routine): SDA input sampled low when
 * the master drives high during an address or data-transmit cycle. SDA input sampled low when the
 * master drives high during the acknowledge bit of a data-receive cycle. For the above two cases,
 * the bit is set at the falling edge of 9th SCL clock during the ACK cycle. A start cycle is
 * attempted when the bus is busy. A repeated start cycle is requested in slave mode. A stop
 * condition is detected when the master did not request it. Software cannot set the bit.
 *
 * Values:
 * 0 - No arbitration lost.
 * 1 - Arbitration is lost.
 */

#define BP_I2C_I2SR_IAL      (4)      //!< Bit position for I2C_I2SR_IAL.
#define BM_I2C_I2SR_IAL      (0x00000010)  //!< Bit mask for I2C_I2SR_IAL.

//! @brief Get value of I2C_I2SR_IAL from a register value.
#define BG_I2C_I2SR_IAL(r)   (((r) & BM_I2C_I2SR_IAL) >> BP_I2C_I2SR_IAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2SR_IAL.
#define BF_I2C_I2SR_IAL(v)   ((((reg16_t) v) << BP_I2C_I2SR_IAL) & BM_I2C_I2SR_IAL)
#else
//! @brief Format value for bitfield I2C_I2SR_IAL.
#define BF_I2C_I2SR_IAL(v)   (((v) << BP_I2C_I2SR_IAL) & BM_I2C_I2SR_IAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IAL field to a new value.
#define BW_I2C_I2SR_IAL(x, v)   (HW_I2C_I2SR_WR(x, (HW_I2C_I2SR_RD(x) & ~BM_I2C_I2SR_IAL) | BF_I2C_I2SR_IAL(v)))
#endif


/* --- Register HW_I2C_I2SR, field IBB[5] (RO)
 *
 * I2C bus busy bit. Indicates the status of the bus. When I2C is enabled (I2C_I2CR[IEN] = 1), it
 * continuously polls the bus data (SDAK) and clock (SCLK) signals to determine a START or STOP
 * condition.
 *
 * Values:
 * 0 - Bus is idle. If a STOP signal is detected, IBB is cleared.
 * 1 - Bus is busy. When START is detected, IBB is set.
 */

#define BP_I2C_I2SR_IBB      (5)      //!< Bit position for I2C_I2SR_IBB.
#define BM_I2C_I2SR_IBB      (0x00000020)  //!< Bit mask for I2C_I2SR_IBB.

//! @brief Get value of I2C_I2SR_IBB from a register value.
#define BG_I2C_I2SR_IBB(r)   (((r) & BM_I2C_I2SR_IBB) >> BP_I2C_I2SR_IBB)


/* --- Register HW_I2C_I2SR, field IAAS[6] (RO)
 *
 * I2C addressed as a slave bit. The ARM platform is interrupted if the interrupt enable
 * (I2C_I2CR[IIEN]) is set. The ARM platform must check the slave read/write bit (SRW) and set its
 * TX/RX mode accordingly. Writing to I2C_I2CR clears this bit.
 *
 * Values:
 * 0 - Not addressed
 * 1 - Addressed as a slave. Set when its own address (I2C_IADR) matches the calling address.
 */

#define BP_I2C_I2SR_IAAS      (6)      //!< Bit position for I2C_I2SR_IAAS.
#define BM_I2C_I2SR_IAAS      (0x00000040)  //!< Bit mask for I2C_I2SR_IAAS.

//! @brief Get value of I2C_I2SR_IAAS from a register value.
#define BG_I2C_I2SR_IAAS(r)   (((r) & BM_I2C_I2SR_IAAS) >> BP_I2C_I2SR_IAAS)


/* --- Register HW_I2C_I2SR, field ICF[7] (RO)
 *
 * Data transferring bit. While one byte of data is transferred, ICF is cleared.
 *
 * Values:
 * 0 - Transfer is in progress.
 * 1 - Transfer is complete. This bit is set by the falling edge of the ninth clock of the last byte
 *     transfer.
 */

#define BP_I2C_I2SR_ICF      (7)      //!< Bit position for I2C_I2SR_ICF.
#define BM_I2C_I2SR_ICF      (0x00000080)  //!< Bit mask for I2C_I2SR_ICF.

//! @brief Get value of I2C_I2SR_ICF from a register value.
#define BG_I2C_I2SR_ICF(r)   (((r) & BM_I2C_I2SR_ICF) >> BP_I2C_I2SR_ICF)


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_I2C_I2DR - I2C Data I/O Register (RW)
 *
 * Reset value: 0x00000000
 *
 * In master-receive mode, reading the data register allows a read to occur and initiates the next
 * byte to be received. In slave mode, the same function is available after it is addressed.
 */
typedef union _hw_i2c_i2dr
{
    reg16_t U;
    struct _hw_i2c_i2dr_bitfields
    {
        unsigned short DATA : 8; //!< [7:0] Data Byte. Holds the last data byte received or the next data byte to be transferred. Software writes the next data byte to be transmitted or reads the data byte received. The core-written value in I2C_I2DR cannot be read back by the core. Only data written by the I2C bus side can be read. I2DR is implemented by 2 different registers. One register is written by IP interface and the data written is transmitted on I2C bus, other register is written by the data received from I2C and read by IP interface.
        unsigned short RESERVED0 : 8; //!< [15:8] Reserved
    } B;
} hw_i2c_i2dr_t;
#endif

/*
 * constants & macros for entire multi-block I2C_I2DR register
 */
#define HW_I2C_I2DR_ADDR(x)      (REGS_I2C_BASE(x) + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_I2C_I2DR(x)           (*(volatile hw_i2c_i2dr_t *) HW_I2C_I2DR_ADDR(x))
#define HW_I2C_I2DR_RD(x)        (HW_I2C_I2DR(x).U)
#define HW_I2C_I2DR_WR(x, v)     (HW_I2C_I2DR(x).U = (v))
#define HW_I2C_I2DR_SET(x, v)    (HW_I2C_I2DR_WR(x, HW_I2C_I2DR_RD(x) |  (v)))
#define HW_I2C_I2DR_CLR(x, v)    (HW_I2C_I2DR_WR(x, HW_I2C_I2DR_RD(x) & ~(v)))
#define HW_I2C_I2DR_TOG(x, v)    (HW_I2C_I2DR_WR(x, HW_I2C_I2DR_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual I2C_I2DR bitfields
 */

/* --- Register HW_I2C_I2DR, field DATA[7:0] (RW)
 *
 * Data Byte. Holds the last data byte received or the next data byte to be transferred. Software
 * writes the next data byte to be transmitted or reads the data byte received. The core-written
 * value in I2C_I2DR cannot be read back by the core. Only data written by the I2C bus side can be
 * read. I2DR is implemented by 2 different registers. One register is written by IP interface and
 * the data written is transmitted on I2C bus, other register is written by the data received from
 * I2C and read by IP interface.
 */

#define BP_I2C_I2DR_DATA      (0)      //!< Bit position for I2C_I2DR_DATA.
#define BM_I2C_I2DR_DATA      (0x000000ff)  //!< Bit mask for I2C_I2DR_DATA.

//! @brief Get value of I2C_I2DR_DATA from a register value.
#define BG_I2C_I2DR_DATA(r)   (((r) & BM_I2C_I2DR_DATA) >> BP_I2C_I2DR_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield I2C_I2DR_DATA.
#define BF_I2C_I2DR_DATA(v)   ((((reg16_t) v) << BP_I2C_I2DR_DATA) & BM_I2C_I2DR_DATA)
#else
//! @brief Format value for bitfield I2C_I2DR_DATA.
#define BF_I2C_I2DR_DATA(v)   (((v) << BP_I2C_I2DR_DATA) & BM_I2C_I2DR_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_I2C_I2DR_DATA(x, v)   (HW_I2C_I2DR_WR(x, (HW_I2C_I2DR_RD(x) & ~BM_I2C_I2DR_DATA) | BF_I2C_I2DR_DATA(v)))
#endif


/*!
 * @brief All I2C module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_i2c
{
    volatile hw_i2c_iadr_t IADR; //!< I2C Address Register
    reg16_t _reserved0;
    volatile hw_i2c_ifdr_t IFDR; //!< I2C Frequency Divider Register
    reg16_t _reserved1;
    volatile hw_i2c_i2cr_t I2CR; //!< I2C Control Register
    reg16_t _reserved2;
    volatile hw_i2c_i2sr_t I2SR; //!< I2C Status Register
    reg16_t _reserved3;
    volatile hw_i2c_i2dr_t I2DR; //!< I2C Data I/O Register
} hw_i2c_t;
#pragma pack()
#endif

//! @brief Macro to access all I2C registers.
//! @param x I2C instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_I2C(0)</code>.
#define HW_I2C(x)     (*(volatile hw_i2c_t *) REGS_I2C_BASE(x))


#endif // _I2C_H