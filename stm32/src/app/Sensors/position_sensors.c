/**
 * @file    position_sensors.c
 * @author  Curtis Team
 * @refact  Team Darlene : Sarthou
 * @brief   Functions to handle position sensors
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app/Sensors/position_sensors.h"
#include "app/Sensors/hall_sensors.h"
#include "config/common_constants.h"
#include "drivers/common_def.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/**
 * @brief   Last computed position (expressed in centimeters) for each hall sensor
*/
float position[HALLSENSORS_NUMBER]; 

/* Private function prototypes -----------------------------------------------*/
void PositionSensor_compute (Sensor_Enum PositionSensor_identifier);

/* Public functions ----------------------------------------------------------*/
//create this function into your communication interface
__weak void SetCarPositionL(float position) {}
__weak void SetCarPositionR(float position) {}

/**
 * @brief   Initializes specified position sensor.
 * @param   PositionSensor_identifier Position sensor to be considered. 
*/
void PositionSensor_QuickInit(Sensor_Enum PositionSensor_identifier)
{
    if (PositionSensor_identifier == SENSOR_L)
    	position[SENSOR_L] = 0.0;
    else if (PositionSensor_identifier == SENSOR_R)
    	position[SENSOR_R] = 0.0;
    else return;
    
    HallSensor_QuickInit(PositionSensor_identifier);
}

/**
 * @brief   Returns the value of position : unit is given by unit parameter
 * @param   unit A parameter to convert centimeters to any expected unit. It is recommended to use defined units such as POSITION_MM, POSITION_CM, POSITION_M, POSITION_IN, POSITION_FT,...
 * @param   PositionSensor_identifier Position sensor to examine
 * @retval  Position sensor's value : unit depends on parameter passed as argument 
*/
float PositionSensor_get(float unit, Sensor_Enum PositionSensor_identifier)
{
	PositionSensor_compute(PositionSensor_identifier);
	float this_position =  position[PositionSensor_identifier] * unit;

	if (PositionSensor_identifier == SENSOR_L)
		SetCarPositionL(this_position);
	else if (PositionSensor_identifier == SENSOR_R)
		SetCarPositionR(this_position);

	return this_position;
}


/* Private functions ---------------------------------------------------------*/
void PositionSensor_compute(Sensor_Enum PositionSensor_identifier)
{
	float lap = (float) HallSensor_getLap(PositionSensor_identifier);
	float sector = (float) HallSensor_getSector(PositionSensor_identifier);
	position[PositionSensor_identifier] = PI * CAR_WHEEL_SIZE * (lap +  sector / HALLSENSOR_NUMBER_OF_SECTORS);
}
