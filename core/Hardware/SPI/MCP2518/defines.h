#ifndef _DRV_CANFDSPI_DEFINES_H
#define _DRV_CANFDSPI_DEFINES_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

// Device selection
//#define MCP2517FD
#define MCP2518FD

// Maximum Size of TX/RX Object
#define MAX_MSG_SIZE 76

// Maximum number of data bytes in message
#define MAX_DATA_BYTES 64

//! CAN FIFO Channels

typedef enum {
    CAN_FIFO_CH0,   // CAN_TXQUEUE_CH0
    CAN_FIFO_CH1,
    CAN_FIFO_CH2,
    CAN_FIFO_CH3,
    CAN_FIFO_CH4,
    CAN_FIFO_CH5,
    CAN_FIFO_CH6,
    CAN_FIFO_CH7,
    CAN_FIFO_CH8,
    CAN_FIFO_CH9,
    CAN_FIFO_CH10,
    CAN_FIFO_CH11,
    CAN_FIFO_CH12,
    CAN_FIFO_CH13,
    CAN_FIFO_CH14,
    CAN_FIFO_CH15,
    CAN_FIFO_CH16,
    CAN_FIFO_CH17,
    CAN_FIFO_CH18,
    CAN_FIFO_CH19,
    CAN_FIFO_CH20,
    CAN_FIFO_CH21,
    CAN_FIFO_CH22,
    CAN_FIFO_CH23,
    CAN_FIFO_CH24,
    CAN_FIFO_CH25,
    CAN_FIFO_CH26,
    CAN_FIFO_CH27,
    CAN_FIFO_CH28,
    CAN_FIFO_CH29,
    CAN_FIFO_CH30,
    CAN_FIFO_CH31,
    CAN_FIFO_TOTAL_CHANNELS
} CAN_FIFO_CHANNEL;

// FIFO0 is a special FIFO, the TX Queue
#define CAN_TXQUEUE_CH0 CAN_FIFO_CH0

//! CAN Filter Channels

typedef enum {
    CAN_FILTER0,
    CAN_FILTER1,
    CAN_FILTER2,
    CAN_FILTER3,
    CAN_FILTER4,
    CAN_FILTER5,
    CAN_FILTER6,
    CAN_FILTER7,
    CAN_FILTER8,
    CAN_FILTER9,
    CAN_FILTER10,
    CAN_FILTER11,
    CAN_FILTER12,
    CAN_FILTER13,
    CAN_FILTER14,
    CAN_FILTER15,
    CAN_FILTER16,
    CAN_FILTER17,
    CAN_FILTER18,
    CAN_FILTER19,
    CAN_FILTER20,
    CAN_FILTER21,
    CAN_FILTER22,
    CAN_FILTER23,
    CAN_FILTER24,
    CAN_FILTER25,
    CAN_FILTER26,
    CAN_FILTER27,
    CAN_FILTER28,
    CAN_FILTER29,
    CAN_FILTER30,
    CAN_FILTER31,
    CAN_FILTER_TOTAL,
} CAN_FILTER;


//! CAN Operation Modes

typedef enum {
    CAN_NORMAL_MODE                             = 0x00,
    CAN_SLEEP_MODE                              = 0x01,
    CAN_INTERNAL_LOOPBACK_MODE                  = 0x02,
    CAN_LISTEN_ONLY_MODE                        = 0x03,
    CAN_CONFIGURATION_MODE                      = 0x04,
    CAN_EXTERNAL_LOOPBACK_MODE                  = 0x05,
    CAN_CLASSIC_MODE                            = 0x06,
    CAN_RESTRICTED_MODE                         = 0x07,
    CAN_INVALID_MODE                            = 0xFF
} CAN_OPERATION_MODE;

//! Transmit Bandwidth Sharing

typedef enum {
    CAN_TXBWS_NO_DELAY,
    CAN_TXBWS_2,
    CAN_TXBWS_4,
    CAN_TXBWS_8,
    CAN_TXBWS_16,
    CAN_TXBWS_32,
    CAN_TXBWS_64,
    CAN_TXBWS_128,
    CAN_TXBWS_256,
    CAN_TXBWS_512,
    CAN_TXBWS_1024,
    CAN_TXBWS_2048,
    CAN_TXBWS_4096
} CAN_TX_BANDWITH_SHARING;

//! Wake-up Filter Time

typedef enum {
    CAN_WFT00,
    CAN_WFT01,
    CAN_WFT10,
    CAN_WFT11
} CAN_WAKEUP_FILTER_TIME;

//! Data Byte Filter Number

