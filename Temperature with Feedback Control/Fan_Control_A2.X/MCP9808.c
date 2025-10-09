#include "MCP9808.h"

#define MCP_add 0x18
//MCP9808 IIC address,change to right address according A0-A2. 1F means A0-A2 set high


uint8_t temp_data[2];  //temperature
extern float offset_temp,offFan_temp;

void MCP9808_init(void)
{
    uint8_t cfg_data[2] = {0x08,0x03};  // byte 0: reg pointer, byte1-2 : cfg_reg data  cfg resolution as 0.0625 C at 250ms
   // I2C1_WriteNBytes(MCP_add,cfg_data,2);
    MSSP_WriteBlock(MCP_add, cfg_data,2);
    MSSP_RegisterSelectAndRead(MCP_add,0x05,temp_data,2);
}

void Read_temp_MCP(void)
{
    /*
    //read 4 times, cal average
    uint16_t temp_16[2];
    uint8_t temp_8[2];
    
    temp_16[0]=0;
    temp_16[1]=0;
    for(uint8_t i=0;i<8;i++)
    {
    
    MSSP_ReadBlock(MCP_add,temp_8,2);
        temp_16[0] =temp_16[0]+ temp_8[0]&0x1F;
         temp_16[1]=temp_16[1]+temp_8[1];
    }
    temp_data[0]=temp_16[0]>>3;
    temp_data[1]=temp_16[1]>>3;*/
    
    MSSP_ReadBlock(MCP_add,temp_data,2);
}

float cal_temp(void)
{
    float re_temp;
    uint8_t temp;
    
    if((temp_data[0]&0x10)==0x10)  //negative
    {
        temp=temp_data[0]&0x0F;     //clear sign
        re_temp= 256-(temp*16+((float)(temp_data[1])/16));
        
    }
    else                        //positive
    {
        temp=temp_data[0]&0x0F;     //clear sign
        re_temp= temp*16+((float)(temp_data[1])/16);    
    }
    
    //-------------------------------------
    //Temperature compensation
    if(re_temp<45)      
    {
        re_temp=re_temp+1;
    }
    else
    {
        re_temp=re_temp+offset_temp;
    }
    
   return re_temp; 
}