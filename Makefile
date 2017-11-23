TARG=main.c

ASM=startup.s

TOOLCHAIN_PREFIX=arm-none-eabi-

GCC = $(TOOLCHAIN_PREFIX)gcc
LD  = $(TOOLCHAIN_PREFIX)ld
AS  = $(TOOLCHAIN_PREFIX)as


main.hex:main.out
	$(LD) -T lpc1114.ld main.out -o main.hex

main.out:main.s
	$(AS) main.s startup.s -o main.out

startup.out:startup.s

main.s:main.c
	$(GCC) -S main.c
