#include <8052.h>
#include "delay.h"
#include "timer.h"

//通过宏形式定义寄存器名称
#define LED P1_1
//时间控制
unsigned int ONOFFSET[24] = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
unsigned int j = 0;
unsigned int timeH = 0;
unsigned int timeM;
unsigned int timeS;
unsigned int i = 0;
int main()
{
	LED = ONOFFSET[timeH]; //初始化
	EA = 1;				   //闭合总中断开关
	TIM0_Init(50000, 20);
	return 0;
}

void timeHChange()
{
	timeH++;
	if (timeH == 60)
	{
		timeH = 0;
	}
	LED = ONOFFSET[timeH];
}

void timeMChange()
{
	timeM++;
	if (timeM == 60)
	{
		timeM = 0;
	}
}

void timeSChange()
{
	timeS++;
	if (timeS == 60)
	{
		timeS = 0;
		timeMChange();
	}
}

void TIM0_IRQHandler() __interrupt 1
{
	static int i;
	TH0 = T0RH; //重新加载重载值
	TL0 = T0RL;
	i++;
	if (i == 2)
	{
		timeSChange();
		i = 0;
	}
}
