//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "check_on_diamond.h"

#define LIGHT_OFF 0.4 //defining a value for the potentiometer

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

void handleLight() //turns the light on or off depending on the state
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
void lightUpdate() //sets the state based on the potentiometer reading
{
   lightReading = lightSelect.read();

   if ( lightReading <= LIGHT_OFF) {
     lightState = LIGHT_STATE_OFF;
 } else if ( lightReading > LIGHT_OFF) {
     lightState = LIGHT_STATE_ON;
   }
}
