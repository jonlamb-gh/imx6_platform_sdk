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

// File: uart4_iomux_config.c

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

// Function to configure IOMUXC for uart4 module.
void uart4_iomux_config(void)
{
    // Config uart4.RXD_MUX to pad KEY_ROW0(V6)
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0_WR(0x00000004);
    // HW_IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT_WR(0x00000003);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0(0x020E0258)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_ROW0.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_ROW0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: MOSI of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_IND_MOSI_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: TDATA[3] of instance: enet.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD5_TXD of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P5_INPUT_DB_AMX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: ROW[0] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: RXD_MUX of instance: uart4.
    //                NOTE: - Config IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[7] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DCIC_OUT of instance: dcic2.
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_ROW0_MUX_MODE(ALT4));
    // Pad KEY_ROW0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0914)
    //   DAISY [1:0] Reset: SEL_CSI0_DAT12_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart4,   In Pin: ipp_uart_rxd_mux
    //     SEL_CSI0_DAT12_ALT3 (0) - Selecting Pad: CSI0_DAT12 for Mode: ALT3.
    //     SEL_CSI0_DAT13_ALT3 (1) - Selecting Pad: CSI0_DAT13 for Mode: ALT3.
    //     SEL_KEY_COL0_ALT4 (2) - Selecting Pad: KEY_COL0 for Mode: ALT4.
    //     SEL_KEY_ROW0_ALT4 (3) - Selecting Pad: KEY_ROW0 for Mode: ALT4.
    HW_IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT_WR(
            BF_IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT_DAISY(SEL_KEY_ROW0_ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0(0x020E0640)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_ROW0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_ROW0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_ROW0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_ROW0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_ROW0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_ROW0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_ROW0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_ROW0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_ROW0_SRE(SRE_SLOW));

    // Config uart4.TXD_MUX to pad KEY_COL0(W5)
    // HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL0_WR(0x00000004);
    // HW_IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT_WR(0x00000003);
    // HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_WR(0x0001B0B0);
    // Mux Register:
    // IOMUXC_SW_MUX_CTL_PAD_KEY_COL0(0x020E0244)
    //   SION [4] - Software Input On Field Reset: SION_DISABLED
    //              Force the selected mux mode Input path no matter of MUX_MODE functionality.
    //     SION_DISABLED (0) - Input Path is determined by functionality of the selected mux mode (regular).
    //     SION_ENABLED (1) - Force input path of pad KEY_COL0.
    //   MUX_MODE [2:0] - MUX Mode Select Field Reset: ALT5
    //                    Select 1 of 8 iomux modes to be used for pad: KEY_COL0.
    //     ALT0 (0) - Select mux mode: ALT0 mux port: SCLK of instance: ecspi1.
    //                NOTE: - Config IOMUXC_ECSPI1_IPP_CSPI_CLK_IN_SELECT_INPUT for mode ALT0.
    //     ALT1 (1) - Select mux mode: ALT1 mux port: RDATA[3] of instance: enet.
    //                NOTE: - Config IOMUXC_ENET_IPP_IND_MAC0_RXDATA_3_SELECT_INPUT for mode ALT1.
    //     ALT2 (2) - Select mux mode: ALT2 mux port: AUD5_TXC of instance: audmux.
    //                NOTE: - Config IOMUXC_AUDMUX_P5_INPUT_TXCLK_AMX_SELECT_INPUT for mode ALT2.
    //     ALT3 (3) - Select mux mode: ALT3 mux port: COL[0] of instance: kpp.
    //     ALT4 (4) - Select mux mode: ALT4 mux port: TXD_MUX of instance: uart4.
    //                NOTE: - Config IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT for mode ALT4.
    //     ALT5 (5) - Select mux mode: ALT5 mux port: GPIO[6] of instance: gpio4.
    //     ALT6 (6) - Select mux mode: ALT6 mux port: DCIC_OUT of instance: dcic1.
    //     ALT7 (7) - Select mux mode: ALT7 mux port: ANY_PU_RST of instance: src.
    HW_IOMUXC_SW_MUX_CTL_PAD_KEY_COL0_WR(
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL0_SION(SION_DISABLED) | 
            BF_IOMUXC_SW_MUX_CTL_PAD_KEY_COL0_MUX_MODE(ALT4));
    // Pad KEY_COL0 is involved in Daisy Chain.
    // Input Select Register:
    // IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT(0x020E0914)
    //   DAISY [1:0] Reset: SEL_CSI0_DAT12_ALT3
    //                 Selecting Pads Involved in Daisy Chain.
    //                 NOTE: Instance: uart4,   In Pin: ipp_uart_rxd_mux
    //     SEL_CSI0_DAT12_ALT3 (0) - Selecting Pad: CSI0_DAT12 for Mode: ALT3.
    //     SEL_CSI0_DAT13_ALT3 (1) - Selecting Pad: CSI0_DAT13 for Mode: ALT3.
    //     SEL_KEY_COL0_ALT4 (2) - Selecting Pad: KEY_COL0 for Mode: ALT4.
    //     SEL_KEY_ROW0_ALT4 (3) - Selecting Pad: KEY_ROW0 for Mode: ALT4.
    HW_IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT_WR(
            BF_IOMUXC_UART4_IPP_UART_RXD_MUX_SELECT_INPUT_DAISY(SEL_KEY_ROW0_ALT4));
    // Pad Control Register:
    // IOMUXC_SW_PAD_CTL_PAD_KEY_COL0(0x020E062C)
    //   HYS [16] - Hysteresis Enable Field Reset: HYS_ENABLED
    //              Select one out of next values for pad: KEY_COL0.
    //     HYS_DISABLED (0) - Hysteresis Disabled
    //     HYS_ENABLED (1) - Hysteresis Enabled
    //   PUS [15:14] - Pull Up / Down Config. Field Reset: PUS_100KOHM_PU
    //                 Select one out of next values for pad: KEY_COL0.
    //     PUS_100KOHM_PD (0) - 100K Ohm Pull Down
    //     PUS_47KOHM_PU (1) - 47K Ohm Pull Up
    //     PUS_100KOHM_PU (2) - 100K Ohm Pull Up
    //     PUS_22KOHM_PU (3) - 22K Ohm Pull Up
    //   PUE [13] - Pull / Keep Select Field Reset: PUE_PULL
    //              Select one out of next values for pad: KEY_COL0.
    //     PUE_KEEP (0) - Keeper
    //     PUE_PULL (1) - Pull
    //   PKE [12] - Pull / Keep Enable Field Reset: PKE_ENABLED
    //              Select one out of next values for pad: KEY_COL0.
    //     PKE_DISABLED (0) - Pull/Keeper Disabled
    //     PKE_ENABLED (1) - Pull/Keeper Enabled
    //   ODE [11] - Open Drain Enable Field Reset: ODE_DISABLED
    //              Select one out of next values for pad: KEY_COL0.
    //     ODE_DISABLED (0) - Open Drain Disabled
    //     ODE_ENABLED (1) - Open Drain Enabled
    //   SPEED [7:6] - Speed Field Reset: SPD_100MHZ
    //                 Select one out of next values for pad: KEY_COL0.
    //     SPD_TBD (0) - TBD
    //     SPD_50MHZ (1) - Low(50 MHz)
    //     SPD_100MHZ (2) - Medium(100 MHz)
    //     SPD_200MHZ (3) - Maximum(200 MHz)
    //   DSE [5:3] - Drive Strength Field Reset: DSE_40OHM
    //               Select one out of next values for pad: KEY_COL0.
    //     DSE_DISABLED (0) - Output driver disabled.
    //     DSE_240OHM (1) - 240 Ohm
    //     DSE_120OHM (2) - 120 Ohm
    //     DSE_80OHM (3) - 80 Ohm
    //     DSE_60OHM (4) - 60 Ohm
    //     DSE_48OHM (5) - 48 Ohm
    //     DSE_40OHM (6) - 40 Ohm
    //     DSE_34OHM (7) - 34 Ohm
    //   SRE [0] - Slew Rate Field Reset: SRE_SLOW
    //             Select one out of next values for pad: KEY_COL0.
    //     SRE_SLOW (0) - Slow Slew Rate
    //     SRE_FAST (1) - Fast Slew Rate
    HW_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_WR(
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_HYS(HYS_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_PUS(PUS_100KOHM_PU) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_PUE(PUE_PULL) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_PKE(PKE_ENABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_ODE(ODE_DISABLED) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_SPEED(SPD_100MHZ) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_DSE(DSE_40OHM) | 
            BF_IOMUXC_SW_PAD_CTL_PAD_KEY_COL0_SRE(SRE_SLOW));
}