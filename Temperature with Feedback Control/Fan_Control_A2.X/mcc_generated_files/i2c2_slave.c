/**
  I2C2 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    i2c2_slave.c

  @Summary
    This is the generated driver implementation file for the I2C2 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for I2C2.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF18326
        Driver Version    :  2.0.1
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.31 and above or later
        MPLAB             :  MPLAB X 5.45
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "i2c2_slave.h"
#include <xc.h>
#include "../slave_service.h"

#define I2C2_SLAVE_ADDRESS      0x2f
#define I2C2_SLAVE_MASK         127

#define TX_buffer_size 17

uint8_t buffer_index = 0;
extern uint8_t slave_reg[TX_buffer_size];
extern uint8_t slave_reg_buf[TX_buffer_size];

#define max_rxBuf   13
uint8_t rxBuf[max_rxBuf + 1] = {0};
uint8_t rxBuf_idx = 0;


typedef enum
{
    I2C2_IDLE,
    I2C2_ADDR_TX,
    I2C2_ADDR_RX,
    I2C2_DATA_TX,
    I2C2_DATA_RX
} i2c2_slave_state_t;

/**
 Section: Global Variables
 */
volatile uint8_t i2c2WrData;
volatile uint8_t i2c2RdData;
volatile uint8_t i2c2SlaveAddr;
static volatile i2c2_slave_state_t i2c2SlaveState = I2C2_IDLE;

/**
 Section: Functions declaration
 */
static void I2C2_Isr(void);
static void I2C2_SlaveDefRdInterruptHandler(void);
static void I2C2_SlaveDefWrInterruptHandler(void);
static void I2C2_SlaveDefAddrInterruptHandler(void);
static void I2C2_SlaveDefWrColInterruptHandler(void);
static void I2C2_SlaveDefBusColInterruptHandler(void);

static void I2C2_SlaveRdCallBack(void);
static void I2C2_SlaveWrCallBack(void);
static void I2C2_SlaveAddrCallBack(void);
static void I2C2_SlaveWrColCallBack(void);
static void I2C2_SlaveBusColCallBack(void);

static inline bool I2C2_SlaveOpen();
static inline void I2C2_SlaveClose();
static inline void I2C2_SlaveSetSlaveAddr(uint8_t slaveAddr);
static inline void I2C2_SlaveSetSlaveMask(uint8_t maskAddr);
static inline void I2C2_SlaveEnableIrq(void);
static inline bool I2C2_SlaveIsAddr(void);
static inline bool I2C2_SlaveIsRead(void);
static inline void I2C2_SlaveClearBuff(void);
static inline void I2C2_SlaveClearIrq(void);
static inline void I2C2_SlaveReleaseClock(void);
static inline bool I2C2_SlaveIsWriteCollision(void);
static inline bool I2C2_SlaveIsTxBufEmpty(void);
static inline bool I2C2_SlaveIsData(void);
static inline void I2C2_SlaveRestart(void);
static inline bool I2C2_SlaveIsRxBufFull(void);
static inline void I2C2_SlaveSendTxData(uint8_t data);
static inline uint8_t I2C2_SlaveGetRxData(void);
static inline uint8_t I2C2_SlaveGetAddr(void);
static inline void I2C2_SlaveSendAck(void);
static inline void I2C2_SlaveSendNack(void);
static inline bool I2C2_SlaveIsOverFlow(void);

void I2C2_Initialize()
{
    SSP2STAT  = 0x80;
    SSP2CON1 |= 0x06;
    SSP2CON2  = 0x81;
    SSP2CON1bits.SSPEN = 0;
}

void I2C2_Open() 
{
    I2C2_SlaveOpen();
    I2C2_SlaveSetSlaveAddr(I2C2_SLAVE_ADDRESS);
    I2C2_SlaveSetSlaveMask(I2C2_SLAVE_MASK);
    I2C2_SlaveSetIsrHandler(I2C2_Isr);
    I2C2_SlaveSetBusColIntHandler(I2C2_SlaveDefBusColInterruptHandler);
    I2C2_SlaveSetWriteIntHandler(I2C2_SlaveDefWrInterruptHandler);
    I2C2_SlaveSetReadIntHandler(I2C2_SlaveDefRdInterruptHandler);
    I2C2_SlaveSetAddrIntHandler(I2C2_SlaveDefAddrInterruptHandler);
    I2C2_SlaveSetWrColIntHandler(I2C2_SlaveDefWrColInterruptHandler);
    I2C2_SlaveEnableIrq();    
}

