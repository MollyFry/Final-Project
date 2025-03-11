//=====[Libraries]=============================================================

#include "arm_book_lib.h"
#include "display.h"
#include "intruder_detection.h"
#include "mbed.h"

#include "user_interface.h"


//=====[Implementations of public functions]===================================
 void userInterfaceDisplayInit()
{
    displayInit();
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "No Intruder      " );


}

void userInterfaceDisplayUpdate()
{
    if (securityThreat == true) {
        displayCharPositionWrite ( 0,0 );
        displayStringWrite( "INTRUDER ALERT!        ");
    }
    if (securityThreat == false) {
        displayCharPositionWrite ( 0,0 );
        displayStringWrite( "No Intruder      " );

    }
}
