#ifndef _CANFD_API_H
#define _CANFD_API_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "defines.h"
#include "registers.h"

#define SPI_DEFAULT_BUFFER_LENGTH 96

typedef uint8_t CANFDSPI_MODULE_ID;

int8_t CANFD_Reset                                           (CANFDSPI_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: SPI Access Functions

int8_t CANFD_ReadByteArray                                   (CANFDSPI_MODULE_ID index, uint16_t address, uint8_t  *rxd, uint16_t nBytes);
int8_t CANFD_WriteByteArray                                  (CANFDSPI_MODULE_ID index, uint16_t address, uint8_t  *txd, uint16_t nBytes);
int8_t CANFD_ReadByteArrayWithCRC                            (CANFDSPI_MODULE_ID index, uint16_t address, uint8_t  *rxd, uint16_t nBytes, bool fromRam, bool* crcIsCorrect);
int8_t CANFD_WriteByteArrayWithCRC                           (CANFDSPI_MODULE_ID index, uint16_t address, uint8_t  *txd, uint16_t nBytes, bool fromRam);
int8_t CANFD_ReadWordArray                                   (CANFDSPI_MODULE_ID index, uint16_t address, uint32_t *rxd, uint16_t nWords);
int8_t CANFD_WriteWordArray                                  (CANFDSPI_MODULE_ID index, uint16_t address, uint32_t *txd, uint16_t nWords);
int8_t CANFD_ReadByte                                        (CANFDSPI_MODULE_ID index, uint16_t address, uint8_t  *rxd);
int8_t CANFD_WriteByte                                       (CANFDSPI_MODULE_ID index, uint16_t address, uint8_t   txd);
int8_t CANFD_ReadWord                                        (CANFDSPI_MODULE_ID index, uint16_t address, uint32_t *rxd);
int8_t CANFD_WriteWord                                       (CANFDSPI_MODULE_ID index, uint16_t address, uint32_t  txd);
int8_t CANFD_ReadHalfWord                                    (CANFDSPI_MODULE_ID index, uint16_t address, uint16_t *rxd);
int8_t CANFD_WriteHalfWord                                   (CANFDSPI_MODULE_ID index, uint16_t address, uint16_t  txd);
int8_t CANFD_WriteByteSafe                                   (CANFDSPI_MODULE_ID index, uint16_t address, uint8_t   txd);
int8_t CANFD_WriteWordSafe                                   (CANFDSPI_MODULE_ID index, uint16_t address, uint32_t  txd);


// *****************************************************************************
// *****************************************************************************
// Section: Configuration
int8_t CANFD_Configure                                       (CANFDSPI_MODULE_ID index, CAN_CONFIG* config);
int8_t CANFD_ConfigureObjectReset                            (                          CAN_CONFIG* config);


// *****************************************************************************
// *****************************************************************************
// Section: Operating mode
int8_t CANFD_OperationModeSelect                             (CANFDSPI_MODULE_ID index, CAN_OPERATION_MODE opMode);
CAN_OPERATION_MODE CANFD_OperationModeGet                    (CANFDSPI_MODULE_ID index);
int8_t CANFD_LowPowerModeEnable                              (CANFDSPI_MODULE_ID index);
int8_t CANFD_LowPowerModeDisable                             (CANFDSPI_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: CAN Transmit

int8_t CANFD_TransmitChannelLoad                             (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_TX_MSGOBJ* txObj, uint8_t *txd, uint32_t txdNumBytes, bool flush);
int8_t CANFD_TransmitChannelConfigure                        (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_TX_FIFO_CONFIG*  config);
int8_t CANFD_TransmitChannelStatusGet                        (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_TX_FIFO_STATUS*  status);
int8_t CANFD_TransmitChannelConfigureObjectReset             (                                                    CAN_TX_FIFO_CONFIG*  config);
int8_t CANFD_TransmitQueueConfigure                          (CANFDSPI_MODULE_ID index,                           CAN_TX_QUEUE_CONFIG* config);
int8_t CANFD_TransmitQueueConfigureObjectReset               (                                                    CAN_TX_QUEUE_CONFIG* config);
int8_t CANFD_TransmitChannelUpdate                           (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, bool flush);
int8_t CANFD_TransmitBandWidthSharingSet                     (CANFDSPI_MODULE_ID index, CAN_TX_BANDWITH_SHARING txbws);
int8_t CANFD_TransmitRequestSet                              (CANFDSPI_MODULE_ID index, CAN_TXREQ_CHANNEL  txreq);
int8_t CANFD_TransmitChannelFlush                            (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel);
int8_t CANFD_TransmitChannelReset                            (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel);
int8_t CANFD_TransmitChannelAbort                            (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel);
int8_t CANFD_TransmitRequestGet                              (CANFDSPI_MODULE_ID index, uint32_t*          txreq);
int8_t CANFD_TransmitAbortAll                                (CANFDSPI_MODULE_ID index);
static inline int8_t CANFD_TransmitQueueAbort                (CANFDSPI_MODULE_ID index)
{
  return CANFD_TransmitChannelAbort(index, CAN_TXQUEUE_CH0);
}
static inline int8_t CANFD_TransmitQueueLoad                 (CANFDSPI_MODULE_ID index, CAN_TX_MSGOBJ* txObj, uint8_t *txd, uint32_t txdNumBytes, bool flush)
{
  return CANFD_TransmitChannelLoad(index, CAN_TXQUEUE_CH0, txObj, txd, txdNumBytes, flush);
}
static inline int8_t CANFD_TransmitQueueFlush                (CANFDSPI_MODULE_ID index)
{
    return CANFD_TransmitChannelFlush(index, CAN_TXQUEUE_CH0);
}
static inline int8_t CANFD_TransmitQueueStatusGet            (CANFDSPI_MODULE_ID index, CAN_TX_FIFO_STATUS* status)
{
    return CANFD_TransmitChannelStatusGet(index, CAN_TXQUEUE_CH0, status);
}
static inline int8_t CANFD_TransmitQueueReset                (CANFDSPI_MODULE_ID index)
{
    return CANFD_TransmitChannelReset(index, CAN_TXQUEUE_CH0);
}
static inline int8_t CANFD_TransmitQueueUpdate               (CANFDSPI_MODULE_ID index, bool flush)
{
    return CANFD_TransmitChannelUpdate(index, CAN_TXQUEUE_CH0, flush);
}


// *****************************************************************************
// *****************************************************************************
// Section: CAN Receive

int8_t    CANFD_FilterObjectConfigure                        (CANFDSPI_MODULE_ID index, CAN_FILTER filter, CAN_FILTEROBJ_ID* id);
int8_t    CANFD_FilterMaskConfigure                          (CANFDSPI_MODULE_ID index, CAN_FILTER filter, CAN_MASKOBJ_ID* mask);
int8_t    CANFD_FilterToFifoLink                             (CANFDSPI_MODULE_ID index, CAN_FILTER filter, CAN_FIFO_CHANNEL channel, bool enable);
int8_t    CANFD_FilterEnable                                 (CANFDSPI_MODULE_ID index, CAN_FILTER filter);
int8_t    CANFD_FilterDisable                                (CANFDSPI_MODULE_ID index, CAN_FILTER filter);
int8_t    CANFD_DeviceNetFilterCountSet                      (CANFDSPI_MODULE_ID index, CAN_DNET_FILTER_SIZE dnfc);
int8_t    CANFD_ReceiveChannelConfigure                      (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel,  CAN_RX_FIFO_CONFIG* config);
int8_t    CANFD_ReceiveChannelConfigureObjectReset           (                                                     CAN_RX_FIFO_CONFIG* config);
int8_t    CANFD_ReceiveChannelStatusGet                      (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_RX_FIFO_STATUS* status);
int8_t    CANFD_ReceiveMessageGet                            (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_RX_MSGOBJ* rxObj, uint8_t *rxd, uint8_t nBytes);
int8_t    CANFD_ReceiveChannelReset                          (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel);
int8_t    CANFD_ReceiveChannelUpdate                         (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel);


// *****************************************************************************
// *****************************************************************************
// Section: Transmit Event FIFO

int8_t    CANFD_TefStatusGet                                 (CANFDSPI_MODULE_ID index, CAN_TEF_FIFO_STATUS* status);
int8_t    CANFD_TefMessageGet                                (CANFDSPI_MODULE_ID index, CAN_TEF_MSGOBJ* tefObj);
int8_t    CANFD_TefConfigure                                 (CANFDSPI_MODULE_ID index, CAN_TEF_CONFIG* config);
int8_t    CANFD_TefConfigureObjectReset                      (                          CAN_TEF_CONFIG* config);
int8_t    CANFD_TefReset                                     (CANFDSPI_MODULE_ID index);
int8_t    CANFD_TefUpdate                                    (CANFDSPI_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: Module Events

int8_t    CANFD_ModuleEventGet                               (CANFDSPI_MODULE_ID index, CAN_MODULE_EVENT* flags);
int8_t    CANFD_ModuleEventEnable                            (CANFDSPI_MODULE_ID index, CAN_MODULE_EVENT  flags);
int8_t    CANFD_ModuleEventDisable                           (CANFDSPI_MODULE_ID index, CAN_MODULE_EVENT  flags);
int8_t    CANFD_ModuleEventClear                             (CANFDSPI_MODULE_ID index, CAN_MODULE_EVENT  flags);
int8_t    CANFD_ModuleEventFilterHitGet                      (CANFDSPI_MODULE_ID index, CAN_FILTER* filterHit);
int8_t    CANFD_ModuleEventRxCodeGet                         (CANFDSPI_MODULE_ID index, CAN_RXCODE* rxCode);
int8_t    CANFD_ModuleEventTxCodeGet                         (CANFDSPI_MODULE_ID index, CAN_TXCODE* txCode);
int8_t    CANFD_ModuleEventIcodeGet                          (CANFDSPI_MODULE_ID index, CAN_ICODE* icode);

// *****************************************************************************
// *****************************************************************************
// Section: Transmit FIFO Events

int8_t    CANFD_TransmitEventGet                             (CANFDSPI_MODULE_ID index, uint32_t* txif);
int8_t    CANFD_TransmitEventAttemptGet                      (CANFDSPI_MODULE_ID index, uint32_t* txatif);
int8_t    CANFD_TransmitChannelIndexGet                      (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, uint8_t* idx);
int8_t    CANFD_TransmitChannelEventGet                      (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_TX_FIFO_EVENT* flags);
int8_t    CANFD_TransmitChannelEventEnable                   (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_TX_FIFO_EVENT  flags);
int8_t    CANFD_TransmitChannelEventDisable                  (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_TX_FIFO_EVENT  flags);
int8_t    CANFD_TransmitChannelEventAttemptClear             (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel);
static inline int8_t CANFD_TransmitQueueIndexGet             (CANFDSPI_MODULE_ID index,                           uint8_t* idx)
{
  return CANFD_TransmitChannelIndexGet(index, CAN_TXQUEUE_CH0, idx);
}
static inline int8_t CANFD_TransmitQueueEventEnable          (CANFDSPI_MODULE_ID index,                           CAN_TX_FIFO_EVENT  flags)
{
    return CANFD_TransmitChannelEventEnable(index, CAN_TXQUEUE_CH0, flags);
}
static inline int8_t CANFD_TransmitQueueEventDisable         (CANFDSPI_MODULE_ID index,                           CAN_TX_FIFO_EVENT  flags)
{
    return CANFD_TransmitChannelEventDisable(index, CAN_TXQUEUE_CH0, flags);
}
static inline int8_t CANFD_TransmitQueueEventGet             (CANFDSPI_MODULE_ID index,                           CAN_TX_FIFO_EVENT* flags)
{
    return CANFD_TransmitChannelEventGet(index, CAN_TXQUEUE_CH0, flags);
}
static inline int8_t CANFD_TransmitQueueEventAttemptClear    (CANFDSPI_MODULE_ID index)
{
    return CANFD_TransmitChannelEventAttemptClear(index, CAN_TXQUEUE_CH0);
}

// *****************************************************************************
// *****************************************************************************
// Section: Receive FIFO Events

int8_t    CANFD_ReceiveChannelEventGet                       (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_RX_FIFO_EVENT* flags);
int8_t    CANFD_ReceiveChannelEventEnable                    (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_RX_FIFO_EVENT  flags);
int8_t    CANFD_ReceiveChannelEventDisable                   (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, CAN_RX_FIFO_EVENT  flags);
int8_t    CANFD_ReceiveChannelIndexGet                       (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, uint8_t* idx);
int8_t    CANFD_ReceiveChannelEventOverflowClear             (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel);
int8_t    CANFD_ReceiveEventOverflowGet                      (CANFDSPI_MODULE_ID index, uint32_t* rxovif);
int8_t    CANFD_ReceiveEventGet                              (CANFDSPI_MODULE_ID index, uint32_t* rxif);


// *****************************************************************************
// *****************************************************************************
// Section: Transmit Event FIFO Events

int8_t    CANFD_TefEventGet                                  (CANFDSPI_MODULE_ID index, CAN_TEF_FIFO_EVENT* flags);
int8_t    CANFD_TefEventEnable                               (CANFDSPI_MODULE_ID index, CAN_TEF_FIFO_EVENT  flags);
int8_t    CANFD_TefEventDisable                              (CANFDSPI_MODULE_ID index, CAN_TEF_FIFO_EVENT  flags);
int8_t    CANFD_TefEventOverflowClear                        (CANFDSPI_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: Error Handling

int8_t    CANFD_ErrorCountStateGet                           (CANFDSPI_MODULE_ID index, uint8_t* tec, uint8_t* rec,  CAN_ERROR_STATE* flags);
int8_t    CANFD_ErrorStateGet                                (CANFDSPI_MODULE_ID index,                              CAN_ERROR_STATE* flags);
int8_t    CANFD_ErrorCountReceiveGet                         (CANFDSPI_MODULE_ID index,               uint8_t* rec);
int8_t    CANFD_ErrorCountTransmitGet                        (CANFDSPI_MODULE_ID index, uint8_t* tec);
int8_t    CANFD_BusDiagnosticsGet                            (CANFDSPI_MODULE_ID index, CAN_BUS_DIAGNOSTIC* bd);
int8_t    CANFD_BusDiagnosticsClear                          (CANFDSPI_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: ECC

int8_t    CANFD_EccEventGet                                  (CANFDSPI_MODULE_ID index, CAN_ECC_EVENT* flags);
int8_t    CANFD_EccEventEnable                               (CANFDSPI_MODULE_ID index, CAN_ECC_EVENT  flags);
int8_t    CANFD_EccEventDisable                              (CANFDSPI_MODULE_ID index, CAN_ECC_EVENT  flags);
int8_t    CANFD_EccEventClear                                (CANFDSPI_MODULE_ID index, CAN_ECC_EVENT  flags);
int8_t    CANFD_EccParitySet                                 (CANFDSPI_MODULE_ID index, uint8_t   parity);
int8_t    CANFD_EccParityGet                                 (CANFDSPI_MODULE_ID index, uint8_t  *parity);
int8_t    CANFD_EccErrorAddressGet                           (CANFDSPI_MODULE_ID index, uint16_t *a);
int8_t    CANFD_RamInit                                      (CANFDSPI_MODULE_ID index, uint8_t   d);
int8_t    CANFD_EccEnable                                    (CANFDSPI_MODULE_ID index);
int8_t    CANFD_EccDisable                                   (CANFDSPI_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: CRC

int8_t    CANFD_CrcEventEnable                               (CANFDSPI_MODULE_ID index, CAN_CRC_EVENT  flags);
int8_t    CANFD_CrcEventDisable                              (CANFDSPI_MODULE_ID index, CAN_CRC_EVENT  flags);
int8_t    CANFD_CrcEventClear                                (CANFDSPI_MODULE_ID index, CAN_CRC_EVENT  flags);
int8_t    CANFD_CrcEventGet                                  (CANFDSPI_MODULE_ID index, CAN_CRC_EVENT* flags);
int8_t    CANFD_CrcValueGet                                  (CANFDSPI_MODULE_ID index, uint16_t* crc);


// *****************************************************************************
// *****************************************************************************
// Section: Time Stamp

int8_t    CANFD_TimeStampModeConfigure                       (CANFDSPI_MODULE_ID index, CAN_TS_MODE mode);
int8_t    CANFD_TimeStampGet                                 (CANFDSPI_MODULE_ID index, uint32_t* ts);
int8_t    CANFD_TimeStampSet                                 (CANFDSPI_MODULE_ID index, uint32_t  ts);
int8_t    CANFD_TimeStampPrescalerSet                        (CANFDSPI_MODULE_ID index, uint16_t  ps);
int8_t    CANFD_TimeStampEnable                              (CANFDSPI_MODULE_ID index);
int8_t    CANFD_TimeStampDisable                             (CANFDSPI_MODULE_ID index);


// *****************************************************************************
// *****************************************************************************
// Section: Oscillator and Bit Time

int8_t    CANFD_BitTimeConfigure                             (CANFDSPI_MODULE_ID index, CAN_BITTIME_SETUP bitTime, CAN_SSP_MODE sspMode, CAN_SYSCLK_SPEED clk);
int8_t    CANFD_BitTimeConfigureData40MHz                    (CANFDSPI_MODULE_ID index, CAN_BITTIME_SETUP bitTime, CAN_SSP_MODE sspMode);
int8_t    CANFD_BitTimeConfigureData20MHz                    (CANFDSPI_MODULE_ID index, CAN_BITTIME_SETUP bitTime, CAN_SSP_MODE sspMode);
int8_t    CANFD_BitTimeConfigureData10MHz                    (CANFDSPI_MODULE_ID index, CAN_BITTIME_SETUP bitTime, CAN_SSP_MODE sspMode);
int8_t    CANFD_BitTimeConfigureNominal40MHz                 (CANFDSPI_MODULE_ID index, CAN_BITTIME_SETUP bitTime);
int8_t    CANFD_BitTimeConfigureNominal20MHz                 (CANFDSPI_MODULE_ID index, CAN_BITTIME_SETUP bitTime);
int8_t    CANFD_BitTimeConfigureNominal10MHz                 (CANFDSPI_MODULE_ID index, CAN_BITTIME_SETUP bitTime);
int8_t    CANFD_OscillatorStatusGet                          (CANFDSPI_MODULE_ID index, CAN_OSC_STATUS* status);
int8_t    CANFD_OscillatorControlSet                         (CANFDSPI_MODULE_ID index, CAN_OSC_CTRL ctrl);
int8_t    CANFD_OscillatorEnable                             (CANFDSPI_MODULE_ID index);
int8_t    CANFD_OscillatorControlObjectReset                 (CAN_OSC_CTRL* ctrl);


// *****************************************************************************
// *****************************************************************************
// Section: GPIO

int8_t    CANFD_GpioModeConfigure                            (CANFDSPI_MODULE_ID index, GPIO_PIN_MODE gpio0, GPIO_PIN_MODE gpio1);
int8_t    CANFD_GpioDirectionConfigure                       (CANFDSPI_MODULE_ID index, GPIO_PIN_DIRECTION gpio0, GPIO_PIN_DIRECTION gpio1);
int8_t    CANFD_GpioStandbyControlEnable                     (CANFDSPI_MODULE_ID index);
int8_t    CANFD_GpioStandbyControlDisable                    (CANFDSPI_MODULE_ID index);
int8_t    CANFD_GpioInterruptPinsOpenDrainConfigure          (CANFDSPI_MODULE_ID index, GPIO_OPEN_DRAIN_MODE mode);
int8_t    CANFD_GpioTransmitPinOpenDrainConfigure            (CANFDSPI_MODULE_ID index, GPIO_OPEN_DRAIN_MODE mode);
int8_t    CANFD_GpioPinSet                                   (CANFDSPI_MODULE_ID index, GPIO_PIN_POS pos, GPIO_PIN_STATE  latch);
int8_t    CANFD_GpioPinRead                                  (CANFDSPI_MODULE_ID index, GPIO_PIN_POS pos, GPIO_PIN_STATE* state);
int8_t    CANFD_GpioClockOutputConfigure                     (CANFDSPI_MODULE_ID index, GPIO_CLKO_MODE mode);


// *****************************************************************************
// *****************************************************************************
// Section: Miscellaneous

uint32_t  CANFD_DlcToDataBytes                               (CAN_DLC dlc);
int8_t    CANFD_FifoIndexGet                                 (CANFDSPI_MODULE_ID index, CAN_FIFO_CHANNEL channel, uint8_t* mi);
uint16_t  CANFD_CalculateCRC16                               (uint8_t* data, uint16_t size);
CAN_DLC   CANFD_DataBytesToDlc                               (uint8_t n);

#endif