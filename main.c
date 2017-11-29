#include<stdint.h>
#include"lpc1114.h"
#include"lpc111x_gpio.h"
void (* const vectors[])(void) __attribute__ ((section(".vectors"))) ;

int
main () {
	GPIO1DIR = 1 << 8;
	while(1) {
		for (int i = 0x200000; i; i --) {
		}
		GPIO1DATA = 0;
	}
}

