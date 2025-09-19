#ifndef _DRV_SPI_H
#define _DRV_SPI_H

// Include files

#include "common.h"

// Index to SPI channel
// Used when multiple MCP25xxFD are connected to the same SPI interface, but with different CS
#define SPI_DEFAULT_BUFFER_LENGTH 96

// Code anchor for break points
#define Nop() asm("nop")

void test_spi_pins(void);

void set_spi_pins(void);

void spi_master_init(void);

//! SPI Initialization

void DRV_SPI_Initialize(void);

//! SPI Read/Write Transfer

int8_t DRV_SPI_TransferData(uint8_t spiSlaveDeviceIndex, uint8_t *SpiTxData, uint8_t *SpiRxData, uint16_t spiTransferSize);


#endif	// _DRV_SPI_H