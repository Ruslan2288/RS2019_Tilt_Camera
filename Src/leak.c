#include "leak.h"

#define MAX_LEAK_VALUE 4095
#define MIN_LEAK_VALUE 450

#define MAX_OUTPUT_VALUE 10
#define MIN_OUTPUT_VALUE 0

int Map( int value, int minInputVal, int maxInputVal, int minOutputVal, int maxOutputVal )
{
	int result=(int)(value*(maxOutputVal-minOutputVal)/(maxInputVal-minInputVal));
	return result;
}

int constrain( int val, int max, int min )
{
	if( val>max )
	{
		val=max;
	}
	else if( val<min )
	{
		val=min;
	}
	return val;
}

int GetLeakSensorValue( ADC_HandleTypeDef *adcHandle, uint8_t adcChannel )
{
	
	
	ADC_ChannelConfTypeDef sConfig;
	sConfig.Channel=adcChannel;	
	sConfig.SamplingTime=ADC_SAMPLETIME_480CYCLES;
	sConfig.Rank=1;
	
	HAL_ADC_ConfigChannel(adcHandle,&sConfig);
	
	HAL_ADC_Start( adcHandle );
	HAL_ADC_PollForConversion( adcHandle, 100000 );
	int adcValue = HAL_ADC_GetValue( adcHandle );
	HAL_ADC_Stop( adcHandle );	
	
	int result=MAX_OUTPUT_VALUE-Map(adcValue,MAX_LEAK_VALUE,MIN_LEAK_VALUE,MAX_OUTPUT_VALUE,MIN_OUTPUT_VALUE);
	result=constrain(result,MAX_OUTPUT_VALUE-1,MIN_OUTPUT_VALUE);
	
	return result;
	
}