/**
 * @file    direction.c
 * @author  L.Senaneuch
 * @refact  Team Darlene : Sarthou
 * @brief   Functions to handle direction   
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app/Sensors/direction.h"
#include "config/modules_definitions.h"
#include "config/common_constants.h"
#include "drivers/adc.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
//create this function into your communication interface
__weak void SetSteeringWheel(uint8_t angle) {}

/* Public functions ----------------------------------------------------------*/
/**
 * @brief   Inits the direction. 
 * @retval  None
*/
void Direction_QuickInit(void)
{
    ADC_QuickInit(DIRECTION_ADC, DIRECTION_GPIO, DIRECTION_PIN, DIRECTION_RANK, DIRECTION_SAMPLING);
}

/**
 * @brief   Returns the direction value in degree
 * @retval  direction
*/
uint8_t Direction_get(void) {
    uint16_t DirectionValue = ADC_QuickGet(DIRECTION_ADC, DIRECTION_RANK);
    SetSteeringWheel(DirectionValue>>4);
	return (DirectionValue>>4);
}

/* Private functions ---------------------------------------------------------*/
