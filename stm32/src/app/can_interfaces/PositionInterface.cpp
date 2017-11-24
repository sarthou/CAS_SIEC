/*
 * PositionInterface.cpp
 *
 *  Created on: 24 nov. 2017
 *      Author: guill
 */

#include "app/can_interfaces/PositionInterface.h"

data_paquet_t position_data_paquet;

data_paquet_t* linkPosition2Can(void)
{
	position_data_paquet.floatMessage[0] = 0.0f;
	position_data_paquet.floatMessage[1] = 0.0f;
	return &position_data_paquet;
}

void SetCarPositionL(float position)
{
	position_data_paquet.floatMessage[0] = position;
}

void SetCarPositionR(float position)
{
	position_data_paquet.floatMessage[1] = position;
}


