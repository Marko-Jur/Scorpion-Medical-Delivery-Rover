//Steering functions

#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"

//This is half the maximum difference between the two motor speeds (one will be -25, the other +25)
const float STEERING_RESOLUTION = 25;
const int DIRECTION = 500;

int transmitter_values[8] = {0,0,0,0,0,0,0,0}; // Values from the transmitters: Right Lateral, Right up/down, Thottle, Left lateral, switch A, switch B, Switch C, Switch D

//Add Function Description here
void motorSetup(){
  
  //Setup the motor pins in the forward direction initially
  
}

//Add Function Description here
void steering(int transmitter_values[8]){
  
  /*In this function you need to do 3 things
  * 1) Figure out which channels you need from the transmitter = Transmitter_values[0],[2],[4] -> Throttle, lateral and reverse.
    2) Map throttle from 0-1000 to 50 - 250
    3) Map lateral from 0-1000 to -STEERING_RESOLUTION, STEERING RESOLUTION
    4) Consider the reverse switch on transmitter_values[4], if the value > DIRECTION, then the motors should go forward, if the value < DIRECTION then go reverse
    5) Create an algorithm that outputs the values to the motors. If you need help check out my manual drive code here: https://github.com/Marko-Jur/Wall-E-Autonomous-Rover/blob/main/Manual_Mode/Manual_Mode.cpp
    6) Scorpion should be able to turn on the spot, eg have just one motor spinning at a time. I do this in my code if you need it.
    7) Make sure you don't write values less than 0 or greater than 250 to the motors.
  
}
