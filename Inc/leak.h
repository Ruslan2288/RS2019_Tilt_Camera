#ifndef LEAK_H
#define LEAK_H

#include "main.h"

int Map( int value, int minInputVal, int maxInputVal, int minOutputVal, int maxOutputVal );
int GetLeakSensorValue( ADC_HandleTypeDef *adcHandle, uint8_t adcChannel );

#endif