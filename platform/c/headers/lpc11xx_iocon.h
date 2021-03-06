#ifndef _LPC111X_IOCON_H_
#define _LPC111X_IOCON_H_

#define IOCON_BASE   (AHB_START + 0x00044000)
#define IOCON_PIO2_6  (* (volatile unsigned long *) (IOCON_BASE + 0x00))
#define IOCON_PIO2_0  (* (volatile unsigned long *) (IOCON_BASE + 0x08))
#define IOCON_PIO0_0  (* (volatile unsigned long *) (IOCON_BASE + 0x0c))
#define IOCON_PIO0_1  (* (volatile unsigned long *) (IOCON_BASE + 0x10))
#define IOCON_PIO1_8  (* (volatile unsigned long *) (IOCON_BASE + 0x14))
#define IOCON_PIO0_2  (* (volatile unsigned long *) (IOCON_BASE + 0x1c))
#define IOCON_PIO2_7  (* (volatile unsigned long *) (IOCON_BASE + 0x20))
#define IOCON_PIO2_8  (* (volatile unsigned long *) (IOCON_BASE + 0x24))
#define IOCON_PIO2_1  (* (volatile unsigned long *) (IOCON_BASE + 0x28))
#define IOCON_PIO0_3  (* (volatile unsigned long *) (IOCON_BASE + 0x2c))
#define IOCON_PIO0_4  (* (volatile unsigned long *) (IOCON_BASE + 0x30))
#define IOCON_PIO0_5  (* (volatile unsigned long *) (IOCON_BASE + 0x34))
#define IOCON_PIO1_9  (* (volatile unsigned long *) (IOCON_BASE + 0x38))
#define IOCON_PIO3_4  (* (volatile unsigned long *) (IOCON_BASE + 0x3c))
#define IOCON_PIO2_4  (* (volatile unsigned long *) (IOCON_BASE + 0x40))
#define IOCON_PIO2_5  (* (volatile unsigned long *) (IOCON_BASE + 0x44))
#define IOCON_PIO3_5  (* (volatile unsigned long *) (IOCON_BASE + 0x48))
#define IOCON_PIO0_6  (* (volatile unsigned long *) (IOCON_BASE + 0x4c))
#define IOCON_PIO0_7  (* (volatile unsigned long *) (IOCON_BASE + 0x50))
#define IOCON_PIO2_9  (* (volatile unsigned long *) (IOCON_BASE + 0x54))
#define IOCON_PIO2_10 (* (volatile unsigned long *) (IOCON_BASE + 0x58))
#define IOCON_PIO2_2  (* (volatile unsigned long *) (IOCON_BASE + 0x5c))
#define IOCON_PIO0_8  (* (volatile unsigned long *) (IOCON_BASE + 0x60))
#define IOCON_PIO0_9  (* (volatile unsigned long *) (IOCON_BASE + 0x64))
#define IOCON_PIO0_10 (* (volatile unsigned long *) (IOCON_BASE + 0x68))
#define IOCON_PIO1_10 (* (volatile unsigned long *) (IOCON_BASE + 0x6c))
#define IOCON_PIO2_11 (* (volatile unsigned long *) (IOCON_BASE + 0x70))
#define IOCON_PIO0_11 (* (volatile unsigned long *) (IOCON_BASE + 0x74))
#define IOCON_PIO1_0  (* (volatile unsigned long *) (IOCON_BASE + 0x78))
#define IOCON_PIO1_1  (* (volatile unsigned long *) (IOCON_BASE + 0x7c))
#define IOCON_PIO1_2  (* (volatile unsigned long *) (IOCON_BASE + 0x80))
#define IOCON_PIO3_0  (* (volatile unsigned long *) (IOCON_BASE + 0x84))
#define IOCON_PIO3_1  (* (volatile unsigned long *) (IOCON_BASE + 0x88))
#define IOCON_PIO2_3  (* (volatile unsigned long *) (IOCON_BASE + 0x8c))
#define IOCON_PIO1_3  (* (volatile unsigned long *) (IOCON_BASE + 0x90))
#define IOCON_PIO1_4  (* (volatile unsigned long *) (IOCON_BASE + 0x94))
#define IOCON_PIO1_11 (* (volatile unsigned long *) (IOCON_BASE + 0x98))
#define IOCON_PIO3_2  (* (volatile unsigned long *) (IOCON_BASE + 0x9c))
#define IOCON_PIO1_5  (* (volatile unsigned long *) (IOCON_BASE + 0xa0))
#define IOCON_PIO1_6  (* (volatile unsigned long *) (IOCON_BASE + 0xa4))
#define IOCON_PIO1_7  (* (volatile unsigned long *) (IOCON_BASE + 0xa8))
#define IOCON_PIO3_3  (* (volatile unsigned long *) (IOCON_BASE + 0xa8))

#endif
