//Contains all functions for Scorpion laser
#import <Arduino.h>
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"

//Add function description here
void setupLaser(){
  
  pinMode(LASER_A, OUTPUT);
  
}

//Add function description here
void laserControl(int switch_d){
  if(switch_d > 1500){
    digitalWrite(LASER_A, HIGH);
    Serial.println("Hi");
  }
  else
    digitalWrite(LASER_A, LOW);
  
}
