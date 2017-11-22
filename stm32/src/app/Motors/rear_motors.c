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

#include "app/Sensors/speed_sensors.h"
#include "app/Sensors/hall_sensors.h"
//#include "data_interface.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define REAR_CONTROL 0 //1 for true; 0 for false

// PI controller
#define Kp_R 0.00005f
#define Ki_R 0.0f

#define Kp_L 0.00005
#define Ki_L 0.0f

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
volatile static int16_t car_speed_L = 0;

/**
 * @brief   Last measured car speed on right wheel
*/
volatile static int16_t car_speed_R = 0;

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

/* Private function prototypes -----------------------------------------------*/
int16_t car_model(float in);
float PI_Controller_L (int32_t in);
float PI_Controller_R (int32_t in);
float ComputeMotorCommand_L(int16_t speed_cmd, int16_t current, int16_t speed);
float ComputeMotorCommand_R(int16_t speed_cmd, int16_t current, int16_t speed);
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
float ComputeMotorCommand_L (int16_t speed_cmd, int16_t current, int16_t speed){
    
    float dc;         //out duty cycle;
    volatile int32_t in_PI;
    float current_f = (float)current;
    volatile float coef_in_PI;   // to adjust PI input depending on how close from MAX_CURRENT we are
    
    if (speed_cmd != 0)
    {
        // duty cycle is 50 if current reaches MAX_CURRENT
        if (fabs(current_f) > MAX_CURRENT)
            dc = (uint8_t)MOTORS_PWM_ZERO;
        else // If MAX_CURRENT is not reached
        {
            // PI controller input depends on how close from MAX_CURRENT is the current
            coef_in_PI = (MAX_CURRENT - fabs(current_f)) / MAX_CURRENT;
            in_PI = (int32_t)((float)((int32_t)speed_cmd - (int32_t)speed) * coef_in_PI);
            dc = PI_Controller_L(in_PI) ; 
        }
    }
    else
        dc = (float)MOTORS_PWM_ZERO;
    
    return dc;
}


/**
 * @brief   Computes the next iteration Motor Duty-Cycle command (right wheel)
 * @param   speed_cmd The speed input command for the control loop (cm/s)
 * @param   current Current in the motor (mA)
 * @param   speed The car speed (cm/s)
 * @retval	The duty-cycle command for the motor
*/
float ComputeMotorCommand_R (int16_t speed_cmd, int16_t current, int16_t speed){
    
    float dc;         //out duty cycle;
    volatile int32_t in_PI;
    float current_f = (float)current;
    volatile float coef_in_PI;   // to adjust PI input depending on how close from MAX_CURRENT we are
    
    if (speed_cmd != 0)
    {
        // duty cycle is 50 if current reaches MAX_CURRENT
        if (fabs(current_f) > MAX_CURRENT)
            dc = (float)MOTORS_PWM_ZERO;
        else // If MAX_CURRENT is not reached
        {
            // PI controller input depends on how close from MAX_CURRENT is the current
            coef_in_PI = (MAX_CURRENT - fabs(current_f)) / MAX_CURRENT;
            in_PI = (int32_t)((float)((int32_t)speed_cmd - (int32_t)speed) * coef_in_PI);
            dc = PI_Controller_R(in_PI) ; 
        }
    }
    else
        dc = (float)MOTORS_PWM_ZERO;

    return dc;
}


/**
 * @brief   Applies a PI controller to the input (left wheel)
 * @param   in PI controller input
 * @return  PI controller output
*/
float PI_Controller_L (int32_t in)
{
    //volatile static const float a1_PI =  T*Ki/2.0 - Kp ;      // coef. formula PI controller
    //volatile static const float a2_PI =  T*Ki/2.0 + Kp; 

    static float outPI_prec_no_offset = 0.0, unsat_PI_output_f = MOTORS_PWM_ZERO;            // buffer previous in & out

    float in_f; 
    float PI_output_f;
    float K_AW = 0.6;
    float AW_f = 0.0;

    in_f = (float)(in);        

    // Simple Anti-windup
    if (unsat_PI_output_f > MOTORS_PWM_MAX)
       AW_f =  K_AW*(unsat_PI_output_f  - MOTORS_PWM_MAX); 
    else if (unsat_PI_output_f  < MOTORS_PWM_MIN)
       AW_f = K_AW*(unsat_PI_output_f  - MOTORS_PWM_MIN);
    else 
       AW_f = 0.0;        

    // Compute PI output - do not forget the 50% offset
    unsat_PI_output_f = outPI_prec_no_offset + Kp_L*in_f - AW_f;
    unsat_PI_output_f += MOTORS_PWM_ZERO;

    // Saturate PI output between Min and Max duty-cycles
    if (unsat_PI_output_f > MOTORS_PWM_MAX)
        PI_output_f = MOTORS_PWM_MAX;
    else if (unsat_PI_output_f < MOTORS_PWM_MIN)
        PI_output_f = MOTORS_PWM_MIN;
    else
        PI_output_f = unsat_PI_output_f;

    // Update variables for next iteration
    outPI_prec_no_offset = PI_output_f - MOTORS_PWM_ZERO;
    return PI_output_f;
}

