/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _SDMACORE_H
#define _SDMACORE_H

#include "regs.h"

#ifndef REGS_SDMACORE_BASE
#define REGS_SDMACORE_BASE (REGS_BASE + 0x020ec000)
#endif


/*!
 * @brief HW_SDMACORE_MC0PTR - ARM platform Channel 0 Pointer
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned MC0PTR : 32; //!< Contains the address-in the ARM platform memory space-of the initial SDMA context and scripts that are loaded by the SDMA boot script running on channel 0.
    } B;
} hw_sdmacore_mc0ptr_t;
#endif

/*
 * constants & macros for entire SDMACORE_MC0PTR register
 */
#define HW_SDMACORE_MC0PTR_ADDR      (REGS_SDMACORE_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_MC0PTR           (*(volatile hw_sdmacore_mc0ptr_t *) HW_SDMACORE_MC0PTR_ADDR)
#define HW_SDMACORE_MC0PTR_RD()      (HW_SDMACORE_MC0PTR.U)
#define HW_SDMACORE_MC0PTR_WR(v)     (HW_SDMACORE_MC0PTR.U = (v))
#define HW_SDMACORE_MC0PTR_SET(v)    (HW_SDMACORE_MC0PTR_WR(HW_SDMACORE_MC0PTR_RD() |  (v)))
#define HW_SDMACORE_MC0PTR_CLR(v)    (HW_SDMACORE_MC0PTR_WR(HW_SDMACORE_MC0PTR_RD() & ~(v)))
#define HW_SDMACORE_MC0PTR_TOG(v)    (HW_SDMACORE_MC0PTR_WR(HW_SDMACORE_MC0PTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_MC0PTR bitfields
 */

/* --- Register HW_SDMACORE_MC0PTR, field MC0PTR
 *
 * Contains the address-in the ARM platform memory space-of the initial
 * SDMA context and scripts that are loaded by the SDMA boot script
 * running on channel 0.
 */

#define BP_SDMACORE_MC0PTR_MC0PTR      0
#define BM_SDMACORE_MC0PTR_MC0PTR      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MC0PTR_MC0PTR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_MC0PTR_MC0PTR)
#else
#define BF_SDMACORE_MC0PTR_MC0PTR(v)   (((v) << 0) & BM_SDMACORE_MC0PTR_MC0PTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MC0PTR_MC0PTR(v)   BF_CS1(SDMACORE_MC0PTR, MC0PTR, v)
#endif

/*!
 * @brief HW_SDMACORE_CCPTR - Current Channel Pointer
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCPTR : 16; //!< Contains the start address of the context data for the current channel: Its value is CONTEXT_BASE + 24* CCR or CONTEXT_BASE + 32* CCR where CONTEXT_BASE = 0x0800. The value 24 or 32 is selected according to the programmed channel scratch RAM size in the register shown in .
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmacore_ccptr_t;
#endif

/*
 * constants & macros for entire SDMACORE_CCPTR register
 */
#define HW_SDMACORE_CCPTR_ADDR      (REGS_SDMACORE_BASE + 0x2)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_CCPTR           (*(volatile hw_sdmacore_ccptr_t *) HW_SDMACORE_CCPTR_ADDR)
#define HW_SDMACORE_CCPTR_RD()      (HW_SDMACORE_CCPTR.U)
#define HW_SDMACORE_CCPTR_WR(v)     (HW_SDMACORE_CCPTR.U = (v))
#define HW_SDMACORE_CCPTR_SET(v)    (HW_SDMACORE_CCPTR_WR(HW_SDMACORE_CCPTR_RD() |  (v)))
#define HW_SDMACORE_CCPTR_CLR(v)    (HW_SDMACORE_CCPTR_WR(HW_SDMACORE_CCPTR_RD() & ~(v)))
#define HW_SDMACORE_CCPTR_TOG(v)    (HW_SDMACORE_CCPTR_WR(HW_SDMACORE_CCPTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_CCPTR bitfields
 */

/* --- Register HW_SDMACORE_CCPTR, field CCPTR
 *
 * Contains the start address of the context data for the current
 * channel: Its value is CONTEXT_BASE + 24* CCR or CONTEXT_BASE + 32* CCR where CONTEXT_BASE =
 * 0x0800.                                 The value 24 or 32 is selected according to the
 * programmed channel                                 scratch RAM size in the register shown in .
 */

#define BP_SDMACORE_CCPTR_CCPTR      0
#define BM_SDMACORE_CCPTR_CCPTR      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_CCPTR_CCPTR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_CCPTR_CCPTR)
#else
#define BF_SDMACORE_CCPTR_CCPTR(v)   (((v) << 0) & BM_SDMACORE_CCPTR_CCPTR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_CCPTR_CCPTR(v)   BF_CS1(SDMACORE_CCPTR, CCPTR, v)
#endif

/*!
 * @brief HW_SDMACORE_CCR - Current Channel Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCR : 5; //!< Contains the number of the current running channel whose context is installed. In the case that the SDMA has finished running the channel and has entered sleep state, CCR will indicate the previous running channel. The PST bits in the OSTAT register indicate when the SDMA is in sleep state.
        unsigned RESERVED0 : 27; //!< Reserved
    } B;
} hw_sdmacore_ccr_t;
#endif

/*
 * constants & macros for entire SDMACORE_CCR register
 */
#define HW_SDMACORE_CCR_ADDR      (REGS_SDMACORE_BASE + 0x3)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_CCR           (*(volatile hw_sdmacore_ccr_t *) HW_SDMACORE_CCR_ADDR)
#define HW_SDMACORE_CCR_RD()      (HW_SDMACORE_CCR.U)
#define HW_SDMACORE_CCR_WR(v)     (HW_SDMACORE_CCR.U = (v))
#define HW_SDMACORE_CCR_SET(v)    (HW_SDMACORE_CCR_WR(HW_SDMACORE_CCR_RD() |  (v)))
#define HW_SDMACORE_CCR_CLR(v)    (HW_SDMACORE_CCR_WR(HW_SDMACORE_CCR_RD() & ~(v)))
#define HW_SDMACORE_CCR_TOG(v)    (HW_SDMACORE_CCR_WR(HW_SDMACORE_CCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_CCR bitfields
 */

/* --- Register HW_SDMACORE_CCR, field CCR
 *
 * Contains the number of the current running channel whose context is
 * installed. In the case that the SDMA has finished running the
 * channel and has entered sleep state, CCR will indicate the previous
 * running channel. The PST bits in the OSTAT register indicate when
 * the SDMA is in sleep state.
 */

#define BP_SDMACORE_CCR_CCR      0
#define BM_SDMACORE_CCR_CCR      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_CCR_CCR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_CCR_CCR)
#else
#define BF_SDMACORE_CCR_CCR(v)   (((v) << 0) & BM_SDMACORE_CCR_CCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_CCR_CCR(v)   BF_CS1(SDMACORE_CCR, CCR, v)
#endif

/*!
 * @brief HW_SDMACORE_NCR - Highest Pending Channel Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NCR : 5; //!< Contains the number of the pending channel that the scheduler has selected to run next.
        unsigned RESERVED0 : 27; //!< Reserved
    } B;
} hw_sdmacore_ncr_t;
#endif

/*
 * constants & macros for entire SDMACORE_NCR register
 */
