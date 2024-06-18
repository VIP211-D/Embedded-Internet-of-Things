/************************************************************/
/* hal.h                                                    */
/*                                                          */
/* Hardware Abstraction Layer (HAL) definitions             */
/* Victoria Iza Paez/ P2655183 / 16/12/2022                 */
/************************************************************/

#ifndef _HAL_H_
#define _HAL_H_

#include <Arduino.h>
#include <Wire.h>

void function1();
void RGB_led();
void shiftingToRegister(unsigned char value);

// Type def for the switches
typedef enum
{
  NOT_PRESSED,
  PARTIAL_PRESS,
  DEBOUNCED_PRESS,
} switch_state_t;


// Define variables used for the RGB

#define TRI_RED             9
#define TRI_BLUE            10
#define TRI_GREEN           11
#define TRI_AMBER           -1

#define MAX_INTENSITY       255 //This is the maximum intensity of the RGB
#define POINTS              25 // Note that this a number chosen 
#define STEP                (250 / POINTS) // This calculation is the value of the steps the intensity is gonna use to increase or decrease
#define TIME                (1000 / POINTS) // This is the amount of time the RGB will wait to increase a STEP

// Defining traffic lights - module 1
#define hal_GreenLed1 B10000000
#define hal_GreenLed1On PORTD |= hal_GreenLed1
#define hal_GreenLed1Off PORTD &= ~hal_GreenLed1

#define hal_GreenLed2 B00010000
#define hal_GreenLed2On PORTD |= hal_GreenLed2
#define hal_GreenLed2Off PORTD &= ~hal_GreenLed2

#define hal_AmberLed2 B00001000
#define hal_AmberLed2On PORTD |= hal_AmberLed2
#define hal_AmberLed2Off PORTD &= ~hal_AmberLed2

#define hal_AmberLed1 B01000000
#define hal_AmberLed1On PORTD |= hal_AmberLed1
#define hal_AmberLed1Off PORTD &= ~hal_AmberLed1

#define hal_RedLed1 B00100000
#define hal_RedLed1On PORTD |= hal_RedLed1
#define hal_RedLed1Off PORTD &= ~hal_RedLed1

#define hal_RedLed2 B00000100
#define hal_RedLed2On PORT2 |= hal_RedLed2
#define hal_RedLed2Off PORT2 &= ~hal_RedLed2

// define the cases for the sequence of the traffic lights
#define hal_tl_case0 PORTD =  hal_AmberLed1 | hal_AmberLed2
#define hal_tl_case1 PORTD =  hal_RedLed1 | hal_RedLed2
#define hal_tl_case2 PORTD =  hal_RedLed1 | hal_RedLed2 | hal_AmberLed1
#define hal_tl_case3 PORTD =  hal_GreenLed1 | hal_RedLed2
#define hal_tl_case4 PORTD =  hal_AmberLed1 | hal_RedLed2
#define hal_tl_case5 PORTD =  hal_RedLed1 | hal_RedLed2
#define hal_tl_case6 PORTD =  hal_RedLed1 | hal_RedLed2 | hal_AmberLed2
#define hal_tl_case7 PORTD =  hal_RedLed1 | hal_GreenLed2
#define hal_tl_case8 PORTD =  hal_RedLed1 | hal_AmberLed2

// Extra cases used in other modules
#define hal_tl_case9 PORTD =  hal_RedLed1 | hal_AmberLed1
#define hal_tl_case10 PORTD =  hal_RedLed1 | hal_AmberLed1 | hal_GreenLed1
#define hal_tl_case11 PORTD =  hal_RedLed1 | hal_AmberLed1 | hal_GreenLed1 | hal_RedLed2
#define hal_tl_case12 PORTD =  hal_RedLed1 | hal_AmberLed1 | hal_GreenLed1 | hal_RedLed2 | hal_AmberLed2
#define hal_tl_case13 PORTD =  hal_GreenLed1 | hal_GreenLed2


// Defining data, clock and latch
#define hal_data B00000001
#define hal_dataH PORTB |= hal_data
#define hal_dataL PORTB &= ~hal_data

#define hal_clock B00010000
#define hal_clockH PORTB |= hal_clock
#define hal_clockL PORTB &= ~hal_clock


#define hal_latch B00100000
#define hal_latchH PORTB |= hal_latch
#define hal_latchL PORTB &= ~hal_latch


//switches
#define switch1_bit B00000001
#define switch1_pressed !(PINC & switch1_bit)
#define switch1_released !switch1_pressed

#define switch2_bit B00000010     
#define switch2_pressed !(PINC & switch2_bit)
#define switch2_released !switch2_pressed

//7 segment display
#define sega B00000001
#define segb B00000010
#define segc B00000100
#define segd B00001000
#define sege B00010000
#define segf B00100000
#define segg B01000000
#define Dot  B10000000

#define num0 (sega|segb|segc|segd|sege|segf)
#define num1 (segb|segc)
#define num2 (sega|segb|segg|segd|sege)
#define num3 (sega|segb|segg|segc|segd)
#define num4 (segf|segb|segg|segc)
#define num5 (sega|segf|segg|segc|segd)
#define num6 (sega|segf|segg|segc|segd|sege)
#define num7 (sega|segb|segc)
#define num8 (sega|segb|segc|segd|sege|segf|segg)
#define num9 (sega|segb|segc|segf|segg|sege)

#define lett (segd|sege|segc|segg)
#define letE (sega|sege|segg|segf|segd)
#define num1 (segb|segc)
#define num2 (sega|segb|segg|segd|sege)
#define letB (segc|segd|sege|segf|segg)
#define letF (sega|sege|segf|segg)

#endif
