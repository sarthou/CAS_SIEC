/**
 * @file    systick.h
 * @author  Curtis Team
 * @brief   Headers of functions to handle systick (STM internal time)  
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _SYSTICK_H
#define _SYSTICK_H

/* Includes ------------------------------------------------------------------*/
#include "drivers/common_def.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/**
 * @brief Frequency to count systicks 
*/
#define SYSTICK_FREQ  1000 // Hz

/**
 * @brief Unit used by the system to count time 
*/
#define SYSTICK_UNIT  (1.0/SYSTICK_FREQ) // s

/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
void SysTick_QuickInit(void);
void SysTick_Callback(void);

#ifdef __cplusplus
 }
#endif

#endif // _SYSTICK_H
