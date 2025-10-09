          
               
#include "mcc_generated_files/mcc.h"
#include "variables_relay.h"
#include "Software_UART.h"
#include "string.h"


void set_adc_values(uint32_t);
uint8_t getOutputLevel( uint16_t,uint8_t);
void timer2ISR(void);
uint32_t millis(void);
uint8_t check_sequence(uint8_t*,uint8_t*,uint8_t*);
uint8_t check_sequence_L1(uint8_t*);
uint8_t check_sequence_L2(uint8_t*);
uint8_t check_sequence_L3(uint8_t*);
void push_string_buffer(char*,size_t);
void initialize(void);
void relay_to_off(uint8_t,uint8_t,bool);
void relay_to_off_step1(uint8_t,bool);
void relay_to_on(uint8_t,uint8_t,bool);
void relay_to_on_step1(uint8_t,bool);
void relay_to_off_msg(uint8_t,uint8_t);
void relay_to_off_step1_msg(uint8_t);
void relay_to_on_msg(uint8_t,uint8_t);
void relay_to_on_step1_msg(uint8_t);

void flag_on_step1(uint8_t);
void flag_off_step1(uint8_t);
void flag_on(uint8_t,uint8_t);
void flag_off(uint8_t,uint8_t);

#define ADC_RES (float)(4.096/1023.00)
#define MARGIN (uint16_t)(0.05/ADC_RES)
#define buffer_size 200
CIRC_BBUF_DEF(my_circ_buf, buffer_size);


uint16_t volt_level[6] = { 0, (uint16_t)(1.6/ADC_RES), (uint16_t)(2.1/ADC_RES), (uint16_t)(2.5/ADC_RES), (uint16_t)(3.0/ADC_RES), (uint16_t)(5.0/ADC_RES)} ;
uint8_t level_pattern[12]={High,Med,High,High,Med,Med,Low,Low,Low,Basic,Basic,Basic};
uint8_t test_seq_L1[12] = {R,R,S,T,S,T,R,S,T,U,V,W};
uint8_t test_seq_L2[12] = {S,S,T,R,T,R,S,T,R,U,V,W};
uint8_t test_seq_L3[12] = {T,T,S,R,S,R,T,S,R,U,V,W};
uint8_t out_seq_L1[13] = {R,R,S,T,S,T,R,S,T,U,V,W,F};
uint8_t out_seq_L2[13] = {S,S,T,R,T,R,S,T,R,U,V,W,F};
uint8_t out_seq_L3[13] = {T,T,S,R,S,R,T,S,R,U,V,W,F};
uint8_t *test_seq_pointer[3];
uint8_t *out_seq_pointer[3];
volatile uint8_t run_mainloop = 0;
volatile uint16_t currentOutputLevels[6] = {0};
volatile uint32_t tick = 0;
volatile uint8_t current_L[3],temp_L[3],updated_L[3];
volatile uint8_t flag_CL3 = 0;
volatile uint8_t flag_CL2 = 0;
volatile uint8_t flag_CL1 = 0;
volatile uint8_t flag_RC = 0;
volatile uint8_t flag_WC = 0;
volatile uint8_t flag_UC = 0;
volatile uint8_t flag_VC = 0;
volatile uint8_t flagL1OnR = 0;
uint16_t result[6]={0};
uint32_t testCounter = 0;


/*
                         Main application
 */

