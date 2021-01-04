//Grab functions
#import <Arduino.h> 
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Grab.h"

//Declare servo and linear actuator objects, you might need to use the Sevro.h library here. If you do it must go into the Scorpion_Libraries.h file, not here.
Servo linear_actuator;
Servo servo;

const int ACTUATOR_MIN = 2000;
const int ACTUATOR_MAX = 1000;
const int ACTUATOR_PICKUP = 1750;


//Add in Function Description Here
void setupGrab(){
 //Setup the servo and Linear actuator pins 
 linear_actuator.attach(LINEAR_ACTUATOR);
}

//Add in Function Description Here
void Grab(int SWITCH_C){
 //Make the servos move. Wait for Switch B on transmitter_values[5] to turn HIGH and then the servos should move
  if (SWITCH_C > 1300){

    linear_actuator.writeMicroseconds(ACTUATOR_PICKUP);
      
      
  }

  else{
    linear_actuator.writeMicroseconds(ACTUATOR_MAX);
  }
}
