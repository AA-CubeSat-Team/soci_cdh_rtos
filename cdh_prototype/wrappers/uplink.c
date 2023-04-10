/*
 * This program implements helper functions for processing and handing uplinked command data.
 */

#include "uplink.h"

/*
 * This function splits the command uplink data into separate packets.
 */
void split_into_packets(unsigned char *data, int data_len, unsigned char ***packets, int **packets_len) {
    int i, start, packet_count = 0;

    // Count the number of packets in the data buffer
    for (i = 0; i < data_len; i++) {
        if (data[i] == EOP) {
            packet_count++;
        }
    }

    // Allocate memory for the packets
    *packets = (unsigned char **)malloc(packet_count * sizeof(unsigned char *));
    *packets_len = (int *)malloc(packet_count * sizeof(int));

    // Split the data buffer into packets
    packet_count = 0;
    start = 0;
    for (i = 0; i < data_len; i++) {
        if (data[i] == EOP) {
            int packet_len = i - start;
            (*packets_len)[packet_count] = packet_len;
            (*packets)[packet_count] = (unsigned char *)malloc(packet_len);
            memcpy((*packets)[packet_count], data + start, packet_len);
            packet_count++;
            start = i + 1;
        }
    }
}

int check_crc(char* crc) {
    return 0;
}

int check_hmac(char* hmac) {
    return 0;
}

int main(int argc, char* argv[]) {

    // Command data as read from flight radio serial buffer
    // This will be an argument provided to uplink.c when running
    // char command_data[] = argv[1];
    unsigned char radio_buffer[] = {
    5, 0, 1, 2, 0x1A, 0xFF,
    9, 1, 10, 20, 30, 40, 0x2B, 0x3C, 0xFF,
    7, 2, 100, 200, 0xAA, 0xBB, 0xCC, 0xFF,
    11, 3, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0xFF
    };
    int data_len = sizeof(radio_buffer) / sizeof(radio_buffer[0]);
    char** packets;
    char* packets_len;

    // Split command_data buffer into packets by terminate character
    split_into_packets(*radio_buffer, data_len, packets, packets_len);

    return 0;
}
