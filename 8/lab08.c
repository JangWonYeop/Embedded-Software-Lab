#define F_CPU 16000000 // CPU Ŭ�� = 16 Mhz
#include <avr/io.h>
#include <util/delay.h>
int main()
{
DDRB = 0x10; // ��Ʈ B�� bit4 �� �Է� ���·� ����
while(1)
{
PORTB = 0x10; // 1ms ���� ��On�� ���� ����
_delay_ms(1);
PORTB = 0x00; // 1ms ���� ��Off�� ���� ����
_delay_ms(1);
}
}
