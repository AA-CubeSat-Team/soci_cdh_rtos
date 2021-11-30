
// rwa_wrap.c


#include "rwa_wrap.h"
#if ARDUINO_CODE
#include <Arduino.h>
#endif


#if WHEELS_INDEPANDANT
rw_data_t rw1, rw2, rw3, rw4;    // saving SRAM
#else
rw_data rw1;
#endif

void reqPacketProcess(uint8_t *req_payload_pt, uint8_t *req_packet_pt, uint8_t *req_payload_len_pt, uint8_t *req_packet_len_pt) { // --- --- --- --- --- --- --- --- ---
  uint8_t req_array_A[MAX_REQ_PACKET] = {0}; // need to allocate max possible size of uint8_t
  uint8_t req_array_B[MAX_REQ_PACKET] = {0};
  uint8_t req_array_C[MAX_REQ_PACKET] = {0};
  uint8_t req_array_D[MAX_REQ_PACKET] = {0};
  uint8_t req_array_E[MAX_REQ_PACKET] = {0};
  uint8_t req_len_A;
  uint8_t req_len_B;
  uint8_t req_len_C;
  uint8_t req_len_D;
  uint8_t req_len_E;
  uint16_t crc_table[] = {0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
                          0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
                          0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
                          0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
                          0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
                          0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
                          0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
                          0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
                          0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
                          0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
                          0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
                          0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
                          0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
                          0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
                          0x7E97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
                          0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
                          0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
                          0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
                          0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
                          0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
                          0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
                          0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
                          0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
                          0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
                          0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
                          0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
                          0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
                          0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
                          0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
                          0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
                          0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
                          0x6e17, 0x7E36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
                          };

  uint8_t ii;

  for (ii = 0; ii < 14; ii++) {
    *(req_packet_pt+ii) = 0;
  }
  *req_packet_len_pt = 0;

  // buf to A – copying variable array (WORKS)
  for (ii = 0; ii < *req_payload_len_pt; ii++) {
    req_array_A[ii] = *(req_payload_pt + ii);
  }
  req_len_A = *req_payload_len_pt;

        // A to B – adding two CRC uint8_t s to end of array (ISSUE)
        uint8_t req_crc[2] = {0};
        uint16_t crc_value = CRC_VAL;

        for (ii = 0; ii < req_len_A; ii++) {
          crc_value = ((crc_value << 8) ^ crc_table[((crc_value >> 8) ^ req_array_A[ii]) & 0x00FF]);
        }
        req_crc[0] = crc_value & 0xFF;
        req_crc[1] = crc_value >> 8;

        for (ii = 0; ii < req_len_A; ii++) {
          req_array_B[ii] = req_array_A[ii];
        }
        req_array_B[req_len_A] = req_crc[0];
        req_array_B[req_len_A + 1] = req_crc[1];
        req_len_B = req_len_A + 2;

  // B to C – checking for 0x7D uint8_t s (WORKS)
  uint8_t fnd;
  fnd = 0;

  for (ii = 0; ii < req_len_B; ii++) {
    if (req_array_B[ii] != 0x7D) {
      req_array_C[ii + fnd] = req_array_B[ii];
    }
    if (req_array_B[ii] == 0x7D) {
      req_array_C[ii + fnd] = 0x7D;
      req_array_C[ii + fnd + 1] = req_array_B[ii] ^ 0x20;
      fnd++;
    }
  }
  req_len_C = req_len_B + fnd;

  // C to D – checking for 0x7E uint8_t s (WORKS)
  fnd = 0;

  for (ii = 0; ii < req_len_C; ii++) {
    if (req_array_C[ii] != 0x7E) {
      req_array_D[ii + fnd] = req_array_C[ii];
    }
    if (req_array_C[ii] == 0x7E) {
      req_array_D[ii + fnd] = 0x7D;
      req_array_D[ii + fnd + 1] = req_array_C[ii] ^ 0x20;
      fnd++;
    }
  }
  req_len_D = req_len_C + fnd;

  // D to E – adding 0x7E uint8_t s to front and back of array (WORKS)
  for (ii = 0; ii < req_len_D; ii++) {
    req_array_E[ii + 1] = req_array_D[ii];
  }
  req_array_E[0] = 0x7E;
  req_array_E[req_len_D + 1] = 0x7E;
  req_len_E = req_len_D + 2;

  // assigning to packet array
  for (ii = 0; ii < req_len_E; ii++) {
    *(req_packet_pt+ii) = req_array_E[ii];
  }
  *req_packet_len_pt = req_len_E;
}

