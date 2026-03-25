#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
#include "Buzzer.h"
#include "LightSensor.h"


int main(void)
{
	LED_Init();	
	Key_Init();
	Buzzer_Init();
	LightSensor_Init();
	uint8_t key_num = 0;
	
	while (1)
	{
		key_num = KEY_GetNum();
		if(key_num == 1)
		{
			LED1_Turn();
			Buzzer_Turn();
		}
		else if(key_num == 2)
		{
			LED2_Turn();
			Buzzer_Turn();
		}
		if(LightSensor_GetNum() == 1)
		{
			Buzzer_ON();
		}
		else
		{
			Buzzer_OFF();
		}
		
	}

}
