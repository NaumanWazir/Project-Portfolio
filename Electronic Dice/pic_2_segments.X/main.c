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
        Device            :  PIC16F1847
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


#define P1	LATBbits.LATB0
#define P2	LATBbits.LATB1  
#define P3	LATBbits.LATB2
#define P4	LATBbits.LATB3
#define P5	LATAbits.LATA6
#define P6	LATAbits.LATA7
#define P7	LATAbits.LATA0
#define P8	LATAbits.LATA1

#define B1 PORTBbits.RB4
#define B2 PORTAbits.RA5

void timer2ISR(void);
char getStates(void);
void change_state(char);
void display_U1(uint8_t);
void display_U2(uint8_t);
void reset_display(void);
void off_display(void);
uint8_t B1_state = 0;
uint8_t B2_state = 0;
uint32_t tick = 0;

void timer2ISR(void){
    tick++;
}

char getStates(void)
{
    if (B1 == LOW)
        return 1;
    if (B2 == LOW)
        return 2;
    return 0;    
}
void change_state(char state)
{
    switch(state)
    {
        case 1:
                B1_state++;   
                break;
        case 2:
                B2_state++;
				B1_state = 0;				
                break;
        default://printf("b0");
                break;        
    }    
}
void reset_display(void){
    P1 = 0;
    P2 = 0;
    P3 = 0;
    P4 = 0;    
    P5 = 0;
    P6 = 0;
    P7 = 0;
    P8 = 0;
}

void off_display(void){
    P1 = 0;
    P2 = 1;
    P3 = 0;
    P4 = 1;    
    P5 = 0;
    P6 = 1;
    P7 = 0;
    P8 = 1;
}

void display_U1(uint8_t input){
    P1 = (input >> 0) & 0x01;
    P2 = (input >> 1) & 0x01;
    P3 = (input >> 2) & 0x01;
    P4 = (input >> 3) & 0x01;
}
void display_U2(uint8_t input){
    P5 = (input >> 0) & 0x01;
    P6 = (input >> 1) & 0x01;
    P7 = (input >> 2) & 0x01;
    P8 = (input >> 3) & 0x01;
}

/*
                         Main application
 */
void main(void)
{
    char button_state;
    char last_button_state = 0;
    uint8_t counter = 0;
    // initialize the device
    SYSTEM_Initialize();
    //TMR2_StartTimer();
    TMR2_SetInterruptHandler(timer2ISR);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    reset_display();
    while (1)
    {
        button_state = getStates();
        if (button_state != last_button_state)
        {
            if(button_state > 0)
            {
                change_state(button_state);
           
                if(B1_state == 1)
                {
                    B2_state = 0;
                    counter = (uint8_t)tick;
                    //counter = TMR2_ReadTimer();
                    do{
                    counter = counter/6;
                    }while(counter > 5);
                    display_U1(counter+1);
                    //printf("B1_1:%u \n\r",counter+1);
                }
                if(B1_state == 2)
                {
                    B2_state = 0;
                    counter = (uint8_t)tick;
                    //counter = TMR2_ReadTimer();
                    do{
                        counter = counter/6;
                    }while(counter > 5);
                    display_U2(counter+1);
                    //printf("B1_2:%u \n\r",counter+1);
                    B1_state = 0;
                }
                if(B2_state == 1)
                {
                    reset_display();
                    B1_state = 0;
                }
                if(B2_state == 2)
                {
                    off_display();
                    B1_state = 0;
                    B2_state = 0;
                }
                
            }
            last_button_state = button_state;   
        }
        __delay_ms(50);
        
        
        
        // Add your application code
    }
}
/**
 End of File
*/