TARG=main.c

ASM=platform/startup.s

TOOLCHAIN_PREFIX=arm-none-eabi-

GCC = $(TOOLCHAIN_PREFIX)gcc
LD  = $(TOOLCHAIN_PREFIX)ld
AS  = $(TOOLCHAIN_PREFIX)as
OBJCOPY = $(TOOLCHAIN_PREFIX)objcopy

C_HEADER = ./platform/c/headers
BUILD_DIR = ./build

$(BUILD_DIR)/main.hex:$(BUILD_DIR)/main.elf
	$(OBJCOPY) -O ihex $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.hex

$(BUILD_DIR)/main.elf:$(BUILD_DIR)/main.o $(BUILD_DIR)/startup.o
	$(LD) -T lpc1114.ld $(BUILD_DIR)/main.o $(BUILD_DIR)/startup.o -o $(BUILD_DIR)/main.elf

$(BUILD_DIR)/startup.o:$(ASM)
	$(GCC) -x assembler-with-cpp -c -mcpu=cortex-m0 -mthumb -I. -Iplatform/c/headers $(ASM) -o $(BUILD_DIR)/startup.o

$(BUILD_DIR)/main.o:main.c
	$(GCC) -c -mcpu=cortex-m0 -mthumb -O2 -ffunction-sections -fdata-sections -Wall -Wstrict-prototypes -Wextra -std=gnu99 -I. -I$(C_HEADER) main.c -o $(BUILD_DIR)/main.o
clean:
	rm build/*
