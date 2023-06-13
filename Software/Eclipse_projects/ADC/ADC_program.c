#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"ADC_interface.h"
#include"ADC_private.h"
#include"ADC_register.h"
#include"ADC_config.h"

static u16* ADC_pu16Reading=NULL; //static because it wont be externed in any other files
static u16* ADC_pu16Voltage=NULL; //global pointer to hold address of passed input to asynch func
static void (*ADC_pvCallbackNotificationFunc) (void)=NULL; //global pointer to function
static u8 ADC_u8BusyState=IDLE;
static u8 ADC_u8AsynchType=CHAIN; //determine state of ADC Asynch when entering ISR
static u8 ADC_u8ChainIndex; //index of channel in array of chain
static u8 ADC_u8ChainSize;
static u8* ADC_u8ChannelArr=NULL;
static u16* ADC_u16ConversionArr=NULL;
static u16* ADC_u16VoltageArr=NULL;
static void (*ADC_pvChainNotificationFunc) (void)=NULL;

void ADC_voidInit(void)
{
	//selecting reference voltage
#if  (ADC_RefSelect==ADC_RefSelect_AREF)
	CLR_BIT(ADMUX,ADMUX_REFS1);
	CLR_BIT(ADMUX,ADMUX_REFS0);
#elif (ADC_RefSelect==ADC_RefSelect_AVCC)
	CLR_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#elif (ADC_RefSelect==ADC_RefSelect_Reserved)
	SET_BIT(ADMUX,ADMUX_REFS1);
	CLR_BIT(ADMUX,ADMUX_REFS0);
#elif (ADC_RefSelect== ADC_RefSelect_InternalVolt)
	SET_BIT(ADMUX,ADMUX_REFS1);
	SET_BIT(ADMUX,ADMUX_REFS0);
#else
#error "Wrong reference selection"
#endif

	//Prescaler selection
	ADCSRA&=ADC_Prescaler_Mask;
	ADCSRA|=ADC_PrescalerSelect;

	//Resolution of output selection (left/right adjust)
#if   (ADC_BitResol==ADC_BitResol_8bits)
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif (ADC_BitResol==ADC_BitResol_10bits)
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "Wrong resolution selection"
#endif

	//enable ADC
	SET_BIT(ADCSRA,ADCSRA_ADEN);
	//set conversion mode
#if (ADC_Conversion==Single_Conversion)
	//clear trigger enable and interrupt enable
	CLR_BIT(ADCSRA,ADCSRA_ADATE);
#elif (ADC_Conversion==Auto_Trigger)
	//Set trigger enable and interrupt enable
	SET_BIT(ADCSRA,ADCSRA_ADATE);
	SET_BIT(ADCSRA,ADCSRA_ADIE);
	//Bit masking SFIOR for getting mode of auto trigger
	SFIOR&=ADC_AutoTrigger_Mask;
	SFIOR|=ADC_AutoTriggerMode;
	//start first conversion
	SET_BIT(ADCSRA,ADCSRA_ADSC);
#endif
}

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16* Copy_pu16MilliVoltage,u16* Copy_pu16Reading)
{
	u8 Local_u8ErrorState=OK;
	if (ADC_u8BusyState==IDLE)
	{
		ADC_u8BusyState=BUSY;
		if ((Copy_pu16MilliVoltage==NULL)||(Copy_pu16Reading==NULL))
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			//Counter for timeout mechanism
			u32 Local_u32Counter=0;
			//clear MUX register
			ADMUX &=ADC_MUX_Mask;
			//set the required channel
			ADMUX|=Copy_u8Channel;
			//start conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			//polling (busy waiting) until flag of completion is set or counter finishes after passing timeout value
			while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0)&&(Local_u32Counter!=ADC_Timeout))
			{
				Local_u32Counter++;
			}
			if (Local_u32Counter==ADC_Timeout)
			{
				//loop is broken due to reaching timeout
				Local_u8ErrorState=NOK;
			}
			else
			{
				//loop is broken due to flag is raised
				//clear flag by setting it
				SET_BIT(ADCSRA,ADCSRA_ADIF);
#if   (ADC_BitResol==ADC_BitResol_8bits)
				*Copy_pu16MilliVoltage=((u32)ADCH*ADC_MaxVoltage)/256UL;
				*Copy_pu16Reading=ADCH;
#elif (ADC_BitResol==ADC_BitResol_10bits)
				*Copy_pu16MilliVoltage=((u32)ADC10Bit*ADC_MaxVoltage)/1024UL;
				*Copy_pu16Reading=ADC10Bit;
#endif
			}
		}
		ADC_u8BusyState=IDLE;
	}
	else
	{
		Local_u8ErrorState=Busy_Func;
	}

	return Local_u8ErrorState;
}

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16*Copy_pu16MilliVoltage,u16* Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void))
{
	u8 Local_u8ErrorState=OK;
	if (ADC_u8BusyState==IDLE)
	{
		//Make ADC busy to avoid calling it before it finishes its conversion dissrupting the whole function
		ADC_u8BusyState=BUSY;
		if ((Copy_pu16MilliVoltage==NULL)||(Copy_pu16Reading==NULL)||(Copy_pvNotificationFunc==NULL))
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			//Make ADC asynch state as single channel
			ADC_u8AsynchType=SINGLE;
			//Make reading,voltage and function value globally saved
			ADC_pu16Reading=Copy_pu16Reading;
			ADC_pu16Voltage=Copy_pu16MilliVoltage;
			ADC_pvCallbackNotificationFunc=Copy_pvNotificationFunc;
			//clear MUX register
			ADMUX&=ADC_MUX_Mask;
			//set the required channel
			ADMUX|=Copy_u8Channel;
			//start conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			//enable ADC interrupt conversion
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		Local_u8ErrorState=Busy_Func;
	}
	return Local_u8ErrorState;
}