#define HW_SDMACORE_NCR_ADDR      (REGS_SDMACORE_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_NCR           (*(volatile hw_sdmacore_ncr_t *) HW_SDMACORE_NCR_ADDR)
#define HW_SDMACORE_NCR_RD()      (HW_SDMACORE_NCR.U)
#define HW_SDMACORE_NCR_WR(v)     (HW_SDMACORE_NCR.U = (v))
#define HW_SDMACORE_NCR_SET(v)    (HW_SDMACORE_NCR_WR(HW_SDMACORE_NCR_RD() |  (v)))
#define HW_SDMACORE_NCR_CLR(v)    (HW_SDMACORE_NCR_WR(HW_SDMACORE_NCR_RD() & ~(v)))
#define HW_SDMACORE_NCR_TOG(v)    (HW_SDMACORE_NCR_WR(HW_SDMACORE_NCR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_NCR bitfields
 */

/* --- Register HW_SDMACORE_NCR, field NCR
 *
 * Contains the number of the pending channel that the scheduler has
 * selected to run next.
 */

#define BP_SDMACORE_NCR_NCR      0
#define BM_SDMACORE_NCR_NCR      0x0000001f

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_NCR_NCR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_NCR_NCR)
#else
#define BF_SDMACORE_NCR_NCR(v)   (((v) << 0) & BM_SDMACORE_NCR_NCR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_NCR_NCR(v)   BF_CS1(SDMACORE_NCR, NCR, v)
#endif

/*!
 * @brief HW_SDMACORE_EVENTS - External DMA Requests Mirror
 *
 * This register is very useful in the case of DMA requests that are active
 * when a peripheral FIFO level is above the programmed watermark. The
 * activation of the DMA request (rising edge) is detected by the SDMA
 * logic and it can enable one or several channels. One of the channels
 * accesses the peripheral and reads or writes a number of data that
 * matches the watermark level (for example, if the watermark is four
 * words, the channel reads or writes four words). If the channel is effectively executed long after
 * the DMA request was                             received, reading or writing the watermark number
 * of data may not be                             sufficient to reset the DMA request (for example,
 * if the FIFO watermark                             is four and at the channel execution it already
 * contains nine pieces of                             data). This means no new rising edge may be
 * detected by the SDMA,                             although there still remains transfers to
 * perform. Therefore, if the                             channel were terminated at that time, it
 * would not be restarted, causing                             potential overrun or underrun of the
 * peripheral.  The proposed mechanism is for the channel to check this register after it
 * has performed the "watermark" number of accesses to the peripheral. If
 * the bit for the DMA request that triggers this channel is set, it means
 * there is still another watermark number of data to transfer. This goes
 * on until the bit is cleared. The same script can be used for multiple
 * channels that require this behavior. The script can determine its
 * channel number from the CCR register and infer the corresponding DMA
 * request bit to check. It needs a reference table that is coherent with
 * the request-channel matrix that the ARM platform programmed.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EVENTS : 32; //!< Reflects the status of the SDMA's external DMA requests. It is meant to allow any channel to monitor the states of these SDMA inputs.  This register displays EVENTS 0-31. The EVENTS2 register displays events 32-47.
    } B;
} hw_sdmacore_events_t;
#endif

/*
 * constants & macros for entire SDMACORE_EVENTS register
 */
#define HW_SDMACORE_EVENTS_ADDR      (REGS_SDMACORE_BASE + 0x5)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EVENTS           (*(volatile hw_sdmacore_events_t *) HW_SDMACORE_EVENTS_ADDR)
#define HW_SDMACORE_EVENTS_RD()      (HW_SDMACORE_EVENTS.U)
#define HW_SDMACORE_EVENTS_WR(v)     (HW_SDMACORE_EVENTS.U = (v))
#define HW_SDMACORE_EVENTS_SET(v)    (HW_SDMACORE_EVENTS_WR(HW_SDMACORE_EVENTS_RD() |  (v)))
#define HW_SDMACORE_EVENTS_CLR(v)    (HW_SDMACORE_EVENTS_WR(HW_SDMACORE_EVENTS_RD() & ~(v)))
#define HW_SDMACORE_EVENTS_TOG(v)    (HW_SDMACORE_EVENTS_WR(HW_SDMACORE_EVENTS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EVENTS bitfields
 */

/* --- Register HW_SDMACORE_EVENTS, field EVENTS
 *
 * Reflects the status of the SDMA's external DMA requests. It is meant
 * to allow any channel to monitor the states of these SDMA inputs.  This register displays EVENTS
 * 0-31. The                                     EVENTS2 register displays events 32-47.
 */

#define BP_SDMACORE_EVENTS_EVENTS      0
#define BM_SDMACORE_EVENTS_EVENTS      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EVENTS_EVENTS(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EVENTS_EVENTS)
#else
#define BF_SDMACORE_EVENTS_EVENTS(v)   (((v) << 0) & BM_SDMACORE_EVENTS_EVENTS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EVENTS_EVENTS(v)   BF_CS1(SDMACORE_EVENTS, EVENTS, v)
#endif

/*!
 * @brief HW_SDMACORE_CCPRI - Current Channel Priority
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CCPRI : 3; //!< Contains the 3-bit priority of the channel whose context is installed. It is 0 when no channel is running.  1-7 current channel priority
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_sdmacore_ccpri_t;
#endif

/*
 * constants & macros for entire SDMACORE_CCPRI register
 */
#define HW_SDMACORE_CCPRI_ADDR      (REGS_SDMACORE_BASE + 0x6)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_CCPRI           (*(volatile hw_sdmacore_ccpri_t *) HW_SDMACORE_CCPRI_ADDR)
#define HW_SDMACORE_CCPRI_RD()      (HW_SDMACORE_CCPRI.U)
#define HW_SDMACORE_CCPRI_WR(v)     (HW_SDMACORE_CCPRI.U = (v))
#define HW_SDMACORE_CCPRI_SET(v)    (HW_SDMACORE_CCPRI_WR(HW_SDMACORE_CCPRI_RD() |  (v)))
#define HW_SDMACORE_CCPRI_CLR(v)    (HW_SDMACORE_CCPRI_WR(HW_SDMACORE_CCPRI_RD() & ~(v)))
#define HW_SDMACORE_CCPRI_TOG(v)    (HW_SDMACORE_CCPRI_WR(HW_SDMACORE_CCPRI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_CCPRI bitfields
 */

/* --- Register HW_SDMACORE_CCPRI, field CCPRI
 *
 * Contains the 3-bit priority of the channel whose context is
 * installed. It is 0 when no channel is running.  1-7 current channel priority
 */

#define BP_SDMACORE_CCPRI_CCPRI      0
#define BM_SDMACORE_CCPRI_CCPRI      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_CCPRI_CCPRI(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_CCPRI_CCPRI)
#else
#define BF_SDMACORE_CCPRI_CCPRI(v)   (((v) << 0) & BM_SDMACORE_CCPRI_CCPRI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_CCPRI_CCPRI(v)   BF_CS1(SDMACORE_CCPRI, CCPRI, v)
#endif

/*!
 * @brief HW_SDMACORE_NCPRI - Next Channel Priority
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned NCPRI : 3; //!< Contains the 3-bit priority of the channel the scheduler has selected to run next. It is 0 when no other channel is pending.
        unsigned RESERVED0 : 29; //!< Reserved
    } B;
} hw_sdmacore_ncpri_t;
#endif

/*
 * constants & macros for entire SDMACORE_NCPRI register
 */
