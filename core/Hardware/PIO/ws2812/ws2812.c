/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */


#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/dma.h"
#include "ws2812.pio.h"
#include "ws2812.h"

/* Dedicate transfer channel for RGB SM */
static int dma_chan = -1;

static inline uint32_t urgb_u32(uint8_t r, uint8_t g, uint8_t b) {
    return  ((uint32_t) (0) << 24) |    //white LED intensity (not present in rgb ws2812 modules)
            ((uint32_t) (g) << 16) |    //green LED intensity
            ((uint32_t) (r) << 8 ) |    //red   LED intensity
            ((uint32_t) (b) << 0 ) ;    //blue  LED intensity
} 

ws2812_sm_error init_ws2812(ws2812_sm* sm_data) 
{
    //set_sys_clock_48();
    
    ws2812_sm_error retVal = SM_WS2812_E_OK;
    uint8_t         offset;

    /* The program must be added at offset 0 in order to work correctly */
    if(pio_can_add_program_at_offset (pio1, &ws2812_program, 0))
    {
        offset = pio_add_program(pio1, &ws2812_program);
        ws2812_program_init(pio1, sm_data->smID, offset, sm_data->pin, 800000, false);

        // /* Configure DMA channel */
        // dma_chan = dma_claim_unused_channel(true);
        // dma_channel_config c = dma_channel_get_default_config(dma_chan);
        // /* Transfer 32 bits of RGBW data (8 LSB are 0 for the RGB version) */
        // channel_config_set_transfer_data_size(&c, DMA_SIZE_32);
        // /* Increment read pixel values */
        // channel_config_set_read_increment(&c, true);
        // /* PIO0 will be always occupied by core0 CAN. PIO1 TX numbers from 0 to 3, depend on sm number */
        // /* Pace the data transfer for the receiving SM */
        // channel_config_set_dreq(&c, DREQ_PIO1_TX0 + sm_data->smID);
        // /* Always write to the same SM RX FIFO */
        // channel_config_set_write_increment(&c, false);
    }
    else
    {
        retVal = SM_WS2812_E_PIO_PROGRAM;
    }

    return retVal;
}

ws2812_sm_error ws2812_loadPattern(ws2812_sm* sm_data)
{
    uint16_t ledIndex = 0u;

    /* Generate pattern */

    for(ledIndex; ledIndex < sm_data->ledNumber; ++ledIndex)
    {
        // pio_sm_put_blocking(pio1, sm_data->smID, (sm_data->patternLocation)[ledIndex]);
    }
}