
//Steering functions
#import <Arduino.h> 
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"


//Defining the steering Resolution: //This is half the maximum difference between the two motor speeds (one will be -25, the other +25)
const int STEERING_RESOLUTION = 50;

int channel_values[8] = {0,0,0,0,0,0,0,0};
int mapped_channel_values[8] = {0,0,0,0,0,0,0,0};

//Values to write to motors
int right_motor_value = 0;
int left_motor_value = 0;


int transmitter_values[8] = {0,0,0,0,0,0,0,0}; // Values from the transmitters: Right Lateral, Right up/down, Thottle, Left lateral, switch A, switch B, Switch C, Switch D

/*Function: Motor Setup
 *Author: Marko Jurisic
 *Input Parameters: None
 *Output Parameters: None
 *
 *Purpose: Sets up the motor directions
 * 
 */
void motorSetup(){
  
  //Setup the motor pins in the forward direction initial
  //Setup the motors
  pinMode(RIGHT_MOTOR_A, OUTPUT);
  pinMode(RIGHT_MOTOR_B, OUTPUT);
  pinMode(RIGHT_MOTOR_ENABLE, OUTPUT);
  
  pinMode(LEFT_MOTOR_A, OUTPUT);
  pinMode(LEFT_MOTOR_B, OUTPUT);
  pinMode(LEFT_MOTOR_ENABLE, OUTPUT);

 
  //Setup Motor Directions:
  digitalWrite(RIGHT_MOTOR_A,HIGH);
  digitalWrite(RIGHT_MOTOR_B,LOW);

  digitalWrite(LEFT_MOTOR_A,HIGH);
  digitalWrite(LEFT_MOTOR_B,LOW);
  
}

/*Function: Steering
 *Author: Marko Jurisic
 *Input Parameters: An array of steering values
 *Output Parameters: None
 *
 *Purpose: Uses the values from the transmitter in order to steer
 * 
 */
void steering(int channel_values[8]){
  
  //Mapping Channel Values
  mapped_channel_values[2] = map(channel_values[0],1000,2003,0,250); //Throttle
  mapped_channel_values[0] = map(channel_values[1],1000,2003,-STEERING_RESOLUTION,STEERING_RESOLUTION); //LRight Lateral

  //Value written to motors:
  
  right_motor_value = mapped_channel_values[2] + mapped_channel_values[0];
  left_motor_value = mapped_channel_values[2] - mapped_channel_values[0];
 

  
  //Allowing Scorpion to turn in place, if throttle is equal to zero we can still write values to the left and right motrs individually
  if (mapped_channel_values[2] == 0 && mapped_channel_values[0] > 3){ //Put greater than 3 just to make sure it's always 0, the transmitter might slightly shift to read 0 as 1 so put 3 to make sure it doesn't turn when the right stick is at 0
    right_motor_value +=150;
    left_motor_value = 0;
    analogWrite(RIGHT_MOTOR_ENABLE,right_motor_value);
  }
  else if (mapped_channel_values[2] == 0 && mapped_channel_values[0] < -3){ //Put greater than 3 just to make sure it's always 0, the transmitter might slightly shift to read 0 as 1 so put 3 to make sure it doesn't turn when the right stick is at 0
    left_motor_value = abs(left_motor_value) + 150;
    right_motor_value = 0;
    analogWrite(RIGHT_MOTOR_ENABLE,left_motor_value);
  }

  //Making sure values are always within motor range:
  else if (right_motor_value > 255){
    right_motor_value = 255; //If the right motor is 255, then we have to minus an extra 20 from the left motor to maintain a constant reoslution of steering
    left_motor_value -= STEERING_RESOLUTION;
  }
  else if (left_motor_value > 255){
    left_motor_value = 255;
    right_motor_value -=STEERING_RESOLUTION;
  }
  else if (right_motor_value < 0){
    right_motor_value = 0;
  }
  else if (left_motor_value < 0){
    left_motor_value = 0;
  }
 
  analogWrite(RIGHT_MOTOR_ENABLE,left_motor_value);
  analogWrite(LEFT_MOTOR_ENABLE,right_motor_value);

//Uncomment to get the values

  
  Serial.print(right_motor_value);Serial.print("\t");
  Serial.print(left_motor_value);Serial.print("\n");
}
