/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#ifndef __IMX_PERFMON_H__
#define	__IMX_PERFMON_H__

#define HW_PERFMON_CTRL	(0x00000000)
#define HW_PERFMON_CTRL_SET	(0x00000004)
#define HW_PERFMON_CTRL_CLR	(0x00000008)
#define HW_PERFMON_CTRL_TOG	(0x0000000c)

#define BM_PERFMON_CTRL_SFTRST	0x80000000
#define BV_PERFMON_CTRL_SFTRST__RUN   0x0
#define BV_PERFMON_CTRL_SFTRST__RESET 0x1
#define BM_PERFMON_CTRL_CLKGATE	0x40000000
#define BV_PERFMON_CTRL_CLKGATE__RUN     0x0
#define BV_PERFMON_CTRL_CLKGATE__NO_CLKS 0x1
#define BP_PERFMON_CTRL_RSVD2	24
#define BM_PERFMON_CTRL_RSVD2	0x3F000000
#define BF_PERFMON_CTRL_RSVD2(v)  \
		(((v) << 24) & BM_PERFMON_CTRL_RSVD2)
#define BP_PERFMON_CTRL_IRQ_MID	16
#define BM_PERFMON_CTRL_IRQ_MID	0x00FF0000
#define BF_PERFMON_CTRL_IRQ_MID(v)  \
		(((v) << 16) & BM_PERFMON_CTRL_IRQ_MID)
#define BP_PERFMON_CTRL_RSVD1	13
#define BM_PERFMON_CTRL_RSVD1	0x0000E000
#define BF_PERFMON_CTRL_RSVD1(v)  \
		(((v) << 13) & BM_PERFMON_CTRL_RSVD1)
#define BM_PERFMON_CTRL_BUS_ERR_IRQ	0x00001000
#define BM_PERFMON_CTRL_LATENCY_IRQ	0x00000800
#define BM_PERFMON_CTRL_TRAP_IRQ	0x00000400
#define BM_PERFMON_CTRL_BUS_ERR_IRQ_EN	0x00000200
#define BM_PERFMON_CTRL_LATENCY_IRQ_EN	0x00000100
#define BM_PERFMON_CTRL_TRAP_IRQ_EN	0x00000080
#define BM_PERFMON_CTRL_LATENCY_ENABLE	0x00000040
#define BM_PERFMON_CTRL_TRAP_IN_RANGE	0x00000020
#define BM_PERFMON_CTRL_TRAP_ENABLE	0x00000010
#define BM_PERFMON_CTRL_READ_EN	0x00000008
#define BM_PERFMON_CTRL_CLR	0x00000004
#define BM_PERFMON_CTRL_SNAP	0x00000002
#define BM_PERFMON_CTRL_RUN	0x00000001
#define BV_PERFMON_CTRL_RUN__HALT 0x0
#define BV_PERFMON_CTRL_RUN__RUN  0x1

#define HW_PERFMON_MASTER_EN	(0x00000010)

#define BP_PERFMON_MASTER_EN_RSVD0	16
#define BM_PERFMON_MASTER_EN_RSVD0	0xFFFF0000
#define BF_PERFMON_MASTER_EN_RSVD0(v) \
		(((v) << 16) & BM_PERFMON_MASTER_EN_RSVD0)
#define BM_PERFMON_MASTER_EN_MID15	0x00008000
#define BM_PERFMON_MASTER_EN_MID14	0x00004000
#define BM_PERFMON_MASTER_EN_MID13	0x00002000
#define BM_PERFMON_MASTER_EN_MID12	0x00001000
#define BM_PERFMON_MASTER_EN_MID11	0x00000800
#define BM_PERFMON_MASTER_EN_MID10	0x00000400
#define BM_PERFMON_MASTER_EN_MID9	0x00000200
#define BM_PERFMON_MASTER_EN_MID8	0x00000100
#define BM_PERFMON_MASTER_EN_MID7	0x00000080
#define BM_PERFMON_MASTER_EN_MID6	0x00000040
#define BM_PERFMON_MASTER_EN_MID5	0x00000020
#define BM_PERFMON_MASTER_EN_MID4	0x00000010
#define BM_PERFMON_MASTER_EN_MID3	0x00000008
#define BM_PERFMON_MASTER_EN_MID2	0x00000004
#define BM_PERFMON_MASTER_EN_MID1	0x00000002
#define BM_PERFMON_MASTER_EN_MID0	0x00000001

