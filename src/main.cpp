/*


*/

#define F_CPU 9600000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart_intr.h"

UART uart;

//===================================================
int main(void)
{
  uart.begin();
  _delay_ms(10);
  uart.println();

  adc_ini();
  for (uint8_t i = 0; i < 3;++i)
  {
    median(adc_read());
  }

  //===================================================
  while (1)
  {
    uint16_t v = (median(adc_read()) * 16 + 120) / 100;
    uart.print(v);
    uart.println();
    _delay_ms(1000);
  }
}

//===================================================