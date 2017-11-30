/*
 * DirectionInterface.cpp
 *
 *  Created on: 21 nov. 2017
 *      Author: Team Darlene : Sarthou
 */

#include "app/can_interfaces/DirectionInterface.h"

data_paquet_t direction_data_paquet;

data_paquet_t* linkDirection2Can(void)
{
	direction_data_paquet.byteMessage[0] = 0;
	return &direction_data_paquet;
}

void GetDirectionMotor(int8_t* angle)
{
	*angle = (int8_t)direction_data_paquet.byteMessage[0];
}





