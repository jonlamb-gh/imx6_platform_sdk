/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
 */
/*----------------------------------------------------------------------------
 SigmaTel Inc
 $Archive: /Fatfs/FileSystem/Fat32/higherapi/Fremovew.c $                                        
 $Revision: 4 $                                       
 $Date: 9/13/03 12:22p $                                           
 Description: Fremovew.c
 Notes:	This file read provides higherlevel API function to remove(delete) a file.
        It considers the string as kUTF16Encoding.
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
>  Function Name: RtStatus_t Fremovew(uint8_t *filepath)

   FunctionType:  Reentrant

   Inputs:        1) Pointer to file name
				   
   Outputs:       SUCCESS or an error code if error occurs
   
   Description:   This function marks the specified file as deleted by making 
                  the first byte (character) of the file name in the directory 
                  entry as 0xE5. It considers the string as UTF16.
----------------------------------------------------------------------------*/
RtStatus_t Fremovew(uint8_t *filepath)
{
    int32_t HandleNumber,RecordNo,index=0,strlen;
    int32_t Dir_Attr;
    RtStatus_t Retval;
    uint8_t buf[32];
    int32_t clusterno;	

	
	/* Take temporary(directory) handle for searching the directory by changing path */
    HandleNumber = DIRECTORY_HANDLE; 

    /* If the temporary handle is already active then change path is not possible */
	if(Handleactive(HandleNumber)== SUCCESS)
	    return ERROR_OS_FILESYSTEM_CHANGEPATH_NOT_POSSIBLE;
    Handle[HandleNumber].HandleActive = 1;

    /* set the handle for search */
    if(SetHandleforsearch(HandleNumber,filepath,kUTF16Encoding,&index) < 0)
    {
        Freehandle(HandleNumber);
   	    return ERROR_OS_FILESYSTEM_INVALID_DIR_PATH ;
	}

	strlen = StrlengthW(filepath);
    /* search for the specified file by changing the path */
    if((clusterno =  Changepath(HandleNumber,filepath,kUTF16Encoding,strlen,index)) <0)
    {
        Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_FILE_NOT_FOUND;
    }
    
    /* Check file attribute, if file attribute is system, volume 
    or directory then file can not be deleted. Return error */					      
    RecordNo =   Handle[HandleNumber].CurrentOffset >> 5;
	
	/* check for root directory */
    if(ReadDirectoryRecord(HandleNumber,RecordNo,buf)<0)
	{
	    Freehandle(HandleNumber);
         return ERROR_OS_FILESYSTEM_INVALID_RECORD_NUMBER;
    }
	
    Dir_Attr = FSGetByte(buf,DIR_ATTRIBUTEOFFSET);
      
    if(Dir_Attr & READ_ONLY || Dir_Attr & SYSTEM || Dir_Attr & DIRECTORY || Dir_Attr & VOLUME_ID)
    {
        Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_FILE_DELETE_FAILED;
	}

	Handle[HandleNumber].FileSize = FSGetDWord((uint8_t *)buf,DIR_FILESIZEOFFSET);

 	/* Set the handle to original position */
	if (Handle[HandleNumber].StartingCluster != 0)
    {
        if((Retval =Fseek(HandleNumber,-DIRRECORDSIZE,SEEK_CUR))<0)
	    {
            Freehandle(HandleNumber);
   	        return  Retval;
	    }
	}
    /* Check whether the file is opened, if file is opened it can not be 
 	deleted. Return error */
    if(	Isfileopen(HandleNumber) == ERROR_OS_FILESYSTEM_FILE_OPEN)
	{
        Freehandle(HandleNumber);
        return ERROR_OS_FILESYSTEM_FILE_DELETE_FAILED;
	}
    /* Delete the directory record of the file */
    if((Retval=DeleteRecord(HandleNumber,RecordNo))<0)
	{
	    Freehandle(HandleNumber);
    	return Retval;
	}
  
    /* Set the Handle to original position */
    Fseek(HandleNumber,(RecordNo *DIRRECORDSIZE),SEEK_SET);
    /* update the handle to associate with the file to be deleted */
    UpdateHandle(HandleNumber,clusterno);

    /* Delete the contents of the file (i.e. Mark all the clusters occupied by 
    the file as zero in FAT Table). */
    if((Retval = DeleteContent(HandleNumber,0))<0)
    {
	    Freehandle(HandleNumber);
    	return Retval;
	}
  
    /* Free the handle used for file search */
    Freehandle(HandleNumber);
    return (SUCCESS); 
}


	 




		







			 




			 
