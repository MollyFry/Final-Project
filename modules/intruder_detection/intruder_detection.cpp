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

DigitalOut trigger(PB_8); //motion sensor
DigitalIn echo(PB_9); //motion sensor
UnbufferedSerial uartUsb(USBTX, USBRX, 115200);



//=====[Declaration and initialization of public global variables]=============

bool securityThreat = true;




//=====[Implementations of public functions]===================================

void intruderDetectionInit()
{

    securityThreat = false; //sets security threat to false initially
    alarmBuzzer.input();
    greenLight = ON;
    redLight = OFF;
}

void intruderDetectionUpdate() 
{  
    if (securityThreat == false){
        greenLight = ON;
        redLight = OFF;
    }
}




void alarms(){

    alarmBuzzer.output();
    greenLight = OFF;
    redLight = ON;

    
}

void pcSerialComStringWrite( const char* str )
{
    uartUsb.write( str, strlen(str) );
}


float measure_distance() {
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


void printToMon() {
    char str[100] = "";
    float distance = measure_distance();
    sprintf ( str, "Distance: %.2f cm\n", distance, measure_distance() );
    pcSerialComStringWrite( str );

}

void engageMotor() {
    float distance = measure_distance();  // Store the value to avoid duplicate readings

    if (distance > 0 && distance < 20.00) {  // Check for valid distance
        motorControlUpdate();
        alarms();
        securityThreat = true;
    }
}
