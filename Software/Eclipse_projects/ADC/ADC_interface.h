#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
/*Options for ADC channel:
  Note: Sin: single ended-->ADC_Channel_Sin_Channel
      Dif: differential-->ADC_Channel_Dif_+ve channel_-ve channel_gain
*/
#define ADC_Channel_Sin_A0            0
#define ADC_Channel_Sin_A1            1
#define ADC_Channel_Sin_A2            2
#define ADC_Channel_Sin_A3            3
#define ADC_Channel_Sin_A4            4
#define ADC_Channel_Sin_A5            5
#define ADC_Channel_Sin_A6            6
#define ADC_Channel_Sin_A7            7
#define ADC_Channel_Dif_A0_A0_10      8
#define ADC_Channel_Dif_A1_A0_10      9
#define ADC_Channel_Dif_A0_A0_200     10
#define ADC_Channel_Dif_A1_A0_200     11
#define ADC_Channel_Dif_A2_A2_10      12
#define ADC_Channel_Dif_A3_A2_10      13
#define ADC_Channel_Dif_A2_A2_200     14
#define ADC_Channel_Dif_A3_A2_200     15
#define ADC_Channel_Dif_A0_A1_1       16
#define ADC_Channel_Dif_A1_A1_1       17
#define ADC_Channel_Dif_A2_A1_1       18
#define ADC_Channel_Dif_A3_A1_1       19
#define ADC_Channel_Dif_A4_A1_1       20
#define ADC_Channel_Dif_A5_A1_1       21
#define ADC_Channel_Dif_A6_A1_1       22
#define ADC_Channel_Dif_A7_A1_1       23
#define ADC_Channel_Dif_A0_A2_1       24
#define ADC_Channel_Dif_A1_A2_1       25
#define ADC_Channel_Dif_A2_A2_1       26
#define ADC_Channel_Dif_A3_A2_1       27
#define ADC_Channel_Dif_A4_A2_1       28
#define ADC_Channel_Dif_A5_A2_1       29
#define ADC_Channel_Sin_Vbg           30
#define ADC_Channel_Sin_GND           31

void ADC_voidInit(void);

u8 ADC_u8StartConversionSynch(u8 Copy_u8Channel,u16*Copy_pu16MilliVoltage,u16* Copy_pu16Reading);

/*this function is used to set channel and pass the notification function,
 reading, and voltages to ISR of ADC interrupt
 *Note: You must open global interrupt enable before using this function properly*/

u8 ADC_u8StartConversionAsynch(u8 Copy_u8Channel,u16*Copy_pu16MilliVoltage,u16* Copy_pu16Reading, void(*Copy_pvNotificationFunc)(void));

typedef struct
{
	u8 ChainSize:4;
	u8* Channel_Arr;
	void (*NotificationFunc)(void);
	u16* Conversion_Arr;
	u16* Voltage_Arr;
}ADC_Chain_t;

/*Note: You must open global interrupt enable before using this function properly*/

u8 ADC_u8ChainConversionAsynch(ADC_Chain_t* Copy_ChainStruct);

s32 Mapping_Value(s32 Copy_s32InputMax,s32 Copy_s32InputMin,s32 Copy_s32OutputMax,s32 Copy_s32OutputMin,s32 Copy_s32InputVal);

#endif
