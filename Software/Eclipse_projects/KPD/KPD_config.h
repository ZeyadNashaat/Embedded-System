#ifndef KPD_CONFIG_H_
#define KPD_CONFIG_H_

#define KPD_COLUMN_PORT				DIO_u8PORTD
#define KPD_ROW_PORT                DIO_u8PORTC

/* Set COLUMN to OUTPUT with Initial Value of HIGH */
#define KPD_COLUMN0_PIN			DIO_u8PIN0
#define KPD_COLUMN1_PIN			DIO_u8PIN1
#define KPD_COLUMN2_PIN			DIO_u8PIN2
#define KPD_COLUMN3_PIN			DIO_u8PIN3

/* Set ROW to INPUT with PULLUP enabled */
#define KPD_ROW0_PIN			DIO_u8PIN4
#define KPD_ROW1_PIN			DIO_u8PIN5
#define KPD_ROW2_PIN			DIO_u8PIN6
#define KPD_ROW3_PIN			DIO_u8PIN7

/* Values should be between 0 and 255*/
#define KPD_NO_PRESSED_KEY		255

#define KPD_ARR_VAL				{{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}

#endif
