#include "STD_TYPES.h"
#include "DIO_Interface.h"
#include "BIT_MATH.h"
#include "Timer1_private.h"
#include "Timer1_interface.h"
#include "Timer1_config.h"

extern u16 count_ovf;
void Timer1_VoidInit(void)
{
	/****************Timer 1 Mode Select******************************/
	#if TIMER1_MODE_SELECT == NORMAL
	//select normal mode 
	clrbit(TCCR1A,WGM10);
	clrbit(TCCR1A,WGM11);
	clrbit(TCCR1B,WGM12);
	clrbit(TCCR1B,WGM13); 
	/*#elif TIMER0_MODE_SELECT == CTC
	//CTC
	setbit(TCCR0,WGM01);
	clrbit(TCCR0,WGM00);
	OCR0 = OCR0_VALUE;*/
	#elif TIMER1_MODE_SELECT == FAST_PWM
	//select Fast PWM Mode
	setbit(TCCR1B,WGM12);
		#if TIMER1_FAST_PWM_MODE_OUTPUTPIN_MODE	== NON_INVERTING_A
			//Noninverting Mode 
			//CODE
			setbit(TCCR1A,COM1A1);
			clrbit(TCCR1A,COM1A0);
			clrbit(TCCR1A,COM1B1);
			clrbit(TCCR1A,COM1B0);
		#elif TIMER1_FAST_PWM_MODE_OUTPUTPIN_MODE	== NON_INVERTING_B
			//Noninverting Mode 
			//CODE
			
			setbit(TIMSK,OCIE1B);/*SET COMPARE MATCH FLAG FOR OCR1B*/
			//setbit(TIMSK,OCIE1A);/*SET COMPARE MATCH FLAG FOR OCR1A*/
			
			clrbit(TCCR1A,COM1A1);
			clrbit(TCCR1A,COM1A0);
			setbit(TCCR1A,COM1B1);
			clrbit(TCCR1A,COM1B0);
		#else
			//Wrong input 
			#warning "Wrong Input for Timer 1 MODE"
		#endif
		#if TIMER1_FAST_PWM_SELECT == TOP_OCR1A
				setbit(TCCR1A,WGM10);
				setbit(TCCR1A,WGM11);
				setbit(TCCR1B,WGM13); 	
		#endif
	/*#elif TIMER0_MODE_SELECT == PWM_PHASE_CORRECT
	//select Phase Correct PWM Mode 
	clrbit(TCCR0,WGM01);
	setbit(TCCR0,WGM00);
		#if TIMER0_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE		==	 CLEAR_WHEN_UP_SET_WHEN_DOWN
		//Noninverting Mode 
		//CODE
		setbit(TCCR0,COM01);
		clrbit(TCCR0,COM00);
		#elif TIMER0_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE	==	 SET_WHEN_UP_CLEAR_WHEN_DOWN
		//Noninverting Mode 
		//CODE
		setbit(TCCR0,COM01);
		setbit(TCCR0,COM00);
		#endif*/
	#else 
		//Wrong input 
		#warning "Wrong Input for Timer 1 MODE"
	#endif
	
	/****************Timer 1 Prescaler Select*************************/
	#if TIMER1_PRESCALER_SELECT == NO_ClOCK_SOURCE
	//No clock source (Timer/Counter stopped).
	clrbit(TCCR1B,CS12);
	clrbit(TCCR1B,CS11);
	clrbit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == PRESCALER_1
	//clkI/O/(No prescaling)
	clrbit(TCCR1B,CS12);
	clrbit(TCCR1B,CS11);
	setbit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == PRESCALER_8
	//clkI/O/8 (From prescaler)
	clrbit(TCCR1B,CS12);
	setbit(TCCR1B,CS11);
	clrbit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == PRESCALER_64
	//clkI/O/64 (From prescaler)
	clrbit(TCCR1B,CS12);
	setbit(TCCR1B,CS11);
	setbit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == PRESCALER_256
	//clkI/O/256 (From prescaler)
	setbit(TCCR1B,CS12);
	clrbit(TCCR1B,CS11);
	clrbit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == PRESCALER_1024
	//clkI/O/1024 (From prescaler)
	setbit(TCCR1B,CS12);
	clrbit(TCCR1B,CS11);
	setbit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == PRESCALER_EXTERNAL_T0_FALLINGEDGE
	//External clock source on T0 pin. Clock on falling edge.
	setbit(TCCR1B,CS12);
	setbit(TCCR1B,CS11);
	clrbit(TCCR1B,CS10);
	#elif TIMER1_PRESCALER_SELECT == PRESCALER_EXTERNAL_T0_RISINGEDGE
	//External clock source on T0 pin. Clock on rising edge.
	setbit(TCCR1B,CS12);
	setbit(TCCR1B,CS11);
	setbit(TCCR1B,CS10);
	#else 
		//Wrong input 
		#warning "Wrong Input for Timer 1 Prescaler"
	#endif
	
	/****************Timer 1 ICU NOISE CANCLER*************************/
	#if TIMER1_NOISECANCLER_SELECT == ENABLED
		setbit(TCCR1B,ICNC1);
	#elif TIMER1_NOISECANCLER_SELECT == DISABLED
		clrbit(TCCR1B,ICNC1);
	#else 
		//Wrong input 
		#warning "Wrong Input for Timer 1 ICU NOISE CANCLER"
	#endif
	
	/****************Timer 1 ICU EDGE SELECT*************************/
	#if TIMER1_ICUEDGE_SELECT == RISING
		setbit(TCCR1B,ICES1);
	#elif TIMER1_ICUEDGE_SELECT == FALLING
		clrbit(TCCR1B,ICES1);
	#else 
		//Wrong input 
		#warning "Wrong Input for Timer 1 ICU EDGE SELECT"
	#endif
	
	/****************Timer 1 ICU INTERRUPT SELECT*************************/
	#if TIMER1_ICUINTERRUPT_SELECT == ENABLED
		setbit(TIMSK,TICIE1);
	#elif TIMER1_ICUINTERRUPT_SELECT == DISABLED
		clrbit(TIMSK,TICIE1);
	#else 
		//Wrong input 
		#warning "Wrong Input for Timer 1 ICU INTERRUPT SELECT"
	#endif
	
	/****************Timer 1 Overflow Interrupt Enable*************************/
	#if TIMER1_OVERFLOW_INTERRUPT_SELECT == ENABLED
		setbit(TIMSK,TOIE1);
	#elif TIMER1_OVERFLOW_INTERRUPT_SELECT == DISABLED
		clrbit(TIMSK,TOIE1);
	#else 
		//Wrong input 
		#warning "Wrong Input for Timer 1 Overflow Interrupt Enable"
	#endif
	
	/*****************Timer 0 Overflow Interrupt Enable/Disable*******/
	/*#if TIMER0_NORMAL_MODE_INTERRUPT == ENABLE
	setbit(TIMSK,TOIE0);
	#elif TIMER0_NORMAL_MODE_INTERRUPT == DISABLE
	clrbit(TIMSK,TOIE0);
	#endif*/
	
	/*****************Timer 0 Overflow Interrupt Enable/Disable*******/
	/*#if TIMER0_CTC_MODE_INTERRUPT == ENABLE
	setbit(TIMSK,OCIE0);
	#elif TIMER0_CTC_MODE_INTERRUPT == DISABLE
	clrbit(TIMSK,OCIE0);
	#endif*/
	
	
}

