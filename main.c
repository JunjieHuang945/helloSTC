#include<8052.h>
#include "delay.h"
int main(){
	//时间控制
	unsigned int ONOFFSET[24]={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned int i,j;
	P1_1=0;//初始化

	//通断测试
	for(i=0;i<3;i++){
		P1_1=1;
		delay_s(1);
		P1_1=0;
	}
	while (1)
	{
		if (j=24)
		{
			j=0;
		}
		
		P1_1 = ONOFFSET[i];
		delay_h(1);
		j++;
	}

	return 0;
}

