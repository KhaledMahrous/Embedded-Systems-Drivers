#ifndef UART_config_H
#define UART_config_H

/************USART CONTROL SECTION********************/
/*
Asynchronous = 1, Synchronous = 0
*/
#define USART_MODE_SELECT 	Asynchronous

/*
PARITY_DISABLE		0
PARITY_EVEN			1
PARITY_ODD			2
*/
#define USART_PARITY_SELECT 	PARITY_DISABLE

/*
STOP_BIT_1 = 0, STOP_BIT_2 = 1
*/
#define USART_STOPBIT_SELECT 	STOP_BIT_1

/*DATA_BITS
BIT_5			0
BIT_6			1
BIT_7			2
BIT_8			3
BIT_9			4
*/
#define USART_DATABITS_SELECT 	BIT_8
/*************INTERRUPTS CONTROL SECTION***************/
/*
RX ENABLE
ENABLE = 1, DISABLE = 0
*/
#define RX_ENABLE 	ENABLE

/*
TX ENABLE
ENABLE = 1, DISABLE = 0
*/
#define TX_ENABLE 	ENABLE

/*
RX COMPLETE INT ENABLE
ENABLE = 1, DISABLE = 0
*/
#define RX_COMPLETE_INT 	DISABLE

/*
TX COMPLETE INT ENABLE
ENABLE = 1, DISABLE = 0
*/
#define TX_COMPLETE_INT 	DISABLE
/************BAUDRATE**************
9600 at 8mhz--> put 51
*/
#define BAUDRATE	51
#endif
