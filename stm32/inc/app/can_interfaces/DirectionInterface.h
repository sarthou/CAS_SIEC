/*
 * DirectionInterface.h
 *
 *  Created on: 21 nov. 2017
 *      Author: Team Darlene : Sarthou
 */

#ifndef APP_CAN_INTERFACES_DIRECTIONINTERFACE_H_
#define APP_CAN_INTERFACES_DIRECTIONINTERFACE_H_

#include "app/Motors/front_motor.h"
#include "app/CAN/CAN_Abstraction.h"

#ifdef __cplusplus
extern "C"{
#endif

data_paquet_t* linkDirection2Can(void);

//this is a weak function first declared in rear_motors.h
void GetDirectionMotor(int8_t* angle);

#ifdef __cplusplus
}
#endif

#endif /* APP_CAN_INTERFACES_DIRECTIONINTERFACE_H_ */
