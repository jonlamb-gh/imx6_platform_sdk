/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _CSI_H
#define _CSI_H

#include "regs.h"

/*
 * i.MX6SL CSI registers defined in this header file.
 *
 * - HW_CSI_CSICR1 - CSI Control Register 1
 * - HW_CSI_CSICR2 - CSI Control Register 2
 * - HW_CSI_CSICR3 - CSI Control Register 3
 * - HW_CSI_CSISTATFIFO - CSI Statistic FIFO Register
 * - HW_CSI_CSIRFIFO - CSI RX FIFO Register
 * - HW_CSI_CSIRXCNT - CSI RX Count Register
 * - HW_CSI_CSISR - CSI Status Register
 * - HW_CSI_CSIDMASA_STATFIFO - CSI DMA Start Address Register - for STATFIFO
 * - HW_CSI_CSIDMATS_STATFIFO - CSI DMA Transfer Size Register - for STATFIFO
 * - HW_CSI_CSIDMASA_FB1 - CSI DMA Start Address Register - for Frame Buffer1
 * - HW_CSI_CSIDMASA_FB2 - CSI DMA Transfer Size Register - for Frame Buffer2
 * - HW_CSI_CSIFBUF_PARA - CSI Frame Buffer Parameter Register
 * - HW_CSI_CSIIMAG_PARA - CSI Image Parameter Register
 *
 * hw_csi_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_CSI_BASE
#define REGS_CSI_BASE (0x020e4000) //!< Base address for CSI.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSICR1 - CSI Control Register 1 (RW)
 *
 * Reset value: 0x40000800
 *
 * This register controls the sensor interface timing , CSI-to-PrP bus interface and interrupt
 * generation. The interrupt enable bits in this register control the interrupt signals and the
 * status bits. That means status bits will only function when the corresponding interrupt bits are
 * enabled.
 */
typedef union _hw_csi_csicr1
{
    reg32_t U;
    struct _hw_csi_csicr1_bitfields
    {
        unsigned PIXEL_BIT : 1; //!< [0] Pixel Bit. This bit indicates the bayer data width for each pixel. This bit should be configured before activating or re-starting the embedded DMA controller.
        unsigned REDGE : 1; //!< [1] Valid Pixel Clock Edge Select. Selects which edge of the CSI_PIXCLK is used to latch the pixel data.
        unsigned INV_PCLK : 1; //!< [2] Invert Pixel Clock Input. This bit determines if the Pixel Clock (CSI_PIXCLK) is inverted before it is applied to the CSI module.
        unsigned INV_DATA : 1; //!< [3] Invert Data Input. This bit enables or disables internal inverters on the data lines.
        unsigned GCLK_MODE : 1; //!< [4] Gated Clock Mode Enable. Controls if CSI is working in gated or non-gated mode. This bit works only in traditional mode-that is, CCIR_EN = 0. Otherwise this bit is ignored.
        unsigned CLR_RXFIFO : 1; //!< [5] Asynchronous RXFIFO Clear. This bit clears the RXFIFO. This bit works only in async FIFO clear mode-that is, FCC = 0. Otherwise this bit is ignored. Writing 1 clears the RXFIFO immediately, RXFIFO restarts immediately after that. The bit is restored to 0 automatically after finish. Normally reads 0.
        unsigned CLR_STATFIFO : 1; //!< [6] Asynchronous STATFIFO Clear. This bit clears the STATFIFO and Reset STAT block. This bit works only in async FIFO clear mode-that is, FCC = 0. Otherwise this bit is ignored. Writing 1 will clear STATFIFO and reset STAT block immediately, STATFIFO and STAT block then wait and restart after the arrival of next SOF. The bit is restored to 0 automatically after finish. Normally reads 0.
        unsigned PACK_DIR : 1; //!< [7] Data Packing Direction. This bit Controls how 8-bit/10-bit image data is packed into 32-bit RX FIFO, and how 16-bit statistical data is packed into 32-bit STAT FIFO.
        unsigned FCC : 1; //!< [8] FIFO Clear Control. This bit determines how the RXFIFO and STATFIFO are cleared. When Synchronous FIFO clear is selected the RXFIFO and STATFIFO are cleared, and STAT block is reset, on every SOF. FIFOs and STAT block restarts immediately after reset. For information on the operation when Asynchronous FIFO clear is selected, refer to the descriptions for the CLR_RXFIFO and CLR_STATFIFO bits.
        unsigned MCLKEN : 1; //!< [9] Sensor Master Clock (MCLK) Enable. This bit enables or disables the MCLK input to the sensor.
        unsigned CCIR_EN : 1; //!< [10] CCIR656 Interface Enable. This bit selects the type of interface used. When the CCIR656 timing decoder is enabled, it replaces the function of timing interface logic.
        unsigned HSYNC_POL : 1; //!< [11] HSYNC Polarity Select. This bit controls the polarity of HSYNC. This bit only works in gated-clock-that is, GCLK_MODE = 1 and CCIR_EN = 0.
        unsigned MCLKDIV : 4; //!< [15:12] Sensor Master Clock (MCLK) Divider. This field contains the divisor MCLK. The MCLK is derived from the PERCLK.
        unsigned SOF_INTEN : 1; //!< [16] Start Of Frame (SOF) Interrupt Enable. This bit enables the SOF interrupt.
        unsigned SOF_POL : 1; //!< [17] SOF Interrupt Polarity. This bit controls the condition that generates an SOF interrupt.
        unsigned RXFF_INTEN : 1; //!< [18] RxFIFO Full Interrupt Enable. This bit enables the RxFIFO full interrupt.
        unsigned FB1_DMA_DONE_INTEN : 1; //!< [19] Frame Buffer1 DMA Transfer Done Interrupt Enable. This bit enables the interrupt of Frame Buffer1 DMA transfer done.
        unsigned FB2_DMA_DONE_INTEN : 1; //!< [20] Frame Buffer2 DMA Transfer Done Interrupt Enable. This bit enables the interrupt of Frame Buffer2 DMA transfer done.
        unsigned STATFF_INTEN : 1; //!< [21] STATFIFO Full Interrupt Enable. This bit enables the STAT FIFO interrupt.
        unsigned SFF_DMA_DONE_INTEN : 1; //!< [22] STATFIFO DMA Transfer Done Interrupt Enable. This bit enables the interrupt of STATFIFO DMA transfer done.
        unsigned RESERVED0 : 1; //!< [23] Reserved. This bit is reserved and should read 0.
        unsigned RF_OR_INTEN : 1; //!< [24] RxFIFO Overrun Interrupt Enable. This bit enables the RX FIFO overrun interrupt.
        unsigned SF_OR_INTEN : 1; //!< [25] STAT FIFO Overrun Interrupt Enable. This bit enables the STATFIFO overrun interrupt.
        unsigned COF_INT_EN : 1; //!< [26] Change Of Image Field (COF) Interrupt Enable. This bit enables the COF interrupt. This bit works only in CCIR interlace mode which is when CCIR_EN = 1 and CCIR_MODE = 1.
        unsigned CCIR_MODE : 1; //!< [27] CCIR Mode Select. This bit controls the CCIR mode of operation. This bit only works in CCIR interface mode.
        unsigned PRP_IF_EN : 1; //!< [28] CSI-PrP Interface Enable. This bit controls the CSI to PrP bus. When enabled the RxFIFO is detached from the AHB bus and connected to PrP. All CPU reads or DMA accesses to the RxFIFO register are ignored. All CSI interrupts are also masked.
        unsigned EOF_INT_EN : 1; //!< [29] End-of-Frame Interrupt Enable. This bit enables and disables the EOF interrupt.
        unsigned EXT_VSYNC : 1; //!< [30] External VSYNC Enable. This bit controls the operational VSYNC mode. This only works when the CSI is in CCIR progressive mode.
        unsigned SWAP16_EN : 1; //!< [31] SWAP 16-Bit Enable. This bit enables the swapping of 16-bit data. Data is packed from 8-bit or 10-bit to 32-bit first (according to the setting of PACK_DIR) and then swapped as 16-bit words before being put into the RX FIFO. The action of the bit only affects the RX FIFO and has no affect on the STAT FIFO. Example of swapping enabled: Data input to FIFO = 0x11223344 Data in RX FIFO = 0x 33441122 Example of swapping disabled: Data input to FIFO = 0x11223344 Data in RX FIFO = 0x11223344
    } B;
} hw_csi_csicr1_t;
#endif

/*
 * constants & macros for entire CSI_CSICR1 register
 */
#define HW_CSI_CSICR1_ADDR      (REGS_CSI_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSICR1           (*(volatile hw_csi_csicr1_t *) HW_CSI_CSICR1_ADDR)
#define HW_CSI_CSICR1_RD()      (HW_CSI_CSICR1.U)
#define HW_CSI_CSICR1_WR(v)     (HW_CSI_CSICR1.U = (v))
#define HW_CSI_CSICR1_SET(v)    (HW_CSI_CSICR1_WR(HW_CSI_CSICR1_RD() |  (v)))
#define HW_CSI_CSICR1_CLR(v)    (HW_CSI_CSICR1_WR(HW_CSI_CSICR1_RD() & ~(v)))
#define HW_CSI_CSICR1_TOG(v)    (HW_CSI_CSICR1_WR(HW_CSI_CSICR1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSICR1 bitfields
 */

/* --- Register HW_CSI_CSICR1, field PIXEL_BIT[0] (RW)
 *
 * Pixel Bit. This bit indicates the bayer data width for each pixel. This bit should be configured
 * before activating or re-starting the embedded DMA controller.
 *
 * Values:
 * 0 - 8-bit data for each pixel
 * 1 - 10-bit data for each pixel
 */

#define BP_CSI_CSICR1_PIXEL_BIT      (0)      //!< Bit position for CSI_CSICR1_PIXEL_BIT.
#define BM_CSI_CSICR1_PIXEL_BIT      (0x00000001)  //!< Bit mask for CSI_CSICR1_PIXEL_BIT.

//! @brief Get value of CSI_CSICR1_PIXEL_BIT from a register value.
#define BG_CSI_CSICR1_PIXEL_BIT(r)   (((r) & BM_CSI_CSICR1_PIXEL_BIT) >> BP_CSI_CSICR1_PIXEL_BIT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_PIXEL_BIT.
#define BF_CSI_CSICR1_PIXEL_BIT(v)   ((((reg32_t) v) << BP_CSI_CSICR1_PIXEL_BIT) & BM_CSI_CSICR1_PIXEL_BIT)
#else
//! @brief Format value for bitfield CSI_CSICR1_PIXEL_BIT.
#define BF_CSI_CSICR1_PIXEL_BIT(v)   (((v) << BP_CSI_CSICR1_PIXEL_BIT) & BM_CSI_CSICR1_PIXEL_BIT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PIXEL_BIT field to a new value.
#define BW_CSI_CSICR1_PIXEL_BIT(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_PIXEL_BIT) | BF_CSI_CSICR1_PIXEL_BIT(v)))
#endif


/* --- Register HW_CSI_CSICR1, field REDGE[1] (RW)
 *
 * Valid Pixel Clock Edge Select. Selects which edge of the CSI_PIXCLK is used to latch the pixel
 * data.
 *
 * Values:
 * 0 - Pixel data is latched at the falling edge of CSI_PIXCLK
 * 1 - Pixel data is latched at the rising edge of CSI_PIXCLK
 */

#define BP_CSI_CSICR1_REDGE      (1)      //!< Bit position for CSI_CSICR1_REDGE.
#define BM_CSI_CSICR1_REDGE      (0x00000002)  //!< Bit mask for CSI_CSICR1_REDGE.

//! @brief Get value of CSI_CSICR1_REDGE from a register value.
#define BG_CSI_CSICR1_REDGE(r)   (((r) & BM_CSI_CSICR1_REDGE) >> BP_CSI_CSICR1_REDGE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_REDGE.
#define BF_CSI_CSICR1_REDGE(v)   ((((reg32_t) v) << BP_CSI_CSICR1_REDGE) & BM_CSI_CSICR1_REDGE)
#else
//! @brief Format value for bitfield CSI_CSICR1_REDGE.
#define BF_CSI_CSICR1_REDGE(v)   (((v) << BP_CSI_CSICR1_REDGE) & BM_CSI_CSICR1_REDGE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the REDGE field to a new value.
#define BW_CSI_CSICR1_REDGE(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_REDGE) | BF_CSI_CSICR1_REDGE(v)))
#endif


/* --- Register HW_CSI_CSICR1, field INV_PCLK[2] (RW)
 *
 * Invert Pixel Clock Input. This bit determines if the Pixel Clock (CSI_PIXCLK) is inverted before
 * it is applied to the CSI module.
 *
 * Values:
 * 0 - CSI_PIXCLK is directly applied to internal circuitry
 * 1 - CSI_PIXCLK is inverted before applied to internal circuitry
 */

#define BP_CSI_CSICR1_INV_PCLK      (2)      //!< Bit position for CSI_CSICR1_INV_PCLK.
#define BM_CSI_CSICR1_INV_PCLK      (0x00000004)  //!< Bit mask for CSI_CSICR1_INV_PCLK.

//! @brief Get value of CSI_CSICR1_INV_PCLK from a register value.
#define BG_CSI_CSICR1_INV_PCLK(r)   (((r) & BM_CSI_CSICR1_INV_PCLK) >> BP_CSI_CSICR1_INV_PCLK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_INV_PCLK.
#define BF_CSI_CSICR1_INV_PCLK(v)   ((((reg32_t) v) << BP_CSI_CSICR1_INV_PCLK) & BM_CSI_CSICR1_INV_PCLK)
#else
//! @brief Format value for bitfield CSI_CSICR1_INV_PCLK.
#define BF_CSI_CSICR1_INV_PCLK(v)   (((v) << BP_CSI_CSICR1_INV_PCLK) & BM_CSI_CSICR1_INV_PCLK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INV_PCLK field to a new value.
#define BW_CSI_CSICR1_INV_PCLK(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_INV_PCLK) | BF_CSI_CSICR1_INV_PCLK(v)))
#endif


/* --- Register HW_CSI_CSICR1, field INV_DATA[3] (RW)
 *
 * Invert Data Input. This bit enables or disables internal inverters on the data lines.
 *
 * Values:
 * 0 - CSI_D[7:0] data lines are directly applied to internal circuitry
 * 1 - CSI_D[7:0] data lines are inverted before applied to internal circuitry
 */

#define BP_CSI_CSICR1_INV_DATA      (3)      //!< Bit position for CSI_CSICR1_INV_DATA.
#define BM_CSI_CSICR1_INV_DATA      (0x00000008)  //!< Bit mask for CSI_CSICR1_INV_DATA.

//! @brief Get value of CSI_CSICR1_INV_DATA from a register value.
#define BG_CSI_CSICR1_INV_DATA(r)   (((r) & BM_CSI_CSICR1_INV_DATA) >> BP_CSI_CSICR1_INV_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_INV_DATA.
#define BF_CSI_CSICR1_INV_DATA(v)   ((((reg32_t) v) << BP_CSI_CSICR1_INV_DATA) & BM_CSI_CSICR1_INV_DATA)
#else
//! @brief Format value for bitfield CSI_CSICR1_INV_DATA.
#define BF_CSI_CSICR1_INV_DATA(v)   (((v) << BP_CSI_CSICR1_INV_DATA) & BM_CSI_CSICR1_INV_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INV_DATA field to a new value.
#define BW_CSI_CSICR1_INV_DATA(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_INV_DATA) | BF_CSI_CSICR1_INV_DATA(v)))
#endif


/* --- Register HW_CSI_CSICR1, field GCLK_MODE[4] (RW)
 *
 * Gated Clock Mode Enable. Controls if CSI is working in gated or non-gated mode. This bit works
 * only in traditional mode-that is, CCIR_EN = 0. Otherwise this bit is ignored.
 *
 * Values:
 * 0 - Non-gated clock mode. All incoming pixel clocks are valid. HSYNC is ignored.
 * 1 - Gated clock mode. Pixel clock signal is valid only when HSYNC is active.
 */

#define BP_CSI_CSICR1_GCLK_MODE      (4)      //!< Bit position for CSI_CSICR1_GCLK_MODE.
#define BM_CSI_CSICR1_GCLK_MODE      (0x00000010)  //!< Bit mask for CSI_CSICR1_GCLK_MODE.

//! @brief Get value of CSI_CSICR1_GCLK_MODE from a register value.
#define BG_CSI_CSICR1_GCLK_MODE(r)   (((r) & BM_CSI_CSICR1_GCLK_MODE) >> BP_CSI_CSICR1_GCLK_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_GCLK_MODE.
#define BF_CSI_CSICR1_GCLK_MODE(v)   ((((reg32_t) v) << BP_CSI_CSICR1_GCLK_MODE) & BM_CSI_CSICR1_GCLK_MODE)
#else
//! @brief Format value for bitfield CSI_CSICR1_GCLK_MODE.
#define BF_CSI_CSICR1_GCLK_MODE(v)   (((v) << BP_CSI_CSICR1_GCLK_MODE) & BM_CSI_CSICR1_GCLK_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GCLK_MODE field to a new value.
#define BW_CSI_CSICR1_GCLK_MODE(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_GCLK_MODE) | BF_CSI_CSICR1_GCLK_MODE(v)))
#endif


/* --- Register HW_CSI_CSICR1, field CLR_RXFIFO[5] (RW)
 *
 * Asynchronous RXFIFO Clear. This bit clears the RXFIFO. This bit works only in async FIFO clear
 * mode-that is, FCC = 0. Otherwise this bit is ignored. Writing 1 clears the RXFIFO immediately,
 * RXFIFO restarts immediately after that. The bit is restored to 0 automatically after finish.
 * Normally reads 0.
 */

#define BP_CSI_CSICR1_CLR_RXFIFO      (5)      //!< Bit position for CSI_CSICR1_CLR_RXFIFO.
#define BM_CSI_CSICR1_CLR_RXFIFO      (0x00000020)  //!< Bit mask for CSI_CSICR1_CLR_RXFIFO.

//! @brief Get value of CSI_CSICR1_CLR_RXFIFO from a register value.
#define BG_CSI_CSICR1_CLR_RXFIFO(r)   (((r) & BM_CSI_CSICR1_CLR_RXFIFO) >> BP_CSI_CSICR1_CLR_RXFIFO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_CLR_RXFIFO.
#define BF_CSI_CSICR1_CLR_RXFIFO(v)   ((((reg32_t) v) << BP_CSI_CSICR1_CLR_RXFIFO) & BM_CSI_CSICR1_CLR_RXFIFO)
#else
//! @brief Format value for bitfield CSI_CSICR1_CLR_RXFIFO.
#define BF_CSI_CSICR1_CLR_RXFIFO(v)   (((v) << BP_CSI_CSICR1_CLR_RXFIFO) & BM_CSI_CSICR1_CLR_RXFIFO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_RXFIFO field to a new value.
#define BW_CSI_CSICR1_CLR_RXFIFO(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_CLR_RXFIFO) | BF_CSI_CSICR1_CLR_RXFIFO(v)))
#endif

/* --- Register HW_CSI_CSICR1, field CLR_STATFIFO[6] (RW)
 *
 * Asynchronous STATFIFO Clear. This bit clears the STATFIFO and Reset STAT block. This bit works
 * only in async FIFO clear mode-that is, FCC = 0. Otherwise this bit is ignored. Writing 1 will
 * clear STATFIFO and reset STAT block immediately, STATFIFO and STAT block then wait and restart
 * after the arrival of next SOF. The bit is restored to 0 automatically after finish. Normally
 * reads 0.
 */

#define BP_CSI_CSICR1_CLR_STATFIFO      (6)      //!< Bit position for CSI_CSICR1_CLR_STATFIFO.
#define BM_CSI_CSICR1_CLR_STATFIFO      (0x00000040)  //!< Bit mask for CSI_CSICR1_CLR_STATFIFO.