void reqSpiTransfer(uint8_t *req_packet_pt, uint8_t *req_packet_len_pt, uint8_t SS_id)
{
  uint8_t tx_buffer[MAX_REQ_PACKET] = {0};

  for (int ii = 0; ii < *req_packet_len_pt; ii++) {
    tx_buffer[ii] = *(req_packet_pt+ii);
  }

  //  defining placeholder for buffer not in use during request
  uint8_t rx_buffer[MAX_REQ_PACKET] = {0};

  for (int jj = 0; jj < MAX_REQ_PACKET; jj++) {
    rx_buffer[jj] = 0x7A;
  }

  // Arduino SPI driver format
  #if ARDUINO_CODE
  SPI.beginTransaction(spiSet);
  digitalWrite(SS_id, LOW);
  SPI.transfer(tx_buffer, *req_packet_len_pt);
  digitalWrite(SS_id, HIGH);
  SPI.endTransaction();

  // DevBoard SPI driver format: SPI_transfer(uint8_t *txBuffer, uint8_t *rxBuffer, size_t transferSize, uint32_t pcsPin)
  #else
  SPI_transfer(tx_buffer, rx_buffer, req_packet_len_pt, SS_id);     // pcsPin for req_packet must be a struct defined in the .h file
  #endif
}

void rplSpiTransfer(uint8_t *rpl_packet_pt, uint8_t *rpl_packet_len_pt, uint8_t SS_id)
{
  uint8_t rx_buffer[MAX_RPL_PACKET] = {0};
  uint8_t tx_buffer[MAX_RPL_PACKET] = {0};

  for (int ii = 0; ii < MAX_RPL_PACKET; ii++) {
    rx_buffer[ii] = 0x7E;
    tx_buffer[ii] = 0x7B;
  }

  //  Arduino SPI Driver format
  #if ARDUINO_CODE
  SPI.beginTransaction(spiSet);
  digitalWrite(SS_id, LOW);
  SPI.transfer(spi_buffer, *rpl_packet_len_pt);
  digitalWrite(SS_id, HIGH);
  SPI.endTransaction();
  #else
  SPI_transfer(tx_buffer, rx_buffer, rpl_packet_len_pt, SS_id);
  #endif

  for (int ii = 0; ii < *rpl_packet_len_pt; ii++) {
    *(rpl_packet_pt+ii) = rx_buffer[ii];
  }
}

