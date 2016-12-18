#define F_CPU	16000000UL	// CPU frequency = 16 Mhz
#include <avr/io.h>	
#include <util/delay.h>

#define	NO_1

#define	LEFT	0
#define	RIGHT	1

#define	INCREASE	0
#define	DECREASE	1


int main(void)
{					

	DDRA = 0xff;


#ifdef NO_1
	unsigned char value = 0;
	while (1)  {
		PORTA = value;
		value = (value+1) % 256;
		_delay_ms(100);
	}
#endif


#ifdef NO_2
	unsigned char value = 0x80;
	while (1)  {
		PORTA = value;
		value >>= 1;
		if (value == 0)
			value = 0x80;
		_delay_ms(100);
	}
#endif


#ifdef NO_3
	int	direction = LEFT;
	unsigned char value = 0x01;
	while (1)  {
		if (direction == LEFT)  {
			if (value == 0x80)	{
	        	value = 0x40;
	        	direction = RIGHT;
			}
			else  {
				value <<= 1;
			}
		}
    	else if (direction == RIGHT)  {
			if (value == 0x01)  {
        		value = 0x02;
        		direction = LEFT;
    		}
    		else  {
        		value >>=1;
			}
		}
    	PORTA = value;
		_delay_ms(100);
	}
#endif


#ifdef NO_4
	int	direction = INCREASE;
	unsigned char value = 1;
	while (1)  {
		if (direction == INCREASE)  {
			if (value == 255)	{
	        	value = 127;
	        	direction = DECREASE;
			}
			else  {
				value = value*2 + 1;
			}
		}
    	else if (direction == DECREASE)  {
			if (value == 0)  {
        		value = 1;
        		direction = INCREASE;
    		}
    		else  {
        		value = value/2;
			}
		}
    	PORTA = value;
		_delay_ms(100);
	}
#endif

#ifdef NO_5
	unsigned int a = 17, b = 49, c = 103;
	unsigned char value;
	while (1)  {
		value = (a++) * (b++) + (c++);
    	PORTA = value;
		_delay_ms(100);
	}
#endif
}
