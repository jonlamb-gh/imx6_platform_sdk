/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _USB_PHY_H
#define _USB_PHY_H

#include "regs.h"

/*
 * i.MX6DQ USB_PHY registers defined in this header file.
 *
 * - HW_USB_PHY_PWD - USB PHY Power-Down Register
 * - HW_USB_PHY_TX - USB PHY Transmitter Control Register
 * - HW_USB_PHY_RX - USB PHY Receiver Control Register
 * - HW_USB_PHY_CTRL - USB PHY General Control Register
 * - HW_USB_PHY_STATUS - USB PHY Status Register
 * - HW_USB_PHY_DEBUG - USB PHY Debug Register
 * - HW_USB_PHY_DEBUG0_STATUS - UTMI Debug Status Register 0
 * - HW_USB_PHY_DEBUG1 - UTMI Debug Status Register 1
 * - HW_USB_PHY_VERSION - UTMI RTL Version
 *
 * hw_usb_phy_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_USB_PHY_BASE
#define REGS_USB_PHY1_BASE (0x020c9000) //!< Base address for USB_PHY instance number 1.
#define REGS_USB_PHY2_BASE (0x020ca000) //!< Base address for USB_PHY instance number 2.

//! @brief Get the base address of USB_PHY by instance number.
//! @param x USB_PHY instance number, from 0 through 2.
#define REGS_USB_PHY_BASE(x) ( x == 1 ? REGS_USB_PHY1_BASE : x == 2 ? REGS_USB_PHY2_BASE : 0xffff0000)
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_PWD - USB PHY Power-Down Register (RW)
 *
 * Reset value: 0x001e1c00
 *
 * The USB PHY Power-Down Register provides overall control of the PHY power state. Before
 * programming this register, the PHY clocks must be enabled in registers USBPHYx_CTRLn and
 * CCM_ANALOG_USBPHYx_PLL_480_CTRLn.
 */
typedef union _hw_usb_phy_pwd
{
    reg32_t U;
    struct _hw_usb_phy_pwd_bitfields
    {
        unsigned RESERVED0 : 10; //!< [9:0] Reserved.
        unsigned TXPWDFS : 1; //!< [10] 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current starvation sources and puts the drivers into high-impedance output. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned TXPWDIBIAS : 1; //!< [11] 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit should be set only when the USB is in suspend mode. This effectively powers down the entire USB transmit path. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned TXPWDV2I : 1; //!< [12] 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current mirror. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the battery charge circuit. Setting this to 1 does not power-down these circuits, unless the corresponding bit in the battery charger is also set for power-down.
        unsigned RESERVED1 : 4; //!< [16:13] Reserved.
        unsigned RXPWDENV : 1; //!< [17] 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch signal). Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWD1PT1 : 1; //!< [18] 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDDIFF : 1; //!< [19] 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RXPWDRX : 1; //!< [20] 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
        unsigned RESERVED2 : 11; //!< [31:21] Reserved.
    } B;
} hw_usb_phy_pwd_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_PWD register
 */
#define HW_USB_PHY_PWD_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x0)
#define HW_USB_PHY_PWD_SET_ADDR(x)  (HW_USB_PHY_PWD_ADDR(x) + 0x4)
#define HW_USB_PHY_PWD_CLR_ADDR(x)  (HW_USB_PHY_PWD_ADDR(x) + 0x8)
#define HW_USB_PHY_PWD_TOG_ADDR(x)  (HW_USB_PHY_PWD_ADDR(x) + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_PWD(x)           (*(volatile hw_usb_phy_pwd_t *) HW_USB_PHY_PWD_ADDR(x))
#define HW_USB_PHY_PWD_RD(x)        (HW_USB_PHY_PWD(x).U)
#define HW_USB_PHY_PWD_WR(x, v)     (HW_USB_PHY_PWD(x).U = (v))
#define HW_USB_PHY_PWD_SET(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_PWD_SET_ADDR(x)) = (v))
#define HW_USB_PHY_PWD_CLR(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_PWD_CLR_ADDR(x)) = (v))
#define HW_USB_PHY_PWD_TOG(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_PWD_TOG_ADDR(x)) = (v))
#endif

/*
 * constants & macros for individual USB_PHY_PWD bitfields
 */

/* --- Register HW_USB_PHY_PWD, field TXPWDFS[10] (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed drivers. This turns off the current
 * starvation sources and puts the drivers into high-impedance output. Note that this bit will be
 * auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_TXPWDFS      (10)      //!< Bit position for USB_PHY_PWD_TXPWDFS.
#define BM_USB_PHY_PWD_TXPWDFS      (0x00000400)  //!< Bit mask for USB_PHY_PWD_TXPWDFS.

//! @brief Get value of USB_PHY_PWD_TXPWDFS from a register value.
#define BG_USB_PHY_PWD_TXPWDFS(r)   (((r) & BM_USB_PHY_PWD_TXPWDFS) >> BP_USB_PHY_PWD_TXPWDFS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_PWD_TXPWDFS.
#define BF_USB_PHY_PWD_TXPWDFS(v)   ((((reg32_t) v) << BP_USB_PHY_PWD_TXPWDFS) & BM_USB_PHY_PWD_TXPWDFS)
#else
//! @brief Format value for bitfield USB_PHY_PWD_TXPWDFS.
#define BF_USB_PHY_PWD_TXPWDFS(v)   (((v) << BP_USB_PHY_PWD_TXPWDFS) & BM_USB_PHY_PWD_TXPWDFS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDFS field to a new value.
#define BW_USB_PHY_PWD_TXPWDFS(x, v)   BFn_CS1((x), USB_PHY_PWD, TXPWDFS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDIBIAS[11] (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY current bias block for the transmitter. This bit
 * should be set only when the USB is in suspend mode. This effectively powers down the entire USB
 * transmit path. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this bit to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_TXPWDIBIAS      (11)      //!< Bit position for USB_PHY_PWD_TXPWDIBIAS.
#define BM_USB_PHY_PWD_TXPWDIBIAS      (0x00000800)  //!< Bit mask for USB_PHY_PWD_TXPWDIBIAS.

//! @brief Get value of USB_PHY_PWD_TXPWDIBIAS from a register value.
#define BG_USB_PHY_PWD_TXPWDIBIAS(r)   (((r) & BM_USB_PHY_PWD_TXPWDIBIAS) >> BP_USB_PHY_PWD_TXPWDIBIAS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_PWD_TXPWDIBIAS.
#define BF_USB_PHY_PWD_TXPWDIBIAS(v)   ((((reg32_t) v) << BP_USB_PHY_PWD_TXPWDIBIAS) & BM_USB_PHY_PWD_TXPWDIBIAS)
#else
//! @brief Format value for bitfield USB_PHY_PWD_TXPWDIBIAS.
#define BF_USB_PHY_PWD_TXPWDIBIAS(v)   (((v) << BP_USB_PHY_PWD_TXPWDIBIAS) & BM_USB_PHY_PWD_TXPWDIBIAS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDIBIAS field to a new value.
#define BW_USB_PHY_PWD_TXPWDIBIAS(x, v)   BFn_CS1((x), USB_PHY_PWD, TXPWDIBIAS, v)
#endif

/* --- Register HW_USB_PHY_PWD, field TXPWDV2I[12] (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB PHY transmit V-to-I converter and the current
 * mirror. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled. Note that these circuits are shared with the
 * battery charge circuit. Setting this to 1 does not power-down these circuits, unless the
 * corresponding bit in the battery charger is also set for power-down.
 */

#define BP_USB_PHY_PWD_TXPWDV2I      (12)      //!< Bit position for USB_PHY_PWD_TXPWDV2I.
#define BM_USB_PHY_PWD_TXPWDV2I      (0x00001000)  //!< Bit mask for USB_PHY_PWD_TXPWDV2I.

//! @brief Get value of USB_PHY_PWD_TXPWDV2I from a register value.
#define BG_USB_PHY_PWD_TXPWDV2I(r)   (((r) & BM_USB_PHY_PWD_TXPWDV2I) >> BP_USB_PHY_PWD_TXPWDV2I)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_PWD_TXPWDV2I.
#define BF_USB_PHY_PWD_TXPWDV2I(v)   ((((reg32_t) v) << BP_USB_PHY_PWD_TXPWDV2I) & BM_USB_PHY_PWD_TXPWDV2I)
#else
//! @brief Format value for bitfield USB_PHY_PWD_TXPWDV2I.
#define BF_USB_PHY_PWD_TXPWDV2I(v)   (((v) << BP_USB_PHY_PWD_TXPWDV2I) & BM_USB_PHY_PWD_TXPWDV2I)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXPWDV2I field to a new value.
#define BW_USB_PHY_PWD_TXPWDV2I(x, v)   BFn_CS1((x), USB_PHY_PWD, TXPWDV2I, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDENV[17] (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed receiver envelope detector (squelch
 * signal). Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_RXPWDENV      (17)      //!< Bit position for USB_PHY_PWD_RXPWDENV.
#define BM_USB_PHY_PWD_RXPWDENV      (0x00020000)  //!< Bit mask for USB_PHY_PWD_RXPWDENV.

//! @brief Get value of USB_PHY_PWD_RXPWDENV from a register value.
#define BG_USB_PHY_PWD_RXPWDENV(r)   (((r) & BM_USB_PHY_PWD_RXPWDENV) >> BP_USB_PHY_PWD_RXPWDENV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_PWD_RXPWDENV.
#define BF_USB_PHY_PWD_RXPWDENV(v)   ((((reg32_t) v) << BP_USB_PHY_PWD_RXPWDENV) & BM_USB_PHY_PWD_RXPWDENV)
#else
//! @brief Format value for bitfield USB_PHY_PWD_RXPWDENV.
#define BF_USB_PHY_PWD_RXPWDENV(v)   (((v) << BP_USB_PHY_PWD_RXPWDENV) & BM_USB_PHY_PWD_RXPWDENV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDENV field to a new value.
#define BW_USB_PHY_PWD_RXPWDENV(x, v)   BFn_CS1((x), USB_PHY_PWD, RXPWDENV, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWD1PT1[18] (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB full-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_RXPWD1PT1      (18)      //!< Bit position for USB_PHY_PWD_RXPWD1PT1.
#define BM_USB_PHY_PWD_RXPWD1PT1      (0x00040000)  //!< Bit mask for USB_PHY_PWD_RXPWD1PT1.

//! @brief Get value of USB_PHY_PWD_RXPWD1PT1 from a register value.
#define BG_USB_PHY_PWD_RXPWD1PT1(r)   (((r) & BM_USB_PHY_PWD_RXPWD1PT1) >> BP_USB_PHY_PWD_RXPWD1PT1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_PWD_RXPWD1PT1.
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   ((((reg32_t) v) << BP_USB_PHY_PWD_RXPWD1PT1) & BM_USB_PHY_PWD_RXPWD1PT1)
#else
//! @brief Format value for bitfield USB_PHY_PWD_RXPWD1PT1.
#define BF_USB_PHY_PWD_RXPWD1PT1(v)   (((v) << BP_USB_PHY_PWD_RXPWD1PT1) & BM_USB_PHY_PWD_RXPWD1PT1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWD1PT1 field to a new value.
#define BW_USB_PHY_PWD_RXPWD1PT1(x, v)   BFn_CS1((x), USB_PHY_PWD, RXPWD1PT1, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDDIFF[19] (RW)
 *
 * 0 = Normal operation. 1 = Power-down the USB high-speed differential receiver. Note that this bit
 * will be auto cleared if there is USB wakeup event while ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is
 * enabled.
 */

#define BP_USB_PHY_PWD_RXPWDDIFF      (19)      //!< Bit position for USB_PHY_PWD_RXPWDDIFF.
#define BM_USB_PHY_PWD_RXPWDDIFF      (0x00080000)  //!< Bit mask for USB_PHY_PWD_RXPWDDIFF.

//! @brief Get value of USB_PHY_PWD_RXPWDDIFF from a register value.
#define BG_USB_PHY_PWD_RXPWDDIFF(r)   (((r) & BM_USB_PHY_PWD_RXPWDDIFF) >> BP_USB_PHY_PWD_RXPWDDIFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_PWD_RXPWDDIFF.
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   ((((reg32_t) v) << BP_USB_PHY_PWD_RXPWDDIFF) & BM_USB_PHY_PWD_RXPWDDIFF)
#else
//! @brief Format value for bitfield USB_PHY_PWD_RXPWDDIFF.
#define BF_USB_PHY_PWD_RXPWDDIFF(v)   (((v) << BP_USB_PHY_PWD_RXPWDDIFF) & BM_USB_PHY_PWD_RXPWDDIFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDDIFF field to a new value.
#define BW_USB_PHY_PWD_RXPWDDIFF(x, v)   BFn_CS1((x), USB_PHY_PWD, RXPWDDIFF, v)
#endif

/* --- Register HW_USB_PHY_PWD, field RXPWDRX[20] (RW)
 *
 * 0 = Normal operation. 1 = Power-down the entire USB PHY receiver block except for the full-speed
 * differential receiver. Note that this bit will be auto cleared if there is USB wakeup event while
 * ENAUTOCLR_PHY_PWD bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_PWD_RXPWDRX      (20)      //!< Bit position for USB_PHY_PWD_RXPWDRX.
#define BM_USB_PHY_PWD_RXPWDRX      (0x00100000)  //!< Bit mask for USB_PHY_PWD_RXPWDRX.

//! @brief Get value of USB_PHY_PWD_RXPWDRX from a register value.
#define BG_USB_PHY_PWD_RXPWDRX(r)   (((r) & BM_USB_PHY_PWD_RXPWDRX) >> BP_USB_PHY_PWD_RXPWDRX)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_PWD_RXPWDRX.
#define BF_USB_PHY_PWD_RXPWDRX(v)   ((((reg32_t) v) << BP_USB_PHY_PWD_RXPWDRX) & BM_USB_PHY_PWD_RXPWDRX)
#else
//! @brief Format value for bitfield USB_PHY_PWD_RXPWDRX.
#define BF_USB_PHY_PWD_RXPWDRX(v)   (((v) << BP_USB_PHY_PWD_RXPWDRX) & BM_USB_PHY_PWD_RXPWDRX)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXPWDRX field to a new value.
#define BW_USB_PHY_PWD_RXPWDRX(x, v)   BFn_CS1((x), USB_PHY_PWD, RXPWDRX, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_TX - USB PHY Transmitter Control Register (RW)
 *
 * Reset value: 0x10060607
 *
 * The USB PHY Transmitter Control Register handles the transmit controls.
 */
