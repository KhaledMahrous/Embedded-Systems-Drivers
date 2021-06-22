#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_VoidInit(void)
{
	
	u8 UCSRC_help= 0b10000000;
	/****select UCSRC*******/
	//setbit(UBRRH,7);
	
	
	setbit(UCSRB,RXEN);//enable rx
	setbit(UCSRB,TXEN);//enable tx
	
	/***BAUDRATE***/
	UBRRH = 0;
	UBRRL = BAUDRATE;
	setbit(UBRRH,URSEL);/*ACCESSING THE UCSRC*/

	#if USART_MODE_SELECT == Asynchronous
		clrbit(UCSRC_help,UMSEL);
	#elif USART_MODE_SELECT == Synchronous
		setbit(UCSRC_help,UMSEL);
	#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	
	#if USART_PARITY_SELECT == PARITY_DISABLE
		clrbit(UCSRC_help,UPM0);
		clrbit(UCSRC_help,UPM1);
	#elif USART_PARITY_SELECT == PARITY_EVEN
		clrbit(UCSRC_help,UPM0);
		setbit(UCSRC_help,UPM1);
	#elif USART_PARITY_SELECT == PARITY_ODD
		setbit(UCSRC_help,UPM0);
		setbit(UCSRC_help,UPM1);
	#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	
	#if USART_STOPBIT_SELECT == STOP_BIT_1
		clrbit(UCSRC_help,USBS);
	#elif USART_STOPBIT_SELECT == STOP_BIT_2
		setbit(UCSRC_help,USBS);
	#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	//interrupts
	#if RX_COMPLETE_INT == DISABLE
		clrbit(UCSRB,RXCIE);
	#elif RX_COMPLETE_INT == ENABLE
		setbit(UCSRB,RXCIE);
	#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	
	#if TX_COMPLETE_INT == DISABLE
		clrbit(UCSRB,TXCIE);
	#elif TX_COMPLETE_INT == ENABLE
		setbit(UCSRB,TXCIE);
	#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	/********DATA_BITS*****************/
	#if USART_DATABITS_SELECT == BIT_5
		clrbit(UCSRB,UCSZ2);
		clrbit(UCSRC_help,UCSZ0);
		clrbit(UCSRC_help,UCSZ1);
	#elif USART_DATABITS_SELECT == BIT_6
		clrbit(UCSRB,UCSZ2);
		setbit(UCSRC_help,UCSZ0);
		clrbit(UCSRC_help,UCSZ1);
	#elif USART_DATABITS_SELECT == BIT_7
		clrbit(UCSRB,UCSZ2);
		clrbit(UCSRC_help,UCSZ0);
		setbit(UCSRC_help,UCSZ1);
	#elif USART_DATABITS_SELECT == BIT_8
		clrbit(UCSRB,UCSZ2);
		setbit(UCSRC_help,UCSZ0);
		setbit(UCSRC_help,UCSZ1);
	#elif USART_DATABITS_SELECT == BIT_9
		setbit(UCSRB,UCSZ2);
		setbit(UCSRC_help,UCSZ0);
		setbit(UCSRC_help,UCSZ1);
	#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	
	UCSRC = UCSRC_help;	/*must put the Register one time as stated in datasheet*/
	/***select UBRRH***/
	//clrbit(UBRRH,7);

	
}
void USART_Transmit(u8 data)
{
	while(!(UCSRA & (1<<UDRE) ));
	UDR = data;
}
u8 USART_Recieve(void)
{
	while(!(UCSRA & (1<<RXC) ));
	return UDR;
}
