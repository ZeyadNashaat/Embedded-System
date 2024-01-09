/*
 * main.c
 *
 *  Created on: Aug 10, 2023
 *      Author: Zeyad Mohamed
 */

#include <msp430.h>
#include <driverlib/driverlib.h>
#include "LED_Interface.h"

void main(void)
{
    WDT_hold(WDT_BASE);
    LED_init();
    displaySS(0, C7_A);
    displaySS(1, C7_B);
    displaySS(2, C7_C);
    displaySS(3, C7_D);
    displaySS(4, C7_E);
    displaySS(5, C7_F);
    displaySS(6, C7_G);
    displaySS(7, MASK_7S_ALL);
    displaySS(8, MASK_7S_ALL);
    displaySS(9, MASK_7S_ALL);
    displaySS(10, MASK_7S_ALL);
    displaySS(11, MASK_7S_ALL);
    displaySS(12, MASK_7S_ALL);
    displaySS(13, MASK_7S_ALL);
    displaySS(14, MASK_7S_ALL);
    displaySS(15, MASK_7S_ALL);
    while(1){
        updateDisplay();

    }

}
