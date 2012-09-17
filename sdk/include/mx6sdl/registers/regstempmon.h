/*
 * Copyright (c) 2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_TEMPMON_REGISTERS_H__
#define __HW_TEMPMON_REGISTERS_H__

#include "regs.h"

/*
 * i.MX6SDL TEMPMON
 *
 * Temperature Monitor
 *
 * Registers defined in this header file:
 * - HW_TEMPMON_TEMPSENSE0 - Tempsensor Control Register 0
 * - HW_TEMPMON_TEMPSENSE1 - Tempsensor Control Register 1
 *
 * - hw_tempmon_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_TEMPMON_BASE
#define HW_TEMPMON_INSTANCE_COUNT (1) //!< Number of instances of the TEMPMON module.
#define REGS_TEMPMON_BASE (0x020c8000) //!< Base address for TEMPMON.
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_TEMPMON_TEMPSENSE0 - Tempsensor Control Register 0
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_TEMPMON_TEMPSENSE0 - Tempsensor Control Register 0 (RW)
 *
 * Reset value: 0x00000001
 *
 * This register defines the basic controls for the temperature sensor minus the frequency of
 * automatic sampling which is defined in the tempsensor.
 */
typedef union _hw_tempmon_tempsense0
{
    reg32_t U;
    struct _hw_tempmon_tempsense0_bitfields
    {
        unsigned POWER_DOWN : 1; //!< [0] This bit powers down the temperature sensor.
        unsigned MEASURE_TEMP : 1; //!< [1] Starts the measurement process.
        unsigned FINISHED : 1; //!< [2] Indicates that the latest temp is valid.
        unsigned RESERVED1 : 5; //!< [7:3] Reserved.
        unsigned TEMP_CNT : 12; //!< [19:8] This bit field contains the last measured temperature count.
        unsigned ALARM_VALUE : 12; //!< [31:20] This bit field contains the temperature count (raw sensor output) that will generate an alarm interrupt.
    } B;
} hw_tempmon_tempsense0_t;
#endif

/*!
 * @name Constants and macros for entire TEMPMON_TEMPSENSE0 register
 */
//@{
#define HW_TEMPMON_TEMPSENSE0_ADDR      (REGS_TEMPMON_BASE + 0x180)
#define HW_TEMPMON_TEMPSENSE0_SET_ADDR  (HW_TEMPMON_TEMPSENSE0_ADDR + 0x4)
#define HW_TEMPMON_TEMPSENSE0_CLR_ADDR  (HW_TEMPMON_TEMPSENSE0_ADDR + 0x8)
#define HW_TEMPMON_TEMPSENSE0_TOG_ADDR  (HW_TEMPMON_TEMPSENSE0_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_TEMPMON_TEMPSENSE0           (*(volatile hw_tempmon_tempsense0_t *) HW_TEMPMON_TEMPSENSE0_ADDR)
#define HW_TEMPMON_TEMPSENSE0_RD()      (HW_TEMPMON_TEMPSENSE0.U)
#define HW_TEMPMON_TEMPSENSE0_WR(v)     (HW_TEMPMON_TEMPSENSE0.U = (v))
#define HW_TEMPMON_TEMPSENSE0_SET(v)    ((*(volatile reg32_t *) HW_TEMPMON_TEMPSENSE0_SET_ADDR) = (v))
#define HW_TEMPMON_TEMPSENSE0_CLR(v)    ((*(volatile reg32_t *) HW_TEMPMON_TEMPSENSE0_CLR_ADDR) = (v))
#define HW_TEMPMON_TEMPSENSE0_TOG(v)    ((*(volatile reg32_t *) HW_TEMPMON_TEMPSENSE0_TOG_ADDR) = (v))
#endif
//@}

/*
 * constants & macros for individual TEMPMON_TEMPSENSE0 bitfields
 */

/*! @name Register TEMPMON_TEMPSENSE0, field POWER_DOWN[0] (RW)
 *
 * This bit powers down the temperature sensor.
 *
 * Values:
 * - POWER_UP = 0 - Enable power to the temperature sensor.
 * - POWER_DOWN = 1 - Power down the temperature sensor.
 */
//@{

#define BP_TEMPMON_TEMPSENSE0_POWER_DOWN      (0)      //!< Bit position for TEMPMON_TEMPSENSE0_POWER_DOWN.
#define BM_TEMPMON_TEMPSENSE0_POWER_DOWN      (0x00000001)  //!< Bit mask for TEMPMON_TEMPSENSE0_POWER_DOWN.

