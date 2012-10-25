/*
 * Copyright (c) 2010-2012, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of Freescale Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
  
/*!
 * @file startup.s
 * @brief this file contains startup code with support for multi-core startup
 * @for imx6quad/dual
 */
    .code 32
    .section ".startup","ax"
    
	.equ Mode_USR, 0x10
	.equ Mode_FIQ, 0x11
	.equ Mode_IRQ, 0x12
	.equ Mode_SVC, 0x13
	.equ Mode_ABT, 0x17
	.equ Mode_UND, 0x1B
	.equ Mode_SYS, 0x1F 

	.equ I_Bit, 0x80 @ /* when I bit is set EQU IRQ is disabled */
	.equ F_Bit, 0x40 @ /* when F bit is set EQU FIQ is disabled */

	@ exception vector adddress holders at top of OCRAM for iMX6Quad/Dual
#if defined(CHIP_MX6SDL)||defined(CHIP_MX6SL)
	.equ ABORT_MEM_ADDR, 0x0091ffec
	.equ IRQ_MEM_ADDR, 0x0091fff4
	.equ FIQ_MEM_ADDR, 0x0091fff8
#elif defined (CHIP_MX6DQ)
	.equ ABORT_MEM_ADDR, 0x0093ffec
	.equ IRQ_MEM_ADDR, 0x0093fff4
	.equ FIQ_MEM_ADDR, 0x0093fff8
#endif    
    .global startup_imx6x
    .func startup_imx6x 
startup_imx6x:
    mov 	r4, r0	@ save r0 for cores 1-3, r0 arg field passed by ROM
                @ r0 is a function pointer for secondary cpus

    ldr		r0, =top_of_stacks  @ symbol defined in $(TARGET).ld linker file
    mov		r1, #2048           @1024*2 is STACK_SIZE per cpu

    @ get cpu id, and subtract the offset from the stacks base address
    mrc     p15,0,r2,c0,c0,5  @ read multiprocessor affinity register
    and     r2, r2, #3        @ mask off, leaving CPU ID field
    mov     r5, r2		     @ save cpu id for later
    mul     r3, r2, r1
    sub     r0, r0, r3
  
    mov     r1, r1, lsl #2
           
    @ set stack for SVC mode
    mov     sp, r0 

    @ set stacks for all other modes 
    msr     CPSR_c, #Mode_FIQ | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_IRQ | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_ABT | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_UND | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    msr     CPSR_c, #Mode_SYS | I_Bit | F_Bit
    sub     r0, r0, r1 
    mov     sp, r0
    
    @ go back to SVC mode and enable interrupts
    msr     CPSR_c, #Mode_SVC
   
    @ check cpu id - cpu0 is primary cpu
    cmp r5, #0
    bxne r4     @ for secondary cpus, jump to argument function pointer passed in by ROM 
/*    blne secondary_cpus_init	*/

primary_cpu_init:
    @@  set-up exception vectors, update ISR jump addresses    
    ldr		r0, =IRQ_MEM_ADDR
    ldr		r1, =IRQ_HDLR
    str		r1, [r0]
    ldr		r0, =ABORT_MEM_ADDR
    ldr		r1, =ABORT_HDLR
    str		r1, [r0]

   	/* init .bss */
    /* clear the .bss section (zero init) */
    ldr     r1,=__bss_start__
    ldr     r2,=__bss_end__
    mov     r3,#0
1:
    cmp     r1,r2
    stmltia r1!,{r3}
    blt     1b
   
 /*   mov r0, #0xFF	   @ 0xFF is lowest priority level
    bl gic_set_cpu_priority_mask
   
    mov r0, #1
    bl gic_cpu_enable
    
    mov r0, #1
    bl gic_enable
*/   
    @ branch to c library entry point 
    ldr     r12, =main               /* save this in register for possible long jump */
    bx      r12                         /* branch to __main */ 
/*
secondary_cpus_init:
    @bl secondary_cpus_init  @ debug endless loop
    mov r0, #0xFF	   @ 0xFF is lowest priority level
    bl gic_set_cpu_priority_mask

    mov r0, #1
    bl gic_cpu_enable

    bx r4		       @ jump to argument function pointer passed in by ROM 
*/	
    .endfunc    @ startup_imx6x()

    .end

