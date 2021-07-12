#include<8052.h>
#include "delay.h"
int main(){
	//时间控制
	unsigned int ONOFFSET[24]={1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	unsigned int i;
	P1_1=0;//初始化
	while (1)
	{
		if (i=24)
		{
			i=0;
		}
		
		P1_1 = ONOFFSET[i];
		delay_h(1);
		i++;
	}

	return 0;
}

