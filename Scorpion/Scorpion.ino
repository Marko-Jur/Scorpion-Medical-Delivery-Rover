//Main controller for Scorpion
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Grab.h"
#include "Comms.h"
#include "Fpv.h"
#include "Lasers.h"

int raw_rc_values[8] = {0,0,0,0,0,0,0,0}; // This is the array you need to pass into the readRc function.

//Add in Function Description Here
void setup(){

  //Start the serial monitor
  Serial.begin(9600);

  //Setup your motor directions and the Receiver
  setupRc();
    
    

}

//Add in Function Description Here
void loop(){

  //Find the values in the receiver, and write them into the raw rc values array:
  rcReader(raw_rc_values);

  //Send these values to the motors
  manualMotorController(raw_rc_values);
    
}
