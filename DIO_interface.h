#ifndef _DIO_interface_H_
#define _DIO_interface_H_
/*registers macros*/
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3
/*pin directions*/
#define INPUT 0
#define OUTPUT 1
/*port directions*/
#define PORT_INPUT 0
#define PORT_OUTPUT 0xFF
/*port value*/
#define PORT_LOW 0
#define PORT_HIGH 0xFF
/*pin directions*/
#define LOW 0
#define HIGH 1
/*PIN NUMBERS*/
typedef enum 
{
	PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7
}PIN_t;

void DIO_SetPinDirection(u8 PORT,u8 PIN, u8 DIRECTION);
void DIO_SetPinValue(u8 PORT,u8 PIN, u8 VALUE);
void DIO_TogPinValue(u8 PORT,u8 PIN);

void DIO_SetPortDirection(u8 PORT,u8 DIRECTION);
void DIO_SetPortValue(u8 PORT,u8 VALUE);

//u8	 DIO_GetPortValue(u8 PORT);
u8	 DIO_GetPinValue(u8 PORT,u8 PIN);
#endif