#include "STD_TYPES.h"
#include "DIO_interface.h"
#include"SW_interface.h"
#include <util/delay.h>

void main(void)
{
	u8 Local_u8ButtonState;
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN7,DIO_u8PIN_HIGH);
	SW_t SW1;
	SW1.PORT=DIO_u8PORTD;
	SW1.PIN=DIO_u8PIN7;
	SW1.CONNTYPE=SW_u8CONNTYPE_PULLUP;
	SW1.LOCKTYPE=SW_u8LOCKTYPE_TEMP;
	while(1)
	{
		Local_u8ButtonState=SW_u8GetState(&SW1);
		if (Local_u8ButtonState==SW_u8STATE_PRESSED)
		{
			DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_HIGH);
		}
		else
		{
			DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_OUTPUT);
			DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN7,DIO_u8PIN_LOW);

		}
	}

}