//! @brief Get value of TEMPMON_TEMPSENSE0_POWER_DOWN from a register value.
#define BG_TEMPMON_TEMPSENSE0_POWER_DOWN(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_TEMPMON_TEMPSENSE0_POWER_DOWN) >> BP_TEMPMON_TEMPSENSE0_POWER_DOWN)

//! @brief Format value for bitfield TEMPMON_TEMPSENSE0_POWER_DOWN.
#define BF_TEMPMON_TEMPSENSE0_POWER_DOWN(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_TEMPMON_TEMPSENSE0_POWER_DOWN) & BM_TEMPMON_TEMPSENSE0_POWER_DOWN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the POWER_DOWN field to a new value.
#define BW_TEMPMON_TEMPSENSE0_POWER_DOWN(v)   BF_CS1(TEMPMON_TEMPSENSE0, POWER_DOWN, v)
#endif

//! @brief Macro to simplify usage of value macros.
#define BF_TEMPMON_TEMPSENSE0_POWER_DOWN_V(v) BF_TEMPMON_TEMPSENSE0_POWER_DOWN(BV_TEMPMON_TEMPSENSE0_POWER_DOWN__##v)

#define BV_TEMPMON_TEMPSENSE0_POWER_DOWN__POWER_UP (0x0) //!< Enable power to the temperature sensor.
#define BV_TEMPMON_TEMPSENSE0_POWER_DOWN__POWER_DOWN (0x1) //!< Power down the temperature sensor.

//@}

/*! @name Register TEMPMON_TEMPSENSE0, field MEASURE_TEMP[1] (RW)
 *
 * Starts the measurement process. If the measurement frequency is zero in the TEMPSENSE1 register,
 * this results in a single conversion.
 *
 * Values:
 * - STOP = 0 - Do not start the measurement process.
 * - START = 1 - Start the measurement process.
 */
//@{

#define BP_TEMPMON_TEMPSENSE0_MEASURE_TEMP      (1)      //!< Bit position for TEMPMON_TEMPSENSE0_MEASURE_TEMP.
#define BM_TEMPMON_TEMPSENSE0_MEASURE_TEMP      (0x00000002)  //!< Bit mask for TEMPMON_TEMPSENSE0_MEASURE_TEMP.

//! @brief Get value of TEMPMON_TEMPSENSE0_MEASURE_TEMP from a register value.
#define BG_TEMPMON_TEMPSENSE0_MEASURE_TEMP(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_TEMPMON_TEMPSENSE0_MEASURE_TEMP) >> BP_TEMPMON_TEMPSENSE0_MEASURE_TEMP)

//! @brief Format value for bitfield TEMPMON_TEMPSENSE0_MEASURE_TEMP.
#define BF_TEMPMON_TEMPSENSE0_MEASURE_TEMP(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_TEMPMON_TEMPSENSE0_MEASURE_TEMP) & BM_TEMPMON_TEMPSENSE0_MEASURE_TEMP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MEASURE_TEMP field to a new value.
#define BW_TEMPMON_TEMPSENSE0_MEASURE_TEMP(v)   BF_CS1(TEMPMON_TEMPSENSE0, MEASURE_TEMP, v)
#endif

//! @brief Macro to simplify usage of value macros.
#define BF_TEMPMON_TEMPSENSE0_MEASURE_TEMP_V(v) BF_TEMPMON_TEMPSENSE0_MEASURE_TEMP(BV_TEMPMON_TEMPSENSE0_MEASURE_TEMP__##v)

#define BV_TEMPMON_TEMPSENSE0_MEASURE_TEMP__STOP (0x0) //!< Do not start the measurement process.
#define BV_TEMPMON_TEMPSENSE0_MEASURE_TEMP__START (0x1) //!< Start the measurement process.

//@}

/*! @name Register TEMPMON_TEMPSENSE0, field FINISHED[2] (RO)
 *
 * Indicates that the latest temp is valid. This bit should be cleared by the sensor after the start
 * of each measurement.
 *
 * Values:
 * - INVALID = 0 - Last measurement is not ready yet.
 * - VALID = 1 - Last measurement is valid.
 */
//@{

#define BP_TEMPMON_TEMPSENSE0_FINISHED      (2)      //!< Bit position for TEMPMON_TEMPSENSE0_FINISHED.
#define BM_TEMPMON_TEMPSENSE0_FINISHED      (0x00000004)  //!< Bit mask for TEMPMON_TEMPSENSE0_FINISHED.

//! @brief Get value of TEMPMON_TEMPSENSE0_FINISHED from a register value.
#define BG_TEMPMON_TEMPSENSE0_FINISHED(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_TEMPMON_TEMPSENSE0_FINISHED) >> BP_TEMPMON_TEMPSENSE0_FINISHED)

