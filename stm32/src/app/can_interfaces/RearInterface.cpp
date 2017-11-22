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
	return &rear_data_paquet;
}

void GetRearMotors(int16_t* speed_L, int16_t* speed_R)
{
	*speed_L = 3;//rear_data_paquet.intMessage[0];
	*speed_R = 3;//rear_data_paquet.intMessage[1];
}


