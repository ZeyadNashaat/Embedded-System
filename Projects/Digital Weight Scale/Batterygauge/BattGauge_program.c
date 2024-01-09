/**
  ******************************************************************************
  * @file    BattGauge_program.c
  * @author  Mamdouh Ezz - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    28-Dec-2022
  * @brief   This file contains all the functions for the BattGauge.
   ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <msp430.h>

#include <driverlib/driverlib.h>

#include "BattGauge_interface.h"
#include "BattGauge_config.h"


/*a global variable to the maped Voltage value.*/
float Batt_Volt_Mapped;

/**
  * @brief  Initializes for battery gauge according to the specified parameter in the BattGauge_config.h.
  * @param  None
  * @retval BattGauge_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref BattGauge_ErrStateTypeDef.
  */

BattGauge_ErrStateTypeDef BattGauge_Init()
{
/*Error checking for input*/
    if (BATTGAUGE_CONVERTER>=SD24_CONVERTER_0 && BATTGAUGE_CONVERTER<=SD24_CONVERTER_3)
    {
        if (BATTGAUGE_ENPORT>=GPIO_PORT_P1 && BATTGAUGE_ENPORT<=GPIO_PORT_P2)
        {
            if (BATTGAUGE_ENPIN>=GPIO_PIN0 && BATTGAUGE_ENPIN<=GPIO_PIN7)
            {
                /*Initialization of ADC module:*/
                    /*initialization of clock used for ADC.*/
                    SD24_init(SD24_BASE, SD24_REF_INTERNAL);
                    /*Parameters used by the ADC: converter, conversion mode, �..*/
                    SD24_initConverterAdvancedParam param = {0};
                    param.converter = BATTGAUGE_CONVERTER; /*Select converter*/
                    param.conversionMode = SD24_CONTINUOUS_MODE; /*Select single mode*/
                    param.groupEnable = SD24_NOT_GROUPED; /*No grouped*/
                    param.inputChannel = SD24_INPUT_CH_ANALOG; /*Input from analog signal*/
                    param.dataFormat = SD24_DATA_FORMAT_2COMPLEMENT; /*2�s complement data format*/
                    param.interruptDelay = SD24_FOURTH_SAMPLE_INTERRUPT; /*4th sample causes interrupt*/
                    param.oversampleRatio = SD24_OVERSAMPLE_32; /*Oversampling ratio 32*/
                    param.gain = SD24_GAIN_1; /*Preamplifier gain x1*/
                    /*Initialization of ADC module.*/
                    SD24_initConverterAdvanced(SD24_BASE, &param);
                    /*Delay for the reference voltage to settle.*/
                    __delay_cycles(3200);

                /*Configuration of Enable pin:*/
                    /*Initialize the enable pin as output.*/
                    GPIO_setAsOutputPin(BATTGAUGE_ENPORT, BATTGAUGE_ENPIN);
                    /*Disable the battery gauge by setting the pin as low.*/
                    GPIO_setOutputLowOnPin(BATTGAUGE_ENPORT, BATTGAUGE_ENPIN);

                /*Return battery state of okay.*/
                    return BattGauge_OK;
            }
            else
            {
                return BattGauge_ERROR;
            }
        }
        else
        {
            return BattGauge_ERROR;
        }
    }
    else
    {
        return BattGauge_ERROR;
    }
}

/**
  * @brief  Read the data of the converted data by the ADC channel and save it in the address of the variable conversion_Value
    * and convert the value to volt and save it in the address of the Batt_Volt.
  * @param  None
  * @retval BattGauge_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref BattGauge_ErrStateTypeDef.
  */

