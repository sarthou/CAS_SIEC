/**
 * @file    Ext_callbacks.c
 * @author  Curtis Team
 * @brief   Functions to manage callbacks for Drivers_Car layer 
 */
 
/* Includes ------------------------------------------------------------------*/
#include "drivers/common_def.h"
#include "app/Callbacks/Ext_callbacks.h"
#include "config/common_constants.h"
#include "config/modules_definitions.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

__weak void HallSensor_Handler(Sensor_Enum hall_identifier) {}

void EXTI_Callback(uint32_t EXTI_Line)
{
    if (EXTI_Line == SENSOR_L_LINE) HallSensor_Handler(SENSOR_L);
    if (EXTI_Line == SENSOR_R_LINE) HallSensor_Handler(SENSOR_R);
}

/* Private functions ---------------------------------------------------------*/
