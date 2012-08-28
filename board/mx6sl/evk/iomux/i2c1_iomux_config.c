/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: i2c1_iomux_config.c

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

// Function to configure IOMUXC for i2c1 module.
void i2c1_iomux_config(void)
{
    // Config i2c1.SCL to pad I2C1_SCL(AC13)
    // HW_IOMUXC_SW_MUX_CTL_PAD_I2C1_SCL_WR(0x00000010);
    // HW_IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_I2C1_SCL(0x020E015C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad I2C1_SCL.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: I2C1_SCL.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SCL of instance: i2c1.
    //                NOTE: - Config Register IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RTS of instance: uart1.
    //                NOTE: - Config Register IOMUXC_UART1_IPP_UART_RTS_B_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SS2 of instance: ecspi3.
    //                NOTE: - Config Register IOMUXC_ECSPI3_IPP_IND_SS_B_2_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: RDATA[0] of instance: fec.
    //                NOTE: - Config Register IOMUXC_FEC_FEC_RDATA_0_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RST of instance: usdhc3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[12] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SS1 of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_SS_B_1_SELECT_INPUT for mode ALT6.
    HW_IOMUXC_SW_MUX_CTL_PAD_I2C1_SCL_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_I2C1_SCL_SION(SION_ENABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_I2C1_SCL_MUX_MODE(ALT0));
    // Pad I2C1_SCL is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT(0x020E071C)
    //   DAISY [1:0] Reset: SEL_AUD_RXFS_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: i2c1,   In Pin: ipp_scl_in
    //     SEL_AUD_RXFS_ALT1 (0) - Selecting Pad: AUD_RXFS for Mode: ALT1.
    //     SEL_HSIC_DAT_ALT1 (1) - Selecting Pad: HSIC_DAT for Mode: ALT1.
    //     SEL_I2C1_SCL_ALT0 (2) - Selecting Pad: I2C1_SCL for Mode: ALT0.
    HW_IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C1_IPP_SCL_IN_SELECT_INPUT_DAISY(SEL_I2C1_SCL_ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL(0x020E044C)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: I2C1_SCL.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: I2C1_SCL.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: I2C1_SCL.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: I2C1_SCL.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: I2C1_SCL.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: I2C1_SCL.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: I2C1_SCL.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: I2C1_SCL.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: I2C1_SCL.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SCL_SRE(SRE_SLOW));

    // Config i2c1.SDA to pad I2C1_SDA(AD13)
    // HW_IOMUXC_SW_MUX_CTL_PAD_I2C1_SDA_WR(0x00000010);
    // HW_IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_I2C1_SDA(0x020E0160)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad I2C1_SDA.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: I2C1_SDA.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SDA of instance: i2c1.
    //                NOTE: - Config Register IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: CTS of instance: uart1.
    //                NOTE: - Config Register IOMUXC_UART1_IPP_UART_RTS_B_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SS3 of instance: ecspi3.
    //                NOTE: - Config Register IOMUXC_ECSPI3_IPP_IND_SS_B_3_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: TX_EN of instance: fec.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: VSELECT of instance: usdhc3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[13] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SS2 of instance: ecspi1.
    //                NOTE: - Config Register IOMUXC_ECSPI1_IPP_IND_SS_B_2_SELECT_INPUT for mode ALT6.
    HW_IOMUXC_SW_MUX_CTL_PAD_I2C1_SDA_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_I2C1_SDA_SION(SION_ENABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_I2C1_SDA_MUX_MODE(ALT0));
    // Pad I2C1_SDA is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT(0x020E0720)
    //   DAISY [1:0] Reset: SEL_AUD_RXC_ALT1
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: i2c1,   In Pin: ipp_sda_in
    //     SEL_AUD_RXC_ALT1 (0) - Selecting Pad: AUD_RXC for Mode: ALT1.
    //     SEL_HSIC_STROBE_ALT1 (1) - Selecting Pad: HSIC_STROBE for Mode: ALT1.
    //     SEL_I2C1_SDA_ALT0 (2) - Selecting Pad: I2C1_SDA for Mode: ALT0.
    HW_IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT_WR(
            BF_IOMUXC_I2C1_IPP_SDA_IN_SELECT_INPUT_DAISY(SEL_I2C1_SDA_ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA(0x020E0450)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: I2C1_SDA.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: I2C1_SDA.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: I2C1_SDA.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: I2C1_SDA.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: I2C1_SDA.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: I2C1_SDA.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: I2C1_SDA.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: I2C1_SDA.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: I2C1_SDA.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_I2C1_SDA_SRE(SRE_SLOW));
}
