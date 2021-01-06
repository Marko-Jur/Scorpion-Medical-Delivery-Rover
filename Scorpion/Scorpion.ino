//Main controller for Scorpion
#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Grab.h"
#include "Comms.h"
#include "Fpv.h"
#include "Lasers.h"

int raw_rc_values[8] = {0,0,0,0,0,0,0,0}; // This is the array you need to pass into the readRc function.

//Add in Function Description Here
void setup(){

    Serial.begin(9600);
    //Setup all the components here. You should call about 3-5 functions here
    void setupRc();
    void setupLasers();
    void motorSetup();
    void setupFpv();
    void setupGrab();
    

}

//Add in Function Description Here
void loop(){
    
    //Comms.cpp registers 8-int array from transmitter directly into raw_rc_values
    void readRc(raw_rc_values);
    
    //Laser control (ON/OFF); input SWITCH_D
    void laserControl(raw_rc_values[7]);
    
    //Steering; input 8-int array
    void steering(raw_rc_values);
    
    //FPV; input SWITCH_B
    void fpvControl(raw_rc_values[5]);
    
    //Grab; input SWITCH_A
    void Grab(raw_rc_values[4]);
        
        
    /* Call functions here to execute the functionality of Scorpion. Your job will be to pass in inputs and extract outputs to functions where necessary. You need to call
    *  about 5-7 functions here. 
    * Figure out the software flow. What's the first function you should call? What starts off every single function? After that the order of functions is up to you!
    */
    
}
