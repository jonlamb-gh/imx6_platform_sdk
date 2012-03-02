/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _ENET_H
#define _ENET_H

#include "regs.h"

/*
 * i.MX6SDL ENET registers defined in this header file.
 *
 * - HW_ENET_EIR - Interrupt Event Register
 * - HW_ENET_EIMR - Interrupt Mask Register
 * - HW_ENET_RDAR - Receive Descriptor Active Register
 * - HW_ENET_TDAR - Transmit Descriptor Active Register
 * - HW_ENET_ECR - Ethernet Control Register
 * - HW_ENET_MMFR - MII Management Frame Register
 * - HW_ENET_MSCR - MII Speed Control Register
 * - HW_ENET_MIBC - MIB Control Register
 * - HW_ENET_RCR - Receive Control Register
 * - HW_ENET_TCR - Transmit Control Register
 * - HW_ENET_PALR - Physical Address Lower Register
 * - HW_ENET_PAUR - Physical Address Upper Register
 * - HW_ENET_OPD - Opcode/Pause Duration Register
 * - HW_ENET_IAUR - Descriptor Individual Upper Address Register
 * - HW_ENET_IALR - Descriptor Individual Lower Address Register
 * - HW_ENET_GAUR - Descriptor Group Upper Address Register
 * - HW_ENET_GALR - Descriptor Group Lower Address Register
 * - HW_ENET_TFWR - Transmit FIFO Watermark Register
 * - HW_ENET_RDSR - Receive Descriptor Ring Start Register
 * - HW_ENET_TDSR - Transmit Buffer Descriptor Ring Start Register
 * - HW_ENET_MRBR - Maximum Receive Buffer Size Register
 * - HW_ENET_RSFL - Receive FIFO Section Full Threshold
 * - HW_ENET_RSEM - Receive FIFO Section Empty Threshold
 * - HW_ENET_RAEM - Receive FIFO Almost Empty Threshold
 * - HW_ENET_RAFL - Receive FIFO Almost Full Threshold
 * - HW_ENET_TSEM - Transmit FIFO Section Empty Threshold
 * - HW_ENET_TAEM - Transmit FIFO Almost Empty Threshold
 * - HW_ENET_TAFL - Transmit FIFO Almost Full Threshold
 * - HW_ENET_TIPG - Transmit Inter-Packet Gap
 * - HW_ENET_FTRL - Frame Truncation Length
 * - HW_ENET_TACC - Transmit Accelerator Function Configuration
 * - HW_ENET_RACC - Receive Accelerator Function Configuration
 * - HW_ENET_ATCR - Timer Control Register
 * - HW_ENET_ATVR - Timer Value Register
 * - HW_ENET_ATOFF - Timer Offset Register
 * - HW_ENET_ATPER - Timer Period Register
 * - HW_ENET_ATCOR - Timer Correction Register
 * - HW_ENET_ATINC - Time-Stamping Clock Period Register
 * - HW_ENET_ATSTMP - Timestamp of Last Transmitted Frame
 *
 * hw_enet_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_ENET_BASE
#define REGS_ENET_BASE (0x02188000) //!< Base address for ENET.
#endif
//@}

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_EIR - Interrupt Event Register (W1C)
 *
 * Reset value: 0x00000000
 *
 * When an event occurs that sets a bit in EIR, an interrupt occurs if the corresponding bit in the
 * interrupt mask register (EIMR) is also set. Writing a 1 to an EIR bit clears it; writing 0 has no
 * effect. This register is cleared upon hardware reset.  Clearing the interrupt bits requires one
 * pclk clock cycle after the write transaction completes. An immediate read after the write to the
 * register returns the old value if there is not at least one pclk cycle between the two
 * transactions.
 */
typedef union _hw_enet_eir
{
    reg32_t U;
    struct _hw_enet_eir_bitfields
    {
        unsigned RESERVED0 : 15; //!< [14:0] 
        unsigned TS_TIMER : 1; //!< [15] The adjustable timer reached the period event. A period event interrupt can be generated if ATCR[PEREN] is set and the timer wraps according to the periodic setting in the ATPER register. Set the timer period value before setting ATCR[PEREN].
        unsigned TS_AVAIL : 1; //!< [16] Indicates that the timestamp of the last transmitted timing frame is available in the ATSTMP register.
        unsigned WAKEUP : 1; //!< [17] Read-only status bit to indicate that a magic packet has been detected. Will act only if ECR[MAGICEN] is set.
        unsigned PLR : 1; //!< [18] Indicates a frame was received with a payload length error. See Frame Length/Type Verification: Payload Length Check for more information.
        unsigned UN : 1; //!< [19] Indicates the transmit FIFO became empty before the complete frame was transmitted. A bad CRC is appended to the frame fragment and the remainder of the frame is discarded.
        unsigned RL : 1; //!< [20] Indicates a collision occurred on each of 16 successive attempts to transmit the frame. The frame is discarded without being transmitted and transmission of the next frame commences. This error can only occur in half-duplex mode.
        unsigned LC : 1; //!< [21] Indicates a collision occurred beyond the collision window (slot time) in half-duplex mode. The frame truncates with a bad CRC and the remainder of the frame is discarded.
        unsigned EBERR : 1; //!< [22] Indicates a system bus error occurred when a uDMA transaction is underway. (Signal dma_eberr_int asserted.) When this bit is set, ECR[ETHER_EN] is cleared, halting frame processing by the MAC. When this occurs, software must ensure proper actions, possibly resetting the system, to resume normal operation.
        unsigned MII : 1; //!< [23] Indicates that the MII has completed the data transfer requested.
        unsigned RXB : 1; //!< [24] Indicates a receive buffer descriptor is not the last in the frame has been updated. (Signal dma_rxb_int asserted)
        unsigned RXF : 1; //!< [25] Indicates a frame has been received and the last corresponding buffer descriptor has been updated. (Signal dma_rxf_int asserted)
        unsigned TXB : 1; //!< [26] Indicates a transmit buffer descriptor has been updated. (Signal dma_txb_int asserted)
        unsigned TXF : 1; //!< [27] Indicates a frame has been transmitted and the last corresponding buffer descriptor has been updated. (Signal dma_txf_int asserted)
        unsigned GRA : 1; //!< [28] This interrupt is asserted after the transmitter is put into a pause state after completion of the frame currently being transmitted. See Graceful Transmit Stop (GTS) for conditions that lead to graceful stop. The GRA interrupt is asserted only when the TX transitions into the stopped state. If this bit is cleared by writing 1 and the TX is still stopped, the bit is not set again.
        unsigned BABT : 1; //!< [29] Indicates the transmitted frame length exceeds RCR[MAX_FL] bytes. Usually this condition is caused when a frame that is too long is placed into the transmit data buffer(s). Truncation does not occur.
        unsigned BABR : 1; //!< [30] Indicates a frame was received with length in excess of RCR[MAX_FL] bytes.
        unsigned RESERVED1 : 1; //!< [31] 
    } B;
} hw_enet_eir_t;
#endif

/*
 * constants & macros for entire ENET_EIR register
 */
#define HW_ENET_EIR_ADDR      (REGS_ENET_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_EIR           (*(volatile hw_enet_eir_t *) HW_ENET_EIR_ADDR)
#define HW_ENET_EIR_RD()      (HW_ENET_EIR.U)
#define HW_ENET_EIR_WR(v)     (HW_ENET_EIR.U = (v))
#define HW_ENET_EIR_SET(v)    (HW_ENET_EIR_WR(HW_ENET_EIR_RD() |  (v)))
#define HW_ENET_EIR_CLR(v)    (HW_ENET_EIR_WR(HW_ENET_EIR_RD() & ~(v)))
#define HW_ENET_EIR_TOG(v)    (HW_ENET_EIR_WR(HW_ENET_EIR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_EIR bitfields
 */

/* --- Register HW_ENET_EIR, field TS_TIMER[15] (W1C)
 *
 * The adjustable timer reached the period event. A period event interrupt can be generated if
 * ATCR[PEREN] is set and the timer wraps according to the periodic setting in the ATPER register.
 * Set the timer period value before setting ATCR[PEREN].
 */

#define BP_ENET_EIR_TS_TIMER      (15)      //!< Bit position for ENET_EIR_TS_TIMER.
#define BM_ENET_EIR_TS_TIMER      (0x00008000)  //!< Bit mask for ENET_EIR_TS_TIMER.

//! @brief Get value of ENET_EIR_TS_TIMER from a register value.
#define BG_ENET_EIR_TS_TIMER(r)   (((r) & BM_ENET_EIR_TS_TIMER) >> BP_ENET_EIR_TS_TIMER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_TS_TIMER.
#define BF_ENET_EIR_TS_TIMER(v)   ((((reg32_t) v) << BP_ENET_EIR_TS_TIMER) & BM_ENET_EIR_TS_TIMER)
#else
//! @brief Format value for bitfield ENET_EIR_TS_TIMER.
#define BF_ENET_EIR_TS_TIMER(v)   (((v) << BP_ENET_EIR_TS_TIMER) & BM_ENET_EIR_TS_TIMER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TS_TIMER field to a new value.
#define BW_ENET_EIR_TS_TIMER(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_TS_TIMER) | BF_ENET_EIR_TS_TIMER(v)))
#endif

/* --- Register HW_ENET_EIR, field TS_AVAIL[16] (W1C)
 *
 * Indicates that the timestamp of the last transmitted timing frame is available in the ATSTMP
 * register.
 */

#define BP_ENET_EIR_TS_AVAIL      (16)      //!< Bit position for ENET_EIR_TS_AVAIL.
#define BM_ENET_EIR_TS_AVAIL      (0x00010000)  //!< Bit mask for ENET_EIR_TS_AVAIL.

//! @brief Get value of ENET_EIR_TS_AVAIL from a register value.
#define BG_ENET_EIR_TS_AVAIL(r)   (((r) & BM_ENET_EIR_TS_AVAIL) >> BP_ENET_EIR_TS_AVAIL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_TS_AVAIL.
#define BF_ENET_EIR_TS_AVAIL(v)   ((((reg32_t) v) << BP_ENET_EIR_TS_AVAIL) & BM_ENET_EIR_TS_AVAIL)
#else
//! @brief Format value for bitfield ENET_EIR_TS_AVAIL.
#define BF_ENET_EIR_TS_AVAIL(v)   (((v) << BP_ENET_EIR_TS_AVAIL) & BM_ENET_EIR_TS_AVAIL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TS_AVAIL field to a new value.
#define BW_ENET_EIR_TS_AVAIL(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_TS_AVAIL) | BF_ENET_EIR_TS_AVAIL(v)))
#endif

/* --- Register HW_ENET_EIR, field WAKEUP[17] (W1C)
 *
 * Read-only status bit to indicate that a magic packet has been detected. Will act only if
 * ECR[MAGICEN] is set.
 */

#define BP_ENET_EIR_WAKEUP      (17)      //!< Bit position for ENET_EIR_WAKEUP.
#define BM_ENET_EIR_WAKEUP      (0x00020000)  //!< Bit mask for ENET_EIR_WAKEUP.

//! @brief Get value of ENET_EIR_WAKEUP from a register value.
#define BG_ENET_EIR_WAKEUP(r)   (((r) & BM_ENET_EIR_WAKEUP) >> BP_ENET_EIR_WAKEUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_WAKEUP.
#define BF_ENET_EIR_WAKEUP(v)   ((((reg32_t) v) << BP_ENET_EIR_WAKEUP) & BM_ENET_EIR_WAKEUP)
#else
//! @brief Format value for bitfield ENET_EIR_WAKEUP.
#define BF_ENET_EIR_WAKEUP(v)   (((v) << BP_ENET_EIR_WAKEUP) & BM_ENET_EIR_WAKEUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP field to a new value.
#define BW_ENET_EIR_WAKEUP(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_WAKEUP) | BF_ENET_EIR_WAKEUP(v)))
#endif

/* --- Register HW_ENET_EIR, field PLR[18] (W1C)
 *
 * Indicates a frame was received with a payload length error. See Frame Length/Type Verification:
 * Payload Length Check for more information.
 */

#define BP_ENET_EIR_PLR      (18)      //!< Bit position for ENET_EIR_PLR.
#define BM_ENET_EIR_PLR      (0x00040000)  //!< Bit mask for ENET_EIR_PLR.

//! @brief Get value of ENET_EIR_PLR from a register value.
#define BG_ENET_EIR_PLR(r)   (((r) & BM_ENET_EIR_PLR) >> BP_ENET_EIR_PLR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_PLR.
#define BF_ENET_EIR_PLR(v)   ((((reg32_t) v) << BP_ENET_EIR_PLR) & BM_ENET_EIR_PLR)
#else
//! @brief Format value for bitfield ENET_EIR_PLR.
#define BF_ENET_EIR_PLR(v)   (((v) << BP_ENET_EIR_PLR) & BM_ENET_EIR_PLR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLR field to a new value.
#define BW_ENET_EIR_PLR(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_PLR) | BF_ENET_EIR_PLR(v)))
#endif

/* --- Register HW_ENET_EIR, field UN[19] (W1C)
 *
 * Indicates the transmit FIFO became empty before the complete frame was transmitted. A bad CRC is
 * appended to the frame fragment and the remainder of the frame is discarded.
 */

#define BP_ENET_EIR_UN      (19)      //!< Bit position for ENET_EIR_UN.
#define BM_ENET_EIR_UN      (0x00080000)  //!< Bit mask for ENET_EIR_UN.

//! @brief Get value of ENET_EIR_UN from a register value.
#define BG_ENET_EIR_UN(r)   (((r) & BM_ENET_EIR_UN) >> BP_ENET_EIR_UN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_UN.
#define BF_ENET_EIR_UN(v)   ((((reg32_t) v) << BP_ENET_EIR_UN) & BM_ENET_EIR_UN)
#else
//! @brief Format value for bitfield ENET_EIR_UN.
#define BF_ENET_EIR_UN(v)   (((v) << BP_ENET_EIR_UN) & BM_ENET_EIR_UN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UN field to a new value.
#define BW_ENET_EIR_UN(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_UN) | BF_ENET_EIR_UN(v)))
#endif

/* --- Register HW_ENET_EIR, field RL[20] (W1C)
 *
 * Indicates a collision occurred on each of 16 successive attempts to transmit the frame. The frame
 * is discarded without being transmitted and transmission of the next frame commences. This error
 * can only occur in half-duplex mode.
 */

#define BP_ENET_EIR_RL      (20)      //!< Bit position for ENET_EIR_RL.
#define BM_ENET_EIR_RL      (0x00100000)  //!< Bit mask for ENET_EIR_RL.

//! @brief Get value of ENET_EIR_RL from a register value.
#define BG_ENET_EIR_RL(r)   (((r) & BM_ENET_EIR_RL) >> BP_ENET_EIR_RL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_RL.
#define BF_ENET_EIR_RL(v)   ((((reg32_t) v) << BP_ENET_EIR_RL) & BM_ENET_EIR_RL)
#else
//! @brief Format value for bitfield ENET_EIR_RL.
#define BF_ENET_EIR_RL(v)   (((v) << BP_ENET_EIR_RL) & BM_ENET_EIR_RL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_ENET_EIR_RL(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_RL) | BF_ENET_EIR_RL(v)))
#endif

/* --- Register HW_ENET_EIR, field LC[21] (W1C)
 *
 * Indicates a collision occurred beyond the collision window (slot time) in half-duplex mode. The
 * frame truncates with a bad CRC and the remainder of the frame is discarded.
 */

#define BP_ENET_EIR_LC      (21)      //!< Bit position for ENET_EIR_LC.
#define BM_ENET_EIR_LC      (0x00200000)  //!< Bit mask for ENET_EIR_LC.

//! @brief Get value of ENET_EIR_LC from a register value.
#define BG_ENET_EIR_LC(r)   (((r) & BM_ENET_EIR_LC) >> BP_ENET_EIR_LC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_LC.
#define BF_ENET_EIR_LC(v)   ((((reg32_t) v) << BP_ENET_EIR_LC) & BM_ENET_EIR_LC)
#else
//! @brief Format value for bitfield ENET_EIR_LC.
#define BF_ENET_EIR_LC(v)   (((v) << BP_ENET_EIR_LC) & BM_ENET_EIR_LC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LC field to a new value.
#define BW_ENET_EIR_LC(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_LC) | BF_ENET_EIR_LC(v)))
#endif

/* --- Register HW_ENET_EIR, field EBERR[22] (W1C)
 *
 * Indicates a system bus error occurred when a uDMA transaction is underway. (Signal dma_eberr_int
 * asserted.) When this bit is set, ECR[ETHER_EN] is cleared, halting frame processing by the MAC.
 * When this occurs, software must ensure proper actions, possibly resetting the system, to resume
 * normal operation.
 */

#define BP_ENET_EIR_EBERR      (22)      //!< Bit position for ENET_EIR_EBERR.
#define BM_ENET_EIR_EBERR      (0x00400000)  //!< Bit mask for ENET_EIR_EBERR.

//! @brief Get value of ENET_EIR_EBERR from a register value.
#define BG_ENET_EIR_EBERR(r)   (((r) & BM_ENET_EIR_EBERR) >> BP_ENET_EIR_EBERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_EBERR.
#define BF_ENET_EIR_EBERR(v)   ((((reg32_t) v) << BP_ENET_EIR_EBERR) & BM_ENET_EIR_EBERR)
#else
//! @brief Format value for bitfield ENET_EIR_EBERR.
#define BF_ENET_EIR_EBERR(v)   (((v) << BP_ENET_EIR_EBERR) & BM_ENET_EIR_EBERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EBERR field to a new value.
#define BW_ENET_EIR_EBERR(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_EBERR) | BF_ENET_EIR_EBERR(v)))
#endif

/* --- Register HW_ENET_EIR, field MII[23] (W1C)
 *
 * Indicates that the MII has completed the data transfer requested.
 */

#define BP_ENET_EIR_MII      (23)      //!< Bit position for ENET_EIR_MII.
#define BM_ENET_EIR_MII      (0x00800000)  //!< Bit mask for ENET_EIR_MII.

//! @brief Get value of ENET_EIR_MII from a register value.
#define BG_ENET_EIR_MII(r)   (((r) & BM_ENET_EIR_MII) >> BP_ENET_EIR_MII)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_MII.
#define BF_ENET_EIR_MII(v)   ((((reg32_t) v) << BP_ENET_EIR_MII) & BM_ENET_EIR_MII)
#else
//! @brief Format value for bitfield ENET_EIR_MII.
#define BF_ENET_EIR_MII(v)   (((v) << BP_ENET_EIR_MII) & BM_ENET_EIR_MII)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MII field to a new value.
#define BW_ENET_EIR_MII(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_MII) | BF_ENET_EIR_MII(v)))
#endif

/* --- Register HW_ENET_EIR, field RXB[24] (W1C)
 *
 * Indicates a receive buffer descriptor is not the last in the frame has been updated. (Signal
 * dma_rxb_int asserted)
 */

#define BP_ENET_EIR_RXB      (24)      //!< Bit position for ENET_EIR_RXB.
#define BM_ENET_EIR_RXB      (0x01000000)  //!< Bit mask for ENET_EIR_RXB.

//! @brief Get value of ENET_EIR_RXB from a register value.
#define BG_ENET_EIR_RXB(r)   (((r) & BM_ENET_EIR_RXB) >> BP_ENET_EIR_RXB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_RXB.
#define BF_ENET_EIR_RXB(v)   ((((reg32_t) v) << BP_ENET_EIR_RXB) & BM_ENET_EIR_RXB)
#else
//! @brief Format value for bitfield ENET_EIR_RXB.
#define BF_ENET_EIR_RXB(v)   (((v) << BP_ENET_EIR_RXB) & BM_ENET_EIR_RXB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXB field to a new value.
#define BW_ENET_EIR_RXB(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_RXB) | BF_ENET_EIR_RXB(v)))
#endif

/* --- Register HW_ENET_EIR, field RXF[25] (W1C)
 *
 * Indicates a frame has been received and the last corresponding buffer descriptor has been
 * updated. (Signal dma_rxf_int asserted)
 */

#define BP_ENET_EIR_RXF      (25)      //!< Bit position for ENET_EIR_RXF.
#define BM_ENET_EIR_RXF      (0x02000000)  //!< Bit mask for ENET_EIR_RXF.

//! @brief Get value of ENET_EIR_RXF from a register value.
#define BG_ENET_EIR_RXF(r)   (((r) & BM_ENET_EIR_RXF) >> BP_ENET_EIR_RXF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_RXF.
#define BF_ENET_EIR_RXF(v)   ((((reg32_t) v) << BP_ENET_EIR_RXF) & BM_ENET_EIR_RXF)
#else
//! @brief Format value for bitfield ENET_EIR_RXF.
#define BF_ENET_EIR_RXF(v)   (((v) << BP_ENET_EIR_RXF) & BM_ENET_EIR_RXF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXF field to a new value.
#define BW_ENET_EIR_RXF(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_RXF) | BF_ENET_EIR_RXF(v)))
#endif

/* --- Register HW_ENET_EIR, field TXB[26] (W1C)
 *
 * Indicates a transmit buffer descriptor has been updated. (Signal dma_txb_int asserted)
 */

#define BP_ENET_EIR_TXB      (26)      //!< Bit position for ENET_EIR_TXB.
#define BM_ENET_EIR_TXB      (0x04000000)  //!< Bit mask for ENET_EIR_TXB.

//! @brief Get value of ENET_EIR_TXB from a register value.
#define BG_ENET_EIR_TXB(r)   (((r) & BM_ENET_EIR_TXB) >> BP_ENET_EIR_TXB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_TXB.
#define BF_ENET_EIR_TXB(v)   ((((reg32_t) v) << BP_ENET_EIR_TXB) & BM_ENET_EIR_TXB)
#else
//! @brief Format value for bitfield ENET_EIR_TXB.
#define BF_ENET_EIR_TXB(v)   (((v) << BP_ENET_EIR_TXB) & BM_ENET_EIR_TXB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXB field to a new value.
#define BW_ENET_EIR_TXB(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_TXB) | BF_ENET_EIR_TXB(v)))
#endif

/* --- Register HW_ENET_EIR, field TXF[27] (W1C)
 *
 * Indicates a frame has been transmitted and the last corresponding buffer descriptor has been
 * updated. (Signal dma_txf_int asserted)
 */

#define BP_ENET_EIR_TXF      (27)      //!< Bit position for ENET_EIR_TXF.
#define BM_ENET_EIR_TXF      (0x08000000)  //!< Bit mask for ENET_EIR_TXF.

//! @brief Get value of ENET_EIR_TXF from a register value.
#define BG_ENET_EIR_TXF(r)   (((r) & BM_ENET_EIR_TXF) >> BP_ENET_EIR_TXF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_TXF.
#define BF_ENET_EIR_TXF(v)   ((((reg32_t) v) << BP_ENET_EIR_TXF) & BM_ENET_EIR_TXF)
#else
//! @brief Format value for bitfield ENET_EIR_TXF.
#define BF_ENET_EIR_TXF(v)   (((v) << BP_ENET_EIR_TXF) & BM_ENET_EIR_TXF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXF field to a new value.
#define BW_ENET_EIR_TXF(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_TXF) | BF_ENET_EIR_TXF(v)))
#endif

/* --- Register HW_ENET_EIR, field GRA[28] (W1C)
 *
 * This interrupt is asserted after the transmitter is put into a pause state after completion of
 * the frame currently being transmitted. See Graceful Transmit Stop (GTS) for conditions that lead
 * to graceful stop. The GRA interrupt is asserted only when the TX transitions into the stopped
 * state. If this bit is cleared by writing 1 and the TX is still stopped, the bit is not set again.
 */

#define BP_ENET_EIR_GRA      (28)      //!< Bit position for ENET_EIR_GRA.
#define BM_ENET_EIR_GRA      (0x10000000)  //!< Bit mask for ENET_EIR_GRA.

//! @brief Get value of ENET_EIR_GRA from a register value.
#define BG_ENET_EIR_GRA(r)   (((r) & BM_ENET_EIR_GRA) >> BP_ENET_EIR_GRA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_GRA.
#define BF_ENET_EIR_GRA(v)   ((((reg32_t) v) << BP_ENET_EIR_GRA) & BM_ENET_EIR_GRA)
#else
//! @brief Format value for bitfield ENET_EIR_GRA.
#define BF_ENET_EIR_GRA(v)   (((v) << BP_ENET_EIR_GRA) & BM_ENET_EIR_GRA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GRA field to a new value.
#define BW_ENET_EIR_GRA(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_GRA) | BF_ENET_EIR_GRA(v)))
#endif

/* --- Register HW_ENET_EIR, field BABT[29] (W1C)
 *
 * Indicates the transmitted frame length exceeds RCR[MAX_FL] bytes. Usually this condition is
 * caused when a frame that is too long is placed into the transmit data buffer(s). Truncation does
 * not occur.
 */

#define BP_ENET_EIR_BABT      (29)      //!< Bit position for ENET_EIR_BABT.
#define BM_ENET_EIR_BABT      (0x20000000)  //!< Bit mask for ENET_EIR_BABT.

//! @brief Get value of ENET_EIR_BABT from a register value.
#define BG_ENET_EIR_BABT(r)   (((r) & BM_ENET_EIR_BABT) >> BP_ENET_EIR_BABT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_BABT.
#define BF_ENET_EIR_BABT(v)   ((((reg32_t) v) << BP_ENET_EIR_BABT) & BM_ENET_EIR_BABT)
#else
//! @brief Format value for bitfield ENET_EIR_BABT.
#define BF_ENET_EIR_BABT(v)   (((v) << BP_ENET_EIR_BABT) & BM_ENET_EIR_BABT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BABT field to a new value.
#define BW_ENET_EIR_BABT(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_BABT) | BF_ENET_EIR_BABT(v)))
#endif

/* --- Register HW_ENET_EIR, field BABR[30] (W1C)
 *
 * Indicates a frame was received with length in excess of RCR[MAX_FL] bytes.
 */

#define BP_ENET_EIR_BABR      (30)      //!< Bit position for ENET_EIR_BABR.
#define BM_ENET_EIR_BABR      (0x40000000)  //!< Bit mask for ENET_EIR_BABR.

//! @brief Get value of ENET_EIR_BABR from a register value.
#define BG_ENET_EIR_BABR(r)   (((r) & BM_ENET_EIR_BABR) >> BP_ENET_EIR_BABR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIR_BABR.
#define BF_ENET_EIR_BABR(v)   ((((reg32_t) v) << BP_ENET_EIR_BABR) & BM_ENET_EIR_BABR)
#else
//! @brief Format value for bitfield ENET_EIR_BABR.
#define BF_ENET_EIR_BABR(v)   (((v) << BP_ENET_EIR_BABR) & BM_ENET_EIR_BABR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BABR field to a new value.
#define BW_ENET_EIR_BABR(v)   (HW_ENET_EIR_WR((HW_ENET_EIR_RD() & ~BM_ENET_EIR_BABR) | BF_ENET_EIR_BABR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_EIMR - Interrupt Mask Register (RW)
 *
 * Reset value: 0x00000000
 *
 * EIMR controls which interrupt events are allowed to generate actual interrupts. A hardware reset
 * clears this register. If the corresponding bits in the EIR and EIMR registers are set, an
 * interrupt is generated. The interrupt signal remains asserted until a 1 is written to the EIR
 * field (write 1 to clear) or a 0 is written to the EIMR field.
 */
typedef union _hw_enet_eimr
{
    reg32_t U;
    struct _hw_enet_eimr_bitfields
    {
        unsigned RESERVED0 : 15; //!< [14:0] 
        unsigned TS_TIMER : 1; //!< [15] Corresponds to interrupt source TS_TIMER defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR TS_TIMER field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned TS_AVAIL : 1; //!< [16] Corresponds to interrupt source TS_AVAIL defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR TS_AVAIL field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned WAKEUP : 1; //!< [17] Corresponds to interrupt source WAKEUP defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR WAKEUP field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned PLR : 1; //!< [18] Corresponds to interrupt source PLR defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR PLR field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned UN : 1; //!< [19] Corresponds to interrupt source UN defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR UN field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned RL : 1; //!< [20] Corresponds to interrupt source RL defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR RL field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned LC : 1; //!< [21] Corresponds to interrupt source LC defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR LC field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned EBERR : 1; //!< [22] Corresponds to interrupt source EBERR defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR EBERR field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned MII : 1; //!< [23] Corresponds to interrupt source MII defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR MII field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned RXB : 1; //!< [24] Corresponds to interrupt source RXB defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR RXB field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned RXF : 1; //!< [25] Corresponds to interrupt source RXF defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR RXF field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned TXB : 1; //!< [26] Corresponds to interrupt source TXB defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR TXF field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned TXF : 1; //!< [27] Corresponds to interrupt source TXF defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR TXF field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned GRA : 1; //!< [28] Corresponds to interrupt source GRA defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR GRA field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned BABT : 1; //!< [29] Corresponds to interrupt source BABT defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR BABT field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned BABR : 1; //!< [30] Corresponds to interrupt source BABR defined by the EIR register and determines whether an interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal generated by the interrupting source. The corresponding EIR BABR field reflects the state of the interrupt signal even if the corresponding EIMR field is cleared.
        unsigned RESERVED1 : 1; //!< [31] 
    } B;
} hw_enet_eimr_t;
#endif

