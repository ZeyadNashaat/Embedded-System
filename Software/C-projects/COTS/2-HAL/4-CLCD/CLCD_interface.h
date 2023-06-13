#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

u8 CLCD_u8SendCommand(u8 Copy_u8Command);

u8 CLCD_u8SendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

#endif