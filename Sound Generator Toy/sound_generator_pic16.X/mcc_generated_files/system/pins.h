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
 * @version Driver Version  3.0.0
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

// get/set IO_RA2 aliases
#define Sound_TRIS                 TRISAbits.TRISA2
#define Sound_LAT                  LATAbits.LATA2
#define Sound_PORT                 PORTAbits.RA2
#define Sound_WPU                  WPUAbits.WPUA2
#define Sound_OD                   ODCONAbits.ODCA2
#define Sound_ANS                  ANSELAbits.ANSA2
#define Sound_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define Sound_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define Sound_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define Sound_GetValue()           PORTAbits.RA2
#define Sound_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define Sound_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define Sound_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define Sound_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define Sound_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define Sound_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define Sound_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define Sound_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)
// get/set IO_RA4 aliases
#define INT_TRIS                 TRISAbits.TRISA4
#define INT_LAT                  LATAbits.LATA4
#define INT_PORT                 PORTAbits.RA4
#define INT_WPU                  WPUAbits.WPUA4
#define INT_OD                   ODCONAbits.ODCA4
#define INT_ANS                  ANSELAbits.ANSA4
#define INT_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define INT_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define INT_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define INT_GetValue()           PORTAbits.RA4
#define INT_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define INT_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define INT_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define INT_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define INT_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define INT_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define INT_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define INT_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)
// get/set IO_RA5 aliases
#define SW_TRIS                 TRISAbits.TRISA5
#define SW_LAT                  LATAbits.LATA5
#define SW_PORT                 PORTAbits.RA5
#define SW_WPU                  WPUAbits.WPUA5
#define SW_OD                   ODCONAbits.ODCA5
#define SW_ANS                  ANSELAbits.ANSA5
#define SW_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define SW_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define SW_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define SW_GetValue()           PORTAbits.RA5
#define SW_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define SW_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define SW_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define SW_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define SW_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define SW_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define SW_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define SW_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)
#define RA5_SetInterruptHandler  SW_SetInterruptHandler
// get/set IO_RC0 aliases
#define SCL_TRIS                 TRISCbits.TRISC0
#define SCL_LAT                  LATCbits.LATC0
#define SCL_PORT                 PORTCbits.RC0
#define SCL_WPU                  WPUCbits.WPUC0
#define SCL_OD                   ODCONCbits.ODCC0
#define SCL_ANS                  ANSELCbits.ANSC0
#define SCL_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define SCL_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define SCL_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define SCL_GetValue()           PORTCbits.RC0
#define SCL_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define SCL_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define SCL_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define SCL_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define SCL_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define SCL_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define SCL_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define SCL_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)
// get/set IO_RC1 aliases
#define SDA_TRIS                 TRISCbits.TRISC1
#define SDA_LAT                  LATCbits.LATC1
#define SDA_PORT                 PORTCbits.RC1
#define SDA_WPU                  WPUCbits.WPUC1
#define SDA_OD                   ODCONCbits.ODCC1
#define SDA_ANS                  ANSELCbits.ANSC1
#define SDA_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define SDA_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define SDA_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define SDA_GetValue()           PORTCbits.RC1
#define SDA_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define SDA_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define SDA_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define SDA_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define SDA_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define SDA_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define SDA_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define SDA_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)
// get/set IO_RC2 aliases
#define LED_TRIS                 TRISCbits.TRISC2
#define LED_LAT                  LATCbits.LATC2
#define LED_PORT                 PORTCbits.RC2
#define LED_WPU                  WPUCbits.WPUC2
#define LED_OD                   ODCONCbits.ODCC2
#define LED_ANS                  ANSELCbits.ANSC2
#define LED_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define LED_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define LED_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define LED_GetValue()           PORTCbits.RC2
#define LED_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define LED_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)
// get/set IO_RC3 aliases
#define LED_BD_TRIS                 TRISCbits.TRISC3
#define LED_BD_LAT                  LATCbits.LATC3
#define LED_BD_PORT                 PORTCbits.RC3
#define LED_BD_WPU                  WPUCbits.WPUC3
#define LED_BD_OD                   ODCONCbits.ODCC3
#define LED_BD_ANS                  ANSELCbits.ANSC3
#define LED_BD_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define LED_BD_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define LED_BD_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define LED_BD_GetValue()           PORTCbits.RC3
#define LED_BD_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define LED_BD_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define LED_BD_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define LED_BD_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define LED_BD_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define LED_BD_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define LED_BD_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define LED_BD_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)
// get/set IO_RC4 aliases
#define IO_RC4_TRIS                 TRISCbits.TRISC4
#define IO_RC4_LAT                  LATCbits.LATC4
#define IO_RC4_PORT                 PORTCbits.RC4
#define IO_RC4_WPU                  WPUCbits.WPUC4
#define IO_RC4_OD                   ODCONCbits.ODCC4
#define IO_RC4_ANS                  ANSELCbits.ANSC4
#define IO_RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_RC4_GetValue()           PORTCbits.RC4
#define IO_RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_RC4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_RC4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_RC4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_RC4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_RC4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_RC4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)
// get/set IO_RC5 aliases
#define IO_RC5_TRIS                 TRISCbits.TRISC5
#define IO_RC5_LAT                  LATCbits.LATC5
#define IO_RC5_PORT                 PORTCbits.RC5
#define IO_RC5_WPU                  WPUCbits.WPUC5
#define IO_RC5_OD                   ODCONCbits.ODCC5
#define IO_RC5_ANS                  ANSELCbits.ANSC5
#define IO_RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_RC5_GetValue()           PORTCbits.RC5
#define IO_RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_RC5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_RC5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_RC5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_RC5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_RC5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_RC5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)
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

/**
 * @ingroup  pinsdriver
 * @brief Interrupt on Change Handler for the SW pin functionality
 * @param none
 * @return none
 */
void SW_ISR(void);

/**
 * @ingroup  pinsdriver
 * @brief Interrupt Handler Setter for SW pin interrupt-on-change functionality.
 *        Allows selecting an interrupt handler for SW at application runtime.
 * @pre Pins intializer called
 * @param InterruptHandler function pointer.
 * @return none
 */
void SW_SetInterruptHandler(void (* InterruptHandler)(void));

/**
 * @ingroup  pinsdriver
 * @brief Dynamic Interrupt Handler for SW pin.
 *        This is a dynamic interrupt handler to be used together with the SW_SetInterruptHandler() method.
 *        This handler is called every time the SW ISR is executed and allows any function to be registered at runtime.
 * @pre Pins intializer called
 * @param none
 * @return none
 */
extern void (*SW_InterruptHandler)(void);

/**
 * @ingroup  pinsdriver
 * @brief Default Interrupt Handler for SW pin. 
 *        This is a predefined interrupt handler to be used together with the SW_SetInterruptHandler() method.
 *        This handler is called every time the SW ISR is executed. 
 * @pre Pins intializer called
 * @param none
 * @return none
 */
void SW_DefaultInterruptHandler(void);


#endif // PINS_H
/**
 End of File
*/