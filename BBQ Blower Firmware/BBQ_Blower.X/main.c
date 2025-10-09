#include "mcc_generated_files/mcc.h"
// PWM3 Blue
// PWM2 Green
// PWM4 Red
// PWM1 Motor 
#define LED_GRN LATAbits.LATA2
#define LED_RED LATCbits.LATC0
#define LED_BLU LATAbits.LATA1
#define BEEPER LATAbits.LATA4
#define MOTOR LATCbits.LATC3
#define BUTTON PORTAbits.RA3
#define CHARGE_POWER PORTAbits.RA5
#define POWER_TAKEOVER LATCbits.LATC5
#define DURPUSHLONG 100    //100 = 1000ms
#define DURPUSHSHORT 50     //50 = 500ms
#define DURBLINKOFF  20
#define DURSLOW 6000        //6000 = 60 secs for simulation keeping it 500 for 5s 
#define DUREND 12000        //12000 = 120 sec for simulation keeping it to 10s
#define DUROFF 20
#define DURBEEPSHORT 5    //5 = 50ms     
#define DURBLINKON 100       //As per doc it should be 50ms but I think 50 ms is not enough for naked eye keeping it at 1 sec for 50ms change 100 to 5 
#define DURBEEPLONG 10     //10 = 100ms   
#define DutyMotor 604
#define YELWARN 583        //((1024*2048)/3600) = 582.5
#define REDWARN 635        //((1024*2048)/3550) = 590.7 moving this to 3.3
#define NOGO    676        //((1024*2048)/3500) = 599.18 moving this to 3.1   
#define NORMAL_GREEN 1
#define YELLOW_ALERT 2
#define RED_ALERT 3
#define KILL_ALERT 4
#define DUR1SEC 100
#define DUR1MIN 6000
#define LED100 32000
enum ButtonState {
    TOOSHORT = 1,
    SHORT,
    LONG
}currentButtState;

enum State {
    StageOff = 1,
    StageWakeUp,
    StageOn,
    StageASlow,
    StageBNormal,
    StageB1,
    StageB2,
    StageCEnd,
    StageDOff,
    StageShutdown,
    StageLowBatt} currentState;  
enum State lastState;   
void ADCISR(void);    
void timer0ISR(void);
void programStates(enum State);
void setStartMotor(uint16_t);
void stopMotor(void);
void setStartGreen(uint16_t duty);
void stopGreen(void);
void setStartRed(uint16_t duty);
void stopRed(void);
void setStartBlue(uint16_t duty);
void stopBlue(void);
void Yellow(void);
void stopYellow(void);
void checkBattery(void);
void stopAll(void);
//uint8_t state = 0;
volatile uint64_t tick = 0;
bool button_state = false;
uint8_t buttonStateUpdated = 0;
uint8_t firstTime = 1;
uint8_t firstTimeB = 0;
uint8_t firstTimeC = 0;
uint8_t run_buttonLoop = 0;
uint8_t run_mainloop = 0;
uint8_t buttonPressedInProg = 0;
uint64_t pressedTime = 0;
uint64_t StageWakeUpTimer = 0;
uint64_t stageA_counter = 0;
uint64_t stageB_counter = 0;
uint64_t stageB1_counter = 0;
uint64_t stageC_counter = 0;
uint64_t stageD_counter = 0;
uint64_t shutdown_counter = 0;
uint64_t battlow_counter = 0;
uint16_t adc_value;
uint16_t battery_voltage = 0;
uint16_t battery_voltage_last = 0;
uint8_t battery_status = NORMAL_GREEN;
uint16_t battery_status_counter = 0;
uint8_t batteryStatusUpdated = 0;
uint8_t singleBeep = 0;
uint8_t doubleBeep = 0;
uint16_t singleBeepCounter = 0;
uint16_t doubleBeepCounter = 0;
uint8_t blinkRedThree = 0;
uint16_t blinkRedThreeCounter = 0;
uint16_t ledCounter = 0;
uint8_t enableGreen = 0;
uint8_t enableRed = 0;
uint8_t enableOrange = 0;
uint8_t enableYellow = 0;

