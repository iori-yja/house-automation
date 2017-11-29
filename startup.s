  .syntax unified
  .cpu cortex-m3
  .fpu softvfp
	.align 2
  .thumb
  .thumb_func
.global entry_point 

/* start address for the initialization values of the .data section. 
defined in linker script */
.word  _pre_start_data
/* start address for the .data section. defined in linker script */  
.word  _start_data
/* end address for the .data section. defined in linker script */
.word  _end_data
/* start address for the .bss section. defined in linker script */
.word  _start_bss
/* end address for the .bss section. defined in linker script */
.word  _end_bss
/* stack used for SystemInit_ExtMemCtl; always internal RAM used */

.section .vectors
isr_vector:
	.word	_main_stack_top
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	0
	.word	1+entry_point
	.word	0
	.word	0
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
 	.word	1+entry_point
 	.word	1+entry_point
 	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	0
	.word	0
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	0
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point
	.word	1+entry_point


.text.reset_handler:
.type  entry_point, %function

.equ GPIO1DIR  ,0x50018000
.equ GPIO1DATA ,0x50013ffc
.equ LED ,8

entry_point:

/*
+-----------------------------------------------------------------------------+
| Initialize .data section
+-----------------------------------------------------------------------------+
*/

	ldr		r1, =_pre_start_data
    ldr		r2, =_start_data
    ldr		r3, =_end_data

	b		2f
1:	ldmia	r1!, {r0}
	stmia	r2!, {r0}
2:	cmp		r2, r3
	bne		1b

/*
+-----------------------------------------------------------------------------+
| Zero-init .bss section
+-----------------------------------------------------------------------------+
*/

	movs	r0, #0
	ldr		r1, =_start_bss
	ldr		r2, =_end_bss

	b		2f
1:	stmia	r1!, {r0}
2:	cmp		r1, r2
	bne		1b


/* Call the application's entry point.*/
	ldr		r0, =main
	blx		r0
	nop
	nop
	nop
	nop
	b		.

.size  entry_point, .-entry_point
