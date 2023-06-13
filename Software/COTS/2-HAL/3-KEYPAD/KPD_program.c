#include "STD_TYPES.h"

#include"DIO_interface.h"
#include"KPD_config.h"
#include"KPD_interface.h"
#include"KPD_private.h"

u8 KPD_u8GetPressedKey(void)
{
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY, Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState;
	static u8 Local_u8KPDArr[ROW_NUM][COLUMN_NUM]=KPD_ARR_VAL;
	static u8 Local_u8ColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8RowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for (Local_u8RowIdx=0;Local_u8RowIdx<ROW_NUM;Local_u8RowIdx++)
	{
		/*Activate current row by setting it to low value*/
		DIO_u8SetPinValue(KPD_ROW_PORT, Local_u8RowArr[Local_u8RowIdx],DIO_u8PIN_LOW);

		for(Local_u8ColumnIdx=0;Local_u8ColumnIdx<COLUMN_NUM;Local_u8ColumnIdx++)
		{
			/*read the value of the current column to know if its pressed or not*/
			DIO_u8GetPinValue(KPD_COLUMN_PORT, Local_u8ColumnArr[Local_u8ColumnIdx],&Local_u8PinState);
			/*Checking if key is pressed (low state) or not (high state)[Pull up connection]*/
			if (DIO_u8PIN_LOW==Local_u8PinState)
			{
				/*Getting the value of the key from the array*/
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
				/*Polling (busy waiting) until the user moves his hand of the key*/
				while(DIO_u8PIN_LOW==Local_u8PinState)
				{
					Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];
				}
				/*returning the value of the key if the key was pressed directly without entering another loop*/
				return Local_u8PressedKey;
			}
		}
		/*Deactivate current row by setting it to high value*/
		DIO_u8SetPinValue(KPD_ROW_PORT, Local_u8RowArr[Local_u8RowIdx],DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