//check battery routine

void checkBattery(void)
{
    uint16_t battery_voltage;
    battery_voltage = adc_value;
    // Check battery status       
          
    //printf("%u \n\r",battery_voltage);
    if (battery_voltage >= NOGO)
    {
        battery_status = (uint16_t)KILL_ALERT;
        //printf("NOGO Batt\n\r");
    }
    else if((battery_voltage < NOGO)&&(battery_voltage >= REDWARN))
    {    
        battery_status = (uint8_t)RED_ALERT;
        //printf("RED Batt\n\r");
    }
    else if((battery_voltage < REDWARN)&&(battery_voltage >= YELWARN))
    {    
        battery_status = (uint8_t)YELLOW_ALERT;
        //printf("YELLOW Batt\n\r");
    }
    else
    {
        battery_status = (uint8_t)NORMAL_GREEN;
        //printf("GREEN Batt\n\r");
    }
    batteryStatusUpdated = 1;        
}
//ADC ISR routine
void ADCISR(void)
{
    adc_value = ADC1_GetConversionResult();
}
void stopMotor(void)
{
    PWM1_DutyCycleSet(0x00);
    PWM1_LoadBufferSet();
    PWM1_Start();
    PWM1_Stop();
    TRISC |= 0x08;
    MOTOR = 0;
}
void setStartMotor(uint16_t duty)
{
    TRISC &= ~0x08;
    PWM1_DutyCycleSet(duty);
    PWM1_LoadBufferSet();
    PWM1_Start();
}
void stopGreen(void)
{
    PWM2_DutyCycleSet(0x00);
    PWM2_LoadBufferSet();
    PWM2_Start();
    PWM2_Stop();
    TRISA |= 0x04;
    LED_GRN = 0;
}
void setStartGreen(uint16_t duty)
{
    TRISA &= ~0x04;
    PWM2_DutyCycleSet(duty);
    PWM2_LoadBufferSet();
    PWM2_Start();
}
void stopBlue(void)
{
    PWM3_DutyCycleSet(0x00);
    PWM3_LoadBufferSet();
    PWM3_Start();
    PWM3_Stop();    
    TRISA |= 0x02;
    LED_BLU = 0;
}
void setStartBlue(uint16_t duty)
{
    TRISA &= ~0x02;
    PWM3_DutyCycleSet(duty);
    PWM3_LoadBufferSet();
    PWM3_Start();
}

void stopRed(void)
{
    PWM4_DutyCycleSet(0x00);
    PWM4_LoadBufferSet();
    PWM4_Start();
    PWM4_Stop();
    TRISC |= 0x01;
    LED_RED = 0;
}
void setStartRed(uint16_t duty)
{
    TRISC &= ~0x01;
    PWM4_DutyCycleSet(duty);
    PWM4_LoadBufferSet();
    PWM4_Start();
}
void setStartYellow(void){
    setStartRed(LED100);
    setStartGreen(LED100);
}
void stopYellow(void){
    stopRed();
    stopGreen();
}

void stopAll(void){
    stopRed();
    stopBlue();
    stopGreen();
}
void iocISR(void)
{   
    button_state = BUTTON;
    run_buttonLoop = 1;    
}

