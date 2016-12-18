#define F_CPU	16000000UL

#include <avr/io.h>
#include <util/delay.h>


void main(){
	//1
	DDRA = 0xff;
	PORTA = 0xff;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	
	//2
	PORTA = 0x80;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x40;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x20;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x10;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x08;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x04;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x02;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x01;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);

	//3
	PORTA = 0xaa;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x55;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);

	//4
	PORTA = 0xcc;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0x33;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);

	//5
	PORTA = 0x81;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0xc3;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 0xe7;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);

	//6
	PORTA = 'A';
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);
	PORTA = 63;
	_delay_ms(1000);
	PORTA = 0x00;
	_delay_ms(1000);

}

