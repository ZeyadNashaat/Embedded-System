#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/*Options: 1- ADC_RefSelect_AREF
           2- ADC_RefSelect_AVCC
           3- ADC_RefSelect_Reserved
           4- ADC_RefSelect_InternalVolt  (2.56V)*/

#define ADC_RefSelect ADC_RefSelect_AVCC

/*Options: 1- ADC_RefSelect_AREF---> put the given voltage in milli to this pin+UL
           2- ADC_RefSelect_AVCC---> 5000UL
           3- ADC_RefSelect_Reserved
           4- ADC_RefSelect_InternalVolt--> 2560UL*/
#define ADC_MaxVoltage 5000UL

/*Options: 1- ADC_BitResol_8bits
           2- ADC_BitResol_10bits*/
#define ADC_BitResol ADC_BitResol_8bits

/*Options: 1- ADC_PrescalerSelect_DIV2
           2- ADC_PrescalerSelect_DIV4
           3- ADC_PrescalerSelect_DIV8
           4- ADC_PrescalerSelect_DIV16
           5- ADC_PrescalerSelect_DIV32
           6- ADC_PrescalerSelect_DIV64
           7- ADC_PrescalerSelect_DIV128*/

#define ADC_PrescalerSelect ADC_PrescalerSelect_DIV128

/*Options:
           1- Single_Conversion
           2- Auto_Trigger
           */

#define ADC_Conversion       Single_Conversion

/*Notes: only works in Auto_Trigger ADC_Conversion mode
 Options:
           1- Free_Running
           2- Analog_Comparator
           3- EXTI_request0
           4- Timer_Counter0_Compare
           5- Timer_Counter0_Overflow
           6- Timer_Counter_CompareB
           7- Timer_Counter1_Overflow
           8- Timer_Counter1_CaptureEvent
           */

#define ADC_AutoTriggerMode  Free_Running

/*Timeout for ending time of ADC conversion
 Choose big time to avoid ending time smaller than conversion time*/

#define ADC_Timeout 1000000

#endif
