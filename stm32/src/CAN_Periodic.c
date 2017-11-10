#include "CAN_Periodic.h"

//Interbal variables
periode_t* periode;
uint16_t current_periode = 0;
uint16_t current_variable = 0;
uint8_t periodic_enable =0;
uint8_t do_periodic = 0;
uint16_t periode_ms_ = 0;

void init_CAN_periodic(uint16_t periode_ms, periode_t* periodes)
{
	periode=periodes;
	periodic_enable = 1;
	current_variable = 0;
	periode_ms_ = periode_ms;
}

int sendSubPeriode(void)
{
	if(sendMessage(periode->subperiodes[current_periode].variables[current_variable].id, *periode->subperiodes[current_periode].variables[current_variable].data) == 0)
	{
		current_variable = current_variable + 1;
		if(current_variable >= periode->subperiodes[current_periode].nb_variables)
		{
			do_periodic = 0;
			current_variable = 0;
			return 0; //end of all variables in this subperiode
		}
	}
	
	return -1; //NOT the end of all variables in this subperiode
}

void CAN_Callback(uint64_t time_ms)
{
	if(periodic_enable)
	{
		if(time_ms %periode_ms_==0)
			do_periodic = 1;
	}
}

void runCanPeriodic(void)
{
	if(do_periodic)
	{
		if(sendSubPeriode() == 0)
		{
			current_periode = current_periode + 1;
			if(current_periode >= periode->nb_subperiodes)
				current_periode = 0;
		}
	}
}
