#include "includes.h"

#define F_CPU	16000000UL	// CPU frequency = 16 Mhz
#include <avr/io.h>	
#include <util/delay.h>

#define  TASK_STK_SIZE  OS_TASK_DEF_STK_SIZE            
#define  N_TASKS        2


OS_STK       TaskStk[N_TASKS][TASK_STK_SIZE];
OS_EVENT	*Sem;


void  LedTask(void *data);
void  FndTask(void *data);


int main (void)
{
  OSInit();

  OS_ENTER_CRITICAL();
  TCCR0=0x07;  
  TIMSK=_BV(TOIE0);                  
  TCNT0=256-(CPU_CLOCK_HZ/OS_TICKS_PER_SEC/ 1024 );   
  OS_EXIT_CRITICAL();
                                   
  OSTaskCreate(LedTask, (void *)0, (void *)&TaskStk[0][TASK_STK_SIZE - 1], 0);
  OSTaskCreate(FndTask, (void *)0, (void *)&TaskStk[1][TASK_STK_SIZE - 1], 1);  

  OSStart();                         
  
  return 0;
}


void LedTask (void *data)
{
  data = data;                                   

  Sem = OSSemCreate(0);

  DDRA = 0xff;		
  while (1)  {
    PORTA = 0xaa;
    OSTimeDlyHMSM(0, 0, 0, 500);
    PORTA = 0x55;
    OSTimeDlyHMSM(0, 0, 0, 500);
	OSSemPost(Sem);
  }
}

void FndTask (void *data)
{
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
	INT8U	err;

    data = data;
	
    DDRC = 0xff;	
    DDRG = 0x0f;
	PORTC = FND_DATA[0];
	PORTG = 0x01;
	
    while(1)  {	
		OSSemPend(Sem, 0, &err);
		num++;
		num3 = (num / 1000) % 10;
		num2 = (num / 100) % 10;
		num1 = (num / 10) % 10;
		num0 = num % 10;
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