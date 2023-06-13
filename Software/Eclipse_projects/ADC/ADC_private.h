#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_RefSelect_AREF     		  1
#define ADC_RefSelect_AVCC            2
#define ADC_RefSelect_Reserved        3
#define ADC_RefSelect_InternalVolt    4

#define ADC_BitResol_8bits			  1
#define ADC_BitResol_10bits           2

#define ADC_Prescaler_Mask            0b11111000
#define ADC_PrescalerSelect_DIV2      0
#define ADC_PrescalerSelect_DIV4      2
#define ADC_PrescalerSelect_DIV8      3
#define ADC_PrescalerSelect_DIV16     4
#define ADC_PrescalerSelect_DIV32     5
#define ADC_PrescalerSelect_DIV64     6
#define ADC_PrescalerSelect_DIV128    7

#define ADC_MUX_Mask                  0b11100000

#define Single_Conversion 			  1
#define Auto_Trigger                  2

#define ADC_AutoTrigger_Mask          0b00011111
#define Free_Running				  0
#define Analog_Comparator             1
#define EXTI_request0                 2
#define Timer_Counter0_Compare        3
#define Timer_Counter0_Overflow       4
#define Timer_Counter_CompareB        5
#define Timer_Counter1_Overflow       6
#define Timer_Counter1_CaptureEvent   7

#define IDLE						  0
#define BUSY						  1
#define CHAIN 						  2
#define SINGLE						  3

#endif