#define HW_SDMACORE_NCPRI_ADDR      (REGS_SDMACORE_BASE + 0x7)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_NCPRI           (*(volatile hw_sdmacore_ncpri_t *) HW_SDMACORE_NCPRI_ADDR)
#define HW_SDMACORE_NCPRI_RD()      (HW_SDMACORE_NCPRI.U)
#define HW_SDMACORE_NCPRI_WR(v)     (HW_SDMACORE_NCPRI.U = (v))
#define HW_SDMACORE_NCPRI_SET(v)    (HW_SDMACORE_NCPRI_WR(HW_SDMACORE_NCPRI_RD() |  (v)))
#define HW_SDMACORE_NCPRI_CLR(v)    (HW_SDMACORE_NCPRI_WR(HW_SDMACORE_NCPRI_RD() & ~(v)))
#define HW_SDMACORE_NCPRI_TOG(v)    (HW_SDMACORE_NCPRI_WR(HW_SDMACORE_NCPRI_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_NCPRI bitfields
 */

/* --- Register HW_SDMACORE_NCPRI, field NCPRI
 *
 * Contains the 3-bit priority of the channel the scheduler has selected
 * to run next. It is 0 when no other channel is pending.
 */

#define BP_SDMACORE_NCPRI_NCPRI      0
#define BM_SDMACORE_NCPRI_NCPRI      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_NCPRI_NCPRI(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_NCPRI_NCPRI)
#else
#define BF_SDMACORE_NCPRI_NCPRI(v)   (((v) << 0) & BM_SDMACORE_NCPRI_NCPRI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_NCPRI_NCPRI(v)   BF_CS1(SDMACORE_NCPRI, NCPRI, v)
#endif

/*!
 * @brief HW_SDMACORE_ECOUNT - OnCE Event Cell Counter
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ECOUNT : 16; //!< The event cell counter contains the number of times minus one that an event detection must occur before generating a debug request.   This register should be written before any attempt to use the event detection counter during an event detection process.  The counter is cleared on a JTAG reset.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmacore_ecount_t;
#endif

/*
 * constants & macros for entire SDMACORE_ECOUNT register
 */
#define HW_SDMACORE_ECOUNT_ADDR      (REGS_SDMACORE_BASE + 0x9)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_ECOUNT           (*(volatile hw_sdmacore_ecount_t *) HW_SDMACORE_ECOUNT_ADDR)
#define HW_SDMACORE_ECOUNT_RD()      (HW_SDMACORE_ECOUNT.U)
#define HW_SDMACORE_ECOUNT_WR(v)     (HW_SDMACORE_ECOUNT.U = (v))
#define HW_SDMACORE_ECOUNT_SET(v)    (HW_SDMACORE_ECOUNT_WR(HW_SDMACORE_ECOUNT_RD() |  (v)))
#define HW_SDMACORE_ECOUNT_CLR(v)    (HW_SDMACORE_ECOUNT_WR(HW_SDMACORE_ECOUNT_RD() & ~(v)))
#define HW_SDMACORE_ECOUNT_TOG(v)    (HW_SDMACORE_ECOUNT_WR(HW_SDMACORE_ECOUNT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_ECOUNT bitfields
 */

/* --- Register HW_SDMACORE_ECOUNT, field ECOUNT
 *
 * The event cell counter contains the number of times minus one that an
 * event detection must occur before generating a debug request.   This register should be written
 * before any attempt to use the                                     event detection counter during
 * an event detection process.  The counter is cleared on a JTAG reset.
 */

#define BP_SDMACORE_ECOUNT_ECOUNT      0
#define BM_SDMACORE_ECOUNT_ECOUNT      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECOUNT_ECOUNT(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_ECOUNT_ECOUNT)
#else
#define BF_SDMACORE_ECOUNT_ECOUNT(v)   (((v) << 0) & BM_SDMACORE_ECOUNT_ECOUNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECOUNT_ECOUNT(v)   BF_CS1(SDMACORE_ECOUNT, ECOUNT, v)
#endif

/*!
 * @brief HW_SDMACORE_ECTL - OnCE Event Cell Control Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ATS : 2; //!< The access type select bits define the memory access type required on the SDMA memory bus.
        unsigned AATC : 2; //!< The Address A Trigger Condition (AATC) controls the operations performed by address comparator A. All operations are performed on unsigned values. This comparator A outputs the addressA condition.
        unsigned ABTC : 2; //!< The Address B Trigger Condition (ABTC) controls the operations performed by address comparator B. All operations are performed on unsigned values. This comparator B outputs the addressB condition.
        unsigned ATC : 2; //!< The address trigger condition bits select how the two address conditions (addressA and addressB) are combined to define the global address matching condition. The supported combinations are described, as follows.
        unsigned DTC : 2; //!< The data trigger condition bits define when data is considered matching after comparison with the data register of the event detection unit. The operations are performed on unsigned values.
        unsigned ECTC : 2; //!< The event cell trigger condition bits select the combination of address and data matching conditions that generate the final address/data condition. During program execution, if this event cell trigger condition goes to 1, a debug request is sent to the SDMA. The EN bit must be set to enable the debug request generation.
        unsigned CNT : 1; //!< Event Counter Enable. The event counter enable bit determines if the cell counter is used during the event detection. In order to use the event counter during an event detection process, the event cell counter register should be loaded with a value equal to the number of times minus one that an event occurs before a debug request is sent. After every event detection, the counter is decreased. When the counter reaches the value 0, the event detection cell sends a debug request to the core. The event counter register should be written and the EN bit should be set before each new event detection process uses the event counter.
        unsigned EN : 1; //!< Event Cell Enable. If the EN bit is set, the event cell is allowed to generate debug requests (the cell is awakened). If it is cleared, the event detection unit is disabled and no hardware breakpoint is generated, but matching conditions are still reflected on the emulation pin.
        unsigned RESERVED0 : 18; //!< Reserved
    } B;
} hw_sdmacore_ectl_t;
#endif

/*
 * constants & macros for entire SDMACORE_ECTL register
 */
#define HW_SDMACORE_ECTL_ADDR      (REGS_SDMACORE_BASE + 0xa)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_ECTL           (*(volatile hw_sdmacore_ectl_t *) HW_SDMACORE_ECTL_ADDR)
#define HW_SDMACORE_ECTL_RD()      (HW_SDMACORE_ECTL.U)
#define HW_SDMACORE_ECTL_WR(v)     (HW_SDMACORE_ECTL.U = (v))
#define HW_SDMACORE_ECTL_SET(v)    (HW_SDMACORE_ECTL_WR(HW_SDMACORE_ECTL_RD() |  (v)))
#define HW_SDMACORE_ECTL_CLR(v)    (HW_SDMACORE_ECTL_WR(HW_SDMACORE_ECTL_RD() & ~(v)))
#define HW_SDMACORE_ECTL_TOG(v)    (HW_SDMACORE_ECTL_WR(HW_SDMACORE_ECTL_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_ECTL bitfields
 */

/* --- Register HW_SDMACORE_ECTL, field ATS
 *
 * The access type select bits define the memory access type required on
 * the SDMA memory bus.
 */

