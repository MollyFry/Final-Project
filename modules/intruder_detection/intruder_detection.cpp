//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "intruder_detection.h"
#include "motor.h"
#include <cstdio>



//=====[Declaration and initialization of public global objects]===============


DigitalOut greenLight(PE_12); 
DigitalOut redLight(PB_4);
DigitalInOut alarmBuzzer(PE_10); // Alarm Buzzer

DigitalOut trigger(PB_8); //ultrasonic sensor
DigitalIn echo(PB_9); //ultrasonic sensor
UnbufferedSerial uartUsb(USBTX, USBRX, 115200); //serial monitor for testing distance ultrasonic sensor is calculating 



//=====[Declaration and initialization of public global variables]=============

//initializing the securityThreat variable
bool securityThreat = false;




//=====[Implementations of public functions]===================================

void intruderDetectionInit() //the initial state
{

    securityThreat = false; //sets security threat to false initially
    alarmBuzzer.input();
    greenLight = ON;
    redLight = OFF;
}

void intruderDetectionUpdate()  //update called which keeps the green light on, provided there is no intruder
{  
    if (securityThreat == false){
        greenLight = ON;
        redLight = OFF;
    }
}




void alarms(){ //this is what occurs when the intruder is detected

    alarmBuzzer.output(); //alarm is turned on
    greenLight = OFF;
    redLight = ON;

    
}

void pcSerialComStringWrite( const char* str ) //used for sending ultrasonic sensor values to monitor
{
    uartUsb.write( str, strlen(str) );
}


float measure_distance() { //measure how far away something is from the ultrasonic sensor
    trigger = 1;
    wait_us(10);
    trigger = 0;

    while (echo == 0);
    Timer timer;
    timer.start();

    while (echo == 1);
    timer.stop();

    float duration = chrono::duration<float, std::micro>(timer.elapsed_time()).count();
    float distance_cm = (duration * 0.0343f) / 2.0f;
    return distance_cm;
}


void printToMon() { //printing the distance to the serial monitor
    char str[100] = "";
    float distance = measure_distance();
    sprintf ( str, "Distance: %.2f cm\n", distance, measure_distance() );
    pcSerialComStringWrite( str );

}

void engageMotor() { //engages the motor when needed
    float distance = measure_distance();  // Store the value to avoid duplicate readings

    if (distance > 0 && distance < 20.00) {  // Check for valid distance
        motorControlUpdate(); //deploy the motor
        alarms(); //deploy the alarms
        securityThreat = true; //this variable is used for the LCD display
    }
}
