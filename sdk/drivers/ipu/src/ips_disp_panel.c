/*
 * Copyright (C) 2011-2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

/*!
 * @file ips_disp_panel.c
 * @brief IPU Software library, display panel parameters setting and initialization
 * @ingroup diag_ipu
 */

#include "ipu/ipu_common.h"
#include "iomux_config.h"
#include "registers/regsipu.h"

static int32_t claa_wvga_panel_init(int32_t *arg)
{
    return true;
}

static int32_t claa_wvga_panel_deinit(void)
{
    return true;
}

extern void ldb_iomux_config(void);
extern void ldb_clock_config(int32_t freq, int32_t ipu_index);
extern void lvds_power_on(void);

static int32_t hannstar_lvds_panel_init(int32_t *ipu_index)
{
    ldb_iomux_config();
    ldb_clock_config(65000000, *ipu_index);
    lvds_power_on();
    if (*ipu_index == 1)
        ldb_config(IPU1_DI0, LVDS_DUAL_PORT, SPWG, LVDS_PANEL_18BITS_MODE);
    else
        ldb_config(IPU2_DI0, LVDS_DUAL_PORT, SPWG, LVDS_PANEL_18BITS_MODE);
    return true;
}

static int32_t hannstar_lvds_panel_deinit(void)
{
    return true;
}

extern void hdmi_pgm_iomux(void);
extern void hdmi_clock_set(int32_t ipu_index, uint32_t pclk);
static int32_t hdmi_1080p60_init(int32_t *ipu_index)
{
    hdmi_pgm_iomux();
    hdmi_clock_set(*ipu_index, 148500000);
    //hdmi_config();
    return true;
}

static int32_t hdmi_1080p60_deinit(void)
{
    return true;
}

static int32_t hdmi_720p60_init(int32_t *ipu_index)
{
    hdmi_pgm_iomux();
    hdmi_clock_set(*ipu_index, 74250000);
    //hdmi_config();
    return true;
}

static int32_t hdmi_720p60_deinit(void)
{
    return true;
}

extern void ext_hdmi_transmitter_power_on(void);
static int32_t ext_hdmi_transmitter_1080p60_init(int32_t *ipu_index)
{
    /*ext_hdmi_transmitter is connected to the parallel interface */
    ipu1_iomux_config();
    ext_hdmi_transmitter_power_on();
    hdmi_clock_set(*ipu_index, 148500000);
    return true;
}

static int32_t ext_hdmi_transmitter_1080p60_deinit(void)
{
    return true;
}

extern void mipi_backlight_en(void);
extern void mipi_display_reset(void);
extern void mipi_clock_set(void);

static int32_t mipi_display_init(int32_t *ipu_index)
{
    mipi_backlight_en();
    mipi_display_reset();
    mipi_clock_set();
    return true;
}

static int32_t mipi_display_deinit(void)
{
    return true;
}

ips_dev_panel_t disp_dev_list[] = {
    {
     "CLAA01 WVGA",             // name
     CLAA_WVGA,                 // panel id flag
     DCMAP_RGB666,              // data format for panel
     60,                        // refresh rate
     800,                       // panel width
     480,                       //panel height
     27000000,                  // pixel clock frequency
     60,                        // hsync start width
     20,                        // hsync width
     40,                        // hsyn back width
     15,                        // vysnc start width
     10,                        // vsync width
     5,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     0,                         // clock selection, internal
     0,                         // clock polarity
     0,                         // hsync polarity
     0,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &claa_wvga_panel_init,     // initialization
     &claa_wvga_panel_deinit,   // deinit
     }
    ,
    {
     "HannStar XGA LVDS",       // name
     HannStar_XGA_LVDS,         // panel id flag
     DCMAP_RGB666,              // data format for panel
     60,                        // refresh rate
     1024,                      // panel width
     768,                       //panel height
     65000000,                  // pixel clock frequency
     296,                       // hsync start width
     136,                       // hsync width
     24,                        // hsyn back width
     32,                        // vysnc start width
     3,                         // vsync width
     6,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     1,                         // clock selection, external
     1,                         // clock polarity
     1,                         // hsync polarity
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &hannstar_lvds_panel_init,
     &hannstar_lvds_panel_deinit,
     }
    ,
    {
     "HDMI 1080P 60Hz",         // name
     HDMI_1080P60,              // panel id flag
     DCMAP_RGB888,              // data format for panel
     60,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     148500000,                 // pixel clock frequency
     192,                       // hsync start width
     44,                        // hsync width
     88,                        // hsyn back width
     41,                        // vysnc start width
     5,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync polarity
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &hdmi_1080p60_init,
     &hdmi_1080p60_deinit,
     }
    ,
    {
     "HDMI 720P 60Hz",          // name
     HDMI_720P60,               // name flag
     DCMAP_RGB888,
     60,                        // refresh rate
     1280,                      // panel width
     720,                       //panel height
     74250000,                  // pixel clock frequency
     260,                       // hsync start width
     40,                        // hsync width
     110,                       // hsyn back width
     25,                        // vysnc start width
     5,                         // vsync width
     5,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     1,                         // clock selection
     0,                         // clock polarity
     1,                         // hsync selection
     1,                         // hsync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &hdmi_720p60_init,         // initialization
     &hdmi_720p60_deinit,       // deinit
     }
    ,
    {
     "SII9022 1080P 60Hz",      // name
     SII9022_1080P60,           // panel id flag
     DCMAP_RGB888,              // data format for panel
     60,                        // refresh rate
     1920,                      // panel width
     1080,                      //panel height
     148500000,                 // pixel clock frequency
     192,                       // hsync start width
     44,                        // hsync width
     88,                        // hsyn back width
     41,                        // vysnc start width
     5,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     1,                         // clock selection, external
     0,                         // clock polarity
     1,                         // hsync polarity
     1,                         // vync polarity
     1,                         // drdy polarity
     0,                         // data polarity
     &ext_hdmi_transmitter_1080p60_init,
     &ext_hdmi_transmitter_1080p60_deinit,
     }
    ,
    {
     "TRULY MIPI TFT480800",    // name
     TRULY_MIPI_TFT480800,      // panel_id_flag
     DCMAP_RGB888,              // data format for panel
     60,                        // refresh rate
     480,                       // panel width
     800,                       //panel height
     24555000,                  // pixel clock frequency
     16,                        // hsync start width
     8,                         // hsync width
     8,                         // hsyn back width
     8,                         // vysnc start width
     4,                         // vsync width
     4,                         // vsync back width
     0,                         // delay from hsync to vsync
     0,                         // interlaced mode
     0,                         // clock selection, internal
     0,                         // clock polarity
     0,                         // hsync polarity
     0,                         // vync polarity
     0,                         // drdy polarity
     0,                         // data polarity
     &mipi_display_init,        // initialization
     &mipi_display_deinit,      // deinit
     }
};

uint32_t num_of_panels = sizeof(disp_dev_list) / sizeof(ips_dev_panel_t);
