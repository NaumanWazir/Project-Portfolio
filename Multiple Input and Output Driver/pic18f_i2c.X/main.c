/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K22
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "mcp23017_handler.h"
#include "pca9685_handler.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
/*
                         Main application
 */
#include <inttypes.h>

const uint8_t  IOX_BASE_ADR_MD1 =0x21;      // Base Address of MCP23017 motor driver 1
const uint8_t  IOX_BASE_ADR_MD2 =0x22;      // Base Address of MCP23017 motor driver 1
const uint8_t  IOX_BASE_ADR_SW =0x20;      // Base Address of MCP23017 motor driver 1
const uint8_t PCA_BASE_ADR = 0x40;// I2C address for PCA9865 with no solder bridges


volatile uint8_t main_loop = 0;

void timer_isr(){

    main_loop = 1;
}

volatile uint8_t check_porta = 0;
volatile uint8_t check_portb = 0;
void isr_ioc()
{
    if(IA_GetValue() == 0)
        check_porta = 1;
    if(IB_GetValue() == 0)
        check_portb = 1;

}
void init_input_mcp23017(void){
    uint8_t states = 0;
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,IOCON,0x04);
    
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,IODIRA,0xFF);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,IODIRB,0xFF);
    //I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,IPOLA,0xFF);
    //I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,IPOLB,0xFF);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,GPPUA,0xFF);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,GPPUB,0xFF);
    
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,GPINTENA,0xFF);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,GPINTENB,0xFF);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,DEFVALA,0xFF);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,DEFVALA,0xFF);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,INTCONA,0x00);
    I2C1_Write1ByteRegister(IOX_BASE_ADR_SW,INTCONB,0x00);
	
    states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,INTCAPA);
    states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,INTCAPB);
    
    states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,GPIOA);
    states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,GPIOB);

}
void main(void)
{    
    uint8_t states = 0;
    uint8_t PORT_value[14];
    uint8_t INTF_value[14];
    uint8_t value = 0xFF;
    uint8_t main_loop_counter = 0;
    SYSTEM_Initialize();
    TMR0_SetInterruptHandler(timer_isr);
    IOCB4_SetInterruptHandler(isr_ioc);
    IOCB5_SetInterruptHandler(isr_ioc);
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    printf("Program Start\n\r");
    
    printf("Setting input mcp23017\n\r");
    init_input_mcp23017();
    printf("Done input mcp\n\r");
    
    printf("Setting output mcp23017\n\r");
    set_all_output_portA(IOX_BASE_ADR_MD1);
    set_all_output_portB(IOX_BASE_ADR_MD1);
    printf("Done output mcp1\n\r");
    set_all_output_portA(IOX_BASE_ADR_MD2);
    set_all_output_portB(IOX_BASE_ADR_MD2);
    printf("Done output mcp2\n\r");
    
    PCA9685_init(PCA_BASE_ADR);
        
    while (1)
    {
        if(check_porta)
        {
            printf("IA\n\r");
            states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,INTFA);
            INTF_value[0] = ((states >> 0)  & 0x01);
            INTF_value[1] = ((states >> 1)  & 0x01);
            INTF_value[2] = ((states >> 2)  & 0x01);
            INTF_value[3] = ((states >> 3)  & 0x01);
            INTF_value[4] = ((states >> 4)  & 0x01);
            INTF_value[5] = ((states >> 5)  & 0x01);
            INTF_value[6] = ((states >> 6)  & 0x01);
            INTF_value[7] = ((states >> 7)  & 0x01);
            printf("INTFA:%x\n\r",states);
            states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,INTCAPA);
            PORT_value[0] = ((states >> 0)  & 0x01);
            PORT_value[1] = ((states >> 1)  & 0x01);
            PORT_value[2] = ((states >> 2)  & 0x01);
            PORT_value[3] = ((states >> 3)  & 0x01);
            PORT_value[4] = ((states >> 4)  & 0x01);
            PORT_value[5] = ((states >> 5)  & 0x01);
            PORT_value[6] = ((states >> 6)  & 0x01);
            PORT_value[7] = ((states >> 7)  & 0x01);
            printf("INTCAPA:%x\n\r",states);
            states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,GPIOA);
            printf("PA:%x\n\r",states);
            check_porta = 0;
        }
        
        if(check_portb)
        {
            printf("IB\n\r");
            states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,INTFB);
            INTF_value[8] = ((states >> 0)  & 0x01);
            INTF_value[9] = ((states >> 1)  & 0x01);
            INTF_value[10] = ((states >> 2)  & 0x01);
            INTF_value[11] = ((states >> 3)  & 0x01);
            INTF_value[12] = ((states >> 4)  & 0x01);
            INTF_value[13] = ((states >> 5)  & 0x01);
            /*INTFB_value[6] = ((states >> 6)  & 0x01);
            INTFB_value[7] = ((states >> 7)  & 0x01);*/
            printf("INTFB:%x\n\r",states);
            states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,INTCAPB);
            printf("INTCAPB:%x\n\r",states);
            PORT_value[8] = ((states >> 0)  & 0x01);
            PORT_value[9] = ((states >> 1)  & 0x01);
            PORT_value[10] = ((states >> 2)  & 0x01);
            PORT_value[11] = ((states >> 3)  & 0x01);
            PORT_value[12] = ((states >> 4)  & 0x01);
            PORT_value[13] = ((states >> 5)  & 0x01);
            /*PORTB_value[6] = ((states >> 6)  & 0x01);
            PORTB_value[7] = ((states >> 7)  & 0x01);*/
            states = I2C1_Read1ByteRegister(IOX_BASE_ADR_SW,GPIOB);
            printf("PB:%x\n\r",states);
            
            check_portb = 0;
        }
        if(INTF_value[0])
        {
            printf("PA0:%x\n\r",PORT_value[0]);
            if(PORT_value[0])
            {
                PORT_value[0] = 0;
            }
            INTF_value[0] = 0;
        }
        
        if(INTF_value[1])
        {
            printf("PA1:%x\n\r",PORT_value[1]);
            if(PORT_value[1])
            {
                PORT_value[1] = 0;
            }
            
            INTF_value[1] = 0;
        }
        if(INTF_value[2])
        {
            printf("PA2:%x\n\r",PORT_value[2]);
            if(PORT_value[2])
            {
                PORT_value[2] = 0;
            }
            INTF_value[2] = 0;
        }
        if(INTF_value[3])
        {
            printf("PA3:%x\n\r",PORT_value[3]);
            if(PORT_value[3])
            {
                PORT_value[3] = 0;
            }
            INTF_value[3] = 0;
        }
        if(INTF_value[4])
        {
            printf("PA4:%x\n\r",PORT_value[4]);
            if(PORT_value[4])
            {
                PORT_value[4] = 0;
            }
            INTF_value[4] = 0;
        }
        
        if(INTF_value[5])
        {
            printf("PA5:%x\n\r",PORT_value[5]);
            if(PORT_value[5])
            {
                PORT_value[5] = 0;
            }
            INTF_value[5] = 0;
        }
        if(INTF_value[6])
        {
            printf("PA6:%x\n\r",PORT_value[6]);
            if(PORT_value[6])
            {
                PORT_value[6] = 0;
            }
            INTF_value[6] = 0;
        }
        if(INTF_value[7])
        {
            printf("PA7:%x\n\r",PORT_value[7]);
            if(PORT_value[7])
            {
                PORT_value[7] = 0;
            }
            INTF_value[7] = 0;
        }
        if(INTF_value[8])
        {
            printf("PB0:%x\n\r",PORT_value[8]);
            if(PORT_value[8])
            {
                PORT_value[8] = 0;
            }
            INTF_value[8] = 0;
        }
        if(INTF_value[9])
        {
            printf("PB1:%x\n\r",PORT_value[9]);
            if(PORT_value[9])
            {
                PORT_value[9] = 0;
            }
            INTF_value[9] = 0;
        }
        if(INTF_value[10])
        {
            printf("PB2:%x\n\r",PORT_value[10]);
            if(PORT_value[10])
            {
                PORT_value[10] = 0;
            }
            INTF_value[10] = 0;
        }
        if(INTF_value[11])
        {
            printf("PB3:%x\n\r",PORT_value[11]);
            if(PORT_value[11])
            {
                PORT_value[11] = 0;
            }
            INTF_value[11] = 0;
        }
        if(INTF_value[12])
        {
            printf("PB4:%x\n\r",PORT_value[12]);
            if(PORT_value[12])
            {
                PORT_value[12] = 0;
            }
            INTF_value[12] = 0;
        }
        if(INTF_value[13])
        {
            printf("PB5:%x\n\r",PORT_value[13]);
            if(PORT_value[13])
            {
                PORT_value[13] = 0;
            }
            INTF_value[13] = 0;
        }
        /*if(INTFB_value[6])
        {
            printf("PB6:%x\n\r",PORTB_value[6]);
            INTFB_value[6] = 0;
        }
        if(INTFB_value[7])
        {
            printf("PB7:%x\n\r",PORTB_value[7]);
            INTFB_value[7] = 0;
        }*/
        
        
        
        if(main_loop)
        {
            main_loop_counter++;
            if(main_loop_counter == 200)
            {
                if(states)
                {
                    Set_Channel(PCA_BASE_ADR,2048,1);
                    Set_Channel(PCA_BASE_ADR,3022,2);
                    states = 0;
                    printf("On\n\r");
                }
                else
                {
                    Set_Channel(PCA_BASE_ADR,1000,1);
                    Set_Channel(PCA_BASE_ADR,500,2);
                    states = 1;
                    printf("Of\n\r");
                }
                main_loop_counter = 0;
            }
         
            LED_Toggle();
            main_loop = 0;
        }
    }
}
/**
 End of File
*/
