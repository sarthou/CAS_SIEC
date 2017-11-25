/**
 * @file    Ext_callbacks.c
 * @author  Team Darlene : Sarthou
 * @brief   Functions to manage callbacks for Drivers_Car layer 
 */
 
#include "drivers/common_def.h"
#include "app/Callbacks/Ext_callbacks.h"
#include "config/common_constants.h"

__weak void HallSensor_Handler(Sensor_Enum hall_identifier) {}

void EXTI_Callback(uint32_t EXTI_Line)
{
    if (EXTI_Line == SENSOR_L_LINE)
    	HallSensor_Handler(SENSOR_L);

    if (EXTI_Line == SENSOR_R_LINE)
    	HallSensor_Handler(SENSOR_R);
}

