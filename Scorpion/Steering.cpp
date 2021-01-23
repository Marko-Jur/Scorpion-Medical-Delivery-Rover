//Steering functions

#include "Arduino.h"
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"

//This is half the maximum difference between the two motor speeds (one will be -25, the other +25)
const float STEERING_RESOLUTION = 25;
const int DIRECTION = 500;
const int TURNING_SENSITIVITY = 3;

int transmitter_values[8] = { 0,0,0,0,0,0,0,0 }; // Values from the transmitters: Right Lateral, Right up/down, Thottle, Left lateral, switch A, switch B, Switch C, Switch D

//Add Function Description here

/* Function: motorSetup
*  Input Parameters: None
*  Output Parameters: None
*  Purpose: Intialize motor pins
*/

void motorSetup() {

	//Setup the motor pins in the forward direction initial
	pinMode(MOTOR_RIGHT_A, OUTPUT);
	pinMode(MOTOR_RIGHT_B, OUTPUT);
	pinMode(MOTOR_RIGHT_ENABLE, OUTPUT);
	pinMode(MOTOR_LEFT_A, OUTPUT);
	pinMode(MOTOR_LEFT_B, OUTPUT);
	pinMode(MOTOR_LEFT_ENABLE, OUTPUT);


	digitalWrite(MOTOR_RIGHT_A, HIGH);
	digitalWrite(MOTOR_RIGHT_B, LOW);

	digitalWrite(MOTOR_LEFT_A, HIGH);
	digitalWrite(MOTOR_LEFT_B, LOW);
}

/* Function: steering
*  Input Parameters: Transmitter values as an array of integers
*  Output Parameters: None
*  Purpose: Use transmitter values to send data motor driver and control steering
*/

void steering(int transmitter_values[8]) {
	int left_motor_speed = 0;
	int right_motor_speed = 0;


	int mapped_values[8] = { 0,0,0,0,0,0,0,0 };

	// Map throttle 0-1000 to 50 - 250
	mapped_values[0] = map(transmitter_values[0], 0, 1000, 50, 250);

	//Map lateral from 0-1000 to -STEERING_RESOLUTION, STEERING RESOLUTION
	mapped_values[2] = map(transmitter_values[2], 0, 1000, -STEERING_RESOLUTION, STEERING_RESOLUTION);

	right_motor_speed = mapped_values[2] + mapped_values[0];
	left_motor_speed = mapped_values[2] - mapped_values[0];


	if (transmitter_values[4] > DIRECTION) { // go forward direction

		//right motor
		digitalWrite(MOTOR_RIGHT_A, HIGH);
		digitalWrite(MOTOR_RIGHT_B, LOW);

		//left motor
		digitalWrite(MOTOR_LEFT_A, HIGH);
		digitalWrite(MOTOR_LEFT_B, LOW);

	}
	else if (transmitter_values[4] < DIRECTION) // go reverse direction
	{
		//right motor
		digitalWrite(MOTOR_RIGHT_A, LOW);
		digitalWrite(MOTOR_RIGHT_B, HIGH);

		//left motor
		digitalWrite(MOTOR_LEFT_A, LOW);
		digitalWrite(MOTOR_LEFT_B, HIGH);
	}



	if(mapped_values[2] == 0 && mapped_values[0] > TURNING_SENSITIVITY)//turn right without moving forward
	{
		right_motor_speed += 150;
		left_motor_speed = 0;
	}
	else if (mapped_values[2] == 0 && mapped_values[0] > -TURNING_SENSITIVITY) { //turn left without moving forward

		right_motor_speed = 0;
		left_motor_speed += 150;


	}//constrain motor speed to correct range
	else if (right_motor_speed > 250) {
		
		right_motor_speed = 250;
		left_motor_speed -= STEERING_RESOLUTION;

	}
	else if (left_motor_speed > 250) {

		right_motor_speed -= STEERING_RESOLUTION;
		left_motor_speed = 250;

	}
	else if (right_motor_speed < 0) {
		right_motor_speed = 0;
	}
	else if (left_motor_speed < 0) {
		left_motor_speed = 0;
	}

	//write motor speeds to driver
	analogWrite(MOTOR_RIGHT_ENABLE, right_motor_speed);
	analogWrite(MOTOR_LEFT_ENABLE, left_motor_speed);

}
