#define F_CPU	16000000UL	// CPU frequency = 16 Mhz
#include <avr/io.h>	
#include <util/delay.h>

void main(){

	DDRA = 0xff;
	PORTA = 0xff;		
	_delay_ms(1000);
	PORTA = 0x00;		
	_delay_ms(1000);

	//1
	/*
	volatile int i;
	for(i=0; i<256; i++){
		PORTA = i;
		_delay_ms(100);
	}
	PORTA = 0x00;		
	_delay_ms(1000);
	*/

	//2
	/*
	volatile int j;
	int on = 128;
	for(j=0; j<8; j++){
		PORTA = on;
		_delay_ms(100);
		on = on/2;
	}
	*/

	//3
	/*
	volatile int k;
	int on = 1;
	for(k=0; k<8; k++){
		PORTA = on;
		_delay_ms(100);
		on = on*2;
	}
	on = 128;
	for(k=0; k<8; k++){
		PORTA = on;
		_delay_ms(100);
		on = on/2;
	}
	*/

	/*
	//4
	volatile int t;
	int on = 128;
	int half = 128;
	for(t=0; t<8; t++){
		PORTA = on;
		_delay_ms(100);
		half = half/2;
		on = on + half;
	}
	on = 255;
	half = 1;
	for(t=0; t<8; t++){
		PORTA = on;
		_delay_ms(100);
		on = on - half;
		half = half*2;
	}
	*/

	/*
	//5
	volatile int z;
	unsigned int a=17, b=49, c=103;
	unsigned int value;
	for (z = 0; z < 20; z++)
	{
		value = (a++) * (b++) + (c++);
		PORTA = value; // LED에 값 출력
		_delay_ms(200); // 0.2초 지연
	}
	*/

	//숙제 
	// 도 = 128, 레 = 64, 미 = 32, 파 = 16, 솔 = 8, 라 = 4, 시 = 2, 도 = 1
	PORTA = 8;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(200);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 16;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 64;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 64;
	_delay_ms(200);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 128;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 64;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 16;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 8;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 8;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 8;
	_delay_ms(200);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 8;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 16;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 64;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 64;
	_delay_ms(200);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 128;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 8;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 8;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(100);
	PORTA = 0;
	_delay_ms(10);
	PORTA = 32;
	_delay_ms(200);
	PORTA = 0;
	_delay_ms(10);
}
