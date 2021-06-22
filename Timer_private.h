#ifndef Timer_private_H
#define Timer_private_H
//timer 0 registers
#define TCCR0   *((volatile u8*) 0x53)
#define TCNT0   *((volatile u8*) 0x52)
#define OCR0    *((volatile u8*) 0x5C)
//for timer 0,1,2
#define TIMSK   *((volatile u8*) 0x59)
#define TIFR    *((volatile u8*) 0x58)
//for global int enable
#define SREG    *((volatile u8*) 0x5F)

/*TIMER 1 REGISTERS*/
#define TCCR1A 	*((volatile u8*)0x4F)
#define TCCR1B 	*((volatile u8*)0x4E)
#define TCNT1H 	*((volatile u8*)0x4D)
#define TCNT1L 	*((volatile u8*)0x4C)
#define OCR1AH 	*((volatile u8*)0x4B)
#define OCR1AL 	*((volatile u8*)0x4A)
#define OCR1BH 	*((volatile u8*)0x49)
#define OCR1BL 	*((volatile u8*)0x48)
#define ICR1H 	*((volatile u8*)0x47)
#define ICR1L 	*((volatile u8*)0x46)


/*TIMER 2 REGISTERS*/
#define TCCR2 	*((volatile u8*)0x45)
#define TCNT2 	*((volatile u8*)0x44)
#define OCR2 	*((volatile u8*)0x43)


//void __vector_11(void) __attribute__((signal));
void __vector_10(void) __attribute__((signal));

#endif