#include "servo.h"

#define MAX_ADC_VALUE 2300
#define MIN_ADC_VALUE 400


float SetServoAngle( int angle, ADC_HandleTypeDef *adcHandle, TIM_HandleTypeDef *timHandle, uint8_t adcChannel )
{ 
			
			ADC_ChannelConfTypeDef sConfig;
			sConfig.Channel=adcChannel;	
			sConfig.SamplingTime=ADC_SAMPLETIME_480CYCLES;
			sConfig.Rank=1;
	
			HAL_ADC_ConfigChannel(adcHandle,&sConfig);
			
			HAL_ADC_Start( adcHandle );
			HAL_ADC_PollForConversion( adcHandle, 100000 );
			int adcValue=HAL_ADC_GetValue( adcHandle );
			HAL_ADC_Stop( adcHandle );

			float angleFromFeedback=( adcValue-MIN_ADC_VALUE )*180/( MAX_ADC_VALUE-MIN_ADC_VALUE );

			timHandle->Instance->CCR1=(int)( 5*angle/9+25 );

			return angleFromFeedback;
}


float GetServoAngle( ADC_HandleTypeDef *adcHandle, uint8_t adcChannel )
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
	
			float angleFromFeedback=( adcValue-MIN_ADC_VALUE )*180/( MAX_ADC_VALUE-MIN_ADC_VALUE );
	
			return angleFromFeedback;
	
}