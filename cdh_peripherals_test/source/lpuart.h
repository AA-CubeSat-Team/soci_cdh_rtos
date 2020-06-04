#ifndef LPUARTH
#define LPUARTH

#include <stdint.h>

void uart3_task(void *pvParameters);
void uart6_task(void *pvParameters);
void uart8_task(void *pvParameters);
void init_uart_tasks();

//const char *to_send3               = "LPUART3 woke up!\r\n";
//const char *to_send6               = "LPUART3 woke up!\r\n";
//const char *to_send8               = "LPUART8 woke up!\r\n";
//
//const char *send_ring_overrun     = "\r\nRing buffer overrun!\r\n";
//const char *send_hardware_overrun = "\r\nHardware buffer overrun!\r\n";
//
//uint8_t background_buffer3[32];
//uint8_t recv_buffer3[4];
//
//uint8_t background_buffer6[32];
//uint8_t recv_buffer6[4];
//
//uint8_t background_buffer8[32];
//uint8_t recv_buffer8[4];

//lpuart_rtos_handle_t handle3;
//struct _lpuart_handle t_handle3;
//
//lpuart_rtos_handle_t handle6;
//struct _lpuart_handle t_handle6;
//
//lpuart_rtos_handle_t handle8;
//struct _lpuart_handle t_handle8;
//
//lpuart_rtos_config_t lpuart_config3 = {
//    .baudrate    = 115200,
//    .parity      = kLPUART_ParityDisabled,
//    .stopbits    = kLPUART_OneStopBit,
//    .buffer      = background_buffer3,
//    .buffer_size = sizeof(background_buffer3),
//	.base  		 = LPUART3,
//};
//
//lpuart_rtos_config_t lpuart_config6 = {
//    .baudrate    = 115200,
//    .parity      = kLPUART_ParityDisabled,
//    .stopbits    = kLPUART_OneStopBit,
//    .buffer      = background_buffer6,
//    .buffer_size = sizeof(background_buffer6),
//	.base  		 = LPUART6,
//};
//
//lpuart_rtos_config_t lpuart_config8 = {
//    .baudrate    = 115200,
//    .parity      = kLPUART_ParityDisabled,
//    .stopbits    = kLPUART_OneStopBit,
//    .buffer      = background_buffer8,
//    .buffer_size = sizeof(background_buffer8),
//	.base  		 = LPUART8,
//};

#endif
