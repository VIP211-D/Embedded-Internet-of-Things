
/************************************************************/
/* Main Code                                                */
/*                                                          */
/* Summative Assignement 2                                  */
/* Victoria Iza Paez/ P2655183 / 21-04-2023                 */
/************************************************************/

#include "hal.h"
#include "Concurrent.h"
#include "TrafficLights.h"
#include "TLset1.h"
#include "TLset2.h"
#include "Maintenance.h"
#include "Barrier.h"
#include "MotorRace.h"
#include "Switch1.h"
#include "Switch2.h"
#include "Heartbeat.h"
#include "RGB.h"
#include <Wire.h>

TrafficLights         TrafficLights_Control;
TLset1                TLset1_Control;
TLset2                TLset2_Control;
Maintenance           Maintenance_Control;
switch_state_t        S1;
switch_state_t        S2;
Barrier               Barrier_Control;
Switch1               Switch1_Control;
Switch2               Switch2_Control;
MotorRace             MotorRace_Control;
Heartbeat             Heartbeat_Control;
RGB                   RGBledControl;

byte                  cmd_modules, cmd_rgb;

void RGBmodule()
{
  switch (cmd_rgb)
  {
    case 0x67:
      RGBledControl.setRunning(false); // Tri-coloured LED to be off.
      digitalWrite(TRI_BLUE, LOW);
      digitalWrite(TRI_GREEN, LOW);
      digitalWrite(TRI_RED, LOW);
      break;
    case 0x68:
      RGBledControl.setRunning(true); // Tri-coloured LED to varying intensities of amber (Hazard).
      RGBledControl.led = TRI_AMBER;
      digitalWrite(TRI_BLUE, LOW);
      break;
    case 0x69:
      RGBledControl.setRunning(true); // Tri-coloured LED to varying intensities of blue (Emergency).
      RGBledControl.led = TRI_BLUE;
      digitalWrite(TRI_GREEN, LOW);
      digitalWrite(TRI_RED, LOW);
      break;
    case 0x6A:
      RGBledControl.setRunning(true); // Tri-coloured LED to varying intensities of green (Doctor).
      RGBledControl.led = TRI_GREEN;
      digitalWrite(TRI_BLUE, LOW);
      digitalWrite(TRI_RED, LOW);
      break;
    case 0x6B:
      RGBledControl.setRunning(true); // Set Tri-coloured LED to varying intensities of red (Police Stopped).
      RGBledControl.led = TRI_RED;
      digitalWrite(TRI_BLUE, LOW);
      digitalWrite(TRI_GREEN, LOW);
      break;
  }
}

void LightsModule()
{
  switch (cmd_modules)
  {
    case 0x61:
      RGBledControl.setRunning(true);
      TrafficLights_Control.setRunning(true);
      TLset1_Control.setRunning(false);
      TLset2_Control.setRunning(false);
      Maintenance_Control.setRunning(false);
      Barrier_Control.setRunning(false);
      MotorRace_Control.setRunning(false);
      break;
    case 0x62:
      RGBledControl.setRunning(true);
      TrafficLights_Control.setRunning(false);
      TLset1_Control.setRunning(true);
      TLset2_Control.setRunning(false);
      Maintenance_Control.setRunning(false);
      Barrier_Control.setRunning(false);
      MotorRace_Control.setRunning(false);
      break;
    case 0x63:
      RGBledControl.setRunning(true);
      TrafficLights_Control.setRunning(false);
      TLset1_Control.setRunning(false);
      TLset2_Control.setRunning(true);
      Maintenance_Control.setRunning(false);
      Barrier_Control.setRunning(false);
      MotorRace_Control.setRunning(false);
      break;
    case 0x64:
      RGBledControl.setRunning(true);
      TrafficLights_Control.setRunning(false);
      TLset1_Control.setRunning(false);
      TLset2_Control.setRunning(false);
      Maintenance_Control.setRunning(true);
      Barrier_Control.setRunning(false);
      MotorRace_Control.setRunning(false);
      break;
    case 0x65: // for the barrier crossing
      RGBledControl.setRunning(true);
      TrafficLights_Control.setRunning(false);
      TLset1_Control.setRunning(false);
      TLset2_Control.setRunning(false);
      Maintenance_Control.setRunning(false);
      Barrier_Control.setRunning(true);
      MotorRace_Control.setRunning(false);
      break;
    case 0x66: // motor racing start lights
      RGBledControl.setRunning(true);
      TrafficLights_Control.setRunning(false);
      TLset1_Control.setRunning(false);
      TLset2_Control.setRunning(false);
      Maintenance_Control.setRunning(false);
      Barrier_Control.setRunning(false);
      MotorRace_Control.setRunning(true);
      break;
  }
}


void setup()
{
  function1();
  RGB_led();
  RGBledControl.setRunning(false);
  TrafficLights_Control.setRunning(false);
  TLset1_Control.setRunning(false);
  TLset1_Control.setRunning(false);
  Maintenance_Control.setRunning(false);
  Barrier_Control.setRunning(false);
  MotorRace_Control.setRunning(false);
  Switch1_Control.setRunning(true);
  Switch2_Control.setRunning(true);
  Heartbeat_Control.setRunning(true);

  Wire.begin(8); /* join i2c bus with address 8 */
  Wire.onReceive(receiveEvent); /* register receive event */
  Serial.begin(9600); /* start serial for debug */
}

void loop()
{
  TrafficLights_Control.process();
  TLset1_Control.process();
  TLset2_Control.process();
  Maintenance_Control.process();
  S1 = Switch1_Control.process();
  S2 = Switch2_Control.process();
  Barrier_Control.process(S1, S2);
  MotorRace_Control.process(S1, S2);
  Heartbeat_Control.process();
  RGBledControl.process();
  RGBmodule();
  LightsModule();
}

void receiveEvent(int howMany)
{
  while (0 < Wire.available())
  {
    char c = Wire.read(); /* receive byte as a character */

    switch (c)
    {
      case 0x61:
      case 0x62:
      case 0x63:
      case 0x64:
      case 0x65:
      case 0x66:
        cmd_modules = c;
        break;
      case 0x67:
      case 0x68:
      case 0x69:
      case 0x6A:
      case 0x6B:
        cmd_rgb = c;
        break;
    }
    Serial.println(); /* to newline */
  }
}