void I2C2_Close() 
{
    I2C2_SlaveClose();
}

uint8_t I2C2_Read()
{
   return I2C2_SlaveGetRxData();
}

void I2C2_Write(uint8_t data)
{
    I2C2_SlaveSendTxData(data);
}

bool I2C2_IsRead()
{
    return I2C2_SlaveIsRead();
}

void I2C2_Enable()
{
    I2C2_Initialize();
}

void I2C2_SendAck()
{
    I2C2_SlaveSendAck();
}

void I2C2_SendNack()
{
    I2C2_SlaveSendNack();
}

static void I2C2_Isr() 
{ 
    I2C2_SlaveClearIrq();

    if(I2C2_SlaveIsAddr())// last byte gotten is address
    {
        if(I2C2_SlaveIsRead())  //with read
        {
            i2c2SlaveState = I2C2_ADDR_TX;
        }
        else                    //write
        {
            i2c2SlaveState = I2C2_ADDR_RX;
        }
    }
    else        //get data
    {
        if(I2C2_SlaveIsRead())  //read
        {
            i2c2SlaveState = I2C2_DATA_TX;
        }
        else        //write
        {
            i2c2SlaveState = I2C2_DATA_RX;
        }
    }

    switch(i2c2SlaveState)
    {
        case I2C2_ADDR_TX:  //  address with read       slave send data
            I2C2_SlaveAddrCallBack();
            if(I2C2_SlaveIsTxBufEmpty())
            {
                I2C2_SlaveWrCallBack();
            }
            break;
        case I2C2_ADDR_RX:      // address with write       slave get data
            rxBuf_idx = 0;
            I2C2_SlaveAddrCallBack();
            break;
        case I2C2_DATA_TX:      
            if(I2C2_SlaveIsTxBufEmpty())
            {
                I2C2_SlaveWrCallBack();
            }
            break;
        case I2C2_DATA_RX:
            if(I2C2_SlaveIsRxBufFull())
            {
                I2C2_SlaveRdCallBack();
            }
            break;
        default:
            break;
    }
    I2C2_SlaveReleaseClock();
}

// Common Event Interrupt Handlers
void I2C2_SlaveSetIsrHandler(i2c2InterruptHandler handler)
{
    MSSP2_InterruptHandler = handler;
}

// Read Event Interrupt Handlers
void I2C2_SlaveSetReadIntHandler(i2c2InterruptHandler handler) {
    I2C2_SlaveRdInterruptHandler = handler;
}

static void I2C2_SlaveRdCallBack() {
    
    // Add your custom callback code here
    char ch = SSP2BUF;
    
    if(rxBuf_idx < max_rxBuf)
    {
        rxBuf[rxBuf_idx++] = ch;
        
        if(rxBuf_idx >= max_rxBuf)
        {update_offset_n_offFan_value();}
    
    }
    else rxBuf_idx = 0;
    
    
    if (I2C2_SlaveRdInterruptHandler) 
    {
        I2C2_SlaveRdInterruptHandler();
    }
}

static void I2C2_SlaveDefRdInterruptHandler() {
    i2c2RdData = I2C2_SlaveGetRxData();
}

// Write Event Interrupt Handlers
void I2C2_SlaveSetWriteIntHandler(i2c2InterruptHandler handler) {
    I2C2_SlaveWrInterruptHandler = handler;
}

static void I2C2_SlaveWrCallBack() {
    // Add your custom callback code here
    if(buffer_index < TX_buffer_size)
    {
        SSP2BUF = slave_reg_buf[buffer_index];
        buffer_index++;
    }
    else
    {
        buffer_index = 0;
    }
    /*
    if (I2C2_SlaveWrInterruptHandler) 
    {
        I2C2_SlaveWrInterruptHandler();
    }*/
}

static void I2C2_SlaveDefWrInterruptHandler() {
    I2C2_SlaveSendTxData(i2c2WrData);
}

