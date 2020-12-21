#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
  DDRB = 1<<2;
  while(1)
  {
    PINB = 1<<2;
    _delay_ms(500);
  }
}

