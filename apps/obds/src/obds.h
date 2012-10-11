/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/
#if !defined(__OBDS_H__)
#define __OBDS_H__

#include <stdint.h>
#include "sdk.h"
#include "audio/audio.h"
#include "menu.h"
#include "text_color.h"
#include "obds_hardware.h"

////////////////////////////////////////////////////////////////////////////////
// Definitions
////////////////////////////////////////////////////////////////////////////////

extern int auto_run_enable;

test_return_t prompt_run_test(const char * const test_name, const char* const indent);
void print_test_passed(const char* const test_name, const char* const indent);
void print_test_skipped(const char* const test_name, const char* const indent);
void print_test_failed(const char* const test_name, const char* const indent);
void print_test_not_implemented(const char* const test_name, const char* const indent);

//#define OBDS_DEBUG
#ifdef OBDS_DEBUG
#define printf1    printf
#else
#define printf1(fmt,args...)
#endif
//#define OBDS_DEBUG2
#ifdef OBDS_DEBUG2
#define printf2    printf
#else
#define printf2(fmt,args...)
#endif

// TODO Replasce this with function prompt_run_test
#define PROMPT_RUN_TEST(name, indent)                       \
    do {                                                    \
        printf("\n%s---- Running < %s >\n", indent, name);  \
        if (!auto_run_enable) {                             \
            if (!is_input_char('y', indent))                \
                return TEST_BYPASSED;                       \
        }                                                   \
        else                                                \
            printf("\n");                                   \
    } while (0)

/*!
 * maximum number of tests currently supported
 */
#define MAX_TESTS              200

typedef enum _select_tests
{
	SEL_CPU_BOARD_ONLY_TESTS,
	SEL_MAIN_BOARD_ONLY_TESTS,
	SEL_CPU_AND_MAIN_BOARD_TESTS,
	SEL_MENU_TESTS

} select_tests_t;

// OBDS tests
menu_action_t program_board_id(const menu_context_t* const context, void* const param);
menu_action_t program_mac_address(const menu_context_t* const context, void* const param);
menu_action_t ddr_test(const menu_context_t* const context, void* const param);
menu_action_t snvs_srtc_test(const menu_context_t* const context, void* const param);
menu_action_t enet_test_main(const menu_context_t* const context, void* const param);
menu_action_t ar8031_test_main(const menu_context_t* const context, void* const param);
menu_action_t KSZ9021RN_test_main(const menu_context_t* const context, void* const param);
menu_action_t android_buttons_test(const menu_context_t* const context, void* const param);
menu_action_t flexcan_test(const menu_context_t* const context, void* const param);
menu_action_t i2c_device_id_check(const menu_context_t* const context, void* const param);
menu_action_t i2s_audio_test(const menu_context_t* const context, void* const param);
menu_action_t uart_test(const menu_context_t* const context, void* const param);
menu_action_t spi_nor_test(const menu_context_t* const context, void* const param);
menu_action_t mmcsd_test(const menu_context_t* const context, void* const param);
menu_action_t pf0100_i2c_device_id_check(const menu_context_t* const context, void* const param);

//
// PRIVATE
//
extern menuitem_t main_menuitems[];

void report_test_results(void);
menu_action_t run_all_tests(const menu_context_t* const context, void* const param);
void select_tests(menuitem_t* const menuitems, const select_tests_t select_tests);

//list of tests from obds

extern int touch_button_test_enable;
extern int eeprom_test_enable;
//extern int ddr_test_enable;
//extern int i2c_device_id_check_p1003_test_enable;
//extern int i2c_device_id_check_mma8451_test_enable;
//extern int i2c_device_id_check_mag3110_test_enable;
//extern int i2c_device_id_check_mag3112_test_enable;
//extern int i2c_device_id_check_isl29023_test_enable;
//extern int i2c_device_id_check_cs42888_test_enable;
extern int touch_screen_test_enable;
extern int adv7180_test_enable;
extern int ard_mb_reset_test_enable;
extern int ard_mb_expander_reset_test_enable;
extern int ds90ur124_test_enable;
extern int mlb_os81050_test_enable;
extern int weim_nor_flash_test_enable;
//extern int pf0100_i2c_device_id_test_enable;
extern int usbh_EHCI_test_mode_test_enable;
extern int usbh_dev_enum_test_enable;
extern int usbo_dev_enum_test_enable;
extern int usbh_hub251x_test_enable;
//extern int spi_nor_test_enable;
extern int smbus_test_enable;
extern int i2c_device_id_check_DA9053_test_enable;
extern int ltc3589_i2c_device_id_test_enable;
extern int pmic_mc13892_test_enable;
//extern int mmcsd_test_enable;
extern int sdio_test_enable;
extern int gps_test_enable;
extern int ipu_display_test_enable;
extern int si476x_test_enable;
//extern int enet_test_enable;
//extern int ar8031_test_enable;
//extern int KSZ9021RN_test_enable;
extern int camera_flashtest_ebable;
//extern int i2s_audio_test_enable;
extern int esai_test_enable;
//extern int spi_nor_test_enable;
//extern int snvs_srtc_test_enable;

//Add variables from obds
extern uint32_t usbh_EHCI_test_mode_base;
extern uint32_t usbh_dev_enum_test_base;
extern uint32_t usbo_dev_enum_test_base;
extern uint32_t usbh_hub251x_test_base;
//extern uint32_t mmcsd_bus_width;
//extern uint32_t mmc_sd_base_address;
extern uint32_t sdio_bus_width;
extern uint32_t sdio_base_address;

extern audio_pcm_t pcm_record;
extern audio_pcm_t pcm_music;
extern audio_card_t snd_card_ssi;
extern audio_card_t snd_card_ssi_sgtl5000;
extern audio_card_t snd_card_ssi_wm8958;
extern audio_card_t snd_card_ssi_wm8962;

//Provide macros for test enter and exit outputs
#define TEST_ENTER(name) printf("Running test: %s\n", name)
#define TEST_EXIT(name) do {printf("..Test: %s\n", name); } while(0) 



#endif // __OBDS_H__
////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