typedef union _hw_usb_phy_tx
{
    reg32_t U;
    struct _hw_usb_phy_tx_bitfields
    {
        unsigned D_CAL : 4; //!< [3:0] Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
        unsigned RESERVED0 : 4; //!< [7:4] Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DN : 4; //!< [11:8] Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED1 : 4; //!< [15:12] Reserved. Note: This bit should remain clear.
        unsigned TXCAL45DP : 4; //!< [19:16] Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000. Resistance is centered by design at 0110.
        unsigned RESERVED2 : 12; //!< [31:20] Reserved.
    } B;
} hw_usb_phy_tx_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_TX register
 */
#define HW_USB_PHY_TX_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x10)
#define HW_USB_PHY_TX_SET_ADDR(x)  (HW_USB_PHY_TX_ADDR(x) + 0x4)
#define HW_USB_PHY_TX_CLR_ADDR(x)  (HW_USB_PHY_TX_ADDR(x) + 0x8)
#define HW_USB_PHY_TX_TOG_ADDR(x)  (HW_USB_PHY_TX_ADDR(x) + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_TX(x)           (*(volatile hw_usb_phy_tx_t *) HW_USB_PHY_TX_ADDR(x))
#define HW_USB_PHY_TX_RD(x)        (HW_USB_PHY_TX(x).U)
#define HW_USB_PHY_TX_WR(x, v)     (HW_USB_PHY_TX(x).U = (v))
#define HW_USB_PHY_TX_SET(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_TX_SET_ADDR(x)) = (v))
#define HW_USB_PHY_TX_CLR(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_TX_CLR_ADDR(x)) = (v))
#define HW_USB_PHY_TX_TOG(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_TX_TOG_ADDR(x)) = (v))
#endif

/*
 * constants & macros for individual USB_PHY_TX bitfields
 */

/* --- Register HW_USB_PHY_TX, field D_CAL[3:0] (RW)
 *
 * Resistor Trimming Code: 0000 = 0.16% 0111 = Nominal 1111 = +25%
 */

#define BP_USB_PHY_TX_D_CAL      (0)      //!< Bit position for USB_PHY_TX_D_CAL.
#define BM_USB_PHY_TX_D_CAL      (0x0000000f)  //!< Bit mask for USB_PHY_TX_D_CAL.

//! @brief Get value of USB_PHY_TX_D_CAL from a register value.
#define BG_USB_PHY_TX_D_CAL(r)   (((r) & BM_USB_PHY_TX_D_CAL) >> BP_USB_PHY_TX_D_CAL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_TX_D_CAL.
#define BF_USB_PHY_TX_D_CAL(v)   ((((reg32_t) v) << BP_USB_PHY_TX_D_CAL) & BM_USB_PHY_TX_D_CAL)
#else
//! @brief Format value for bitfield USB_PHY_TX_D_CAL.
#define BF_USB_PHY_TX_D_CAL(v)   (((v) << BP_USB_PHY_TX_D_CAL) & BM_USB_PHY_TX_D_CAL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the D_CAL field to a new value.
#define BW_USB_PHY_TX_D_CAL(x, v)   BFn_CS1((x), USB_PHY_TX, D_CAL, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DN[11:8] (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DN output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_TXCAL45DN      (8)      //!< Bit position for USB_PHY_TX_TXCAL45DN.
#define BM_USB_PHY_TX_TXCAL45DN      (0x00000f00)  //!< Bit mask for USB_PHY_TX_TXCAL45DN.

//! @brief Get value of USB_PHY_TX_TXCAL45DN from a register value.
#define BG_USB_PHY_TX_TXCAL45DN(r)   (((r) & BM_USB_PHY_TX_TXCAL45DN) >> BP_USB_PHY_TX_TXCAL45DN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_TX_TXCAL45DN.
#define BF_USB_PHY_TX_TXCAL45DN(v)   ((((reg32_t) v) << BP_USB_PHY_TX_TXCAL45DN) & BM_USB_PHY_TX_TXCAL45DN)
#else
//! @brief Format value for bitfield USB_PHY_TX_TXCAL45DN.
#define BF_USB_PHY_TX_TXCAL45DN(v)   (((v) << BP_USB_PHY_TX_TXCAL45DN) & BM_USB_PHY_TX_TXCAL45DN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DN field to a new value.
#define BW_USB_PHY_TX_TXCAL45DN(x, v)   BFn_CS1((x), USB_PHY_TX, TXCAL45DN, v)
#endif

/* --- Register HW_USB_PHY_TX, field TXCAL45DP[19:16] (RW)
 *
 * Decode to select a 45-Ohm resistance to the USB_DP output pin. Maximum resistance = 0000.
 * Resistance is centered by design at 0110.
 */

#define BP_USB_PHY_TX_TXCAL45DP      (16)      //!< Bit position for USB_PHY_TX_TXCAL45DP.
#define BM_USB_PHY_TX_TXCAL45DP      (0x000f0000)  //!< Bit mask for USB_PHY_TX_TXCAL45DP.

//! @brief Get value of USB_PHY_TX_TXCAL45DP from a register value.
#define BG_USB_PHY_TX_TXCAL45DP(r)   (((r) & BM_USB_PHY_TX_TXCAL45DP) >> BP_USB_PHY_TX_TXCAL45DP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_TX_TXCAL45DP.
#define BF_USB_PHY_TX_TXCAL45DP(v)   ((((reg32_t) v) << BP_USB_PHY_TX_TXCAL45DP) & BM_USB_PHY_TX_TXCAL45DP)
#else
//! @brief Format value for bitfield USB_PHY_TX_TXCAL45DP.
#define BF_USB_PHY_TX_TXCAL45DP(v)   (((v) << BP_USB_PHY_TX_TXCAL45DP) & BM_USB_PHY_TX_TXCAL45DP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXCAL45DP field to a new value.
#define BW_USB_PHY_TX_TXCAL45DP(x, v)   BFn_CS1((x), USB_PHY_TX, TXCAL45DP, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_RX - USB PHY Receiver Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The USB PHY Receiver Control Register handles receive path controls.
 */
typedef union _hw_usb_phy_rx
{
    reg32_t U;
    struct _hw_usb_phy_rx_bitfields
    {
        unsigned ENVADJ : 3; //!< [2:0] The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 = Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED0 : 1; //!< [3] Reserved.
        unsigned DISCONADJ : 3; //!< [6:4] The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 = Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
        unsigned RESERVED1 : 15; //!< [21:7] Reserved.
        unsigned RXDBYPASS : 1; //!< [22] 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the full-speed differential receiver. This test mode is intended for lab use only.
        unsigned RESERVED2 : 9; //!< [31:23] Reserved.
    } B;
} hw_usb_phy_rx_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_RX register
 */
#define HW_USB_PHY_RX_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x20)
#define HW_USB_PHY_RX_SET_ADDR(x)  (HW_USB_PHY_RX_ADDR(x) + 0x4)
#define HW_USB_PHY_RX_CLR_ADDR(x)  (HW_USB_PHY_RX_ADDR(x) + 0x8)
#define HW_USB_PHY_RX_TOG_ADDR(x)  (HW_USB_PHY_RX_ADDR(x) + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_RX(x)           (*(volatile hw_usb_phy_rx_t *) HW_USB_PHY_RX_ADDR(x))
#define HW_USB_PHY_RX_RD(x)        (HW_USB_PHY_RX(x).U)
#define HW_USB_PHY_RX_WR(x, v)     (HW_USB_PHY_RX(x).U = (v))
#define HW_USB_PHY_RX_SET(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_RX_SET_ADDR(x)) = (v))
#define HW_USB_PHY_RX_CLR(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_RX_CLR_ADDR(x)) = (v))
#define HW_USB_PHY_RX_TOG(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_RX_TOG_ADDR(x)) = (v))
#endif

/*
 * constants & macros for individual USB_PHY_RX bitfields
 */

/* --- Register HW_USB_PHY_RX, field ENVADJ[2:0] (RW)
 *
 * The ENVADJ field adjusts the trip point for the envelope detector. 0000 = Trip-Level Voltage is
 * 0.12500 V 0001 = Trip-Level Voltage is 0.10000 V 0010 = Trip-Level Voltage is 0.13750 V 0011 =
 * Trip-Level Voltage is 0.15000 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_ENVADJ      (0)      //!< Bit position for USB_PHY_RX_ENVADJ.
#define BM_USB_PHY_RX_ENVADJ      (0x00000007)  //!< Bit mask for USB_PHY_RX_ENVADJ.

//! @brief Get value of USB_PHY_RX_ENVADJ from a register value.
#define BG_USB_PHY_RX_ENVADJ(r)   (((r) & BM_USB_PHY_RX_ENVADJ) >> BP_USB_PHY_RX_ENVADJ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_RX_ENVADJ.
#define BF_USB_PHY_RX_ENVADJ(v)   ((((reg32_t) v) << BP_USB_PHY_RX_ENVADJ) & BM_USB_PHY_RX_ENVADJ)
#else
//! @brief Format value for bitfield USB_PHY_RX_ENVADJ.
#define BF_USB_PHY_RX_ENVADJ(v)   (((v) << BP_USB_PHY_RX_ENVADJ) & BM_USB_PHY_RX_ENVADJ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVADJ field to a new value.
#define BW_USB_PHY_RX_ENVADJ(x, v)   BFn_CS1((x), USB_PHY_RX, ENVADJ, v)
#endif

/* --- Register HW_USB_PHY_RX, field DISCONADJ[6:4] (RW)
 *
 * The DISCONADJ field adjusts the trip point for the disconnect detector: 0000 = Trip-Level Voltage
 * is 0.57500 V 0001 = Trip-Level Voltage is 0.56875 V 0010 = Trip-Level Voltage is 0.58125 V 0011 =
 * Trip-Level Voltage is 0.58750 V 01XX = Reserved 1XXX = Reserved
 */

#define BP_USB_PHY_RX_DISCONADJ      (4)      //!< Bit position for USB_PHY_RX_DISCONADJ.
#define BM_USB_PHY_RX_DISCONADJ      (0x00000070)  //!< Bit mask for USB_PHY_RX_DISCONADJ.

//! @brief Get value of USB_PHY_RX_DISCONADJ from a register value.
#define BG_USB_PHY_RX_DISCONADJ(r)   (((r) & BM_USB_PHY_RX_DISCONADJ) >> BP_USB_PHY_RX_DISCONADJ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_RX_DISCONADJ.
#define BF_USB_PHY_RX_DISCONADJ(v)   ((((reg32_t) v) << BP_USB_PHY_RX_DISCONADJ) & BM_USB_PHY_RX_DISCONADJ)
#else
//! @brief Format value for bitfield USB_PHY_RX_DISCONADJ.
#define BF_USB_PHY_RX_DISCONADJ(v)   (((v) << BP_USB_PHY_RX_DISCONADJ) & BM_USB_PHY_RX_DISCONADJ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DISCONADJ field to a new value.
#define BW_USB_PHY_RX_DISCONADJ(x, v)   BFn_CS1((x), USB_PHY_RX, DISCONADJ, v)
#endif

/* --- Register HW_USB_PHY_RX, field RXDBYPASS[22] (RW)
 *
 * 0 = Normal operation. 1 = Use the output of the USB_DP single-ended receiver in place of the
 * full-speed differential receiver. This test mode is intended for lab use only.
 */

#define BP_USB_PHY_RX_RXDBYPASS      (22)      //!< Bit position for USB_PHY_RX_RXDBYPASS.
#define BM_USB_PHY_RX_RXDBYPASS      (0x00400000)  //!< Bit mask for USB_PHY_RX_RXDBYPASS.

//! @brief Get value of USB_PHY_RX_RXDBYPASS from a register value.
#define BG_USB_PHY_RX_RXDBYPASS(r)   (((r) & BM_USB_PHY_RX_RXDBYPASS) >> BP_USB_PHY_RX_RXDBYPASS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_RX_RXDBYPASS.
#define BF_USB_PHY_RX_RXDBYPASS(v)   ((((reg32_t) v) << BP_USB_PHY_RX_RXDBYPASS) & BM_USB_PHY_RX_RXDBYPASS)
#else
//! @brief Format value for bitfield USB_PHY_RX_RXDBYPASS.
#define BF_USB_PHY_RX_RXDBYPASS(v)   (((v) << BP_USB_PHY_RX_RXDBYPASS) & BM_USB_PHY_RX_RXDBYPASS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXDBYPASS field to a new value.
#define BW_USB_PHY_RX_RXDBYPASS(x, v)   BFn_CS1((x), USB_PHY_RX, RXDBYPASS, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_CTRL - USB PHY General Control Register (RW)
 *
 * Reset value: 0xc0200000
 *
 * The USB PHY General Control Register handles OTG and Host controls. This register also includes
 * interrupt enables and connectivity detect enables and results.
 */
