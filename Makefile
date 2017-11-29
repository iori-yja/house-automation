TARG=main.c

ASM=startup.s

TOOLCHAIN_PREFIX=arm-none-eabi-

GCC = $(TOOLCHAIN_PREFIX)gcc
LD  = $(TOOLCHAIN_PREFIX)ld
AS  = $(TOOLCHAIN_PREFIX)as
OBJCOPY = $(TOOLCHAIN_PREFIX)objcopy

C_HEADER = ./platform/c/headers
BUILD_DIR = ./build

$(BUILD_DIR)/main.hex:$(BUILD_DIR)/main.elf
	$(OBJCOPY) -O ihex $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.hex

$(BUILD_DIR)/main.elf:$(BUILD_DIR)/main.out
	$(LD) -T lpc1114.ld $(BUILD_DIR)/main.out -o $(BUILD_DIR)/main.elf

$(BUILD_DIR)/main.out:$(BUILD_DIR)/main.s
	$(AS)  -mcpu=cortex-m0 -mthumb $(BUILD_DIR)/main.s startup.s -o $(BUILD_DIR)/main.out

$(BUILD_DIR)/main.s:main.c
	$(GCC) -c -mcpu=cortex-m0 -mthumb -O2 -ffunction-sections -fdata-sections -Wall -Wstrict-prototypes -Wextra -std=c99 -S -I$(C_HEADER) main.c -o $(BUILD_DIR)/main.s

clean:
	rm build/*