/*
 * constants & macros for entire ENET_EIMR register
 */
#define HW_ENET_EIMR_ADDR      (REGS_ENET_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_EIMR           (*(volatile hw_enet_eimr_t *) HW_ENET_EIMR_ADDR)
#define HW_ENET_EIMR_RD()      (HW_ENET_EIMR.U)
#define HW_ENET_EIMR_WR(v)     (HW_ENET_EIMR.U = (v))
#define HW_ENET_EIMR_SET(v)    (HW_ENET_EIMR_WR(HW_ENET_EIMR_RD() |  (v)))
#define HW_ENET_EIMR_CLR(v)    (HW_ENET_EIMR_WR(HW_ENET_EIMR_RD() & ~(v)))
#define HW_ENET_EIMR_TOG(v)    (HW_ENET_EIMR_WR(HW_ENET_EIMR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_EIMR bitfields
 */

/* --- Register HW_ENET_EIMR, field TS_TIMER[15] (RW)
 *
 * Corresponds to interrupt source TS_TIMER defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR TS_TIMER field reflects the state of
 * the interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_TS_TIMER      (15)      //!< Bit position for ENET_EIMR_TS_TIMER.
#define BM_ENET_EIMR_TS_TIMER      (0x00008000)  //!< Bit mask for ENET_EIMR_TS_TIMER.

//! @brief Get value of ENET_EIMR_TS_TIMER from a register value.
#define BG_ENET_EIMR_TS_TIMER(r)   (((r) & BM_ENET_EIMR_TS_TIMER) >> BP_ENET_EIMR_TS_TIMER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_TS_TIMER.
#define BF_ENET_EIMR_TS_TIMER(v)   ((((reg32_t) v) << BP_ENET_EIMR_TS_TIMER) & BM_ENET_EIMR_TS_TIMER)
#else
//! @brief Format value for bitfield ENET_EIMR_TS_TIMER.
#define BF_ENET_EIMR_TS_TIMER(v)   (((v) << BP_ENET_EIMR_TS_TIMER) & BM_ENET_EIMR_TS_TIMER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TS_TIMER field to a new value.
#define BW_ENET_EIMR_TS_TIMER(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_TS_TIMER) | BF_ENET_EIMR_TS_TIMER(v)))
#endif

/* --- Register HW_ENET_EIMR, field TS_AVAIL[16] (RW)
 *
 * Corresponds to interrupt source TS_AVAIL defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR TS_AVAIL field reflects the state of
 * the interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_TS_AVAIL      (16)      //!< Bit position for ENET_EIMR_TS_AVAIL.
#define BM_ENET_EIMR_TS_AVAIL      (0x00010000)  //!< Bit mask for ENET_EIMR_TS_AVAIL.

//! @brief Get value of ENET_EIMR_TS_AVAIL from a register value.
#define BG_ENET_EIMR_TS_AVAIL(r)   (((r) & BM_ENET_EIMR_TS_AVAIL) >> BP_ENET_EIMR_TS_AVAIL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_TS_AVAIL.
#define BF_ENET_EIMR_TS_AVAIL(v)   ((((reg32_t) v) << BP_ENET_EIMR_TS_AVAIL) & BM_ENET_EIMR_TS_AVAIL)
#else
//! @brief Format value for bitfield ENET_EIMR_TS_AVAIL.
#define BF_ENET_EIMR_TS_AVAIL(v)   (((v) << BP_ENET_EIMR_TS_AVAIL) & BM_ENET_EIMR_TS_AVAIL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TS_AVAIL field to a new value.
#define BW_ENET_EIMR_TS_AVAIL(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_TS_AVAIL) | BF_ENET_EIMR_TS_AVAIL(v)))
#endif

/* --- Register HW_ENET_EIMR, field WAKEUP[17] (RW)
 *
 * Corresponds to interrupt source WAKEUP defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR WAKEUP field reflects the state of
 * the interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_WAKEUP      (17)      //!< Bit position for ENET_EIMR_WAKEUP.
#define BM_ENET_EIMR_WAKEUP      (0x00020000)  //!< Bit mask for ENET_EIMR_WAKEUP.

//! @brief Get value of ENET_EIMR_WAKEUP from a register value.
#define BG_ENET_EIMR_WAKEUP(r)   (((r) & BM_ENET_EIMR_WAKEUP) >> BP_ENET_EIMR_WAKEUP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_WAKEUP.
#define BF_ENET_EIMR_WAKEUP(v)   ((((reg32_t) v) << BP_ENET_EIMR_WAKEUP) & BM_ENET_EIMR_WAKEUP)
#else
//! @brief Format value for bitfield ENET_EIMR_WAKEUP.
#define BF_ENET_EIMR_WAKEUP(v)   (((v) << BP_ENET_EIMR_WAKEUP) & BM_ENET_EIMR_WAKEUP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the WAKEUP field to a new value.
#define BW_ENET_EIMR_WAKEUP(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_WAKEUP) | BF_ENET_EIMR_WAKEUP(v)))
#endif

/* --- Register HW_ENET_EIMR, field PLR[18] (RW)
 *
 * Corresponds to interrupt source PLR defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR PLR field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_PLR      (18)      //!< Bit position for ENET_EIMR_PLR.
#define BM_ENET_EIMR_PLR      (0x00040000)  //!< Bit mask for ENET_EIMR_PLR.

//! @brief Get value of ENET_EIMR_PLR from a register value.
#define BG_ENET_EIMR_PLR(r)   (((r) & BM_ENET_EIMR_PLR) >> BP_ENET_EIMR_PLR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_PLR.
#define BF_ENET_EIMR_PLR(v)   ((((reg32_t) v) << BP_ENET_EIMR_PLR) & BM_ENET_EIMR_PLR)
#else
//! @brief Format value for bitfield ENET_EIMR_PLR.
#define BF_ENET_EIMR_PLR(v)   (((v) << BP_ENET_EIMR_PLR) & BM_ENET_EIMR_PLR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PLR field to a new value.
#define BW_ENET_EIMR_PLR(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_PLR) | BF_ENET_EIMR_PLR(v)))
#endif

/* --- Register HW_ENET_EIMR, field UN[19] (RW)
 *
 * Corresponds to interrupt source UN defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR UN field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_UN      (19)      //!< Bit position for ENET_EIMR_UN.
#define BM_ENET_EIMR_UN      (0x00080000)  //!< Bit mask for ENET_EIMR_UN.

//! @brief Get value of ENET_EIMR_UN from a register value.
#define BG_ENET_EIMR_UN(r)   (((r) & BM_ENET_EIMR_UN) >> BP_ENET_EIMR_UN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_UN.
#define BF_ENET_EIMR_UN(v)   ((((reg32_t) v) << BP_ENET_EIMR_UN) & BM_ENET_EIMR_UN)
#else
//! @brief Format value for bitfield ENET_EIMR_UN.
#define BF_ENET_EIMR_UN(v)   (((v) << BP_ENET_EIMR_UN) & BM_ENET_EIMR_UN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the UN field to a new value.
#define BW_ENET_EIMR_UN(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_UN) | BF_ENET_EIMR_UN(v)))
#endif

/* --- Register HW_ENET_EIMR, field RL[20] (RW)
 *
 * Corresponds to interrupt source RL defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR RL field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_RL      (20)      //!< Bit position for ENET_EIMR_RL.
#define BM_ENET_EIMR_RL      (0x00100000)  //!< Bit mask for ENET_EIMR_RL.

//! @brief Get value of ENET_EIMR_RL from a register value.
#define BG_ENET_EIMR_RL(r)   (((r) & BM_ENET_EIMR_RL) >> BP_ENET_EIMR_RL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_RL.
#define BF_ENET_EIMR_RL(v)   ((((reg32_t) v) << BP_ENET_EIMR_RL) & BM_ENET_EIMR_RL)
#else
//! @brief Format value for bitfield ENET_EIMR_RL.
#define BF_ENET_EIMR_RL(v)   (((v) << BP_ENET_EIMR_RL) & BM_ENET_EIMR_RL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RL field to a new value.
#define BW_ENET_EIMR_RL(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_RL) | BF_ENET_EIMR_RL(v)))
#endif

/* --- Register HW_ENET_EIMR, field LC[21] (RW)
 *
 * Corresponds to interrupt source LC defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR LC field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_LC      (21)      //!< Bit position for ENET_EIMR_LC.
#define BM_ENET_EIMR_LC      (0x00200000)  //!< Bit mask for ENET_EIMR_LC.

//! @brief Get value of ENET_EIMR_LC from a register value.
#define BG_ENET_EIMR_LC(r)   (((r) & BM_ENET_EIMR_LC) >> BP_ENET_EIMR_LC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_LC.
#define BF_ENET_EIMR_LC(v)   ((((reg32_t) v) << BP_ENET_EIMR_LC) & BM_ENET_EIMR_LC)
#else
//! @brief Format value for bitfield ENET_EIMR_LC.
#define BF_ENET_EIMR_LC(v)   (((v) << BP_ENET_EIMR_LC) & BM_ENET_EIMR_LC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LC field to a new value.
#define BW_ENET_EIMR_LC(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_LC) | BF_ENET_EIMR_LC(v)))
#endif

/* --- Register HW_ENET_EIMR, field EBERR[22] (RW)
 *
 * Corresponds to interrupt source EBERR defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR EBERR field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_EBERR      (22)      //!< Bit position for ENET_EIMR_EBERR.
#define BM_ENET_EIMR_EBERR      (0x00400000)  //!< Bit mask for ENET_EIMR_EBERR.

//! @brief Get value of ENET_EIMR_EBERR from a register value.
#define BG_ENET_EIMR_EBERR(r)   (((r) & BM_ENET_EIMR_EBERR) >> BP_ENET_EIMR_EBERR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_EBERR.
#define BF_ENET_EIMR_EBERR(v)   ((((reg32_t) v) << BP_ENET_EIMR_EBERR) & BM_ENET_EIMR_EBERR)
#else
//! @brief Format value for bitfield ENET_EIMR_EBERR.
#define BF_ENET_EIMR_EBERR(v)   (((v) << BP_ENET_EIMR_EBERR) & BM_ENET_EIMR_EBERR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EBERR field to a new value.
#define BW_ENET_EIMR_EBERR(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_EBERR) | BF_ENET_EIMR_EBERR(v)))
#endif

/* --- Register HW_ENET_EIMR, field MII[23] (RW)
 *
 * Corresponds to interrupt source MII defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR MII field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_MII      (23)      //!< Bit position for ENET_EIMR_MII.
#define BM_ENET_EIMR_MII      (0x00800000)  //!< Bit mask for ENET_EIMR_MII.

//! @brief Get value of ENET_EIMR_MII from a register value.
#define BG_ENET_EIMR_MII(r)   (((r) & BM_ENET_EIMR_MII) >> BP_ENET_EIMR_MII)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_MII.
#define BF_ENET_EIMR_MII(v)   ((((reg32_t) v) << BP_ENET_EIMR_MII) & BM_ENET_EIMR_MII)
#else
//! @brief Format value for bitfield ENET_EIMR_MII.
#define BF_ENET_EIMR_MII(v)   (((v) << BP_ENET_EIMR_MII) & BM_ENET_EIMR_MII)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MII field to a new value.
#define BW_ENET_EIMR_MII(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_MII) | BF_ENET_EIMR_MII(v)))
#endif

/* --- Register HW_ENET_EIMR, field RXB[24] (RW)
 *
 * Corresponds to interrupt source RXB defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR RXB field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_RXB      (24)      //!< Bit position for ENET_EIMR_RXB.
#define BM_ENET_EIMR_RXB      (0x01000000)  //!< Bit mask for ENET_EIMR_RXB.

//! @brief Get value of ENET_EIMR_RXB from a register value.
#define BG_ENET_EIMR_RXB(r)   (((r) & BM_ENET_EIMR_RXB) >> BP_ENET_EIMR_RXB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_RXB.
#define BF_ENET_EIMR_RXB(v)   ((((reg32_t) v) << BP_ENET_EIMR_RXB) & BM_ENET_EIMR_RXB)
#else
//! @brief Format value for bitfield ENET_EIMR_RXB.
#define BF_ENET_EIMR_RXB(v)   (((v) << BP_ENET_EIMR_RXB) & BM_ENET_EIMR_RXB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXB field to a new value.
#define BW_ENET_EIMR_RXB(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_RXB) | BF_ENET_EIMR_RXB(v)))
#endif

/* --- Register HW_ENET_EIMR, field RXF[25] (RW)
 *
 * Corresponds to interrupt source RXF defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR RXF field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 */

#define BP_ENET_EIMR_RXF      (25)      //!< Bit position for ENET_EIMR_RXF.
#define BM_ENET_EIMR_RXF      (0x02000000)  //!< Bit mask for ENET_EIMR_RXF.

//! @brief Get value of ENET_EIMR_RXF from a register value.
#define BG_ENET_EIMR_RXF(r)   (((r) & BM_ENET_EIMR_RXF) >> BP_ENET_EIMR_RXF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_RXF.
#define BF_ENET_EIMR_RXF(v)   ((((reg32_t) v) << BP_ENET_EIMR_RXF) & BM_ENET_EIMR_RXF)
#else
//! @brief Format value for bitfield ENET_EIMR_RXF.
#define BF_ENET_EIMR_RXF(v)   (((v) << BP_ENET_EIMR_RXF) & BM_ENET_EIMR_RXF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RXF field to a new value.
#define BW_ENET_EIMR_RXF(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_RXF) | BF_ENET_EIMR_RXF(v)))
#endif

/* --- Register HW_ENET_EIMR, field TXB[26] (RW)
 *
 * Corresponds to interrupt source TXB defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR TXF field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_ENET_EIMR_TXB      (26)      //!< Bit position for ENET_EIMR_TXB.
#define BM_ENET_EIMR_TXB      (0x04000000)  //!< Bit mask for ENET_EIMR_TXB.

//! @brief Get value of ENET_EIMR_TXB from a register value.
#define BG_ENET_EIMR_TXB(r)   (((r) & BM_ENET_EIMR_TXB) >> BP_ENET_EIMR_TXB)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_TXB.
#define BF_ENET_EIMR_TXB(v)   ((((reg32_t) v) << BP_ENET_EIMR_TXB) & BM_ENET_EIMR_TXB)
#else
//! @brief Format value for bitfield ENET_EIMR_TXB.
#define BF_ENET_EIMR_TXB(v)   (((v) << BP_ENET_EIMR_TXB) & BM_ENET_EIMR_TXB)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXB field to a new value.
#define BW_ENET_EIMR_TXB(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_TXB) | BF_ENET_EIMR_TXB(v)))
#endif


/* --- Register HW_ENET_EIMR, field TXF[27] (RW)
 *
 * Corresponds to interrupt source TXF defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR TXF field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_ENET_EIMR_TXF      (27)      //!< Bit position for ENET_EIMR_TXF.
#define BM_ENET_EIMR_TXF      (0x08000000)  //!< Bit mask for ENET_EIMR_TXF.

//! @brief Get value of ENET_EIMR_TXF from a register value.
#define BG_ENET_EIMR_TXF(r)   (((r) & BM_ENET_EIMR_TXF) >> BP_ENET_EIMR_TXF)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_TXF.
#define BF_ENET_EIMR_TXF(v)   ((((reg32_t) v) << BP_ENET_EIMR_TXF) & BM_ENET_EIMR_TXF)
#else
//! @brief Format value for bitfield ENET_EIMR_TXF.
#define BF_ENET_EIMR_TXF(v)   (((v) << BP_ENET_EIMR_TXF) & BM_ENET_EIMR_TXF)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TXF field to a new value.
#define BW_ENET_EIMR_TXF(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_TXF) | BF_ENET_EIMR_TXF(v)))
#endif


/* --- Register HW_ENET_EIMR, field GRA[28] (RW)
 *
 * Corresponds to interrupt source GRA defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR GRA field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_ENET_EIMR_GRA      (28)      //!< Bit position for ENET_EIMR_GRA.
#define BM_ENET_EIMR_GRA      (0x10000000)  //!< Bit mask for ENET_EIMR_GRA.

//! @brief Get value of ENET_EIMR_GRA from a register value.
#define BG_ENET_EIMR_GRA(r)   (((r) & BM_ENET_EIMR_GRA) >> BP_ENET_EIMR_GRA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_GRA.
#define BF_ENET_EIMR_GRA(v)   ((((reg32_t) v) << BP_ENET_EIMR_GRA) & BM_ENET_EIMR_GRA)
#else
//! @brief Format value for bitfield ENET_EIMR_GRA.
#define BF_ENET_EIMR_GRA(v)   (((v) << BP_ENET_EIMR_GRA) & BM_ENET_EIMR_GRA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GRA field to a new value.
#define BW_ENET_EIMR_GRA(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_GRA) | BF_ENET_EIMR_GRA(v)))
#endif


/* --- Register HW_ENET_EIMR, field BABT[29] (RW)
 *
 * Corresponds to interrupt source BABT defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR BABT field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_ENET_EIMR_BABT      (29)      //!< Bit position for ENET_EIMR_BABT.
#define BM_ENET_EIMR_BABT      (0x20000000)  //!< Bit mask for ENET_EIMR_BABT.

//! @brief Get value of ENET_EIMR_BABT from a register value.
#define BG_ENET_EIMR_BABT(r)   (((r) & BM_ENET_EIMR_BABT) >> BP_ENET_EIMR_BABT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_BABT.
#define BF_ENET_EIMR_BABT(v)   ((((reg32_t) v) << BP_ENET_EIMR_BABT) & BM_ENET_EIMR_BABT)
#else
//! @brief Format value for bitfield ENET_EIMR_BABT.
#define BF_ENET_EIMR_BABT(v)   (((v) << BP_ENET_EIMR_BABT) & BM_ENET_EIMR_BABT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BABT field to a new value.
#define BW_ENET_EIMR_BABT(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_BABT) | BF_ENET_EIMR_BABT(v)))
#endif


/* --- Register HW_ENET_EIMR, field BABR[30] (RW)
 *
 * Corresponds to interrupt source BABR defined by the EIR register and determines whether an
 * interrupt condition can generate an interrupt. At every module clock, the EIR samples the signal
 * generated by the interrupting source. The corresponding EIR BABR field reflects the state of the
 * interrupt signal even if the corresponding EIMR field is cleared.
 *
 * Values:
 * 0 - The corresponding interrupt source is masked.
 * 1 - The corresponding interrupt source is not masked.
 */

#define BP_ENET_EIMR_BABR      (30)      //!< Bit position for ENET_EIMR_BABR.
#define BM_ENET_EIMR_BABR      (0x40000000)  //!< Bit mask for ENET_EIMR_BABR.

//! @brief Get value of ENET_EIMR_BABR from a register value.
#define BG_ENET_EIMR_BABR(r)   (((r) & BM_ENET_EIMR_BABR) >> BP_ENET_EIMR_BABR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_EIMR_BABR.
#define BF_ENET_EIMR_BABR(v)   ((((reg32_t) v) << BP_ENET_EIMR_BABR) & BM_ENET_EIMR_BABR)
#else
//! @brief Format value for bitfield ENET_EIMR_BABR.
#define BF_ENET_EIMR_BABR(v)   (((v) << BP_ENET_EIMR_BABR) & BM_ENET_EIMR_BABR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BABR field to a new value.
#define BW_ENET_EIMR_BABR(v)   (HW_ENET_EIMR_WR((HW_ENET_EIMR_RD() & ~BM_ENET_EIMR_BABR) | BF_ENET_EIMR_BABR(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RDAR - Receive Descriptor Active Register (RW)
 *
 * Reset value: 0x00000000
 *
 * RDAR is a command register, written by the user, to indicate that the receive descriptor ring has
 * been updated, that is, that the driver produced empty receive buffers with the empty bit set.
 * When the register is written, the RDAR bit is set. This is independent of the data actually
 * written by the user. When set, the MAC polls the receive descriptor ring and processes receive
 * frames, provided ECR[ETHER_EN] is also set. After the MAC polls a receive descriptor whose empty
 * bit is not set, MAC clears RDAR and ceases receive descriptor ring polling until the user sets
 * the bit again, signifying that additional descriptors have been placed into the receive
 * descriptor ring.  The RDAR register is cleared at reset and when ECR[ETHER_EN] transitions from
 * set to cleared or when ECR[RESET] is set.
 */
typedef union _hw_enet_rdar
{
    reg32_t U;
    struct _hw_enet_rdar_bitfields
    {
        unsigned RESERVED0 : 24; //!< [23:0] 
        unsigned RDAR : 1; //!< [24] Always set to 1 when this register is written, regardless of the value written. This field is cleared by the MAC device when no additional empty descriptors remain in the receive ring. It is also cleared when ECR[ETHER_EN] transitions from set to cleared or when ECR[RESET] is set.
        unsigned RESERVED1 : 7; //!< [31:25] 
    } B;
} hw_enet_rdar_t;
#endif

/*
 * constants & macros for entire ENET_RDAR register
 */
#define HW_ENET_RDAR_ADDR      (REGS_ENET_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RDAR           (*(volatile hw_enet_rdar_t *) HW_ENET_RDAR_ADDR)
#define HW_ENET_RDAR_RD()      (HW_ENET_RDAR.U)
#define HW_ENET_RDAR_WR(v)     (HW_ENET_RDAR.U = (v))
#define HW_ENET_RDAR_SET(v)    (HW_ENET_RDAR_WR(HW_ENET_RDAR_RD() |  (v)))
#define HW_ENET_RDAR_CLR(v)    (HW_ENET_RDAR_WR(HW_ENET_RDAR_RD() & ~(v)))
#define HW_ENET_RDAR_TOG(v)    (HW_ENET_RDAR_WR(HW_ENET_RDAR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RDAR bitfields
 */

/* --- Register HW_ENET_RDAR, field RDAR[24] (RW)
 *
 * Always set to 1 when this register is written, regardless of the value written. This field is
 * cleared by the MAC device when no additional empty descriptors remain in the receive ring. It is
 * also cleared when ECR[ETHER_EN] transitions from set to cleared or when ECR[RESET] is set.
 */

#define BP_ENET_RDAR_RDAR      (24)      //!< Bit position for ENET_RDAR_RDAR.
#define BM_ENET_RDAR_RDAR      (0x01000000)  //!< Bit mask for ENET_RDAR_RDAR.

//! @brief Get value of ENET_RDAR_RDAR from a register value.
#define BG_ENET_RDAR_RDAR(r)   (((r) & BM_ENET_RDAR_RDAR) >> BP_ENET_RDAR_RDAR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RDAR_RDAR.
#define BF_ENET_RDAR_RDAR(v)   ((((reg32_t) v) << BP_ENET_RDAR_RDAR) & BM_ENET_RDAR_RDAR)
#else
//! @brief Format value for bitfield ENET_RDAR_RDAR.
#define BF_ENET_RDAR_RDAR(v)   (((v) << BP_ENET_RDAR_RDAR) & BM_ENET_RDAR_RDAR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RDAR field to a new value.
#define BW_ENET_RDAR_RDAR(v)   (HW_ENET_RDAR_WR((HW_ENET_RDAR_RD() & ~BM_ENET_RDAR_RDAR) | BF_ENET_RDAR_RDAR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TDAR - Transmit Descriptor Active Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The TDAR is a command register that the user writes to indicate that the transmit descriptor ring
 * has been updated, that is, that transmit buffers have been produced by the driver with the ready
 * bit set in the buffer descriptor.  When the register is written, the TDAR bit is set. This value
 * is independent of the data actually written by the user. When set, the MAC polls the transmit
 * descriptor ring and processes transmit frames, provided ECR[ETHER_EN] is also set. After the MAC
 * polls a transmit descriptor that contains a ready bit that is not set, the MAC clears TDAR and
 * ceases transmit descriptor ring polling until the user sets the bit again, signifying additional
 * descriptors have been placed into the transmit descriptor ring.  The TDAR register is cleared at
 * reset, when ECR[ETHER_EN] transitions from set to cleared, or when ECR[RESET] is set.
 */
typedef union _hw_enet_tdar
{
    reg32_t U;
    struct _hw_enet_tdar_bitfields
    {
        unsigned RESERVED0 : 24; //!< [23:0] 
        unsigned TDAR : 1; //!< [24] Always set to 1 when this register is written, regardless of the value written. This bit is cleared by the MAC device when no additional ready descriptors remain in the transmit ring. Also cleared when ECR[ETHER_EN] transitions from set to cleared or when ECR[RESET] is set.
        unsigned RESERVED1 : 7; //!< [31:25] 
    } B;
} hw_enet_tdar_t;
#endif

/*
 * constants & macros for entire ENET_TDAR register
 */
#define HW_ENET_TDAR_ADDR      (REGS_ENET_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TDAR           (*(volatile hw_enet_tdar_t *) HW_ENET_TDAR_ADDR)
#define HW_ENET_TDAR_RD()      (HW_ENET_TDAR.U)
#define HW_ENET_TDAR_WR(v)     (HW_ENET_TDAR.U = (v))
#define HW_ENET_TDAR_SET(v)    (HW_ENET_TDAR_WR(HW_ENET_TDAR_RD() |  (v)))
#define HW_ENET_TDAR_CLR(v)    (HW_ENET_TDAR_WR(HW_ENET_TDAR_RD() & ~(v)))
#define HW_ENET_TDAR_TOG(v)    (HW_ENET_TDAR_WR(HW_ENET_TDAR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TDAR bitfields
 */

/* --- Register HW_ENET_TDAR, field TDAR[24] (RW)
 *
 * Always set to 1 when this register is written, regardless of the value written. This bit is
 * cleared by the MAC device when no additional ready descriptors remain in the transmit ring. Also
 * cleared when ECR[ETHER_EN] transitions from set to cleared or when ECR[RESET] is set.
 */

#define BP_ENET_TDAR_TDAR      (24)      //!< Bit position for ENET_TDAR_TDAR.
#define BM_ENET_TDAR_TDAR      (0x01000000)  //!< Bit mask for ENET_TDAR_TDAR.

//! @brief Get value of ENET_TDAR_TDAR from a register value.
#define BG_ENET_TDAR_TDAR(r)   (((r) & BM_ENET_TDAR_TDAR) >> BP_ENET_TDAR_TDAR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TDAR_TDAR.
#define BF_ENET_TDAR_TDAR(v)   ((((reg32_t) v) << BP_ENET_TDAR_TDAR) & BM_ENET_TDAR_TDAR)
#else
//! @brief Format value for bitfield ENET_TDAR_TDAR.
#define BF_ENET_TDAR_TDAR(v)   (((v) << BP_ENET_TDAR_TDAR) & BM_ENET_TDAR_TDAR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TDAR field to a new value.
#define BW_ENET_TDAR_TDAR(v)   (HW_ENET_TDAR_WR((HW_ENET_TDAR_RD() & ~BM_ENET_TDAR_TDAR) | BF_ENET_TDAR_TDAR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ECR - Ethernet Control Register (RW)
 *
 * Reset value: 0xf0000000
 *
 * ECR is a read/write user register, though hardware may also alter fields in this register. It
 * controls many of the high level features of the Ethernet MAC, including legacy FEC support
 * through the EN1588 field.
 */
typedef union _hw_enet_ecr
{
    reg32_t U;
    struct _hw_enet_ecr_bitfields
    {
        unsigned RESET : 1; //!< [0] When this field is set, it clears the ETHER_EN field. The system that instanciates the MAC is expected to perform necessary actions to perform the equivalent of a hardware reset on the MAC when the pin ecr_reset becomes asserted.
        unsigned ETHEREN : 1; //!< [1] Enables/disables the Ethernet MAC. When the MAC is disabled, the buffer descriptors for an aborted transmit frame are not updated. The uDMA, buffer descriptor, and FIFO control logic are reset, including the buffer descriptor and FIFO pointers. Hardware clears this field under the following conditions: RESET is set by software An error condition causes the EBERR field to set. ETHEREN must be set at the very last step during ENET configuration/setup/initialization, only after all other ENET-related registers have been configured.
        unsigned MAGICEN : 1; //!< [2] Enables/disables magic packet detection. MAGICEN is relevant only if the SLEEP field is set. If MAGICEN is set, changing the SLEEP field enables/disables sleep mode and magic packet detection.
        unsigned SLEEP : 1; //!< [3] 
        unsigned EN1588 : 1; //!< [4] Enables enhanced functionality of the MAC.
        unsigned RESERVED0 : 1; //!< [5] Reserved.
        unsigned DBGEN : 1; //!< [6] Enables debug input pin mac_freeze the MAC to enter hardware freeze mode when the device enters debug mode. In addition, the bit setting is available on the toplevel signal dbg_en.
        unsigned STOPEN : 1; //!< [7] Controls toplevel output pin stop_en. Has no effect inside the core beside controlling the pin device behavior in doze mode. In doze mode, if this field is set then all the clocks of the ENET assembly are disabled, except the RMII /MII clock. Doze mode is similar to a conditional stop mode entry for the ENET assembly depending on ECR[STOPEN]. If module clocks are gated in this mode, the module can still wake the system after receiving a magic packet in stop mode. MAGICEN must be set prior to entering sleep/stop mode.
        unsigned RESERVED1 : 24; //!< [31:8] Reserved.
    } B;
} hw_enet_ecr_t;
#endif

/*
 * constants & macros for entire ENET_ECR register
 */
