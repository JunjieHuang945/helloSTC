#include<8052.h>
#include "delay.h"
int main(){
	//必须在函数明之后初始化变量
	unsigned char index=0;
	unsigned char LEDSET[8]={0xFE,0xFD,0xFB,0xF7,0xEF,0xDF,0xBF,0x7F};

	P1_3=1;//使能三八译码器
	P1_4=0;

	P1_2=1;//**************
	P1_1=1;//让三八译码器IO6输出低电平
	P1_0 =0;//**************

	while (1)
	{
		P0=LEDSET[index];
		index++;
		if (index>=8)index=0;
		delay_ms(100);
	}
	
	return 0;
}

