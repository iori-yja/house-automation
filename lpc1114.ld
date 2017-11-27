/*
+=============================================================================+
| stacks sizes
+=============================================================================+
*/

/* Handler mode (core exceptions / interrupts) can use only main stack */
/* Thread mode can use main stack (default) or process stack - selected in CONTROL special register */

__main_stack_size = 0;
__process_stack_size = 1024;


/*----------------------------*/
ENTRY(entry_point)

MEMORY {
  FLASH (rx)      : ORIGIN = 0x00000000, LENGTH = 32K 
  RAM (xrw)       : ORIGIN = 0x10000000, LENGTH = 192K
}

__rom_start = ORIGIN(FLASH);
__rom_size = LENGTH(FLASH);
__rom_end = __rom_start + __rom_size;

__ram_start = ORIGIN(RAM);
__ram_size = LENGTH(RAM);
__ram_end = __ram_start + __ram_size;

SECTIONS
{
  . = 0x0;
  .vectors :
  {
    . = ALIGN(4);
    KEEP(*(.vectors)) /* 0x00 - 0xC0 */
    . = ALIGN(4);
  } >FLASH AT > FLASH

  . = 0xC0;
	.text :
	{
		. = 0xC0;
		. = ALIGN(4);
    *(.text .text*)
		*(.glue_7t .glue_7);
    *(.rodata .rodata*)
		*(.eh_frame_hdr);
		*(.eh_frame);

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .; /* define a global symbols at end of code */
	} > FLASH AT > FLASH 

	. = ALIGN(4);
 .ARM.extab   : { *(.ARM.extab* .gnu.linkonce.armextab.*) } >FLASH
	.ARM : {
	__exidx_start = .;
		*(.ARM.exidx*)
		__exidx_end = .;
	} >FLASH

  .init_array :
  {
    PROVIDE_HIDDEN (__init_array_start = .);
    KEEP (*(SORT(.init_array.*)))
    KEEP (*(.init_array*))
    PROVIDE_HIDDEN (__init_array_end = .);
  } >FLASH
  .fini_array :
  {
    PROVIDE_HIDDEN (__fini_array_start = .);
    KEEP (*(.fini_array*))
    KEEP (*(SORT(.fini_array.*)))
    PROVIDE_HIDDEN (__fini_array_end = .);
  } >FLASH


	.data :
	{
		. = ALIGN(4);
		__data_init_start = .;
		__data_start = .;
		. = ALIGN(4);
		*(.data .data.* .gnu.linkonce.d.*)

		__data_end = .;
	} > RAM AT > FLASH

	.bss :
	{
		. = ALIGN(4);
		__bss_start = .;
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON);
		__bss_end = .;
	} > RAM AT > RAM 

/*----------------------------*/
	.stack :
	{
		. = ALIGN(8);
		__stack_start = .;
		. = ALIGN(8);
		__main_stack_start = .;
		. += __main_stack_size;

		. = ALIGN(8);
		__main_stack_end = .;

		. = ALIGN(8);
		__process_stack_start = .;

		. += __process_stack_size;

		. = ALIGN(8);
		__process_stack_end = .;

		. = ALIGN(8);
		__stack_end = .;
	} > RAM AT > RAM 

	. = ALIGN(4);
	__heap_start = .;

	. = ALIGN(4);
	__heap_end = __ram_end;

	.stab 				0 (NOLOAD) : { *(.stab) }
	.stabstr 			0 (NOLOAD) : { *(.stabstr) }
}

