/************************************************************/
/* MotorRace.cpp                                            */
/*                                                          */
/* Motor Racing                                             */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "MotorRace.h"
#include "Switch1.h"
#include "Switch2.h"
#include "hal.h"

MotorRace::MotorRace()
{
}


void MotorRace::process(switch_state_t S1, switch_state_t S2)
{
  if (actionTask())
  {
    switch (state)
    {
      case 0:
        PORTD = B00000000; // modify for it to be more responsive = -module delay
        if (S1 == DEBOUNCED_PRESS)
        {
          state = 1;
          s1_press_count;
        }
        break;
      case 1:
        PORTD = hal_RedLed1;
        module_delay = 1000;
        if (S1 == DEBOUNCED_PRESS)
        {
          s1_press_count++;
          if (s1_press_count == 2)
          {
            state = 9;
          }
        }
        else
        {
          state = 2;
        }
        break;
      case 2:
        PORTD = hal_tl_case9;
        module_delay = 1000;
        if (S1 == DEBOUNCED_PRESS)
        {
          s1_press_count++;
          if (s1_press_count == 2)
          {
            state = 9;
          }
        }
        else
        {
          state = 3;
        }
        break;
      case 3:
        PORTD = hal_tl_case10;
        module_delay = 1000;
        if (S1 == DEBOUNCED_PRESS)
        {
          s1_press_count++;
          if (s1_press_count == 2)
          {
            state = 9;
          }
        }
        else
        {
          state = 4;
        }
        break;
      case 4:
        PORTD = hal_tl_case11;
        module_delay = 1000;
        if (S1 == DEBOUNCED_PRESS)
        {
          s1_press_count++;
          if (s1_press_count == 2)
          {
            state = 9;
          }
        }
        else
        {
          state = 5;
        }
        break;
      case 5:
        PORTD = hal_tl_case12;
        module_delay = 1000;
        if (S1 == DEBOUNCED_PRESS)
        {
          s1_press_count++;
          if (s1_press_count == 2)
          {
            state = 9;
          }
        }
        else
        {
          state = 6;
        }
        break;
      case 6:
        PORTD = B00000000;
        module_delay = 2000;
        if (S1 == DEBOUNCED_PRESS)
        {
          state = 9;
        }
        else
        {
          state = 7;
        }
        break;
      case 7:
        PORTD = hal_tl_case13;
        if (S1 == DEBOUNCED_PRESS)
        {
          state = 8;
        }
        else if (S2 == DEBOUNCED_PRESS)
        {
          state = 0;
        }
        else
        {
          state = 7;
        }
        break;
      case 8:
        PORTD = hal_tl_case5;
        if (S2 == DEBOUNCED_PRESS)
        {
          state = 0;
        }
        else
        {
          state = 8;
        }
        break;
      case 9:
        module_delay = 500;
        if (millis() % 1000 < 500)
        {
          PORTD = hal_tl_case0;
        } else
        {
          PORTD = B00000000;
        }

        if (S2 == DEBOUNCED_PRESS)
        {
          state = 0;
        }
        else
        {
          state = 9;
        }
        break;
        break;

      default:
        state = 0;
    }
  }
}