BattGauge_ErrStateTypeDef BattGauge_Read(void)
{

    /*Initializing BattGauge_Counter for counting the time for ending the conversion*/
    unsigned short counter=0;
    /*a variable to hold the digital output from the ADC.*/
    unsigned short Conversion_Value;
    /*a variable to the Voltage value.*/
    unsigned short Batt_Volt;
    /*Enable battery gauge by setting enable pin to high*/
    GPIO_setOutputHighOnPin(BATTGAUGE_ENPORT, BATTGAUGE_ENPIN);
    /*Start ADC conversion*/
    SD24_startConverterConversion(SD24_BASE,BATTGAUGE_CONVERTER);
    /*Busy wait until the conversion is finished*/
    while( SD24_getInterruptStatus(SD24_BASE, BATTGAUGE_CONVERTER, SD24_CONVERTER_INTERRUPT) == 0 )
    {
        /* increment the counter*/
        counter++;
        /*if the conversion take more than 4 seconds will return error*/
        if (counter>65500)
        {
            return BattGauge_TIMEOUT;
        }
    }

    /*store the ADC conversion value in adress of the Conversion_Value*/
    Conversion_Value = SD24_getResults(SD24_BASE, BATTGAUGE_CONVERTER);
    /*Calculate the voltage input for the ADC  from the digital output of the ADC by multiplying the conversion value by ((1200mv/((2^15)-1)=0.0366) in address of the Batt_Volt*/
    Batt_Volt = Conversion_Value * 0.0366 ;

    /*Map between the voltage input for the ADC and the battery voltage*/
    BattGauge_Mapping(Batt_Volt);

    /*Disable the battery gauge by setting the enable pin as low.*/
    GPIO_setOutputLowOnPin(BATTGAUGE_ENPORT, BATTGAUGE_ENPIN);

    /*return battery state of okay*/
    return BattGauge_OK;
}

/**
  * @brief  Mapping the voltage input to the MCU through the ADC channel to the voltage from the Battery using straight line equation y=mx+c.
  * @param  None
  * @retval BattGauge_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref BattGauge_ErrStateTypeDef.
  */
BattGauge_ErrStateTypeDef BattGauge_Mapping(unsigned short Batt_Volt)
{
    /*to prevent 0 slop as the variables aren't float*/
    if ((BattGauge_MAXIMUM_VOLT_MAPPED-BattGauge_MINIMUM_VOLT_MAPPED)>(BattGauge_MAXIMUM_VOLT-BattGauge_MINIMUM_VOLT))
    {
        unsigned short x1= BattGauge_MINIMUM_VOLT;
        unsigned short y1= BattGauge_MINIMUM_VOLT_MAPPED;
        unsigned short x2= BattGauge_MAXIMUM_VOLT;
        unsigned short y2= BattGauge_MAXIMUM_VOLT_MAPPED;

        /* m= (y2-y1)/(x2-x1)*/
        float slope = (((float)y2-(float)y1)/((float)x2-(float)x1));
        /*y = mx + c*/
        Batt_Volt_Mapped = ((Batt_Volt-x1)*slope)+y1;
        /*change the Batt_Volt_Mapped from milivolt to volt */
        Batt_Volt_Mapped= Batt_Volt_Mapped/1000;

        return BattGauge_OK;
    }
    else{
        return BattGauge_ERROR;
    }
}

/**
  * @brief  Check if the Battery voltage is less than the threshold value.
  * @param  None
  * @retval BattGauge_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref BattGauge_ErrStateTypeDef.
  */
BattGauge_ErrStateTypeDef BattGauge_Check(void)

{
    if (Batt_Volt_Mapped<BATTGAUGE_THRESH)
    {
        /*return low battery*/
        return BattGauge_LOWBATT;
    }
    else
    {
        return BattGauge_OK;
    }
}

 /**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/
/*History Log*/
/*****************************************************************************************************
          User          |                     brief                         |         Date
******************************************************************************************************
Mamdouh Ezz             |Initial release STM                                |28-Dec-2022
Zeyad Mohamed           |Edit for MSP430I2041                               |23-Aug-2023
                        |                                                   |
******************************************************************************************************/
/*---------------------------------------------------------------------------------------------------*-
------------------------------------- END OF FILE -----------------------------------------------------
-*---------------------------------------------------------------------------------------------------*/
