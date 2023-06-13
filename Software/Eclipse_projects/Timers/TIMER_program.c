#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"Timer_private.h"
#include"TIMER_interface.h"
#include"TIMER_config.h"
#include"TIMER_register.h"

static void (*TIMER0_pvCallBackFunc)(void)=NULL;

void TIMER0_voidInit(void)
{

#if   (TIMER0_Mode==TIMER0_ModeNormal)
	//mode selection
	CLR_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
	//enabling interrupt enable
	SET_BIT(TIMSK,TIMSK_TOIE0);
	//setting value of preload
	TCNT0=TIMER0_OverFlow_Value;
#elif (TIMER0_Mode==TIMER0_ModePWM)
	//mode selection
	SET_BIT(TCCR0,TCCR0_WGM00);
	CLR_BIT(TCCR0,TCCR0_WGM01);
#elif (TIMER0_Mode==TIMER0_ModeCTC)
	//mode selection
	CLR_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	//enabling interrupt
	SET_BIT(TIMSK,TIMSK_OCIE0);
	//setting compare match value
	OCR0=TIMER0_CTC_Value;
	//pin mode selection
#if   (TIMER0_CTC_PinMode==TIMER0_CTC_PinMode_Disconn)
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#elif (TIMER0_CTC_PinMode==TIMER0_CTC_PinMode_Toggle)
	SET_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#elif (TIMER0_CTC_PinMode==TIMER0_CTC_PinMode_Clr)
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#elif (TIMER0_CTC_PinMode==TIMER0_CTC_PinMode_Set)
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#else
#error "Wrong CTC pin mode choice"
#endif
#elif (TIMER0_Mode==TIMER0_ModeFastPWM)
	//mode selection
	SET_BIT(TCCR0,TCCR0_WGM00);
	SET_BIT(TCCR0,TCCR0_WGM01);
	//pin mode selection
#if   (TIMER0_FPWM_PinMode==TIMER0_FPWM_PinMode_Disconn)
	CLR_BIT(TCCR0,TCCR0_COM00);
	CLR_BIT(TCCR0,TCCR0_COM01);
#elif (TIMER0_FPWM_PinMode==TIMER0_FPWM_PinMode_ClrCompareMatch_SetTop)
	CLR_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#elif (TIMER0_FPWM_PinMode==TIMER0_FPWM_PinMode_ClrTop_SetCompareMatch)
	SET_BIT(TCCR0,TCCR0_COM00);
	SET_BIT(TCCR0,TCCR0_COM01);
#endif
#else
#error"Wrong mode selection"
#endif
	//Timer prescaler selection
	TCCR0 &=Timer_Prescaler_Mask;
	TCCR0 |=TIMER0_Prescaler;
}

u8 TIMER0_u8SetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if (Copy_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc=Copy_pvCallBackFunc;
	}
	else
	{
		Local_u8ErrorState=NULL_POINTER;
	}
	return Local_u8ErrorState;
}
u8 TIMER0_u8FastPWM(u8 Copy_u8DutyCycle,u32 Copy_u8PeriodTimeMilli)
{
	u8 Local_u8ErrorState=OK;
	u8 Local_u8TicktimeMicro=TIMER0_Prescaler/TIMER0_FREQ_MEGA;
	u8 Local_u8OverFlowTicks=((u32)Copy_u8PeriodTimeMilli*1000)/Local_u8TicktimeMicro;
}
void __vector_10 (void) __attribute__((signal)); //ISR of TIMER0 CTC mode
void __vector_10 (void)
{
	if (TIMER0_pvCallBackFunc!=NULL)
	{
		TIMER0_pvCallBackFunc();
	}
}
