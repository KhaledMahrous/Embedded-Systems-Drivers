//#include <string.h>
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "BIT_MATH.h"
#include "EXINT_interface.h"
#include "EXINT_private.h"
#include <avr/delay.h>

void __vector_1(void)
{
	DIO_TogPinValue(PORTA,PIN0);
}

void EXINT_VoidInit()
{
	//ISC = falling edge mode
	clrbit(MCUCR,0);
	setbit(MCUCR,1);
	// enable PIE of INT0
	setbit(GICR,6);
	//enable GIE global enable
	setbit(SREG,7);
}