//! @brief Macro to simplify usage of value macros.
#define BF_TEMPMON_TEMPSENSE0_FINISHED_V(v) BF_TEMPMON_TEMPSENSE0_FINISHED(BV_TEMPMON_TEMPSENSE0_FINISHED__##v)

#define BV_TEMPMON_TEMPSENSE0_FINISHED__INVALID (0x0) //!< Last measurement is not ready yet.
#define BV_TEMPMON_TEMPSENSE0_FINISHED__VALID (0x1) //!< Last measurement is valid.

//@}

/*! @name Register TEMPMON_TEMPSENSE0, field TEMP_CNT[19:8] (RO)
 *
 * This bit field contains the last measured temperature count.
 */
//@{

#define BP_TEMPMON_TEMPSENSE0_TEMP_CNT      (8)      //!< Bit position for TEMPMON_TEMPSENSE0_TEMP_CNT.
#define BM_TEMPMON_TEMPSENSE0_TEMP_CNT      (0x000fff00)  //!< Bit mask for TEMPMON_TEMPSENSE0_TEMP_CNT.

//! @brief Get value of TEMPMON_TEMPSENSE0_TEMP_CNT from a register value.
#define BG_TEMPMON_TEMPSENSE0_TEMP_CNT(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_TEMPMON_TEMPSENSE0_TEMP_CNT) >> BP_TEMPMON_TEMPSENSE0_TEMP_CNT)

//@}

/*! @name Register TEMPMON_TEMPSENSE0, field ALARM_VALUE[31:20] (RW)
 *
 * This bit field contains the temperature count (raw sensor output) that will generate an alarm
 * interrupt.
 */
//@{

#define BP_TEMPMON_TEMPSENSE0_ALARM_VALUE      (20)      //!< Bit position for TEMPMON_TEMPSENSE0_ALARM_VALUE.
#define BM_TEMPMON_TEMPSENSE0_ALARM_VALUE      (0xfff00000)  //!< Bit mask for TEMPMON_TEMPSENSE0_ALARM_VALUE.

//! @brief Get value of TEMPMON_TEMPSENSE0_ALARM_VALUE from a register value.
#define BG_TEMPMON_TEMPSENSE0_ALARM_VALUE(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_TEMPMON_TEMPSENSE0_ALARM_VALUE) >> BP_TEMPMON_TEMPSENSE0_ALARM_VALUE)

//! @brief Format value for bitfield TEMPMON_TEMPSENSE0_ALARM_VALUE.
#define BF_TEMPMON_TEMPSENSE0_ALARM_VALUE(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_TEMPMON_TEMPSENSE0_ALARM_VALUE) & BM_TEMPMON_TEMPSENSE0_ALARM_VALUE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ALARM_VALUE field to a new value.
#define BW_TEMPMON_TEMPSENSE0_ALARM_VALUE(v)   BF_CS1(TEMPMON_TEMPSENSE0, ALARM_VALUE, v)
#endif

//@}

//-------------------------------------------------------------------------------------------
// HW_TEMPMON_TEMPSENSE1 - Tempsensor Control Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_TEMPMON_TEMPSENSE1 - Tempsensor Control Register 1 (RW)
 *
 * Reset value: 0x00000001
 *
 * This register defines the automatic repeat time of the temperature sensor.
 */
typedef union _hw_tempmon_tempsense1
{
    reg32_t U;
    struct _hw_tempmon_tempsense1_bitfields
    {
        unsigned MEASURE_FREQ : 16; //!< [15:0] This bits determines how many RTC clocks to wait before automatically repeating a temperature measurement.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved.
    } B;
} hw_tempmon_tempsense1_t;
#endif

/*!
 * @name Constants and macros for entire TEMPMON_TEMPSENSE1 register
 */
//@{
#define HW_TEMPMON_TEMPSENSE1_ADDR      (REGS_TEMPMON_BASE + 0x190)
#define HW_TEMPMON_TEMPSENSE1_SET_ADDR  (HW_TEMPMON_TEMPSENSE1_ADDR + 0x4)
#define HW_TEMPMON_TEMPSENSE1_CLR_ADDR  (HW_TEMPMON_TEMPSENSE1_ADDR + 0x8)
#define HW_TEMPMON_TEMPSENSE1_TOG_ADDR  (HW_TEMPMON_TEMPSENSE1_ADDR + 0xC)