typedef enum {
    CAN_DNET_FILTER_DISABLE = 0,
    CAN_DNET_FILTER_SIZE_1_BIT,
    CAN_DNET_FILTER_SIZE_2_BIT,
    CAN_DNET_FILTER_SIZE_3_BIT,
    CAN_DNET_FILTER_SIZE_4_BIT,
    CAN_DNET_FILTER_SIZE_5_BIT,
    CAN_DNET_FILTER_SIZE_6_BIT,
    CAN_DNET_FILTER_SIZE_7_BIT,
    CAN_DNET_FILTER_SIZE_8_BIT,
    CAN_DNET_FILTER_SIZE_9_BIT,
    CAN_DNET_FILTER_SIZE_10_BIT,
    CAN_DNET_FILTER_SIZE_11_BIT,
    CAN_DNET_FILTER_SIZE_12_BIT,
    CAN_DNET_FILTER_SIZE_13_BIT,
    CAN_DNET_FILTER_SIZE_14_BIT,
    CAN_DNET_FILTER_SIZE_15_BIT,
    CAN_DNET_FILTER_SIZE_16_BIT,
    CAN_DNET_FILTER_SIZE_17_BIT,
    CAN_DNET_FILTER_SIZE_18_BIT
} CAN_DNET_FILTER_SIZE;

//! FIFO Payload Size

typedef enum {
    CAN_PLSIZE_8,
    CAN_PLSIZE_12,
    CAN_PLSIZE_16,
    CAN_PLSIZE_20,
    CAN_PLSIZE_24,
    CAN_PLSIZE_32,
    CAN_PLSIZE_48,
    CAN_PLSIZE_64
} CAN_FIFO_PLSIZE;

//! CAN Configure

typedef struct _CAN_CONFIG {
    uint32_t DNetFilterCount                : 5;
    uint32_t IsoCrcEnable                   : 1;
    uint32_t ProtocolExpectionEventDisable  : 1;
    uint32_t WakeUpFilterEnable             : 1;
    uint32_t WakeUpFilterTime               : 2;
    uint32_t BitRateSwitchDisable           : 1;
    uint32_t RestrictReTxAttempts           : 1;
    uint32_t EsiInGatewayMode               : 1;
    uint32_t SystemErrorToListenOnly        : 1;
    uint32_t StoreInTEF                     : 1;
    uint32_t TXQEnable                      : 1;
    uint32_t TxBandWidthSharing             : 4;
} CAN_CONFIG;

//! CAN Transmit Channel Configure

typedef struct _CAN_TX_FIFO_CONFIG {
    uint32_t RTREnable      : 1;
    uint32_t TxPriority     : 5;
    uint32_t TxAttempts     : 2;
    uint32_t FifoSize       : 5;
    uint32_t PayLoadSize    : 3;
} CAN_TX_FIFO_CONFIG;

//! CAN Transmit Queue Configure

typedef struct _CAN_TX_QUEUE_CONFIG {
    uint32_t TxPriority     : 5;
    uint32_t TxAttempts     : 2;
    uint32_t FifoSize       : 5;
    uint32_t PayLoadSize    : 3;
} CAN_TX_QUEUE_CONFIG;

//! CAN Receive Channel Configure

typedef struct _CAN_RX_FIFO_CONFIG {
    uint32_t RxTimeStampEnable  : 1;
    uint32_t FifoSize           : 5;
    uint32_t PayLoadSize        : 3;
} CAN_RX_FIFO_CONFIG;

//! CAN Transmit Event FIFO Configure

typedef struct _CAN_TEF_CONFIG {
    uint32_t TimeStampEnable    : 1;
    uint32_t FifoSize           : 5;
} CAN_TEF_CONFIG;

/**********************************************/
/* CAN Message Objects ************************/

/**
 * @brief CAN Message Object ID
 * @param SID   Standard Identifier
 * @param EID   Extended Identifier
 * @param SID11 In FD mode the standard ID can be extended to 12 bit using r1
 */
typedef struct _CAN_MSGOBJ_ID {
    uint32_t SID            : 11;
    uint32_t EID            : 18;
    uint32_t SID11          : 1;
    uint32_t unimplemented1 : 2;
} CAN_MSGOBJ_ID;

//! CAN Data Length Code

typedef enum {
    CAN_DLC_0,
    CAN_DLC_1,
    CAN_DLC_2,
    CAN_DLC_3,
    CAN_DLC_4,
    CAN_DLC_5,
    CAN_DLC_6,
    CAN_DLC_7,
    CAN_DLC_8,
    CAN_DLC_12,
    CAN_DLC_16,
    CAN_DLC_20,
    CAN_DLC_24,
    CAN_DLC_32,
    CAN_DLC_48,
    CAN_DLC_64
} CAN_DLC;

