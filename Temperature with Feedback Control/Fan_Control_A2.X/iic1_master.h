/* 
 * File:   iic1_master.h
 * Author: yangxiao
 *
 * Created on September 18, 2021, 10:53 PM
 */

#ifndef IIC1_MASTER_H
#define	IIC1_MASTER_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
 
typedef enum {
    I2C1_NOERR, // The message was sent.
    I2C1_BUSY,  // Message was not sent, bus was busy.
    I2C1_FAIL,  // Message was not sent, bus failure
    I2C1_NACK
} iic1_error_t;
typedef enum
{
    I2C1_STOP=1,
    I2C1_RESTART_READ,
    I2C1_RESTART_WRITE,
    I2C1_CONTINUE,
    I2C1_RESET_LINK
} iic1_operations_t;

// I2C1 STATES

  #define  IIC1_IDLE  0  
  #define  IIC1_START_SEND 1
  #define  IIC1_DEV_SEND 2  
  #define  IIC1_DEV_ACK  3
  #define  IIC1_STOP_SEND 4
  #define  IIC1_REG_SEND 5
  #define   IIC1_REG_ACK 6
  #define  IIC1_DATA_SEND 7
  #define  IIC1_DATA_ACK 8
  #define  IIC1_DATA_DONE 9
  #define IIC1_START_SEND1 10




void IIC1_Initialize();
iic1_error_t iic1_master_wrtie_reg_Nbytes(uint8_t dev_add,uint8_t reg_add, uint8_t *data, uint8_t num);
void IIC1_InterruptHandler();
#ifdef	__cplusplus
}
#endif

#endif	/* IIC1_MASTER_H */

