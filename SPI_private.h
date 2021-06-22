#ifndef SPI_private_H
#define SPI_private_H

#define SPCR 	*((volatile u8*)0x2D)
#define SPSR 	*((volatile u8*)0x2E)
#define SPDR 	*((volatile u8*)0x2F)
//SPCR pins
#define SPR0	0
#define SPR1	1
#define CPHA	2
#define CPOL	3
#define MSTR	4
#define DORD	5
#define SPE		6
#define SPIE	7
//SPSR pins
#define SPI2X	0
#define WCOL	6
#define SPIF	7
//clock frequency
#define FOSC_4		0
#define FOSC_16		1
#define FOSC_64		2
#define FOSC_128	3
#define FOSC_2		4
#define FOSC_8		5
#define FOSC_32		6

#define ENABLE		0
#define DISABLE		1
//DATA ORDER
#define LSB_FIRST	0
#define MSB_FIRST	1


#endif