#define BP_SDMACORE_ECTL_ATS      0
#define BM_SDMACORE_ECTL_ATS      0x00000003

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ATS(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_ECTL_ATS)
#else
#define BF_SDMACORE_ECTL_ATS(v)   (((v) << 0) & BM_SDMACORE_ECTL_ATS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ATS(v)   BF_CS1(SDMACORE_ECTL, ATS, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field AATC
 *
 * The Address A Trigger Condition (AATC) controls the operations
 * performed by address comparator A. All operations are performed on
 * unsigned values. This comparator A outputs the addressA
 * condition.
 */

#define BP_SDMACORE_ECTL_AATC      2
#define BM_SDMACORE_ECTL_AATC      0x0000000c

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_AATC(v)   ((((reg32_t) v) << 2) & BM_SDMACORE_ECTL_AATC)
#else
#define BF_SDMACORE_ECTL_AATC(v)   (((v) << 2) & BM_SDMACORE_ECTL_AATC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_AATC(v)   BF_CS1(SDMACORE_ECTL, AATC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field ABTC
 *
 * The Address B Trigger Condition (ABTC) controls the operations
 * performed by address comparator B. All operations are performed on
 * unsigned values. This comparator B outputs the addressB
 * condition.
 */

#define BP_SDMACORE_ECTL_ABTC      4
#define BM_SDMACORE_ECTL_ABTC      0x00000030

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ABTC(v)   ((((reg32_t) v) << 4) & BM_SDMACORE_ECTL_ABTC)
#else
#define BF_SDMACORE_ECTL_ABTC(v)   (((v) << 4) & BM_SDMACORE_ECTL_ABTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ABTC(v)   BF_CS1(SDMACORE_ECTL, ABTC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field ATC
 *
 * The address trigger condition bits select how the two address
 * conditions (addressA and addressB) are combined to define the global
 * address matching condition. The supported combinations are
 * described, as follows.
 */

#define BP_SDMACORE_ECTL_ATC      6
#define BM_SDMACORE_ECTL_ATC      0x000000c0

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ATC(v)   ((((reg32_t) v) << 6) & BM_SDMACORE_ECTL_ATC)
#else
#define BF_SDMACORE_ECTL_ATC(v)   (((v) << 6) & BM_SDMACORE_ECTL_ATC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ATC(v)   BF_CS1(SDMACORE_ECTL, ATC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field DTC
 *
 * The data trigger condition bits define when data is considered
 * matching after comparison with the data register of the event
 * detection unit. The operations are performed on unsigned values.
 */

#define BP_SDMACORE_ECTL_DTC      8
#define BM_SDMACORE_ECTL_DTC      0x00000300

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_DTC(v)   ((((reg32_t) v) << 8) & BM_SDMACORE_ECTL_DTC)
#else
#define BF_SDMACORE_ECTL_DTC(v)   (((v) << 8) & BM_SDMACORE_ECTL_DTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_DTC(v)   BF_CS1(SDMACORE_ECTL, DTC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field ECTC
 *
 * The event cell trigger condition bits select the combination of
 * address and data matching conditions that generate the final
 * address/data condition. During program execution, if this event cell
 * trigger condition goes to 1, a debug request is sent to the SDMA.
 * The EN bit must be set to enable the debug request generation.
 */

#define BP_SDMACORE_ECTL_ECTC      10
#define BM_SDMACORE_ECTL_ECTC      0x00000c00

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_ECTC(v)   ((((reg32_t) v) << 10) & BM_SDMACORE_ECTL_ECTC)
#else
#define BF_SDMACORE_ECTL_ECTC(v)   (((v) << 10) & BM_SDMACORE_ECTL_ECTC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_ECTC(v)   BF_CS1(SDMACORE_ECTL, ECTC, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field CNT
 *
 * Event Counter Enable. The event counter enable bit determines if the
 * cell counter is used during the event detection. In order to use the
 * event counter during an event detection process, the event cell
 * counter register should be loaded with a value equal to the number
 * of times minus one that an event occurs before a debug request is
 * sent. After every event detection, the counter is decreased. When
 * the counter reaches the value 0, the event detection cell sends a
 * debug request to the core. The event counter register should be
 * written and the EN bit should be set before each new event detection
 * process uses the event counter.
 */

#define BP_SDMACORE_ECTL_CNT      12
#define BM_SDMACORE_ECTL_CNT      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_CNT(v)   ((((reg32_t) v) << 12) & BM_SDMACORE_ECTL_CNT)
#else
#define BF_SDMACORE_ECTL_CNT(v)   (((v) << 12) & BM_SDMACORE_ECTL_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_CNT(v)   BF_CS1(SDMACORE_ECTL, CNT, v)
#endif

/* --- Register HW_SDMACORE_ECTL, field EN
 *
 * Event Cell Enable. If the EN bit is set, the event cell is allowed to
 * generate debug requests (the cell is awakened). If it is cleared,
 * the event detection unit is disabled and no hardware breakpoint is
 * generated, but matching conditions are still reflected on the
 * emulation pin.
 */

#define BP_SDMACORE_ECTL_EN      13
#define BM_SDMACORE_ECTL_EN      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ECTL_EN(v)   ((((reg32_t) v) << 13) & BM_SDMACORE_ECTL_EN)
#else
#define BF_SDMACORE_ECTL_EN(v)   (((v) << 13) & BM_SDMACORE_ECTL_EN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ECTL_EN(v)   BF_CS1(SDMACORE_ECTL, EN, v)
#endif

/*!
 * @brief HW_SDMACORE_EAA - OnCE Event Address Register A
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EAA : 16; //!< Event Cell Address Register A computes an address A condition. It is cleared on a JTAG reset.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmacore_eaa_t;
#endif

/*
 * constants & macros for entire SDMACORE_EAA register
 */
#define HW_SDMACORE_EAA_ADDR      (REGS_SDMACORE_BASE + 0xb)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EAA           (*(volatile hw_sdmacore_eaa_t *) HW_SDMACORE_EAA_ADDR)
#define HW_SDMACORE_EAA_RD()      (HW_SDMACORE_EAA.U)
#define HW_SDMACORE_EAA_WR(v)     (HW_SDMACORE_EAA.U = (v))
#define HW_SDMACORE_EAA_SET(v)    (HW_SDMACORE_EAA_WR(HW_SDMACORE_EAA_RD() |  (v)))
#define HW_SDMACORE_EAA_CLR(v)    (HW_SDMACORE_EAA_WR(HW_SDMACORE_EAA_RD() & ~(v)))
#define HW_SDMACORE_EAA_TOG(v)    (HW_SDMACORE_EAA_WR(HW_SDMACORE_EAA_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EAA bitfields
 */

/* --- Register HW_SDMACORE_EAA, field EAA
 *
 * Event Cell Address Register A computes an address A condition. It is
 * cleared on a JTAG reset.
 */

#define BP_SDMACORE_EAA_EAA      0
#define BM_SDMACORE_EAA_EAA      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EAA_EAA(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EAA_EAA)
#else
#define BF_SDMACORE_EAA_EAA(v)   (((v) << 0) & BM_SDMACORE_EAA_EAA)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EAA_EAA(v)   BF_CS1(SDMACORE_EAA, EAA, v)
#endif

