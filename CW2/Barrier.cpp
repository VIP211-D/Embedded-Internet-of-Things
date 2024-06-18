/************************************************************/
/* Barrier.cpp                                              */
/*                                                          */
/* Barrier crossing controller                              */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "Barrier.h"
#include "Switch1.h"
#include "Switch2.h"
#include "hal.h"

Barrier::Barrier()
{
}

void Barrier::process(switch_state_t S1, switch_state_t S2)
{
  // FSM used for the switch
  switch (statesw)
  {
    case 0:
      if (S1 == DEBOUNCED_PRESS)
      {
        train++;
        statesw = 1;
      }
      else if (S2 == DEBOUNCED_PRESS && train > 0)
      {
        train--;
        statesw = 1;
      }
      break;
    case 1:
      if (S1 != DEBOUNCED_PRESS  && S2 != DEBOUNCED_PRESS)
      {
        statesw = 0;
      }
      break;
  }

  if (actionTask())
  {
    switch (state)
    {
      case 0:
        PORTD = B00000000;
        if (S1 == DEBOUNCED_PRESS)
        {
          state = 1;
        }
        else 
        {
          state = 0;
        }
        break;
      case 1:
        PORTD = hal_tl_case0;
        module_delay = 5000;
        state = 2;
        break;
      case 2:
        PORTD = hal_tl_case1;
        module_delay = 500;
        state = 3;
        break;
      case 3:
        PORTD = hal_RedLed1;
        module_delay = 500;
        state = 4;
        break;
      case 4:
        PORTD = hal_RedLed2;
        module_delay = 500;
        if (train == 0)
        {
          state = 0;
        }
        else
        {
          state = 3;
        }
        break;
      default:
        state = 0;
    }
  }
}
