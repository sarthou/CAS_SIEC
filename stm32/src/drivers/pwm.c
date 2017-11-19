/**
 * @file 	pwm.c
 * @author  Curtis Team
 * @brief 	Functions to handle SPI
*/

/* Includes ------------------------------------------------------------------*/
#include "drivers/pwm.h"
#include "drivers/tim.h"
#include "drivers/gpio.h"
#include "config/common_constants.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/**
 * @brief Recommended mode for initilization of GPIO when used as PWM
*/
#define PWM_GPIO_MODE GPIO_Mode_AF_PP

/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
void pwm_gpio_init(TIM_TypeDef *TIMx, uint16_t Channelx);

/* Public functions ----------------------------------------------------------*/
/**
 * @brief Makes the initialization of the PWM with the parameters specified
 * @param 
*/
void PWM_QuickInit(TIM_TypeDef *TIMx, uint16_t Channelx, float frequencyPWMHz) {
    float duree_pwm_usec = US_PER_S/frequencyPWMHz;
    TIM_OCInitTypeDef  TIM_OCInitStructure;
    
    pwm_gpio_init(TIMx,Channelx);

    TIM_QuickInit(TIMx, duree_pwm_usec);

    /* always initialise local variables before use */
    TIM_OCStructInit (&TIM_OCInitStructure);
 
    /* Common settings for all channels */
    TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
    TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
    TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
    TIM_OCInitStructure.TIM_Pulse = 0;
    
            if(Channelx == TIM_Channel_1)  TIM_OC1Init(TIMx, &TIM_OCInitStructure); 
    else    if(Channelx == TIM_Channel_2)  TIM_OC2Init(TIMx, &TIM_OCInitStructure);
    else    if(Channelx == TIM_Channel_3)  TIM_OC3Init(TIMx, &TIM_OCInitStructure);
    else    if(Channelx == TIM_Channel_4)  TIM_OC4Init(TIMx, &TIM_OCInitStructure);
    
    if(TIMx == TIM1) TIM_CtrlPWMOutputs(TIMx, ENABLE); else{}
}
    
/**
 * @brief   Makes the initialization of the complementary channel of the PWM with the parameters specified
 * @param   TIMx Timer to use
 * @param   Channelx Channel to use
 * @retval  0 if everything went right, -1 if unexpected remap type according to chosen Timer, -2 if Timer is not available for PWM complementary (only TIM1 is available), -3 is channel is not available.
*/
//int PWM_QuickInit_Complementary(TIM_TypeDef *TIMx, uint16_t Channelx) {
//    TIM_remap_TypeDef remap = TIM_RemapStatus(TIMx);
////remap = PartialRemap1;
//    TIM_CCxNCmd (TIMx, Channelx, TIM_CCxN_Enable);
//    
//    if (TIMx != TIM1) return -2; 
//    else {
//        if (remap == DefaultRemap) {
//            switch (Channelx) {
//                case TIM_Channel_1: GPIO_QuickInit(GPIOB, GPIO_Pin_13, PWM_GPIO_MODE); break;
//                case TIM_Channel_2: GPIO_QuickInit(GPIOB, GPIO_Pin_14, PWM_GPIO_MODE); break;
//                case TIM_Channel_3: GPIO_QuickInit(GPIOB, GPIO_Pin_15, PWM_GPIO_MODE); break;
//                default: return -3; break;
//            }
//        }
//        else if (remap == PartialRemap1) {
//            switch (Channelx) {
//                RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
//                case TIM_Channel_1: GPIO_QuickInit(GPIOA, GPIO_Pin_7, PWM_GPIO_MODE); break;
//                case TIM_Channel_2: GPIO_QuickInit(GPIOB, GPIO_Pin_0, PWM_GPIO_MODE); break;
//                case TIM_Channel_3: GPIO_QuickInit(GPIOB, GPIO_Pin_1, PWM_GPIO_MODE); break;
//                default: return -3; break;
//            }
//        }
//        else if (remap == PartialRemap2) {
//            return -1;
//        }
//        else    if (remap == FullRemap) {
//            return -1;
//        }
//        else {}
//    }
//    return 0;
//}
/// The code above set complementary on remap pins by default
int PWM_QuickInit_Complementary(TIM_TypeDef *TIMx, uint16_t Channelx) {
    TIM_CCxNCmd	(TIMx, Channelx,TIM_CCxN_Enable);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
    GPIO_PinRemapConfig(GPIO_PartialRemap_TIM1, ENABLE);
    switch (Channelx) {
     case TIM_Channel_1: GPIO_QuickInit(GPIOA, GPIO_Pin_7, PWM_GPIO_MODE); break;
     case TIM_Channel_2: GPIO_QuickInit(GPIOB, GPIO_Pin_0, PWM_GPIO_MODE); break;
     case TIM_Channel_3: GPIO_QuickInit(GPIOB, GPIO_Pin_1, PWM_GPIO_MODE); break;
     default: break;
    }
    return 0;
}

