/*
 * File:   i2c.c
 * Author: Shahzad Anwar Khan*/
//*** github.com/sak311819
//*** https://sak-engineering-lab.blogspot.com/
//*** fiver.com/SAK_engineering
/* Created on January 2, 2023, 11:26 AM

 ****************************  Copyright Note  ******************************************
   Anyone having this code can use it for deveoplment purposes only. Redistribution
   of this code under antoher name and without permission will be an illegal and immoral
   action. If you want to improve this code, you are welcome to make forks, contribute and
   make pull requests or report bugs on github. All types of feedback is welcomed and will
   help make this project more useful for everyone out there. Thanks!
 *****************************************************************************************
 */

#include "i2c.h"
#include<stdio.h>

bool I2C_Init() {
    SDA = 1;
    SCL = 1;
    //    SDA_PIN = 0;
    //    SCL_PIN = 0;
    SCL_LAT = 0;
    SDA_LAT = 0;
    //    start_bit = 0;
    //    stop_bit = 0;
    return 1;
}

/*
 --> Pre Req: SCL is High
 *  After Affect, SCL is low, SDA is LOW
 */
bool I2C_Start() {
    //    if (I2C_busy()) {
    //        return 0;
    //    }
    SCL = 1;
    I2C_Delay2();
    SDA = 0;
    I2C_Delay2();
    SCL = 0;
    //    I2C_Delay(); // !! optional, will be repeated in transmit_byte
    return 1;
}

/*
 --> Pre Req: SCL is High,
 *  After Affect, SCL is High, SDA is High
 */
void I2C_Stop() {
    SCL = 0; // start of stop cycle
    I2C_Delay2(); // give some hold delay so that SDA isn't affected while SCL is high
    SDA = 0; // force sda to low to create leading edge
    I2C_Delay(); // at least one half cycle delay necessary before stop condition
    SCL = 1; // release SCL
    //    DELAY_microseconds(3); // give ample delay to let scl set up
    I2C_Delay2();
    SDA = 1; // then release SDA to generate stop condition
    I2C_Delay(); // give delay to avoid immediate start calls.
    //    I2C_Interrupt = 0;
    //    start_bit = 0;
}

bool I2C_busy() {
    bool flag = false;
    //    if (start_bit | stop_bit) {
    //        if (start_bit == 0 && stop_bit == 1) {
    //            flag = false;
    //        } else {
    //            flag = true;
    //        }
    //    } else {
    //        flag = false;
    //    }
    return flag;
}

void I2C_Delay() { // delay equal to half period of i2c clock
    DELAY_microseconds(i2c_half_clock_period);
}

void I2C_Delay2() { // delay equal to half period of i2c clock
    DELAY_microseconds(i2c_half_clock_period2);
}
//void I2C_Delay4() { // delay equal to half period of i2c clock
//    DELAY_microseconds(i2c_quarter_clock_period2);
//}
/*
 Write n data bytes to slave of given address, from the buffer given as pointer
 * starts and stops i2c internally
 */
unsigned int I2C_Multi_Write(unsigned char slave_address, unsigned char* ptr, unsigned int len) {
    unsigned int count = 0;
    slave_address = (uint8_t) (slave_address << 1);
    while (!I2C_Start());
    bool resp = I2C_Transmit_Byte(slave_address);
    if (resp == NACK) { // slave adress invalid?
        I2C_Stop();
        //        //printf("Multi Write NACK\n\r"); !! debug off for the time being to avoid unnecceary delays
        return 0;
    }
    unsigned int i;
    for (i = 0; i < len; i++) {
        resp = I2C_Transmit_Byte(*ptr);
        if (resp == ACK) { // if transfer successful
            ptr++;
            count++;
        } else {
            //            printf("Multi Write NACK\n\r");
            break;
        }
    }
    I2C_Stop();
    return count;
}
/*
 Writes only one byte to the slave of given address
 * It starts and stops i2c bus internally
 */
bool I2C_Single_Write(unsigned char slave_address, unsigned char data) {
    while (!I2C_Start());
    slave_address = (uint8_t) (slave_address << 1);
    bool resp = I2C_Transmit_Byte(slave_address);
    if (resp == NACK) { // no slave of this address ?
        //printf("Single Write NACK\n\r");
        I2C_Stop(); // if so, stop here and
        return NACK; // go back with nack
    }
    //    I2C_Start();
    resp = I2C_Transmit_Byte(data);
    //    I2C_Transmit_Byte(data);
    I2C_Stop();
    return resp;
}

bool I2C_Detect_Slave(unsigned char slave_address) {
    slave_address = (uint8_t) (slave_address << 1);
    while (!I2C_Start());
    bool resp = I2C_Transmit_Byte(slave_address);
    I2C_Stop();
    if (resp == ACK) {
                printf("<-- Slave found at address %d", slave_address);
    }
    return resp;
}

unsigned char I2C_Single_Read(unsigned char slave_address) {
    //    printf(" slave raw address: %d, read address : ", slave_address);
    slave_address = (uint8_t) (slave_address << 1) | 1;
    //    printf(" %d \n\r", slave_address);
    while (!I2C_Start());
    //    slave_address=slave_address&0xFF;
    if (NACK == I2C_Transmit_Byte(slave_address)) {
        I2C_Stop(); // stope on nack
        printf("Single Read NACK\n\r");
        return 0;
    }
    //    I2C_Start();
    unsigned char data = 0;
    data = I2C_Receive_Byte(); // read incoming data
    I2C_Send_ACK(NACK); // and send nack to terminate after 1 byte
    I2C_Stop();
    //    printf("incoming data from slave: 0x%x\n\r", data);
    return data;
}

