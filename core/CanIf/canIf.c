#include "canIf.h"
#include <stdint.h>
#include "hardware/spi.h"
#include "../Hardware/SPI/MCP2515/MCP2515_can.h"

#define DEFAULT_MCP_SPI_CLK (8 * 1000 * 1000)
#define DEFAULT_MCP_BITRATE CAN_500KBPS
#define DEFAULT_MCP_CLK     MCP_8MHZ

///TODO: 
can_frame connectionRequestFrame = 
{
    .can_id = 0x42,
    .can_dlc = 8,
};


MCP2515_instance    can_spi_hw_instance;
bool                can_spi_hw_initialized;

/**
 * @brief Initialize the MCP2515 SPI CAN interface
 * @details Initialize SPI1 block (pins 12,13,14,15) or SPI1 block (pins 16,17,18,19) and set up the MCP2515 controller
 * 
 */
uint8_t canIf_init(CAN_SPI_ClusterID clusterID)
{
    uint8_t retVal = 0;

    can_spi_hw_initialized = false; 

    if(CAN_SPI_CLUSTER_0 == clusterID)
    {
        can_spi_hw_instance.INT_PIN       = 11u;
        can_spi_hw_instance.RX_PIN        = 12u;
        can_spi_hw_instance.CS_PIN        = 13u;
        can_spi_hw_instance.SCK_PIN       = 14u;
        can_spi_hw_instance.TX_PIN        = 15u;
        can_spi_hw_instance.SPI_INSTANCE  = spi1;
        can_spi_hw_instance.SPI_CLOCK     = DEFAULT_MCP_SPI_CLK;
    }
    else if(CAN_SPI_CLUSTER_1 == clusterID)
    {
        can_spi_hw_instance.RX_PIN        = 16u;
        can_spi_hw_instance.CS_PIN        = 17u;
        can_spi_hw_instance.SCK_PIN       = 18u;
        can_spi_hw_instance.TX_PIN        = 19u;
        can_spi_hw_instance.INT_PIN       = 20u;
        can_spi_hw_instance.SPI_INSTANCE  = spi0;
        can_spi_hw_instance.SPI_CLOCK     = DEFAULT_MCP_SPI_CLK;
    }
    else
    {
        /* Report SPI_CLUSTER_UNDEFINED error */
        retVal = 1;
    }

    if(0 == retVal)
    {
        /* Initialize SPI hardware */
        MCP2515_init            (&can_spi_hw_instance);
        /* Reset the MCP IC */
        MCP2515_reset           (&can_spi_hw_instance);
        /* Set crystal oscilator and baudrate */
        MCP2515_setBitrate      (&can_spi_hw_instance, DEFAULT_MCP_BITRATE, DEFAULT_MCP_CLK);

        /* Check the status of the IC */
        MCP2515_getStatus       (&can_spi_hw_instance, &can_spi_hw_instance.icStatus);
        MCP2515_getRxStatus     (&can_spi_hw_instance, &can_spi_hw_instance.rxStatus);

        ///TODO: check the ic status
        if(can_spi_hw_instance.icStatus)
        {

        }
        ///TODO: check the rx buffer status
        else if(can_spi_hw_instance.rxStatus)
        {

        }
        else
        {
            /* No errors detected */
            retVal = 0;
            can_spi_hw_initialized = true;
        }

    }

}

uint8_t canIf_start()
{
    uint8_t retVal = 0;

    /* Check if the SPI hw was initialized successfully */
    if(true == can_spi_hw_initialized)
    {
        /* Set controller into normal mode */
        MCP2515_setNormalMode   (&can_spi_hw_instance);
        
        /* Send network connection request */
        // MCP2515_sendMessage     (&can_spi_hw_instance, &(canInterface->txIfFrames[0].canFrame));
    }

    return retVal;
}