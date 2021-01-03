//Contains all files for PPM receiver 
#import <Arduino.h>
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Comms.h" 


//Defining the Receiver object

//Defining the steering Resolution:
const int STEERING_RESOLUTION = 20;

//Array for values:
unsigned long int a,b,c;
int x[15],ch1[15],ch[10],i;
//Throttle - CH[4]
//Right Lateral - CH[2]
//Switch A - CH[6]
//Switch B - CH[7]
//Switch C - CH[8]

int channel_values[8] = {0,0,0,0,0,0,0,0};
int mapped_channel_values[8] = {0,0,0,0,0,0,0,0};

//Values to write to motors
int right_motor_value = 0;
int left_motor_value = 0;

/*Function: RC Setup
 *Author: Marko Jurisic
 *Input Parameters: None
 *Output Parameters: None
 *
 *Purpose: Sets up the receiver
 * 
 */
void setupRc(){

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

 //Setting up the motors
 pinMode(RCRX, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(2), read_me, FALLING);
  // enabling interrupt at pin 2

  
}

/*Function: RC Reader
 *Author: Marko Jurisic
 *Input Parameters: An array of steering values
 *Output Parameters: Modifies the input array with values from the transmitter
 *
 *Purpose: Getting values from the transmitter to steer Scorpion
 * 
 */

void rcReader(int channel_values[8]){
  read_rc();

  channel_values[0] = ch[4]; //Throttle
  channel_values[1] = ch[2]; //Right Lateral
  channel_values[2] = ch[6]; //Switch A
  channel_values[3] = ch[7]; //Switch B
  channel_values[4] = ch[8]; //Switch C

  //Uncomment to get data
  /*
  Serial.print(channel_values[0]);Serial.print("\t");
  Serial.print(channel_values[1]);Serial.print("\t");
  Serial.print(channel_values[2]);Serial.print("\t");
  Serial.print(channel_values[3]);Serial.print("\t");
  Serial.print(channel_values[4]);Serial.print("\t");
  Serial.print("\n");
  */

  delay(100);

}


void read_me()  {
 //this code reads value from RC reciever from PPM pin (Pin 2 or 3)
 //this code gives channel values from 0-1000 values
 //    -: ABHILASH :-    //
a=micros(); //store time value a when pin value falling
c=a-b;      //calculating time inbetween two peaks
b=a;//
x[i]=c;     //storing 15 value in array
i=i+1;

if(i==15){
  for(int j=0;j<15;j++){
    ch1[j]=x[j];
    delay(1);
    }
             i=0;}}//copy store all values from temporary array another array after 15 reading 

void read_rc(){
int i,j,k=0;
  for(k=14;k>-1;k--){//k = 14
    if(ch1[k]>10000){
      j=k;
      delay(1);
      }}//detecting separation space 10000us in that another array //delay
                         
  for(i=1;i<=8;i++){ //i = 6
    ch[i]=(ch1[i]);
    delay(1);
    }}
    //assign 6 channel values after separation space

/*Function: RC Reader
 *Author: Marko Jurisic
 *Input Parameters: An array of steering values
 *Output Parameters: None
 *
 *Purpose: Uses the values from the transmitter in order to steer
 * 
 */
void manualMotorController(int channel_values[]){

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
  
  
  
  