// 20 ms interrupt timer
void timer2ISR(void)
{
    tick++;    
    run_mainloop = 1;
}
uint32_t millis(void)
{
    uint32_t out;
    INTERRUPT_PeripheralInterruptDisable();
    out = tick*20;
    INTERRUPT_PeripheralInterruptEnable();
    return out;
}
void push_string_buffer(char*data,size_t len)
{
    for (int i = 0; i < (int)(len);i++)
        circ_bbuf_push(&my_circ_buf,*(data+i));
}
void initialize(void)
{
    //Set microcontroller all relay control pin to 0
    RC_IN1	 = 0;
    RC_IN2	 = 0;
    UC_IN1	 = 0;
    UC_IN2	 = 0;
    VC_IN1	 = 0;
    VC_IN2	 = 0;
    WC_IN1	 = 0;	
    WC_IN2	 = 0;
    SL1_IN1 = 0;
    SL1_IN2 = 0;
    SL2_IN1 = 0;
    SL2_IN2 = 0;
    SL3_IN1 = 0;
    SL3_IN2 = 0;
    TL1_IN1 = 0;
    TL1_IN2 = 0;
    TL2_IN1 = 0;
    TL2_IN2 = 0;
    TL3_IN1 = 0;
    TL3_IN2 = 0;
    CL1_IN1 = 0;
    CL1_IN2 = 0;
    CL2_IN1 = 0;
    CL2_IN2 = 0;
    CL3_IN1 = 0;
    CL3_IN2 = 0;
    
    RC_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    RC_IN2 = LOW;       

    WC_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    WC_IN2 = LOW;
    
    
    VC_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    VC_IN2 = LOW;

    UC_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    UC_IN2 = LOW;
    
    CL1_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    CL1_IN2 = LOW;

    CL2_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    CL2_IN2 = LOW;
    CL3_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    CL3_IN2 = LOW;
    
    SL1_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    SL1_IN2 = LOW;    
    
    SL2_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    SL2_IN2 = LOW;

    SL3_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    SL3_IN2 = LOW;
    
    
    TL1_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    TL1_IN2 = LOW;
    
    TL2_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    TL2_IN2 = LOW;
    
    TL3_IN2 = HIGH;
    __delay_ms(SwitchDelay);
    TL3_IN2 = LOW;
    
    temp_L[L1] = F;
    temp_L[L2] = F;
    temp_L[L3] = F;
    current_L[L1] = F;
    current_L[L2] = F;
    current_L[L3] = F;
    
}
void main(void)
{
    uint8_t ch;
    uint8_t indexADC = 0;
    uint8_t indexLoad = 0;
    uint16_t counter = 0;
    uint32_t lastDebounceLevel[3] = {0};
    uint8_t inc_for_5sec[3] = {0};
    uint32_t lastDebounceAdc[6] = {0};
    uint8_t inc_for_2sec[6] = {0};
    uint8_t relayOfInProgress = 0;
    uint8_t relayOnInProgress = 0;
    uint8_t phaseWas = 6;
    uint8_t outputWas = 3;
    uint8_t phaseIs = 6;
    uint8_t outputIs = 3;
    uint8_t phaseExpected = 6;
    uint32_t time[6] = {0};
    uint32_t relayIsOff[3] = {0};
    uint8_t reading[6];
    uint8_t updated_reading[6];
    uint8_t previous[6];
    char buffer[50];
    SYSTEM_Initialize();
    test_seq_pointer [0] = test_seq_L1; 
    test_seq_pointer [1] = test_seq_L2; 
    test_seq_pointer [2] = test_seq_L3;
    out_seq_pointer [0] = out_seq_L1; 
    out_seq_pointer [1] = out_seq_L2; 
    out_seq_pointer [2] = out_seq_L3; 
    InitSoftUART();
    initialize();
    TMR1_SetInterruptHandler(timer2ISR);

    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    
    
    while (1)
    {            
        if(!circ_bbuf_pop(&my_circ_buf, &ch))
            UART_Transmit(ch);
        
        if(run_mainloop)
        {        
            //testCounter++;
            //set_adc_values(testCounter*20);
            //for (index = R; index <= W; index++)
            //{
                result[indexADC] = ADC_GetConversion(indexADC);
                updated_reading[indexADC] = getOutputLevel(result[indexADC],indexADC);
                if(updated_reading[indexADC] != previous[indexADC])
                {
                    time[indexADC] = millis();
                    lastDebounceAdc[indexADC] = 0;
                    inc_for_2sec [indexADC] = 1;
                }
                    //lastDebounceAdc[indexADC] = millis();
                //if ((millis() - lastDebounceAdc[indexADC]) > Wait2sec)
                if (lastDebounceAdc[indexADC] >= 16)
                    if (updated_reading[indexADC] != reading[indexADC])
                    {                     
                        reading[indexADC] = updated_reading[indexADC];
                        buffer[0]='A';
                        buffer[1]= indexADC+0x30;
                        buffer[2]= ':';
                        buffer[3]= reading[indexADC]+0x30;
                        buffer[4]= '\n';
                        buffer[5]= '\r';   
                        push_string_buffer(buffer,6);
                        lastDebounceAdc[indexADC] = 0;                     
                        inc_for_2sec[indexADC] = 0;
                    //    sprintf(buffer,"%d,%u\n\r",indexADC,result[indexADC]);                        
                    //    push_string_buffer(buffer,strlen(buffer));
                    }
                if (inc_for_2sec[indexADC])                        
                    lastDebounceAdc[indexADC]++;
                previous[indexADC] = updated_reading[indexADC];
            //}        
            updated_L[L1] = check_sequence_L1(reading);
            updated_L[L2] = check_sequence_L2(reading);
            updated_L[L3] = check_sequence_L3(reading);
            
            //for (index = L1; index<= L3; index++)
            //{
            //    updated_L[index] = check_sequence(reading,test_seq_pointer[index],out_seq_pointer[index]);
                if(updated_L[indexLoad] != temp_L[indexLoad])
                {
                    if((!relayOfInProgress) && (!relayOnInProgress)) 
                        {
                            outputWas = indexLoad;
                            phaseWas = current_L[indexLoad];
                            phaseExpected = updated_L[indexLoad];
                            counter = 0;         
                            relayOfInProgress = 1;
                            //lastDebounceLevel[indexLoad] = millis();
                            lastDebounceLevel[indexLoad] = 0;
                            inc_for_5sec[indexLoad] = 1;
                            //time[indexLoad] = millis();
                        }
                    else
                        updated_L[indexLoad] = temp_L[indexLoad]; 
                }
                temp_L[indexLoad] = updated_L[indexLoad];
                
                //if ((millis() - lastDebounceLevel[indexLoad]) > Wait5sec)
                if (lastDebounceLevel[indexLoad] >= 83)
                {
                    if ((updated_L[indexLoad] != current_L[indexLoad])||(relayIsOff[indexLoad]))
                    {
                    if((!relayOfInProgress) && (!relayOnInProgress)) 
                        {
                            outputIs = indexLoad;
                            phaseIs = updated_L[indexLoad];
                            current_L[indexLoad] = updated_L[indexLoad];
                            //sprintf(buffer,"L%d:%u\n\r",indexLoad+1,phaseIs);
                            buffer[0]='L';
                            buffer[1]= indexLoad+0x30+1;
                            buffer[2]= ':';
                            buffer[3]= phaseIs+0x30;
                            buffer[4]= '\n';
                            buffer[5]= '\r';
                            push_string_buffer(buffer,6);
                            //sprintf(buffer,"%d,%u\n\r",indexLoad,millis()-time[indexLoad]);                        
                            //push_string_buffer(buffer,strlen(buffer));
                            counter = 0;
                            relayOnInProgress = 1;
                            relayIsOff[indexLoad] = 0;
                            lastDebounceLevel[indexLoad]=0;
                            inc_for_5sec[indexLoad] = 0;
                        }                    
                    } 
                }
                if (inc_for_5sec[indexLoad])                        
                    lastDebounceLevel[indexLoad]++;
                
            //}
            if(relayOfInProgress)
            {           
                if (counter == 0)
                {
                    if (((phaseWas == R) || ((phaseWas >= U)&&(phaseWas <= W))) &&
                        ((phaseExpected == R) || ((phaseExpected >= U)&&(phaseExpected <= W))))    
                            relay_to_off(phaseWas,outputWas,0); 
                       
                    else
                    {
                        relay_to_off(phaseWas,outputWas,1);
                        relay_to_off_msg(phaseWas,outputWas);
                    }
                    relayIsOff[outputWas] = 1;
                }
                counter++;
                if(counter == DELAYMULIPLIER) 
                {                        
                    relay_to_off(phaseWas,outputWas,0);
                    if (!(((phaseWas == R) || ((phaseWas >= U)&&(phaseWas <= W))) &&
                        ((phaseExpected == R) || ((phaseExpected >= U)&&(phaseExpected <= W)))))
                            flag_off(phaseWas,outputWas);
                    
                    if ((phaseWas == R) || ((phaseWas >= U)&&(phaseWas <= W)))
                    {
                        if(phaseWas == R && outputWas == L1)
                            flagL1OnR = 0;
                        relay_to_off_step1(phaseWas,1);
                        relay_to_off_step1_msg(phaseWas);
                    }
                    else
                    { 
                        relayOfInProgress = 0;
                        counter = 0;
                    }
                }
                if(counter == 2*DELAYMULIPLIER-1) 
                {       
                    relay_to_off_step1(phaseWas,0);
                    flag_off_step1(phaseWas);
                    relayOfInProgress = 0;
                    counter = 0;
                }            
            }                
            if(relayOnInProgress)
            {
                if (counter == 0)
                {
                    relay_to_on(phaseIs,outputIs,1);
                    relay_to_on_msg(phaseIs,outputIs);
                }
                counter++;
                if(counter == DELAYMULIPLIER) 
                {                        
                    relay_to_on(phaseIs,outputIs,0);
                    flag_on(phaseIs,outputIs);
                    if ((phaseIs == R) || ((phaseIs >= U)&&(phaseIs <= W)))
                    {
                        if(phaseIs == R && outputIs == L1)
                            flagL1OnR = 1;
                        relay_to_on_step1(phaseIs,1);
                        relay_to_on_step1_msg(phaseIs);
                    }
                    else
                    { 
                        relayOnInProgress = 0;
                        counter = 0;
                    }
                }
                if(counter == 2*DELAYMULIPLIER-1) 
                {       
                    relay_to_on_step1(phaseIs,0);
                    flag_on_step1(phaseIs);
                    relayOnInProgress = 0;
                    counter = 0;
                }            
            }
            indexADC++;
            indexLoad++;
            if(indexADC >= 6)
                indexADC = 0;
            if(indexLoad >= 3)
                indexLoad = 0;
            run_mainloop = 0;
        }
        
    }
}
uint8_t check_sequence_L1(uint8_t*channel_reading){
    if(*(channel_reading+0) == level_pattern[0])
        return(out_seq_L1[0]);
    else if(*(channel_reading+0) == level_pattern[1])
        return(out_seq_L1[1]);
    else if(*(channel_reading+1) == level_pattern[2])
        return(out_seq_L1[2]);
    else if(*(channel_reading+2) == level_pattern[3])
        return(out_seq_L1[3]);
    else if(*(channel_reading+1) == level_pattern[4])
        return(out_seq_L1[4]);
    else if(*(channel_reading+2) == level_pattern[5])
        return(out_seq_L1[5]);
    else if(*(channel_reading+0) == level_pattern[6])
        return(out_seq_L1[6]);
    else if(*(channel_reading+1) == level_pattern[7])
        return(out_seq_L1[7]);
    else if(*(channel_reading+2) == level_pattern[8])
        return(out_seq_L1[8]);
    else if(*(channel_reading+3) == level_pattern[9])
        return(out_seq_L1[9]);
    else if(*(channel_reading+4) == level_pattern[10])
        return(out_seq_L1[10]);
    else if(*(channel_reading+5) == level_pattern[11])
        return(out_seq_L1[11]);
    else
        return(out_seq_L1[12]);
}

