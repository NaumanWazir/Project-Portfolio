/**
  PWM4 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    pwm4.c

  @Summary
    This is the generated driver implementation file for the PWM4 driver using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides implementations for driver APIs for PWM4.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16LF1574
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above or later
        MPLAB             :  MPLAB X 6.00
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

/**
  Section: Included Files
*/

#include <xc.h>
#include "pwm4.h"

/**
  Section: PWM4 APIs
*/

void PWM4_Initialize(void)
{
    // set the PWM4 to the options selected in the User Interface

     //PHIE disabled; DCIE disabled; OFIE disabled; PRIE disabled; 
    PWM4INTE = 0x00;

     //PHIF cleared; OFIF cleared; DCIF cleared; PRIF cleared; 
    PWM4INTF = 0x00;

     //PS No_Prescalar; CS FOSC; 
    PWM4CLKCON = 0x00;

     //LDS LD1_trigger; LDT disabled; LDA load; 
    PWM4LDCON = 0x80;

     //OFM independent_run; OFS OF1_match; OFO match_incrementing; 
    PWM4OFCON = 0x00;

     //PWM4PHH 0; 
    PWM4PHH = 0x00;

     //PWM4PHL 0; 
    PWM4PHL = 0x00;

     //PWM4DCH 0; 
    PWM4DCH = 0x00;

     //PWM4DCL 0; 
    PWM4DCL = 0x00;

     //PWM4PRH 125; 
    PWM4PRH = 0x7D;

     //PWM4PRL 0; 
    PWM4PRL = 0x00;

     //PWM4OFH 0; 
    PWM4OFH = 0x00;

     //PWM4OFL 31; 
    PWM4OFL = 0x1F;

     //PWM4TMRH 0; 
    PWM4TMRH = 0x00;

     //PWM4TMRL 0; 
    PWM4TMRL = 0x00;

     //MODE standard_PWM; POL active_hi; EN enabled; 
    //PWM4CON = 0x80;

}    


void PWM4_Start(void)
{
    PWM4CONbits.EN = 1;		
}

void PWM4_Stop(void)
{
    PWM4CONbits.EN = 0;		
}

/*bool PWM4_CheckOutputStatus(void)
{
    return (PWM4CONbits.OUT);		
}*/

void PWM4_LoadBufferSet(void)
{
    PWM4LDCONbits.LDA = 1;		
}

/*void PWM4_PhaseSet(uint16_t phaseCount)
{
    PWM4PHH = (phaseCount>>8);        //writing 8 MSBs to PWMPHH register
    PWM4PHL = (uint8_t)(phaseCount);           //writing 8 LSBs to PWMPHL register
}*/

void PWM4_DutyCycleSet(uint16_t dutyCycleCount)
{
    PWM4DCH = (dutyCycleCount>>8);	//writing 8 MSBs to PWMDCH register
    PWM4DCL = (uint8_t)(dutyCycleCount);	//writing 8 LSBs to PWMDCL register		
}

/*void PWM4_PeriodSet(uint16_t periodCount)
{
    PWM4PRH = (periodCount>>8);	//writing 8 MSBs to PWMPRH register
    PWM4PRL = (uint8_t)(periodCount);	//writing 8 LSBs to PWMPRL register		
}*/

/*void PWM4_OffsetSet(uint16_t offsetCount)
{
    PWM4OFH = (offsetCount>>8);	//writing 8 MSBs to PWMOFH register
    PWM4OFL = (uint8_t)(offsetCount);	//writing 8 LSBs to PWMOFL register		
}*/

/*uint16_t PWM4_TimerCountGet(void)
{
    return ((uint16_t)((PWM4TMRH<<8) | PWM4TMRL));       		
}*/

/*bool PWM4_IsOffsetMatchOccured(void)
{
    return (PWM4INTFbits.OFIF);		
}*/

/*bool PWM4_IsPhaseMatchOccured(void)
{
    return (PWM4INTFbits.PHIF);	
}*/

/*bool PWM4_IsDutyCycleMatchOccured(void)
{
    return (PWM4INTFbits.DCIF);		
}*/

/*bool PWM4_IsPeriodMatchOccured(void)
{
    return (PWM4INTFbits.PRIF);		
}*/

/**
 End of File
*/


