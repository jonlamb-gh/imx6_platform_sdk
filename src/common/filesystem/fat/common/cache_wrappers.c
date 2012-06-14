/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */

///////////////////////////////////////////////////////////////////////////////
//! \addtogroup fs_fat
//! @{
//! \file cache_wrappers.c
//! \brief Contains wrappers for the cache read and write calls.
///////////////////////////////////////////////////////////////////////////////

#include "fat_internal.h"
// #include "drivers/media/media_cache.h"
// #include "drivers/media/media_buffer_manager.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
//#include <arm_ghs.h>
#include "usdhc/inc/usdhc_ifc.h"
#include <assert.h>

extern uint32_t g_usdhc_base_addr;

typedef struct {
    uint8_t * buffer;
    uint32_t sector;
    bool isValid;
} fat_cache_t;

fat_cache_t g_fatCache = {0};
uint32_t g_u32MbrStartSector = 0;

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

//! \brief Determines if a sector is within the first FAT.
static bool IsFATSector(uint32_t drive, uint32_t sector)
{
    uint32_t start = MediaTable[drive].RsvdSectors;
    uint32_t end = start + MediaTable[drive].FATSize;
    return (sector >= start) && (sector < end); 
}

//! \brief Returns the appropriate weight for the given sector.
// static inline int32_t GetSectorWeight(uint32_t drive, uint32_t sector)
// {
//     return IsFATSector(drive, sector) ? kMediaCacheWeight_High : kMediaCacheWeight_Medium;
// }

RtStatus_t FSWriteSector(int32_t deviceNumber, int32_t sectorNumber, int32_t destOffset, uint8_t * sourceBuffer, int32_t sourceOffset, int32_t numBytesToWrite, int32_t writeType)
{
//    assert(false);
    return SUCCESS;
}

// used by Fwrite_BypassCache(), used by StorWriteObjectData()
RtStatus_t FSWriteSector_BypassCache(int32_t deviceNumber, int32_t sectorNumber, int32_t destOffset, uint8_t * sourceBuffer, int32_t sourceOffset, int32_t numBytesToWrite, int32_t writeType)
{
    // Setup param block for write.
    return FSWriteSector(deviceNumber, sectorNumber, destOffset, sourceBuffer, sourceOffset, numBytesToWrite, writeType);
}

// Used only in clearcluster() in the FAT filesystem. Can replace with call to writesector.
RtStatus_t FSEraseSector(int32_t deviceNumber, int32_t sectorNumber)
{
    RtStatus_t status;
    uint8_t * buffer;

    // Acquire a buffer to hold the empty sector.
    uint32_t bufferSize = MediaTable[deviceNumber].BytesPerSector;
    buffer = (uint8_t *)malloc(bufferSize);
    
    // Clear the sector buffer to all zeroes.
    memset(buffer, 0, MediaTable[deviceNumber].BytesPerSector);
    
    status = FSWriteSector(deviceNumber, sectorNumber, 0, buffer, 0, bufferSize, 0);

    // Let go of the sector buffer.
    free(buffer);

    return status;
}

#define BYTES_PER_SECTOR 512
#define NUM_OF_SECTOR    1024
#define CACHE_SIZE NUM_OF_SECTOR*BYTES_PER_SECTOR
extern uint8_t g_cache_buf[];
extern uint32_t g_start_sector;

/* enable only one option, not both */
#define RAM_FS
//#define NON_CACHED

