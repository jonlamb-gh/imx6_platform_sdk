/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved.
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

// File: iomux_config.c

#include <iomux_config.h>

// Function to configure iomux for i.MX6SDL board Smart_Device Rev. A.
void iomux_config(void)
{
    audmux_iomux_config();
    can1_iomux_config();
    ccm_iomux_config();
    ecspi1_iomux_config();
    enet_iomux_config();
    gpio1_iomux_config();
    gpio2_iomux_config();
    gpio3_iomux_config();
    gpio4_iomux_config();
    gpio5_iomux_config();
    gpio6_iomux_config();
    gpio7_iomux_config();
    i2c1_iomux_config();
    i2c2_iomux_config();
    i2c3_iomux_config();
    ipu1_iomux_config();
    kpp_iomux_config();
    pwm1_iomux_config();
    uart1_iomux_config();
    usdhc2_iomux_config();
    usdhc3_iomux_config();
    usdhc4_iomux_config();
    gps_iomux_config();
}

// Definitions for unused modules.
void anatop_iomux_config()
{
};

void asrc_iomux_config()
{
};

void caam_wrapper_iomux_config()
{
};

void can2_iomux_config()
{
};

void csu_iomux_config()
{
};

void dcic1_iomux_config()
{
};

void dcic2_iomux_config()
{
};

void ecspi2_iomux_config()
{
};

void ecspi3_iomux_config()
{
};

void ecspi4_iomux_config()
{
};

void epdc_iomux_config()
{
};

void epit1_iomux_config()
{
};

void epit2_iomux_config()
{
};

void esai_iomux_config()
{
};

void gpt_iomux_config()
{
};

void hdmi_tx_iomux_config()
{
};

void i2c4_iomux_config()
{
};

void lcdif_iomux_config()
{
};

void ldb_iomux_config()
{
};

void mipi_core_iomux_config()
{
};

void mipi_hsi_ctrl_iomux_config()
{
};

void mlb_iomux_config()
{
};

void mmdc_iomux_config()
{
};

void pcie_ctrl_iomux_config()
{
};

void pwm2_iomux_config()
{
};

void pwm3_iomux_config()
{
};

void pwm4_iomux_config()
{
};

void rawnand_iomux_config()
{
};

void sdma_iomux_config()
{
};

void simba_iomux_config()
{
};

void sjc_iomux_config()
{
};

void snvs_hp_wrapper_iomux_config()
{
};

void snvs_lp_wrapper_iomux_config()
{
};

void spdif_iomux_config()
{
};

void src_iomux_config()
{
};

void tcu_iomux_config()
{
};

void uart2_iomux_config()
{
};

void uart3_iomux_config()
{
};

void uart4_iomux_config()
{
};

void uart5_iomux_config()
{
};

void usboh3_iomux_config()
{
};

void usdhc1_iomux_config()
{
};

void wdog1_iomux_config()
{
};

void wdog2_iomux_config()
{
};

void weim_iomux_config()
{
};
