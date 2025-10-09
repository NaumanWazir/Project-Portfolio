
#define _XTAL_FREQ 8000000
#include <string.h>
#include <xc.h>
#include "Configuration_Header_File.h"
#include "lcd.h"
#include <stdio.h>


#define ZP 6    // 0
#define FN 4    // -90
#define FP 8    // 90
#define TURNON 0
#define TURNOF 1
#define DUR1SEC 100
#define DUR1MIN 6000

enum State {
    StartA = 1,
    StateA,
    StartB,
    StateB,
    StateRun,
    StateAExpires,
    StateBExpires,
    StateExpires} currentState;  
enum State lastState;


void programStates(enum State);
uint8_t decode_key(uint8_t key);
void set_led (uint8_t num);

/*********************Definition of Ports********************************/
//LCD pins are defined in lcd.h
#define LCD 1
#ifdef LCD
#define RS PORTDbits.RD6
#define RW PORTDbits.RD5
#define EN PORTDbits.RD4
#define D0 PORTDbits.RD0
#define D1 PORTDbits.RD1
#define D2 PORTDbits.RD2
#define D3 PORTDbits.RD3
#endif


// keypad pins input
#define DA PORTBbits.RB5
#define A PORTBbits.RB0
#define B PORTBbits.RB1
#define C PORTBbits.RB2
#define D PORTBbits.RB3


//bar output
#define B1 LATAbits.LATA0
#define B2 LATAbits.LATA1
#define B3 LATAbits.LATA4
#define B4 LATAbits.LATA5

//ir input
#define IR PORTCbits.RC2
//servo out
#define M1 LATAbits.LATA3
#define M2 LATAbits.LATA6
//buzzer
#define Buzz LATAbits.LATA2

volatile uint8_t run_mainloop = 0;
volatile uint8_t scan = 1;
volatile uint8_t run_servo = 0;
uint8_t press_key = 'n';
uint8_t last_press_key = 'n';
uint8_t firstTime = 1; 
uint8_t input = 0; 
uint8_t DosageA = 0;
uint8_t DosageB = 0;
uint8_t TimeA = 0;
uint8_t TimeB = 0;
uint8_t enableBuzzer = 0;
uint8_t BuzzerIsEnable = 0;
uint8_t Morning = 0;
uint8_t Evening = 0;
uint64_t MorningCounter = 0;
uint64_t EveningCounter = 0;
uint64_t BuzzerCounter = 0;
uint64_t StateRunCounter = 0;
uint8_t servoCounter = 0;
uint8_t on_time1 = FN;
uint8_t on_time2 = FN;
uint8_t on_time1_update = FN;
uint8_t on_time2_update = FN;
uint8_t enableServo = 0;
uint8_t ir_state = 0;
uint8_t count1 = 0;
uint8_t count2 = 0;
uint8_t lastposition = FN;
char msg[20];
void Timer1_start()
{
    T1CONbits.RD16 = 1;
    T1CONbits.T1RUN = 0;
    T1CONbits.TMR1CS = 0;
    T1CONbits.T1CKPS = 0b00;
    T1CONbits.T1OSCEN = 0;
    TMR1 = 65046;
    INTCONbits.PEIE = 1;
   	PIE1bits.TMR1IE = 1;
    PIR1bits.TMR1IF = 0;
    T1CONbits.TMR1ON = 1;	
}
void Timer0_start()
{
    T0CONbits.T08BIT = 1;
    T0CONbits.T0CS = 0;
    T0CONbits.PSA = 0;
    T0CONbits.T0PS = 0b110;
    TMR0L = 100;
    INTCONbits.TMR0IE = 1;		/* Enable Timer1 Overflow Interrupt */
    INTCONbits.TMR0IF = 0;
   	T0CONbits.TMR0ON = 1;	
}
void External_Interrupt_start(){
    //INTCON2bits.INTEDG0 = 1;
    INTCON2bits.NOT_RBPU = 0;
    INTCONbits.RBIE = 1;
    INTCONbits.RBIF = 0;
}
void __interrupt() isr(void)
{  
    if(INTCONbits.TMR0IF)
    {
        run_mainloop = 1;
        TMR0L = 100;
        INTCONbits.TMR0IF = 0;;  /* Make Timer1 Overflow Flag to '0' */
    }
    if(INTCONbits.RBIF)
    {
        if(DA == 1)
            scan = 1;
        INTCONbits.RBIF = 0;
    }
    if(PIR1bits.TMR1IF)
    {
        count1++;
        
        if (count1 == 1)
        {
            M1 = 1;
            M2 = 1;
            on_time1 = on_time1_update;
            on_time2 = on_time2_update;
        }
        if (count1 == on_time1)
        {
            M1 = 0;
        }
        if (count1 == on_time2)
        {
            M2 = 0;
        }
        if(count1 == 80)
        {
            count1 = 0;
        }
        TMR1 = 65046;
        run_servo = 1;
        PIR1bits.TMR1IF = 0;
    }
}
void set_led (uint8_t num){
    switch(num)
    {
        case 0:
            B1 = TURNOF;
            B2 = TURNOF;
            B3 = TURNOF; 
            break;   
        case 1:
            B1 = TURNON;
            B2 = TURNOF;
            B3 = TURNOF; 
            break;
        case 2:
            B1 = TURNON;
            B2 = TURNON;
            B3 = TURNOF; 
            break; 
        case 3:
            B1 = TURNON;
            B2 = TURNON;
            B3 = TURNON; 
            break;
        default:
            B1 = TURNOF;
            B2 = TURNOF;
            B3 = TURNOF;
            break;    
    }
}
uint8_t get_ir(void){
    if(IR == 1)
        return 1;
    else
        return 0;
}
uint8_t decode_key(uint8_t key){
    uint8_t ret = 'n';
    switch(key){
        case 0: ret = 1; break;
        case 1: ret = 2; break;
        case 2: ret = 3; break;
        case 3: ret = 'A'; break;
        case 4: ret = 4; break;
        case 5: ret = 5; break;
        case 6: ret = 6; break;
        case 7: ret = 'B'; break;
        case 8: ret = 7; break;
        case 9: ret = 8; break;
        case 10: ret = 9; break;
        case 11: ret = 'C'; break;
        case 12: ret = '*'; break;
        case 13: ret = 0; break;
        case 14: ret = '#'; break;
        case 15: ret = 'D'; break;
    }
    return ret;
}