typedef union _hw_usb_phy_ctrl
{
    reg32_t U;
    struct _hw_usb_phy_ctrl_bitfields
    {
        unsigned ENOTG_ID_CHG_IRQ : 1; //!< [0] Enable OTG_ID_CHG_IRQ.
        unsigned ENHOSTDISCONDETECT : 1; //!< [1] For host mode, enables high-speed disconnect detector. This signal allows the override of enabling the detection that is normally done in the UTMI controller. The UTMI controller enables this circuit whenever the host sends a start-of-frame packet.
        unsigned ENIRQHOSTDISCON : 1; //!< [2] Enables interrupt for detection of disconnection to Device when in high-speed host mode. This should be enabled after ENDEVPLUGINDETECT is enabled.
        unsigned HOSTDISCONDETECT_IRQ : 1; //!< [3] Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENDEVPLUGINDETECT : 1; //!< [4] For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
        unsigned DEVPLUGIN_POLARITY : 1; //!< [5] For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
        unsigned OTG_ID_CHG_IRQ : 1; //!< [6] OTG ID change interrupt. Indicates the value of ID pin changed.
        unsigned ENOTGIDDETECT : 1; //!< [7] Enables circuit to detect resistance of MiniAB ID pin.
        unsigned RESUMEIRQSTICKY : 1; //!< [8] Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only set during the wake-up period.
        unsigned ENIRQRESUMEDETECT : 1; //!< [9] Enables interrupt for detection of a non-J state on the USB line. This should only be enabled after the device has entered suspend mode.
        unsigned RESUME_IRQ : 1; //!< [10] Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset during suspend. Use this bit to wake up from suspend for either the resume or the reset case. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned ENIRQDEVPLUGIN : 1; //!< [11] Enables interrupt for the detection of connectivity to the USB line.
        unsigned DEVPLUGIN_IRQ : 1; //!< [12] Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned DATA_ON_LRADC : 1; //!< [13] Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
        unsigned ENUTMILEVEL2 : 1; //!< [14] Enables UTMI+ Level2. This should be enabled if needs to support LS device
        unsigned ENUTMILEVEL3 : 1; //!< [15] Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device connected
        unsigned ENIRQWAKEUP : 1; //!< [16] Enables interrupt for the wakeup events.
        unsigned WAKEUP_IRQ : 1; //!< [17] Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space and not by a general write.
        unsigned RESERVED0 : 1; //!< [18] Reserved.
        unsigned ENAUTOCLR_CLKGATE : 1; //!< [19] Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENAUTOCLR_PHY_PWD : 1; //!< [20] Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
        unsigned ENDPDMCHG_WKUP : 1; //!< [21] Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled by default.
        unsigned ENIDCHG_WKUP : 1; //!< [22] Enables the feature to wakeup USB if ID is toggled when USB is suspended.
        unsigned ENVBUSCHG_WKUP : 1; //!< [23] Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
        unsigned FSDLL_RST_EN : 1; //!< [24] Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
        unsigned RESERVED1 : 2; //!< [26:25] Reserved.
        unsigned OTG_ID_VALUE : 1; //!< [27] Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE has debounce logic to filter the glitches on ID Pad.
        unsigned HOST_FORCE_LS_SE0 : 1; //!< [28] Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in host mode for the resume sequence. After the packet is transferred, this bit is cleared. The design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger this event when leaving suspend. This bit is used in conjunction with USBPHYx_DEBUG_HOST_RESUME_DEBUG.
        unsigned UTMI_SUSPENDM : 1; //!< [29] Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required by the UTMI specification.
        unsigned CLKGATE : 1; //!< [30] Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated. Note this bit can be auto-cleared if there is any wakeup event when USB is suspended while ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
        unsigned SFTRST : 1; //!< [31] Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL registers. Set to 0 to release the PHY from reset.
    } B;
} hw_usb_phy_ctrl_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_CTRL register
 */
#define HW_USB_PHY_CTRL_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x30)
#define HW_USB_PHY_CTRL_SET_ADDR(x)  (HW_USB_PHY_CTRL_ADDR(x) + 0x4)
#define HW_USB_PHY_CTRL_CLR_ADDR(x)  (HW_USB_PHY_CTRL_ADDR(x) + 0x8)
#define HW_USB_PHY_CTRL_TOG_ADDR(x)  (HW_USB_PHY_CTRL_ADDR(x) + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_CTRL(x)           (*(volatile hw_usb_phy_ctrl_t *) HW_USB_PHY_CTRL_ADDR(x))
#define HW_USB_PHY_CTRL_RD(x)        (HW_USB_PHY_CTRL(x).U)
#define HW_USB_PHY_CTRL_WR(x, v)     (HW_USB_PHY_CTRL(x).U = (v))
#define HW_USB_PHY_CTRL_SET(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_CTRL_SET_ADDR(x)) = (v))
#define HW_USB_PHY_CTRL_CLR(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_CTRL_CLR_ADDR(x)) = (v))
#define HW_USB_PHY_CTRL_TOG(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_CTRL_TOG_ADDR(x)) = (v))
#endif

/*
 * constants & macros for individual USB_PHY_CTRL bitfields
 */

/* --- Register HW_USB_PHY_CTRL, field ENOTG_ID_CHG_IRQ[0] (RW)
 *
 * Enable OTG_ID_CHG_IRQ.
 */

#define BP_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ      (0)      //!< Bit position for USB_PHY_CTRL_ENOTG_ID_CHG_IRQ.
#define BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ      (0x00000001)  //!< Bit mask for USB_PHY_CTRL_ENOTG_ID_CHG_IRQ.

//! @brief Get value of USB_PHY_CTRL_ENOTG_ID_CHG_IRQ from a register value.
#define BG_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(r)   (((r) & BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ) >> BP_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENOTG_ID_CHG_IRQ.
#define BF_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ) & BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENOTG_ID_CHG_IRQ.
#define BF_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(v)   (((v) << BP_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ) & BM_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_ENOTG_ID_CHG_IRQ(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENOTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENHOSTDISCONDETECT[1] (RW)
 *
 * For host mode, enables high-speed disconnect detector. This signal allows the override of
 * enabling the detection that is normally done in the UTMI controller. The UTMI controller enables
 * this circuit whenever the host sends a start-of-frame packet.
 */

#define BP_USB_PHY_CTRL_ENHOSTDISCONDETECT      (1)      //!< Bit position for USB_PHY_CTRL_ENHOSTDISCONDETECT.
#define BM_USB_PHY_CTRL_ENHOSTDISCONDETECT      (0x00000002)  //!< Bit mask for USB_PHY_CTRL_ENHOSTDISCONDETECT.

//! @brief Get value of USB_PHY_CTRL_ENHOSTDISCONDETECT from a register value.
#define BG_USB_PHY_CTRL_ENHOSTDISCONDETECT(r)   (((r) & BM_USB_PHY_CTRL_ENHOSTDISCONDETECT) >> BP_USB_PHY_CTRL_ENHOSTDISCONDETECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENHOSTDISCONDETECT.
#define BF_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENHOSTDISCONDETECT) & BM_USB_PHY_CTRL_ENHOSTDISCONDETECT)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENHOSTDISCONDETECT.
#define BF_USB_PHY_CTRL_ENHOSTDISCONDETECT(v)   (((v) << BP_USB_PHY_CTRL_ENHOSTDISCONDETECT) & BM_USB_PHY_CTRL_ENHOSTDISCONDETECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHOSTDISCONDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENHOSTDISCONDETECT(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENHOSTDISCONDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQHOSTDISCON[2] (RW)
 *
 * Enables interrupt for detection of disconnection to Device when in high-speed host mode. This
 * should be enabled after ENDEVPLUGINDETECT is enabled.
 */

#define BP_USB_PHY_CTRL_ENIRQHOSTDISCON      (2)      //!< Bit position for USB_PHY_CTRL_ENIRQHOSTDISCON.
#define BM_USB_PHY_CTRL_ENIRQHOSTDISCON      (0x00000004)  //!< Bit mask for USB_PHY_CTRL_ENIRQHOSTDISCON.

//! @brief Get value of USB_PHY_CTRL_ENIRQHOSTDISCON from a register value.
#define BG_USB_PHY_CTRL_ENIRQHOSTDISCON(r)   (((r) & BM_USB_PHY_CTRL_ENIRQHOSTDISCON) >> BP_USB_PHY_CTRL_ENIRQHOSTDISCON)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQHOSTDISCON.
#define BF_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENIRQHOSTDISCON) & BM_USB_PHY_CTRL_ENIRQHOSTDISCON)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQHOSTDISCON.
#define BF_USB_PHY_CTRL_ENIRQHOSTDISCON(v)   (((v) << BP_USB_PHY_CTRL_ENIRQHOSTDISCON) & BM_USB_PHY_CTRL_ENIRQHOSTDISCON)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQHOSTDISCON field to a new value.
#define BW_USB_PHY_CTRL_ENIRQHOSTDISCON(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENIRQHOSTDISCON, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field HOSTDISCONDETECT_IRQ[3] (RW)
 *
 * Indicates that the device has disconnected in high-speed mode. Reset this bit by writing a 1 to
 * the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ      (3)      //!< Bit position for USB_PHY_CTRL_HOSTDISCONDETECT_IRQ.
#define BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ      (0x00000008)  //!< Bit mask for USB_PHY_CTRL_HOSTDISCONDETECT_IRQ.

//! @brief Get value of USB_PHY_CTRL_HOSTDISCONDETECT_IRQ from a register value.
#define BG_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(r)   (((r) & BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ) >> BP_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_HOSTDISCONDETECT_IRQ.
#define BF_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ) & BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_HOSTDISCONDETECT_IRQ.
#define BF_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(v)   (((v) << BP_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ) & BM_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOSTDISCONDETECT_IRQ field to a new value.
#define BW_USB_PHY_CTRL_HOSTDISCONDETECT_IRQ(x, v)   BFn_CS1((x), USB_PHY_CTRL, HOSTDISCONDETECT_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDEVPLUGINDETECT[4] (RW)
 *
 * For device mode, enables 200-KOhm pullups for detecting connectivity to the host.
 */

#define BP_USB_PHY_CTRL_ENDEVPLUGINDETECT      (4)      //!< Bit position for USB_PHY_CTRL_ENDEVPLUGINDETECT.
#define BM_USB_PHY_CTRL_ENDEVPLUGINDETECT      (0x00000010)  //!< Bit mask for USB_PHY_CTRL_ENDEVPLUGINDETECT.

//! @brief Get value of USB_PHY_CTRL_ENDEVPLUGINDETECT from a register value.
#define BG_USB_PHY_CTRL_ENDEVPLUGINDETECT(r)   (((r) & BM_USB_PHY_CTRL_ENDEVPLUGINDETECT) >> BP_USB_PHY_CTRL_ENDEVPLUGINDETECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENDEVPLUGINDETECT.
#define BF_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENDEVPLUGINDETECT) & BM_USB_PHY_CTRL_ENDEVPLUGINDETECT)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENDEVPLUGINDETECT.
#define BF_USB_PHY_CTRL_ENDEVPLUGINDETECT(v)   (((v) << BP_USB_PHY_CTRL_ENDEVPLUGINDETECT) & BM_USB_PHY_CTRL_ENDEVPLUGINDETECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDEVPLUGINDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENDEVPLUGINDETECT(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENDEVPLUGINDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_POLARITY[5] (RW)
 *
 * For device mode, if this bit is cleared to 0, then it trips the interrupt if the device is
 * plugged in. If set to 1, then it trips the interrupt if the device is unplugged.
 */

#define BP_USB_PHY_CTRL_DEVPLUGIN_POLARITY      (5)      //!< Bit position for USB_PHY_CTRL_DEVPLUGIN_POLARITY.
#define BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY      (0x00000020)  //!< Bit mask for USB_PHY_CTRL_DEVPLUGIN_POLARITY.

//! @brief Get value of USB_PHY_CTRL_DEVPLUGIN_POLARITY from a register value.
#define BG_USB_PHY_CTRL_DEVPLUGIN_POLARITY(r)   (((r) & BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY) >> BP_USB_PHY_CTRL_DEVPLUGIN_POLARITY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_DEVPLUGIN_POLARITY.
#define BF_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_DEVPLUGIN_POLARITY) & BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_DEVPLUGIN_POLARITY.
#define BF_USB_PHY_CTRL_DEVPLUGIN_POLARITY(v)   (((v) << BP_USB_PHY_CTRL_DEVPLUGIN_POLARITY) & BM_USB_PHY_CTRL_DEVPLUGIN_POLARITY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_POLARITY field to a new value.
#define BW_USB_PHY_CTRL_DEVPLUGIN_POLARITY(x, v)   BFn_CS1((x), USB_PHY_CTRL, DEVPLUGIN_POLARITY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_CHG_IRQ[6] (RW)
 *
 * OTG ID change interrupt. Indicates the value of ID pin changed.
 */

#define BP_USB_PHY_CTRL_OTG_ID_CHG_IRQ      (6)      //!< Bit position for USB_PHY_CTRL_OTG_ID_CHG_IRQ.
#define BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ      (0x00000040)  //!< Bit mask for USB_PHY_CTRL_OTG_ID_CHG_IRQ.

//! @brief Get value of USB_PHY_CTRL_OTG_ID_CHG_IRQ from a register value.
#define BG_USB_PHY_CTRL_OTG_ID_CHG_IRQ(r)   (((r) & BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ) >> BP_USB_PHY_CTRL_OTG_ID_CHG_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_OTG_ID_CHG_IRQ.
#define BF_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_OTG_ID_CHG_IRQ) & BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_OTG_ID_CHG_IRQ.
#define BF_USB_PHY_CTRL_OTG_ID_CHG_IRQ(v)   (((v) << BP_USB_PHY_CTRL_OTG_ID_CHG_IRQ) & BM_USB_PHY_CTRL_OTG_ID_CHG_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OTG_ID_CHG_IRQ field to a new value.
#define BW_USB_PHY_CTRL_OTG_ID_CHG_IRQ(x, v)   BFn_CS1((x), USB_PHY_CTRL, OTG_ID_CHG_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENOTGIDDETECT[7] (RW)
 *
 * Enables circuit to detect resistance of MiniAB ID pin.
 */

