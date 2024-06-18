/************************************************************/
/* MotorRace.h                                              */
/*                                                          */
/* Motor Racing                                             */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _MotorRace_h_
#define _MotorRace_h_

#include "Concurrent.h"
#include "Switch1.h"
#include "Switch2.h"

class MotorRace : public Concurrent
{
  public:
    void process(switch_state_t S1, switch_state_t S2);
    MotorRace();
  private:
    int state;
    int s1_press_count = 0;
};

#endif
