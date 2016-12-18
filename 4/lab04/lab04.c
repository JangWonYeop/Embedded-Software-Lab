/*
#define F_CPU 16000000UL
#include <avr/io.h> // ATmega128 register 정의
#include <util/delay.h>

int main(void)
{
	DDRA = 0xff;
	DDRE &= 0xf3;

	while (1)
	{
		PORTA = PINE; // SW1 = PE bit4, SW2 = PE bit5
		_delay_ms(100);
	}
}
*/


/*
#define F_CPU 16000000UL
#include <avr/io.h> // ATmega128 register 정의
#include <util/delay.h>

int main(void)
{
	DDRA = 0xff;
	PORTA = 0x00;
	DDRE &= 0xcf;

	int led = 0;
	int value = 0x00;

	while (1)
	{
		if(led == 0){
			if(PINE == 0xef){
				led = 1;
				value = 0xff;
				PORTA = value;
			}
			if(PINE == 0xdf){
				led = 1;
				value++;
				PORTA = value;
			}
		}

		if(led == 1){
			if(PINE == 0xef){
				led = 0;
				value = 0x00;
				PORTA = value;
			}
			if(PINE == 0xdf){
				value++;
				PORTA = value;
			}
		}
	}
}
*/

// 스위치 1번이 led4, 2번이 led3
/*
#define F_CPU	16000000UL
#include <avr/io.h>		
#include <avr/interrupt.h>	
#include <util/delay.h>

volatile static int num = 0;

// switch 1
SIGNAL(SIG_INTERRUPT4){

	cli( );

	if(PORTA == 0x00){
		PORTA = 0xff;
	}
	else{
		PORTA = 0x00;
	}
	_delay_ms(100);	

	sei( );
}

// switch 2
SIGNAL(SIG_INTERRUPT5){

	cli( );

	num++;
	_delay_ms(100);	

	sei( );
}

void main(){

	static unsigned char FND_DATA[ ]= {
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

	DDRA = 0xff;
	PORTA = 0x00;

	DDRE = 0xcf;
	DDRC = 0xff;

	EICRA = 0x00;
	EICRB = 0x0a;

	EIMSK = 0x30;
	SREG |= 0x80;

//4321
	while(1){
		PORTC = FND_DATA[num%10];
		PORTG = 0x01;

		PORTC = FND_DATA[(num/10)%10];
		PORTG = 0x02;

		PORTC = FND_DATA[(num/100)%10];
		PORTG = 0x04;

		PORTC = FND_DATA[(num/1000)%10];
		PORTG = 0x08;
	}
}
*/

/*
#define F_CPU	16000000UL
#include <avr/io.h>		
#include <avr/interrupt.h>	
#include <util/delay.h>

volatile int onOff = 0;
volatile int num = 0;
volatile int display = 0;
volatile int start = 0;

SIGNAL(SIG_INTERRUPT4){

	cli( );

	if(onOff == 0){
		onOff = 1;
		start = 1;
	}
	else{
		onOff = 0;
		display = num;
	}
	_delay_ms(100);	

	sei( );
}

SIGNAL(SIG_INTERRUPT5){

	cli( );

	num = 0;
	display = 0;
	start = 0;
	onOff = 0;
	_delay_ms(100);	

	sei( );
}

void main(){

	static unsigned char FND_DATA[ ]= {
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

	DDRE = 0xcf;
	DDRC = 0xff;

	EICRA = 0x00;
	EICRB = 0x0a;

	EIMSK = 0x30;
	SREG |= 0x80;

	while(1){
		if(onOff == 1){
			PORTC = FND_DATA[num%10];
			PORTG = 0x01;
			_delay_ms(2);

			PORTC = FND_DATA[(num/10)%10];
			PORTG = 0x02;
			_delay_ms(3);

			PORTC = FND_DATA[(num/100)%10];
			PORTG = 0x04;
			_delay_ms(2);

			PORTC = FND_DATA[(num/1000)%10];
			PORTG = 0x08;
			_delay_ms(3);
		}
		else{
			PORTC = FND_DATA[display%10];
			PORTG = 0x01;
			_delay_ms(2);

			PORTC = FND_DATA[(display/10)%10];
			PORTG = 0x02;
			_delay_ms(3);

			PORTC = FND_DATA[(display/100)%10];
			PORTG = 0x04;
			_delay_ms(2);

			PORTC = FND_DATA[(display/1000)%10];
			PORTG = 0x08;
			_delay_ms(3);
		}
		if(start == 1){
			num++;
		}
	}
}
*/

/*
#define F_CPU	16000000UL
#include <avr/io.h>		
#include <util/delay.h>

volatile int num = 0;

void main(){

	static unsigned char FND_DATA[ ]= {
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

	DDRA = 0xff;
	PORTA = 0x00;

	DDRE = 0xcf;
	DDRC = 0xff;

//4321
// 스위치 1번이 led4, 2번이 led3
// 스위치 1번 눌렸을 때 00100000
// 스위치 2번 눌렸을 때 00010000
	while(1){

		if(PORTA == 0x00){
			if(PINE == 0x20 ){
				PORTA = 0xff;
				_delay_ms(100);
			}
		}
		else{
			if(PINE == 0x20){
				PORTA = 0x00;
				_delay_ms(100);
			}
		}

		PORTC = FND_DATA[num%10];
		PORTG = 0x01;

		PORTC = FND_DATA[(num/10)%10];
		PORTG = 0x02;

		PORTC = FND_DATA[(num/100)%10];
		PORTG = 0x04;

		PORTC = FND_DATA[(num/1000)%10];
		PORTG = 0x08;

		if(PINE == 0x10){
			num++;
			_delay_ms(100);
		}
	}
}
*/

#define F_CPU	16000000UL
#include <avr/io.h>		
#include <util/delay.h>

volatile int num = 0;
volatile int onOff = 0;
volatile int tempNum = 0;

void main(){

	static unsigned char FND_DATA[ ]= {
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

	DDRE = 0xcf;
	DDRC = 0xff;

	while(1){
		
		if(onOff == 1){
		PORTC = FND_DATA[num%10];
		PORTG = 0x01;
		_delay_ms(2);

		PORTC = FND_DATA[(num/10)%10];
		PORTG = 0x02;
		_delay_ms(3);

		PORTC = FND_DATA[(num/100)%10];
		PORTG = 0x04;
		_delay_ms(2);

		PORTC = FND_DATA[(num/1000)%10];
		PORTG = 0x08;
		_delay_ms(3);
		}
		else{
			PORTC = FND_DATA[tempNum%10];
		PORTG = 0x01;
		_delay_ms(2);

		PORTC = FND_DATA[(tempNum/10)%10];
		PORTG = 0x02;
		_delay_ms(3);

		PORTC = FND_DATA[(tempNum/100)%10];
		PORTG = 0x04;
		_delay_ms(2);

		PORTC = FND_DATA[(tempNum/1000)%10];
		PORTG = 0x08;
		_delay_ms(3);
		}

		if(onOff == 0){
			if(PINE == 0x20){
				onOff = 1;
				_delay_ms(100);
			}
		}
		else{
			if(PINE == 0x20){
				onOff = 0;
				tempNum = num;
				_delay_ms(100);
			}
		}

		if(PINE == 0x10){
			num = 0;
			onOff = 0;
			tempNum = 0;
			_delay_ms(100);
		}

		num++;
	}
}