#define BP_USB_PHY_CTRL_ENOTGIDDETECT      (7)      //!< Bit position for USB_PHY_CTRL_ENOTGIDDETECT.
#define BM_USB_PHY_CTRL_ENOTGIDDETECT      (0x00000080)  //!< Bit mask for USB_PHY_CTRL_ENOTGIDDETECT.

//! @brief Get value of USB_PHY_CTRL_ENOTGIDDETECT from a register value.
#define BG_USB_PHY_CTRL_ENOTGIDDETECT(r)   (((r) & BM_USB_PHY_CTRL_ENOTGIDDETECT) >> BP_USB_PHY_CTRL_ENOTGIDDETECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENOTGIDDETECT.
#define BF_USB_PHY_CTRL_ENOTGIDDETECT(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENOTGIDDETECT) & BM_USB_PHY_CTRL_ENOTGIDDETECT)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENOTGIDDETECT.
#define BF_USB_PHY_CTRL_ENOTGIDDETECT(v)   (((v) << BP_USB_PHY_CTRL_ENOTGIDDETECT) & BM_USB_PHY_CTRL_ENOTGIDDETECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENOTGIDDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENOTGIDDETECT(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENOTGIDDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUMEIRQSTICKY[8] (RW)
 *
 * Set to 1 will make RESUME_IRQ bit a sticky bit until software clear it. Set to 0, RESUME_IRQ only
 * set during the wake-up period.
 */

#define BP_USB_PHY_CTRL_RESUMEIRQSTICKY      (8)      //!< Bit position for USB_PHY_CTRL_RESUMEIRQSTICKY.
#define BM_USB_PHY_CTRL_RESUMEIRQSTICKY      (0x00000100)  //!< Bit mask for USB_PHY_CTRL_RESUMEIRQSTICKY.

//! @brief Get value of USB_PHY_CTRL_RESUMEIRQSTICKY from a register value.
#define BG_USB_PHY_CTRL_RESUMEIRQSTICKY(r)   (((r) & BM_USB_PHY_CTRL_RESUMEIRQSTICKY) >> BP_USB_PHY_CTRL_RESUMEIRQSTICKY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_RESUMEIRQSTICKY.
#define BF_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_RESUMEIRQSTICKY) & BM_USB_PHY_CTRL_RESUMEIRQSTICKY)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_RESUMEIRQSTICKY.
#define BF_USB_PHY_CTRL_RESUMEIRQSTICKY(v)   (((v) << BP_USB_PHY_CTRL_RESUMEIRQSTICKY) & BM_USB_PHY_CTRL_RESUMEIRQSTICKY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUMEIRQSTICKY field to a new value.
#define BW_USB_PHY_CTRL_RESUMEIRQSTICKY(x, v)   BFn_CS1((x), USB_PHY_CTRL, RESUMEIRQSTICKY, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQRESUMEDETECT[9] (RW)
 *
 * Enables interrupt for detection of a non-J state on the USB line. This should only be enabled
 * after the device has entered suspend mode.
 */

#define BP_USB_PHY_CTRL_ENIRQRESUMEDETECT      (9)      //!< Bit position for USB_PHY_CTRL_ENIRQRESUMEDETECT.
#define BM_USB_PHY_CTRL_ENIRQRESUMEDETECT      (0x00000200)  //!< Bit mask for USB_PHY_CTRL_ENIRQRESUMEDETECT.

//! @brief Get value of USB_PHY_CTRL_ENIRQRESUMEDETECT from a register value.
#define BG_USB_PHY_CTRL_ENIRQRESUMEDETECT(r)   (((r) & BM_USB_PHY_CTRL_ENIRQRESUMEDETECT) >> BP_USB_PHY_CTRL_ENIRQRESUMEDETECT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQRESUMEDETECT.
#define BF_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENIRQRESUMEDETECT) & BM_USB_PHY_CTRL_ENIRQRESUMEDETECT)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQRESUMEDETECT.
#define BF_USB_PHY_CTRL_ENIRQRESUMEDETECT(v)   (((v) << BP_USB_PHY_CTRL_ENIRQRESUMEDETECT) & BM_USB_PHY_CTRL_ENIRQRESUMEDETECT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQRESUMEDETECT field to a new value.
#define BW_USB_PHY_CTRL_ENIRQRESUMEDETECT(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENIRQRESUMEDETECT, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field RESUME_IRQ[10] (RW)
 *
 * Indicates that the host is sending a wake-up after suspend. This bit is also set on a reset
 * during suspend. Use this bit to wake up from suspend for either the resume or the reset case.
 * Reset this bit by writing a 1 to the clear address space and not by a general write.
 */

#define BP_USB_PHY_CTRL_RESUME_IRQ      (10)      //!< Bit position for USB_PHY_CTRL_RESUME_IRQ.
#define BM_USB_PHY_CTRL_RESUME_IRQ      (0x00000400)  //!< Bit mask for USB_PHY_CTRL_RESUME_IRQ.

//! @brief Get value of USB_PHY_CTRL_RESUME_IRQ from a register value.
#define BG_USB_PHY_CTRL_RESUME_IRQ(r)   (((r) & BM_USB_PHY_CTRL_RESUME_IRQ) >> BP_USB_PHY_CTRL_RESUME_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_RESUME_IRQ.
#define BF_USB_PHY_CTRL_RESUME_IRQ(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_RESUME_IRQ) & BM_USB_PHY_CTRL_RESUME_IRQ)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_RESUME_IRQ.
#define BF_USB_PHY_CTRL_RESUME_IRQ(v)   (((v) << BP_USB_PHY_CTRL_RESUME_IRQ) & BM_USB_PHY_CTRL_RESUME_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESUME_IRQ field to a new value.
#define BW_USB_PHY_CTRL_RESUME_IRQ(x, v)   BFn_CS1((x), USB_PHY_CTRL, RESUME_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQDEVPLUGIN[11] (RW)
 *
 * Enables interrupt for the detection of connectivity to the USB line.
 */

#define BP_USB_PHY_CTRL_ENIRQDEVPLUGIN      (11)      //!< Bit position for USB_PHY_CTRL_ENIRQDEVPLUGIN.
#define BM_USB_PHY_CTRL_ENIRQDEVPLUGIN      (0x00000800)  //!< Bit mask for USB_PHY_CTRL_ENIRQDEVPLUGIN.

//! @brief Get value of USB_PHY_CTRL_ENIRQDEVPLUGIN from a register value.
#define BG_USB_PHY_CTRL_ENIRQDEVPLUGIN(r)   (((r) & BM_USB_PHY_CTRL_ENIRQDEVPLUGIN) >> BP_USB_PHY_CTRL_ENIRQDEVPLUGIN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQDEVPLUGIN.
#define BF_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENIRQDEVPLUGIN) & BM_USB_PHY_CTRL_ENIRQDEVPLUGIN)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQDEVPLUGIN.
#define BF_USB_PHY_CTRL_ENIRQDEVPLUGIN(v)   (((v) << BP_USB_PHY_CTRL_ENIRQDEVPLUGIN) & BM_USB_PHY_CTRL_ENIRQDEVPLUGIN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQDEVPLUGIN field to a new value.
#define BW_USB_PHY_CTRL_ENIRQDEVPLUGIN(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENIRQDEVPLUGIN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DEVPLUGIN_IRQ[12] (RW)
 *
 * Indicates that the device is connected. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_DEVPLUGIN_IRQ      (12)      //!< Bit position for USB_PHY_CTRL_DEVPLUGIN_IRQ.
#define BM_USB_PHY_CTRL_DEVPLUGIN_IRQ      (0x00001000)  //!< Bit mask for USB_PHY_CTRL_DEVPLUGIN_IRQ.

//! @brief Get value of USB_PHY_CTRL_DEVPLUGIN_IRQ from a register value.
#define BG_USB_PHY_CTRL_DEVPLUGIN_IRQ(r)   (((r) & BM_USB_PHY_CTRL_DEVPLUGIN_IRQ) >> BP_USB_PHY_CTRL_DEVPLUGIN_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_DEVPLUGIN_IRQ.
#define BF_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_DEVPLUGIN_IRQ) & BM_USB_PHY_CTRL_DEVPLUGIN_IRQ)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_DEVPLUGIN_IRQ.
#define BF_USB_PHY_CTRL_DEVPLUGIN_IRQ(v)   (((v) << BP_USB_PHY_CTRL_DEVPLUGIN_IRQ) & BM_USB_PHY_CTRL_DEVPLUGIN_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEVPLUGIN_IRQ field to a new value.
#define BW_USB_PHY_CTRL_DEVPLUGIN_IRQ(x, v)   BFn_CS1((x), USB_PHY_CTRL, DEVPLUGIN_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field DATA_ON_LRADC[13] (RW)
 *
 * Enables the LRADC to monitor USB_DP and USB_DM. This is for use in non-USB modes only.
 */

#define BP_USB_PHY_CTRL_DATA_ON_LRADC      (13)      //!< Bit position for USB_PHY_CTRL_DATA_ON_LRADC.
#define BM_USB_PHY_CTRL_DATA_ON_LRADC      (0x00002000)  //!< Bit mask for USB_PHY_CTRL_DATA_ON_LRADC.

//! @brief Get value of USB_PHY_CTRL_DATA_ON_LRADC from a register value.
#define BG_USB_PHY_CTRL_DATA_ON_LRADC(r)   (((r) & BM_USB_PHY_CTRL_DATA_ON_LRADC) >> BP_USB_PHY_CTRL_DATA_ON_LRADC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_DATA_ON_LRADC.
#define BF_USB_PHY_CTRL_DATA_ON_LRADC(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_DATA_ON_LRADC) & BM_USB_PHY_CTRL_DATA_ON_LRADC)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_DATA_ON_LRADC.
#define BF_USB_PHY_CTRL_DATA_ON_LRADC(v)   (((v) << BP_USB_PHY_CTRL_DATA_ON_LRADC) & BM_USB_PHY_CTRL_DATA_ON_LRADC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA_ON_LRADC field to a new value.
#define BW_USB_PHY_CTRL_DATA_ON_LRADC(x, v)   BFn_CS1((x), USB_PHY_CTRL, DATA_ON_LRADC, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL2[14] (RW)
 *
 * Enables UTMI+ Level2. This should be enabled if needs to support LS device
 */

#define BP_USB_PHY_CTRL_ENUTMILEVEL2      (14)      //!< Bit position for USB_PHY_CTRL_ENUTMILEVEL2.
#define BM_USB_PHY_CTRL_ENUTMILEVEL2      (0x00004000)  //!< Bit mask for USB_PHY_CTRL_ENUTMILEVEL2.

//! @brief Get value of USB_PHY_CTRL_ENUTMILEVEL2 from a register value.
#define BG_USB_PHY_CTRL_ENUTMILEVEL2(r)   (((r) & BM_USB_PHY_CTRL_ENUTMILEVEL2) >> BP_USB_PHY_CTRL_ENUTMILEVEL2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENUTMILEVEL2.
#define BF_USB_PHY_CTRL_ENUTMILEVEL2(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENUTMILEVEL2) & BM_USB_PHY_CTRL_ENUTMILEVEL2)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENUTMILEVEL2.
#define BF_USB_PHY_CTRL_ENUTMILEVEL2(v)   (((v) << BP_USB_PHY_CTRL_ENUTMILEVEL2) & BM_USB_PHY_CTRL_ENUTMILEVEL2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL2 field to a new value.
#define BW_USB_PHY_CTRL_ENUTMILEVEL2(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENUTMILEVEL2, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENUTMILEVEL3[15] (RW)
 *
 * Enables UTMI+ Level3. This should be enabled if needs to support external FS Hub with LS device
 * connected
 */

#define BP_USB_PHY_CTRL_ENUTMILEVEL3      (15)      //!< Bit position for USB_PHY_CTRL_ENUTMILEVEL3.
#define BM_USB_PHY_CTRL_ENUTMILEVEL3      (0x00008000)  //!< Bit mask for USB_PHY_CTRL_ENUTMILEVEL3.

//! @brief Get value of USB_PHY_CTRL_ENUTMILEVEL3 from a register value.
#define BG_USB_PHY_CTRL_ENUTMILEVEL3(r)   (((r) & BM_USB_PHY_CTRL_ENUTMILEVEL3) >> BP_USB_PHY_CTRL_ENUTMILEVEL3)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENUTMILEVEL3.
#define BF_USB_PHY_CTRL_ENUTMILEVEL3(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENUTMILEVEL3) & BM_USB_PHY_CTRL_ENUTMILEVEL3)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENUTMILEVEL3.
#define BF_USB_PHY_CTRL_ENUTMILEVEL3(v)   (((v) << BP_USB_PHY_CTRL_ENUTMILEVEL3) & BM_USB_PHY_CTRL_ENUTMILEVEL3)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENUTMILEVEL3 field to a new value.
#define BW_USB_PHY_CTRL_ENUTMILEVEL3(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENUTMILEVEL3, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIRQWAKEUP[16] (RW)
 *
 * Enables interrupt for the wakeup events.
 */

#define BP_USB_PHY_CTRL_ENIRQWAKEUP      (16)      //!< Bit position for USB_PHY_CTRL_ENIRQWAKEUP.
#define BM_USB_PHY_CTRL_ENIRQWAKEUP      (0x00010000)  //!< Bit mask for USB_PHY_CTRL_ENIRQWAKEUP.

