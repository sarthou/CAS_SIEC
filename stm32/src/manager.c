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

//#include "system_time.h"

//#include "position_sensors.h"
//#include "speed_sensors.h"

//#include "motors.h"
//#include "front_motor.h"
//#include "rear_motors.h"

//#include "us_sensors.h"
//#include "direction.h"

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
/* Public functions ----------------------------------------------------------*/

/**
 * @brief   Counter to determine command refreshing time
*/
uint32_t Manager_remainingTimeInCommandPeriod = MANAGER_TIME_BETWEEN_TWO_UPDATES;

data_paquet_t var1;
data_paquet_t var2;
data_paquet_t var3;

data_paquet_t rec1;
data_paquet_t rec2;
data_paquet_t rec3;

periode_t my_periode;

/** 
* @brief  Initializes all the sensors / actuators
* @retval none  
*/

void Manager_Init(void)
{
	canInit();

    FrontMotor_QuickInit();
    RearMotors_QuickInit();
    RearMotors_Enable();
    
    /*
    PositionSensor_QuickInit(SENSOR_L);
    PositionSensor_QuickInit(SENSOR_R);
    
    SpeedSensor_QuickInit(SENSOR_L);
    SpeedSensor_QuickInit(SENSOR_R);
		
    Mirroring_Init();
    //Mirroring_Start();
	
	  US_QuickInit();
		US_StartAcq();
			
	  Direction_QuickInit();*/
	
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
