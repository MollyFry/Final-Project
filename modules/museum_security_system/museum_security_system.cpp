//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "motor.h"
#include "museum_security_system.h"
#include "check_on_diamond.h"
#include "intruder_detection.h"
#include "check_code.h"
#include "user_interface.h"
#include "display.h"


//=====[Implementations of public functions]===================================



void museum_security_systemInit()
{
    matrixKeypadInit();
    lightInit();
    intruderDetectionInit();
    motorControlInit();
    userInterfaceDisplayInit();
}

void museum_security_systemUpdate()
{
    matrixKeypadUpdate();
    handleLight();
    engageMotor();
    intruderDetectionUpdate();
    userInterfaceDisplayUpdate();
    alarmDeactivationUpdate();
    printToMon();
    measure_distance();

}
