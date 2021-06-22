#ifndef Timer_interface_H
#define Timer_interface_H
void GIE_VoidEnable(void);
void Timer_VoidInit(u8 Copy_TimerNum,u8 Copy_TimerMode,u8 Copy_PrescalerSelect,u8 Copy_CompareMatch_or_Preload);
//timer select
#define TIMER_0				0
#define TIMER_1				1
#define TIMER_2				2
//modes select
#define NORMAL_MODE 		0X00
#define PHASE_PWM_MODE 		0X40
#define CTC_MODE	 		0X08
#define FAST_PWM_MODE 		0X48
//prescaller select
#define PRE_SCALER_NO_CLOCK						0X00
#define PRE_SCALER_NO_PRE						0X01
#define PRE_SCALER_8							0X02
#define PRE_SCALER_64							0X03
#define PRE_SCALER_256							0X04
#define PRE_SCALER_1024							0X05
#define PRE_SCALER_External_CLOCK_T0_RISING		0X06
#define PRE_SCALER_External_CLOCK_T0_FAILING	0X07

#endif