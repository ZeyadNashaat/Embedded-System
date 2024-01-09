/*
 * main.c
 *
 *  Created on: Aug 21, 2023
 *      Author: Zeyad Mohamed
 */
#include <msp430.h>
#include <driverlib/driverlib.h>
#include "BattGauge_interface.h"
//unsigned long voltage;
//unsigned long results;
void main(void)
{
    WDT_hold(WDT_BASE);
    BattGauge_Init();
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN4);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN4);
//    SD24_init(SD24_BASE, SD24_REF_INTERNAL); // Select internal REF
//    SD24_initConverterAdvancedParam param = {0};
//    param.converter = SD24_CONVERTER_0; // Select converter
//    param.conversionMode = SD24_CONTINUOUS_MODE; // Select single mode
//    param.groupEnable = SD24_NOT_GROUPED; // No grouped
//    param.inputChannel = SD24_INPUT_CH_ANALOG; // Input from analog signal
//    param.dataFormat = SD24_DATA_FORMAT_2COMPLEMENT; // 2’s complement data format
//    param.interruptDelay = SD24_FOURTH_SAMPLE_INTERRUPT; // 4th sample causes interrupt
//    param.oversampleRatio = SD24_OVERSAMPLE_32; // Oversampling ratio 32
//    param.gain = SD24_GAIN_1; // Preamplifier gain x1
//    SD24_initConverterAdvanced(SD24_BASE, &param);
//    __delay_cycles(3200);
    while (1)
    {
        BattGauge_Read();
        unsigned int state=BattGauge_Check();
        if (state==BattGauge_LOWBATT)
        {
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN4);
        }
        else
        {
            GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN4);
        }
//        SD24_startConverterConversion(SD24_BASE,SD24_CONVERTER_0); // Set bit to start conversion
//        // Poll interrupt flag for channel 2
//        while( SD24_getInterruptStatus(SD24_BASE, SD24_CONVERTER_0, SD24_CONVERTER_INTERRUPT) == 0 );
//        results = SD24_getResults(SD24_BASE, SD24_CONVERTER_0); // Save CH2 results (clears IFG)
//        voltage=results*0.0366;
    }

}
