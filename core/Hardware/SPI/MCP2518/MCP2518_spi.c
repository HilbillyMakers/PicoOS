// Include files
#include "MCP2518_spi.h"

void test_spi_pins(void)
{
    gpio_init   (MOSI_PIN);
    gpio_init   (MISO_PIN);
    gpio_init   (SCK_PIN);
    gpio_init   (CS_FD1);
    gpio_set_dir(MOSI_PIN,  GPIO_OUT);
    gpio_set_dir(MISO_PIN,  GPIO_OUT);
    gpio_set_dir(SCK_PIN,   GPIO_OUT);
    gpio_set_dir(CS_FD1,    GPIO_OUT);

    gpio_put    (MOSI_PIN,  1);
    gpio_put    (MISO_PIN,  1);
    gpio_put    (SCK_PIN,   1);
    gpio_put    (CS_FD1,    1);

    sleep_ms    (250);
    gpio_put    (MOSI_PIN,  0);
    sleep_ms    (250);

   // gpio_put(MISO_PIN, 1);
    sleep_ms    (250);
    gpio_put    (MISO_PIN,  0);
    sleep_ms    (250);
 
   // gpio_put(SCK_PIN, 1);
    sleep_ms    (250);
    gpio_put    (SCK_PIN,   0);
    sleep_ms    (250);

  //  gpio_put(CS_FD1, 1);
    sleep_ms    (250);
    gpio_put    (CS_FD1,    0);
    sleep_ms    (250);

    gpio_put    (MOSI_PIN,  1);
    gpio_put    (MISO_PIN,  1);
    gpio_put    (SCK_PIN,   1);
    gpio_put    (CS_FD1,    1);
}

void set_spi_pins(void)
{
    gpio_init   (MOSI_PIN);
    gpio_init   (MISO_PIN);
    gpio_init   (SCK_PIN);
    gpio_init   (CS_FD1);
    gpio_init   (CS_FD2);
    gpio_set_dir(MOSI_PIN,  GPIO_OUT);
    gpio_set_dir(MISO_PIN,  GPIO_IN);
    gpio_set_dir(SCK_PIN,   GPIO_OUT);
    gpio_set_dir(CS_FD1,    GPIO_OUT);
    gpio_set_dir(CS_FD2,    GPIO_OUT);
    gpio_put    (MOSI_PIN,  1);
    gpio_put    (SCK_PIN,   1);
    gpio_put    (CS_FD1,    1);
    gpio_put    (CS_FD2,    1);
}


void DRV_SPI_Initialize(void)
{
	  spi_master_init();
}

int8_t DRV_SPI_TransferData(uint8_t spiSlaveDeviceIndex, uint8_t *SpiTxData, uint8_t *SpiRxData, uint16_t spiTransferSize)
{

	  if (CAN1 == spiSlaveDeviceIndex)
	  {
		  gpio_put(CS_FD1, 0); // Select MCP2518FD
		  spi_write_read_blocking(SPI_DEVICE, SpiTxData, SpiRxData, spiTransferSize);
		  gpio_put(CS_FD1, 1); // Deselect MCP2518FD	
	  }
	  else if (CAN2 == spiSlaveDeviceIndex)
	  {
		  gpio_put(CS_FD2, 0); // Select MCP2518FD
		  spi_write_read_blocking(SPI_DEVICE, SpiTxData, SpiRxData, spiTransferSize);
		  gpio_put(CS_FD2, 1); // Deselect MCP2518FD	
	  }

    return 0;
}

void spi_master_init(void)
{
    // These are the defaults anyway:
    spi_set_format    (SPI_DEVICE, 8U, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
    //
    // CAN FD board is clocked at 40MHz, so SPI must be no more than 17000000: FSCK must
    // be less than or equal to 0.85 * (FSYSCLK/2). Other boards may use different clocks for
    // the CAN controller and this should be reflected here.
    spi_init          (SPI_DEVICE, 17000000);
    gpio_set_function (MISO_PIN, GPIO_FUNC_SPI);
    gpio_set_function (SCK_PIN,  GPIO_FUNC_SPI);
    gpio_set_function (MOSI_PIN, GPIO_FUNC_SPI);
    gpio_pull_up      (MOSI_PIN);
    gpio_pull_up      (MISO_PIN);

    // Set the chip select pin for the MCP25xxFD as a GPIO port
    gpio_set_function (CS_FD1, GPIO_FUNC_SIO);
    gpio_set_function (CS_FD2, GPIO_FUNC_SIO);

}

//#define USE_SPI_FUNCTIONS