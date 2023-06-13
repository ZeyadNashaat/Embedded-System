#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "LED_interface.h"
#include<util/delay.h>

void main(void)
{
	LED_t LED1=
	{
			DIO_u8PORTA,
			DIO_u8PIN4,
			LED_u8CONNTYPE_SRC
	};
	while (1)
	{
		LED_voidTurnOn(&LED1);
		_delay_ms(2000);
		LED_voidTurnOff(&LED1);
		_delay_ms(2000);
	}
}
