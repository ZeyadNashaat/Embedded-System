#include<util/delay.h>
#include<avr/io.h>
#include"STD_TYPES.h"
#include"BIT_MATH.h"
void main(void)
{
	while(1)
		{
			DDRB=0b00010111;
			u8 SEVSEGARR[10]=
			{0b00000000, 0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110, 0b00000111,
			0b00010000, 0b00010001};
			u8 i,j;
			u8 k=0,l=0;
			for (i=0;i<20;i++)
			{
				if (i<9)
				{
					SET_BIT(DDRA,3);
					CLR_BIT(DDRA,2);
					PORTB=SEVSEGARR[i+1];
					_delay_ms(1000);
				}
				else if (i<19&&i>=9)
				{
					for (j=0;j<=100;j++)
					{
						if (j%2==0)
						{
							SET_BIT(DDRA,3);
							CLR_BIT(DDRA,2);
							PORTB=SEVSEGARR[k];
							_delay_ms(10);
						}
						else
						{
							CLR_BIT(DDRA,3);
							SET_BIT(DDRA,2);
							PORTB=SEVSEGARR[1];
							_delay_ms(10);
						}
					}
					k=k+1;
				}
				else
				{
					for (j=0;j<=100;j++)
					{
						if (j%2==0)
						{
							SET_BIT(DDRA,3);
							CLR_BIT(DDRA,2);
							PORTB=SEVSEGARR[l];
							_delay_ms(10);
						}
						else
						{
							CLR_BIT(DDRA,3);
							SET_BIT(DDRA,2);
							PORTB=SEVSEGARR[2];
							_delay_ms(10);
						}
					}
					l=l+1;
				}

			}
		}
}