void rplPacketProcess(uint8_t *rpl_payload_pt, uint8_t *rpl_packet_pt, uint8_t *rpl_payload_len_pt, uint8_t *rpl_packet_len_pt) { //(NEEDS WORK) --- --- --- --- --- --- --- --- ---
  uint8_t rpl_array_Z[MAX_RPL_PACKET] = {0};
  uint8_t rpl_array_Y[MAX_RPL_PACKET] = {0};
  uint8_t rpl_array_X[MAX_RPL_PACKET] = {0};
  uint8_t rpl_array_W[MAX_RPL_PACKET] = {0};
  uint8_t rpl_len_Z;
  uint8_t rpl_len_Y;
  uint8_t rpl_len_X;
  uint8_t rpl_len_W;
  uint16_t crc_table[] = {0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50a5, 0x60c6, 0x70e7,
                          0x8108, 0x9129, 0xa14a, 0xb16b, 0xc18c, 0xd1ad, 0xe1ce, 0xf1ef,
                          0x1231, 0x0210, 0x3273, 0x2252, 0x52b5, 0x4294, 0x72f7, 0x62d6,
                          0x9339, 0x8318, 0xb37b, 0xa35a, 0xd3bd, 0xc39c, 0xf3ff, 0xe3de,
                          0x2462, 0x3443, 0x0420, 0x1401, 0x64e6, 0x74c7, 0x44a4, 0x5485,
                          0xa56a, 0xb54b, 0x8528, 0x9509, 0xe5ee, 0xf5cf, 0xc5ac, 0xd58d,
                          0x3653, 0x2672, 0x1611, 0x0630, 0x76d7, 0x66f6, 0x5695, 0x46b4,
                          0xb75b, 0xa77a, 0x9719, 0x8738, 0xf7df, 0xe7fe, 0xd79d, 0xc7bc,
                          0x48c4, 0x58e5, 0x6886, 0x78a7, 0x0840, 0x1861, 0x2802, 0x3823,
                          0xc9cc, 0xd9ed, 0xe98e, 0xf9af, 0x8948, 0x9969, 0xa90a, 0xb92b,
                          0x5af5, 0x4ad4, 0x7ab7, 0x6a96, 0x1a71, 0x0a50, 0x3a33, 0x2a12,
                          0xdbfd, 0xcbdc, 0xfbbf, 0xeb9e, 0x9b79, 0x8b58, 0xbb3b, 0xab1a,
                          0x6ca6, 0x7c87, 0x4ce4, 0x5cc5, 0x2c22, 0x3c03, 0x0c60, 0x1c41,
                          0xedae, 0xfd8f, 0xcdec, 0xddcd, 0xad2a, 0xbd0b, 0x8d68, 0x9d49,
                          0x7E97, 0x6eb6, 0x5ed5, 0x4ef4, 0x3e13, 0x2e32, 0x1e51, 0x0e70,
                          0xff9f, 0xefbe, 0xdfdd, 0xcffc, 0xbf1b, 0xaf3a, 0x9f59, 0x8f78,
                          0x9188, 0x81a9, 0xb1ca, 0xa1eb, 0xd10c, 0xc12d, 0xf14e, 0xe16f,
                          0x1080, 0x00a1, 0x30c2, 0x20e3, 0x5004, 0x4025, 0x7046, 0x6067,
                          0x83b9, 0x9398, 0xa3fb, 0xb3da, 0xc33d, 0xd31c, 0xe37f, 0xf35e,
                          0x02b1, 0x1290, 0x22f3, 0x32d2, 0x4235, 0x5214, 0x6277, 0x7256,
                          0xb5ea, 0xa5cb, 0x95a8, 0x8589, 0xf56e, 0xe54f, 0xd52c, 0xc50d,
                          0x34e2, 0x24c3, 0x14a0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
                          0xa7db, 0xb7fa, 0x8799, 0x97b8, 0xe75f, 0xf77e, 0xc71d, 0xd73c,
                          0x26d3, 0x36f2, 0x0691, 0x16b0, 0x6657, 0x7676, 0x4615, 0x5634,
                          0xd94c, 0xc96d, 0xf90e, 0xe92f, 0x99c8, 0x89e9, 0xb98a, 0xa9ab,
                          0x5844, 0x4865, 0x7806, 0x6827, 0x18c0, 0x08e1, 0x3882, 0x28a3,
                          0xcb7d, 0xdb5c, 0xeb3f, 0xfb1e, 0x8bf9, 0x9bd8, 0xabbb, 0xbb9a,
                          0x4a75, 0x5a54, 0x6a37, 0x7a16, 0x0af1, 0x1ad0, 0x2ab3, 0x3a92,
                          0xfd2e, 0xed0f, 0xdd6c, 0xcd4d, 0xbdaa, 0xad8b, 0x9de8, 0x8dc9,
                          0x7c26, 0x6c07, 0x5c64, 0x4c45, 0x3ca2, 0x2c83, 0x1ce0, 0x0cc1,
                          0xef1f, 0xff3e, 0xcf5d, 0xdf7c, 0xaf9b, 0xbfba, 0x8fd9, 0x9ff8,
                          0x6e17, 0x7E36, 0x4e55, 0x5e74, 0x2e93, 0x3eb2, 0x0ed1, 0x1ef0
                          };

  // copying packet array (WORKS)
  uint8_t ii;

  for (ii = 0; ii < *rpl_packet_len_pt; ii++) {
    rpl_array_Z[ii] = *(rpl_packet_pt + ii);
  }
  rpl_len_Z = *rpl_packet_len_pt;

  // Z to Y – copies request array to new array without frame flags (0x7E) (WORKS)
  uint8_t fnd;
  fnd = 0;

  for (ii = 0; ii < rpl_len_Z; ii++) {
    if (rpl_array_Z[ii] != 0x7E) {
      rpl_array_Y[ii - fnd] = rpl_array_Z[ii];
    }
    if (rpl_array_Z[ii] == 0x7E) {
      fnd++;
    }
  }
  rpl_len_Y = rpl_len_Z - fnd;

  // in case reply is made entirely of flag bytes
  if (fnd == rpl_len_Z){
    for (ii = 0; ii < rpl_len_Z; ii++) {
      *(rpl_payload_pt + ii) = rpl_array_Z[ii];
    }
    *rpl_payload_len_pt = rpl_len_Z;
    return;
  }

  // Y to X – runs reverse XOR process to remove escape bytes (0x7D) from reply array (WORKS)
  fnd = 0;

  for (ii = 0; ii < rpl_len_Y; ii++) {
    if (rpl_array_Y[ii + fnd] != 0x7D) {
      rpl_array_X[ii] = rpl_array_Y[ii + fnd];
    }
    if (rpl_array_Y[ii + fnd] == 0x7D) {
      rpl_array_X[ii] = rpl_array_Y[ii + fnd + 1] ^ 0x20;
      fnd++;
    }
  }
  rpl_len_X = rpl_len_Y - fnd;

  // X to W – removes two CRC uint8_t s from end of array (WORKS)
  for (ii = 0; ii < (rpl_len_X - 2); ii++) {
    rpl_array_W[ii] = rpl_array_X[ii];
  }
  rpl_len_W = rpl_len_X - 2;

  // compares RWA reply CRC with calculated reply CRC (WORKS, need to add flag)
  uint8_t rpl_crc_rwa[] = {rpl_array_X[rpl_len_X - 2], rpl_array_X[rpl_len_X - 1]};

  uint8_t rpl_crc_calc[2] = { };
  uint16_t crc_value = CRC_VAL;

  for (ii = 0; ii < rpl_len_W; ii++) {
    crc_value = ((crc_value << 8) ^ crc_table[((crc_value >> 8) ^ rpl_array_W[ii]) & 0x00FF]);
  }
  rpl_crc_calc[0] = crc_value & 0xFF;
  rpl_crc_calc[1] = crc_value >> 8;

  if (rpl_crc_rwa[0] == rpl_crc_calc[0] && rpl_crc_rwa[1] == rpl_crc_calc[1]) {
//    do something
  }


  // copies to rpl_payload_pt
  for (ii = 0; ii < rpl_len_W; ii++) {
    *(rpl_payload_pt + ii) = rpl_array_W[ii];
  }
  *rpl_payload_len_pt = rpl_len_W;
}

