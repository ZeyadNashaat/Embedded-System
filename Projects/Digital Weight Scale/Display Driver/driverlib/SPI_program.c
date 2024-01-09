/**
  ******************************************************************************
  * @file    A_SPI_program.c
  * @author  Zeyad Mohamed - Embedded Systems Team - I-D Tech
  * @version V1.1.0
  * @date    27-Aug-2023
  * @brief   This file contains all the functions for initializing and enabling EUSCIA SPI.
   ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include <driverlib/driverlib.h>
#include <msp430.h>


/**
  * @brief  Initializes and enables the SPI A module according to the needed parameters.
  * @param  None
  * @retval SPI_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref SPI_ErrStateTypeDef
  */
SPI_ErrStateTypeDef SPI_A_init(void)
{
    //initialization of clock used for SPI.
    CS_setupDCO(CS_INTERNAL_RESISTOR);
    CS_initClockSignal(CS_SMCLK,CS_CLOCK_DIVIDER_1);
    //Configuration of pins used with SPI module.
    SPI_A_OUT();
    //Set-up SPI configuration: clock source and value, LSB� first, normally high�clock polarity, data changed on the falling edge and captured on the rising one,�4-pin functionality�
    EUSCI_A_SPI_initMasterParam spiMasterConfig =
        {
            EUSCI_A_SPI_CLOCKSOURCE_SMCLK,
            16384000,
            SPI_A_FREQ,
            EUSCI_A_SPI_LSB_FIRST,
            EUSCI_A_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,
            EUSCI_A_SPI_CLOCKPOLARITY_INACTIVITY_HIGH,
            EUSCI_A_SPI_4PIN_UCxSTE_ACTIVE_LOW,
        };
    EUSCI_A_SPI_initMaster(EUSCI_A0_BASE, &spiMasterConfig);
    EUSCI_A_SPI_select4PinFunctionality(EUSCI_A0_BASE, EUSCI_A_SPI_ENABLE_SIGNAL_FOR_4WIRE_SLAVE);
    //Enabling SPI module.
    EUSCI_A_SPI_enable(EUSCI_A0_BASE);
    return SPI_OK;
}

/**
  * @brief  Initializes and enables the SPI B module according to the needed parameters.
  * @param  None
  * @retval SPI_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref SPI_ErrStateTypeDef
  */
SPI_ErrStateTypeDef SPI_B_init(void)
{
    //initialization of clock used for SPI.
    CS_setupDCO(CS_INTERNAL_RESISTOR);
    CS_initClockSignal(CS_SMCLK,CS_CLOCK_DIVIDER_1);
    //Configuration of pins used with SPI module.
    SPI_B_OUT();
    //Set-up SPI configuration: clock source and value, LSB� first, normally high�clock polarity, data changed on the falling edge and captured on the rising one,�4-pin functionality�
    EUSCI_B_SPI_initMasterParam spiMasterConfig =
        {
            EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
            16384000,
            SPI_B_FREQ,
            EUSCI_B_SPI_LSB_FIRST,
            EUSCI_B_SPI_PHASE_DATA_CHANGED_ONFIRST_CAPTURED_ON_NEXT,
            EUSCI_B_SPI_CLOCKPOLARITY_INACTIVITY_HIGH,
            EUSCI_B_SPI_4PIN_UCxSTE_ACTIVE_LOW,
        };
    EUSCI_B_SPI_initMaster(EUSCI_B0_BASE, &spiMasterConfig);
    EUSCI_B_SPI_select4PinFunctionality(EUSCI_B0_BASE, EUSCI_B_SPI_ENABLE_SIGNAL_FOR_4WIRE_SLAVE);
    //Enabling SPI module.
    EUSCI_B_SPI_enable(EUSCI_B0_BASE);
    return SPI_OK;
}

/**
  * @brief  Transmit data through SPI A while polling on the data to make sure its all sent.
  * @param  data: data sent through SPI
  * @retval SPI_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref SPI_ErrStateTypeDef
  */
SPI_ErrStateTypeDef SPI_A_SendData(unsigned char data)
{
    unsigned int timeout_counter=0;
    //Transmit the data through SPI A.
    EUSCI_A_SPI_transmitData(EUSCI_A0_BASE, data);
    //Polling until the whole data is sent and sending buffer is empty.
    while(EUSCI_A_SPI_isBusy(EUSCI_A0_BASE)==EUSCI_A_SPI_BUSY)
    {
        timeout_counter++;
        if (timeout_counter>4000)
        {
            return SPI_TIMEOUT;
        }
    }
    return SPI_OK;
}

/**
  * @brief  Transmit data through SPI B while polling on the data to make sure its all sent.
  * @param  data: data sent through SPI
  * @retval SPI_ErrStateTypeDef: an error state that indicates that the system operate correctly @ref SPI_ErrStateTypeDef
  */
SPI_ErrStateTypeDef SPI_B_SendData(unsigned char data)
{
    unsigned int timeout_counter=0;
    //Transmit the data through SPI B.
    EUSCI_B_SPI_transmitData(EUSCI_B0_BASE, data);
    //Polling until the whole data is sent and sending buffer is empty.
    while(EUSCI_B_SPI_isBusy(EUSCI_B0_BASE)==EUSCI_B_SPI_BUSY)
    {
        timeout_counter++;
        if (timeout_counter>4000)
        {
            return SPI_TIMEOUT;
        }
    }
    return SPI_OK;
}


/**
  * @}
  */

/*History Log*/
/*****************************************************************************************************
          User          |                     brief                         |         Date
******************************************************************************************************
Zeyad Mohamed           |Initial release for MSP430I2041                    |29-Aug-2023
                        |                                                   |
                        |                                                   |
******************************************************************************************************/

/*------------------------------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------------------------------*-
------------------------------------- END OF FILE -----------------------------------------------------
-*---------------------------------------------------------------------------------------------------*/
