/**
 * @file    battery.h
 * @author  Curtis Team
 * @brief   Headers of functions to handle battery 
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _BATTERY_H
#define _BATTERY_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
extern "C"{
#endif

/* Exported functions ------------------------------------------------------- */
void Battery_QuickInit(void);
uint8_t Battery_get(void);

//this is a weak function first declared in system_time
void Battery_Callback(uint64_t time_ms);

#ifdef __cplusplus
}
#endif

#endif // _BATTERY_H
