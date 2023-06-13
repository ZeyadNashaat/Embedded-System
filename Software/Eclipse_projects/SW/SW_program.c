#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include<util/delay.h>

#include "DIO_interface.h"
#include "SW_interface.h"
#include "SW_config.h"
#include "SW_private.h"

u8 SW_u8GetState(SW_t* Copy_pu8struct)
{
	u8 Local_u8SwState;
	u8 Pin_u8Value;
	DIO_u8GetPinValue((Copy_pu8struct->PORT), (Copy_pu8struct->PIN), &Pin_u8Value);
	if ((Copy_pu8struct->LOCKTYPE)==SW_u8LOCKTYPE_TEMP)
	{
		_delay_ms(100);
		if ((Copy_pu8struct->CONNTYPE)==SW_u8CONNTYPE_PULLUP)
		{
			if (Pin_u8Value==0)
			{
				Local_u8SwState=SW_u8STATE_PRESSED;
			}
			else
			{
				Local_u8SwState=SW_u8STATE_NPRESSED;
			}

		}
		else if ((Copy_pu8struct->CONNTYPE)==SW_u8CONNTYPE_PULLDOWN)
		{
			if (Pin_u8Value==0)
			{
				Local_u8SwState=SW_u8STATE_NPRESSED;
			}
			else
			{
				Local_u8SwState=SW_u8STATE_PRESSED;
			}
		}
	}
	else if ((Copy_pu8struct->LOCKTYPE)==SW_u8LOCKTYPE_SELF)
	{
		if ((Copy_pu8struct->CONNTYPE)==SW_u8CONNTYPE_PULLUP)
		{
			if (Pin_u8Value==0)
			{
				Local_u8SwState=SW_u8STATE_PRESSED;
			}
			else
			{
				Local_u8SwState=SW_u8STATE_NPRESSED;
			}

		}
		else if ((Copy_pu8struct->CONNTYPE)==SW_u8CONNTYPE_PULLDOWN)
		{
			if (Pin_u8Value==0)
			{
				Local_u8SwState=SW_u8STATE_NPRESSED;
			}
			else
			{
				Local_u8SwState=SW_u8STATE_PRESSED;
			}
		}

	}

	return Local_u8SwState;
}