#define HW_ENET_ECR_ADDR      (REGS_ENET_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ECR           (*(volatile hw_enet_ecr_t *) HW_ENET_ECR_ADDR)
#define HW_ENET_ECR_RD()      (HW_ENET_ECR.U)
#define HW_ENET_ECR_WR(v)     (HW_ENET_ECR.U = (v))
#define HW_ENET_ECR_SET(v)    (HW_ENET_ECR_WR(HW_ENET_ECR_RD() |  (v)))
#define HW_ENET_ECR_CLR(v)    (HW_ENET_ECR_WR(HW_ENET_ECR_RD() & ~(v)))
#define HW_ENET_ECR_TOG(v)    (HW_ENET_ECR_WR(HW_ENET_ECR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_ECR bitfields
 */

/* --- Register HW_ENET_ECR, field RESET[0] (RW)
 *
 * When this field is set, it clears the ETHER_EN field. The system that instanciates the MAC is
 * expected to perform necessary actions to perform the equivalent of a hardware reset on the MAC
 * when the pin ecr_reset becomes asserted.
 */

#define BP_ENET_ECR_RESET      (0)      //!< Bit position for ENET_ECR_RESET.
#define BM_ENET_ECR_RESET      (0x00000001)  //!< Bit mask for ENET_ECR_RESET.

//! @brief Get value of ENET_ECR_RESET from a register value.
#define BG_ENET_ECR_RESET(r)   (((r) & BM_ENET_ECR_RESET) >> BP_ENET_ECR_RESET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ECR_RESET.
#define BF_ENET_ECR_RESET(v)   ((((reg32_t) v) << BP_ENET_ECR_RESET) & BM_ENET_ECR_RESET)
#else
//! @brief Format value for bitfield ENET_ECR_RESET.
#define BF_ENET_ECR_RESET(v)   (((v) << BP_ENET_ECR_RESET) & BM_ENET_ECR_RESET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESET field to a new value.
#define BW_ENET_ECR_RESET(v)   (HW_ENET_ECR_WR((HW_ENET_ECR_RD() & ~BM_ENET_ECR_RESET) | BF_ENET_ECR_RESET(v)))
#endif

/* --- Register HW_ENET_ECR, field ETHEREN[1] (RW)
 *
 * Enables/disables the Ethernet MAC. When the MAC is disabled, the buffer descriptors for an
 * aborted transmit frame are not updated. The uDMA, buffer descriptor, and FIFO control logic are
 * reset, including the buffer descriptor and FIFO pointers. Hardware clears this field under the
 * following conditions: RESET is set by software An error condition causes the EBERR field to set.
 * ETHEREN must be set at the very last step during ENET configuration/setup/initialization, only
 * after all other ENET-related registers have been configured.
 *
 * Values:
 * 0 - Reception immediately stops and transmission stops after a bad CRC is appended to any currently
 *     transmitted frame.
 * 1 - MAC is enabled, and reception and transmission are possible.
 */

#define BP_ENET_ECR_ETHEREN      (1)      //!< Bit position for ENET_ECR_ETHEREN.
#define BM_ENET_ECR_ETHEREN      (0x00000002)  //!< Bit mask for ENET_ECR_ETHEREN.

//! @brief Get value of ENET_ECR_ETHEREN from a register value.
#define BG_ENET_ECR_ETHEREN(r)   (((r) & BM_ENET_ECR_ETHEREN) >> BP_ENET_ECR_ETHEREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ECR_ETHEREN.
#define BF_ENET_ECR_ETHEREN(v)   ((((reg32_t) v) << BP_ENET_ECR_ETHEREN) & BM_ENET_ECR_ETHEREN)
#else
//! @brief Format value for bitfield ENET_ECR_ETHEREN.
#define BF_ENET_ECR_ETHEREN(v)   (((v) << BP_ENET_ECR_ETHEREN) & BM_ENET_ECR_ETHEREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ETHEREN field to a new value.
#define BW_ENET_ECR_ETHEREN(v)   (HW_ENET_ECR_WR((HW_ENET_ECR_RD() & ~BM_ENET_ECR_ETHEREN) | BF_ENET_ECR_ETHEREN(v)))
#endif


/* --- Register HW_ENET_ECR, field MAGICEN[2] (RW)
 *
 * Enables/disables magic packet detection. MAGICEN is relevant only if the SLEEP field is set. If
 * MAGICEN is set, changing the SLEEP field enables/disables sleep mode and magic packet detection.
 *
 * Values:
 * 0 - Magic detection logic disabled.
 * 1 - The MAC core detects magic packets and asserts EIR[WAKEUP] when a frame is detected.
 */

#define BP_ENET_ECR_MAGICEN      (2)      //!< Bit position for ENET_ECR_MAGICEN.
#define BM_ENET_ECR_MAGICEN      (0x00000004)  //!< Bit mask for ENET_ECR_MAGICEN.

//! @brief Get value of ENET_ECR_MAGICEN from a register value.
#define BG_ENET_ECR_MAGICEN(r)   (((r) & BM_ENET_ECR_MAGICEN) >> BP_ENET_ECR_MAGICEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ECR_MAGICEN.
#define BF_ENET_ECR_MAGICEN(v)   ((((reg32_t) v) << BP_ENET_ECR_MAGICEN) & BM_ENET_ECR_MAGICEN)
#else
//! @brief Format value for bitfield ENET_ECR_MAGICEN.
#define BF_ENET_ECR_MAGICEN(v)   (((v) << BP_ENET_ECR_MAGICEN) & BM_ENET_ECR_MAGICEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MAGICEN field to a new value.
#define BW_ENET_ECR_MAGICEN(v)   (HW_ENET_ECR_WR((HW_ENET_ECR_RD() & ~BM_ENET_ECR_MAGICEN) | BF_ENET_ECR_MAGICEN(v)))
#endif


/* --- Register HW_ENET_ECR, field SLEEP[3] (RW)
 *

 *
 * Values:
 * 0 - Normal operating mode.
 * 1 - Sleep mode.
 */

#define BP_ENET_ECR_SLEEP      (3)      //!< Bit position for ENET_ECR_SLEEP.
#define BM_ENET_ECR_SLEEP      (0x00000008)  //!< Bit mask for ENET_ECR_SLEEP.

//! @brief Get value of ENET_ECR_SLEEP from a register value.
#define BG_ENET_ECR_SLEEP(r)   (((r) & BM_ENET_ECR_SLEEP) >> BP_ENET_ECR_SLEEP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ECR_SLEEP.
#define BF_ENET_ECR_SLEEP(v)   ((((reg32_t) v) << BP_ENET_ECR_SLEEP) & BM_ENET_ECR_SLEEP)
#else
//! @brief Format value for bitfield ENET_ECR_SLEEP.
#define BF_ENET_ECR_SLEEP(v)   (((v) << BP_ENET_ECR_SLEEP) & BM_ENET_ECR_SLEEP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SLEEP field to a new value.
#define BW_ENET_ECR_SLEEP(v)   (HW_ENET_ECR_WR((HW_ENET_ECR_RD() & ~BM_ENET_ECR_SLEEP) | BF_ENET_ECR_SLEEP(v)))
#endif


/* --- Register HW_ENET_ECR, field EN1588[4] (RW)
 *
 * Enables enhanced functionality of the MAC.
 *
 * Values:
 * 0 - Legacy FEC buffer descriptors and functions enabled.
 * 1 - Enhanced frame time-stamping functions enabled. Has no effect within the MAC besides controlling the
 *     DMA control bit ena_1588.
 */

#define BP_ENET_ECR_EN1588      (4)      //!< Bit position for ENET_ECR_EN1588.
#define BM_ENET_ECR_EN1588      (0x00000010)  //!< Bit mask for ENET_ECR_EN1588.

//! @brief Get value of ENET_ECR_EN1588 from a register value.
#define BG_ENET_ECR_EN1588(r)   (((r) & BM_ENET_ECR_EN1588) >> BP_ENET_ECR_EN1588)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ECR_EN1588.
#define BF_ENET_ECR_EN1588(v)   ((((reg32_t) v) << BP_ENET_ECR_EN1588) & BM_ENET_ECR_EN1588)
#else
//! @brief Format value for bitfield ENET_ECR_EN1588.
#define BF_ENET_ECR_EN1588(v)   (((v) << BP_ENET_ECR_EN1588) & BM_ENET_ECR_EN1588)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN1588 field to a new value.
#define BW_ENET_ECR_EN1588(v)   (HW_ENET_ECR_WR((HW_ENET_ECR_RD() & ~BM_ENET_ECR_EN1588) | BF_ENET_ECR_EN1588(v)))
#endif


/* --- Register HW_ENET_ECR, field DBGEN[6] (RW)
 *
 * Enables debug input pin mac_freeze the MAC to enter hardware freeze mode when the device enters
 * debug mode. In addition, the bit setting is available on the toplevel signal dbg_en.
 *
 * Values:
 * 0 - MAC continues operation in debug mode.
 * 1 - MAC enters hardware freeze mode when the processor is in debug mode.
 */

#define BP_ENET_ECR_DBGEN      (6)      //!< Bit position for ENET_ECR_DBGEN.
#define BM_ENET_ECR_DBGEN      (0x00000040)  //!< Bit mask for ENET_ECR_DBGEN.

//! @brief Get value of ENET_ECR_DBGEN from a register value.
#define BG_ENET_ECR_DBGEN(r)   (((r) & BM_ENET_ECR_DBGEN) >> BP_ENET_ECR_DBGEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ECR_DBGEN.
#define BF_ENET_ECR_DBGEN(v)   ((((reg32_t) v) << BP_ENET_ECR_DBGEN) & BM_ENET_ECR_DBGEN)
#else
//! @brief Format value for bitfield ENET_ECR_DBGEN.
#define BF_ENET_ECR_DBGEN(v)   (((v) << BP_ENET_ECR_DBGEN) & BM_ENET_ECR_DBGEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DBGEN field to a new value.
#define BW_ENET_ECR_DBGEN(v)   (HW_ENET_ECR_WR((HW_ENET_ECR_RD() & ~BM_ENET_ECR_DBGEN) | BF_ENET_ECR_DBGEN(v)))
#endif


/* --- Register HW_ENET_ECR, field STOPEN[7] (RW)
 *
 * Controls toplevel output pin stop_en. Has no effect inside the core beside controlling the pin
 * device behavior in doze mode. In doze mode, if this field is set then all the clocks of the ENET
 * assembly are disabled, except the RMII /MII clock. Doze mode is similar to a conditional stop
 * mode entry for the ENET assembly depending on ECR[STOPEN]. If module clocks are gated in this
 * mode, the module can still wake the system after receiving a magic packet in stop mode. MAGICEN
 * must be set prior to entering sleep/stop mode.
 */

#define BP_ENET_ECR_STOPEN      (7)      //!< Bit position for ENET_ECR_STOPEN.
#define BM_ENET_ECR_STOPEN      (0x00000080)  //!< Bit mask for ENET_ECR_STOPEN.

//! @brief Get value of ENET_ECR_STOPEN from a register value.
#define BG_ENET_ECR_STOPEN(r)   (((r) & BM_ENET_ECR_STOPEN) >> BP_ENET_ECR_STOPEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ECR_STOPEN.
#define BF_ENET_ECR_STOPEN(v)   ((((reg32_t) v) << BP_ENET_ECR_STOPEN) & BM_ENET_ECR_STOPEN)
#else
//! @brief Format value for bitfield ENET_ECR_STOPEN.
#define BF_ENET_ECR_STOPEN(v)   (((v) << BP_ENET_ECR_STOPEN) & BM_ENET_ECR_STOPEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STOPEN field to a new value.
#define BW_ENET_ECR_STOPEN(v)   (HW_ENET_ECR_WR((HW_ENET_ECR_RD() & ~BM_ENET_ECR_STOPEN) | BF_ENET_ECR_STOPEN(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_MMFR - MII Management Frame Register (RW)
 *
 * Reset value: 0x00000000
 *
 * Writing to MMFR triggers a management frame transaction to the PHY device unless MSCR is
 * programmed to zero.  If MSCR is changed from zero to non-zero during a write to MMFR, an MII
 * frame is generated with the data previously written to the MMFR. If MSCR is cleared while MMFR is
 * written and then MSCR is written with a non-zero value, an MII frame is generated with the data
 * previously written to the MMFR. This allows MMFR and MSCR to be programmed in either order if
 * MSCR is currently zero.  If the MMFR register is written while frame generation is in progress,
 * the frame contents are altered. Software must use the EIR[MII] interrupt indication to avoid
 * writing to the MMFR register while frame generation is in progress.
 */
typedef union _hw_enet_mmfr
{
    reg32_t U;
    struct _hw_enet_mmfr_bitfields
    {
        unsigned DATA : 16; //!< [15:0] This is the field for data to be written to or read from the PHY register.
        unsigned TA : 2; //!< [17:16] This field must be programmed to 10 to generate a valid MII management frame.
        unsigned RA : 5; //!< [22:18] Specifies one of up to 32 registers within the specified PHY device.
        unsigned PA : 5; //!< [27:23] Specifies one of up to 32 attached PHY devices.
        unsigned OP : 2; //!< [29:28] Determines the frame operation.
        unsigned ST : 2; //!< [31:30] These fields must be programmed to 01 for a valid MII management frame.
    } B;
} hw_enet_mmfr_t;
#endif

/*
 * constants & macros for entire ENET_MMFR register
 */
#define HW_ENET_MMFR_ADDR      (REGS_ENET_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_MMFR           (*(volatile hw_enet_mmfr_t *) HW_ENET_MMFR_ADDR)
#define HW_ENET_MMFR_RD()      (HW_ENET_MMFR.U)
#define HW_ENET_MMFR_WR(v)     (HW_ENET_MMFR.U = (v))
#define HW_ENET_MMFR_SET(v)    (HW_ENET_MMFR_WR(HW_ENET_MMFR_RD() |  (v)))
#define HW_ENET_MMFR_CLR(v)    (HW_ENET_MMFR_WR(HW_ENET_MMFR_RD() & ~(v)))
#define HW_ENET_MMFR_TOG(v)    (HW_ENET_MMFR_WR(HW_ENET_MMFR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_MMFR bitfields
 */

/* --- Register HW_ENET_MMFR, field DATA[15:0] (RW)
 *
 * This is the field for data to be written to or read from the PHY register.
 */

#define BP_ENET_MMFR_DATA      (0)      //!< Bit position for ENET_MMFR_DATA.
#define BM_ENET_MMFR_DATA      (0x0000ffff)  //!< Bit mask for ENET_MMFR_DATA.

//! @brief Get value of ENET_MMFR_DATA from a register value.
#define BG_ENET_MMFR_DATA(r)   (((r) & BM_ENET_MMFR_DATA) >> BP_ENET_MMFR_DATA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MMFR_DATA.
#define BF_ENET_MMFR_DATA(v)   ((((reg32_t) v) << BP_ENET_MMFR_DATA) & BM_ENET_MMFR_DATA)
#else
//! @brief Format value for bitfield ENET_MMFR_DATA.
#define BF_ENET_MMFR_DATA(v)   (((v) << BP_ENET_MMFR_DATA) & BM_ENET_MMFR_DATA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA field to a new value.
#define BW_ENET_MMFR_DATA(v)   (HW_ENET_MMFR_WR((HW_ENET_MMFR_RD() & ~BM_ENET_MMFR_DATA) | BF_ENET_MMFR_DATA(v)))
#endif

/* --- Register HW_ENET_MMFR, field TA[17:16] (RW)
 *
 * This field must be programmed to 10 to generate a valid MII management frame.
 */

#define BP_ENET_MMFR_TA      (16)      //!< Bit position for ENET_MMFR_TA.
#define BM_ENET_MMFR_TA      (0x00030000)  //!< Bit mask for ENET_MMFR_TA.

//! @brief Get value of ENET_MMFR_TA from a register value.
#define BG_ENET_MMFR_TA(r)   (((r) & BM_ENET_MMFR_TA) >> BP_ENET_MMFR_TA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MMFR_TA.
#define BF_ENET_MMFR_TA(v)   ((((reg32_t) v) << BP_ENET_MMFR_TA) & BM_ENET_MMFR_TA)
#else
//! @brief Format value for bitfield ENET_MMFR_TA.
#define BF_ENET_MMFR_TA(v)   (((v) << BP_ENET_MMFR_TA) & BM_ENET_MMFR_TA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TA field to a new value.
#define BW_ENET_MMFR_TA(v)   (HW_ENET_MMFR_WR((HW_ENET_MMFR_RD() & ~BM_ENET_MMFR_TA) | BF_ENET_MMFR_TA(v)))
#endif

/* --- Register HW_ENET_MMFR, field RA[22:18] (RW)
 *
 * Specifies one of up to 32 registers within the specified PHY device.
 */

#define BP_ENET_MMFR_RA      (18)      //!< Bit position for ENET_MMFR_RA.
#define BM_ENET_MMFR_RA      (0x007c0000)  //!< Bit mask for ENET_MMFR_RA.

//! @brief Get value of ENET_MMFR_RA from a register value.
#define BG_ENET_MMFR_RA(r)   (((r) & BM_ENET_MMFR_RA) >> BP_ENET_MMFR_RA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MMFR_RA.
#define BF_ENET_MMFR_RA(v)   ((((reg32_t) v) << BP_ENET_MMFR_RA) & BM_ENET_MMFR_RA)
#else
//! @brief Format value for bitfield ENET_MMFR_RA.
#define BF_ENET_MMFR_RA(v)   (((v) << BP_ENET_MMFR_RA) & BM_ENET_MMFR_RA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RA field to a new value.
#define BW_ENET_MMFR_RA(v)   (HW_ENET_MMFR_WR((HW_ENET_MMFR_RD() & ~BM_ENET_MMFR_RA) | BF_ENET_MMFR_RA(v)))
#endif

/* --- Register HW_ENET_MMFR, field PA[27:23] (RW)
 *
 * Specifies one of up to 32 attached PHY devices.
 */

#define BP_ENET_MMFR_PA      (23)      //!< Bit position for ENET_MMFR_PA.
#define BM_ENET_MMFR_PA      (0x0f800000)  //!< Bit mask for ENET_MMFR_PA.

//! @brief Get value of ENET_MMFR_PA from a register value.
#define BG_ENET_MMFR_PA(r)   (((r) & BM_ENET_MMFR_PA) >> BP_ENET_MMFR_PA)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MMFR_PA.
#define BF_ENET_MMFR_PA(v)   ((((reg32_t) v) << BP_ENET_MMFR_PA) & BM_ENET_MMFR_PA)
#else
//! @brief Format value for bitfield ENET_MMFR_PA.
#define BF_ENET_MMFR_PA(v)   (((v) << BP_ENET_MMFR_PA) & BM_ENET_MMFR_PA)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PA field to a new value.
#define BW_ENET_MMFR_PA(v)   (HW_ENET_MMFR_WR((HW_ENET_MMFR_RD() & ~BM_ENET_MMFR_PA) | BF_ENET_MMFR_PA(v)))
#endif

/* --- Register HW_ENET_MMFR, field OP[29:28] (RW)
 *
 * Determines the frame operation.
 *
 * Values:
 * 00 - Write frame operation, but not MII compliant.
 * 01 - Write frame operation for a valid MII management frame.
 * 10 - Read frame operation for a valid MII management frame.
 * 11 - Read frame operation, but not MII compliant.
 */

#define BP_ENET_MMFR_OP      (28)      //!< Bit position for ENET_MMFR_OP.
#define BM_ENET_MMFR_OP      (0x30000000)  //!< Bit mask for ENET_MMFR_OP.

//! @brief Get value of ENET_MMFR_OP from a register value.
#define BG_ENET_MMFR_OP(r)   (((r) & BM_ENET_MMFR_OP) >> BP_ENET_MMFR_OP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MMFR_OP.
#define BF_ENET_MMFR_OP(v)   ((((reg32_t) v) << BP_ENET_MMFR_OP) & BM_ENET_MMFR_OP)
#else
//! @brief Format value for bitfield ENET_MMFR_OP.
#define BF_ENET_MMFR_OP(v)   (((v) << BP_ENET_MMFR_OP) & BM_ENET_MMFR_OP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OP field to a new value.
#define BW_ENET_MMFR_OP(v)   (HW_ENET_MMFR_WR((HW_ENET_MMFR_RD() & ~BM_ENET_MMFR_OP) | BF_ENET_MMFR_OP(v)))
#endif


/* --- Register HW_ENET_MMFR, field ST[31:30] (RW)
 *
 * These fields must be programmed to 01 for a valid MII management frame.
 */

#define BP_ENET_MMFR_ST      (30)      //!< Bit position for ENET_MMFR_ST.
#define BM_ENET_MMFR_ST      (0xc0000000)  //!< Bit mask for ENET_MMFR_ST.

//! @brief Get value of ENET_MMFR_ST from a register value.
#define BG_ENET_MMFR_ST(r)   (((r) & BM_ENET_MMFR_ST) >> BP_ENET_MMFR_ST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MMFR_ST.
#define BF_ENET_MMFR_ST(v)   ((((reg32_t) v) << BP_ENET_MMFR_ST) & BM_ENET_MMFR_ST)
#else
//! @brief Format value for bitfield ENET_MMFR_ST.
#define BF_ENET_MMFR_ST(v)   (((v) << BP_ENET_MMFR_ST) & BM_ENET_MMFR_ST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ST field to a new value.
#define BW_ENET_MMFR_ST(v)   (HW_ENET_MMFR_WR((HW_ENET_MMFR_RD() & ~BM_ENET_MMFR_ST) | BF_ENET_MMFR_ST(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_MSCR - MII Speed Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * MSCR provides control of the MII clock (MDC pin) frequency and allows a preamble drop on the MII
 * management frame.  The MII_SPEED field must be programmed with a value to provide an MDC
 * frequency of less than or equal to 2.5 MHz to be compliant with the IEEE 802.3 MII specification.
 * The MII_SPEED must be set to a non-zero value to source a read or write management frame. After
 * the management frame is complete, the MSCR register may optionally be cleared to turn off MDC.
 * The MDC signal generated has a 50% duty cycle except when MII_SPEED changes during operation.
 * This change takes effect following a rising or falling edge of MDC.  If the internal module clock
 * is 25 MHz, programming this register to 0x0000_0004 results in an MDC as stated in the following
 * equation:  25 MHz / ((4 + 1) x 2) = 2.5 MHz  The following table shows the optimum values for
 * MII_SPEED as a function of internal module clock frequency.   Programming Examples for MSCR
 * Internal MAC clock frequency  MSCR [MII_SPEED]  MDC frequency      25 MHz  0x4  2.50 MHz    33
 * MHz  0x6  2.36 MHz    40 MHz  0x7  2.50 MHz    50 MHz  0x9  2.50 MHz    66 MHz  0xD  2.36 MHz
 */
typedef union _hw_enet_mscr
{
    reg32_t U;
    struct _hw_enet_mscr_bitfields
    {
        unsigned RESERVED0 : 1; //!< [0] 
        unsigned MII_SPEED : 6; //!< [6:1] Controls the frequency of the MII management interface clock (MDC) relative to the internal module clock. A value of 0 in this field turns off MDC and leaves it in low voltage state. Any non-zero value results in the MDC frequency of: 1/((MII_SPEED + 1) x 2) of the internal module clock frequency (ipg_clk_s)
        unsigned DIS_PRE : 1; //!< [7] Enables/disables prepending a preamble to the MII management frame. The MII standard allows the preamble to be dropped if the attached PHY devices do not require it.
        unsigned HOLDTIME : 3; //!< [10:8] IEEE802.3 clause 22 defines a minimum of 10 ns for the holdtime on the MDIO output. Depending on the host bus frequency, the setting may need to be increased.
        unsigned RESERVED1 : 21; //!< [31:11] 
    } B;
} hw_enet_mscr_t;
#endif

/*
 * constants & macros for entire ENET_MSCR register
 */
#define HW_ENET_MSCR_ADDR      (REGS_ENET_BASE + 0x44)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_MSCR           (*(volatile hw_enet_mscr_t *) HW_ENET_MSCR_ADDR)
#define HW_ENET_MSCR_RD()      (HW_ENET_MSCR.U)
#define HW_ENET_MSCR_WR(v)     (HW_ENET_MSCR.U = (v))
#define HW_ENET_MSCR_SET(v)    (HW_ENET_MSCR_WR(HW_ENET_MSCR_RD() |  (v)))
#define HW_ENET_MSCR_CLR(v)    (HW_ENET_MSCR_WR(HW_ENET_MSCR_RD() & ~(v)))
#define HW_ENET_MSCR_TOG(v)    (HW_ENET_MSCR_WR(HW_ENET_MSCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_MSCR bitfields
 */

/* --- Register HW_ENET_MSCR, field MII_SPEED[6:1] (RW)
 *
 * Controls the frequency of the MII management interface clock (MDC) relative to the internal
 * module clock. A value of 0 in this field turns off MDC and leaves it in low voltage state. Any
 * non-zero value results in the MDC frequency of: 1/((MII_SPEED + 1) x 2) of the internal module
 * clock frequency (ipg_clk_s)
 */

#define BP_ENET_MSCR_MII_SPEED      (1)      //!< Bit position for ENET_MSCR_MII_SPEED.
#define BM_ENET_MSCR_MII_SPEED      (0x0000007e)  //!< Bit mask for ENET_MSCR_MII_SPEED.

//! @brief Get value of ENET_MSCR_MII_SPEED from a register value.
#define BG_ENET_MSCR_MII_SPEED(r)   (((r) & BM_ENET_MSCR_MII_SPEED) >> BP_ENET_MSCR_MII_SPEED)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MSCR_MII_SPEED.
#define BF_ENET_MSCR_MII_SPEED(v)   ((((reg32_t) v) << BP_ENET_MSCR_MII_SPEED) & BM_ENET_MSCR_MII_SPEED)
#else
//! @brief Format value for bitfield ENET_MSCR_MII_SPEED.
#define BF_ENET_MSCR_MII_SPEED(v)   (((v) << BP_ENET_MSCR_MII_SPEED) & BM_ENET_MSCR_MII_SPEED)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MII_SPEED field to a new value.
#define BW_ENET_MSCR_MII_SPEED(v)   (HW_ENET_MSCR_WR((HW_ENET_MSCR_RD() & ~BM_ENET_MSCR_MII_SPEED) | BF_ENET_MSCR_MII_SPEED(v)))
#endif

/* --- Register HW_ENET_MSCR, field DIS_PRE[7] (RW)
 *
 * Enables/disables prepending a preamble to the MII management frame. The MII standard allows the
 * preamble to be dropped if the attached PHY devices do not require it.
 *
 * Values:
 * 0 - Preamble enabled.
 * 1 - Preamble (32 ones) is not prepended to the MII management frame.
 */

#define BP_ENET_MSCR_DIS_PRE      (7)      //!< Bit position for ENET_MSCR_DIS_PRE.
#define BM_ENET_MSCR_DIS_PRE      (0x00000080)  //!< Bit mask for ENET_MSCR_DIS_PRE.

//! @brief Get value of ENET_MSCR_DIS_PRE from a register value.
#define BG_ENET_MSCR_DIS_PRE(r)   (((r) & BM_ENET_MSCR_DIS_PRE) >> BP_ENET_MSCR_DIS_PRE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MSCR_DIS_PRE.
#define BF_ENET_MSCR_DIS_PRE(v)   ((((reg32_t) v) << BP_ENET_MSCR_DIS_PRE) & BM_ENET_MSCR_DIS_PRE)
#else
//! @brief Format value for bitfield ENET_MSCR_DIS_PRE.
#define BF_ENET_MSCR_DIS_PRE(v)   (((v) << BP_ENET_MSCR_DIS_PRE) & BM_ENET_MSCR_DIS_PRE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DIS_PRE field to a new value.
#define BW_ENET_MSCR_DIS_PRE(v)   (HW_ENET_MSCR_WR((HW_ENET_MSCR_RD() & ~BM_ENET_MSCR_DIS_PRE) | BF_ENET_MSCR_DIS_PRE(v)))
#endif


/* --- Register HW_ENET_MSCR, field HOLDTIME[10:8] (RW)
 *
 * IEEE802.3 clause 22 defines a minimum of 10 ns for the holdtime on the MDIO output. Depending on
 * the host bus frequency, the setting may need to be increased.
 *
 * Values:
 * 000 - 1 internal module clock pclk (ipg_clk_s) cycle
 * 001 - 2 internal module clock pclk (ipg_clk_s) cycles
 * 010 - 3 internal module clock pclk (ipg_clk_s) cycles
 * 111 - 8 internal module clock pclk (ipg_clk_s) cycles
 */

#define BP_ENET_MSCR_HOLDTIME      (8)      //!< Bit position for ENET_MSCR_HOLDTIME.
#define BM_ENET_MSCR_HOLDTIME      (0x00000700)  //!< Bit mask for ENET_MSCR_HOLDTIME.

