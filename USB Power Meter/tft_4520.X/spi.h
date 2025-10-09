#ifndef SPI_H
#define SPI_H

/**
  Section: Included Files
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* SPI interfaces */
typedef enum { 
    SPI_DEFAULT
} spi_modes_t;

void SPI_Initialize(void);
bool SPI_Open(spi_modes_t spiUniqueConfiguration);
void SPI_Close(void);
uint8_t SPI_ExchangeByte(uint8_t data);
void SPI_ExchangeBlock(void *block, size_t blockSize);
void SPI_WriteBlock(void *block, size_t blockSize);
void SPI_ReadBlock(void *block, size_t blockSize);
void SPI_WriteByte(uint8_t byte);
uint8_t SPI_ReadByte(void);

#endif //SPI_H