/************************************************************/
/* Switch2.h                                                */
/*                                                          */
/* Switch2                                                  */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _Switch2_h_
#define _Switch2_h_

#include "Concurrent.h"
#include "hal.h"


class Switch2 : public Concurrent
{
  public:
    switch_state_t process();
    Switch2();
  private:
    int state;
    int debounce_count;
    int debounce = 300;
};

#endif
