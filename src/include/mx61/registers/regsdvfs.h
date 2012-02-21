/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

#ifndef _DVFSC_H
#define _DVFSC_H

#include "regs.h"

#ifndef REGS_DVFSC_BASE
#define REGS_DVFSC_BASE (REGS_BASE + 0x020dc000)
#endif


/*!
 * @brief HW_DVFSC_THRS - DVFSC Thresholds
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned PNCTHR : 6; //!< Panic threshold for load tracking
        unsigned RESERVED0 : 10; //!< Reserved
        unsigned DWTHR : 6; //!< Down threshold for load tracking
        unsigned UPTHR : 6; //!< Upper threshold for load tracking
        unsigned RESERVED1 : 4; //!< Reserved
    } B;
} hw_dvfsc_thrs_t;
#endif

/*
 * constants & macros for entire DVFSC_THRS register
 */
#define HW_DVFSC_THRS_ADDR      (REGS_DVFSC_BASE + 0x0)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_THRS           (*(volatile hw_dvfsc_thrs_t *) HW_DVFSC_THRS_ADDR)
#define HW_DVFSC_THRS_RD()      (HW_DVFSC_THRS.U)
#define HW_DVFSC_THRS_WR(v)     (HW_DVFSC_THRS.U = (v))
#define HW_DVFSC_THRS_SET(v)    (HW_DVFSC_THRS_WR(HW_DVFSC_THRS_RD() |  (v)))
#define HW_DVFSC_THRS_CLR(v)    (HW_DVFSC_THRS_WR(HW_DVFSC_THRS_RD() & ~(v)))
#define HW_DVFSC_THRS_TOG(v)    (HW_DVFSC_THRS_WR(HW_DVFSC_THRS_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_THRS bitfields
 */

/* --- Register HW_DVFSC_THRS, field PNCTHR
 *
 * Panic threshold for load tracking
 */

#define BP_DVFSC_THRS_PNCTHR      0
#define BM_DVFSC_THRS_PNCTHR      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_THRS_PNCTHR(v)   ((((reg32_t) v) << 0) & BM_DVFSC_THRS_PNCTHR)
#else
#define BF_DVFSC_THRS_PNCTHR(v)   (((v) << 0) & BM_DVFSC_THRS_PNCTHR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_THRS_PNCTHR(v)   BF_CS1(DVFSC_THRS, PNCTHR, v)
#endif

/* --- Register HW_DVFSC_THRS, field DWTHR
 *
 * Down threshold for load tracking
 */

#define BP_DVFSC_THRS_DWTHR      16
#define BM_DVFSC_THRS_DWTHR      0x003f0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_THRS_DWTHR(v)   ((((reg32_t) v) << 16) & BM_DVFSC_THRS_DWTHR)
#else
#define BF_DVFSC_THRS_DWTHR(v)   (((v) << 16) & BM_DVFSC_THRS_DWTHR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_THRS_DWTHR(v)   BF_CS1(DVFSC_THRS, DWTHR, v)
#endif

/* --- Register HW_DVFSC_THRS, field UPTHR
 *
 * Upper threshold for load tracking
 */

#define BP_DVFSC_THRS_UPTHR      22
#define BM_DVFSC_THRS_UPTHR      0x0fc00000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_THRS_UPTHR(v)   ((((reg32_t) v) << 22) & BM_DVFSC_THRS_UPTHR)
#else
#define BF_DVFSC_THRS_UPTHR(v)   (((v) << 22) & BM_DVFSC_THRS_UPTHR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_THRS_UPTHR(v)   BF_CS1(DVFSC_THRS, UPTHR, v)
#endif

/*!
 * @brief HW_DVFSC_COUN - DVFSC Counters thresholds
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned UPCNT : 8; //!< UP counter threshold value
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned DN_CNT : 8; //!< Down counter threshold value
        unsigned RESERVED1 : 8; //!< Reserved
    } B;
} hw_dvfsc_coun_t;
#endif

/*
 * constants & macros for entire DVFSC_COUN register
 */
#define HW_DVFSC_COUN_ADDR      (REGS_DVFSC_BASE + 0x4)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_COUN           (*(volatile hw_dvfsc_coun_t *) HW_DVFSC_COUN_ADDR)
#define HW_DVFSC_COUN_RD()      (HW_DVFSC_COUN.U)
#define HW_DVFSC_COUN_WR(v)     (HW_DVFSC_COUN.U = (v))
#define HW_DVFSC_COUN_SET(v)    (HW_DVFSC_COUN_WR(HW_DVFSC_COUN_RD() |  (v)))
#define HW_DVFSC_COUN_CLR(v)    (HW_DVFSC_COUN_WR(HW_DVFSC_COUN_RD() & ~(v)))
#define HW_DVFSC_COUN_TOG(v)    (HW_DVFSC_COUN_WR(HW_DVFSC_COUN_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_COUN bitfields
 */

/* --- Register HW_DVFSC_COUN, field UPCNT
 *
 * UP counter threshold value
 */

#define BP_DVFSC_COUN_UPCNT      0
#define BM_DVFSC_COUN_UPCNT      0x000000ff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_COUN_UPCNT(v)   ((((reg32_t) v) << 0) & BM_DVFSC_COUN_UPCNT)
#else
#define BF_DVFSC_COUN_UPCNT(v)   (((v) << 0) & BM_DVFSC_COUN_UPCNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_COUN_UPCNT(v)   BF_CS1(DVFSC_COUN, UPCNT, v)
#endif

/* --- Register HW_DVFSC_COUN, field DN_CNT
 *
 * Down counter threshold value
 */

#define BP_DVFSC_COUN_DN_CNT      16
#define BM_DVFSC_COUN_DN_CNT      0x00ff0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_COUN_DN_CNT(v)   ((((reg32_t) v) << 16) & BM_DVFSC_COUN_DN_CNT)
#else
#define BF_DVFSC_COUN_DN_CNT(v)   (((v) << 16) & BM_DVFSC_COUN_DN_CNT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_COUN_DN_CNT(v)   BF_CS1(DVFSC_COUN, DN_CNT, v)
#endif

/*!
 * @brief HW_DVFSC_SIG1 - DVFSC general purpose bits weight
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned WSW6 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[6]
        unsigned WSW7 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[7]
        unsigned WSW8 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[8]
        unsigned WSW9 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[9]
        unsigned WSW10 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[10]
        unsigned WSW11 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[11]
        unsigned WSW12 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[12]
        unsigned WSW13 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[13]
        unsigned WSW14 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[14]
        unsigned WSW15 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[15]
    } B;
} hw_dvfsc_sig1_t;
#endif

/*
 * constants & macros for entire DVFSC_SIG1 register
 */
#define HW_DVFSC_SIG1_ADDR      (REGS_DVFSC_BASE + 0x8)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_SIG1           (*(volatile hw_dvfsc_sig1_t *) HW_DVFSC_SIG1_ADDR)
#define HW_DVFSC_SIG1_RD()      (HW_DVFSC_SIG1.U)
#define HW_DVFSC_SIG1_WR(v)     (HW_DVFSC_SIG1.U = (v))
#define HW_DVFSC_SIG1_SET(v)    (HW_DVFSC_SIG1_WR(HW_DVFSC_SIG1_RD() |  (v)))
#define HW_DVFSC_SIG1_CLR(v)    (HW_DVFSC_SIG1_WR(HW_DVFSC_SIG1_RD() & ~(v)))
#define HW_DVFSC_SIG1_TOG(v)    (HW_DVFSC_SIG1_WR(HW_DVFSC_SIG1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_SIG1 bitfields
 */

/* --- Register HW_DVFSC_SIG1, field WSW6
 *
 * General purpose load tracking signal weight dvfs_w_sig[6]
 */

#define BP_DVFSC_SIG1_WSW6      2
#define BM_DVFSC_SIG1_WSW6      0x0000001c

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW6(v)   ((((reg32_t) v) << 2) & BM_DVFSC_SIG1_WSW6)
#else
#define BF_DVFSC_SIG1_WSW6(v)   (((v) << 2) & BM_DVFSC_SIG1_WSW6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW6(v)   BF_CS1(DVFSC_SIG1, WSW6, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW7
 *
 * General purpose load tracking signal weight dvfs_w_sig[7]
 */

#define BP_DVFSC_SIG1_WSW7      5
#define BM_DVFSC_SIG1_WSW7      0x000000e0

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW7(v)   ((((reg32_t) v) << 5) & BM_DVFSC_SIG1_WSW7)
#else
#define BF_DVFSC_SIG1_WSW7(v)   (((v) << 5) & BM_DVFSC_SIG1_WSW7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW7(v)   BF_CS1(DVFSC_SIG1, WSW7, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW8
 *
 * General purpose load tracking signal weight dvfs_w_sig[8]
 */

#define BP_DVFSC_SIG1_WSW8      8
#define BM_DVFSC_SIG1_WSW8      0x00000700

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW8(v)   ((((reg32_t) v) << 8) & BM_DVFSC_SIG1_WSW8)
#else
#define BF_DVFSC_SIG1_WSW8(v)   (((v) << 8) & BM_DVFSC_SIG1_WSW8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW8(v)   BF_CS1(DVFSC_SIG1, WSW8, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW9
 *
 * General purpose load tracking signal weight dvfs_w_sig[9]
 */

#define BP_DVFSC_SIG1_WSW9      11
#define BM_DVFSC_SIG1_WSW9      0x00003800

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW9(v)   ((((reg32_t) v) << 11) & BM_DVFSC_SIG1_WSW9)
#else
#define BF_DVFSC_SIG1_WSW9(v)   (((v) << 11) & BM_DVFSC_SIG1_WSW9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW9(v)   BF_CS1(DVFSC_SIG1, WSW9, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW10
 *
 * General purpose load tracking signal weight dvfs_w_sig[10]
 */

#define BP_DVFSC_SIG1_WSW10      14
#define BM_DVFSC_SIG1_WSW10      0x0001c000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW10(v)   ((((reg32_t) v) << 14) & BM_DVFSC_SIG1_WSW10)
#else
#define BF_DVFSC_SIG1_WSW10(v)   (((v) << 14) & BM_DVFSC_SIG1_WSW10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW10(v)   BF_CS1(DVFSC_SIG1, WSW10, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW11
 *
 * General purpose load tracking signal weight dvfs_w_sig[11]
 */

#define BP_DVFSC_SIG1_WSW11      17
#define BM_DVFSC_SIG1_WSW11      0x000e0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW11(v)   ((((reg32_t) v) << 17) & BM_DVFSC_SIG1_WSW11)
#else
#define BF_DVFSC_SIG1_WSW11(v)   (((v) << 17) & BM_DVFSC_SIG1_WSW11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW11(v)   BF_CS1(DVFSC_SIG1, WSW11, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW12
 *
 * General purpose load tracking signal weight dvfs_w_sig[12]
 */

#define BP_DVFSC_SIG1_WSW12      20
#define BM_DVFSC_SIG1_WSW12      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW12(v)   ((((reg32_t) v) << 20) & BM_DVFSC_SIG1_WSW12)
#else
#define BF_DVFSC_SIG1_WSW12(v)   (((v) << 20) & BM_DVFSC_SIG1_WSW12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW12(v)   BF_CS1(DVFSC_SIG1, WSW12, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW13
 *
 * General purpose load tracking signal weight dvfs_w_sig[13]
 */

#define BP_DVFSC_SIG1_WSW13      23
#define BM_DVFSC_SIG1_WSW13      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW13(v)   ((((reg32_t) v) << 23) & BM_DVFSC_SIG1_WSW13)
#else
#define BF_DVFSC_SIG1_WSW13(v)   (((v) << 23) & BM_DVFSC_SIG1_WSW13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW13(v)   BF_CS1(DVFSC_SIG1, WSW13, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW14
 *
 * General purpose load tracking signal weight dvfs_w_sig[14]
 */

#define BP_DVFSC_SIG1_WSW14      26
#define BM_DVFSC_SIG1_WSW14      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW14(v)   ((((reg32_t) v) << 26) & BM_DVFSC_SIG1_WSW14)
#else
#define BF_DVFSC_SIG1_WSW14(v)   (((v) << 26) & BM_DVFSC_SIG1_WSW14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW14(v)   BF_CS1(DVFSC_SIG1, WSW14, v)
#endif

/* --- Register HW_DVFSC_SIG1, field WSW15
 *
 * General purpose load tracking signal weight dvfs_w_sig[15]
 */

