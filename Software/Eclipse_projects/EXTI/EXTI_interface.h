#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/*Sense control cases*/
#define Sense_LowLevel    0
#define Sense_OnChange    1
#define Sense_FallingEdge 2
#define Sense_RisingEdge  3


void EXTI_voidInt0Init(u8 Copy_u8SenseControl);

void EXTI_voidInt1Init(u8 Copy_u8SenseControl);

void EXTI_voidInt2Init(u8 Copy_u8SenseControl);

u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void)); /*input is pointer to function with void
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	return and void argument*/
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void));

u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void));

#endif
