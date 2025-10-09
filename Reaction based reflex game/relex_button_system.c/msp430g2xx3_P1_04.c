/* --COPYRIGHT--,BSD_EX
 * Copyright (c) 2012, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *******************************************************************************

//******************************************************************************
*/
#include <msp430.h>
#include "lcd.h"
#include <stdio.h>
#include <string.h>

void setLed(void);
char message[20];
#define SETB(PORT,Pin)   (PORT |= (Pin))
#define CLRB(PORT,Pin)   (PORT &= ~(Pin))
#define SET_TIMER 1000  //1000 = 1 ms


#define IN_PORT P1OUT
#define R1  BIT0
#define G1  BIT1
#define R2  BIT2
#define G2  BIT3
#define LED_PORT P1OUT
#define GRN_LED BIT5
#define RED_LED BIT4

#define DAT_PORT    P2
#define D4          BIT0
#define D5          BIT1
#define D6          BIT2
#define D7          BIT3
#define RS_PORT     P2
#define RS          BIT4
#define EN_PORT     P2
#define EN          BIT5

volatile uint32_t time = 0;
uint32_t timeKeeper = 0;
volatile uint8_t mainLoop = 0;

volatile uint8_t start = 0;
volatile uint8_t firstTime = 1;
volatile uint8_t AnyButton = 0;
volatile uint8_t ledState = 0;


volatile uint8_t P1HasPressed = 0;
volatile uint8_t P2HasPressed = 0;
volatile uint8_t P1Win = 0;
volatile uint8_t P2Win = 0;
volatile uint8_t P1Pressed = 0;
volatile uint8_t P2Pressed = 0;
volatile uint32_t P1time = 0;
volatile uint32_t P2time = 0;
volatile uint32_t Dtime = 0;
enum State {
    StageOff = 1,
    StageSet,
    StagePlay,
    StageResult}currentState;

void ProgramStates(enum State cases);

void setLed(void){
    uint32_t random = 0;
    random = time;
    if(random & 0x0001)
    {
        P1OUT |= GRN_LED;    //set
        P1OUT &= ~RED_LED;   //clear
        ledState = 0x2;
    }
    else
    {
        P1OUT |= RED_LED;
        P1OUT &= ~GRN_LED;
        ledState = 0x1;
    }
}

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop watchdog timer
  DCOCTL = 0;
  BCSCTL1 = CALBC1_1MHZ;
  DCOCTL = CALDCO_1MHZ;
  CCTL1 = CCIE;                             // CCR1 interrupt enabled
  CCR1 = SET_TIMER;
  TACTL = TASSEL_2 + MC_2;                  // SMCLK, Contmode

  P1DIR |= GRN_LED | RED_LED;               // Configure LED pins as output,rest are input
  P1OUT |= R1 | G1 | R2 | G2;               // SET ALL INPUT HIGH
  P1REN |= R1 | G1 | R2 | G2;               // pullup on input
  P1IE |= R1 | G1 | R2 | G2;                // interrupt enabled
  P1IES |= R1 | G1 | R2 | G2;               //Hi/lo edge
  P1IFG &= ~(R1 | G1 | R2 | G2);                           // P1.4 IFG cleared

  // lcd_init(data_port, d4, d5, d6, d7, rs_port, rs, en_port, en)
  currentState = StageOff;
  lcd_init(DAT_PORT, D4, D5, D6, D7, RS_PORT, RS, EN_PORT, EN);

  //lcd_setCursor(0,0);
  //__bis_SR_register(LPM4_bits + GIE);       // Enter LPM4 w/interrupt
  __bis_SR_register(GIE);       // Enter LPM4 w/interrupt
  while(1){
      // runs after every 10 ms
      if(mainLoop == 10){
          ProgramStates(currentState);
          mainLoop = 0;
      }
  }
  //__bis_SR_register(LPM4_bits + GIE);       // Enter LPM4 w/interrupt
}

