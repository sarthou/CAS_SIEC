#include "CAN_Abstraction.h" /*Our Abstration*/
#include "CAN_Periodic.h"
#include <signal.h>
#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

data_paquet_t transMotorsOrder;
data_paquet_t transSteeringWheelOrder;

data_paquet_t recPosSteeringWheel;
data_paquet_t recPosWheels;
data_paquet_t recUSFrontBack;
data_paquet_t recUSLeft;
data_paquet_t recUSRight;

data_paquet_t recBattery;

periode_t my_periode;

volatile uint32_t msTicks; 
 void alarmWakeup(int sig_num){
	 if(sig_num== SIGALRM){
		 msTicks=msTicks+1;
		 CanCallback(msTicks);
	 }
 }
 
void init_my_can()
{
	subperiode_t sub1;
	{
		variable_paquet_t paquet1;
		paquet1.id = 16;
		paquet1.data = &transMotorsOrder;
		variable_paquet_t paquet2;
		paquet2.id = 17;
		paquet2.data = &transSteeringWheelOrder;
		
		sub1.variables[0] = paquet1;
		sub1.variables[1] = paquet2;
		sub1.nb_variables = 2;
	}
	
	subperiode_t sub2;
	{
		variable_paquet_t paquet1;
		paquet1.id = 16;
		paquet1.data = &transMotorsOrder;
		variable_paquet_t paquet2;
		paquet2.id = 17;
		paquet2.data = &transSteeringWheelOrder;
		
		sub2.variables[0] = paquet1;
		sub2.variables[1] = paquet2;
		sub2.nb_variables = 2;
	}
	
	my_periode.subperiodes[0] = sub1;
	my_periode.subperiodes[1] = sub2;
	my_periode.nb_subperiodes = 2;
	initCanPeriodic(50, &my_periode);
}


/*----------------------------------------------------------------------------
  MAIN function
 *----------------------------------------------------------------------------*/
int main (void)  {
	
	//Set value of variables contained in subperiod;
	transMotorsOrder.intMessage[0]=25300;
	transMotorsOrder.intMessage[1]=20000;
	
	transSteeringWheelOrder.byteMessage[0]=132;

	init_my_can();
	
	signal(SIGALRM, alarmWakeup);
	ualarm(1000,1000);//First ofset, Second period, en µs
	
	canSubscribe(0,&recUSFrontBack);
	canSubscribe(1, &recUSLeft);
	canSubscribe(2, &recUSRight);
	canSubscribe(257, &recPosSteeringWheel);
	canSubscribe(256, &recPosWheels);
	
	canSubscribe(512, &recBattery);
	
	canInit();
	
  while (1) {
	runCanPeriodic();
	
	receiveMessage();
	
  }
}