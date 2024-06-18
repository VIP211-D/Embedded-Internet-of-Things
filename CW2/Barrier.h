/************************************************************/
/* Barrier.h                                                */
/*                                                          */
/* Barrier crossing controller                              */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _Barrier_h_
#define _Barrier_h_
#include "Switch1.h"
#include "Switch2.h"
#include "Concurrent.h"

class Barrier : public Concurrent
{
  public:
    Barrier();
    void process(switch_state_t S1, switch_state_t S2);
  private:
    int state;
    int train = 0;
    int cmd = 0;
    int statesw;
};

#endif
