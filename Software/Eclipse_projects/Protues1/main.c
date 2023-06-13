#include"STD_TYPES.h"
#include"DIO_interface.h"
#include<util/delay.h>
void main(void)
{
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	while(1)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
		_delay_ms(150);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
		_delay_ms(150);
	}
}
