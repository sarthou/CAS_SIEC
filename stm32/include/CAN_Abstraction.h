#ifndef __CAN_ABSTRACTION_H
#define __CAN_ABSTRACTION_H

#include "STM32F10x.h"
#include "CAN.h"

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
}data_paquet;

//Represents a CAN frame with data and its id
typedef struct{
	data_paquet data;
	int16_t id;
}can_paquet;

//Subscribes to an id and set the memory place for the data
void can_subscribe(int id, data_paquet* data);

//Inits CAN bus
//Subscriptions must be done before this function
void can_Init(void);

//Generic functions for sending and receiving messages 
int sendMessage(int16_t id, data_paquet data);
int sendMessageFloat(int16_t id, float data1, float data2);
int sendMessageChar(int16_t id, char data);
int receiveMessage(void);

#endif
