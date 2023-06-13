#include<avr/io.h>
#include<util/delay.h>
void main(void)
{
	DDRB=0b10000000;
	DDRA=0b01010000;
	while(1)
	{
		PORTB=0b10000000;
		_delay_ms(3000);
		PORTB=0;
		PORTA=0b01000000;
		_delay_ms(2000);
		PORTA=0b00010000;
	}
}
