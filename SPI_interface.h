#ifndef SPI_interface_H
#define SPI_interface_H

void SPI_VoidMasterInit(void);
void SPI_VoidSlaveInit(void);
void SPI_VoidMasterTransmit(u8 data);
u8 SPI_VoidSlaveRecieve(void);

#endif