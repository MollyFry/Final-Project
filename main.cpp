//=====[Libraries]=============================================================
#include "arm_book_lib.h"

#include "check_on_diamond.h"
#include "motor.h"
#include "museum_security_system.h"
#include "intruder_detection.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    museum_security_systemInit();
    while (true) {
       museum_security_systemUpdate();
       //printToMon(); //for testing how far away things should be!
       delay(10);
    }
}
