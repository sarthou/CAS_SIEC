#ifndef __CAN_ABSTRACTION_H
#define __CAN_ABSTRACTION_H

#include "STM32F10x.h"
#include "CAN.h"

typedef union 
{
	char stringMessage[8];
	int8_t byteMessage[8];
	int16_t intMessage[4];
	float floatMessage[2];
}data_paquet;

typedef struct{
	data_paquet data;
	int16_t id;
}can_paquet;

void can_Init (int* ids, unsigned int size);

void sendMessage(int16_t id, data_paquet data);
void sendMessageFloat(int16_t id, float data1, float data2);
void sendMessageChar(int16_t id, char data);
int receiveMessage(can_paquet* received);

#endif
