/************************************************************/
/* Maintenance.cpp                                          */
/*                                                          */
/* Maintenance                                              */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "Maintenance.h"
#include "hal.h"

Maintenance::Maintenance()
{
}

  void Maintenance::process()
{
  if (actionTask())
  {
    switch (state)
    {
      case 0:
        PORTD = hal_tl_case0;
        module_delay = 500;
        state = 1;
        break;
      case 1:
        PORTD = B00000000;
        module_delay = 500;
        state = 0;
        break;
      default:
        state = 0;
    }
  }
}
