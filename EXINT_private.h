#ifndef _EXINT_private_H
#define _EXINT_private_H

#define MCUCR  *((volatile u8*) 0x55)
#define MCUCSR *((volatile u8*) 0x54)
#define GICR   *((volatile u8*) 0x5B)
#define GIFR   *((volatile u8*) 0x5A)
#define SREG   *((volatile u8*) 0x5F)

void __vector_1(void) __attribute__((signal));

#endif