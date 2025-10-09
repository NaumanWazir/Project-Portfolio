/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h> // include processor files - each processor file is guarded.  

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */
  
#define SwitchDelay 100   
    
//define ADC channel
#define R 0
#define S 1  
#define T 2
#define U 3
#define V 4
#define W 5    
#define F 6    
    
#define L1 0
#define L2 1
#define L3 2

#define DELAYMULIPLIER 6 //51 for 1 sec should be 6 for 100ms
//    
#define VLow  0
#define Low   1
#define Med   2
#define High  3
#define VHigh 4    
#define Basic 1
#define Wait5sec 4999   
#define Wait2sec 1999    
    
//Coding for Phase level
#define OFF 0    
#define RH 1	//R high
#define RM 2	//R Medium 
#define RL 3	//R Low
#define SH 4	//S high
#define SM 5	//S medium
#define SL 6	//S low
#define TH 7	//T high
#define TM 8	//T medium
#define TL 9	//T low
#define UB  10	//U Basic
#define VB  11	//V Basic
#define WB  12	//W Basic
#define OFF1 13
#define OFF2 14
#define OFF3 15
    

//Relay driver Pin assignment 
#define UC_IN1	LATAbits.LATA6
#define UC_IN2	LATAbits.LATA7
#define SL3_IN1	LATBbits.LATB0
#define SL3_IN2	LATBbits.LATB1
#define TL3_IN1	LATBbits.LATB2
#define TL3_IN2	LATBbits.LATB3
#define CL3_IN1	LATCbits.LATC0
#define CL3_IN2	LATCbits.LATC1
#define CL2_IN1	LATCbits.LATC2
#define CL2_IN2	LATCbits.LATC3
#define RC_IN1	LATCbits.LATC4
#define RC_IN2	LATCbits.LATC5
#define SL2_IN1	LATCbits.LATC6
#define SL2_IN2 LATCbits.LATC7
#define VC_IN1	LATDbits.LATD0
#define VC_IN2	LATDbits.LATD1
#define CL1_IN1	LATDbits.LATD2
#define CL1_IN2	LATDbits.LATD3
#define TL2_IN1	LATDbits.LATD4
#define TL2_IN2	LATDbits.LATD5
#define WC_IN1	LATDbits.LATD6	
#define WC_IN2	LATDbits.LATD7
#define SL1_IN1	LATFbits.LATF0
#define SL1_IN2	LATFbits.LATF1
#define TL1_IN1	LATFbits.LATF2
#define TL1_IN2	LATFbits.LATF3
    
    
    

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	/* XC_HEADER_TEMPLATE_H */

