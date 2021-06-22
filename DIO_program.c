#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "DIO_interface.h"
#include "DIO_private.h"

void DIO_SetPinDirection(u8 PORT,u8 PIN, u8 DIRECTION)
{
	switch(PORT)
	{
		case PORTA: if(DIRECTION == INPUT)
					{
						clrbit(DDRA_REG,PIN);
					}
					else if(DIRECTION == OUTPUT)
					{
							setbit(DDRA_REG,PIN);
					}
					else;
					break;
		case PORTB: if(DIRECTION == INPUT)
					{
						clrbit(DDRB_REG,PIN);
					}
					else if(DIRECTION == OUTPUT)
					{
							setbit(DDRB_REG,PIN);
					}
					else;
					break;
		case PORTC: if(DIRECTION == INPUT)
					{
						clrbit(DDRC_REG,PIN);
					}
					else if(DIRECTION == OUTPUT)
					{
							setbit(DDRC_REG,PIN);
					}
					else;
					break;
		case PORTD: if(DIRECTION == INPUT)
					{
						clrbit(DDRD_REG,PIN);
					}
					else if(DIRECTION == OUTPUT)
					{
							setbit(DDRD_REG,PIN);
					}
					else;
					break;
		default:    break;
	}
}
void DIO_SetPinValue(u8 PORT,u8 PIN, u8 VALUE)
{
	{
	switch(PORT)
	{
		case PORTA: if(VALUE == LOW)
					{
						clrbit(PORTA_REG,PIN);
					}
					else if(VALUE == HIGH)
					{
						setbit(PORTA_REG,PIN);
					}
					else;
					break;
		case PORTB: if(VALUE == LOW)
					{
						clrbit(PORTB_REG,PIN);
					}
					else if(VALUE == HIGH)
					{
						setbit(PORTB_REG,PIN);
					}
					else;
					break;
		case PORTC: if(VALUE == LOW)
					{
						clrbit(PORTC_REG,PIN);
					}
					else if(VALUE == HIGH)
					{
						setbit(PORTC_REG,PIN);
					}
					else;
					break;
		case PORTD: if(VALUE == LOW)
					{
						clrbit(PORTD_REG,PIN);
					}
					else if(VALUE == HIGH)
					{
						setbit(PORTD_REG,PIN);
					}
					else;
					break;
		default:    break;
	}
}
}
void DIO_TogPinValue(u8 PORT,u8 PIN)
{
	switch(PORT)
	{
		case PORTA: togbit(PORTA_REG,PIN);
					break;
		case PORTB: togbit(PORTB_REG,PIN);
					break;
		case PORTC: togbit(PORTC_REG,PIN);
					break;
		case PORTD: togbit(PORTD_REG,PIN);
					break;
		default: //error
					break;
	}
}

void DIO_SetPortDirection(u8 PORT,u8 DIRECTION)
{
	switch(PORT)
	{
		case PORTA:	DDRA_REG = DIRECTION;
					break;
		case PORTB: DDRB_REG = DIRECTION;
					break;
		case PORTC: DDRC_REG = DIRECTION;
					break;
		case PORTD: DDRD_REG = DIRECTION;
					break;
		default:	break;
	}
}
void DIO_SetPortValue(u8 PORT,u8 VALUE)
{
	switch(PORT)
	{
		case PORTA:	PORTA_REG = VALUE;
					break;
		case PORTB: PORTB_REG = VALUE;
					break;
		case PORTC: PORTC_REG = VALUE;
					break;
		case PORTD: PORTD_REG = VALUE;
					break;
		default:	break;
	}
}
/*
void DIO_GetPortValue(u8 PORT ,u8 data[])
{
	u8 port;
	 portCehck(PORT);
	 switch(PORT){
			case PORTA:
					port = PINA;
							break;
				case PORTB:
					port = PINB;
							break;
				case PORTC:
					port = PINC;
							break;
				case PORTD:
					port = PIND;
							break;
				default:	break;
	 }
	 for(int i = 0; i < 8 ; i++){
		 data[i] = GET_BIT(port,i);
	 }
}*/
	/*u8 DIO_u8GetPortVal(u8 PortNo , u8* PortVal)
	{
	u8 FuncReturnState = STD_OK;
	if( (PortNo >= DIO_PORTA) && (PortNo <= DIO_PORTD) &&(PortVal != STD_NULL) )
	{
		switch (PortNo)
		{
			case DIO_PORTA:
			*PortVal = PINA;
			break;
			case DIO_PORTB:
			*PortVal = PINB;
			case DIO_PORTC:
			*PortVal = PINC;
			break;
			case DIO_PORTD:
			*PortVal = PIND;
			break;
		}
	}
		else
		{
			FuncReturnState = STD_NOK;
		}
		return FuncReturnState;
	}*/
u8	 DIO_GetPinValue(u8 PORT,u8 PIN)
{
	u8 pinvalue;
	switch(PORT)
	{
		case PORTA: pinvalue = getbit(PINA_REG,PIN);
					break;
		case PORTB: pinvalue = getbit(PINB_REG,PIN);
					break;
		case PORTC: pinvalue = getbit(PINC_REG,PIN);
					break;
		case PORTD: pinvalue = getbit(PIND_REG,PIN);
					break;
		default:	break;
	}
	return pinvalue;
}