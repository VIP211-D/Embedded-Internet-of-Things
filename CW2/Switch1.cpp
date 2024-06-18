/************************************************************/
/* Switch1.cpp                                              */
/*                                                          */
/* Switch1                                                  */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */  
/************************************************************/

#include "Switch1.h"
#include "hal.h"

Switch1::Switch1()
{
  Run = false;
  module_delay = 10;
  state = 0;
}

switch_state_t Switch1::process()
{
  if (actionTask())
  {
    switch (state)
    {
      case NOT_PRESSED:
        if (switch1_released) state = NOT_PRESSED;
        else {
          debounce_count = module_time;
          state = PARTIAL_PRESS;
        }
        break;

      case PARTIAL_PRESS:
        if (switch1_released) state = NOT_PRESSED;
        else if ((module_time - debounce_count) < debounce) state = PARTIAL_PRESS;
        else state = DEBOUNCED_PRESS;
        break;

      case DEBOUNCED_PRESS:
        if (switch1_released) state = NOT_PRESSED;
        else state = DEBOUNCED_PRESS;
        break;

      default:
        state = NOT_PRESSED;
        break;
    }
    state;
  }
  return state;
}