uint8_t check_sequence_L2(uint8_t*channel_reading){
    if(*(channel_reading+1) == level_pattern[0])
        return(out_seq_L2[0]);
    else if(*(channel_reading+1) == level_pattern[1])
        return(out_seq_L2[1]);
    else if(*(channel_reading+2) == level_pattern[2])
        return(out_seq_L2[2]);
    else if(*(channel_reading+0) == level_pattern[3])
        return(out_seq_L2[3]);
    else if(*(channel_reading+2) == level_pattern[4])
        return(out_seq_L2[4]);
    else if(*(channel_reading+0) == level_pattern[5])
        return(out_seq_L2[5]);
    else if(*(channel_reading+1) == level_pattern[6])
        return(out_seq_L2[6]);
    else if(*(channel_reading+2) == level_pattern[7])
        return(out_seq_L2[7]);
    else if(*(channel_reading+0) == level_pattern[8])
        return(out_seq_L2[8]);
    else if(*(channel_reading+3) == level_pattern[9])
        return(out_seq_L2[9]);
    else if(*(channel_reading+4) == level_pattern[10])
        return(out_seq_L2[10]);
    else if(*(channel_reading+5) == level_pattern[11])
        return(out_seq_L2[11]);
    else
        return(out_seq_L2[12]);
}

