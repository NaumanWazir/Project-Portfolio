/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
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
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/mccp2_compare.h"
#include "mcc_generated_files/mccp3_compare.h"
#include "mcc_generated_files/tmr1.h"
#include "mcc_generated_files/uart1.h"
//#include "pid_controller.h"
#include "stdio.h"
#define PULSESBYENC 390
#define DISTANCETHRESHOLD 2

uint8_t Current_A1 = 0;
uint8_t Current_B1 = 0;
uint8_t Current_A2 = 0;
uint8_t Current_B2 = 0;
uint8_t Previous_A1 = 0;
uint8_t Previous_B1 = 0;
uint8_t Previous_A2 = 0;
uint8_t Previous_B2 = 0; 
volatile uint8_t Direction_1 = 0; 
volatile uint8_t Direction_2 = 0;
volatile int16_t counter_1 = 0;
volatile int16_t counter_2 = 0;
int16_t map(float,float,float,float,float);
int16_t map(float x, float in_min, float in_max, float out_min, float out_max) {
    
   float a =  x - in_min;
   float b = out_max - out_min;
   float c = in_max - in_min;
   float d = (a/c);
   float e = d * b + out_min;  
   return (int16_t)e;
}
uint16_t time1 = 0;
volatile uint8_t Calculate_D1 = 0;
volatile uint8_t measure_D1 = 0;
void Echo1(void){
    if(measure_D1 == 1)
    {
        if(ECHO1_GetValue()==1)
        {
            TMR2_Counter16BitSet(0);
            TMR2_Start();
        }
        else
        {
            TMR2_Stop();
            time1 = TMR2_Counter16BitGet();
            Calculate_D1 = 1;
            measure_D1 = 0;
        }
    }   
}
uint16_t time2 = 0;
volatile uint8_t Calculate_D2 = 0;
volatile uint8_t measure_D2 = 0;
void Echo2(void){
    if(measure_D2 == 1)
    {
        if(ECHO2_GetValue()==1)
        {
            TMR3_Counter16BitSet(0);
            TMR3_Start();
        }
        else
        {
            TMR3_Stop();
            time2 = TMR3_Counter16BitGet();
            Calculate_D2 = 1;
            measure_D2 = 0;
        }
    }   
}


void IOC_Routine(void){
    Current_A1 = A1_GetValue();
    Current_B1 = B1_GetValue();
    if(Current_A1 != Previous_A1)
        counter_1++;
    
    Current_A2 = A2_GetValue();
    Current_B2 = B2_GetValue();
    if(Current_A2 != Previous_A2)
        counter_2++;
    
    
    Direction_1 = Previous_B1 ^ Current_A1;
    
    Direction_2 = Previous_B2 ^ Current_A2;  
    
    Previous_A1 = Current_A1;
    Previous_B1 = Current_B1;
    
    Previous_A2 = Current_A2;
    Previous_B2 = Current_B2; 
    
}
uint16_t period = 0x31F;
  
void setMotor1(int8_t dir, uint16_t pwmVal){
  
  EN_A_SetHigh();
  if(dir == 1){
    DIRA_P_SetHigh();
    DIRA_N_SetLow();
  }
  else if(dir == -1){
    DIRA_N_SetHigh();
    DIRA_P_SetLow();
  }
  else{
    EN_A_SetLow();  
    DIRA_P_SetLow();
    DIRA_N_SetLow();
  }
  MCCP2_COMPARE_DualEdgeBufferedConfig(period,pwmVal);
}

void setMotor2(int8_t dir, uint16_t pwmVal){
  
  EN_B_SetHigh();
  if(dir == 1){
    DIRB_P_SetHigh();
    DIRB_N_SetLow();
  }
  else if(dir == -1){
    DIRB_N_SetHigh();
    DIRB_P_SetLow();
  }
  else{
    EN_B_SetLow();  
    DIRB_P_SetLow();
    DIRB_N_SetLow();
  }
  MCCP3_COMPARE_DualEdgeBufferedConfig(period,pwmVal);
}

void run_forward(uint16_t pwmVal){
    setMotor1(1,pwmVal);
    setMotor2(1,pwmVal);
}

void run_backward(uint16_t pwmVal){
    setMotor1(-1,pwmVal);
    setMotor2(-1,pwmVal);
}

void run_left(uint16_t pwmVal){
    setMotor1(-1,pwmVal);
    setMotor2(1,pwmVal);
}

void run_right(uint16_t pwmVal){
    setMotor1(1,pwmVal);
    setMotor2(-1,pwmVal);
}
void stop(void){
    setMotor1(0,0);
    setMotor2(0,0);
}
// runs at 10ms
volatile uint8_t mainloop = 0;
void TIMER1_ISR(void){
    mainloop = 1;
}
/*
                         Main application
 */
