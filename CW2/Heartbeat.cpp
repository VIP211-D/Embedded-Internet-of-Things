/************************************************************/
/* Heartbeat.cpp                                            */
/*                                                          */
/* Heartbeat                                                */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "Heartbeat.h"
#include "hal.h"

Heartbeat::Heartbeat()
{
  Run = false;
  state = 0;
  module_delay = 10;
}

byte Heartbeat::process()
{
  if (actionTask())
  {
    switch (state)
    {
      case 0:
        hb = B10000000;
        module_delay = 270;
        state = 1;
        break;
      case 1:
        hb = B0000000;
        module_delay = 270;
        state = 0;
        break;
      default:
        state = 0;
    }
  }
  return hb;
}
