/**
 * @file    exti.h
 * @author  Curtis Team
 * @brief   Headers of functions to handle external interrupts (EXTI)  
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _EXTI_H
#define _EXTI_H

/* Includes ------------------------------------------------------------------*/
#include "drivers/common_def.h"
#include "drivers/gpio.h"
#include "drivers/nvic.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/**
 * @brief Given pin was succesfully initialize as external interruption
*/
#define EXTI_NO_ERROR                  0

/**
 * @brief Given pin couldn't be initialize as external interruption due to a non valid line
*/ 
#define EXTI_ERROR_INVALID_LINE        -1

/**
 * @brief Given pin couldn't be initialize as external interruption due to a problem while computing channel
*/ 
#define EXTI_ERROR_INVALID_CHANNEL     -2

/**
 * @def EXTI_ERROR_INVALID_PORT_SOURCE
 * @brief Given port couldn't be found
*/ 
#define EXTI_ERROR_INVALID_PORT_SOURCE -3

/**
 * @def EXTI_ERROR_INVALID_PIN_SOURCE
 * @brief Given pin couldn't be found
*/ 
#define EXTI_ERROR_INVALID_PIN_SOURCE  -4

/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
int EXTI_QuickInit(GPIO_TypeDef *GPIOx, uint16_t pin, EXTITrigger_TypeDef trigger, uint8_t priority);
int EXTI_ReInit(GPIO_TypeDef *GPIOx, uint16_t pin, EXTITrigger_TypeDef trigger, uint8_t priority);

void EXTI_Callback(uint32_t EXTI_Line);

#ifdef __cplusplus
 }
#endif

#endif // _EXTI_H
