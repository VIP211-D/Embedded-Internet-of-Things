/************************************************************/
/* RGB.h                                                    */
/*                                                          */
/* RGB LED code                                             */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _RGB_h_
#define _RGB_h_

#include "Concurrent.h"
#include "hal.h"

class RGB: public Concurrent
{
  public:
    void process();
    RGB();
    int led;
  private:
    int intensity;
    int dirn;
};

#endif
