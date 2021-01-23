//Contains all functions for Scorpion laser

#import <Arduino.h> 
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Lasers.h"

//Function declarations:
/*
void setupLasers();
void laserControl(int SWITCH_B);
*/


//Add function description here
void setuplasers(){
  
  //Do stuff
  pinMode(LASER_A, OUTPUT); //Look at Blinky example. //DON'T USE A NUMBER FOR THE PIN, USE LASER_A.
  pinMode(LASER_B, OUTPUT);
  
}

//Add function description here
void laserControl(int SWITCH_B){
  
  if (SWITCH_B > 1500){
    digitalWrite(LASER_A, HIGH);
    digitalWrite(LASER_B, HIGH);
  }
  else{
    digitalWrite(LASER_A, LOW);
    digitalWrite(LASER_B, LOW);
  }
  
  
}
