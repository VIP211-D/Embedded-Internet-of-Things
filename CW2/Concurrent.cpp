/************************************************************/
/* Concurrent.cpp                                           */
/*                                                          */
/* Formative Assignment 2                                   */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "Concurrent.h"
#include <Arduino.h>

//--------------------------------------------------------------
// Constructor
// Puts class into a sane state whenever an instance of the
// class is declared.
//--------------------------------------------------------------

Concurrent::Concurrent()
{
  Run = false;
  module_delay = 1000;
  module_time = millis();
}

//--------------------------------------------------------------
// setModuleDelay
// Accessor function to set the module delay
//--------------------------------------------------------------

void Concurrent::setModuleDelay(unsigned long mod_delay)
{
  module_delay = mod_delay;
}


//--------------------------------------------------------------
// getModuleDelay
// Accessor function to retrieve the module delay
//--------------------------------------------------------------

void Concurrent::getModuleDelay()
{
  return module_delay;
}

//--------------------------------------------------------------
// startRunning
// Accessor function to set the timing running......
//--------------------------------------------------------------

void Concurrent::startRunning()
{
  Run = true;
}


//--------------------------------------------------------------
// stopRunning
// Accessor function to stop the timing running.
//--------------------------------------------------------------

void Concurrent::stopRunning()
{
  Run = false;
}


//--------------------------------------------------------------
// setRunning()
// Takes a boolean parameter: start
// Accessor function to start (true) or stop (false) the timing
// running.
//--------------------------------------------------------------

void Concurrent::setRunning(bool start)
{
  Run = start;
}


//--------------------------------------------------------------
// actionTask
// Function to perform the timing.
// This function will return true if the required time interval
// has expired. It will return false if either the module is
// not running, or whether the required interval has not
// expired.
//--------------------------------------------------------------

bool Concurrent::actionTask()
{
  if (Run == false)
  {
    // The timer is not running. Nothing really to do
    module_time = millis();
    module_doStep = false;
  }
  else
  {
    // Performing the timing.
    unsigned long m = millis();
    if (((long)(m - module_time)) > module_delay)
    {
      // Timeout has elapsed. Give indication that this
      // module can perform its task.
      module_time = m;
      module_doStep = true;
    }
    else
    {
      module_doStep = false;
    }
  }

  return module_doStep;
}