u8 ADC_u8ChainConversionAsynch(ADC_Chain_t* Copy_ChainStruct)
{
	u8 Local_u8ErrorState=OK;
	if (ADC_u8BusyState==IDLE)
	{
		//Make ADC busy to avoid calling it before it finishes its conversion dissrupting the whole function
		ADC_u8BusyState=BUSY;
		if (Copy_ChainStruct==NULL)
		{
			Local_u8ErrorState=NULL_POINTER;
		}
		else
		{
			//make ADC Asynch type CHAIN type
			ADC_u8AsynchType=CHAIN;
			//save variables in struct into global variables
			ADC_u8ChainSize=Copy_ChainStruct->ChainSize;
			ADC_u8ChannelArr=Copy_ChainStruct->Channel_Arr;
			ADC_u16ConversionArr=Copy_ChainStruct->Conversion_Arr;
			ADC_u16VoltageArr=Copy_ChainStruct->Voltage_Arr;
			ADC_pvChainNotificationFunc=Copy_ChainStruct->NotificationFunc;
			//set chain index to zero indicating first channel conversion
			ADC_u8ChainIndex=0;
			//clear MUX register
			ADMUX&=ADC_MUX_Mask;
			//set the required channel
			ADMUX|=*(ADC_u8ChannelArr); //or ADC_u8ChannelArr[ADC_u8ChainIndex]
			//start conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			//enable ADC interrupt conversion
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
	}
	else
	{
		Local_u8ErrorState=Busy_Func;
	}
	return Local_u8ErrorState;
}

void __vector_16(void) __attribute__((signal)); //ISR of ADC
void __vector_16(void)
{
	if (ADC_u8AsynchType==SINGLE)
	{
		//Read ADC result and voltage
#if   (ADC_BitResol==ADC_BitResol_8bits)
		*ADC_pu16Voltage=((u32)ADCH*ADC_MaxVoltage)/256UL;
		*ADC_pu16Reading=ADCH;
#elif (ADC_BitResol==ADC_BitResol_10bits)
		*ADC_pu16Voltage=((u32)ADC10Bit*ADC_MaxVoltage)/1024UL;
		*ADC_pu16Reading=ADC10Bit;
#endif
		//Make ADC IDLE before calling notification to enable recalling Asynch func inside notification
		ADC_u8BusyState=IDLE;
		//invoke Call function notification
		ADC_pvCallbackNotificationFunc();
		//Disable ADC conversion complete interrupt
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8AsynchType==CHAIN)
	{
		//read the current conversion
#if   (ADC_BitResol==ADC_BitResol_8bits)
		*(ADC_u16VoltageArr+ADC_u8ChainIndex)=((u32)ADCH*ADC_MaxVoltage)/256UL;//ADC_u16VoltageArr[ADC_u8ChainIndex]
		*(ADC_u16ConversionArr+ADC_u8ChainIndex)=ADCH;
#elif (ADC_BitResol==ADC_BitResol_10bits)
		*(ADC_u16VoltageArr+ADC_u8ChainIndex)=((u32)ADC10Bit*ADC_MaxVoltage)/1024UL;
		*(ADC_u16ConversionArr+ADC_u8ChainIndex)=ADC10Bit;
#endif
		//index increment
		ADC_u8ChainIndex++;
		//check chain is finished or not
		if (ADC_u8ChainIndex==ADC_u8ChainSize)
		{
			//Make ADC busy state IDLE
			ADC_u8BusyState=IDLE;
			//invoke notification function
			ADC_pvChainNotificationFunc();
			//disable interrupt enable
			CLR_BIT(ADCSRA,ADCSRA_ADIE);
		}
		else
		{
			//clear MUX register
			ADMUX&=ADC_MUX_Mask;
			//set the required channel
			ADMUX|=*(ADC_u8ChannelArr+ADC_u8ChainIndex);
			//start next conversion
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}
	}

}

s32 Mapping_Value(s32 Copy_s32InputMax,s32 Copy_s32InputMin,s32 Copy_s32OutputMax,s32 Copy_s32OutputMin,s32 Copy_s32InputVal)
{
	s32 Copy_s32OutputVal=(((Copy_s32OutputMax-Copy_s32OutputMin)*(Copy_s32InputVal-Copy_s32InputMin))/(Copy_s32InputMax-Copy_s32InputMin))+Copy_s32OutputMin;
	return Copy_s32OutputVal;
}
