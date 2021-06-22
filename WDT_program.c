#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT_private.h"
#include "WDT_interface.h"
void WDT_VoidEnable(void)
{
	//1 sec delay 
	setbit(WDTCR,WDP2);
	setbit(WDTCR,WDP1);
	clrbit(WDTCR,WDP0);
	//enable watchdog
	setbit(WDTCR,WDE);
}
void WDT_VoidDisable(void)
{
	//set both WDE and WDTOE 
	WDTCR = 0b00011000;
	//in 4 clock cycles close WDE
	WDTCR = 0;
}