// command 4 - get reaction wheel status --- --- --- --- --- ---
void reqPayloadWrite_cmd4(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt) {
  uint8_t com_id = 4;

  *req_payload_pt = com_id;

  *req_payload_len_pt = 1;
}

void rplPayloadRead_cmd4(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt) {
  // com_id = 4
  // length = 12
  rwX_pt->result = *(rpl_payload_pt+1);

  rwX_pt->currSpeed = (*(rpl_payload_pt+5) << 24) | (*(rpl_payload_pt+4) << 16) | (*(rpl_payload_pt+3) << 8) | *(rpl_payload_pt+2);

  rwX_pt->refSpeed = (*(rpl_payload_pt+9) << 24) | (*(rpl_payload_pt+8) << 16) | (*(rpl_payload_pt+7) << 8) | *(rpl_payload_pt+6);

  rwX_pt->state = *(rpl_payload_pt+10);

  rwX_pt->currClcMode = *(rpl_payload_pt+11);

  // system ID only
  #if ADUINO_CODE
  rwX_pt->time_N = millis() - time_0;
  #endif
}


// command 6 - set reference speed --- --- --- --- --- ---
void reqPayloadWrite_cmd6(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt) {
  uint8_t com_id = 6;

  *req_payload_pt = com_id;

  *(req_payload_pt+1) = rwX_pt->reqSpeed & 0xFF;
  *(req_payload_pt+2) = (rwX_pt->reqSpeed >> 8) & 0xFF;
  *(req_payload_pt+3) = (rwX_pt->reqSpeed >> 16) & 0xFF;
  *(req_payload_pt+4) = (rwX_pt->reqSpeed >> 24) & 0xFF;

  *(req_payload_pt+5) = rwX_pt->rampTime & 0xFF;
  *(req_payload_pt+6) = (rwX_pt->rampTime >> 8) & 0xFF;

  *req_payload_len_pt = 1 + 6;
}

void rplPayloadRead_cmd6(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt) {
  // com_id = 6
  // length = 2
  rwX_pt->result = *(rpl_payload_pt+1);
}


// command 7 - set current limit control mode --- --- --- --- --- ---
void reqPayloadWrite_cmd7(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt) {
  uint8_t com_id = 7;

  *req_payload_pt = com_id;

  *(req_payload_pt+1) = rwX_pt->reqClcMode;

  *req_payload_len_pt = 1 + 1;
}

void rplPayloadRead_cmd7(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt) {
  // com_id = 7
  // length = 2
  rwX_pt->result = *(rpl_payload_pt+1);
}


