//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "display.h"
#include "intruder_detection.h"
#include "mbed.h"
#include "user_interface.h"


//=====[Implementations of public functions]===================================

 void userInterfaceDisplayInit() //initializes the LCD display to say "No Intruder"
{
    displayInit();
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "No Intruder      " );


}

void userInterfaceDisplayUpdate()
{
    if (securityThreat == true) { //when there is a security threat, the message is changed on the LCD display
        displayCharPositionWrite ( 0,0 );
        displayStringWrite( "INTRUDER ALERT!        ");
    }
    if (securityThreat == false) {
        displayCharPositionWrite ( 0,0 );
        displayStringWrite( "No Intruder      " );

    }
}
