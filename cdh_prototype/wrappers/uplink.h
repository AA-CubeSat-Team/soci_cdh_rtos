/*
 * Implements helper function for processing uplinked command data in com_task.c.
 */

// #include "openssl.c"
// #include "crc.c"
#include <stdio.h>
#include <string.h>

#define EOP 0xFF

#define header_cmd_pkt_ack 0
#define com_cmd_pkt_ack 0
#define gnc_cmd_pkt_ack 0
#define img_cmd_pkt_ack 0


// Split command buffer into individual command packets
void split_into_packets(unsigned char *data, int data_len, unsigned char ***packets, int **packets_len);

// Checks HMAC on header packet
// Returns 0 for fail, returns 1 for pass
int check_hmac(char* hmac);

// Checks CRC for each packet
// Updates cmd_pkt acknowledgment value
// 0 for fail, returns 1 for pass
int check_crc(char* crc);
