#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	GPIO_InitTypeDef  GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	//GPIO_SetBits(GPIOA,GPIO_Pin_0);
	//GPIO_ResetBits(GPIOA,GPIO_Pin_0);
	//GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);

	/* 流水灯：每次只点亮一位，循环左移；若 LED 为低电平点亮，把下一行改成 GPIO_Write(GPIOA, ~Bit_pin & 0x00FF) */
	uint16_t Bit_pin = 0x0001;

	while (1)
	{
		GPIO_Write(GPIOA, ~Bit_pin);
		Delay_ms(500);
		Bit_pin <<= 1;
		if (Bit_pin > 0x0080)
		{
			Bit_pin = 0x0001;
		}
	}
}