int main(void)
{ 
    uint8_t scan_key = 0;
    currentState = StartA;
    OSCCON = 0x72;                        /*Use internal oscillator and set frequency to 8 MHz*/ 
    //set port direction for LCD at  
    TRISD = 0;
    //set pin direction on port b
    TRISB = 0xFF;
    //ir input
    TRISCbits.TRISC2 = 1;
    //servo out    
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA6 = 0;
    //bar output
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;
    //buzzer out
    TRISAbits.TRISA2 = 0;
    
    RW = 0;
    Lcd_Init();
    Lcd_Set_Cursor(1,4);
    Lcd_Write_String("Medicine");
    Lcd_Set_Cursor(2,4);
    Lcd_Write_String("Alert");
    __delay_ms(1000);
    B1 = TURNOF;                           //2s delay
    B2 = TURNOF;                          //2s delay
    B3 = TURNOF;                          //2s delay
    B4 = TURNOF;
    Timer0_start();
    Timer1_start();
    ei(); // enable global interrupts
    
    
    while(1)
    {
        if(run_mainloop)
        {
            programStates(currentState);
            ir_state = get_ir();
            run_mainloop = 0;
        }
        if(scan)
        {
            scan_key = 0;
            if(A == 1)
                scan_key |= 0x01;
            if(B == 1)
                scan_key |= 0x02;
            if(C == 1)
                scan_key |= 0x04;
            if(D == 1)
                scan_key |= 0x08;
            scan = 0;
            press_key = decode_key(scan_key);
        }
        if(run_servo)
        {
            run_servo = 0;
        }
        if(enableBuzzer)
        {
            BuzzerCounter++;
            if (BuzzerCounter == 1)
            {
                Buzz = 0;
            }
            if (BuzzerCounter == 0.5*DUR1SEC)
                Buzz = 1;
            if (BuzzerCounter == 2*0.5*DUR1SEC)
            {    
                Buzz = 0;
                BuzzerCounter = 0;
                enableBuzzer = 0;
            }
        }
        
    }		
 return 0;
}
void programStates(enum State cases){
    switch(cases)
    {
        case StartA:
            if(firstTime)
            {
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Input dosage");
                Lcd_Set_Cursor(2,1);
                Lcd_Write_String("and time (A)");
                firstTime = 0;
                on_time1_update = FN;
                        
            }
            if(last_press_key != press_key)
            {
                if(press_key == 'A')
                {
                    currentState = StateA;
                    firstTime = 1;
                }
                last_press_key = press_key;
            }
            break;
        case StateA:
                if(firstTime)
                {
                    Lcd_Clear();
                    Lcd_Set_Cursor(1,1);
                    Lcd_Write_String("Input Dosage:");
                    Lcd_Set_Cursor(2,1);
                    Lcd_Write_String("Input Time:");
                    Lcd_Set_Cursor(1,14);
                    sprintf(msg,"%d",DosageA);
                    Lcd_Write_String(msg);
                    Lcd_Set_Cursor(2,12);
                    sprintf(msg,"%d",TimeA);
                    Lcd_Write_String(msg);
                    Lcd_Set_Cursor(1,14);
                    Lcd_Blink_Cursor_On();
                    firstTime = 0;
                    input = 1;
                }
                if(last_press_key != press_key)
                {
                    if(input == 1)
                    {
                        if((press_key >= 0) && (press_key <= 3))
                        {
                            DosageA = press_key;
                            Lcd_Set_Cursor(1,14);
                            sprintf(msg,"%d",DosageA);
                            Lcd_Write_String(msg);
                            Lcd_Set_Cursor(2,12);
                            set_led(DosageA);
                            press_key = 'n';
                            input = 2;
                        }
                    }
                    else if(input == 2)
                    {
                        if((press_key >= 0) && (press_key <= 2))
                        {
                            TimeA = press_key;
                            Lcd_Set_Cursor(2,12);
                            sprintf(msg,"%d",TimeA);
                            Lcd_Write_String(msg);
                            press_key = 'n';
                            input = 3;
                        }
                    }
                    else if(input == 3)
                    {
                        if((press_key >= 0) && (press_key <= 9))
                        {
                            TimeA = TimeA*10 + press_key;
                            Lcd_Set_Cursor(2,12);
                            sprintf(msg,"%d",TimeA);
                            Lcd_Write_String(msg);
                            Lcd_Blink_Cursor_Of();
                            input = 0;
                        }
                    }
                    else if(input == 0)
                    {
                        if(press_key == 'B')
                        {
                            press_key = 'n';
                            Morning = 1;
                            MorningCounter = 0;
                            currentState = StartB;
                            firstTime = 1;
                        }
                    }
                    last_press_key = press_key;
                }
            break;
            
        case StartB:
            if(firstTime)
            {
                set_led(0);
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Input dosage");
                Lcd_Set_Cursor(2,1);
                Lcd_Write_String("and time (B)");
                firstTime = 0;
            }
            if(last_press_key != press_key)
            {
                if(press_key == 'B')
                {
                    currentState = StateB;
                    press_key = 'n';
                    firstTime = 1;
                }
                last_press_key = press_key;
            }
            break;
        case StateB:
                if(firstTime)
                {
                    Lcd_Clear();
                    Lcd_Set_Cursor(1,1);
                    Lcd_Write_String("Input Dosage:");
                    Lcd_Set_Cursor(2,1);
                    Lcd_Write_String("Input Time:");
                    Lcd_Set_Cursor(1,14);
                    sprintf(msg,"%d",DosageB);
                    Lcd_Write_String(msg);
                    Lcd_Set_Cursor(2,12);
                    sprintf(msg,"%d",TimeB);
                    Lcd_Write_String(msg);
                    Lcd_Set_Cursor(1,14);
                    Lcd_Blink_Cursor_On();
                    firstTime = 0;
                    input = 1;
                }
                if(last_press_key != press_key)
                {
                    if(input == 1)
                    {
                        if((press_key >= 0) && (press_key <= 3))
                        {
                            DosageB = press_key;
                            Lcd_Set_Cursor(1,14);
                            sprintf(msg,"%d",DosageB);
                            Lcd_Write_String(msg);
                            Lcd_Set_Cursor(2,12);
                            set_led(DosageB);
                            press_key = 'n';
                            input = 2;
                        }
                    }
                    else if(input == 2)
                    {
                        if((press_key >= 0) && (press_key <= 2))
                        {
                            TimeB = press_key;
                            Lcd_Set_Cursor(2,12);
                            sprintf(msg,"%d",TimeB);
                            Lcd_Write_String(msg);
                            press_key = 'n';
                            input = 3;
                        }
                    }
                    else if(input == 3)
                    {
                        if((press_key >= 0) && (press_key <= 9))
                        {
                            TimeB = TimeB*10 + press_key;
                            Lcd_Set_Cursor(2,12);
                            sprintf(msg,"%d",TimeB);
                            Lcd_Write_String(msg);
                            Lcd_Blink_Cursor_Of();
                            __delay_ms(1000);
                            input = 0;
                        }
                    }
                    else if(input == 0)
                    {
                        if(press_key == 'C')
                        {
                            Evening = 1;
                            EveningCounter = 0;
                            currentState = StateRun;
                            firstTime = 1;
                            press_key = 'n';
                        }
                    }
                    last_press_key = press_key;
                }
            break;
        case StateRun:
            if(firstTime)
            {
                set_led(0);
             
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Reminder Time in");
                Lcd_Set_Cursor(2,1);
                sprintf(msg,"M:%d    E:%d",(uint8_t)(MorningCounter/100),(uint8_t)(EveningCounter/100));
                Lcd_Write_String(msg);
                StateRunCounter = 0;
                firstTime = 0;
                
            }
            if(StateRunCounter == DUR1SEC)
            {
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Reminder Time in");
                Lcd_Set_Cursor(2,1);
                sprintf(msg,"M:%d    E:%d",(uint8_t)(MorningCounter/100),(uint8_t)(EveningCounter/100));
                Lcd_Write_String(msg);
                StateRunCounter = 0;
            }
            if(Morning)
            {
                MorningCounter++;
                if(MorningCounter >= TimeA * DUR1SEC)
                {
                    firstTime = 1;
                    currentState = StateAExpires;
                    MorningCounter = 0;
                }        
            
            }
            if(Evening)
            {
                EveningCounter++;
                if(EveningCounter >= TimeB * DUR1SEC)
                {
                    firstTime = 1;
                    currentState = StateBExpires;
                    EveningCounter = 0;
                }  
            }
            if((Morning == 0) && (Evening == 0))
            {
                firstTime = 1;
                currentState = StateExpires;
            }
            StateRunCounter++;
            break;
        case StateAExpires:
            if(firstTime)
            {
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Morning Medicine");
                Lcd_Set_Cursor(2,4);
                Lcd_Write_String("Time");
                firstTime = 0;
                set_led(DosageA);
                BuzzerIsEnable = 1;
                servoCounter = 0;
            }
            if(Evening)
                EveningCounter++;
            if(BuzzerIsEnable)
                enableBuzzer = 1;
            /*if(ir_state == 1)
            {
                BuzzerIsEnable = 0;
                enableBuzzer = 0;
                Buzz = 0;
            }*/
            if(servoCounter == DUR1SEC)
            {
                if(enableServo)
                {
                    //on_time1_update = ZP;
                    currentState = StateRun;
                    firstTime = 1;
                    enableServo = 0;
                }
            }
            if(last_press_key != press_key)
            {
                if(press_key == 'A')
                {
                    enableBuzzer = 0;
                    Buzz = 0;
                    lastposition++;
                    on_time1_update = lastposition;
                    
                    enableServo = 1;
                    Morning = 0;
                    servoCounter = 0;
                }
                if(press_key == 'C')
                {
                    BuzzerIsEnable = 0;
                    enableBuzzer = 0;
                    Buzz = 0;
                    press_key = 'n';
                }
                last_press_key = press_key;    
            }
            servoCounter++;
            break;
        case StateBExpires:
            if(firstTime)
            {
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Evening Medicine");
                Lcd_Set_Cursor(2,4);
                Lcd_Write_String("Time");
                firstTime = 0;
                set_led(DosageB);
                BuzzerIsEnable = 1;
                servoCounter = 0;
            }
            if(Morning)
                MorningCounter++;
            if(BuzzerIsEnable)
                enableBuzzer = 1;
            /*if(ir_state == 1)
            {
                BuzzerIsEnable = 0;
                enableBuzzer = 0;
                Buzz = 0;
            }*/
            if(servoCounter == DUR1SEC)
            {
                if(enableServo)
                {
                    //on_time2_update = ZP;
                    currentState = StateRun;
                    firstTime = 1;
                    enableServo = 0;
                }
            }
            if(last_press_key != press_key)
            {
                if(press_key == 'B')
                {
                    enableBuzzer = 0;
                    Buzz = 0;
                    
                    lastposition++;
                    on_time1_update = lastposition;
                    //on_time2_update = FP;
                    enableServo = 1;
                    Evening = 0;
                    servoCounter = 0;
                }
                if(press_key == 'C')
                {
                    BuzzerIsEnable = 0;
                    enableBuzzer = 0;
                    Buzz = 0;
                    press_key = 'n';
                }
                last_press_key = press_key;    
            }
            servoCounter++;
            break;
        case StateExpires:
            if(firstTime)
            {
                Lcd_Clear();
                Lcd_Set_Cursor(1,1);
                Lcd_Write_String("Please Refill");
                Lcd_Set_Cursor(2,4);
                Lcd_Write_String("Medication");
                firstTime = 0;
            }
            enableBuzzer = 1;
            if(last_press_key != press_key)
            {
                if(press_key == 'C')
                {
                    currentState = StartA;
                    enableBuzzer = 0;
                    Buzz = 0;
                    firstTime = 1;
                }
                last_press_key = press_key;    
            }
            break;
        default:
            break;
    
    }


}

//****************************Functions********************************









