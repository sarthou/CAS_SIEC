/**
 * @file    system_time.h
 * @author  Curtis Team
 * @refact  Team Darlene : Sarthou
 * @brief   Headers of functions to manage time
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _SYSTEM_TIME_H
#define _SYSTEM_TIME_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include "stm32f10x.h"

extern uint64_t time_millis; // add by Lucien
/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

/* Exported functions ------------------------------------------------------- */
void System_Time_QuickInit(void);

void SysTick_Callback(void);

uint64_t millis(void);

void pause(uint16_t ms);

#ifdef __cplusplus
}
#endif

#endif // _SYSTEM_TIME_H
