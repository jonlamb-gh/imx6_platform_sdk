/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/base/ChangeToRootdirectory.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:20p $                                           
 Description: ChangeToRootdirectory.c
 Notes:	This file read provides base function to change the directory to Root directory 
----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------
		File Includes
----------------------------------------------------------------------------*/
#include <types.h>
#include "fstypes.h"
#include "fat_internal.h"
#include <error.h>
#include <filesystem/fsapi.h> //! \todo malinclusion
#include "platform.h"
#include "bootsecoffset.h" 
#include "diroffset.h" 

/*----------------------------------------------------------------------------
>  Function Name: RtStatus_t ChangeToRootdirectory(int32_t HandleNumber)

   FunctionType:  Reentrant

   Inputs:        1)HandleNumber
                 
   Outputs:       Returns SUCCESS or an error code if an Error occurs

   Description:   Sets the handle to Root directory of given device number
<	 
----------------------------------------------------------------------------*/
RtStatus_t ChangeToRootdirectory(int32_t HandleNumber)
{
    int32_t DeviceNum; 

	if((HandleNumber <0)||(HandleNumber >=maxhandles))
	    return ERROR_OS_FILESYSTEM_MAX_HANDLES_EXCEEDED;

    DeviceNum =  Handle[HandleNumber].Device;

    if (MediaTable[DeviceNum].FATType ==FAT12 || MediaTable[DeviceNum].FATType ==FAT16)
    {
	    Handle[HandleNumber].StartingCluster = 0;
		Handle[HandleNumber].CurrentCluster = 0;
		Handle[HandleNumber].CurrentSector = MediaTable[DeviceNum].FirRootdirsec;
    }

    else if (MediaTable[DeviceNum].FATType ==FAT32)
    {
	    Handle[HandleNumber].StartingCluster = MediaTable[ DeviceNum].RootdirCluster;
	    Handle[HandleNumber].CurrentCluster = MediaTable[ DeviceNum].RootdirCluster;
	    Handle[HandleNumber].CurrentSector=Firstsectorofcluster(DeviceNum,MediaTable[ DeviceNum].RootdirCluster);
    }
    else 
        return ERROR_OS_FILESYSTEM_MEDIA_TYPE_NOT_SUPPORTED;

	Handle[HandleNumber].CurrentOffset=0;
	Handle[HandleNumber].BytePosInSector=0;
	Handle[HandleNumber].SectorPosInCluster=0;
	Handle[HandleNumber].DirSector=0;
	Handle[HandleNumber].diroffset=0;
	Handle[HandleNumber].FileSize=0;

	return SUCCESS;
}
           


