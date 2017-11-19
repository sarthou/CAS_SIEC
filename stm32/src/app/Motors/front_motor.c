/**
 * @file    front_motor.c
 * @author  Curtis Team
 * @brief   Functions to handle front motor  
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app/Motors/front_motor.h"
#include "app/Motors/motors.h"

#include "car_types.h"

#include "drivers/exti.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/**
 * @brief   Front motor speed when turning left
*/
#define FRONT_MOTOR_SPEED_L               0.8

/**
 * @brief   Front motor speed when turning right
*/
#define FRONT_MOTOR_SPEED_R               -FRONT_MOTOR_SPEED_L

/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
side_TypeDef FrontMotor_position = NONE;
side_TypeDef FrontMotor_order = NONE;

/* Private function prototypes -----------------------------------------------*/
void turn_left(void);
void turn_right(void);
void turn_stop(void);

/* Public functions ----------------------------------------------------------*/
/**
 * @brief   Initialisation of Exti use for front motor
 * @retval  None
*/
void FrontMotor_QuickInit(void)
{
    Motor_QuickInit(FRONT_MOTOR);
}

/**
 * @brief   Check the front motor's position before set an order to front motor to turn right or left
 * @param   direction Direction of front motor
*/
void FrontMotor_turn(side_TypeDef direction)
{
	if (direction == LEFT)
	{
		if (FrontMotor_position != LEFT)
		{
            turn_left();
            FrontMotor_order = LEFT;
			FrontMotor_position = NONE;           
		}
	}
	else if (direction == RIGHT)
	{
		if (FrontMotor_position != RIGHT)
		{
			turn_right();
			FrontMotor_order = RIGHT;
			FrontMotor_position = NONE;
		}
	}
	else
		turn_stop();
}

/**
 * @brief   Callback service for front motor: Once the Exti rised for one direction(left or right), set the speed equals to zero and get the current position(direction)
 * @param   direction Direction of front motor
 * @retval  None
*/
void FrontMotor_Handler(side_TypeDef direction)
{
	if (direction ==  LEFT)
	{
		FrontMotor_order = NONE;
		FrontMotor_position = LEFT;
        turn_stop();
	}
	else if (direction ==  RIGHT)
	{
		FrontMotor_order = NONE;
		FrontMotor_position = RIGHT;
        turn_stop();
	}
}

/* Private functions ---------------------------------------------------------*/
/**
 * @brief   Gives an order to front motor to turn left
 * @param   None
*/
void turn_left(void)
{
	Motor_setSpeed(FRONT_MOTOR, FRONT_MOTOR_SPEED_L);
    Motor_Enable(FRONT_MOTOR);
}

/**
 * @brief   Gives an order to front motor to turn right
 * @param   None
*/
void turn_right(void)
{
	Motor_setSpeed(FRONT_MOTOR, FRONT_MOTOR_SPEED_R);
    Motor_Enable(FRONT_MOTOR);
}

/**
 * @brief   Stops the front motor
 * @param   None
*/
void turn_stop(void)
{
    Motor_setSpeed(FRONT_MOTOR, (float) NONE);
    Motor_Disable(FRONT_MOTOR);
}
