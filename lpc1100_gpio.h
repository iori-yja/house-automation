#ifndef _LPC1114_H_
#define _LPC1114_H_

#define GPIO0_BASE   (AHB_START + 0x00000000)
#define GPIO1_BASE   (AHB_START + 0x00010000)
#define GPIO2_BASE   (AHB_START + 0x00020000)
#define GPIO3_BASE   (AHB_START + 0x00030000)

#define IOCON_BASE   (AHB_START + 0x00044000)
#define IOCON_PIO2_6 (* (volatile unsigned long *) (IOCON_BASE + (0 * 4))
#define IOCON_PIO2_0 (* (volatile unsigned long *) (IOCON_BASE + (1 * 4))
#define IOCON_PIO0_1 (* (volatile unsigned long *) (IOCON_BASE + (2 * 4))
#define IOCON_PIO1_8 (* (volatile unsigned long *) (IOCON_BASE + (3 * 4))
#define IOCON_PIO0_2 (* (volatile unsigned long *) (IOCON_BASE + (4 * 4))
#define IOCON_PIO2_7 (* (volatile unsigned long *) (IOCON_BASE + (5 * 4))
#define IOCON_PIO2_8 (* (volatile unsigned long *) (IOCON_BASE + (6 * 4))
#define IOCON_PIO2_1 (* (volatile unsigned long *) (IOCON_BASE + (7 * 4))
#define IOCON_PIO0_3 (* (volatile unsigned long *) (IOCON_BASE + (8 * 4))

#endif