//! @brief Get value of CSI_CSICR1_CLR_STATFIFO from a register value.
#define BG_CSI_CSICR1_CLR_STATFIFO(r)   (((r) & BM_CSI_CSICR1_CLR_STATFIFO) >> BP_CSI_CSICR1_CLR_STATFIFO)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_CLR_STATFIFO.
#define BF_CSI_CSICR1_CLR_STATFIFO(v)   ((((reg32_t) v) << BP_CSI_CSICR1_CLR_STATFIFO) & BM_CSI_CSICR1_CLR_STATFIFO)
#else
//! @brief Format value for bitfield CSI_CSICR1_CLR_STATFIFO.
#define BF_CSI_CSICR1_CLR_STATFIFO(v)   (((v) << BP_CSI_CSICR1_CLR_STATFIFO) & BM_CSI_CSICR1_CLR_STATFIFO)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CLR_STATFIFO field to a new value.
#define BW_CSI_CSICR1_CLR_STATFIFO(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_CLR_STATFIFO) | BF_CSI_CSICR1_CLR_STATFIFO(v)))
#endif

/* --- Register HW_CSI_CSICR1, field PACK_DIR[7] (RW)
 *
 * Data Packing Direction. This bit Controls how 8-bit/10-bit image data is packed into 32-bit RX
 * FIFO, and how 16-bit statistical data is packed into 32-bit STAT FIFO.
 *
 * Values:
 * 0 - Pack from LSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x44332211 in RX
 *     FIFO. For stat data, 0xAAAA, 0xBBBB, it will appear as 0xBBBBAAAA in STAT FIFO.
 * 1 - Pack from MSB first. For image data, 0x11, 0x22, 0x33, 0x44, it will appear as 0x11223344 in RX
 *     FIFO. For stat data, 0xAAAA, 0xBBBB, it will appear as 0xAAAABBBB in STAT FIFO.
 */

#define BP_CSI_CSICR1_PACK_DIR      (7)      //!< Bit position for CSI_CSICR1_PACK_DIR.
#define BM_CSI_CSICR1_PACK_DIR      (0x00000080)  //!< Bit mask for CSI_CSICR1_PACK_DIR.

//! @brief Get value of CSI_CSICR1_PACK_DIR from a register value.
#define BG_CSI_CSICR1_PACK_DIR(r)   (((r) & BM_CSI_CSICR1_PACK_DIR) >> BP_CSI_CSICR1_PACK_DIR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_PACK_DIR.
#define BF_CSI_CSICR1_PACK_DIR(v)   ((((reg32_t) v) << BP_CSI_CSICR1_PACK_DIR) & BM_CSI_CSICR1_PACK_DIR)
#else
//! @brief Format value for bitfield CSI_CSICR1_PACK_DIR.
#define BF_CSI_CSICR1_PACK_DIR(v)   (((v) << BP_CSI_CSICR1_PACK_DIR) & BM_CSI_CSICR1_PACK_DIR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PACK_DIR field to a new value.
#define BW_CSI_CSICR1_PACK_DIR(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_PACK_DIR) | BF_CSI_CSICR1_PACK_DIR(v)))
#endif


/* --- Register HW_CSI_CSICR1, field FCC[8] (RW)
 *
 * FIFO Clear Control. This bit determines how the RXFIFO and STATFIFO are cleared. When Synchronous
 * FIFO clear is selected the RXFIFO and STATFIFO are cleared, and STAT block is reset, on every
 * SOF. FIFOs and STAT block restarts immediately after reset. For information on the operation when
 * Asynchronous FIFO clear is selected, refer to the descriptions for the CLR_RXFIFO and
 * CLR_STATFIFO bits.
 *
 * Values:
 * 0 - Asynchronous FIFO clear is selected.
 * 1 - Synchronous FIFO clear is selected.
 */

#define BP_CSI_CSICR1_FCC      (8)      //!< Bit position for CSI_CSICR1_FCC.
#define BM_CSI_CSICR1_FCC      (0x00000100)  //!< Bit mask for CSI_CSICR1_FCC.

//! @brief Get value of CSI_CSICR1_FCC from a register value.
#define BG_CSI_CSICR1_FCC(r)   (((r) & BM_CSI_CSICR1_FCC) >> BP_CSI_CSICR1_FCC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_FCC.
#define BF_CSI_CSICR1_FCC(v)   ((((reg32_t) v) << BP_CSI_CSICR1_FCC) & BM_CSI_CSICR1_FCC)
#else
//! @brief Format value for bitfield CSI_CSICR1_FCC.
#define BF_CSI_CSICR1_FCC(v)   (((v) << BP_CSI_CSICR1_FCC) & BM_CSI_CSICR1_FCC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FCC field to a new value.
#define BW_CSI_CSICR1_FCC(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_FCC) | BF_CSI_CSICR1_FCC(v)))
#endif


/* --- Register HW_CSI_CSICR1, field MCLKEN[9] (RW)
 *
 * Sensor Master Clock (MCLK) Enable. This bit enables or disables the MCLK input to the sensor.
 *
 * Values:
 * 0 - MCLK disable
 * 1 - MCLK enable
 */

#define BP_CSI_CSICR1_MCLKEN      (9)      //!< Bit position for CSI_CSICR1_MCLKEN.
#define BM_CSI_CSICR1_MCLKEN      (0x00000200)  //!< Bit mask for CSI_CSICR1_MCLKEN.

//! @brief Get value of CSI_CSICR1_MCLKEN from a register value.
#define BG_CSI_CSICR1_MCLKEN(r)   (((r) & BM_CSI_CSICR1_MCLKEN) >> BP_CSI_CSICR1_MCLKEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_MCLKEN.
#define BF_CSI_CSICR1_MCLKEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_MCLKEN) & BM_CSI_CSICR1_MCLKEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_MCLKEN.
#define BF_CSI_CSICR1_MCLKEN(v)   (((v) << BP_CSI_CSICR1_MCLKEN) & BM_CSI_CSICR1_MCLKEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MCLKEN field to a new value.
#define BW_CSI_CSICR1_MCLKEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_MCLKEN) | BF_CSI_CSICR1_MCLKEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field CCIR_EN[10] (RW)
 *
 * CCIR656 Interface Enable. This bit selects the type of interface used. When the CCIR656 timing
 * decoder is enabled, it replaces the function of timing interface logic.
 *
 * Values:
 * 0 - Traditional interface is selected. Timing interface logic is used to latch data.
 * 1 - CCIR656 interface is selected.
 */

#define BP_CSI_CSICR1_CCIR_EN      (10)      //!< Bit position for CSI_CSICR1_CCIR_EN.
#define BM_CSI_CSICR1_CCIR_EN      (0x00000400)  //!< Bit mask for CSI_CSICR1_CCIR_EN.

//! @brief Get value of CSI_CSICR1_CCIR_EN from a register value.
#define BG_CSI_CSICR1_CCIR_EN(r)   (((r) & BM_CSI_CSICR1_CCIR_EN) >> BP_CSI_CSICR1_CCIR_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_CCIR_EN.
#define BF_CSI_CSICR1_CCIR_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_CCIR_EN) & BM_CSI_CSICR1_CCIR_EN)
#else
//! @brief Format value for bitfield CSI_CSICR1_CCIR_EN.
#define BF_CSI_CSICR1_CCIR_EN(v)   (((v) << BP_CSI_CSICR1_CCIR_EN) & BM_CSI_CSICR1_CCIR_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CCIR_EN field to a new value.
#define BW_CSI_CSICR1_CCIR_EN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_CCIR_EN) | BF_CSI_CSICR1_CCIR_EN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field HSYNC_POL[11] (RW)
 *
 * HSYNC Polarity Select. This bit controls the polarity of HSYNC. This bit only works in gated-
 * clock-that is, GCLK_MODE = 1 and CCIR_EN = 0.
 *
 * Values:
 * 0 - HSYNC is active low
 * 1 - HSYNC is active high
 */

#define BP_CSI_CSICR1_HSYNC_POL      (11)      //!< Bit position for CSI_CSICR1_HSYNC_POL.
#define BM_CSI_CSICR1_HSYNC_POL      (0x00000800)  //!< Bit mask for CSI_CSICR1_HSYNC_POL.

//! @brief Get value of CSI_CSICR1_HSYNC_POL from a register value.
#define BG_CSI_CSICR1_HSYNC_POL(r)   (((r) & BM_CSI_CSICR1_HSYNC_POL) >> BP_CSI_CSICR1_HSYNC_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_HSYNC_POL.
#define BF_CSI_CSICR1_HSYNC_POL(v)   ((((reg32_t) v) << BP_CSI_CSICR1_HSYNC_POL) & BM_CSI_CSICR1_HSYNC_POL)
#else
//! @brief Format value for bitfield CSI_CSICR1_HSYNC_POL.
#define BF_CSI_CSICR1_HSYNC_POL(v)   (((v) << BP_CSI_CSICR1_HSYNC_POL) & BM_CSI_CSICR1_HSYNC_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSYNC_POL field to a new value.
#define BW_CSI_CSICR1_HSYNC_POL(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_HSYNC_POL) | BF_CSI_CSICR1_HSYNC_POL(v)))
#endif


/* --- Register HW_CSI_CSICR1, field MCLKDIV[15:12] (RW)
 *
 * Sensor Master Clock (MCLK) Divider. This field contains the divisor MCLK. The MCLK is derived
 * from the PERCLK.
 *
 * Values:
 * 0000 - Divided by 1
 * 0001 - Divided by 2
 * 0010 - Divided by 4
 * 0011 - Divided by 6
 * 0100 - Divided by 8
 * 0101 - Divided by 10
 * 0110 - Divided by 12
 * 0111 - Divided by 14
 * 1000 - Divided by 16
 * 1001 - Divided by 18
 * 1010 - Divided by 20
 * 1011 - Divided by 22
 * 1100 - Divided by 24
 * 1101 - Divided by 26
 * 1110 - Divided by 28
 * 1111 - Divided by 30
 */

#define BP_CSI_CSICR1_MCLKDIV      (12)      //!< Bit position for CSI_CSICR1_MCLKDIV.
#define BM_CSI_CSICR1_MCLKDIV      (0x0000f000)  //!< Bit mask for CSI_CSICR1_MCLKDIV.

//! @brief Get value of CSI_CSICR1_MCLKDIV from a register value.
#define BG_CSI_CSICR1_MCLKDIV(r)   (((r) & BM_CSI_CSICR1_MCLKDIV) >> BP_CSI_CSICR1_MCLKDIV)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_MCLKDIV.
#define BF_CSI_CSICR1_MCLKDIV(v)   ((((reg32_t) v) << BP_CSI_CSICR1_MCLKDIV) & BM_CSI_CSICR1_MCLKDIV)
#else
//! @brief Format value for bitfield CSI_CSICR1_MCLKDIV.
#define BF_CSI_CSICR1_MCLKDIV(v)   (((v) << BP_CSI_CSICR1_MCLKDIV) & BM_CSI_CSICR1_MCLKDIV)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MCLKDIV field to a new value.
#define BW_CSI_CSICR1_MCLKDIV(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_MCLKDIV) | BF_CSI_CSICR1_MCLKDIV(v)))
#endif


/* --- Register HW_CSI_CSICR1, field SOF_INTEN[16] (RW)
 *
 * Start Of Frame (SOF) Interrupt Enable. This bit enables the SOF interrupt.
 *
 * Values:
 * 0 - SOF interrupt disable
 * 1 - SOF interrupt enable
 */

#define BP_CSI_CSICR1_SOF_INTEN      (16)      //!< Bit position for CSI_CSICR1_SOF_INTEN.
#define BM_CSI_CSICR1_SOF_INTEN      (0x00010000)  //!< Bit mask for CSI_CSICR1_SOF_INTEN.

//! @brief Get value of CSI_CSICR1_SOF_INTEN from a register value.
#define BG_CSI_CSICR1_SOF_INTEN(r)   (((r) & BM_CSI_CSICR1_SOF_INTEN) >> BP_CSI_CSICR1_SOF_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_SOF_INTEN.
#define BF_CSI_CSICR1_SOF_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_SOF_INTEN) & BM_CSI_CSICR1_SOF_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_SOF_INTEN.
#define BF_CSI_CSICR1_SOF_INTEN(v)   (((v) << BP_CSI_CSICR1_SOF_INTEN) & BM_CSI_CSICR1_SOF_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOF_INTEN field to a new value.
#define BW_CSI_CSICR1_SOF_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_SOF_INTEN) | BF_CSI_CSICR1_SOF_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field SOF_POL[17] (RW)
 *
 * SOF Interrupt Polarity. This bit controls the condition that generates an SOF interrupt.
 *
 * Values:
 * 0 - SOF interrupt is generated on SOF falling edge
 * 1 - SOF interrupt is generated on SOF rising edge
 */

#define BP_CSI_CSICR1_SOF_POL      (17)      //!< Bit position for CSI_CSICR1_SOF_POL.
#define BM_CSI_CSICR1_SOF_POL      (0x00020000)  //!< Bit mask for CSI_CSICR1_SOF_POL.

//! @brief Get value of CSI_CSICR1_SOF_POL from a register value.
#define BG_CSI_CSICR1_SOF_POL(r)   (((r) & BM_CSI_CSICR1_SOF_POL) >> BP_CSI_CSICR1_SOF_POL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_SOF_POL.
#define BF_CSI_CSICR1_SOF_POL(v)   ((((reg32_t) v) << BP_CSI_CSICR1_SOF_POL) & BM_CSI_CSICR1_SOF_POL)
#else
//! @brief Format value for bitfield CSI_CSICR1_SOF_POL.
#define BF_CSI_CSICR1_SOF_POL(v)   (((v) << BP_CSI_CSICR1_SOF_POL) & BM_CSI_CSICR1_SOF_POL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOF_POL field to a new value.
#define BW_CSI_CSICR1_SOF_POL(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_SOF_POL) | BF_CSI_CSICR1_SOF_POL(v)))
#endif


/* --- Register HW_CSI_CSICR1, field RXFF_INTEN[18] (RW)
 *
 * RxFIFO Full Interrupt Enable. This bit enables the RxFIFO full interrupt.
 *
 * Values:
 * 0 - RxFIFO full interrupt disable
 * 1 - RxFIFO full interrupt enable
 */

#define BP_CSI_CSICR1_RXFF_INTEN      (18)      //!< Bit position for CSI_CSICR1_RXFF_INTEN.
#define BM_CSI_CSICR1_RXFF_INTEN      (0x00040000)  //!< Bit mask for CSI_CSICR1_RXFF_INTEN.

//! @brief Get value of CSI_CSICR1_RXFF_INTEN from a register value.
#define BG_CSI_CSICR1_RXFF_INTEN(r)   (((r) & BM_CSI_CSICR1_RXFF_INTEN) >> BP_CSI_CSICR1_RXFF_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_RXFF_INTEN.
#define BF_CSI_CSICR1_RXFF_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_RXFF_INTEN) & BM_CSI_CSICR1_RXFF_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_RXFF_INTEN.
#define BF_CSI_CSICR1_RXFF_INTEN(v)   (((v) << BP_CSI_CSICR1_RXFF_INTEN) & BM_CSI_CSICR1_RXFF_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFF_INTEN field to a new value.
#define BW_CSI_CSICR1_RXFF_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_RXFF_INTEN) | BF_CSI_CSICR1_RXFF_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field FB1_DMA_DONE_INTEN[19] (RW)
 *
 * Frame Buffer1 DMA Transfer Done Interrupt Enable. This bit enables the interrupt of Frame Buffer1
 * DMA transfer done.
 *
 * Values:
 * 0 - Frame Buffer1 DMA Transfer Done interrupt disable
 * 1 - Frame Buffer1 DMA Transfer Done interrupt enable
 */

#define BP_CSI_CSICR1_FB1_DMA_DONE_INTEN      (19)      //!< Bit position for CSI_CSICR1_FB1_DMA_DONE_INTEN.
#define BM_CSI_CSICR1_FB1_DMA_DONE_INTEN      (0x00080000)  //!< Bit mask for CSI_CSICR1_FB1_DMA_DONE_INTEN.

//! @brief Get value of CSI_CSICR1_FB1_DMA_DONE_INTEN from a register value.
#define BG_CSI_CSICR1_FB1_DMA_DONE_INTEN(r)   (((r) & BM_CSI_CSICR1_FB1_DMA_DONE_INTEN) >> BP_CSI_CSICR1_FB1_DMA_DONE_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_FB1_DMA_DONE_INTEN.
#define BF_CSI_CSICR1_FB1_DMA_DONE_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_FB1_DMA_DONE_INTEN) & BM_CSI_CSICR1_FB1_DMA_DONE_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_FB1_DMA_DONE_INTEN.
#define BF_CSI_CSICR1_FB1_DMA_DONE_INTEN(v)   (((v) << BP_CSI_CSICR1_FB1_DMA_DONE_INTEN) & BM_CSI_CSICR1_FB1_DMA_DONE_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FB1_DMA_DONE_INTEN field to a new value.
#define BW_CSI_CSICR1_FB1_DMA_DONE_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_FB1_DMA_DONE_INTEN) | BF_CSI_CSICR1_FB1_DMA_DONE_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field FB2_DMA_DONE_INTEN[20] (RW)
 *
 * Frame Buffer2 DMA Transfer Done Interrupt Enable. This bit enables the interrupt of Frame Buffer2
 * DMA transfer done.
 *
 * Values:
 * 0 - Frame Buffer2 DMA Transfer Done interrupt disable
 * 1 - Frame Buffer2 DMA Transfer Done interrupt enable
 */

#define BP_CSI_CSICR1_FB2_DMA_DONE_INTEN      (20)      //!< Bit position for CSI_CSICR1_FB2_DMA_DONE_INTEN.
#define BM_CSI_CSICR1_FB2_DMA_DONE_INTEN      (0x00100000)  //!< Bit mask for CSI_CSICR1_FB2_DMA_DONE_INTEN.

//! @brief Get value of CSI_CSICR1_FB2_DMA_DONE_INTEN from a register value.
#define BG_CSI_CSICR1_FB2_DMA_DONE_INTEN(r)   (((r) & BM_CSI_CSICR1_FB2_DMA_DONE_INTEN) >> BP_CSI_CSICR1_FB2_DMA_DONE_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_FB2_DMA_DONE_INTEN.
#define BF_CSI_CSICR1_FB2_DMA_DONE_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_FB2_DMA_DONE_INTEN) & BM_CSI_CSICR1_FB2_DMA_DONE_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_FB2_DMA_DONE_INTEN.
#define BF_CSI_CSICR1_FB2_DMA_DONE_INTEN(v)   (((v) << BP_CSI_CSICR1_FB2_DMA_DONE_INTEN) & BM_CSI_CSICR1_FB2_DMA_DONE_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FB2_DMA_DONE_INTEN field to a new value.
#define BW_CSI_CSICR1_FB2_DMA_DONE_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_FB2_DMA_DONE_INTEN) | BF_CSI_CSICR1_FB2_DMA_DONE_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field STATFF_INTEN[21] (RW)
 *
 * STATFIFO Full Interrupt Enable. This bit enables the STAT FIFO interrupt.
 *
 * Values:
 * 0 - STATFIFO full interrupt disable
 * 1 - STATFIFO full interrupt enable
 */

#define BP_CSI_CSICR1_STATFF_INTEN      (21)      //!< Bit position for CSI_CSICR1_STATFF_INTEN.
#define BM_CSI_CSICR1_STATFF_INTEN      (0x00200000)  //!< Bit mask for CSI_CSICR1_STATFF_INTEN.

