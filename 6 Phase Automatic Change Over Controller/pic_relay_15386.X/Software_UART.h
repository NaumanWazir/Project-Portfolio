
#ifndef __SOFT_UART_H
#define __SOFT_UART_H

#include "mcc_generated_files/mcc.h"
//#ifndef _XTAL_FREQ
// // This definition is required to calibrate __delay_us() and __delay_ms()
// #define _XTAL_FREQ 20000000
//#endif
#define Baudrate              9600                      // bps (9600,98)(38400,16)
#define OneBitDelay           98                        //(1000000/Baudrate)		// microseconds
#define DataBitCount          8                         // no parity, no flow control
#define UART_RX               PORTEbits.RE3						// UART RX pin
#define UART_TX               PORTEbits.RE0						// UART TX pin
#define UART_RX_DIR			  TRISEbits.TRISE3				// UART RX pin direction register
#define UART_TX_DIR			  TRISEbits.TRISE0					// UART TX pin direction register

#define CIRC_BBUF_DEF(x,y)                \
    uint8_t x##_data_space[y];            \
    circ_bbuf_t x = {                     \
        .buffer = x##_data_space,         \
        .head = 0,                        \
        .tail = 0,                        \
        .maxlen = y                       \
    }
typedef struct {
    uint8_t * const buffer;
    int head;
    int tail;
    const int maxlen;
} circ_bbuf_t;


//Function Declarations
void InitSoftUART(void);
unsigned char UART_Receive(void);
void UART_Transmit(const char);
void UART_Transmit_Asci(uint8_t);

int circ_bbuf_push(circ_bbuf_t *c, uint8_t data);
int circ_bbuf_pop(circ_bbuf_t *c, uint8_t *data);
void circ_bbuf_reset(circ_bbuf_t *c);
#endif