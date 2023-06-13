#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GIE_register.h"
#include "GIE_interface.h"

void GIE_voidState(u8 Copy_u8GIEState)
{
	switch(Copy_u8GIEState)
	{
	case (GIE_Enable):
			SET_BIT(SREG,SREG_I);
	break;
	case (GIE_Disable):
			CLR_BIT(SREG,SREG_I);
	}
}
