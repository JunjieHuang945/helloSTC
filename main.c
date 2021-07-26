#include <8052.h>
#include "delay.h"
#include "timer.h"

//通过宏形式定义寄存器名称
#define LED P0_0
//led关闭电平
#define LED_STATUS_OFF 0
//led打开电平
#define LED_STATUS_ON 1
//控制时间周期长度
#define TIME_H_LENGTH 4
//补光时间控制
unsigned int ONOFFSET[TIME_H_LENGTH] = {0, 1, 2, 3, 4, 6};
unsigned int timeD = 1;
unsigned int timeH = 0;
unsigned int timeM;
unsigned int timeS;
unsigned int i = 0;
//重新设置LED状态函数
void resetLEDStatus();
//天数改变函数
void timeDChange();
//小时改变函数
void timeHChange();
//分钟改变函数
void timeMChange();
//秒钟改变函数
void timeSChange();

int main()
{
	LED = LED_STATUS_OFF;
	EA = 1; //闭合总中断开关
	TIM0_Init(50000, 20);
	//LED默认关闭
	resetLEDStatus();
	return 0;
}

void resetLEDStatus()
{
	unsigned int index = 0;
	for (index = 0; index < TIME_H_LENGTH; index++)
	{
		int status = ONOFFSET[index];
		if (status == timeH)
		{
			LED = LED_STATUS_ON;
			return;
		}
	}
	LED = LED_STATUS_OFF;
}

void timeDChange()
{
	timeD++;
	if (timeD == 32)
	{
		timeD = 1;
	}
}

void timeHChange()
{
	timeH++;
	if (timeH == 24)
	{
		timeH = 0;
		timeDChange();
	}
	resetLEDStatus();
}

void timeMChange()
{
	timeM++;
	if (timeM == 60)
	{
		timeM = 0;
		timeHChange();
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
	TH0 = T0RH; //重新加载重载值
	TL0 = T0RL;
	i++;
	if (i == 2)
	{
		timeSChange();
		i = 0;
	}
}
