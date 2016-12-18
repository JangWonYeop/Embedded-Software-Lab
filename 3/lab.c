/*
#include <avr/io.h> // ATmega128 register 정의

void main()
{
	unsigned char FND_DATA[ ]= {0x3f, 0x06, 0x5b, 0x4f,
	0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e,
	0x79, 0x71, 0x80, 0x40, 0x08}; // 0~9, A~F, ‘.’, ‘-’, ‘_”

	DDRC = 0xff; // C 포트는 모두 출력
	DDRG = 0x0f; // G 포트도 4개는 출력

	PORTC = FND_DATA[7]; // C 포트는 FND 데이터 신호
	PORTG = 0x01; // G 포트는 FND 선택 신호
}
*/

/*
#include <avr/io.h>
#include <util/delay.h>

void main()
{
	unsigned char FND_DATA[ ]= {0x3f, 0x06, 0x5b,
	0x4f, 0x66, 0x6d, 0x7d, 0x27, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e,
	0x79, 0x71, 0x80, 0x40, 0x08};

	DDRC = 0xff;
	DDRG = 0x0f;

	while(1)
	{
		PORTC = FND_DATA[1];
		PORTG = 0x08;
		_delay_ms(1);

		PORTC = FND_DATA[2];
		PORTG = 0x04;
		_delay_ms(1);

		PORTC = FND_DATA[3];
		PORTG = 0x02;
		_delay_ms(1);

		PORTC = FND_DATA[4];
		PORTG = 0x01;
		_delay_ms(1);
	}
}
*/

/*
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void main()
{
	unsigned char FND_DATA[ ]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 
	0x6d, 0x7d, 0x27, 0x7f, 0x6f, 0x77, 0x7c, 0x39,
	0x5e, 0x79, 0x71, 0x80, 0x40, 0x08};

	unsigned int num=0, num0, num1=0, num2=0, num3=0;

	DDRC = 0xff;
	DDRG = 0x0f;

	while(1)
	{
		num++;

		num0 = num%10;

		if(num0 == 0){
			num1++;
		}
		if(num1 == 10){
			num1 = 0;
			num2++;
		}
		if(num2 == 10){
			num2 = 0;
			num3++;
		}
		if(num3 == 10){
			num3 = 0;
		}

		PORTC = FND_DATA[num3];
		PORTG = 0x08;
		_delay_ms(2);

		PORTC = FND_DATA[num2];
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
*/



#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

void main()
{
	unsigned char FND_DATA[ ]= {0x3f, 0x06, 0x5b, 0x4f, 0x66, 
	0x6d, 0x7d, 0x27, 0x7f, 0x6f, 0x77, 0x7c, 0x39,
	0x5e, 0x79, 0x71, 0x80, 0x40, 0x08};

	unsigned int num=0, num0, num1=0, num2=0, num3=0;
	unsigned int cnt = 0;

	DDRC = 0xff;
	DDRG = 0x0f;

	while(1)
	{
		cnt++;

		if(cnt == 100){
			cnt = 0;
			num++;
		}

		num0 = num%10;

		if(num0 == 0 && cnt == 0){
			num1++;
		}
		if(num1 == 6){
			num1 = 0;
			num2++;
		}
		if(num2 == 10){
			num2 = 0;
			num3++;
		}
		if(num3 == 6){
			num3 = 0;
		}

		PORTC = FND_DATA[num3];
		PORTG = 0x08;
		_delay_ms(2);

		PORTC = FND_DATA[num2] + 0x80;
		PORTG = 0x04;
		_delay_ms(3);

		if(cnt <= 25){
			PORTC = FND_DATA[num1];
			PORTG = 0x02;
			_delay_ms(2);

			PORTC = FND_DATA[num0];
			PORTG = 0x01;
			_delay_ms(3);
		}
		else if(cnt > 25 && cnt <= 50){}
		else if(cnt > 50 && cnt <= 75){
			PORTC = FND_DATA[num1];
			PORTG = 0x02;
			_delay_ms(2);

			PORTC = FND_DATA[num0];
			PORTG = 0x01;
			_delay_ms(3);
		}
		else{}
	}
}

