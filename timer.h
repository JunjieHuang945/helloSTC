#ifndef TIMER_H
#define TIMER_H
extern int T0RH,T0RL,T1RH,T1RL;
void TIM0_Init(int us,int trim);
void TIM1_Init(int us,int trim);
#endif