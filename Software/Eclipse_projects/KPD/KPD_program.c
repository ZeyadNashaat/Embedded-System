
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "KPD_config.h"
#include "KPD_private.h"
#include "KPD_inteface.h"

u8 KPD_u8GetPressedKey(void){
	u8 Local_u8PressedKey=KPD_NO_PRESSED_KEY;
	u8 Local_u8ColumnIdx, Local_u8RowIdx, Local_u8PinState;
	static u8 Local_u8KPDArr[4][4]=KPD_ARR_VAL;
	static u8 Local_u8KPDColumnArr[COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
	static u8 Local_u8KPDRowArr[ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN};

	for(Local_u8ColumnIdx=0; Local_u8ColumnIdx<COLUMN_NUM; Local_u8ColumnIdx++){
		/* Activate Current Column */
		DIO_u8SetPinValue(KPD_COLUMN_PORT, Local_u8KPDColumnArr[Local_u8ColumnIdx], DIO_u8PIN_LOW);

		for(Local_u8RowIdx=0; Local_u8RowIdx<ROW_NUM; Local_u8RowIdx++){
			/* Read Current Row */
			DIO_u8GetPinValue(KPD_ROW_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);

			/*Check if Switch is Pressed*/
			if(DIO_u8PIN_LOW==Local_u8PinState){
				Local_u8PressedKey=Local_u8KPDArr[Local_u8RowIdx][Local_u8ColumnIdx];

				/* Polling(busy waiting) until key is released */
				while(DIO_u8PIN_LOW==Local_u8PinState){
					DIO_u8GetPinValue(KPD_ROW_PORT, Local_u8KPDRowArr[Local_u8RowIdx], &Local_u8PinState);
				}

				return Local_u8PressedKey;
			}
		}
		/* Deactivate Current Column */
		DIO_u8SetPinValue(KPD_COLUMN_PORT, Local_u8KPDColumnArr[Local_u8ColumnIdx], DIO_u8PIN_HIGH);
	}

	return Local_u8PressedKey;
}
