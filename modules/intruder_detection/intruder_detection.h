//=====[#include guards - begin]===============================================

#ifndef _INTRUDER_DETECTION_H_
#define _INTRUDER_DETECTION_H_

//=====[Declarations (prototypes) of public functions]=========================

void intruderDetectionInit();
void intruderDetectionUpdate();
extern bool securityThreat;

void alarms();


void intruderAlarmUpdate();
bool intruderDetectorStateRead();
bool intruderDetectedRead();
void intruderAlarmDeactivate();

void pcSerialComStringWrite( const char* str );
void printToMon();
float measure_distance();
void engageMotor();

//=====[#include guards - end]=================================================

#endif // _INTRUDER_DETECTION_H_
