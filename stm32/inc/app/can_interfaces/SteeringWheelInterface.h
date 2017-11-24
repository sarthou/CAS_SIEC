/*
 * SteeringWheelInterface.h
 *
 *  Created on: 22 nov. 2017
 *      Author: guill
 */

#ifndef APP_CAN_INTERFACES_STEERINGWHEELINTERFACE_H_
#define APP_CAN_INTERFACES_STEERINGWHEELINTERFACE_H_

#include "app/Sensors/direction.h"
#include "app/CAN/CAN_Abstraction.h"

#ifdef __cplusplus
extern "C"{
#endif

data_paquet_t* linkSteeringWheel2Can(void);

//this is a weak function first declared in rear_motors.h
void SetSteeringWheel(uint8_t angle);

#ifdef __cplusplus
}
#endif

#endif /* APP_CAN_INTERFACES_STEERINGWHEELINTERFACE_H_ */
