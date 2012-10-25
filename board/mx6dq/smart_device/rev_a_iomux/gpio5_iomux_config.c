/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

// File: gpio5_iomux_config.c

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

// Function to configure IOMUXC for gpio5 module.
void gpio5_iomux_config(void)
{
    // Config gpio5.GPIO[0] to pad EIM_WAIT(M25)
    // DI0_D0_CS
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_WR(0x0000B060);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT(0x020E0154)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_WAIT.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 5 iomux modes to be used for pad: EIM_WAIT.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_WAIT of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: WEIM_DTACK_B of instance: weim.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[0] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: HDATA[30] of instance: tpsmp.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: BT_CFG[25] of instance: src.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_WAIT_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT(0x020E0468)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_WAIT.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_WAIT.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_WAIT.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_WAIT.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_WAIT.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_50MHZ
    //                 Select one out of next values for pad: EIM_WAIT.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_60OHM
    //               Select one out of next values for pad: EIM_WAIT.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: EIM_WAIT.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_HYS(HYS_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_SPEED(SPD_50MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_DSE(DSE_60OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_WAIT_SRE(SRE_SLOW));

    // Config gpio5.GPIO[2] to pad EIM_A25(H19)
    // CHG_FLT1_B
    // HW_IOMUXC_SW_MUX_CTL_PAD_EIM_A25_WR(0x00000005);
    // HW_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_WR(0x0000B0B1);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_EIM_A25(0x020E0088)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad EIM_A25.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT0
    //                    Select 1 of 8 iomux modes to be used for pad: EIM_A25.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: WEIM_A[25] of instance: weim.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS1 of instance: ecspi4.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: RDY of instance: ecspi2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: DI1_PIN12 of instance: ipu1.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DI0_D1_CS of instance: ipu1.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[2] of instance: gpio5.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: CEC_LINE of instance: hdmi_tx.
    //                NOTE: - Config Register IOMUXC_HDMI_TX_ICECIN_SELECT_INPUT for mode ALT6.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: HBURST[0] of instance: pl301_mx63per1.
    HW_IOMUXC_SW_MUX_CTL_PAD_EIM_A25_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_A25_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_EIM_A25_MUX_MODE(ALT5));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_EIM_A25(0x020E039C)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_DISABLED
    //              Select one out of next values for pad: EIM_A25.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: EIM_A25.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: EIM_A25.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: EIM_A25.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: EIM_A25.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: EIM_A25.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: EIM_A25.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_FAST
    //             Select one out of next values for pad: EIM_A25.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_HYS(HYS_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_EIM_A25_SRE(SRE_FAST));
}
