/**
 * @file    front_motor.c
 * @author  Curtis Team
 * @brief   Functions to handle front motor  
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app/Motors/front_motor.h"
#include "app/Motors/motors.h"
#include "app/Sensors/direction.h"

#include "car_types.h"

#include "drivers/exti.h"

/* Private typedef -----------------------------------------------------------*/
#define FRONT_CONTROL 1 //1 for true; 0 for false

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
    Direction_QuickInit();
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

/*void RearMotors_Callback(uint64_t time_ms)
{
	if(time_ms%10 == 0) // MOTORS_COMMAND_TIME_BETWEEN_TWO_UPDATES
	{
		if(FRONT_CONTROL)
		{
			 RearMotor_controlL(speed_cmd);
			 RearMotor_controlR(speed_cmd);
		}
		else
		{
			int16_t motor_speed = (float)(speed_cmd/10.0); //reduce speed in case of non-control
			Motor_setSpeed(REAR_MOTOR_R, motor_speed);
			Motor_setSpeed(REAR_MOTOR_L, motor_speed);
		}
	}
}*/
/*if (direction ==  LEFT)
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
}*/

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