//! @brief Get value of ENET_MSCR_HOLDTIME from a register value.
#define BG_ENET_MSCR_HOLDTIME(r)   (((r) & BM_ENET_MSCR_HOLDTIME) >> BP_ENET_MSCR_HOLDTIME)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MSCR_HOLDTIME.
#define BF_ENET_MSCR_HOLDTIME(v)   ((((reg32_t) v) << BP_ENET_MSCR_HOLDTIME) & BM_ENET_MSCR_HOLDTIME)
#else
//! @brief Format value for bitfield ENET_MSCR_HOLDTIME.
#define BF_ENET_MSCR_HOLDTIME(v)   (((v) << BP_ENET_MSCR_HOLDTIME) & BM_ENET_MSCR_HOLDTIME)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the HOLDTIME field to a new value.
#define BW_ENET_MSCR_HOLDTIME(v)   (HW_ENET_MSCR_WR((HW_ENET_MSCR_RD() & ~BM_ENET_MSCR_HOLDTIME) | BF_ENET_MSCR_HOLDTIME(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_MIBC - MIB Control Register (RW)
 *
 * Reset value: 0xc0000000
 *
 * MIBC is a read/write register controlling and observing the state of the MIB block. Access this
 * register to disable the MIB block operation or clear the MIB counters. The MIB_DIS field resets
 * to 1.
 */
typedef union _hw_enet_mibc
{
    reg32_t U;
    struct _hw_enet_mibc_bitfields
    {
        unsigned RESERVED0 : 29; //!< [28:0] 
        unsigned MIB_CLEAR : 1; //!< [29] If set, all statistics counters are reset to 0. This field is not self-clearing. To clear the MIB counters set and then clear the field.
        unsigned MIB_IDLE : 1; //!< [30] If this status field is set, the MIB block is not currently updating any MIB counters.
        unsigned MIB_DIS : 1; //!< [31] If this control field is set, the MIB logic halts and does not update any MIB counters.
    } B;
} hw_enet_mibc_t;
#endif

/*
 * constants & macros for entire ENET_MIBC register
 */
#define HW_ENET_MIBC_ADDR      (REGS_ENET_BASE + 0x64)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_MIBC           (*(volatile hw_enet_mibc_t *) HW_ENET_MIBC_ADDR)
#define HW_ENET_MIBC_RD()      (HW_ENET_MIBC.U)
#define HW_ENET_MIBC_WR(v)     (HW_ENET_MIBC.U = (v))
#define HW_ENET_MIBC_SET(v)    (HW_ENET_MIBC_WR(HW_ENET_MIBC_RD() |  (v)))
#define HW_ENET_MIBC_CLR(v)    (HW_ENET_MIBC_WR(HW_ENET_MIBC_RD() & ~(v)))
#define HW_ENET_MIBC_TOG(v)    (HW_ENET_MIBC_WR(HW_ENET_MIBC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_MIBC bitfields
 */

/* --- Register HW_ENET_MIBC, field MIB_CLEAR[29] (RW)
 *
 * If set, all statistics counters are reset to 0. This field is not self-clearing. To clear the MIB
 * counters set and then clear the field.
 */

#define BP_ENET_MIBC_MIB_CLEAR      (29)      //!< Bit position for ENET_MIBC_MIB_CLEAR.
#define BM_ENET_MIBC_MIB_CLEAR      (0x20000000)  //!< Bit mask for ENET_MIBC_MIB_CLEAR.

//! @brief Get value of ENET_MIBC_MIB_CLEAR from a register value.
#define BG_ENET_MIBC_MIB_CLEAR(r)   (((r) & BM_ENET_MIBC_MIB_CLEAR) >> BP_ENET_MIBC_MIB_CLEAR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MIBC_MIB_CLEAR.
#define BF_ENET_MIBC_MIB_CLEAR(v)   ((((reg32_t) v) << BP_ENET_MIBC_MIB_CLEAR) & BM_ENET_MIBC_MIB_CLEAR)
#else
//! @brief Format value for bitfield ENET_MIBC_MIB_CLEAR.
#define BF_ENET_MIBC_MIB_CLEAR(v)   (((v) << BP_ENET_MIBC_MIB_CLEAR) & BM_ENET_MIBC_MIB_CLEAR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MIB_CLEAR field to a new value.
#define BW_ENET_MIBC_MIB_CLEAR(v)   (HW_ENET_MIBC_WR((HW_ENET_MIBC_RD() & ~BM_ENET_MIBC_MIB_CLEAR) | BF_ENET_MIBC_MIB_CLEAR(v)))
#endif

/* --- Register HW_ENET_MIBC, field MIB_IDLE[30] (RO)
 *
 * If this status field is set, the MIB block is not currently updating any MIB counters.
 */

#define BP_ENET_MIBC_MIB_IDLE      (30)      //!< Bit position for ENET_MIBC_MIB_IDLE.
#define BM_ENET_MIBC_MIB_IDLE      (0x40000000)  //!< Bit mask for ENET_MIBC_MIB_IDLE.

//! @brief Get value of ENET_MIBC_MIB_IDLE from a register value.
#define BG_ENET_MIBC_MIB_IDLE(r)   (((r) & BM_ENET_MIBC_MIB_IDLE) >> BP_ENET_MIBC_MIB_IDLE)

/* --- Register HW_ENET_MIBC, field MIB_DIS[31] (RW)
 *
 * If this control field is set, the MIB logic halts and does not update any MIB counters.
 */

#define BP_ENET_MIBC_MIB_DIS      (31)      //!< Bit position for ENET_MIBC_MIB_DIS.
#define BM_ENET_MIBC_MIB_DIS      (0x80000000)  //!< Bit mask for ENET_MIBC_MIB_DIS.

//! @brief Get value of ENET_MIBC_MIB_DIS from a register value.
#define BG_ENET_MIBC_MIB_DIS(r)   (((r) & BM_ENET_MIBC_MIB_DIS) >> BP_ENET_MIBC_MIB_DIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MIBC_MIB_DIS.
#define BF_ENET_MIBC_MIB_DIS(v)   ((((reg32_t) v) << BP_ENET_MIBC_MIB_DIS) & BM_ENET_MIBC_MIB_DIS)
#else
//! @brief Format value for bitfield ENET_MIBC_MIB_DIS.
#define BF_ENET_MIBC_MIB_DIS(v)   (((v) << BP_ENET_MIBC_MIB_DIS) & BM_ENET_MIBC_MIB_DIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MIB_DIS field to a new value.
#define BW_ENET_MIBC_MIB_DIS(v)   (HW_ENET_MIBC_WR((HW_ENET_MIBC_RD() & ~BM_ENET_MIBC_MIB_DIS) | BF_ENET_MIBC_MIB_DIS(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RCR - Receive Control Register (RW)
 *
 * Reset value: 0x05ee0001
 *

 */
typedef union _hw_enet_rcr
{
    reg32_t U;
    struct _hw_enet_rcr_bitfields
    {
        unsigned LOOP : 1; //!< [0] This is an MII internal loopback, therefore MII_MODE must be written to 1 and RMII_MODE must be written to 0.
        unsigned DRT : 1; //!< [1] 
        unsigned MII_MODE : 1; //!< [2] This field must always be set.
        unsigned PROM : 1; //!< [3] All frames are accepted regardless of address matching.
        unsigned BC_REJ : 1; //!< [4] If set, frames with destination address (DA) equal to 0xFFFF_FFFF_FFFF are rejected unless the PROM field is set. If BC_REJ and PROM are set, frames with broadcast DA are accepted and the MISS (M) is set in the receive buffer descriptor.
        unsigned FCE : 1; //!< [5] If set, the receiver detects PAUSE frames. Upon PAUSE frame detection, the transmitter stops transmitting data frames for a given duration.
        unsigned RESERVED0 : 2; //!< [7:6] Reserved.
        unsigned RMII_MODE : 1; //!< [8] Specifies whether the MAC is configured for MII mode or RMII operation , when ECR[SPEED] is cleared . Do not set both RCR[RGMII_EN] or RCR[RMII_MODE].
        unsigned RMII_10T : 1; //!< [9] Enables 10-Mbps mode of the RMII or RGMII .
        unsigned RESERVED1 : 2; //!< [11:10] 
        unsigned PADEN : 1; //!< [12] Specifies whether the MAC removes padding from received frames.
        unsigned PAUFWD : 1; //!< [13] Specifies whether pause frames are terminated or forwarded.
        unsigned CRCFWD : 1; //!< [14] Specifies whether the CRC field of received frames is transmitted or stripped. If padding function is enabled (PADEN = 1), CRCFWD is ignored and the CRC field is checked and always terminated and removed.
        unsigned CFEN : 1; //!< [15] Enables/disables the MAC control frame.
        unsigned MAX_FL : 14; //!< [29:16] Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the frame. Transmit frames longer than MAX_FL cause the BABT interrupt to occur. Receive frames longer than MAX_FL cause the BABR interrupt to occur and set the LG field in the end of frame receive buffer descriptor. The recommended default value to be programmed is 1518 or 1522 if VLAN tags are supported.
        unsigned NLC : 1; //!< [30] Enables/disables a payload length check.
        unsigned GRS : 1; //!< [31] Read-only status indicating that the MAC receive datapath is stopped.
    } B;
} hw_enet_rcr_t;
#endif

/*
 * constants & macros for entire ENET_RCR register
 */
#define HW_ENET_RCR_ADDR      (REGS_ENET_BASE + 0x84)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RCR           (*(volatile hw_enet_rcr_t *) HW_ENET_RCR_ADDR)
#define HW_ENET_RCR_RD()      (HW_ENET_RCR.U)
#define HW_ENET_RCR_WR(v)     (HW_ENET_RCR.U = (v))
#define HW_ENET_RCR_SET(v)    (HW_ENET_RCR_WR(HW_ENET_RCR_RD() |  (v)))
#define HW_ENET_RCR_CLR(v)    (HW_ENET_RCR_WR(HW_ENET_RCR_RD() & ~(v)))
#define HW_ENET_RCR_TOG(v)    (HW_ENET_RCR_WR(HW_ENET_RCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RCR bitfields
 */

/* --- Register HW_ENET_RCR, field LOOP[0] (RW)
 *
 * This is an MII internal loopback, therefore MII_MODE must be written to 1 and RMII_MODE must be
 * written to 0.
 *
 * Values:
 * 0 - Loopback disabled.
 * 1 - Transmitted frames are looped back internal to the device and transmit MII output signals are not
 *     asserted. DRT must be cleared. When set the Core signal ena_loop is set to '1'.
 */

#define BP_ENET_RCR_LOOP      (0)      //!< Bit position for ENET_RCR_LOOP.
#define BM_ENET_RCR_LOOP      (0x00000001)  //!< Bit mask for ENET_RCR_LOOP.

//! @brief Get value of ENET_RCR_LOOP from a register value.
#define BG_ENET_RCR_LOOP(r)   (((r) & BM_ENET_RCR_LOOP) >> BP_ENET_RCR_LOOP)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_LOOP.
#define BF_ENET_RCR_LOOP(v)   ((((reg32_t) v) << BP_ENET_RCR_LOOP) & BM_ENET_RCR_LOOP)
#else
//! @brief Format value for bitfield ENET_RCR_LOOP.
#define BF_ENET_RCR_LOOP(v)   (((v) << BP_ENET_RCR_LOOP) & BM_ENET_RCR_LOOP)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LOOP field to a new value.
#define BW_ENET_RCR_LOOP(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_LOOP) | BF_ENET_RCR_LOOP(v)))
#endif


/* --- Register HW_ENET_RCR, field DRT[1] (RW)
 *

 *
 * Values:
 * 0 - Receive path operates independently of transmit. Used for full-duplex or to monitor transmit
 *     activity in half-duplex mode.
 * 1 - Disable reception of frames while transmitting. Normally used for half-duplex mode.
 */

#define BP_ENET_RCR_DRT      (1)      //!< Bit position for ENET_RCR_DRT.
#define BM_ENET_RCR_DRT      (0x00000002)  //!< Bit mask for ENET_RCR_DRT.

//! @brief Get value of ENET_RCR_DRT from a register value.
#define BG_ENET_RCR_DRT(r)   (((r) & BM_ENET_RCR_DRT) >> BP_ENET_RCR_DRT)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_DRT.
#define BF_ENET_RCR_DRT(v)   ((((reg32_t) v) << BP_ENET_RCR_DRT) & BM_ENET_RCR_DRT)
#else
//! @brief Format value for bitfield ENET_RCR_DRT.
#define BF_ENET_RCR_DRT(v)   (((v) << BP_ENET_RCR_DRT) & BM_ENET_RCR_DRT)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the DRT field to a new value.
#define BW_ENET_RCR_DRT(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_DRT) | BF_ENET_RCR_DRT(v)))
#endif


/* --- Register HW_ENET_RCR, field MII_MODE[2] (RW)
 *
 * This field must always be set.
 *
 * Values:
 * 0 - Reserved.
 * 1 - MII or RMII mode, as indicated by the RMII_MODE field.
 */

#define BP_ENET_RCR_MII_MODE      (2)      //!< Bit position for ENET_RCR_MII_MODE.
#define BM_ENET_RCR_MII_MODE      (0x00000004)  //!< Bit mask for ENET_RCR_MII_MODE.

//! @brief Get value of ENET_RCR_MII_MODE from a register value.
#define BG_ENET_RCR_MII_MODE(r)   (((r) & BM_ENET_RCR_MII_MODE) >> BP_ENET_RCR_MII_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_MII_MODE.
#define BF_ENET_RCR_MII_MODE(v)   ((((reg32_t) v) << BP_ENET_RCR_MII_MODE) & BM_ENET_RCR_MII_MODE)
#else
//! @brief Format value for bitfield ENET_RCR_MII_MODE.
#define BF_ENET_RCR_MII_MODE(v)   (((v) << BP_ENET_RCR_MII_MODE) & BM_ENET_RCR_MII_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MII_MODE field to a new value.
#define BW_ENET_RCR_MII_MODE(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_MII_MODE) | BF_ENET_RCR_MII_MODE(v)))
#endif


/* --- Register HW_ENET_RCR, field PROM[3] (RW)
 *
 * All frames are accepted regardless of address matching.
 *
 * Values:
 * 0 - Disabled.
 * 1 - Enabled.
 */

#define BP_ENET_RCR_PROM      (3)      //!< Bit position for ENET_RCR_PROM.
#define BM_ENET_RCR_PROM      (0x00000008)  //!< Bit mask for ENET_RCR_PROM.

//! @brief Get value of ENET_RCR_PROM from a register value.
#define BG_ENET_RCR_PROM(r)   (((r) & BM_ENET_RCR_PROM) >> BP_ENET_RCR_PROM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_PROM.
#define BF_ENET_RCR_PROM(v)   ((((reg32_t) v) << BP_ENET_RCR_PROM) & BM_ENET_RCR_PROM)
#else
//! @brief Format value for bitfield ENET_RCR_PROM.
#define BF_ENET_RCR_PROM(v)   (((v) << BP_ENET_RCR_PROM) & BM_ENET_RCR_PROM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PROM field to a new value.
#define BW_ENET_RCR_PROM(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_PROM) | BF_ENET_RCR_PROM(v)))
#endif


/* --- Register HW_ENET_RCR, field BC_REJ[4] (RW)
 *
 * If set, frames with destination address (DA) equal to 0xFFFF_FFFF_FFFF are rejected unless the
 * PROM field is set. If BC_REJ and PROM are set, frames with broadcast DA are accepted and the MISS
 * (M) is set in the receive buffer descriptor.
 */

#define BP_ENET_RCR_BC_REJ      (4)      //!< Bit position for ENET_RCR_BC_REJ.
#define BM_ENET_RCR_BC_REJ      (0x00000010)  //!< Bit mask for ENET_RCR_BC_REJ.

//! @brief Get value of ENET_RCR_BC_REJ from a register value.
#define BG_ENET_RCR_BC_REJ(r)   (((r) & BM_ENET_RCR_BC_REJ) >> BP_ENET_RCR_BC_REJ)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_BC_REJ.
#define BF_ENET_RCR_BC_REJ(v)   ((((reg32_t) v) << BP_ENET_RCR_BC_REJ) & BM_ENET_RCR_BC_REJ)
#else
//! @brief Format value for bitfield ENET_RCR_BC_REJ.
#define BF_ENET_RCR_BC_REJ(v)   (((v) << BP_ENET_RCR_BC_REJ) & BM_ENET_RCR_BC_REJ)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the BC_REJ field to a new value.
#define BW_ENET_RCR_BC_REJ(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_BC_REJ) | BF_ENET_RCR_BC_REJ(v)))
#endif

/* --- Register HW_ENET_RCR, field FCE[5] (RW)
 *
 * If set, the receiver detects PAUSE frames. Upon PAUSE frame detection, the transmitter stops
 * transmitting data frames for a given duration.
 */

#define BP_ENET_RCR_FCE      (5)      //!< Bit position for ENET_RCR_FCE.
#define BM_ENET_RCR_FCE      (0x00000020)  //!< Bit mask for ENET_RCR_FCE.

//! @brief Get value of ENET_RCR_FCE from a register value.
#define BG_ENET_RCR_FCE(r)   (((r) & BM_ENET_RCR_FCE) >> BP_ENET_RCR_FCE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_FCE.
#define BF_ENET_RCR_FCE(v)   ((((reg32_t) v) << BP_ENET_RCR_FCE) & BM_ENET_RCR_FCE)
#else
//! @brief Format value for bitfield ENET_RCR_FCE.
#define BF_ENET_RCR_FCE(v)   (((v) << BP_ENET_RCR_FCE) & BM_ENET_RCR_FCE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FCE field to a new value.
#define BW_ENET_RCR_FCE(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_FCE) | BF_ENET_RCR_FCE(v)))
#endif

/* --- Register HW_ENET_RCR, field RMII_MODE[8] (RW)
 *
 * Specifies whether the MAC is configured for MII mode or RMII operation , when ECR[SPEED] is
 * cleared . Do not set both RCR[RGMII_EN] or RCR[RMII_MODE].
 *
 * Values:
 * 0 - MAC configured for MII mode. The core signal ena_rmii is set to 0.
 * 1 - MAC configured for RMII operation. The core signal ena_rmii is set to 1.
 */

#define BP_ENET_RCR_RMII_MODE      (8)      //!< Bit position for ENET_RCR_RMII_MODE.
#define BM_ENET_RCR_RMII_MODE      (0x00000100)  //!< Bit mask for ENET_RCR_RMII_MODE.

//! @brief Get value of ENET_RCR_RMII_MODE from a register value.
#define BG_ENET_RCR_RMII_MODE(r)   (((r) & BM_ENET_RCR_RMII_MODE) >> BP_ENET_RCR_RMII_MODE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_RMII_MODE.
#define BF_ENET_RCR_RMII_MODE(v)   ((((reg32_t) v) << BP_ENET_RCR_RMII_MODE) & BM_ENET_RCR_RMII_MODE)
#else
//! @brief Format value for bitfield ENET_RCR_RMII_MODE.
#define BF_ENET_RCR_RMII_MODE(v)   (((v) << BP_ENET_RCR_RMII_MODE) & BM_ENET_RCR_RMII_MODE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RMII_MODE field to a new value.
#define BW_ENET_RCR_RMII_MODE(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_RMII_MODE) | BF_ENET_RCR_RMII_MODE(v)))
#endif


/* --- Register HW_ENET_RCR, field RMII_10T[9] (RW)
 *
 * Enables 10-Mbps mode of the RMII or RGMII .
 *
 * Values:
 * 0 - 100 Mbps operation. . The 50 MHz RMII reference clock (RMII_REF_CLK) is sent to the RMII or RGMII ,
 *     while a divided-by-2 version (25 MHz) is sent to the MAC. The core signal set_10 is set to 0.
 * 1 - 10 Mbps operation. . The 50 MHz RMII reference clock (RMII_REF_CLK) is divided by 10 (5 MHz) and
 *     used in the RMII or RGMII , while a divided-by-20 version (2.5 MHz) is sent to the MAC. The
 *     core signal set_10 is set to 1.
 */

#define BP_ENET_RCR_RMII_10T      (9)      //!< Bit position for ENET_RCR_RMII_10T.
#define BM_ENET_RCR_RMII_10T      (0x00000200)  //!< Bit mask for ENET_RCR_RMII_10T.

//! @brief Get value of ENET_RCR_RMII_10T from a register value.
#define BG_ENET_RCR_RMII_10T(r)   (((r) & BM_ENET_RCR_RMII_10T) >> BP_ENET_RCR_RMII_10T)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_RMII_10T.
#define BF_ENET_RCR_RMII_10T(v)   ((((reg32_t) v) << BP_ENET_RCR_RMII_10T) & BM_ENET_RCR_RMII_10T)
#else
//! @brief Format value for bitfield ENET_RCR_RMII_10T.
#define BF_ENET_RCR_RMII_10T(v)   (((v) << BP_ENET_RCR_RMII_10T) & BM_ENET_RCR_RMII_10T)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RMII_10T field to a new value.
#define BW_ENET_RCR_RMII_10T(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_RMII_10T) | BF_ENET_RCR_RMII_10T(v)))
#endif


/* --- Register HW_ENET_RCR, field PADEN[12] (RW)
 *
 * Specifies whether the MAC removes padding from received frames.
 *
 * Values:
 * 0 - No padding is removed on receive by the MAC.
 * 1 - Padding is removed from received frames.
 */

#define BP_ENET_RCR_PADEN      (12)      //!< Bit position for ENET_RCR_PADEN.
#define BM_ENET_RCR_PADEN      (0x00001000)  //!< Bit mask for ENET_RCR_PADEN.

//! @brief Get value of ENET_RCR_PADEN from a register value.
#define BG_ENET_RCR_PADEN(r)   (((r) & BM_ENET_RCR_PADEN) >> BP_ENET_RCR_PADEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_PADEN.
#define BF_ENET_RCR_PADEN(v)   ((((reg32_t) v) << BP_ENET_RCR_PADEN) & BM_ENET_RCR_PADEN)
#else
//! @brief Format value for bitfield ENET_RCR_PADEN.
#define BF_ENET_RCR_PADEN(v)   (((v) << BP_ENET_RCR_PADEN) & BM_ENET_RCR_PADEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PADEN field to a new value.
#define BW_ENET_RCR_PADEN(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_PADEN) | BF_ENET_RCR_PADEN(v)))
#endif


/* --- Register HW_ENET_RCR, field PAUFWD[13] (RW)
 *
 * Specifies whether pause frames are terminated or forwarded.
 *
 * Values:
 * 0 - Pause frames are terminated and discarded in the MAC.
 * 1 - Pause frames are forwarded to the user application.
 */

#define BP_ENET_RCR_PAUFWD      (13)      //!< Bit position for ENET_RCR_PAUFWD.
#define BM_ENET_RCR_PAUFWD      (0x00002000)  //!< Bit mask for ENET_RCR_PAUFWD.

//! @brief Get value of ENET_RCR_PAUFWD from a register value.
#define BG_ENET_RCR_PAUFWD(r)   (((r) & BM_ENET_RCR_PAUFWD) >> BP_ENET_RCR_PAUFWD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_PAUFWD.
#define BF_ENET_RCR_PAUFWD(v)   ((((reg32_t) v) << BP_ENET_RCR_PAUFWD) & BM_ENET_RCR_PAUFWD)
#else
//! @brief Format value for bitfield ENET_RCR_PAUFWD.
#define BF_ENET_RCR_PAUFWD(v)   (((v) << BP_ENET_RCR_PAUFWD) & BM_ENET_RCR_PAUFWD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PAUFWD field to a new value.
#define BW_ENET_RCR_PAUFWD(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_PAUFWD) | BF_ENET_RCR_PAUFWD(v)))
#endif


/* --- Register HW_ENET_RCR, field CRCFWD[14] (RW)
 *
 * Specifies whether the CRC field of received frames is transmitted or stripped. If padding
 * function is enabled (PADEN = 1), CRCFWD is ignored and the CRC field is checked and always
 * terminated and removed.
 *
 * Values:
 * 0 - The CRC field of received frames is transmitted to the user application.
 * 1 - The CRC field is stripped from the frame.
 */

#define BP_ENET_RCR_CRCFWD      (14)      //!< Bit position for ENET_RCR_CRCFWD.
#define BM_ENET_RCR_CRCFWD      (0x00004000)  //!< Bit mask for ENET_RCR_CRCFWD.

//! @brief Get value of ENET_RCR_CRCFWD from a register value.
#define BG_ENET_RCR_CRCFWD(r)   (((r) & BM_ENET_RCR_CRCFWD) >> BP_ENET_RCR_CRCFWD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_CRCFWD.
#define BF_ENET_RCR_CRCFWD(v)   ((((reg32_t) v) << BP_ENET_RCR_CRCFWD) & BM_ENET_RCR_CRCFWD)
#else
//! @brief Format value for bitfield ENET_RCR_CRCFWD.
#define BF_ENET_RCR_CRCFWD(v)   (((v) << BP_ENET_RCR_CRCFWD) & BM_ENET_RCR_CRCFWD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRCFWD field to a new value.
#define BW_ENET_RCR_CRCFWD(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_CRCFWD) | BF_ENET_RCR_CRCFWD(v)))
#endif


/* --- Register HW_ENET_RCR, field CFEN[15] (RW)
 *
 * Enables/disables the MAC control frame.
 *
 * Values:
 * 0 - MAC control frames with any opcode other than 0x0001 (pause frame) are accepted and forwarded to the
 *     client interface.
 * 1 - MAC control frames with any opcode other than 0x0001 (pause frame) are silently discarded.
 */

#define BP_ENET_RCR_CFEN      (15)      //!< Bit position for ENET_RCR_CFEN.
#define BM_ENET_RCR_CFEN      (0x00008000)  //!< Bit mask for ENET_RCR_CFEN.

//! @brief Get value of ENET_RCR_CFEN from a register value.
#define BG_ENET_RCR_CFEN(r)   (((r) & BM_ENET_RCR_CFEN) >> BP_ENET_RCR_CFEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_CFEN.
#define BF_ENET_RCR_CFEN(v)   ((((reg32_t) v) << BP_ENET_RCR_CFEN) & BM_ENET_RCR_CFEN)
#else
//! @brief Format value for bitfield ENET_RCR_CFEN.
#define BF_ENET_RCR_CFEN(v)   (((v) << BP_ENET_RCR_CFEN) & BM_ENET_RCR_CFEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CFEN field to a new value.
#define BW_ENET_RCR_CFEN(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_CFEN) | BF_ENET_RCR_CFEN(v)))
#endif


/* --- Register HW_ENET_RCR, field MAX_FL[29:16] (RW)
 *
 * Resets to decimal 1518. Length is measured starting at DA and includes the CRC at the end of the
 * frame. Transmit frames longer than MAX_FL cause the BABT interrupt to occur. Receive frames
 * longer than MAX_FL cause the BABR interrupt to occur and set the LG field in the end of frame
 * receive buffer descriptor. The recommended default value to be programmed is 1518 or 1522 if VLAN
 * tags are supported.
 */

#define BP_ENET_RCR_MAX_FL      (16)      //!< Bit position for ENET_RCR_MAX_FL.
#define BM_ENET_RCR_MAX_FL      (0x3fff0000)  //!< Bit mask for ENET_RCR_MAX_FL.

//! @brief Get value of ENET_RCR_MAX_FL from a register value.
#define BG_ENET_RCR_MAX_FL(r)   (((r) & BM_ENET_RCR_MAX_FL) >> BP_ENET_RCR_MAX_FL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_MAX_FL.
#define BF_ENET_RCR_MAX_FL(v)   ((((reg32_t) v) << BP_ENET_RCR_MAX_FL) & BM_ENET_RCR_MAX_FL)
#else
//! @brief Format value for bitfield ENET_RCR_MAX_FL.
#define BF_ENET_RCR_MAX_FL(v)   (((v) << BP_ENET_RCR_MAX_FL) & BM_ENET_RCR_MAX_FL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the MAX_FL field to a new value.
#define BW_ENET_RCR_MAX_FL(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_MAX_FL) | BF_ENET_RCR_MAX_FL(v)))
#endif

/* --- Register HW_ENET_RCR, field NLC[30] (RW)
 *
 * Enables/disables a payload length check.
 *
 * Values:
 * 0 - The payload length check is disabled.
 * 1 - The core checks the frame's payload length with the frame length/type field. Errors are indicated in
 *     the EIR[PLC] field.
 */

#define BP_ENET_RCR_NLC      (30)      //!< Bit position for ENET_RCR_NLC.
#define BM_ENET_RCR_NLC      (0x40000000)  //!< Bit mask for ENET_RCR_NLC.

//! @brief Get value of ENET_RCR_NLC from a register value.
#define BG_ENET_RCR_NLC(r)   (((r) & BM_ENET_RCR_NLC) >> BP_ENET_RCR_NLC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RCR_NLC.
#define BF_ENET_RCR_NLC(v)   ((((reg32_t) v) << BP_ENET_RCR_NLC) & BM_ENET_RCR_NLC)
#else
//! @brief Format value for bitfield ENET_RCR_NLC.
#define BF_ENET_RCR_NLC(v)   (((v) << BP_ENET_RCR_NLC) & BM_ENET_RCR_NLC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the NLC field to a new value.
#define BW_ENET_RCR_NLC(v)   (HW_ENET_RCR_WR((HW_ENET_RCR_RD() & ~BM_ENET_RCR_NLC) | BF_ENET_RCR_NLC(v)))
#endif


/* --- Register HW_ENET_RCR, field GRS[31] (RO)
 *
 * Read-only status indicating that the MAC receive datapath is stopped.
 */