//! @brief Get value of CSI_CSICR1_STATFF_INTEN from a register value.
#define BG_CSI_CSICR1_STATFF_INTEN(r)   (((r) & BM_CSI_CSICR1_STATFF_INTEN) >> BP_CSI_CSICR1_STATFF_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_STATFF_INTEN.
#define BF_CSI_CSICR1_STATFF_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_STATFF_INTEN) & BM_CSI_CSICR1_STATFF_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_STATFF_INTEN.
#define BF_CSI_CSICR1_STATFF_INTEN(v)   (((v) << BP_CSI_CSICR1_STATFF_INTEN) & BM_CSI_CSICR1_STATFF_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATFF_INTEN field to a new value.
#define BW_CSI_CSICR1_STATFF_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_STATFF_INTEN) | BF_CSI_CSICR1_STATFF_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field SFF_DMA_DONE_INTEN[22] (RW)
 *
 * STATFIFO DMA Transfer Done Interrupt Enable. This bit enables the interrupt of STATFIFO DMA
 * transfer done.
 *
 * Values:
 * 0 - STATFIFO DMA Transfer Done interrupt disable
 * 1 - STATFIFO DMA Transfer Done interrupt enable
 */

#define BP_CSI_CSICR1_SFF_DMA_DONE_INTEN      (22)      //!< Bit position for CSI_CSICR1_SFF_DMA_DONE_INTEN.
#define BM_CSI_CSICR1_SFF_DMA_DONE_INTEN      (0x00400000)  //!< Bit mask for CSI_CSICR1_SFF_DMA_DONE_INTEN.

//! @brief Get value of CSI_CSICR1_SFF_DMA_DONE_INTEN from a register value.
#define BG_CSI_CSICR1_SFF_DMA_DONE_INTEN(r)   (((r) & BM_CSI_CSICR1_SFF_DMA_DONE_INTEN) >> BP_CSI_CSICR1_SFF_DMA_DONE_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_SFF_DMA_DONE_INTEN.
#define BF_CSI_CSICR1_SFF_DMA_DONE_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_SFF_DMA_DONE_INTEN) & BM_CSI_CSICR1_SFF_DMA_DONE_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_SFF_DMA_DONE_INTEN.
#define BF_CSI_CSICR1_SFF_DMA_DONE_INTEN(v)   (((v) << BP_CSI_CSICR1_SFF_DMA_DONE_INTEN) & BM_CSI_CSICR1_SFF_DMA_DONE_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SFF_DMA_DONE_INTEN field to a new value.
#define BW_CSI_CSICR1_SFF_DMA_DONE_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_SFF_DMA_DONE_INTEN) | BF_CSI_CSICR1_SFF_DMA_DONE_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field RF_OR_INTEN[24] (RW)
 *
 * RxFIFO Overrun Interrupt Enable. This bit enables the RX FIFO overrun interrupt.
 *
 * Values:
 * 0 - RxFIFO overrun interrupt is disabled
 * 1 - RxFIFO overrun interrupt is enabled
 */

#define BP_CSI_CSICR1_RF_OR_INTEN      (24)      //!< Bit position for CSI_CSICR1_RF_OR_INTEN.
#define BM_CSI_CSICR1_RF_OR_INTEN      (0x01000000)  //!< Bit mask for CSI_CSICR1_RF_OR_INTEN.

//! @brief Get value of CSI_CSICR1_RF_OR_INTEN from a register value.
#define BG_CSI_CSICR1_RF_OR_INTEN(r)   (((r) & BM_CSI_CSICR1_RF_OR_INTEN) >> BP_CSI_CSICR1_RF_OR_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_RF_OR_INTEN.
#define BF_CSI_CSICR1_RF_OR_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_RF_OR_INTEN) & BM_CSI_CSICR1_RF_OR_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_RF_OR_INTEN.
#define BF_CSI_CSICR1_RF_OR_INTEN(v)   (((v) << BP_CSI_CSICR1_RF_OR_INTEN) & BM_CSI_CSICR1_RF_OR_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RF_OR_INTEN field to a new value.
#define BW_CSI_CSICR1_RF_OR_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_RF_OR_INTEN) | BF_CSI_CSICR1_RF_OR_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field SF_OR_INTEN[25] (RW)
 *
 * STAT FIFO Overrun Interrupt Enable. This bit enables the STATFIFO overrun interrupt.
 *
 * Values:
 * 0 - STATFIFO overrun interrupt is disabled
 * 1 - STATFIFO overrun interrupt is enabled
 */

#define BP_CSI_CSICR1_SF_OR_INTEN      (25)      //!< Bit position for CSI_CSICR1_SF_OR_INTEN.
#define BM_CSI_CSICR1_SF_OR_INTEN      (0x02000000)  //!< Bit mask for CSI_CSICR1_SF_OR_INTEN.

//! @brief Get value of CSI_CSICR1_SF_OR_INTEN from a register value.
#define BG_CSI_CSICR1_SF_OR_INTEN(r)   (((r) & BM_CSI_CSICR1_SF_OR_INTEN) >> BP_CSI_CSICR1_SF_OR_INTEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_SF_OR_INTEN.
#define BF_CSI_CSICR1_SF_OR_INTEN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_SF_OR_INTEN) & BM_CSI_CSICR1_SF_OR_INTEN)
#else
//! @brief Format value for bitfield CSI_CSICR1_SF_OR_INTEN.
#define BF_CSI_CSICR1_SF_OR_INTEN(v)   (((v) << BP_CSI_CSICR1_SF_OR_INTEN) & BM_CSI_CSICR1_SF_OR_INTEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SF_OR_INTEN field to a new value.
#define BW_CSI_CSICR1_SF_OR_INTEN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_SF_OR_INTEN) | BF_CSI_CSICR1_SF_OR_INTEN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field COF_INT_EN[26] (RW)
 *
 * Change Of Image Field (COF) Interrupt Enable. This bit enables the COF interrupt. This bit works
 * only in CCIR interlace mode which is when CCIR_EN = 1 and CCIR_MODE = 1.
 *
 * Values:
 * 0 - COF interrupt is disabled
 * 1 - COF interrupt is enabled
 */

#define BP_CSI_CSICR1_COF_INT_EN      (26)      //!< Bit position for CSI_CSICR1_COF_INT_EN.
#define BM_CSI_CSICR1_COF_INT_EN      (0x04000000)  //!< Bit mask for CSI_CSICR1_COF_INT_EN.

//! @brief Get value of CSI_CSICR1_COF_INT_EN from a register value.
#define BG_CSI_CSICR1_COF_INT_EN(r)   (((r) & BM_CSI_CSICR1_COF_INT_EN) >> BP_CSI_CSICR1_COF_INT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_COF_INT_EN.
#define BF_CSI_CSICR1_COF_INT_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_COF_INT_EN) & BM_CSI_CSICR1_COF_INT_EN)
#else
//! @brief Format value for bitfield CSI_CSICR1_COF_INT_EN.
#define BF_CSI_CSICR1_COF_INT_EN(v)   (((v) << BP_CSI_CSICR1_COF_INT_EN) & BM_CSI_CSICR1_COF_INT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COF_INT_EN field to a new value.
#define BW_CSI_CSICR1_COF_INT_EN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_COF_INT_EN) | BF_CSI_CSICR1_COF_INT_EN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field CCIR_MODE[27] (RW)
 *
 * CCIR Mode Select. This bit controls the CCIR mode of operation. This bit only works in CCIR
 * interface mode.
 *
 * Values:
 * 0 - Progressive mode is selected
 * 1 - Interlace mode is selected
 */

#define BP_CSI_CSICR1_CCIR_MODE      (27)      //!< Bit position for CSI_CSICR1_CCIR_MODE.
#define BM_CSI_CSICR1_CCIR_MODE      (0x08000000)  //!< Bit mask for CSI_CSICR1_CCIR_MODE.

//! @brief Get value of CSI_CSICR1_CCIR_MODE from a register value.
#define BG_CSI_CSICR1_CCIR_MODE(r)   (((r) & BM_CSI_CSICR1_CCIR_MODE) >> BP_CSI_CSICR1_CCIR_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_CCIR_MODE.
#define BF_CSI_CSICR1_CCIR_MODE(v)   ((((reg32_t) v) << BP_CSI_CSICR1_CCIR_MODE) & BM_CSI_CSICR1_CCIR_MODE)
#else
//! @brief Format value for bitfield CSI_CSICR1_CCIR_MODE.
#define BF_CSI_CSICR1_CCIR_MODE(v)   (((v) << BP_CSI_CSICR1_CCIR_MODE) & BM_CSI_CSICR1_CCIR_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CCIR_MODE field to a new value.
#define BW_CSI_CSICR1_CCIR_MODE(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_CCIR_MODE) | BF_CSI_CSICR1_CCIR_MODE(v)))
#endif


/* --- Register HW_CSI_CSICR1, field PRP_IF_EN[28] (RW)
 *
 * CSI-PrP Interface Enable. This bit controls the CSI to PrP bus. When enabled the RxFIFO is
 * detached from the AHB bus and connected to PrP. All CPU reads or DMA accesses to the RxFIFO
 * register are ignored. All CSI interrupts are also masked.
 *
 * Values:
 * 0 - CSI to PrP bus is disabled
 * 1 - CSI to PrP bus is enabled
 */

#define BP_CSI_CSICR1_PRP_IF_EN      (28)      //!< Bit position for CSI_CSICR1_PRP_IF_EN.
#define BM_CSI_CSICR1_PRP_IF_EN      (0x10000000)  //!< Bit mask for CSI_CSICR1_PRP_IF_EN.

//! @brief Get value of CSI_CSICR1_PRP_IF_EN from a register value.
#define BG_CSI_CSICR1_PRP_IF_EN(r)   (((r) & BM_CSI_CSICR1_PRP_IF_EN) >> BP_CSI_CSICR1_PRP_IF_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_PRP_IF_EN.
#define BF_CSI_CSICR1_PRP_IF_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_PRP_IF_EN) & BM_CSI_CSICR1_PRP_IF_EN)
#else
//! @brief Format value for bitfield CSI_CSICR1_PRP_IF_EN.
#define BF_CSI_CSICR1_PRP_IF_EN(v)   (((v) << BP_CSI_CSICR1_PRP_IF_EN) & BM_CSI_CSICR1_PRP_IF_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRP_IF_EN field to a new value.
#define BW_CSI_CSICR1_PRP_IF_EN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_PRP_IF_EN) | BF_CSI_CSICR1_PRP_IF_EN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field EOF_INT_EN[29] (RW)
 *
 * End-of-Frame Interrupt Enable. This bit enables and disables the EOF interrupt.
 *
 * Values:
 * 0 - EOF interrupt is disabled.
 * 1 - EOF interrupt is generated when RX count value is reached.
 */

#define BP_CSI_CSICR1_EOF_INT_EN      (29)      //!< Bit position for CSI_CSICR1_EOF_INT_EN.
#define BM_CSI_CSICR1_EOF_INT_EN      (0x20000000)  //!< Bit mask for CSI_CSICR1_EOF_INT_EN.

//! @brief Get value of CSI_CSICR1_EOF_INT_EN from a register value.
#define BG_CSI_CSICR1_EOF_INT_EN(r)   (((r) & BM_CSI_CSICR1_EOF_INT_EN) >> BP_CSI_CSICR1_EOF_INT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_EOF_INT_EN.
#define BF_CSI_CSICR1_EOF_INT_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_EOF_INT_EN) & BM_CSI_CSICR1_EOF_INT_EN)
#else
//! @brief Format value for bitfield CSI_CSICR1_EOF_INT_EN.
#define BF_CSI_CSICR1_EOF_INT_EN(v)   (((v) << BP_CSI_CSICR1_EOF_INT_EN) & BM_CSI_CSICR1_EOF_INT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EOF_INT_EN field to a new value.
#define BW_CSI_CSICR1_EOF_INT_EN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_EOF_INT_EN) | BF_CSI_CSICR1_EOF_INT_EN(v)))
#endif


/* --- Register HW_CSI_CSICR1, field EXT_VSYNC[30] (RW)
 *
 * External VSYNC Enable. This bit controls the operational VSYNC mode. This only works when the CSI
 * is in CCIR progressive mode.
 *
 * Values:
 * 0 - Internal VSYNC mode
 * 1 - External VSYNC mode
 */

#define BP_CSI_CSICR1_EXT_VSYNC      (30)      //!< Bit position for CSI_CSICR1_EXT_VSYNC.
#define BM_CSI_CSICR1_EXT_VSYNC      (0x40000000)  //!< Bit mask for CSI_CSICR1_EXT_VSYNC.

//! @brief Get value of CSI_CSICR1_EXT_VSYNC from a register value.
#define BG_CSI_CSICR1_EXT_VSYNC(r)   (((r) & BM_CSI_CSICR1_EXT_VSYNC) >> BP_CSI_CSICR1_EXT_VSYNC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_EXT_VSYNC.
#define BF_CSI_CSICR1_EXT_VSYNC(v)   ((((reg32_t) v) << BP_CSI_CSICR1_EXT_VSYNC) & BM_CSI_CSICR1_EXT_VSYNC)
#else
//! @brief Format value for bitfield CSI_CSICR1_EXT_VSYNC.
#define BF_CSI_CSICR1_EXT_VSYNC(v)   (((v) << BP_CSI_CSICR1_EXT_VSYNC) & BM_CSI_CSICR1_EXT_VSYNC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EXT_VSYNC field to a new value.
#define BW_CSI_CSICR1_EXT_VSYNC(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_EXT_VSYNC) | BF_CSI_CSICR1_EXT_VSYNC(v)))
#endif


/* --- Register HW_CSI_CSICR1, field SWAP16_EN[31] (RW)
 *
 * SWAP 16-Bit Enable. This bit enables the swapping of 16-bit data. Data is packed from 8-bit or
 * 10-bit to 32-bit first (according to the setting of PACK_DIR) and then swapped as 16-bit words
 * before being put into the RX FIFO. The action of the bit only affects the RX FIFO and has no
 * affect on the STAT FIFO. Example of swapping enabled: Data input to FIFO = 0x11223344 Data in RX
 * FIFO = 0x 33441122 Example of swapping disabled: Data input to FIFO = 0x11223344 Data in RX FIFO
 * = 0x11223344
 *
 * Values:
 * 0 - Disable swapping
 * 1 - Enable swapping
 */

#define BP_CSI_CSICR1_SWAP16_EN      (31)      //!< Bit position for CSI_CSICR1_SWAP16_EN.
#define BM_CSI_CSICR1_SWAP16_EN      (0x80000000)  //!< Bit mask for CSI_CSICR1_SWAP16_EN.

//! @brief Get value of CSI_CSICR1_SWAP16_EN from a register value.
#define BG_CSI_CSICR1_SWAP16_EN(r)   (((r) & BM_CSI_CSICR1_SWAP16_EN) >> BP_CSI_CSICR1_SWAP16_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR1_SWAP16_EN.
#define BF_CSI_CSICR1_SWAP16_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR1_SWAP16_EN) & BM_CSI_CSICR1_SWAP16_EN)
#else
//! @brief Format value for bitfield CSI_CSICR1_SWAP16_EN.
#define BF_CSI_CSICR1_SWAP16_EN(v)   (((v) << BP_CSI_CSICR1_SWAP16_EN) & BM_CSI_CSICR1_SWAP16_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SWAP16_EN field to a new value.
#define BW_CSI_CSICR1_SWAP16_EN(v)   (HW_CSI_CSICR1_WR((HW_CSI_CSICR1_RD() & ~BM_CSI_CSICR1_SWAP16_EN) | BF_CSI_CSICR1_SWAP16_EN(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSICR2 - CSI Control Register 2 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register provides the statistic block with data about which live view resolution is being
 * used, and the starting sensor pixel of the Bayer pattern. It also contains the horizontal and
 * vertical count used to determine the number of pixels to skip between the 64 x 64 blocks of
 * statistics when generating statistics on live view image that are greater than 512 x 384.
 */
typedef union _hw_csi_csicr2
{
    reg32_t U;
    struct _hw_csi_csicr2_bitfields
    {
        unsigned HSC : 8; //!< [7:0] Horizontal Skip Count. Contains the number of pixels to skip. SCE must be 1, otherwise HSC is ignored.
        unsigned VSC : 8; //!< [15:8] Vertical Skip Count. Contains the number of rows to skip. SCE must be 1, otherwise VSC is ignored.
        unsigned LVRM : 3; //!< [18:16] Live View Resolution Mode. Selects the grid size used for live view resolution.
        unsigned BTS : 2; //!< [20:19] Bayer Tile Start. Controls the Bayer pattern starting point.
        unsigned RESERVED0 : 2; //!< [22:21] Reserved. These bits are reserved and should read 0.
        unsigned SCE : 1; //!< [23] Skip Count Enable. Enables or disables the skip count feature.
        unsigned AFS : 2; //!< [25:24] Auto Focus Spread. Selects which green pixels are used for auto-focus.
        unsigned DRM : 1; //!< [26] Double Resolution Mode. Controls size of statistics grid.
        unsigned RESERVED1 : 1; //!< [27] Reserved. These bit is reserved and should read 0.
        unsigned DMA_BURST_TYPE_SFF : 2; //!< [29:28] Burst Type of DMA Transfer from STATFIFO. Selects the burst type of DMA transfer from STATFIFO.
        unsigned DMA_BURST_TYPE_RFF : 2; //!< [31:30] Burst Type of DMA Transfer from RxFIFO. Selects the burst type of DMA transfer from RxFIFO.
    } B;
} hw_csi_csicr2_t;
#endif

/*
 * constants & macros for entire CSI_CSICR2 register
 */
#define HW_CSI_CSICR2_ADDR      (REGS_CSI_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSICR2           (*(volatile hw_csi_csicr2_t *) HW_CSI_CSICR2_ADDR)
#define HW_CSI_CSICR2_RD()      (HW_CSI_CSICR2.U)
#define HW_CSI_CSICR2_WR(v)     (HW_CSI_CSICR2.U = (v))
#define HW_CSI_CSICR2_SET(v)    (HW_CSI_CSICR2_WR(HW_CSI_CSICR2_RD() |  (v)))
#define HW_CSI_CSICR2_CLR(v)    (HW_CSI_CSICR2_WR(HW_CSI_CSICR2_RD() & ~(v)))
#define HW_CSI_CSICR2_TOG(v)    (HW_CSI_CSICR2_WR(HW_CSI_CSICR2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSICR2 bitfields
 */

/* --- Register HW_CSI_CSICR2, field HSC[7:0] (RW)
 *
 * Horizontal Skip Count. Contains the number of pixels to skip. SCE must be 1, otherwise HSC is
 * ignored.
 *
 * Values:
 * 0-255 - Number of pixels to skip minus 1
 */

#define BP_CSI_CSICR2_HSC      (0)      //!< Bit position for CSI_CSICR2_HSC.
#define BM_CSI_CSICR2_HSC      (0x000000ff)  //!< Bit mask for CSI_CSICR2_HSC.

//! @brief Get value of CSI_CSICR2_HSC from a register value.
#define BG_CSI_CSICR2_HSC(r)   (((r) & BM_CSI_CSICR2_HSC) >> BP_CSI_CSICR2_HSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_HSC.
#define BF_CSI_CSICR2_HSC(v)   ((((reg32_t) v) << BP_CSI_CSICR2_HSC) & BM_CSI_CSICR2_HSC)
#else
//! @brief Format value for bitfield CSI_CSICR2_HSC.
#define BF_CSI_CSICR2_HSC(v)   (((v) << BP_CSI_CSICR2_HSC) & BM_CSI_CSICR2_HSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HSC field to a new value.
#define BW_CSI_CSICR2_HSC(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_HSC) | BF_CSI_CSICR2_HSC(v)))
#endif


/* --- Register HW_CSI_CSICR2, field VSC[15:8] (RW)
 *
 * Vertical Skip Count. Contains the number of rows to skip. SCE must be 1, otherwise VSC is
 * ignored.
 *
 * Values:
 * 0-255 - Number of rows to skip minus 1
 */

#define BP_CSI_CSICR2_VSC      (8)      //!< Bit position for CSI_CSICR2_VSC.
#define BM_CSI_CSICR2_VSC      (0x0000ff00)  //!< Bit mask for CSI_CSICR2_VSC.

