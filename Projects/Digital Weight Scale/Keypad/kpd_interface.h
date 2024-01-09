/**
  ******************************************************************************
  * @file    KPD_Interface.h
  * @author  Mamdouh Ezz - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    28-Dec-2022
  * @brief   This file contains all the functions prototypes for the KPD_Preph firmware library.
   ******************************************************************************
  */

//-See KPD_Program.c for details
/*-----------------------------------------------------------------------------------------------------*/



// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#include"kpd_config.h"

// ------------------------------------ Public/Exported Data Types -------------------------------------
/** @addtogroup KPD_Exported_Types
  * @{
  */
/**
  * @brief KPD error states
  * The definition of the DSCI error state that is used by @ref KPD_Init and @ref KPD_GetPressedKey
  */
typedef enum KPD_ErrStateTypeDef
{
    KPD_OK, /*!< KPD runs correctly */
    KPD_TIMEOUT,
    KPD_ERROR,  /*!< KPD was pressed more than 4 seconds  */
    KPD_KEYHOLD = 90,
    KPD_NOKEYPRESSED = 100
}KPD_ErrStateTypeDef;


/**
  * @}
  */
// ------------------------------------ Public/Exported Variables declaration --------------------------

// ------------------------------------ Public/Exported functions Prototypes -------------------------------------

/*------------------------------------------------------------------------------------------------*/

/** @addtogroup KPD_Exported_Functions
  * @{
  */

KPD_ErrStateTypeDef KPD_Init(void);

KPD_ErrStateTypeDef KPD_GetPressedKey(void);


/**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/

#endif /*KPD_INTERFACE_H_*/

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