#define BP_DVFSC_SIG1_WSW15      29
#define BM_DVFSC_SIG1_WSW15      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG1_WSW15(v)   ((((reg32_t) v) << 29) & BM_DVFSC_SIG1_WSW15)
#else
#define BF_DVFSC_SIG1_WSW15(v)   (((v) << 29) & BM_DVFSC_SIG1_WSW15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG1_WSW15(v)   BF_CS1(DVFSC_SIG1, WSW15, v)
#endif

/*!
 * @brief HW_DVFSC_SIG0 - DVFSC general purpose bits weight
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned WSW0 : 6; //!< General purpose load tracking signal weight dvfs_w_sig[0]. This value is relevant during GPC0 counting period or when GPB0 is set.
        unsigned WSW1 : 6; //!< General purpose load tracking signal weight dvfs_w_sig[1]. This value is relevant during GPC1 counting period or when GPB1 is set.
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned WSW2 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[2]
        unsigned WSW3 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[3]
        unsigned WSW4 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[4]
        unsigned WSW5 : 3; //!< General purpose load tracking signal weight dvfs_w_sig[5]
    } B;
} hw_dvfsc_sig0_t;
#endif

/*
 * constants & macros for entire DVFSC_SIG0 register
 */
#define HW_DVFSC_SIG0_ADDR      (REGS_DVFSC_BASE + 0xc)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_SIG0           (*(volatile hw_dvfsc_sig0_t *) HW_DVFSC_SIG0_ADDR)
#define HW_DVFSC_SIG0_RD()      (HW_DVFSC_SIG0.U)
#define HW_DVFSC_SIG0_WR(v)     (HW_DVFSC_SIG0.U = (v))
#define HW_DVFSC_SIG0_SET(v)    (HW_DVFSC_SIG0_WR(HW_DVFSC_SIG0_RD() |  (v)))
#define HW_DVFSC_SIG0_CLR(v)    (HW_DVFSC_SIG0_WR(HW_DVFSC_SIG0_RD() & ~(v)))
#define HW_DVFSC_SIG0_TOG(v)    (HW_DVFSC_SIG0_WR(HW_DVFSC_SIG0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_SIG0 bitfields
 */

/* --- Register HW_DVFSC_SIG0, field WSW0
 *
 * General purpose load tracking signal weight dvfs_w_sig[0]. This value
 * is relevant during GPC0 counting period or when GPB0 is set.
 */

#define BP_DVFSC_SIG0_WSW0      0
#define BM_DVFSC_SIG0_WSW0      0x0000003f

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG0_WSW0(v)   ((((reg32_t) v) << 0) & BM_DVFSC_SIG0_WSW0)
#else
#define BF_DVFSC_SIG0_WSW0(v)   (((v) << 0) & BM_DVFSC_SIG0_WSW0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG0_WSW0(v)   BF_CS1(DVFSC_SIG0, WSW0, v)
#endif

/* --- Register HW_DVFSC_SIG0, field WSW1
 *
 * General purpose load tracking signal weight dvfs_w_sig[1]. This value
 * is relevant during GPC1 counting period or when GPB1 is set.
 */

#define BP_DVFSC_SIG0_WSW1      6
#define BM_DVFSC_SIG0_WSW1      0x00000fc0

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG0_WSW1(v)   ((((reg32_t) v) << 6) & BM_DVFSC_SIG0_WSW1)
#else
#define BF_DVFSC_SIG0_WSW1(v)   (((v) << 6) & BM_DVFSC_SIG0_WSW1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG0_WSW1(v)   BF_CS1(DVFSC_SIG0, WSW1, v)
#endif

/* --- Register HW_DVFSC_SIG0, field WSW2
 *
 * General purpose load tracking signal weight dvfs_w_sig[2]
 */

#define BP_DVFSC_SIG0_WSW2      20
#define BM_DVFSC_SIG0_WSW2      0x00700000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG0_WSW2(v)   ((((reg32_t) v) << 20) & BM_DVFSC_SIG0_WSW2)
#else
#define BF_DVFSC_SIG0_WSW2(v)   (((v) << 20) & BM_DVFSC_SIG0_WSW2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG0_WSW2(v)   BF_CS1(DVFSC_SIG0, WSW2, v)
#endif

/* --- Register HW_DVFSC_SIG0, field WSW3
 *
 * General purpose load tracking signal weight dvfs_w_sig[3]
 */

#define BP_DVFSC_SIG0_WSW3      23
#define BM_DVFSC_SIG0_WSW3      0x03800000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG0_WSW3(v)   ((((reg32_t) v) << 23) & BM_DVFSC_SIG0_WSW3)
#else
#define BF_DVFSC_SIG0_WSW3(v)   (((v) << 23) & BM_DVFSC_SIG0_WSW3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG0_WSW3(v)   BF_CS1(DVFSC_SIG0, WSW3, v)
#endif

/* --- Register HW_DVFSC_SIG0, field WSW4
 *
 * General purpose load tracking signal weight dvfs_w_sig[4]
 */

#define BP_DVFSC_SIG0_WSW4      26
#define BM_DVFSC_SIG0_WSW4      0x1c000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG0_WSW4(v)   ((((reg32_t) v) << 26) & BM_DVFSC_SIG0_WSW4)
#else
#define BF_DVFSC_SIG0_WSW4(v)   (((v) << 26) & BM_DVFSC_SIG0_WSW4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG0_WSW4(v)   BF_CS1(DVFSC_SIG0, WSW4, v)
#endif

/* --- Register HW_DVFSC_SIG0, field WSW5
 *
 * General purpose load tracking signal weight dvfs_w_sig[5]
 */

#define BP_DVFSC_SIG0_WSW5      29
#define BM_DVFSC_SIG0_WSW5      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_SIG0_WSW5(v)   ((((reg32_t) v) << 29) & BM_DVFSC_SIG0_WSW5)
#else
#define BF_DVFSC_SIG0_WSW5(v)   (((v) << 29) & BM_DVFSC_SIG0_WSW5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_SIG0_WSW5(v)   BF_CS1(DVFSC_SIG0, WSW5, v)
#endif

/*!
 * @brief HW_DVFSC_GPC0 - DVFSC general purpose bit 0 weight counter
 *
 * DVFS general purpose bits weight counter.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPBC0 : 17; //!< GPBC0 - General Purpose bits Counter 0  During period of this counter the GeP bit 0 will be set and WSW0 will be added to the calculations.
        unsigned RESERVED0 : 13; //!< Reserved
        unsigned C0ACT : 1; //!< C0ACT-Counter 0 active indicator
        unsigned C0STRT : 1; //!< C0STRT-Counter 0 start  Setting of this bit will initialize down counting of the GPC0 value.  Bit is self-cleared next cycle after setting.  Any setting of this bit will re-start GPC0 counter to the GPC0 value.  GPB0 bit disables (overrides) GPC0 counter-WSW0 weight is applicable continuously
    } B;
} hw_dvfsc_gpc0_t;
#endif

/*
 * constants & macros for entire DVFSC_GPC0 register
 */
#define HW_DVFSC_GPC0_ADDR      (REGS_DVFSC_BASE + 0x10)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_GPC0           (*(volatile hw_dvfsc_gpc0_t *) HW_DVFSC_GPC0_ADDR)
#define HW_DVFSC_GPC0_RD()      (HW_DVFSC_GPC0.U)
#define HW_DVFSC_GPC0_WR(v)     (HW_DVFSC_GPC0.U = (v))
#define HW_DVFSC_GPC0_SET(v)    (HW_DVFSC_GPC0_WR(HW_DVFSC_GPC0_RD() |  (v)))
#define HW_DVFSC_GPC0_CLR(v)    (HW_DVFSC_GPC0_WR(HW_DVFSC_GPC0_RD() & ~(v)))
#define HW_DVFSC_GPC0_TOG(v)    (HW_DVFSC_GPC0_WR(HW_DVFSC_GPC0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_GPC0 bitfields
 */

/* --- Register HW_DVFSC_GPC0, field GPBC0
 *
 * GPBC0 - General Purpose bits Counter 0  During period of this counter the GeP bit 0 will be set
 * and WSW0 will                                 be added to the calculations.
 */

#define BP_DVFSC_GPC0_GPBC0      0
#define BM_DVFSC_GPC0_GPBC0      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPC0_GPBC0(v)   ((((reg32_t) v) << 0) & BM_DVFSC_GPC0_GPBC0)
#else
#define BF_DVFSC_GPC0_GPBC0(v)   (((v) << 0) & BM_DVFSC_GPC0_GPBC0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPC0_GPBC0(v)   BF_CS1(DVFSC_GPC0, GPBC0, v)
#endif

/* --- Register HW_DVFSC_GPC0, field C0ACT
 *
 * C0ACT-Counter 0 active indicator
 */

#define BP_DVFSC_GPC0_C0ACT      30
#define BM_DVFSC_GPC0_C0ACT      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPC0_C0ACT(v)   ((((reg32_t) v) << 30) & BM_DVFSC_GPC0_C0ACT)
#else
#define BF_DVFSC_GPC0_C0ACT(v)   (((v) << 30) & BM_DVFSC_GPC0_C0ACT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPC0_C0ACT(v)   BF_CS1(DVFSC_GPC0, C0ACT, v)
#endif

/* --- Register HW_DVFSC_GPC0, field C0STRT
 *
 * C0STRT-Counter 0 start  Setting of this bit will initialize down counting of the GPC0
 * value.  Bit is self-cleared next cycle after setting.  Any setting of this bit will re-start GPC0
 * counter to the GPC0                                 value.  GPB0 bit disables (overrides) GPC0
 * counter-WSW0 weight is applicable                                 continuously
 */

#define BP_DVFSC_GPC0_C0STRT      31
#define BM_DVFSC_GPC0_C0STRT      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPC0_C0STRT(v)   ((((reg32_t) v) << 31) & BM_DVFSC_GPC0_C0STRT)
#else
#define BF_DVFSC_GPC0_C0STRT(v)   (((v) << 31) & BM_DVFSC_GPC0_C0STRT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPC0_C0STRT(v)   BF_CS1(DVFSC_GPC0, C0STRT, v)
#endif

/*!
 * @brief HW_DVFSC_GPC1 - DVFSC general purpose bit 1 weight counter
 *
 * DVFS general purpose bits weight counter1.
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPBC1 : 17; //!< GPBC1 - General Purpose bits Counter 1  During period of this counter the GeP bit 1 will be set and WSW1 will be added to the calculations.
        unsigned RESERVED0 : 13; //!< Reserved
        unsigned C1ACT : 1; //!< C1ACT - Counter 1 active indicator
        unsigned C1STRT : 1; //!< C1STRT - Counter 1start  Setting of this bit will initialize down counting of the GPC1 value.  Bit is self-cleared next cycle after setting.  Any setting of this bit will re-start GPC1 counter to the GPC1 value.  GPB1 bit disables (overrides) GPC1 counter - WSW1 weight is applicable continuously
    } B;
} hw_dvfsc_gpc1_t;
#endif

/*
 * constants & macros for entire DVFSC_GPC1 register
 */
#define HW_DVFSC_GPC1_ADDR      (REGS_DVFSC_BASE + 0x14)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_GPC1           (*(volatile hw_dvfsc_gpc1_t *) HW_DVFSC_GPC1_ADDR)
#define HW_DVFSC_GPC1_RD()      (HW_DVFSC_GPC1.U)
#define HW_DVFSC_GPC1_WR(v)     (HW_DVFSC_GPC1.U = (v))
#define HW_DVFSC_GPC1_SET(v)    (HW_DVFSC_GPC1_WR(HW_DVFSC_GPC1_RD() |  (v)))
#define HW_DVFSC_GPC1_CLR(v)    (HW_DVFSC_GPC1_WR(HW_DVFSC_GPC1_RD() & ~(v)))
#define HW_DVFSC_GPC1_TOG(v)    (HW_DVFSC_GPC1_WR(HW_DVFSC_GPC1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_GPC1 bitfields
 */

/* --- Register HW_DVFSC_GPC1, field GPBC1
 *
 * GPBC1 - General Purpose bits Counter 1  During period of this counter the GeP bit 1 will be set
 * and WSW1 will                                 be added to the calculations.
 */

#define BP_DVFSC_GPC1_GPBC1      0
#define BM_DVFSC_GPC1_GPBC1      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPC1_GPBC1(v)   ((((reg32_t) v) << 0) & BM_DVFSC_GPC1_GPBC1)
#else
#define BF_DVFSC_GPC1_GPBC1(v)   (((v) << 0) & BM_DVFSC_GPC1_GPBC1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPC1_GPBC1(v)   BF_CS1(DVFSC_GPC1, GPBC1, v)
#endif

