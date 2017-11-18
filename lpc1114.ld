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
