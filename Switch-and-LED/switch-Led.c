#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif
#include <avr/io.h> 
#include <util/delay.h> 

int change = 1;
int main(void)
{
  DDRB = 0x30; // PB5 as OUTPUT
  DDRB = DDRB & 0xFE; // PB0 as INPUT
  while (1)
  {
    if ((PINB & 0x01) == 1) 
    {
      if(change == 1)
      {
        PORTB = 0x20;
        change = 0;
        while((PINB & 0x01) == 1);
      }
      else if(change == 0)
      {
        PORTB = 0x00;
        change = 1;
        while((PINB & 0x01) == 1);
      }
    } 
  }
} 