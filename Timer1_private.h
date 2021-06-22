#ifndef Timer1_private_H
#define Timer1_private_H
//timer 0 registers
#define TCCR0   *((volatile u8*) 0x53)
#define TCNT0   *((volatile u8*) 0x52)
#define OCR0    *((volatile u8*) 0x5C)
//for timer 0,1,2
#define TIMSK   *((volatile u8*) 0x59)
#define TIFR    *((volatile u8*) 0x58)

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
//register to get both ICR1L and ICR1H
#define ICU_D 	*((volatile u16*) 0x46)
#define OCRA_D 	*((volatile u16*) 0x4A)
#define OCRB_D 	*((volatile u16*) 0x48)
/*TIMER 2 REGISTERS*/
#define TCCR2 	*((volatile u8*)0x45)
#define TCNT2 	*((volatile u8*)0x44)
#define OCR2 	*((volatile u8*)0x43)

#define ENABLED   1
#define DISABLED  0
#define NULL	0
//ICU EDGE SELECT
#define RISING	1
#define FALLING	0
//TCCR1A Register
#define WGM10	0
#define	WGM11	1
#define	COM1B0	4
#define	COM1B1	5
#define	COM1A0	6
#define	COM1A1	7
//TCCR1B Register
#define CS10	0
#define	CS11	1
#define	CS12	2
#define WGM12	3
#define	WGM13	4
#define	ICES1	6
#define	ICNC1	7
//TIMSK Register
#define TOIE0  0
#define OCIE0  1
#define TOIE1  2
#define OCIE1B 3
#define OCIE1A 4
#define TICIE1 5


/****************Timer 1 Select Mode Options *********************/
#define NORMAL					0
#define FAST_PWM				1
/****************Timer 1 FAST PWM OPTIONS Options *********************/
#define EIGHT_BIT					0
#define NINE_BIT					1
#define TEN_BIT						2
#define TOP_ICR1					3
#define TOP_OCR1A					4

/****************Timer 1 Prescaler Select Options*************************/
#define NO_ClOCK_SOURCE							0
#define PRESCALER_1								1
#define PRESCALER_8								2
#define PRESCALER_64							3
#define PRESCALER_256							4
#define PRESCALER_1024							5
#define PRESCALER_EXTERNAL_T0_FALLINGEDGE		6
#define PRESCALER_EXTERNAL_T0_RISINGEDGE		7
/*****************Timer 1 Fast PWM Select OUTPUT pin Mode *******************/
#define NON_INVERTING_A	0
#define INVERTING_A		1
#define NON_INVERTING_B	2
#define INVERTING_B		3

/*****************Timer 1 Phase Correct PWM Select OUTPUT pin Mode *******************/
#define CLEAR_WHEN_UP_SET_WHEN_DOWN		0
#define SET_WHEN_UP_CLEAR_WHEN_DOWN		1

void __vector_9(void) __attribute__((signal));
void __vector_6(void) __attribute__((signal));

#endif