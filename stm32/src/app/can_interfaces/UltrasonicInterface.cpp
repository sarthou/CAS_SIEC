/*
 * UltrasonicInterface.cpp
 *
 *  Created on: 26 nov. 2017
 *      Author: Team Darlene : Sarthou
 */

#include "app/can_interfaces/UltasonicInterface.h"

data_paquet_t usFB_data_paquet;
data_paquet_t usL_data_paquet;
data_paquet_t usR_data_paquet;

data_paquet_t* linkUltrasonicFB2Can(void)
{
	usFB_data_paquet.floatMessage[0] = 0.0f;
	usFB_data_paquet.floatMessage[1] = 0.0f;
	return &usFB_data_paquet;
}

data_paquet_t* linkUltrasonicL2Can(void)
{
	usL_data_paquet.floatMessage[0] = 0.0f;
	usL_data_paquet.floatMessage[1] = 0.0f;
	return &usL_data_paquet;
}

data_paquet_t* linkUltrasonicR2Can(void)
{
	usR_data_paquet.floatMessage[0] = 0.0f;
	usR_data_paquet.floatMessage[1] = 0.0f;
	return &usR_data_paquet;
}

void SetUltrasonicFront(float distance)
{
	usFB_data_paquet.floatMessage[0] = distance;
}

void SetUltrasonicBack(float distance)
{
	usFB_data_paquet.floatMessage[1] = distance;
}

void SetUltrasonicLeftFront(float distance)
{
	usL_data_paquet.floatMessage[0] = distance;
}

void SetUltrasonicRightFront(float distance)
{
	usR_data_paquet.floatMessage[0] = distance;
}

void SetUltrasonicLeftBack(float distance)
{
	usL_data_paquet.floatMessage[1] = distance;
}

void SetUltrasonicRightBack(float distance)
{
	usR_data_paquet.floatMessage[1] = distance;
}