/**
 * @brief CAN TX Message Object Control 
 * @param DLC Data Length Code
 * @param IDE Identifier Extension Flag; distinguishes between base and extended format
 * @param RTR Remote Transmission Request; not used in CAN FD
 * @param BRS Bit Rate Switch; selects if data bit rate is switched
 * @param FDF FD Frame; distinguishes between CAN and CAN FD formats
 * @param ESI Error Status Indicator 
                In CAN to CAN gateway mode (CiCON.ESIGM=1), the transmitted ESI flag is a “logical OR” of T1.ESI
                and error passive state of the CAN controller; 
                In normal mode ESI indicates the error status
                    1 = Transmitting node is error passive
                    0 = Transmitting node is error active
 * @param SEQ Sequence to keep track of transmitted messages in Transmit Event FIFO
 */
typedef struct _CAN_TX_MSGOBJ_CTRL {
    uint32_t DLC : 4;
    uint32_t IDE : 1;
    uint32_t RTR : 1;
    uint32_t BRS : 1;
    uint32_t FDF : 1;
    uint32_t ESI : 1;
    uint32_t SEQ : 23;
} CAN_TX_MSGOBJ_CTRL;

//! CAN RX Message Object Control

typedef struct _CAN_RX_MSGOBJ_CTRL {
    uint32_t DLC            : 4;
    uint32_t IDE            : 1;
    uint32_t RTR            : 1;
    uint32_t BRS            : 1;
    uint32_t FDF            : 1;
    uint32_t ESI            : 1;
    uint32_t unimplemented1 : 2;
    uint32_t FilterHit      : 5;
    uint32_t unimplemented2 : 16;
} CAN_RX_MSGOBJ_CTRL;

//! CAN Message Time Stamp
typedef uint32_t CAN_MSG_TIMESTAMP;

/**
 * @brief CAN Message Time Stamp
 * @param TBCPRE Time Base Counter Prescaler bits
 *                  1023 = TBC increments every 1024 clocks
 *                  ...
 *                  0 = TBC increments every 1 clock
 *
 * @param TBCEN  Time Base Counter Enable bit
 *                  (1 = Enable TBC)
 *                  (0 = Stop and reset TBC)
 * @param TSEOF  Time Stamp EOF bit - 
 *                  (1 - Time Stamp when frame is taken valid - 
 *                      | RX no error until last but one bit of EOF
 *                      | TX no error until the end of EOF)
 *                  (0 - Time Stamp at “beginning” of Frame -
 *                      | Classical Frame: at sample point of SOF
 *                      | FD Frame: see TSRES bit)
 * @param TSRES  Time Stamp res bit (FD Frames only) -
 *                  (1 = at sample point of the bit following the FDF bit.)
 *                  (0 =  at sample point of SOF)
 */
typedef union _U_CAN_MSG_TIMESTAMP {
    struct {
        uint32_t TBCPRE             : 10;
        uint32_t unimplemented5     : 5;
        uint32_t TBCEN              : 1;
        uint32_t TSEOF              : 1;
        uint32_t TSRES              : 1;
        uint32_t Unimplemented11    : 11;
    } bF;
    uint32_t word[1];
    uint8_t  byte[4]; 
} U_CAN_MSG_TIMESTAMP;


/**
 * @brief CAN TX Message Object
 * @param id        Bits 0 - 31 Contains message ID configuration data
 * @param ctrl      Bits 0 - 31 Contain message configuration data
 * @param timeStamp 
 * 
 * @param word
 * 
 * @param byte
 */
typedef union _CAN_TX_MSGOBJ {

    struct {
        CAN_MSGOBJ_ID       id;
        CAN_TX_MSGOBJ_CTRL  ctrl;
        CAN_MSG_TIMESTAMP   timeStamp;
    } bF;
    uint32_t    word[3];
    uint8_t     byte[12];
} CAN_TX_MSGOBJ;

//! CAN RX Message Object

typedef union _CAN_RX_MSGOBJ {

    struct {
        CAN_MSGOBJ_ID       id;
        CAN_RX_MSGOBJ_CTRL  ctrl;
        CAN_MSG_TIMESTAMP   timeStamp;
    } bF;
    uint32_t    word[3];
    uint8_t     byte[12];
} CAN_RX_MSGOBJ;

//! CAN TEF Message Object

