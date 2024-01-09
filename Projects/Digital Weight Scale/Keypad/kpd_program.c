/**
  ******************************************************************************
  * @file    KPD_program.c
  * @author  Mamdouh Ezz - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    22-Dec-2022
  * @brief   This file contains all the functions for the keypad.
   ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <msp430.h>

#include <driverlib/driverlib.h>

#include "kpd_interface.h"

/*Global variable to save the pressed key in it*/
unsigned short PressedKey;
/*old state to initialize the old state*/
unsigned short OldState = OLD_STAT_VAL ;

/**
  * @brief  Initializes the Keypad ports and pins according to the specified parameter in the kpd_config.h.
  * @param
  * @retval KPD_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref KPD_ErrStateTypeDef.
  */

KPD_ErrStateTypeDef KPD_Init()
{
    /*Check that the column and row number is less than one */
    if (COLUMN_NUM<1 & ROW_NUM<1)
    {
        /*return error*/
        return KPD_ERROR;
    }
    /*check entry of column port*/
    else if (KPD_COLUMN_PORT<GPIO_PORT_P1 && KPD_COLUMN_PORT>GPIO_PORT_P2)
    {
        return KPD_ERROR;
    }
    /*check entry of row port*/
    else if (KPD_ROW_PORT<GPIO_PORT_P1 && KPD_ROW_PORT>GPIO_PORT_P2)
    {
        return KPD_ERROR;
    }
    else
    {
        /*set the Column pins to be Output */
        GPIO_setAsOutputPin(KPD_COLUMN_PORT, KPD_COLUMN0_PIN);
        GPIO_setAsOutputPin(KPD_COLUMN_PORT, KPD_COLUMN1_PIN);
        GPIO_setAsOutputPin(KPD_COLUMN_PORT, KPD_COLUMN2_PIN);
        GPIO_setAsOutputPin(KPD_COLUMN_PORT, KPD_COLUMN3_PIN);
        /*set the column pins as output high*/
        GPIO_setOutputHighOnPin(KPD_COLUMN_PORT, KPD_COLUMN0_PIN);
        GPIO_setOutputHighOnPin(KPD_COLUMN_PORT, KPD_COLUMN1_PIN);
        GPIO_setOutputHighOnPin(KPD_COLUMN_PORT, KPD_COLUMN2_PIN);
        GPIO_setOutputHighOnPin(KPD_COLUMN_PORT, KPD_COLUMN3_PIN);
        /*set the Row pin to be Input */
        /*Input is externally pulled up*/
        GPIO_setAsInputPin(KPD_ROW_PORT, KPD_ROW0_PIN);
        GPIO_setAsInputPin(KPD_ROW_PORT, KPD_ROW1_PIN);
        GPIO_setAsInputPin(KPD_ROW_PORT, KPD_ROW2_PIN);
        GPIO_setAsInputPin(KPD_ROW_PORT, KPD_ROW3_PIN);
        GPIO_setAsInputPin(KPD_ROW_PORT, KPD_ROW4_PIN);
        GPIO_setAsInputPin(KPD_ROW_PORT, KPD_ROW5_PIN);
        return KPD_OK;
    }
}

/**
  * @brief  Read the data of the pressed key.
  * @param
  * @retval KPD_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref KPD_ErrStateTypeDef.
  */
KPD_ErrStateTypeDef KPD_GetPressedKey(void)
{
    /* 2D Array for the Keypad*/
    unsigned short kpdArr[ROW_NUM][COLUMN_NUM] = KPD_ARR_VAL;
    /* Array for the column values*/
    unsigned short kpdColumnArr [COLUMN_NUM]={KPD_COLUMN0_PIN,KPD_COLUMN1_PIN,KPD_COLUMN2_PIN,KPD_COLUMN3_PIN};
    /* Array for the row values*/
    unsigned short kpdRowArr [ROW_NUM]={KPD_ROW0_PIN,KPD_ROW1_PIN,KPD_ROW2_PIN,KPD_ROW3_PIN,KPD_ROW4_PIN,KPD_ROW5_PIN};
    /*Initializing the state of the pin 1: not Pressed 0: Pressed*/
    unsigned char pinState=KEY_NPRESSED;
    /*column number in the loop*/
    unsigned char columnId;
    /*row number in the loop*/
    unsigned char rowId;

    /*Loop on the columns*/
    for (columnId=0; columnId<COLUMN_NUM; columnId++)
    {
        /*set the current column to low*/
        GPIO_setOutputLowOnPin(KPD_COLUMN_PORT,kpdColumnArr[columnId]);

        /*loop on the current row*/
        for (rowId=0; rowId<ROW_NUM; rowId++)
        {
            /*Read the input from the current row and update it to the pin state*/
            pinState= GPIO_getInputPinValue(KPD_ROW_PORT, kpdRowArr[rowId]);

            /*check if the key is pressed*/
            if (pinState == KEY_PRESSED)
            {
                /*check if old state is equal to the current state*/
                if (OldState == kpdArr[rowId][columnId])
                {
                    /*the pressed key value is hold*/
                    PressedKey= KPD_KEYHOLD;
                    /*set the current column to high*/
                    GPIO_setOutputHighOnPin(KPD_COLUMN_PORT,kpdColumnArr[columnId]);
                    /*return error state of key hold*/
                    return KPD_KEYHOLD;
                }
                /*if old state is not the same as the current state*/
                else
                {
                    /*update the pressed key value*/
                    PressedKey= kpdArr[rowId][columnId];
                    /*update the old state with the current state*/
                    OldState= PressedKey;
                    /*set the current column to high*/
                    GPIO_setOutputHighOnPin(KPD_COLUMN_PORT,kpdColumnArr[columnId]);
                    /*return error state of okay*/
                    return KPD_OK;
                }
            }
        }
        /*set high to the current column if no key is pressed*/
        GPIO_setOutputHighOnPin(KPD_COLUMN_PORT,kpdColumnArr[columnId]);
    }
    /*update old state and key pressed values to no key pressed*/
    PressedKey= OldState= KPD_NOKEYPRESSED;
    /*return error state of no key pressed*/
    return KPD_NOKEYPRESSED;
}

/**
 * @}
 */
/*------------------------------------------------------------------------------------------------*/

/*History Log*/
/*****************************************************************************************************
          User          |                     brief                         |         Date
******************************************************************************************************
Mamdouh Ezz             |Initial release for STM                            |22-Dec-2022
Zeyad Mohamed           |Edit for MSP430I2041                               |15-Aug-2023
                        |                                                   |
******************************************************************************************************/
/*---------------------------------------------------------------------------------------------------*-
------------------------------------- END OF FILE -----------------------------------------------------
-*---------------------------------------------------------------------------------------------------*/
