  //Contains all functions for FPV

#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
const int FRONT_POS = 0; // ready position
const int BACK_POS = 180; //grab 
Servo camServo;

//Add function description here
void setupFpv(){
  camServo.attach(CAM_SERVO);
}

//Add in function description here
void fpvControl(int SWITCH_C){
    
  if (SWITCH_C > 1300){
    camServo.write(FRONT_POS);
  }
  else{
    camServo.write(FRONT_POS);
  }
  
}
}
