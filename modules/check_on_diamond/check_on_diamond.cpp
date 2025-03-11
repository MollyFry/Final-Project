//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "check_on_diamond.h"

#define LIGHT_OFF 0.4

//=====[Declaration and initialization of public global objects]=============

AnalogIn lightSelect(A0); //potentiometer reading in mode selection
DigitalOut diamondLight(PE_14);  // light for checking the diamond



float lightReading = 0.0;


lightState_t lightState = LIGHT_STATE_OFF;
float lightValue = 0.0;

//=====[Implementations of public functions]===================================

void lightInit()
{
    diamondLight = OFF; //initializes diamond light to be off
}

void handleLight()
{
   lightUpdate();
   switch(lightState){
       case LIGHT_STATE_OFF:
           diamondLight = OFF;
           break;
       case LIGHT_STATE_ON:
           diamondLight = ON;
           break;
   }
}
void lightUpdate()
{
   lightReading = lightSelect.read();

   if ( lightReading <= LIGHT_OFF) {
     lightState = LIGHT_STATE_OFF;
 } else if ( lightReading > LIGHT_OFF) {
     lightState = LIGHT_STATE_ON;
   }
}