void ProgramStates(enum State cases){

    switch(cases){

        case StageOff:
            if(firstTime){
                lcd_setCursor(0,0);
                lcd_print("Press Any Button");
                lcd_setCursor(1,5);
                lcd_print("to Start");
                firstTime = 0;
            }
            if(AnyButton){
                currentState = StageSet;
            }
        break;
        case StageSet:
            lcd_clear();
            lcd_setCursor(0,5);
            lcd_print("*");
            setLed();
            currentState = StagePlay;
            firstTime = 1;
         break;
        case StagePlay:
            if(firstTime){
                P1HasPressed = 0;
                P2HasPressed = 0;
                P1Pressed = 0;
                P2Pressed = 0;
                P1time = 0;
                P2time = 0;
                firstTime = 0;
                timeKeeper = 0;
            }
            if(timeKeeper == 100){  // 100 is equivalent to 1 sec 500 should be equal to 500

                P1OUT &= ~RED_LED;   //clear
                P1OUT &= ~GRN_LED;   //clear
                currentState = StageResult;
                firstTime = 1;
            }
            timeKeeper++;
        break;
        case StageResult:
            if(firstTime)
            {
                firstTime = 0;
                if((P1HasPressed == 0) && (P2HasPressed == 0))
                {
                    lcd_clear();
                    lcd_setCursor(0,0);
                    lcd_print("No one pressed");
                }
                else if ((P1HasPressed == 1) && (P2HasPressed == 0))
                {
                    if(P1Pressed == ledState)
                    {
                        P1Win++;
                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("P1 Win");
                        lcd_setCursor(1,0);
                        lcd_print("No pressed P2");
                    }
                    else{

                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("No pressed P2");
                        lcd_setCursor(1,0);
                        lcd_print("Wrong pressed P1");
                    }
                }
                else if ((P1HasPressed == 0) && (P2HasPressed == 1))
                {
                    if(P2Pressed == ledState)
                    {
                        P2Win++;
                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("P2 Win");
                        lcd_setCursor(1,0);
                        lcd_print("No pressed P1");
                    }
                    else{

                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("No pressed P1");
                        lcd_setCursor(1,0);
                        lcd_print("Wrong pressed P2");
                    }
                }
                else if ((P1HasPressed == 1) && (P2HasPressed == 1))
                {
                    if((P1Pressed == ledState) && (P2Pressed != ledState) )
                    {
                        P1Win++;
                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("P1 Win");
                        sprintf(message,"%d",(P1time - P2time));
                        lcd_setCursor(1,0);
                        lcd_print(message);
                    }
                    else if((P1Pressed != ledState) && (P2Pressed == ledState) )
                    {
                        P2Win++;
                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("P2 Win");
                        sprintf(message,"%d",(P1time - P2time));
                        lcd_setCursor(1,0);
                        lcd_print(message);
                    }
                    else if((P1Pressed != ledState) && (P2Pressed != ledState) )
                    {
                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("Both Wrong");
                        sprintf(message,"%d",(P1time - P2time));
                        lcd_setCursor(1,0);
                        lcd_print(message);
                    }
                    else
                    {
                        P1Win++;
                        P2Win++;
                        lcd_clear();
                        lcd_setCursor(0,0);
                        lcd_print("Both Win");
                        sprintf(message,"%d",(P1time - P2time));
                        lcd_setCursor(1,0);
                        lcd_print(message);
                    }

                }
            }
            delay(50000);
            lcd_clear();
            lcd_setCursor(0,0);
            sprintf(message,"Score P1:%d",P1Win);
            lcd_print(message);
            lcd_setCursor(1,0);
            sprintf(message,"Score P2:%d",P2Win);
            lcd_print(message);
            //5 sec delay
            delay(50000);
            if((P1Win == 3) && (P2Win < 3))
            {
                lcd_clear();
                lcd_setCursor(0,0);
                lcd_print("P1 Win Match");
                delay(50000);
                P1Win = 0;
                P2Win = 0;
                AnyButton = 0;
            }
            if((P2Win == 3) && (P1Win < 3))
            {
                lcd_clear();
                lcd_setCursor(0,0);
                lcd_print("P2 Win Match");
                delay(50000);
                P1Win = 0;
                P2Win = 0;
                AnyButton = 0;
            }
            if((P2Win == 3) && (P1Win == 3))
            {
                lcd_clear();
                lcd_setCursor(0,0);
                lcd_print("Match Tie");
                delay(50000);
                P1Win = 0;
                P2Win = 0;
                AnyButton = 0;
             }
             currentState = StageOff;
             firstTime = 1;
        break;
        default:
         break;
    }
}

// Port 1 interrupt service routine
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(PORT1_VECTOR))) Port_1 (void)
#else
#error Compiler not supported!
#endif
{
  AnyButton = 1;
  if(P1IFG & R1){
     if(P1HasPressed == 0){
        P1Pressed = 1;
        P1time = time;
        P1HasPressed = 1;
     }
     P1IFG &= ~R1;
  }
  if(P1IFG & G1){
     if(P1HasPressed == 0){
         P1Pressed = 2;
         P1time = time;
         P1HasPressed = 1;
     }
     P1IFG &= ~G1;
  }
  if(P1IFG & R2){
      if(P2HasPressed == 0){
          P2Pressed = 1;
          P2time = time;
          P2HasPressed = 1;
      }
     P1IFG &= ~R2;
  }
  if(P1IFG & G2){
      if(P2HasPressed == 0){
           P2Pressed = 2;
           P2time = time;
           P2HasPressed = 1;
      }
      P1IFG &= ~G2;
  }

}


// Timer_A3 Interrupt Vector (TA0IV) handler
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A1_VECTOR
__interrupt void Timer_A(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(TIMER0_A1_VECTOR))) Timer_A (void)
#else
#error Compiler not supported!
#endif
{
  switch( TA0IV )
  {
  case  2:                                  // CCR1
    {
    CCR1 += SET_TIMER;                          // Add Offset to CCR1
    time++;
    mainLoop++;
    }
           break;
  case  4: break;                           // CCR2 not used
  case 10: break;                           // overflow not used
 }
}