//! @brief Get value of USB_PHY_CTRL_ENIRQWAKEUP from a register value.
#define BG_USB_PHY_CTRL_ENIRQWAKEUP(r)   (((r) & BM_USB_PHY_CTRL_ENIRQWAKEUP) >> BP_USB_PHY_CTRL_ENIRQWAKEUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQWAKEUP.
#define BF_USB_PHY_CTRL_ENIRQWAKEUP(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENIRQWAKEUP) & BM_USB_PHY_CTRL_ENIRQWAKEUP)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENIRQWAKEUP.
#define BF_USB_PHY_CTRL_ENIRQWAKEUP(v)   (((v) << BP_USB_PHY_CTRL_ENIRQWAKEUP) & BM_USB_PHY_CTRL_ENIRQWAKEUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIRQWAKEUP field to a new value.
#define BW_USB_PHY_CTRL_ENIRQWAKEUP(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENIRQWAKEUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field WAKEUP_IRQ[17] (RW)
 *
 * Indicates that there is a wakeup event. Reset this bit by writing a 1 to the clear address space
 * and not by a general write.
 */

#define BP_USB_PHY_CTRL_WAKEUP_IRQ      (17)      //!< Bit position for USB_PHY_CTRL_WAKEUP_IRQ.
#define BM_USB_PHY_CTRL_WAKEUP_IRQ      (0x00020000)  //!< Bit mask for USB_PHY_CTRL_WAKEUP_IRQ.

//! @brief Get value of USB_PHY_CTRL_WAKEUP_IRQ from a register value.
#define BG_USB_PHY_CTRL_WAKEUP_IRQ(r)   (((r) & BM_USB_PHY_CTRL_WAKEUP_IRQ) >> BP_USB_PHY_CTRL_WAKEUP_IRQ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_WAKEUP_IRQ.
#define BF_USB_PHY_CTRL_WAKEUP_IRQ(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_WAKEUP_IRQ) & BM_USB_PHY_CTRL_WAKEUP_IRQ)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_WAKEUP_IRQ.
#define BF_USB_PHY_CTRL_WAKEUP_IRQ(v)   (((v) << BP_USB_PHY_CTRL_WAKEUP_IRQ) & BM_USB_PHY_CTRL_WAKEUP_IRQ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP_IRQ field to a new value.
#define BW_USB_PHY_CTRL_WAKEUP_IRQ(x, v)   BFn_CS1((x), USB_PHY_CTRL, WAKEUP_IRQ, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_CLKGATE[19] (RW)
 *
 * Enables the feature to auto-clear the CLKGATE bit if there is wakeup event while USB is
 * suspended. This should be enabled if needs to support auto wakeup without S/W's interaction.
 */

#define BP_USB_PHY_CTRL_ENAUTOCLR_CLKGATE      (19)      //!< Bit position for USB_PHY_CTRL_ENAUTOCLR_CLKGATE.
#define BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE      (0x00080000)  //!< Bit mask for USB_PHY_CTRL_ENAUTOCLR_CLKGATE.

//! @brief Get value of USB_PHY_CTRL_ENAUTOCLR_CLKGATE from a register value.
#define BG_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(r)   (((r) & BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE) >> BP_USB_PHY_CTRL_ENAUTOCLR_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENAUTOCLR_CLKGATE.
#define BF_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENAUTOCLR_CLKGATE) & BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENAUTOCLR_CLKGATE.
#define BF_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(v)   (((v) << BP_USB_PHY_CTRL_ENAUTOCLR_CLKGATE) & BM_USB_PHY_CTRL_ENAUTOCLR_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_ENAUTOCLR_CLKGATE(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENAUTOCLR_CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENAUTOCLR_PHY_PWD[20] (RW)
 *
 * Enables the feature to auto-clear the PWD register bits in USBPHYx_PWD if there is wakeup event
 * while USB is suspended. This should be enabled if needs to support auto wakeup without S/W's
 * interaction.
 */

#define BP_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD      (20)      //!< Bit position for USB_PHY_CTRL_ENAUTOCLR_PHY_PWD.
#define BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD      (0x00100000)  //!< Bit mask for USB_PHY_CTRL_ENAUTOCLR_PHY_PWD.

//! @brief Get value of USB_PHY_CTRL_ENAUTOCLR_PHY_PWD from a register value.
#define BG_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(r)   (((r) & BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD) >> BP_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENAUTOCLR_PHY_PWD.
#define BF_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD) & BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENAUTOCLR_PHY_PWD.
#define BF_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(v)   (((v) << BP_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD) & BM_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENAUTOCLR_PHY_PWD field to a new value.
#define BW_USB_PHY_CTRL_ENAUTOCLR_PHY_PWD(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENAUTOCLR_PHY_PWD, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENDPDMCHG_WKUP[21] (RW)
 *
 * Enables the feature to wakeup USB if DP/DM is toggled when USB is suspended. This bit is enabled
 * by default.
 */

#define BP_USB_PHY_CTRL_ENDPDMCHG_WKUP      (21)      //!< Bit position for USB_PHY_CTRL_ENDPDMCHG_WKUP.
#define BM_USB_PHY_CTRL_ENDPDMCHG_WKUP      (0x00200000)  //!< Bit mask for USB_PHY_CTRL_ENDPDMCHG_WKUP.

//! @brief Get value of USB_PHY_CTRL_ENDPDMCHG_WKUP from a register value.
#define BG_USB_PHY_CTRL_ENDPDMCHG_WKUP(r)   (((r) & BM_USB_PHY_CTRL_ENDPDMCHG_WKUP) >> BP_USB_PHY_CTRL_ENDPDMCHG_WKUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENDPDMCHG_WKUP.
#define BF_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENDPDMCHG_WKUP) & BM_USB_PHY_CTRL_ENDPDMCHG_WKUP)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENDPDMCHG_WKUP.
#define BF_USB_PHY_CTRL_ENDPDMCHG_WKUP(v)   (((v) << BP_USB_PHY_CTRL_ENDPDMCHG_WKUP) & BM_USB_PHY_CTRL_ENDPDMCHG_WKUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENDPDMCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_ENDPDMCHG_WKUP(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENDPDMCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENIDCHG_WKUP[22] (RW)
 *
 * Enables the feature to wakeup USB if ID is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_ENIDCHG_WKUP      (22)      //!< Bit position for USB_PHY_CTRL_ENIDCHG_WKUP.
#define BM_USB_PHY_CTRL_ENIDCHG_WKUP      (0x00400000)  //!< Bit mask for USB_PHY_CTRL_ENIDCHG_WKUP.

//! @brief Get value of USB_PHY_CTRL_ENIDCHG_WKUP from a register value.
#define BG_USB_PHY_CTRL_ENIDCHG_WKUP(r)   (((r) & BM_USB_PHY_CTRL_ENIDCHG_WKUP) >> BP_USB_PHY_CTRL_ENIDCHG_WKUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENIDCHG_WKUP.
#define BF_USB_PHY_CTRL_ENIDCHG_WKUP(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENIDCHG_WKUP) & BM_USB_PHY_CTRL_ENIDCHG_WKUP)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENIDCHG_WKUP.
#define BF_USB_PHY_CTRL_ENIDCHG_WKUP(v)   (((v) << BP_USB_PHY_CTRL_ENIDCHG_WKUP) & BM_USB_PHY_CTRL_ENIDCHG_WKUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENIDCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_ENIDCHG_WKUP(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENIDCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field ENVBUSCHG_WKUP[23] (RW)
 *
 * Enables the feature to wakeup USB if VBUS is toggled when USB is suspended.
 */

#define BP_USB_PHY_CTRL_ENVBUSCHG_WKUP      (23)      //!< Bit position for USB_PHY_CTRL_ENVBUSCHG_WKUP.
#define BM_USB_PHY_CTRL_ENVBUSCHG_WKUP      (0x00800000)  //!< Bit mask for USB_PHY_CTRL_ENVBUSCHG_WKUP.

//! @brief Get value of USB_PHY_CTRL_ENVBUSCHG_WKUP from a register value.
#define BG_USB_PHY_CTRL_ENVBUSCHG_WKUP(r)   (((r) & BM_USB_PHY_CTRL_ENVBUSCHG_WKUP) >> BP_USB_PHY_CTRL_ENVBUSCHG_WKUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_ENVBUSCHG_WKUP.
#define BF_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_ENVBUSCHG_WKUP) & BM_USB_PHY_CTRL_ENVBUSCHG_WKUP)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_ENVBUSCHG_WKUP.
#define BF_USB_PHY_CTRL_ENVBUSCHG_WKUP(v)   (((v) << BP_USB_PHY_CTRL_ENVBUSCHG_WKUP) & BM_USB_PHY_CTRL_ENVBUSCHG_WKUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENVBUSCHG_WKUP field to a new value.
#define BW_USB_PHY_CTRL_ENVBUSCHG_WKUP(x, v)   BFn_CS1((x), USB_PHY_CTRL, ENVBUSCHG_WKUP, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field FSDLL_RST_EN[24] (RW)
 *
 * Enables the feature to reset the FSDLL lock detection logic at the end of each TX packet.
 */

#define BP_USB_PHY_CTRL_FSDLL_RST_EN      (24)      //!< Bit position for USB_PHY_CTRL_FSDLL_RST_EN.
#define BM_USB_PHY_CTRL_FSDLL_RST_EN      (0x01000000)  //!< Bit mask for USB_PHY_CTRL_FSDLL_RST_EN.

//! @brief Get value of USB_PHY_CTRL_FSDLL_RST_EN from a register value.
#define BG_USB_PHY_CTRL_FSDLL_RST_EN(r)   (((r) & BM_USB_PHY_CTRL_FSDLL_RST_EN) >> BP_USB_PHY_CTRL_FSDLL_RST_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_FSDLL_RST_EN.
#define BF_USB_PHY_CTRL_FSDLL_RST_EN(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_FSDLL_RST_EN) & BM_USB_PHY_CTRL_FSDLL_RST_EN)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_FSDLL_RST_EN.
#define BF_USB_PHY_CTRL_FSDLL_RST_EN(v)   (((v) << BP_USB_PHY_CTRL_FSDLL_RST_EN) & BM_USB_PHY_CTRL_FSDLL_RST_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FSDLL_RST_EN field to a new value.
#define BW_USB_PHY_CTRL_FSDLL_RST_EN(x, v)   BFn_CS1((x), USB_PHY_CTRL, FSDLL_RST_EN, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field OTG_ID_VALUE[27] (RO)
 *
 * Almost same as OTGID_STATUS in USBPHYx_STATUS Register. The only difference is that OTG_ID_VALUE
 * has debounce logic to filter the glitches on ID Pad.
 */

#define BP_USB_PHY_CTRL_OTG_ID_VALUE      (27)      //!< Bit position for USB_PHY_CTRL_OTG_ID_VALUE.
#define BM_USB_PHY_CTRL_OTG_ID_VALUE      (0x08000000)  //!< Bit mask for USB_PHY_CTRL_OTG_ID_VALUE.

//! @brief Get value of USB_PHY_CTRL_OTG_ID_VALUE from a register value.
#define BG_USB_PHY_CTRL_OTG_ID_VALUE(r)   (((r) & BM_USB_PHY_CTRL_OTG_ID_VALUE) >> BP_USB_PHY_CTRL_OTG_ID_VALUE)

/* --- Register HW_USB_PHY_CTRL, field HOST_FORCE_LS_SE0[28] (RW)
 *
 * Forces the next FS packet that is transmitted to have a EOP with LS timing. This bit is used in
 * host mode for the resume sequence. After the packet is transferred, this bit is cleared. The
 * design can use this function to force the LS SE0 or use the USBPHYx_CTRL_UTMI_SUSPENDM to trigger
 * this event when leaving suspend. This bit is used in conjunction with
 * USBPHYx_DEBUG_HOST_RESUME_DEBUG.
 */

#define BP_USB_PHY_CTRL_HOST_FORCE_LS_SE0      (28)      //!< Bit position for USB_PHY_CTRL_HOST_FORCE_LS_SE0.
#define BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0      (0x10000000)  //!< Bit mask for USB_PHY_CTRL_HOST_FORCE_LS_SE0.

//! @brief Get value of USB_PHY_CTRL_HOST_FORCE_LS_SE0 from a register value.
#define BG_USB_PHY_CTRL_HOST_FORCE_LS_SE0(r)   (((r) & BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0) >> BP_USB_PHY_CTRL_HOST_FORCE_LS_SE0)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_HOST_FORCE_LS_SE0.
#define BF_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_HOST_FORCE_LS_SE0) & BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_HOST_FORCE_LS_SE0.
#define BF_USB_PHY_CTRL_HOST_FORCE_LS_SE0(v)   (((v) << BP_USB_PHY_CTRL_HOST_FORCE_LS_SE0) & BM_USB_PHY_CTRL_HOST_FORCE_LS_SE0)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_FORCE_LS_SE0 field to a new value.
#define BW_USB_PHY_CTRL_HOST_FORCE_LS_SE0(x, v)   BFn_CS1((x), USB_PHY_CTRL, HOST_FORCE_LS_SE0, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field UTMI_SUSPENDM[29] (RO)
 *
 * Used by the PHY to indicate a powered-down state. If all the power-down bits in the USBPHYx_PWD
 * are enabled, UTMI_SUSPENDM will be 0, otherwise 1. UTMI_SUSPENDM is negative logic, as required
 * by the UTMI specification.
 */

#define BP_USB_PHY_CTRL_UTMI_SUSPENDM      (29)      //!< Bit position for USB_PHY_CTRL_UTMI_SUSPENDM.
#define BM_USB_PHY_CTRL_UTMI_SUSPENDM      (0x20000000)  //!< Bit mask for USB_PHY_CTRL_UTMI_SUSPENDM.