#define HW_PERFMON_TRAP_ADDR_LOW	(0x00000020)

#define BP_PERFMON_TRAP_ADDR_LOW_ADDR	0
#define BM_PERFMON_TRAP_ADDR_LOW_ADDR	0xFFFFFFFF
#define BF_PERFMON_TRAP_ADDR_LOW_ADDR(v)	(v)

#define HW_PERFMON_TRAP_ADDR_HIGH	(0x00000030)

#define BP_PERFMON_TRAP_ADDR_HIGH_ADDR	0
#define BM_PERFMON_TRAP_ADDR_HIGH_ADDR	0xFFFFFFFF
#define BF_PERFMON_TRAP_ADDR_HIGH_ADDR(v)	(v)

#define HW_PERFMON_LAT_THRESHOLD	(0x00000040)

#define BP_PERFMON_LAT_THRESHOLD_RSVD0	12
#define BM_PERFMON_LAT_THRESHOLD_RSVD0	0xFFFFF000
#define BF_PERFMON_LAT_THRESHOLD_RSVD0(v) \
		(((v) << 12) & BM_PERFMON_LAT_THRESHOLD_RSVD0)
#define BP_PERFMON_LAT_THRESHOLD_VALUE	0
#define BM_PERFMON_LAT_THRESHOLD_VALUE	0x00000FFF
#define BF_PERFMON_LAT_THRESHOLD_VALUE(v)  \
		(((v) << 0) & BM_PERFMON_LAT_THRESHOLD_VALUE)

#define HW_PERFMON_ACTIVE_CYCLE	(0x00000050)

#define BP_PERFMON_ACTIVE_CYCLE_COUNT	0
#define BM_PERFMON_ACTIVE_CYCLE_COUNT	0xFFFFFFFF
#define BF_PERFMON_ACTIVE_CYCLE_COUNT(v)	(v)

#define HW_PERFMON_TRANSFER_COUNT	(0x00000060)

#define BP_PERFMON_TRANSFER_COUNT_VALUE	0
#define BM_PERFMON_TRANSFER_COUNT_VALUE	0xFFFFFFFF
#define BF_PERFMON_TRANSFER_COUNT_VALUE(v)	(v)

#define HW_PERFMON_TOTAL_LATENCY	(0x00000070)

#define BP_PERFMON_TOTAL_LATENCY_COUNT	0
#define BM_PERFMON_TOTAL_LATENCY_COUNT	0xFFFFFFFF
#define BF_PERFMON_TOTAL_LATENCY_COUNT(v)	(v)

#define HW_PERFMON_DATA_COUNT	(0x00000080)

#define BP_PERFMON_DATA_COUNT_COUNT	0
#define BM_PERFMON_DATA_COUNT_COUNT	0xFFFFFFFF
#define BF_PERFMON_DATA_COUNT_COUNT(v)	(v)

#define HW_PERFMON_MAX_LATENCY	(0x00000090)

#define BP_PERFMON_MAX_LATENCY_ABURST	30
#define BM_PERFMON_MAX_LATENCY_ABURST	0xC0000000
#define BF_PERFMON_MAX_LATENCY_ABURST(v) \
		(((v) << 30) & BM_PERFMON_MAX_LATENCY_ABURST)
#define BP_PERFMON_MAX_LATENCY_ALEN	26
#define BM_PERFMON_MAX_LATENCY_ALEN	0x3C000000
#define BF_PERFMON_MAX_LATENCY_ALEN(v)  \
		(((v) << 26) & BM_PERFMON_MAX_LATENCY_ALEN)
#define BP_PERFMON_MAX_LATENCY_ASIZE	23
#define BM_PERFMON_MAX_LATENCY_ASIZE	0x03800000
#define BF_PERFMON_MAX_LATENCY_ASIZE(v)  \
		(((v) << 23) & BM_PERFMON_MAX_LATENCY_ASIZE)
