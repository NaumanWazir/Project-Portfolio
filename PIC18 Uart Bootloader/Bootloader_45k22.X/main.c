 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/
#include "mcc_generated_files/system/system.h"
#include "mcc_generated_files/bootloader/example/bl_example.h"
#include "mcc_generated_files/bootloader/library/core/bl_core.h"
#include <stdint.h> 

#ifdef __XC8__
#include <xc.h> 
#endif 

volatile const uint16_t 
#ifdef __XC8__ 
__at(0x303E) 
#endif 
applicationFooter __attribute__((used, section("application_footer"))) = 0xAA55;


/*
    Main application
*/

uint8_t eraseflash(uint32_t address)
{

    TBLPTRU = (uint8_t) (address >> 16);
    TBLPTRH = (uint8_t) (address >> 8);
    TBLPTRL = (uint8_t) address;
    
    //Access program Flash memory EEPGD
    EECON1bits.EEPGD = 1;
    
    //Access Flash program or data EEPROM memory CFGS
    EECON1bits.CFGS = 0;

    //Allows write cycles to Flash program WREN
    EECON1bits.WREN = 1;

    //Erase the program memory row addressed by TBLPTR with the next WR command FREE
    EECON1bits.FREE = 1;     

    //Disable global interrupt
    INTCONbits.GIE = 0;
    
    EECON2 = 0x55;
    EECON2 = 0xAA;
    
    EECON1bits.WR = 1;
    while(EECON1bits.WR == 1);
    
    //Disable global interrupt
    INTCONbits.GIE = 1;
    
    if (EECON1bits.WRERR == 1) 
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

uint8_t flashWrite(uint32_t address,uint8_t *dataBuffer)
{
    
    uint8_t flashDataCount = PROGMEM_PAGE_SIZE;
    //Load table pointer with the target address of the byte  
    TBLPTRU = (uint8_t) (address >> 16);
    TBLPTRH = (uint8_t) (address >> 8);
    TBLPTRL = (uint8_t) address;

    while (flashDataCount-- > 0U)
    {
        TABLAT = (uint8_t)*dataBuffer;
        dataBuffer++;
        asm("TBLWT+*");
        //If last latch to be written
        /*if (flashDataCount == 0U)
        {
            //Write program Flash memory 
            asm("TBLWT");
        }
        else
        {
            asm("TBLWTPOSTINC");
        } 
         */  
    }
    
    //Access program Flash memory EEPGD
    EECON1bits.EEPGD = 1;
    
    //Access Flash program or data EEPROM memory CFGS
    EECON1bits.CFGS = 0;

    //Allows write cycles to Flash program WREN
    EECON1bits.WREN = 1;

    //Erase the program memory row addressed by TBLPTR with the next WR command FREE
    EECON1bits.FREE = 1;     

    //Disable global interrupt
    INTCONbits.GIE = 0;
    
    EECON2 = 0x55;
    EECON2 = 0xAA;
    
    //Load table pointer with the target address of the byte  
    TBLPTRU = (uint8_t) (address >> 16);
    TBLPTRH = (uint8_t) (address >> 8);
    TBLPTRL = (uint8_t) address;
        
    EECON1bits.WR = 1;
    NOP();
    NOP();
    while(EECON1bits.WR == 1);
    
    //Disable global interrupt
    INTCONbits.GIE = 1;
    
    //Allows write cycles to Flash program WREN
    EECON1bits.WREN = 0;

    if (EECON1bits.WRERR == 1) 
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main(void)
{
    SYSTEM_Initialize();
    /*uint8_t data[64];
    for (int i = 0; i< 64; i++)
    {
        data[i] = i;
    }*/
    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts 
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts 
    // Use the following macros to: 

    // Enable the Global Interrupts 
    INTERRUPT_GlobalInterruptEnable(); 

    // Disable the Global Interrupts 
    //INTERRUPT_GlobalInterruptDisable(); 

    // Enable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptEnable(); 

    // Disable the Peripheral Interrupts 
    //INTERRUPT_PeripheralInterruptDisable(); 

    printf("Start \n\r");
    BL_ExampleInitialize();
    /*if(eraseflash(0x3000) == 1)
    {
        printf("S1\n\r");
    }
    else
    {
        printf("F1\n\r");
    }
    if(flashWrite(0x3000,data))
    {
        printf("S2\n\r");
    }
    else
    {
        printf("F2\n\r");
    }
    printf("Done\n\r");
    if(eraseflash(0x2000) == 1)
    {
        printf("S1\n\r");
    }
    else
    {
        printf("F1\n\r");
    }
    if(flashWrite(0x2000,data))
    {
        printf("S2\n\r");
    }
    else
    {
        printf("F2\n\r");
    }
    printf("Done\n\r");*/
    while(1)
    {
        BL_Example();
    }  
}

