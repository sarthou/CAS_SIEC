/**
 * @file    motors.h
 * @author  Curtis Team
 * @brief   Headers of functions to handle motors
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _MOTORS_H
#define _MOTORS_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include "stm32f10x.h"
#include "config/common_constants.h"
#include "config/modules_definitions.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/**
 * @brief       Variation of the speed command value between its maximum or minimum value and the zero
*/
#define MOTORS_SPEED_DELTA                  ((float)1.0)

/**
 * @brief       Speed command value used to turn the motors forwards(+) or backwards(-) to their maximum
*/
#define MOTORS_SPEED_MAX                    (MOTORS_SPEED_DELTA)

/* Exported macro ------------------------------------------------------------*/
/* Exported variables --------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
void Motor_QuickInit(Motors_Enum Motor);
void Motor_setSpeed(Motors_Enum Motor, float speed);
void Motor_Disable(Motors_Enum Motor);
void Motor_Enable(Motors_Enum Motor);
int16_t Motor_getCurrent(Motors_Enum Motor);

#ifdef __cplusplus
 }
#endif

#endif // _MOTORS_H
