#define F_CPU	16000000UL	// CPU frequency = 16 Mhz
#include <avr/io.h>	
#include <util/delay.h>


int main(void)
{					
	DDRA = 0xff;		
	PORTA = 0xff;		
	_delay_ms(1000);		
				
	PORTA = 0x80;	
	_delay_ms(1000);

	while (1)  {
		PORTA = 0xaa;
		_delay_ms(500);
		PORTA = 0x55;
		_delay_ms(500);
	}
}

