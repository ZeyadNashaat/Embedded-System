#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

//Timer0_Modes:
#define TIMER0_ModeNormal								1
#define TIMER0_ModePWM									2
#define TIMER0_ModeCTC      							3
#define TIMER0_ModeFastPWM  							4

//Timer0_prescaler:
#define Timer_Prescaler_Mask							0b11111000
#define TIMER0_Prescaler_NoClock						0
#define TIMER0_Prescaler_DIV1							1
#define TIMER0_Prescaler_DIV8							2
#define TIMER0_Prescaler_DIV64							3
#define TIMER0_Prescaler_DIV256							4
#define TIMER0_Prescaler_DIV1024						5
#define TIMER0_Prescaler_EXTCLk_Falling					6
#define TIMER0_Prescaler_EXTCLk_Rising					7

//Timer0_CTC_PinModes
#define TIMER0_CTC_PinMode_Disconn						1
#define TIMER0_CTC_PinMode_Toggle						2
#define TIMER0_CTC_PinMode_Set							3
#define TIMER0_CTC_PinMode_Clr							4

//Timer0_FPWM_PinModes
#define TIMER0_FPWM_PinMode_Disconn						1
#define TIMER0_FPWM_PinMode_ClrCompareMatch_SetTop		2
#define TIMER0_FPWM_PinMode_ClrTop_SetCompareMatch		3

//Timer0_Resolution
#define TIMER0_Resolution								8
#define TIMER0_OverFlowTicks							256

#endif
