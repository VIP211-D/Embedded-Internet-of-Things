/************************************************************/
/* TLset1.h                                                 */
/*                                                          */
/*Set 1 priority                                            */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _TLset1_h_
#define _TLset1_h_

#include "Concurrent.h"

class TLset1 : public Concurrent
{
  public:
    void process();
    TLset1();
  private:
    int state;
};

#endif
