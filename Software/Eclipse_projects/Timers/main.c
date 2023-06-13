#include"STD_TYPES.h"

#include"DIO_interface.h"
#include"GIE_interface.h"
#include"TIMER_interface.h"

void PWM(void);

void main (void)
{
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
	TIMER0_voidInit();
	TIMER0_u8SetCallBack(&PWM);
	GIE_voidState(GIE_Enable);
	while (1)
	{

	}
}
void PWM(void)
{
	static u8 Local_u8Counter=0;
	Local_u8Counter++;
	if (Local_u8Counter==5)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else if (Local_u8Counter==10)
	{
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_LOW);
	}
	else if (Local_u8Counter==15)//the ISR will be reached every 1ms
	{
		//setting pin to low
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_LOW);
	}
	else if (Local_u8Counter==20)
	{
		//setting pin to high
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN1,DIO_u8PIN_HIGH);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN2,DIO_u8PIN_HIGH);
		Local_u8Counter=0;
	}
}
