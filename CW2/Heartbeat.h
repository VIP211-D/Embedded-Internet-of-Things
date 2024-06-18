/************************************************************/
/* Haertbeat.h                                              */
/*                                                          */
/* Heartbeat                                                */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _Heartbeat_h_
#define _Heartbeat_h_

#include "Concurrent.h"
#include <Arduino.h>

class Heartbeat : public Concurrent
{
  public:
    byte process();
    Heartbeat();
    getDot_seg();
  private:
    int state;
    byte hb;
};

#endif
