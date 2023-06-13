#include"STD_TYPES.h"

#include"DIO_interface.h"
#include"EXTI_interface.h"
#include"GIE_interface.h"
/*lighting a LED using interrupt*/

void INT2_ISR(void);

void main(void)
{
	/*pull-up activation for INT0 (PIND2) for push button*/
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_INPUT);
	DIO_u8SetPinValue(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PIN_HIGH);
	/*output for LED on A0*/
	DIO_u8SetPinDirection(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_OUTPUT);
	/*interrupt on INT0 initialization*/
	EXTI_voidInt2Init(Sense_FallingEdge);
	/*Sending ISR of INT0*/
	EXTI_u8Int2SetCallBack(&INT2_ISR);
	/*enable global interrupt*/
	GIE_voidState(GIE_Enable);
	while(1)
	{

	}
}

void INT2_ISR(void)
{
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
}
