#include<8052.h>
#include "timer.h"
int T0RH,T0RL,T1RH,T1RL;
void TIM0_Init(int us, int trim)
{
    int tmp;  //临时变量
     
    tmp = 11059200 / 12;            //定时器计数频率
    tmp = ( tmp * (us/100) )/10000; //计算所需的计数值
    tmp = 65536 - tmp;              //计算定时器重载值
    tmp = tmp+trim;                 //微调计数值使其定时更精确到我们想要的定时时间
    T0RH = (unsigned char)(tmp>>8); //定时器重载值拆分为高低字节  
    T0RL = (unsigned char)tmp;
    TMOD &= 0xF0; //清0低四位 
    TMOD |= 0x01; //设置定时器0为工作模式1   
    TH0 = T0RH;   //加载T0重载值   
    TL0 = T0RL;
    ET0 = 1;      //闭合定时器0中断的开关        
    TR0 = 1;      //启动定时器0        
}
void TIM1_Init(int us, int trim) 
{
    int tmp;  //临时变量
     
    tmp = 11059200 / 12;            //定时器计数频率
    tmp = ( tmp * (us/100) )/10000; //计算所需的计数值
    tmp = 65536 - tmp;              //计算定时器重载值
    tmp = tmp+trim;                 //微调计数值使其定时更精确到我们想要的定时时间
    T1RH = (unsigned char)(tmp>>8); //定时器重载值拆分为高低字节    
    T1RL = (unsigned char)tmp;
    TMOD&=0x0F;//清0高四位
    TMOD|=0x10;//设置定时器1为工作模式1 
    TH1 = T1RH;//加载T1重载值     
    TL1 = T1RL;
    ET1 = 1;   //闭合定时器1中断的开关        
    TR1 = 1;   //启动定时器1         
}