//! @brief Get value of USB_PHY_CTRL_UTMI_SUSPENDM from a register value.
#define BG_USB_PHY_CTRL_UTMI_SUSPENDM(r)   (((r) & BM_USB_PHY_CTRL_UTMI_SUSPENDM) >> BP_USB_PHY_CTRL_UTMI_SUSPENDM)

/* --- Register HW_USB_PHY_CTRL, field CLKGATE[30] (RW)
 *
 * Gate UTMI Clocks. Clear to 0 to run clocks. Set to 1 to gate clocks. Set this to save power while
 * the USB is not actively being used. Configuration state is kept while the clock is gated. Note
 * this bit can be auto-cleared if there is any wakeup event when USB is suspended while
 * ENAUTOCLR_CLKGATE bit of USBPHYx_CTRL is enabled.
 */

#define BP_USB_PHY_CTRL_CLKGATE      (30)      //!< Bit position for USB_PHY_CTRL_CLKGATE.
#define BM_USB_PHY_CTRL_CLKGATE      (0x40000000)  //!< Bit mask for USB_PHY_CTRL_CLKGATE.

//! @brief Get value of USB_PHY_CTRL_CLKGATE from a register value.
#define BG_USB_PHY_CTRL_CLKGATE(r)   (((r) & BM_USB_PHY_CTRL_CLKGATE) >> BP_USB_PHY_CTRL_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_CLKGATE.
#define BF_USB_PHY_CTRL_CLKGATE(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_CLKGATE) & BM_USB_PHY_CTRL_CLKGATE)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_CLKGATE.
#define BF_USB_PHY_CTRL_CLKGATE(v)   (((v) << BP_USB_PHY_CTRL_CLKGATE) & BM_USB_PHY_CTRL_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_CTRL_CLKGATE(x, v)   BFn_CS1((x), USB_PHY_CTRL, CLKGATE, v)
#endif

/* --- Register HW_USB_PHY_CTRL, field SFTRST[31] (RW)
 *
 * Writing a 1 to this bit will soft-reset the USBPHYx_PWD, USBPHYx_TX, USBPHYx_RX, and USBPHYx_CTRL
 * registers. Set to 0 to release the PHY from reset.
 */

#define BP_USB_PHY_CTRL_SFTRST      (31)      //!< Bit position for USB_PHY_CTRL_SFTRST.
#define BM_USB_PHY_CTRL_SFTRST      (0x80000000)  //!< Bit mask for USB_PHY_CTRL_SFTRST.

//! @brief Get value of USB_PHY_CTRL_SFTRST from a register value.
#define BG_USB_PHY_CTRL_SFTRST(r)   (((r) & BM_USB_PHY_CTRL_SFTRST) >> BP_USB_PHY_CTRL_SFTRST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_CTRL_SFTRST.
#define BF_USB_PHY_CTRL_SFTRST(v)   ((((reg32_t) v) << BP_USB_PHY_CTRL_SFTRST) & BM_USB_PHY_CTRL_SFTRST)
#else
//! @brief Format value for bitfield USB_PHY_CTRL_SFTRST.
#define BF_USB_PHY_CTRL_SFTRST(v)   (((v) << BP_USB_PHY_CTRL_SFTRST) & BM_USB_PHY_CTRL_SFTRST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SFTRST field to a new value.
#define BW_USB_PHY_CTRL_SFTRST(x, v)   BFn_CS1((x), USB_PHY_CTRL, SFTRST, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_STATUS - USB PHY Status Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The USB PHY Status Register holds results of IRQ and other detects.
 */
typedef union _hw_usb_phy_status
{
    reg32_t U;
    struct _hw_usb_phy_status_bitfields
    {
        unsigned RESERVED0 : 3; //!< [2:0] Reserved.
        unsigned HOSTDISCONDETECT_STATUS : 1; //!< [3] Indicates that the device has disconnected while in high-speed host mode.
        unsigned RESERVED1 : 2; //!< [5:4] Reserved.
        unsigned DEVPLUGIN_STATUS : 1; //!< [6] Indicates that the device has been connected on the USB_DP and USB_DM lines.
        unsigned RESERVED2 : 1; //!< [7] Reserved.
        unsigned OTGID_STATUS : 1; //!< [8] Indicates the results of ID pin on MiniAB plug. False (0) is when ID resistance is less than Ra_Plug_ID, indicating host (A) side. True (1) is when ID resistance is greater than Rb_Plug_ID, indicating device (B) side.
        unsigned RESERVED3 : 1; //!< [9] Reserved.
        unsigned RESUME_STATUS : 1; //!< [10] Indicates that the host is sending a wake-up after suspend and has triggered an interrupt.
        unsigned RESERVED4 : 21; //!< [31:11] Reserved.
    } B;
} hw_usb_phy_status_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_STATUS register
 */
#define HW_USB_PHY_STATUS_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_STATUS(x)           (*(volatile hw_usb_phy_status_t *) HW_USB_PHY_STATUS_ADDR(x))
#define HW_USB_PHY_STATUS_RD(x)        (HW_USB_PHY_STATUS(x).U)
#define HW_USB_PHY_STATUS_WR(x, v)     (HW_USB_PHY_STATUS(x).U = (v))
#define HW_USB_PHY_STATUS_SET(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) |  (v)))
#define HW_USB_PHY_STATUS_CLR(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) & ~(v)))
#define HW_USB_PHY_STATUS_TOG(x, v)    (HW_USB_PHY_STATUS_WR(x, HW_USB_PHY_STATUS_RD(x) ^  (v)))
#endif

/*
 * constants & macros for individual USB_PHY_STATUS bitfields
 */

/* --- Register HW_USB_PHY_STATUS, field HOSTDISCONDETECT_STATUS[3] (RO)
 *
 * Indicates that the device has disconnected while in high-speed host mode.
 */

#define BP_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      (3)      //!< Bit position for USB_PHY_STATUS_HOSTDISCONDETECT_STATUS.
#define BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS      (0x00000008)  //!< Bit mask for USB_PHY_STATUS_HOSTDISCONDETECT_STATUS.

//! @brief Get value of USB_PHY_STATUS_HOSTDISCONDETECT_STATUS from a register value.
#define BG_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS(r)   (((r) & BM_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS) >> BP_USB_PHY_STATUS_HOSTDISCONDETECT_STATUS)

/* --- Register HW_USB_PHY_STATUS, field DEVPLUGIN_STATUS[6] (RO)
 *
 * Indicates that the device has been connected on the USB_DP and USB_DM lines.
 */

#define BP_USB_PHY_STATUS_DEVPLUGIN_STATUS      (6)      //!< Bit position for USB_PHY_STATUS_DEVPLUGIN_STATUS.
#define BM_USB_PHY_STATUS_DEVPLUGIN_STATUS      (0x00000040)  //!< Bit mask for USB_PHY_STATUS_DEVPLUGIN_STATUS.

//! @brief Get value of USB_PHY_STATUS_DEVPLUGIN_STATUS from a register value.
#define BG_USB_PHY_STATUS_DEVPLUGIN_STATUS(r)   (((r) & BM_USB_PHY_STATUS_DEVPLUGIN_STATUS) >> BP_USB_PHY_STATUS_DEVPLUGIN_STATUS)

/* --- Register HW_USB_PHY_STATUS, field OTGID_STATUS[8] (RW)
 *
 * Indicates the results of ID pin on MiniAB plug. False (0) is when ID resistance is less than
 * Ra_Plug_ID, indicating host (A) side. True (1) is when ID resistance is greater than Rb_Plug_ID,
 * indicating device (B) side.
 */

#define BP_USB_PHY_STATUS_OTGID_STATUS      (8)      //!< Bit position for USB_PHY_STATUS_OTGID_STATUS.
#define BM_USB_PHY_STATUS_OTGID_STATUS      (0x00000100)  //!< Bit mask for USB_PHY_STATUS_OTGID_STATUS.

//! @brief Get value of USB_PHY_STATUS_OTGID_STATUS from a register value.
#define BG_USB_PHY_STATUS_OTGID_STATUS(r)   (((r) & BM_USB_PHY_STATUS_OTGID_STATUS) >> BP_USB_PHY_STATUS_OTGID_STATUS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_STATUS_OTGID_STATUS.
#define BF_USB_PHY_STATUS_OTGID_STATUS(v)   ((((reg32_t) v) << BP_USB_PHY_STATUS_OTGID_STATUS) & BM_USB_PHY_STATUS_OTGID_STATUS)
#else
//! @brief Format value for bitfield USB_PHY_STATUS_OTGID_STATUS.
#define BF_USB_PHY_STATUS_OTGID_STATUS(v)   (((v) << BP_USB_PHY_STATUS_OTGID_STATUS) & BM_USB_PHY_STATUS_OTGID_STATUS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OTGID_STATUS field to a new value.
#define BW_USB_PHY_STATUS_OTGID_STATUS(x, v)   (HW_USB_PHY_STATUS_WR(x, (HW_USB_PHY_STATUS_RD(x) & ~BM_USB_PHY_STATUS_OTGID_STATUS) | BF_USB_PHY_STATUS_OTGID_STATUS(v)))
#endif

/* --- Register HW_USB_PHY_STATUS, field RESUME_STATUS[10] (RO)
 *
 * Indicates that the host is sending a wake-up after suspend and has triggered an interrupt.
 */

#define BP_USB_PHY_STATUS_RESUME_STATUS      (10)      //!< Bit position for USB_PHY_STATUS_RESUME_STATUS.
#define BM_USB_PHY_STATUS_RESUME_STATUS      (0x00000400)  //!< Bit mask for USB_PHY_STATUS_RESUME_STATUS.

//! @brief Get value of USB_PHY_STATUS_RESUME_STATUS from a register value.
#define BG_USB_PHY_STATUS_RESUME_STATUS(r)   (((r) & BM_USB_PHY_STATUS_RESUME_STATUS) >> BP_USB_PHY_STATUS_RESUME_STATUS)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG - USB PHY Debug Register (RW)
 *
 * Reset value: 0x7f180000
 *
 * This register is used to debug the USB PHY.
 */
typedef union _hw_usb_phy_debug
{
    reg32_t U;
    struct _hw_usb_phy_debug_bitfields
    {
        unsigned OTGIDPIOLOCK : 1; //!< [0] Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power for the comparators that are used to determine the ID status.
        unsigned DEBUG_INTERFACE_HOLD : 1; //!< [1] Use holding registers to assist in timing for external UTMI interface.
        unsigned HSTPULLDOWN : 2; //!< [3:2] Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM line. Clear to 0 to disable.
        unsigned ENHSTPULLDOWN : 2; //!< [5:4] Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned TX2RXCOUNT : 4; //!< [11:8] Delay in between the end of transmit to the beginning of receive. This is a Johnson count value and thus will count to 8.
        unsigned ENTX2RXCOUNT : 1; //!< [12] Set this bit to allow a countdown to transition in between TX and RX.
        unsigned RESERVED1 : 3; //!< [15:13] Reserved.
        unsigned SQUELCHRESETCOUNT : 5; //!< [20:16] Delay in between the detection of squelch to the reset of high-speed RX.
        unsigned RESERVED2 : 3; //!< [23:21] Reserved.
        unsigned ENSQUELCHRESET : 1; //!< [24] Set bit to allow squelch to reset high-speed receive.
        unsigned SQUELCHRESETLENGTH : 4; //!< [28:25] Duration of RESET in terms of the number of 480-MHz cycles.
        unsigned HOST_RESUME_DEBUG : 1; //!< [29] Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
        unsigned CLKGATE : 1; //!< [30] Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power while the USB is not actively being used. Configuration state is kept while the clock is gated.
        unsigned RESERVED3 : 1; //!< [31] Reserved.
    } B;
} hw_usb_phy_debug_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG register
 */
#define HW_USB_PHY_DEBUG_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x50)
#define HW_USB_PHY_DEBUG_SET_ADDR(x)  (HW_USB_PHY_DEBUG_ADDR(x) + 0x4)
#define HW_USB_PHY_DEBUG_CLR_ADDR(x)  (HW_USB_PHY_DEBUG_ADDR(x) + 0x8)
#define HW_USB_PHY_DEBUG_TOG_ADDR(x)  (HW_USB_PHY_DEBUG_ADDR(x) + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG(x)           (*(volatile hw_usb_phy_debug_t *) HW_USB_PHY_DEBUG_ADDR(x))
#define HW_USB_PHY_DEBUG_RD(x)        (HW_USB_PHY_DEBUG(x).U)
#define HW_USB_PHY_DEBUG_WR(x, v)     (HW_USB_PHY_DEBUG(x).U = (v))
#define HW_USB_PHY_DEBUG_SET(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_DEBUG_SET_ADDR(x)) = (v))
#define HW_USB_PHY_DEBUG_CLR(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_DEBUG_CLR_ADDR(x)) = (v))
#define HW_USB_PHY_DEBUG_TOG(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_DEBUG_TOG_ADDR(x)) = (v))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG bitfields
 */

/* --- Register HW_USB_PHY_DEBUG, field OTGIDPIOLOCK[0] (RW)
 *
 * Once OTG ID from USBPHYx_STATUS_OTGID_STATUS, use this to hold the value. This is to save power
 * for the comparators that are used to determine the ID status.
 */

#define BP_USB_PHY_DEBUG_OTGIDPIOLOCK      (0)      //!< Bit position for USB_PHY_DEBUG_OTGIDPIOLOCK.
#define BM_USB_PHY_DEBUG_OTGIDPIOLOCK      (0x00000001)  //!< Bit mask for USB_PHY_DEBUG_OTGIDPIOLOCK.