/*!
 * @brief HW_SDMACORE_EAB - OnCE Event Cell Address Register B
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EAB : 16; //!< Event Cell Address Register B computes an address B condition. It is cleared on a JTAG reset.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmacore_eab_t;
#endif

/*
 * constants & macros for entire SDMACORE_EAB register
 */
#define HW_SDMACORE_EAB_ADDR      (REGS_SDMACORE_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EAB           (*(volatile hw_sdmacore_eab_t *) HW_SDMACORE_EAB_ADDR)
#define HW_SDMACORE_EAB_RD()      (HW_SDMACORE_EAB.U)
#define HW_SDMACORE_EAB_WR(v)     (HW_SDMACORE_EAB.U = (v))
#define HW_SDMACORE_EAB_SET(v)    (HW_SDMACORE_EAB_WR(HW_SDMACORE_EAB_RD() |  (v)))
#define HW_SDMACORE_EAB_CLR(v)    (HW_SDMACORE_EAB_WR(HW_SDMACORE_EAB_RD() & ~(v)))
#define HW_SDMACORE_EAB_TOG(v)    (HW_SDMACORE_EAB_WR(HW_SDMACORE_EAB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EAB bitfields
 */

/* --- Register HW_SDMACORE_EAB, field EAB
 *
 * Event Cell Address Register B computes an address B condition. It is
 * cleared on a JTAG reset.
 */

#define BP_SDMACORE_EAB_EAB      0
#define BM_SDMACORE_EAB_EAB      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EAB_EAB(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EAB_EAB)
#else
#define BF_SDMACORE_EAB_EAB(v)   (((v) << 0) & BM_SDMACORE_EAB_EAB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EAB_EAB(v)   BF_CS1(SDMACORE_EAB, EAB, v)
#endif

/*!
 * @brief HW_SDMACORE_EAM - OnCE Event Cell Address Mask
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EAM : 16; //!< The Event Cell Address Mask contains a user-defined address mask value. This mask is applied to the address value latched from the memory address bus before performing the address comparison.  There is a common address mask value for both address comparators. If bit i of this register is set, then bit i of the address value latched from the memory bus does not influence the result of the address comparison. The register is cleared on a JTAG reset.
        unsigned RESERVED0 : 16; //!< Reserved
    } B;
} hw_sdmacore_eam_t;
#endif

/*
 * constants & macros for entire SDMACORE_EAM register
 */
#define HW_SDMACORE_EAM_ADDR      (REGS_SDMACORE_BASE + 0xd)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EAM           (*(volatile hw_sdmacore_eam_t *) HW_SDMACORE_EAM_ADDR)
#define HW_SDMACORE_EAM_RD()      (HW_SDMACORE_EAM.U)
#define HW_SDMACORE_EAM_WR(v)     (HW_SDMACORE_EAM.U = (v))
#define HW_SDMACORE_EAM_SET(v)    (HW_SDMACORE_EAM_WR(HW_SDMACORE_EAM_RD() |  (v)))
#define HW_SDMACORE_EAM_CLR(v)    (HW_SDMACORE_EAM_WR(HW_SDMACORE_EAM_RD() & ~(v)))
#define HW_SDMACORE_EAM_TOG(v)    (HW_SDMACORE_EAM_WR(HW_SDMACORE_EAM_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EAM bitfields
 */

/* --- Register HW_SDMACORE_EAM, field EAM
 *
 * The Event Cell Address Mask contains a user-defined address mask
 * value. This mask is applied to the address value latched from the
 * memory address bus before performing the address comparison.  There is a common address mask
 * value for both address comparators.                                 If bit i of this register is
 * set, then bit i of the                                 address value latched from the memory bus
 * does not influence the                                 result of the address comparison. The
 * register is cleared on a JTAG                                 reset.
 */

#define BP_SDMACORE_EAM_EAM      0
#define BM_SDMACORE_EAM_EAM      0x0000ffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EAM_EAM(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EAM_EAM)
#else
#define BF_SDMACORE_EAM_EAM(v)   (((v) << 0) & BM_SDMACORE_EAM_EAM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EAM_EAM(v)   BF_CS1(SDMACORE_EAM, EAM, v)
#endif

/*!
 * @brief HW_SDMACORE_ED - OnCE Event Cell Data Register
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ED : 32; //!< The event cell data register contains a user defined data value. This data value is an input for the data comparator which generates the data condition. It is cleared on a JTAG reset.
    } B;
} hw_sdmacore_ed_t;
#endif

/*
 * constants & macros for entire SDMACORE_ED register
 */
#define HW_SDMACORE_ED_ADDR      (REGS_SDMACORE_BASE + 0xe)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_ED           (*(volatile hw_sdmacore_ed_t *) HW_SDMACORE_ED_ADDR)
#define HW_SDMACORE_ED_RD()      (HW_SDMACORE_ED.U)
#define HW_SDMACORE_ED_WR(v)     (HW_SDMACORE_ED.U = (v))
#define HW_SDMACORE_ED_SET(v)    (HW_SDMACORE_ED_WR(HW_SDMACORE_ED_RD() |  (v)))
#define HW_SDMACORE_ED_CLR(v)    (HW_SDMACORE_ED_WR(HW_SDMACORE_ED_RD() & ~(v)))
#define HW_SDMACORE_ED_TOG(v)    (HW_SDMACORE_ED_WR(HW_SDMACORE_ED_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_ED bitfields
 */

/* --- Register HW_SDMACORE_ED, field ED
 *
 * The event cell data register contains a user defined data value. This
 * data value is an input for the data comparator which generates the
 * data condition. It is cleared on a JTAG reset.
 */

#define BP_SDMACORE_ED_ED      0
#define BM_SDMACORE_ED_ED      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_ED_ED(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_ED_ED)
#else
#define BF_SDMACORE_ED_ED(v)   (((v) << 0) & BM_SDMACORE_ED_ED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_ED_ED(v)   BF_CS1(SDMACORE_ED, ED, v)
#endif

/*!
 * @brief HW_SDMACORE_EDM - OnCE Event Cell Data Mask
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EDM : 32; //!< The event cell data mask register contains the user-defined data mask value.   This mask is applied to the data value latched from the memory bus before performing the data comparison.  Setting bit i of the event cell data mask register means that bit i of the data value latched from the address bus does not influence the result of the data comparison.  The data mask is cleared on a JTAG reset.
    } B;
} hw_sdmacore_edm_t;
#endif

/*
 * constants & macros for entire SDMACORE_EDM register
 */
#define HW_SDMACORE_EDM_ADDR      (REGS_SDMACORE_BASE + 0xf)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_EDM           (*(volatile hw_sdmacore_edm_t *) HW_SDMACORE_EDM_ADDR)
#define HW_SDMACORE_EDM_RD()      (HW_SDMACORE_EDM.U)
#define HW_SDMACORE_EDM_WR(v)     (HW_SDMACORE_EDM.U = (v))
#define HW_SDMACORE_EDM_SET(v)    (HW_SDMACORE_EDM_WR(HW_SDMACORE_EDM_RD() |  (v)))
#define HW_SDMACORE_EDM_CLR(v)    (HW_SDMACORE_EDM_WR(HW_SDMACORE_EDM_RD() & ~(v)))
#define HW_SDMACORE_EDM_TOG(v)    (HW_SDMACORE_EDM_WR(HW_SDMACORE_EDM_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_EDM bitfields
 */

