TARG=main.c

ASM=startup.s

TOOLCHAIN_PREFIX=arm-none-eabi-

GCC = $(TOOLCHAIN_PREFIX)gcc
LD  = $(TOOLCHAIN_PREFIX)ld
AS  = $(TOOLCHAIN_PREFIX)as

C_HEADER = ./platform/c/headers
BUILD_DIR = ./build

$(BUILD_DIR)/main.hex:$(BUILD_DIR)/main.out
	$(LD) -T lpc1114.ld $(BUILD_DIR)/main.out -o $(BUILD_DIR)/main.hex

$(BUILD_DIR)/main.out:$(BUILD_DIR)/main.s
	$(AS) $(BUILD_DIR)/main.s startup.s -o $(BUILD_DIR)/main.out

$(BUILD_DIR)/main.s:main.c
	$(GCC) -S -I$(C_HEADER) main.c -o $(BUILD_DIR)/main.s

clean:
	rm build/*
