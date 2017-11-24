/*
 * PositionInterface.h
 *
 *  Created on: 24 nov. 2017
 *      Author: guill
 */

#ifndef APP_CAN_INTERFACES_POSITIONINTERFACE_H_
#define APP_CAN_INTERFACES_POSITIONINTERFACE_H_


#include "app/Sensors/position_sensors.h"
#include "app/CAN/CAN_Abstraction.h"

#ifdef __cplusplus
extern "C"{
#endif

data_paquet_t* linkPosition2Can(void);

//this is a weak function first declared in position_sensors
void SetCarPositionL(float position);
void SetCarPositionR(float position);

#ifdef __cplusplus
}
#endif

#endif /* APP_CAN_INTERFACES_POSITIONINTERFACE_H_ */
