/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: esai_iomux_config.c

#include <io.h>
#include <iomux_define.h>
#include <iomux_register.h>

// Function to config iomux for instance esai.
void esai_iomux_config(void)
{
    // Config esai.FSR to pad ENET_REF_CLK(V22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK(0x020E01F0)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_REF_CLK.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: ENET_REF_CLK.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TX_CLK of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: FSR of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_FSR_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[23] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: SRCLK of instance: spdif.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_REF_CLK);
    // Pad ENET_REF_CLK is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_FSR_SELECT_INPUT(0x020E082C)
    //   DAISY (0) Reset: SEL_ENET_REF_CLK_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_fsr
    //     SEL_ENET_REF_CLK_ALT2 (0) - Selecting Pad: ENET_REF_CLK for Mode: ALT2.
    //     SEL_GPIO_9_ALT0 (1) - Selecting Pad: GPIO_9 for Mode: ALT0.
    writel((SEL_ENET_REF_CLK_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_FSR_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK(0x020E05C0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_REF_CLK.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_REF_CLK.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_REF_CLK.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_REF_CLK.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_REF_CLK.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_REF_CLK);

    // Config esai.FST to pad ENET_RXD1(W22)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_RXD1(0x020E01FC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_RXD1.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: ENET_RXD1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: MLBSIG of instance: mlb.
    //                NOTE: - Config IOMUXC_MLB_MLB_SIG_IN_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RDATA[1] of instance: enet.
    //                NOTE: - Config IOMUXC_ENET_IPP_IND_MAC0_RXDATA_1_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: FST of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_FST_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: 1588_EVENT3_OUT of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[26] of instance: gpio1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_RXD1);
    // Pad ENET_RXD1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_FST_SELECT_INPUT(0x020E0830)
    //   DAISY (0) Reset: SEL_ENET_RXD1_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_fst
    //     SEL_ENET_RXD1_ALT2 (0) - Selecting Pad: ENET_RXD1 for Mode: ALT2.
    //     SEL_GPIO_2_ALT0 (1) - Selecting Pad: GPIO_2 for Mode: ALT0.
    writel((SEL_ENET_RXD1_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_FST_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_RXD1(0x020E05CC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_RXD1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_RXD1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_RXD1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_RXD1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_RXD1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_RXD1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_RXD1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_RXD1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_RXD1);

    // Config esai.HCKR to pad ENET_RX_ER(W23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER(0x020E01F4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_RX_ER.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: ENET_RX_ER.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: USBOTG_ID of instance: anatop.
    //                NOTE: - Config IOMUXC_ANATOP_USB_OTG_ID_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RX_ER of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: HCKR of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_HCKR_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: IN1 of instance: spdif.
    //                NOTE: - Config IOMUXC_SPDIF_SPDIF_IN1_SELECT_INPUT for mode ALT3.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: 1588_EVENT2_OUT of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[24] of instance: gpio1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_RX_ER);
    // Pad ENET_RX_ER is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_HCKR_SELECT_INPUT(0x020E0834)
    //   DAISY (0) Reset: SEL_ENET_RX_ER_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_hckr
    //     SEL_ENET_RX_ER_ALT2 (0) - Selecting Pad: ENET_RX_ER for Mode: ALT2.
    //     SEL_GPIO_3_ALT0 (1) - Selecting Pad: GPIO_3 for Mode: ALT0.
    writel((SEL_ENET_RX_ER_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_HCKR_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER(0x020E05C4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_RX_ER.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_RX_ER.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_RX_ER.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_RX_ER.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_RX_ER.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_RX_ER.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_RX_ER.
    //               NOTE: 000 output driver disabled;
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_RX_ER.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_RX_ER);

    // Config esai.HCKT to pad ENET_RXD0(W21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_RXD0(0x020E01F8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_RXD0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: ENET_RXD0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RDATA[0] of instance: enet.
    //                NOTE: - Config IOMUXC_ENET_IPP_IND_MAC0_RXDATA_0_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: HCKT of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_HCKT_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: OUT1 of instance: spdif.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[27] of instance: gpio1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_RXD0);
    // Pad ENET_RXD0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_HCKT_SELECT_INPUT(0x020E0838)
    //   DAISY (0) Reset: SEL_ENET_RXD0_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_hckt
    //     SEL_ENET_RXD0_ALT2 (0) - Selecting Pad: ENET_RXD0 for Mode: ALT2.
    //     SEL_GPIO_4_ALT0 (1) - Selecting Pad: GPIO_4 for Mode: ALT0.
    writel((SEL_ENET_RXD0_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_HCKT_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_RXD0(0x020E05C8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_RXD0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_RXD0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_RXD0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_RXD0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_RXD0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Read Only Field
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_RXD0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_RXD0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_RXD0);

    // Config esai.SCKR to pad ENET_MDIO(V23)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_MDIO(0x020E01EC)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_MDIO.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: ENET_MDIO.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MDIO of instance: enet.
    //                NOTE: - Config IOMUXC_ENET_IPP_IND_MAC0_MDIO_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SCKR of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SCKR_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: 1588_EVENT1_OUT of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[22] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: PLOCK of instance: spdif.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_MDIO);
    // Pad ENET_MDIO is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SCKR_SELECT_INPUT(0x020E083C)
    //   DAISY (0) Reset: SEL_ENET_MDIO_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sckr
    //     SEL_ENET_MDIO_ALT2 (0) - Selecting Pad: ENET_MDIO for Mode: ALT2.
    //     SEL_GPIO_1_ALT0 (1) - Selecting Pad: GPIO_1 for Mode: ALT0.
    writel((SEL_ENET_MDIO_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_SCKR_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_MDIO(0x020E05BC)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_MDIO.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_MDIO.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_MDIO.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_MDIO.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_MDIO.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_MDIO.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_MDIO.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_MDIO.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_MDIO);

    // Config esai.SCKT to pad ENET_CRS_DV(U21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV(0x020E01E4)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_CRS_DV.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: ENET_CRS_DV.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RX_EN of instance: enet.
    //                NOTE: - Config IOMUXC_ENET_IPP_IND_MAC0_RXEN_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: SCKT of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SCKT_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: SPDIF_EXTCLK of instance: spdif.
    //                NOTE: - Config IOMUXC_SPDIF_TX_CLK2_SELECT_INPUT for mode ALT3.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[25] of instance: gpio1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_CRS_DV);
    // Pad ENET_CRS_DV is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SCKT_SELECT_INPUT(0x020E0840)
    //   DAISY (0) Reset: SEL_ENET_CRS_DV_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sckt
    //     SEL_ENET_CRS_DV_ALT2 (0) - Selecting Pad: ENET_CRS_DV for Mode: ALT2.
    //     SEL_GPIO_6_ALT0 (1) - Selecting Pad: GPIO_6 for Mode: ALT0.
    writel((SEL_ENET_CRS_DV_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_SCKT_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV(0x020E05B4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_CRS_DV.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_CRS_DV.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_CRS_DV.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_CRS_DV.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_CRS_DV.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Read Only Field
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_CRS_DV.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_CRS_DV.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_CRS_DV);

    // Config esai.TX0 to pad NANDF_CS2(A17)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2(0x020E027C)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS2.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: NANDF_CS2.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE2N of instance: rawnand.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX0 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO0_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: WEIM_CRE of instance: weim.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: CLKO2 of instance: ccm.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[15] of instance: gpio6.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: CLKO of instance: usdhc2.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0xF), IOMUXC_SW_MUX_CTL_PAD_NANDF_CS2);
    // Pad NANDF_CS2 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SDO0_SELECT_INPUT(0x020E0844)
    //   DAISY (0) Reset: SEL_GPIO_17_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sdo0
    //     SEL_GPIO_17_ALT0 (0) - Selecting Pad: GPIO_17 for Mode: ALT0.
    //     SEL_NANDF_CS2_ALT2 (1) - Selecting Pad: NANDF_CS2 for Mode: ALT2.
    writel((SEL_GPIO_17_ALT0 & 0x1), IOMUXC_ESAI_IPP_IND_SDO0_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2(0x020E0664)
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
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_CS2);

    // Config esai.TX1 to pad NANDF_CS3(D16)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3(0x020E0280)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad NANDF_CS3.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 9 iomux modes to be used for pad: NANDF_CS3.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: CE3N of instance: rawnand.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX1 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO1_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: WEIM_A[26] of instance: weim.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[16] of instance: gpio6.
    //     ALT8 (8) - Select mux mode: ALT8 mux port: CLKI of instance: usdhc2.
    //                NOTE: - Config IOMUXC_USDHC2_IPP_CARD_CLK_IN_SELECT_INPUT for mode ALT8.
    //     ALT9 (9) - Select mux mode: ALT9 mux port: SDA of instance: i2c4.
    //                NOTE: - Config IOMUXC_I2C4_IPP_SDA_IN_SELECT_INPUT for mode ALT9.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0xF), IOMUXC_SW_MUX_CTL_PAD_NANDF_CS3);
    // Pad NANDF_CS3 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SDO1_SELECT_INPUT(0x020E0848)
    //   DAISY (0) Reset: SEL_GPIO_18_ALT0
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sdo1
    //     SEL_GPIO_18_ALT0 (0) - Selecting Pad: GPIO_18 for Mode: ALT0.
    //     SEL_NANDF_CS3_ALT2 (1) - Selecting Pad: NANDF_CS3 for Mode: ALT2.
    writel((SEL_GPIO_18_ALT0 & 0x1), IOMUXC_ESAI_IPP_IND_SDO1_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3(0x020E0668)
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
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_NANDF_CS3);

    // Config esai.TX2_RX3 to pad ENET_TXD1(W20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_TXD1(0x020E0208)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_TXD1.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 7 iomux modes to be used for pad: ENET_TXD1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: MLBCLK of instance: mlb.
    //                NOTE: - Config IOMUXC_MLB_MLB_CLK_IN_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TDATA[1] of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX2_RX3 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO2_SDI3_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: 1588_EVENT0_IN of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[29] of instance: gpio1.
    //     ALT9 (9) - Select mux mode: ALT9 mux port: SDA of instance: i2c4.
    //                NOTE: - Config IOMUXC_I2C4_IPP_SDA_IN_SELECT_INPUT for mode ALT9.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0xF), IOMUXC_SW_MUX_CTL_PAD_ENET_TXD1);
    // Pad ENET_TXD1 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SDO2_SDI3_SELECT_INPUT(0x020E084C)
    //   DAISY (0) Reset: SEL_ENET_TXD1_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sdo2_sdi3
    //     SEL_ENET_TXD1_ALT2 (0) - Selecting Pad: ENET_TXD1 for Mode: ALT2.
    //     SEL_GPIO_5_ALT0 (1) - Selecting Pad: GPIO_5 for Mode: ALT0.
    writel((SEL_ENET_TXD1_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_SDO2_SDI3_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_TXD1(0x020E05D8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_TXD1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_TXD1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_TXD1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_TXD1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_TXD1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_TXD1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_TXD1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_TXD1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_TXD1);

    // Config esai.TX3_RX2 to pad ENET_TX_EN(V21)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_TX_EN(0x020E0200)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_TX_EN.
    //   MUX_MODE (3-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 5 iomux modes to be used for pad: ENET_TX_EN.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TX_EN of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX3_RX2 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO3_SDI2_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[28] of instance: gpio1.
    //     ALT9 (9) - Select mux mode: ALT9 mux port: SCL of instance: i2c4.
    //                NOTE: - Config IOMUXC_I2C4_IPP_SCL_IN_SELECT_INPUT for mode ALT9.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0xF), IOMUXC_SW_MUX_CTL_PAD_ENET_TX_EN);
    // Pad ENET_TX_EN is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SDO3_SDI2_SELECT_INPUT(0x020E0850)
    //   DAISY (0) Reset: SEL_ENET_TX_EN_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sdo3_sdi2
    //     SEL_ENET_TX_EN_ALT2 (0) - Selecting Pad: ENET_TX_EN for Mode: ALT2.
    //     SEL_GPIO_16_ALT0 (1) - Selecting Pad: GPIO_16 for Mode: ALT0.
    writel((SEL_ENET_TX_EN_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_SDO3_SDI2_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_TX_EN(0x020E05D0)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_TX_EN.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_TX_EN.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_TX_EN.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_TX_EN.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_TX_EN.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_TX_EN.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_TX_EN.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_TX_EN.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_TX_EN);

    // Config esai.TX4_RX1 to pad ENET_TXD0(U20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_TXD0(0x020E0204)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_TXD0.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 4 iomux modes to be used for pad: ENET_TXD0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TDATA[0] of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX4_RX1 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO4_SDI1_SELECT_INPUT for mode ALT2.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[30] of instance: gpio1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_TXD0);
    // Pad ENET_TXD0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SDO4_SDI1_SELECT_INPUT(0x020E0854)
    //   DAISY (0) Reset: SEL_ENET_TXD0_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sdo4_sdi1
    //     SEL_ENET_TXD0_ALT2 (0) - Selecting Pad: ENET_TXD0 for Mode: ALT2.
    //     SEL_GPIO_7_ALT0 (1) - Selecting Pad: GPIO_7 for Mode: ALT0.
    writel((SEL_ENET_TXD0_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_SDO4_SDI1_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_TXD0(0x020E05D4)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_TXD0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_TXD0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_TXD0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_TXD0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_TXD0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_TXD0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_TXD0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_TXD0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_TXD0);

    // Config esai.TX5_RX0 to pad ENET_MDC(V20)
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_ENET_MDC(0x020E01E8)
    //   SION (4) - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad ENET_MDC.
    //   MUX_MODE (2-0) - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 6 iomux modes to be used for pad: ENET_MDC.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: MLBDAT of instance: mlb.
    //                NOTE: - Config IOMUXC_MLB_MLB_DATA_IN_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: MDC of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: TX5_RX0 of instance: esai.
    //                NOTE: - Config IOMUXC_ESAI_IPP_IND_SDO5_SDI0_SELECT_INPUT for mode ALT2.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: 1588_EVENT1_IN of instance: enet.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[31] of instance: gpio1.
    writel((SION_DISABLED & 0x1) << 4 | (ALT2 & 0x7), IOMUXC_SW_MUX_CTL_PAD_ENET_MDC);
    // Pad ENET_MDC is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_ESAI_IPP_IND_SDO5_SDI0_SELECT_INPUT(0x020E0858)
    //   DAISY (0) Reset: SEL_ENET_MDC_ALT2
    //               Selecting Pads Involved in Daisy Chain.
    //               NOTE: Instance: esai,   In Pin: ipp_ind_sdo5_sdi0
    //     SEL_ENET_MDC_ALT2 (0) - Selecting Pad: ENET_MDC for Mode: ALT2.
    //     SEL_GPIO_8_ALT0 (1) - Selecting Pad: GPIO_8 for Mode: ALT0.
    writel((SEL_ENET_MDC_ALT2 & 0x1), IOMUXC_ESAI_IPP_IND_SDO5_SDI0_SELECT_INPUT);
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_ENET_MDC(0x020E05B8)
    //   HYS (16) - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: ENET_MDC.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS (15-14) - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: ENET_MDC.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE (13) - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: ENET_MDC.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE (12) - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: ENET_MDC.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE (11) - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: ENET_MDC.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED (7-6) - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: ENET_MDC.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE (5-3) - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: ENET_MDC.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE (0) - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: ENET_MDC.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    writel((HYS_ENABLED & 0x1) << 16 | (PUS_100KOHM_PU & 0x3) << 14 | (PUE_PULL & 0x1) << 13 |
           (PKE_ENABLED & 0x1) << 12 | (ODE_DISABLED & 0x1) << 11 | (SPD_100MHZ & 0x3) << 6 |
           (DSE_40OHM & 0x7) << 3 | (SRE_SLOW & 0x1), IOMUXC_SW_PAD_CTL_PAD_ENET_MDC);
}