#define BP_PERFMON_MAX_LATENCY_TAGID	15
#define BM_PERFMON_MAX_LATENCY_TAGID	0x007F8000
#define BF_PERFMON_MAX_LATENCY_TAGID(v)  \
		(((v) << 15) & BM_PERFMON_MAX_LATENCY_TAGID)
#define BP_PERFMON_MAX_LATENCY_RSVD0	12
#define BM_PERFMON_MAX_LATENCY_RSVD0	0x00007000
#define BF_PERFMON_MAX_LATENCY_RSVD0(v)  \
		(((v) << 12) & BM_PERFMON_MAX_LATENCY_RSVD0)
#define BP_PERFMON_MAX_LATENCY_COUNT	0
#define BM_PERFMON_MAX_LATENCY_COUNT	0x00000FFF
#define BF_PERFMON_MAX_LATENCY_COUNT(v)  \
		(((v) << 0) & BM_PERFMON_MAX_LATENCY_COUNT)

#define HW_PERFMON_DEBUG	(0x000000a0)

#define BP_PERFMON_DEBUG_RSVD	2
#define BM_PERFMON_DEBUG_RSVD	0xFFFFFFFC
#define BF_PERFMON_DEBUG_RSVD(v) \
		(((v) << 2) & BM_PERFMON_DEBUG_RSVD)
#define BM_PERFMON_DEBUG_TOTAL_CYCLE_CLR_EN	0x00000002
#define BM_PERFMON_DEBUG_ERR_MID	0x00000001

#define HW_PERFMON_VERSION	(0x000000b0)

#define BP_PERFMON_VERSION_MAJOR	24
#define BM_PERFMON_VERSION_MAJOR	0xFF000000
#define BF_PERFMON_VERSION_MAJOR(v) \
		(((v) << 24) & BM_PERFMON_VERSION_MAJOR)
#define BP_PERFMON_VERSION_MINOR	16
#define BM_PERFMON_VERSION_MINOR	0x00FF0000
#define BF_PERFMON_VERSION_MINOR(v)  \
		(((v) << 16) & BM_PERFMON_VERSION_MINOR)
#define BP_PERFMON_VERSION_STEP	0
#define BM_PERFMON_VERSION_STEP	0x0000FFFF
#define BF_PERFMON_VERSION_STEP(v)  \
		(((v) << 0) & BM_PERFMON_VERSION_STEP)

typedef enum {
    PERFMON_MID0 = 0x01 << 0,
    PERFMON_MID1 = 0x01 << 1,
    PERFMON_MID2 = 0x01 << 2,
    PERFMON_MID3 = 0x01 << 3,
    PERFMON_MID4 = 0x01 << 4,
    PERFMON_MID5 = 0x01 << 5,
    PERFMON_MID6 = 0x01 << 6,
    PERFMON_MID7 = 0x01 << 7,
    PERFMON_MID8 = 0x01 << 8,
    PERFMON_MID9 = 0x01 << 9,
    PERFMON_MID10 = 0x01 << 10,
    PERFMON_MID11 = 0x01 << 11,
    PERFMON_MID12 = 0x01 << 12,
    PERFMON_MID13 = 0x01 << 13,
    PERFMON_MID14 = 0x01 << 14,
    PERFMON_MID15 = 0x01 << 15,

    PERFMON_MID_MAX,
} perfmon_mid_e;

typedef union {
    struct {
        uint32_t aburst:2;
        uint32_t a_len:4;
        uint32_t asize:3;
        uint32_t tag_id:8;
        uint32_t reserved0:3;
        uint32_t cnt:12;
    } fields;
    uint32_t u;
} perf_latency_t, *perf_latency_p;

typedef struct {
    uint32_t total_active_cycle;
    uint32_t total_trans;
    uint32_t total_datas;
    uint32_t total_lat_cnt;
    perf_latency_t max_latency;
} perfmon_res_t, *perfmon_res_p;

typedef enum {
    PERFMON_TRANS_WRITE,
    PERFMON_TRANS_READ,
} perfmon_trans_e;

int perfmon_start(uint32_t base, uint32_t mid, perfmon_trans_e trans);
int perfmon_stop(uint32_t base, perfmon_res_p res);

#endif /*__IMX_PERFMON_H__ */