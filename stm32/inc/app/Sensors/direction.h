/**
 * @file    direction.h
 * @author  L.S
 * @brief   Headers of functions to handle Direction value
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DIRECTION_H
#define _DIRECTION_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include <stddef.h>
#include "stm32f10x.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
void Direction_QuickInit(void);
uint8_t Direction_get(void);

#ifdef __cplusplus
 }
#endif

#endif // _DIRECTION_H
