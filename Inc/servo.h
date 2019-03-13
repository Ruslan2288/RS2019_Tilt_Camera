#ifndef SERVO_H
#define SERVO_H

#include "main.h"


float SetServoAngle( int angle, ADC_HandleTypeDef *adcHandle, TIM_HandleTypeDef *timHandle, uint8_t adcChannel );
float GetServoAngle( ADC_HandleTypeDef *adcHandle, uint8_t adcChannel );

#endif
