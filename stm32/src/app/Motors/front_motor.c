/**
 * @file    front_motor.c
 * @author  Curtis Team
 * @refact  Team Darlene : Sarthou
 * @brief   Functions to handle front motor  
 */
 
/* Includes ------------------------------------------------------------------*/
#include "app/Motors/front_motor.h"
#include "app/Motors/motors.h"
#include "app/Sensors/direction.h"

#include "car_types.h"

#include "drivers/exti.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define FRONT_CONTROL 	1 //1 for true; 0 for false

#define LEFT_ANGLE 		0xA7
#define CENTER_ANGLE 	0x8D
#define RIGHT_ANGLE		0x72

/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
int8_t angle_cmd = 0;

// PI controller
#define Kp 0.05f
#define Ki 0.0f

uint8_t delta_angle = 0;

/**
 * @brief   Duty cycle applied on direction motor
*/
float duty_cycle = MOTORS_PWM_ZERO;

/* Private function prototypes -----------------------------------------------*/
void DirectionMotor_control(int8_t angle_cmd);
float ComputeMotorCommand(uint8_t commande, uint8_t real_angle);

//create this function into your communication interface
__weak void GetDirectionMotor(int8_t* angle) {}

/* Public functions ----------------------------------------------------------*/
/**
 * @brief   Initialisation of Exti use for front motor
 * @retval  None
*/
void FrontMotor_QuickInit(void)
{
    Motor_QuickInit(FRONT_MOTOR);
    Direction_QuickInit();
    if((LEFT_ANGLE - CENTER_ANGLE) < (CENTER_ANGLE - RIGHT_ANGLE))
    	delta_angle = LEFT_ANGLE - CENTER_ANGLE;
    else
    	delta_angle = CENTER_ANGLE - RIGHT_ANGLE;
    Motor_Enable(FRONT_MOTOR);
}

void DirectionMotor_Callback(uint64_t time_ms)
{
	if(time_ms%10 == 0) // MOTORS_COMMAND_TIME_BETWEEN_TWO_UPDATES
	{
		GetDirectionMotor(&angle_cmd);
		if(FRONT_CONTROL)
		{
			 DirectionMotor_control(angle_cmd);
		}
		else
			Motor_setSpeed(FRONT_MOTOR, 0);
	}
}

/* Private functions ---------------------------------------------------------*/
void DirectionMotor_control(int8_t cmd_angle)
{
	// Command must be send without jitter...
	//motor_speed = (duty_cycle - MOTORS_PWM_ZERO) / ((MOTORS_PWM_DELTA_MAX)/(MOTORS_SPEED_DELTA));
	Motor_setSpeed(FRONT_MOTOR, duty_cycle);

	// ... so we need to compute the command for next send.
	uint8_t real_angle = Direction_get();
	uint8_t commande = (uint8_t)((float)(cmd_angle*delta_angle/100.0f) + CENTER_ANGLE);
	duty_cycle = ComputeMotorCommand(commande, real_angle);
}

float ComputeMotorCommand(uint8_t commande, uint8_t real_angle)
{
	 float dc;         //out duty cycle;

	 if (commande != 0)
	 {
		 float error = (float)(commande - real_angle);
		 dc = error * Kp;
	 }
	 else
		 dc = (float)MOTORS_PWM_ZERO;

	 return dc;
}
