//#include "mcc_generated_files/device_config.h"
#include "Software_UART.h"



 
void InitSoftUART(void)		// Initialize UART pins to proper values
{
	UART_TX = 1;			// TX pin is high in idle state
	
	//UART_RX_DIR = 1;		// Input
	//UART_TX_DIR = 0;		// Output
}


/*
unsigned char UART_Receive(void)
{
	unsigned char DataValue = 0;

	//wait for start bit
	//while(UART_RX==1);
    if (UART_RX == 1)
       return 0x000;
    
	__delay_us(OneBitDelay);
	__delay_us(OneBitDelay/2);   // Take sample value in the mid of bit duration

	for ( unsigned char i = 0; i < DataBitCount; i++ )
	{
		if ( UART_RX == 1 )   //if received bit is high
		{
			DataValue += (1<<i);
		}

		__delay_us(OneBitDelay);
	}

	// Check for stop bit
	if ( UART_RX == 1 )       //Stop bit should be high
	{
		__delay_us(OneBitDelay/2);
		return DataValue;
	}
	else                      //some error occurred !
	{
		__delay_us(OneBitDelay/2);
		return 0x000;
	}
}
*/



void UART_Transmit(const char DataValue)
{
	/* Basic Logic
	   
	   TX pin is usually high. A high to low bit is the starting bit and 
	   a low to high bit is the ending bit. No parity bit. No flow control.
	   BitCount is the number of bits to transmit. Data is transmitted LSB first.

	*/

	// Send Start Bit
	UART_TX = 0;
	__delay_us(OneBitDelay);

	for ( unsigned char i = 0; i < DataBitCount; i++ )
	{
		//Set Data pin according to the DataValue
		if( ((DataValue>>i)&0x1) == 0x1 )   //if Bit is high
		{
			UART_TX = 1;
		}
		else      //if Bit is low
		{
			UART_TX = 0;
		}

	    __delay_us(OneBitDelay);
	}

	//Send Stop Bit
	UART_TX = 1;
	__delay_us(OneBitDelay);
}
int circ_bbuf_pop(circ_bbuf_t *c, uint8_t *data)
{
    int next;

    if (c->head == c->tail)  // if the head == tail, we don't have any data
        return -1;

    next = c->tail + 1;  // next is where tail will point to after this read.
    if(next >= c->maxlen)
        next = 0;

    *data = c->buffer[c->tail];  // Read data and then move
    c->tail = next;              // tail to next offset.
    return 0;  // return success to indicate successful push.
}

int circ_bbuf_push(circ_bbuf_t *c, uint8_t data)
{
    int next;

    next = c->head + 1;  // next is where head will point to after this write.
    if (next >= c->maxlen)
        next = 0;

    if (next == c->tail)  // if the head + 1 == tail, circular buffer is full
        return -1;

    c->buffer[c->head] = data;  // Load data and then move
    c->head = next;             // head to next data offset.
    return 0;  // return success to indicate successful push.
}
/*
void circ_bbuf_reset(circ_bbuf_t *c){

c->head = 0;
c->tail = 0;

}
*/
/*
void UART_Transmit_Asci(uint8_t c){
    UART_Transmit(c+0x30);
}
 */