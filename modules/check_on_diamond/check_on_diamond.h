//=====[#include guards - begin]===============================================

#ifndef _CHECK_ON_DIAMOND_H_
#define _CHECK_ON_DIAMOND_H_



//=====[Declaration of public data types]======================================


typedef enum {
  LIGHT_STATE_OFF,
  LIGHT_STATE_ON
} lightState_t;
//=====[Declarations (prototypes) of public functions]=========================

void lightInit();
void lightUpdate();
void handleLight();

//=====[#include guards - end]=================================================

#endif // _CHECK_ON_DIAMOND_H_