#ifndef __LANGUAGE_ASM__
#define HW_TEMPMON_TEMPSENSE1           (*(volatile hw_tempmon_tempsense1_t *) HW_TEMPMON_TEMPSENSE1_ADDR)
#define HW_TEMPMON_TEMPSENSE1_RD()      (HW_TEMPMON_TEMPSENSE1.U)
#define HW_TEMPMON_TEMPSENSE1_WR(v)     (HW_TEMPMON_TEMPSENSE1.U = (v))
#define HW_TEMPMON_TEMPSENSE1_SET(v)    ((*(volatile reg32_t *) HW_TEMPMON_TEMPSENSE1_SET_ADDR) = (v))
#define HW_TEMPMON_TEMPSENSE1_CLR(v)    ((*(volatile reg32_t *) HW_TEMPMON_TEMPSENSE1_CLR_ADDR) = (v))
#define HW_TEMPMON_TEMPSENSE1_TOG(v)    ((*(volatile reg32_t *) HW_TEMPMON_TEMPSENSE1_TOG_ADDR) = (v))
#endif
//@}

/*
 * constants & macros for individual TEMPMON_TEMPSENSE1 bitfields
 */

/*! @name Register TEMPMON_TEMPSENSE1, field MEASURE_FREQ[15:0] (RW)
 *
 * This bits determines how many RTC clocks to wait before automatically repeating a temperature
 * measurement. The pause time before remeasuring is the field value multiplied by the RTC period.
 *
 * Values:
 * - 0x0000 - Defines a single measurement with no repeat.
 * - . . . - 
 * - 0x0001 - Updates the temperature value at a RTC clock rate.
 * - 0x0002 - Updates the temperature value at a RTC/2 clock rate.
 * - 0xFFFF - Determines a two second sample period with a 32.768KHz RTC clock. Exact timings depend on the
 *     accuracy of the RTC clock.
 */
//@{

#define BP_TEMPMON_TEMPSENSE1_MEASURE_FREQ      (0)      //!< Bit position for TEMPMON_TEMPSENSE1_MEASURE_FREQ.
#define BM_TEMPMON_TEMPSENSE1_MEASURE_FREQ      (0x0000ffff)  //!< Bit mask for TEMPMON_TEMPSENSE1_MEASURE_FREQ.

//! @brief Get value of TEMPMON_TEMPSENSE1_MEASURE_FREQ from a register value.
#define BG_TEMPMON_TEMPSENSE1_MEASURE_FREQ(r)   ((__REG_VALUE_TYPE((r), reg32_t) & BM_TEMPMON_TEMPSENSE1_MEASURE_FREQ) >> BP_TEMPMON_TEMPSENSE1_MEASURE_FREQ)

//! @brief Format value for bitfield TEMPMON_TEMPSENSE1_MEASURE_FREQ.
#define BF_TEMPMON_TEMPSENSE1_MEASURE_FREQ(v)   ((__REG_VALUE_TYPE((v), reg32_t) << BP_TEMPMON_TEMPSENSE1_MEASURE_FREQ) & BM_TEMPMON_TEMPSENSE1_MEASURE_FREQ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MEASURE_FREQ field to a new value.
#define BW_TEMPMON_TEMPSENSE1_MEASURE_FREQ(v)   BF_CS1(TEMPMON_TEMPSENSE1, MEASURE_FREQ, v)
#endif

//@}

//-------------------------------------------------------------------------------------------
// hw_tempmon_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All TEMPMON module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_tempmon
{
    reg32_t _reserved0[96];
    volatile hw_tempmon_tempsense0_t TEMPSENSE0; //!< Tempsensor Control Register 0
    volatile reg32_t TEMPSENSE0_SET; //!< Tempsensor Control Register 0 Set
    volatile reg32_t TEMPSENSE0_CLR; //!< Tempsensor Control Register 0 Clear
    volatile reg32_t TEMPSENSE0_TOG; //!< Tempsensor Control Register 0 Toggle
    volatile hw_tempmon_tempsense1_t TEMPSENSE1; //!< Tempsensor Control Register 1
    volatile reg32_t TEMPSENSE1_SET; //!< Tempsensor Control Register 1 Set
    volatile reg32_t TEMPSENSE1_CLR; //!< Tempsensor Control Register 1 Clear
    volatile reg32_t TEMPSENSE1_TOG; //!< Tempsensor Control Register 1 Toggle
} hw_tempmon_t;
#pragma pack()

//! @brief Macro to access all TEMPMON registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_TEMPMON</code>.
#define HW_TEMPMON     (*(hw_tempmon_t *) REGS_TEMPMON_BASE)
#endif

#endif // __HW_TEMPMON_REGISTERS_H__