// command 10 - ping --- --- --- --- --- ---
void reqPayloadWrite_cmd10(uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt) {
  uint8_t com_id = 10;

  *req_payload_pt = com_id;

  *req_payload_len_pt = 1;
}

void rplPayloadRead_cmd10(uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt) {
  // com_id = 10
  // length = 2
  rwX_pt->result = *(rpl_payload_pt+1);
}


void reqPayloadWriteSwitcher(uint8_t com_id, uint8_t *req_payload_pt, uint8_t *req_payload_len_pt, struct rw_data *rwX_pt){
  switch (com_id){
    case 4:
      reqPayloadWrite_cmd4(req_payload_pt, req_payload_len_pt, rwX_pt);
      break;
    case 6:
      reqPayloadWrite_cmd6(req_payload_pt, req_payload_len_pt, rwX_pt);
      break;
    case 7:
      reqPayloadWrite_cmd7(req_payload_pt, req_payload_len_pt, rwX_pt);
      break;
    case 10:
      reqPayloadWrite_cmd10(req_payload_pt, req_payload_len_pt, rwX_pt);
      break;
  }
}

void rplPayloadReadSwitcher(uint8_t com_id, uint8_t *rpl_payload_pt, uint8_t *rpl_payload_len_pt, struct rw_data *rwX_pt){
  switch (com_id){
    case 4:
      rplPayloadRead_cmd4(rpl_payload_pt, rpl_payload_len_pt, rwX_pt);
      break;
    case 6:
      rplPayloadRead_cmd6(rpl_payload_pt, rpl_payload_len_pt, rwX_pt);
      break;
    case 7:
      rplPayloadRead_cmd7(rpl_payload_pt, rpl_payload_len_pt, rwX_pt);
      break;
    case 10:
      rplPayloadRead_cmd10(rpl_payload_pt, rpl_payload_len_pt, rwX_pt);
      break;
  }
}

