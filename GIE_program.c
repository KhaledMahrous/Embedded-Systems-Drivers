#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_private.h"
#include "GIE_interface.h"

void GIE_VoidEnable(void)
{
	setbit(SREG,7);
}
void GIE_VoidDisable(void)
{
	clrbit(SREG,7);
}