/* --- Register HW_DVFSC_GPC1, field C1ACT
 *
 * C1ACT - Counter 1 active indicator
 */

#define BP_DVFSC_GPC1_C1ACT      30
#define BM_DVFSC_GPC1_C1ACT      0x40000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPC1_C1ACT(v)   ((((reg32_t) v) << 30) & BM_DVFSC_GPC1_C1ACT)
#else
#define BF_DVFSC_GPC1_C1ACT(v)   (((v) << 30) & BM_DVFSC_GPC1_C1ACT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPC1_C1ACT(v)   BF_CS1(DVFSC_GPC1, C1ACT, v)
#endif

/* --- Register HW_DVFSC_GPC1, field C1STRT
 *
 * C1STRT - Counter 1start  Setting of this bit will initialize down counting of the GPC1
 * value.  Bit is self-cleared next cycle after setting.  Any setting of this bit will re-start GPC1
 * counter to the GPC1                                 value.  GPB1 bit disables (overrides) GPC1
 * counter - WSW1 weight is                                 applicable continuously
 */

#define BP_DVFSC_GPC1_C1STRT      31
#define BM_DVFSC_GPC1_C1STRT      0x80000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPC1_C1STRT(v)   ((((reg32_t) v) << 31) & BM_DVFSC_GPC1_C1STRT)
#else
#define BF_DVFSC_GPC1_C1STRT(v)   (((v) << 31) & BM_DVFSC_GPC1_C1STRT)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPC1_C1STRT(v)   BF_CS1(DVFSC_GPC1, C1STRT, v)
#endif

/*!
 * @brief HW_DVFSC_GPBT - DVFSC general purpose bits enables
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned GPB0 : 1; //!< General purpose bit 0. Its weight is set by WSW0 value. IF set (1), the GPBC0 operation is disregarded, WSW0 value is applied continuously.
        unsigned GPB1 : 1; //!< General purpose bit 1. Its weight is set by WSW1 value. IF set (1), the GPBC1 operation is disregarded, WSW1 value is applied continuously.
        unsigned GPB2 : 1; //!< General purpose bit 2. Its weight is set by WSW2 value.
        unsigned GPB3 : 1; //!< General purpose bit 3. Its weight is set by WSW3 value.
        unsigned GPB4 : 1; //!< General purpose bit 4. Its weight is set by WSW4 value.
        unsigned GPB5 : 1; //!< General purpose bit 5. Its weight is set by WSW5 value.
        unsigned GPB6 : 1; //!< General purpose bit 6. Its weight is set by WSW6 value.
        unsigned GPB7 : 1; //!< General purpose bit 7. Its weight is set by WSW7 value.
        unsigned GPB8 : 1; //!< General purpose bit 8. Its weight is set by WSW8 value.
        unsigned GPB9 : 1; //!< General purpose bit 9. Its weight is set by WSW9 value.
        unsigned GPB10 : 1; //!< General purpose bit 10. Its weight is set by WSW10 value.
        unsigned GPB11 : 1; //!< General purpose bit 11. Its weight is set by WSW11 value.
        unsigned GPB12 : 1; //!< General purpose bit 12. Its weight is set by WSW12 value.
        unsigned GPB13 : 1; //!< General purpose bit 13. Its weight is set by WSW13 value.
        unsigned GPB14 : 1; //!< General purpose bit 14. Its weight is set by WSW14 value.
        unsigned GPB15 : 1; //!< General purpose bit 15. Its weight is set by WSW15 value.
        unsigned RESERVED : 16; //!< N/A
    } B;
} hw_dvfsc_gpbt_t;
#endif

/*
 * constants & macros for entire DVFSC_GPBT register
 */
#define HW_DVFSC_GPBT_ADDR      (REGS_DVFSC_BASE + 0x18)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_GPBT           (*(volatile hw_dvfsc_gpbt_t *) HW_DVFSC_GPBT_ADDR)
#define HW_DVFSC_GPBT_RD()      (HW_DVFSC_GPBT.U)
#define HW_DVFSC_GPBT_WR(v)     (HW_DVFSC_GPBT.U = (v))
#define HW_DVFSC_GPBT_SET(v)    (HW_DVFSC_GPBT_WR(HW_DVFSC_GPBT_RD() |  (v)))
#define HW_DVFSC_GPBT_CLR(v)    (HW_DVFSC_GPBT_WR(HW_DVFSC_GPBT_RD() & ~(v)))
#define HW_DVFSC_GPBT_TOG(v)    (HW_DVFSC_GPBT_WR(HW_DVFSC_GPBT_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_GPBT bitfields
 */

/* --- Register HW_DVFSC_GPBT, field GPB0
 *
 * General purpose bit 0. Its weight is set by WSW0 value. IF set (1),
 * the GPBC0 operation is disregarded, WSW0 value is applied
 * continuously.
 */

#define BP_DVFSC_GPBT_GPB0      0
#define BM_DVFSC_GPBT_GPB0      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB0(v)   ((((reg32_t) v) << 0) & BM_DVFSC_GPBT_GPB0)
#else
#define BF_DVFSC_GPBT_GPB0(v)   (((v) << 0) & BM_DVFSC_GPBT_GPB0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB0(v)   BF_CS1(DVFSC_GPBT, GPB0, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB1
 *
 * General purpose bit 1. Its weight is set by WSW1 value. IF set (1),
 * the GPBC1 operation is disregarded, WSW1 value is applied
 * continuously.
 */

#define BP_DVFSC_GPBT_GPB1      1
#define BM_DVFSC_GPBT_GPB1      0x00000002

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB1(v)   ((((reg32_t) v) << 1) & BM_DVFSC_GPBT_GPB1)
#else
#define BF_DVFSC_GPBT_GPB1(v)   (((v) << 1) & BM_DVFSC_GPBT_GPB1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB1(v)   BF_CS1(DVFSC_GPBT, GPB1, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB2
 *
 * General purpose bit 2. Its weight is set by WSW2 value.
 */

#define BP_DVFSC_GPBT_GPB2      2
#define BM_DVFSC_GPBT_GPB2      0x00000004

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB2(v)   ((((reg32_t) v) << 2) & BM_DVFSC_GPBT_GPB2)
#else
#define BF_DVFSC_GPBT_GPB2(v)   (((v) << 2) & BM_DVFSC_GPBT_GPB2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB2(v)   BF_CS1(DVFSC_GPBT, GPB2, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB3
 *
 * General purpose bit 3. Its weight is set by WSW3 value.
 */

#define BP_DVFSC_GPBT_GPB3      3
#define BM_DVFSC_GPBT_GPB3      0x00000008

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB3(v)   ((((reg32_t) v) << 3) & BM_DVFSC_GPBT_GPB3)
#else
#define BF_DVFSC_GPBT_GPB3(v)   (((v) << 3) & BM_DVFSC_GPBT_GPB3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB3(v)   BF_CS1(DVFSC_GPBT, GPB3, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB4
 *
 * General purpose bit 4. Its weight is set by WSW4 value.
 */

#define BP_DVFSC_GPBT_GPB4      4
#define BM_DVFSC_GPBT_GPB4      0x00000010

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB4(v)   ((((reg32_t) v) << 4) & BM_DVFSC_GPBT_GPB4)
#else
#define BF_DVFSC_GPBT_GPB4(v)   (((v) << 4) & BM_DVFSC_GPBT_GPB4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB4(v)   BF_CS1(DVFSC_GPBT, GPB4, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB5
 *
 * General purpose bit 5. Its weight is set by WSW5 value.
 */

#define BP_DVFSC_GPBT_GPB5      5
#define BM_DVFSC_GPBT_GPB5      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB5(v)   ((((reg32_t) v) << 5) & BM_DVFSC_GPBT_GPB5)
#else
#define BF_DVFSC_GPBT_GPB5(v)   (((v) << 5) & BM_DVFSC_GPBT_GPB5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB5(v)   BF_CS1(DVFSC_GPBT, GPB5, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB6
 *
 * General purpose bit 6. Its weight is set by WSW6 value.
 */

#define BP_DVFSC_GPBT_GPB6      6
#define BM_DVFSC_GPBT_GPB6      0x00000040

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB6(v)   ((((reg32_t) v) << 6) & BM_DVFSC_GPBT_GPB6)
#else
#define BF_DVFSC_GPBT_GPB6(v)   (((v) << 6) & BM_DVFSC_GPBT_GPB6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB6(v)   BF_CS1(DVFSC_GPBT, GPB6, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB7
 *
 * General purpose bit 7. Its weight is set by WSW7 value.
 */

#define BP_DVFSC_GPBT_GPB7      7
#define BM_DVFSC_GPBT_GPB7      0x00000080

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB7(v)   ((((reg32_t) v) << 7) & BM_DVFSC_GPBT_GPB7)
#else
#define BF_DVFSC_GPBT_GPB7(v)   (((v) << 7) & BM_DVFSC_GPBT_GPB7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB7(v)   BF_CS1(DVFSC_GPBT, GPB7, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB8
 *
 * General purpose bit 8. Its weight is set by WSW8 value.
 */

#define BP_DVFSC_GPBT_GPB8      8
#define BM_DVFSC_GPBT_GPB8      0x00000100

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB8(v)   ((((reg32_t) v) << 8) & BM_DVFSC_GPBT_GPB8)
#else
#define BF_DVFSC_GPBT_GPB8(v)   (((v) << 8) & BM_DVFSC_GPBT_GPB8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB8(v)   BF_CS1(DVFSC_GPBT, GPB8, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB9
 *
 * General purpose bit 9. Its weight is set by WSW9 value.
 */

#define BP_DVFSC_GPBT_GPB9      9
#define BM_DVFSC_GPBT_GPB9      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB9(v)   ((((reg32_t) v) << 9) & BM_DVFSC_GPBT_GPB9)
#else
#define BF_DVFSC_GPBT_GPB9(v)   (((v) << 9) & BM_DVFSC_GPBT_GPB9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB9(v)   BF_CS1(DVFSC_GPBT, GPB9, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB10
 *
 * General purpose bit 10. Its weight is set by WSW10 value.
 */

#define BP_DVFSC_GPBT_GPB10      10
#define BM_DVFSC_GPBT_GPB10      0x00000400

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB10(v)   ((((reg32_t) v) << 10) & BM_DVFSC_GPBT_GPB10)
#else
#define BF_DVFSC_GPBT_GPB10(v)   (((v) << 10) & BM_DVFSC_GPBT_GPB10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB10(v)   BF_CS1(DVFSC_GPBT, GPB10, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB11
 *
 * General purpose bit 11. Its weight is set by WSW11 value.
 */

#define BP_DVFSC_GPBT_GPB11      11
#define BM_DVFSC_GPBT_GPB11      0x00000800

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB11(v)   ((((reg32_t) v) << 11) & BM_DVFSC_GPBT_GPB11)
#else
#define BF_DVFSC_GPBT_GPB11(v)   (((v) << 11) & BM_DVFSC_GPBT_GPB11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB11(v)   BF_CS1(DVFSC_GPBT, GPB11, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB12
 *
 * General purpose bit 12. Its weight is set by WSW12 value.
 */

#define BP_DVFSC_GPBT_GPB12      12
#define BM_DVFSC_GPBT_GPB12      0x00001000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB12(v)   ((((reg32_t) v) << 12) & BM_DVFSC_GPBT_GPB12)
#else
#define BF_DVFSC_GPBT_GPB12(v)   (((v) << 12) & BM_DVFSC_GPBT_GPB12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB12(v)   BF_CS1(DVFSC_GPBT, GPB12, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB13
 *
 * General purpose bit 13. Its weight is set by WSW13 value.
 */

#define BP_DVFSC_GPBT_GPB13      13
#define BM_DVFSC_GPBT_GPB13      0x00002000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB13(v)   ((((reg32_t) v) << 13) & BM_DVFSC_GPBT_GPB13)
#else
#define BF_DVFSC_GPBT_GPB13(v)   (((v) << 13) & BM_DVFSC_GPBT_GPB13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB13(v)   BF_CS1(DVFSC_GPBT, GPB13, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB14
 *
 * General purpose bit 14. Its weight is set by WSW14 value.
 */

#define BP_DVFSC_GPBT_GPB14      14
#define BM_DVFSC_GPBT_GPB14      0x00004000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB14(v)   ((((reg32_t) v) << 14) & BM_DVFSC_GPBT_GPB14)
#else
#define BF_DVFSC_GPBT_GPB14(v)   (((v) << 14) & BM_DVFSC_GPBT_GPB14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB14(v)   BF_CS1(DVFSC_GPBT, GPB14, v)
#endif

