/*
 * Copyright (C) 2012, Freescale Semiconductor, Inc. All Rights Reserved
 * THIS SOURCE CODE IS CONFIDENTIAL AND PROPRIETARY AND MAY NOT
 * BE USED OR DISTRIBUTED WITHOUT THE WRITTEN PERMISSION OF
 * Freescale Semiconductor, Inc.
*/

#include "utility/spinlock.h"
#include "timer/timer.h"

////////////////////////////////////////////////////////////////////////////////
// Constants
////////////////////////////////////////////////////////////////////////////////

enum
{
    kUnlocked = 0,  //!< Unlocked value for the spinlock.
    kLocked = 1     //!< Locked value for the spinlock.
};

////////////////////////////////////////////////////////////////////////////////
// Code
////////////////////////////////////////////////////////////////////////////////

void spinlock_init(spinlock_t * lock)
{
    *lock = kUnlocked;
}

int spinlock_lock(spinlock_t * lock, uint32_t timeout)
{
    uint64_t startTime = time_get_microseconds();
    
    // Wait for lock to become available.
    while (*lock != kUnlocked)
    {
        // Unless the caller wants to wait forever, check if the timeout has elapsed.
        if ((timeout != kSpinlockWaitForever)
            && (time_get_microseconds() - startTime >= timeout))
        {
            return 1;
        }
    }
    
    // Lock the lock.
    *lock = kLocked;
    
    return 0;
}

void spinlock_unlock(spinlock_t * lock)
{
    // Unlock the lock.
    *lock = kUnlocked;
}

bool spinlock_is_locked(spinlock_t * lock)
{
    return (*lock != kUnlocked);
}

////////////////////////////////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////////////////////////////////
