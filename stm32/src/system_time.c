/**
 * @file    system_time.c
 * @author  Curtis Team
 * @brief   Functions to manage time  
 */
 
/* Includes ------------------------------------------------------------------*/

#include "system_time.h"
#include "drivers/systick.h"
#include "app/CAN/CAN_Periodic.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/**
 * @brief   Current STM32 time (expressed in milliseconds)
*/
uint64_t time_millis; // added by L.S
/* Private function prototypes -----------------------------------------------*/
/* Public functions ----------------------------------------------------------*/

__weak void HallSensor_TimeCallback(void) {}
__weak void Manager_Callback(void) {}

__weak void RearMotors_Callback(uint64_t time_ms) {}
__weak void DirectionMotor_Callback(uint64_t time_ms) {}

__weak void Battery_Callback(uint64_t time_ms) {}
    
/**
 * @brief   Makes the initialization of time for the whole system 
 * @retval  None
*/
void System_Time_QuickInit(void) {
    time_millis = 0;
    SystemCoreClock = 64000000;
    SystemCoreClockUpdate();
    SysTick_QuickInit();
}

/**
 * @brief   Callback associated to SysTick. 
 * Please add here your periodic functions
 * @retval  None
*/
void SysTick_Callback(void) {
		
	// Time increment 
	time_millis ++;

	CanCallback(time_millis);

	HallSensor_TimeCallback();
	RearMotors_Callback(time_millis);

	DirectionMotor_Callback(time_millis);

	Battery_Callback(time_millis);

	//Manager_Callback();
}

/**
 * @brief       Returns the current STM32 time
 * @return      uint64_t Time elapsed since initialization 
 * @retval      Result is expressed in ms 
*/
uint64_t millis(void) {
  return time_millis;
}

/**
 * @brief       Pauses the system during the specified time
 * @param       ms Expected pause length (expressed in milliseconds)
 * @retval      None
*/
void pause(uint16_t ms) {
    uint64_t arrivalTime = time_millis;
    while (time_millis < arrivalTime + ms) {}
}

/* Private functions ---------------------------------------------------------*/
