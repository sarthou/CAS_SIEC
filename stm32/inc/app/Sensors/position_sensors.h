/**
 * @file    position_sensors.h
 * @author  Curtis Team
 * @refact  Team Darlene : Sarthou
 * @brief   Headers of functions to handle position sensors 
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _POSITION_SENSOR_H
#define _POSITION_SENSOR_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include "stm32f10x.h"
#include "config/modules_definitions.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
void PositionSensor_QuickInit(Sensor_Enum PositionSensor_identifier);
float PositionSensor_get(float unit, Sensor_Enum PositionSensor_identifier);

#ifdef __cplusplus
 }
#endif

#endif // _POSITION_SENSOR_H