/**
 * @brief   Applies a PI controller to the input (right wheel)
 * @param   in PI controller input
 * @return  PI controller output
*/
float PI_Controller_R (int32_t in)
{
    //volatile static const float a1_PI = Kp + T*Ki/2.0 ;      // coef. formula PI controller
    //volatile static const float a2_PI = Kp - T*Ki/2.0 ; 
    static const float a1_PI = T*Ki_R/2.0 - Kp_R ;      // coef. formula PI controller
    static const float a2_PI = T*Ki_R/2.0 + Kp_R;

    static float outPI_prec_no_offset = 0.0, unsat_PI_output_f = MOTORS_PWM_ZERO;            // buffer previous in & out

    float in_f; 
    float PI_output_f;
    float K_AW = 0.6;
    float AW_f = 0.0;

    in_f = (float)(in);        

    // Simple Anti-windup
    if (unsat_PI_output_f > MOTORS_PWM_MAX)
       AW_f =  K_AW*(unsat_PI_output_f  - MOTORS_PWM_MAX); 
    else if (unsat_PI_output_f  < MOTORS_PWM_MIN)
       AW_f = K_AW*(unsat_PI_output_f  - MOTORS_PWM_MIN);
    else 
       AW_f = 0.0;        

    // Compute PI output - do not forget the 50% offset
    unsat_PI_output_f = outPI_prec_no_offset + Kp_R*in_f - AW_f;
    unsat_PI_output_f += MOTORS_PWM_ZERO;

    // Saturate PI output between Min and Max duty-cycles
    if (unsat_PI_output_f > MOTORS_PWM_MAX)
        PI_output_f = MOTORS_PWM_MAX;
    else if (unsat_PI_output_f < MOTORS_PWM_MIN)
        PI_output_f = MOTORS_PWM_MIN;
    else
        PI_output_f = unsat_PI_output_f;

    // Update variables for next iteration
    outPI_prec_no_offset = PI_output_f - MOTORS_PWM_ZERO;
    return PI_output_f;
}

/**
 * @brief   The core of the control loop for rear motor left
 * @param   speed_cmdL The speed command
 * @retval	None
*/
void RearMotor_controlL(int16_t speed_cmd)
{
    float motor_speed_L;
    
    // Command must be send without jitter...
    motor_speed_L = (duty_cycle_L - MOTORS_PWM_ZERO) / ((MOTORS_PWM_DELTA_MAX)/(MOTORS_SPEED_DELTA));
    Motor_setSpeed(REAR_MOTOR_L, motor_speed_L);

    // ... so we need to compute the command for next send.
    car_speed_L = SpeedSensor_get(SPEED_CM_S, SENSOR_L);     
    duty_cycle_L = ComputeMotorCommand_L(speed_cmd, current, car_speed_L);
}

/**
 * @brief   The core of the control loop for rear motor left
 * @param   speed_cmdR The speed command
 * @retval	None
*/
void RearMotor_controlR(int16_t speed_cmd)
{
    float motor_speed_R;
    
    // Command must be send without jitter...
    motor_speed_R = (duty_cycle_R - MOTORS_PWM_ZERO) / ((MOTORS_PWM_DELTA_MAX)/(MOTORS_SPEED_DELTA));  //from duty cycle to [-1, 1]
    Motor_setSpeed(REAR_MOTOR_R, motor_speed_R);

    // ... so we need to compute the command for next sending.
    car_speed_R = SpeedSensor_get(SPEED_CM_S, SENSOR_R);     
    duty_cycle_R = ComputeMotorCommand_R(speed_cmd, current, car_speed_R);
}

