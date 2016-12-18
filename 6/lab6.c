#define F_CPU	16000000UL	// CPU frequency = 16 Mhz
#include <avr/io.h>	
#include <util/delay.h>

int main (void)
{
  DDRA = 0xff;	

  unsigned char FND_DATA[ ]= {
		0x3f, // 0
		0x06, // 1 
		0x5b, // 2 
		0x4f, // 3 
		0x66, // 4 
		0x6d, // 5 
		0x7d, // 6 
		0x27, // 7 
		0x7f, // 8 
		0x6f, // 9 
		0x77, // A 
		0x7c, // B 
		0x39, // C 
		0x5e, // D 
		0x79, // E 
		0x71, // F 
		0x80, // . 
		0x40, // - 
		0x08  // _
	};
    unsigned int num=0, num0, num1, num2, num3;

	DDRC = 0xff;	
    DDRG = 0x0f;
  	
  while (1)  {
    PORTA = 0xaa;
	//_delay_ms(500);

	for(int i=0; i<50; i++){
		num++;
		num3 = (num / 1000) % 10;
		num2 = (num / 100) % 10;
		num1 = (num / 10) % 10;
		num0 = num % 10;
		PORTC = FND_DATA[num3];
		PORTG = 0x08;	
		_delay_ms(2);
			
		PORTC = FND_DATA[num2] | FND_DATA[16];
		PORTG = 0x04;
		_delay_ms(3);
		
		PORTC = FND_DATA[num1];
		PORTG = 0x02;	
		_delay_ms(2);
		
		PORTC = FND_DATA[num0];
		PORTG = 0x01;
		_delay_ms(3);
	}

    PORTA = 0x55;
	//_delay_ms(500);

	for(int i=0; i<50; i++){
		num++;
		num3 = (num / 1000) % 10;
		num2 = (num / 100) % 10;
		num1 = (num / 10) % 10;
		num0 = num % 10;
		PORTC = FND_DATA[num3];
		PORTG = 0x08;	
		_delay_ms(2);
			
		PORTC = FND_DATA[num2] | FND_DATA[16];
		PORTG = 0x04;
		_delay_ms(3);
		
		PORTC = FND_DATA[num1];
		PORTG = 0x02;	
		_delay_ms(2);
		
		PORTC = FND_DATA[num0];
		PORTG = 0x01;
		_delay_ms(3);
	}
  }                         
  
  return 0;
}
