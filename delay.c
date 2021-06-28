#include "delay.h"
void delay_ms(unsigned int i){
    unsigned char j;
    for(i; i > 0; i--)
    for(j = 255; j > 0; j--);
}