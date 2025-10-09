

/*
 * File:   i2c.h
 * Author: Shahzad Anwar Khan*/
//*** github.com/sak311819
//*** https://sak-engineering-lab.blogspot.com/ 
//*** fiver.com/SAK_engineering
 /* Created on January 2, 2023, 11:26 AM
 
    *******************  Copyright Note ***************************************************
    Anyone having this code can use it for deveoplment purposes only. Redistribution
    of this code under antoher name and without permission will be an illegal and immoral
    action. If you want to improve this code, you are welcome to make forks, contribute and
    make pull requests or report bugs on github. All types of feedback(non-abusive of course)
    is welcomed and will help make this project more useful for everyone out there. Thanks!
    *****************************************************************************************
*/

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef I2C_H
#define	I2C_H
 
#include <xc.h>
#include<stdbool.h>

#define SCL TRISCbits.TRISC0
#define SCL_PIN PORTCbits.RC0
#define SCL_LAT LATCbits.LATC0

#define SDA TRISCbits.TRISC1
#define SDA_PIN PORTCbits.RC1
#define SDA_LAT LATCbits.LATC1

//#define I2C_Interrupt PIR1bits.SSPIF 
//#define stop_bit SSPSTATbits.I2C_STOP
//#define start_bit SSPSTATbits.I2C_START

#define ACK 1
#define NACK 0
#define i2c_half_clock_period 50 // 10 us for 10kHz
#define i2c_half_clock_period2 25 // 10 us for 10kHz
//#define i2c_half_clock_period2 25 // 10 us for 10kHz
bool I2C_Init(void);
bool I2C_Check_ACK(void);
void I2C_Send_ACK(bool);
bool I2C_Detect_Slave(unsigned char);
bool I2C_Start(void);
void I2C_Stop(void);
bool I2C_busy(void);
void I2C_Delay(void);
void I2C_Delay2(void);
bool I2C_Single_Write(unsigned char ,unsigned char );
unsigned int I2C_Multi_Write(unsigned char,unsigned char*,unsigned int);
unsigned char I2C_Single_Read(unsigned char);
unsigned int I2C_Multi_Read(unsigned char,unsigned char*,unsigned int );
bool I2C_Transmit_Byte(unsigned char);
unsigned char I2C_Receive_Byte(void);
void transmit_1(void);
void transmit_0(void);
extern void DELAY_microseconds(uint16_t);
#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */