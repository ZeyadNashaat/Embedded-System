/**
  ******************************************************************************
  * @file    KPD_config.h
  * @author  Mamdouh Ezz - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    28-Dec-2022
  * @brief   This file contains all the prebuilt configurations for KPD.
   ******************************************************************************
  */

//-See KPD_Program.c for details
/*-----------------------------------------------------------------------------------------------------*/

// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

/**
  * @brief  Macro used to define the column number.
  */
#define COLUMN_NUM      4

/**
  * @brief  Macro used to define the row number.
  */
#define ROW_NUM             6

/**
  * @brief  Macro used to define the port used by the column.
  */
#define KPD_COLUMN_PORT         GPIO_PORT_P1

/**
  * @brief  Macro used to define the port used by the row.
  */
#define KPD_ROW_PORT            GPIO_PORT_P2

/**
  * @brief  Macro used to define the pins used by the column.
  */
#define KPD_COLUMN0_PIN         GPIO_PIN4
#define KPD_COLUMN1_PIN         GPIO_PIN5
#define KPD_COLUMN2_PIN         GPIO_PIN6
#define KPD_COLUMN3_PIN         GPIO_PIN7

/**
  * @brief  Macro used to define the pins used by the row.
  */
#define KPD_ROW0_PIN                GPIO_PIN0
#define KPD_ROW1_PIN                GPIO_PIN1
#define KPD_ROW2_PIN                GPIO_PIN2
#define KPD_ROW3_PIN                GPIO_PIN3
#define KPD_ROW4_PIN                GPIO_PIN4
#define KPD_ROW5_PIN                GPIO_PIN5

/**
  * @brief  Macro used to define the values of the buttons saved in array.
  */
#define KPD_ARR_VAL                 {{7,8,9,11},{4,5,6,12},{1,2,3,13},{0,10,14,15},{16,17,18,19},{20,21,22,23}}

/**
  * @brief  Macros used to hold the start value of old state of key pressed.
  */
#define OLD_STAT_VAL    200

/**
  * @brief  Macros used to hold the value when a key is not pressed.
  */
#define KEY_NPRESSED  1

/**
  * @brief  Macros used to hold the value when a key is pressed.
  */
#define KEY_PRESSED     0

/**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/
#endif /*KPD_CONFIG_h_*/

/*History Log*/
/*****************************************************************************************************
          User          |                     brief                         |         Date
******************************************************************************************************
Mamdouh Ezz             |Initial release for STM                            |28-Dec-2022
Zeyad Mohamed           |Edit for MSP430I2041                               |15-Aug-2023
                        |                                                   |
******************************************************************************************************/
/*---------------------------------------------------------------------------------------------------*-
------------------------------------- END OF FILE -----------------------------------------------------
-*---------------------------------------------------------------------------------------------------*/
