/**
 * @file 	pwm.h
 * @author 	Curtis Team
 * @brief 	Headers of functions to handle PWM
*/
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _PWM_H
#define _PWM_H

/* Includes ------------------------------------------------------------------*/
#include "drivers/common_def.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/

#ifdef __cplusplus
 extern "C" {
#endif

/* Exported functions ------------------------------------------------------- */
void PWM_QuickInit(TIM_TypeDef *TIMx, uint16_t Channelx, float frequencyPWMHz);
int PWM_QuickInit_Complementary(TIM_TypeDef *TIMx, uint16_t Channelx);
void PWM_SetDutyCycle(TIM_TypeDef *TIMx, uint16_t Channelx, float dutyCycle);
void PWM_Start(TIM_TypeDef *TIMx);
void PWM_Stop(TIM_TypeDef *TIMx);

#ifdef __cplusplus
 }
#endif

#endif // _PWM_H
