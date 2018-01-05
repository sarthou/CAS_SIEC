/*
 * car_types.h
 *
 *  Created on: 19 nov. 2017
 *      Author: Team Darlene : Sarthou
 */

#ifndef CAR_TYPES_H_
#define CAR_TYPES_H_

/**
 * @brief    Direction of the car
*/
typedef enum {
    /** * @brief    Neither forward neither backward */
    NEUTRAL,
    /** * @brief    Forward */
    FORWARD,
    /** * @brief    Backward */
    BACKWARD
} direction_TypeDef;

/**
 * @brief    Side of turning
*/
typedef enum {
  /** * @brief    Left */
  LEFT = 1,
  /** * @brief    Neither left neither right */
  NONE = 0,
  /** * @brief    Right */
  RIGHT = -1
} side_TypeDef;

#endif /* CAR_TYPES_H_ */
