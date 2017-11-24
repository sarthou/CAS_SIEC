#include "CAN_Abstraction.h" /*Our Abstration*/
#include "CAN_Periodic.h"
#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

volatile uint32_t msTicks; 
 void alarmWakeup(int sig_num){
	 if(sig_num== SIGALRM){
		// printf("%d\n",msTicks);
		 msTicks=msTicks+1;
		 CanCallback(msTicks);
	 }
 }

data_paquet_t var1;
data_paquet_t var2;
data_paquet_t var3;

periode_t my_periode;

void init_my_can()
{
	subperiode_t sub1;
	{
		variable_paquet_t paquet1;
		paquet1.id = 42;
		paquet1.data = &var1;
		variable_paquet_t paquet2;
		paquet2.id = 2;
		paquet2.data = &var2;
		
		sub1.variables[0] = paquet1;
		sub1.variables[1] = paquet2;
		sub1.nb_variables = 2;
	}
	
	subperiode_t sub2;
	{
		variable_paquet_t paquet1;
		paquet1.id = 25;
		paquet1.data = &var3;
		variable_paquet_t paquet2;
		paquet2.id = 2;
		paquet2.data = &var2;
		
		sub2.variables[0] = paquet1;
		sub2.variables[1] = paquet2;
		sub2.nb_variables = 2;
	}
	my_periode.subperiodes[0] = sub1;
	my_periode.subperiodes[1] = sub2;
	my_periode.nb_subperiodes = 2;
	initCanPeriodic(1000, &my_periode);
}


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void)  {
	
	var1.stringMessage[0] = 'H';
	var1.stringMessage[1] = 'C';
	var1.stringMessage[2] = 'C';
	var1.stringMessage[3] = '\0';
	var2.stringMessage[0] = 65;
	var3.stringMessage[0] = 66;

	init_my_can();
	
	signal(SIGALRM, alarmWakeup);
	ualarm(1000,1000);//First ofset, Second period, en µs
	
  while (1) {
	runCanPeriodic();
  }
}