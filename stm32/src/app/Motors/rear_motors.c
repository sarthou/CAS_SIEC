/**
 * @file    rear_motors.c
 * @author  Curtis Team
 * @brief   Functions to handle rear motors
 */
 
 /* Includes ------------------------------------------------------------------*/
#include "app/Motors/rear_motors.h"
#include "stm32f10x_conf.h"
#include <math.h>
#include "app/Motors/motors.h"

#include "system_time.h"
#include "drivers/common_def.h"

#include "app/Sensors/position_sensors.h"
#include "app/Sensors/speed_sensors.h"
#include "app/Sensors/hall_sensors.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define REAR_CONTROL 1 //1 for true; 0 for false

// PI controller
#define Kp_R 0.1f//0.015f

#define Kp_L 0.1f//0.015f

#define T 0.01f                // 100hz control loop frequency
/* Private macro -------------------------------------------------------------*/
/* Public variables ----------------------------------------------------------*/
/**
 * @brief   Measured Current in the motor
*/
int16_t current = 0; 

/**
 * @brief   Last measured car speed on left wheel
*/
volatile static float car_total_distance_L = 0;

/**
 * @brief   Last measured car speed on right wheel
*/
volatile static float car_total_distance_R = 0;

/**
 * @brief   Expected speed on the wheel
*/
int16_t speed_cmd_L = 0;
int16_t speed_cmd_R = 0;

/**
 * @brief   Duty cycle applied on left motor
*/
volatile static float duty_cycle_L = MOTORS_PWM_ZERO;

/**
 * @brief   Duty cycle applied on right motor
*/
volatile static float duty_cycle_R = MOTORS_PWM_ZERO;

/**
 * @brief   Formal output of the system
*/
static float out_prec = 0;

uint8_t is_init = 0;

/* Private function prototypes -----------------------------------------------*/
int16_t car_model(float in);
float ComputeMotorCommand_L(float speed_cmd, float position);
float ComputeMotorCommand_R(float speed_cmd, float position);
void RearMotor_controlL(int16_t speed_cmd);
void RearMotor_controlR(int16_t speed_cmd);

/* Public functions ----------------------------------------------------------*/
//create this function into your communication interface
__weak void GetRearMotors(int16_t* speed_L, int16_t* speed_R) {}

/**
 * @brief   Initializes rear motors
 * @retval  None
*/
void RearMotors_QuickInit(void)
{
    Motor_QuickInit(REAR_MOTOR_L);
    Motor_QuickInit(REAR_MOTOR_R);
    
    SpeedSensor_QuickInit(SENSOR_L);
    SpeedSensor_QuickInit(SENSOR_R);

    PositionSensor_QuickInit(SENSOR_L);
    PositionSensor_QuickInit(SENSOR_R);

    is_init = 1;
}

/**
 * @brief   Allows rear motors to spin
 * @retval  None
*/
void RearMotors_Enable(void)
{
    Motor_Enable(REAR_MOTOR_L);
    Motor_Enable(REAR_MOTOR_R);
}

/**
 * @brief   Forbides rear motors to spin
 * @retval  None
*/
void RearMotors_Disable(void)
{
    Motor_Disable(REAR_MOTOR_L);
    Motor_Disable(REAR_MOTOR_R);
}

/**
 * @brief   Callback associated to rear motors whose aim is to set the adequate command on the motor 
 * @retval	None
*/
void RearMotors_Callback(uint64_t time_ms)
{
	if(is_init)
	{
		if(time_ms%10 == 0) // MOTORS_COMMAND_TIME_BETWEEN_TWO_UPDATES
		{
			GetRearMotors(&speed_cmd_L, &speed_cmd_R);
			if(REAR_CONTROL)
			{
				 RearMotor_controlL(speed_cmd_L);
				 RearMotor_controlR(speed_cmd_R);
			}
			else
			{
				float motor_speed_L = (float)(speed_cmd_L/10.0); //reduce speed in case of non-control
				float motor_speed_R = (float)(speed_cmd_R/10.0); //reduce speed in case of non-control
				Motor_setSpeed(REAR_MOTOR_R, motor_speed_L);
				Motor_setSpeed(REAR_MOTOR_L, motor_speed_R);
			}
		}
	}
}

/**
 * @brief   Sets speed which must be regulated. 
 * @param   speed Expected speed (in cm/s)
 * @retval	None
*/
void RearMotors_setSpeed(int16_t speed_L, int16_t speed_R)
{
    speed_cmd_L = speed_L;
    speed_cmd_R = speed_R;
}
/* Private functions ---------------------------------------------------------*/
/**
 * @brief   [for debug only] Calculates system answer according to its input.
 * @param   in The input of the system.
 * @retval	System output.
*/
int16_t car_model(float in)
{
    float K_model = 250.0;   // speed in cm/s
    float T_model = 0.1;
    int16_t out;
    out = (K_model * (float)(in-MOTORS_PWM_ZERO) - T_model * out_prec);
    out_prec = (float)out;
    return out;
}

/**
 * @brief   Computes the next iteration Motor Duty-Cycle command (left wheel)
 * @param   speed_cmd The speed input command for the control loop (cm/s)
 * @param   current Current in the motor (mA)
 * @param   speed The car speed (cm/s)
 * @retval	The duty-cycle command for the motor
*/
float ComputeMotorCommand_L (float speed_cmd, float position)
{
    float dc;         //out duty cycle;
    
    car_total_distance_L += speed_cmd*0.01f;

	float error = (float)(car_total_distance_L - position);
	dc = error * Kp_L;
    
    return dc;
}


/**
 * @brief   Computes the next iteration Motor Duty-Cycle command (right wheel)
 * @param   speed_cmd The speed input command for the control loop (cm/s)
 * @param   current Current in the motor (mA)
 * @param   speed The car speed (cm/s)
 * @retval	The duty-cycle command for the motor
*/
float ComputeMotorCommand_R (float speed_cmd, float position)
{
    float dc;         //out duty cycle;
    
    car_total_distance_R += speed_cmd*0.01f;

	float error = (float)(car_total_distance_R - position);
	dc = error * Kp_R;

    return dc;
}

/**
 * @brief   The core of the control loop for rear motor left
 * @param   speed_cmdL The speed command
 * @retval	None
*/
void RearMotor_controlL(int16_t speed_cmd)
{
    // Command must be send without jitter...
    Motor_setSpeed(REAR_MOTOR_L, duty_cycle_L);

    // ... so we need to compute the command for next send.
    float car_speed_L = SpeedSensor_get(SPEED_CM_S, SENSOR_L);
    float car_position_L = PositionSensor_get(POSITION_CM, SENSOR_L);

    duty_cycle_L = ComputeMotorCommand_L(speed_cmd, car_position_L);

    float error = car_speed_L - speed_cmd;
}

/**
 * @brief   The core of the control loop for rear motor left
 * @param   speed_cmdR The speed command
 * @retval	None
*/
void RearMotor_controlR(int16_t speed_cmd)
{
	// Command must be send without jitter...
	Motor_setSpeed(REAR_MOTOR_R, duty_cycle_R);

	// ... so we need to compute the command for next send.
	float car_speed_R = SpeedSensor_get(SPEED_CM_S, SENSOR_R);
	float car_position_R = PositionSensor_get(POSITION_CM, SENSOR_R);

	duty_cycle_R = ComputeMotorCommand_R(speed_cmd, car_position_R);

	float error = car_speed_R - speed_cmd;
}