void (*TIMER1_ICU_PTRFUN)(void)=NULL;/*ptr to function takes null and return null*/
void TIMER1_VoidSetCallBack(void (*ptr)(void))//call back function which will be called from main with the pointer to function wants to execute in ISR
{
	TIMER1_ICU_PTRFUN = ptr;
}

void set_OCR1A_top(u16 loc_value)
{
	OCRA_D=loc_value;
}
void set_OCR1B_duty(u16 loc_value)
{
	u32 duty_cycle= (loc_value*20000)/100;
	OCRB_D=duty_cycle;
}
/*
void __vector_6(void)
{
	if(TIMER1_ICU_PTRFUN!=NULL)
		TIMER1_ICU_PTRFUN();
	//flag=0;
	/*if(flag==0)
	{
		flag++;
		snap1=0;
		snap1=ICU_D+(count_ovf*65536);
		//to take the second snap at falling edge
		clrbit(TCCR1B,ICES1);
	}
	else if(flag == 1)
	{
		flag++;
		snap2=0;
		snap2=ICU_D+(count_ovf*65536);
		//to take the third snap at Rising edge
		setbit(TCCR1B,ICES1);
	}
	else if(flag==2)
	{
		flag++;
		snap3=0;
		snap3=ICU_D+(count_ovf*65536);
	}
	else;
}*/
/*
void __vector_9(void)
{
	count_ovf++;
}
*/
/*
void Timer1_VoidSetDutyCycle(u8 Copy_DutyCycle)
{
	float signal = (Copy_DutyCycle/(float)100)*256;
	OCR0= (u8)signal;
}
*/