//! @brief Get value of USB_PHY_DEBUG_OTGIDPIOLOCK from a register value.
#define BG_USB_PHY_DEBUG_OTGIDPIOLOCK(r)   (((r) & BM_USB_PHY_DEBUG_OTGIDPIOLOCK) >> BP_USB_PHY_DEBUG_OTGIDPIOLOCK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_OTGIDPIOLOCK.
#define BF_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_OTGIDPIOLOCK) & BM_USB_PHY_DEBUG_OTGIDPIOLOCK)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_OTGIDPIOLOCK.
#define BF_USB_PHY_DEBUG_OTGIDPIOLOCK(v)   (((v) << BP_USB_PHY_DEBUG_OTGIDPIOLOCK) & BM_USB_PHY_DEBUG_OTGIDPIOLOCK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OTGIDPIOLOCK field to a new value.
#define BW_USB_PHY_DEBUG_OTGIDPIOLOCK(x, v)   BFn_CS1((x), USB_PHY_DEBUG, OTGIDPIOLOCK, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field DEBUG_INTERFACE_HOLD[1] (RW)
 *
 * Use holding registers to assist in timing for external UTMI interface.
 */

#define BP_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD      (1)      //!< Bit position for USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD.
#define BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD      (0x00000002)  //!< Bit mask for USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD.

//! @brief Get value of USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD from a register value.
#define BG_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(r)   (((r) & BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD) >> BP_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD.
#define BF_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD) & BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD.
#define BF_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(v)   (((v) << BP_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD) & BM_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DEBUG_INTERFACE_HOLD field to a new value.
#define BW_USB_PHY_DEBUG_DEBUG_INTERFACE_HOLD(x, v)   BFn_CS1((x), USB_PHY_DEBUG, DEBUG_INTERFACE_HOLD, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HSTPULLDOWN[3:2] (RW)
 *
 * Set bit 3 to 1 to pull down 15-KOhm on USB_DP line. Set bit 2 to 1 to pull down 15-KOhm on USB_DM
 * line. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_HSTPULLDOWN      (2)      //!< Bit position for USB_PHY_DEBUG_HSTPULLDOWN.
#define BM_USB_PHY_DEBUG_HSTPULLDOWN      (0x0000000c)  //!< Bit mask for USB_PHY_DEBUG_HSTPULLDOWN.

//! @brief Get value of USB_PHY_DEBUG_HSTPULLDOWN from a register value.
#define BG_USB_PHY_DEBUG_HSTPULLDOWN(r)   (((r) & BM_USB_PHY_DEBUG_HSTPULLDOWN) >> BP_USB_PHY_DEBUG_HSTPULLDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_HSTPULLDOWN.
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_HSTPULLDOWN) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_HSTPULLDOWN.
#define BF_USB_PHY_DEBUG_HSTPULLDOWN(v)   (((v) << BP_USB_PHY_DEBUG_HSTPULLDOWN) & BM_USB_PHY_DEBUG_HSTPULLDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_HSTPULLDOWN(x, v)   BFn_CS1((x), USB_PHY_DEBUG, HSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENHSTPULLDOWN[5:4] (RW)
 *
 * Set bit 5 to 1 to override the control of the USB_DP 15-KOhm pulldown. Set bit 4 to 1 to override
 * the control of the USB_DM 15-KOhm pulldown. Clear to 0 to disable.
 */

#define BP_USB_PHY_DEBUG_ENHSTPULLDOWN      (4)      //!< Bit position for USB_PHY_DEBUG_ENHSTPULLDOWN.
#define BM_USB_PHY_DEBUG_ENHSTPULLDOWN      (0x00000030)  //!< Bit mask for USB_PHY_DEBUG_ENHSTPULLDOWN.

//! @brief Get value of USB_PHY_DEBUG_ENHSTPULLDOWN from a register value.
#define BG_USB_PHY_DEBUG_ENHSTPULLDOWN(r)   (((r) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN) >> BP_USB_PHY_DEBUG_ENHSTPULLDOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_ENHSTPULLDOWN.
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_ENHSTPULLDOWN) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_ENHSTPULLDOWN.
#define BF_USB_PHY_DEBUG_ENHSTPULLDOWN(v)   (((v) << BP_USB_PHY_DEBUG_ENHSTPULLDOWN) & BM_USB_PHY_DEBUG_ENHSTPULLDOWN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENHSTPULLDOWN field to a new value.
#define BW_USB_PHY_DEBUG_ENHSTPULLDOWN(x, v)   BFn_CS1((x), USB_PHY_DEBUG, ENHSTPULLDOWN, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field TX2RXCOUNT[11:8] (RW)
 *
 * Delay in between the end of transmit to the beginning of receive. This is a Johnson count value
 * and thus will count to 8.
 */

#define BP_USB_PHY_DEBUG_TX2RXCOUNT      (8)      //!< Bit position for USB_PHY_DEBUG_TX2RXCOUNT.
#define BM_USB_PHY_DEBUG_TX2RXCOUNT      (0x00000f00)  //!< Bit mask for USB_PHY_DEBUG_TX2RXCOUNT.

//! @brief Get value of USB_PHY_DEBUG_TX2RXCOUNT from a register value.
#define BG_USB_PHY_DEBUG_TX2RXCOUNT(r)   (((r) & BM_USB_PHY_DEBUG_TX2RXCOUNT) >> BP_USB_PHY_DEBUG_TX2RXCOUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_TX2RXCOUNT.
#define BF_USB_PHY_DEBUG_TX2RXCOUNT(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_TX2RXCOUNT) & BM_USB_PHY_DEBUG_TX2RXCOUNT)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_TX2RXCOUNT.
#define BF_USB_PHY_DEBUG_TX2RXCOUNT(v)   (((v) << BP_USB_PHY_DEBUG_TX2RXCOUNT) & BM_USB_PHY_DEBUG_TX2RXCOUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_TX2RXCOUNT(x, v)   BFn_CS1((x), USB_PHY_DEBUG, TX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENTX2RXCOUNT[12] (RW)
 *
 * Set this bit to allow a countdown to transition in between TX and RX.
 */

#define BP_USB_PHY_DEBUG_ENTX2RXCOUNT      (12)      //!< Bit position for USB_PHY_DEBUG_ENTX2RXCOUNT.
#define BM_USB_PHY_DEBUG_ENTX2RXCOUNT      (0x00001000)  //!< Bit mask for USB_PHY_DEBUG_ENTX2RXCOUNT.

//! @brief Get value of USB_PHY_DEBUG_ENTX2RXCOUNT from a register value.
#define BG_USB_PHY_DEBUG_ENTX2RXCOUNT(r)   (((r) & BM_USB_PHY_DEBUG_ENTX2RXCOUNT) >> BP_USB_PHY_DEBUG_ENTX2RXCOUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_ENTX2RXCOUNT.
#define BF_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_ENTX2RXCOUNT) & BM_USB_PHY_DEBUG_ENTX2RXCOUNT)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_ENTX2RXCOUNT.
#define BF_USB_PHY_DEBUG_ENTX2RXCOUNT(v)   (((v) << BP_USB_PHY_DEBUG_ENTX2RXCOUNT) & BM_USB_PHY_DEBUG_ENTX2RXCOUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTX2RXCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_ENTX2RXCOUNT(x, v)   BFn_CS1((x), USB_PHY_DEBUG, ENTX2RXCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETCOUNT[20:16] (RW)
 *
 * Delay in between the detection of squelch to the reset of high-speed RX.
 */

#define BP_USB_PHY_DEBUG_SQUELCHRESETCOUNT      (16)      //!< Bit position for USB_PHY_DEBUG_SQUELCHRESETCOUNT.
#define BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT      (0x001f0000)  //!< Bit mask for USB_PHY_DEBUG_SQUELCHRESETCOUNT.

//! @brief Get value of USB_PHY_DEBUG_SQUELCHRESETCOUNT from a register value.
#define BG_USB_PHY_DEBUG_SQUELCHRESETCOUNT(r)   (((r) & BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT) >> BP_USB_PHY_DEBUG_SQUELCHRESETCOUNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_SQUELCHRESETCOUNT.
#define BF_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_SQUELCHRESETCOUNT) & BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_SQUELCHRESETCOUNT.
#define BF_USB_PHY_DEBUG_SQUELCHRESETCOUNT(v)   (((v) << BP_USB_PHY_DEBUG_SQUELCHRESETCOUNT) & BM_USB_PHY_DEBUG_SQUELCHRESETCOUNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETCOUNT field to a new value.
#define BW_USB_PHY_DEBUG_SQUELCHRESETCOUNT(x, v)   BFn_CS1((x), USB_PHY_DEBUG, SQUELCHRESETCOUNT, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field ENSQUELCHRESET[24] (RW)
 *
 * Set bit to allow squelch to reset high-speed receive.
 */

#define BP_USB_PHY_DEBUG_ENSQUELCHRESET      (24)      //!< Bit position for USB_PHY_DEBUG_ENSQUELCHRESET.
#define BM_USB_PHY_DEBUG_ENSQUELCHRESET      (0x01000000)  //!< Bit mask for USB_PHY_DEBUG_ENSQUELCHRESET.

//! @brief Get value of USB_PHY_DEBUG_ENSQUELCHRESET from a register value.
#define BG_USB_PHY_DEBUG_ENSQUELCHRESET(r)   (((r) & BM_USB_PHY_DEBUG_ENSQUELCHRESET) >> BP_USB_PHY_DEBUG_ENSQUELCHRESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_ENSQUELCHRESET.
#define BF_USB_PHY_DEBUG_ENSQUELCHRESET(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_ENSQUELCHRESET) & BM_USB_PHY_DEBUG_ENSQUELCHRESET)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_ENSQUELCHRESET.
#define BF_USB_PHY_DEBUG_ENSQUELCHRESET(v)   (((v) << BP_USB_PHY_DEBUG_ENSQUELCHRESET) & BM_USB_PHY_DEBUG_ENSQUELCHRESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENSQUELCHRESET field to a new value.
#define BW_USB_PHY_DEBUG_ENSQUELCHRESET(x, v)   BFn_CS1((x), USB_PHY_DEBUG, ENSQUELCHRESET, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field SQUELCHRESETLENGTH[28:25] (RW)
 *
 * Duration of RESET in terms of the number of 480-MHz cycles.
 */

#define BP_USB_PHY_DEBUG_SQUELCHRESETLENGTH      (25)      //!< Bit position for USB_PHY_DEBUG_SQUELCHRESETLENGTH.
#define BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH      (0x1e000000)  //!< Bit mask for USB_PHY_DEBUG_SQUELCHRESETLENGTH.

//! @brief Get value of USB_PHY_DEBUG_SQUELCHRESETLENGTH from a register value.
#define BG_USB_PHY_DEBUG_SQUELCHRESETLENGTH(r)   (((r) & BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH) >> BP_USB_PHY_DEBUG_SQUELCHRESETLENGTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_SQUELCHRESETLENGTH.
#define BF_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_SQUELCHRESETLENGTH) & BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_SQUELCHRESETLENGTH.
#define BF_USB_PHY_DEBUG_SQUELCHRESETLENGTH(v)   (((v) << BP_USB_PHY_DEBUG_SQUELCHRESETLENGTH) & BM_USB_PHY_DEBUG_SQUELCHRESETLENGTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SQUELCHRESETLENGTH field to a new value.
#define BW_USB_PHY_DEBUG_SQUELCHRESETLENGTH(x, v)   BFn_CS1((x), USB_PHY_DEBUG, SQUELCHRESETLENGTH, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field HOST_RESUME_DEBUG[29] (RW)
 *
 * Choose to trigger the host resume SE0 with HOST_FORCE_LS_SE0 = 0 or UTMI_SUSPEND = 1.
 */

#define BP_USB_PHY_DEBUG_HOST_RESUME_DEBUG      (29)      //!< Bit position for USB_PHY_DEBUG_HOST_RESUME_DEBUG.
#define BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG      (0x20000000)  //!< Bit mask for USB_PHY_DEBUG_HOST_RESUME_DEBUG.

//! @brief Get value of USB_PHY_DEBUG_HOST_RESUME_DEBUG from a register value.
#define BG_USB_PHY_DEBUG_HOST_RESUME_DEBUG(r)   (((r) & BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG) >> BP_USB_PHY_DEBUG_HOST_RESUME_DEBUG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_HOST_RESUME_DEBUG.
#define BF_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_HOST_RESUME_DEBUG) & BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_HOST_RESUME_DEBUG.
#define BF_USB_PHY_DEBUG_HOST_RESUME_DEBUG(v)   (((v) << BP_USB_PHY_DEBUG_HOST_RESUME_DEBUG) & BM_USB_PHY_DEBUG_HOST_RESUME_DEBUG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOST_RESUME_DEBUG field to a new value.
#define BW_USB_PHY_DEBUG_HOST_RESUME_DEBUG(x, v)   BFn_CS1((x), USB_PHY_DEBUG, HOST_RESUME_DEBUG, v)
#endif

/* --- Register HW_USB_PHY_DEBUG, field CLKGATE[30] (RW)
 *
 * Gate Test Clocks. Clear to 0 for running clocks. Set to 1 to gate clocks. Set this to save power
 * while the USB is not actively being used. Configuration state is kept while the clock is gated.
 */

#define BP_USB_PHY_DEBUG_CLKGATE      (30)      //!< Bit position for USB_PHY_DEBUG_CLKGATE.
#define BM_USB_PHY_DEBUG_CLKGATE      (0x40000000)  //!< Bit mask for USB_PHY_DEBUG_CLKGATE.