uint8_t check_sequence_L3(uint8_t*channel_reading){
    if(*(channel_reading+2) == level_pattern[0])
        return(out_seq_L3[0]);
    else if(*(channel_reading+2) == level_pattern[1])
        return(out_seq_L3[1]);
    else if(*(channel_reading+1) == level_pattern[2])
        return(out_seq_L3[2]);
    else if(*(channel_reading+0) == level_pattern[3])
        return(out_seq_L3[3]);
    else if(*(channel_reading+1) == level_pattern[4])
        return(out_seq_L3[4]);
    else if(*(channel_reading+0) == level_pattern[5])
        return(out_seq_L3[5]);
    else if(*(channel_reading+2) == level_pattern[6])
        return(out_seq_L3[6]);
    else if(*(channel_reading+1) == level_pattern[7])
        return(out_seq_L3[7]);
    else if(*(channel_reading+0) == level_pattern[8])
        return(out_seq_L3[8]);
    else if(*(channel_reading+3) == level_pattern[9])
        return(out_seq_L3[9]);
    else if(*(channel_reading+4) == level_pattern[10])
        return(out_seq_L3[10]);
    else if(*(channel_reading+5) == level_pattern[11])
        return(out_seq_L3[11]);
    else
        return(out_seq_L3[12]);
}


