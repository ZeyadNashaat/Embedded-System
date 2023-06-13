#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void LED_voidTurnOn(LED_t* Copy_pu8struct)
{
	if ((Copy_pu8struct->CONNTYPE)==LED_u8CONNTYPE_SRC)
	{
		DIO_u8SetPinDirection((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_HIGH);
	}
	else if ((Copy_pu8struct->CONNTYPE)==LED_u8CONNTYPE_SNK)
	{
		DIO_u8SetPinDirection((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_LOW);
	}
}

void LED_voidTurnOff(LED_t* Copy_pu8struct)
{
	if ((Copy_pu8struct->CONNTYPE)==LED_u8CONNTYPE_SRC)
	{
		DIO_u8SetPinDirection((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_LOW);
	}
	else if ((Copy_pu8struct->CONNTYPE)==LED_u8CONNTYPE_SNK)
	{
		DIO_u8SetPinDirection((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_OUTPUT);
		DIO_u8SetPinValue((Copy_pu8struct->PORT),(Copy_pu8struct->PIN), DIO_u8PIN_HIGH);
	}
}