//! @brief Get value of CSI_CSICR2_VSC from a register value.
#define BG_CSI_CSICR2_VSC(r)   (((r) & BM_CSI_CSICR2_VSC) >> BP_CSI_CSICR2_VSC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_VSC.
#define BF_CSI_CSICR2_VSC(v)   ((((reg32_t) v) << BP_CSI_CSICR2_VSC) & BM_CSI_CSICR2_VSC)
#else
//! @brief Format value for bitfield CSI_CSICR2_VSC.
#define BF_CSI_CSICR2_VSC(v)   (((v) << BP_CSI_CSICR2_VSC) & BM_CSI_CSICR2_VSC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the VSC field to a new value.
#define BW_CSI_CSICR2_VSC(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_VSC) | BF_CSI_CSICR2_VSC(v)))
#endif


/* --- Register HW_CSI_CSICR2, field LVRM[18:16] (RW)
 *
 * Live View Resolution Mode. Selects the grid size used for live view resolution.
 *
 * Values:
 * 0 - 512 x 384
 * 1 - 448 x 336
 * 2 - 384 x 288
 * 3 - 384 x 256
 * 4 - 320 x 240
 * 5 - 288 x 216
 * 6 - 400 x 300
 */

#define BP_CSI_CSICR2_LVRM      (16)      //!< Bit position for CSI_CSICR2_LVRM.
#define BM_CSI_CSICR2_LVRM      (0x00070000)  //!< Bit mask for CSI_CSICR2_LVRM.

//! @brief Get value of CSI_CSICR2_LVRM from a register value.
#define BG_CSI_CSICR2_LVRM(r)   (((r) & BM_CSI_CSICR2_LVRM) >> BP_CSI_CSICR2_LVRM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_LVRM.
#define BF_CSI_CSICR2_LVRM(v)   ((((reg32_t) v) << BP_CSI_CSICR2_LVRM) & BM_CSI_CSICR2_LVRM)
#else
//! @brief Format value for bitfield CSI_CSICR2_LVRM.
#define BF_CSI_CSICR2_LVRM(v)   (((v) << BP_CSI_CSICR2_LVRM) & BM_CSI_CSICR2_LVRM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LVRM field to a new value.
#define BW_CSI_CSICR2_LVRM(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_LVRM) | BF_CSI_CSICR2_LVRM(v)))
#endif


/* --- Register HW_CSI_CSICR2, field BTS[20:19] (RW)
 *
 * Bayer Tile Start. Controls the Bayer pattern starting point.
 *
 * Values:
 * 00 - GR
 * 01 - RG
 * 10 - BG
 * 11 - GB
 */

#define BP_CSI_CSICR2_BTS      (19)      //!< Bit position for CSI_CSICR2_BTS.
#define BM_CSI_CSICR2_BTS      (0x00180000)  //!< Bit mask for CSI_CSICR2_BTS.

//! @brief Get value of CSI_CSICR2_BTS from a register value.
#define BG_CSI_CSICR2_BTS(r)   (((r) & BM_CSI_CSICR2_BTS) >> BP_CSI_CSICR2_BTS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_BTS.
#define BF_CSI_CSICR2_BTS(v)   ((((reg32_t) v) << BP_CSI_CSICR2_BTS) & BM_CSI_CSICR2_BTS)
#else
//! @brief Format value for bitfield CSI_CSICR2_BTS.
#define BF_CSI_CSICR2_BTS(v)   (((v) << BP_CSI_CSICR2_BTS) & BM_CSI_CSICR2_BTS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BTS field to a new value.
#define BW_CSI_CSICR2_BTS(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_BTS) | BF_CSI_CSICR2_BTS(v)))
#endif


/* --- Register HW_CSI_CSICR2, field SCE[23] (RW)
 *
 * Skip Count Enable. Enables or disables the skip count feature.
 *
 * Values:
 * 0 - Skip count disable
 * 1 - Skip count enable
 */

#define BP_CSI_CSICR2_SCE      (23)      //!< Bit position for CSI_CSICR2_SCE.
#define BM_CSI_CSICR2_SCE      (0x00800000)  //!< Bit mask for CSI_CSICR2_SCE.

//! @brief Get value of CSI_CSICR2_SCE from a register value.
#define BG_CSI_CSICR2_SCE(r)   (((r) & BM_CSI_CSICR2_SCE) >> BP_CSI_CSICR2_SCE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_SCE.
#define BF_CSI_CSICR2_SCE(v)   ((((reg32_t) v) << BP_CSI_CSICR2_SCE) & BM_CSI_CSICR2_SCE)
#else
//! @brief Format value for bitfield CSI_CSICR2_SCE.
#define BF_CSI_CSICR2_SCE(v)   (((v) << BP_CSI_CSICR2_SCE) & BM_CSI_CSICR2_SCE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SCE field to a new value.
#define BW_CSI_CSICR2_SCE(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_SCE) | BF_CSI_CSICR2_SCE(v)))
#endif


/* --- Register HW_CSI_CSICR2, field AFS[25:24] (RW)
 *
 * Auto Focus Spread. Selects which green pixels are used for auto-focus.
 *
 * Values:
 * 00 - Abs Diff on consecutive green pixels
 * 01 - Abs Diff on every third green pixels
 * 1x - Abs Diff on every four green pixels
 */

#define BP_CSI_CSICR2_AFS      (24)      //!< Bit position for CSI_CSICR2_AFS.
#define BM_CSI_CSICR2_AFS      (0x03000000)  //!< Bit mask for CSI_CSICR2_AFS.

//! @brief Get value of CSI_CSICR2_AFS from a register value.
#define BG_CSI_CSICR2_AFS(r)   (((r) & BM_CSI_CSICR2_AFS) >> BP_CSI_CSICR2_AFS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_AFS.
#define BF_CSI_CSICR2_AFS(v)   ((((reg32_t) v) << BP_CSI_CSICR2_AFS) & BM_CSI_CSICR2_AFS)
#else
//! @brief Format value for bitfield CSI_CSICR2_AFS.
#define BF_CSI_CSICR2_AFS(v)   (((v) << BP_CSI_CSICR2_AFS) & BM_CSI_CSICR2_AFS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the AFS field to a new value.
#define BW_CSI_CSICR2_AFS(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_AFS) | BF_CSI_CSICR2_AFS(v)))
#endif


/* --- Register HW_CSI_CSICR2, field DRM[26] (RW)
 *
 * Double Resolution Mode. Controls size of statistics grid.
 *
 * Values:
 * 0 - Stats grid of 8 x 6
 * 1 - Stats grid of 8 x 12
 */

#define BP_CSI_CSICR2_DRM      (26)      //!< Bit position for CSI_CSICR2_DRM.
#define BM_CSI_CSICR2_DRM      (0x04000000)  //!< Bit mask for CSI_CSICR2_DRM.

//! @brief Get value of CSI_CSICR2_DRM from a register value.
#define BG_CSI_CSICR2_DRM(r)   (((r) & BM_CSI_CSICR2_DRM) >> BP_CSI_CSICR2_DRM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_DRM.
#define BF_CSI_CSICR2_DRM(v)   ((((reg32_t) v) << BP_CSI_CSICR2_DRM) & BM_CSI_CSICR2_DRM)
#else
//! @brief Format value for bitfield CSI_CSICR2_DRM.
#define BF_CSI_CSICR2_DRM(v)   (((v) << BP_CSI_CSICR2_DRM) & BM_CSI_CSICR2_DRM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DRM field to a new value.
#define BW_CSI_CSICR2_DRM(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_DRM) | BF_CSI_CSICR2_DRM(v)))
#endif


/* --- Register HW_CSI_CSICR2, field DMA_BURST_TYPE_SFF[29:28] (RW)
 *
 * Burst Type of DMA Transfer from STATFIFO. Selects the burst type of DMA transfer from STATFIFO.
 *
 * Values:
 * 00 - INCR8
 * 01 - INCR4
 * 10 - INCR8
 * 11 - INCR16
 */

#define BP_CSI_CSICR2_DMA_BURST_TYPE_SFF      (28)      //!< Bit position for CSI_CSICR2_DMA_BURST_TYPE_SFF.
#define BM_CSI_CSICR2_DMA_BURST_TYPE_SFF      (0x30000000)  //!< Bit mask for CSI_CSICR2_DMA_BURST_TYPE_SFF.

//! @brief Get value of CSI_CSICR2_DMA_BURST_TYPE_SFF from a register value.
#define BG_CSI_CSICR2_DMA_BURST_TYPE_SFF(r)   (((r) & BM_CSI_CSICR2_DMA_BURST_TYPE_SFF) >> BP_CSI_CSICR2_DMA_BURST_TYPE_SFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_DMA_BURST_TYPE_SFF.
#define BF_CSI_CSICR2_DMA_BURST_TYPE_SFF(v)   ((((reg32_t) v) << BP_CSI_CSICR2_DMA_BURST_TYPE_SFF) & BM_CSI_CSICR2_DMA_BURST_TYPE_SFF)
#else
//! @brief Format value for bitfield CSI_CSICR2_DMA_BURST_TYPE_SFF.
#define BF_CSI_CSICR2_DMA_BURST_TYPE_SFF(v)   (((v) << BP_CSI_CSICR2_DMA_BURST_TYPE_SFF) & BM_CSI_CSICR2_DMA_BURST_TYPE_SFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_BURST_TYPE_SFF field to a new value.
#define BW_CSI_CSICR2_DMA_BURST_TYPE_SFF(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_DMA_BURST_TYPE_SFF) | BF_CSI_CSICR2_DMA_BURST_TYPE_SFF(v)))
#endif


/* --- Register HW_CSI_CSICR2, field DMA_BURST_TYPE_RFF[31:30] (RW)
 *
 * Burst Type of DMA Transfer from RxFIFO. Selects the burst type of DMA transfer from RxFIFO.
 *
 * Values:
 * 00 - INCR8
 * 01 - INCR4
 * 10 - INCR8
 * 11 - INCR16
 */

#define BP_CSI_CSICR2_DMA_BURST_TYPE_RFF      (30)      //!< Bit position for CSI_CSICR2_DMA_BURST_TYPE_RFF.
#define BM_CSI_CSICR2_DMA_BURST_TYPE_RFF      (0xc0000000)  //!< Bit mask for CSI_CSICR2_DMA_BURST_TYPE_RFF.

//! @brief Get value of CSI_CSICR2_DMA_BURST_TYPE_RFF from a register value.
#define BG_CSI_CSICR2_DMA_BURST_TYPE_RFF(r)   (((r) & BM_CSI_CSICR2_DMA_BURST_TYPE_RFF) >> BP_CSI_CSICR2_DMA_BURST_TYPE_RFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR2_DMA_BURST_TYPE_RFF.
#define BF_CSI_CSICR2_DMA_BURST_TYPE_RFF(v)   ((((reg32_t) v) << BP_CSI_CSICR2_DMA_BURST_TYPE_RFF) & BM_CSI_CSICR2_DMA_BURST_TYPE_RFF)
#else
//! @brief Format value for bitfield CSI_CSICR2_DMA_BURST_TYPE_RFF.
#define BF_CSI_CSICR2_DMA_BURST_TYPE_RFF(v)   (((v) << BP_CSI_CSICR2_DMA_BURST_TYPE_RFF) & BM_CSI_CSICR2_DMA_BURST_TYPE_RFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_BURST_TYPE_RFF field to a new value.
#define BW_CSI_CSICR2_DMA_BURST_TYPE_RFF(v)   (HW_CSI_CSICR2_WR((HW_CSI_CSICR2_RD() & ~BM_CSI_CSICR2_DMA_BURST_TYPE_RFF) | BF_CSI_CSICR2_DMA_BURST_TYPE_RFF(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSICR3 - CSI Control Register 3 (RW)
 *
 * Reset value: 0x00000000
 *
 * This read/write register acts as an extension of the functionality of the CSI Control register 1,
 * adding additional control and features.
 */
typedef union _hw_csi_csicr3
{
    reg32_t U;
    struct _hw_csi_csicr3_bitfields
    {
        unsigned ECC_AUTO_EN : 1; //!< [0] Automatic Error Correction Enable. This bit enables and disables the automatic error correction. If an error occurs and error correction is disabled only the ECC_INT status bit is set. This feature only works in CCIR interlace mode.
        unsigned ECC_INT_EN : 1; //!< [1] Error Detection Interrupt Enable. This bit enables and disables the error detection interrupt. This feature only works in CCIR interlace mode.
        unsigned ZERO_PACK_EN : 1; //!< [2] Dummy Zero Packing Enable. This bit causes a dummy zero to be packed with every 3 incoming bytes, forming a 32-bit word. The dummy zero is always packed to the LSB position. This packing function is only available in 8-bit/pixel mode.
        unsigned TWO_8BIT_SENSOR : 1; //!< [3] Two 8-bit Sensor Mode. This bit indicates one 16-bit sensor or two 8-bit sensors are connected to the 16-bit data ports. This bit should be set if there is one 16-bit sensor or two 8-bit sensors are connected. This bit should be configured before activating or restarting the embedded DMA controller.
        unsigned RXFF_LEVEL : 3; //!< [6:4] RxFIFO Full Level . When the number of data in RxFIFO reaches this level, a RxFIFO full interrupt is generated, or an RXFIFO DMA request is sent , or CSI-PrP burst cycle is issued .
        unsigned HRESP_ERR_EN : 1; //!< [7] Hresponse Error Enable. This bit enables the hresponse error interrupt.
        unsigned STATFF_LEVEL : 3; //!< [10:8] STATFIFO Full Level. When the number of data in STATFIFO reach this level, STATFIFO full interrupt is generated, or STATFIFO DMA request is sent.
        unsigned DMA_REQ_EN_SFF : 1; //!< [11] DMA Request Enable for STATFIFO. This bit enables the dma request from STATFIFO to the embedded DMA controller.
        unsigned DMA_REQ_EN_RFF : 1; //!< [12] DMA Request Enable for RxFIFO. This bit enables the dma request from RxFIFO to the embedded DMA controller.
        unsigned DMA_REFLASH_SFF : 1; //!< [13] Reflash DMA Controller for STATFIFO. This bit reflash the embedded DMA controller for STATFIFO. It should be reflashed before the embedded DMA controller starts to work. (Cleared automatically after reflashing is done)
        unsigned DMA_REFLASH_RFF : 1; //!< [14] Reflash DMA Controller for RxFIFO. This bit reflash the embedded DMA controller for RxFIFO. It should be reflashed before the embedded DMA controller starts to work. (Cleared automatically after reflashing is done)
        unsigned FRMCNT_RST : 1; //!< [15] Frame Count Reset. Resets the Frame Counter. (Cleared automatically after reset is done)
        unsigned FRMCNT : 16; //!< [31:16] Frame Counter. This is a 16-bit Frame Counter (Wraps around automatically after reaching the maximum)
    } B;
} hw_csi_csicr3_t;
#endif

/*
 * constants & macros for entire CSI_CSICR3 register
 */
#define HW_CSI_CSICR3_ADDR      (REGS_CSI_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSICR3           (*(volatile hw_csi_csicr3_t *) HW_CSI_CSICR3_ADDR)
#define HW_CSI_CSICR3_RD()      (HW_CSI_CSICR3.U)
#define HW_CSI_CSICR3_WR(v)     (HW_CSI_CSICR3.U = (v))
#define HW_CSI_CSICR3_SET(v)    (HW_CSI_CSICR3_WR(HW_CSI_CSICR3_RD() |  (v)))
#define HW_CSI_CSICR3_CLR(v)    (HW_CSI_CSICR3_WR(HW_CSI_CSICR3_RD() & ~(v)))
#define HW_CSI_CSICR3_TOG(v)    (HW_CSI_CSICR3_WR(HW_CSI_CSICR3_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSICR3 bitfields
 */

/* --- Register HW_CSI_CSICR3, field ECC_AUTO_EN[0] (RW)
 *
 * Automatic Error Correction Enable. This bit enables and disables the automatic error correction.
 * If an error occurs and error correction is disabled only the ECC_INT status bit is set. This
 * feature only works in CCIR interlace mode.
 *
 * Values:
 * 0 - Auto Error correction is disabled.
 * 1 - Auto Error correction is enabled.
 */

#define BP_CSI_CSICR3_ECC_AUTO_EN      (0)      //!< Bit position for CSI_CSICR3_ECC_AUTO_EN.
#define BM_CSI_CSICR3_ECC_AUTO_EN      (0x00000001)  //!< Bit mask for CSI_CSICR3_ECC_AUTO_EN.

//! @brief Get value of CSI_CSICR3_ECC_AUTO_EN from a register value.
#define BG_CSI_CSICR3_ECC_AUTO_EN(r)   (((r) & BM_CSI_CSICR3_ECC_AUTO_EN) >> BP_CSI_CSICR3_ECC_AUTO_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_ECC_AUTO_EN.
#define BF_CSI_CSICR3_ECC_AUTO_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR3_ECC_AUTO_EN) & BM_CSI_CSICR3_ECC_AUTO_EN)
#else
//! @brief Format value for bitfield CSI_CSICR3_ECC_AUTO_EN.
#define BF_CSI_CSICR3_ECC_AUTO_EN(v)   (((v) << BP_CSI_CSICR3_ECC_AUTO_EN) & BM_CSI_CSICR3_ECC_AUTO_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECC_AUTO_EN field to a new value.
#define BW_CSI_CSICR3_ECC_AUTO_EN(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_ECC_AUTO_EN) | BF_CSI_CSICR3_ECC_AUTO_EN(v)))
#endif


/* --- Register HW_CSI_CSICR3, field ECC_INT_EN[1] (RW)
 *
 * Error Detection Interrupt Enable. This bit enables and disables the error detection interrupt.
 * This feature only works in CCIR interlace mode.
 *
 * Values:
 * 0 - No interrupt is generated when error is detected. Only the status bit ECC_INT is set.
 * 1 - Interrupt is generated when error is detected.
 */

#define BP_CSI_CSICR3_ECC_INT_EN      (1)      //!< Bit position for CSI_CSICR3_ECC_INT_EN.
#define BM_CSI_CSICR3_ECC_INT_EN      (0x00000002)  //!< Bit mask for CSI_CSICR3_ECC_INT_EN.

//! @brief Get value of CSI_CSICR3_ECC_INT_EN from a register value.
#define BG_CSI_CSICR3_ECC_INT_EN(r)   (((r) & BM_CSI_CSICR3_ECC_INT_EN) >> BP_CSI_CSICR3_ECC_INT_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_ECC_INT_EN.
#define BF_CSI_CSICR3_ECC_INT_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR3_ECC_INT_EN) & BM_CSI_CSICR3_ECC_INT_EN)
#else
//! @brief Format value for bitfield CSI_CSICR3_ECC_INT_EN.
#define BF_CSI_CSICR3_ECC_INT_EN(v)   (((v) << BP_CSI_CSICR3_ECC_INT_EN) & BM_CSI_CSICR3_ECC_INT_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECC_INT_EN field to a new value.
#define BW_CSI_CSICR3_ECC_INT_EN(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_ECC_INT_EN) | BF_CSI_CSICR3_ECC_INT_EN(v)))
#endif


/* --- Register HW_CSI_CSICR3, field ZERO_PACK_EN[2] (RW)
 *
 * Dummy Zero Packing Enable. This bit causes a dummy zero to be packed with every 3 incoming bytes,
 * forming a 32-bit word. The dummy zero is always packed to the LSB position. This packing function
 * is only available in 8-bit/pixel mode.
 *
 * Values:
 * 0 - Zero packing disabled
 * 1 - Zero packing enabled
 */

#define BP_CSI_CSICR3_ZERO_PACK_EN      (2)      //!< Bit position for CSI_CSICR3_ZERO_PACK_EN.
#define BM_CSI_CSICR3_ZERO_PACK_EN      (0x00000004)  //!< Bit mask for CSI_CSICR3_ZERO_PACK_EN.

