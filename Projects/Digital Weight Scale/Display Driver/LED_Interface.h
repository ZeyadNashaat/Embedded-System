/**
  ******************************************************************************
  * @file    LED_Interface.h
  * @author  Zeyad Mohamed - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    10-Aug-2023
  * @brief   This file contains all the prototypes for LED.
   ******************************************************************************
  */

//-See LED_prog.c for details
/*-----------------------------------------------------------------------------------------------------*/

// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#include "LED_Config.h"

/**
  * @}
  */
// ------------------------------------ Public/Exported Variables declaration --------------------------

// ------------------------------------ Public/Exported functions Prototypes -------------------------------------

/*------------------------------------------------------------------------------------------------*/

/** @addtogroup LED_Exported_Functions
  * @{
  */
void LED_BeginTransaction(void);
void LED_EndTransaction(void);
void LED_init(void);
void LED_reset(void);
void LED_send(unsigned char data);
void LED_sendCommand(unsigned char cmd);
void updateBRT(unsigned char brightnessLevel);
void displaySS(unsigned char position, unsigned char value);
void updateDisplay(void);


/**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/

#endif /* LED_INTERFACE_H_ */

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
