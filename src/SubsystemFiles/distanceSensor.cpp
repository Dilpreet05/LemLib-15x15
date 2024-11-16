#include "main.h"
#include <cmath>
#include <math.h>
#define LINEAR_SLOPE -0.143
#define Y_INTERCEPT 1.021

#define Vin 3.17
#define DECAY_CONSTANT -0.17

/** 
 *  Custom distance sensor (non-vex)
 *  Equation to find the distance of the object from the sensor is:
 *  d = SLOPE * log(voltage) + Y_INTERCEPT
 * 
 * 
 */

float getDistance(){

    return (
        LINEAR_SLOPE*(log(distanceSensor.get_value())) + Y_INTERCEPT
        // Vin*exp(-.17*distanceSensor.get_value())

    );

}