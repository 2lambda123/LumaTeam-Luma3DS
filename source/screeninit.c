/*
*   screeninit.c
*       by Aurora Wright
*   Screen init code by dark_samus, bil1s, Normmatt, delebile and others.
*   Screen deinit code by tiniVi.
*
*   Copyright (c) 2016 All Rights Reserved
*/

#include "screeninit.h"
#include "memory.h"
#include "draw.h"
#include "i2c.h"
#include "../build/screeninit.h"

#define SCREENINIT_ADDRESS 0x24F03000

vu32 *arm11Entry = (u32 *)0x1FFFFFF8;

void deinitScreens(void)
{
    void __attribute__((naked)) ARM11(void)
    {
        //Disable interrupts
        __asm(".word 0xF10C01C0");

        //Clear ARM11 entry offset
        *arm11Entry = 0;

        //Shutdown LCDs
        *(vu32 *)0x10202A44 = 0;
        *(vu32 *)0x10202244 = 0;
        *(vu32 *)0x10202014 = 0;

        //Wait for the entry to be set
        while(!*arm11Entry);

        //Jump to it
        ((void (*)())*arm11Entry)();
    }

    if(PDN_GPU_CNT != 1)
    {
        *arm11Entry = (u32)ARM11;
        while(*arm11Entry);
    }
}

void initScreens(void)
{
    if(PDN_GPU_CNT == 1)
    {
        memcpy((void *)SCREENINIT_ADDRESS, screeninit, screeninit_size);

        //Write brightness level for the stub to pick up
        *(vu32 *)(SCREENINIT_ADDRESS + 8) = 0;

        *arm11Entry = SCREENINIT_ADDRESS;
        while(*arm11Entry);

        //Turn on backlight
        i2cWriteRegister(I2C_DEV_MCU, 0x22, 0x2A);
    }

    clearScreens();
}