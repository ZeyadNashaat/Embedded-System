#include "STD_TYPES.h"
#include<util/delay.h>
#include"GIE_interface.h"
#include"DIO_interface.h"
#include"ADC_interface.h"

void NotifFunc(void);

void main(void)
{
	u8 Local_u8error;u16* millivolt;u16* reading;
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_INPUT);
	DIO_u8SetPinDirection(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PIN_OUTPUT);
	GIE_voidState(GIE_Enable);
	ADC_voidInit();
	while(1)
	{
		Local_u8error= ADC_u8StartConversionAsynch(ADC_Channel_Sin_A0,millivolt,reading,&NotifFunc);
		DIO_u8SetPortValue(DIO_u8PORTC,*reading);
		_delay_ms(5000);
	}
}
void NotifFunc(void)
{
	DIO_u8SetPinValue(DIO_u8PORTD,DIO_u8PIN0,DIO_u8PIN_HIGH);
}