typedef union _CAN_TEF_MSGOBJ {

    struct {
        CAN_MSGOBJ_ID       id;
        CAN_TX_MSGOBJ_CTRL  ctrl;
        CAN_MSG_TIMESTAMP   timeStamp;
    } bF;
    uint32_t    word[3];
    uint8_t     byte[12];
} CAN_TEF_MSGOBJ;

//! CAN Filter Object ID

typedef struct _CAN_FILTEROBJ_ID {
    uint32_t SID            : 11;
    uint32_t EID            : 18;
    uint32_t SID11          : 1;
    uint32_t EXIDE          : 1;
    uint32_t unimplemented1 : 1;
} CAN_FILTEROBJ_ID;

//! CAN Mask Object ID

typedef struct _CAN_MASKOBJ_ID {
    uint32_t MSID           : 11;
    uint32_t MEID           : 18;
    uint32_t MSID11         : 1;
    uint32_t MIDE           : 1;
    uint32_t unimplemented1 : 1;
} CAN_MASKOBJ_ID;

//! CAN RX FIFO Status

typedef enum {
    CAN_RX_FIFO_EMPTY                       = 0x00,
    CAN_RX_FIFO_NOT_EMPTY                   = 0x01,
    CAN_RX_FIFO_HALF_FULL                   = 0x02,
    CAN_RX_FIFO_FULL                        = 0x04,
    CAN_RX_FIFO_OVERFLOW                    = 0x08,
    CAN_RX_FIFO_STATUS_MASK                 = 0x0F,
} CAN_RX_FIFO_STATUS;

//! CAN TX FIFO Status

typedef enum {
    CAN_TX_FIFO_FULL                        = 0x000,
    CAN_TX_FIFO_NOT_FULL                    = 0x001,
    CAN_TX_FIFO_HALF_FULL                   = 0x002,
    CAN_TX_FIFO_EMPTY                       = 0x004,
    CAN_TX_FIFO_ATTEMPTS_EXHAUSTED          = 0x010,
    CAN_TX_FIFO_ERROR                       = 0x020,
    CAN_TX_FIFO_ARBITRATION_LOST            = 0x040,
    CAN_TX_FIFO_ABORTED                     = 0x080,
    CAN_TX_FIFO_TRANSMITTING                = 0x100,
    CAN_TX_FIFO_STATUS_MASK                 = 0x1F7,
} CAN_TX_FIFO_STATUS;

//! CAN TEF FIFO Status

typedef enum {
    CAN_TEF_FIFO_EMPTY                      = 0x00,
    CAN_TEF_FIFO_NOT_EMPTY                  = 0x01,
    CAN_TEF_FIFO_HALF_FULL                  = 0x02,
    CAN_TEF_FIFO_FULL                       = 0x04,
    CAN_TEF_FIFO_OVERFLOW                   = 0x08,
    CAN_TEF_FIFO_STATUS_MASK                = 0x0F,
} CAN_TEF_FIFO_STATUS;

//! CAN Module Event (Interrupts)

typedef enum {
    CAN_NO_EVENT                            = 0x0000,
    CAN_TX_EVENT                            = 0x0001,
    CAN_RX_EVENT                            = 0x0002,
    CAN_TIME_BASE_COUNTER_EVENT             = 0x0004,
    CAN_OPERATION_MODE_CHANGE_EVENT         = 0x0008,
    CAN_TEF_EVENT                           = 0x0010,

    CAN_RAM_ECC_EVENT                       = 0x0100,
    CAN_SPI_CRC_EVENT                       = 0x0200,
    CAN_TX_ATTEMPTS_EVENT                   = 0x0400,
    CAN_RX_OVERFLOW_EVENT                   = 0x0800,
    CAN_SYSTEM_ERROR_EVENT                  = 0x1000,
    CAN_BUS_ERROR_EVENT                     = 0x2000,
    CAN_BUS_WAKEUP_EVENT                    = 0x4000,
    CAN_RX_INVALID_MESSAGE_EVENT            = 0x8000,
    CAN_ALL_EVENTS                          = 0xFF1F,
} CAN_MODULE_EVENT;

//! CAN TX FIFO Event (Interrupts)

typedef enum {
    CAN_TX_FIFO_NO_EVENT                    = 0x00,
    CAN_TX_FIFO_NOT_FULL_EVENT              = 0x01,
    CAN_TX_FIFO_HALF_FULL_EVENT             = 0x02,
    CAN_TX_FIFO_EMPTY_EVENT                 = 0x04,
    CAN_TX_FIFO_ATTEMPTS_EXHAUSTED_EVENT    = 0x10,
    CAN_TX_FIFO_ALL_EVENTS                  = 0x17,
} CAN_TX_FIFO_EVENT;

//! CAN RX FIFO Event (Interrupts)

