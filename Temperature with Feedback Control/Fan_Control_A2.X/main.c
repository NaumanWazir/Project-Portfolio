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
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.7
        Device            :  PIC16LF18326
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
#include "MCP9808.h"
#include "pid.h"

#include "slave_service.h"

bool time,F_startup=0;

float Tol_max = max;
float Tol_min = min;

float Tol_1 = 1.0;
float Tol_2 = -1.0;

uint8_t MaxFanSpeed = 100;//100;
float percent = 1.0;
uint16_t duty = 0xFFFF;
  
extern float SetTemp;
extern POSPID temp_ctrl;
extern float offset_temp,offFan_temp;

/*
                         Main application
*/
float temperature;
void main(void)
{
    float temperature_temp;
    // initialize the device
    SYSTEM_Initialize();   
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    
    init_pid();
    MCP9808_init();
    
    //load default value..
    SetTemp = target;
    Tol_max = SetTemp + Tol_1;
    Tol_min = SetTemp + Tol_2;
    offFan_temp = Tol_min;
    offset_temp = 2.5;
    percent = ((float)MaxFanSpeed/(float)100.0);

    while (1)
    { 
        if(time == 1)
        {
            Read_temp_MCP();
            temperature = cal_temp();
            //temperature = Tol_max + 10;
			
            temperature_temp = temperature;
            
            
            if((percent >= 0.25) && (percent < 0.50))
                duty = (uint16_t)(((float)0x140)*percent) + 0x2C;
            else if((percent >=0.50)&&(percent < 0.75))                
                duty = (uint16_t)(((float)0x140)*percent) + 0x2F;// One 1% offset in fan require offset of 3 in pwm
            else if((percent >=0.75)&&(percent < 0.90))                
                duty = (uint16_t)(((float)0x140)*percent) + 0x2C;// One 1% offset in fan require offset of 3 in pwm
            else                
                duty = (uint16_t)(((float)0x140)*percent);
            
            pos_PIDRegulation(&temp_ctrl,temperature_temp);        
            //if temperature > max 71, fan running in full speed.
            if(temperature > Tol_max)                    
            {               
                PWM5_LoadDutyValue(duty);
            }
            else if (temperature < Tol_min)               //else fan running in min speed
            {
                PWM5_LoadDutyValue(0); 
            }
            else
            {
                //duty = (uint16_t)(((float)0x140)*percent);
                if((uint16_t)fabs(temp_ctrl.result) > duty) temp_ctrl.result = (float)(duty);
                PWM5_LoadDutyValue((uint16_t)fabs(temp_ctrl.result));
            }
      
            //  PWM5_LoadDutyValue(duty);
            update_slave_reg();
            time = 0;
        }
        
        if(temperature < offFan_temp)
        {
            IO_RA5_SetLow();
        }
        else
        {
            IO_RA5_SetHigh(); 
        }       
    }
}

/**
 End of File
*/