#include "pca9685_handler.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "mcc_generated_files/delay.h"

void PCA9685_init(uint8_t address){
    I2C1_Write1ByteRegister(address,MODE1,0b00110001);
    I2C1_Write1ByteRegister(address,PRE_SCALE_ADDRESS,0x03);   //maximum 1526 Hz
    I2C1_Write1ByteRegister(address,MODE1,0b10100001);
    I2C1_Write1ByteRegister(address,MODE2,0b00000100);
    DELAY_milliseconds(1);
}
void Set_All(uint8_t address,uint16_t pwm){
    //LED_ON_L
    I2C1_Write1ByteRegister(address,ALL_CH_ON_L_reg,0);
    //LED_ON_H 
    I2C1_Write1ByteRegister(address,ALL_CH_ON_H_reg,0);
    //LED0_OFF_L
    I2C1_Write1ByteRegister(address,ALL_CH_OFF_L_reg,pwm & 0xFF);
    //LED0_OFF_H
    I2C1_Write1ByteRegister(address,ALL_CH_OFF_H_reg,(pwm >> 8) & 0xFF);
}

void Set_Channel(uint8_t address,uint16_t pwm,uint8_t Channel){
    //LED_ON_L
    I2C1_Write1ByteRegister(address,LED0 + 4 * Channel ,0);
    //LED_ON_H 
    I2C1_Write1ByteRegister(address,LED0 + 1 + 4 * Channel,0);
    //LED0_OFF_L
    I2C1_Write1ByteRegister(address,LED0 + 2 + 4 * Channel,pwm & 0xFF);
    //LED0_OFF_H
    I2C1_Write1ByteRegister(address,LED0 + 3 + 4 * Channel,(pwm >> 8) & 0xFF);
}

