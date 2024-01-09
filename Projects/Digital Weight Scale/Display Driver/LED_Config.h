/**
  ******************************************************************************
  * @file    LED_Config.h
  * @author  Zeyad Mohamed - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    10-Aug-2023
  * @brief   This file contains all the pre-built configurations for LED.
   ******************************************************************************
  */

//-See LED_Prog.c for details
/*-----------------------------------------------------------------------------------------------------*/

// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

/**
  * @brief  Macros used to bit to segmet mapping.
  */
#define S7_A                    0x10
#define S7_B                    0x20
#define S7_C                    0x40
#define S7_D                    0x01
#define S7_E                    0x02
#define S7_F                    0x08
#define S7_G                    0x04
#define S7_DP                   0x80

/**
  * @brief  Macros used to display all segment.
  */
#define MASK_7S_ALL             (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F | S7_G | S7_DP)

/**
  * @brief  Macros used to display digits.
  */
#define C7_0                    (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F)
#define C7_1                    (S7_B | S7_C)
#define C7_2                    (S7_A | S7_B | S7_D | S7_E | S7_G)
#define C7_3                    (S7_A | S7_B | S7_C | S7_D | S7_G)
#define C7_4                    (S7_B | S7_C | S7_F | S7_G)
#define C7_5                    (S7_A | S7_C | S7_D | S7_F | S7_G)
#define C7_6                    (S7_A | S7_C | S7_D | S7_E | S7_F | S7_G)
#define C7_7                    (S7_A | S7_B | S7_C)
#define C7_8                    (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F | S7_G)
#define C7_9                    (S7_A | S7_B | S7_C | S7_D | S7_F | S7_G)

/**
  * @brief  Macros used to display Upper case alphabet.
  */
#define C7_A                    (S7_A | S7_B | S7_C | S7_E | S7_F | S7_G )
#define C7_B                    (S7_C | S7_D | S7_E | S7_F | S7_G)
#define C7_C                    (S7_A | S7_D | S7_E | S7_F)
#define C7_D                    (S7_B | S7_C | S7_D | S7_E | S7_G)
#define C7_E                    (S7_A | S7_D | S7_E | S7_F | S7_G)
#define C7_F                    (S7_A | S7_E | S7_F | S7_G)
#define C7_G                    (S7_A | S7_C | S7_D | S7_E | S7_F)
#define C7_H                    (S7_B | S7_C | S7_E | S7_F | S7_G)
#define C7_I                    (S7_B | S7_C)
#define C7_J                    (S7_B | S7_C | S7_D | S7_E)
#define C7_K                    (S7_B | S7_C | S7_E | S7_F | S7_G)
#define C7_L                    (S7_D | S7_E | S7_F)
#define C7_M                    (S7_A | S7_C | S7_E)
#define C7_N                    (S7_A | S7_B | S7_C | S7_E | S7_F)
#define C7_O                    (S7_A | S7_B | S7_C | S7_D | S7_E | S7_F)
#define C7_P                    (S7_A | S7_B | S7_E | S7_F | S7_G)
#define C7_Q                    (S7_A | S7_B | S7_C | S7_F | S7_G)
#define C7_R                    (S7_E | S7_G )
#define C7_S                    (S7_A | S7_C | S7_D | S7_F | S7_G)
#define C7_T                    (S7_D | S7_E | S7_F | S7_G)
#define C7_U                    (S7_B | S7_C | S7_D | S7_E | S7_F)
#define C7_V                    (S7_B | S7_C | S7_D | S7_E | S7_F)
#define C7_W                    (S7_B | S7_D | S7_F)
#define C7_X                    (S7_B | S7_C | S7_E | S7_F | S7_G)
#define C7_Y                    (S7_B | S7_C | S7_D | S7_F | S7_G)
#define C7_Z                    (S7_A | S7_B | S7_D | S7_E | S7_G)


/**
  * @brief  Macros used to use to put negative on the display
  */
#define C7_NEGATIVE             (S7_G)

/**
  * @brief  Macros used to use in the sleep mode.
  */
#define C7_Sleep                (S7_G)


/**
  * @brief  Macros used to use in the sleep mode.
  */
#define C7_calibration_o        (S7_C | S7_D | S7_E | S7_G)


/**
  * @brief  Macros used to define number of digits controlled by the driver.
  */
#define NUM_DIGIT               16

/**
  * @brief  Macros used to Mapping Grids.
  */
#define S7_ICON_GR1             15
#define S7_ICON_GR2             14
#define S7_ICON_GR3             13
#define S7_ICON_GR4             12
#define S7_ICON_GR5             11
#define S7_ICON_GR6             6
#define S7_ICON_GR7             7
#define S7_ICON_GR8             8
#define S7_ICON_GR9             9
#define S7_ICON_GR10            10
#define S7_ICON_GR11            0
#define S7_ICON_GR12            1
#define S7_ICON_GR13            2
#define S7_ICON_GR14            3
#define S7_ICON_GR15            4
#define S7_ICON_GR16            5

/**
  * @brief  Macros used define used SPI A module for the LED driver.
  */
#define LED_SPI_A               1

/**
  * @brief  Macros used define used SPI B module for the LED driver.
  */
#define LED_SPI_B               2

/**
  * @brief  Macro used to define the SPI module used. Available values: LED_SPI_A or LED_SPI_B
  */
#define LED_SPI_MODULE          LED_SPI_A

/**
  * @brief  Macros used to control the brightness of LEDs.
  */
#define LED_BRT0                0x00 //Pulsewidth 1/16
#define LED_BRT1                0x01
#define LED_BRT2                0x02
#define LED_BRT3                0x03
#define LED_BRT4                0x04
#define LED_BRT5                0x05
#define LED_BRT6                0x06
#define LED_BRT7                0x07 //Pulsewidth 14/16

/**
  * @brief  Macros used to switch LEDs off.
  */
#define LED_OFF                 (0x80)

/**
  * @brief  Macros used to display control commands.
  */
#define LED_ON                  (0x88)

/**
  * @brief  Macros used to turn off LEDs in a digit.
  */
#define DIGIT_OFF                  (0x00)

/**
  * @brief  Macros used to turn on LEDs in a digit.
  */
#define DIGIT_ON                  (0xFF)

/**
  * @brief  Macro used to define the starting address for the first digit.
  */
#define START_ADDRESS           (0xC0)

/**
  * @brief  Macro used to define the Data write fixed command (0x44).
  */
#define WRITE_FIXED             0b01000100

/**
  * @brief  Macro used to define the Data write increment command (0x40).
  */
#define WRITE_INC               0b01000000

/**
  * @brief  Macro used to define the Activate the Display (0x8f).
  */
#define ACTIVATE                LED_ON|LED_BRT7

/**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/
#endif /* LED_CONFIG_H_ */

/*History Log*/
/*****************************************************************************************************
          User          |                     brief                         |         Date
******************************************************************************************************
Zeyad Mohamed           |Initial release for MSP430I2041                    |10-Aug-2023
                        |                                                   |
                        |                                                   |
******************************************************************************************************/

/*---------------------------------------------------------------------------------------------------*-
------------------------------------- END OF FILE -----------------------------------------------------
-*---------------------------------------------------------------------------------------------------*/
