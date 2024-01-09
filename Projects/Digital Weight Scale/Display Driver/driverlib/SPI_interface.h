/**
  ******************************************************************************
  * @file    SPI_interface.h
  * @author  Zeyad Mohamed - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    29-Aug-2023
  * @brief   This file contains all the functions prototypes for the SPI.
   ******************************************************************************
  */

//-See SPI_program.c for details
/*-----------------------------------------------------------------------------------------------------*/



// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef DRIVERLIB_SPI_INTERFACE_H_
#define DRIVERLIB_SPI_INTERFACE_H_

#include "SPI_config.h"
// ------------------------------------ Public/Exported Data Types -------------------------------------
/** @addtogroup BattGauge_Exported_Types
  * @{
  */
/**
  * @brief SPI error states
  * The definition of the SPI error state that is used by @ref SPI_A_Init and @ref SPI_B_init @ref SPI_A_SendData and @ref SPI_B_SendData
  */
typedef enum SPI_ErrStateTypeDef
{
    SPI_OK=0, /*!< SPI runs correctly */
    SPI_TIMEOUT=1, /*!< SPI  time out to make sure the data is sent*/
    SPI_ERROR
}SPI_ErrStateTypeDef;


/**
  * @}
  */
// ------------------------------------ Public/Exported Variables declaration --------------------------

// ------------------------------------ Public/Exported functions Prototypes -------------------------------------

/*------------------------------------------------------------------------------------------------*/

/** @addtogroup BattGauge_Exported_Functions
  * @{
  */

SPI_ErrStateTypeDef SPI_A_init(void);

SPI_ErrStateTypeDef SPI_B_init(void);

SPI_ErrStateTypeDef SPI_A_SendData(unsigned char data);

SPI_ErrStateTypeDef SPI_B_SendData(unsigned char data);

/**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/

#endif /* DRIVERLIB_SPI_INTERFACE_H_ */

/*History Log*/
/*****************************************************************************************************
          User          |                     brief                         |         Date
******************************************************************************************************
Zeyad Mohamed           |Initial release for MSP430I2041                    |29-Aug-2023
                        |                                                   |
                        |                                                   |
******************************************************************************************************/

/*---------------------------------------------------------------------------------------------------*-
------------------------------------- END OF FILE -----------------------------------------------------
-*---------------------------------------------------------------------------------------------------*/
