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
    
    

}

//Add in Function Description Here
void loop(){
    
    /* Call functions here to execute the functionality of Scorpion. Your job will be to pass in inputs and extract outputs to functions where necessary. You need to call
    *  about 5-7 functions here. 
    * Figure out the software flow. What's the first function you should call? What starts off every single function? After that the order of functions is up to you!
    */
    
}
