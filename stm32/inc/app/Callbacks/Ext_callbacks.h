/**
 * @file    Ext_callbacks.h
 * @author  Team Darlene : Sarthou
 * @brief   Headers of functions to manage callbacks for Drivers_Car layer 
 */
 
#ifndef EXT_CALLBACKS_H
#define EXT_CALLBACKS_H

#include <stdint.h>
#include <stddef.h>
#include <stm32f10x.h>
#include "config/modules_definitions.h"

#ifdef __cplusplus
 extern "C" {
#endif

void HallSensor_Handler(Sensor_Enum hall_identifier);

#ifdef __cplusplus
 }
#endif

#endif // EXT_CALLBACKS_H