/* --- Register HW_DVFSC_GPBT, field GPB15
 *
 * General purpose bit 15. Its weight is set by WSW15 value.
 */

#define BP_DVFSC_GPBT_GPB15      15
#define BM_DVFSC_GPBT_GPB15      0x00008000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_GPB15(v)   ((((reg32_t) v) << 15) & BM_DVFSC_GPBT_GPB15)
#else
#define BF_DVFSC_GPBT_GPB15(v)   (((v) << 15) & BM_DVFSC_GPBT_GPB15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_GPB15(v)   BF_CS1(DVFSC_GPBT, GPB15, v)
#endif

/* --- Register HW_DVFSC_GPBT, field RESERVED
 *
 * N/A
 */

#define BP_DVFSC_GPBT_RESERVED      16
#define BM_DVFSC_GPBT_RESERVED      0xffff0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_GPBT_RESERVED(v)   ((((reg32_t) v) << 16) & BM_DVFSC_GPBT_RESERVED)
#else
#define BF_DVFSC_GPBT_RESERVED(v)   (((v) << 16) & BM_DVFSC_GPBT_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_GPBT_RESERVED(v)   BF_CS1(DVFSC_GPBT, RESERVED, v)
#endif

/*!
 * @brief HW_DVFSC_EMAC - DVFSC EMAC settings
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned EMAC : 9; //!< EMAC - EMA control value
        unsigned RESERVED : 23; //!< Reserved
    } B;
} hw_dvfsc_emac_t;
#endif

/*
 * constants & macros for entire DVFSC_EMAC register
 */
#define HW_DVFSC_EMAC_ADDR      (REGS_DVFSC_BASE + 0x1c)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_EMAC           (*(volatile hw_dvfsc_emac_t *) HW_DVFSC_EMAC_ADDR)
#define HW_DVFSC_EMAC_RD()      (HW_DVFSC_EMAC.U)
#define HW_DVFSC_EMAC_WR(v)     (HW_DVFSC_EMAC.U = (v))
#define HW_DVFSC_EMAC_SET(v)    (HW_DVFSC_EMAC_WR(HW_DVFSC_EMAC_RD() |  (v)))
#define HW_DVFSC_EMAC_CLR(v)    (HW_DVFSC_EMAC_WR(HW_DVFSC_EMAC_RD() & ~(v)))
#define HW_DVFSC_EMAC_TOG(v)    (HW_DVFSC_EMAC_WR(HW_DVFSC_EMAC_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_EMAC bitfields
 */

/* --- Register HW_DVFSC_EMAC, field EMAC
 *
 * EMAC - EMA control value
 */

#define BP_DVFSC_EMAC_EMAC      0
#define BM_DVFSC_EMAC_EMAC      0x000001ff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_EMAC_EMAC(v)   ((((reg32_t) v) << 0) & BM_DVFSC_EMAC_EMAC)
#else
#define BF_DVFSC_EMAC_EMAC(v)   (((v) << 0) & BM_DVFSC_EMAC_EMAC)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_EMAC_EMAC(v)   BF_CS1(DVFSC_EMAC, EMAC, v)
#endif

/* --- Register HW_DVFSC_EMAC, field RESERVED
 *
 * Reserved
 */

#define BP_DVFSC_EMAC_RESERVED      9
#define BM_DVFSC_EMAC_RESERVED      0xfffffe00

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_EMAC_RESERVED(v)   ((((reg32_t) v) << 9) & BM_DVFSC_EMAC_RESERVED)
#else
#define BF_DVFSC_EMAC_RESERVED(v)   (((v) << 9) & BM_DVFSC_EMAC_RESERVED)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_EMAC_RESERVED(v)   BF_CS1(DVFSC_EMAC, RESERVED, v)
#endif

/*!
 * @brief HW_DVFSC_CNTR - DVFSC Control
 *
 * DIV3CK division         DIV3CK setting  dividing ratio  sum_3 passing bits  div_1_clk cumulative
 * divider      00  1  4-0  1*512=512    001  4  6-2  4*512=2048    010  16  8-4  16*512=8192    011
 * 64  10-6  64*512=32768    100  256  12-8  256*512=131072    101  1024  16-10  1024*512=524288
 * Preliminary Divider definition       DIV_RATIO value  ARM clk division ratio      000000  1
 * 000001  2    000010  3    ...  ...
 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned DVFEN : 1; //!< DVFEN  DVFS enable. This bit enables the DVFSC.  Between disable and enable there has to be at least 3 cycles of div_3_clk.
        unsigned RESERVED0 : 2; //!< Reserved
        unsigned LTBRSR : 2; //!< LTBRSR - Load Tracking Buffer Register Source:
        unsigned LTBRSH : 1; //!< LTBRSH - Load Tracking Buffer Register Shift:
        unsigned PFUS : 3; //!< PFUS - Periodic Frequency Update Status
        unsigned PFUE : 1; //!< PFUE - Period Frequency Update Enable
        unsigned RESERVED1 : 1; //!< Reserved
        unsigned DIV_RATIO : 6; //!< DIV_RATIO - Divider value. Divider divides the input ARM clock, following the table
        unsigned MINF : 1; //!< Minimum frequency reached. Interrupt will not be created in minimum frequency reached and frequency decrease required.
        unsigned MAXF : 1; //!< Maximum frequency reached. Interrupt will not be created in maximum frequency reached and frequency increase required.
        unsigned WFIM : 1; //!< DVFS Wait for Interrupt mask bit
        unsigned FSVAI : 2; //!< FSVAI  DVFS Frequency adjustment interrupt. These status bits indicate that the system frequency should be changed.
        unsigned FSVAIM : 1; //!< DVFS Frequency adjustment interrupt mask. This bit masks the DVFS frequency adjustment interrupt. FSVAI status bits will be still asserted in relevant cases.  interrupt is masked.
        unsigned PIRQS : 1; //!< PIRQS - Pattern IRQ Source  * write '1' to clear. Writing '1' will clear interrupt if interrupt was from pattern
        unsigned DVFIS : 1; //!< DVFS Interrupt select. These bits define destination of DVFS interrupts.  ARM platform interrupt will be generated for DVFS events.
        unsigned LBFL0 : 1; //!< Load buffer 0 - full status bit. This bit indicates that log buffer registers are full. The bit is set to 1 automatically.  An interrupt will be generated if LBMI bit is set to "0"  Load buffer1 is full.  Write '1' to clear. (write '0' leaves bit unchanged)
        unsigned LBFL1 : 1; //!< Load buffer 1 - full status bit. This bit indicates that log buffer registers are full. The bit is set to 1 automatically.  An interrupt will be generated if LBMI bit is set to '0'  Load buffer0 is full.Write '1' to clear.  (write '0' leaves bit unchanged)
        unsigned LBMI : 1; //!< Load buffer full mask interrupt. This bit masks the generation of this interrupt.  Load buffer full interrupt is masked (LBFL0 and LBFL1 bits still will be updated, but interrupt won't be generated)
        unsigned DVFEV : 1; //!< Always give a DVFS event.
        unsigned DIV3CK : 3; //!< DIV3CK - div_3_clk division ratio inside the DVFSC. According to the
    } B;
} hw_dvfsc_cntr_t;
#endif

/*
 * constants & macros for entire DVFSC_CNTR register
 */
#define HW_DVFSC_CNTR_ADDR      (REGS_DVFSC_BASE + 0x20)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_CNTR           (*(volatile hw_dvfsc_cntr_t *) HW_DVFSC_CNTR_ADDR)
#define HW_DVFSC_CNTR_RD()      (HW_DVFSC_CNTR.U)
#define HW_DVFSC_CNTR_WR(v)     (HW_DVFSC_CNTR.U = (v))
#define HW_DVFSC_CNTR_SET(v)    (HW_DVFSC_CNTR_WR(HW_DVFSC_CNTR_RD() |  (v)))
#define HW_DVFSC_CNTR_CLR(v)    (HW_DVFSC_CNTR_WR(HW_DVFSC_CNTR_RD() & ~(v)))
#define HW_DVFSC_CNTR_TOG(v)    (HW_DVFSC_CNTR_WR(HW_DVFSC_CNTR_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_CNTR bitfields
 */

/* --- Register HW_DVFSC_CNTR, field DVFEN
 *
 * DVFEN  DVFS enable. This bit enables the DVFSC.  Between disable and enable there has to be at
 * least 3 cycles of                                 div_3_clk.
 */

#define BP_DVFSC_CNTR_DVFEN      0
#define BM_DVFSC_CNTR_DVFEN      0x00000001

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_DVFEN(v)   ((((reg32_t) v) << 0) & BM_DVFSC_CNTR_DVFEN)
#else
#define BF_DVFSC_CNTR_DVFEN(v)   (((v) << 0) & BM_DVFSC_CNTR_DVFEN)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_DVFEN(v)   BF_CS1(DVFSC_CNTR, DVFEN, v)
#endif

/* --- Register HW_DVFSC_CNTR, field LTBRSR
 *
 * LTBRSR - Load Tracking Buffer Register Source:
 */

#define BP_DVFSC_CNTR_LTBRSR      3
#define BM_DVFSC_CNTR_LTBRSR      0x00000018

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_LTBRSR(v)   ((((reg32_t) v) << 3) & BM_DVFSC_CNTR_LTBRSR)
#else
#define BF_DVFSC_CNTR_LTBRSR(v)   (((v) << 3) & BM_DVFSC_CNTR_LTBRSR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_LTBRSR(v)   BF_CS1(DVFSC_CNTR, LTBRSR, v)
#endif

/* --- Register HW_DVFSC_CNTR, field LTBRSH
 *
 * LTBRSH - Load Tracking Buffer Register Shift:
 */

#define BP_DVFSC_CNTR_LTBRSH      5
#define BM_DVFSC_CNTR_LTBRSH      0x00000020

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_LTBRSH(v)   ((((reg32_t) v) << 5) & BM_DVFSC_CNTR_LTBRSH)
#else
#define BF_DVFSC_CNTR_LTBRSH(v)   (((v) << 5) & BM_DVFSC_CNTR_LTBRSH)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_LTBRSH(v)   BF_CS1(DVFSC_CNTR, LTBRSH, v)
#endif

/* --- Register HW_DVFSC_CNTR, field PFUS
 *
 * PFUS - Periodic Frequency Update Status
 */

#define BP_DVFSC_CNTR_PFUS      6
#define BM_DVFSC_CNTR_PFUS      0x000001c0

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_PFUS(v)   ((((reg32_t) v) << 6) & BM_DVFSC_CNTR_PFUS)
#else
#define BF_DVFSC_CNTR_PFUS(v)   (((v) << 6) & BM_DVFSC_CNTR_PFUS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_PFUS(v)   BF_CS1(DVFSC_CNTR, PFUS, v)
#endif

/* --- Register HW_DVFSC_CNTR, field PFUE
 *
 * PFUE - Period Frequency Update Enable
 */

#define BP_DVFSC_CNTR_PFUE      9
#define BM_DVFSC_CNTR_PFUE      0x00000200

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_PFUE(v)   ((((reg32_t) v) << 9) & BM_DVFSC_CNTR_PFUE)
#else
#define BF_DVFSC_CNTR_PFUE(v)   (((v) << 9) & BM_DVFSC_CNTR_PFUE)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_PFUE(v)   BF_CS1(DVFSC_CNTR, PFUE, v)
#endif

/* --- Register HW_DVFSC_CNTR, field DIV_RATIO
 *
 * DIV_RATIO - Divider value. Divider divides the input ARM clock,
 * following the table
 */

#define BP_DVFSC_CNTR_DIV_RATIO      11
#define BM_DVFSC_CNTR_DIV_RATIO      0x0001f800

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_DIV_RATIO(v)   ((((reg32_t) v) << 11) & BM_DVFSC_CNTR_DIV_RATIO)
#else
#define BF_DVFSC_CNTR_DIV_RATIO(v)   (((v) << 11) & BM_DVFSC_CNTR_DIV_RATIO)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_DIV_RATIO(v)   BF_CS1(DVFSC_CNTR, DIV_RATIO, v)
#endif

/* --- Register HW_DVFSC_CNTR, field MINF
 *
 * Minimum frequency reached. Interrupt will not be created in minimum
 * frequency reached and frequency decrease required.
 */

