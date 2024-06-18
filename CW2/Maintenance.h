/************************************************************/
/* Maintenance.h                                            */
/*                                                          */
/* Maintenance                                              */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _Maintenance_h_
#define _Maintenance_h_

#include "Concurrent.h"

class Maintenance : public Concurrent
{
  public:
    void process();
    Maintenance();
  private:
    int state;
};

#endif