typedef enum {
    CAN_RX_FIFO_NO_EVENT                    = 0x00,
    CAN_RX_FIFO_NOT_EMPTY_EVENT             = 0x01,
    CAN_RX_FIFO_HALF_FULL_EVENT             = 0x02,
    CAN_RX_FIFO_FULL_EVENT                  = 0x04,
    CAN_RX_FIFO_OVERFLOW_EVENT              = 0x08,
    CAN_RX_FIFO_ALL_EVENTS                  = 0x0F,
} CAN_RX_FIFO_EVENT;

//! CAN TEF FIFO Event (Interrupts)

typedef enum {
    CAN_TEF_FIFO_NO_EVENT                   = 0x00,
    CAN_TEF_FIFO_NOT_EMPTY_EVENT            = 0x01,
    CAN_TEF_FIFO_HALF_FULL_EVENT            = 0x02,
    CAN_TEF_FIFO_FULL_EVENT                 = 0x04,
    CAN_TEF_FIFO_OVERFLOW_EVENT             = 0x08,
    CAN_TEF_FIFO_ALL_EVENTS                 = 0x0F,
} CAN_TEF_FIFO_EVENT;

//! CAN Bit Time Setup: Arbitration/Data Bit Phase

typedef enum {
    CAN_500K_1M, // 0x00
    CAN_500K_2M, // 0x01
    CAN_500K_3M,
    CAN_500K_4M,
    CAN_500K_5M, // 0x04
    CAN_500K_6M7,
    CAN_500K_8M, // 0x06
    CAN_500K_10M,
    CAN_250K_500K, // 0x08
    CAN_250K_833K,
    CAN_250K_1M,
    CAN_250K_1M5,
    CAN_250K_2M,
    CAN_250K_3M,
    CAN_250K_4M,
    CAN_1000K_4M, // 0x0f
    CAN_1000K_8M,
    CAN_125K_500K // 0x11
} CAN_BITTIME_SETUP;

//! CAN Nominal Bit Time Setup

typedef enum {
    CAN_NBT_125K,
    CAN_NBT_250K,
    CAN_NBT_500K,
    CAN_NBT_1M
} CAN_NOMINAL_BITTIME_SETUP;

//! CAN Data Bit Time Setup

typedef enum {
    CAN_DBT_500K,
    CAN_DBT_833K,
    CAN_DBT_1M,
    CAN_DBT_1M5,
    CAN_DBT_2M,
    CAN_DBT_3M,
    CAN_DBT_4M,
    CAN_DBT_5M,
    CAN_DBT_6M7,
    CAN_DBT_8M,
    CAN_DBT_10M
} CAN_DATA_BITTIME_SETUP;

//! Secondary Sample Point Mode

typedef enum {
    CAN_SSP_MODE_OFF,
    CAN_SSP_MODE_MANUAL,
    CAN_SSP_MODE_AUTO
} CAN_SSP_MODE;

//! CAN Error State

typedef enum {
    CAN_ERROR_FREE_STATE                    = 0x00,
    CAN_TX_RX_WARNING_STATE                 = 0x01,
    CAN_RX_WARNING_STATE                    = 0x02,
    CAN_TX_WARNING_STATE                    = 0x04,
    CAN_RX_BUS_PASSIVE_STATE                = 0x08,
    CAN_TX_BUS_PASSIVE_STATE                = 0x10,
    CAN_TX_BUS_OFF_STATE                    = 0x20,
    CAN_ERROR_ALL                           = 0x3F,
} CAN_ERROR_STATE;

//! CAN Time Stamp Mode Select

typedef enum {
    CAN_TS_SOF                              = 0x00,
    CAN_TS_EOF                              = 0x01,
    CAN_TS_RES                              = 0x02
} CAN_TS_MODE;

//! CAN ECC EVENT

typedef enum {
    CAN_ECC_NO_EVENT                        = 0x00,
    CAN_ECC_ALL_EVENTS                      = 0x06,
    CAN_ECC_SEC_EVENT                       = 0x02,
    CAN_ECC_DED_EVENT                       = 0x04
} CAN_ECC_EVENT;

//! CAN CRC EVENT

typedef enum {
    CAN_CRC_NO_EVENT                        = 0x00,
    CAN_CRC_ALL_EVENTS                      = 0x03,
    CAN_CRC_CRCERR_EVENT                    = 0x01,
    CAN_CRC_FORMERR_EVENT                   = 0x02
} CAN_CRC_EVENT;

//! GPIO Pin Position

typedef enum {
    GPIO_PIN_0,
    GPIO_PIN_1
} GPIO_PIN_POS;

