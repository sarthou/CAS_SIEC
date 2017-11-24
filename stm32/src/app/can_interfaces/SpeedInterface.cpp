/*
 * SpeedInterface.cpp
 *
 *  Created on: 24 nov. 2017
 *      Author: guill
 */

#include "app/can_interfaces/SpeedInterface.h"

data_paquet_t speed_data_paquet;

data_paquet_t* linkSpeed2Can(void)
{
	speed_data_paquet.floatMessage[0] = 0.0f;
	speed_data_paquet.floatMessage[1] = 0.0f;
	return &speed_data_paquet;
}

void SetCarSpeedL(float speed)
{
	speed_data_paquet.floatMessage[0] = speed;
}

void SetCarSpeedR(float speed)
{
	speed_data_paquet.floatMessage[1] = speed;
}