// ADDRESS Event Interrupt Handlers
void I2C2_SlaveSetAddrIntHandler(i2c2InterruptHandler handler){
    I2C2_SlaveAddrInterruptHandler = handler;
}

  static void I2C2_SlaveAddrCallBack() {
    if (I2C2_SlaveAddrInterruptHandler) {
        I2C2_SlaveAddrInterruptHandler();
    }
}

static void I2C2_SlaveDefAddrInterruptHandler() {
    i2c2SlaveAddr = I2C2_SlaveGetRxData();
}

// Write Collision Event Interrupt Handlers
void I2C2_SlaveSetWrColIntHandler(i2c2InterruptHandler handler){
    I2C2_SlaveWrColInterruptHandler = handler;
}

static void  I2C2_SlaveWrColCallBack() {
    // Add your custom callback code here
    if ( I2C2_SlaveWrColInterruptHandler) 
    {
         I2C2_SlaveWrColInterruptHandler();
    }
}

static void I2C2_SlaveDefWrColInterruptHandler() {
}

// Bus Collision Event Interrupt Handlers
void I2C2_SlaveSetBusColIntHandler(i2c2InterruptHandler handler){
    I2C2_SlaveBusColInterruptHandler = handler;
}

static void  I2C2_SlaveBusColCallBack() {
    // Add your custom callback code here
    if ( I2C2_SlaveBusColInterruptHandler) 
    {
         I2C2_SlaveBusColInterruptHandler();
    }
}

static void I2C2_SlaveDefBusColInterruptHandler() {
}

static inline bool I2C2_SlaveOpen()
{
    if(!SSP2CON1bits.SSPEN)
    {      
        SSP2STAT  = 0x80;
        SSP2CON1 |= 0x06;
        SSP2CON2  = 0x81;
        SSP2CON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

static inline void I2C2_SlaveClose()
{
    SSP2STAT  = 0x80;
    SSP2CON1 |= 0x06;
    SSP2CON2  = 0x81;
    SSP2CON1bits.SSPEN = 0;
}

static inline void I2C2_SlaveSetSlaveAddr(uint8_t slaveAddr)
{
    SSP2ADD = (uint8_t) (slaveAddr << 1);
}

static inline void I2C2_SlaveSetSlaveMask(uint8_t maskAddr)
{
    SSP2MSK = (uint8_t) (maskAddr << 1);
}

static inline void I2C2_SlaveEnableIrq()
{
    PIE2bits.SSP2IE = 1;
}

static inline bool I2C2_SlaveIsAddr()
{
    return !(SSP2STATbits.D_nA);
}

static inline bool I2C2_SlaveIsRead()
{
    return (SSP2STATbits.R_nW);
}

static inline void I2C2_SlaveClearIrq()
{
    PIR2bits.SSP2IF = 0;
}

static inline void I2C2_SlaveReleaseClock()
{
    SSP2CON1bits.CKP = 1;
}

static inline bool I2C2_SlaveIsWriteCollision()
{
    return SSP2CON1bits.WCOL;
}

static inline bool I2C2_SlaveIsData()
{
    return SSP2STATbits.D_nA;
}

static inline void I2C2_SlaveRestart(void)
{
    SSP2CON2bits.RSEN = 1;
}

static inline bool I2C2_SlaveIsTxBufEmpty()
{
    return !SSP2STATbits.BF;
}

static inline bool I2C2_SlaveIsRxBufFull()
{
    return SSP2STATbits.BF;
}

static inline void I2C2_SlaveSendTxData(uint8_t data)
{
    SSP2BUF = data;
}

static inline uint8_t I2C2_SlaveGetRxData()
{
    return SSP2BUF;
}

static inline uint8_t I2C2_SlaveGetAddr()
{
    return SSP2ADD;
}

static inline void I2C2_SlaveSendAck()
{
    SSP2CON2bits.ACKDT = 0;
    SSP2CON2bits.ACKEN = 1;
}

static inline void I2C2_SlaveSendNack()
{
    SSP2CON2bits.ACKDT = 1;
    SSP2CON2bits.ACKEN = 1;
}

static inline bool I2C2_SlaveIsOverFlow()
{
    return SSP2CON1bits.SSPOV;
}