int main(void)
{
    int16_t current_v1; 
    int16_t current_v2;
    float Distance_1 = 0;
    float Distance_2 = 0;
    uint8_t duty_cycle = 50;
    uint16_t pwm = period*duty_cycle/100;  
    uint8_t duty_cycle_updated = 50;
    char Message[4];
    uint8_t index = 0;
    uint8_t ticks = 0;
    // initialize the device
    SYSTEM_Initialize();
    printf("Program Started");
    //L298 Settings
    //Disable both
    EN_A_SetLow();
    EN_B_SetLow();
    
    A1_SetInterruptHandler(IOC_Routine);
    B1_SetInterruptHandler(IOC_Routine);
    A2_SetInterruptHandler(IOC_Routine);
    B2_SetInterruptHandler(IOC_Routine);
    ECHO2_SetInterruptHandler(Echo1);
    ECHO1_SetInterruptHandler(Echo2);
    TMR1_SetInterruptHandler(TIMER1_ISR);
    
    while (1)
    {
        if(UART1_IsRxReady())
        {
            char rx = UART1_Read();
            if(rx == 'A' || rx == 'a')
            {    
                printf("Left\n\r");
                run_left(pwm);
            }
            if(rx == 'S' || rx == 's')
            {
                printf("Right\n\r");
                run_right(pwm);
            }
            if(rx == 'W' || rx == 'w')
            {
                printf("Forward\n\r");
                run_forward(pwm);
            }
            if(rx == 'Z' || rx == 'z')
            {
                printf("backward\n\r");
                run_backward(pwm);
            }
            if(rx == 'X' || rx == 'x')
            {
                printf("stop\n\r");
                stop();
            }if(rx == 'Q' || rx == 'q')
            {
                printf("Please Enter number between 0 to 100\n\r");
                //scanf("%u",&duty_cycle);
                //printf("%d\n\r",duty_cycle);
                while(1)
                {
                    Message[index] = UART1_Read();
                    if((Message[index] >= '0')&& (Message[index] <= '9') )
                    {
                        //printf("%c",Message[index]);
                        uint8_t num  = (uint8_t)(Message[index++]) - 0x30;
                        //printf(":%u \n\r",num);
                        if(index == 1)
                        {    
                            duty_cycle_updated = num;
                            printf("%u \r",duty_cycle_updated);
                        }
                        if(index == 2)
                        {    
                            duty_cycle_updated = duty_cycle_updated*10 + num;
                            printf("%u \r",duty_cycle_updated);
                        }
                        if(index == 3)
                        {    
                            duty_cycle_updated = duty_cycle_updated*10 + num;
                            printf("%u \r",duty_cycle_updated);
                            index = 0;
                            break;
                        }
                    }
                    else{
                        printf("Invalid entry\n\r");
                        index = 0;
                    }
                }
                printf("Duty cycle:%u \n\r",duty_cycle_updated);
                if(duty_cycle_updated > 100 )
                    printf("Invalid duty cycle\n\r");
                else
                {    
                    duty_cycle = duty_cycle_updated;
                    pwm = period*duty_cycle/100;
                }
            }
        }
        if(mainloop)
        {   
            ticks++;
            current_v1 = Direction_1*counter_1/PULSESBYENC;
            counter_1 = 0;
            current_v2 = Direction_2*counter_2/PULSESBYENC;
            counter_2 = 0;
            
            TRIG1_SetHigh();
            DELAY_milliseconds(10);
            TRIG1_SetLow();
            measure_D1 = 1;
            
            TRIG2_SetHigh();
            DELAY_milliseconds(10);
            TRIG2_SetLow();
            measure_D2 = 1;
            
            if(Calculate_D1 == 1)
            {
                Distance_1 = (34000*time1)/(2*4000000);
                Calculate_D1 = 0;
            }
            
            if(Calculate_D2 == 1)
            {
                Distance_2 = (34000*time2)/(2*4000000);
                Calculate_D2 = 0;
            }
            
            //printf speed after 1 sec;
            if(ticks == 100)
            {
                printf("V1:%d \n\r",current_v1);
                printf("V2:%d \n\r",current_v2);
                
                printf("D1:%f \n\r",Distance_1);
                printf("D2:%f \n\r",Distance_2);
                
                if((Distance_1 < DISTANCETHRESHOLD) ||(Distance_2 < DISTANCETHRESHOLD))
                    Buzz_SetHigh();
                else
                    Buzz_SetLow();
                ticks = 0;
            }
            mainloop = 0;
        }
    }


    return 1;
}
/**
 End of File
*/