//! @brief Get value of CSI_CSICR3_ZERO_PACK_EN from a register value.
#define BG_CSI_CSICR3_ZERO_PACK_EN(r)   (((r) & BM_CSI_CSICR3_ZERO_PACK_EN) >> BP_CSI_CSICR3_ZERO_PACK_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_ZERO_PACK_EN.
#define BF_CSI_CSICR3_ZERO_PACK_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR3_ZERO_PACK_EN) & BM_CSI_CSICR3_ZERO_PACK_EN)
#else
//! @brief Format value for bitfield CSI_CSICR3_ZERO_PACK_EN.
#define BF_CSI_CSICR3_ZERO_PACK_EN(v)   (((v) << BP_CSI_CSICR3_ZERO_PACK_EN) & BM_CSI_CSICR3_ZERO_PACK_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ZERO_PACK_EN field to a new value.
#define BW_CSI_CSICR3_ZERO_PACK_EN(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_ZERO_PACK_EN) | BF_CSI_CSICR3_ZERO_PACK_EN(v)))
#endif


/* --- Register HW_CSI_CSICR3, field TWO_8BIT_SENSOR[3] (RW)
 *
 * Two 8-bit Sensor Mode. This bit indicates one 16-bit sensor or two 8-bit sensors are connected to
 * the 16-bit data ports. This bit should be set if there is one 16-bit sensor or two 8-bit sensors
 * are connected. This bit should be configured before activating or restarting the embedded DMA
 * controller.
 *
 * Values:
 * 0 - Only one sensor is connected.
 * 1 - Two 8-bit sensors are connected or one 16-bit sensor is connected.
 */

#define BP_CSI_CSICR3_TWO_8BIT_SENSOR      (3)      //!< Bit position for CSI_CSICR3_TWO_8BIT_SENSOR.
#define BM_CSI_CSICR3_TWO_8BIT_SENSOR      (0x00000008)  //!< Bit mask for CSI_CSICR3_TWO_8BIT_SENSOR.

//! @brief Get value of CSI_CSICR3_TWO_8BIT_SENSOR from a register value.
#define BG_CSI_CSICR3_TWO_8BIT_SENSOR(r)   (((r) & BM_CSI_CSICR3_TWO_8BIT_SENSOR) >> BP_CSI_CSICR3_TWO_8BIT_SENSOR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_TWO_8BIT_SENSOR.
#define BF_CSI_CSICR3_TWO_8BIT_SENSOR(v)   ((((reg32_t) v) << BP_CSI_CSICR3_TWO_8BIT_SENSOR) & BM_CSI_CSICR3_TWO_8BIT_SENSOR)
#else
//! @brief Format value for bitfield CSI_CSICR3_TWO_8BIT_SENSOR.
#define BF_CSI_CSICR3_TWO_8BIT_SENSOR(v)   (((v) << BP_CSI_CSICR3_TWO_8BIT_SENSOR) & BM_CSI_CSICR3_TWO_8BIT_SENSOR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TWO_8BIT_SENSOR field to a new value.
#define BW_CSI_CSICR3_TWO_8BIT_SENSOR(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_TWO_8BIT_SENSOR) | BF_CSI_CSICR3_TWO_8BIT_SENSOR(v)))
#endif


/* --- Register HW_CSI_CSICR3, field RXFF_LEVEL[6:4] (RW)
 *
 * RxFIFO Full Level . When the number of data in RxFIFO reaches this level, a RxFIFO full interrupt
 * is generated, or an RXFIFO DMA request is sent , or CSI-PrP burst cycle is issued .
 *
 * Values:
 * 000 - 4 Words
 * 001 - 8 Words
 * 010 - 16 Words
 * 011 - 24 Words
 * 100 - 32 Words
 * 101 - 4 8 Words
 * 110 - 64 Words
 * 111 - 96 Words
 */

#define BP_CSI_CSICR3_RXFF_LEVEL      (4)      //!< Bit position for CSI_CSICR3_RXFF_LEVEL.
#define BM_CSI_CSICR3_RXFF_LEVEL      (0x00000070)  //!< Bit mask for CSI_CSICR3_RXFF_LEVEL.

//! @brief Get value of CSI_CSICR3_RXFF_LEVEL from a register value.
#define BG_CSI_CSICR3_RXFF_LEVEL(r)   (((r) & BM_CSI_CSICR3_RXFF_LEVEL) >> BP_CSI_CSICR3_RXFF_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_RXFF_LEVEL.
#define BF_CSI_CSICR3_RXFF_LEVEL(v)   ((((reg32_t) v) << BP_CSI_CSICR3_RXFF_LEVEL) & BM_CSI_CSICR3_RXFF_LEVEL)
#else
//! @brief Format value for bitfield CSI_CSICR3_RXFF_LEVEL.
#define BF_CSI_CSICR3_RXFF_LEVEL(v)   (((v) << BP_CSI_CSICR3_RXFF_LEVEL) & BM_CSI_CSICR3_RXFF_LEVEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFF_LEVEL field to a new value.
#define BW_CSI_CSICR3_RXFF_LEVEL(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_RXFF_LEVEL) | BF_CSI_CSICR3_RXFF_LEVEL(v)))
#endif


/* --- Register HW_CSI_CSICR3, field HRESP_ERR_EN[7] (RW)
 *
 * Hresponse Error Enable. This bit enables the hresponse error interrupt.
 *
 * Values:
 * 0 - Disable hresponse error interrupt
 * 1 - Enable hresponse error interrupt
 */

#define BP_CSI_CSICR3_HRESP_ERR_EN      (7)      //!< Bit position for CSI_CSICR3_HRESP_ERR_EN.
#define BM_CSI_CSICR3_HRESP_ERR_EN      (0x00000080)  //!< Bit mask for CSI_CSICR3_HRESP_ERR_EN.

//! @brief Get value of CSI_CSICR3_HRESP_ERR_EN from a register value.
#define BG_CSI_CSICR3_HRESP_ERR_EN(r)   (((r) & BM_CSI_CSICR3_HRESP_ERR_EN) >> BP_CSI_CSICR3_HRESP_ERR_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_HRESP_ERR_EN.
#define BF_CSI_CSICR3_HRESP_ERR_EN(v)   ((((reg32_t) v) << BP_CSI_CSICR3_HRESP_ERR_EN) & BM_CSI_CSICR3_HRESP_ERR_EN)
#else
//! @brief Format value for bitfield CSI_CSICR3_HRESP_ERR_EN.
#define BF_CSI_CSICR3_HRESP_ERR_EN(v)   (((v) << BP_CSI_CSICR3_HRESP_ERR_EN) & BM_CSI_CSICR3_HRESP_ERR_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HRESP_ERR_EN field to a new value.
#define BW_CSI_CSICR3_HRESP_ERR_EN(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_HRESP_ERR_EN) | BF_CSI_CSICR3_HRESP_ERR_EN(v)))
#endif


/* --- Register HW_CSI_CSICR3, field STATFF_LEVEL[10:8] (RW)
 *
 * STATFIFO Full Level. When the number of data in STATFIFO reach this level, STATFIFO full
 * interrupt is generated, or STATFIFO DMA request is sent.
 *
 * Values:
 * 000 - 4 Words
 * 001 - 8 Words
 * 010 - 12 Words
 * 011 - 16 Words
 * 100 - 24 Words
 * 101 - 32 Words
 * 110 - 48 Words
 * 111 - 64 Words
 */

#define BP_CSI_CSICR3_STATFF_LEVEL      (8)      //!< Bit position for CSI_CSICR3_STATFF_LEVEL.
#define BM_CSI_CSICR3_STATFF_LEVEL      (0x00000700)  //!< Bit mask for CSI_CSICR3_STATFF_LEVEL.

//! @brief Get value of CSI_CSICR3_STATFF_LEVEL from a register value.
#define BG_CSI_CSICR3_STATFF_LEVEL(r)   (((r) & BM_CSI_CSICR3_STATFF_LEVEL) >> BP_CSI_CSICR3_STATFF_LEVEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_STATFF_LEVEL.
#define BF_CSI_CSICR3_STATFF_LEVEL(v)   ((((reg32_t) v) << BP_CSI_CSICR3_STATFF_LEVEL) & BM_CSI_CSICR3_STATFF_LEVEL)
#else
//! @brief Format value for bitfield CSI_CSICR3_STATFF_LEVEL.
#define BF_CSI_CSICR3_STATFF_LEVEL(v)   (((v) << BP_CSI_CSICR3_STATFF_LEVEL) & BM_CSI_CSICR3_STATFF_LEVEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATFF_LEVEL field to a new value.
#define BW_CSI_CSICR3_STATFF_LEVEL(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_STATFF_LEVEL) | BF_CSI_CSICR3_STATFF_LEVEL(v)))
#endif


/* --- Register HW_CSI_CSICR3, field DMA_REQ_EN_SFF[11] (RW)
 *
 * DMA Request Enable for STATFIFO. This bit enables the dma request from STATFIFO to the embedded
 * DMA controller.
 *
 * Values:
 * 0 - Disable the dma request
 * 1 - Enable the dma request
 */

#define BP_CSI_CSICR3_DMA_REQ_EN_SFF      (11)      //!< Bit position for CSI_CSICR3_DMA_REQ_EN_SFF.
#define BM_CSI_CSICR3_DMA_REQ_EN_SFF      (0x00000800)  //!< Bit mask for CSI_CSICR3_DMA_REQ_EN_SFF.

//! @brief Get value of CSI_CSICR3_DMA_REQ_EN_SFF from a register value.
#define BG_CSI_CSICR3_DMA_REQ_EN_SFF(r)   (((r) & BM_CSI_CSICR3_DMA_REQ_EN_SFF) >> BP_CSI_CSICR3_DMA_REQ_EN_SFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_DMA_REQ_EN_SFF.
#define BF_CSI_CSICR3_DMA_REQ_EN_SFF(v)   ((((reg32_t) v) << BP_CSI_CSICR3_DMA_REQ_EN_SFF) & BM_CSI_CSICR3_DMA_REQ_EN_SFF)
#else
//! @brief Format value for bitfield CSI_CSICR3_DMA_REQ_EN_SFF.
#define BF_CSI_CSICR3_DMA_REQ_EN_SFF(v)   (((v) << BP_CSI_CSICR3_DMA_REQ_EN_SFF) & BM_CSI_CSICR3_DMA_REQ_EN_SFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_REQ_EN_SFF field to a new value.
#define BW_CSI_CSICR3_DMA_REQ_EN_SFF(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_DMA_REQ_EN_SFF) | BF_CSI_CSICR3_DMA_REQ_EN_SFF(v)))
#endif


/* --- Register HW_CSI_CSICR3, field DMA_REQ_EN_RFF[12] (RW)
 *
 * DMA Request Enable for RxFIFO. This bit enables the dma request from RxFIFO to the embedded DMA
 * controller.
 *
 * Values:
 * 0 - Disable the dma request
 * 1 - Enable the dma request
 */

#define BP_CSI_CSICR3_DMA_REQ_EN_RFF      (12)      //!< Bit position for CSI_CSICR3_DMA_REQ_EN_RFF.
#define BM_CSI_CSICR3_DMA_REQ_EN_RFF      (0x00001000)  //!< Bit mask for CSI_CSICR3_DMA_REQ_EN_RFF.

//! @brief Get value of CSI_CSICR3_DMA_REQ_EN_RFF from a register value.
#define BG_CSI_CSICR3_DMA_REQ_EN_RFF(r)   (((r) & BM_CSI_CSICR3_DMA_REQ_EN_RFF) >> BP_CSI_CSICR3_DMA_REQ_EN_RFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_DMA_REQ_EN_RFF.
#define BF_CSI_CSICR3_DMA_REQ_EN_RFF(v)   ((((reg32_t) v) << BP_CSI_CSICR3_DMA_REQ_EN_RFF) & BM_CSI_CSICR3_DMA_REQ_EN_RFF)
#else
//! @brief Format value for bitfield CSI_CSICR3_DMA_REQ_EN_RFF.
#define BF_CSI_CSICR3_DMA_REQ_EN_RFF(v)   (((v) << BP_CSI_CSICR3_DMA_REQ_EN_RFF) & BM_CSI_CSICR3_DMA_REQ_EN_RFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_REQ_EN_RFF field to a new value.
#define BW_CSI_CSICR3_DMA_REQ_EN_RFF(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_DMA_REQ_EN_RFF) | BF_CSI_CSICR3_DMA_REQ_EN_RFF(v)))
#endif


/* --- Register HW_CSI_CSICR3, field DMA_REFLASH_SFF[13] (RW)
 *
 * Reflash DMA Controller for STATFIFO. This bit reflash the embedded DMA controller for STATFIFO.
 * It should be reflashed before the embedded DMA controller starts to work. (Cleared automatically
 * after reflashing is done)
 *
 * Values:
 * 0 - No reflashing
 * 1 - Reflash the embedded DMA controller
 */

#define BP_CSI_CSICR3_DMA_REFLASH_SFF      (13)      //!< Bit position for CSI_CSICR3_DMA_REFLASH_SFF.
#define BM_CSI_CSICR3_DMA_REFLASH_SFF      (0x00002000)  //!< Bit mask for CSI_CSICR3_DMA_REFLASH_SFF.

//! @brief Get value of CSI_CSICR3_DMA_REFLASH_SFF from a register value.
#define BG_CSI_CSICR3_DMA_REFLASH_SFF(r)   (((r) & BM_CSI_CSICR3_DMA_REFLASH_SFF) >> BP_CSI_CSICR3_DMA_REFLASH_SFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_DMA_REFLASH_SFF.
#define BF_CSI_CSICR3_DMA_REFLASH_SFF(v)   ((((reg32_t) v) << BP_CSI_CSICR3_DMA_REFLASH_SFF) & BM_CSI_CSICR3_DMA_REFLASH_SFF)
#else
//! @brief Format value for bitfield CSI_CSICR3_DMA_REFLASH_SFF.
#define BF_CSI_CSICR3_DMA_REFLASH_SFF(v)   (((v) << BP_CSI_CSICR3_DMA_REFLASH_SFF) & BM_CSI_CSICR3_DMA_REFLASH_SFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_REFLASH_SFF field to a new value.
#define BW_CSI_CSICR3_DMA_REFLASH_SFF(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_DMA_REFLASH_SFF) | BF_CSI_CSICR3_DMA_REFLASH_SFF(v)))
#endif


/* --- Register HW_CSI_CSICR3, field DMA_REFLASH_RFF[14] (RW)
 *
 * Reflash DMA Controller for RxFIFO. This bit reflash the embedded DMA controller for RxFIFO. It
 * should be reflashed before the embedded DMA controller starts to work. (Cleared automatically
 * after reflashing is done)
 *
 * Values:
 * 0 - No reflashing
 * 1 - Reflash the embedded DMA controller
 */

#define BP_CSI_CSICR3_DMA_REFLASH_RFF      (14)      //!< Bit position for CSI_CSICR3_DMA_REFLASH_RFF.
#define BM_CSI_CSICR3_DMA_REFLASH_RFF      (0x00004000)  //!< Bit mask for CSI_CSICR3_DMA_REFLASH_RFF.

//! @brief Get value of CSI_CSICR3_DMA_REFLASH_RFF from a register value.
#define BG_CSI_CSICR3_DMA_REFLASH_RFF(r)   (((r) & BM_CSI_CSICR3_DMA_REFLASH_RFF) >> BP_CSI_CSICR3_DMA_REFLASH_RFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_DMA_REFLASH_RFF.
#define BF_CSI_CSICR3_DMA_REFLASH_RFF(v)   ((((reg32_t) v) << BP_CSI_CSICR3_DMA_REFLASH_RFF) & BM_CSI_CSICR3_DMA_REFLASH_RFF)
#else
//! @brief Format value for bitfield CSI_CSICR3_DMA_REFLASH_RFF.
#define BF_CSI_CSICR3_DMA_REFLASH_RFF(v)   (((v) << BP_CSI_CSICR3_DMA_REFLASH_RFF) & BM_CSI_CSICR3_DMA_REFLASH_RFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_REFLASH_RFF field to a new value.
#define BW_CSI_CSICR3_DMA_REFLASH_RFF(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_DMA_REFLASH_RFF) | BF_CSI_CSICR3_DMA_REFLASH_RFF(v)))
#endif


/* --- Register HW_CSI_CSICR3, field FRMCNT_RST[15] (RW)
 *
 * Frame Count Reset. Resets the Frame Counter. (Cleared automatically after reset is done)
 *
 * Values:
 * 0 - Do not reset
 * 1 - Reset frame counter immediately
 */

#define BP_CSI_CSICR3_FRMCNT_RST      (15)      //!< Bit position for CSI_CSICR3_FRMCNT_RST.
#define BM_CSI_CSICR3_FRMCNT_RST      (0x00008000)  //!< Bit mask for CSI_CSICR3_FRMCNT_RST.

//! @brief Get value of CSI_CSICR3_FRMCNT_RST from a register value.
#define BG_CSI_CSICR3_FRMCNT_RST(r)   (((r) & BM_CSI_CSICR3_FRMCNT_RST) >> BP_CSI_CSICR3_FRMCNT_RST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_FRMCNT_RST.
#define BF_CSI_CSICR3_FRMCNT_RST(v)   ((((reg32_t) v) << BP_CSI_CSICR3_FRMCNT_RST) & BM_CSI_CSICR3_FRMCNT_RST)
#else
//! @brief Format value for bitfield CSI_CSICR3_FRMCNT_RST.
#define BF_CSI_CSICR3_FRMCNT_RST(v)   (((v) << BP_CSI_CSICR3_FRMCNT_RST) & BM_CSI_CSICR3_FRMCNT_RST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRMCNT_RST field to a new value.
#define BW_CSI_CSICR3_FRMCNT_RST(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_FRMCNT_RST) | BF_CSI_CSICR3_FRMCNT_RST(v)))
#endif


/* --- Register HW_CSI_CSICR3, field FRMCNT[31:16] (RW)
 *
 * Frame Counter. This is a 16-bit Frame Counter (Wraps around automatically after reaching the
 * maximum)
 */

#define BP_CSI_CSICR3_FRMCNT      (16)      //!< Bit position for CSI_CSICR3_FRMCNT.
#define BM_CSI_CSICR3_FRMCNT      (0xffff0000)  //!< Bit mask for CSI_CSICR3_FRMCNT.

//! @brief Get value of CSI_CSICR3_FRMCNT from a register value.
#define BG_CSI_CSICR3_FRMCNT(r)   (((r) & BM_CSI_CSICR3_FRMCNT) >> BP_CSI_CSICR3_FRMCNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSICR3_FRMCNT.
#define BF_CSI_CSICR3_FRMCNT(v)   ((((reg32_t) v) << BP_CSI_CSICR3_FRMCNT) & BM_CSI_CSICR3_FRMCNT)
#else
//! @brief Format value for bitfield CSI_CSICR3_FRMCNT.
#define BF_CSI_CSICR3_FRMCNT(v)   (((v) << BP_CSI_CSICR3_FRMCNT) & BM_CSI_CSICR3_FRMCNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRMCNT field to a new value.
#define BW_CSI_CSICR3_FRMCNT(v)   (HW_CSI_CSICR3_WR((HW_CSI_CSICR3_RD() & ~BM_CSI_CSICR3_FRMCNT) | BF_CSI_CSICR3_FRMCNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSISTATFIFO - CSI Statistic FIFO Register (RO)
 *
 * Reset value: 0x00000000
 *
 * The StatFIFO is a read-only register containing statistic data from the sensor. Writing to this
 * register has no effect.
 */
typedef union _hw_csi_csistatfifo
{
    reg32_t U;
    struct _hw_csi_csistatfifo_bitfields
    {
        unsigned STAT : 32; //!< [31:0] Static data from sensor
    } B;
} hw_csi_csistatfifo_t;
#endif

/*
 * constants & macros for entire CSI_CSISTATFIFO register
 */
