#ifndef EXTI_REGISTER_H
#define EXTI_REGISTER_H

#define GICR	    	*((volatile u8*)0x5B) /*Specific interrupt enable register*/
#define GICR_INT1		7 
#define GICR_INT0		6
#define GICR_INT2		5

#define GIFR	    	*((volatile u8*)0x5A) /*interrupt flag register*/
#define GIFR_INTF1		7
#define GIFR_INTF0		6
#define GIFR_INTF2		5

#define MCUCR	    	*((volatile u8*)0x55) /*interrupt sense control for INT1 and INT0*/
#define MCUCR_ISC11 	3 /*for INT1*/   			
#define MCUCR_ISC10 	2 /*for INT1*/
#define MCUCR_ISC01 	1 /*for INT0*/
#define MCUCR_ISC00 	0 /*for INT0*/

#define MCUCSR	 		*((volatile u8*)0x54) /*interrupt sense control for INT2*/
#define MCUCSR_ISC2		6 /*for INT2*/

#endif
