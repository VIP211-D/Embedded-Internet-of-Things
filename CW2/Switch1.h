/************************************************************/
/* Switch1.h                                                */
/*                                                          */
/* Switch1                                                  */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _Switch1_h_
#define _Switch1_h_

#include "Concurrent.h"
#include "hal.h"


class Switch1 : public Concurrent
{
  public:
    switch_state_t process();
    Switch1();
  private:
    int state;
    int debounce_count;
    int debounce = 300;
};

#endif
