#include"STD_TYPES.h"
#include<util/delay.h>

#include"DIO_interface.h"
#include"CLCD_interface.h"
#include"CLCD_config.h"
#include"CLCD_private.h"

void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	/*Setting RS pin to low (command mode)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	/*Setting RW Pin to low (write mode)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*put command on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);
	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	/*Setting RS pin to high (data mode)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	/*Setting RW Pin to low (write mode)*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	/*put data on data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);
	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
}

void CLCD_voidInit(void)
{

}
