/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Zeyad Mohamed
 */

#include <msp430.h>
#include <driverlib/driverlib.h>
#include "kpd_interface.h"

extern unsigned short PressedKey;

void main(void)
{
    WDT_hold(WDTHOLD);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN4);
    GPIO_setOutputLowOnPin(GPIO_PORT_P1, GPIO_PIN4);
    KPD_Init();
    while(1)
    {
        KPD_GetPressedKey();
        if (PressedKey == 7)
        {
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN4);
        }
    }
}
