//Main controller for Scorpion
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Grab.h"
#include "Comms.h"
#include "Fpv.h"
#include "Lasers.h"
#include "Steering.h"

int raw_rc_values[9] = {0,0,0,0,0,0,0,0,0}; // This is the array you need to pass into the readRc function.

//Add in Function Description Here
void setup(){

  //Start the serial monitor
  Serial.begin(9600);

  //Setup the Receiver
  setupRc();

  //Setup the motor directions
  motorSetup();
    
    

}

//Add in Function Description Here
void loop(){

  //Find the values in the receiver, and write them into the raw rc values array:
  rcReader(raw_rc_values);

  //Send these values to the motors
  steering(raw_rc_values);

  //Call Grab and pass in Switch B, a high Switch B initiates a Grab.
  Grab(raw_rc_values[7]);

  //Call FPV and pass in Switch C, a high Switch C turns on the FPV
  fpvControl(raw_rc_values[8]);
  
    
}
