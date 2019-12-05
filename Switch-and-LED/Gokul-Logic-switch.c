#ifndef F_CPU
#define F_CPU 16000000UL // 16 MHz clock speed
#endif
#include <avr/io.h> 
#include <util/delay.h> 

#define LED1_ON (PORTB |= 1<<5 )
#define LED1_OFF (PORTB &= ~(1<<5) )
#define LED1_TOGGLE (PORTB ^= 1<<5 )

#define LED2_ON (PORTB |= 1<<4 )
#define LED2_OFF (PORTB &= ~(1<<4) )
#define LED2_TOGGLE (PORTB ^= 1<<4 )

#define BUTTON1 (PINB & 0x01)

char led1_lastState = 0;
int led2_delay = 200; //ms
long int led2_timestamp = 0; 
long int systemTimer = 0;

int main(void)
{
  DDRB = 0x30; // PB5 as OUTPUT
  DDRB = DDRB & 0xFE; // PB0 as INPUT
  while (1)
  {
    if(BUTTON1 != led1_lastState)
    {
      led1_lastState = BUTTON1;
      if(BUTTON1 ==  1)
      LED1_TOGGLE;
    }
    if( ((systemTimer - led2_timestamp) >= led2_delay/2))
    {
      led2_timestamp = systemTimer;
      LED2_TOGGLE;
    }
    systemTimer++;
    //  LED2_TOGGLE;
    _delay_ms(1);
  }
} 