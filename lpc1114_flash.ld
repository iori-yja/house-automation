ENTRY(entry_point)

MEMORY {
  FLASH (rx)      : ORIGIN = 0x00000000, LENGTH = 32K 
  RAM (xrw)       : ORIGIN = 0x10000000, LENGTH = 192K
}

SECTIONS
{
  . = 0x0;
  .interrupt_vectors:
  {
    . = ALIGN(4);
    KEEP(*(.interrupt_vectors)) /* 0x00 - 0xC0 */
    . = ALIGN(4);
  } >FLASH

  . = 0xC0;
  .text :
  {
    *(.text .text*)
		*(.glue_7t .glue_7);
    *(.rodata .rodata*)
		*(.eh_frame_hdr);
		*(.eh_frame);

    KEEP (*(.init))
    KEEP (*(.fini))

    . = ALIGN(4);
    _etext = .; /* define a global symbols at end of code */
  } >FLASH


  . = ALIGN(4);
  _pre_start_data = .;

  .data : AT ( _sidata )
  {
    . = ALIGN(4);
    _start_data = .;
    *(.data)
    *(.data*)

    . = ALIGN(4);
    _end_data = .;
  } >RAM

  . = ALIGN(4);
  .bss :
  {
    _start_bss = .;
    *(.bss)
    *(.bss*)
    *(COMMON)

    . = ALIGN(4);
    _end_bss = .;
  } >RAM

  .ARM.attributes 0 : { *(.ARM.attributes) }
}