#define BP_ENET_RCR_GRS      (31)      //!< Bit position for ENET_RCR_GRS.
#define BM_ENET_RCR_GRS      (0x80000000)  //!< Bit mask for ENET_RCR_GRS.

//! @brief Get value of ENET_RCR_GRS from a register value.
#define BG_ENET_RCR_GRS(r)   (((r) & BM_ENET_RCR_GRS) >> BP_ENET_RCR_GRS)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TCR - Transmit Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * TCR is read/write and configures the transmit block. This register is cleared at system reset.
 * FDEN can only be modified when ECR[ETHER_EN] is cleared.
 */
typedef union _hw_enet_tcr
{
    reg32_t U;
    struct _hw_enet_tcr_bitfields
    {
        unsigned GTS : 1; //!< [0] When this field is set, MAC stops transmission after any frame currently transmitted is complete and EIR[GRA] is set. If frame transmission is not currently underway, the GRA interrupt is asserted immediately. After transmission finishes, clear GTS to restart. The next frame in the transmit FIFO is then transmitted. If an early collision occurs during transmission when GTS is set, transmission stops after the collision. The frame is transmitted again after GTS is cleared. There may be old frames in the transmit FIFO that transmit when GTS is reasserted. To avoid this, clear ECR[ETHER_EN] following the GRA interrupt.
        unsigned RESERVED0 : 1; //!< [1] 
        unsigned FDEN : 1; //!< [2] If this field is set, frames transmit independent of carrier sense and collision inputs. Only modify this bit when ECR[ETHER_EN] is cleared.
        unsigned TFC_PAUSE : 1; //!< [3] Pauses frame transmission. When this field is set, EIR[GRA] is set. With transmission of data frames stopped, the MAC transmits a MAC control PAUSE frame. Next, the MAC clears TFC_PAUSE and resumes transmitting data frames. If the transmitter pauses due to user assertion of GTS or reception of a PAUSE frame, the MAC may continue transmitting a MAC control PAUSE frame.
        unsigned RFC_PAUSE : 1; //!< [4] This status field is set when a full-duplex flow control pause frame is received and the transmitter pauses for the duration defined in this pause frame. This field automatically clears when the pause duration is complete.
        unsigned ADDSEL : 3; //!< [7:5] If ADDINS is set, indicates the MAC address that overwrites the source MAC address. If any other value than those listed below is used, supplemental MAC address 3 (SMACx3) is used.
        unsigned ADDINS : 1; //!< [8] 
        unsigned CRCFWD : 1; //!< [9] 
        unsigned RESERVED1 : 22; //!< [31:10] 
    } B;
} hw_enet_tcr_t;
#endif

/*
 * constants & macros for entire ENET_TCR register
 */
#define HW_ENET_TCR_ADDR      (REGS_ENET_BASE + 0xc4)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TCR           (*(volatile hw_enet_tcr_t *) HW_ENET_TCR_ADDR)
#define HW_ENET_TCR_RD()      (HW_ENET_TCR.U)
#define HW_ENET_TCR_WR(v)     (HW_ENET_TCR.U = (v))
#define HW_ENET_TCR_SET(v)    (HW_ENET_TCR_WR(HW_ENET_TCR_RD() |  (v)))
#define HW_ENET_TCR_CLR(v)    (HW_ENET_TCR_WR(HW_ENET_TCR_RD() & ~(v)))
#define HW_ENET_TCR_TOG(v)    (HW_ENET_TCR_WR(HW_ENET_TCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TCR bitfields
 */

/* --- Register HW_ENET_TCR, field GTS[0] (RW)
 *
 * When this field is set, MAC stops transmission after any frame currently transmitted is complete
 * and EIR[GRA] is set. If frame transmission is not currently underway, the GRA interrupt is
 * asserted immediately. After transmission finishes, clear GTS to restart. The next frame in the
 * transmit FIFO is then transmitted. If an early collision occurs during transmission when GTS is
 * set, transmission stops after the collision. The frame is transmitted again after GTS is cleared.
 * There may be old frames in the transmit FIFO that transmit when GTS is reasserted. To avoid this,
 * clear ECR[ETHER_EN] following the GRA interrupt.
 */

#define BP_ENET_TCR_GTS      (0)      //!< Bit position for ENET_TCR_GTS.
#define BM_ENET_TCR_GTS      (0x00000001)  //!< Bit mask for ENET_TCR_GTS.

//! @brief Get value of ENET_TCR_GTS from a register value.
#define BG_ENET_TCR_GTS(r)   (((r) & BM_ENET_TCR_GTS) >> BP_ENET_TCR_GTS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TCR_GTS.
#define BF_ENET_TCR_GTS(v)   ((((reg32_t) v) << BP_ENET_TCR_GTS) & BM_ENET_TCR_GTS)
#else
//! @brief Format value for bitfield ENET_TCR_GTS.
#define BF_ENET_TCR_GTS(v)   (((v) << BP_ENET_TCR_GTS) & BM_ENET_TCR_GTS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GTS field to a new value.
#define BW_ENET_TCR_GTS(v)   (HW_ENET_TCR_WR((HW_ENET_TCR_RD() & ~BM_ENET_TCR_GTS) | BF_ENET_TCR_GTS(v)))
#endif

/* --- Register HW_ENET_TCR, field FDEN[2] (RW)
 *
 * If this field is set, frames transmit independent of carrier sense and collision inputs. Only
 * modify this bit when ECR[ETHER_EN] is cleared.
 */

#define BP_ENET_TCR_FDEN      (2)      //!< Bit position for ENET_TCR_FDEN.
#define BM_ENET_TCR_FDEN      (0x00000004)  //!< Bit mask for ENET_TCR_FDEN.

//! @brief Get value of ENET_TCR_FDEN from a register value.
#define BG_ENET_TCR_FDEN(r)   (((r) & BM_ENET_TCR_FDEN) >> BP_ENET_TCR_FDEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TCR_FDEN.
#define BF_ENET_TCR_FDEN(v)   ((((reg32_t) v) << BP_ENET_TCR_FDEN) & BM_ENET_TCR_FDEN)
#else
//! @brief Format value for bitfield ENET_TCR_FDEN.
#define BF_ENET_TCR_FDEN(v)   (((v) << BP_ENET_TCR_FDEN) & BM_ENET_TCR_FDEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the FDEN field to a new value.
#define BW_ENET_TCR_FDEN(v)   (HW_ENET_TCR_WR((HW_ENET_TCR_RD() & ~BM_ENET_TCR_FDEN) | BF_ENET_TCR_FDEN(v)))
#endif

/* --- Register HW_ENET_TCR, field TFC_PAUSE[3] (RW)
 *
 * Pauses frame transmission. When this field is set, EIR[GRA] is set. With transmission of data
 * frames stopped, the MAC transmits a MAC control PAUSE frame. Next, the MAC clears TFC_PAUSE and
 * resumes transmitting data frames. If the transmitter pauses due to user assertion of GTS or
 * reception of a PAUSE frame, the MAC may continue transmitting a MAC control PAUSE frame.
 *
 * Values:
 * 0 - No PAUSE frame transmitted.
 * 1 - The MAC stops transmission of data frames after the current transmission is complete.
 */

#define BP_ENET_TCR_TFC_PAUSE      (3)      //!< Bit position for ENET_TCR_TFC_PAUSE.
#define BM_ENET_TCR_TFC_PAUSE      (0x00000008)  //!< Bit mask for ENET_TCR_TFC_PAUSE.

//! @brief Get value of ENET_TCR_TFC_PAUSE from a register value.
#define BG_ENET_TCR_TFC_PAUSE(r)   (((r) & BM_ENET_TCR_TFC_PAUSE) >> BP_ENET_TCR_TFC_PAUSE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TCR_TFC_PAUSE.
#define BF_ENET_TCR_TFC_PAUSE(v)   ((((reg32_t) v) << BP_ENET_TCR_TFC_PAUSE) & BM_ENET_TCR_TFC_PAUSE)
#else
//! @brief Format value for bitfield ENET_TCR_TFC_PAUSE.
#define BF_ENET_TCR_TFC_PAUSE(v)   (((v) << BP_ENET_TCR_TFC_PAUSE) & BM_ENET_TCR_TFC_PAUSE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFC_PAUSE field to a new value.
#define BW_ENET_TCR_TFC_PAUSE(v)   (HW_ENET_TCR_WR((HW_ENET_TCR_RD() & ~BM_ENET_TCR_TFC_PAUSE) | BF_ENET_TCR_TFC_PAUSE(v)))
#endif


/* --- Register HW_ENET_TCR, field RFC_PAUSE[4] (RO)
 *
 * This status field is set when a full-duplex flow control pause frame is received and the
 * transmitter pauses for the duration defined in this pause frame. This field automatically clears
 * when the pause duration is complete.
 */

#define BP_ENET_TCR_RFC_PAUSE      (4)      //!< Bit position for ENET_TCR_RFC_PAUSE.
#define BM_ENET_TCR_RFC_PAUSE      (0x00000010)  //!< Bit mask for ENET_TCR_RFC_PAUSE.

//! @brief Get value of ENET_TCR_RFC_PAUSE from a register value.
#define BG_ENET_TCR_RFC_PAUSE(r)   (((r) & BM_ENET_TCR_RFC_PAUSE) >> BP_ENET_TCR_RFC_PAUSE)

/* --- Register HW_ENET_TCR, field ADDSEL[7:5] (RW)
 *
 * If ADDINS is set, indicates the MAC address that overwrites the source MAC address. If any other
 * value than those listed below is used, supplemental MAC address 3 (SMACx3) is used.
 *
 * Values:
 * 000 - Node MAC address programmed on PADDR1/2 registers.
 * 100 -  Reserved.  Supplemental MAC address 0 (SMACx0).
 * 101 -  Reserved.  Supplemental MAC address 1 (SMACx1).
 * 110 -  Reserved.  Supplemental MAC address 2 (SMACx2).
 */

#define BP_ENET_TCR_ADDSEL      (5)      //!< Bit position for ENET_TCR_ADDSEL.
#define BM_ENET_TCR_ADDSEL      (0x000000e0)  //!< Bit mask for ENET_TCR_ADDSEL.

//! @brief Get value of ENET_TCR_ADDSEL from a register value.
#define BG_ENET_TCR_ADDSEL(r)   (((r) & BM_ENET_TCR_ADDSEL) >> BP_ENET_TCR_ADDSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TCR_ADDSEL.
#define BF_ENET_TCR_ADDSEL(v)   ((((reg32_t) v) << BP_ENET_TCR_ADDSEL) & BM_ENET_TCR_ADDSEL)
#else
//! @brief Format value for bitfield ENET_TCR_ADDSEL.
#define BF_ENET_TCR_ADDSEL(v)   (((v) << BP_ENET_TCR_ADDSEL) & BM_ENET_TCR_ADDSEL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDSEL field to a new value.
#define BW_ENET_TCR_ADDSEL(v)   (HW_ENET_TCR_WR((HW_ENET_TCR_RD() & ~BM_ENET_TCR_ADDSEL) | BF_ENET_TCR_ADDSEL(v)))
#endif


/* --- Register HW_ENET_TCR, field ADDINS[8] (RW)
 *

 *
 * Values:
 * 0 - The source MAC address is not modified by the MAC.
 * 1 - The MAC overwrites the source MAC address with the programmed MAC address according to ADDSEL.
 */

#define BP_ENET_TCR_ADDINS      (8)      //!< Bit position for ENET_TCR_ADDINS.
#define BM_ENET_TCR_ADDINS      (0x00000100)  //!< Bit mask for ENET_TCR_ADDINS.

//! @brief Get value of ENET_TCR_ADDINS from a register value.
#define BG_ENET_TCR_ADDINS(r)   (((r) & BM_ENET_TCR_ADDINS) >> BP_ENET_TCR_ADDINS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TCR_ADDINS.
#define BF_ENET_TCR_ADDINS(v)   ((((reg32_t) v) << BP_ENET_TCR_ADDINS) & BM_ENET_TCR_ADDINS)
#else
//! @brief Format value for bitfield ENET_TCR_ADDINS.
#define BF_ENET_TCR_ADDINS(v)   (((v) << BP_ENET_TCR_ADDINS) & BM_ENET_TCR_ADDINS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ADDINS field to a new value.
#define BW_ENET_TCR_ADDINS(v)   (HW_ENET_TCR_WR((HW_ENET_TCR_RD() & ~BM_ENET_TCR_ADDINS) | BF_ENET_TCR_ADDINS(v)))
#endif


/* --- Register HW_ENET_TCR, field CRCFWD[9] (RW)
 *

 *
 * Values:
 * 0 - TxBD[TC] ff_tx_crc_fwd controls whether the frame has a CRC from the application.
 * 1 - The transmitter does not append any CRC to transmitted frames, as it is expecting a frame with CRC
 *     from the application.
 */

#define BP_ENET_TCR_CRCFWD      (9)      //!< Bit position for ENET_TCR_CRCFWD.
#define BM_ENET_TCR_CRCFWD      (0x00000200)  //!< Bit mask for ENET_TCR_CRCFWD.

//! @brief Get value of ENET_TCR_CRCFWD from a register value.
#define BG_ENET_TCR_CRCFWD(r)   (((r) & BM_ENET_TCR_CRCFWD) >> BP_ENET_TCR_CRCFWD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TCR_CRCFWD.
#define BF_ENET_TCR_CRCFWD(v)   ((((reg32_t) v) << BP_ENET_TCR_CRCFWD) & BM_ENET_TCR_CRCFWD)
#else
//! @brief Format value for bitfield ENET_TCR_CRCFWD.
#define BF_ENET_TCR_CRCFWD(v)   (((v) << BP_ENET_TCR_CRCFWD) & BM_ENET_TCR_CRCFWD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CRCFWD field to a new value.
#define BW_ENET_TCR_CRCFWD(v)   (HW_ENET_TCR_WR((HW_ENET_TCR_RD() & ~BM_ENET_TCR_CRCFWD) | BF_ENET_TCR_CRCFWD(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_PALR - Physical Address Lower Register (RW)
 *
 * Reset value: 0x00000000
 *
 * PALR contains the lower 32 bits (bytes 0, 1, 2, 3) of the 48-bit address used in the address
 * recognition process to compare with the destination address (DA) field of receive frames with an
 * individual DA. In addition, this register is used in bytes 0 through 3 of the six-byte source
 * address field when transmitting PAUSE frames. This register is not reset and you must initialize
 * it.
 */
typedef union _hw_enet_palr
{
    reg32_t U;
    struct _hw_enet_palr_bitfields
    {
        unsigned PADDR1 : 32; //!< [31:0] Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8), and 3 (bits 7:0) of the 6-byte individual address are used for exact match and the source address field in PAUSE frames.
    } B;
} hw_enet_palr_t;
#endif

/*
 * constants & macros for entire ENET_PALR register
 */
#define HW_ENET_PALR_ADDR      (REGS_ENET_BASE + 0xe4)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_PALR           (*(volatile hw_enet_palr_t *) HW_ENET_PALR_ADDR)
#define HW_ENET_PALR_RD()      (HW_ENET_PALR.U)
#define HW_ENET_PALR_WR(v)     (HW_ENET_PALR.U = (v))
#define HW_ENET_PALR_SET(v)    (HW_ENET_PALR_WR(HW_ENET_PALR_RD() |  (v)))
#define HW_ENET_PALR_CLR(v)    (HW_ENET_PALR_WR(HW_ENET_PALR_RD() & ~(v)))
#define HW_ENET_PALR_TOG(v)    (HW_ENET_PALR_WR(HW_ENET_PALR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_PALR bitfields
 */

/* --- Register HW_ENET_PALR, field PADDR1[31:0] (RW)
 *
 * Bytes 0 (bits 31:24), 1 (bits 23:16), 2 (bits 15:8), and 3 (bits 7:0) of the 6-byte individual
 * address are used for exact match and the source address field in PAUSE frames.
 */

#define BP_ENET_PALR_PADDR1      (0)      //!< Bit position for ENET_PALR_PADDR1.
#define BM_ENET_PALR_PADDR1      (0xffffffff)  //!< Bit mask for ENET_PALR_PADDR1.

//! @brief Get value of ENET_PALR_PADDR1 from a register value.
#define BG_ENET_PALR_PADDR1(r)   (((r) & BM_ENET_PALR_PADDR1) >> BP_ENET_PALR_PADDR1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_PALR_PADDR1.
#define BF_ENET_PALR_PADDR1(v)   ((((reg32_t) v) << BP_ENET_PALR_PADDR1) & BM_ENET_PALR_PADDR1)
#else
//! @brief Format value for bitfield ENET_PALR_PADDR1.
#define BF_ENET_PALR_PADDR1(v)   (((v) << BP_ENET_PALR_PADDR1) & BM_ENET_PALR_PADDR1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PADDR1 field to a new value.
#define BW_ENET_PALR_PADDR1(v)   (HW_ENET_PALR_WR((HW_ENET_PALR_RD() & ~BM_ENET_PALR_PADDR1) | BF_ENET_PALR_PADDR1(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_PAUR - Physical Address Upper Register (RW)
 *
 * Reset value: 0x00008808
 *
 * PAUR contains the upper 16 bits (bytes 4 and 5) of the 48-bit address used in the address
 * recognition process to compare with the destination address (DA) field of receive frames with an
 * individual DA. In addition, this register is used in bytes 4 and 5 of the six-byte source address
 * field when transmitting PAUSE frames. Bits 15:0 of PAUR contain a constant type field (0x8808)
 * for transmission of PAUSE frames. The upper 16 bits of this register are not reset and you must
 * initialize it.
 */
typedef union _hw_enet_paur
{
    reg32_t U;
    struct _hw_enet_paur_bitfields
    {
        unsigned TYPE : 16; //!< [15:0] These fields have a constant value of 0x8808.
        unsigned PADDR2 : 16; //!< [31:16] Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address used for exact match, and the source address field in PAUSE frames.
    } B;
} hw_enet_paur_t;
#endif

/*
 * constants & macros for entire ENET_PAUR register
 */
#define HW_ENET_PAUR_ADDR      (REGS_ENET_BASE + 0xe8)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_PAUR           (*(volatile hw_enet_paur_t *) HW_ENET_PAUR_ADDR)
#define HW_ENET_PAUR_RD()      (HW_ENET_PAUR.U)
#define HW_ENET_PAUR_WR(v)     (HW_ENET_PAUR.U = (v))
#define HW_ENET_PAUR_SET(v)    (HW_ENET_PAUR_WR(HW_ENET_PAUR_RD() |  (v)))
#define HW_ENET_PAUR_CLR(v)    (HW_ENET_PAUR_WR(HW_ENET_PAUR_RD() & ~(v)))
#define HW_ENET_PAUR_TOG(v)    (HW_ENET_PAUR_WR(HW_ENET_PAUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_PAUR bitfields
 */

/* --- Register HW_ENET_PAUR, field TYPE[15:0] (RO)
 *
 * These fields have a constant value of 0x8808.
 */

#define BP_ENET_PAUR_TYPE      (0)      //!< Bit position for ENET_PAUR_TYPE.
#define BM_ENET_PAUR_TYPE      (0x0000ffff)  //!< Bit mask for ENET_PAUR_TYPE.

//! @brief Get value of ENET_PAUR_TYPE from a register value.
#define BG_ENET_PAUR_TYPE(r)   (((r) & BM_ENET_PAUR_TYPE) >> BP_ENET_PAUR_TYPE)

/* --- Register HW_ENET_PAUR, field PADDR2[31:16] (RW)
 *
 * Bytes 4 (bits 31:24) and 5 (bits 23:16) of the 6-byte individual address used for exact match,
 * and the source address field in PAUSE frames.
 */

#define BP_ENET_PAUR_PADDR2      (16)      //!< Bit position for ENET_PAUR_PADDR2.
#define BM_ENET_PAUR_PADDR2      (0xffff0000)  //!< Bit mask for ENET_PAUR_PADDR2.

//! @brief Get value of ENET_PAUR_PADDR2 from a register value.
#define BG_ENET_PAUR_PADDR2(r)   (((r) & BM_ENET_PAUR_PADDR2) >> BP_ENET_PAUR_PADDR2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_PAUR_PADDR2.
#define BF_ENET_PAUR_PADDR2(v)   ((((reg32_t) v) << BP_ENET_PAUR_PADDR2) & BM_ENET_PAUR_PADDR2)
#else
//! @brief Format value for bitfield ENET_PAUR_PADDR2.
#define BF_ENET_PAUR_PADDR2(v)   (((v) << BP_ENET_PAUR_PADDR2) & BM_ENET_PAUR_PADDR2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PADDR2 field to a new value.
#define BW_ENET_PAUR_PADDR2(v)   (HW_ENET_PAUR_WR((HW_ENET_PAUR_RD() & ~BM_ENET_PAUR_PADDR2) | BF_ENET_PAUR_PADDR2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_OPD - Opcode/Pause Duration Register (RW)
 *
 * Reset value: 0x00010000
 *
 * OPD is read/write accessible. This register contains the 16-bit opcode and 16-bit pause duration
 * fields used in transmission of a PAUSE frame. The opcode field is a constant value, 0x0001. When
 * another node detects a PAUSE frame, that node pauses transmission for the duration specified in
 * the pause duration field. The lower 16 bits of this register are not reset and you must
 * initialize it.
 */
typedef union _hw_enet_opd
{
    reg32_t U;
    struct _hw_enet_opd_bitfields
    {
        unsigned PAUSE_DUR : 16; //!< [15:0] Pause duration field used in PAUSE frames.
        unsigned OPCODE : 16; //!< [31:16] These fields have a constant value of 0x0001.
    } B;
} hw_enet_opd_t;
#endif

/*
 * constants & macros for entire ENET_OPD register
 */
#define HW_ENET_OPD_ADDR      (REGS_ENET_BASE + 0xec)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_OPD           (*(volatile hw_enet_opd_t *) HW_ENET_OPD_ADDR)
#define HW_ENET_OPD_RD()      (HW_ENET_OPD.U)
#define HW_ENET_OPD_WR(v)     (HW_ENET_OPD.U = (v))
#define HW_ENET_OPD_SET(v)    (HW_ENET_OPD_WR(HW_ENET_OPD_RD() |  (v)))
#define HW_ENET_OPD_CLR(v)    (HW_ENET_OPD_WR(HW_ENET_OPD_RD() & ~(v)))
#define HW_ENET_OPD_TOG(v)    (HW_ENET_OPD_WR(HW_ENET_OPD_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_OPD bitfields
 */

/* --- Register HW_ENET_OPD, field PAUSE_DUR[15:0] (RW)
 *
 * Pause duration field used in PAUSE frames.
 */

#define BP_ENET_OPD_PAUSE_DUR      (0)      //!< Bit position for ENET_OPD_PAUSE_DUR.
#define BM_ENET_OPD_PAUSE_DUR      (0x0000ffff)  //!< Bit mask for ENET_OPD_PAUSE_DUR.

//! @brief Get value of ENET_OPD_PAUSE_DUR from a register value.
#define BG_ENET_OPD_PAUSE_DUR(r)   (((r) & BM_ENET_OPD_PAUSE_DUR) >> BP_ENET_OPD_PAUSE_DUR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_OPD_PAUSE_DUR.
#define BF_ENET_OPD_PAUSE_DUR(v)   ((((reg32_t) v) << BP_ENET_OPD_PAUSE_DUR) & BM_ENET_OPD_PAUSE_DUR)
#else
//! @brief Format value for bitfield ENET_OPD_PAUSE_DUR.
#define BF_ENET_OPD_PAUSE_DUR(v)   (((v) << BP_ENET_OPD_PAUSE_DUR) & BM_ENET_OPD_PAUSE_DUR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PAUSE_DUR field to a new value.
#define BW_ENET_OPD_PAUSE_DUR(v)   (HW_ENET_OPD_WR((HW_ENET_OPD_RD() & ~BM_ENET_OPD_PAUSE_DUR) | BF_ENET_OPD_PAUSE_DUR(v)))
#endif

/* --- Register HW_ENET_OPD, field OPCODE[31:16] (RO)
 *
 * These fields have a constant value of 0x0001.
 */

#define BP_ENET_OPD_OPCODE      (16)      //!< Bit position for ENET_OPD_OPCODE.
#define BM_ENET_OPD_OPCODE      (0xffff0000)  //!< Bit mask for ENET_OPD_OPCODE.

//! @brief Get value of ENET_OPD_OPCODE from a register value.
#define BG_ENET_OPD_OPCODE(r)   (((r) & BM_ENET_OPD_OPCODE) >> BP_ENET_OPD_OPCODE)

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_IAUR - Descriptor Individual Upper Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * IAUR contains the upper 32 bits of the 64-bit individual address hash table. The address
 * recognition process uses this table to check for a possible match with the destination address
 * (DA) field of receive frames with an individual DA. This register is not reset and you must
 * initialize it.
 */
typedef union _hw_enet_iaur
{
    reg32_t U;
    struct _hw_enet_iaur_bitfields
    {
        unsigned IADDR1 : 32; //!< [31:0] Contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of IADDR1 contains hash index bit 32.
    } B;
} hw_enet_iaur_t;
#endif

/*
 * constants & macros for entire ENET_IAUR register
 */
#define HW_ENET_IAUR_ADDR      (REGS_ENET_BASE + 0x118)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_IAUR           (*(volatile hw_enet_iaur_t *) HW_ENET_IAUR_ADDR)
#define HW_ENET_IAUR_RD()      (HW_ENET_IAUR.U)
#define HW_ENET_IAUR_WR(v)     (HW_ENET_IAUR.U = (v))
#define HW_ENET_IAUR_SET(v)    (HW_ENET_IAUR_WR(HW_ENET_IAUR_RD() |  (v)))
#define HW_ENET_IAUR_CLR(v)    (HW_ENET_IAUR_WR(HW_ENET_IAUR_RD() & ~(v)))
#define HW_ENET_IAUR_TOG(v)    (HW_ENET_IAUR_WR(HW_ENET_IAUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_IAUR bitfields
 */

/* --- Register HW_ENET_IAUR, field IADDR1[31:0] (RW)
 *
 * Contains the upper 32 bits of the 64-bit hash table used in the address recognition process for
 * receive frames with a unicast address. Bit 31 of IADDR1 contains hash index bit 63. Bit 0 of
 * IADDR1 contains hash index bit 32.
 */

#define BP_ENET_IAUR_IADDR1      (0)      //!< Bit position for ENET_IAUR_IADDR1.
#define BM_ENET_IAUR_IADDR1      (0xffffffff)  //!< Bit mask for ENET_IAUR_IADDR1.

//! @brief Get value of ENET_IAUR_IADDR1 from a register value.
#define BG_ENET_IAUR_IADDR1(r)   (((r) & BM_ENET_IAUR_IADDR1) >> BP_ENET_IAUR_IADDR1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_IAUR_IADDR1.
#define BF_ENET_IAUR_IADDR1(v)   ((((reg32_t) v) << BP_ENET_IAUR_IADDR1) & BM_ENET_IAUR_IADDR1)
#else
//! @brief Format value for bitfield ENET_IAUR_IADDR1.
#define BF_ENET_IAUR_IADDR1(v)   (((v) << BP_ENET_IAUR_IADDR1) & BM_ENET_IAUR_IADDR1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IADDR1 field to a new value.
#define BW_ENET_IAUR_IADDR1(v)   (HW_ENET_IAUR_WR((HW_ENET_IAUR_RD() & ~BM_ENET_IAUR_IADDR1) | BF_ENET_IAUR_IADDR1(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_IALR - Descriptor Individual Lower Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * IALR contains the lower 32 bits of the 64-bit individual address hash table. The address
 * recognition process uses this table to check for a possible match with the DA field of receive
 * frames with an individual DA. This register is not reset and you must initialize it.
 */
typedef union _hw_enet_ialr
{
    reg32_t U;
    struct _hw_enet_ialr_bitfields
    {
        unsigned IADDR2 : 32; //!< [31:0] Contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of IADDR2 contains hash index bit 0.
    } B;
} hw_enet_ialr_t;
#endif

/*
 * constants & macros for entire ENET_IALR register
 */
#define HW_ENET_IALR_ADDR      (REGS_ENET_BASE + 0x11c)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_IALR           (*(volatile hw_enet_ialr_t *) HW_ENET_IALR_ADDR)
#define HW_ENET_IALR_RD()      (HW_ENET_IALR.U)
#define HW_ENET_IALR_WR(v)     (HW_ENET_IALR.U = (v))
#define HW_ENET_IALR_SET(v)    (HW_ENET_IALR_WR(HW_ENET_IALR_RD() |  (v)))
#define HW_ENET_IALR_CLR(v)    (HW_ENET_IALR_WR(HW_ENET_IALR_RD() & ~(v)))
#define HW_ENET_IALR_TOG(v)    (HW_ENET_IALR_WR(HW_ENET_IALR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_IALR bitfields
 */

/* --- Register HW_ENET_IALR, field IADDR2[31:0] (RW)
 *
 * Contains the lower 32 bits of the 64-bit hash table used in the address recognition process for
 * receive frames with a unicast address. Bit 31 of IADDR2 contains hash index bit 31. Bit 0 of
 * IADDR2 contains hash index bit 0.
 */

#define BP_ENET_IALR_IADDR2      (0)      //!< Bit position for ENET_IALR_IADDR2.
#define BM_ENET_IALR_IADDR2      (0xffffffff)  //!< Bit mask for ENET_IALR_IADDR2.

