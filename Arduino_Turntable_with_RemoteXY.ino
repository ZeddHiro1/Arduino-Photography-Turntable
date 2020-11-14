/* Example sketch to control a stepper motor with TB6600 stepper motor driver and Arduino without a library: continuous rotation. More info: https://www.makerguides.com */
/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 2.4.3 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.5.1 or later version;
     - for iOS 1.4.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////

// RemoteXY select connection mode and include library 
//#define REMOTEXY_MODE__HC05_SOFTSERIAL 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 4
#define REMOTEXY_SERIAL_TX 5
#define REMOTEXY_SERIAL_SPEED 9600

// Define stepper motor connections:
#define dirPin 2
#define stepPin 3

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,3,0,0,0,75,0,10,28,1,
  4,128,7,63,49,7,94,26,129,0,
  26,58,9,3,24,83,112,101,101,100,
  0,2,1,7,22,46,5,1,31,31,
  31,79,78,0,79,70,70,0,2,1,
  7,44,46,5,13,31,31,31,67,67,
  87,0,67,87,0,129,0,24,37,13,
  3,24,68,105,114,101,99,116,105,111,
  110,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider_1; // =0..100 slider position 
  uint8_t on_off; // =1 if switch ON and =0 if OFF 
  uint8_t cw_ccw; // =1 if switch ON and =0 if OFF 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop)

/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

unsigned long previousMillis = 0;

byte interval = 10;

void setup() 
{
  
  RemoteXY_Init (); 
  
    // Declare pins as output:
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);

  // Set the spinning direction CW/CCW:
  //digitalWrite(dirPin, LOW);
  // TODO you setup code
  
}

void loop() 
{ 
  RemoteXY_Handler ();
  unsigned long currentMillis = millis();
  static byte toggle = 0;
  digitalWrite(dirPin, RemoteXY.cw_ccw);
  interval = 1 + 10 - RemoteXY.slider_1/10;
    
  if ( (currentMillis - previousMillis >= interval) && RemoteXY.on_off == 1)
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    // TODO you loop code
    // use the RemoteXY structure for data transfer
    // do not call delay() 
    if(toggle == 1)
    {
      digitalWrite(stepPin, LOW);
      toggle = 0;
    }
    else if(toggle == 0)
    {
      digitalWrite(stepPin, HIGH);
      toggle = 1;
    }
  }

}
