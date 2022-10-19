#include <8052.h>
#include "delay.h"
#include "timer.h"
#include "main.h"

int ledSetIndex = 0;
int main()
{
	closLED();
	closWPP();
	EA = 1; //闭合总中断开关
	TIM0_Init(50000, 20);
	//LED默认关闭
	resetLEDStatus();
	while (0)
	{
		if (needToRun == 1)
		{
			int timeIndex;
			openWPP();
			for (timeIndex = WPP_RUN_TIME; timeIndex > 0; timeIndex--)
			{
				delay_s(1);
			}
			closWPP();
			needToRun = 0;
		}
	}

	return 0;
}

/**
 * 重新设置补光灯状态
 * */
void resetLEDStatus()
{
	for (ledSetIndex = 0; ledSetIndex < LED_SET_LENGTH; ledSetIndex++)
	{
		int status = ledSwitchSet[ledSetIndex];
		if (status == timeH)
		{
			openLED();
			return;
		}
	}
	closLED();
}
//打开补光灯
void openLED()
{
	LED1 = STATUS_ON;
	LED2 = STATUS_ON;
	LED3 = STATUS_ON;
	LED4 = STATUS_ON;
}
//关闭补光灯
void closLED()
{
	LED1 = STATUS_OFF;
	LED2 = STATUS_OFF;
	LED3 = STATUS_OFF;
	LED4 = STATUS_OFF;
}
/**
 * 重新设置抽水机状态
 * */
void resetWPPStatus()
{
}
/**
 * 打开抽水机
 * */
void openWPP()
{
	WPP1 = STATUS_ON;
	WPP2 = STATUS_ON;
	WPP3 = STATUS_ON;
	WPP4 = STATUS_ON;
}

/**
 * 关闭抽水机
 * */
void closWPP()
{
	WPP1 = STATUS_OFF;
	WPP2 = STATUS_OFF;
	WPP3 = STATUS_OFF;
	WPP4 = STATUS_OFF;
}
/**
 * 时间天改变
 * */
void timeDChange()
{
	timeD++;
	if (timeD == 32)
	{
		timeD = 1;
	}
	if (timeD % WPP_RUN_DAY_INTERVAL == 0)
	{
		needToRun = 1;
	}
}

/**
 * 时间小时改变
 * */
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
/**
 * 时间分钟改变
 * **/
void timeMChange()
{
	timeM++;
	if (timeM == 60)
	{
		timeM = 0;
		timeHChange();
	}
}

/**
 * 时间秒改变
 * */
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
