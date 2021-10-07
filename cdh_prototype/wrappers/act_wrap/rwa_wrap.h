
// rwa_wrap.h


#ifndef ACTUATOR_WRAP_RWA_WRAP_H_
#define ACTUATOR_WRAP_RWA_WRAP_H_


#define ARDUINO_CODE     			0
#define WHEELS_INDEPANDANT 			1

#if ARDUINO_CODE
  #include <Arduino.h>
  #include <SPI.h>
#else
  //#include "fsl_lpspi.c"
  //#include "fsl_lpspi_freertos.h"
  #include "peripherals.h"
#endif

// set timeout between request and reply (milliseconds)
#define SPI_TIMEOUT 20

#if ARDUINO_CODE
SPISettings spiSet(125000, MSBFIRST, SPI_MODE0); // SPI driver is initialized
// assigns GPIO pins to be SS pins (Arduino only)
#define SS1 3
#define SS2 4
#define SS3 5
#define SS4 6
// assigns GPIO pins to be EN pins (Arduino only)
#define EN1 A1
#define EN2 A2
#define EN3 A3
#define EN4 A4
#else
// assigns GPIO pins
#define SS1 RWA0
#define SS2 RWA1
#define SS3 RWA2
#define SS4 RWA3
#endif

#define MAX_REQ_PAYLOAD 6 + 1     // N_max = 6 plus comID
#define MAX_REQ_PACKET 2*(MAX_REQ_PAYLOAD + 2) + 2   // adds CRC, doubles for max XOR, adds flags
#define MAX_RPL_PAYLOAD 10 + 2    // N_max = 10 plus comID and result
#define MAX_RPL_PACKET 2*(MAX_RPL_PAYLOAD + 2) + 2    // adds CRC, doubles for max XOR, adds flags

#define CRC_VAL (uint16_t)0xFFFF

typedef struct rw_data
{
    int16_t time_N;
    uint8_t result;
    uint16_t rampTime;
    int32_t reqSpeed;
    double reqSpeed_double;
    int32_t currSpeed;
    double currSpeed_double;
    int32_t refSpeed;
    uint8_t state;
    uint8_t reqClcMode;
    uint8_t currClcMode;
    uint8_t lastResetStatus;
    int32_t mcuTemp;
    float presSensTemp;
    float pressure;

//    uint32_t numOfInvalidCrcPackets;
//    uint32_t numOfInvalidLenPackets;
//    uint32_t numOfInvalidCmdPackets;
//    uint32_t numOfCmdExecutedRequests;
//    uint32_t numOfCmdReplies;
//    uint32_t uartNumOfBytesWritten;
//    uint32_t uartNumOfBytesRead;
//    uint32_t uartNumOfParityErrors;
//    uint32_t uartNumOfNoiseErrors;
//    uint32_t uartNumOfFrameErrors;
//    uint32_t uartNumOfRegisterOverrunErrors;
//    uint32_t uartTotalNumOfErrors;
//    uint32_t spiNumOfBytesWritten;
//    uint32_t spiNumOfBytesRead;
//    uint32_t spiNumOfRegisterOverrunErrors;
//    uint32_t spiTotalNumOfErrors;
//    uint32_t versionMajor;
//    uint32_t versionBuildNumber;
//    uint32_t uid1;
//    uint32_t uid2;
//    uint32_t uid3;
} rw_data_t;

#if WHEELS_INDEPANDANT
extern rw_data_t rw1, rw2, rw3, rw4;   // saving SRAM
#else
extern struct rw_data rw1;
#endif

// test only
extern bool debug_mode;
extern int16_t time_0;


void reqPacketProcess(uint8_t *req_payload_pt, uint8_t *req_packet_pt, uint8_t *req_payload_len_pt, uint8_t *req_packet_len_pt);
void reqSpiTransfer(uint8_t *req_packet_pt, uint8_t *req_packet_len_pt, uint8_t SS_id);
void rplSpiTransfer(uint8_t *rpl_packet_pt, uint8_t *rpl_packet_len_pt, uint8_t SS_id);
void rplPacketProcess(uint8_t *rpl_payload_pt, uint8_t *rpl_packet_pt, uint8_t *rpl_payload_len_pt, uint8_t *rpl_packet_len_pt);
void reqPayloadWrite_cmd4(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt);
void rplPayloadRead_cmd4(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt);
void reqPayloadWrite_cmd6(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt);
void rplPayloadRead_cmd6(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt);
void reqPayloadWrite_cmd7(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt);
void rplPayloadRead_cmd7(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt);
void reqPayloadWrite_cmd10(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt);
void rplPayloadRead_cmd10(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt);
void commandAll(uint8_t com_id);


#endif /* ACTUATOR_WRAP_RWA_WRAP_H_ */


