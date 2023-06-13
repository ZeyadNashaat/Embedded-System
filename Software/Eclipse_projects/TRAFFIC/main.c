#include<util/delay.h>
#include<avr/io.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
void main(void)
{
	u8 i;
	DDRA=0b01011000;
	DDRB=0b10010111;
	u8 SEVSEGARR[10]=
			{0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111,
			0b00010000, 0b00010001};
	u8 j=0;
	u8 k=0;
	while(1)
	{
		j=0;
		k=0;
		for (i=0;i<10;i++)
		{
			if (i<=3)
			{
				PORTB=SEVSEGARR[i+1];
				CLR_BIT(PORTA,4);
				SET_BIT(PORTB,7);
			}
			else if (i<=5)
			{
				PORTB=SEVSEGARR[j+1];
				j=j+1;
				CLR_BIT(PORTB,7);
				SET_BIT(PORTA,6);
			}
			else
			{
				PORTB=SEVSEGARR[k+1];
				k=k+1;
				CLR_BIT(PORTA,6);
				SET_BIT(PORTA,4);
			}
			_delay_ms(1000);
		}
	}
}
