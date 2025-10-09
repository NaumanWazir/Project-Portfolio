/*
 * File:   main.c
 * Author: nauma
 *
 * Created on March 14, 2023, 2:34 PM
 */

#include "device_config.h"
#include "pin_manager.h"
#include "eusart1.h"
#include "interrupt_manager.h"
#include "tmr2.h"
#include "adc.h"
#include "spi.h"

#include "ST7735_TFT.h"
#include "FreeSansBold9pt7b.h"
#include "Picopixel.h"

#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <xc.h>


//#define char_width 18
//#define char_length 15
#define ADC_RES (float)(5/1023.00)
#define B1 PORTAbits.RA7
#define B2 PORTAbits.RA6
#define B3 PORTCbits.RC0
#define B4 PORTCbits.RC1
#define LED LATCbits.LATC2
#define AmWH 10782
#define CmWH 10782
#define GRAPHMAX 5.00
#define Sample 10
#define Refresh 5

void myTimer2ISR(void);
char getStates(void);
void change_state(char);
void update_display(int8_t);
void display_default(void);
void display_page1(void);
void display_page2(void);
void display_page3(void);
void display_page4(void);
int map(float,float,float,float,float);
void text6_display(uint8_t,uint8_t,float,uint16_t);
void text2_display(uint8_t,uint8_t,uint8_t,uint16_t);
void clean_writable_area(void);
uint8_t counter = 0;
uint8_t one_sec = 0;
uint8_t led_state = 0;
int8_t current_display = 0;
int8_t current_rotation = 1;
uint8_t flag_update_display = 1;
uint8_t flag_rotation = 1;
uint8_t not_retain_values = 1;
uint8_t position_text[8][2];
uint16_t previous_valus[8];
float previous_valus_ft[3];
uint8_t update = 0;
float adc_err;
// 20 ms interrupt timer
void myTimer2ISR(void){
    counter++;
    update++;
    
    if(counter == 50)
    {
        counter = 0;
        one_sec = 1;
    }
}
char getStates(void)
{
    if (B1 == HIGH)
        return 1;
    if (B2 == HIGH)
        return 2;
    if (B3 == HIGH)
        return 3;
    if (B4 == HIGH)
        return 4;
return 0;    
}
void change_state(char state)
{
    switch(state)
    {
        case 1: printf("b1");
                current_display--;   
                if (current_display < 0)
                    current_display = 5;
                break;
        case 2: printf("b2");
                current_display++;   
                if (current_display > 5)
                    current_display = 0; 
                break;    
        case 3: printf("b3");
                current_rotation--;   
                if (current_rotation < 0)
                    current_rotation = 3;
                break;
        case 4: printf("b4");              
                current_rotation++;   
                if (current_rotation > 3)
                    current_rotation = 0;
                break;
        default:printf("b0");
                break;        
    }    
}


void update_display(int8_t cases)
{
    switch(cases)
	{
        case 0:
            display_page1();
            break;
        case 1:
            display_page1();
            break;
        case 2:
            display_page2();
            break;
        case 3:
            display_page3();
            break;
        case 4:
            display_page4();
            break;
        case 5:
            display_page4();
            break;
        default:
            display_page1();
    }
}

void main(void) 
{
    char button_state;
    char last_button_state;
    uint16_t result;
    OSCCON = 0x70;
    TRISB = 0x00;
    TRISBbits.TRISB0 = 0;
    TRISAbits.TRISA7 = 1;
    TRISAbits.TRISA6 = 1;    
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC0 = 1;
    TRISCbits.TRISC2 = 0;
    
    TRISCbits.TRISC5 = 0;
    TRISCbits.TRISC4 = 1;

    LATBbits.LATB0 = 1;
    LATCbits.LATC2 = 1;
    
    
    EUSART1_Initialize();
    ADC_Initialize();
    SPI_Initialize();
    SPI_Open(SPI_DEFAULT);
	INTERRUPT_Initialize();
	TMR2_Initialize();
    TMR2_SetInterruptHandler(myTimer2ISR);
    printf("nauman\n\r");
    TFT_BlackTab_Initialize();
    fillScreen(ST7735_BLACK);
    setRotation(1);
    setTextWrap(false);
    setFont(&FreeSansBold9pt7b);
    display_default();
    display_page1();
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    while(1)
    {
        button_state = getStates();
        if (button_state != last_button_state)
        {
            if(button_state > 0)
            {
                change_state(button_state);
                if(button_state == 3 || button_state == 4 )
                {   
                    setRotation((uint8_t)current_rotation);
                    not_retain_values = 0;
                    if(current_rotation == 1 || current_rotation == 3)
                        flag_rotation = 1;
                    else
                        flag_rotation = 0;
                    display_default();
                }
                flag_update_display = 1;
            }
            last_button_state = button_state;
        }
        if(update >= Refresh)
        {
            result = ADC_GetConversion(channel_AN4);
            adc_err = ((result * ADC_RES)* 0.809);
            
            update_display(current_display);
            not_retain_values = 1;
            update = 0;
        }
//         __delay_ms(10);
    }
    return;
}