#define BP_DVFSC_CNTR_MINF      17
#define BM_DVFSC_CNTR_MINF      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_MINF(v)   ((((reg32_t) v) << 17) & BM_DVFSC_CNTR_MINF)
#else
#define BF_DVFSC_CNTR_MINF(v)   (((v) << 17) & BM_DVFSC_CNTR_MINF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_MINF(v)   BF_CS1(DVFSC_CNTR, MINF, v)
#endif

/* --- Register HW_DVFSC_CNTR, field MAXF
 *
 * Maximum frequency reached. Interrupt will not be created in maximum
 * frequency reached and frequency increase required.
 */

#define BP_DVFSC_CNTR_MAXF      18
#define BM_DVFSC_CNTR_MAXF      0x00040000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_MAXF(v)   ((((reg32_t) v) << 18) & BM_DVFSC_CNTR_MAXF)
#else
#define BF_DVFSC_CNTR_MAXF(v)   (((v) << 18) & BM_DVFSC_CNTR_MAXF)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_MAXF(v)   BF_CS1(DVFSC_CNTR, MAXF, v)
#endif

/* --- Register HW_DVFSC_CNTR, field WFIM
 *
 * DVFS Wait for Interrupt mask bit
 */

#define BP_DVFSC_CNTR_WFIM      19
#define BM_DVFSC_CNTR_WFIM      0x00080000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_WFIM(v)   ((((reg32_t) v) << 19) & BM_DVFSC_CNTR_WFIM)
#else
#define BF_DVFSC_CNTR_WFIM(v)   (((v) << 19) & BM_DVFSC_CNTR_WFIM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_WFIM(v)   BF_CS1(DVFSC_CNTR, WFIM, v)
#endif

/* --- Register HW_DVFSC_CNTR, field FSVAI
 *
 * FSVAI  DVFS Frequency adjustment interrupt. These status bits indicate that
 * the system frequency should be changed.
 */

#define BP_DVFSC_CNTR_FSVAI      20
#define BM_DVFSC_CNTR_FSVAI      0x00300000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_FSVAI(v)   ((((reg32_t) v) << 20) & BM_DVFSC_CNTR_FSVAI)
#else
#define BF_DVFSC_CNTR_FSVAI(v)   (((v) << 20) & BM_DVFSC_CNTR_FSVAI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_FSVAI(v)   BF_CS1(DVFSC_CNTR, FSVAI, v)
#endif

/* --- Register HW_DVFSC_CNTR, field FSVAIM
 *
 * DVFS Frequency adjustment interrupt mask. This bit masks the DVFS
 * frequency adjustment interrupt. FSVAI status bits will be still
 * asserted in relevant cases.  interrupt is masked.
 */

#define BP_DVFSC_CNTR_FSVAIM      22
#define BM_DVFSC_CNTR_FSVAIM      0x00400000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_FSVAIM(v)   ((((reg32_t) v) << 22) & BM_DVFSC_CNTR_FSVAIM)
#else
#define BF_DVFSC_CNTR_FSVAIM(v)   (((v) << 22) & BM_DVFSC_CNTR_FSVAIM)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_FSVAIM(v)   BF_CS1(DVFSC_CNTR, FSVAIM, v)
#endif

/* --- Register HW_DVFSC_CNTR, field PIRQS
 *
 * PIRQS - Pattern IRQ Source  * write '1' to clear. Writing '1' will clear interrupt if interrupt
 * was from pattern
 */

#define BP_DVFSC_CNTR_PIRQS      23
#define BM_DVFSC_CNTR_PIRQS      0x00800000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_PIRQS(v)   ((((reg32_t) v) << 23) & BM_DVFSC_CNTR_PIRQS)
#else
#define BF_DVFSC_CNTR_PIRQS(v)   (((v) << 23) & BM_DVFSC_CNTR_PIRQS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_PIRQS(v)   BF_CS1(DVFSC_CNTR, PIRQS, v)
#endif

/* --- Register HW_DVFSC_CNTR, field DVFIS
 *
 * DVFS Interrupt select. These bits define destination of DVFS
 * interrupts.  ARM platform interrupt will be generated for DVFS events.
 */

#define BP_DVFSC_CNTR_DVFIS      24
#define BM_DVFSC_CNTR_DVFIS      0x01000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_DVFIS(v)   ((((reg32_t) v) << 24) & BM_DVFSC_CNTR_DVFIS)
#else
#define BF_DVFSC_CNTR_DVFIS(v)   (((v) << 24) & BM_DVFSC_CNTR_DVFIS)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_DVFIS(v)   BF_CS1(DVFSC_CNTR, DVFIS, v)
#endif

/* --- Register HW_DVFSC_CNTR, field LBFL0
 *
 * Load buffer 0 - full status bit. This bit indicates that log buffer
 * registers are full. The bit is set to 1 automatically.  An interrupt will be generated if LBMI
 * bit is set to "0"  Load buffer1 is full.  Write '1' to clear. (write '0' leaves bit unchanged)
 */

#define BP_DVFSC_CNTR_LBFL0      25
#define BM_DVFSC_CNTR_LBFL0      0x02000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_LBFL0(v)   ((((reg32_t) v) << 25) & BM_DVFSC_CNTR_LBFL0)
#else
#define BF_DVFSC_CNTR_LBFL0(v)   (((v) << 25) & BM_DVFSC_CNTR_LBFL0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_LBFL0(v)   BF_CS1(DVFSC_CNTR, LBFL0, v)
#endif

/* --- Register HW_DVFSC_CNTR, field LBFL1
 *
 * Load buffer 1 - full status bit. This bit indicates that log buffer
 * registers are full. The bit is set to 1 automatically.  An interrupt will be generated if LBMI
 * bit is set to '0'  Load buffer0 is full.Write '1' to clear.  (write '0' leaves bit unchanged)
 */

#define BP_DVFSC_CNTR_LBFL1      26
#define BM_DVFSC_CNTR_LBFL1      0x04000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_LBFL1(v)   ((((reg32_t) v) << 26) & BM_DVFSC_CNTR_LBFL1)
#else
#define BF_DVFSC_CNTR_LBFL1(v)   (((v) << 26) & BM_DVFSC_CNTR_LBFL1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_LBFL1(v)   BF_CS1(DVFSC_CNTR, LBFL1, v)
#endif

/* --- Register HW_DVFSC_CNTR, field LBMI
 *
 * Load buffer full mask interrupt. This bit masks the generation of
 * this interrupt.  Load buffer full interrupt is masked (LBFL0 and LBFL1 bits still will
 * be updated, but interrupt won't be generated)
 */

#define BP_DVFSC_CNTR_LBMI      27
#define BM_DVFSC_CNTR_LBMI      0x08000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_LBMI(v)   ((((reg32_t) v) << 27) & BM_DVFSC_CNTR_LBMI)
#else
#define BF_DVFSC_CNTR_LBMI(v)   (((v) << 27) & BM_DVFSC_CNTR_LBMI)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_LBMI(v)   BF_CS1(DVFSC_CNTR, LBMI, v)
#endif

/* --- Register HW_DVFSC_CNTR, field DVFEV
 *
 * Always give a DVFS event.
 */

#define BP_DVFSC_CNTR_DVFEV      28
#define BM_DVFSC_CNTR_DVFEV      0x10000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_DVFEV(v)   ((((reg32_t) v) << 28) & BM_DVFSC_CNTR_DVFEV)
#else
#define BF_DVFSC_CNTR_DVFEV(v)   (((v) << 28) & BM_DVFSC_CNTR_DVFEV)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_DVFEV(v)   BF_CS1(DVFSC_CNTR, DVFEV, v)
#endif

/* --- Register HW_DVFSC_CNTR, field DIV3CK
 *
 * DIV3CK - div_3_clk division ratio inside the DVFSC. According to the
 */

#define BP_DVFSC_CNTR_DIV3CK      29
#define BM_DVFSC_CNTR_DIV3CK      0xe0000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_CNTR_DIV3CK(v)   ((((reg32_t) v) << 29) & BM_DVFSC_CNTR_DIV3CK)
#else
#define BF_DVFSC_CNTR_DIV3CK(v)   (((v) << 29) & BM_DVFSC_CNTR_DIV3CK)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_CNTR_DIV3CK(v)   BF_CS1(DVFSC_CNTR, DIV3CK, v)
#endif

/*!
 * @brief HW_DVFSC_LTR0_0 - DVFSC Load Tracking Register 0, portion 0
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LTS0_0 : 4; //!< Load Tracking Sample 0
        unsigned LTS0_1 : 4; //!< Load Tracking Sample 1
        unsigned LTS0_2 : 4; //!< Load Tracking Sample 2
        unsigned LTS0_3 : 4; //!< Load Tracking Sample 3
        unsigned LTS0_4 : 4; //!< Load Tracking Sample 4
        unsigned LTS0_5 : 4; //!< Load Tracking Sample 5
        unsigned LTS0_6 : 4; //!< Load Tracking Sample 6
        unsigned LTS0_7 : 4; //!< Load Tracking Sample 7
    } B;
} hw_dvfsc_ltr0_0_t;
#endif

/*
 * constants & macros for entire DVFSC_LTR0_0 register
 */
#define HW_DVFSC_LTR0_0_ADDR      (REGS_DVFSC_BASE + 0x24)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_LTR0_0           (*(volatile hw_dvfsc_ltr0_0_t *) HW_DVFSC_LTR0_0_ADDR)
#define HW_DVFSC_LTR0_0_RD()      (HW_DVFSC_LTR0_0.U)
#define HW_DVFSC_LTR0_0_WR(v)     (HW_DVFSC_LTR0_0.U = (v))
#define HW_DVFSC_LTR0_0_SET(v)    (HW_DVFSC_LTR0_0_WR(HW_DVFSC_LTR0_0_RD() |  (v)))
#define HW_DVFSC_LTR0_0_CLR(v)    (HW_DVFSC_LTR0_0_WR(HW_DVFSC_LTR0_0_RD() & ~(v)))
#define HW_DVFSC_LTR0_0_TOG(v)    (HW_DVFSC_LTR0_0_WR(HW_DVFSC_LTR0_0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_LTR0_0 bitfields
 */

/* --- Register HW_DVFSC_LTR0_0, field LTS0_0
 *
 * Load Tracking Sample 0
 */

#define BP_DVFSC_LTR0_0_LTS0_0      0
#define BM_DVFSC_LTR0_0_LTS0_0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_0(v)   ((((reg32_t) v) << 0) & BM_DVFSC_LTR0_0_LTS0_0)
#else
#define BF_DVFSC_LTR0_0_LTS0_0(v)   (((v) << 0) & BM_DVFSC_LTR0_0_LTS0_0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_0(v)   BF_CS1(DVFSC_LTR0_0, LTS0_0, v)
#endif

/* --- Register HW_DVFSC_LTR0_0, field LTS0_1
 *
 * Load Tracking Sample 1
 */

#define BP_DVFSC_LTR0_0_LTS0_1      4
#define BM_DVFSC_LTR0_0_LTS0_1      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_1(v)   ((((reg32_t) v) << 4) & BM_DVFSC_LTR0_0_LTS0_1)
#else
#define BF_DVFSC_LTR0_0_LTS0_1(v)   (((v) << 4) & BM_DVFSC_LTR0_0_LTS0_1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_1(v)   BF_CS1(DVFSC_LTR0_0, LTS0_1, v)
#endif

/* --- Register HW_DVFSC_LTR0_0, field LTS0_2
 *
 * Load Tracking Sample 2
 */

#define BP_DVFSC_LTR0_0_LTS0_2      8
#define BM_DVFSC_LTR0_0_LTS0_2      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_2(v)   ((((reg32_t) v) << 8) & BM_DVFSC_LTR0_0_LTS0_2)
#else
#define BF_DVFSC_LTR0_0_LTS0_2(v)   (((v) << 8) & BM_DVFSC_LTR0_0_LTS0_2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_2(v)   BF_CS1(DVFSC_LTR0_0, LTS0_2, v)
#endif

/* --- Register HW_DVFSC_LTR0_0, field LTS0_3
 *
 * Load Tracking Sample 3
 */

#define BP_DVFSC_LTR0_0_LTS0_3      12
#define BM_DVFSC_LTR0_0_LTS0_3      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_3(v)   ((((reg32_t) v) << 12) & BM_DVFSC_LTR0_0_LTS0_3)
#else
#define BF_DVFSC_LTR0_0_LTS0_3(v)   (((v) << 12) & BM_DVFSC_LTR0_0_LTS0_3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_3(v)   BF_CS1(DVFSC_LTR0_0, LTS0_3, v)
#endif

/* --- Register HW_DVFSC_LTR0_0, field LTS0_4
 *
 * Load Tracking Sample 4
 */

