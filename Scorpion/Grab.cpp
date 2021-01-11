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
const int ACTUATOR_PICKUP = 2000;

const int SERVO_PICKUP = 0;
const int SERVO_RETRIEVE = 70;

//Timer for Sevo and Linear actuator
int time_a = 0;


//Add in Function Description Here
void setupGrab(){
 //Setup the servo and Linear actuator pins 
 linear_actuator.attach(LINEAR_ACTUATOR);
 servo.attach(SERVO);
}

//Add in Function Description Here
void Grab(int SWITCH_C){

  //linear_actuator.writeMicroseconds(ACTUATOR_PICKUP);
  
 //Make the servos move. Wait for Switch B on transmitter_values[5] to turn HIGH and then the servos should move
 
  if (SWITCH_C > 1300 && SWITCH_C < 1700){

   time_a = millis();
   linear_actuator.writeMicroseconds(ACTUATOR_PICKUP);

   delay(2000);
   
   servo.write(SERVO_RETRIEVE);
        
  }

  else if (SWITCH_C > 1700){
   time_a = millis();
   
   servo.write(SERVO_RETRIEVE);
   linear_actuator.write(ACTUATOR_PICKUP);
  }

  else{
    linear_actuator.writeMicroseconds(ACTUATOR_MAX);
    servo.write(SERVO_PICKUP);
  }
}
