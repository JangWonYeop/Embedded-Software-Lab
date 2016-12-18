#define F_CPU 16000000 // CPU 클록 = 16 Mhz
#include <avr/io.h>
#include <util/delay.h>
int main()
{
DDRB = 0x10; // 포트 B의 bit4 를 입력 상태로 세팅
while(1)
{
PORTB = 0x10; // 1ms 동안 ‘On’ 상태 유지
_delay_ms(1);
PORTB = 0x00; // 1ms 동안 ‘Off’ 상태 유지
_delay_ms(1);
}
}
