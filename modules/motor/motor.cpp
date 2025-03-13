//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "intruder_detection.h"
#include "mbed.h"

#include "motor.h"



//=====[Declaration and initialization of public global objects]===============


//defining the pins for the motor
DigitalInOut motorM1Pin(PF_2); 
DigitalInOut motorM2Pin(PE_6);

//defining a variable to be enumerated
int motorUpdateCounter;



//=====[Implementations of public functions]===================================



void motorControlInit() //initialize the motor
{
    motorM1Pin.mode(OpenDrain);
    motorM2Pin.mode(OpenDrain);
    
    motorM1Pin.input();
    motorM2Pin.input();
    motorUpdateCounter = 0;



}




void motorControlUpdate() //this makes the motor run when it's called
{   
    if ( (motorUpdateCounter <= 30)) { //makes sure that the motor only runs for a set amount of time
            motorM2Pin.input(); //swap input and output to change direction!!
            motorM1Pin.output();
            motorUpdateCounter++;

    if (motorUpdateCounter > 30){ //change number to determine how long it runs for
        motorM2Pin.input(); //setting both of these pins to input stops the motor
        motorM1Pin.input();
        }

    }  
}
