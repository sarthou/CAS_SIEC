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

void can_subscribe(int id, data_paquet* data);
void can_Init(void);

int sendMessage(int16_t id, data_paquet data);
int sendMessageFloat(int16_t id, float data1, float data2);
int sendMessageChar(int16_t id, char data);
int receiveMessage(void);

#endif