uint8_t check_sequence(uint8_t*channel_reading,uint8_t*channel_seq,uint8_t*out_seq){
 
uint8_t i;
for(i = 0;i<13;i++)
{
    if (i == 12)
        break;
    if((*(channel_reading + *(channel_seq +i))) == (level_pattern[i]))
        break;
} 
return (*(out_seq + i));    
}

uint8_t getOutputLevel( uint16_t inputLevel,uint8_t index ) {

  const uint16_t margin = MARGIN ;  
  const uint16_t numberOfLevelsOutput = 5 ;   
//const  uint16_t initialOutputLevel = 0 ;
  uint16_t currentOutputLevel = 0 ;
  currentOutputLevel = currentOutputLevels[index];
  uint16_t lb = volt_level[ currentOutputLevel ] ;
  if ( currentOutputLevel > 0 ) lb -= margin  ;   
  uint16_t ub = volt_level[ currentOutputLevel + 1 ] ;
  if ( currentOutputLevel < numberOfLevelsOutput ) ub +=  margin  ;
  if ( inputLevel < lb || inputLevel > ub ) {
    uint16_t i;
    for ( i = 0 ; i < numberOfLevelsOutput ; i++ ) {
      if ( inputLevel >= volt_level[ i ] && inputLevel <= volt_level[ i + 1 ] ) break ;
    }
    currentOutputLevel = i ;  
    currentOutputLevels[index] = currentOutputLevel;
  }
  if((index >= 3) && (currentOutputLevel!=0))
    {
      currentOutputLevels[index] = Basic;
      currentOutputLevel = Basic;
    }
  return (uint8_t)(currentOutputLevel) ;
}
void relay_to_off(uint8_t phase,uint8_t L,bool OnOf){
    switch(phase)
    {
        case U:
        case V:
        case W:
        case R:
            if(L == L1)
                if(flag_CL1)
                    CL1_IN2 = OnOf;   
            if(L == L2)
                if(flag_CL2)
                    CL2_IN2 = OnOf;
            if(L == L3)
                if(flag_CL3)
                    CL3_IN2 = OnOf;
            break;
        case S:
            if(L == L1)
                SL1_IN2 = OnOf;   
            if(L == L2)
                SL2_IN2 = OnOf;
            if(L == L3)
                SL3_IN2 = OnOf;
            break;
        case T:
            if(L == L1)
                TL1_IN2 = OnOf;   
            if(L == L2)
                TL2_IN2 = OnOf;
            if(L == L3)
                TL3_IN2 = OnOf;
            break;
        default:
            break;
    }
}
void relay_to_off_step1(uint8_t phase,bool OnOf)
{

    switch(phase)
    {
        case R:
            if(flag_RC && (!flagL1OnR))
                RC_IN2 = OnOf; 
            break;
        case W:
            if(flag_WC)
                WC_IN2 = OnOf; 
            break;
        case U:
            if(flag_UC)
                UC_IN2 = OnOf; 
            break;
        case V:
            if(flag_VC)
                VC_IN2 = OnOf; 
            break;
        default:
            break;
    }
}