void commandAll(uint8_t com_id) {

  uint8_t req_payload_rw1[MAX_REQ_PAYLOAD] = {0};
  uint8_t req_payload_len_rw1 = MAX_REQ_PAYLOAD;
  uint8_t req_packet_rw1[MAX_REQ_PACKET] = {0};
  uint8_t req_packet_len_rw1 = MAX_REQ_PACKET;

  uint8_t req_payload_rw2[MAX_REQ_PAYLOAD] = {0};
  uint8_t req_payload_len_rw2 = MAX_REQ_PAYLOAD;
  uint8_t req_packet_rw2[MAX_REQ_PACKET] = {0};
  uint8_t req_packet_len_rw2 = MAX_REQ_PACKET;

  uint8_t req_payload_rw3[MAX_REQ_PAYLOAD] = {0};
  uint8_t req_payload_len_rw3 = MAX_REQ_PAYLOAD;
  uint8_t req_packet_rw3[MAX_REQ_PACKET] = {0};
  uint8_t req_packet_len_rw3 = MAX_REQ_PACKET;

  uint8_t req_payload_rw4[MAX_REQ_PAYLOAD] = {0};
  uint8_t req_payload_len_rw4 = MAX_REQ_PAYLOAD;
  uint8_t req_packet_rw4[MAX_REQ_PACKET] = {0};
  uint8_t req_packet_len_rw4 = MAX_REQ_PACKET;

  uint8_t rpl_payload_rw1[MAX_RPL_PAYLOAD] = {0};
  uint8_t rpl_payload_len_rw1 = MAX_RPL_PAYLOAD;
  uint8_t rpl_packet_rw1[MAX_RPL_PACKET] = {0};
  uint8_t rpl_packet_len_rw1 = MAX_RPL_PACKET;

  uint8_t rpl_payload_rw2[MAX_RPL_PAYLOAD] = {0};
  uint8_t rpl_payload_len_rw2 = MAX_RPL_PAYLOAD;
  uint8_t rpl_packet_rw2[MAX_RPL_PACKET] = {0};
  uint8_t rpl_packet_len_rw2 = MAX_RPL_PACKET;

  uint8_t rpl_payload_rw3[MAX_RPL_PAYLOAD] = {0};
  uint8_t rpl_payload_len_rw3 = MAX_RPL_PAYLOAD;
  uint8_t rpl_packet_rw3[MAX_RPL_PACKET] = {0};
  uint8_t rpl_packet_len_rw3 = MAX_RPL_PACKET;

  uint8_t rpl_payload_rw4[MAX_RPL_PAYLOAD] = {0};
  uint8_t rpl_payload_len_rw4 = MAX_RPL_PAYLOAD;
  uint8_t rpl_packet_rw4[MAX_RPL_PACKET] = {0};
  uint8_t rpl_packet_len_rw4 = MAX_RPL_PACKET;

  int rpl_data_len;

  switch (com_id){
    case 4:
      rpl_data_len = 10;
      break;
    case 6:
      rpl_data_len = 0;
      break;
    case 10:
      rpl_data_len = 0;
      break;
  }

  rpl_packet_len_rw1 = 2*(rpl_data_len + 4) + 3;
  rpl_packet_len_rw2 = 2*(rpl_data_len + 4) + 3;
  rpl_packet_len_rw3 = 2*(rpl_data_len + 4) + 3;
  rpl_packet_len_rw4 = 2*(rpl_data_len + 4) + 3;

  // rw1
  reqPayloadWriteSwitcher(com_id, &req_payload_rw1[0], &req_payload_len_rw1, &rw1);
  reqPacketProcess(&req_payload_rw1[0], &req_packet_rw1[0], &req_payload_len_rw1, &req_packet_len_rw1);
  reqSpiTransfer(&req_packet_rw1[0], &req_packet_len_rw1, SS1);

  #if WHEELS_INDEPANDANT
  // rw2
  reqPayloadWriteSwitcher(com_id, &req_payload_rw2[0], &req_payload_len_rw2, &rw2);
  reqPacketProcess(&req_payload_rw2[0], &req_packet_rw2[0], &req_payload_len_rw2, &req_packet_len_rw2);
  reqSpiTransfer(&req_packet_rw2[0], &req_packet_len_rw2, SS2);

  // rw3
  reqPayloadWriteSwitcher(com_id, &req_payload_rw3[0], &req_payload_len_rw3, &rw3);
  reqPacketProcess(&req_payload_rw1[0], &req_packet_rw3[0], &req_payload_len_rw3, &req_packet_len_rw3);
  reqSpiTransfer(&req_packet_rw3[0], &req_packet_len_rw3, SS3);

  // rw4
  reqPayloadWriteSwitcher(com_id, &req_payload_rw4[0], &req_payload_len_rw4, &rw4);
  reqPacketProcess(&req_payload_rw4[0], &req_packet_rw4[0], &req_payload_len_rw4, &req_packet_len_rw4);
  reqSpiTransfer(&req_packet_rw4[0], &req_packet_len_rw4, SS4);
  #endif

  #if ARDUINO_CODE
  delay(SPI_TIMEOUT);
  #endif

  // rw1
  rplSpiTransfer(&rpl_packet_rw1[0], &rpl_packet_len_rw1, SS1);
  rplPacketProcess(&rpl_payload_rw1[0], &rpl_packet_rw1[0], &rpl_payload_len_rw1, &rpl_packet_len_rw1);
  rplPayloadReadSwitcher(com_id, &rpl_payload_rw1[0], &rpl_payload_len_rw1, &rw1);

  #if WHEELS_INDEPANDANT
  // rw2
  rplSpiTransfer(&rpl_packet_rw2[0], &rpl_packet_len_rw2, SS2);
  rplPacketProcess(&rpl_payload_rw2[0], &rpl_packet_rw2[0], &rpl_payload_len_rw2, &rpl_packet_len_rw2);
  rplPayloadReadSwitcher(com_id, &rpl_payload_rw2[0], &rpl_payload_len_rw2, &rw2);

  // rw3
  rplSpiTransfer(&rpl_packet_rw3[0], &rpl_packet_len_rw3, SS3);
  rplPacketProcess(&rpl_payload_rw3[0], &rpl_packet_rw3[0], &rpl_payload_len_rw3, &rpl_packet_len_rw3);
  rplPayloadReadSwitcher(com_id, &rpl_payload_rw3[0], &rpl_payload_len_rw3, &rw3);

  // rw4
  rplSpiTransfer(&rpl_packet_rw4[0], &rpl_packet_len_rw4, SS4);
  rplPacketProcess(&rpl_payload_rw4[0], &rpl_packet_rw4[0], &rpl_payload_len_rw4, &rpl_packet_len_rw4);
  rplPayloadReadSwitcher(com_id, &rpl_payload_rw4[0], &rpl_payload_len_rw4, &rw4);
  #endif
}

