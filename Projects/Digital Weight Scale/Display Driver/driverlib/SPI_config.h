/**
  ******************************************************************************
  * @file    SPI_Config.h
  * @author  Zeyad Mohamed - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    29-Aug-2023
  * @brief   This file contains all the pre-built configurations for SPI.
   ******************************************************************************
  */

//-See SPI_progarm.c for details
/*-----------------------------------------------------------------------------------------------------*/

// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef DRIVERLIB_SPI_CONFIG_H_
#define DRIVERLIB_SPI_CONFIG_H_

/**
  * @brief  Macro used to define the port used by the SPI A module.
  */
#define SPI_A_GPIO                GPIO_PORT_P1

/**
  * @brief  Macro used to define the pins used by the SPI A module. Another strobe pins can be added to control another LEDs.
  */
#define SPI_A_CLOCK_PIN           GPIO_PIN1
#define SPI_A_DATA_PIN            GPIO_PIN3
#define SPI_A_STB_PIN             GPIO_PIN0

/**
  * @brief  Macro used to define frequency by which the SPI A module functions. It should start from 2KHz.
  */
#define SPI_A_FREQ                2000

/**
  * @brief  Macro used to configurate SPI A port and pins.
  */
#define SPI_A_OUT()             do{GPIO_setAsPeripheralModuleFunctionInputPin(SPI_A_GPIO, SPI_A_STB_PIN | SPI_A_DATA_PIN| SPI_A_CLOCK_PIN,GPIO_PRIMARY_MODULE_FUNCTION);\
                                   GPIO_setAsOutputPin(SPI_A_GPIO, SPI_A_STB_PIN);\
                                   GPIO_setOutputHighOnPin(SPI_A_GPIO, SPI_A_STB_PIN);} while(0)

/**
  * @brief  Macro used to end the transaction from SPI A.
  */
#define STB_A_END_TRANSACTION()   GPIO_setOutputHighOnPin(SPI_A_GPIO, SPI_A_STB_PIN)

/**
  * @brief  Macro used to Begin the transaction from SPI A.
  */
#define STB_A_BEGIN_TRANSACTION() GPIO_setOutputLowOnPin(SPI_A_GPIO, SPI_A_STB_PIN)

/**
  * @brief  Macro used to define the port used by the SPI B module.
  */
#define SPI_B_GPIO                GPIO_PORT_P1

/**
  * @brief  Macro used to define the pins used by the SPI B module. Another strobe pins can be added to control another LEDs.
  */
#define SPI_B_CLOCK_PIN           GPIO_PIN5
#define SPI_B_DATA_PIN            GPIO_PIN7
#define SPI_B_STB_PIN             GPIO_PIN4

/**
  * @brief  Macro used to define frequency by which the SPI B module functions. It should start from 2KHz.
  */
#define SPI_B_FREQ                2000

/**
  * @brief  Macro used to configurate SPI B port and pins.
  */
#define SPI_B_OUT()             do{GPIO_setAsPeripheralModuleFunctionInputPin(SPI_B_GPIO, SPI_B_STB_PIN | SPI_B_DATA_PIN| SPI_B_CLOCK_PIN,GPIO_PRIMARY_MODULE_FUNCTION);\
                                   GPIO_setAsOutputPin(SPI_B_GPIO, SPI_B_STB_PIN);\
                                   GPIO_setOutputHighOnPin(SPI_B_GPIO, SPI_B_STB_PIN);} while(0)
/**
  * @brief  Macro used to end the transaction from SPI B.
  */
#define STB_B_END_TRANSACTION()   GPIO_setOutputHighOnPin(SPI_B_GPIO, SPI_B_STB_PIN)

/**
  * @brief  Macro used to Begin the transaction from SPI B.
  */
#define STB_B_BEGIN_TRANSACTION() GPIO_setOutputLowOnPin(SPI_B_GPIO, SPI_B_STB_PIN)


#endif /* DRIVERLIB_SPI_CONFIG_H_ */

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
