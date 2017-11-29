#ifndef _LPC111X_GPIO_H_
#define _LPC111X_GPIO_H_

#define GPIO0_BASE   (AHB_START + 0x00000000)
#define GPIO1_BASE   (AHB_START + 0x00010000)
#define GPIO2_BASE   (AHB_START + 0x00020000)
#define GPIO3_BASE   (AHB_START + 0x00030000)

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
