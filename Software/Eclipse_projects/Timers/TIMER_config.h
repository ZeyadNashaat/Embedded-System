#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_

/*Options: 1- TIMER0_ModeNormal
           2- TIMER0_ModePWM
           3- TIMER0_ModeCTC
           4- TIMER0_ModeFastPWM
           */

#define TIMER0_Mode			TIMER0_ModeFastPWM

/*Set value to preload of over flow mode register from 0:255 */

#define TIMER0_OverFlow_Value  0

/*Set value to compare match value register from 0:255*/

#define TIMER0_CTC_Value    125

/*Options: 1- TIMER0_Prescaler_NoClock
           2- TIMER0_Prescaler_DIV1
           3- TIMER0_Prescaler_DIV8
           4- TIMER0_Prescaler_DIV64
           5- TIMER0_Prescaler_DIV256
           6- TIMER0_Prescaler_DIV1024
           7- TIMER0_Prescaler_EXTCLk_Falling
           8- TIMER0_Prescaler_EXTCLk_Rising
   Note: option 7,8 is on PinB0
    */

#define TIMER0_Prescaler 	TIMER0_Prescaler_DIV64

/*Options: 1- TIMER0_Prescaler_DIV1------------>8
           2- TIMER0_Prescaler_DIV8------------>8
           3- TIMER0_Prescaler_DIV64----------->8
           4- TIMER0_Prescaler_DIV256---------->8
           5- TIMER0_Prescaler_DIV1024--------->8
           6- TIMER0_Prescaler_EXTCLk_Falling-->Provide clock frequency in MegaHz
           7- TIMER0_Prescaler_EXTCLk_Rising--->Provide clock frequency in MegaHz
*/
#define TIMER0_FREQ_MEGA	8

/*Options: 1- TIMER0_CTC_PinMode_Disconn
 	 	   2- TIMER0_CTC_PinMode_Toggle
 	 	   3- TIMER0_CTC_PinMode_Set
 	 	   4- TIMER0_CTC_PinMode_Clr
  Note: on PinB3*/

#define TIMER0_CTC_PinMode TIMER0_CTC_PinMode_Disconn

/*Options: 1- TIMER0_FPWM_PinMode_Disconn
           2- TIMER0_FPWM_PinMode_ClrCompareMatch_SetTop
           3- TIMER0_FPWM_PinMode_ClrTop_SetCompareMatch
  Note: on PinB3*/
#define TIMER0_FPWM_PinMode	TIMER0_FPWM_PinMode_ClrCompareMatch_SetTop

#endif
