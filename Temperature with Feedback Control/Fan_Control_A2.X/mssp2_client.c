#include "mssp2_client.h"

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

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>

// Temp register
static volatile uint8_t temp = 0;

//Functions to call on specific events
static void (*storeByte)(uint8_t) = NULL;
static uint8_t (*getByte)(void) = NULL;
static void (*I2C2StopHandler) (void) = NULL;

#define SLAVE_ADD 0x10


void MSSP_ClientInit(void)
{
    //Reset Registers
    SSP2CON1 = 0x00;
    SSP2CON2 = 0x00;
    SSP2CON3 = 0x00;
    SSP2STAT = 0x00;
        
    //Disable slew control for Standard mode
    SSP2STATbits.SMP = 1;
    
    //Set MSSP Operating Mode (7-bit Client)
    SSP2CON1bits.SSPM = 0b0110;
    
    //Enable clock stretching
    SSP2CON2bits.SEN = 1;
    
    //Enable bus collision interrupts
    SSP2CON3bits.SBCDE = 1;
    
    //Enable STOP Interrupts
    SSP2CON3bits.PCIE = 1;
    
    //Load client address
    SSP2ADD = (SLAVE_ADD << 1);
    
    //Clear Bus Collision interrupt flag
    PIR2bits.BCL2IF = 0;
    
    //Clear the SSP interrupt flag
    PIR2bits.SSP2IF = 0;
    
    //Enable BCLIF
  //  PIE2bits.BCL2IE = 1;
    
    //Enable SSPIF
    PIE2bits.SSP2IE = 1;
    
    //Enable the module
    SSP2CON1bits.SSPEN = 1;
}

void _MSSP_ProcessInterrupt(void)
{
    //Check for SSPIF
    if(PIR2bits.SSP2IF)                                                         
    {
        if (SSP2STATbits.P)
        {
            //Stop Condition
            
            if (I2C2StopHandler != NULL)
            {
                //If valid, call the I2C Stop Event Function
                I2C2StopHandler();
            }
        }
        else if(SSP2STATbits.R_nW)//read
        {
            //Host wants to read (client transmit)
            if (getByte != NULL)
            {
                //Get the byte to send
                SSP2BUF = getByte();
            }
            else
            {
                //Write a default value
                SSP2BUF = 0x00;
            }
        }   
        else if(!SSP2STATbits.R_nW) //write
        {
            // Host wants to write (client receive)
            if(!SSP2STATbits.D_nA)   //address                                            
            {
                //Last byte was an address
                
                //Clear the Buffer Full (BF) flag
                temp = SSP1BUF;
            }
            if(SSP2STATbits.D_nA)       //data
            {
                //Last byte was data
                
                if (storeByte != NULL)
                {
                    //Store the byte from the host
                    storeByte(SSP2BUF);
                }
                else
                {
                    //Clear the Buffer Full (BF) flag
                    temp = SSP2BUF;
                }
            }
        }
    }
    if(PIR2bits.BCL2IF)
    {
        //Clear the Buffer Full (BF) flag
        temp = SSP2BUF;
        
        // Clear BCLIF
        PIR2bits.BCL2IF = 0;
    }
    
    //Release Clock Stretch
    SSP2CON1bits.CKP = 1;
    
    //Clear SSP1IF
    PIR2bits.SSP2IF = 0;
}

void assignMSSPByteWriteHandler(void (*writeHandler)(uint8_t))
{
    storeByte = writeHandler;
}

void assignMSSPByteReadHandler(uint8_t (*readHandler)(void))
{
    getByte = readHandler;
}

void assignMSSPStopHandler(void (*stopHandler)(void))
{
    I2C2StopHandler = stopHandler;
}