/**
 * @brief   Sets the duty cycle of the PWM generated by given Timer and Channel
 * @param   TIMx Timer to use
 * @param   Channelx Channel to use
 * @param   dutyCycle Duty cycle value. dutyCycle must be between 0.0 and 1.0
 * @retval  none
*/
void PWM_SetDutyCycle(TIM_TypeDef *TIMx, uint16_t Channelx, float dutyCycle) {
    volatile uint16_t pulse_length = 0; // nbre entier non sign� de 16 bits
    uint16_t resolution;

    resolution = TIMx->ARR;

    pulse_length = (uint16_t)((float)resolution*dutyCycle);  

    switch(Channelx) {
        case TIM_Channel_1 : TIM_SetCompare1(TIMx,pulse_length); break;
        case TIM_Channel_2 : TIM_SetCompare2(TIMx,pulse_length); break;
        case TIM_Channel_3 : TIM_SetCompare3(TIMx,pulse_length); break;
        case TIM_Channel_4 : TIM_SetCompare4(TIMx,pulse_length); break;
        default: break;
    }
}

/**
 * @brief   Starts PWM
 * @param   TIMx Timer to use
 * @retval  none
*/
void PWM_Start(TIM_TypeDef *TIMx) {
    TIM_Start(TIMx);
}

/**
 * @brief   Stops PWM
 * @param   TIMx Timer to use
 * @retval  none
*/
void PWM_Stop(TIM_TypeDef *TIMx) {
    TIM_Stop(TIMx);
}

/* Private functions ---------------------------------------------------------*/
/**
 * @brief   Makes the initialization of the GPIO supporting the PWM chosen
 * @param   TIMx Timer to use
 * @param   Channelx Channel to use
 * @retval  none
*/
void pwm_gpio_init(TIM_TypeDef *TIMx, uint16_t Channelx) {
    if (TIMx == TIM1) {
        switch (Channelx) {
            case TIM_Channel_1: GPIO_QuickInit(GPIOA, GPIO_Pin_8 , PWM_GPIO_MODE); break;
            case TIM_Channel_2: GPIO_QuickInit(GPIOA, GPIO_Pin_9 , PWM_GPIO_MODE); break;
            case TIM_Channel_3: GPIO_QuickInit(GPIOA, GPIO_Pin_10, PWM_GPIO_MODE); break;
            case TIM_Channel_4: GPIO_QuickInit(GPIOA, GPIO_Pin_11, PWM_GPIO_MODE); break;
            default: break;
        }
    }
    else if (TIMx == TIM2) {
        switch (Channelx) {
            case TIM_Channel_1: GPIO_QuickInit(GPIOA, GPIO_Pin_0, PWM_GPIO_MODE); break;
            case TIM_Channel_2: GPIO_QuickInit(GPIOA, GPIO_Pin_1, PWM_GPIO_MODE); break;
            case TIM_Channel_3: GPIO_QuickInit(GPIOA, GPIO_Pin_2, PWM_GPIO_MODE); break;
            case TIM_Channel_4: GPIO_QuickInit(GPIOA, GPIO_Pin_3, PWM_GPIO_MODE); break;
            default: break;
        }
    }
    else if (TIMx == TIM3) {
        switch (Channelx) {
            case TIM_Channel_1: GPIO_QuickInit(GPIOA, GPIO_Pin_6, PWM_GPIO_MODE); break;
            case TIM_Channel_2: GPIO_QuickInit(GPIOA, GPIO_Pin_7, PWM_GPIO_MODE); break;
            case TIM_Channel_3: GPIO_QuickInit(GPIOB, GPIO_Pin_0, PWM_GPIO_MODE); break;
            case TIM_Channel_4: GPIO_QuickInit(GPIOB, GPIO_Pin_1, PWM_GPIO_MODE); break;
            default: break;
        }
    }
    else if (TIMx == TIM4) {
        switch (Channelx) {
            case TIM_Channel_1: GPIO_QuickInit(GPIOB, GPIO_Pin_6, PWM_GPIO_MODE); break;
            case TIM_Channel_2: GPIO_QuickInit(GPIOB, GPIO_Pin_7, PWM_GPIO_MODE); break;
            case TIM_Channel_3: GPIO_QuickInit(GPIOB, GPIO_Pin_8, PWM_GPIO_MODE); break;
            case TIM_Channel_4: GPIO_QuickInit(GPIOB, GPIO_Pin_9, PWM_GPIO_MODE); break;
            default: break;
        }
    }
} 