void relay_to_on(uint8_t phase,uint8_t L, bool OnOf)
{
    switch(phase)
    {
        case U:
        case V:
        case W:
        case R:
            if(L == L1)
                if(!flag_CL1)
                    CL1_IN1 = OnOf;   
            if(L == L2)
                if(!flag_CL2)
                    CL2_IN1 = OnOf;
            if(L == L3)
                if(!flag_CL3)
                    CL3_IN1 = OnOf;
            break;
        case S:
            if(L == L1)
                SL1_IN1 = OnOf;   
            if(L == L2)
                SL2_IN1 = OnOf;
            if(L == L3)
                SL3_IN1 = OnOf;
            break;
        case T:
            if(L == L1)
                TL1_IN1 = OnOf;   
            if(L == L2)
                TL2_IN1 = OnOf;
            if(L == L3)
                TL3_IN1 = OnOf;
            break;
        default:
            break;
    }
}
void relay_to_on_step1(uint8_t phase,bool OnOf)
{
    switch(phase)
    {
        case R:
            if(!flag_RC)
                RC_IN1 = OnOf; 
            break;
        case W:           
            if(!flag_WC)
                WC_IN1 = OnOf; 
            break;
        case U:    
            if(!flag_UC)
                UC_IN1 = OnOf; 
            break;
        case V:    
            if(!flag_VC)
                VC_IN1 = OnOf; 
            break;
        default:
            break;
    }
}


void flag_on(uint8_t phase,uint8_t L)
{
    switch(phase)
    {
        case U:
        case V:
        case W:
        case R:
            if(L == L1)
                flag_CL1 = 1;  
            if(L == L2)
                flag_CL2 = 1;
            if(L == L3)
                flag_CL3 = 1;
            break;
        
        case T:
        case S:
            //if(L == L1)
            //    flagL1OnR = 0;
            break; 
        default:
            break;
    }
}

void flag_off(uint8_t phase,uint8_t L)
{
    switch(phase)
    {
        case U:
        case V:
        case W:
            if(L == L1)
                flag_CL1 = 0;
            if(L == L2)
                flag_CL2 = 0;
            if(L == L3)
                flag_CL3 = 0;
            break;
        case R:
            if(L == L1)
                {
                    flag_CL1 = 0;
                    flagL1OnR = 0;
                }  
            if(L == L2)
                flag_CL2 = 0;
            if(L == L3)
                flag_CL3 = 0;
            break;        
        default:
            break;
    }
}


void flag_on_step1(uint8_t phase)
{
    switch(phase)
    {
        case R:
            flag_RC = 1; 
            break;
        case W:
            flag_WC = 1; 
            break;
        case U:
            flag_UC = 1;  
            break;
        case V:
            flag_VC = 1;  
            break;
        default:
            break;
    }
}
void flag_off_step1(uint8_t phase)
{
    switch(phase)
    {
        case R:
            if(!flagL1OnR)
                flag_RC = 0; 
            break;
        case W:
            flag_WC = 0; 
            break;
        case U:
            flag_UC = 0;  
            break;
        case V:
            flag_VC = 0;  
            break;
        default:
            break;
    }


}


