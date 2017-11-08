#ifndef CAN_APPLICATION_H
#define CAN_APPLICATION_H

#include "CAN_Abstraction.h"

typedef struct
{
	data_paquet* data;
	int16_t id;
} variable_paquet_t;

typedef struct
{
	variable_paquet_t variables[10];
	uint16_t nb_variables;
}subperiode_t;

typedef struct 
{
	subperiode_t subperiodes[10];
	uint16_t nb_subperiodes;
}periode_t;

void init_CAN_periodic(uint16_t periode_ms, periode_t* periodes);

void CAN_Callback(uint64_t time_ms);

#endif
