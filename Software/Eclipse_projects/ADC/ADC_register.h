#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX         *((volatile u8*)0x27)  //ADC multiplexer selection register
#define ADMUX_REFS1   7                      //Reference selection bit1
#define ADMUX_REFS0   6                      //reference selection bit0
#define ADMUX_ADLAR   5                      //ADC left adjustment result
#define ADMUX_MUX4	  4                      //Channel and gain selection mux bits
#define ADMUX_MUX3    3
#define ADMUX_MUX2    2
#define ADMUX_MUX1    1
#define ADMUX_MUX0    0

#define ADCSRA        *((volatile u8*)0x26)  //ADC control and status register
#define ADCSRA_ADEN   7                      //ADC Enable
#define ADCSRA_ADSC   6                      //ADC conversion
#define ADCSRA_ADATE  5                      //ADC auto trigger enable
#define ADCSRA_ADIF   4                      //interrupt flag
#define ADCSRA_ADIE   3                      //interrupt enable
#define ADCSRA_ADPS2  2                      //prescaler bit2
#define ADCSRA_ADPS1  1                      //prescaler bit1
#define ADCSRA_ADPS0  0                      //prescaler bit0

#define ADCH     *((volatile u8*)0x25)       //ADC high register
#define ADCL     *((volatile u8*)0x24)       //ADC low register

#define ADC10Bit *((volatile u16*)0x24)      //reading 10bits using u16 starting of ADCL ten ADCH

#define SFIOR	 *((volatile u8*)0x50)		 //contains bits of auto trigerring mode
#define ADTS2		  7
#define ADTS1         6
#define ADTS0         5

#endif
