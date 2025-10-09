/**
  PIN MANAGER Generated Driver File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the PIC24 / dsPIC33 / PIC32MM MCUs device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for PIN MANAGER.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.171.4
        Device            :  PIC24FJ256GA702
    The generated drivers are tested against the following:
        Compiler          :  XC16 v2.10
        MPLAB 	          :  MPLAB X v6.05
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/


/**
    Section: Includes
*/

#include <xc.h>
#include <stdio.h>
#include "pin_manager.h"

/**
 Section: File specific functions
*/
void (*ECHO2_InterruptHandler)(void) = NULL;
void (*ECHO1_InterruptHandler)(void) = NULL;
void (*A1_InterruptHandler)(void) = NULL;
void (*A2_InterruptHandler)(void) = NULL;
void (*B1_InterruptHandler)(void) = NULL;
void (*B2_InterruptHandler)(void) = NULL;

/**
 Section: Driver Interface Function Definitions
*/
void PIN_MANAGER_Initialize (void)
{
    /****************************************************************************
     * Setting the Output Latch SFR(s)
     ***************************************************************************/
    LATA = 0x0000;
    LATB = 0x4000;

    /****************************************************************************
     * Setting the GPIO Direction SFR(s)
     ***************************************************************************/
    TRISA = 0x0009;
    TRISB = 0x80F3;

    /****************************************************************************
     * Setting the Weak Pull Up and Weak Pull Down SFR(s)
     ***************************************************************************/
    IOCPDA = 0x0000;
    IOCPDB = 0x00F0;
    IOCPUA = 0x0000;
    IOCPUB = 0x0000;

    /****************************************************************************
     * Setting the Open Drain SFR(s)
     ***************************************************************************/
    ODCA = 0x0000;
    ODCB = 0x0000;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR(s)
     ***************************************************************************/
    ANSA = 0x0000;
    ANSB = 0x0000;
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    RPOR5bits.RP11R = 0x0010;    //RB11->MCCP2:OCM2A
    RPOR1bits.RP2R = 0x0012;    //RB2->MCCP3:OCM3A
    RPINR18bits.U1RXR = 0x000F;    //RB15->UART1:U1RX
    RPOR7bits.RP14R = 0x0003;    //RB14->UART1:U1TX

    __builtin_write_OSCCONL(OSCCON | 0x40); // lock PPS
    
    /****************************************************************************
     * Interrupt On Change: any
     ***************************************************************************/
    IOCNAbits.IOCNA0 = 1;    //Pin : RA0
    IOCNAbits.IOCNA3 = 1;    //Pin : RA3
    IOCNBbits.IOCNB4 = 1;    //Pin : RB4
    IOCNBbits.IOCNB5 = 1;    //Pin : RB5
    IOCNBbits.IOCNB6 = 1;    //Pin : RB6
    IOCNBbits.IOCNB7 = 1;    //Pin : RB7
    IOCPAbits.IOCPA0 = 1;    //Pin : RA0
    IOCPAbits.IOCPA3 = 1;    //Pin : RA3
    IOCPBbits.IOCPB4 = 1;    //Pin : RB4
    IOCPBbits.IOCPB5 = 1;    //Pin : RB5
    IOCPBbits.IOCPB6 = 1;    //Pin : RB6
    IOCPBbits.IOCPB7 = 1;    //Pin : RB7
    /****************************************************************************
     * Interrupt On Change: flag
     ***************************************************************************/
    IOCFAbits.IOCFA0 = 0;    //Pin : RA0
    IOCFAbits.IOCFA3 = 0;    //Pin : RA3
    IOCFBbits.IOCFB4 = 0;    //Pin : RB4
    IOCFBbits.IOCFB5 = 0;    //Pin : RB5
    IOCFBbits.IOCFB6 = 0;    //Pin : RB6
    IOCFBbits.IOCFB7 = 0;    //Pin : RB7
    /****************************************************************************
     * Interrupt On Change: config
     ***************************************************************************/
    PADCONbits.IOCON = 1;    //Config for PORTA
    
    /* Initialize IOC Interrupt Handler*/
    ECHO2_SetInterruptHandler(&ECHO2_CallBack);
    ECHO1_SetInterruptHandler(&ECHO1_CallBack);
    A1_SetInterruptHandler(&A1_CallBack);
    A2_SetInterruptHandler(&A2_CallBack);
    B1_SetInterruptHandler(&B1_CallBack);
    B2_SetInterruptHandler(&B2_CallBack);
    
    /****************************************************************************
     * Interrupt On Change: Interrupt Enable
     ***************************************************************************/
    IFS1bits.IOCIF = 0; //Clear IOCI interrupt flag
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void __attribute__ ((weak)) ECHO2_CallBack(void)
{

}

void __attribute__ ((weak)) ECHO1_CallBack(void)
{

}

void __attribute__ ((weak)) A1_CallBack(void)
{

}

void __attribute__ ((weak)) A2_CallBack(void)
{

}

void __attribute__ ((weak)) B1_CallBack(void)
{

}

void __attribute__ ((weak)) B2_CallBack(void)
{

}

void ECHO2_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    ECHO2_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void ECHO2_SetIOCInterruptHandler(void *handler)
{ 
    ECHO2_SetInterruptHandler(handler);
}

void ECHO1_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    ECHO1_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void ECHO1_SetIOCInterruptHandler(void *handler)
{ 
    ECHO1_SetInterruptHandler(handler);
}

void A1_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    A1_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void A1_SetIOCInterruptHandler(void *handler)
{ 
    A1_SetInterruptHandler(handler);
}

void A2_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    A2_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void A2_SetIOCInterruptHandler(void *handler)
{ 
    A2_SetInterruptHandler(handler);
}

void B1_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    B1_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void B1_SetIOCInterruptHandler(void *handler)
{ 
    B1_SetInterruptHandler(handler);
}

void B2_SetInterruptHandler(void (* InterruptHandler)(void))
{ 
    IEC1bits.IOCIE = 0; //Disable IOCI interrupt
    B2_InterruptHandler = InterruptHandler; 
    IEC1bits.IOCIE = 1; //Enable IOCI interrupt
}

void B2_SetIOCInterruptHandler(void *handler)
{ 
    B2_SetInterruptHandler(handler);
}

/* Interrupt service routine for the IOCI interrupt. */
void __attribute__ (( interrupt, no_auto_psv )) _IOCInterrupt ( void )
{
    if(IFS1bits.IOCIF == 1)
    {
        if(IOCFAbits.IOCFA0 == 1)
        {
            if(ECHO2_InterruptHandler) 
            { 
                ECHO2_InterruptHandler(); 
            }
            
            IOCFAbits.IOCFA0 = 0;  //Clear flag for Pin - RA0

        }
        
        if(IOCFAbits.IOCFA3 == 1)
        {
            if(ECHO1_InterruptHandler) 
            { 
                ECHO1_InterruptHandler(); 
            }
            
            IOCFAbits.IOCFA3 = 0;  //Clear flag for Pin - RA3

        }
        
        if(IOCFBbits.IOCFB4 == 1)
        {
            if(A1_InterruptHandler) 
            { 
                A1_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB4 = 0;  //Clear flag for Pin - RB4

        }
        
        if(IOCFBbits.IOCFB6 == 1)
        {
            if(A2_InterruptHandler) 
            { 
                A2_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB6 = 0;  //Clear flag for Pin - RB6

        }
        
        if(IOCFBbits.IOCFB5 == 1)
        {
            if(B1_InterruptHandler) 
            { 
                B1_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB5 = 0;  //Clear flag for Pin - RB5

        }
        
        if(IOCFBbits.IOCFB7 == 1)
        {
            if(B2_InterruptHandler) 
            { 
                B2_InterruptHandler(); 
            }
            
            IOCFBbits.IOCFB7 = 0;  //Clear flag for Pin - RB7

        }
        
        
        // Clear the flag
        IFS1bits.IOCIF = 0;
    }
}

