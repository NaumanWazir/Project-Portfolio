#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

#include "slave_service.h"
#include "pid.h"

#define max_rxBuf   13
#define max_txBuf   17

uint8_t slave_reg[max_txBuf + 1] = {0};
uint8_t slave_reg_buf[max_txBuf + 1] = {0};

extern uint8_t temp_data[2];
extern uint16_t speed;
extern float temperature;
extern uint8_t rxBuf[max_rxBuf + 1];

float offset_temp,offFan_temp;

extern float Tol_max;
extern float Tol_min;
extern float Tol_1;
extern float Tol_2;
extern float percent;

extern uint8_t MaxFanSpeed;
float SetTemp = target;

/*update slave reg content */
void update_slave_reg(void)
{
    float temp;
    int temp_storage;
    int temp_storage1;
    uint8_t x = 0;
    
    if(temperature < Tol_min)
    {speed = 0;}
    
    //update temperature
    temp_storage =(int)temperature;
    slave_reg[0]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[1]= (uint8_t)((temperature-temp_storage+temp_storage1)*16);
    
    //update fan speed
    slave_reg[2]= (speed&0xFF00)>>8;
    slave_reg[3]= speed&0x00FF;
    
    //update offset temperature
    temp_storage =(int)offset_temp;
    slave_reg[4] = (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[5]= (uint8_t)((offset_temp-temp_storage+temp_storage1)*16);
    
    //update offset temperature
    temp_storage =(int)offFan_temp;
    slave_reg[6]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[7]= (uint8_t)((offFan_temp-temp_storage+temp_storage1)*16);

    //update the SetTemp
    temp_storage =(int)SetTemp;
    slave_reg[8]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[9]= (uint8_t)((SetTemp-temp_storage+temp_storage1)*16);

    //update the Tol_1
    temp_storage =(int)Tol_1;
    slave_reg[10]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[11]= (uint8_t)((Tol_1-temp_storage+temp_storage1)*16);
 
    temp = Tol_2;
    if(temp < 0.0) temp = -Tol_2;
    //update the Tol_2
    temp_storage =(int)temp;
    slave_reg[12]= (uint8_t)(temp_storage/16);
    temp_storage1= temp_storage%16;
    slave_reg[13]= (uint8_t)((temp-temp_storage+temp_storage1)*16);
    
    //update the MaxFanSpeed
    slave_reg[14] = MaxFanSpeed;
    
    //update crc
    slave_reg[15]= 0x00;
    slave_reg[16]= slave_reg[0]^slave_reg[1]^slave_reg[2]^slave_reg[3]^slave_reg[4]^slave_reg[5]^slave_reg[6]^slave_reg[7]^slave_reg[8]^slave_reg[9]^slave_reg[10]^slave_reg[11]^slave_reg[12]^slave_reg[13]^slave_reg[14];
    
    PIE2bits.SSP2IE = 0;
    for(x = 0; x < 17; x++)
    {
        slave_reg_buf[x] = slave_reg[x];
    }
    PIE2bits.SSP2IE = 1;
}


void update_offset_n_offFan_value(void)
{
    uint8_t temp = rxBuf[0]^rxBuf[1]^rxBuf[2]^rxBuf[3]^rxBuf[4]^rxBuf[5]^rxBuf[6]^rxBuf[7]^rxBuf[8]^rxBuf[9]^rxBuf[10];
  
    if((temp == rxBuf[12]) &&(rxBuf[11] == 0))    
    {
        // calculate temperature for offset temperature.
        if((rxBuf[0]&0x10)==0x10)//negative
        {
            temp=rxBuf[0]&0x0F;//clear sign
            offset_temp = 256-(temp*16+((float)(rxBuf[1])/16));
        }
        else{//positive
            temp=rxBuf[0]&0x0F;     //clear sign
            offset_temp = temp*16+((float)(rxBuf[1])/16);    
        }
        
        //............................................................
        
        // calculate temperature for offset temperature.
        if((rxBuf[2]&0x10)==0x10)//negative
        {
            temp=rxBuf[2]&0x0F;//clear sign
            offFan_temp = 256-(temp*16+((float)(rxBuf[3])/16));
        }
        else{//positive
            temp=rxBuf[2]&0x0F;     //clear sign
            offFan_temp = temp*16+((float)(rxBuf[3])/16);    
        }
        
        // calculate target temperature
        if((rxBuf[4]&0x10)==0x10)//negative
        {
            temp=rxBuf[4]&0x0F;//clear sign
            SetTemp = 256-(temp*16+((float)(rxBuf[5])/16));
        }
        else{//positive
            temp=rxBuf[4]&0x0F;     //clear sign
            SetTemp = temp*16+((float)(rxBuf[5])/16);    
        }        
        
        Tol_1 = (float)(rxBuf[6]*16)+((float)(rxBuf[7])/16);
        Tol_2 = (float)(rxBuf[8]*16)+((float)(rxBuf[9])/16);
        
        Tol_2 = -Tol_2;
        Tol_max = SetTemp + Tol_1;
        Tol_min = SetTemp + Tol_2;
        
        MaxFanSpeed = rxBuf[10];
        percent = ((float)MaxFanSpeed/(float)100.0);
        
        set_pid_target(SetTemp);
    }
    //update_slave_reg();
}