/* --- Register HW_SDMACORE_EDM, field EDM
 *
 * The event cell data mask register contains the user-defined data mask
 * value.   This mask is applied to the data value latched from the memory
 * bus before performing the data comparison.  Setting bit i of the event cell data mask register
 * means                                     that bit i of the data value latched from the address
 * bus                                     does not influence the result of the data comparison.
 * The data mask is cleared on a JTAG reset.
 */

#define BP_SDMACORE_EDM_EDM      0
#define BM_SDMACORE_EDM_EDM      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_EDM_EDM(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_EDM_EDM)
#else
#define BF_SDMACORE_EDM_EDM(v)   (((v) << 0) & BM_SDMACORE_EDM_EDM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_EDM_EDM(v)   BF_CS1(SDMACORE_EDM, EDM, v)
#endif

/*!
 * @brief HW_SDMACORE_RTB - OnCE Real-Time Buffer
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RTB : 32; //!< The Real Time Buffer register stores and retrieves run time information without putting the SDMA in debug mode. Writing to that register triggers a pulse on a specific real-time debug pin whose connection depends on the chip implementation.  The RTB value can be accessed by the OnCE under ARM platform or JTAG control using the rbuffer command.
    } B;
} hw_sdmacore_rtb_t;
#endif

/*
 * constants & macros for entire SDMACORE_RTB register
 */
#define HW_SDMACORE_RTB_ADDR      (REGS_SDMACORE_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_RTB           (*(volatile hw_sdmacore_rtb_t *) HW_SDMACORE_RTB_ADDR)
#define HW_SDMACORE_RTB_RD()      (HW_SDMACORE_RTB.U)
#define HW_SDMACORE_RTB_WR(v)     (HW_SDMACORE_RTB.U = (v))
#define HW_SDMACORE_RTB_SET(v)    (HW_SDMACORE_RTB_WR(HW_SDMACORE_RTB_RD() |  (v)))
#define HW_SDMACORE_RTB_CLR(v)    (HW_SDMACORE_RTB_WR(HW_SDMACORE_RTB_RD() & ~(v)))
#define HW_SDMACORE_RTB_TOG(v)    (HW_SDMACORE_RTB_WR(HW_SDMACORE_RTB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_RTB bitfields
 */

/* --- Register HW_SDMACORE_RTB, field RTB
 *
 * The Real Time Buffer register stores and retrieves run time
 * information without putting the SDMA in debug mode. Writing to that
 * register triggers a pulse on a specific real-time debug pin whose
 * connection depends on the chip implementation.  The RTB value can be accessed by the OnCE under
 * ARM platform or JTAG                                 control using the rbuffer command.
 */

#define BP_SDMACORE_RTB_RTB      0
#define BM_SDMACORE_RTB_RTB      0xffffffff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_RTB_RTB(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_RTB_RTB)
#else
#define BF_SDMACORE_RTB_RTB(v)   (((v) << 0) & BM_SDMACORE_RTB_RTB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_RTB_RTB(v)   BF_CS1(SDMACORE_RTB, RTB, v)
#endif

/*!
 * @brief HW_SDMACORE_TB - OnCE Trace Buffer
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHFADDR : 14; //!< The change of flow address is the address where the change of flow is taken when executing a change of flow instruction.
        unsigned TADDR : 14; //!< The target address is the address taken after the execution of the change of flow instruction.
        unsigned TBF : 1; //!< The Trace Buffer Flag is set when the buffer contains the addresses of a valid change of flow. The contents of the buffer should be ignored otherwise.
        unsigned RESERVED0 : 3; //!< Reserved
    } B;
} hw_sdmacore_tb_t;
#endif

/*
 * constants & macros for entire SDMACORE_TB register
 */
#define HW_SDMACORE_TB_ADDR      (REGS_SDMACORE_BASE + 0x19)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_TB           (*(volatile hw_sdmacore_tb_t *) HW_SDMACORE_TB_ADDR)
#define HW_SDMACORE_TB_RD()      (HW_SDMACORE_TB.U)
#define HW_SDMACORE_TB_WR(v)     (HW_SDMACORE_TB.U = (v))
#define HW_SDMACORE_TB_SET(v)    (HW_SDMACORE_TB_WR(HW_SDMACORE_TB_RD() |  (v)))
#define HW_SDMACORE_TB_CLR(v)    (HW_SDMACORE_TB_WR(HW_SDMACORE_TB_RD() & ~(v)))
#define HW_SDMACORE_TB_TOG(v)    (HW_SDMACORE_TB_WR(HW_SDMACORE_TB_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_TB bitfields
 */

/* --- Register HW_SDMACORE_TB, field CHFADDR
 *
 * The change of flow address is the address where the change of flow is
 * taken when executing a change of flow instruction.
 */

#define BP_SDMACORE_TB_CHFADDR      0
#define BM_SDMACORE_TB_CHFADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_TB_CHFADDR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_TB_CHFADDR)
#else
#define BF_SDMACORE_TB_CHFADDR(v)   (((v) << 0) & BM_SDMACORE_TB_CHFADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_TB_CHFADDR(v)   BF_CS1(SDMACORE_TB, CHFADDR, v)
#endif

/* --- Register HW_SDMACORE_TB, field TADDR
 *
 * The target address is the address taken after the execution of the
 * change of flow instruction.
 */

#define BP_SDMACORE_TB_TADDR      14
#define BM_SDMACORE_TB_TADDR      0x0fffc000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_TB_TADDR(v)   ((((reg32_t) v) << 14) & BM_SDMACORE_TB_TADDR)
#else
#define BF_SDMACORE_TB_TADDR(v)   (((v) << 14) & BM_SDMACORE_TB_TADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_TB_TADDR(v)   BF_CS1(SDMACORE_TB, TADDR, v)
#endif

/* --- Register HW_SDMACORE_TB, field TBF
 *
 * The Trace Buffer Flag is set when the buffer contains the addresses
 * of a valid change of flow. The contents of the buffer should be
 * ignored otherwise.
 */

#define BP_SDMACORE_TB_TBF      28
#define BM_SDMACORE_TB_TBF      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_TB_TBF(v)   ((((reg32_t) v) << 28) & BM_SDMACORE_TB_TBF)
#else
#define BF_SDMACORE_TB_TBF(v)   (((v) << 28) & BM_SDMACORE_TB_TBF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_TB_TBF(v)   BF_CS1(SDMACORE_TB, TBF, v)
#endif

