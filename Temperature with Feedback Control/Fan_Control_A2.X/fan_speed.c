#include "fan_speed.h"
uint16_t old_ccp;
uint16_t new_ccp;
uint16_t speed;

void cal_speed(uint16_t capture)
{
    new_ccp=  capture;
    
    if(new_ccp>old_ccp)
    {
        speed= (uint16_t)(600000/(new_ccp-old_ccp));
    }
    else
    {
        speed= (uint16_t)(600000/(new_ccp+65536-old_ccp));
    }
    old_ccp=new_ccp;
}



