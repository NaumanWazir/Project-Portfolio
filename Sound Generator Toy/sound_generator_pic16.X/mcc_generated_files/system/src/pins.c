/**
 * Generated Driver File
 * 
 * @file pins.c
 * 
 * @ingroup  pinsdriver
 * 
 * @brief This is generated driver implementation for pins. 
 *        This file provides implementations for pin APIs for all pins selected in the GUI.
 *
 * @version Driver Version 3.0.0
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

#include "../pins.h"

void (*SW_InterruptHandler)(void);

void PIN_MANAGER_Initialize(void)
{
   /**
    LATx registers
    */
    LATA = 0x0;
    LATC = 0x0;

    /**
    TRISx registers
    */
    TRISA = 0x33;
    TRISC = 0x23;

    /**
    ANSELx registers
    */
    ANSELA = 0x7;
    ANSELC = 0x0;

    /**
    WPUx registers
    */
    WPUA = 0x20;
    WPUC = 0x3;
  
    /**
    ODx registers
    */
   
    ODCONA = 0x0;
    ODCONC = 0x0;
    /**
    SLRCONx registers
    */
    SLRCONA = 0x17;
    SLRCONC = 0x3C;
    /**
    INLVLx registers
    */
    INLVLA = 0x1F;
    INLVLC = 0x30;

    /**
    PPS registers
    */
    RX1PPS = 0x15; //RC5->EUSART1:RX1;
    RC4PPS = 0x13;  //RC4->EUSART1:TX1;
    CCP1PPS = 0x2;  //RA2->CCP1:CCP1;
    RA2PPS = 0x09;  //RA2->CCP1:CCP1;

    /**
    APFCON registers
    */

   /**
    IOCx registers 
    */
    IOCAP = 0x20;
    IOCAN = 0x20;
    IOCAF = 0x0;
    IOCCP = 0x0;
    IOCCN = 0x0;
    IOCCF = 0x0;

    SW_SetInterruptHandler(SW_DefaultInterruptHandler);

    // Enable PIE0bits.IOCIE interrupt 
    PIE0bits.IOCIE = 1; 
}
  
void PIN_MANAGER_IOC(void)
{
    // interrupt on change for pin SW}
    if(IOCAFbits.IOCAF5 == 1)
    {
        SW_ISR();  
    }
}
   
/**
   SW Interrupt Service Routine
*/
void SW_ISR(void) {

    // Add custom IOCAF5 code

    // Call the interrupt handler for the callback registered at runtime
    if(SW_InterruptHandler)
    {
        SW_InterruptHandler();
    }
    IOCAFbits.IOCAF5 = 0;
}

/**
  Allows selecting an interrupt handler for IOCAF5 at application runtime
*/
void SW_SetInterruptHandler(void (* InterruptHandler)(void)){
    SW_InterruptHandler = InterruptHandler;
}

/**
  Default interrupt handler for IOCAF5
*/
void SW_DefaultInterruptHandler(void){
    // add your SW interrupt custom code
    // or set custom function using SW_SetInterruptHandler()
}
/**
 End of File
*/