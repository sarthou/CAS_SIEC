/**
 * @file    debug.h
 * @author  Curtis Team
 * @brief   Headers of functions to help debugging  
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DEBUG_H
#define _DEBUG_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <stdint.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
int fputc(int ch, FILE *f);
void dbg_sleep(uint32_t ms);

#ifdef __cplusplus
 }
#endif

#endif // _DEBUG_H
