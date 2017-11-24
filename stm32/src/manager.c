/**
 * @file    nucleo_functionnalities_manager.c
 * @author  Curtis Team
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

#include "app/Sensors/battery.h"

#include "system_time.h"

#include "app/Motors/motors.h"
#include "app/Sensors/hall_sensors.h"

//#include "us_sensors.h"

//#include "data_interface.h"
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

/**
 * @brief   Counter to determine command refreshing time
*/
uint32_t Manager_remainingTimeInCommandPeriod = MANAGER_TIME_BETWEEN_TWO_UPDATES;

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

    Battery_QuickInit();


	System_Time_QuickInit();

    /*
    Mirroring_Init();
    //Mirroring_Start();
	
	US_QuickInit();
	US_StartAcq();*/

    uint16_t received_id = -1;
	while(1)
	{
		received_id = receiveMessage();
	}

}

/**
 * @brief   Callback associated to the nucleo functionnalities manager whose aim is to set the adequate command and update the sensors' data
 * @retval	None
*/
void Manager_Callback(void) {
    /*Manager_remainingTimeInCommandPeriod --;
    
    if (Manager_remainingTimeInCommandPeriod == 0) {
    // ACTUATORS    
        // Front motors
        if (pDataITF_PI->motor_dir == LEFT || pDataITF_PI->motor_dir == RIGHT){
          FrontMotor_turn (pDataITF_PI->motor_dir);
        }
        else if (pDataITF_PI->motor_dir != LEFT && pDataITF_PI->motor_dir != RIGHT) {
            FrontMotor_turn(NONE);// do nothing
        }
        
    // SENSORS   
        // wheel speed    
        pDataITF_STM->wheel_speed_R = SpeedSensor_get(SPEED_CM_S, SENSOR_R);
        pDataITF_STM->wheel_speed_L = SpeedSensor_get(SPEED_CM_S, SENSOR_L);
        
        // travelled distance
        pDataITF_STM->travelled_distance_R = PositionSensor_get(POSITION_CM, SENSOR_R);
        pDataITF_STM->travelled_distance_L = PositionSensor_get(POSITION_CM, SENSOR_L);
        
        
        //motors current
       // pDataITF_STM->motor_current_R = ;
       // pDataITF_STM->motor_current_L = ;
        Manager_remainingTimeInCommandPeriod = MANAGER_TIME_BETWEEN_TWO_UPDATES;  
    }*/
}

void init_my_can()
{
	subperiode_t sub1;
	{
		variable_paquet_t paquet1;
		paquet1.id = 0x101;
		paquet1.data = linkSteeringWheel2Can();

		sub1.variables[0] = paquet1;
		sub1.nb_variables = 1;
	}

	subperiode_t sub2;
	{
		variable_paquet_t paquet1;
		paquet1.id = 0x100;
		paquet1.data = linkPosition2Can();

		variable_paquet_t paquet2;
		paquet2.id = 0x102;
		paquet2.data = linkSpeed2Can();

		sub2.variables[0] = paquet1;
		sub2.variables[1] = paquet2;
		sub2.nb_variables = 2;
	}

	my_periode.subperiodes[0] = sub1;
	my_periode.subperiodes[1] = sub2;
	my_periode.nb_subperiodes = 2;
	initCanPeriodic(50, &my_periode);
}