#define BP_DVFSC_LTR0_0_LTS0_4      16
#define BM_DVFSC_LTR0_0_LTS0_4      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_4(v)   ((((reg32_t) v) << 16) & BM_DVFSC_LTR0_0_LTS0_4)
#else
#define BF_DVFSC_LTR0_0_LTS0_4(v)   (((v) << 16) & BM_DVFSC_LTR0_0_LTS0_4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_4(v)   BF_CS1(DVFSC_LTR0_0, LTS0_4, v)
#endif

/* --- Register HW_DVFSC_LTR0_0, field LTS0_5
 *
 * Load Tracking Sample 5
 */

#define BP_DVFSC_LTR0_0_LTS0_5      20
#define BM_DVFSC_LTR0_0_LTS0_5      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_5(v)   ((((reg32_t) v) << 20) & BM_DVFSC_LTR0_0_LTS0_5)
#else
#define BF_DVFSC_LTR0_0_LTS0_5(v)   (((v) << 20) & BM_DVFSC_LTR0_0_LTS0_5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_5(v)   BF_CS1(DVFSC_LTR0_0, LTS0_5, v)
#endif

/* --- Register HW_DVFSC_LTR0_0, field LTS0_6
 *
 * Load Tracking Sample 6
 */

#define BP_DVFSC_LTR0_0_LTS0_6      24
#define BM_DVFSC_LTR0_0_LTS0_6      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_6(v)   ((((reg32_t) v) << 24) & BM_DVFSC_LTR0_0_LTS0_6)
#else
#define BF_DVFSC_LTR0_0_LTS0_6(v)   (((v) << 24) & BM_DVFSC_LTR0_0_LTS0_6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_6(v)   BF_CS1(DVFSC_LTR0_0, LTS0_6, v)
#endif

/* --- Register HW_DVFSC_LTR0_0, field LTS0_7
 *
 * Load Tracking Sample 7
 */

#define BP_DVFSC_LTR0_0_LTS0_7      28
#define BM_DVFSC_LTR0_0_LTS0_7      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_0_LTS0_7(v)   ((((reg32_t) v) << 28) & BM_DVFSC_LTR0_0_LTS0_7)
#else
#define BF_DVFSC_LTR0_0_LTS0_7(v)   (((v) << 28) & BM_DVFSC_LTR0_0_LTS0_7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_0_LTS0_7(v)   BF_CS1(DVFSC_LTR0_0, LTS0_7, v)
#endif

/*!
 * @brief HW_DVFSC_LTR0_1 - DVFSC Load Tracking Register 0, portion 1
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LTS0_8 : 4; //!< Load Tracking Sample 8
        unsigned LTS0_9 : 4; //!< Load Tracking Sample 9
        unsigned LTS0_10 : 4; //!< Load Tracking Sample 10
        unsigned LTS0_11 : 4; //!< Load Tracking Sample 11
        unsigned LTS0_12 : 4; //!< Load Tracking Sample 12
        unsigned LTS0_13 : 4; //!< Load Tracking Sample 13
        unsigned LTS0_14 : 4; //!< Load Tracking Sample 14
        unsigned LTS0_15 : 4; //!< Load Tracking Sample 15
    } B;
} hw_dvfsc_ltr0_1_t;
#endif

/*
 * constants & macros for entire DVFSC_LTR0_1 register
 */
#define HW_DVFSC_LTR0_1_ADDR      (REGS_DVFSC_BASE + 0x28)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_LTR0_1           (*(volatile hw_dvfsc_ltr0_1_t *) HW_DVFSC_LTR0_1_ADDR)
#define HW_DVFSC_LTR0_1_RD()      (HW_DVFSC_LTR0_1.U)
#define HW_DVFSC_LTR0_1_WR(v)     (HW_DVFSC_LTR0_1.U = (v))
#define HW_DVFSC_LTR0_1_SET(v)    (HW_DVFSC_LTR0_1_WR(HW_DVFSC_LTR0_1_RD() |  (v)))
#define HW_DVFSC_LTR0_1_CLR(v)    (HW_DVFSC_LTR0_1_WR(HW_DVFSC_LTR0_1_RD() & ~(v)))
#define HW_DVFSC_LTR0_1_TOG(v)    (HW_DVFSC_LTR0_1_WR(HW_DVFSC_LTR0_1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_LTR0_1 bitfields
 */

/* --- Register HW_DVFSC_LTR0_1, field LTS0_8
 *
 * Load Tracking Sample 8
 */

#define BP_DVFSC_LTR0_1_LTS0_8      0
#define BM_DVFSC_LTR0_1_LTS0_8      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_8(v)   ((((reg32_t) v) << 0) & BM_DVFSC_LTR0_1_LTS0_8)
#else
#define BF_DVFSC_LTR0_1_LTS0_8(v)   (((v) << 0) & BM_DVFSC_LTR0_1_LTS0_8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_8(v)   BF_CS1(DVFSC_LTR0_1, LTS0_8, v)
#endif

/* --- Register HW_DVFSC_LTR0_1, field LTS0_9
 *
 * Load Tracking Sample 9
 */

#define BP_DVFSC_LTR0_1_LTS0_9      4
#define BM_DVFSC_LTR0_1_LTS0_9      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_9(v)   ((((reg32_t) v) << 4) & BM_DVFSC_LTR0_1_LTS0_9)
#else
#define BF_DVFSC_LTR0_1_LTS0_9(v)   (((v) << 4) & BM_DVFSC_LTR0_1_LTS0_9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_9(v)   BF_CS1(DVFSC_LTR0_1, LTS0_9, v)
#endif

/* --- Register HW_DVFSC_LTR0_1, field LTS0_10
 *
 * Load Tracking Sample 10
 */

#define BP_DVFSC_LTR0_1_LTS0_10      8
#define BM_DVFSC_LTR0_1_LTS0_10      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_10(v)   ((((reg32_t) v) << 8) & BM_DVFSC_LTR0_1_LTS0_10)
#else
#define BF_DVFSC_LTR0_1_LTS0_10(v)   (((v) << 8) & BM_DVFSC_LTR0_1_LTS0_10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_10(v)   BF_CS1(DVFSC_LTR0_1, LTS0_10, v)
#endif

/* --- Register HW_DVFSC_LTR0_1, field LTS0_11
 *
 * Load Tracking Sample 11
 */

#define BP_DVFSC_LTR0_1_LTS0_11      12
#define BM_DVFSC_LTR0_1_LTS0_11      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_11(v)   ((((reg32_t) v) << 12) & BM_DVFSC_LTR0_1_LTS0_11)
#else
#define BF_DVFSC_LTR0_1_LTS0_11(v)   (((v) << 12) & BM_DVFSC_LTR0_1_LTS0_11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_11(v)   BF_CS1(DVFSC_LTR0_1, LTS0_11, v)
#endif

/* --- Register HW_DVFSC_LTR0_1, field LTS0_12
 *
 * Load Tracking Sample 12
 */

#define BP_DVFSC_LTR0_1_LTS0_12      16
#define BM_DVFSC_LTR0_1_LTS0_12      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_12(v)   ((((reg32_t) v) << 16) & BM_DVFSC_LTR0_1_LTS0_12)
#else
#define BF_DVFSC_LTR0_1_LTS0_12(v)   (((v) << 16) & BM_DVFSC_LTR0_1_LTS0_12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_12(v)   BF_CS1(DVFSC_LTR0_1, LTS0_12, v)
#endif

/* --- Register HW_DVFSC_LTR0_1, field LTS0_13
 *
 * Load Tracking Sample 13
 */

#define BP_DVFSC_LTR0_1_LTS0_13      20
#define BM_DVFSC_LTR0_1_LTS0_13      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_13(v)   ((((reg32_t) v) << 20) & BM_DVFSC_LTR0_1_LTS0_13)
#else
#define BF_DVFSC_LTR0_1_LTS0_13(v)   (((v) << 20) & BM_DVFSC_LTR0_1_LTS0_13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_13(v)   BF_CS1(DVFSC_LTR0_1, LTS0_13, v)
#endif

/* --- Register HW_DVFSC_LTR0_1, field LTS0_14
 *
 * Load Tracking Sample 14
 */

#define BP_DVFSC_LTR0_1_LTS0_14      24
#define BM_DVFSC_LTR0_1_LTS0_14      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_14(v)   ((((reg32_t) v) << 24) & BM_DVFSC_LTR0_1_LTS0_14)
#else
#define BF_DVFSC_LTR0_1_LTS0_14(v)   (((v) << 24) & BM_DVFSC_LTR0_1_LTS0_14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_14(v)   BF_CS1(DVFSC_LTR0_1, LTS0_14, v)
#endif

/* --- Register HW_DVFSC_LTR0_1, field LTS0_15
 *
 * Load Tracking Sample 15
 */

#define BP_DVFSC_LTR0_1_LTS0_15      28
#define BM_DVFSC_LTR0_1_LTS0_15      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR0_1_LTS0_15(v)   ((((reg32_t) v) << 28) & BM_DVFSC_LTR0_1_LTS0_15)
#else
#define BF_DVFSC_LTR0_1_LTS0_15(v)   (((v) << 28) & BM_DVFSC_LTR0_1_LTS0_15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR0_1_LTS0_15(v)   BF_CS1(DVFSC_LTR0_1, LTS0_15, v)
#endif

/*!
 * @brief HW_DVFSC_LTR1_0 - DVFSC Load Tracking Register 1, portion 0
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LTS1_0 : 4; //!< Load Tracking Sample 0
        unsigned LTS1_1 : 4; //!< Load Tracking Sample 1
        unsigned LTS1_2 : 4; //!< Load Tracking Sample 2
        unsigned LTS1_3 : 4; //!< Load Tracking Sample 3
        unsigned LTS1_4 : 4; //!< Load Tracking Sample 4
        unsigned LTS1_5 : 4; //!< Load Tracking Sample 5
        unsigned LTS1_6 : 4; //!< Load Tracking Sample 6
        unsigned LTS1_7 : 4; //!< Load Tracking Sample 7
    } B;
} hw_dvfsc_ltr1_0_t;
#endif

/*
 * constants & macros for entire DVFSC_LTR1_0 register
 */
#define HW_DVFSC_LTR1_0_ADDR      (REGS_DVFSC_BASE + 0x2c)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_LTR1_0           (*(volatile hw_dvfsc_ltr1_0_t *) HW_DVFSC_LTR1_0_ADDR)
#define HW_DVFSC_LTR1_0_RD()      (HW_DVFSC_LTR1_0.U)
#define HW_DVFSC_LTR1_0_WR(v)     (HW_DVFSC_LTR1_0.U = (v))
#define HW_DVFSC_LTR1_0_SET(v)    (HW_DVFSC_LTR1_0_WR(HW_DVFSC_LTR1_0_RD() |  (v)))
#define HW_DVFSC_LTR1_0_CLR(v)    (HW_DVFSC_LTR1_0_WR(HW_DVFSC_LTR1_0_RD() & ~(v)))
#define HW_DVFSC_LTR1_0_TOG(v)    (HW_DVFSC_LTR1_0_WR(HW_DVFSC_LTR1_0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_LTR1_0 bitfields
 */

/* --- Register HW_DVFSC_LTR1_0, field LTS1_0
 *
 * Load Tracking Sample 0
 */

#define BP_DVFSC_LTR1_0_LTS1_0      0
#define BM_DVFSC_LTR1_0_LTS1_0      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_0(v)   ((((reg32_t) v) << 0) & BM_DVFSC_LTR1_0_LTS1_0)
#else
#define BF_DVFSC_LTR1_0_LTS1_0(v)   (((v) << 0) & BM_DVFSC_LTR1_0_LTS1_0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_0(v)   BF_CS1(DVFSC_LTR1_0, LTS1_0, v)
#endif

/* --- Register HW_DVFSC_LTR1_0, field LTS1_1
 *
 * Load Tracking Sample 1
 */

#define BP_DVFSC_LTR1_0_LTS1_1      4
#define BM_DVFSC_LTR1_0_LTS1_1      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_1(v)   ((((reg32_t) v) << 4) & BM_DVFSC_LTR1_0_LTS1_1)
#else
#define BF_DVFSC_LTR1_0_LTS1_1(v)   (((v) << 4) & BM_DVFSC_LTR1_0_LTS1_1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_1(v)   BF_CS1(DVFSC_LTR1_0, LTS1_1, v)
#endif

/* --- Register HW_DVFSC_LTR1_0, field LTS1_2
 *
 * Load Tracking Sample 2
 */