// 10 ms interrupt timer
void timer0ISR(void)
{
    tick++;
    run_mainloop = 1;    
}
void main(void){
    // initialize the device
    SYSTEM_Initialize();
    POWER_TAKEOVER = 1;
    stopMotor();   
    LED_RED = 0;
    LED_GRN = 0;
    LED_BLU = 0;
    BEEPER = 0;
    MOTOR = 0;
    //battery_voltage = ADC1_GetConversion(channel_FVR);
    ////printf("%u \n\r",battery_voltage);
    while(!FVR_IsOutputReady());
    ADC1_SetInterruptHandler(ADCISR);
    ADC1_SelectChannel(channel_FVR);
    //ADC1_SelectChannel(channel_AN0);
    TMR0_SetInterruptHandler(timer0ISR);
    IOCAF3_SetInterruptHandler(iocISR);
    ADC1_StartConversion();
    currentState = StageWakeUp;
    currentButtState = LONG;
    //printf("Start\n\r");
    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();
    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();
    if(CHARGE_POWER != HIGH)
    {
        //printf("BATT MISSING\n\r");
        button_state = HIGH;
        run_buttonLoop = 1;
    }
    else
    {
        //printf("BATT POWER\n\r");
    }
    
    while(1)
    {
        if(run_buttonLoop)
        {
            //printf("I\n\r");
            if(button_state)
            {
                pressedTime = 0;
                buttonPressedInProg = 1;
            }
            else
            {
                //printf("%llu \n\r",pressedTime);
                //Button press for less than DURPUSHSHORT
                if(pressedTime >= DURPUSHLONG)
                {
                    //printf("L \n\r");
                    currentButtState = LONG;
                }
                //Button press for short
                else if((pressedTime < DURPUSHLONG)&&(pressedTime >= DURPUSHSHORT ))
                {
                    //printf("S \n\r");
                    currentButtState = SHORT;
                }
                // Button press for long time
                else 
                {
                    //printf("P \n\r");
                    currentButtState = TOOSHORT;
                }
               buttonPressedInProg = 0;
               buttonStateUpdated = 1;
            }
            run_buttonLoop = 0;
        }
        if(run_mainloop)
        {   
            if(buttonPressedInProg)
            {    
                pressedTime++;
                ////printf("C\n\r");
                //First beep for short or long press of button
                if(pressedTime == DURPUSHSHORT)
                    singleBeep = 1;
                // Second beep for long press of buttonDUR1SEC
                //if(pressedTime == DURPUSHLONG)
                if(pressedTime == DURPUSHSHORT + DUR1SEC + DURBEEPLONG)
                    doubleBeep = 1;
                    //singleBeep = 1;
            }
            if(singleBeep)
            {
                singleBeepCounter++;
                if (singleBeepCounter == 1)
                {
                    BEEPER = 1;
                    ////printf("B \n\r");
                }
                if (singleBeepCounter == DURBEEPLONG)
                {
                    BEEPER = 0;
                    singleBeep = 0;
                    singleBeepCounter = 0;
                }
            }
            if(doubleBeep)
            {
                doubleBeepCounter++;
                if (doubleBeepCounter == 1)
                    BEEPER = 1;
                if (doubleBeepCounter == DURBEEPSHORT)
                    BEEPER = 0;
                if (doubleBeepCounter == 2*DURBEEPSHORT)
                    BEEPER = 1;
                if (doubleBeepCounter == 3*DURBEEPSHORT)
                {
                    BEEPER = 0;
                    doubleBeep = 0;
                    doubleBeepCounter = 0;
                }
            }
            if(blinkRedThree)
            {
                blinkRedThreeCounter++;
                if (blinkRedThreeCounter == 1)
                    setStartRed(LED100);
                if (blinkRedThreeCounter == DURBLINKON)
                    stopRed();
                if (blinkRedThreeCounter == 2*DURBLINKON)
                    setStartRed(LED100);
                if (blinkRedThreeCounter == 3*DURBLINKON)
                    stopRed();
                if (blinkRedThreeCounter == 4*DURBLINKON)
                    setStartRed(LED100);
                if (blinkRedThreeCounter == 5*DURBLINKON)
                {
                    stopRed();
                    blinkRedThree= 0;
                    blinkRedThreeCounter = 0;
                }
            }            
            
            programStates(currentState);
            //ADC1_SelectChannel(channel_FVR);
            //ADC1_SelectChannel(channel_AN0);
            //ADC1_StartConversion();
            run_mainloop = 0;                        
        }    
    }
}

