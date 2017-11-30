/*
 * UltasonicInterface.h
 *
 *  Created on: 26 nov. 2017
 *      Author: Team Darlene : Sarthou
 */

#ifndef APP_CAN_INTERFACES_ULTASONICINTERFACE_H_
#define APP_CAN_INTERFACES_ULTASONICINTERFACE_H_

#include "app/Sensors/us_sensors.h"
#include "app/CAN/CAN_Abstraction.h"

#ifdef __cplusplus
extern "C"{
#endif

data_paquet_t* linkUltrasonicFB2Can(void);
data_paquet_t* linkUltrasonicL2Can(void);
data_paquet_t* linkUltrasonicR2Can(void);

//this is a weak function first declared in us_sensors
void SetUltrasonicFront(float distance);
void SetUltrasonicBack(float distance);
void SetUltrasonicLeftFront(float distance);
void SetUltrasonicRightFront(float distance);
void SetUltrasonicLeftBack(float distance);
void SetUltrasonicRightBack(float distance);

#ifdef __cplusplus
}
#endif

#endif /* APP_CAN_INTERFACES_ULTASONICINTERFACE_H_ */
