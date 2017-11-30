/**
 * @file 	common_constants.h
 * @author 	Curtis Team
 * @brief 	Constants used by all the layers
*/
 
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _COMMON_CONSTANTS_H
#define _COMMON_CONSTANTS_H

/* Includes ------------------------------------------------------------------*/
#include <stm32f10x.h>

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/**
 * @brief    Number of microseconds per second
*/
#define US_PER_S                (1.0e+06)

/**
 * @brief    Pi constant
*/
#define PI                      3.141592653589793238


/**
 * @brief    Car wheel diameter (expressed in cm)
*/
#define CAR_WHEEL_SIZE          19

/**
 * @brief    Car maximum forward speed (expressed in cm/s)
*/
#define CAR_MAX_SPEED 		    138.889	                // cm/s  => 138.889 cm/s = 5 km/h

/**
 * @brief    Car maximum backward speed (expressed in cm/s)
*/
#define CAR_MIN_SPEED			-CAR_MAX_SPEED			// cm/s

/**
 * @brief   Value given if car browses instantly the distance between two samples
*/
#define INFINITE                999999.99

/**
 * @brief   Used to get position value in the adequate unit 
*/
#define POSITION_MM		        10                      // millimeters

/**
 * @brief   Used to get position value in the adequate unit 
*/
#define POSITION_CM		        1                       // centimeters

/**
 * @brief   Used to get position value in the adequate unit 
*/
#define POSITION_M 		        0.01                    // meters

/**
 * @brief   Used to get position value in the adequate unit 
*/
#define	POSITION_KM		        0.00001                 // kilometers

/**
 * @brief   Used to get position value in the adequate unit 
*/
#define POSITION_IN		        0.393701                // inches

/**
 * @brief   Used to get position value in the adequate unit 
*/
#define POSITION_FT		        0.0328084               // feet

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_MM_S		        10                      // millimeters per second

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_CM_S 		        1                       // centimeters per second

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_M_S		        0.01                    // meters per second

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_KM_S		        0.00001                 // kilometers per second

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_KM_H		        0.036                   // kilometers per hour

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_FT_S		        0.0328084               // feet per second

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_MI_H		        0.02236936		        // miles per hour

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_MI_S		        0.0000062137            // miles per second

/**
 * @brief   Used to get speed value in the adequate unit
 */
#define SPEED_KNOT		        0.01943845  	        // knots

/**
 * @brief   Convert float to percentage coefficient 
 */
#define PERCENTAGE              100


/**
* @brief    Number of ultrasonic sensors
*/
#define US_NUM             			6

/**
 * @brief coef to convert counter value in cm
 */
#define DISTANCE_COEF								0.02621

/* Position of US in array*/
#define REAR_LEFT					0
#define REAR_CENTER					1
#define REAR_RIGHT					2
#define FRONT_LEFT					3
#define FRONT_CENTER				4
#define FRONT_RIGHT					5

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif // _COMMON_CONSTANTS_H
