/*
 * RearInterface.cpp
 *
 *  Created on: 20 nov. 2017
 *      Author: guill
 */

#include "app/can_interfaces/RearInterface.h"

data_paquet_t rear_data_paquet;

data_paquet_t* linkRear2Can(void)
{
	rear_data_paquet.intMessage[0] = 0;
	rear_data_paquet.intMessage[1] = 0;
	return &rear_data_paquet;
}

void GetRearMotors(int16_t* speed_L, int16_t* speed_R)
{
	*speed_L = rear_data_paquet.intMessage[0] / 10.0f;
	*speed_R = rear_data_paquet.intMessage[1] / 10.0f;
}


