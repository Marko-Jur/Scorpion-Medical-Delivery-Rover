//Contains all functions for Scorpion laser

#import <Arduino.h> 
#include <Pin_Assignments.h>
#include <Scorpion_Libraries.h>
#include <Lasers.h>


//Set up pin locations for 2 lasers
void setupLasers(){
  pinMode(LASER_A, OUTPUT);
  pinMode(LASER_B, OUTPUT);
}

//Switching 2 lasers ON/OFF simultaneously with input from transmitter
void loop() {
  
void laserControl(int SWITCH_D){
  if (SWITCH_D > 1500){
    digitalWrite(LASER_A, HIGH);
    digitalWrite(LASER_B, HIGH);
  }
  else{
    digitalWrite(LASER_A, LOW);
    digitalWrite(LASER_B, LOW);
  }  
}
