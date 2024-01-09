/**
  ******************************************************************************
  * @file    BattGauge_config.h
  * @author  Mamdouh Ezz - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    28-Dec-2022
  * @brief   This file contains all the prebuild configuration of the Battery Gauge
   ******************************************************************************
  */

//-See BattGauge_Program.c for details
/*-----------------------------------------------------------------------------------------------------*/

// ------------------------------------- Define Guardian to prevent recursive inclusion ----------------
#ifndef BATTGAUGE_CONFIG_H_
#define BATTGAUGE_CONFIG_H_


/**
  * @brief  Macro used to define the converter used by the BattGauge.
  */
#define BATTGAUGE_CONVERTER                                                     SD24_CONVERTER_3

/**
  * @brief  Macro used to define the port used by the enable for the BattGauge.
  */
#define BATTGAUGE_ENPORT                                                        GPIO_PORT_P2

/**
  * @brief  Macro used to define the pin used by the enable for the BattGauge.
  */
#define BATTGAUGE_ENPIN                                                         GPIO_PIN0

/**
  * @brief  Macro used to define the Battery threshold (in volt).
  */
#define BATTGAUGE_THRESH                                                        3.5

/**
  * @brief  Macro used to define the minimum volt mapped of the battery gauge (in milli volt).
  */
#define BattGauge_MINIMUM_VOLT_MAPPED                                           0

/**
  * @brief  Macro used to define the maximum volt mapped of the battery gauge (in milli volt).
  */
#define BattGauge_MAXIMUM_VOLT_MAPPED                                           4400

/**
  * @brief  Macro used to define the Battery minimum volt to be input for the MCU (in milli volt).
  */
#define BattGauge_MINIMUM_VOLT                                                  0

/**
  * @brief  Macro used to define the Battery maximum volt to be input for the MCU (in milli volt).
  */
#define BattGauge_MAXIMUM_VOLT                                                   1100


/**
  * @}
  */
/*------------------------------------------------------------------------------------------------*/
#endif /*KPD_CONFIG_h_*/

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
