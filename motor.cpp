//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "intruder_detection.h"
#include "mbed.h"

#include "motor.h"



//=====[Declaration and initialization of public global objects]===============



DigitalInOut motorM1Pin(PF_2);
DigitalInOut motorM2Pin(PE_6);

DigitalIn resetButton(PF_9);

int motorUpdateCounter;



//=====[Implementations of public functions]===================================



void motorControlInit()
{
    motorM1Pin.mode(OpenDrain);
    motorM2Pin.mode(OpenDrain);
    
    motorM1Pin.input();
    motorM2Pin.input();
    motorUpdateCounter = 0;
    motorUpdateCounter2 = 0;
    resetButton.mode(PullDown);


}




void motorControlUpdate()
{   
    if ( (motorUpdateCounter <= 30)) { 
            motorM2Pin.input(); //swap input and output to change direction!!
            motorM1Pin.output();
            motorUpdateCounter++;

    if (motorUpdateCounter > 30){ //change number to determine how long it runs for
        motorM2Pin.input();
        motorM1Pin.input();
        }

    }  
}
