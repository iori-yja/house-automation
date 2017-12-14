#include<stdint.h>
#include"lpc1114.h"
#include"lpc111x_gpio.h"
#include"lpc11xx_iocon.h"

#define SYSAHBCLKCTRL (* (volatile unsigned long *) (APB_START + 0x48080))

volatile uint32_t count = 0;
int
main () {
	volatile uint32_t count2 = 0;
	SYSAHBCLKCTRL |= (1 << 16);
	GPIO1DIR = 1 << 8;
	GPIO1DATA = 0;
	for (; count < 100000; count ++) ;
	GPIO1DATA |= 1 << 8;

	//for (; count2 < 100000; count2 ++) ;
	//GPIO1DATA = 0;

	while(1);
	return 0;
}

