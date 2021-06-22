#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "ADC_private.h"
#include "BIT_MATH.h"
void ADC_VoidInit(void)
{
	//enable ADC
	setbit(ADCSRA,7);
	#if VOLTAGE_REFERENCE_SELECTION == AREF
		clrbit(ADMUX,6);
		clrbit(ADMUX,7);
	#elif VOLTAGE_REFERENCE_SELECTION == AVCC
		//set refv = AVCC
		setbit(ADMUX,6);
		clrbit(ADMUX,7);
	#elif VOLTAGE_REFERENCE_SELECTION == Internal_2.56V
		setbit(ADMUX,6);
		setbit(ADMUX,7);
	#else
		//Wrong input 
		#warning "Wrong Input for ADC enable"
	#endif
	
	#if ADC_PRESCALLER == PRESCALLER_2
		clrbit(ADCSRA,2);
		clrbit(ADCSRA,1);
		clrbit(ADCSRA,0);
	#elif ADC_PRESCALLER == PRESCALLER_4
		clrbit(ADCSRA,0);
		setbit(ADCSRA,1);
		clrbit(ADCSRA,2);
	#elif ADC_PRESCALLER == PRESCALLER_8
		setbit(ADCSRA,0);
		setbit(ADCSRA,1);
		clrbit(ADCSRA,2);
	#elif ADC_PRESCALLER == PRESCALLER_16
		setbit(ADCSRA,2);
		clrbit(ADCSRA,1);
		clrbit(ADCSRA,0);
	#elif ADC_PRESCALLER == PRESCALLER_32
		setbit(ADCSRA,2);
		clrbit(ADCSRA,1);
		setbit(ADCSRA,0);
	#elif ADC_PRESCALLER == PRESCALLER_64
		//ADC prescaler = 64
		setbit(ADCSRA,2);
		setbit(ADCSRA,1);
		clrbit(ADCSRA,0);
	#elif ADC_PRESCALLER == PRESCALLER_128
		setbit(ADCSRA,2);
		setbit(ADCSRA,1);
		setbit(ADCSRA,0);
	#else
		//Wrong input 
		#warning "Wrong Input for ADC prescaller"
	#endif

	#if ADC_ADJUST == RIGHT_ADJUST
		//ADCLAR = right adjust
		clrbit(ADMUX,5);
	#elif ADC_ADJUST == LEFT_ADJUST
		//ADCLAR = left adjust
		setbit(ADMUX,5);
	#else
		//Wrong input 
		#warning "Wrong Input for ADC adjust"
	#endif
	
	//interrupt and free running cases
	
	/*//ADCLAR = right adjust
	clrbit(ADMUX,5);
	//from 0 to 4 choose when reading ADC
	//disable auto trigger ADATE
	clrbit(ADCSRA,5);
	
	//ADC interrupt enable = 0 
	clrbit(ADCSRA,3);
	//ADC prescaler = 64
	setbit(ADCSRA,2);
	setbit(ADCSRA,1);
	clrbit(ADCSRA,0);*/
}
u16 ADC_u16ReadDigitalValue(u8 copy_u8chnum)
{
	//select channel
	ADMUX = ADMUX&0b11100000;
	if(copy_u8chnum < 8)
		ADMUX|=copy_u8chnum;
	//start conversion
	setbit(ADCSRA,6);
	//wait while conversion completes
	while(getbit(ADCSRA,4)==0)
	{
		
	}
	//clear flag
	setbit(ADCSRA,4);
	//return data
	return ADC_D;
}
/*
int main()
{
	u16 digital_value=0;
	u16 analog_volt =0;
	while(1)
	{
		analog_volt=(digital_value*((u32)5000))/1023;//convert to mv
	}
	return 0;
}	
*/