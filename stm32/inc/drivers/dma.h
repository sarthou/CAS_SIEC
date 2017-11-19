/**
 * @file    dma.h
 * @author  Curtis Team
 * @brief   Headers of functions to handle DMA  
 */
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _DMA_H
#define _DMA_H

/* Includes ------------------------------------------------------------------*/
#include "drivers/common_def.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
void DMA_QuickInit_Periph2Buffer(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t PeripheralBaseAddr, uint32_t PeripheralDataSize, uint32_t MemoryBaseAddr, uint32_t MemoryDataSize, uint32_t MemoryBufferSize);
void DMA_QuickInit_Buffer2Periph(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t PeripheralBaseAddr, uint32_t PeripheralDataSize, uint32_t MemoryBaseAddr, uint32_t MemoryDataSize, uint32_t MemoryBufferSize);

void DMA_Callback(DMA_Channel_TypeDef* DMAy_Channelx, uint8_t itstatus);

#ifdef __cplusplus
 }
#endif

#endif // _DMA_H
