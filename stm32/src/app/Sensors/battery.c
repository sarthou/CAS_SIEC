/**
 * @file    battery.c
 * @author  Curtis Team
 * @refact  Team Darlene : Sarthou
 * @brief   Functions to handle battery   
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app/Sensors/battery.h"
#include "config/modules_definitions.h"
#include "config/common_constants.h"
#include "drivers/adc.h"

#include <math.h>

#include "app/CAN/CAN_Abstraction.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
uint8_t last_battery = 110; // impossible percent value
/* Private function prototypes -----------------------------------------------*/
/* Public functions ----------------------------------------------------------*/
/**
 * @brief   Inits the battery. 
 * @retval  None
*/
void Battery_QuickInit(void)
{
    ADC_QuickInit(BATTERY_ADC, BATTERY_GPIO, BATTERY_PIN, BATTERY_RANK, BATTERY_SAMPLING);
}

/**
 * @brief   Returns the charge of the battery
 * @retval  Charge of the battery (in percentage)
*/
uint8_t Battery_get(void)
{
    uint16_t BatteryValue = ADC_QuickGet(BATTERY_ADC, BATTERY_RANK);
    return PERCENTAGE*(BatteryValue - BATTERY_ADC_SCALE)/BATTERY_ADC_SCALE;
}

void Battery_Callback(uint64_t time_ms)
{
	if((time_ms % 500) == 0)
	{
		uint8_t current_bat = Battery_get();
		if(fabs(last_battery - current_bat) > 2)
		{
			if(sendMessageChar(0x200, current_bat) == 0)
				last_battery = current_bat;
		}
	}
}

/* Private functions ---------------------------------------------------------*/
