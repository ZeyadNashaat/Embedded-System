#include "STD_TYPES.h"
#include"DIO_interface.h"
#include"KPD_inteface.h"
#include"KPD_config.h"

void main(void)
{
	DIO_u8SetPortDirection(KPD_COLUMN_PORT,DIO_u8PORT_INPUT);
	DIO_u8SetPortValue(KPD_COLUMN_PORT,DIO_u8PORT_HIGH);
	DIO_u8SetPortDirection(KPD_ROW_PORT,DIO_u8PIN_OUTPUT);
	DIO_u8SetPortValue(KPD_ROW_PORT,DIO_u8PIN_HIGH);
	u8 Local_u8KeyValue;
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	while(1)
	{
		Local_u8KeyValue=KPD_u8GetPressedKey();
		if (Local_u8KeyValue==2)
		{
			DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		}
	}
}
