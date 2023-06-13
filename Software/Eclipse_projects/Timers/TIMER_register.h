#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

#define TCCR0			*((volatile u8*)0x53)     //Timer/Counter0 control register
#define TCCR0_FOC0		7     				     //forces output compare match when setting this bit
#define TCCR0_WGM00 	6     				    //Waveform generation mode bits
#define TCCR0_WGM01		3
#define TCCR0_COM00		4	  				   //controls output compare pin OC0(PB3)
#define TCCR0_COM01		5
#define TCCR0_CS02      2	                  //Controls clock prescalling
#define TCCR0_CS01		1
#define TCCR0_CS00		0

#define TCNT0           *((volatile u8*)0x52) //Timer/Counter0 overflow register

#define OCR0  			*((volatile u8*)0x5C) //Timer/Counter0 output compare register

#define TIMSK           *((volatile u8*)0x59) //Timer/Counter0 interrupt mask
#define TIMSK_OCIE0		1  					  //Timer/Counter0 output compare interrupt enable
#define TIMSK_TOIE0     0					  //Timer/Counter0 overflow interrupt enable

#endif