//! @brief Get value of USB_PHY_DEBUG_CLKGATE from a register value.
#define BG_USB_PHY_DEBUG_CLKGATE(r)   (((r) & BM_USB_PHY_DEBUG_CLKGATE) >> BP_USB_PHY_DEBUG_CLKGATE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG_CLKGATE.
#define BF_USB_PHY_DEBUG_CLKGATE(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG_CLKGATE) & BM_USB_PHY_DEBUG_CLKGATE)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG_CLKGATE.
#define BF_USB_PHY_DEBUG_CLKGATE(v)   (((v) << BP_USB_PHY_DEBUG_CLKGATE) & BM_USB_PHY_DEBUG_CLKGATE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLKGATE field to a new value.
#define BW_USB_PHY_DEBUG_CLKGATE(x, v)   BFn_CS1((x), USB_PHY_DEBUG, CLKGATE, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG0_STATUS - UTMI Debug Status Register 0 (RO)
 *
 * Reset value: 0x00000000
 *
 * The UTMI Debug Status Register 0 holds multiple views for counters and status of state machines.
 * This is used in conjunction with the USBPHYx_DEBUG1_DBG_ADDRESS field to choose which function to
 * view. The default is described in the bit fields below and is used to count errors.
 */
typedef union _hw_usb_phy_debug0_status
{
    reg32_t U;
    struct _hw_usb_phy_debug0_status_bitfields
    {
        unsigned LOOP_BACK_FAIL_COUNT : 16; //!< [15:0] Running count of the failed pseudo-random generator loopback. Each time entering testmode, counter goes to 900D and will count up for every detected packet failure in digital/analog loopback tests.
        unsigned UTMI_RXERROR_FAIL_COUNT : 10; //!< [25:16] Running count of the UTMI_RXERROR.
        unsigned SQUELCH_COUNT : 6; //!< [31:26] Running count of the squelch reset instead of normal end for HS RX.
    } B;
} hw_usb_phy_debug0_status_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG0_STATUS register
 */
#define HW_USB_PHY_DEBUG0_STATUS_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x60)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG0_STATUS(x)           (*(volatile hw_usb_phy_debug0_status_t *) HW_USB_PHY_DEBUG0_STATUS_ADDR(x))
#define HW_USB_PHY_DEBUG0_STATUS_RD(x)        (HW_USB_PHY_DEBUG0_STATUS(x).U)
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG0_STATUS bitfields
 */

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field LOOP_BACK_FAIL_COUNT[15:0] (RO)
 *
 * Running count of the failed pseudo-random generator loopback. Each time entering testmode,
 * counter goes to 900D and will count up for every detected packet failure in digital/analog
 * loopback tests.
 */

#define BP_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      (0)      //!< Bit position for USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT.
#define BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT      (0x0000ffff)  //!< Bit mask for USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT.

//! @brief Get value of USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT from a register value.
#define BG_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(r)   (((r) & BM_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT) >> BP_USB_PHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT)

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field UTMI_RXERROR_FAIL_COUNT[25:16] (RO)
 *
 * Running count of the UTMI_RXERROR.
 */

#define BP_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      (16)      //!< Bit position for USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT.
#define BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT      (0x03ff0000)  //!< Bit mask for USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT.

//! @brief Get value of USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT from a register value.
#define BG_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(r)   (((r) & BM_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT) >> BP_USB_PHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT)

/* --- Register HW_USB_PHY_DEBUG0_STATUS, field SQUELCH_COUNT[31:26] (RO)
 *
 * Running count of the squelch reset instead of normal end for HS RX.
 */

#define BP_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      (26)      //!< Bit position for USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT.
#define BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT      (0xfc000000)  //!< Bit mask for USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT.

//! @brief Get value of USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT from a register value.
#define BG_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT(r)   (((r) & BM_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT) >> BP_USB_PHY_DEBUG0_STATUS_SQUELCH_COUNT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_DEBUG1 - UTMI Debug Status Register 1 (RW)
 *
 * Reset value: 0x00001000
 *
 * Chooses the muxing of the debug register to be shown in USBPHYx_DEBUG0_STATUS.
 */
typedef union _hw_usb_phy_debug1
{
    reg32_t U;
    struct _hw_usb_phy_debug1_bitfields
    {
        unsigned RESERVED0 : 13; //!< [12:0] Reserved. Note: This bit should remain clear.
        unsigned ENTAILADJVD : 2; //!< [14:13] Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is -20% 11 = Delay is -40%
        unsigned RESERVED1 : 17; //!< [31:15] Reserved.
    } B;
} hw_usb_phy_debug1_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_DEBUG1 register
 */
#define HW_USB_PHY_DEBUG1_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x70)
#define HW_USB_PHY_DEBUG1_SET_ADDR(x)  (HW_USB_PHY_DEBUG1_ADDR(x) + 0x4)
#define HW_USB_PHY_DEBUG1_CLR_ADDR(x)  (HW_USB_PHY_DEBUG1_ADDR(x) + 0x8)
#define HW_USB_PHY_DEBUG1_TOG_ADDR(x)  (HW_USB_PHY_DEBUG1_ADDR(x) + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_DEBUG1(x)           (*(volatile hw_usb_phy_debug1_t *) HW_USB_PHY_DEBUG1_ADDR(x))
#define HW_USB_PHY_DEBUG1_RD(x)        (HW_USB_PHY_DEBUG1(x).U)
#define HW_USB_PHY_DEBUG1_WR(x, v)     (HW_USB_PHY_DEBUG1(x).U = (v))
#define HW_USB_PHY_DEBUG1_SET(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_DEBUG1_SET_ADDR(x)) = (v))
#define HW_USB_PHY_DEBUG1_CLR(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_DEBUG1_CLR_ADDR(x)) = (v))
#define HW_USB_PHY_DEBUG1_TOG(x, v)    ((*(volatile reg32_t *) HW_USB_PHY_DEBUG1_TOG_ADDR(x)) = (v))
#endif

/*
 * constants & macros for individual USB_PHY_DEBUG1 bitfields
 */

/* --- Register HW_USB_PHY_DEBUG1, field ENTAILADJVD[14:13] (RW)
 *
 * Delay increment of the rise of squelch: 00 = Delay is nominal 01 = Delay is +20% 10 = Delay is
 * -20% 11 = Delay is -40%
 */

#define BP_USB_PHY_DEBUG1_ENTAILADJVD      (13)      //!< Bit position for USB_PHY_DEBUG1_ENTAILADJVD.
#define BM_USB_PHY_DEBUG1_ENTAILADJVD      (0x00006000)  //!< Bit mask for USB_PHY_DEBUG1_ENTAILADJVD.

//! @brief Get value of USB_PHY_DEBUG1_ENTAILADJVD from a register value.
#define BG_USB_PHY_DEBUG1_ENTAILADJVD(r)   (((r) & BM_USB_PHY_DEBUG1_ENTAILADJVD) >> BP_USB_PHY_DEBUG1_ENTAILADJVD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield USB_PHY_DEBUG1_ENTAILADJVD.
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   ((((reg32_t) v) << BP_USB_PHY_DEBUG1_ENTAILADJVD) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#else
//! @brief Format value for bitfield USB_PHY_DEBUG1_ENTAILADJVD.
#define BF_USB_PHY_DEBUG1_ENTAILADJVD(v)   (((v) << BP_USB_PHY_DEBUG1_ENTAILADJVD) & BM_USB_PHY_DEBUG1_ENTAILADJVD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENTAILADJVD field to a new value.
#define BW_USB_PHY_DEBUG1_ENTAILADJVD(x, v)   BFn_CS1((x), USB_PHY_DEBUG1, ENTAILADJVD, v)
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_USB_PHY_VERSION - UTMI RTL Version (RO)
 *
 * Reset value: 0x04020000
 *
 * Fields for RTL Version.
 */
typedef union _hw_usb_phy_version
{
    reg32_t U;
    struct _hw_usb_phy_version_bitfields
    {
        unsigned STEP : 16; //!< [15:0] Fixed read-only value reflecting the stepping of the RTL version.
        unsigned MINOR : 8; //!< [23:16] Fixed read-only value reflecting the MINOR field of the RTL version.
        unsigned MAJOR : 8; //!< [31:24] Fixed read-only value reflecting the MAJOR field of the RTL version.
    } B;
} hw_usb_phy_version_t;
#endif

/*
 * constants & macros for entire multi-block USB_PHY_VERSION register
 */
#define HW_USB_PHY_VERSION_ADDR(x)      (REGS_USB_PHY_BASE(x) + 0x80)

#ifndef __LANGUAGE_ASM__
#define HW_USB_PHY_VERSION(x)           (*(volatile hw_usb_phy_version_t *) HW_USB_PHY_VERSION_ADDR(x))
#define HW_USB_PHY_VERSION_RD(x)        (HW_USB_PHY_VERSION(x).U)
#endif

/*
 * constants & macros for individual USB_PHY_VERSION bitfields
 */

/* --- Register HW_USB_PHY_VERSION, field STEP[15:0] (RO)
 *
 * Fixed read-only value reflecting the stepping of the RTL version.
 */

#define BP_USB_PHY_VERSION_STEP      (0)      //!< Bit position for USB_PHY_VERSION_STEP.
#define BM_USB_PHY_VERSION_STEP      (0x0000ffff)  //!< Bit mask for USB_PHY_VERSION_STEP.

//! @brief Get value of USB_PHY_VERSION_STEP from a register value.
#define BG_USB_PHY_VERSION_STEP(r)   (((r) & BM_USB_PHY_VERSION_STEP) >> BP_USB_PHY_VERSION_STEP)

/* --- Register HW_USB_PHY_VERSION, field MINOR[23:16] (RO)
 *
 * Fixed read-only value reflecting the MINOR field of the RTL version.
 */

#define BP_USB_PHY_VERSION_MINOR      (16)      //!< Bit position for USB_PHY_VERSION_MINOR.
#define BM_USB_PHY_VERSION_MINOR      (0x00ff0000)  //!< Bit mask for USB_PHY_VERSION_MINOR.

//! @brief Get value of USB_PHY_VERSION_MINOR from a register value.
#define BG_USB_PHY_VERSION_MINOR(r)   (((r) & BM_USB_PHY_VERSION_MINOR) >> BP_USB_PHY_VERSION_MINOR)

/* --- Register HW_USB_PHY_VERSION, field MAJOR[31:24] (RO)
 *
 * Fixed read-only value reflecting the MAJOR field of the RTL version.
 */

#define BP_USB_PHY_VERSION_MAJOR      (24)      //!< Bit position for USB_PHY_VERSION_MAJOR.
#define BM_USB_PHY_VERSION_MAJOR      (0xff000000)  //!< Bit mask for USB_PHY_VERSION_MAJOR.

//! @brief Get value of USB_PHY_VERSION_MAJOR from a register value.
#define BG_USB_PHY_VERSION_MAJOR(r)   (((r) & BM_USB_PHY_VERSION_MAJOR) >> BP_USB_PHY_VERSION_MAJOR)


/*!
 * @brief All USB_PHY module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_usb_phy
{
    volatile hw_usb_phy_pwd_t PWD; //!< USB PHY Power-Down Register
    volatile reg32_t PWD_SET; //!< USB PHY Power-Down Register Set
    volatile reg32_t PWD_CLR; //!< USB PHY Power-Down Register Clear
    volatile reg32_t PWD_TOG; //!< USB PHY Power-Down Register Toggle
    volatile hw_usb_phy_tx_t TX; //!< USB PHY Transmitter Control Register
    volatile reg32_t TX_SET; //!< USB PHY Transmitter Control Register Set
    volatile reg32_t TX_CLR; //!< USB PHY Transmitter Control Register Clear
    volatile reg32_t TX_TOG; //!< USB PHY Transmitter Control Register Toggle
    volatile hw_usb_phy_rx_t RX; //!< USB PHY Receiver Control Register
    volatile reg32_t RX_SET; //!< USB PHY Receiver Control Register Set
    volatile reg32_t RX_CLR; //!< USB PHY Receiver Control Register Clear
    volatile reg32_t RX_TOG; //!< USB PHY Receiver Control Register Toggle
    volatile hw_usb_phy_ctrl_t CTRL; //!< USB PHY General Control Register
    volatile reg32_t CTRL_SET; //!< USB PHY General Control Register Set
    volatile reg32_t CTRL_CLR; //!< USB PHY General Control Register Clear
    volatile reg32_t CTRL_TOG; //!< USB PHY General Control Register Toggle
    volatile hw_usb_phy_status_t STATUS; //!< USB PHY Status Register
    reg32_t _reserved0[3];
    volatile hw_usb_phy_debug_t DEBUG; //!< USB PHY Debug Register
    volatile reg32_t DEBUG_SET; //!< USB PHY Debug Register Set
    volatile reg32_t DEBUG_CLR; //!< USB PHY Debug Register Clear
    volatile reg32_t DEBUG_TOG; //!< USB PHY Debug Register Toggle
    volatile hw_usb_phy_debug0_status_t DEBUG0_STATUS; //!< UTMI Debug Status Register 0
    reg32_t _reserved1[3];
    volatile hw_usb_phy_debug1_t DEBUG1; //!< UTMI Debug Status Register 1
    volatile reg32_t DEBUG1_SET; //!< UTMI Debug Status Register 1 Set
    volatile reg32_t DEBUG1_CLR; //!< UTMI Debug Status Register 1 Clear
    volatile reg32_t DEBUG1_TOG; //!< UTMI Debug Status Register 1 Toggle
    volatile hw_usb_phy_version_t VERSION; //!< UTMI RTL Version
} hw_usb_phy_t;
#pragma pack()
#endif

//! @brief Macro to access all USB_PHY registers.
//! @param x USB_PHY instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_USB_PHY(0)</code>.
#define HW_USB_PHY(x)     (*(volatile hw_usb_phy_t *) REGS_USB_PHY_BASE(x))


#endif // _USB_PHY_H