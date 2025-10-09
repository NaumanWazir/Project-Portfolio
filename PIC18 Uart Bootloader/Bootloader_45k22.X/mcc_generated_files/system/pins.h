/**
 * Generated Pins header File
 * 
 * @file pins.h
 * 
 * @defgroup  pinsdriver Pins Driver
 * 
 * @brief This is generated driver header for pins. 
 *        This header file provides APIs for all pins selected in the GUI.
 *
 * @version Driver Version  3.1.0
*/

/*
© [2024] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/

#ifndef PINS_H
#define PINS_H

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set RA0 aliases
#define BL_ENTRY_TRIS                 TRISAbits.TRISA0
#define BL_ENTRY_LAT                  LATAbits.LATA0
#define BL_ENTRY_PORT                 PORTAbits.RA0
#define BL_ENTRY_WPU                  WPUAbits.
#define BL_ENTRY_OD                   ODCONAbits.
#define BL_ENTRY_ANS                  ANSELAbits.ANSA0
#define BL_ENTRY_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define BL_ENTRY_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define BL_ENTRY_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define BL_ENTRY_GetValue()           PORTAbits.RA0
#define BL_ENTRY_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define BL_ENTRY_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define BL_ENTRY_SetPullup()          do { WPUAbits. = 1; } while(0)
#define BL_ENTRY_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define BL_ENTRY_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define BL_ENTRY_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define BL_ENTRY_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define BL_ENTRY_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set RA1 aliases
#define BL_INDICATOR_TRIS                 TRISAbits.TRISA1
#define BL_INDICATOR_LAT                  LATAbits.LATA1
#define BL_INDICATOR_PORT                 PORTAbits.RA1
#define BL_INDICATOR_WPU                  WPUAbits.
#define BL_INDICATOR_OD                   ODCONAbits.
#define BL_INDICATOR_ANS                  ANSELAbits.ANSA1
#define BL_INDICATOR_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define BL_INDICATOR_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define BL_INDICATOR_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define BL_INDICATOR_GetValue()           PORTAbits.RA1
#define BL_INDICATOR_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define BL_INDICATOR_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define BL_INDICATOR_SetPullup()          do { WPUAbits. = 1; } while(0)
#define BL_INDICATOR_ResetPullup()        do { WPUAbits. = 0; } while(0)
#define BL_INDICATOR_SetPushPull()        do { ODCONAbits. = 0; } while(0)
#define BL_INDICATOR_SetOpenDrain()       do { ODCONAbits. = 1; } while(0)
#define BL_INDICATOR_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define BL_INDICATOR_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set RC6 aliases
#define IO_RC6_TRIS                 TRISCbits.TRISC6
#define IO_RC6_LAT                  LATCbits.LATC6
#define IO_RC6_PORT                 PORTCbits.RC6
#define IO_RC6_WPU                  WPUCbits.
#define IO_RC6_OD                   ODCONCbits.
#define IO_RC6_ANS                  ANSELCbits.ANSC6
#define IO_RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_RC6_GetValue()           PORTCbits.RC6
#define IO_RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_RC6_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC6_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC6_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC6_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_RC6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set RC7 aliases
#define IO_RC7_TRIS                 TRISCbits.TRISC7
#define IO_RC7_LAT                  LATCbits.LATC7
#define IO_RC7_PORT                 PORTCbits.RC7
#define IO_RC7_WPU                  WPUCbits.
#define IO_RC7_OD                   ODCONCbits.
#define IO_RC7_ANS                  ANSELCbits.ANSC7
#define IO_RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_RC7_GetValue()           PORTCbits.RC7
#define IO_RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_RC7_SetPullup()          do { WPUCbits. = 1; } while(0)
#define IO_RC7_ResetPullup()        do { WPUCbits. = 0; } while(0)
#define IO_RC7_SetPushPull()        do { ODCONCbits. = 0; } while(0)
#define IO_RC7_SetOpenDrain()       do { ODCONCbits. = 1; } while(0)
#define IO_RC7_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_RC7_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

// get/set RD6 aliases
#define IO_RD6_TRIS                 TRISDbits.TRISD6
#define IO_RD6_LAT                  LATDbits.LATD6
#define IO_RD6_PORT                 PORTDbits.RD6
#define IO_RD6_WPU                  WPUDbits.
#define IO_RD6_OD                   ODCONDbits.
#define IO_RD6_ANS                  ANSELDbits.ANSD6
#define IO_RD6_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define IO_RD6_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define IO_RD6_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define IO_RD6_GetValue()           PORTDbits.RD6
#define IO_RD6_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define IO_RD6_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define IO_RD6_SetPullup()          do { WPUDbits. = 1; } while(0)
#define IO_RD6_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define IO_RD6_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define IO_RD6_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define IO_RD6_SetAnalogMode()      do { ANSELDbits.ANSD6 = 1; } while(0)
#define IO_RD6_SetDigitalMode()     do { ANSELDbits.ANSD6 = 0; } while(0)

// get/set RD7 aliases
#define IO_RD7_TRIS                 TRISDbits.TRISD7
#define IO_RD7_LAT                  LATDbits.LATD7
#define IO_RD7_PORT                 PORTDbits.RD7
#define IO_RD7_WPU                  WPUDbits.
#define IO_RD7_OD                   ODCONDbits.
#define IO_RD7_ANS                  ANSELDbits.ANSD7
#define IO_RD7_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define IO_RD7_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define IO_RD7_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define IO_RD7_GetValue()           PORTDbits.RD7
#define IO_RD7_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define IO_RD7_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define IO_RD7_SetPullup()          do { WPUDbits. = 1; } while(0)
#define IO_RD7_ResetPullup()        do { WPUDbits. = 0; } while(0)
#define IO_RD7_SetPushPull()        do { ODCONDbits. = 0; } while(0)
#define IO_RD7_SetOpenDrain()       do { ODCONDbits. = 1; } while(0)
#define IO_RD7_SetAnalogMode()      do { ANSELDbits.ANSD7 = 1; } while(0)
#define IO_RD7_SetDigitalMode()     do { ANSELDbits.ANSD7 = 0; } while(0)

/**
 * @ingroup  pinsdriver
 * @brief GPIO and peripheral I/O initialization
 * @param none
 * @return none
 */
void PIN_MANAGER_Initialize (void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handling routine
 * @param none
 * @return none
 */
void PIN_MANAGER_IOC(void);


#endif // PINS_H
/**
 End of File
*/