#define BP_DVFSC_LTR1_0_LTS1_2      8
#define BM_DVFSC_LTR1_0_LTS1_2      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_2(v)   ((((reg32_t) v) << 8) & BM_DVFSC_LTR1_0_LTS1_2)
#else
#define BF_DVFSC_LTR1_0_LTS1_2(v)   (((v) << 8) & BM_DVFSC_LTR1_0_LTS1_2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_2(v)   BF_CS1(DVFSC_LTR1_0, LTS1_2, v)
#endif

/* --- Register HW_DVFSC_LTR1_0, field LTS1_3
 *
 * Load Tracking Sample 3
 */

#define BP_DVFSC_LTR1_0_LTS1_3      12
#define BM_DVFSC_LTR1_0_LTS1_3      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_3(v)   ((((reg32_t) v) << 12) & BM_DVFSC_LTR1_0_LTS1_3)
#else
#define BF_DVFSC_LTR1_0_LTS1_3(v)   (((v) << 12) & BM_DVFSC_LTR1_0_LTS1_3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_3(v)   BF_CS1(DVFSC_LTR1_0, LTS1_3, v)
#endif

/* --- Register HW_DVFSC_LTR1_0, field LTS1_4
 *
 * Load Tracking Sample 4
 */

#define BP_DVFSC_LTR1_0_LTS1_4      16
#define BM_DVFSC_LTR1_0_LTS1_4      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_4(v)   ((((reg32_t) v) << 16) & BM_DVFSC_LTR1_0_LTS1_4)
#else
#define BF_DVFSC_LTR1_0_LTS1_4(v)   (((v) << 16) & BM_DVFSC_LTR1_0_LTS1_4)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_4(v)   BF_CS1(DVFSC_LTR1_0, LTS1_4, v)
#endif

/* --- Register HW_DVFSC_LTR1_0, field LTS1_5
 *
 * Load Tracking Sample 5
 */

#define BP_DVFSC_LTR1_0_LTS1_5      20
#define BM_DVFSC_LTR1_0_LTS1_5      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_5(v)   ((((reg32_t) v) << 20) & BM_DVFSC_LTR1_0_LTS1_5)
#else
#define BF_DVFSC_LTR1_0_LTS1_5(v)   (((v) << 20) & BM_DVFSC_LTR1_0_LTS1_5)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_5(v)   BF_CS1(DVFSC_LTR1_0, LTS1_5, v)
#endif

/* --- Register HW_DVFSC_LTR1_0, field LTS1_6
 *
 * Load Tracking Sample 6
 */

#define BP_DVFSC_LTR1_0_LTS1_6      24
#define BM_DVFSC_LTR1_0_LTS1_6      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_6(v)   ((((reg32_t) v) << 24) & BM_DVFSC_LTR1_0_LTS1_6)
#else
#define BF_DVFSC_LTR1_0_LTS1_6(v)   (((v) << 24) & BM_DVFSC_LTR1_0_LTS1_6)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_6(v)   BF_CS1(DVFSC_LTR1_0, LTS1_6, v)
#endif

/* --- Register HW_DVFSC_LTR1_0, field LTS1_7
 *
 * Load Tracking Sample 7
 */

#define BP_DVFSC_LTR1_0_LTS1_7      28
#define BM_DVFSC_LTR1_0_LTS1_7      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_0_LTS1_7(v)   ((((reg32_t) v) << 28) & BM_DVFSC_LTR1_0_LTS1_7)
#else
#define BF_DVFSC_LTR1_0_LTS1_7(v)   (((v) << 28) & BM_DVFSC_LTR1_0_LTS1_7)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_0_LTS1_7(v)   BF_CS1(DVFSC_LTR1_0, LTS1_7, v)
#endif

/*!
 * @brief HW_DVFSC_LTR1_1 - DVFS Load Tracking Register 3, portion 1
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned LTS1_8 : 4; //!< Load Tracking Sample 8
        unsigned LTS1_9 : 4; //!< Load Tracking Sample 9
        unsigned LTS1_10 : 4; //!< Load Tracking Sample 10
        unsigned LTS1_11 : 4; //!< Load Tracking Sample 11
        unsigned LTS1_12 : 4; //!< Load Tracking Sample 12
        unsigned LTS1_13 : 4; //!< Load Tracking Sample 13
        unsigned LTS1_14 : 4; //!< Load Tracking Sample 14
        unsigned LTS1_15 : 4; //!< Load Tracking Sample 15
    } B;
} hw_dvfsc_ltr1_1_t;
#endif

/*
 * constants & macros for entire DVFSC_LTR1_1 register
 */
#define HW_DVFSC_LTR1_1_ADDR      (REGS_DVFSC_BASE + 0x30)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_LTR1_1           (*(volatile hw_dvfsc_ltr1_1_t *) HW_DVFSC_LTR1_1_ADDR)
#define HW_DVFSC_LTR1_1_RD()      (HW_DVFSC_LTR1_1.U)
#define HW_DVFSC_LTR1_1_WR(v)     (HW_DVFSC_LTR1_1.U = (v))
#define HW_DVFSC_LTR1_1_SET(v)    (HW_DVFSC_LTR1_1_WR(HW_DVFSC_LTR1_1_RD() |  (v)))
#define HW_DVFSC_LTR1_1_CLR(v)    (HW_DVFSC_LTR1_1_WR(HW_DVFSC_LTR1_1_RD() & ~(v)))
#define HW_DVFSC_LTR1_1_TOG(v)    (HW_DVFSC_LTR1_1_WR(HW_DVFSC_LTR1_1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_LTR1_1 bitfields
 */

/* --- Register HW_DVFSC_LTR1_1, field LTS1_8
 *
 * Load Tracking Sample 8
 */

#define BP_DVFSC_LTR1_1_LTS1_8      0
#define BM_DVFSC_LTR1_1_LTS1_8      0x0000000f

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_8(v)   ((((reg32_t) v) << 0) & BM_DVFSC_LTR1_1_LTS1_8)
#else
#define BF_DVFSC_LTR1_1_LTS1_8(v)   (((v) << 0) & BM_DVFSC_LTR1_1_LTS1_8)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_8(v)   BF_CS1(DVFSC_LTR1_1, LTS1_8, v)
#endif

/* --- Register HW_DVFSC_LTR1_1, field LTS1_9
 *
 * Load Tracking Sample 9
 */

#define BP_DVFSC_LTR1_1_LTS1_9      4
#define BM_DVFSC_LTR1_1_LTS1_9      0x000000f0

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_9(v)   ((((reg32_t) v) << 4) & BM_DVFSC_LTR1_1_LTS1_9)
#else
#define BF_DVFSC_LTR1_1_LTS1_9(v)   (((v) << 4) & BM_DVFSC_LTR1_1_LTS1_9)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_9(v)   BF_CS1(DVFSC_LTR1_1, LTS1_9, v)
#endif

/* --- Register HW_DVFSC_LTR1_1, field LTS1_10
 *
 * Load Tracking Sample 10
 */

#define BP_DVFSC_LTR1_1_LTS1_10      8
#define BM_DVFSC_LTR1_1_LTS1_10      0x00000f00

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_10(v)   ((((reg32_t) v) << 8) & BM_DVFSC_LTR1_1_LTS1_10)
#else
#define BF_DVFSC_LTR1_1_LTS1_10(v)   (((v) << 8) & BM_DVFSC_LTR1_1_LTS1_10)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_10(v)   BF_CS1(DVFSC_LTR1_1, LTS1_10, v)
#endif

/* --- Register HW_DVFSC_LTR1_1, field LTS1_11
 *
 * Load Tracking Sample 11
 */

#define BP_DVFSC_LTR1_1_LTS1_11      12
#define BM_DVFSC_LTR1_1_LTS1_11      0x0000f000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_11(v)   ((((reg32_t) v) << 12) & BM_DVFSC_LTR1_1_LTS1_11)
#else
#define BF_DVFSC_LTR1_1_LTS1_11(v)   (((v) << 12) & BM_DVFSC_LTR1_1_LTS1_11)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_11(v)   BF_CS1(DVFSC_LTR1_1, LTS1_11, v)
#endif

/* --- Register HW_DVFSC_LTR1_1, field LTS1_12
 *
 * Load Tracking Sample 12
 */

#define BP_DVFSC_LTR1_1_LTS1_12      16
#define BM_DVFSC_LTR1_1_LTS1_12      0x000f0000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_12(v)   ((((reg32_t) v) << 16) & BM_DVFSC_LTR1_1_LTS1_12)
#else
#define BF_DVFSC_LTR1_1_LTS1_12(v)   (((v) << 16) & BM_DVFSC_LTR1_1_LTS1_12)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_12(v)   BF_CS1(DVFSC_LTR1_1, LTS1_12, v)
#endif

/* --- Register HW_DVFSC_LTR1_1, field LTS1_13
 *
 * Load Tracking Sample 13
 */

#define BP_DVFSC_LTR1_1_LTS1_13      20
#define BM_DVFSC_LTR1_1_LTS1_13      0x00f00000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_13(v)   ((((reg32_t) v) << 20) & BM_DVFSC_LTR1_1_LTS1_13)
#else
#define BF_DVFSC_LTR1_1_LTS1_13(v)   (((v) << 20) & BM_DVFSC_LTR1_1_LTS1_13)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_13(v)   BF_CS1(DVFSC_LTR1_1, LTS1_13, v)
#endif

/* --- Register HW_DVFSC_LTR1_1, field LTS1_14
 *
 * Load Tracking Sample 14
 */

#define BP_DVFSC_LTR1_1_LTS1_14      24
#define BM_DVFSC_LTR1_1_LTS1_14      0x0f000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_14(v)   ((((reg32_t) v) << 24) & BM_DVFSC_LTR1_1_LTS1_14)
#else
#define BF_DVFSC_LTR1_1_LTS1_14(v)   (((v) << 24) & BM_DVFSC_LTR1_1_LTS1_14)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_14(v)   BF_CS1(DVFSC_LTR1_1, LTS1_14, v)
#endif

/* --- Register HW_DVFSC_LTR1_1, field LTS1_15
 *
 * Load Tracking Sample 15
 */

#define BP_DVFSC_LTR1_1_LTS1_15      28
#define BM_DVFSC_LTR1_1_LTS1_15      0xf0000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_LTR1_1_LTS1_15(v)   ((((reg32_t) v) << 28) & BM_DVFSC_LTR1_1_LTS1_15)
#else
#define BF_DVFSC_LTR1_1_LTS1_15(v)   (((v) << 28) & BM_DVFSC_LTR1_1_LTS1_15)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_LTR1_1_LTS1_15(v)   BF_CS1(DVFSC_LTR1_1, LTS1_15, v)
#endif

/*!
 * @brief HW_DVFSC_PT0 - DVFSC pattern 0 length
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FPTN0 : 17; //!< FPTN0 - Frequency pattern 0 counter  During period of this counter the frequency will be reduced from the EMA-detected level.
        unsigned PT0A : 1; //!< PT0A - Pattern 0 currently active (read-only)
        unsigned RESERVED0 : 14; //!< Reserved
    } B;
} hw_dvfsc_pt0_t;
#endif

/*
 * constants & macros for entire DVFSC_PT0 register
 */
#define HW_DVFSC_PT0_ADDR      (REGS_DVFSC_BASE + 0x34)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_PT0           (*(volatile hw_dvfsc_pt0_t *) HW_DVFSC_PT0_ADDR)
#define HW_DVFSC_PT0_RD()      (HW_DVFSC_PT0.U)
#define HW_DVFSC_PT0_WR(v)     (HW_DVFSC_PT0.U = (v))
#define HW_DVFSC_PT0_SET(v)    (HW_DVFSC_PT0_WR(HW_DVFSC_PT0_RD() |  (v)))
#define HW_DVFSC_PT0_CLR(v)    (HW_DVFSC_PT0_WR(HW_DVFSC_PT0_RD() & ~(v)))
#define HW_DVFSC_PT0_TOG(v)    (HW_DVFSC_PT0_WR(HW_DVFSC_PT0_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_PT0 bitfields
 */

/* --- Register HW_DVFSC_PT0, field FPTN0
 *
 * FPTN0 - Frequency pattern 0 counter  During period of this counter the frequency will be reduced
 * from the                                 EMA-detected level.
 */

#define BP_DVFSC_PT0_FPTN0      0
#define BM_DVFSC_PT0_FPTN0      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT0_FPTN0(v)   ((((reg32_t) v) << 0) & BM_DVFSC_PT0_FPTN0)
#else
#define BF_DVFSC_PT0_FPTN0(v)   (((v) << 0) & BM_DVFSC_PT0_FPTN0)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT0_FPTN0(v)   BF_CS1(DVFSC_PT0, FPTN0, v)
#endif