//! GPIO Pin Modes

typedef enum {
    GPIO_MODE_INT,
    GPIO_MODE_GPIO
} GPIO_PIN_MODE;

//! GPIO Pin Directions

typedef enum {
    GPIO_OUTPUT,
    GPIO_INPUT
} GPIO_PIN_DIRECTION;

//! GPIO Open Drain Mode

typedef enum {
    GPIO_PUSH_PULL,
    GPIO_OPEN_DRAIN
} GPIO_OPEN_DRAIN_MODE;

//! GPIO Pin State

typedef enum {
    GPIO_LOW,
    GPIO_HIGH
} GPIO_PIN_STATE;

//! Clock Output Mode

typedef enum {
    GPIO_CLKO_CLOCK,
    GPIO_CLKO_SOF
} GPIO_CLKO_MODE;

//! CAN Bus Diagnostic flags

typedef struct _CAN_BUS_DIAG_FLAGS {
    uint32_t NBIT0_ERR      : 1;
    uint32_t NBIT1_ERR      : 1;
    uint32_t NACK_ERR       : 1;
    uint32_t NFORM_ERR      : 1;
    uint32_t NSTUFF_ERR     : 1;
    uint32_t NCRC_ERR       : 1;
    uint32_t unimplemented1 : 1;
    uint32_t TXBO_ERR       : 1;
    uint32_t DBIT0_ERR      : 1;
    uint32_t DBIT1_ERR      : 1;
    uint32_t unimplemented2 : 1;
    uint32_t DFORM_ERR      : 1;
    uint32_t DSTUFF_ERR     : 1;
    uint32_t DCRC_ERR       : 1;
    uint32_t ESI            : 1;
    uint32_t DLC_MISMATCH   : 1;
} CAN_BUS_DIAG_FLAGS;

//! CAN Bus Diagnostic Error Counts

typedef struct _CAN_BUS_ERROR_COUNT {
    uint8_t NREC;
    uint8_t NTEC;
    uint8_t DREC;
    uint8_t DTEC;
} CAN_BUS_ERROR_COUNT;

//! CAN BUS DIAGNOSTICS

typedef union _CAN_BUS_DIAGNOSTIC {

    struct {
        CAN_BUS_ERROR_COUNT errorCount;
        uint16_t            errorFreeMsgCount;
        CAN_BUS_DIAG_FLAGS  flag;
    } bF;
    uint32_t    word[2];
    uint8_t     byte[8];
} CAN_BUS_DIAGNOSTIC;

//! TXREQ Channel Bits
// Multiple channels can be or'ed together

typedef enum {
    CAN_TXREQ_CH0                       = 0x00000001,
    CAN_TXREQ_CH1                       = 0x00000002,
    CAN_TXREQ_CH2                       = 0x00000004,
    CAN_TXREQ_CH3                       = 0x00000008,
    CAN_TXREQ_CH4                       = 0x00000010,
    CAN_TXREQ_CH5                       = 0x00000020,
    CAN_TXREQ_CH6                       = 0x00000040,
    CAN_TXREQ_CH7                       = 0x00000080,

    CAN_TXREQ_CH8                       = 0x00000100,
    CAN_TXREQ_CH9                       = 0x00000200,
    CAN_TXREQ_CH10                      = 0x00000400,
    CAN_TXREQ_CH11                      = 0x00000800,
    CAN_TXREQ_CH12                      = 0x00001000,
    CAN_TXREQ_CH13                      = 0x00002000,
    CAN_TXREQ_CH14                      = 0x00004000,
    CAN_TXREQ_CH15                      = 0x00008000,

    CAN_TXREQ_CH16                      = 0x00010000,
    CAN_TXREQ_CH17                      = 0x00020000,
    CAN_TXREQ_CH18                      = 0x00040000,
    CAN_TXREQ_CH19                      = 0x00080000,
    CAN_TXREQ_CH20                      = 0x00100000,
    CAN_TXREQ_CH21                      = 0x00200000,
    CAN_TXREQ_CH22                      = 0x00400000,
    CAN_TXREQ_CH23                      = 0x00800000,

    CAN_TXREQ_CH24                      = 0x01000000,
    CAN_TXREQ_CH25                      = 0x02000000,
    CAN_TXREQ_CH26                      = 0x04000000,
    CAN_TXREQ_CH27                      = 0x08000000,
    CAN_TXREQ_CH28                      = 0x10000000,
    CAN_TXREQ_CH29                      = 0x20000000,
    CAN_TXREQ_CH30                      = 0x40000000,
    CAN_TXREQ_CH31                      = 0x80000000
} CAN_TXREQ_CHANNEL;