void relay_to_off_msg(uint8_t phase,uint8_t L)
{
    char buffer[50]={0};
    switch(phase)
    {
        case U:
        case V:
        case W:
        case R:
            if(L == L1)            
                if(flag_CL1)
                {//sprintf(buffer,"CL1 Off \n\r");
                    buffer[0]='C';
                    buffer[1]='L';
                    buffer[2]='1';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            if(L == L2)
                if(flag_CL2)
                {//sprintf(buffer,"CL2 Off \n\r");
                    buffer[0]='C';
                    buffer[1]='L';
                    buffer[2]='2';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            if(L == L3)
                if(flag_CL3)
                {//sprintf(buffer,"CL3 Off \n\r");
                    buffer[0]='C';
                    buffer[1]='L';
                    buffer[2]='3';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            break;
        case S:
            if(L == L1)
                {//sprintf(buffer,"SL1 Off \n\r");
                    buffer[0]='S';
                    buffer[1]='L';
                    buffer[2]='1';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }   
            if(L == L2)
                {//sprintf(buffer,"SL2 Off \n\r");
                    buffer[0]='S';
                    buffer[1]='L';
                    buffer[2]='2';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            if(L == L3)
                {//sprintf(buffer,"SL3 Off \n\r");
                    buffer[0]='S';
                    buffer[1]='L';
                    buffer[2]='3';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            break;
        case T:
            if(L == L1)
                {//sprintf(buffer,"TL1 Off \n\r");
                    buffer[0]='T';
                    buffer[1]='L';
                    buffer[2]='1';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }    
            if(L == L2)
                {//sprintf(buffer,"TL2 Off \n\r");
                    buffer[0]='T';
                    buffer[1]='L';
                    buffer[2]='2';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            if(L == L3)
                {//sprintf(buffer,"TL3 Off \n\r");
                    buffer[0]='T';
                    buffer[1]='L';
                    buffer[2]='3';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            break;
        default:
            break;
    }
    push_string_buffer(buffer,8);
}

void relay_to_off_step1_msg(uint8_t phase)
{ 
    char buffer[50]={0};
    switch(phase)
    {
        case R:
            if(flag_RC && (!flagL1OnR))
            {//sprintf(buffer,"RC Off \n\r");
                    buffer[0]='R';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'f';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
                } 
            break;
        case W:
            if(flag_WC)
            {//sprintf(buffer,"WC Off \n\r");
                    buffer[0]='W';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'f';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
                } 
            break;
        case U:
            if(flag_UC)
            {//sprintf(buffer,"UC Off \n\r");
                    buffer[0]='U';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'f';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
                }  
            break;
        case V:
            if(flag_VC)
            {//sprintf(buffer,"VC Off \n\r");
                    buffer[0]='V';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'f';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
                }  
            break;
        default:
            break;
    }
    push_string_buffer(buffer,7);
}

void relay_to_on_msg(uint8_t phase,uint8_t L)
{
    char buffer[50]={0};
    switch(phase)
    {
        case U:
        case V:
        case W:
        case R:
            if(L == L1)
                if(!flag_CL1)
                {//sprintf(buffer,"CL1 On \n\r");
                    buffer[0]='C';
                    buffer[1]='L';
                    buffer[2]='1';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }       
            if(L == L2)
                if(!flag_CL2)
                {//sprintf(buffer,"TL2 On \n\r");
                    buffer[0]='C';
                    buffer[1]='L';
                    buffer[2]='2';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            if(L == L3)
                if(!flag_CL3)
                {//sprintf(buffer,"CL3 On \n\r");
                    buffer[0]='C';
                    buffer[1]='L';
                    buffer[2]='3';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            break;
        case S:
            if(L == L1)
                {//sprintf(buffer,"SL1 On \n\r");
                    buffer[0]='S';
                    buffer[1]='L';
                    buffer[2]='1';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }       
            if(L == L2)
                {//sprintf(buffer,"SL2 On \n\r");
                    buffer[0]='S';
                    buffer[1]='L';
                    buffer[2]='2';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            if(L == L3)
                {//sprintf(buffer,"SL3 On \n\r");
                    buffer[0]='S';
                    buffer[1]='L';
                    buffer[2]='3';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            break;
        case T:
            if(L == L1)
                {//sprintf(buffer,"TL1 On \n\r");
                    buffer[0]='T';
                    buffer[1]='L';
                    buffer[2]='1';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }    
            if(L == L2)
                {//sprintf(buffer,"TL2 On \n\r");
                    buffer[0]='T';
                    buffer[1]='L';
                    buffer[2]='2';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            if(L == L3)
                {//sprintf(buffer,"TL3 On \n\r");
                    buffer[0]='T';
                    buffer[1]='L';
                    buffer[2]='3';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'n';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            break;
        default:
                {//sprintf(buffer,"TL3 On \n\r");
                    buffer[0]='S';
                    buffer[1]='P';
                    buffer[2]='1';
                    buffer[3]= ' ';
                    buffer[4]= 'O';
                    buffer[5]= 'f';
                    buffer[6]= '\n';
                    buffer[7]= '\r';
                }
            break;
    }
    push_string_buffer(buffer,8);
}

void relay_to_on_step1_msg(uint8_t phase)
{
    char buffer[50]={0};
    switch(phase)
    {
        case R:
            if(!flag_RC)
            {//sprintf(buffer,"RC On \n\r");
                    buffer[0]='R';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'n';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
            }  
            break;
        case W:
            if(!flag_WC)
            {//sprintf(buffer,"WC On \n\r");
                    buffer[0]='W';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'n';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
            } 
            break;
        case U:
            if(!flag_UC)
            {//sprintf(buffer,"UC On \n\r");
                    buffer[0]='U';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'n';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
            }  
            break;
        case V:
            if(!flag_VC)
            {//sprintf(buffer,"RC On \n\r");
                    buffer[0]='V';
                    buffer[1]='C';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'n';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
            } 
            break;
        default:
            {//sprintf(buffer,"Off \n\r");
                    buffer[0]='S';
                    buffer[1]='1';
                    buffer[2]= ' ';
                    buffer[3]= 'O';
                    buffer[4]= 'f';
                    buffer[5]= '\n';
                    buffer[6]= '\r';
            } 
            break;
    }
    push_string_buffer(buffer,7);
}

void set_adc_values(uint32_t timer)
{
    //1.8 = 368,450 = 2.2,572 = 2.8,675 = 3.3
    
    
    if(timer == 5000)
    {
        result[0] = 368;
        result[1] = 0;
        result[2] = 0;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 15000)
    {
        result[0] = 368;
        result[1] = 368;
        result[2] = 0;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 25000)
    {
        result[0] = 368;
        result[1] = 368;
        result[2] = 368;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0;
    }
    else if(timer == 35000)
    {
        result[0] = 450;
        result[1] = 368;
        result[2] = 368;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 45000)
    {
        result[0] = 450;
        result[1] = 450;
        result[2] = 368;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 55000)
    {
        result[0] = 450;
        result[1] = 450;
        result[2] = 450;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 65000)
    {
        result[0] = 572;
        result[1] = 450;
        result[2] = 450;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 75000)
    {
        result[0] = 572;
        result[1] = 572;
        result[2] = 450;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 85000)
    {
        result[0] = 572;
        result[1] = 572;
        result[2] = 572;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 95000)
    {
        result[0] = 675;
        result[1] = 572;
        result[2] = 572;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 105000)
    {
        result[0] = 675;
        result[1] = 675;
        result[2] = 572;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 115000)
    {
        result[0] = 675;
        result[1] = 675;
        result[2] = 675;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }
    else if(timer == 125000)
    {
        result[0] = 675;
        result[1] = 675;
        result[2] = 675;
        result[3] = 0;
        result[4] = 0;
        result[5] = 368; 
    }
    else if(timer == 135000)
    {
        result[0] = 675;
        result[1] = 675;
        result[2] = 675;
        result[3] = 0;
        result[4] = 368;
        result[5] = 368; 
    }
    else if(timer == 145000)
    {
        result[0] = 675;
        result[1] = 675;
        result[2] = 675;
        result[3] = 368;
        result[4] = 368;
        result[5] = 368; 
    }
    else if(timer >= 155000)
    {
        result[0] = 0;
        result[1] = 0;
        result[2] = 0;
        result[3] = 0;
        result[4] = 0;
        result[5] = 0; 
    }

}

/**
 End of File
*/