void programStates(enum State cases){
    
   switch(cases){
        case StageWakeUp:
            if(firstTime)
            {
                //printf("Wake up \n\r");
                firstTime = 0;
                StageWakeUpTimer = 0;
                battery_status_counter = 0;
                checkBattery();
                if(battery_status == (uint16_t)NORMAL_GREEN)
                    setStartGreen(LED100);
                if(battery_status == (uint16_t)YELLOW_ALERT)
                    setStartYellow();
                if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                    setStartRed(LED100);
                if(battery_status != (uint16_t)NORMAL_GREEN)
                    singleBeep = 1;
            }
            if(buttonStateUpdated)
            {
                buttonStateUpdated = 0;
                if((battery_status != (uint16_t)RED_ALERT)&&(battery_status != (uint16_t)KILL_ALERT))
                {
                    if(currentButtState == SHORT)
                        currentState = StageASlow;
                    firstTime = 1;
                }
            }
            // Change 5 below to 2 for 2 sec 
            if(StageWakeUpTimer == 5*DUR1SEC)
            {
                if((battery_status == (uint16_t)NORMAL_GREEN)||(battery_status == (uint16_t)YELLOW_ALERT))
                {
                    //printf("Go to S \n\r");
                    currentState = StageShutdown;    
                    firstTime = 1;
                }else
                {
                    POWER_TAKEOVER = 0;
                    __delay_ms(100);
                }
            }
            //battery_status_counter++;
            StageWakeUpTimer++;
            break;
        case StageASlow:
            if(firstTime)
            {
                printf("Stage A\n\r");
                //setStartMotor((uint16_t)(DutyMotor*0.3));
                stageA_counter = 0;
                firstTime = 0;
                ledCounter = 1;
                stopAll();
            }
            if(stageA_counter == 2*DUR1SEC)
            {
                checkBattery();
                if(battery_status == (uint16_t)NORMAL_GREEN)
                    enableGreen = 1;
                if(battery_status == (uint16_t)YELLOW_ALERT)
                    enableYellow = 1;
                if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                    enableRed = 1;
            }     
            if(ledCounter == 1)
            {   if(enableGreen)
                    setStartGreen(LED100);
                if(enableYellow)
                    setStartYellow();
                if(enableRed)
                    setStartRed(LED100);
            }
            if(ledCounter == DURBLINKON)
            {    
                stopAll();
            }
            if(ledCounter == 2*DUR1SEC)
                ledCounter = 0;
            if(buttonStateUpdated)
            {
                buttonStateUpdated = 0;
                stopGreen();
                if(currentButtState == LONG)
                {
                    //printf("Go to S \n\r");
                    currentState = StageShutdown;
                    firstTime = 1;
                }
                if(currentButtState == SHORT)
                {    
                    //printf("Go to B \n\r");
                    currentState = StageBNormal;
                    firstTime = 1;
                }
                if(currentButtState == TOOSHORT)
                {    
                }
            }
            if(stageA_counter == DUR1MIN)
            {
                //printf("Go to B \n\r");
                currentState =  StageBNormal; 
                firstTime = 1;
            }
            ledCounter++;
            stageA_counter++;
            break;
        case StageBNormal:
            if(firstTime)
            {
                printf("Stage B \n\r");
                //setStartMotor(DutyMotor);
                battery_status_counter = 0;
                firstTimeB = 1;
                firstTime = 0;
            }
            if(firstTimeB)
            {
                if(battery_status_counter == 2*DUR1SEC)
                {
                    checkBattery();
                    battery_status_counter = 0;
                    firstTimeB = 0;
                    if(battery_status == (uint16_t)NORMAL_GREEN)
                        setStartGreen(LED100);
                    if(battery_status == (uint16_t)YELLOW_ALERT)
                        setStartYellow();
                    if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                    {
                        stopYellow();
                        setStartRed(LED100);
                        currentState = StageB1;
                        firstTime = 1;    
                    }
                }
            }
            else
            {
                if(battery_status_counter == DUR1MIN)
                {
                    checkBattery();
                    battery_status_counter = 0;
                    if(battery_status == (uint16_t)NORMAL_GREEN)
                        setStartGreen(LED100);
                    if(battery_status == (uint16_t)YELLOW_ALERT)
                        setStartYellow();
                    if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                    {
                        stopYellow();
                        setStartRed(LED100);
                        currentState = StageB1;
                        firstTime = 1;    
                    }
                }
            }
                
            if(buttonStateUpdated)
            {
                buttonStateUpdated = 0;
                if(currentButtState == LONG)
                {
                    //printf("Go to S \n\r");
                    currentState = StageShutdown;
                    firstTime = 1;
                }
                if(currentButtState == SHORT)
                {    
                    stopMotor();
                    //MOTOR = 0;
                    //printf("Go to C \n\r");
                    currentState = StageCEnd;
                    firstTime = 1;
                }
                if(currentButtState == TOOSHORT)
                {   
                }
            }
            battery_status_counter++;
            //stageB_counter++;
            break;
        case StageB1:
            if(firstTime)
            {
                //printf("Stage B1 \n\r");
                //setStartMotor(DutyMotor*0.5);
                battery_status_counter = 0;
                firstTime = 0;
            }
            if(battery_status_counter == DUR1MIN)
            {
                checkBattery();
                singleBeep = 1;
                if(battery_status == (uint16_t)NORMAL_GREEN)
                    setStartGreen(LED100);
                if(battery_status == (uint16_t)YELLOW_ALERT)
                    setStartRed(LED100);
                if(battery_status == (uint16_t)RED_ALERT)
                    setStartRed(LED100);
                if(battery_status == (uint16_t)KILL_ALERT)
                {                    
                    setStartRed(LED100);
                    currentState = StageB2;
                    firstTime = 1; 
                }
                battery_status_counter = 0;
            }
            if(stageB1_counter == (uint64_t)(DUR1MIN*10))
            {
                //printf("Go to B2 \n\r");
                currentState =  StageB2; 
                firstTime = 1;
            }
            if(buttonStateUpdated)
            {
                buttonStateUpdated = 0;
                if(currentButtState == LONG)
                {
                    //printf("Go to S \n\r");
                    currentState = StageShutdown;
                    firstTime = 1;
                }
                if(currentButtState == SHORT)
                {    
                    stopMotor();
                    //MOTOR = 0;
                    //printf("Go to C \n\r");
                    currentState = StageCEnd;
                    firstTime = 1;
                }
                if(currentButtState == TOOSHORT)
                {    
                }
            }
            battery_status_counter++;
            stageB1_counter++;
            break;
        case StageB2:
            if(firstTime)
            {
                //printf("Stage B2 \n\r");
                //setStartMotor(DutyMotor*0.3);
                //    stageB_counter = 0;
                battery_status_counter = 0;
                //checkBattery();
                //stopAll();
                firstTime = 0;
                ledCounter = 0;
            }
            if(battery_status_counter == DUR1MIN)
            {
                checkBattery();
                if(battery_status == (uint16_t)NORMAL_GREEN)
                    setStartGreen(LED100);
                if(battery_status == (uint16_t)YELLOW_ALERT)
                    setStartRed(LED100);
                if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                    setStartRed(LED100);
                battery_status_counter = 0;
            }
            
            if(ledCounter == 1)
                setStartRed(LED100);
            if(ledCounter == DURBLINKON)
            {    
                stopRed();
            }
            if(ledCounter == 2*DUR1SEC)
            {
                ledCounter = 0;
                singleBeep = 1;
            }
            if(buttonStateUpdated)
            {
                buttonStateUpdated = 0;
                if(currentButtState == LONG)
                {
                    //printf("Go to S \n\r");
                    currentState = StageShutdown;
                    firstTime = 1;
                }
                if(currentButtState == SHORT)
                {    
                    stopMotor();
                    //MOTOR = 0;
                    //printf("Go to C \n\r");
                    currentState = StageCEnd;
                    firstTime = 1;
                }
                if(currentButtState == TOOSHORT)
                {    
                }
            }
            battery_status_counter++;
            ledCounter++;
            break;
        case StageCEnd:
            if(firstTime)
            {
                printf("Stage C \n\r");
                //setStartMotor((uint16_t)(DutyMotor*0.5));
                firstTime = 0;
                stageC_counter = 0;
                //setStartBlue(LED100);
                battery_status_counter = DUR1MIN;
                ledCounter = 0;
                firstTimeC = 1;
            }
            if(battery_status_counter == DUR1MIN)
            {
                checkBattery();
                battery_status_counter = 0;
                if(battery_status == (uint16_t)NORMAL_GREEN)
                    setStartGreen(LED100);
                if(battery_status == (uint16_t)YELLOW_ALERT)
                    setStartRed(LED100);
                if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                    setStartRed(LED100);
                
                if(battery_status != (uint16_t)NORMAL_GREEN)
                    singleBeep = 1;
                battery_status_counter = 0;
                stopBlue();
                ledCounter = 0;
            }
            if(firstTimeC)
            {
                if(ledCounter == 5*DUR1SEC)
                {
                    stopAll();
                    setStartBlue(LED100);
                    firstTimeC = 0;
                }
            }
            else
            {
                if(ledCounter == 2*DUR1SEC)
                {
                    stopAll();
                    setStartBlue(LED100);
                    //firstTimeC = 0;
                }
            
            
            }
            if(stageC_counter == 2*DUR1MIN)
            {
                //printf("C:Go to D \n\r");
                lastState = currentState;
                currentState = StageDOff;
                firstTime = 1;
            }
            if(buttonStateUpdated)
            {
                buttonStateUpdated = 0;
                if(currentButtState == LONG)
                {
                    //printf("Go to S \n\r");
                    currentState = StageShutdown;
                    firstTime = 1;
                }
                if(currentButtState == SHORT)
                {    
                    stopMotor();
                    //MOTOR = 0;
                    //printf("Go to D \n\r");
                    //lastState = currentState;
                    currentState = StageDOff;
                    firstTime = 1;
                }
                if(currentButtState == TOOSHORT)
                {    
                    checkBattery();
                    if(battery_status == (uint16_t)NORMAL_GREEN)
                        setStartGreen(LED100);
                    if(battery_status == (uint16_t)YELLOW_ALERT)
                        setStartRed(LED100);
                    if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                        setStartRed(LED100);
                    
                    if(battery_status != (uint16_t)NORMAL_GREEN)
                        singleBeep = 1;
                    ledCounter = 0;
                    stopBlue();
                }
            }
            stageC_counter++;
            battery_status_counter++;
            ledCounter++;
            break;
        case StageDOff:
            if(firstTime)
            {
                stopMotor();
                //printf("Stage D \n\r");
                firstTime = 0;
                singleBeep = 1;
                stageD_counter = 0;
                checkBattery();
                if(battery_status == (uint16_t)NORMAL_GREEN)
                    setStartGreen(LED100);
                if(battery_status == (uint16_t)YELLOW_ALERT)
                    setStartRed(LED100);
                if((battery_status == (uint16_t)RED_ALERT)||(battery_status == (uint16_t)KILL_ALERT))
                    setStartRed(LED100);
                
                if(battery_status != NORMAL_GREEN)
                    singleBeep = 1;    
                //stageD_counter = 5*DUR1SEC;
            }
            if(stageD_counter == 5*DUR1SEC)
            {
                stopAll();
                //printf("Go to S \n\r");
                currentState = StageShutdown;
                firstTime = 1;
            }
            stageD_counter++;
            break;    
        case StageShutdown:
            if(firstTime)
            {
                //printf("Shut down \n\r");
                stopMotor();
                stopAll();
                shutdown_counter = 0;
                firstTime = 0;
            }
            shutdown_counter++;
            if (shutdown_counter == 1)
                BEEPER = 1;
            if (shutdown_counter == DURBEEPSHORT)
                BEEPER = 0;
            if (shutdown_counter == 2*DURBEEPSHORT)
                BEEPER = 1;
            if (shutdown_counter == 3*DURBEEPSHORT)
                BEEPER = 0;
            if (shutdown_counter == 4*DURBEEPSHORT)
                BEEPER = 1;
            if (shutdown_counter == 5*DURBEEPSHORT)
            {
                BEEPER = 0;
                //shutdown_counter = 0;
                POWER_TAKEOVER = 0;
                __delay_ms(100);
            }
            break;
        case StageLowBatt:
            break;
       default:
           break;      
   }  
}
