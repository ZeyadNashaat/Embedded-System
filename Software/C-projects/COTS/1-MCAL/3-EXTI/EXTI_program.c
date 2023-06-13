#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"
#include "EXTI_register.h"

/*global pointer to function to hold INT0/INT1/INT2 ISR address from local variable of call back function */
void (*EXTI_pvInt0Func)(void)=NULL;

void (*EXTI_pvInt1Func)(void)=NULL;

void (*EXTI_pvInt2Func)(void)=NULL;

void EXTI_voidInt0Init(u8 Copy_u8SenseControl)
{
	/*set sense control for INT0*/
	switch (Copy_u8SenseControl)
	{
	case (Sense_LowLevel): /*for low level :ISC01=0,ISC00=0*/
				CLR_BIT(MCUCR,MCUCR_ISC01);
				CLR_BIT(MCUCR,MCUCR_ISC00);
	break;
	case (Sense_OnChange): /*for on change :ISC01=0,ISC00=1*/
				CLR_BIT(MCUCR,MCUCR_ISC01);
				SET_BIT(MCUCR,MCUCR_ISC00);
	break;
	case (Sense_FallingEdge): /*for falling edge :ISC01=1,ISC00=0*/
				SET_BIT(MCUCR,MCUCR_ISC01);
				CLR_BIT(MCUCR,MCUCR_ISC00);
	break;
	case (Sense_RisingEdge): /*for rising edge :ISC01=1,ISC00=1*/
				SET_BIT(MCUCR,MCUCR_ISC01);
				SET_BIT(MCUCR,MCUCR_ISC00);
	break;
	}
	/*peripheral (specific) interrupt enable*/
	SET_BIT(GICR,GICR_INT0);
}

void EXTI_voidInt1Init(u8 Copy_u8SenseControl)
{
	/*set sense control for INT1*/
	switch (Copy_u8SenseControl)
	{
	case (Sense_LowLevel): /*for low level :ISC11=0,ISC10=0*/
				CLR_BIT(MCUCR,MCUCR_ISC11);
				CLR_BIT(MCUCR,MCUCR_ISC10);
	break;
	case (Sense_OnChange): /*for on change :ISC11=0,ISC10=1*/
				CLR_BIT(MCUCR,MCUCR_ISC11);
				SET_BIT(MCUCR,MCUCR_ISC10);
	break;
	case (Sense_FallingEdge): /*for falling edge :ISC11=1,ISC10=0*/
				SET_BIT(MCUCR,MCUCR_ISC11);
				CLR_BIT(MCUCR,MCUCR_ISC10);
	break;
	case (Sense_RisingEdge): /*for rising edge :ISC11=1,ISC10=1*/
				SET_BIT(MCUCR,MCUCR_ISC11);
				SET_BIT(MCUCR,MCUCR_ISC10);
	break;
	}
	/*peripheral (specific) interrupt enable*/
	SET_BIT(GICR,GICR_INT1);
}

void EXTI_voidInt2Init(u8 Copy_u8SenseControl)
{
	/*set sense control for INT2*/
	switch(Copy_u8SenseControl)
	{
	case (Sense_FallingEdge):
				CLR_BIT(MCUCSR,MCUCSR_ISC2);
	break;
	case (Sense_RisingEdge):
				SET_BIT(MCUCSR,MCUCSR_ISC2);
	break;
	}
	/*peripheral (specific) interrupt enable*/
	SET_BIT(GICR,GICR_INT2);
}

/*This function enables the user to send the address of INT0 ISR to be stored in global variable*/
u8 EXTI_u8Int0SetCallBack(void (*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvInt0Func!=NULL)
	{
		EXTI_pvInt0Func=Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}
/*Setting ISR of INT0*/
void __vector_1 (void) __attribute__((signal));
void __vector_1 (void)
{
	if (EXTI_pvInt0Func!=NULL)
	{
	EXTI_pvInt0Func();
	}
	else
	{
		/*do nothing if user did not send ISR to INT0*/
	}
}

/*This function enables the user to send the address of INT1 ISR to be stored in global variable*/
u8 EXTI_u8Int1SetCallBack(void (*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvInt1Func!=NULL)
	{
		EXTI_pvInt1Func=Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}
/*Setting ISR of INT1*/
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if (EXTI_pvInt1Func!=NULL)
	{
	EXTI_pvInt1Func();
	}
	else
	{
		/*do nothing if user did not send ISR to INT1*/
	}
}

/*This function enables the user to send the address of INT2 ISR to be stored in global variable*/
u8 EXTI_u8Int2SetCallBack(void (*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorStatus=OK;
	if (Copy_pvInt2Func!=NULL)
	{
		EXTI_pvInt2Func=Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorStatus=NULL_POINTER;
	}
	return Local_u8ErrorStatus;
}
/*Setting ISR of INT2*/
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if (EXTI_pvInt2Func!=NULL)
	{
	EXTI_pvInt2Func();
	}
	else
	{
		/*do nothing if user did not send ISR to INT2*/
	}
}

