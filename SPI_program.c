#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_VoidMasterInit(void)
{
	//set MOSI and SCK as output
	//enable SPI, MASTER mode
	setbit(SPCR,SPE);
	setbit(SPCR,MSTR);
	//CLOCK POLARITY AND CLOCK PHASE
	clrbit(SPCR,CPOL);//rising edge leading
	clrbit(SPCR,CPHA);//recieve in leading edge and send on trailling
	//SCK Frequency
	/********CLOCK*****************/
	#if SPI_FREQUENCY == FOSC_4
		clrbit(SPCR,SPR0);
		clrbit(SPCR,SPR1);
		clrbit(SPSR,SPI2X);
	#elif SPI_FREQUENCY == FOSC_16
		setbit(SPCR,SPR0);
		clrbit(SPCR,SPR1);
		clrbit(SPSR,SPI2X);
	#elif SPI_FREQUENCY == FOSC_64	
		clrbit(SPCR,SPR0);
		setbit(SPCR,SPR1);
		clrbit(SPSR,SPI2X);		
	#elif SPI_FREQUENCY == FOSC_128
		setbit(SPCR,SPR0);
		setbit(SPCR,SPR1);
		clrbit(SPSR,SPI2X);
	#elif SPI_FREQUENCY == FOSC_2
		clrbit(SPCR,SPR0);
		clrbit(SPCR,SPR1);
		setbit(SPSR,SPI2X);		
	#elif SPI_FREQUENCY == FOSC_8
		setbit(SPCR,SPR0);
		clrbit(SPCR,SPR1);
		setbit(SPSR,SPI2X);	
	#elif SPI_FREQUENCY == FOSC_32
		clrbit(SPCR,SPR0);
		setbit(SPCR,SPR1);
		setbit(SPSR,SPI2X);
	#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	
	/**********INTERRUPT*************/
	#if SPI_INTERRUPT == ENABLE
		setbit(SPCR,SPIE);
	#elif SPI_INTERRUPT == DISABLE
		clrbit(SPCR,SPIE);
		#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	
	/**********DATA ORDER*************/
	#if DATA_ORDER == LSB_FIRST
		setbit(SPCR,DORD);
	#elif DATA_ORDER == MSB_FIRST
		clrbit(SPCR,DORD);
		#else
	//Wrong input 
		#warning "Wrong Input"
	#endif



}
void SPI_VoidSlaveInit(void)
{
	/* Set MISO output, all others input */
	//enable SPI, MASTER mode
	setbit(SPCR,SPE);
	clrbit(SPCR,MSTR);

	//CLOCK POLARITY AND CLOCK PHASE
	clrbit(SPCR,CPOL);//rising edge leading
	clrbit(SPCR,CPHA);//recieve in leading edge and send on trailling

	/**********INTERRUPT*************/
	#if SPI_INTERRUPT == ENABLE
		setbit(SPCR,SPIE);
	#elif SPI_INTERRUPT == DISABLE
		clrbit(SPCR,SPIE);
		#else
	//Wrong input 
		#warning "Wrong Input"
	#endif
	
	/**********DATA ORDER*************/
	#if DATA_ORDER == LSB_FIRST
		setbit(SPCR,DORD);
	#elif DATA_ORDER == MSB_FIRST
		clrbit(SPCR,DORD);
		#else
	//Wrong input 
		#warning "Wrong Input"
	#endif


}
void SPI_VoidMasterTransmit(u8 data)
{
	SPDR = data;
	/* Wait for transmission complete */
	while(!(SPSR & (1<<SPIF)))
	;
}
u8 SPI_VoidSlaveRecieve(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return data register */
	return SPDR;
}
