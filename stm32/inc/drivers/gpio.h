/**
 * @file    gpio.h
 * @author  Curtis Team
 * @brief   Headers of functions to handle GPIO
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _GPIO_H
#define _GPIO_H

/* Includes ------------------------------------------------------------------*/
#include "drivers/common_def.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
void GPIO_QuickInit(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin, GPIOMode_TypeDef GPIO_Mode);

#ifdef __cplusplus
 }
#endif

#endif // _GPIO_H
