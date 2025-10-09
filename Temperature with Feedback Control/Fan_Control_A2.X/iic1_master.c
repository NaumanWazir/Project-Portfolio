#include "iic1_master.h"
#include <xc.h>



uint8_t iic1_state;

void IIC1_Initialize()
{
    SSP1STAT = 0x80;
    SSP1CON1 = 0x08;
    SSP1CON2 = 0x00;
    SSP1CON3 |=0x60;
    SSP1ADD  = 0x4F;
    SSP1CON1bits.SSPEN = 1;
}



// 
iic1_error_t iic1_master_wrtie_reg_Nbytes(uint8_t dev_add,uint8_t reg_add, uint8_t *data, uint8_t num)
{
  //  uint8_t state;
    iic1_error_t error; 
    static uint8_t len;
    if(iic1_state==IIC1_IDLE)           //if IDLE, could use IIC1
    {
        len=num;                    //START
        SSP1CON2bits.SEN=1;
        iic1_state=IIC1_START_SEND;
        error=I2C1_BUSY;
    }
    if(iic1_state==IIC1_START_SEND)     //
    {
        SSP1BUF=dev_add;
        iic1_state= IIC1_DEV_SEND;
    }
    if(iic1_state==IIC1_DEV_ACK)
    {
        if(SSP1CON2bits.ACKSTAT==0)        //
        {
          SSP1BUF=reg_add;
          iic1_state=IIC1_REG_SEND;
        }
        else            //
        {
            SSP1CON2bits.PEN=1;
            iic1_state=IIC1_STOP_SEND;
            return I2C1_NACK;
        }
    }
    if((iic1_state==IIC1_REG_ACK)||(iic1_state==IIC1_DATA_ACK))
    {
        if(SSP1CON2bits.ACKSTAT==0)        //
        {
            while(len--)
            {
             SSP1BUF=*data++;
             iic1_state=IIC1_DATA_SEND;        
            }
                         
             if(len ==0)
             {
                 iic1_state=IIC1_DATA_DONE;
             }
        }
        else            //
        {
            SSP1CON2bits.PEN=1;
            iic1_state=IIC1_STOP_SEND;
            return I2C1_NACK;
        }
    }
    if(iic1_state==IIC1_DATA_DONE)
    {
            SSP1CON2bits.PEN=1;
            iic1_state=IIC1_STOP_SEND;
            error =I2C1_NOERR;
    }
    return error;
}





//
void IIC1_InterruptHandler()
{
    if(iic1_state==IIC1_START_SEND)     //
    {
       // PIR1bits.SSP1IF=0;
        iic1_state= IIC1_START_SEND1;
    }
    if(iic1_state ==IIC1_DEV_SEND)
    {
      //  PIR1bits.SSP1IF=0;
        iic1_state= IIC1_DEV_ACK;
        
    }
    if(iic1_state==IIC1_STOP_SEND)
    {
        // PIR1bits.SSP1IF=0;
         iic1_state=IIC1_IDLE;
    }
    if(iic1_state==IIC1_REG_SEND)
    {
        // PIR1bits.SSP1IF=0;
         iic1_state=IIC1_REG_ACK;
    }
    if(iic1_state==IIC1_DATA_SEND)
    {
       
         iic1_state=IIC1_DATA_ACK;  
    }
      PIR1bits.SSP1IF=0;
}