int32_t * FSReadSector(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, uint32_t * token)
{
    assert(deviceNumber == 0);

    int status = 0;
    uint32_t actualSectorNumber = sectorNumber;
    uint32_t sectorSize = MediaTable[deviceNumber].BytesPerSector;
    uint32_t sectorNum, sector_offset = 0;

//   printf("s %X \n",actualSectorNumber);

    // Handle FAT cache.
    bool isFat = IsFATSector(deviceNumber, sectorNumber);
    if (isFat && g_fatCache.isValid && g_fatCache.sector == actualSectorNumber)
    {
        *token = 0;
        return (int32_t *) g_fatCache.buffer;
    }

    uint8_t * buffer;
    if (isFat)
    {
        buffer = g_fatCache.buffer;
        g_fatCache.sector = actualSectorNumber;
        g_fatCache.isValid = false;
        sectorNum = 1;
    }
    else
    {
        /* Not a fat sector, allocate a new buffer that
           is released by FSReleaseSector() */
#ifdef NON_CACHED
           buffer = (uint8_t *)malloc(CACHE_SIZE);
#else
           if((actualSectorNumber < (g_start_sector + NUM_OF_SECTOR))
                         && (actualSectorNumber > g_start_sector))
            sector_offset = actualSectorNumber - g_start_sector;
        buffer = g_cache_buf;
        sectorNum = NUM_OF_SECTOR;
#endif /* NON_CACHED */
        }
#ifndef RAM_FS
    if((g_start_sector == 0xFFFFFFFF) || (actualSectorNumber > (g_start_sector + NUM_OF_SECTOR))
                                      || (actualSectorNumber < g_start_sector))
    {
        status = card_data_read(g_usdhc_base_addr, (int *)buffer, sectorNum * sectorSize,
                       actualSectorNumber * sectorSize);
//        printf("l %X o %X\n",sectorNum * sectorSize,actualSectorNumber * sectorSize);

        g_start_sector = actualSectorNumber;
    }
#endif /* RAM_FS */
#ifdef NON_CACHED
    status = card_data_read(g_usdhc_base_addr, (int *)buffer, sectorSize,
                       actualSectorNumber * sectorSize);
#endif /* NON_CACHED */
    // Give the caller the token so they can release the cache entry.
    if ((status == 0) && token)
    {
        if (isFat)
        {
            g_fatCache.isValid = true;
            *token = 0;
        }
        else
            *token = (uint32_t)buffer;

//        printf("add %X so %X\n",(int32_t)(buffer+(sector_offset * sectorSize)),sector_offset);

#ifndef RAM_FS
//        uint32_t i;
//        for(i=0;i<0x200;i++)
//            printf("%01X",*(uint8_t *)(buffer + (sector_offset * sectorSize) + i));
//        printf("\n");
#ifdef NON_CACHED
        return (int32_t *) (buffer);
#else
        return (int32_t *) (buffer + (sector_offset * sectorSize));
#endif /* NON_CACHED */

#else
        /* hardcoded address in DDR, that's only for test purpose !!! */
        buffer = (uint8_t *) 0x11000000;
//       uint32_t i;
//       for(i=0;i<0x200;i++)
//            printf("%01X",*(uint8_t *)(buffer + (sectorNumber * sectorSize) + i));
//        printf("\n");
//        printf("add %X\n",(int32_t)(buffer + (sectorNumber * sectorSize)));
        return (int32_t *) (buffer + (sectorNumber * sectorSize));
#endif /* RAM_FS */
    }
    else
    {
        if (!isFat)
        {
            free(buffer);
        }
        // An error occurred, so return NULL.
        return NULL;
    }

}

// used by Fread_BypassCache(), used by StorReadObjectData()
int32_t * FSReadSector_BypassCache(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, uint8_t *pBuffer, uint32_t * token)
{
    return FSReadSector(deviceNumber, sectorNumber, writeType, token);
}

RtStatus_t FSReleaseSector(uint32_t token)
{
    if (token)
    {
#ifdef NON_CACHED
        free((void *)token);
#endif
    }
    return SUCCESS;
}

RtStatus_t FSFlushSector(int32_t deviceNumber, int32_t sectorNumber, int32_t writeType, int32_t ix, int32_t * writeFlag)
{
    return SUCCESS;
}

RtStatus_t FlushCache(void)
{
    g_fatCache.isValid = false;
    
    return SUCCESS;
}

RtStatus_t FSFlushDriveCache(int32_t deviceNumber)
{
    return FlushCache();
}

////////////////////////////////////////////////////////////////////////////////
//! \brief Verify if the supplied sector contains valid fields of a
//!        Partition Boot Sector. Internal function.
//! \param[in] pSectorBuffer - Sector Data (presumably of a Partition Boot Sector)
//!
//! \retval SUCCESS
//! \retval ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND 
//! \internal
////////////////////////////////////////////////////////////////////////////////
RtStatus_t VerifyPBS(uint8_t* pSectorData)
{
    uint32_t u8SecValue = 1;
    uint8_t u8SecPerClus = pSectorData[0x0d];
    uint32_t i;

    // Verify that the Sectors Per Cluster field is a power of 2 value
    for (i = 0; i < 8; i++)
    {
        if (u8SecPerClus == u8SecValue)
        {
            break;
        }
        u8SecValue <<= 1;
    }

    if ((u8SecValue == 256) || ((pSectorData[0] != 0xEB) && (pSectorData[0] != 0xE9)))
    {
	     return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
    }

    // Verify the Boot Sector signature field (should be 0xAA55)
    if (((pSectorData[0x1fe] == 0x55) && (pSectorData[0x1ff] == 0xAA)) ||
        ((pSectorData[0x7fe] == 0x55) && (pSectorData[0x7ff] == 0xAA)))
    {
        return SUCCESS;
    }

    return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
}

