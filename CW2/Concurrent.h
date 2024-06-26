/************************************************************/
/* Councurrent.h                                            */
/*                                                          */
/* Formative Assignment 2                                   */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#ifndef _Concurrent_h_
#define _Concurrent_h_


//------------------------------------------------------------------------------
// Public functions:
//   getModuleDelay() - retrieves the module delay (interval between
//                      performing tasks.)
//   setModuleDelay() - sets the module delay
//   startRunning()   - starts the timing: the module is running
//   stopRunning()    - stops any timing: the module is held/stopped
//   setRunning()     - uses a Boolean to start (true) or stop (false) running
//   actionTask()     - performs the timing.
//                      Returns true if it is time to perform its task
//                      Returns false if it not time to perform its task
//-----------------------------------------------------------------------------

class Concurrent {
  public:
    bool             actionTask();
    bool             init_module2;
    void             setModuleDelay(unsigned long mod_delay);
    void             getModuleDelay();
    void             startRunning();
    void             stopRunning();
    void             setRunning(bool start);

    Concurrent();

  protected:
    unsigned long    module_time;          // Reference time
    unsigned long    module_delay;         // Required delay.
    bool             module_doStep;        // Indicates whether a task can be run
    bool             Run;            // Indicates whether the timing is
    // running or held.
};

#endif