//! Oscillator Control

typedef struct _CAN_OSC_CTRL {
    uint32_t PllEnable          : 1;
    uint32_t OscDisable         : 1;
    uint32_t SclkDivide         : 1;
    uint32_t ClkOutDivide       : 2;
#ifndef MCP2517FD
    uint32_t LowPowerModeEnable : 1;
#endif
} CAN_OSC_CTRL;

//! Oscillator Status

typedef struct _CAN_OSC_STATUS {
    uint32_t PllReady   : 1;
    uint32_t OscReady   : 1;
    uint32_t SclkReady  : 1;
} CAN_OSC_STATUS;

//! ICODE

typedef enum {
    CAN_ICODE_FIFO_CH0                  = 0x00,
    CAN_ICODE_FIFO_CH1                  = 0x01,
    CAN_ICODE_FIFO_CH2                  = 0x02,
    CAN_ICODE_FIFO_CH3                  = 0x03,
    CAN_ICODE_FIFO_CH4                  = 0x04,
    CAN_ICODE_FIFO_CH5                  = 0x05,
    CAN_ICODE_FIFO_CH6                  = 0x06,
    CAN_ICODE_FIFO_CH7                  = 0x07,
    CAN_ICODE_FIFO_CH8                  = 0x08,
    CAN_ICODE_FIFO_CH9                  = 0x09,
    CAN_ICODE_FIFO_CH10                 = 0x0A,
    CAN_ICODE_FIFO_CH11                 = 0x0B,
    CAN_ICODE_FIFO_CH12                 = 0x0C,
    CAN_ICODE_FIFO_CH13                 = 0x0D,
    CAN_ICODE_FIFO_CH14                 = 0x0E,
    CAN_ICODE_FIFO_CH15                 = 0x0F,
    CAN_ICODE_FIFO_CH16                 = 0x10,
    CAN_ICODE_FIFO_CH17                 = 0x11,
    CAN_ICODE_FIFO_CH18                 = 0x12,
    CAN_ICODE_FIFO_CH19                 = 0x13,
    CAN_ICODE_FIFO_CH20                 = 0x14,
    CAN_ICODE_FIFO_CH21                 = 0x15,
    CAN_ICODE_FIFO_CH22                 = 0x16,
    CAN_ICODE_FIFO_CH23                 = 0x17,
    CAN_ICODE_FIFO_CH24                 = 0x18,
    CAN_ICODE_FIFO_CH25                 = 0x19,
    CAN_ICODE_FIFO_CH26                 = 0x1A,
    CAN_ICODE_FIFO_CH27                 = 0x1B,
    CAN_ICODE_FIFO_CH28                 = 0x1C,
    CAN_ICODE_FIFO_CH29                 = 0x1D,
    CAN_ICODE_FIFO_CH30                 = 0x1E,
    CAN_ICODE_FIFO_CH31                 = 0x1F,
    CAN_ICODE_TOTAL_CHANNELS            = 0x20,

    CAN_ICODE_NO_INT                    = 0x40,
    CAN_ICODE_CERRIF                    = 0x41,
    CAN_ICODE_WAKIF                     = 0x42,
    CAN_ICODE_RXOVIF                    = 0x43,
    CAN_ICODE_ADDRERR_SERRIF            = 0x44,
    CAN_ICODE_MABOV_SERRIF              = 0x45,
    CAN_ICODE_TBCIF                     = 0x46,
    CAN_ICODE_MODIF                     = 0x47,
    CAN_ICODE_IVMIF                     = 0x48,
    CAN_ICODE_TEFIF                     = 0x49,
    CAN_ICODE_TXATIF                    = 0x4A,
    CAN_ICODE_RESERVED                  = 0x4B,
} CAN_ICODE;

//! RXCODE

