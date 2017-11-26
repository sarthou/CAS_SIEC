/**
 * @file    nucleo_functionnalities_manager.c
 * @author  Team Darlene : Sarthou
 * @brief   for the updates of the data structures and of the car commands
 */


/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "stm32f10x.h"
#include "manager.h"

#include "app/CAN/CAN_Abstraction.h"
#include "app/CAN/CAN_Periodic.h"

#include "app/Motors/front_motor.h"
#include "app/can_interfaces/DirectionInterface.h"
#include "app/Motors/rear_motors.h"
#include "app/can_interfaces/RearInterface.h"

#include "app/can_interfaces/SteeringWheelInterface.h"
#include "app/can_interfaces/PositionInterface.h"
#include "app/can_interfaces/SpeedInterface.h"
#include "app/can_interfaces/UltasonicInterface.h"

#include "app/Sensors/battery.h"

#include "system_time.h"

#include "app/Motors/motors.h"
#include "app/Sensors/hall_sensors.h"

#include "app/Sensors/us_sensors.h"

//#include "mirroring.h"

/**
 * @brief   Manager refresh time (in ms)
*/
#define MANAGER_TIME_BETWEEN_TWO_UPDATES 10 //ms

/**
 * @brief   Speed of the motors
*/
float motor_speed = 0.0;
uint16_t speedD;
uint16_t speedG;

/* Private function prototypes -----------------------------------------------*/
void init_my_can();
/* Public functions ----------------------------------------------------------*/

periode_t my_periode;

/** 
* @brief  Initializes all the sensors / actuators
* @retval none  
*/

void Manager_Init(void)
{
	canSubscribe(0x010, linkRear2Can());
	canSubscribe(0x011, linkDirection2Can());

	init_my_can(); //init periodic sending
	canInit();

    RearMotors_QuickInit();
    RearMotors_Enable();
    
    FrontMotor_QuickInit();

    US_QuickInit();
    US_StartAcq();

    Battery_QuickInit();


	System_Time_QuickInit();
	
	/*
	Mirroring_Init();
	//Mirroring_Start();*/

	while(1)
	{
		runCanPeriodic();
		receiveMessage();
	}

}

void init_my_can()
{
	subperiode_t sub1;
	{
		variable_paquet_t paquet1;
		paquet1.id = 0x101;
		paquet1.data = linkSteeringWheel2Can();

		variable_paquet_t paquet2;
		paquet1.id = 0x000;
		paquet1.data = linkUltrasonicFB2Can();

		variable_paquet_t paquet3;
		paquet1.id = 0x001;
		paquet1.data = linkUltrasonicL2Can();

		variable_paquet_t paquet4;
		paquet1.id = 0x002;
		paquet1.data = linkUltrasonicR2Can();

		sub1.variables[0] = paquet1;
		sub1.variables[1] = paquet2;
		sub1.variables[2] = paquet3;
		sub1.variables[3] = paquet4;
		sub1.nb_variables = 4;
	}

	subperiode_t sub2;
	{
		variable_paquet_t paquet1;
		paquet1.id = 0x100;
		paquet1.data = linkPosition2Can();

		variable_paquet_t paquet2;
		paquet2.id = 0x102;
		paquet2.data = linkSpeed2Can();

		variable_paquet_t paquet3;
		paquet1.id = 0x000;
		paquet1.data = linkUltrasonicFB2Can();

		variable_paquet_t paquet4;
		paquet1.id = 0x001;
		paquet1.data = linkUltrasonicL2Can();

		variable_paquet_t paquet5;
		paquet1.id = 0x002;
		paquet1.data = linkUltrasonicR2Can();

		sub2.variables[0] = paquet1;
		sub2.variables[1] = paquet2;
		sub2.variables[2] = paquet3;
		sub2.variables[3] = paquet4;
		sub2.variables[4] = paquet5;
		sub2.nb_variables = 5;
	}

	my_periode.subperiodes[0] = sub1;
	my_periode.subperiodes[1] = sub2;
	my_periode.nb_subperiodes = 2;
	initCanPeriodic(50, &my_periode);
}
