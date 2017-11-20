/*
 * RearInterface.h
 *
 *  Created on: 20 nov. 2017
 *      Author: guill
 */

#ifndef APP_CAN_INTERFACES_REARINTERFACE_H_
#define APP_CAN_INTERFACES_REARINTERFACE_H_

#include "app/Motors/rear_motors.h"
#include "app/CAN/CAN_Abstraction.h"

#ifdef __cplusplus
extern "C"{
#endif

data_paquet_t* linkRear2Can(void);

//this is a weak function first declared in rear_motors.h
//void GetRearMotors(int16_t* speed_L, int16_t* speed_R);

#ifdef __cplusplus
}
#endif

#endif /* APP_CAN_INTERFACES_REARINTERFACE_H_ */
