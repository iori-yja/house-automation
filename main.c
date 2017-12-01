#include<stdint.h>
#include"lpc1114.h"
#include"lpc111x_gpio.h"
#include"lpc11xx_iocon.h"

void (* const vectors[])(void) __attribute__ ((section(".vectors"))) ;
#define SYSAHBCLKCTRL (* (volatile unsigned long *) (APB_START + 0x48080))

int
main () {
	volatile uint32_t count;
	SYSAHBCLKCTRL |= (1 << 16);
	GPIO1DIR = 1 << 8;
	GPIO1DATA = 0;
	for (count = 0; count < 1000000; count ++) ;
	GPIO1DATA ^= 1 << 8;
}

