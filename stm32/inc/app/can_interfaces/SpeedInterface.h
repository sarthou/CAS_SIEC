/*
 * SpeedInterface.h
 *
 *  Created on: 24 nov. 2017
 *      Author: Team Darlene : Sarthou
 */

#ifndef APP_CAN_INTERFACES_SPEEDINTERFACE_H_
#define APP_CAN_INTERFACES_SPEEDINTERFACE_H_

#include "app/Sensors/speed_sensors.h"
#include "app/CAN/CAN_Abstraction.h"

#ifdef __cplusplus
extern "C"{
#endif

data_paquet_t* linkSpeed2Can(void);

//this is a weak function first declared in speed_sensors
void SetCarSpeedL(float speed);
void SetCarSpeedR(float speed);

#ifdef __cplusplus
}
#endif

#endif /* APP_CAN_INTERFACES_SPEEDINTERFACE_H_ */
