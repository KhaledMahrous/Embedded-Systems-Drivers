#ifndef Timer1_config_H
#define Timer1_config_H

#define MAXOVERFLOW 625

/****************Timer 1 Select Mode *********************
NORMAL				=	0
PWM_FAST			=	1
CTC					=	2
PWM_PHASE_CORRECT	=	3

case(pwm_FAST)
choose one of modes: 
*EIGHT_BIT
*NINE_BIT
*TEN_BIT
*TOP_ICR1
*TOP_OCR1A
 */
#define TIMER1_MODE_SELECT	FAST_PWM
//enter value if you want to preload from 0 to 255 if you don't want to preload set as 0;
#define TIMER1_FAST_PWM_SELECT	TOP_OCR1A
/*****************Timer 1 Fast PWM Select OUTPUT pin Mode *******************
NON_INVERTING_A		=	0
INVERTING_A			=	1
NON_INVERTING_B		=	2
INVERTING_B			=	3	*/											
#define TIMER1_FAST_PWM_MODE_OUTPUTPIN_MODE	 NON_INVERTING_B

/****************Timer 1 Prescaler Select*************************
 NO_ClOCK_SOURCE					=	0
 PRESCALER_1						=	1
 PRESCALER_8						=	2
 PRESCALER_64						=	3
 PRESCALER_256						=	4
 PRESCALER_1024						=	5
 PRESCALER_EXTERNAL_T0_FALLINGEDGE	=	6
 PRESCALER_EXTERNAL_T0_RISINGEDGE	=	7 							*/
#define TIMER1_PRESCALER_SELECT		 PRESCALER_8

/****************Timer 1 ICU noise canceler Select*************************
ENABLED
DISABLED
*/
#define TIMER1_NOISECANCLER_SELECT		DISABLED
/****************Timer 1 ICU noise canceler Select*************************
RISING
FALLING
*/
#define TIMER1_ICUEDGE_SELECT		RISING

/****************Timer 1 ICU INTERRUPT Select*************************
ENABLED
DISABLED
*/
#define TIMER1_ICUINTERRUPT_SELECT		DISABLED

/****************Timer 1 Overflow Interrupt Enable*************************
ENABLED
DISABLED
*/
#define TIMER1_OVERFLOW_INTERRUPT_SELECT	DISABLED





/*****************Timer 0 Phase Correct PWM Select OUTPUT pin Mode *******************
CLEAR_WHEN_UP_SET_WHEN_DOWN			=	0
SET_WHEN_UP_CLEAR_WHEN_DOWN			=	1						
#define TIMER0_PHASECORRECT_PWM_MODE_OUTPUTPIN_MODE		 SET_WHEN_UP_CLEAR_WHEN_DOWN*/



/******************************		max preload value is 255*****************************/
#define TIMER0_PRELOAD_VALUE	0




/*******************************	Timer 0 NORMAL MODE Interrupt Select	**************************
 ENABLE  = 0
 DISABLE = 1			
#define TIMER0_NORMAL_MODE_INTERRUPT	ENABLE
#define ENABLE			0
#define DISABLE 		1*/


/*******************************	Timer 0 CTC MODE Interrupt Select	**************************
 ENABLE  = 0
 DISABLE = 1			
#define TIMER0_CTC_MODE_INTERRUPT	ENABLE*/


#endif