/*
 --> Pre Req: SCL is High, SDA relesed by master during ack check and used by slave
 *  After Affect, SCL is HIgh, SDA is dependent on data by slave
 *  This function does not send ack/nack to allow its use in single or multi reads.
 * Ack/nack have to be sent explicitly by calling functions
 */
unsigned char I2C_Receive_Byte() {
    unsigned char received_byte = 0;
    //    unsigned char mask = 0x80;
    int i;
    if (SDA == 0) { // release sda if pulled low
        SCL = 0;
        I2C_Delay2();
        SDA = 1;
    }
    for (i = 0; i < 8; i++) {
        SCL = 0; //avoid false stop condition by letting SCL low
        I2C_Delay(); // first half cycle delay
        SCL = 1; // give positive edge
        I2C_Delay(); //second half cycle delay
        if (SDA_PIN == 1) { // sample data at end
            //printf("1_");
            received_byte = received_byte | 1; // insert ones only, zeros will be auto added on shifts
        }
        //        else {
        //            //            received_byte=received_byte|0;
        //            //printf("0_");
        //        }
        if (i < 7) { // shift for first 7 msbs only
            received_byte = (uint8_t) (received_byte << 1);
        }
    }
    //printf("\n\r");
    return received_byte;
}
/*
 Transmit One byte ( 8 bits ) and return the status ACK/NACK
 */
bool I2C_Transmit_Byte(unsigned char data) {
    unsigned char check = 0;
    unsigned char mask = 0x80;
    int i;
    for (i = 0; i < 8; i++) {
        check = mask&data;
        data = (uint8_t) (data << 1);
        if (check == mask) {
            transmit_1();
        } else {
            transmit_0();
        }
    }
    bool resp = I2C_Check_ACK();
    return resp;
}

unsigned int I2C_Multi_Read(unsigned char slave_address, unsigned char*ptr, unsigned int len) {
    unsigned int count = 0;
    while (!I2C_Start());
    slave_address = (uint8_t) (slave_address << 1) | 1;
    if (NACK == I2C_Transmit_Byte(slave_address)) {
        I2C_Stop(); // stop on nack
        //printf("Multi Read NACK\n\r");
        return 0;
    }
    while (len > 0) {
        //        unsigned char data = 0;
        *ptr = I2C_Receive_Byte();
        if (len > 1) {
            I2C_Send_ACK(ACK);
        }
        ptr++;
        len--;
        count++; // this count will be returned, in future, I2C collisions will be addressed
    }
    I2C_Send_ACK(NACK);
    I2C_Stop();
    return count;
}

/*
 --> Pre Req: SCL is High, SDA to be released by this function
 *  After Affect, SCL is HIgh, SDA is dependent on ACK
 */
bool I2C_Check_ACK() {
    SCL = 0; // begin 9th clock start,keep it low before disturbing SDA
    I2C_Delay2(); //give hold time, make it 2 for confirmed 1+us delay
    SDA = 1; // release SDA floating high
    I2C_Delay2(); // first half cycle of 9th pulse
    SCL = 1; // give out rising edge,
    // slave must pull sda low during high period of 9th pulse
    I2C_Delay(); //second half cycle delay, after this, slave should send ACK/NACK , !! reduce this time if ack not detected properly
    if (SDA_PIN == 0) { // if SDA pulled low by some slave
        return ACK; // return ack
    } else {
        return NACK; // otherwise return Nack
    }
}

/*
 --> Pre Req: SCL is High, SDA dependent on slave data last bit
 *  After Affect, SCL is HIgh, SDA is dependent on ACK/NACK by master
 */
void I2C_Send_ACK(bool ack) {
    SCL = 0;
    I2C_Delay2(); // quater cycle delay
    if (ack) {
        SDA = 0;
    }//send acknowledge
    else {
        SDA = 1;
    } // don't send acknowledge
    I2C_Delay2(); // first half cycle complete
    SCL = 1; // giving rising edge
    I2C_Delay(); // second half cycle delay
    
}

/*
 --> Pre Req: SCL is Low on MSB, SCL high for others
 *  After Affect, SCL is High, SDA is data
 */
void transmit_0(void) {
    SCL = 0; // pull line low
    I2C_Delay2(); // give set up delay
    SDA = 0; // pull sda low to transmit zero
    //     DELAY_microseconds(2);
    I2C_Delay2(); // give first half cycle delay
    SCL = 1; // give scl positvie edge to let slave latch SDA data
    I2C_Delay();
}

/*
 --> Pre Req: SCL is Low on MSB, SCL high for others
 *  After Affect, SCL is High, SDA is data
 */
void transmit_1(void) {
    SCL = 0; // pull SCL LOW
    I2C_Delay2(); // give delay before changing SDA
    SDA = 1; // release SDA to transmit 1
    I2C_Delay2(); // first half cycle delay
    SCL = 1; // transmit edge of SCL to let slave latch SDA data
    I2C_Delay(); // give half cycle delay to complete period
}