/*!
 * @brief HW_SDMACORE_OSTAT - OnCE Status
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned ECDR : 3; //!< Event Cell Debug Request. If the debug request comes from the event cell, the reason for entering debug mode is given by the EDR bits. The encoding of the EDR bits is useful to find out more precisely why the debug request was generated. A debug request from an event cell is generated for a specific combination of the addressA, addressB, and data conditions; the value of those fields is given by the EDR bits. If all three bits of the EDR are reset, then it did not generate any debug request. If the cell did generate a debug request, then at least one EDR bit is set; the meaning of the encoding is as follows:
        unsigned RESERVED0 : 4; //!< Reserved
        unsigned MST : 1; //!< This flag is raised when the OnCE is controlled from the ARM platform peripheral interface.
        unsigned SWB : 1; //!< This flag is raised when the SDMA has entered debug mode after a software breakpoint.
        unsigned ODR : 1; //!< This flag is raised when the SDMA has entered debug mode after a OnCE debug request.
        unsigned EDR : 1; //!< This flag is raised when the SDMA has entered debug mode after an external debug request.
        unsigned RCV : 1; //!< After each write access to the real time buffer (RTB), the RCV bit is set. This bit is cleared after execution of an rbuffer command and on a JTAG reset.
        unsigned PST : 4; //!< The Processor Status bits reflect the state of the SDMA RISC engine.   The "Program" state is the usual instruction execution cycle.  The "Data" state is inserted when there are wait-states during a load or a store on the data bus (ld or st).  The "Change of Flow" state is the second cycle of any instruction that breaks the sequence of instructions (jumps and channel-switching instructions).  The "Change of Flow in Loop" state is used when an error causes a hardware loop exit.  The "Debug" state means the SDMA is in debug mode.  The "Functional Unit" state is inserted when there are wait-states during a load or a store on the functional units bus (ldf or stf).  In "Sleep" modes, no script is running (this is the RISC engine idle state). The "after Reset" is slightly different because no context restoring phase will happen when a channel is triggered: The script located at address 0 will be executed (boot operation).  The "in Sleep" states are the same as above except they do not have any corresponding channel. They are used when entering debug mode after reset; the reason is that it is necessary to return to the "Sleep after Reset" state when leaving debug mode.
        unsigned RESERVED1 : 16; //!< Reserved
    } B;
} hw_sdmacore_ostat_t;
#endif

/*
 * constants & macros for entire SDMACORE_OSTAT register
 */
#define HW_SDMACORE_OSTAT_ADDR      (REGS_SDMACORE_BASE + 0x1a)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_OSTAT           (*(volatile hw_sdmacore_ostat_t *) HW_SDMACORE_OSTAT_ADDR)
#define HW_SDMACORE_OSTAT_RD()      (HW_SDMACORE_OSTAT.U)
#define HW_SDMACORE_OSTAT_WR(v)     (HW_SDMACORE_OSTAT.U = (v))
#define HW_SDMACORE_OSTAT_SET(v)    (HW_SDMACORE_OSTAT_WR(HW_SDMACORE_OSTAT_RD() |  (v)))
#define HW_SDMACORE_OSTAT_CLR(v)    (HW_SDMACORE_OSTAT_WR(HW_SDMACORE_OSTAT_RD() & ~(v)))
#define HW_SDMACORE_OSTAT_TOG(v)    (HW_SDMACORE_OSTAT_WR(HW_SDMACORE_OSTAT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_OSTAT bitfields
 */

/* --- Register HW_SDMACORE_OSTAT, field ECDR
 *
 * Event Cell Debug Request. If the debug request comes from the event
 * cell, the reason for entering debug mode is given by the EDR bits.
 * The encoding of the EDR bits is useful to find out more precisely
 * why the debug request was generated. A debug request from an event
 * cell is generated for a specific combination of the addressA,
 * addressB, and data conditions; the value of those fields is given by
 * the EDR bits. If all three bits of the EDR are reset, then it did
 * not generate any debug request. If the cell did generate a debug
 * request, then at least one EDR bit is set; the meaning of the
 * encoding is as follows:
 */

#define BP_SDMACORE_OSTAT_ECDR      0
#define BM_SDMACORE_OSTAT_ECDR      0x00000007

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_ECDR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_OSTAT_ECDR)
#else
#define BF_SDMACORE_OSTAT_ECDR(v)   (((v) << 0) & BM_SDMACORE_OSTAT_ECDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_ECDR(v)   BF_CS1(SDMACORE_OSTAT, ECDR, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field MST
 *
 * This flag is raised when the OnCE is controlled from the ARM platform
 * peripheral interface.
 */

#define BP_SDMACORE_OSTAT_MST      7
#define BM_SDMACORE_OSTAT_MST      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_MST(v)   ((((reg32_t) v) << 7) & BM_SDMACORE_OSTAT_MST)
#else
#define BF_SDMACORE_OSTAT_MST(v)   (((v) << 7) & BM_SDMACORE_OSTAT_MST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_MST(v)   BF_CS1(SDMACORE_OSTAT, MST, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field SWB
 *
 * This flag is raised when the SDMA has entered debug mode after a
 * software breakpoint.
 */

#define BP_SDMACORE_OSTAT_SWB      8
#define BM_SDMACORE_OSTAT_SWB      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_SWB(v)   ((((reg32_t) v) << 8) & BM_SDMACORE_OSTAT_SWB)
#else
#define BF_SDMACORE_OSTAT_SWB(v)   (((v) << 8) & BM_SDMACORE_OSTAT_SWB)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_SWB(v)   BF_CS1(SDMACORE_OSTAT, SWB, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field ODR
 *
 * This flag is raised when the SDMA has entered debug mode after a OnCE
 * debug request.
 */

#define BP_SDMACORE_OSTAT_ODR      9
#define BM_SDMACORE_OSTAT_ODR      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_ODR(v)   ((((reg32_t) v) << 9) & BM_SDMACORE_OSTAT_ODR)
#else
#define BF_SDMACORE_OSTAT_ODR(v)   (((v) << 9) & BM_SDMACORE_OSTAT_ODR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_ODR(v)   BF_CS1(SDMACORE_OSTAT, ODR, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field EDR
 *
 * This flag is raised when the SDMA has entered debug mode after an
 * external debug request.
 */

#define BP_SDMACORE_OSTAT_EDR      10
#define BM_SDMACORE_OSTAT_EDR      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_EDR(v)   ((((reg32_t) v) << 10) & BM_SDMACORE_OSTAT_EDR)
#else
#define BF_SDMACORE_OSTAT_EDR(v)   (((v) << 10) & BM_SDMACORE_OSTAT_EDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_EDR(v)   BF_CS1(SDMACORE_OSTAT, EDR, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field RCV
 *
 * After each write access to the real time buffer (RTB), the RCV bit is
 * set. This bit is cleared after execution of an rbuffer command and on a JTAG reset.
 */

#define BP_SDMACORE_OSTAT_RCV      11
#define BM_SDMACORE_OSTAT_RCV      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_RCV(v)   ((((reg32_t) v) << 11) & BM_SDMACORE_OSTAT_RCV)
#else
#define BF_SDMACORE_OSTAT_RCV(v)   (((v) << 11) & BM_SDMACORE_OSTAT_RCV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_RCV(v)   BF_CS1(SDMACORE_OSTAT, RCV, v)
#endif

/* --- Register HW_SDMACORE_OSTAT, field PST
 *
 * The Processor Status bits reflect the state of the SDMA RISC
 * engine.   The "Program" state is the usual instruction execution cycle.  The "Data" state is
 * inserted when there are wait-states during a                                     load or a store
 * on the data bus (ld or st).  The "Change of Flow" state is the second cycle of any
 * instruction that breaks the sequence of instructions (jumps and
 * channel-switching instructions).  The "Change of Flow in Loop" state is used when an error causes
 * a hardware loop exit.  The "Debug" state means the SDMA is in debug mode.  The "Functional Unit"
 * state is inserted when there are                                     wait-states during a load or
 * a store on the functional units bus                                     (ldf or stf).  In "Sleep"
 * modes, no script is running (this is the RISC engine                                     idle
 * state). The "after Reset" is slightly different because no
 * context restoring phase will happen when a channel is triggered:
 * The script located at address 0 will be executed (boot
 * operation).  The "in Sleep" states are the same as above except they do not
 * have any corresponding channel. They are used when entering
 * debug mode after reset; the reason is that it is necessary to
 * return to the "Sleep after Reset" state when leaving debug mode.
 */

