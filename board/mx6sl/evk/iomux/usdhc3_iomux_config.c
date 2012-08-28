/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: usdhc3_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.3.2.1
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "iomux_define.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for usdhc3 module.
void usdhc3_iomux_config(void)
{
    // Config usdhc3.CD to pad REF_CLK_32K(AD14)
    // HW_IOMUXC_SW_MUX_CTL_PAD_REF_CLK_32K_WR(0x00000006);
    // HW_IOMUXC_USDHC3_IPP_CARD_DET_SELECT_INPUT_WR(0x00000003);
    // HW_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_WR(0x000170B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_REF_CLK_32K(0x020E0228)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad REF_CLK_32K.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: REF_CLK_32K.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SDA of instance: i2c3.
    //                NOTE: - Config Register IOMUXC_I2C3_IPP_SDA_IN_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: PWMO of instance: pwm4.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: USB_OTG1_ID of instance: usb.
    //                NOTE: - Config Register IOMUXC_ANALOG_USB_OTG_ID_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: LCTL of instance: usdhc1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[22] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: CD of instance: usdhc3.
    //                NOTE: - Config Register IOMUXC_USDHC3_IPP_CARD_DET_SELECT_INPUT for mode ALT6.
    HW_IOMUXC_SW_MUX_CTL_PAD_REF_CLK_32K_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_REF_CLK_32K_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_REF_CLK_32K_MUX_MODE(ALT6));
    // Pad REF_CLK_32K is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_USDHC3_IPP_CARD_DET_SELECT_INPUT(0x020E0838)
    //   DAISY [1:0] Reset: SEL_EPDC_PWRWAKEUP_ALT6
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: usdhc3,   In Pin: ipp_card_det
    //     SEL_EPDC_PWRWAKEUP_ALT6 (0) - Selecting Pad: EPDC_PWRWAKEUP for Mode: ALT6.
    //     SEL_FEC_TXD1_ALT4 (1) - Selecting Pad: FEC_TXD1 for Mode: ALT4.
    //     SEL_I2C2_SDA_ALT4 (2) - Selecting Pad: I2C2_SDA for Mode: ALT4.
    //     SEL_REF_CLK_32K_ALT6 (3) - Selecting Pad: REF_CLK_32K for Mode: ALT6.
    HW_IOMUXC_USDHC3_IPP_CARD_DET_SELECT_INPUT_WR(
            BF_IOMUXC_USDHC3_IPP_CARD_DET_SELECT_INPUT_DAISY(SEL_REF_CLK_32K_ALT6));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K(0x020E0530)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: REF_CLK_32K.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: REF_CLK_32K.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: REF_CLK_32K.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: REF_CLK_32K.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: REF_CLK_32K.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: REF_CLK_32K.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: REF_CLK_32K.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: REF_CLK_32K.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: REF_CLK_32K.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_PUS(PUS_47KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_REF_CLK_32K_SRE(SRE_SLOW));

    // Config usdhc3.CLK to pad SD3_CLK(AB11)
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD3_CLK_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_CLK(0x020E0280)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_CLK.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_CLK.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CLK of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD5_RXFS of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_RXFS_AMX_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: COL[5] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_COL_5_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: D[10] of instance: csi.
    //                NOTE: - Config Register IOMUXC_CSI_IPP_CSI_D_10_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: WDOG_RST_B_DEB of instance: wdog1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[18] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USB_OTG1_PWR of instance: usb.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD3_CLK_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_CLK_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_CLK_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_CLK(0x020E0588)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: SD3_CLK.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_CLK.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: SD3_CLK.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: SD3_CLK.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_CLK.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_CLK.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_CLK.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_CLK.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_CLK.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CLK_SRE(SRE_SLOW));

    // Config usdhc3.CMD to pad SD3_CMD(AA11)
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD3_CMD_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_CMD(0x020E0284)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_CMD.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_CMD.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CMD of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD5_RXC of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_RXCLK_AMX_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ROW[5] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_5_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: D[11] of instance: csi.
    //                NOTE: - Config Register IOMUXC_CSI_IPP_CSI_D_11_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: USB_OTG2_ID of instance: usb.
    //                NOTE: - Config Register IOMUXC_ANALOG_USB_UH1_ID_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[21] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USB_OTG2_PWR of instance: usb.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD3_CMD_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_CMD_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_CMD_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_CMD(0x020E058C)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: SD3_CMD.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_CMD.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: SD3_CMD.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: SD3_CMD.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_CMD.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_CMD.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_CMD.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_CMD.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_CMD.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_CMD_SRE(SRE_SLOW));

    // Config usdhc3.DAT0 to pad SD3_DAT0(AC11)
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0(0x020E0288)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_DAT0.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_DAT0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT0 of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD5_RXD of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_DA_AMX_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: COL[6] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_COL_6_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: D[12] of instance: csi.
    //                NOTE: - Config Register IOMUXC_CSI_IPP_CSI_D_12_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: USB_OTG1_ID of instance: usb.
    //                NOTE: - Config Register IOMUXC_ANALOG_USB_OTG_ID_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[19] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: JTAG_ACT of instance: sjc.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT0_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0(0x020E0590)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: SD3_DAT0.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_DAT0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: SD3_DAT0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: SD3_DAT0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_DAT0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_DAT0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_DAT0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_DAT0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_DAT0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT0_SRE(SRE_SLOW));

    // Config usdhc3.DAT1 to pad SD3_DAT1(AD11)
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1(0x020E028C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_DAT1.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_DAT1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT1 of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD5_TXC of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_TXCLK_AMX_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ROW[6] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_6_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: D[13] of instance: csi.
    //                NOTE: - Config Register IOMUXC_CSI_IPP_CSI_D_13_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: VSELECT of instance: usdhc1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[20] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DE_B of instance: sjc.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT1_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1(0x020E0594)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: SD3_DAT1.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_DAT1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: SD3_DAT1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: SD3_DAT1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_DAT1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_DAT1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_DAT1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_DAT1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_DAT1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT1_SRE(SRE_SLOW));

    // Config usdhc3.DAT2 to pad SD3_DAT2(AC12)
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2(0x020E0290)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_DAT2.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_DAT2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT2 of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD5_TXFS of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_TXFS_AMX_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: COL[7] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_COL_7_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: D[14] of instance: csi.
    //                NOTE: - Config Register IOMUXC_CSI_IPP_CSI_D_14_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: EPITO of instance: epit1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[16] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USB_OTG2_OC of instance: usb.
    //                NOTE: - Config Register IOMUXC_USB_IPP_IND_OTG2_OC_SELECT_INPUT for mode ALT6.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT2_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2(0x020E0598)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: SD3_DAT2.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_DAT2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: SD3_DAT2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: SD3_DAT2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_DAT2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_DAT2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_DAT2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_DAT2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_DAT2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT2_SRE(SRE_SLOW));

    // Config usdhc3.DAT3 to pad SD3_DAT3(AD12)
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3(0x020E0294)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD3_DAT3.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD3_DAT3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT3 of instance: usdhc3.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: AUD5_TXD of instance: audmux.
    //                NOTE: - Config Register IOMUXC_AUDMUX_P5_INPUT_DB_AMX_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: ROW[7] of instance: kpp.
    //                NOTE: - Config Register IOMUXC_KPP_IPP_IND_ROW_7_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: D[15] of instance: csi.
    //                NOTE: - Config Register IOMUXC_CSI_IPP_CSI_D_15_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: EPITO of instance: epit2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[17] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: USB_OTG1_OC of instance: usb.
    //                NOTE: - Config Register IOMUXC_USB_IPP_IND_OTG_OC_SELECT_INPUT for mode ALT6.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD3_DAT3_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3(0x020E059C)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: SD3_DAT3.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD3_DAT3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: SD3_DAT3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: SD3_DAT3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD3_DAT3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD3_DAT3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD3_DAT3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD3_DAT3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD3_DAT3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD3_DAT3_SRE(SRE_SLOW));
}
