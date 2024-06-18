/************************************************************/
/* TarfficLights.h                                          */
/*                                                          */
/* Traffic Lights                                           */
/* Victoria Iza Paez/ P2655183 / 16/12/2022                 */
/************************************************************/

#ifndef _TrafficLights_h_
#define _TrafficLights_h_

#include "Concurrent.h"

class TrafficLights : public Concurrent
{
  public:
    void process();
    TrafficLights();
  private:
    int state;
};

#endif
