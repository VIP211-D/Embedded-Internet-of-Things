/************************************************************/
/* TLset2.h                                                 */
/*                                                          */
/* Set 2 priority                                           */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _TLset2_h_
#define _TLset2_h_

#include "Concurrent.h"

class TLset2 : public Concurrent
{
  public:
    void process();
    TLset2();
  private:
    int state;
};

#endif
