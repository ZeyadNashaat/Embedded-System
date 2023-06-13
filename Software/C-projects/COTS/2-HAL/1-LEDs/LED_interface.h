#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_u8CONNTYPE_SRC 1
#define LED_u8CONNTYPE_SNK 0

typedef struct
{
	u8 PORT;
	u8 PIN;
	u8 CONNTYPE;
}LED_t;

void LED_voidTurnOn(LED_t* Copy_pu8struct);
void LED_voidTurnOff(LED_t* Copy_pu8struct);

#endif