void display_default(void){
    uint8_t x0 = 5;
    uint8_t y0 = 5;
    fillScreen(ST7735_BLACK);
    fillRoundRect(x0, y0, tft_width - 10,22, 1, ST7735_BLUE);  
    //draw arrow right
    x0 = tft_width - 25;
    y0 = 6;
    drawRoundRect(x0,y0,12,15,3,ST7735_WHITE);
    drawFastVLine(x0+11,y0,15,ST7735_BLUE);
    drawFastVLine(x0+10,y0,15,ST7735_BLUE);
    fillTriangle(x0+10,y0+10,x0+10,y0+20,x0+15,y0+15,ST7735_WHITE);
    
    //draw arrow left
    x0 = 12;
    y0 = 6;
    drawRoundRect(x0,y0,12,15,3,ST7735_WHITE);
    drawFastVLine(x0,y0,15,ST7735_BLUE);
    drawFastVLine(x0+1,y0,15,ST7735_BLUE);
    fillTriangle(x0+1,y0+10,x0+1,y0+20,x0-4,y0+15,ST7735_WHITE);
 
    x0 = 5;
    y0 = tft_height - 22;
    fillRoundRect(x0,y0, ((tft_width - 5)/2) - 5, 22, 1, ST7735_BLUE);
    fillRoundRect(((tft_width - 5)/2) + 5, y0,((tft_width - 5)/2) - 5, 22, 1, ST7735_BLUE);   
    
    y0 = y0 + 14;
    char *txttwo = "PREV";    
    char *txtone = "NEXT";
    if(flag_rotation)
    {
        x0 = 18;    
        drawText( x0, y0+3, txttwo, ST7735_WHITE, ST7735_WHITE, 1);
        x0 = ((tft_width - 5)/2) + 18;
        drawText( x0, y0+3, txtone, ST7735_WHITE, ST7735_WHITE, 1);
    }
    else
    {
        x0 = 10;    
        drawText( x0, y0, txttwo, ST7735_WHITE, ST7735_WHITE, 1);
        x0 = ((tft_width - 5)/2) + 10;
        drawText( x0, y0, txtone, ST7735_WHITE, ST7735_WHITE, 1);
    }
}


