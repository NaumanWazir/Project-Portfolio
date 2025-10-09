#include "mcp23017_handler.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

void set_all_input_portA(uint8_t address){
    I2C1_Write1ByteRegister(address,IODIRA,0xFF);
}
void set_all_input_portB(uint8_t address){
    I2C1_Write1ByteRegister(address,IODIRB,0xFF);
}
void set_all_output_portA(uint8_t address){
    I2C1_Write1ByteRegister(address,IODIRA,0x00);
}
void set_all_output_portB(uint8_t address){
    I2C1_Write1ByteRegister(address,IODIRB,0x00);
}

// pin number should be 0 to 7
void set_pin_input_portA(uint8_t address, uint8_t pinNumber){
    uint8_t value; 
    value = I2C1_Read1ByteRegister(address,IODIRA);
    value |= (pinNumber);
    I2C1_Write1ByteRegister(address,IODIRA,value);
}

// pin number should be 0 to 7
void set_pin_input_portB(uint8_t address, uint8_t pinNumber){
    uint8_t value; 
    value = I2C1_Read1ByteRegister(address,IODIRB);
    value |= (pinNumber);
    I2C1_Write1ByteRegister(address,IODIRB,value);
}
// pin number should be 0 to 7
void set_pin_output_portA(uint8_t address, uint8_t pinNumber){
    uint8_t value; 
    value = I2C1_Read1ByteRegister(address,IODIRA);
    value &= ~(pinNumber);
    I2C1_Write1ByteRegister(address,IODIRA,value);
}

// pin number should be 0 to 7
void set_pin_output_portB(uint8_t address, uint8_t pinNumber){
    uint8_t value; 
    value = I2C1_Read1ByteRegister(address,IODIRB);
    value &= ~(pinNumber);
    I2C1_Write1ByteRegister(address,IODIRB,value);
}
void set_all_portA(uint8_t address){
    I2C1_Write1ByteRegister(address,GPIOA,0xFF);
}
void set_all_portB(uint8_t address){
    I2C1_Write1ByteRegister(address,GPIOB,0xFF);
}
void clear_all_portA(uint8_t address){
    I2C1_Write1ByteRegister(address,GPIOA,0x00);
}
void clear_all_portB(uint8_t address){
    I2C1_Write1ByteRegister(address,GPIOB,0x00);
}
uint8_t read_all_portA(uint8_t address,uint8_t reg){
    return I2C1_Read1ByteRegister(address,reg);
}
uint8_t read_all_portB(uint8_t address,uint8_t reg){
    return I2C1_Read1ByteRegister(address,reg);
}

uint8_t get_state_bit(uint8_t byte_in,uint8_t bitNumber){
    return ((byte_in >> bitNumber)  & 0x01);
}
