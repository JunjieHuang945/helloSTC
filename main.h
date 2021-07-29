#ifndef MAIN_H
#define MAIN_H

//定义补光灯引脚
#define LED1 P0_0
#define LED2 P0_1
#define LED3 P0_2
#define LED4 P0_3

//定义补光灯引脚
#define WPP1 P0_4
#define WPP2 P0_5
#define WPP3 P0_6
#define WPP4 P0_7

//关闭电平
#define STATUS_OFF 0
//打开电平
#define STATUS_ON 1

//控制时间周期长度
#define LED_SET_LENGTH 4
//补光时间控制
unsigned int ledSwitchSet[LED_SET_LENGTH] = {0, 1, 2, 3, 4};

//抽水机间隔每*天启动一次
#define WPP_RUN_DAY_INTERVAL 3
//抽水机每次运行*秒
#define WPP_RUN_TIME 5
//是否需要执行浇水
unsigned int needToRun = 0;
//默认天数
unsigned int timeD = 1;
//默认小时
unsigned int timeH = 0;
//默认分钟
unsigned int timeM = 0;
//默认秒
unsigned int timeS = 0;
unsigned int i = 0;
//重新设置LED状态函数
void resetLEDStatus();
//重新设置抽水机工作时间
void resetWPPStatus();
//打开抽水机
void openWPP();
//关闭抽水机
void closWPP();
//打开补光灯
void openLED();
//关闭补光灯
void closLED();
//天数改变函数
void timeDChange();
//小时改变函数
void timeHChange();
//分钟改变函数
void timeMChange();
//秒钟改变函数
void timeSChange();
#endif