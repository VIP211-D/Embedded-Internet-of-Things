/************************************************************/
/* Switch2.cpp                                              */
/*                                                          */
/* Switch2                                                  */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "Switch2.h"
#include "hal.h"

Switch2::Switch2()
{
  Run = false;
  module_delay = 10;
  state = 0;
}

switch_state_t Switch2::process()
{
  if (actionTask())
  {
    switch (state)
    {
      case NOT_PRESSED:
        if (switch2_released) state = NOT_PRESSED;
        else {
          debounce_count = module_time;
          state = PARTIAL_PRESS;
        }
        break;

      case PARTIAL_PRESS:
        if (switch2_released) state = NOT_PRESSED;
        else if ((module_time - debounce_count) < debounce) state = PARTIAL_PRESS;
        else state = DEBOUNCED_PRESS;
        break;

      case DEBOUNCED_PRESS:
        if (switch2_released) state = NOT_PRESSED;
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
