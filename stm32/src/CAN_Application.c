#include "CAN_Application.h"

periode_t* periode;
uint16_t current_periode = 0;
uint8_t periodic_enable =0;

void init_CAN_periodic(uint16_t periode_ms, periode_t* periodes)
{
	periode=periodes;
	//Start timer
	periodic_enable = 1;
}

void sendSubPeriode(void)
{
	uint16_t i=0;
	for(i=0;i<periode->subperiodes[current_periode].nb_variables;i++){
		sendMessage(periode->subperiodes[current_periode].variables[i].id, *periode->subperiodes[current_periode].variables[i].data);
	}
}

void CAN_Callback(uint64_t time_ms)
{
	if(periodic_enable)
	{
		if(time_ms %1000==0)
		{
			sendSubPeriode();
			current_periode++;
			if(current_periode >= periode->nb_subperiodes)
				current_periode = 0;
		}
	}
}
