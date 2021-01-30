//Grab functions

#import <Arduino.h> 
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Grab.h"

//Declare servo and linear actuator objects, you might need to use the Sevro.h library here. If you do it must go into the Scorpion_Libraries.h file, not here.
Servo linear_actuator;
Servo servo;



// servo positions 
#define SERVO_MIN 0 // ready position
#define SERVO_MAX 70 //grab position

// linear actuator positions
#define LINEAR_MIN 2000 //close even tighter incase box slips
#define LINEAR_GRAB 2000 // grab position 
#define LINEAR_MAX 1000 // ready position


// define the three switch positions
#define MIDDLE_POS_MIN 1300
#define MIDDLE_POS_MAX 1700

// define delay
#define DELAY 1000 // amount of delay between movements in milliseconds

/* Function: setupGrab
*  Input Parameters: None
*  Output Parameters: None
*  Purpose: Use transmitter values to send data motor driver and control steering
*/
void setupGrab() {
	linear_actuator.attach(LINEAR_ACTUATOR);
	servo.attach(SERVO);

	//Setup the servo and Linear actuator pins 
}

/* Function: Grab
*  Input Parameters: Transmitter values as an array of integers 
*  Output Parameters: None
*  Purpose: control grab function of the rover
*/
void Grab(int transmitter_values[8]) {

	int grab_switch = transmitter_values[5]; // define grab switch

	//grab box as tightly
	if (grab_switch > MIDDLE_POS_MAX) { //switch fully on position

		linear_actuator.writeMicroseconds(LINEAR_MIN);
		delay(DELAY);
		servo.write(SERVO_MAX);


	}
	//grab box
	else if (grab_switch > MIDDLE_POS_MIN && grab_switch < MIDDLE_POS_MAX) { // switch in middle position
		
		linear_actuator.writeMicroseconds(LINEAR_GRAB);
		delay(DELAY);
		servo.write(SERVO_MAX);
		
	}
	//ready to grab position
	else { // switch in off position

		servo.write(SERVO_MIN);
		delay(DELAY);
		linear_actuator.writeMicroseconds(LINEAR_MAX);
	}

}
