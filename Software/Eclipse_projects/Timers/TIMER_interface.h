#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

void TIMER0_voidInit(void);

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void));

u8 TIMER0_u8FastPWM(u8 Copy_u8DutyCycle,u32 Copy_u8PeriodTimeMilli);

#endif
