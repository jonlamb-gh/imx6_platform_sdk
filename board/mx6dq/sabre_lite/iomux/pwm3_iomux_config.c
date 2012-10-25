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

// File: pwm3_iomux_config.c

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

// Function to configure IOMUXC for pwm3 module.
void pwm3_iomux_config(void)
{
    // Config pwm3.PWMO to pad SD1_DAT1(C20)
    // J16 - MIPI GP
    // HW_IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1_WR(0x00000002);
    // HW_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1(0x020E033C)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad SD1_DAT1.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: SD1_DAT1.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: DAT1 of instance: usdhc1.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: SS0 of instance: ecspi5.
    //                NOTE: - Config Register IOMUXC_ECSPI5_IPP_IND_SS_B_0_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: PWMO of instance: pwm3.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: CAPIN2 of instance: gpt.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: DIAG_STATUS_BUS_MUX[7] of instance: pcie_ctrl.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[17] of instance: gpio1.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: OPHYDTB[0] of instance: hdmi_tx.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANATOP_TESTO[8] of instance: anatop.
    HW_IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_SD1_DAT1_MUX_MODE(ALT2));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1(0x020E0724)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: SD1_DAT1.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: SD1_DAT1.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: SD1_DAT1.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: SD1_DAT1.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: SD1_DAT1.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: SD1_DAT1.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: SD1_DAT1.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: SD1_DAT1.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_SD1_DAT1_SRE(SRE_SLOW));
}
