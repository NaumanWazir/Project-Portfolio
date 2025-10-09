#ifndef MCP23017_H_
#define MCP23017_H_

#include <inttypes.h>

//MCP23017 internal registers - Not all registers included. See the Microchip MCP23017 datasheet for full list
const uint8_t  IODIRA = 0x00;           // Port A direction register. Write a 0 to make a pin an output, a 1 to make it an input
const uint8_t  IODIRB = 0x01;           // Port B direction register
const uint8_t  GPIOA = 0x12;            // Register Address of Port A
const uint8_t  GPIOB = 0x13;            // Register Address of Port B
const uint8_t  GPPUA = 0x0C;            // Register Address of Port A pull upp
const uint8_t  GPPUB  = 0x0D;            // Register Address of Port B pull up
const uint8_t  IOCON  = 0x0A;           // CONFIGURATION REGISTER
const uint8_t  GPINTENA  = 0x04;           // port a int enable
const uint8_t  GPINTENB  = 0x05;           // port a int enable
const uint8_t  INTCONA  = 0x08;           // port a int compare
const uint8_t  INTCONB  = 0x09;           // port b int compare
const uint8_t  DEFVALA  = 0x06;           // port a int compare default
const uint8_t  DEFVALB  = 0x07;           // port b int compare default
const uint8_t  IPOLA  = 0x02;           // port a int input polarity
const uint8_t  IPOLB  = 0x03;           // port b int input polarity

const uint8_t  INTCAPA  = 0x10;           // port a int caputre
const uint8_t  INTCAPB  = 0x11;           // port b int capture
const uint8_t  INTFA  = 0x0E;           // port a int flag
const uint8_t  INTFB  = 0x0F;           // port b int flag

// Set all pins as input
void set_all_input_portA(uint8_t address);
void set_all_input_portB(uint8_t address);
// Set all pins as output
void set_all_output_portA(uint8_t address);
void set_all_output_portB(uint8_t address);
// Set all particular pins as input
void set_pin_input_portA(uint8_t address, uint8_t pinNumber);
void set_pin_input_portB(uint8_t address, uint8_t pinNumber);
// Set all particular pins as output
void set_pin_output_portA(uint8_t address, uint8_t pinNumber);
void set_pin_output_portB(uint8_t address, uint8_t pinNumber);

// Set all pins to 1
void set_all_portA(uint8_t address);
void set_all_portB(uint8_t address);

// Clear all pins to 0
void clear_all_portA(uint8_t address);
void clear_all_portB(uint8_t address);

//Real all pins 
// reg could be INTFB,INTCAPB,GPIOB
uint8_t read_all_portA(uint8_t address,uint8_t reg);
uint8_t read_all_portB(uint8_t address,uint8_t reg);

//get state of a bit in bytes
// bitNumber should be 0 to 7
uint8_t get_state_bit(uint8_t byte_in,uint8_t bitNumber);

#endif /* MCP23017_H_ */