//! @brief Get value of ENET_IALR_IADDR2 from a register value.
#define BG_ENET_IALR_IADDR2(r)   (((r) & BM_ENET_IALR_IADDR2) >> BP_ENET_IALR_IADDR2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_IALR_IADDR2.
#define BF_ENET_IALR_IADDR2(v)   ((((reg32_t) v) << BP_ENET_IALR_IADDR2) & BM_ENET_IALR_IADDR2)
#else
//! @brief Format value for bitfield ENET_IALR_IADDR2.
#define BF_ENET_IALR_IADDR2(v)   (((v) << BP_ENET_IALR_IADDR2) & BM_ENET_IALR_IADDR2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IADDR2 field to a new value.
#define BW_ENET_IALR_IADDR2(v)   (HW_ENET_IALR_WR((HW_ENET_IALR_RD() & ~BM_ENET_IALR_IADDR2) | BF_ENET_IALR_IADDR2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_GAUR - Descriptor Group Upper Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * GAUR contains the upper 32 bits of the 64-bit hash table used in the address recognition process
 * for receive frames with a multicast address. You must initialize this register.
 */
typedef union _hw_enet_gaur
{
    reg32_t U;
    struct _hw_enet_gaur_bitfields
    {
        unsigned GADDR1 : 32; //!< [31:0] Contains the upper 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of GADDR1 contains hash index bit 32.
    } B;
} hw_enet_gaur_t;
#endif

/*
 * constants & macros for entire ENET_GAUR register
 */
#define HW_ENET_GAUR_ADDR      (REGS_ENET_BASE + 0x120)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_GAUR           (*(volatile hw_enet_gaur_t *) HW_ENET_GAUR_ADDR)
#define HW_ENET_GAUR_RD()      (HW_ENET_GAUR.U)
#define HW_ENET_GAUR_WR(v)     (HW_ENET_GAUR.U = (v))
#define HW_ENET_GAUR_SET(v)    (HW_ENET_GAUR_WR(HW_ENET_GAUR_RD() |  (v)))
#define HW_ENET_GAUR_CLR(v)    (HW_ENET_GAUR_WR(HW_ENET_GAUR_RD() & ~(v)))
#define HW_ENET_GAUR_TOG(v)    (HW_ENET_GAUR_WR(HW_ENET_GAUR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_GAUR bitfields
 */

/* --- Register HW_ENET_GAUR, field GADDR1[31:0] (RW)
 *
 * Contains the upper 32 bits of the 64-bit hash table used in the address recognition process for
 * receive frames with a multicast address. Bit 31 of GADDR1 contains hash index bit 63. Bit 0 of
 * GADDR1 contains hash index bit 32.
 */

#define BP_ENET_GAUR_GADDR1      (0)      //!< Bit position for ENET_GAUR_GADDR1.
#define BM_ENET_GAUR_GADDR1      (0xffffffff)  //!< Bit mask for ENET_GAUR_GADDR1.

//! @brief Get value of ENET_GAUR_GADDR1 from a register value.
#define BG_ENET_GAUR_GADDR1(r)   (((r) & BM_ENET_GAUR_GADDR1) >> BP_ENET_GAUR_GADDR1)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_GAUR_GADDR1.
#define BF_ENET_GAUR_GADDR1(v)   ((((reg32_t) v) << BP_ENET_GAUR_GADDR1) & BM_ENET_GAUR_GADDR1)
#else
//! @brief Format value for bitfield ENET_GAUR_GADDR1.
#define BF_ENET_GAUR_GADDR1(v)   (((v) << BP_ENET_GAUR_GADDR1) & BM_ENET_GAUR_GADDR1)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GADDR1 field to a new value.
#define BW_ENET_GAUR_GADDR1(v)   (HW_ENET_GAUR_WR((HW_ENET_GAUR_RD() & ~BM_ENET_GAUR_GADDR1) | BF_ENET_GAUR_GADDR1(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_GALR - Descriptor Group Lower Address Register (RW)
 *
 * Reset value: 0x00000000
 *
 * GALR contains the lower 32 bits of the 64-bit hash table used in the address recognition process
 * for receive frames with a multicast address. You must initialize this register.
 */
typedef union _hw_enet_galr
{
    reg32_t U;
    struct _hw_enet_galr_bitfields
    {
        unsigned GADDR2 : 32; //!< [31:0] Contains the lower 32 bits of the 64-bit hash table used in the address recognition process for receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of GADDR2 contains hash index bit 0.
    } B;
} hw_enet_galr_t;
#endif

/*
 * constants & macros for entire ENET_GALR register
 */
#define HW_ENET_GALR_ADDR      (REGS_ENET_BASE + 0x124)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_GALR           (*(volatile hw_enet_galr_t *) HW_ENET_GALR_ADDR)
#define HW_ENET_GALR_RD()      (HW_ENET_GALR.U)
#define HW_ENET_GALR_WR(v)     (HW_ENET_GALR.U = (v))
#define HW_ENET_GALR_SET(v)    (HW_ENET_GALR_WR(HW_ENET_GALR_RD() |  (v)))
#define HW_ENET_GALR_CLR(v)    (HW_ENET_GALR_WR(HW_ENET_GALR_RD() & ~(v)))
#define HW_ENET_GALR_TOG(v)    (HW_ENET_GALR_WR(HW_ENET_GALR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_GALR bitfields
 */

/* --- Register HW_ENET_GALR, field GADDR2[31:0] (RW)
 *
 * Contains the lower 32 bits of the 64-bit hash table used in the address recognition process for
 * receive frames with a multicast address. Bit 31 of GADDR2 contains hash index bit 31. Bit 0 of
 * GADDR2 contains hash index bit 0.
 */

#define BP_ENET_GALR_GADDR2      (0)      //!< Bit position for ENET_GALR_GADDR2.
#define BM_ENET_GALR_GADDR2      (0xffffffff)  //!< Bit mask for ENET_GALR_GADDR2.

//! @brief Get value of ENET_GALR_GADDR2 from a register value.
#define BG_ENET_GALR_GADDR2(r)   (((r) & BM_ENET_GALR_GADDR2) >> BP_ENET_GALR_GADDR2)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_GALR_GADDR2.
#define BF_ENET_GALR_GADDR2(v)   ((((reg32_t) v) << BP_ENET_GALR_GADDR2) & BM_ENET_GALR_GADDR2)
#else
//! @brief Format value for bitfield ENET_GALR_GADDR2.
#define BF_ENET_GALR_GADDR2(v)   (((v) << BP_ENET_GALR_GADDR2) & BM_ENET_GALR_GADDR2)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the GADDR2 field to a new value.
#define BW_ENET_GALR_GADDR2(v)   (HW_ENET_GALR_WR((HW_ENET_GALR_RD() & ~BM_ENET_GALR_GADDR2) | BF_ENET_GALR_GADDR2(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TFWR - Transmit FIFO Watermark Register (RW)
 *
 * Reset value: 0x00000000
 *
 * If TFR[STRFWD] is cleared, TFWR[TFWR] controls the amount of data required in the transmit FIFO
 * before transmission of a frame can begin. This allows you to minimize transmit latency (TFWR = 00
 * or 01) or allow for larger bus access latency (TFWR = 11) due to contention for the system bus.
 * Setting the watermark to a high value minimizes the risk of transmit FIFO underrun due to
 * contention for the system bus. The byte counts associated with the TFWR field may need to be
 * modified to match a given system requirement. For example, worst case bus access latency by the
 * transmit data DMA channel.
 */
typedef union _hw_enet_tfwr
{
    reg32_t U;
    struct _hw_enet_tfwr_bitfields
    {
        unsigned TFWR : 6; //!< [5:0] If STRFWD is cleared, indicates the number of bytes written to the transmit FIFO before transmission of a frame begins. If a frame with less than the threshold is written,it is still sent, independently of this threshold setting. The threshold is only relevant if the frame is larger than the threshold given.
        unsigned RESERVED0 : 2; //!< [7:6] 
        unsigned STRFWD : 1; //!< [8] 
        unsigned RESERVED1 : 23; //!< [31:9] 
    } B;
} hw_enet_tfwr_t;
#endif

/*
 * constants & macros for entire ENET_TFWR register
 */
#define HW_ENET_TFWR_ADDR      (REGS_ENET_BASE + 0x144)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TFWR           (*(volatile hw_enet_tfwr_t *) HW_ENET_TFWR_ADDR)
#define HW_ENET_TFWR_RD()      (HW_ENET_TFWR.U)
#define HW_ENET_TFWR_WR(v)     (HW_ENET_TFWR.U = (v))
#define HW_ENET_TFWR_SET(v)    (HW_ENET_TFWR_WR(HW_ENET_TFWR_RD() |  (v)))
#define HW_ENET_TFWR_CLR(v)    (HW_ENET_TFWR_WR(HW_ENET_TFWR_RD() & ~(v)))
#define HW_ENET_TFWR_TOG(v)    (HW_ENET_TFWR_WR(HW_ENET_TFWR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TFWR bitfields
 */

/* --- Register HW_ENET_TFWR, field TFWR[5:0] (RW)
 *
 * If STRFWD is cleared, indicates the number of bytes written to the transmit FIFO before
 * transmission of a frame begins. If a frame with less than the threshold is written,it is still
 * sent, independently of this threshold setting. The threshold is only relevant if the frame is
 * larger than the threshold given.
 *
 * Values:
 * 000000 - 64 bytes written.
 * 000001 - 64 bytes written.
 * 000010 - 128 bytes written.
 * 000011 - 192 bytes written.
 * 111111 - 4032 bytes written.
 */

#define BP_ENET_TFWR_TFWR      (0)      //!< Bit position for ENET_TFWR_TFWR.
#define BM_ENET_TFWR_TFWR      (0x0000003f)  //!< Bit mask for ENET_TFWR_TFWR.

//! @brief Get value of ENET_TFWR_TFWR from a register value.
#define BG_ENET_TFWR_TFWR(r)   (((r) & BM_ENET_TFWR_TFWR) >> BP_ENET_TFWR_TFWR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TFWR_TFWR.
#define BF_ENET_TFWR_TFWR(v)   ((((reg32_t) v) << BP_ENET_TFWR_TFWR) & BM_ENET_TFWR_TFWR)
#else
//! @brief Format value for bitfield ENET_TFWR_TFWR.
#define BF_ENET_TFWR_TFWR(v)   (((v) << BP_ENET_TFWR_TFWR) & BM_ENET_TFWR_TFWR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TFWR field to a new value.
#define BW_ENET_TFWR_TFWR(v)   (HW_ENET_TFWR_WR((HW_ENET_TFWR_RD() & ~BM_ENET_TFWR_TFWR) | BF_ENET_TFWR_TFWR(v)))
#endif


/* --- Register HW_ENET_TFWR, field STRFWD[8] (RW)
 *

 *
 * Values:
 * 0 - Disabled, the transmission start threshold is programmed in TFWR.
 * 1 - Enabled.
 */

#define BP_ENET_TFWR_STRFWD      (8)      //!< Bit position for ENET_TFWR_STRFWD.
#define BM_ENET_TFWR_STRFWD      (0x00000100)  //!< Bit mask for ENET_TFWR_STRFWD.

//! @brief Get value of ENET_TFWR_STRFWD from a register value.
#define BG_ENET_TFWR_STRFWD(r)   (((r) & BM_ENET_TFWR_STRFWD) >> BP_ENET_TFWR_STRFWD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TFWR_STRFWD.
#define BF_ENET_TFWR_STRFWD(v)   ((((reg32_t) v) << BP_ENET_TFWR_STRFWD) & BM_ENET_TFWR_STRFWD)
#else
//! @brief Format value for bitfield ENET_TFWR_STRFWD.
#define BF_ENET_TFWR_STRFWD(v)   (((v) << BP_ENET_TFWR_STRFWD) & BM_ENET_TFWR_STRFWD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the STRFWD field to a new value.
#define BW_ENET_TFWR_STRFWD(v)   (HW_ENET_TFWR_WR((HW_ENET_TFWR_RD() & ~BM_ENET_TFWR_STRFWD) | BF_ENET_TFWR_STRFWD(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RDSR - Receive Descriptor Ring Start Register (RW)
 *
 * Reset value: 0x00000000
 *
 * RDSR points to the beginning of the circular receive buffer descriptor queue in external memory.
 * This pointer must be 64-bit aligned (bits 2–0 must be zero); however, it is recommended to be
 * 128-bit aligned, that is, evenly divisible by 16. This register is not reset and must be
 * initialized prior to operation.
 */
typedef union _hw_enet_rdsr
{
    reg32_t U;
    struct _hw_enet_rdsr_bitfields
    {
        unsigned RESERVED0 : 3; //!< [2:0] 
        unsigned R_DES_START : 29; //!< [31:3] Pointer to the beginning of the receive buffer descriptor queue. Not used internally, drives the core output signal RDSR.
    } B;
} hw_enet_rdsr_t;
#endif

/*
 * constants & macros for entire ENET_RDSR register
 */
#define HW_ENET_RDSR_ADDR      (REGS_ENET_BASE + 0x180)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RDSR           (*(volatile hw_enet_rdsr_t *) HW_ENET_RDSR_ADDR)
#define HW_ENET_RDSR_RD()      (HW_ENET_RDSR.U)
#define HW_ENET_RDSR_WR(v)     (HW_ENET_RDSR.U = (v))
#define HW_ENET_RDSR_SET(v)    (HW_ENET_RDSR_WR(HW_ENET_RDSR_RD() |  (v)))
#define HW_ENET_RDSR_CLR(v)    (HW_ENET_RDSR_WR(HW_ENET_RDSR_RD() & ~(v)))
#define HW_ENET_RDSR_TOG(v)    (HW_ENET_RDSR_WR(HW_ENET_RDSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RDSR bitfields
 */

/* --- Register HW_ENET_RDSR, field R_DES_START[31:3] (RW)
 *
 * Pointer to the beginning of the receive buffer descriptor queue. Not used internally, drives the
 * core output signal RDSR.
 */

#define BP_ENET_RDSR_R_DES_START      (3)      //!< Bit position for ENET_RDSR_R_DES_START.
#define BM_ENET_RDSR_R_DES_START      (0xfffffff8)  //!< Bit mask for ENET_RDSR_R_DES_START.

//! @brief Get value of ENET_RDSR_R_DES_START from a register value.
#define BG_ENET_RDSR_R_DES_START(r)   (((r) & BM_ENET_RDSR_R_DES_START) >> BP_ENET_RDSR_R_DES_START)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RDSR_R_DES_START.
#define BF_ENET_RDSR_R_DES_START(v)   ((((reg32_t) v) << BP_ENET_RDSR_R_DES_START) & BM_ENET_RDSR_R_DES_START)
#else
//! @brief Format value for bitfield ENET_RDSR_R_DES_START.
#define BF_ENET_RDSR_R_DES_START(v)   (((v) << BP_ENET_RDSR_R_DES_START) & BM_ENET_RDSR_R_DES_START)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the R_DES_START field to a new value.
#define BW_ENET_RDSR_R_DES_START(v)   (HW_ENET_RDSR_WR((HW_ENET_RDSR_RD() & ~BM_ENET_RDSR_R_DES_START) | BF_ENET_RDSR_R_DES_START(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TDSR - Transmit Buffer Descriptor Ring Start Register (RW)
 *
 * Reset value: 0x00000000
 *
 * TDSR provides a pointer to the beginning of the circular transmit buffer descriptor queue in
 * external memory. This pointer must be 64-bit aligned (bits 2–0 must be zero); however, it is
 * recommended to be 128-bit aligned, that is, evenly divisible by 16. This register is undefined at
 * reset and must be initialized prior to operation.
 */
typedef union _hw_enet_tdsr
{
    reg32_t U;
    struct _hw_enet_tdsr_bitfields
    {
        unsigned RESERVED0 : 3; //!< [2:0] 
        unsigned X_DES_START : 29; //!< [31:3] Pointer to the beginning of the transmit buffer descriptor queue. Not used internally, drives the core output signal TDSR.
    } B;
} hw_enet_tdsr_t;
#endif

/*
 * constants & macros for entire ENET_TDSR register
 */
#define HW_ENET_TDSR_ADDR      (REGS_ENET_BASE + 0x184)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TDSR           (*(volatile hw_enet_tdsr_t *) HW_ENET_TDSR_ADDR)
#define HW_ENET_TDSR_RD()      (HW_ENET_TDSR.U)
#define HW_ENET_TDSR_WR(v)     (HW_ENET_TDSR.U = (v))
#define HW_ENET_TDSR_SET(v)    (HW_ENET_TDSR_WR(HW_ENET_TDSR_RD() |  (v)))
#define HW_ENET_TDSR_CLR(v)    (HW_ENET_TDSR_WR(HW_ENET_TDSR_RD() & ~(v)))
#define HW_ENET_TDSR_TOG(v)    (HW_ENET_TDSR_WR(HW_ENET_TDSR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TDSR bitfields
 */

/* --- Register HW_ENET_TDSR, field X_DES_START[31:3] (RW)
 *
 * Pointer to the beginning of the transmit buffer descriptor queue. Not used internally, drives the
 * core output signal TDSR.
 */

#define BP_ENET_TDSR_X_DES_START      (3)      //!< Bit position for ENET_TDSR_X_DES_START.
#define BM_ENET_TDSR_X_DES_START      (0xfffffff8)  //!< Bit mask for ENET_TDSR_X_DES_START.

//! @brief Get value of ENET_TDSR_X_DES_START from a register value.
#define BG_ENET_TDSR_X_DES_START(r)   (((r) & BM_ENET_TDSR_X_DES_START) >> BP_ENET_TDSR_X_DES_START)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TDSR_X_DES_START.
#define BF_ENET_TDSR_X_DES_START(v)   ((((reg32_t) v) << BP_ENET_TDSR_X_DES_START) & BM_ENET_TDSR_X_DES_START)
#else
//! @brief Format value for bitfield ENET_TDSR_X_DES_START.
#define BF_ENET_TDSR_X_DES_START(v)   (((v) << BP_ENET_TDSR_X_DES_START) & BM_ENET_TDSR_X_DES_START)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the X_DES_START field to a new value.
#define BW_ENET_TDSR_X_DES_START(v)   (HW_ENET_TDSR_WR((HW_ENET_TDSR_RD() & ~BM_ENET_TDSR_X_DES_START) | BF_ENET_TDSR_X_DES_START(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_MRBR - Maximum Receive Buffer Size Register (RW)
 *
 * Reset value: 0x00000000
 *
 * The MRBR is a user-programmable register that dictates the maximum size of all receive buffers.
 * This value should take into consideration that the receive CRC is always written into the last
 * receive buffer.  To allow one maximum size frame per buffer, MRBR must be set to RCR[MAX_FL] or
 * larger.  To properly align the buffer, MRBR must be evenly divisible by 16. To ensure this, bits
 * 3–0 are forced low.  To minimize bus usage (descriptor fetches), set MRBR greater than or equal
 * to 256 bytes.  The MRBR register is undefined at reset and must be initialized by the user.
 */
typedef union _hw_enet_mrbr
{
    reg32_t U;
    struct _hw_enet_mrbr_bitfields
    {
        unsigned RESERVED0 : 4; //!< [3:0] 
        unsigned R_BUF_SIZE : 10; //!< [13:4] Receive buffer size in bytes. Not used internally, drives the Core output signal TDSR.
        unsigned RESERVED1 : 18; //!< [31:14] 
    } B;
} hw_enet_mrbr_t;
#endif

/*
 * constants & macros for entire ENET_MRBR register
 */
#define HW_ENET_MRBR_ADDR      (REGS_ENET_BASE + 0x188)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_MRBR           (*(volatile hw_enet_mrbr_t *) HW_ENET_MRBR_ADDR)
#define HW_ENET_MRBR_RD()      (HW_ENET_MRBR.U)
#define HW_ENET_MRBR_WR(v)     (HW_ENET_MRBR.U = (v))
#define HW_ENET_MRBR_SET(v)    (HW_ENET_MRBR_WR(HW_ENET_MRBR_RD() |  (v)))
#define HW_ENET_MRBR_CLR(v)    (HW_ENET_MRBR_WR(HW_ENET_MRBR_RD() & ~(v)))
#define HW_ENET_MRBR_TOG(v)    (HW_ENET_MRBR_WR(HW_ENET_MRBR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_MRBR bitfields
 */

/* --- Register HW_ENET_MRBR, field R_BUF_SIZE[13:4] (RW)
 *
 * Receive buffer size in bytes. Not used internally, drives the Core output signal TDSR.
 */

#define BP_ENET_MRBR_R_BUF_SIZE      (4)      //!< Bit position for ENET_MRBR_R_BUF_SIZE.
#define BM_ENET_MRBR_R_BUF_SIZE      (0x00003ff0)  //!< Bit mask for ENET_MRBR_R_BUF_SIZE.

