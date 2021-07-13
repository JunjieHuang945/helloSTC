#include<8052.h>
#include "delay.h"

//通过宏形式定义寄存器名称
#define LED P1_1
unsigned int j;
//时间控制
unsigned int ONOFFSET[24]={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
/**
*初始化中断函数
**/
void Ini1init(){
	IT1=1;
	EX1=1;
	EA=1;
}
int main(){
	unsigned int i;
	LED = 0;//初始化
	Ini1init();
	//通断测试
	for(i=0;i<3;i++){
		LED = 1;
		delay_s(1);
		LED = 0;
	}
	while (1)
	{
		if (j=24)
		{
			j=0;
		}
		LED = ONOFFSET[j];
		delay_h(1);
		j++;
	}
	return 0;
}
void Int1() __interrupt 2{
	j = 0;
	LED = ONOFFSET[j];
}

