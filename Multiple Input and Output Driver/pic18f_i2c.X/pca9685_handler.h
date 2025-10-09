#ifndef PCA9685_H_
#define PCA9685_H_

#include <inttypes.h>
const uint8_t PCA9685_software_reset = 0x06;// Reset the device
const uint8_t  MODE1 =  0x00;        // 0x00 location for Mode1 register address
const uint8_t  MODE2 =  0x01;        // 0x01 location for Mode2 reigster address
const uint8_t  PRE_SCALE_ADDRESS = 0xFE;
const uint8_t  LED0 =   0x06;        // location for start of LED0 registers
const uint8_t  ALL_CH_ON_L_reg =  0xFA;
const uint8_t  ALL_CH_ON_H_reg =  0xFB;
const uint8_t  ALL_CH_OFF_L_reg =  0xFC;
const uint8_t  ALL_CH_OFF_H_reg = 0xFD;
void PCA9685_init(uint8_t address);
void Set_All(uint8_t address,uint16_t pwm);
void Set_Channel(uint8_t address,uint16_t pwm,uint8_t Channel);
#endif /* PCA9685_H_ */