//! @brief Get value of ENET_MRBR_R_BUF_SIZE from a register value.
#define BG_ENET_MRBR_R_BUF_SIZE(r)   (((r) & BM_ENET_MRBR_R_BUF_SIZE) >> BP_ENET_MRBR_R_BUF_SIZE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_MRBR_R_BUF_SIZE.
#define BF_ENET_MRBR_R_BUF_SIZE(v)   ((((reg32_t) v) << BP_ENET_MRBR_R_BUF_SIZE) & BM_ENET_MRBR_R_BUF_SIZE)
#else
//! @brief Format value for bitfield ENET_MRBR_R_BUF_SIZE.
#define BF_ENET_MRBR_R_BUF_SIZE(v)   (((v) << BP_ENET_MRBR_R_BUF_SIZE) & BM_ENET_MRBR_R_BUF_SIZE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the R_BUF_SIZE field to a new value.
#define BW_ENET_MRBR_R_BUF_SIZE(v)   (HW_ENET_MRBR_WR((HW_ENET_MRBR_RD() & ~BM_ENET_MRBR_R_BUF_SIZE) | BF_ENET_MRBR_R_BUF_SIZE(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RSFL - Receive FIFO Section Full Threshold (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_rsfl
{
    reg32_t U;
    struct _hw_enet_rsfl_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_enet_rsfl_t;
#endif

/*
 * constants & macros for entire ENET_RSFL register
 */
#define HW_ENET_RSFL_ADDR      (REGS_ENET_BASE + 0x190)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RSFL           (*(volatile hw_enet_rsfl_t *) HW_ENET_RSFL_ADDR)
#define HW_ENET_RSFL_RD()      (HW_ENET_RSFL.U)
#define HW_ENET_RSFL_WR(v)     (HW_ENET_RSFL.U = (v))
#define HW_ENET_RSFL_SET(v)    (HW_ENET_RSFL_WR(HW_ENET_RSFL_RD() |  (v)))
#define HW_ENET_RSFL_CLR(v)    (HW_ENET_RSFL_WR(HW_ENET_RSFL_RD() & ~(v)))
#define HW_ENET_RSFL_TOG(v)    (HW_ENET_RSFL_WR(HW_ENET_RSFL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RSFL bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RSEM - Receive FIFO Section Empty Threshold (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_rsem
{
    reg32_t U;
    struct _hw_enet_rsem_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_enet_rsem_t;
#endif

/*
 * constants & macros for entire ENET_RSEM register
 */
#define HW_ENET_RSEM_ADDR      (REGS_ENET_BASE + 0x194)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RSEM           (*(volatile hw_enet_rsem_t *) HW_ENET_RSEM_ADDR)
#define HW_ENET_RSEM_RD()      (HW_ENET_RSEM.U)
#define HW_ENET_RSEM_WR(v)     (HW_ENET_RSEM.U = (v))
#define HW_ENET_RSEM_SET(v)    (HW_ENET_RSEM_WR(HW_ENET_RSEM_RD() |  (v)))
#define HW_ENET_RSEM_CLR(v)    (HW_ENET_RSEM_WR(HW_ENET_RSEM_RD() & ~(v)))
#define HW_ENET_RSEM_TOG(v)    (HW_ENET_RSEM_WR(HW_ENET_RSEM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RSEM bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RAEM - Receive FIFO Almost Empty Threshold (RW)
 *
 * Reset value: 0x00000004
 *

 */
typedef union _hw_enet_raem
{
    reg32_t U;
    struct _hw_enet_raem_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_enet_raem_t;
#endif

/*
 * constants & macros for entire ENET_RAEM register
 */
#define HW_ENET_RAEM_ADDR      (REGS_ENET_BASE + 0x198)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RAEM           (*(volatile hw_enet_raem_t *) HW_ENET_RAEM_ADDR)
#define HW_ENET_RAEM_RD()      (HW_ENET_RAEM.U)
#define HW_ENET_RAEM_WR(v)     (HW_ENET_RAEM.U = (v))
#define HW_ENET_RAEM_SET(v)    (HW_ENET_RAEM_WR(HW_ENET_RAEM_RD() |  (v)))
#define HW_ENET_RAEM_CLR(v)    (HW_ENET_RAEM_WR(HW_ENET_RAEM_RD() & ~(v)))
#define HW_ENET_RAEM_TOG(v)    (HW_ENET_RAEM_WR(HW_ENET_RAEM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RAEM bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RAFL - Receive FIFO Almost Full Threshold (RW)
 *
 * Reset value: 0x00000004
 *

 */
typedef union _hw_enet_rafl
{
    reg32_t U;
    struct _hw_enet_rafl_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_enet_rafl_t;
#endif

/*
 * constants & macros for entire ENET_RAFL register
 */
#define HW_ENET_RAFL_ADDR      (REGS_ENET_BASE + 0x19c)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RAFL           (*(volatile hw_enet_rafl_t *) HW_ENET_RAFL_ADDR)
#define HW_ENET_RAFL_RD()      (HW_ENET_RAFL.U)
#define HW_ENET_RAFL_WR(v)     (HW_ENET_RAFL.U = (v))
#define HW_ENET_RAFL_SET(v)    (HW_ENET_RAFL_WR(HW_ENET_RAFL_RD() |  (v)))
#define HW_ENET_RAFL_CLR(v)    (HW_ENET_RAFL_WR(HW_ENET_RAFL_RD() & ~(v)))
#define HW_ENET_RAFL_TOG(v)    (HW_ENET_RAFL_WR(HW_ENET_RAFL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RAFL bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TSEM - Transmit FIFO Section Empty Threshold (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_tsem
{
    reg32_t U;
    struct _hw_enet_tsem_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_enet_tsem_t;
#endif

/*
 * constants & macros for entire ENET_TSEM register
 */
#define HW_ENET_TSEM_ADDR      (REGS_ENET_BASE + 0x1a0)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TSEM           (*(volatile hw_enet_tsem_t *) HW_ENET_TSEM_ADDR)
#define HW_ENET_TSEM_RD()      (HW_ENET_TSEM.U)
#define HW_ENET_TSEM_WR(v)     (HW_ENET_TSEM.U = (v))
#define HW_ENET_TSEM_SET(v)    (HW_ENET_TSEM_WR(HW_ENET_TSEM_RD() |  (v)))
#define HW_ENET_TSEM_CLR(v)    (HW_ENET_TSEM_WR(HW_ENET_TSEM_RD() & ~(v)))
#define HW_ENET_TSEM_TOG(v)    (HW_ENET_TSEM_WR(HW_ENET_TSEM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TSEM bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TAEM - Transmit FIFO Almost Empty Threshold (RW)
 *
 * Reset value: 0x00000004
 *

 */
typedef union _hw_enet_taem
{
    reg32_t U;
    struct _hw_enet_taem_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_enet_taem_t;
#endif

/*
 * constants & macros for entire ENET_TAEM register
 */
#define HW_ENET_TAEM_ADDR      (REGS_ENET_BASE + 0x1a4)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TAEM           (*(volatile hw_enet_taem_t *) HW_ENET_TAEM_ADDR)
#define HW_ENET_TAEM_RD()      (HW_ENET_TAEM.U)
#define HW_ENET_TAEM_WR(v)     (HW_ENET_TAEM.U = (v))
#define HW_ENET_TAEM_SET(v)    (HW_ENET_TAEM_WR(HW_ENET_TAEM_RD() |  (v)))
#define HW_ENET_TAEM_CLR(v)    (HW_ENET_TAEM_WR(HW_ENET_TAEM_RD() & ~(v)))
#define HW_ENET_TAEM_TOG(v)    (HW_ENET_TAEM_WR(HW_ENET_TAEM_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TAEM bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TAFL - Transmit FIFO Almost Full Threshold (RW)
 *
 * Reset value: 0x00000008
 *

 */
typedef union _hw_enet_tafl
{
    reg32_t U;
    struct _hw_enet_tafl_bitfields
    {
        unsigned RESERVED0 : 32; //!< [31:0] Reserved.
    } B;
} hw_enet_tafl_t;
#endif

/*
 * constants & macros for entire ENET_TAFL register
 */
#define HW_ENET_TAFL_ADDR      (REGS_ENET_BASE + 0x1a8)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TAFL           (*(volatile hw_enet_tafl_t *) HW_ENET_TAFL_ADDR)
#define HW_ENET_TAFL_RD()      (HW_ENET_TAFL.U)
#define HW_ENET_TAFL_WR(v)     (HW_ENET_TAFL.U = (v))
#define HW_ENET_TAFL_SET(v)    (HW_ENET_TAFL_WR(HW_ENET_TAFL_RD() |  (v)))
#define HW_ENET_TAFL_CLR(v)    (HW_ENET_TAFL_WR(HW_ENET_TAFL_RD() & ~(v)))
#define HW_ENET_TAFL_TOG(v)    (HW_ENET_TAFL_WR(HW_ENET_TAFL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TAFL bitfields
 */

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TIPG - Transmit Inter-Packet Gap (RW)
 *
 * Reset value: 0x0000000c
 *

 */
typedef union _hw_enet_tipg
{
    reg32_t U;
    struct _hw_enet_tipg_bitfields
    {
        unsigned IPG : 5; //!< [4:0] Indicates the IPG, in bytes, between transmitted frames. Valid values range from 8 to 27. If value is less than 8, the IPG is 8. If value is greater than 27, the IPG is 27.
        unsigned RESERVED0 : 27; //!< [31:5] 
    } B;
} hw_enet_tipg_t;
#endif

/*
 * constants & macros for entire ENET_TIPG register
 */
#define HW_ENET_TIPG_ADDR      (REGS_ENET_BASE + 0x1ac)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TIPG           (*(volatile hw_enet_tipg_t *) HW_ENET_TIPG_ADDR)
#define HW_ENET_TIPG_RD()      (HW_ENET_TIPG.U)
#define HW_ENET_TIPG_WR(v)     (HW_ENET_TIPG.U = (v))
#define HW_ENET_TIPG_SET(v)    (HW_ENET_TIPG_WR(HW_ENET_TIPG_RD() |  (v)))
#define HW_ENET_TIPG_CLR(v)    (HW_ENET_TIPG_WR(HW_ENET_TIPG_RD() & ~(v)))
#define HW_ENET_TIPG_TOG(v)    (HW_ENET_TIPG_WR(HW_ENET_TIPG_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TIPG bitfields
 */

/* --- Register HW_ENET_TIPG, field IPG[4:0] (RW)
 *
 * Indicates the IPG, in bytes, between transmitted frames. Valid values range from 8 to 27. If
 * value is less than 8, the IPG is 8. If value is greater than 27, the IPG is 27.
 */

#define BP_ENET_TIPG_IPG      (0)      //!< Bit position for ENET_TIPG_IPG.
#define BM_ENET_TIPG_IPG      (0x0000001f)  //!< Bit mask for ENET_TIPG_IPG.

//! @brief Get value of ENET_TIPG_IPG from a register value.
#define BG_ENET_TIPG_IPG(r)   (((r) & BM_ENET_TIPG_IPG) >> BP_ENET_TIPG_IPG)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TIPG_IPG.
#define BF_ENET_TIPG_IPG(v)   ((((reg32_t) v) << BP_ENET_TIPG_IPG) & BM_ENET_TIPG_IPG)
#else
//! @brief Format value for bitfield ENET_TIPG_IPG.
#define BF_ENET_TIPG_IPG(v)   (((v) << BP_ENET_TIPG_IPG) & BM_ENET_TIPG_IPG)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPG field to a new value.
#define BW_ENET_TIPG_IPG(v)   (HW_ENET_TIPG_WR((HW_ENET_TIPG_RD() & ~BM_ENET_TIPG_IPG) | BF_ENET_TIPG_IPG(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_FTRL - Frame Truncation Length (RW)
 *
 * Reset value: 0x000007ff
 *

 */
typedef union _hw_enet_ftrl
{
    reg32_t U;
    struct _hw_enet_ftrl_bitfields
    {
        unsigned TRUNC_FL : 14; //!< [13:0] Indicates the value a receive frame is truncated, if it is greater than this value. Must be greater than or equal to RCR[MAX_FL]. Truncation happens at TRUNC_FL. However, when truncation occurs, the application (FIFO) may receive less data, guaranteeing that it never receives more than the set limit.
        unsigned RESERVED0 : 18; //!< [31:14] 
    } B;
} hw_enet_ftrl_t;
#endif

/*
 * constants & macros for entire ENET_FTRL register
 */
#define HW_ENET_FTRL_ADDR      (REGS_ENET_BASE + 0x1b0)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_FTRL           (*(volatile hw_enet_ftrl_t *) HW_ENET_FTRL_ADDR)
#define HW_ENET_FTRL_RD()      (HW_ENET_FTRL.U)
#define HW_ENET_FTRL_WR(v)     (HW_ENET_FTRL.U = (v))
#define HW_ENET_FTRL_SET(v)    (HW_ENET_FTRL_WR(HW_ENET_FTRL_RD() |  (v)))
#define HW_ENET_FTRL_CLR(v)    (HW_ENET_FTRL_WR(HW_ENET_FTRL_RD() & ~(v)))
#define HW_ENET_FTRL_TOG(v)    (HW_ENET_FTRL_WR(HW_ENET_FTRL_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_FTRL bitfields
 */

/* --- Register HW_ENET_FTRL, field TRUNC_FL[13:0] (RW)
 *
 * Indicates the value a receive frame is truncated, if it is greater than this value. Must be
 * greater than or equal to RCR[MAX_FL]. Truncation happens at TRUNC_FL. However, when truncation
 * occurs, the application (FIFO) may receive less data, guaranteeing that it never receives more
 * than the set limit.
 */

#define BP_ENET_FTRL_TRUNC_FL      (0)      //!< Bit position for ENET_FTRL_TRUNC_FL.
#define BM_ENET_FTRL_TRUNC_FL      (0x00003fff)  //!< Bit mask for ENET_FTRL_TRUNC_FL.

//! @brief Get value of ENET_FTRL_TRUNC_FL from a register value.
#define BG_ENET_FTRL_TRUNC_FL(r)   (((r) & BM_ENET_FTRL_TRUNC_FL) >> BP_ENET_FTRL_TRUNC_FL)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_FTRL_TRUNC_FL.
#define BF_ENET_FTRL_TRUNC_FL(v)   ((((reg32_t) v) << BP_ENET_FTRL_TRUNC_FL) & BM_ENET_FTRL_TRUNC_FL)
#else
//! @brief Format value for bitfield ENET_FTRL_TRUNC_FL.
#define BF_ENET_FTRL_TRUNC_FL(v)   (((v) << BP_ENET_FTRL_TRUNC_FL) & BM_ENET_FTRL_TRUNC_FL)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the TRUNC_FL field to a new value.
#define BW_ENET_FTRL_TRUNC_FL(v)   (HW_ENET_FTRL_WR((HW_ENET_FTRL_RD() & ~BM_ENET_FTRL_TRUNC_FL) | BF_ENET_FTRL_TRUNC_FL(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_TACC - Transmit Accelerator Function Configuration (RW)
 *
 * Reset value: 0x00000000
 *
 * TACC controls accelerator actions when sending frames. The register can be changed before or
 * after each frame, but it must remain unmodified during frame writes into the transmit FIFO.  The
 * TFWR[STRFWD] field must be set to use the checksum feature.
 */
typedef union _hw_enet_tacc
{
    reg32_t U;
    struct _hw_enet_tacc_bitfields
    {
        unsigned SHIFT16 : 1; //!< [0] 
        unsigned RESERVED0 : 2; //!< [2:1] 
        unsigned IPCHK : 1; //!< [3] Enables insertion of IP header checksum. The setting is OR'ed with the pin ff_tx_ipchk_ins.
        unsigned PROCHK : 1; //!< [4] Enables insertion of protocol checksum. The setting is OR'ed with the pin ff_tx_protchk_ins.
        unsigned RESERVED1 : 27; //!< [31:5] 
    } B;
} hw_enet_tacc_t;
#endif

/*
 * constants & macros for entire ENET_TACC register
 */
#define HW_ENET_TACC_ADDR      (REGS_ENET_BASE + 0x1c0)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_TACC           (*(volatile hw_enet_tacc_t *) HW_ENET_TACC_ADDR)
#define HW_ENET_TACC_RD()      (HW_ENET_TACC.U)
#define HW_ENET_TACC_WR(v)     (HW_ENET_TACC.U = (v))
#define HW_ENET_TACC_SET(v)    (HW_ENET_TACC_WR(HW_ENET_TACC_RD() |  (v)))
#define HW_ENET_TACC_CLR(v)    (HW_ENET_TACC_WR(HW_ENET_TACC_RD() & ~(v)))
#define HW_ENET_TACC_TOG(v)    (HW_ENET_TACC_WR(HW_ENET_TACC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_TACC bitfields
 */

/* --- Register HW_ENET_TACC, field SHIFT16[0] (RW)
 *

 *
 * Values:
 * 0 - Disabled.
 * 1 - Indicates to the transmit data FIFO that the written frames contain two additional octets before the
 *     frame data. This means the actual frame begins at bit 16 of the first word written into the
 *     FIFO. This function allows putting the frame payload on a 32-bit boundary in memory, as the
 *     14-byte Ethernet header is extended to a 16-byte header.
 */

#define BP_ENET_TACC_SHIFT16      (0)      //!< Bit position for ENET_TACC_SHIFT16.
#define BM_ENET_TACC_SHIFT16      (0x00000001)  //!< Bit mask for ENET_TACC_SHIFT16.

//! @brief Get value of ENET_TACC_SHIFT16 from a register value.
#define BG_ENET_TACC_SHIFT16(r)   (((r) & BM_ENET_TACC_SHIFT16) >> BP_ENET_TACC_SHIFT16)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TACC_SHIFT16.
#define BF_ENET_TACC_SHIFT16(v)   ((((reg32_t) v) << BP_ENET_TACC_SHIFT16) & BM_ENET_TACC_SHIFT16)
#else
//! @brief Format value for bitfield ENET_TACC_SHIFT16.
#define BF_ENET_TACC_SHIFT16(v)   (((v) << BP_ENET_TACC_SHIFT16) & BM_ENET_TACC_SHIFT16)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SHIFT16 field to a new value.
#define BW_ENET_TACC_SHIFT16(v)   (HW_ENET_TACC_WR((HW_ENET_TACC_RD() & ~BM_ENET_TACC_SHIFT16) | BF_ENET_TACC_SHIFT16(v)))
#endif


/* --- Register HW_ENET_TACC, field IPCHK[3] (RW)
 *
 * Enables insertion of IP header checksum. The setting is OR'ed with the pin ff_tx_ipchk_ins.
 *
 * Values:
 * 0 - Checksum is not inserted.
 * 1 - If an IP frame is transmitted, the checksum is inserted automatically. The IP header checksum field
 *     must be cleared. If a non-IP frame is transmitted the frame is not modified.
 */

#define BP_ENET_TACC_IPCHK      (3)      //!< Bit position for ENET_TACC_IPCHK.
#define BM_ENET_TACC_IPCHK      (0x00000008)  //!< Bit mask for ENET_TACC_IPCHK.

//! @brief Get value of ENET_TACC_IPCHK from a register value.
#define BG_ENET_TACC_IPCHK(r)   (((r) & BM_ENET_TACC_IPCHK) >> BP_ENET_TACC_IPCHK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TACC_IPCHK.
#define BF_ENET_TACC_IPCHK(v)   ((((reg32_t) v) << BP_ENET_TACC_IPCHK) & BM_ENET_TACC_IPCHK)
#else
//! @brief Format value for bitfield ENET_TACC_IPCHK.
#define BF_ENET_TACC_IPCHK(v)   (((v) << BP_ENET_TACC_IPCHK) & BM_ENET_TACC_IPCHK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPCHK field to a new value.
#define BW_ENET_TACC_IPCHK(v)   (HW_ENET_TACC_WR((HW_ENET_TACC_RD() & ~BM_ENET_TACC_IPCHK) | BF_ENET_TACC_IPCHK(v)))
#endif


/* --- Register HW_ENET_TACC, field PROCHK[4] (RW)
 *
 * Enables insertion of protocol checksum. The setting is OR'ed with the pin ff_tx_protchk_ins.
 *
 * Values:
 * 0 - Checksum not inserted.
 * 1 - If an IP frame with a known protocol is transmitted, the checksum is inserted automatically into the
 *     frame. The checksum field must be cleared. The other frames are not modified.
 */

#define BP_ENET_TACC_PROCHK      (4)      //!< Bit position for ENET_TACC_PROCHK.
#define BM_ENET_TACC_PROCHK      (0x00000010)  //!< Bit mask for ENET_TACC_PROCHK.

//! @brief Get value of ENET_TACC_PROCHK from a register value.
#define BG_ENET_TACC_PROCHK(r)   (((r) & BM_ENET_TACC_PROCHK) >> BP_ENET_TACC_PROCHK)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_TACC_PROCHK.
#define BF_ENET_TACC_PROCHK(v)   ((((reg32_t) v) << BP_ENET_TACC_PROCHK) & BM_ENET_TACC_PROCHK)
#else
//! @brief Format value for bitfield ENET_TACC_PROCHK.
#define BF_ENET_TACC_PROCHK(v)   (((v) << BP_ENET_TACC_PROCHK) & BM_ENET_TACC_PROCHK)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PROCHK field to a new value.
#define BW_ENET_TACC_PROCHK(v)   (HW_ENET_TACC_WR((HW_ENET_TACC_RD() & ~BM_ENET_TACC_PROCHK) | BF_ENET_TACC_PROCHK(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_RACC - Receive Accelerator Function Configuration (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_racc
{
    reg32_t U;
    struct _hw_enet_racc_bitfields
    {
        unsigned PADREM : 1; //!< [0] 
        unsigned IPDIS : 1; //!< [1] 
        unsigned PRODIS : 1; //!< [2] 
        unsigned RESERVED0 : 3; //!< [5:3] 
        unsigned LINEDIS : 1; //!< [6] 
        unsigned SHIFT16 : 1; //!< [7] When this field is set, the actual frame data starts at bit 16 of the first word read from the RX FIFO aligning the Ethernet payload on a 32-bit boundary. This function only affects the FIFO storage and has no influence on the statistics, which use the actual length of the frame received.
        unsigned RESERVED1 : 24; //!< [31:8] 
    } B;
} hw_enet_racc_t;
#endif

/*
 * constants & macros for entire ENET_RACC register
 */
#define HW_ENET_RACC_ADDR      (REGS_ENET_BASE + 0x1c4)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_RACC           (*(volatile hw_enet_racc_t *) HW_ENET_RACC_ADDR)
#define HW_ENET_RACC_RD()      (HW_ENET_RACC.U)
#define HW_ENET_RACC_WR(v)     (HW_ENET_RACC.U = (v))
#define HW_ENET_RACC_SET(v)    (HW_ENET_RACC_WR(HW_ENET_RACC_RD() |  (v)))
#define HW_ENET_RACC_CLR(v)    (HW_ENET_RACC_WR(HW_ENET_RACC_RD() & ~(v)))
#define HW_ENET_RACC_TOG(v)    (HW_ENET_RACC_WR(HW_ENET_RACC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_RACC bitfields
 */

/* --- Register HW_ENET_RACC, field PADREM[0] (RW)
 *

 *
 * Values:
 * 0 - Padding not removed.
 * 1 - Any bytes following the IP payload section of the frame are removed from the frame.
 */

#define BP_ENET_RACC_PADREM      (0)      //!< Bit position for ENET_RACC_PADREM.
#define BM_ENET_RACC_PADREM      (0x00000001)  //!< Bit mask for ENET_RACC_PADREM.

//! @brief Get value of ENET_RACC_PADREM from a register value.
#define BG_ENET_RACC_PADREM(r)   (((r) & BM_ENET_RACC_PADREM) >> BP_ENET_RACC_PADREM)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RACC_PADREM.
#define BF_ENET_RACC_PADREM(v)   ((((reg32_t) v) << BP_ENET_RACC_PADREM) & BM_ENET_RACC_PADREM)
#else
//! @brief Format value for bitfield ENET_RACC_PADREM.
#define BF_ENET_RACC_PADREM(v)   (((v) << BP_ENET_RACC_PADREM) & BM_ENET_RACC_PADREM)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PADREM field to a new value.
#define BW_ENET_RACC_PADREM(v)   (HW_ENET_RACC_WR((HW_ENET_RACC_RD() & ~BM_ENET_RACC_PADREM) | BF_ENET_RACC_PADREM(v)))
#endif


/* --- Register HW_ENET_RACC, field IPDIS[1] (RW)
 *

 *
 * Values:
 * 0 - Frames with wrong IPv4 header checksum are not discarded.
 * 1 - If an IPv4 frame is received with a mismatching header checksum, the frame is discarded. IPv6 has no
 *     header checksum and is not affected by this setting. Discarding is only available when the RX
 *     FIFO operates in store and forward mode (RSFL cleared).
 */

#define BP_ENET_RACC_IPDIS      (1)      //!< Bit position for ENET_RACC_IPDIS.
#define BM_ENET_RACC_IPDIS      (0x00000002)  //!< Bit mask for ENET_RACC_IPDIS.

//! @brief Get value of ENET_RACC_IPDIS from a register value.
#define BG_ENET_RACC_IPDIS(r)   (((r) & BM_ENET_RACC_IPDIS) >> BP_ENET_RACC_IPDIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RACC_IPDIS.
#define BF_ENET_RACC_IPDIS(v)   ((((reg32_t) v) << BP_ENET_RACC_IPDIS) & BM_ENET_RACC_IPDIS)
#else
//! @brief Format value for bitfield ENET_RACC_IPDIS.
#define BF_ENET_RACC_IPDIS(v)   (((v) << BP_ENET_RACC_IPDIS) & BM_ENET_RACC_IPDIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the IPDIS field to a new value.
#define BW_ENET_RACC_IPDIS(v)   (HW_ENET_RACC_WR((HW_ENET_RACC_RD() & ~BM_ENET_RACC_IPDIS) | BF_ENET_RACC_IPDIS(v)))
#endif


/* --- Register HW_ENET_RACC, field PRODIS[2] (RW)
 *

 *
 * Values:
 * 0 - Frames with wrong checksum are not discarded.
 * 1 - If a TCP/IP, UDP/IP, or ICMP/IP frame is received that has a wrong TCP, UDP, or ICMP checksum, the
 *     frame is discarded. Discarding is only available when the RX FIFO operates in store and
 *     forward mode (RSFL cleared).
 */

#define BP_ENET_RACC_PRODIS      (2)      //!< Bit position for ENET_RACC_PRODIS.
#define BM_ENET_RACC_PRODIS      (0x00000004)  //!< Bit mask for ENET_RACC_PRODIS.

//! @brief Get value of ENET_RACC_PRODIS from a register value.
#define BG_ENET_RACC_PRODIS(r)   (((r) & BM_ENET_RACC_PRODIS) >> BP_ENET_RACC_PRODIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RACC_PRODIS.
#define BF_ENET_RACC_PRODIS(v)   ((((reg32_t) v) << BP_ENET_RACC_PRODIS) & BM_ENET_RACC_PRODIS)
#else
//! @brief Format value for bitfield ENET_RACC_PRODIS.
#define BF_ENET_RACC_PRODIS(v)   (((v) << BP_ENET_RACC_PRODIS) & BM_ENET_RACC_PRODIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PRODIS field to a new value.
#define BW_ENET_RACC_PRODIS(v)   (HW_ENET_RACC_WR((HW_ENET_RACC_RD() & ~BM_ENET_RACC_PRODIS) | BF_ENET_RACC_PRODIS(v)))
#endif


/* --- Register HW_ENET_RACC, field LINEDIS[6] (RW)
 *

 *
 * Values:
 * 0 - Frames with errors are not discarded.
 * 1 - Any frame received with a CRC, length, or PHY error is automatically discarded and not forwarded to
 *     the user application interface.
 */

#define BP_ENET_RACC_LINEDIS      (6)      //!< Bit position for ENET_RACC_LINEDIS.
#define BM_ENET_RACC_LINEDIS      (0x00000040)  //!< Bit mask for ENET_RACC_LINEDIS.

//! @brief Get value of ENET_RACC_LINEDIS from a register value.
#define BG_ENET_RACC_LINEDIS(r)   (((r) & BM_ENET_RACC_LINEDIS) >> BP_ENET_RACC_LINEDIS)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RACC_LINEDIS.
#define BF_ENET_RACC_LINEDIS(v)   ((((reg32_t) v) << BP_ENET_RACC_LINEDIS) & BM_ENET_RACC_LINEDIS)
#else
//! @brief Format value for bitfield ENET_RACC_LINEDIS.
#define BF_ENET_RACC_LINEDIS(v)   (((v) << BP_ENET_RACC_LINEDIS) & BM_ENET_RACC_LINEDIS)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the LINEDIS field to a new value.
#define BW_ENET_RACC_LINEDIS(v)   (HW_ENET_RACC_WR((HW_ENET_RACC_RD() & ~BM_ENET_RACC_LINEDIS) | BF_ENET_RACC_LINEDIS(v)))
#endif


/* --- Register HW_ENET_RACC, field SHIFT16[7] (RW)
 *
 * When this field is set, the actual frame data starts at bit 16 of the first word read from the RX
 * FIFO aligning the Ethernet payload on a 32-bit boundary. This function only affects the FIFO
 * storage and has no influence on the statistics, which use the actual length of the frame
 * received.
 *
 * Values:
 * 0 - Disabled.
 * 1 - Instructs the MAC to write two additional bytes in front of each frame received into the RX FIFO.
 */

#define BP_ENET_RACC_SHIFT16      (7)      //!< Bit position for ENET_RACC_SHIFT16.
#define BM_ENET_RACC_SHIFT16      (0x00000080)  //!< Bit mask for ENET_RACC_SHIFT16.

//! @brief Get value of ENET_RACC_SHIFT16 from a register value.
#define BG_ENET_RACC_SHIFT16(r)   (((r) & BM_ENET_RACC_SHIFT16) >> BP_ENET_RACC_SHIFT16)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_RACC_SHIFT16.
#define BF_ENET_RACC_SHIFT16(v)   ((((reg32_t) v) << BP_ENET_RACC_SHIFT16) & BM_ENET_RACC_SHIFT16)
#else
//! @brief Format value for bitfield ENET_RACC_SHIFT16.
#define BF_ENET_RACC_SHIFT16(v)   (((v) << BP_ENET_RACC_SHIFT16) & BM_ENET_RACC_SHIFT16)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SHIFT16 field to a new value.
#define BW_ENET_RACC_SHIFT16(v)   (HW_ENET_RACC_WR((HW_ENET_RACC_RD() & ~BM_ENET_RACC_SHIFT16) | BF_ENET_RACC_SHIFT16(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ATCR - Timer Control Register (RW)
 *
 * Reset value: 0x00000000
 *
 * ATCR command fields can trigger the corresponding events directly. It is not necessary to
 * preserve any of the configuration fields when a command field is set in the register, that is, no
 * read-modify-write is required. The fields are automatically cleared after the command completes.
 */
typedef union _hw_enet_atcr
{
    reg32_t U;
    struct _hw_enet_atcr_bitfields
    {
        unsigned EN : 1; //!< [0] 
        unsigned RESERVED0 : 1; //!< [1] 
        unsigned OFFEN : 1; //!< [2] 
        unsigned OFFRST : 1; //!< [3] 
        unsigned PEREN : 1; //!< [4] 
        unsigned RESERVED1 : 2; //!< [6:5] 
        unsigned PINPER : 1; //!< [7] Enables event signal output external pin frc_evt_period assertion on period event. Not all devices contain the event signal output. See the chip configuration details.
        unsigned RESERVED2 : 1; //!< [8] 
        unsigned RESTART : 1; //!< [9] Resets the timer to zero. This has no effect on the counter enable. If the counter is enabled when this field is set, the timer is reset to zero and starts counting from there. When set, all other fields are ignored during a write.
        unsigned RESERVED3 : 1; //!< [10] 
        unsigned CAPTURE : 1; //!< [11] 
        unsigned RESERVED4 : 1; //!< [12] This is a test command. When set, the timer increments by the value given in the correction increment register. Should not be used during normal operation.
        unsigned SLAVE : 1; //!< [13] 
        unsigned RESERVED5 : 18; //!< [31:14] 
    } B;
} hw_enet_atcr_t;
#endif

/*
 * constants & macros for entire ENET_ATCR register
 */
#define HW_ENET_ATCR_ADDR      (REGS_ENET_BASE + 0x400)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ATCR           (*(volatile hw_enet_atcr_t *) HW_ENET_ATCR_ADDR)
#define HW_ENET_ATCR_RD()      (HW_ENET_ATCR.U)
#define HW_ENET_ATCR_WR(v)     (HW_ENET_ATCR.U = (v))
#define HW_ENET_ATCR_SET(v)    (HW_ENET_ATCR_WR(HW_ENET_ATCR_RD() |  (v)))
#define HW_ENET_ATCR_CLR(v)    (HW_ENET_ATCR_WR(HW_ENET_ATCR_RD() & ~(v)))
#define HW_ENET_ATCR_TOG(v)    (HW_ENET_ATCR_WR(HW_ENET_ATCR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_ATCR bitfields
 */

/* --- Register HW_ENET_ATCR, field EN[0] (RW)
 *

 *
 * Values:
 * 0 - The timer stops at the current value.
 * 1 - The timer starts incrementing.
 */

#define BP_ENET_ATCR_EN      (0)      //!< Bit position for ENET_ATCR_EN.
#define BM_ENET_ATCR_EN      (0x00000001)  //!< Bit mask for ENET_ATCR_EN.

//! @brief Get value of ENET_ATCR_EN from a register value.
#define BG_ENET_ATCR_EN(r)   (((r) & BM_ENET_ATCR_EN) >> BP_ENET_ATCR_EN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_EN.
#define BF_ENET_ATCR_EN(v)   ((((reg32_t) v) << BP_ENET_ATCR_EN) & BM_ENET_ATCR_EN)
#else
//! @brief Format value for bitfield ENET_ATCR_EN.
#define BF_ENET_ATCR_EN(v)   (((v) << BP_ENET_ATCR_EN) & BM_ENET_ATCR_EN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the EN field to a new value.
#define BW_ENET_ATCR_EN(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_EN) | BF_ENET_ATCR_EN(v)))
#endif


/* --- Register HW_ENET_ATCR, field OFFEN[2] (RW)
 *

 *
 * Values:
 * 0 - Disable.
 * 1 - The timer can be reset to zero when the given offset time is reached (offset event). The field is
 *     cleared when the offset event is reached, so no further event occurs until the field is set
 *     again. The timer offset value must be set before setting this field.
 */

#define BP_ENET_ATCR_OFFEN      (2)      //!< Bit position for ENET_ATCR_OFFEN.
#define BM_ENET_ATCR_OFFEN      (0x00000004)  //!< Bit mask for ENET_ATCR_OFFEN.

//! @brief Get value of ENET_ATCR_OFFEN from a register value.
#define BG_ENET_ATCR_OFFEN(r)   (((r) & BM_ENET_ATCR_OFFEN) >> BP_ENET_ATCR_OFFEN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_OFFEN.
#define BF_ENET_ATCR_OFFEN(v)   ((((reg32_t) v) << BP_ENET_ATCR_OFFEN) & BM_ENET_ATCR_OFFEN)
#else
//! @brief Format value for bitfield ENET_ATCR_OFFEN.
#define BF_ENET_ATCR_OFFEN(v)   (((v) << BP_ENET_ATCR_OFFEN) & BM_ENET_ATCR_OFFEN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFEN field to a new value.
#define BW_ENET_ATCR_OFFEN(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_OFFEN) | BF_ENET_ATCR_OFFEN(v)))
#endif


/* --- Register HW_ENET_ATCR, field OFFRST[3] (RW)
 *

 *
 * Values:
 * 0 - The timer is not affected and no action occurs, besides clearing OFFEN, when the offset is reached.
 * 1 - If OFFEN is set, the timer resets to zero when the offset setting is reached. The offset event does
 *     not cause a timer interrupt.
 */

#define BP_ENET_ATCR_OFFRST      (3)      //!< Bit position for ENET_ATCR_OFFRST.
#define BM_ENET_ATCR_OFFRST      (0x00000008)  //!< Bit mask for ENET_ATCR_OFFRST.

//! @brief Get value of ENET_ATCR_OFFRST from a register value.
#define BG_ENET_ATCR_OFFRST(r)   (((r) & BM_ENET_ATCR_OFFRST) >> BP_ENET_ATCR_OFFRST)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_OFFRST.
#define BF_ENET_ATCR_OFFRST(v)   ((((reg32_t) v) << BP_ENET_ATCR_OFFRST) & BM_ENET_ATCR_OFFRST)
#else
//! @brief Format value for bitfield ENET_ATCR_OFFRST.
#define BF_ENET_ATCR_OFFRST(v)   (((v) << BP_ENET_ATCR_OFFRST) & BM_ENET_ATCR_OFFRST)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFRST field to a new value.
#define BW_ENET_ATCR_OFFRST(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_OFFRST) | BF_ENET_ATCR_OFFRST(v)))
#endif


/* --- Register HW_ENET_ATCR, field PEREN[4] (RW)
 *

 *
 * Values:
 * 0 - Disable.
 * 1 -  A period event interrupt can be generated (EIR[TS_TIMER]) and the event signal output external pin
 *     frc_evt_period is asserted when the timer wraps around according to the periodic setting
 *     ATPER. The timer period value must be set before setting this bit.  Not all devices contain
 *     the event signal output. See the chip configuration details.
 */

#define BP_ENET_ATCR_PEREN      (4)      //!< Bit position for ENET_ATCR_PEREN.
#define BM_ENET_ATCR_PEREN      (0x00000010)  //!< Bit mask for ENET_ATCR_PEREN.

//! @brief Get value of ENET_ATCR_PEREN from a register value.
#define BG_ENET_ATCR_PEREN(r)   (((r) & BM_ENET_ATCR_PEREN) >> BP_ENET_ATCR_PEREN)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_PEREN.
#define BF_ENET_ATCR_PEREN(v)   ((((reg32_t) v) << BP_ENET_ATCR_PEREN) & BM_ENET_ATCR_PEREN)
#else
//! @brief Format value for bitfield ENET_ATCR_PEREN.
#define BF_ENET_ATCR_PEREN(v)   (((v) << BP_ENET_ATCR_PEREN) & BM_ENET_ATCR_PEREN)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PEREN field to a new value.
#define BW_ENET_ATCR_PEREN(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_PEREN) | BF_ENET_ATCR_PEREN(v)))
#endif


/* --- Register HW_ENET_ATCR, field PINPER[7] (RW)
 *
 * Enables event signal output external pin frc_evt_period assertion on period event. Not all
 * devices contain the event signal output. See the chip configuration details.
 *
 * Values:
 * 0 - Disable.
 * 1 - Enable.
 */

#define BP_ENET_ATCR_PINPER      (7)      //!< Bit position for ENET_ATCR_PINPER.
#define BM_ENET_ATCR_PINPER      (0x00000080)  //!< Bit mask for ENET_ATCR_PINPER.

//! @brief Get value of ENET_ATCR_PINPER from a register value.
#define BG_ENET_ATCR_PINPER(r)   (((r) & BM_ENET_ATCR_PINPER) >> BP_ENET_ATCR_PINPER)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_PINPER.
#define BF_ENET_ATCR_PINPER(v)   ((((reg32_t) v) << BP_ENET_ATCR_PINPER) & BM_ENET_ATCR_PINPER)
#else
//! @brief Format value for bitfield ENET_ATCR_PINPER.
#define BF_ENET_ATCR_PINPER(v)   (((v) << BP_ENET_ATCR_PINPER) & BM_ENET_ATCR_PINPER)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PINPER field to a new value.
#define BW_ENET_ATCR_PINPER(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_PINPER) | BF_ENET_ATCR_PINPER(v)))
#endif


/* --- Register HW_ENET_ATCR, field RESTART[9] (RW)
 *
 * Resets the timer to zero. This has no effect on the counter enable. If the counter is enabled
 * when this field is set, the timer is reset to zero and starts counting from there. When set, all
 * other fields are ignored during a write.
 */

#define BP_ENET_ATCR_RESTART      (9)      //!< Bit position for ENET_ATCR_RESTART.
#define BM_ENET_ATCR_RESTART      (0x00000200)  //!< Bit mask for ENET_ATCR_RESTART.

//! @brief Get value of ENET_ATCR_RESTART from a register value.
#define BG_ENET_ATCR_RESTART(r)   (((r) & BM_ENET_ATCR_RESTART) >> BP_ENET_ATCR_RESTART)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_RESTART.
#define BF_ENET_ATCR_RESTART(v)   ((((reg32_t) v) << BP_ENET_ATCR_RESTART) & BM_ENET_ATCR_RESTART)
#else
//! @brief Format value for bitfield ENET_ATCR_RESTART.
#define BF_ENET_ATCR_RESTART(v)   (((v) << BP_ENET_ATCR_RESTART) & BM_ENET_ATCR_RESTART)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the RESTART field to a new value.
#define BW_ENET_ATCR_RESTART(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_RESTART) | BF_ENET_ATCR_RESTART(v)))
#endif

/* --- Register HW_ENET_ATCR, field CAPTURE[11] (RW)
 *

 *
 * Values:
 * 0 - No effect.
 * 1 - The current time is captured and can be read from the ATVR register.
 */

#define BP_ENET_ATCR_CAPTURE      (11)      //!< Bit position for ENET_ATCR_CAPTURE.
#define BM_ENET_ATCR_CAPTURE      (0x00000800)  //!< Bit mask for ENET_ATCR_CAPTURE.

//! @brief Get value of ENET_ATCR_CAPTURE from a register value.
#define BG_ENET_ATCR_CAPTURE(r)   (((r) & BM_ENET_ATCR_CAPTURE) >> BP_ENET_ATCR_CAPTURE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_CAPTURE.
#define BF_ENET_ATCR_CAPTURE(v)   ((((reg32_t) v) << BP_ENET_ATCR_CAPTURE) & BM_ENET_ATCR_CAPTURE)
#else
//! @brief Format value for bitfield ENET_ATCR_CAPTURE.
#define BF_ENET_ATCR_CAPTURE(v)   (((v) << BP_ENET_ATCR_CAPTURE) & BM_ENET_ATCR_CAPTURE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the CAPTURE field to a new value.
#define BW_ENET_ATCR_CAPTURE(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_CAPTURE) | BF_ENET_ATCR_CAPTURE(v)))
#endif


/* --- Register HW_ENET_ATCR, field SLAVE[13] (RW)
 *

 *
 * Values:
 * 0 - The timer is active and all configuration fields in this register are relevant.
 * 1 - The internal timer is disabled and the externally provided timer value from pins frc_in() is used.
 *     All other fields, except CAPTURE, in this register have no effect. CAPTURE can still be used
 *     to capture the current timer value.
 */

#define BP_ENET_ATCR_SLAVE      (13)      //!< Bit position for ENET_ATCR_SLAVE.
#define BM_ENET_ATCR_SLAVE      (0x00002000)  //!< Bit mask for ENET_ATCR_SLAVE.

//! @brief Get value of ENET_ATCR_SLAVE from a register value.
#define BG_ENET_ATCR_SLAVE(r)   (((r) & BM_ENET_ATCR_SLAVE) >> BP_ENET_ATCR_SLAVE)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCR_SLAVE.
#define BF_ENET_ATCR_SLAVE(v)   ((((reg32_t) v) << BP_ENET_ATCR_SLAVE) & BM_ENET_ATCR_SLAVE)
#else
//! @brief Format value for bitfield ENET_ATCR_SLAVE.
#define BF_ENET_ATCR_SLAVE(v)   (((v) << BP_ENET_ATCR_SLAVE) & BM_ENET_ATCR_SLAVE)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the SLAVE field to a new value.
#define BW_ENET_ATCR_SLAVE(v)   (HW_ENET_ATCR_WR((HW_ENET_ATCR_RD() & ~BM_ENET_ATCR_SLAVE) | BF_ENET_ATCR_SLAVE(v)))
#endif


#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ATVR - Timer Value Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_atvr
{
    reg32_t U;
    struct _hw_enet_atvr_bitfields
    {
        unsigned ATIME : 32; //!< [31:0] A write sets the timer. A read returns the last captured value. To read the current value, issue a capture command (set ATCR[CAPTURE]) prior to reading this register.
    } B;
} hw_enet_atvr_t;
#endif

/*
 * constants & macros for entire ENET_ATVR register
 */
#define HW_ENET_ATVR_ADDR      (REGS_ENET_BASE + 0x404)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ATVR           (*(volatile hw_enet_atvr_t *) HW_ENET_ATVR_ADDR)
#define HW_ENET_ATVR_RD()      (HW_ENET_ATVR.U)
#define HW_ENET_ATVR_WR(v)     (HW_ENET_ATVR.U = (v))
#define HW_ENET_ATVR_SET(v)    (HW_ENET_ATVR_WR(HW_ENET_ATVR_RD() |  (v)))
#define HW_ENET_ATVR_CLR(v)    (HW_ENET_ATVR_WR(HW_ENET_ATVR_RD() & ~(v)))
#define HW_ENET_ATVR_TOG(v)    (HW_ENET_ATVR_WR(HW_ENET_ATVR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_ATVR bitfields
 */

/* --- Register HW_ENET_ATVR, field ATIME[31:0] (RW)
 *
 * A write sets the timer. A read returns the last captured value. To read the current value, issue
 * a capture command (set ATCR[CAPTURE]) prior to reading this register.
 */

#define BP_ENET_ATVR_ATIME      (0)      //!< Bit position for ENET_ATVR_ATIME.
#define BM_ENET_ATVR_ATIME      (0xffffffff)  //!< Bit mask for ENET_ATVR_ATIME.

//! @brief Get value of ENET_ATVR_ATIME from a register value.
#define BG_ENET_ATVR_ATIME(r)   (((r) & BM_ENET_ATVR_ATIME) >> BP_ENET_ATVR_ATIME)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATVR_ATIME.
#define BF_ENET_ATVR_ATIME(v)   ((((reg32_t) v) << BP_ENET_ATVR_ATIME) & BM_ENET_ATVR_ATIME)
#else
//! @brief Format value for bitfield ENET_ATVR_ATIME.
#define BF_ENET_ATVR_ATIME(v)   (((v) << BP_ENET_ATVR_ATIME) & BM_ENET_ATVR_ATIME)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the ATIME field to a new value.
#define BW_ENET_ATVR_ATIME(v)   (HW_ENET_ATVR_WR((HW_ENET_ATVR_RD() & ~BM_ENET_ATVR_ATIME) | BF_ENET_ATVR_ATIME(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ATOFF - Timer Offset Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_atoff
{
    reg32_t U;
    struct _hw_enet_atoff_bitfields
    {
        unsigned OFFSET : 32; //!< [31:0] Offset value for one-shot event generation. When the timer reaches the value, an event can be generated to reset the counter. If the increment value in ATINC is given in true nanoseconds, this value is also given in true nanoseconds.
    } B;
} hw_enet_atoff_t;
#endif

/*
 * constants & macros for entire ENET_ATOFF register
 */
#define HW_ENET_ATOFF_ADDR      (REGS_ENET_BASE + 0x408)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ATOFF           (*(volatile hw_enet_atoff_t *) HW_ENET_ATOFF_ADDR)
#define HW_ENET_ATOFF_RD()      (HW_ENET_ATOFF.U)
#define HW_ENET_ATOFF_WR(v)     (HW_ENET_ATOFF.U = (v))
#define HW_ENET_ATOFF_SET(v)    (HW_ENET_ATOFF_WR(HW_ENET_ATOFF_RD() |  (v)))
#define HW_ENET_ATOFF_CLR(v)    (HW_ENET_ATOFF_WR(HW_ENET_ATOFF_RD() & ~(v)))
#define HW_ENET_ATOFF_TOG(v)    (HW_ENET_ATOFF_WR(HW_ENET_ATOFF_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_ATOFF bitfields
 */

/* --- Register HW_ENET_ATOFF, field OFFSET[31:0] (RW)
 *
 * Offset value for one-shot event generation. When the timer reaches the value, an event can be
 * generated to reset the counter. If the increment value in ATINC is given in true nanoseconds,
 * this value is also given in true nanoseconds.
 */

#define BP_ENET_ATOFF_OFFSET      (0)      //!< Bit position for ENET_ATOFF_OFFSET.
#define BM_ENET_ATOFF_OFFSET      (0xffffffff)  //!< Bit mask for ENET_ATOFF_OFFSET.

//! @brief Get value of ENET_ATOFF_OFFSET from a register value.
#define BG_ENET_ATOFF_OFFSET(r)   (((r) & BM_ENET_ATOFF_OFFSET) >> BP_ENET_ATOFF_OFFSET)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATOFF_OFFSET.
#define BF_ENET_ATOFF_OFFSET(v)   ((((reg32_t) v) << BP_ENET_ATOFF_OFFSET) & BM_ENET_ATOFF_OFFSET)
#else
//! @brief Format value for bitfield ENET_ATOFF_OFFSET.
#define BF_ENET_ATOFF_OFFSET(v)   (((v) << BP_ENET_ATOFF_OFFSET) & BM_ENET_ATOFF_OFFSET)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the OFFSET field to a new value.
#define BW_ENET_ATOFF_OFFSET(v)   (HW_ENET_ATOFF_WR((HW_ENET_ATOFF_RD() & ~BM_ENET_ATOFF_OFFSET) | BF_ENET_ATOFF_OFFSET(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ATPER - Timer Period Register (RW)
 *
 * Reset value: 0x3b9aca00
 *

 */
typedef union _hw_enet_atper
{
    reg32_t U;
    struct _hw_enet_atper_bitfields
    {
        unsigned PERIOD : 32; //!< [31:0] Value for generating periodic events. Each instance the timer reaches this value, the period event occurs and the timer restarts. If the increment value in ATINC is given in true nanoseconds, this value is also given in true nanoseconds. The value should be initialized to 1,000,000,000 (1 x 10 9 ) to represent a timer wrap around of one second. The increment value set in ATINC should be set to the true nanoseconds of the period of clock ts_clk, hence implementing a true 1 second counter.
    } B;
} hw_enet_atper_t;
#endif

/*
 * constants & macros for entire ENET_ATPER register
 */
#define HW_ENET_ATPER_ADDR      (REGS_ENET_BASE + 0x40c)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ATPER           (*(volatile hw_enet_atper_t *) HW_ENET_ATPER_ADDR)
#define HW_ENET_ATPER_RD()      (HW_ENET_ATPER.U)
#define HW_ENET_ATPER_WR(v)     (HW_ENET_ATPER.U = (v))
#define HW_ENET_ATPER_SET(v)    (HW_ENET_ATPER_WR(HW_ENET_ATPER_RD() |  (v)))
#define HW_ENET_ATPER_CLR(v)    (HW_ENET_ATPER_WR(HW_ENET_ATPER_RD() & ~(v)))
#define HW_ENET_ATPER_TOG(v)    (HW_ENET_ATPER_WR(HW_ENET_ATPER_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_ATPER bitfields
 */

/* --- Register HW_ENET_ATPER, field PERIOD[31:0] (RW)
 *
 * Value for generating periodic events. Each instance the timer reaches this value, the period
 * event occurs and the timer restarts. If the increment value in ATINC is given in true
 * nanoseconds, this value is also given in true nanoseconds. The value should be initialized to
 * 1,000,000,000 (1 x 10 9 ) to represent a timer wrap around of one second. The increment value set
 * in ATINC should be set to the true nanoseconds of the period of clock ts_clk, hence implementing
 * a true 1 second counter.
 */

#define BP_ENET_ATPER_PERIOD      (0)      //!< Bit position for ENET_ATPER_PERIOD.
#define BM_ENET_ATPER_PERIOD      (0xffffffff)  //!< Bit mask for ENET_ATPER_PERIOD.

//! @brief Get value of ENET_ATPER_PERIOD from a register value.
#define BG_ENET_ATPER_PERIOD(r)   (((r) & BM_ENET_ATPER_PERIOD) >> BP_ENET_ATPER_PERIOD)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATPER_PERIOD.
#define BF_ENET_ATPER_PERIOD(v)   ((((reg32_t) v) << BP_ENET_ATPER_PERIOD) & BM_ENET_ATPER_PERIOD)
#else
//! @brief Format value for bitfield ENET_ATPER_PERIOD.
#define BF_ENET_ATPER_PERIOD(v)   (((v) << BP_ENET_ATPER_PERIOD) & BM_ENET_ATPER_PERIOD)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the PERIOD field to a new value.
#define BW_ENET_ATPER_PERIOD(v)   (HW_ENET_ATPER_WR((HW_ENET_ATPER_RD() & ~BM_ENET_ATPER_PERIOD) | BF_ENET_ATPER_PERIOD(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ATCOR - Timer Correction Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_atcor
{
    reg32_t U;
    struct _hw_enet_atcor_bitfields
    {
        unsigned COR : 31; //!< [30:0] Defines after how many timer clock cycles (ts_clk) the correction counter should be reset and trigger a correction increment on the timer. The amount of correction is defined in ATINC[INC_CORR]. For example, setting the increment amount to zero stops the timer for one clock cycle, slowing it down. Larger values speed up the timer. A value of 0 disables the correction counter and no corrections occur. This value is given in clock cycles, not in nanoseconds as all other values.
        unsigned RESERVED0 : 1; //!< [31] 
    } B;
} hw_enet_atcor_t;
#endif

/*
 * constants & macros for entire ENET_ATCOR register
 */
#define HW_ENET_ATCOR_ADDR      (REGS_ENET_BASE + 0x410)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ATCOR           (*(volatile hw_enet_atcor_t *) HW_ENET_ATCOR_ADDR)
#define HW_ENET_ATCOR_RD()      (HW_ENET_ATCOR.U)
#define HW_ENET_ATCOR_WR(v)     (HW_ENET_ATCOR.U = (v))
#define HW_ENET_ATCOR_SET(v)    (HW_ENET_ATCOR_WR(HW_ENET_ATCOR_RD() |  (v)))
#define HW_ENET_ATCOR_CLR(v)    (HW_ENET_ATCOR_WR(HW_ENET_ATCOR_RD() & ~(v)))
#define HW_ENET_ATCOR_TOG(v)    (HW_ENET_ATCOR_WR(HW_ENET_ATCOR_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_ATCOR bitfields
 */

/* --- Register HW_ENET_ATCOR, field COR[30:0] (RW)
 *
 * Defines after how many timer clock cycles (ts_clk) the correction counter should be reset and
 * trigger a correction increment on the timer. The amount of correction is defined in
 * ATINC[INC_CORR]. For example, setting the increment amount to zero stops the timer for one clock
 * cycle, slowing it down. Larger values speed up the timer. A value of 0 disables the correction
 * counter and no corrections occur. This value is given in clock cycles, not in nanoseconds as all
 * other values.
 */

#define BP_ENET_ATCOR_COR      (0)      //!< Bit position for ENET_ATCOR_COR.
#define BM_ENET_ATCOR_COR      (0x7fffffff)  //!< Bit mask for ENET_ATCOR_COR.

//! @brief Get value of ENET_ATCOR_COR from a register value.
#define BG_ENET_ATCOR_COR(r)   (((r) & BM_ENET_ATCOR_COR) >> BP_ENET_ATCOR_COR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATCOR_COR.
#define BF_ENET_ATCOR_COR(v)   ((((reg32_t) v) << BP_ENET_ATCOR_COR) & BM_ENET_ATCOR_COR)
#else
//! @brief Format value for bitfield ENET_ATCOR_COR.
#define BF_ENET_ATCOR_COR(v)   (((v) << BP_ENET_ATCOR_COR) & BM_ENET_ATCOR_COR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the COR field to a new value.
#define BW_ENET_ATCOR_COR(v)   (HW_ENET_ATCOR_WR((HW_ENET_ATCOR_RD() & ~BM_ENET_ATCOR_COR) | BF_ENET_ATCOR_COR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ATINC - Time-Stamping Clock Period Register (RW)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_atinc
{
    reg32_t U;
    struct _hw_enet_atinc_bitfields
    {
        unsigned INC : 7; //!< [6:0] The timer increments by this amount each clock cycle. For example, set to 10 for 100 MHz, 8 for 125 MHz, 5 for 200 MHz. For highest precision, use a value that is an integer fraction of the period set in ATPER.
        unsigned RESERVED0 : 1; //!< [7] 
        unsigned INC_CORR : 7; //!< [14:8] This value is added every time the correction timer expires (every clock cycle given in ATCOR). A value smaller than INC slows the timer, while a value larger than INC speeds the timer.
        unsigned RESERVED1 : 17; //!< [31:15] 
    } B;
} hw_enet_atinc_t;
#endif

/*
 * constants & macros for entire ENET_ATINC register
 */
#define HW_ENET_ATINC_ADDR      (REGS_ENET_BASE + 0x414)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ATINC           (*(volatile hw_enet_atinc_t *) HW_ENET_ATINC_ADDR)
#define HW_ENET_ATINC_RD()      (HW_ENET_ATINC.U)
#define HW_ENET_ATINC_WR(v)     (HW_ENET_ATINC.U = (v))
#define HW_ENET_ATINC_SET(v)    (HW_ENET_ATINC_WR(HW_ENET_ATINC_RD() |  (v)))
#define HW_ENET_ATINC_CLR(v)    (HW_ENET_ATINC_WR(HW_ENET_ATINC_RD() & ~(v)))
#define HW_ENET_ATINC_TOG(v)    (HW_ENET_ATINC_WR(HW_ENET_ATINC_RD() ^  (v)))
#endif

/*
 * constants & macros for individual ENET_ATINC bitfields
 */

/* --- Register HW_ENET_ATINC, field INC[6:0] (RW)
 *
 * The timer increments by this amount each clock cycle. For example, set to 10 for 100 MHz, 8 for
 * 125 MHz, 5 for 200 MHz. For highest precision, use a value that is an integer fraction of the
 * period set in ATPER.
 */

#define BP_ENET_ATINC_INC      (0)      //!< Bit position for ENET_ATINC_INC.
#define BM_ENET_ATINC_INC      (0x0000007f)  //!< Bit mask for ENET_ATINC_INC.

//! @brief Get value of ENET_ATINC_INC from a register value.
#define BG_ENET_ATINC_INC(r)   (((r) & BM_ENET_ATINC_INC) >> BP_ENET_ATINC_INC)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATINC_INC.
#define BF_ENET_ATINC_INC(v)   ((((reg32_t) v) << BP_ENET_ATINC_INC) & BM_ENET_ATINC_INC)
#else
//! @brief Format value for bitfield ENET_ATINC_INC.
#define BF_ENET_ATINC_INC(v)   (((v) << BP_ENET_ATINC_INC) & BM_ENET_ATINC_INC)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC field to a new value.
#define BW_ENET_ATINC_INC(v)   (HW_ENET_ATINC_WR((HW_ENET_ATINC_RD() & ~BM_ENET_ATINC_INC) | BF_ENET_ATINC_INC(v)))
#endif

/* --- Register HW_ENET_ATINC, field INC_CORR[14:8] (RW)
 *
 * This value is added every time the correction timer expires (every clock cycle given in ATCOR). A
 * value smaller than INC slows the timer, while a value larger than INC speeds the timer.
 */

#define BP_ENET_ATINC_INC_CORR      (8)      //!< Bit position for ENET_ATINC_INC_CORR.
#define BM_ENET_ATINC_INC_CORR      (0x00007f00)  //!< Bit mask for ENET_ATINC_INC_CORR.

//! @brief Get value of ENET_ATINC_INC_CORR from a register value.
#define BG_ENET_ATINC_INC_CORR(r)   (((r) & BM_ENET_ATINC_INC_CORR) >> BP_ENET_ATINC_INC_CORR)

#ifndef __LANGUAGE_ASM__
//! @brief Format value for bitfield ENET_ATINC_INC_CORR.
#define BF_ENET_ATINC_INC_CORR(v)   ((((reg32_t) v) << BP_ENET_ATINC_INC_CORR) & BM_ENET_ATINC_INC_CORR)
#else
//! @brief Format value for bitfield ENET_ATINC_INC_CORR.
#define BF_ENET_ATINC_INC_CORR(v)   (((v) << BP_ENET_ATINC_INC_CORR) & BM_ENET_ATINC_INC_CORR)
#endif

#ifndef __LANGUAGE_ASM__
//! @brief Set the INC_CORR field to a new value.
#define BW_ENET_ATINC_INC_CORR(v)   (HW_ENET_ATINC_WR((HW_ENET_ATINC_RD() & ~BM_ENET_ATINC_INC_CORR) | BF_ENET_ATINC_INC_CORR(v)))
#endif

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_ENET_ATSTMP - Timestamp of Last Transmitted Frame (RO)
 *
 * Reset value: 0x00000000
 *

 */
typedef union _hw_enet_atstmp
{
    reg32_t U;
    struct _hw_enet_atstmp_bitfields
    {
        unsigned TIMESTAMP : 32; //!< [31:0] Timestamp of the last frame transmitted by the core that had TxBD[TS] set the ff_tx_ts_frm signal asserted from the user application . This register is only valid when EIR[TS_AVAIL] is set.
    } B;
} hw_enet_atstmp_t;
#endif

/*
 * constants & macros for entire ENET_ATSTMP register
 */
#define HW_ENET_ATSTMP_ADDR      (REGS_ENET_BASE + 0x418)

#ifndef __LANGUAGE_ASM__
#define HW_ENET_ATSTMP           (*(volatile hw_enet_atstmp_t *) HW_ENET_ATSTMP_ADDR)
#define HW_ENET_ATSTMP_RD()      (HW_ENET_ATSTMP.U)
#endif

/*
 * constants & macros for individual ENET_ATSTMP bitfields
 */

/* --- Register HW_ENET_ATSTMP, field TIMESTAMP[31:0] (RW)
 *
 * Timestamp of the last frame transmitted by the core that had TxBD[TS] set the ff_tx_ts_frm signal
 * asserted from the user application . This register is only valid when EIR[TS_AVAIL] is set.
 */

#define BP_ENET_ATSTMP_TIMESTAMP      (0)      //!< Bit position for ENET_ATSTMP_TIMESTAMP.
#define BM_ENET_ATSTMP_TIMESTAMP      (0xffffffff)  //!< Bit mask for ENET_ATSTMP_TIMESTAMP.

//! @brief Get value of ENET_ATSTMP_TIMESTAMP from a register value.
#define BG_ENET_ATSTMP_TIMESTAMP(r)   (((r) & BM_ENET_ATSTMP_TIMESTAMP) >> BP_ENET_ATSTMP_TIMESTAMP)


/*!
 * @brief All ENET module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_enet
{
    reg32_t _reserved0;
    volatile hw_enet_eir_t EIR; //!< Interrupt Event Register
    volatile hw_enet_eimr_t EIMR; //!< Interrupt Mask Register
    reg32_t _reserved1;
    volatile hw_enet_rdar_t RDAR; //!< Receive Descriptor Active Register
    volatile hw_enet_tdar_t TDAR; //!< Transmit Descriptor Active Register
    reg32_t _reserved2[3];
    volatile hw_enet_ecr_t ECR; //!< Ethernet Control Register
    reg32_t _reserved3[6];
    volatile hw_enet_mmfr_t MMFR; //!< MII Management Frame Register
    volatile hw_enet_mscr_t MSCR; //!< MII Speed Control Register
    reg32_t _reserved4[7];
    volatile hw_enet_mibc_t MIBC; //!< MIB Control Register
    reg32_t _reserved5[7];
    volatile hw_enet_rcr_t RCR; //!< Receive Control Register
    reg32_t _reserved6[15];
    volatile hw_enet_tcr_t TCR; //!< Transmit Control Register
    reg32_t _reserved7[7];
    volatile hw_enet_palr_t PALR; //!< Physical Address Lower Register
    volatile hw_enet_paur_t PAUR; //!< Physical Address Upper Register
    volatile hw_enet_opd_t OPD; //!< Opcode/Pause Duration Register
    reg32_t _reserved8[10];
    volatile hw_enet_iaur_t IAUR; //!< Descriptor Individual Upper Address Register
    volatile hw_enet_ialr_t IALR; //!< Descriptor Individual Lower Address Register
    volatile hw_enet_gaur_t GAUR; //!< Descriptor Group Upper Address Register
    volatile hw_enet_galr_t GALR; //!< Descriptor Group Lower Address Register
    reg32_t _reserved9[7];
    volatile hw_enet_tfwr_t TFWR; //!< Transmit FIFO Watermark Register
    reg32_t _reserved10[14];
    volatile hw_enet_rdsr_t RDSR; //!< Receive Descriptor Ring Start Register
    volatile hw_enet_tdsr_t TDSR; //!< Transmit Buffer Descriptor Ring Start Register
    volatile hw_enet_mrbr_t MRBR; //!< Maximum Receive Buffer Size Register
    reg32_t _reserved11;
    volatile hw_enet_rsfl_t RSFL; //!< Receive FIFO Section Full Threshold
    volatile hw_enet_rsem_t RSEM; //!< Receive FIFO Section Empty Threshold
    volatile hw_enet_raem_t RAEM; //!< Receive FIFO Almost Empty Threshold
    volatile hw_enet_rafl_t RAFL; //!< Receive FIFO Almost Full Threshold
    volatile hw_enet_tsem_t TSEM; //!< Transmit FIFO Section Empty Threshold
    volatile hw_enet_taem_t TAEM; //!< Transmit FIFO Almost Empty Threshold
    volatile hw_enet_tafl_t TAFL; //!< Transmit FIFO Almost Full Threshold
    volatile hw_enet_tipg_t TIPG; //!< Transmit Inter-Packet Gap
    volatile hw_enet_ftrl_t FTRL; //!< Frame Truncation Length
    reg32_t _reserved12[3];
    volatile hw_enet_tacc_t TACC; //!< Transmit Accelerator Function Configuration
    volatile hw_enet_racc_t RACC; //!< Receive Accelerator Function Configuration
    reg32_t _reserved13[142];
    volatile hw_enet_atcr_t ATCR; //!< Timer Control Register
    volatile hw_enet_atvr_t ATVR; //!< Timer Value Register
    volatile hw_enet_atoff_t ATOFF; //!< Timer Offset Register
    volatile hw_enet_atper_t ATPER; //!< Timer Period Register
    volatile hw_enet_atcor_t ATCOR; //!< Timer Correction Register
    volatile hw_enet_atinc_t ATINC; //!< Time-Stamping Clock Period Register
    volatile hw_enet_atstmp_t ATSTMP; //!< Timestamp of Last Transmitted Frame
} hw_enet_t;
#pragma pack()
#endif

//! @brief Macro to access all ENET registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_ENET(0)</code>.
#define HW_ENET     (*(volatile hw_enet_t *) REGS_ENET_BASE)


#endif // _ENET_H
