/*
 * SteeringWheelInterface.cpp
 *
 *  Created on: 22 nov. 2017
 *      Author: guill
 */

#include "app/can_interfaces/SteeringWheelInterface.h"

data_paquet_t SteeringWheel_data_paquet;

data_paquet_t* linkSteeringWheel2Can(void)
{
	return &SteeringWheel_data_paquet;
}

void SetSteeringWheel(uint8_t angle)
{
	SteeringWheel_data_paquet.byteMessage[0] = angle;
}