void display_page1(void)
{
    uint8_t x0 = 5;
    uint8_t y0 = 5;    
    uint8_t GP;
    float voltage,current,temp;
    float watt,ohms,mAh,mWh;
    uint16_t result[3];
    char v0[6];
    //setFont(&FreeSansBold9pt7b);

    if(flag_update_display)
    { 
        clean_writable_area();
        //line 1
        x0 = 5;
        y0 = 45;
        position_text[0][0] = x0;
        position_text[0][1] = y0;
        drawChar(x0 + 54 ,y0,'V',ST7735_GREEN, ST7735_BLACK, 1);

        //draw thermometer
        uint8_t x1 = tft_width - 45;
        uint8_t y1 = y0-3;
        drawCircle(x1,y1,4,ST7735_YELLOW);
        fillCircle(x1,y1,2,ST7735_YELLOW);
        fillRect(x1,y1-11,1,8,ST7735_YELLOW);
        drawRoundRect(x1-2,y1-13,5,11,1,ST7735_YELLOW);
        drawFastVLine(x1+3,y1-11,1,ST7735_YELLOW);
        drawFastVLine(x1+3,y1-9,1,ST7735_YELLOW);
        drawFastVLine(x1+3,y1-7,1,ST7735_YELLOW);
        //thermometer ends

        drawCircle(tft_width - 20,y0 - 10,1,ST7735_YELLOW);
        drawChar(tft_width - 19 ,y0,'C',ST7735_YELLOW, ST7735_BLACK, 1); 


        position_text[1][0] = tft_width - 40;
        position_text[1][1] = y0;

        //line 2
        x0 = 5;
        y0 = y0 + 15;

        position_text[2][0] = x0;
        position_text[2][1] = y0;

        drawChar(x0 + 54,y0,'A',ST7735_LBLUE, ST7735_BLACK,1); 

        //sprintf(v0,"GP");
        drawChar(tft_width - 40 ,y0,'P',ST7735_RED, ST7735_BLACK, 1); 
        drawChar(tft_width - 50 ,y0,'G',ST7735_RED, ST7735_BLACK, 1); 

        position_text[3][0] = tft_width - 25;
        position_text[3][1] = y0;

        //line 3
        x0 = 5;
        y0 = y0 + 15;
        position_text[4][0] = 5;
        position_text[4][1] = y0;
        drawChar(55,y0,'m',ST7735_RED, ST7735_BLACK, 1);
        drawChar(70,y0,'A',ST7735_RED, ST7735_BLACK, 1);
        drawChar(81,y0,'h',ST7735_RED, ST7735_BLACK, 1);

        if (flag_rotation)
        {
            position_text[5][0] = tft_width - 65;
            position_text[5][1] = y0;
            drawChar(tft_width - 15 ,y0,'0',ST7735_BLUE, ST7735_BLACK, 1);
            drawFastHLine(tft_width - 15 ,y0,10,ST7735_BLACK);
            drawFastHLine(tft_width - 15 ,y0,4,ST7735_BLUE);
            drawFastHLine(tft_width - 9 ,y0,4,ST7735_BLUE);
        }
        //line 4
        x0 = 5;
        y0 = y0 + 15;
        position_text[6][0] = x0;
        position_text[6][1] = y0;

    //    snprintf(v0, 6, "%d", result);
    //    drawText(x0,y0,v0, ST7735_YELLOW, ST7735_BLACK, 1);

        drawChar(55,y0,'m',ST7735_YELLOW, ST7735_BLACK, 1);
        drawChar(69,y0,'W',ST7735_YELLOW, ST7735_BLACK, 1);
        drawChar(84,y0,'h',ST7735_YELLOW, ST7735_BLACK, 1);

        if(flag_rotation)
        {
            position_text[7][0] = tft_width - 65;
            position_text[7][1] = y0;
            drawChar(tft_width - 16 ,y0,'W',ST7735_WHITE, ST7735_BLACK, 1);
        }
        else
        {
            y0 = y0 + 15;
            position_text[7][0] = 5;
            position_text[7][1] = y0;

            drawChar(63,y0,'W',ST7735_WHITE, ST7735_BLACK, 1);

            y0 = y0 + 15;
            position_text[5][0] = 5;
            position_text[5][1] = y0;

            drawChar(68,y0,'0',ST7735_BLUE, ST7735_BLACK, 1);
            drawFastHLine(68 ,y0,10,ST7735_BLACK);
            drawFastHLine(68 ,y0,4,ST7735_BLUE);
            drawFastHLine(74,y0,4,ST7735_BLUE);
        }
        if (current_display == 1 )
        {   
            GP = 2;
            mWh = AmWH;
            //GP
            text2_display(position_text[3][0],position_text[3][1],GP,ST7735_RED);
            //mWh
            text6_display(position_text[6][0],position_text[6][1],mWh,ST7735_YELLOW);
        }
        else
        {   
            GP = 1;
            mWh = CmWH;
            //GP
            text2_display(position_text[3][0],position_text[3][1],GP,ST7735_RED);
            //mWh
            text6_display(position_text[6][0],position_text[6][1],mWh,ST7735_YELLOW);
        }
        
    }
    
    // updation of values start here
    if (current_display == 1 )
    {   
        result[0] = ADC_GetConversion(channel_AN2);
        __delay_ms(1);
        result[1] = ADC_GetConversion(channel_AN1);
        __delay_ms(1);
    }
    else
    {   
        result[0] = ADC_GetConversion(channel_AN3);
        __delay_ms(1);
        result[1] = ADC_GetConversion(channel_AN0);
        __delay_ms(1);
    }

    //temp
    result[2] = ADC_GetConversion(channel_AN4);
    if (result[2] != previous_valus[2] || flag_update_display)
    {
        previous_valus[2] = result[2];
        temp = (result[2] * ADC_RES) * 50.0 * adc_err;
        text2_display(position_text[1][0],position_text[1][1],(uint8_t)temp,ST7735_YELLOW);	
    }

    if ((result[0] != previous_valus[0]) || (result[1] != previous_valus[1]) || flag_update_display)
    {
            //voltage
        if ((result[0] != previous_valus[0]) || flag_update_display)
        {
            previous_valus[0] = result[0];
            voltage = (result[0] * ADC_RES) * adc_err;   
            text6_display(position_text[0][0],position_text[0][1],voltage,ST7735_GREEN);
        //mAh
            
            mAh = mWh/voltage*10;
           text6_display(position_text[4][0],position_text[4][1],mAh,ST7735_RED);		
        }
        //Current
            
        if ((result[1] != previous_valus[1]) || flag_update_display)
        {
            previous_valus[1] = result[1];
            current = (result[1] * ADC_RES) * adc_err;
            text6_display(position_text[2][0],position_text[2][1],current,ST7735_LBLUE); 
        }

        //Ohms
        ohms = voltage/current;
        text6_display(position_text[5][0],position_text[5][1],ohms,ST7735_BLUE);

        //W
        watt = voltage * current;
        text6_display(position_text[7][0],position_text[7][1],watt,ST7735_WHITE);
    }
    flag_update_display = 0;    
}
void display_page2(void){

    uint8_t x0 = 5;
    uint8_t y0 = 5;
    char v0[6];
    float mWh,mAh,A;
    static uint8_t hour,min,sec;
    
    if(flag_update_display)
    { 
        clean_writable_area();
        //line 1    
        x0 = 5;
        y0 = 45;
        position_text[0][0] = x0;
        position_text[0][1] = y0;

        drawChar(60,y0,'m',ST7735_GREEN, ST7735_BLACK, 1);
        drawChar(77,y0,'A',ST7735_GREEN, ST7735_BLACK, 1);
        drawChar(94,y0,'h',ST7735_GREEN, ST7735_BLACK, 1);
 
        //line 2
        x0 = 5;
        y0 = y0 + 15;
        position_text[1][0] = x0;
        position_text[1][1] = y0;
        
        drawChar(60,y0,'m',ST7735_LBLUE, ST7735_BLACK, 1);
        drawChar(76,y0,'W',ST7735_LBLUE, ST7735_BLACK, 1);
        drawChar(94,y0,'h',ST7735_LBLUE, ST7735_BLACK, 1);

        //line 3
        x0 = 5;
        y0 = y0 + 15;
        position_text[2][0] = x0;
        position_text[2][1] = y0;
        
        drawChar(28,y0,':',ST7735_WHITE, ST7735_BLACK, 1);

        position_text[3][0] = 35;
        position_text[3][1] = y0;
        
        drawChar(59 ,y0,':',ST7735_WHITE, ST7735_BLACK, 1);

        position_text[4][0] = 66;
        position_text[4][1] = y0;
    
        
        //line 4
        x0 = 5;
        y0 = y0 + 15;

        position_text[5][0] = 20;
        position_text[5][1] = y0;
            
        drawChar(70,y0,'A',ST7735_WHITE, ST7735_BLACK, 1);
        
        drawChar(90,y0,'R',ST7735_RED, ST7735_BLACK, 1);
        drawChar(103,y0,'E',ST7735_RED, ST7735_BLACK, 1);
        drawChar(114,y0,'C',ST7735_RED, ST7735_BLACK, 1);
        if (not_retain_values)
        {
            hour = 0;
            min = 0;
            sec = 0;
        }
    }
    
        //mAh
        mAh = 10782;
        if (mAh != previous_valus_ft[0] || flag_update_display)
        {
            previous_valus_ft[0] = mAh;
            text6_display(position_text[0][0],position_text[0][1],mWh,ST7735_GREEN);
        }
        //mWh
        mWh = 10782;
        if (mWh != previous_valus_ft[1] || flag_update_display)
        {        
            previous_valus_ft[1] = mWh;
            text6_display(position_text[1][0],position_text[1][1],mWh,ST7735_LBLUE);
        }
        A = 1.245;        
        if (A != previous_valus_ft[2] || flag_update_display)
        {        
            previous_valus_ft[2] = A;
            text6_display(position_text[5][0],position_text[5][1],A,ST7735_WHITE);
        }
        
        if (one_sec || flag_update_display)
        {
            one_sec = 0;
            sec++;
            if (sec == 60)
                {
                    sec = 0;
                    min++;
                }
            if (min == 60)
                {
                    min = 0;
                    hour++;
                }
            if (hour == 24)
                {
                    hour = 0;
                }
            if (hour != previous_valus[0] || flag_update_display)
            {           
                previous_valus[0] = hour;
                text2_display(position_text[2][0],position_text[2][1],hour,ST7735_WHITE);
            }
            
            if (min != previous_valus[1] || flag_update_display)
            {           
                previous_valus[1] = min;
                text2_display(position_text[3][0],position_text[3][1],min,ST7735_WHITE);
            }
            
            if (sec != previous_valus[2] || flag_update_display)
            {           
                previous_valus[2] = sec;
                text2_display(position_text[4][0],position_text[4][1],sec,ST7735_WHITE);
            }
        }
    
    flag_update_display = 0;
}
void display_page3(void){
    uint8_t x0 = 5;
    uint8_t y0 = 5; 
    static uint8_t min,temp,bright;
    char v0[6];
    if(flag_update_display)
    {
        clean_writable_area();
        if(flag_rotation)
        {
            //draw box
            x0 = 5; 
            y0 = 30;
            drawRoundRect(x0,y0,tft_width - 10,tft_height - 56,3,ST7735_WHITE);
            drawFastVLine(x0 + 50,y0,tft_height - 56,ST7735_WHITE);
            drawFastHLine(x0,y0+(tft_height - 56)/3,tft_width - 10,ST7735_WHITE);
            drawFastHLine(x0,y0+2*(tft_height - 56)/3,tft_width - 10,ST7735_WHITE);

            //draw clcck
            x0 = 20;
            y0 = 32;
            drawRectWH(x0,y0,18,18,ST7735_RED);
            drawLine(x0,y0+9,x0+2,y0+9,ST7735_RED);
            drawLine(x0+17,y0+9,x0+15,y0+9,ST7735_RED);
            drawLine(x0+9,y0,x0+9,y0+2,ST7735_RED);
            drawLine(x0+9,y0+17,x0+9,y0+15,ST7735_RED);
            drawFastVLine(x0+9,y0+9-5,5,ST7735_RED);
            drawFastHLine(x0+9,y0+9,5,ST7735_RED);


            x0 = 58;
            y0 = 47;
            position_text[0][0] = x0;
            position_text[0][1] = y0;
            //minutes
            x0 = 81;
            char *txtthree = "Minutes";
            drawText(x0, y0, txtthree, ST7735_RED, ST7735_WHITE, 1);

            //draw bulb
            x0 = 30;
            y0 = 64;
            fillCircle(x0,y0,5,ST7735_GREEN);
            drawFastVLine(x0,y0-10,3,ST7735_GREEN);
            drawFastVLine(x0,y0+7,3,ST7735_GREEN);
            drawFastHLine(x0-10,y0,3,ST7735_GREEN);
            drawFastHLine(x0+7,y0,3,ST7735_GREEN);
            drawLine(x0,y0,x0+9,y0+9,ST7735_GREEN);
            drawLine(x0,y0,x0+9,y0-9,ST7735_GREEN);
            drawLine(x0,y0,x0-9,y0+9,ST7735_GREEN);
            drawLine(x0,y0,x0-9,y0-9,ST7735_GREEN);
            drawCircle(x0,y0,6,ST7735_BLACK);


            x0 = 58;
            y0 = 69;
            position_text[1][0] = x0;
            position_text[1][1] = y0;
            x0 = 81;
            char *txtfive = "Bright";
            drawText(x0, y0, txtfive, ST7735_GREEN, ST7735_WHITE, 1);

            //draw thermometer
            uint8_t x1 = 30;
            uint8_t y1 = 92;
            drawCircle(x1,y1,4,ST7735_YELLOW);
            fillCircle(x1,y1,2,ST7735_YELLOW);
            fillRect(x1,y1-11,1,8,ST7735_YELLOW);
            drawRoundRect(x1-2,y1-13,5,11,1,ST7735_YELLOW);
            drawFastVLine(x1+3,y1-11,1,ST7735_YELLOW);
            drawFastVLine(x1+3,y1-9,1,ST7735_YELLOW);
            drawFastVLine(x1+3,y1-7,1,ST7735_YELLOW);
            //thermometer ends
            x0 = 58;
            y0 = 93;
            position_text[2][0] = x0;
            position_text[2][1] = y0;
            x0 = 81;
            char *txtfour = "Temp";
            drawText(x0, y0, txtfour, ST7735_YELLOW, ST7735_WHITE, 1);
        }
        else
        {
            x0 = 5; 
            y0 = 30;
            drawRoundRect(x0,y0,tft_width - 10,tft_height - 56,3,ST7735_WHITE);
            drawFastVLine(x0 + 30,y0,tft_height - 56,ST7735_WHITE);
            drawFastHLine(x0,y0+(tft_height - 56)/3,tft_width - 10,ST7735_WHITE);
            drawFastHLine(x0,y0+2*(tft_height - 56)/3,tft_width - 10,ST7735_WHITE);

            //draw clcck
            x0 = 10;
            y0 = 38;
            drawRectWH(x0,y0,18,18,ST7735_RED);
            drawLine(x0,y0+9,x0+2,y0+9,ST7735_RED);
            drawLine(x0+17,y0+9,x0+15,y0+9,ST7735_RED);
            drawLine(x0+9,y0,x0+9,y0+2,ST7735_RED);
            drawLine(x0+9,y0+17,x0+9,y0+15,ST7735_RED);
            drawFastVLine(x0+9,y0+9-5,5,ST7735_RED);
            drawFastHLine(x0+9,y0+9,5,ST7735_RED);

            x0 = 36;
            y0 = 53;
            position_text[0][0] = x0;
            position_text[0][1] = y0;
            x0 = 58;
            char *txtthree = "Minute";
            drawText(x0, y0, txtthree, ST7735_RED, ST7735_WHITE, 1);
            //draw bulb
            x0 = 20;
            y0 = 80;
            fillCircle(x0,y0,5,ST7735_GREEN);
            drawFastVLine(x0,y0-10,3,ST7735_GREEN);
            drawFastVLine(x0,y0+7,3,ST7735_GREEN);
            drawFastHLine(x0-10,y0,3,ST7735_GREEN);
            drawFastHLine(x0+7,y0,3,ST7735_GREEN);
            drawLine(x0,y0,x0+9,y0+9,ST7735_GREEN);
            drawLine(x0,y0,x0+9,y0-9,ST7735_GREEN);
            drawLine(x0,y0,x0-9,y0+9,ST7735_GREEN);
            drawLine(x0,y0,x0-9,y0-9,ST7735_GREEN);
            drawCircle(x0,y0,6,ST7735_BLACK);

            x0 = 36;
            y0 = 85;
            position_text[1][0] = x0;
            position_text[1][1] = y0;
            x0 = 58;
            char *txtfive = "Bright";
            drawText(x0, y0, txtfive, ST7735_GREEN, ST7735_WHITE, 1);

            //draw thermometer
            uint8_t x1 = 20;
            uint8_t y1 = 122;
            drawCircle(x1,y1,4,ST7735_YELLOW);
            fillCircle(x1,y1,2,ST7735_YELLOW);
            fillRect(x1,y1-11,1,8,ST7735_YELLOW);
            drawRoundRect(x1-2,y1-13,5,11,1,ST7735_YELLOW);
            drawFastVLine(x1+3,y1-11,1,ST7735_YELLOW);
            drawFastVLine(x1+3,y1-9,1,ST7735_YELLOW);
            drawFastVLine(x1+3,y1-7,1,ST7735_YELLOW);
            //thermometer ends

            x0 = 36;
            y0 = 120;
            position_text[2][0] = x0;
            position_text[2][1] = y0;
            x0 = 58;
            char *txtfour = "Temp";
            drawText(x0, y0, txtfour, ST7735_YELLOW, ST7735_WHITE, 1); 
            
            //For demo only
            min = 0;
            bright = 0;
            temp = 0;
    
        }    
    }
    
    // For demo only
    if(one_sec){
        min++;
        bright++;
        temp++;
        one_sec = 0;
    }
    //minutes
    if (min != previous_valus[0] || flag_update_display)
    {    
        previous_valus[0] = min;
        text2_display(position_text[0][0],position_text[0][1],min,ST7735_RED);
    }
    //brightness    
    if (bright != previous_valus[1] || flag_update_display)
    {    
        previous_valus[1] = bright;
        text2_display(position_text[1][0],position_text[1][1],bright,ST7735_GREEN); 
    }
    //Temperature
    if (temp != previous_valus[2] || flag_update_display)
    {    
        previous_valus[2] = temp;
        text2_display(position_text[2][0],position_text[2][1],temp,ST7735_YELLOW);
    }    
    
    flag_update_display = 0;    
}
void display_page4(void){
    char v0[6];
    uint16_t result;
    float voltage; 
    static uint8_t x0 = 5;
    static uint8_t y0 = 5;
    static uint8_t graph_y_min;
    static uint8_t graph_y_max;
    float k = 5.5; //start value
    uint8_t value;
    uint8_t i;
    static uint8_t buffer_y[Sample];
    //drawFastVLine(x0,y0,tft_height - 3.75*char_length,ST7735_WHITE);
    if (flag_update_display)
    {
        x0 = 25; 
        y0 = 30;
        clean_writable_area();
        setFont(&Picopixel);
        snprintf(v0, 6, "%.2f", GRAPHMAX);
        drawText(x0-20,y0+3,v0, ST7735_WHITE, ST7735_BLACK, 1);
        drawChar(x0-5,y0+3,'V',ST7735_WHITE, ST7735_BLACK, 1);
        drawFastHLine(x0-1,y0+1,3,ST7735_WHITE);
        for ( i=0;i < 6;i++)
        {    
            drawFastHLine(x0-1,y0+3+11*i,1,ST7735_WHITE);
            drawFastHLine(x0-1,y0+5+11*i,1,ST7735_WHITE);
            drawFastHLine(x0-1,y0+7+11*i,1,ST7735_WHITE);
            drawFastHLine(x0-1,y0+9+11*i,1,ST7735_WHITE);
            snprintf(v0, 6, "%.2f", GRAPHMAX - 0.833*(i+1));
            drawText(x0-20,y0+3+11*(i+1),v0, ST7735_WHITE, ST7735_BLACK, 1);
            drawChar(x0-5,y0+3+11*(i+1),'V',ST7735_WHITE, ST7735_BLACK, 1);
            drawFastHLine(x0-1,y0+1+11*(i+1),3,ST7735_WHITE);
        }
        graph_y_min = y0 + 1;
        //drawFastHLine(x0-1,graph_y_min,100,ST7735_WHITE);
        graph_y_max = y0 + 67;
        //drawFastHLine(x0-1,graph_y_max,100,ST7735_WHITE);
        setFont(&FreeSansBold9pt7b);
        for (i = 0; i < Sample; i++)
            buffer_y[i] = graph_y_max;
        i = 0;
    }
    if(current_display == 4)
        result = ADC_GetConversion(channel_AN2);
    else
        result = ADC_GetConversion(channel_AN3);
    voltage = result * ADC_RES * adc_err ;
    value = map ((float)result,0.0,1023.0,(float)graph_y_max,(float)graph_y_min);
    for (i = 0; i < Sample - 1; i++)
        drawLine(x0+10*i,buffer_y[i],x0+10*(i+1),buffer_y[i+1],ST7735_BLACK);
    for (i = 0; i < Sample -1;i++)
        {
            buffer_y[i] = buffer_y[i+1];
        }
    buffer_y[Sample -1] = value; 
    for (i = 0; i < Sample -1 ; i++)
        drawLine(x0+10*i,buffer_y[i],x0+10*(i+1),buffer_y[i+1],ST7735_YELLOW);
    //x0 = x0+5;
    //y0 = value;
    flag_update_display = 0;
}

int map(float x, float in_min, float in_max, float out_min, float out_max) {
    
   float a =  x - in_min;
   float b = out_max - out_min;
   float c = in_max - in_min;
   float d = (a/c);
   float e = d * b + out_min;  
   return (int)e;
}

void clean_writable_area(void){
    fillRect(5,29,tft_width - 5,tft_height - 52,ST7735_BLACK);
}
void text6_display(uint8_t x,uint8_t y,float value,uint16_t color)
{
   char v0[6];
   fillRect(x,y-12,50,15,ST7735_BLACK);  
   snprintf(v0, 6, "%4f", value);
   drawText(x,y,v0, color, ST7735_BLACK, 1);
}
void text2_display(uint8_t x,uint8_t y,uint8_t value,uint16_t color)
{
   char v0[6];
   fillRect(x,y-13,20,15,ST7735_BLACK);      
   snprintf(v0, 6, "%2d", value);
   drawText(x,y,v0, color, ST7735_BLACK, 1);
}