/* --- Register HW_DVFSC_PT0, field PT0A
 *
 * PT0A - Pattern 0 currently active (read-only)
 */

#define BP_DVFSC_PT0_PT0A      17
#define BM_DVFSC_PT0_PT0A      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT0_PT0A(v)   ((((reg32_t) v) << 17) & BM_DVFSC_PT0_PT0A)
#else
#define BF_DVFSC_PT0_PT0A(v)   (((v) << 17) & BM_DVFSC_PT0_PT0A)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT0_PT0A(v)   BF_CS1(DVFSC_PT0, PT0A, v)
#endif

/*!
 * @brief HW_DVFSC_PT1 - DVFSC pattern 1 length
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FPTN1 : 17; //!< FPTN1 - Frequency pattern 1 counter  During period of this counter the frequency will be set to the EMA-detected level.
        unsigned PT1A : 1; //!< PT1A - Pattern 1 currently active (read-only)
        unsigned RESERVED0 : 14; //!< Reserved
    } B;
} hw_dvfsc_pt1_t;
#endif

/*
 * constants & macros for entire DVFSC_PT1 register
 */
#define HW_DVFSC_PT1_ADDR      (REGS_DVFSC_BASE + 0x38)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_PT1           (*(volatile hw_dvfsc_pt1_t *) HW_DVFSC_PT1_ADDR)
#define HW_DVFSC_PT1_RD()      (HW_DVFSC_PT1.U)
#define HW_DVFSC_PT1_WR(v)     (HW_DVFSC_PT1.U = (v))
#define HW_DVFSC_PT1_SET(v)    (HW_DVFSC_PT1_WR(HW_DVFSC_PT1_RD() |  (v)))
#define HW_DVFSC_PT1_CLR(v)    (HW_DVFSC_PT1_WR(HW_DVFSC_PT1_RD() & ~(v)))
#define HW_DVFSC_PT1_TOG(v)    (HW_DVFSC_PT1_WR(HW_DVFSC_PT1_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_PT1 bitfields
 */

/* --- Register HW_DVFSC_PT1, field FPTN1
 *
 * FPTN1 - Frequency pattern 1 counter  During period of this counter the frequency will be set to
 * the                                 EMA-detected level.
 */

#define BP_DVFSC_PT1_FPTN1      0
#define BM_DVFSC_PT1_FPTN1      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT1_FPTN1(v)   ((((reg32_t) v) << 0) & BM_DVFSC_PT1_FPTN1)
#else
#define BF_DVFSC_PT1_FPTN1(v)   (((v) << 0) & BM_DVFSC_PT1_FPTN1)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT1_FPTN1(v)   BF_CS1(DVFSC_PT1, FPTN1, v)
#endif

/* --- Register HW_DVFSC_PT1, field PT1A
 *
 * PT1A - Pattern 1 currently active (read-only)
 */

#define BP_DVFSC_PT1_PT1A      17
#define BM_DVFSC_PT1_PT1A      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT1_PT1A(v)   ((((reg32_t) v) << 17) & BM_DVFSC_PT1_PT1A)
#else
#define BF_DVFSC_PT1_PT1A(v)   (((v) << 17) & BM_DVFSC_PT1_PT1A)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT1_PT1A(v)   BF_CS1(DVFSC_PT1, PT1A, v)
#endif

/*!
 * @brief HW_DVFSC_PT2 - DVFSC pattern 2 length
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FPTN2 : 17; //!< FPTN2 - Frequency pattern 2 counter  During period of this counter the frequency will be increased to higher, than detected by the EMA-detected level.
        unsigned PT2A : 1; //!< PT2A - Pattern 2 currently active (read-only)
        unsigned RESERVED0 : 8; //!< Reserved
        unsigned P2THR : 6; //!< P2THR - Pattern 2 Threshold  Threshold of current DVFS load (after EMA), for generating interrupts with PFUS indicators 110, 111. If the current performance is greater than the P2THR value, the interrupts will be generated. Otherwise, pattern delay will be counted, but without interrupt generation.
    } B;
} hw_dvfsc_pt2_t;
#endif

/*
 * constants & macros for entire DVFSC_PT2 register
 */
#define HW_DVFSC_PT2_ADDR      (REGS_DVFSC_BASE + 0x3c)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_PT2           (*(volatile hw_dvfsc_pt2_t *) HW_DVFSC_PT2_ADDR)
#define HW_DVFSC_PT2_RD()      (HW_DVFSC_PT2.U)
#define HW_DVFSC_PT2_WR(v)     (HW_DVFSC_PT2.U = (v))
#define HW_DVFSC_PT2_SET(v)    (HW_DVFSC_PT2_WR(HW_DVFSC_PT2_RD() |  (v)))
#define HW_DVFSC_PT2_CLR(v)    (HW_DVFSC_PT2_WR(HW_DVFSC_PT2_RD() & ~(v)))
#define HW_DVFSC_PT2_TOG(v)    (HW_DVFSC_PT2_WR(HW_DVFSC_PT2_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_PT2 bitfields
 */

/* --- Register HW_DVFSC_PT2, field FPTN2
 *
 * FPTN2 - Frequency pattern 2 counter  During period of this counter the frequency will be
 * increased to                                 higher, than detected by the EMA-detected level.
 */

#define BP_DVFSC_PT2_FPTN2      0
#define BM_DVFSC_PT2_FPTN2      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT2_FPTN2(v)   ((((reg32_t) v) << 0) & BM_DVFSC_PT2_FPTN2)
#else
#define BF_DVFSC_PT2_FPTN2(v)   (((v) << 0) & BM_DVFSC_PT2_FPTN2)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT2_FPTN2(v)   BF_CS1(DVFSC_PT2, FPTN2, v)
#endif

/* --- Register HW_DVFSC_PT2, field PT2A
 *
 * PT2A - Pattern 2 currently active (read-only)
 */

#define BP_DVFSC_PT2_PT2A      17
#define BM_DVFSC_PT2_PT2A      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT2_PT2A(v)   ((((reg32_t) v) << 17) & BM_DVFSC_PT2_PT2A)
#else
#define BF_DVFSC_PT2_PT2A(v)   (((v) << 17) & BM_DVFSC_PT2_PT2A)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT2_PT2A(v)   BF_CS1(DVFSC_PT2, PT2A, v)
#endif

/* --- Register HW_DVFSC_PT2, field P2THR
 *
 * P2THR - Pattern 2 Threshold  Threshold of current DVFS load (after EMA), for generating
 * interrupts                                 with PFUS indicators 110, 111. If the current
 * performance is greater                                 than the P2THR value, the interrupts will
 * be generated. Otherwise,                                 pattern delay will be counted, but
 * without interrupt generation.
 */

#define BP_DVFSC_PT2_P2THR      26
#define BM_DVFSC_PT2_P2THR      0xfc000000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT2_P2THR(v)   ((((reg32_t) v) << 26) & BM_DVFSC_PT2_P2THR)
#else
#define BF_DVFSC_PT2_P2THR(v)   (((v) << 26) & BM_DVFSC_PT2_P2THR)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT2_P2THR(v)   BF_CS1(DVFSC_PT2, P2THR, v)
#endif

/*!
 * @brief HW_DVFSC_PT3 - DVFSC pattern 3 length
 *

 */
#ifndef __LANGUAGE_ASM__
typedef union
{
    reg32_t  U;
    struct
    {
        unsigned FPTN3 : 17; //!< FPTN3 - Frequency pattern 3 counter  During period of this counter the frequency will be set to the EMA-detected level.
        unsigned PT3A : 1; //!< PT3A - Pattern 3 currently active (read-only)
        unsigned RESERVED0 : 15; //!< Reserved
    } B;
} hw_dvfsc_pt3_t;
#endif

/*
 * constants & macros for entire DVFSC_PT3 register
 */
#define HW_DVFSC_PT3_ADDR      (REGS_DVFSC_BASE + 0x40)

#ifndef __LANGUAGE_ASM__
#define HW_DVFSC_PT3           (*(volatile hw_dvfsc_pt3_t *) HW_DVFSC_PT3_ADDR)
#define HW_DVFSC_PT3_RD()      (HW_DVFSC_PT3.U)
#define HW_DVFSC_PT3_WR(v)     (HW_DVFSC_PT3.U = (v))
#define HW_DVFSC_PT3_SET(v)    (HW_DVFSC_PT3_WR(HW_DVFSC_PT3_RD() |  (v)))
#define HW_DVFSC_PT3_CLR(v)    (HW_DVFSC_PT3_WR(HW_DVFSC_PT3_RD() & ~(v)))
#define HW_DVFSC_PT3_TOG(v)    (HW_DVFSC_PT3_WR(HW_DVFSC_PT3_RD() ^  (v)))
#endif


/*
 * constants & macros for individual DVFSC_PT3 bitfields
 */

/* --- Register HW_DVFSC_PT3, field FPTN3
 *
 * FPTN3 - Frequency pattern 3 counter  During period of this counter the frequency will be set to
 * the                                 EMA-detected level.
 */

#define BP_DVFSC_PT3_FPTN3      0
#define BM_DVFSC_PT3_FPTN3      0x0001ffff

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT3_FPTN3(v)   ((((reg32_t) v) << 0) & BM_DVFSC_PT3_FPTN3)
#else
#define BF_DVFSC_PT3_FPTN3(v)   (((v) << 0) & BM_DVFSC_PT3_FPTN3)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT3_FPTN3(v)   BF_CS1(DVFSC_PT3, FPTN3, v)
#endif

/* --- Register HW_DVFSC_PT3, field PT3A
 *
 * PT3A - Pattern 3 currently active (read-only)
 */

#define BP_DVFSC_PT3_PT3A      17
#define BM_DVFSC_PT3_PT3A      0x00020000

#ifndef __LANGUAGE_ASM__
#define BF_DVFSC_PT3_PT3A(v)   ((((reg32_t) v) << 17) & BM_DVFSC_PT3_PT3A)
#else
#define BF_DVFSC_PT3_PT3A(v)   (((v) << 17) & BM_DVFSC_PT3_PT3A)
#endif
#ifndef __LANGUAGE_ASM__
#define BW_DVFSC_PT3_PT3A(v)   BF_CS1(DVFSC_PT3, PT3A, v)
#endif



/*!
 * @brief All DVFSC module registers.
 */
#ifndef __LANGUAGE_ASM__
typedef struct
{
    volatile hw_dvfsc_thrs_t THRS; //!< DVFSC Thresholds
    volatile hw_dvfsc_coun_t COUN; //!< DVFSC Counters thresholds
    volatile hw_dvfsc_sig1_t SIG1; //!< DVFSC general purpose bits weight
    volatile hw_dvfsc_sig0_t SIG0; //!< DVFSC general purpose bits weight
    volatile hw_dvfsc_gpc0_t GPC0; //!< DVFSC general purpose bit 0 weight counter
    volatile hw_dvfsc_gpc1_t GPC1; //!< DVFSC general purpose bit 1 weight counter
    volatile hw_dvfsc_gpbt_t GPBT; //!< DVFSC general purpose bits enables
    volatile hw_dvfsc_emac_t EMAC; //!< DVFSC EMAC settings
    volatile hw_dvfsc_cntr_t CNTR; //!< DVFSC Control
    volatile hw_dvfsc_ltr0_0_t LTR0_0; //!< DVFSC Load Tracking Register 0, portion 0
    volatile hw_dvfsc_ltr0_1_t LTR0_1; //!< DVFSC Load Tracking Register 0, portion 1
    volatile hw_dvfsc_ltr1_0_t LTR1_0; //!< DVFSC Load Tracking Register 1, portion 0
    volatile hw_dvfsc_ltr1_1_t LTR1_1; //!< DVFS Load Tracking Register 3, portion 1
    volatile hw_dvfsc_pt0_t PT0; //!< DVFSC pattern 0 length
    volatile hw_dvfsc_pt1_t PT1; //!< DVFSC pattern 1 length
    volatile hw_dvfsc_pt2_t PT2; //!< DVFSC pattern 2 length
    volatile hw_dvfsc_pt3_t PT3; //!< DVFSC pattern 3 length
} hw_dvfsc_t
#endif

//! @brief Macro to access all DVFSC registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_DVFSC(0)</code>.
#define HW_DVFSC     (*(volatile hw_dvfsc_t *) REGS_DVFSC_BASE)


#endif // _DVFSC_H
