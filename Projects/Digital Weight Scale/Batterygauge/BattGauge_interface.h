/**
  ******************************************************************************
  * @file    BattGauge_interface.h
  * @author  Mamdouh Ezz - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    28-Dec-2022
  * @brief   This file contains all the functions prototypes for the BattGauge.
   ******************************************************************************
  */

//-See BattGauge_Program.c for details
/*-----------------------------------------------------------------------------------------------------*/



// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef BATTGAUGE_INTERFACE_H_
#define BATTGAUGE_INTERFACE_H_

#include "BattGauge_config.h"

// ------------------------------------ Public/Exported Data Types -------------------------------------
/** @addtogroup BattGauge_Exported_Types
  * @{
  */
/**
  * @brief BattGauge error states
  * The definition of the BattGauge error state that is used by @ref BattGauge_Init and @ref BattGauge_Read @ref BattGauge_Mapping and @ref BattGauge_Check
  */
typedef enum BattGauge_ErrStateTypeDef
{
    BattGauge_OK=0, /*!< BattGauge runs correctly */
    BattGauge_TIMEOUT=1, /*!< BattGauge  time out to make sure the conversion is done*/
    BattGauge_ERROR,
    BattGauge_LOWBATT /*!< BattGauge  low battery warning*/
}BattGauge_ErrStateTypeDef;


/**
  * @}
  */
// ------------------------------------ Public/Exported Variables declaration --------------------------

// ------------------------------------ Public/Exported functions Prototypes -------------------------------------

/*------------------------------------------------------------------------------------------------*/

/** @addtogroup BattGauge_Exported_Functions
  * @{
  */

BattGauge_ErrStateTypeDef BattGauge_Init(void);

BattGauge_ErrStateTypeDef BattGauge_Read(void);

BattGauge_ErrStateTypeDef BattGauge_Mapping(unsigned short Batt_Volt);

BattGauge_ErrStateTypeDef BattGauge_Check(void);

/**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/

#endif /*BattGauge_INTERFACE_H_*/

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
