//Contains all files for PPM receiver 

#include "Pin_Assignments.h"
#include "Scorpion_Libraries.h"
#include "Comms.h"
#import<Arduino.h>

int rc_values[8] = { 0,0,0,0,0,0,0,0 };
int x[15], ch1[15], i;

//Add in Function Description Here
void setupRc() {
    //Setup RC pins here
    Serial.begin(9600);
    pinMode(2, INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(2), readMe, FALLING);

}

//Add in Function Description Here
void readRc(int rc_values[8]) {
    //Read values from the transmitter and  store them accordingly into the array
     //[0] - Right Lateral, 
     //[1] - Right up/down, 
     //[2] - Thottle, 
     //[3] - Left lateral, 
     //[4] - Switch A, 
     //[5] - Switch B, 
     //[6] - Switch C, 
     //[7] - Switch D

    int i, j, k = 0;
    for (k = 14; k > -1; k--) {
        if (ch1[k] > 10000) {
            j = k;
            delay(1);
        }
        for (i = 0; i <= 7; i++) {
            rc_values[i] = (ch1[i + j]);
            delay(1);
        }
    }
}

void readMe() {
    int a, b, c;
    a = micros();
    c = a - b;
    b = a;
    x[i] = c;
    i = i + 1;

    if (i == 15) {
        for (int j = 0; j < 15; j++) {
            ch1[j] = x[j];
            delay(1);
        }
        i = 0;
    }
}




  
  
  
  
  
