/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: pwm1_iomux_config.c

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

// Function to configure IOMUXC for pwm1 module.
void pwm1_iomux_config(void)
{
    // Config pwm1.PWMO to pad PWM1(Y7)
    // HW_IOMUXC_SW_MUX_CTL_PAD_PWM1_WR(0x00000000);
    // HW_IOMUXC_SW_PAD_CTL_PAD_PWM1_WR(0x000110B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_PWM1(0x020E0220)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad PWM1.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: PWM1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: PWMO of instance: pwm1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: CLKO of instance: ccm.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUDIO_CLK_OUT of instance: audmux.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: REF_OUT of instance: fec.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: MCLK of instance: csi.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[23] of instance: gpio3.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: EPITO of instance: epit1.
    HW_IOMUXC_SW_MUX_CTL_PAD_PWM1_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_PWM1_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_PWM1_MUX_MODE(ALT0));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_PWM1(0x020E0528)
    //   LVE [22] - Low Voltage Enable Field Reset: LVE_DISABLED
    //              Select one out of next values for pad: PWM1.
    //     LVE_DISABLED (0) - High Voltage
    //     LVE_ENABLED (1) - Low Voltage
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: PWM1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Configure Field Reset: PUS_100KOHM_PD
    //                 Select one out of next values for pad: PWM1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_KEEP
    //              Select one out of next values for pad: PWM1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: PWM1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: PWM1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: PWM1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: PWM1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: PWM1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_PWM1_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_LVE(LVE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_PUS(PUS_100KOHM_PD) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_PUE(PUE_KEEP) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_PWM1_SRE(SRE_SLOW));
}