#define HW_CSI_CSISTATFIFO_ADDR      (REGS_CSI_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSISTATFIFO           (*(volatile hw_csi_csistatfifo_t *) HW_CSI_CSISTATFIFO_ADDR)
#define HW_CSI_CSISTATFIFO_RD()      (HW_CSI_CSISTATFIFO.U)
#endif

/*
 * constants & macros for individual CSI_CSISTATFIFO bitfields
 */

/* --- Register HW_CSI_CSISTATFIFO, field STAT[31:0] (RO)
 *
 * Static data from sensor
 */

#define BP_CSI_CSISTATFIFO_STAT      (0)      //!< Bit position for CSI_CSISTATFIFO_STAT.
#define BM_CSI_CSISTATFIFO_STAT      (0xffffffff)  //!< Bit mask for CSI_CSISTATFIFO_STAT.

//! @brief Get value of CSI_CSISTATFIFO_STAT from a register value.
#define BG_CSI_CSISTATFIFO_STAT(r)   (((r) & BM_CSI_CSISTATFIFO_STAT) >> BP_CSI_CSISTATFIFO_STAT)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIRFIFO - CSI RX FIFO Register (RO)
 *
 * Reset value: 0x00000000
 *
 * This read-only register contains received image data. Writing to this register has no effect.
 */
typedef union _hw_csi_csirfifo
{
    reg32_t U;
    struct _hw_csi_csirfifo_bitfields
    {
        unsigned IMAGE : 32; //!< [31:0] Received image data
    } B;
} hw_csi_csirfifo_t;
#endif

/*
 * constants & macros for entire CSI_CSIRFIFO register
 */
#define HW_CSI_CSIRFIFO_ADDR      (REGS_CSI_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIRFIFO           (*(volatile hw_csi_csirfifo_t *) HW_CSI_CSIRFIFO_ADDR)
#define HW_CSI_CSIRFIFO_RD()      (HW_CSI_CSIRFIFO.U)
#endif

/*
 * constants & macros for individual CSI_CSIRFIFO bitfields
 */

/* --- Register HW_CSI_CSIRFIFO, field IMAGE[31:0] (RO)
 *
 * Received image data
 */

#define BP_CSI_CSIRFIFO_IMAGE      (0)      //!< Bit position for CSI_CSIRFIFO_IMAGE.
#define BM_CSI_CSIRFIFO_IMAGE      (0xffffffff)  //!< Bit mask for CSI_CSIRFIFO_IMAGE.

//! @brief Get value of CSI_CSIRFIFO_IMAGE from a register value.
#define BG_CSI_CSIRFIFO_IMAGE(r)   (((r) & BM_CSI_CSIRFIFO_IMAGE) >> BP_CSI_CSIRFIFO_IMAGE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIRXCNT - CSI RX Count Register (RW)
 *
 * Reset value: 0x00009600
 *
 * This register works for EOF interrupt generation. It should be set to the number of words to
 * receive that would generate an EOF interrupt.  There is an internal counter that counts the
 * number of words read from the RX FIFO. Whenever the RX FIFO is being read, by either the CPU or
 * the embedded DMA controller, the counter value is updated and compared with this register. If the
 * values match, then an EOF interrupt is triggered.
 */
typedef union _hw_csi_csirxcnt
{
    reg32_t U;
    struct _hw_csi_csirxcnt_bitfields
    {
        unsigned RXCNT : 22; //!< [21:0] RxFIFO Count. This 22-bit counter for RXFIFO is updated each time the RXFIFO is read by CPU or DMA.This counter should be set to the expected number of words to receive that would generate an EOF interrupt.
        unsigned RESERVED0 : 10; //!< [31:22] Reserved. These bits are reserved and should read 0.
    } B;
} hw_csi_csirxcnt_t;
#endif

/*
 * constants & macros for entire CSI_CSIRXCNT register
 */
#define HW_CSI_CSIRXCNT_ADDR      (REGS_CSI_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIRXCNT           (*(volatile hw_csi_csirxcnt_t *) HW_CSI_CSIRXCNT_ADDR)
#define HW_CSI_CSIRXCNT_RD()      (HW_CSI_CSIRXCNT.U)
#define HW_CSI_CSIRXCNT_WR(v)     (HW_CSI_CSIRXCNT.U = (v))
#define HW_CSI_CSIRXCNT_SET(v)    (HW_CSI_CSIRXCNT_WR(HW_CSI_CSIRXCNT_RD() |  (v)))
#define HW_CSI_CSIRXCNT_CLR(v)    (HW_CSI_CSIRXCNT_WR(HW_CSI_CSIRXCNT_RD() & ~(v)))
#define HW_CSI_CSIRXCNT_TOG(v)    (HW_CSI_CSIRXCNT_WR(HW_CSI_CSIRXCNT_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSIRXCNT bitfields
 */

/* --- Register HW_CSI_CSIRXCNT, field RXCNT[21:0] (RW)
 *
 * RxFIFO Count. This 22-bit counter for RXFIFO is updated each time the RXFIFO is read by CPU or
 * DMA.This counter should be set to the expected number of words to receive that would generate an
 * EOF interrupt.
 */

#define BP_CSI_CSIRXCNT_RXCNT      (0)      //!< Bit position for CSI_CSIRXCNT_RXCNT.
#define BM_CSI_CSIRXCNT_RXCNT      (0x003fffff)  //!< Bit mask for CSI_CSIRXCNT_RXCNT.

//! @brief Get value of CSI_CSIRXCNT_RXCNT from a register value.
#define BG_CSI_CSIRXCNT_RXCNT(r)   (((r) & BM_CSI_CSIRXCNT_RXCNT) >> BP_CSI_CSIRXCNT_RXCNT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIRXCNT_RXCNT.
#define BF_CSI_CSIRXCNT_RXCNT(v)   ((((reg32_t) v) << BP_CSI_CSIRXCNT_RXCNT) & BM_CSI_CSIRXCNT_RXCNT)
#else
//! @brief Format value for bitfield CSI_CSIRXCNT_RXCNT.
#define BF_CSI_CSIRXCNT_RXCNT(v)   (((v) << BP_CSI_CSIRXCNT_RXCNT) & BM_CSI_CSIRXCNT_RXCNT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXCNT field to a new value.
#define BW_CSI_CSIRXCNT_RXCNT(v)   (HW_CSI_CSIRXCNT_WR((HW_CSI_CSIRXCNT_RD() & ~BM_CSI_CSIRXCNT_RXCNT) | BF_CSI_CSIRXCNT_RXCNT(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSISR - CSI Status Register (RW)
 *
 * Reset value: 0x00004000
 *
 * This read/write register shows sensor interface status, and which kind of interrupt is being
 * generated. The corresponding interrupt bits must be set for the status bit to function. Status
 * bits should function normally even if the corresponding interrupt enable bits are not enabled.
 */
typedef union _hw_csi_csisr
{
    reg32_t U;
    struct _hw_csi_csisr_bitfields
    {
        unsigned DRDY : 1; //!< [0] RXFIFO Data Ready. Indicates the presence of data that is ready for transfer in the RxFIFO. (Cleared automatically by reading FIFO)
        unsigned ECC_INT : 1; //!< [1] CCIR Error Interrupt. This bit indicates an error has occurred. This only works in CCIR Interlace mode. (Cleared by writing 1)
        unsigned RESERVED0 : 5; //!< [6:2] Reserved. These bits are reserved and should read 0.
        unsigned HRESP_ERR_INT : 1; //!< [7] Hresponse Error Interrupt Status. Indicates that a hresponse error has been detected. (Cleared by writing 1)
        unsigned RESERVED1 : 5; //!< [12:8] Reserved. These bits are reserved and should read 0.
        unsigned COF_INT : 1; //!< [13] Change Of Field Interrupt Status. Indicates that a change of the video field has been detected. Only works in CCIR Interlace mode. Software should read this bit first and then dispatch the new field from F1_INT and F2_INT. (Cleared by writing 1)
        unsigned F1_INT : 1; //!< [14] CCIR Field 1 Interrupt Status. Indicates the presence of field 1 of video in CCIR mode. (Cleared automatically when current field does not match) Only works in CCIR Interlace mode.
        unsigned F2_INT : 1; //!< [15] CCIR Field 2 Interrupt Status. Indicates the presence of field 2 of video in CCIR mode. (Cleared automatically when current field does not match) Only works in CCIR Interlace mode.
        unsigned SOF_INT : 1; //!< [16] Start of Frame Interrupt Status. Indicates when SOF is detected. (Cleared by writing 1)
        unsigned EOF_INT : 1; //!< [17] End of Frame (EOF) Interrupt Status. Indicates when EOF is detected. (Cleared by writing 1)
        unsigned RXFF_INT : 1; //!< [18] RXFIFO Full Interrupt Status. Indicates the number of data in the RxFIFO reaches the trigger level. (this bit is cleared automatically by reading the RxFIFO)
        unsigned DMA_TSF_DONE_FB1 : 1; //!< [19] DMA Transfer Done in Frame Buffer1. Indicates that the DMA transfer from RxFIFO to Frame Buffer1 is completed. It can trigger an interrupt if the corresponding enable bit is set in CSICR1. This bit can be cleared by by writting 1 or reflashing the RxFIFO dma controller in CSICR3. (Cleared by writing 1)
        unsigned DMA_TSF_DONE_FB2 : 1; //!< [20] DMA Transfer Done in Frame Buffer2. Indicates that the DMA transfer from RxFIFO to Frame Buffer2 is completed. It can trigger an interrupt if the corresponding enable bit is set in CSICR1. This bit can be cleared by by writting 1 or reflashing the RxFIFO dma controller in CSICR3. (Cleared by writing 1)
        unsigned STATFF_INT : 1; //!< [21] STATFIFO Full Interrupt Status. Indicates the number of data in the STATFIFO reaches the trigger level. (this bit is cleared automatically by reading the STATFIFO)
        unsigned DMA_TSF_DONE_SFF : 1; //!< [22] DMA Transfer Done from StatFIFO. Indicates that the dma transfer from StatFIFO is completed. It can trigger an interrupt if the corresponding enable bit is set in CSICR1. This bit can be cleared by writting 1 or reflashing the StatFIFO dma controller in CSICR3.(Cleared by writing 1)
        unsigned RESERVED2 : 1; //!< [23] Reserved. This bit is reserved and should read 0.
        unsigned RF_OR_INT : 1; //!< [24] RxFIFO Overrun Interrupt Status. Indicates the overflow status of the RxFIFO register. (Cleared by writing 1)
        unsigned SF_OR_INT : 1; //!< [25] STATFIFO Overrun Interrupt Status. Indicates the overflow status of the STATFIFO register. (Cleared by writing 1)
        unsigned RESERVED3 : 6; //!< [31:26] Reserved. These bits are reserved and should read 0.
    } B;
} hw_csi_csisr_t;
#endif

/*
 * constants & macros for entire CSI_CSISR register
 */
#define HW_CSI_CSISR_ADDR      (REGS_CSI_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSISR           (*(volatile hw_csi_csisr_t *) HW_CSI_CSISR_ADDR)
#define HW_CSI_CSISR_RD()      (HW_CSI_CSISR.U)
#define HW_CSI_CSISR_WR(v)     (HW_CSI_CSISR.U = (v))
#define HW_CSI_CSISR_SET(v)    (HW_CSI_CSISR_WR(HW_CSI_CSISR_RD() |  (v)))
#define HW_CSI_CSISR_CLR(v)    (HW_CSI_CSISR_WR(HW_CSI_CSISR_RD() & ~(v)))
#define HW_CSI_CSISR_TOG(v)    (HW_CSI_CSISR_WR(HW_CSI_CSISR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSISR bitfields
 */

/* --- Register HW_CSI_CSISR, field DRDY[0] (RW)
 *
 * RXFIFO Data Ready. Indicates the presence of data that is ready for transfer in the RxFIFO.
 * (Cleared automatically by reading FIFO)
 *
 * Values:
 * 0 - No data (word) is ready
 * 1 - At least 1 datum (word) is ready in RXFIFO.
 */

#define BP_CSI_CSISR_DRDY      (0)      //!< Bit position for CSI_CSISR_DRDY.
#define BM_CSI_CSISR_DRDY      (0x00000001)  //!< Bit mask for CSI_CSISR_DRDY.

//! @brief Get value of CSI_CSISR_DRDY from a register value.
#define BG_CSI_CSISR_DRDY(r)   (((r) & BM_CSI_CSISR_DRDY) >> BP_CSI_CSISR_DRDY)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_DRDY.
#define BF_CSI_CSISR_DRDY(v)   ((((reg32_t) v) << BP_CSI_CSISR_DRDY) & BM_CSI_CSISR_DRDY)
#else
//! @brief Format value for bitfield CSI_CSISR_DRDY.
#define BF_CSI_CSISR_DRDY(v)   (((v) << BP_CSI_CSISR_DRDY) & BM_CSI_CSISR_DRDY)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DRDY field to a new value.
#define BW_CSI_CSISR_DRDY(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_DRDY) | BF_CSI_CSISR_DRDY(v)))
#endif


/* --- Register HW_CSI_CSISR, field ECC_INT[1] (RW)
 *
 * CCIR Error Interrupt. This bit indicates an error has occurred. This only works in CCIR Interlace
 * mode. (Cleared by writing 1)
 *
 * Values:
 * 0 - No error detected
 * 1 - Error is detected in CCIR coding
 */

#define BP_CSI_CSISR_ECC_INT      (1)      //!< Bit position for CSI_CSISR_ECC_INT.
#define BM_CSI_CSISR_ECC_INT      (0x00000002)  //!< Bit mask for CSI_CSISR_ECC_INT.

//! @brief Get value of CSI_CSISR_ECC_INT from a register value.
#define BG_CSI_CSISR_ECC_INT(r)   (((r) & BM_CSI_CSISR_ECC_INT) >> BP_CSI_CSISR_ECC_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_ECC_INT.
#define BF_CSI_CSISR_ECC_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_ECC_INT) & BM_CSI_CSISR_ECC_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_ECC_INT.
#define BF_CSI_CSISR_ECC_INT(v)   (((v) << BP_CSI_CSISR_ECC_INT) & BM_CSI_CSISR_ECC_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ECC_INT field to a new value.
#define BW_CSI_CSISR_ECC_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_ECC_INT) | BF_CSI_CSISR_ECC_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field HRESP_ERR_INT[7] (RW)
 *
 * Hresponse Error Interrupt Status. Indicates that a hresponse error has been detected. (Cleared by
 * writing 1)
 *
 * Values:
 * 0 - No hresponse error.
 * 1 - Hresponse error is detected.
 */

#define BP_CSI_CSISR_HRESP_ERR_INT      (7)      //!< Bit position for CSI_CSISR_HRESP_ERR_INT.
#define BM_CSI_CSISR_HRESP_ERR_INT      (0x00000080)  //!< Bit mask for CSI_CSISR_HRESP_ERR_INT.

//! @brief Get value of CSI_CSISR_HRESP_ERR_INT from a register value.
#define BG_CSI_CSISR_HRESP_ERR_INT(r)   (((r) & BM_CSI_CSISR_HRESP_ERR_INT) >> BP_CSI_CSISR_HRESP_ERR_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_HRESP_ERR_INT.
#define BF_CSI_CSISR_HRESP_ERR_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_HRESP_ERR_INT) & BM_CSI_CSISR_HRESP_ERR_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_HRESP_ERR_INT.
#define BF_CSI_CSISR_HRESP_ERR_INT(v)   (((v) << BP_CSI_CSISR_HRESP_ERR_INT) & BM_CSI_CSISR_HRESP_ERR_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HRESP_ERR_INT field to a new value.
#define BW_CSI_CSISR_HRESP_ERR_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_HRESP_ERR_INT) | BF_CSI_CSISR_HRESP_ERR_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field COF_INT[13] (RW)
 *
 * Change Of Field Interrupt Status. Indicates that a change of the video field has been detected.
 * Only works in CCIR Interlace mode. Software should read this bit first and then dispatch the new
 * field from F1_INT and F2_INT. (Cleared by writing 1)
 *
 * Values:
 * 0 - Video field has no change.
 * 1 - Change of video field is detected.
 */

#define BP_CSI_CSISR_COF_INT      (13)      //!< Bit position for CSI_CSISR_COF_INT.
#define BM_CSI_CSISR_COF_INT      (0x00002000)  //!< Bit mask for CSI_CSISR_COF_INT.

//! @brief Get value of CSI_CSISR_COF_INT from a register value.
#define BG_CSI_CSISR_COF_INT(r)   (((r) & BM_CSI_CSISR_COF_INT) >> BP_CSI_CSISR_COF_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_COF_INT.
#define BF_CSI_CSISR_COF_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_COF_INT) & BM_CSI_CSISR_COF_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_COF_INT.
#define BF_CSI_CSISR_COF_INT(v)   (((v) << BP_CSI_CSISR_COF_INT) & BM_CSI_CSISR_COF_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COF_INT field to a new value.
#define BW_CSI_CSISR_COF_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_COF_INT) | BF_CSI_CSISR_COF_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field F1_INT[14] (RW)
 *
 * CCIR Field 1 Interrupt Status. Indicates the presence of field 1 of video in CCIR mode. (Cleared
 * automatically when current field does not match) Only works in CCIR Interlace mode.
 *
 * Values:
 * 0 - Field 1 of video is not detected.
 * 1 - Field 1 of video is about to start.
 */

#define BP_CSI_CSISR_F1_INT      (14)      //!< Bit position for CSI_CSISR_F1_INT.
#define BM_CSI_CSISR_F1_INT      (0x00004000)  //!< Bit mask for CSI_CSISR_F1_INT.

//! @brief Get value of CSI_CSISR_F1_INT from a register value.
#define BG_CSI_CSISR_F1_INT(r)   (((r) & BM_CSI_CSISR_F1_INT) >> BP_CSI_CSISR_F1_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_F1_INT.
#define BF_CSI_CSISR_F1_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_F1_INT) & BM_CSI_CSISR_F1_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_F1_INT.
#define BF_CSI_CSISR_F1_INT(v)   (((v) << BP_CSI_CSISR_F1_INT) & BM_CSI_CSISR_F1_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the F1_INT field to a new value.
#define BW_CSI_CSISR_F1_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_F1_INT) | BF_CSI_CSISR_F1_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field F2_INT[15] (RW)
 *
 * CCIR Field 2 Interrupt Status. Indicates the presence of field 2 of video in CCIR mode. (Cleared
 * automatically when current field does not match) Only works in CCIR Interlace mode.
 *
 * Values:
 * 0 - Field 2 of video is not detected
 * 1 - Field 2 of video is about to start
 */

#define BP_CSI_CSISR_F2_INT      (15)      //!< Bit position for CSI_CSISR_F2_INT.
#define BM_CSI_CSISR_F2_INT      (0x00008000)  //!< Bit mask for CSI_CSISR_F2_INT.

//! @brief Get value of CSI_CSISR_F2_INT from a register value.
#define BG_CSI_CSISR_F2_INT(r)   (((r) & BM_CSI_CSISR_F2_INT) >> BP_CSI_CSISR_F2_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_F2_INT.
#define BF_CSI_CSISR_F2_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_F2_INT) & BM_CSI_CSISR_F2_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_F2_INT.
#define BF_CSI_CSISR_F2_INT(v)   (((v) << BP_CSI_CSISR_F2_INT) & BM_CSI_CSISR_F2_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the F2_INT field to a new value.
#define BW_CSI_CSISR_F2_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_F2_INT) | BF_CSI_CSISR_F2_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field SOF_INT[16] (RW)
 *
 * Start of Frame Interrupt Status. Indicates when SOF is detected. (Cleared by writing 1)
 *
 * Values:
 * 0 - SOF is not detected.
 * 1 - SOF is detected.
 */

