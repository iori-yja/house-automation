  .syntax unified
  .cpu cortex-m3
  .fpu softvfp
  .thumb
  .thumb_func
.text
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


.section  .text.reset_handler:
.type  entry_point, %function

entry_point:
  movs  r1, #0
  b init_data

init_data:
  ldr  r3, =_pre_start_data
  ldr  r3, [r3, r1]
  str  r3, [r0, r1]
  adds  r1, r1, #4
    
init_data_loop:
  ldr  r0, =_start_data
  ldr  r3, =_end_data
  adds  r2, r0, r1
  cmp  r2, r3
  bcc  init_data_loop
  ldr  r2, =_start_bss

  b  init_bss

init_bss:
  movs  r3, #0
  str  r3, [r2], #4
    
init_bss_loop:
  ldr  r3, = _end_bss
  cmp  r2, r3
  bcc  init_bss_loop

/* Call the application's entry point.*/
	ldr		r0, =main
	blx		r0
	nop
	nop
	nop
	nop
	b		.

main:
	b main

.size  entry_point, .-entry_point
