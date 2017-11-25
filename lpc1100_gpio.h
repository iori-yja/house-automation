#ifndef _LPC1114_H_
#define _LPC1114_H_

#define GPIO0_BASE   (AHB_START + 0x00000000)
#define GPIO1_BASE   (AHB_START + 0x00010000)
#define GPIO2_BASE   (AHB_START + 0x00020000)
#define GPIO3_BASE   (AHB_START + 0x00030000)

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

#define GPIO0DATA (* (volatile unsigned long *) (GPIO0_BASE + 0x3ffc))
#define GPIO1DATA (* (volatile unsigned long *) (GPIO1_BASE + 0x3ffc))
#define GPIO2DATA (* (volatile unsigned long *) (GPIO2_BASE + 0x3ffc))
#define GPIO3DATA (* (volatile unsigned long *) (GPIO3_BASE + 0x3ffc))

#define GPIO0DIR  (* (volatile unsigned long *) (GPIO0_BASE + 0x8000))
#define GPIO1DIR  (* (volatile unsigned long *) (GPIO1_BASE + 0x8000))
#define GPIO2DIR  (* (volatile unsigned long *) (GPIO2_BASE + 0x8000))
#define GPIO3DIR  (* (volatile unsigned long *) (GPIO3_BASE + 0x8000))

/* Interrupt sensitive 0 = edge sensitive, 1 = level sensitive */
#define GPIO0IS   (* (volatile unsigned long *) (GPIO0_BASE + 0x8004))
#define GPIO1IS   (* (volatile unsigned long *) (GPIO1_BASE + 0x8004))
#define GPIO2IS   (* (volatile unsigned long *) (GPIO2_BASE + 0x8004))
#define GPIO3IS   (* (volatile unsigned long *) (GPIO3_BASE + 0x8004))

/* Interrupt both edges sense, 0 = depends on IEV, 1 = both */
#define GPIO0IBE  (* (volatile unsigned long *) (GPIO0_BASE + 0x8008))
#define GPIO1IBE  (* (volatile unsigned long *) (GPIO1_BASE + 0x8008))
#define GPIO2IBE  (* (volatile unsigned long *) (GPIO2_BASE + 0x8008))
#define GPIO3IBE  (* (volatile unsigned long *) (GPIO3_BASE + 0x8008))

/* Interrupt event, 0 = falling or low, 1 = rising or high */
#define GPIO0IEV  (* (volatile unsigned long *) (GPIO0_BASE + 0x800c))
#define GPIO1IEV  (* (volatile unsigned long *) (GPIO1_BASE + 0x800c))
#define GPIO2IEV  (* (volatile unsigned long *) (GPIO2_BASE + 0x800c))
#define GPIO3IEV  (* (volatile unsigned long *) (GPIO3_BASE + 0x800c))

/* Interrupt mask (enable), 1 = enable */
#define GPIO0IE   (* (volatile unsigned long *) (GPIO0_BASE + 0x8010))
#define GPIO1IE   (* (volatile unsigned long *) (GPIO1_BASE + 0x8010))
#define GPIO2IE   (* (volatile unsigned long *) (GPIO2_BASE + 0x8010))
#define GPIO3IE   (* (volatile unsigned long *) (GPIO3_BASE + 0x8010))

/* Interrupt raw status, 0 = empty, 1 = arrived. RO */
#define GPIO0RIS  (* (volatile unsigned long *) (GPIO0_BASE + 0x8014))
#define GPIO1RIS  (* (volatile unsigned long *) (GPIO1_BASE + 0x8014))
#define GPIO2RIS  (* (volatile unsigned long *) (GPIO2_BASE + 0x8014))
#define GPIO3RIS  (* (volatile unsigned long *) (GPIO3_BASE + 0x8014))

/* Interrupt masked interrupt status, 0 = empty, 1 = arrived. RO */
#define GPIO0MIS  (* (volatile unsigned long *) (GPIO0_BASE + 0x8018))
#define GPIO1MIS  (* (volatile unsigned long *) (GPIO1_BASE + 0x8018))
#define GPIO2MIS  (* (volatile unsigned long *) (GPIO2_BASE + 0x8018))
#define GPIO3MIS  (* (volatile unsigned long *) (GPIO3_BASE + 0x8018))

/* Interrupt clear, 1 = clear. WO */
#define GPIO0IC   (* (volatile unsigned long *) (GPIO0_BASE + 0x8018))
#define GPIO1IC   (* (volatile unsigned long *) (GPIO1_BASE + 0x8018))
#define GPIO2IC   (* (volatile unsigned long *) (GPIO2_BASE + 0x8018))
#define GPIO3IC   (* (volatile unsigned long *) (GPIO3_BASE + 0x8018))

#endif