RtStatus_t FSDataDriveInit(DriveTag_t tag)
{
    uint32_t u32PbsTotalSectors;
    uint32_t ProbablePBSFlag = 0;
    uint8_t* pSectorData;
    RtStatus_t retval = SUCCESS;
    uint32_t pbsOffset;
    uint32_t token;

	/*Note by Ray: in this function, intialize the uSDHC controller*/
    retval = card_init(g_usdhc_base_addr, 8);
    /*now enable the INTERRUPT mode of usdhc */
    SDHC_INTR_mode = 1;
    SDHC_ADMA_mode = 0;
    if (retval == 1) {
        return 1;
    }

    // Setup fat cache.
    memset(&g_fatCache, 0, sizeof(g_fatCache));
    /* initialize with a default value before getting size from FAT table */
    MediaTable[(int)tag].BytesPerSector = 512;
    uint32_t sectorSize = MediaTable[(int)tag].BytesPerSector;
    g_fatCache.buffer = (uint8_t *)malloc(sectorSize);

    // Reset partition offset.
    g_u32MbrStartSector = 0;

    // First read sector 0
    pSectorData = (uint8_t *)FSReadSector(tag, 0, 0, &token);
    if (retval != SUCCESS || pSectorData == 0)
    {
        return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
    }

    // First, extract the assumed start sector. We don't want to set the g_u32MbrStartSector
    // global yet, because ReadSector() uses MediaRead(), which offsets based on that global's
    // value. Thus, we'd get a double offset when trying to read the PBS.
    pbsOffset = pSectorData[0x1c6] + (pSectorData[0x1c7] << 8) + (pSectorData[0x1c8] << 16) + (pSectorData[0x1c9] << 24);

    FSReleaseSector(token);

    // Now read what may be the first sector of the first partition
    pSectorData = (uint8_t *)FSReadSector(tag, pbsOffset, 0, &token);
    if (retval != SUCCESS || pSectorData == 0)
    {
        // The read failed, hence we might not have this sector as MBR, assume PBS
        ProbablePBSFlag = 1;
    }
    else
    {
        if ((retval = VerifyPBS(pSectorData)) != SUCCESS)
        {
            // The verification failed, so assume PBS
            ProbablePBSFlag = 1;
        }
    }

    FSReleaseSector(token);

    // Ok, so Sector 0 might be a PBS, verify that this is indeed the case.
    if (ProbablePBSFlag == 1)
    {
        pbsOffset = 0;

        pSectorData = (uint8_t *)FSReadSector(tag, pbsOffset, 0, &token);
        if (retval != SUCCESS || pSectorData == 0)
        {
            // Not necessary to media_cache_release() here, because the read failed.

            retval = ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
            return retval;
        }
        
        if ((retval = VerifyPBS(pSectorData)) != SUCCESS)
        {
            FSReleaseSector(token);
            return retval;
        }
    }
    else
    {
        /* it usually ends here */
        g_u32MbrStartSector = pbsOffset;
    }

    FSReleaseSector(token);

    // Get Total Sectors from PBS (first look at small 2-byte count field at 0x13&0x14)
    u32PbsTotalSectors = pSectorData[0x13] + (pSectorData[0x14] << 8);

    if (u32PbsTotalSectors == 0)
    {
        // Total Sectors is in the large 4-byte count field beginning at 0x20
        u32PbsTotalSectors = pSectorData[0x20] + (pSectorData[0x21] << 8) + (pSectorData[0x22] << 16) + (pSectorData[0x23] << 24);
    }

    if (u32PbsTotalSectors == 0)
    {
        return ERROR_OS_FILESYSTEM_FILESYSTEM_NOT_FOUND;
    }

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////
// End of file
////////////////////////////////////////////////////////////////////////////////
//! @}

