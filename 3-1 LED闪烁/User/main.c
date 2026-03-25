#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"
int main(void)
{
	LED_Init();	
	Key_Init();
	
	uint8_t key_num = 0;
	
	while (1)
	{
		key_num = KEY_GetNum();
		if(key_num == 1)
		{
			LED1_Turn();
		}
		else if(key_num == 2)
		{
			LED2_Turn();
		}
	}

}