#define BP_CSI_CSISR_SOF_INT      (16)      //!< Bit position for CSI_CSISR_SOF_INT.
#define BM_CSI_CSISR_SOF_INT      (0x00010000)  //!< Bit mask for CSI_CSISR_SOF_INT.

//! @brief Get value of CSI_CSISR_SOF_INT from a register value.
#define BG_CSI_CSISR_SOF_INT(r)   (((r) & BM_CSI_CSISR_SOF_INT) >> BP_CSI_CSISR_SOF_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_SOF_INT.
#define BF_CSI_CSISR_SOF_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_SOF_INT) & BM_CSI_CSISR_SOF_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_SOF_INT.
#define BF_CSI_CSISR_SOF_INT(v)   (((v) << BP_CSI_CSISR_SOF_INT) & BM_CSI_CSISR_SOF_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOF_INT field to a new value.
#define BW_CSI_CSISR_SOF_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_SOF_INT) | BF_CSI_CSISR_SOF_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field EOF_INT[17] (RW)
 *
 * End of Frame (EOF) Interrupt Status. Indicates when EOF is detected. (Cleared by writing 1)
 *
 * Values:
 * 0 - EOF is not detected.
 * 1 - EOF is detected.
 */

#define BP_CSI_CSISR_EOF_INT      (17)      //!< Bit position for CSI_CSISR_EOF_INT.
#define BM_CSI_CSISR_EOF_INT      (0x00020000)  //!< Bit mask for CSI_CSISR_EOF_INT.

//! @brief Get value of CSI_CSISR_EOF_INT from a register value.
#define BG_CSI_CSISR_EOF_INT(r)   (((r) & BM_CSI_CSISR_EOF_INT) >> BP_CSI_CSISR_EOF_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_EOF_INT.
#define BF_CSI_CSISR_EOF_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_EOF_INT) & BM_CSI_CSISR_EOF_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_EOF_INT.
#define BF_CSI_CSISR_EOF_INT(v)   (((v) << BP_CSI_CSISR_EOF_INT) & BM_CSI_CSISR_EOF_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EOF_INT field to a new value.
#define BW_CSI_CSISR_EOF_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_EOF_INT) | BF_CSI_CSISR_EOF_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field RXFF_INT[18] (RW)
 *
 * RXFIFO Full Interrupt Status. Indicates the number of data in the RxFIFO reaches the trigger
 * level. (this bit is cleared automatically by reading the RxFIFO)
 *
 * Values:
 * 0 - RxFIFO is not full.
 * 1 - RxFIFO is full.
 */

#define BP_CSI_CSISR_RXFF_INT      (18)      //!< Bit position for CSI_CSISR_RXFF_INT.
#define BM_CSI_CSISR_RXFF_INT      (0x00040000)  //!< Bit mask for CSI_CSISR_RXFF_INT.

//! @brief Get value of CSI_CSISR_RXFF_INT from a register value.
#define BG_CSI_CSISR_RXFF_INT(r)   (((r) & BM_CSI_CSISR_RXFF_INT) >> BP_CSI_CSISR_RXFF_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_RXFF_INT.
#define BF_CSI_CSISR_RXFF_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_RXFF_INT) & BM_CSI_CSISR_RXFF_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_RXFF_INT.
#define BF_CSI_CSISR_RXFF_INT(v)   (((v) << BP_CSI_CSISR_RXFF_INT) & BM_CSI_CSISR_RXFF_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXFF_INT field to a new value.
#define BW_CSI_CSISR_RXFF_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_RXFF_INT) | BF_CSI_CSISR_RXFF_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field DMA_TSF_DONE_FB1[19] (RW)
 *
 * DMA Transfer Done in Frame Buffer1. Indicates that the DMA transfer from RxFIFO to Frame Buffer1
 * is completed. It can trigger an interrupt if the corresponding enable bit is set in CSICR1. This
 * bit can be cleared by by writting 1 or reflashing the RxFIFO dma controller in CSICR3. (Cleared
 * by writing 1)
 *
 * Values:
 * 0 - DMA transfer is not completed.
 * 1 - DMA transfer is completed.
 */

#define BP_CSI_CSISR_DMA_TSF_DONE_FB1      (19)      //!< Bit position for CSI_CSISR_DMA_TSF_DONE_FB1.
#define BM_CSI_CSISR_DMA_TSF_DONE_FB1      (0x00080000)  //!< Bit mask for CSI_CSISR_DMA_TSF_DONE_FB1.

//! @brief Get value of CSI_CSISR_DMA_TSF_DONE_FB1 from a register value.
#define BG_CSI_CSISR_DMA_TSF_DONE_FB1(r)   (((r) & BM_CSI_CSISR_DMA_TSF_DONE_FB1) >> BP_CSI_CSISR_DMA_TSF_DONE_FB1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_DMA_TSF_DONE_FB1.
#define BF_CSI_CSISR_DMA_TSF_DONE_FB1(v)   ((((reg32_t) v) << BP_CSI_CSISR_DMA_TSF_DONE_FB1) & BM_CSI_CSISR_DMA_TSF_DONE_FB1)
#else
//! @brief Format value for bitfield CSI_CSISR_DMA_TSF_DONE_FB1.
#define BF_CSI_CSISR_DMA_TSF_DONE_FB1(v)   (((v) << BP_CSI_CSISR_DMA_TSF_DONE_FB1) & BM_CSI_CSISR_DMA_TSF_DONE_FB1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_TSF_DONE_FB1 field to a new value.
#define BW_CSI_CSISR_DMA_TSF_DONE_FB1(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_DMA_TSF_DONE_FB1) | BF_CSI_CSISR_DMA_TSF_DONE_FB1(v)))
#endif


/* --- Register HW_CSI_CSISR, field DMA_TSF_DONE_FB2[20] (RW)
 *
 * DMA Transfer Done in Frame Buffer2. Indicates that the DMA transfer from RxFIFO to Frame Buffer2
 * is completed. It can trigger an interrupt if the corresponding enable bit is set in CSICR1. This
 * bit can be cleared by by writting 1 or reflashing the RxFIFO dma controller in CSICR3. (Cleared
 * by writing 1)
 *
 * Values:
 * 0 - DMA transfer is not completed.
 * 1 - DMA transfer is completed.
 */

#define BP_CSI_CSISR_DMA_TSF_DONE_FB2      (20)      //!< Bit position for CSI_CSISR_DMA_TSF_DONE_FB2.
#define BM_CSI_CSISR_DMA_TSF_DONE_FB2      (0x00100000)  //!< Bit mask for CSI_CSISR_DMA_TSF_DONE_FB2.

//! @brief Get value of CSI_CSISR_DMA_TSF_DONE_FB2 from a register value.
#define BG_CSI_CSISR_DMA_TSF_DONE_FB2(r)   (((r) & BM_CSI_CSISR_DMA_TSF_DONE_FB2) >> BP_CSI_CSISR_DMA_TSF_DONE_FB2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_DMA_TSF_DONE_FB2.
#define BF_CSI_CSISR_DMA_TSF_DONE_FB2(v)   ((((reg32_t) v) << BP_CSI_CSISR_DMA_TSF_DONE_FB2) & BM_CSI_CSISR_DMA_TSF_DONE_FB2)
#else
//! @brief Format value for bitfield CSI_CSISR_DMA_TSF_DONE_FB2.
#define BF_CSI_CSISR_DMA_TSF_DONE_FB2(v)   (((v) << BP_CSI_CSISR_DMA_TSF_DONE_FB2) & BM_CSI_CSISR_DMA_TSF_DONE_FB2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_TSF_DONE_FB2 field to a new value.
#define BW_CSI_CSISR_DMA_TSF_DONE_FB2(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_DMA_TSF_DONE_FB2) | BF_CSI_CSISR_DMA_TSF_DONE_FB2(v)))
#endif


/* --- Register HW_CSI_CSISR, field STATFF_INT[21] (RW)
 *
 * STATFIFO Full Interrupt Status. Indicates the number of data in the STATFIFO reaches the trigger
 * level. (this bit is cleared automatically by reading the STATFIFO)
 *
 * Values:
 * 0 - STATFIFO is not full.
 * 1 - STATFIFO is full.
 */

#define BP_CSI_CSISR_STATFF_INT      (21)      //!< Bit position for CSI_CSISR_STATFF_INT.
#define BM_CSI_CSISR_STATFF_INT      (0x00200000)  //!< Bit mask for CSI_CSISR_STATFF_INT.

//! @brief Get value of CSI_CSISR_STATFF_INT from a register value.
#define BG_CSI_CSISR_STATFF_INT(r)   (((r) & BM_CSI_CSISR_STATFF_INT) >> BP_CSI_CSISR_STATFF_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_STATFF_INT.
#define BF_CSI_CSISR_STATFF_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_STATFF_INT) & BM_CSI_CSISR_STATFF_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_STATFF_INT.
#define BF_CSI_CSISR_STATFF_INT(v)   (((v) << BP_CSI_CSISR_STATFF_INT) & BM_CSI_CSISR_STATFF_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STATFF_INT field to a new value.
#define BW_CSI_CSISR_STATFF_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_STATFF_INT) | BF_CSI_CSISR_STATFF_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field DMA_TSF_DONE_SFF[22] (RW)
 *
 * DMA Transfer Done from StatFIFO. Indicates that the dma transfer from StatFIFO is completed. It
 * can trigger an interrupt if the corresponding enable bit is set in CSICR1. This bit can be
 * cleared by writting 1 or reflashing the StatFIFO dma controller in CSICR3.(Cleared by writing 1)
 *
 * Values:
 * 0 - DMA transfer is not completed.
 * 1 - DMA transfer is completed.
 */

#define BP_CSI_CSISR_DMA_TSF_DONE_SFF      (22)      //!< Bit position for CSI_CSISR_DMA_TSF_DONE_SFF.
#define BM_CSI_CSISR_DMA_TSF_DONE_SFF      (0x00400000)  //!< Bit mask for CSI_CSISR_DMA_TSF_DONE_SFF.

//! @brief Get value of CSI_CSISR_DMA_TSF_DONE_SFF from a register value.
#define BG_CSI_CSISR_DMA_TSF_DONE_SFF(r)   (((r) & BM_CSI_CSISR_DMA_TSF_DONE_SFF) >> BP_CSI_CSISR_DMA_TSF_DONE_SFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_DMA_TSF_DONE_SFF.
#define BF_CSI_CSISR_DMA_TSF_DONE_SFF(v)   ((((reg32_t) v) << BP_CSI_CSISR_DMA_TSF_DONE_SFF) & BM_CSI_CSISR_DMA_TSF_DONE_SFF)
#else
//! @brief Format value for bitfield CSI_CSISR_DMA_TSF_DONE_SFF.
#define BF_CSI_CSISR_DMA_TSF_DONE_SFF(v)   (((v) << BP_CSI_CSISR_DMA_TSF_DONE_SFF) & BM_CSI_CSISR_DMA_TSF_DONE_SFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_TSF_DONE_SFF field to a new value.
#define BW_CSI_CSISR_DMA_TSF_DONE_SFF(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_DMA_TSF_DONE_SFF) | BF_CSI_CSISR_DMA_TSF_DONE_SFF(v)))
#endif


/* --- Register HW_CSI_CSISR, field RF_OR_INT[24] (RW)
 *
 * RxFIFO Overrun Interrupt Status. Indicates the overflow status of the RxFIFO register. (Cleared
 * by writing 1)
 *
 * Values:
 * 0 - RXFIFO has not overflowed.
 * 1 - RXFIFO has overflowed.
 */

#define BP_CSI_CSISR_RF_OR_INT      (24)      //!< Bit position for CSI_CSISR_RF_OR_INT.
#define BM_CSI_CSISR_RF_OR_INT      (0x01000000)  //!< Bit mask for CSI_CSISR_RF_OR_INT.

//! @brief Get value of CSI_CSISR_RF_OR_INT from a register value.
#define BG_CSI_CSISR_RF_OR_INT(r)   (((r) & BM_CSI_CSISR_RF_OR_INT) >> BP_CSI_CSISR_RF_OR_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_RF_OR_INT.
#define BF_CSI_CSISR_RF_OR_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_RF_OR_INT) & BM_CSI_CSISR_RF_OR_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_RF_OR_INT.
#define BF_CSI_CSISR_RF_OR_INT(v)   (((v) << BP_CSI_CSISR_RF_OR_INT) & BM_CSI_CSISR_RF_OR_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RF_OR_INT field to a new value.
#define BW_CSI_CSISR_RF_OR_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_RF_OR_INT) | BF_CSI_CSISR_RF_OR_INT(v)))
#endif


/* --- Register HW_CSI_CSISR, field SF_OR_INT[25] (RW)
 *
 * STATFIFO Overrun Interrupt Status. Indicates the overflow status of the STATFIFO register.
 * (Cleared by writing 1)
 *
 * Values:
 * 0 - STATFIFO has not overflowed.
 * 1 - STATFIFO has overflowed.
 */

#define BP_CSI_CSISR_SF_OR_INT      (25)      //!< Bit position for CSI_CSISR_SF_OR_INT.
#define BM_CSI_CSISR_SF_OR_INT      (0x02000000)  //!< Bit mask for CSI_CSISR_SF_OR_INT.

//! @brief Get value of CSI_CSISR_SF_OR_INT from a register value.
#define BG_CSI_CSISR_SF_OR_INT(r)   (((r) & BM_CSI_CSISR_SF_OR_INT) >> BP_CSI_CSISR_SF_OR_INT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSISR_SF_OR_INT.
#define BF_CSI_CSISR_SF_OR_INT(v)   ((((reg32_t) v) << BP_CSI_CSISR_SF_OR_INT) & BM_CSI_CSISR_SF_OR_INT)
#else
//! @brief Format value for bitfield CSI_CSISR_SF_OR_INT.
#define BF_CSI_CSISR_SF_OR_INT(v)   (((v) << BP_CSI_CSISR_SF_OR_INT) & BM_CSI_CSISR_SF_OR_INT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SF_OR_INT field to a new value.
#define BW_CSI_CSISR_SF_OR_INT(v)   (HW_CSI_CSISR_WR((HW_CSI_CSISR_RD() & ~BM_CSI_CSISR_SF_OR_INT) | BF_CSI_CSISR_SF_OR_INT(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIDMASA_STATFIFO - CSI DMA Start Address Register - for STATFIFO (RW)
 *
 * Reset value: 0x00000000
 *
 * This register provides the start address for the embedded DMA controller of STATFIFO. The
 * embedded DMA controller will read data from STATFIFO and write it to the external memory from the
 * start address. This register should be configured before activating or restarting the embedded
 * DMA controller.
 */
typedef union _hw_csi_csidmasa_statfifo
{
    reg32_t U;
    struct _hw_csi_csidmasa_statfifo_bitfields
    {
        unsigned RESERVED0 : 2; //!< [1:0] Reserved. These bits are reserved and should read 0.
        unsigned DMA_START_ADDR_SFF : 30; //!< [31:2] DMA Start Address for STATFIFO. Indicates the start address to write data. The embedded DMA controller will read data from STATFIFO and write it from this address through AHB bus. The address should be word aligned.
    } B;
} hw_csi_csidmasa_statfifo_t;
#endif

/*
 * constants & macros for entire CSI_CSIDMASA_STATFIFO register
 */
#define HW_CSI_CSIDMASA_STATFIFO_ADDR      (REGS_CSI_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIDMASA_STATFIFO           (*(volatile hw_csi_csidmasa_statfifo_t *) HW_CSI_CSIDMASA_STATFIFO_ADDR)
#define HW_CSI_CSIDMASA_STATFIFO_RD()      (HW_CSI_CSIDMASA_STATFIFO.U)
#define HW_CSI_CSIDMASA_STATFIFO_WR(v)     (HW_CSI_CSIDMASA_STATFIFO.U = (v))
#define HW_CSI_CSIDMASA_STATFIFO_SET(v)    (HW_CSI_CSIDMASA_STATFIFO_WR(HW_CSI_CSIDMASA_STATFIFO_RD() |  (v)))
#define HW_CSI_CSIDMASA_STATFIFO_CLR(v)    (HW_CSI_CSIDMASA_STATFIFO_WR(HW_CSI_CSIDMASA_STATFIFO_RD() & ~(v)))
#define HW_CSI_CSIDMASA_STATFIFO_TOG(v)    (HW_CSI_CSIDMASA_STATFIFO_WR(HW_CSI_CSIDMASA_STATFIFO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSIDMASA_STATFIFO bitfields
 */

/* --- Register HW_CSI_CSIDMASA_STATFIFO, field DMA_START_ADDR_SFF[31:2] (RW)
 *
 * DMA Start Address for STATFIFO. Indicates the start address to write data. The embedded DMA
 * controller will read data from STATFIFO and write it from this address through AHB bus. The
 * address should be word aligned.
 */

#define BP_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF      (2)      //!< Bit position for CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF.
#define BM_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF      (0xfffffffc)  //!< Bit mask for CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF.

//! @brief Get value of CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF from a register value.
#define BG_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF(r)   (((r) & BM_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF) >> BP_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF.
#define BF_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF(v)   ((((reg32_t) v) << BP_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF) & BM_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF)
#else
//! @brief Format value for bitfield CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF.
#define BF_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF(v)   (((v) << BP_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF) & BM_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_START_ADDR_SFF field to a new value.
#define BW_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF(v)   (HW_CSI_CSIDMASA_STATFIFO_WR((HW_CSI_CSIDMASA_STATFIFO_RD() & ~BM_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF) | BF_CSI_CSIDMASA_STATFIFO_DMA_START_ADDR_SFF(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIDMATS_STATFIFO - CSI DMA Transfer Size Register - for STATFIFO (RW)
 *
 * Reset value: 0x00000000
 *
 * This register provides the total transfer size for the embedded DMA controller of STATFIFO. This
 * register should be configured before activating or restarting the embedded DMA controller.
 */
typedef union _hw_csi_csidmats_statfifo
{
    reg32_t U;
    struct _hw_csi_csidmats_statfifo_bitfields
    {
        unsigned DMA_TSF_SIZE_SFF : 32; //!< [31:0] DMA Transfer Size for STATFIFO. Indicates how many words to be transfered by the embedded DMA controller. The size should be word aligned.
    } B;
} hw_csi_csidmats_statfifo_t;
#endif

/*
 * constants & macros for entire CSI_CSIDMATS_STATFIFO register
 */
#define HW_CSI_CSIDMATS_STATFIFO_ADDR      (REGS_CSI_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIDMATS_STATFIFO           (*(volatile hw_csi_csidmats_statfifo_t *) HW_CSI_CSIDMATS_STATFIFO_ADDR)
#define HW_CSI_CSIDMATS_STATFIFO_RD()      (HW_CSI_CSIDMATS_STATFIFO.U)
#define HW_CSI_CSIDMATS_STATFIFO_WR(v)     (HW_CSI_CSIDMATS_STATFIFO.U = (v))
#define HW_CSI_CSIDMATS_STATFIFO_SET(v)    (HW_CSI_CSIDMATS_STATFIFO_WR(HW_CSI_CSIDMATS_STATFIFO_RD() |  (v)))
#define HW_CSI_CSIDMATS_STATFIFO_CLR(v)    (HW_CSI_CSIDMATS_STATFIFO_WR(HW_CSI_CSIDMATS_STATFIFO_RD() & ~(v)))
#define HW_CSI_CSIDMATS_STATFIFO_TOG(v)    (HW_CSI_CSIDMATS_STATFIFO_WR(HW_CSI_CSIDMATS_STATFIFO_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSIDMATS_STATFIFO bitfields
 */

/* --- Register HW_CSI_CSIDMATS_STATFIFO, field DMA_TSF_SIZE_SFF[31:0] (RW)
 *
 * DMA Transfer Size for STATFIFO. Indicates how many words to be transfered by the embedded DMA
 * controller. The size should be word aligned.
 */

#define BP_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF      (0)      //!< Bit position for CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF.
#define BM_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF      (0xffffffff)  //!< Bit mask for CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF.

