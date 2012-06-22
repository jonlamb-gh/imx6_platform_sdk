/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: gpio6_iomux_config.c

/* ------------------------------------------------------------------------------
 * <auto-generated>
 *     This code was generated by a tool.
 *     Runtime Version:3.3.2.0
 *
 *     Changes to this file may cause incorrect behavior and will be lost if
 *     the code is regenerated.
 * </auto-generated>
 * ------------------------------------------------------------------------------
*/

#include "iomux_config.h"
#include "iomux_define.h"
#include "registers/regsiomuxc.h"

// Function to configure IOMUXC for gpio6 module.
void gpio6_iomux_config(void)
{
    // Config gpio6.GPIO[10] to pad NANDF_RB0(B16)
    // AUX_5V_EN
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0(0x020E02E0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_RB0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_RB0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: READY0 of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI0_PIN1 of instance: ipu2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[2] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[14] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[14] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[10] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_OUT[33] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HSIZE[1] of instance: pl301_mx63per1.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_RB0_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0(0x020E06C8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_RB0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_RB0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_RB0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_RB0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_RB0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_RB0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_RB0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_RB0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_RB0_SRE(SRE_SLOW));

    // Config gpio6.GPIO[11] to pad NANDF_CS0(F15)
    // DISP0_RST_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0(0x020E02E4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: NANDF_CS0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE0N of instance: rawnand.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[15] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[15] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[11] of instance: gpio6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HSIZE[2] of instance: pl301_mx63per1.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS0_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0(0x020E06CC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS0_SRE(SRE_SLOW));

    // Config gpio6.GPIO[14] to pad NANDF_CS1(C16)
    // DISP0_PWR_EN
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1(0x020E02E8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: NANDF_CS1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE1N of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: VSELECT of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: VSELECT of instance: usdhc3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[3] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[14] of instance: gpio6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HREADYOUT of instance: pl301_mx63per1.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS1_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1(0x020E06D0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS1_SRE(SRE_SLOW));

    // Config gpio6.GPIO[15] to pad NANDF_CS2(A17)
    // CABC_EN0
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2(0x020E02EC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS2.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: NANDF_CS2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE2N of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[0] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX0 of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_SDO0_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: WEIM_CRE of instance: weim.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CLKO2 of instance: ccm.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[15] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SISG[0] of instance: ipu2.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2(0x020E06D4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS2.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS2.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS2.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS2.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS2.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS2.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS2.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS2.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2_SRE(SRE_SLOW));

    // Config gpio6.GPIO[16] to pad NANDF_CS3(D16)
    // CABC_EN1
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3(0x020E02F0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS3.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_CS3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE3N of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[1] of instance: ipu1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX1 of instance: esai.
    //                NOTE: - Config Register IOMUXC_ESAI_IPP_IND_SDO1_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: WEIM_A[26] of instance: weim.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[4] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[16] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SISG[1] of instance: ipu2.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: CLK of instance: tpsmp.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3(0x020E06D8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CS3.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CS3.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CS3.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CS3.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CS3.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CS3.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CS3.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CS3.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3_SRE(SRE_SLOW));

    // Config gpio6.GPIO[31] to pad EIM_BCLK(N22)
    // DI0_D1_CS
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_BCLK_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_WR(0x0000B0B1);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_BCLK(0x020E0158)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_BCLK.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 4 iomux modes to be used for pad: EIM_BCLK.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_BCLK of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: DI1_PIN16 of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[31] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: HDATA[31] of instance: tpsmp.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_BCLK_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_BCLK_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_BCLK_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK(0x020E046C)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_BCLK.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_BCLK.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_BCLK.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_BCLK.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_BCLK.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_BCLK.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_BCLK.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_BCLK.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_HYS(HYS_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_BCLK_SRE(SRE_FAST));

    // Config gpio6.GPIO[7] to pad NANDF_CLE(C15)
    // CAP_TCH_INT1
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE(0x020E02D4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CLE.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_CLE.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CLE of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[4] of instance: ipu2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[31] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[11] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[11] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[7] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[23] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HTRANS[0] of instance: tpsmp.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_CLE_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE(0x020E06BC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_CLE.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_CLE.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_CLE.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_CLE.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_CLE.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_CLE.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_CLE.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_CLE.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_CLE_SRE(SRE_SLOW));

    // Config gpio6.GPIO[8] to pad NANDF_ALE(A16)
    // CAP_TCH_INT0
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE(0x020E02D8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_ALE.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_ALE.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: ALE of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RST of instance: usdhc4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[0] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[12] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[12] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[8] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_IN[24] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HTRANS[1] of instance: tpsmp.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_ALE_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE(0x020E06C0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_ALE.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_ALE.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_ALE.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_ALE.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_ALE.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_ALE.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_ALE.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_ALE.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_ALE_SRE(SRE_SLOW));

    // Config gpio6.GPIO[9] to pad NANDF_WP_B(E15)
    // DISP0_WR
    // HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B(0x020E02DC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_WP_B.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: NANDF_WP_B.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: RESETN of instance: rawnand.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SISG[5] of instance: ipu2.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: DIAG_STATUS_BUS_MUX[1] of instance: pcie_ctrl.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: UH3_DFD_OUT[13] of instance: usboh3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: UH2_DFD_OUT[13] of instance: usboh3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[9] of instance: gpio6.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DPHY_TEST_OUT[32] of instance: mipi_core.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HSIZE[0] of instance: pl301_mx63per1.
    HW_IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_NANDF_WP_B_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B(0x020E06C4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: NANDF_WP_B.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: NANDF_WP_B.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: NANDF_WP_B.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: NANDF_WP_B.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: NANDF_WP_B.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: NANDF_WP_B.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: NANDF_WP_B.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: NANDF_WP_B.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_NANDF_WP_B_SRE(SRE_SLOW));
}