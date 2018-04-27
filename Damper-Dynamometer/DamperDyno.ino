/*==========================================================================================
 *  Author: Bryan Lin - May 15, 2016
 *  Damper Dynamometer: Controls and Sensor Data Collection
 *  
 *  The Damper Dynamometer, Damper Dyno for short, uses pneumatic controls to send timed
 *  outputs in order to actuate a damper inside the dyno case. A load cell and linear
 *  potentiometer (LinearPot) installed inside the dyno case then measures the compression force
 *  the damper experiences and the position of the damper respectively. By measuring time and
 *  the position of the damper, a velocity is derived. The calculated velocity in inches per
 *  second and calculated load (lbs) is then sent through the serial port to be processed
 *  via Python in order to create a graph. From the graph, the damper's damping coefficients
 *  can be determined and used to tune other dampers in the racecar.
 *===========================================================================================
 *  Edited By: Brian Tang - April 10, 2017
 *  - Included a new 24bit ADC Shield for the Arduino and implemented the library that came
 *  with the shield (Ard2499).
 *  - Attempted to control the pneumatic outputs using PWM and PID control theories, ended up
 *  using timed interrupts via TimerOne library.
 */ 

/*-------------------------Libraries-------------------------*/
#include <Wire.h>               // Imports ADC Library
#include <Ard2499.h>            // Imports ADC Library
Ard2499 ard2499board1;          // Initializes ADC board
#include <TimerOne.h>           // Imports Timed Interrupts Library (compatible with Arduino Uno and Mega)
/*-----------------Class Constants and Fields-----------------*/
const float LinearPot = A1;        // LinPot ADC Channel 3
const float LoadCell = A3;         // Load Cell Pin
const int   Button = 2;            // Button pin
const float LinearPotActuation = 4.000; // measured in inches
const float NumDivisions = 1024.0; // Onboard 10-bit ADC
const float PositionConversion = LinearPotActuation/NumDivisions;
float t1;                          // time counter #1
float t2;                          // time counter #2
float p1;                          // position counter #1
float p2;                          // position counter #2
volatile int cycleCount = -1;      // counts number of cycles performed
const int compressionPin = 10;
volatile int cState = LOW;        // state of compression *cannot be initialize to have the same status as rebound*
const int reboundPin = 9;
volatile int rState = HIGH;
