/************************************************************/
/* hal.cpp                                                  */
/*                                                          */
/* Hardware Abstraction Layer (HAL) implementation          */
/* Victoria Iza Paez/ P2655183 / 16/12/2022                 */
/************************************************************/

#include "hal.h"

void RGB_led()
{
  pinMode(TRI_RED, OUTPUT);
  pinMode(TRI_GREEN, OUTPUT);
  pinMode(TRI_BLUE, OUTPUT);
}

void function1()
{
  // Traffic lights module 1 implementation
  DDRD |= hal_GreenLed1 | hal_AmberLed1 | hal_RedLed1 | hal_GreenLed2 | hal_AmberLed2 | hal_RedLed2;

  // Heartbeat moodule 2 implementation
  DDRB |= hal_data | hal_clock | hal_latch;


  // Swicthes implemenation
  DDRC &= ~switch1_bit;
  PORTC |= switch1_bit;
  DDRC &= ~switch2_bit;
  PORTC |= switch2_bit;

}

// Shift to register implementation - coded here because it will be used in other files
void shiftingToRegister(unsigned char value)
{
  for (unsigned char mask = B10000000; mask != 0; mask >>= 1) // check if it works in another place
  {
    if (mask & value)
    {
      hal_dataH;
    }
    else
    {
      hal_dataL;
    }
    hal_clockH;
    hal_clockL;
  }
  hal_latchH;
  hal_latchL;
}
