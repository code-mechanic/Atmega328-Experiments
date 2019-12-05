#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif
#include <avr/io.h> 
#include <util/delay.h> 
char change = 1;
char release_check;
int main(void)
{
  DDRB = 0x30; // PB5 as OUTPUT
  DDRB = DDRB & 0xFE; // PB0 as INPUT
  while (1)
  {
    PORTB |= 0x10; 
    _delay_ms(100);
    PORTB &= 0xEF; 
    _delay_ms(100);
    if ((PINB & 0x01) == 1) 
    {
      if(change == 0xFE) // old 1
      {
        PORTB |= 0x20;
      }
      else if(change == 1) // old 0
      {
        PORTB &= 0xDF;
      }
      release_check = 1;
    }
    if ((PINB & 0x01) == 0)
    {
      if(release_check == 1)
      {
        change = ~change;
        release_check = 0;
      }
    }
  }
} 