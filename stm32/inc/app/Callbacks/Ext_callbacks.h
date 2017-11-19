/**
 * @file    Ext_callbacks.h
 * @author  Curtis Team
 * @brief   Headers of functions to manage callbacks for Drivers_Car layer 
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DRIVER_CALLBACKS_H
#define _DRIVER_CALLBACKS_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include <stm32f10x.h>
#include "config/common_constants.h"
#include "config/modules_definitions.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#ifdef __cplusplus
 extern "C" {
#endif

void HallSensor_Handler(Sensor_Enum hall_identifier);

#ifdef __cplusplus
 }
#endif

#endif // _DRIVER_CALLBACKS_H
