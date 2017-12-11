/*
+=============================================================================+
| stacks sizes
+=============================================================================+
*/

/* Handler mode (core exceptions / interrupts) can use only main stack */
/* Thread mode can use main stack (default) or process stack - selected in CONTROL special register */
_stack_capacity = 2048;

/*----------------------------*/
ENTRY(entry_point)

MEMORY {
  FLASH (rx)      : ORIGIN = 0x00000000, LENGTH = 32K 
  RAM (xrw)       : ORIGIN = 0x10000000, LENGTH = 192K
}

__rom_start = ORIGIN(FLASH);
__rom_size = LENGTH(FLASH);
__rom_end = __rom_start + __rom_size;

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
		_pre_start_data = .;
		_start_data = .;
		. = ALIGN(4);
		*(.data .data.* .gnu.linkonce.d.*)

		_end_data = .;
	} > RAM AT > FLASH

	.bss :
	{
		. = ALIGN(4);
		_start_bss = .;
		*(.bss .bss.* .gnu.linkonce.b.*)
		*(COMMON);
		_end_bss = .;
	} > RAM AT > RAM 

/*----------------------------*/
	.stack :
	{
		. = ALIGN(8);
		_stack_bottom = .;
		. += _stack_capacity;
		. = ALIGN(8);
		_stack_top = .;
	} > RAM

	.stab 				0 (NOLOAD) : { *(.stab) }
	.stabstr 			0 (NOLOAD) : { *(.stabstr) }
}

