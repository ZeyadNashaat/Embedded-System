#include<util/delay.h>
#include<avr/io.h>
#include"STD_TYPES.h"
void main(void)
{
	while(1)
	{
		DDRA=0b00001000;
		DDRB=0b00010111;
		u8 SEVSEGARR[10]=
		{0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111,
		0b00010000, 0b00010001};
		u8 i;
		for (i=0;i<10;i++)
		{
			PORTB=SEVSEGARR[i];
			_delay_ms(1000);
		}
		}
}
