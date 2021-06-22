#ifndef _ADC_private_H
#define _ADC_private_H

#define ADMUX   *((volatile u8*) 0x27)
#define ADCSRA  *((volatile u8*) 0x26)
#define ADCH    *((volatile u8*) 0x25)
#define ADCL    *((volatile u8*) 0x24)
#define SFIOR   *((volatile u8*) 0x50)

#define ADC_D 	*((volatile u16*) 0x24)
/*voltage reference*/
#define AREF 				0
#define AVCC 				1
#define Internal_2.56V 		2
/*ADC prescaller selection*/
#define PRESCALLER_2	0
#define PRESCALLER_4	1
#define PRESCALLER_8	2
#define PRESCALLER_16	3
#define PRESCALLER_32	4
#define PRESCALLER_64	5
#define PRESCALLER_128	6
/*ADC adjust selection*/
#define RIGHT_ADJUST	0
#define LEFT_ADJUST		1
/**/


#endif