typedef enum {
    CAN_RXCODE_FIFO_CH1                 = 0x01,
    CAN_RXCODE_FIFO_CH2                 = 0x02,
    CAN_RXCODE_FIFO_CH3                 = 0x03,
    CAN_RXCODE_FIFO_CH4                 = 0x04,
    CAN_RXCODE_FIFO_CH5                 = 0x05,
    CAN_RXCODE_FIFO_CH6                 = 0x06,
    CAN_RXCODE_FIFO_CH7                 = 0x07,
    CAN_RXCODE_FIFO_CH8                 = 0x08,
    CAN_RXCODE_FIFO_CH9                 = 0x09,
    CAN_RXCODE_FIFO_CH10                = 0x0A,
    CAN_RXCODE_FIFO_CH11                = 0x0B,
    CAN_RXCODE_FIFO_CH12                = 0x0C,
    CAN_RXCODE_FIFO_CH13                = 0x0D,
    CAN_RXCODE_FIFO_CH14                = 0x0E,
    CAN_RXCODE_FIFO_CH15                = 0x0F,
    CAN_RXCODE_FIFO_CH16                = 0x10,
    CAN_RXCODE_FIFO_CH17                = 0x11,
    CAN_RXCODE_FIFO_CH18                = 0x12,
    CAN_RXCODE_FIFO_CH19                = 0x13,
    CAN_RXCODE_FIFO_CH20                = 0x14,
    CAN_RXCODE_FIFO_CH21                = 0x15,
    CAN_RXCODE_FIFO_CH22                = 0x16,
    CAN_RXCODE_FIFO_CH23                = 0x17,
    CAN_RXCODE_FIFO_CH24                = 0x18,
    CAN_RXCODE_FIFO_CH25                = 0x19,
    CAN_RXCODE_FIFO_CH26                = 0x1A,
    CAN_RXCODE_FIFO_CH27                = 0x1B,
    CAN_RXCODE_FIFO_CH28                = 0x1C,
    CAN_RXCODE_FIFO_CH29                = 0x1D,
    CAN_RXCODE_FIFO_CH30                = 0x1E,
    CAN_RXCODE_FIFO_CH31                = 0x1F,
    CAN_RXCODE_TOTAL_CHANNELS           = 0x20,
    CAN_RXCODE_NO_INT                   = 0x40,
    CAN_RXCODE_RESERVED                 = 0x41,
} CAN_RXCODE;

//! TXCODE

typedef enum {
    CAN_TXCODE_FIFO_CH0                 = 0x00,
    CAN_TXCODE_FIFO_CH1                 = 0x01,
    CAN_TXCODE_FIFO_CH2                 = 0x02,
    CAN_TXCODE_FIFO_CH3                 = 0x03,
    CAN_TXCODE_FIFO_CH4                 = 0x04,
    CAN_TXCODE_FIFO_CH5                 = 0x05,
    CAN_TXCODE_FIFO_CH6                 = 0x06,
    CAN_TXCODE_FIFO_CH7                 = 0x07,
    CAN_TXCODE_FIFO_CH8                 = 0x08,
    CAN_TXCODE_FIFO_CH9                 = 0x09,
    CAN_TXCODE_FIFO_CH10                = 0x0A,
    CAN_TXCODE_FIFO_CH11                = 0x0B,
    CAN_TXCODE_FIFO_CH12                = 0x0C,
    CAN_TXCODE_FIFO_CH13                = 0x0D,
    CAN_TXCODE_FIFO_CH14                = 0x0E,
    CAN_TXCODE_FIFO_CH15                = 0x0F,
    CAN_TXCODE_FIFO_CH16                = 0x10,
    CAN_TXCODE_FIFO_CH17                = 0x11,
    CAN_TXCODE_FIFO_CH18                = 0x12,
    CAN_TXCODE_FIFO_CH19                = 0x13,
    CAN_TXCODE_FIFO_CH20                = 0x14,
    CAN_TXCODE_FIFO_CH21                = 0x15,
    CAN_TXCODE_FIFO_CH22                = 0x16,
    CAN_TXCODE_FIFO_CH23                = 0x17,
    CAN_TXCODE_FIFO_CH24                = 0x18,
    CAN_TXCODE_FIFO_CH25                = 0x19,
    CAN_TXCODE_FIFO_CH26                = 0x1A,
    CAN_TXCODE_FIFO_CH27                = 0x1B,
    CAN_TXCODE_FIFO_CH28                = 0x1C,
    CAN_TXCODE_FIFO_CH29                = 0x1D,
    CAN_TXCODE_FIFO_CH30                = 0x1E,
    CAN_TXCODE_FIFO_CH31                = 0x1F,
    CAN_TXCODE_TOTAL_CHANNELS           = 0x20,
    CAN_TXCODE_NO_INT                   = 0x40,
    CAN_TXCODE_RESERVED                 = 0x41
} CAN_TXCODE;

//! System Clock Selection

typedef enum {
    CAN_SYSCLK_40M,
    CAN_SYSCLK_20M,
    CAN_SYSCLK_10M
} CAN_SYSCLK_SPEED;

//! CLKO Divide

typedef enum {
    OSC_CLKO_DIV1,
    OSC_CLKO_DIV2,
    OSC_CLKO_DIV4,
    OSC_CLKO_DIV10
} OSC_CLKO_DIVIDE;

#endif // _DRV_CANFDSPI_DEFINES_H