//! @brief Get value of CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF from a register value.
#define BG_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF(r)   (((r) & BM_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF) >> BP_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF.
#define BF_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF(v)   ((((reg32_t) v) << BP_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF) & BM_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF)
#else
//! @brief Format value for bitfield CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF.
#define BF_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF(v)   (((v) << BP_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF) & BM_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_TSF_SIZE_SFF field to a new value.
#define BW_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF(v)   (HW_CSI_CSIDMATS_STATFIFO_WR((HW_CSI_CSIDMATS_STATFIFO_RD() & ~BM_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF) | BF_CSI_CSIDMATS_STATFIFO_DMA_TSF_SIZE_SFF(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIDMASA_FB1 - CSI DMA Start Address Register - for Frame Buffer1 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register provides the start address in the frame buffer1 for the embedded DMA controller of
 * RxFIFO. The embedded DMA controller will read data from RxFIFO and write it to the frame buffer1
 * from the start address. This register should be configured before activating or restarting the
 * embedded DMA controller.
 */
typedef union _hw_csi_csidmasa_fb1
{
    reg32_t U;
    struct _hw_csi_csidmasa_fb1_bitfields
    {
        unsigned RESERVED0 : 2; //!< [1:0] Reserved. These bits are reserved and should read 0.
        unsigned DMA_START_ADDR_FB1 : 30; //!< [31:2] DMA Start Address in Frame Buffer1. Indicates the start address to write data. The embedded DMA controller will read data from RxFIFO and write it from this address through AHB bus. The address should be word aligned.
    } B;
} hw_csi_csidmasa_fb1_t;
#endif

/*
 * constants & macros for entire CSI_CSIDMASA_FB1 register
 */
#define HW_CSI_CSIDMASA_FB1_ADDR      (REGS_CSI_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIDMASA_FB1           (*(volatile hw_csi_csidmasa_fb1_t *) HW_CSI_CSIDMASA_FB1_ADDR)
#define HW_CSI_CSIDMASA_FB1_RD()      (HW_CSI_CSIDMASA_FB1.U)
#define HW_CSI_CSIDMASA_FB1_WR(v)     (HW_CSI_CSIDMASA_FB1.U = (v))
#define HW_CSI_CSIDMASA_FB1_SET(v)    (HW_CSI_CSIDMASA_FB1_WR(HW_CSI_CSIDMASA_FB1_RD() |  (v)))
#define HW_CSI_CSIDMASA_FB1_CLR(v)    (HW_CSI_CSIDMASA_FB1_WR(HW_CSI_CSIDMASA_FB1_RD() & ~(v)))
#define HW_CSI_CSIDMASA_FB1_TOG(v)    (HW_CSI_CSIDMASA_FB1_WR(HW_CSI_CSIDMASA_FB1_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSIDMASA_FB1 bitfields
 */

/* --- Register HW_CSI_CSIDMASA_FB1, field DMA_START_ADDR_FB1[31:2] (RW)
 *
 * DMA Start Address in Frame Buffer1. Indicates the start address to write data. The embedded DMA
 * controller will read data from RxFIFO and write it from this address through AHB bus. The address
 * should be word aligned.
 */

#define BP_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1      (2)      //!< Bit position for CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1.
#define BM_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1      (0xfffffffc)  //!< Bit mask for CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1.

//! @brief Get value of CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1 from a register value.
#define BG_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1(r)   (((r) & BM_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1) >> BP_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1.
#define BF_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1(v)   ((((reg32_t) v) << BP_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1) & BM_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1)
#else
//! @brief Format value for bitfield CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1.
#define BF_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1(v)   (((v) << BP_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1) & BM_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_START_ADDR_FB1 field to a new value.
#define BW_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1(v)   (HW_CSI_CSIDMASA_FB1_WR((HW_CSI_CSIDMASA_FB1_RD() & ~BM_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1) | BF_CSI_CSIDMASA_FB1_DMA_START_ADDR_FB1(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIDMASA_FB2 - CSI DMA Transfer Size Register - for Frame Buffer2 (RW)
 *
 * Reset value: 0x00000000
 *
 * This register provides the start address in the frame buffer2 for the embedded DMA controller of
 * RxFIFO. The embedded DMA controller will read data from RxFIFO and write it to the frame buffer2
 * from the start address. This register should be configured before activating or restarting the
 * embedded DMA controller.
 */
typedef union _hw_csi_csidmasa_fb2
{
    reg32_t U;
    struct _hw_csi_csidmasa_fb2_bitfields
    {
        unsigned RESERVED0 : 2; //!< [1:0] Reserved. These bits are reserved and should read 0.
        unsigned DMA_START_ADDR_FB2 : 30; //!< [31:2] DMA Start Address in Frame Buffer2. Indicates the start address to write data. The embedded DMA controller will read data from RxFIFO and write it from this address through AHB bus. The address should be word aligned.
    } B;
} hw_csi_csidmasa_fb2_t;
#endif

/*
 * constants & macros for entire CSI_CSIDMASA_FB2 register
 */
#define HW_CSI_CSIDMASA_FB2_ADDR      (REGS_CSI_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIDMASA_FB2           (*(volatile hw_csi_csidmasa_fb2_t *) HW_CSI_CSIDMASA_FB2_ADDR)
#define HW_CSI_CSIDMASA_FB2_RD()      (HW_CSI_CSIDMASA_FB2.U)
#define HW_CSI_CSIDMASA_FB2_WR(v)     (HW_CSI_CSIDMASA_FB2.U = (v))
#define HW_CSI_CSIDMASA_FB2_SET(v)    (HW_CSI_CSIDMASA_FB2_WR(HW_CSI_CSIDMASA_FB2_RD() |  (v)))
#define HW_CSI_CSIDMASA_FB2_CLR(v)    (HW_CSI_CSIDMASA_FB2_WR(HW_CSI_CSIDMASA_FB2_RD() & ~(v)))
#define HW_CSI_CSIDMASA_FB2_TOG(v)    (HW_CSI_CSIDMASA_FB2_WR(HW_CSI_CSIDMASA_FB2_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSIDMASA_FB2 bitfields
 */

/* --- Register HW_CSI_CSIDMASA_FB2, field DMA_START_ADDR_FB2[31:2] (RW)
 *
 * DMA Start Address in Frame Buffer2. Indicates the start address to write data. The embedded DMA
 * controller will read data from RxFIFO and write it from this address through AHB bus. The address
 * should be word aligned.
 */

#define BP_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2      (2)      //!< Bit position for CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2.
#define BM_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2      (0xfffffffc)  //!< Bit mask for CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2.

//! @brief Get value of CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2 from a register value.
#define BG_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2(r)   (((r) & BM_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2) >> BP_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2.
#define BF_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2(v)   ((((reg32_t) v) << BP_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2) & BM_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2)
#else
//! @brief Format value for bitfield CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2.
#define BF_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2(v)   (((v) << BP_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2) & BM_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMA_START_ADDR_FB2 field to a new value.
#define BW_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2(v)   (HW_CSI_CSIDMASA_FB2_WR((HW_CSI_CSIDMASA_FB2_RD() & ~BM_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2) | BF_CSI_CSIDMASA_FB2_DMA_START_ADDR_FB2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIFBUF_PARA - CSI Frame Buffer Parameter Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register provides the stride of the frame buffer to show how many words to skip before
 * starting to write the next row of the image. The width of the frame buffer minus the width of the
 * image is the stride. This register should be configured before activating or restarting the
 * embedded DMA controller.
 */
typedef union _hw_csi_csifbuf_para
{
    reg32_t U;
    struct _hw_csi_csifbuf_para_bitfields
    {
        unsigned FBUF_STRIDE : 16; //!< [15:0] Frame Buffer Parameter. Indicates the stride of the frame buffer. The width of the frame buffer(in word) minus the width of the image(in word) is the stride. The stride should be word aligned. The embedded DMA controller will skip the stride before starting to write the next row of the image.
        unsigned RESERVED0 : 16; //!< [31:16] Reserved. These bits are reserved and should read 0.
    } B;
} hw_csi_csifbuf_para_t;
#endif

/*
 * constants & macros for entire CSI_CSIFBUF_PARA register
 */
#define HW_CSI_CSIFBUF_PARA_ADDR      (REGS_CSI_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIFBUF_PARA           (*(volatile hw_csi_csifbuf_para_t *) HW_CSI_CSIFBUF_PARA_ADDR)
#define HW_CSI_CSIFBUF_PARA_RD()      (HW_CSI_CSIFBUF_PARA.U)
#define HW_CSI_CSIFBUF_PARA_WR(v)     (HW_CSI_CSIFBUF_PARA.U = (v))
#define HW_CSI_CSIFBUF_PARA_SET(v)    (HW_CSI_CSIFBUF_PARA_WR(HW_CSI_CSIFBUF_PARA_RD() |  (v)))
#define HW_CSI_CSIFBUF_PARA_CLR(v)    (HW_CSI_CSIFBUF_PARA_WR(HW_CSI_CSIFBUF_PARA_RD() & ~(v)))
#define HW_CSI_CSIFBUF_PARA_TOG(v)    (HW_CSI_CSIFBUF_PARA_WR(HW_CSI_CSIFBUF_PARA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSIFBUF_PARA bitfields
 */

/* --- Register HW_CSI_CSIFBUF_PARA, field FBUF_STRIDE[15:0] (RW)
 *
 * Frame Buffer Parameter. Indicates the stride of the frame buffer. The width of the frame
 * buffer(in word) minus the width of the image(in word) is the stride. The stride should be word
 * aligned. The embedded DMA controller will skip the stride before starting to write the next row
 * of the image.
 */

#define BP_CSI_CSIFBUF_PARA_FBUF_STRIDE      (0)      //!< Bit position for CSI_CSIFBUF_PARA_FBUF_STRIDE.
#define BM_CSI_CSIFBUF_PARA_FBUF_STRIDE      (0x0000ffff)  //!< Bit mask for CSI_CSIFBUF_PARA_FBUF_STRIDE.

//! @brief Get value of CSI_CSIFBUF_PARA_FBUF_STRIDE from a register value.
#define BG_CSI_CSIFBUF_PARA_FBUF_STRIDE(r)   (((r) & BM_CSI_CSIFBUF_PARA_FBUF_STRIDE) >> BP_CSI_CSIFBUF_PARA_FBUF_STRIDE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIFBUF_PARA_FBUF_STRIDE.
#define BF_CSI_CSIFBUF_PARA_FBUF_STRIDE(v)   ((((reg32_t) v) << BP_CSI_CSIFBUF_PARA_FBUF_STRIDE) & BM_CSI_CSIFBUF_PARA_FBUF_STRIDE)
#else
//! @brief Format value for bitfield CSI_CSIFBUF_PARA_FBUF_STRIDE.
#define BF_CSI_CSIFBUF_PARA_FBUF_STRIDE(v)   (((v) << BP_CSI_CSIFBUF_PARA_FBUF_STRIDE) & BM_CSI_CSIFBUF_PARA_FBUF_STRIDE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FBUF_STRIDE field to a new value.
#define BW_CSI_CSIFBUF_PARA_FBUF_STRIDE(v)   (HW_CSI_CSIFBUF_PARA_WR((HW_CSI_CSIFBUF_PARA_RD() & ~BM_CSI_CSIFBUF_PARA_FBUF_STRIDE) | BF_CSI_CSIFBUF_PARA_FBUF_STRIDE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_CSI_CSIIMAG_PARA - CSI Image Parameter Register (RW)
 *
 * Reset value: 0x00000000
 *
 * This register provides the width and the height of the image from the sensor. The width and
 * height should be aligned in pixel. The width of the image multiplied by the height is the total
 * pixel size that will be transfered in a frame by the embedded DMA controller. This register
 * should be configured before activating or restarting the embedded DMA controller.
 */
typedef union _hw_csi_csiimag_para
{
    reg32_t U;
    struct _hw_csi_csiimag_para_bitfields
    {
        unsigned IMAGE_HEIGHT : 16; //!< [15:0] Image Height. Indicates how many pixels in a column of the image from the sensor.
        unsigned IMAGE_WIDTH : 16; //!< [31:16] Image Width. Indicates how many pixels in a line of the image from the sensor. If the input data from the sensor is 8-bit/pixel format, the IMAGE_WIDTH should be a multiple of 4 pixels. If the input data from the sensor is 10-bit/pixel or 16-bit/pixel format, the IMAGE_WIDTH should be a multiple of 2 pixels.
    } B;
} hw_csi_csiimag_para_t;
#endif

/*
 * constants & macros for entire CSI_CSIIMAG_PARA register
 */
#define HW_CSI_CSIIMAG_PARA_ADDR      (REGS_CSI_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_CSI_CSIIMAG_PARA           (*(volatile hw_csi_csiimag_para_t *) HW_CSI_CSIIMAG_PARA_ADDR)
#define HW_CSI_CSIIMAG_PARA_RD()      (HW_CSI_CSIIMAG_PARA.U)
#define HW_CSI_CSIIMAG_PARA_WR(v)     (HW_CSI_CSIIMAG_PARA.U = (v))
#define HW_CSI_CSIIMAG_PARA_SET(v)    (HW_CSI_CSIIMAG_PARA_WR(HW_CSI_CSIIMAG_PARA_RD() |  (v)))
#define HW_CSI_CSIIMAG_PARA_CLR(v)    (HW_CSI_CSIIMAG_PARA_WR(HW_CSI_CSIIMAG_PARA_RD() & ~(v)))
#define HW_CSI_CSIIMAG_PARA_TOG(v)    (HW_CSI_CSIIMAG_PARA_WR(HW_CSI_CSIIMAG_PARA_RD() ^  (v)))
#endif

/*
 * constants & macros for individual CSI_CSIIMAG_PARA bitfields
 */

/* --- Register HW_CSI_CSIIMAG_PARA, field IMAGE_HEIGHT[15:0] (RW)
 *
 * Image Height. Indicates how many pixels in a column of the image from the sensor.
 */

#define BP_CSI_CSIIMAG_PARA_IMAGE_HEIGHT      (0)      //!< Bit position for CSI_CSIIMAG_PARA_IMAGE_HEIGHT.
#define BM_CSI_CSIIMAG_PARA_IMAGE_HEIGHT      (0x0000ffff)  //!< Bit mask for CSI_CSIIMAG_PARA_IMAGE_HEIGHT.

//! @brief Get value of CSI_CSIIMAG_PARA_IMAGE_HEIGHT from a register value.
#define BG_CSI_CSIIMAG_PARA_IMAGE_HEIGHT(r)   (((r) & BM_CSI_CSIIMAG_PARA_IMAGE_HEIGHT) >> BP_CSI_CSIIMAG_PARA_IMAGE_HEIGHT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIIMAG_PARA_IMAGE_HEIGHT.
#define BF_CSI_CSIIMAG_PARA_IMAGE_HEIGHT(v)   ((((reg32_t) v) << BP_CSI_CSIIMAG_PARA_IMAGE_HEIGHT) & BM_CSI_CSIIMAG_PARA_IMAGE_HEIGHT)
#else
//! @brief Format value for bitfield CSI_CSIIMAG_PARA_IMAGE_HEIGHT.
#define BF_CSI_CSIIMAG_PARA_IMAGE_HEIGHT(v)   (((v) << BP_CSI_CSIIMAG_PARA_IMAGE_HEIGHT) & BM_CSI_CSIIMAG_PARA_IMAGE_HEIGHT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IMAGE_HEIGHT field to a new value.
#define BW_CSI_CSIIMAG_PARA_IMAGE_HEIGHT(v)   (HW_CSI_CSIIMAG_PARA_WR((HW_CSI_CSIIMAG_PARA_RD() & ~BM_CSI_CSIIMAG_PARA_IMAGE_HEIGHT) | BF_CSI_CSIIMAG_PARA_IMAGE_HEIGHT(v)))
#endif

/* --- Register HW_CSI_CSIIMAG_PARA, field IMAGE_WIDTH[31:16] (RW)
 *
 * Image Width. Indicates how many pixels in a line of the image from the sensor. If the input data
 * from the sensor is 8-bit/pixel format, the IMAGE_WIDTH should be a multiple of 4 pixels. If the
 * input data from the sensor is 10-bit/pixel or 16-bit/pixel format, the IMAGE_WIDTH should be a
 * multiple of 2 pixels.
 */

#define BP_CSI_CSIIMAG_PARA_IMAGE_WIDTH      (16)      //!< Bit position for CSI_CSIIMAG_PARA_IMAGE_WIDTH.
#define BM_CSI_CSIIMAG_PARA_IMAGE_WIDTH      (0xffff0000)  //!< Bit mask for CSI_CSIIMAG_PARA_IMAGE_WIDTH.

//! @brief Get value of CSI_CSIIMAG_PARA_IMAGE_WIDTH from a register value.
#define BG_CSI_CSIIMAG_PARA_IMAGE_WIDTH(r)   (((r) & BM_CSI_CSIIMAG_PARA_IMAGE_WIDTH) >> BP_CSI_CSIIMAG_PARA_IMAGE_WIDTH)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield CSI_CSIIMAG_PARA_IMAGE_WIDTH.
#define BF_CSI_CSIIMAG_PARA_IMAGE_WIDTH(v)   ((((reg32_t) v) << BP_CSI_CSIIMAG_PARA_IMAGE_WIDTH) & BM_CSI_CSIIMAG_PARA_IMAGE_WIDTH)
#else
//! @brief Format value for bitfield CSI_CSIIMAG_PARA_IMAGE_WIDTH.
#define BF_CSI_CSIIMAG_PARA_IMAGE_WIDTH(v)   (((v) << BP_CSI_CSIIMAG_PARA_IMAGE_WIDTH) & BM_CSI_CSIIMAG_PARA_IMAGE_WIDTH)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IMAGE_WIDTH field to a new value.
#define BW_CSI_CSIIMAG_PARA_IMAGE_WIDTH(v)   (HW_CSI_CSIIMAG_PARA_WR((HW_CSI_CSIIMAG_PARA_RD() & ~BM_CSI_CSIIMAG_PARA_IMAGE_WIDTH) | BF_CSI_CSIIMAG_PARA_IMAGE_WIDTH(v)))
#endif


/*!
 * @brief All CSI module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_csi
{
    volatile hw_csi_csicr1_t CSICR1; //!< CSI Control Register 1
    volatile hw_csi_csicr2_t CSICR2; //!< CSI Control Register 2
    volatile hw_csi_csicr3_t CSICR3; //!< CSI Control Register 3
    volatile hw_csi_csistatfifo_t CSISTATFIFO; //!< CSI Statistic FIFO Register
    volatile hw_csi_csirfifo_t CSIRFIFO; //!< CSI RX FIFO Register
    volatile hw_csi_csirxcnt_t CSIRXCNT; //!< CSI RX Count Register
    volatile hw_csi_csisr_t CSISR; //!< CSI Status Register
    reg32_t _reserved0;
    volatile hw_csi_csidmasa_statfifo_t CSIDMASA_STATFIFO; //!< CSI DMA Start Address Register - for STATFIFO
    volatile hw_csi_csidmats_statfifo_t CSIDMATS_STATFIFO; //!< CSI DMA Transfer Size Register - for STATFIFO
    volatile hw_csi_csidmasa_fb1_t CSIDMASA_FB1; //!< CSI DMA Start Address Register - for Frame Buffer1
    volatile hw_csi_csidmasa_fb2_t CSIDMASA_FB2; //!< CSI DMA Transfer Size Register - for Frame Buffer2
    volatile hw_csi_csifbuf_para_t CSIFBUF_PARA; //!< CSI Frame Buffer Parameter Register
    volatile hw_csi_csiimag_para_t CSIIMAG_PARA; //!< CSI Image Parameter Register
} hw_csi_t;
#pragma pack()
#endif

//! @brief Macro to access all CSI registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_CSI(0)</code>.
#define HW_CSI     (*(volatile hw_csi_t *) REGS_CSI_BASE)


#endif // _CSI_H