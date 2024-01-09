/**
  ******************************************************************************
  * @file    LED_Prog.c
  * @author  Zeyad Mohamed - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    10-Aug-2023
  * @brief   This file contains all the functions for the LED.
   ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <msp430.h>

#include <driverlib/driverlib.h>

#include "LED_Interface.h"

unsigned char displayCache[NUM_DIGIT];
unsigned char mapdisplay[NUM_DIGIT] = {S7_ICON_GR1,S7_ICON_GR2,S7_ICON_GR3,S7_ICON_GR4,S7_ICON_GR5,S7_ICON_GR6,S7_ICON_GR7,S7_ICON_GR8,S7_ICON_GR9,S7_ICON_GR10,S7_ICON_GR11,S7_ICON_GR12,S7_ICON_GR13,S7_ICON_GR14,S7_ICON_GR15,S7_ICON_GR16};
unsigned char default_BRT = LED_BRT6;

/**
  * @brief  Enable transaction of SPI modules according to STB pin.
  * @param  None
  * @retval None
  */
void LED_BeginTransaction(void)
{
#if LED_SPI_MODULE==LED_SPI_A
    STB_A_BEGIN_TRANSACTION();
#elif LED_SPI_MODULE==LED_SPI_B
    STB_B_BEGIN_TRANSACTION();
#else
#error "Choose the right SPI module"
#endif
}

/**
  * @brief  disable transaction of SPI modules according to STB pin.
  * @param  None
  * @retval None
  */
void LED_EndTransaction(void)
{
#if LED_SPI_MODULE==LED_SPI_A
    STB_A_END_TRANSACTION();
#elif LED_SPI_MODULE==LED_SPI_B
    STB_B_END_TRANSACTION();
#else
#error "Choose the right SPI module"
#endif
}

/**
  * @brief  Initializes the LED according to the specified parameter for the SPI module.
  * @param  None
  * @retval None
  */
void LED_init(void)
{

#if LED_SPI_MODULE==LED_SPI_A
    //Initialization and enable of SPI module.
    SPI_A_init();
#elif LED_SPI_MODULE==LED_SPI_B
    SPI_B_init();
#else
#error "Enter the right SPI module"
#endif
    //Activation of display mode.
    LED_sendCommand(ACTIVATE);
    //Resetting of the whole driver: LED_reset().
    LED_reset();
}

/**
  * @brief  Rest the indication board according to needed parameters.
  * @param  None
  * @retval None
  */
void LED_reset(void)
{
    unsigned char i;
    //Adjust data command to write increment command to start.
    LED_sendCommand(WRITE_INC);
    //Begin transaction by setting STB pin as low.
    LED_BeginTransaction();
    //Set display address to start from address 0.
    LED_send(START_ADDRESS);
    //Loop on all of the digits.
    for (i=0; i<16; i++)
    {
        //Turn off all of the LEDs in the digit by sending 0 to the address.
        LED_send(DIGIT_OFF);
        //Rewrite the display cashe to value of 0.
        displayCache[i]= DIGIT_OFF;
    }
    //End transaction by setting STB pin as high.
    LED_EndTransaction();
    //Adjust display control to activate command.
    LED_sendCommand(ACTIVATE);
}

/**
  * @brief  Transmit data through SPI
  * @param  data: data sent through SPI
  * @retval None
  */
void LED_send(unsigned char data)
{
#if LED_SPI_MODULE==LED_SPI_A
    SPI_A_SendData(data);
#elif LED_SPI_MODULE==LED_SPI_B
    SPI_B_SendData(data);
#else
#error "choose the right SPI module"
#endif
}

/**
  * @brief  Transmit command through SPI
  * @param  cmd: command sent through SPI
  * @retval None
  */
void LED_sendCommand(unsigned char cmd)
{
    //Begin transaction by setting STB pin as low.
    LED_BeginTransaction();
    //Send command through SPI.
    LED_send(cmd);
    //End transaction by setting STB pin as high.
    LED_EndTransaction();
}

/**
  * @brief  Update the Brightness of the leds based on the value of a global variable.
  * @param  brightnessLevel: level of the brightness needed sent by user through keypad.
  * @retval None
  */
void updateBRT(unsigned char brightnessLevel)
{
    /*switching on the value of the pressedKey*/
    switch (brightnessLevel)
    {
        /*if the value of pressedkey = 1*/
        case 1:
        /*update the led brightness to LED_BRT0*/
        default_BRT = LED_BRT0;
        break;

        /*if the value of pressedkey = 2*/
        case 2:
        /*update the led brightness to LED_BRT2*/
        default_BRT = LED_BRT2;
        break;

        /*the default value of the led brightness*/
        case 3:
        /*update the led brightness to LED_BRT6*/
        default_BRT = LED_BRT6;
        break;
    }
}

/**
  * @brief  Assign a value to a specific display.
  * @param  position: the position of the Display.
                        value: the value need to be added to the Display.
  * @retval None.
  */
void displaySS(unsigned char position, unsigned char value)
{
    unsigned char mapPosition;
    mapPosition = mapdisplay[position];
    /*update the value of a specific position in the array*/
    displayCache[mapPosition] = value ;
}

/**
  * @brief  update all displays with the new value given.
  * @param  None
  * @retval None
  */
void updateDisplay(void)
{
    unsigned char p;
    //Send write increment command
    LED_sendCommand(WRITE_INC);
    //Begin transaction by setting STB pin as low.
    LED_BeginTransaction();
    //Set starting address to 0
    LED_send(START_ADDRESS);
    //Loop on the values and send it to each digit
    for(p=0; p<NUM_DIGIT; p++)
    {
        LED_send(displayCache[p]);
    }
    //End transaction by setting STB pin as high.
    LED_EndTransaction();
    //Send activation command with the selected brightness level.
    LED_sendCommand(LED_ON | default_BRT);
}


/**
  * @}
  */

/*History Log*/
/*****************************************************************************************************
          User          |                     brief                         |         Date
******************************************************************************************************
Zeyad Mohamed           |Initial release for MSP430I2041                    |10-Aug-2023
                        |                                                   |
                        |                                                   |
******************************************************************************************************/

/*------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------*-
------------------------------------- END OF FILE -----------------------------------------------------
-*---------------------------------------------------------------------------------------------------*/
