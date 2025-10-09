
#include "spi.h"
#include <xc.h>

typedef struct { 
    uint8_t con1; 
    uint8_t stat;
    uint8_t add;
    uint8_t operation;
} spi_configuration_t;

//con1 == SSPxCON1, stat == SSPxSTAT, add == SSPxADD, operation == Master/Slave
static const spi_configuration_t spi_configuration[] = {   
    { 0x10, 0x80, 0x1, 0 }
};

void SPI_Initialize(void)
{
    //SPI setup
    SSPSTAT = 0x80;
    SSPCON1 = 0x00;
    SSPADD = 0x01;
    TRISCbits.TRISC3 = 0;
    SSPCON1bits.SSPEN = 0;
}

bool SPI_Open(spi_modes_t spiUniqueConfiguration)
{
    if(!SSPCON1bits.SSPEN)
    {
        SSPSTAT = spi_configuration[spiUniqueConfiguration].stat;
        SSPCON1 = spi_configuration[spiUniqueConfiguration].con1;
        SSPADD  = spi_configuration[spiUniqueConfiguration].add;
        TRISCbits.TRISC3 = spi_configuration[spiUniqueConfiguration].operation;
        SSPCON1bits.SSPEN = 1;
        return true;
    }
    return false;
}

void SPI_Close(void)
{
    SSPCON1bits.SSPEN = 0;
}

uint8_t SPI_ExchangeByte(uint8_t data)
{
    SSPBUF = data;
    while(!PIR1bits.SSPIF);
    PIR1bits.SSPIF = 0;
    return SSPBUF;
}

void SPI_ExchangeBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SSPBUF = *data;
        while(!PIR1bits.SSPIF);
        PIR1bits.SSPIF = 0;
        *data++ = SSPBUF;
    }
}

// Half Duplex SPI Functions
void SPI_WriteBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        SPI_ExchangeByte(*data++);
    }
}

void SPI_ReadBlock(void *block, size_t blockSize)
{
    uint8_t *data = block;
    while(blockSize--)
    {
        *data++ = SPI_ExchangeByte(0);
    }
}

void SPI_WriteByte(uint8_t byte)
{
    SSPBUF = byte;
}

uint8_t SPI_ReadByte(void)
{
    return SSPBUF;
}