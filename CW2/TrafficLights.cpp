/************************************************************/
/* TrafficLights.cpp                                        */
/*                                                          */
/* Traffic Lights                                           */
/* Victoria Iza Paez/ P2655183 / 16/12/2022                 */
/************************************************************/

#include "TrafficLights.h"
#include "hal.h"

TrafficLights::TrafficLights()
{
}

void TrafficLights::process()
{
  if (actionTask())
  {
    switch (state)
    {
      case 0:
        PORTD = hal_tl_case0;
        module_delay = 2000;
        state = 1;
        break;
      case 1:
        PORTD = hal_tl_case1;
        module_delay = 1000;
        state = 2;
        Serial.print("Set 1 active\n");
        break;
      case 2:
        PORTD = hal_tl_case2;
        module_delay = 1000;
        state = 3;
        Serial.print("Set 1 active\n");
        break;
      case 3:
        PORTD = hal_tl_case3;
        module_delay = 6000;
        state = 4;
        Serial.print("Set 1 active\n");
        break;
      case 4:
        PORTD = hal_tl_case4;
        module_delay = 1000;
        state = 5;
        Serial.print("Set 1 active\n");
        break;
      case 5:
        PORTD = hal_tl_case5;
        module_delay = 1000;
        state = 6;
        Serial.print("Set 2 active\n");
        break;
      case 6:
        PORTD = hal_tl_case6;
        module_delay = 1000;
        state = 7;
        Serial.print("Set 2 active\n");
        break;
      case 7:
        PORTD = hal_tl_case7;
        module_delay = 6000;
        state = 8;
        Serial.print("Set 2 active\n");
        break;
      case 8:
        PORTD = hal_tl_case8;
        module_delay = 1000;
        state = 1;
        Serial.print("Set 2 active\n");
        break;
      default:
        state = 0;
    }
  }
}
