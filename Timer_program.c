#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "BIT_MATH.h"
#include "Timer_private.h"
#include "Timer_interface.h"
void Timer_VoidInit(u8 Copy_TimerNum,u8 Copy_TimerMode,u8 Copy_PrescalerSelect,u8 Copy_CompareMatch_or_Preload)
{
	switch(Copy_TimerNum)
	{
		
		case TIMER_0:
			TCCR0 |= Copy_PrescalerSelect;
			TCCR0 |= Copy_TimerMode;
			if((Copy_TimerMode==NORMAL_MODE)||(Copy_TimerMode==CTC_MODE))
			{//Bit 7 – FOC0: Force Output Compare: set to one if non pwm mode
				setbit(TCCR0,7);
				if(Copy_TimerMode==NORMAL_MODE)
				{
					setbit(TIMSK,0);
					//Timer/Counter Register –TCNT0 write to set preload value to timer
					TCNT0=Copy_CompareMatch_or_Preload;
				}
				else
				{
					setbit(TIMSK,1);
					//Output Compare Register –OCR0 set with the value you want tocompare with
					OCR0= Copy_CompareMatch_or_Preload;
				}
			}
			else if(Copy_TimerMode==FAST_PWM_MODE)
			{
				setbit(TCCR0,5);//non inverting mode
			}
			else;
			break;
		case TIMER_1:
			break;
		case TIMER_2:
			break;
		default:
			break;
	}
	//init for normal mode over flow compare match
	/*
	GIE_VoidEnable();
	//Bit 7 – FOC0: Force Output Compare: set to one if non pwm mode
	setbit(TCCR0,7);
	//clear bit WGM00(6) WGM01(3) to select normal mode
	clrbit(TCCR0,6);
	clrbit(TCCR0,3);
	//CS00:CS02 select clock source with prescaller 256 prescaller
	clrbit(TCCR0,0);
	clrbit(TCCR0,1);
	setbit(TCCR0,2);
	//Timer/Counter Register –TCNT0 write to set preload value to timer
	TCNT0=0b11101110;
	//Timer/Counter Interrupt MaskRegister – TIMSK
	//Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
	clrbit(TIMSK,1);
	//Bit 0 – TOIE0: Timer/Counter0 Overflow Interrupt Enable
	setbit(TIMSK,0);
	//preload value 238
	*/
	//init for ctc mode
	/*GIE_VoidEnable();
	//Bit 7 – FOC0: Force Output Compare: set to onw if non pwm mode
	setbit(TCCR0,7);
	//clear bit WGM00(6) WGM01(3) to select normal mode
	clrbit(TCCR0,6);
	setbit(TCCR0,3);
	//CS00:CS02 select clock source with prescaller 256 prescaller
	clrbit(TCCR0,0);
	clrbit(TCCR0,1);
	setbit(TCCR0,2);
	//Output Compare Register –OCR0 set with the value you want tocompare with
	OCR0= 125;
	//Bit 1 – OCIE0: Timer/Counter0 Output Compare Match Interrupt Enable
	clrbit(TIMSK,0);
	setbit(TIMSK,1);*/
}
void Timer0_VoidSetDutyCycle(u8 Copy_DutyCycle)
{
	float signal = (Copy_DutyCycle/(float)100)*256;
	OCR0= (u8)signal;
}
/*
void __vector_11(void)
{
	static u8 count=0;
	//case toggle every 1s , 8mhz ,256 pre , 8bit timer
	//set preload
	if(count==250)
	{
		//preload value 238
		//TCNT0=0b11101110;
		count=0;
		DIO_TogPinValue(PORTA,PIN0);
	}
	else
		count++;
}
*/
/*void __vector_10(void)
{
	static u8 count=0;
	//case toggle every 1s , 8mhz ,256 pre , 8bit timer
	//set preload
	if(count==250)
	{
		//preload value 238
		//TCNT0=0b11101110;
		count=0;
		DIO_TogPinValue(PORTA,PIN0);
	}
	else
		count++;
}
//for global int enable
void GIE_VoidEnable(void)
{
	setbit(SREG,7);
}*/