#define BP_SDMACORE_OSTAT_PST      12
#define BM_SDMACORE_OSTAT_PST      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_OSTAT_PST(v)   ((((reg32_t) v) << 12) & BM_SDMACORE_OSTAT_PST)
#else
#define BF_SDMACORE_OSTAT_PST(v)   (((v) << 12) & BM_SDMACORE_OSTAT_PST)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_OSTAT_PST(v)   BF_CS1(SDMACORE_OSTAT, PST, v)
#endif

/*!
 * @brief HW_SDMACORE_MCHN0ADDR - Channel 0 Boot Address
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned CHN0ADDR : 14; //!< Contains the address of the channel 0 routine programmed by the ARM platform; it is loaded into a general register at the very start of the boot and the SDMA jumps to the address it contains. By default, it points to the standard boot routine in ROM.
        unsigned SMSZ : 1; //!< The bit 14 (Scratch Memory Size) determines if scratch memory must be available after every channel context. After reset, it is equal to 0, which defines a RAM space of 24 words for each channel. All of this area stores the channel context. By setting this bit, 32 words are reserved for every channel context, which gives eight additional words that can be used by the channel script to store any type of data. Those words are never erased by the context switching mechanism.
        unsigned RESERVED0 : 17; //!< Reserved
    } B;
} hw_sdmacore_mchn0addr_t;
#endif

/*
 * constants & macros for entire SDMACORE_MCHN0ADDR register
 */
#define HW_SDMACORE_MCHN0ADDR_ADDR      (REGS_SDMACORE_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_SDMACORE_MCHN0ADDR           (*(volatile hw_sdmacore_mchn0addr_t *) HW_SDMACORE_MCHN0ADDR_ADDR)
#define HW_SDMACORE_MCHN0ADDR_RD()      (HW_SDMACORE_MCHN0ADDR.U)
#define HW_SDMACORE_MCHN0ADDR_WR(v)     (HW_SDMACORE_MCHN0ADDR.U = (v))
#define HW_SDMACORE_MCHN0ADDR_SET(v)    (HW_SDMACORE_MCHN0ADDR_WR(HW_SDMACORE_MCHN0ADDR_RD() |  (v)))
#define HW_SDMACORE_MCHN0ADDR_CLR(v)    (HW_SDMACORE_MCHN0ADDR_WR(HW_SDMACORE_MCHN0ADDR_RD() & ~(v)))
#define HW_SDMACORE_MCHN0ADDR_TOG(v)    (HW_SDMACORE_MCHN0ADDR_WR(HW_SDMACORE_MCHN0ADDR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual SDMACORE_MCHN0ADDR bitfields
 */

/* --- Register HW_SDMACORE_MCHN0ADDR, field CHN0ADDR
 *
 * Contains the address of the channel 0 routine programmed by the ARM
 * platform; it is loaded into a general register at the very start of
 * the boot and the SDMA jumps to the address it contains. By default,
 * it points to the standard boot routine in ROM.
 */

#define BP_SDMACORE_MCHN0ADDR_CHN0ADDR      0
#define BM_SDMACORE_MCHN0ADDR_CHN0ADDR      0x00003fff

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MCHN0ADDR_CHN0ADDR(v)   ((((reg32_t) v) << 0) & BM_SDMACORE_MCHN0ADDR_CHN0ADDR)
#else
#define BF_SDMACORE_MCHN0ADDR_CHN0ADDR(v)   (((v) << 0) & BM_SDMACORE_MCHN0ADDR_CHN0ADDR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MCHN0ADDR_CHN0ADDR(v)   BF_CS1(SDMACORE_MCHN0ADDR, CHN0ADDR, v)
#endif

/* --- Register HW_SDMACORE_MCHN0ADDR, field SMSZ
 *
 * The bit 14 (Scratch Memory Size) determines if scratch memory must be
 * available after every channel context. After reset, it is equal to
 * 0, which defines a RAM space of 24 words for each channel. All of
 * this area stores the channel context. By setting this bit, 32 words
 * are reserved for every channel context, which gives eight additional
 * words that can be used by the channel script to store any type of
 * data. Those words are never erased by the context switching
 * mechanism.
 */

#define BP_SDMACORE_MCHN0ADDR_SMSZ      14
#define BM_SDMACORE_MCHN0ADDR_SMSZ      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_SDMACORE_MCHN0ADDR_SMSZ(v)   ((((reg32_t) v) << 14) & BM_SDMACORE_MCHN0ADDR_SMSZ)
#else
#define BF_SDMACORE_MCHN0ADDR_SMSZ(v)   (((v) << 14) & BM_SDMACORE_MCHN0ADDR_SMSZ)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_SDMACORE_MCHN0ADDR_SMSZ(v)   BF_CS1(SDMACORE_MCHN0ADDR, SMSZ, v)
#endif



/*!
 * @brief All SDMACORE module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_sdmacore_mc0ptr_t MC0PTR; //!< ARM platform Channel 0 Pointer
    volatile hw_sdmacore_ccptr_t CCPTR; //!< Current Channel Pointer
    volatile hw_sdmacore_ccr_t CCR; //!< Current Channel Register
    volatile hw_sdmacore_ncr_t NCR; //!< Highest Pending Channel Register
    volatile hw_sdmacore_events_t EVENTS; //!< External DMA Requests Mirror
    volatile hw_sdmacore_ccpri_t CCPRI; //!< Current Channel Priority
    volatile hw_sdmacore_ncpri_t NCPRI; //!< Next Channel Priority
    volatile hw_sdmacore_ecount_t ECOUNT; //!< OnCE Event Cell Counter
    volatile hw_sdmacore_ectl_t ECTL; //!< OnCE Event Cell Control Register
    volatile hw_sdmacore_eaa_t EAA; //!< OnCE Event Address Register A
    volatile hw_sdmacore_eab_t EAB; //!< OnCE Event Cell Address Register B
    volatile hw_sdmacore_eam_t EAM; //!< OnCE Event Cell Address Mask
    volatile hw_sdmacore_ed_t ED; //!< OnCE Event Cell Data Register
    volatile hw_sdmacore_edm_t EDM; //!< OnCE Event Cell Data Mask
    volatile hw_sdmacore_rtb_t RTB; //!< OnCE Real-Time Buffer
    volatile hw_sdmacore_tb_t TB; //!< OnCE Trace Buffer
    volatile hw_sdmacore_ostat_t OSTAT; //!< OnCE Status
    volatile hw_sdmacore_mchn0addr_t MCHN0ADDR; //!< Channel 0 Boot Address
} hw_sdmacore_t
#endif

//! @brief Macro to access all SDMACORE registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_SDMACORE(0)</code>.
#define HW_SDMACORE     (*(volatile hw_sdmacore_t *) REGS_SDMACORE_BASE)


#endif // _SDMACORE_H
