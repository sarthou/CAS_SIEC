#ifndef __CAN_ABSTRACTION_H
#define __CAN_ABSTRACTION_H

//#include "STM32F10x.h"
//#include "CAN.h"

/*
First abstraction concerning CAN API
This abstraction gives some functions to easily manipulate CAN bus
*/

//Represents data under different formats
typedef union 
{
	char stringMessage[8];
	int8_t byteMessage[8];
	int16_t intMessage[4];
	float floatMessage[2];
}data_paquet_t;

//Represents a CAN frame with data and its id
typedef struct{
	data_paquet_t data;
	int16_t id;
}can_paquet_t;




#endif