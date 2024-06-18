/************************************************************/
/* RGB.cpp                                                  */
/*                                                          */
/* RGB LED code                                             */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "RGB.h"
#include "Concurrent.h"
#include "hal.h"

RGB::RGB()
{
  intensity = 5;
  led = TRI_GREEN;
  dirn = 1;
  module_delay = TIME;
}

void RGB::process()
{
  if (actionTask())
  {
    intensity = intensity + (dirn * STEP);
    if (intensity <= 0 || intensity >= 255)
    {
      dirn = -dirn;
    }
    else
    {
      if (led == TRI_AMBER)
      {
        analogWrite(TRI_RED, intensity);
        analogWrite(TRI_GREEN, intensity / 3);
      }
      else
      {
        analogWrite(led, intensity);
      }
    }
  }
}
