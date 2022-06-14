#include "sun_wrap.h"
#include "fsl_debug_console.h"
#include "com_protocol_helper.h"
#include "peripherals.h"
#include <math.h>
const uint8_t anglesComm[4] = {0x60, 0x04, 0x01, 0x05};
const TickType_t xDelay10ms = pdMS_TO_TICKS(10);
/* number of bytes returned for angle command */
const int angleRespLength = 17;
// sun sensor struct
sun_t Sun1;
uint8_t sun_recv_buffer[17];
uint8_t buf[1];
/* converts the response bytes into floats, but saves them as doubles */
/* since the data is stored as a double, and also checks data for errors */
/* takes a pointer to the data that will be written over (e.g. angles), */
/* a pointer to the error, and a pointer to isValid */
void readFloats(double* data, uint8_t* error, uint8_t* isValid){
   for (int x = 0; x < 3; x++){
      uint8_t bytes[4] = {sun_recv_buffer[4*x+3], sun_recv_buffer[4*x+4], sun_recv_buffer[4*x+5], sun_recv_buffer[4*x+6]};
//      printf ("Bytes: ");
//      for (int i = 0; i < sizeof(bytes); i++) {
//    	  printf ("0x%2x ", bytes[i]);
//      }
//      printf ("\r\n");
//      memcpy((data + x), &bytes, sizeof(float));
//      printf ("0x%8x\r\n", ((bytes[0] << 24) | (bytes[1] << 16) | (bytes[2] << 8) | (bytes[3])));
      uint32_t num = ((bytes[3] << 24) | (bytes[2] << 16) | (bytes[1] << 8) | (bytes[0]));
      float f;
      f = *((float*)&num);
      Sun1.angles[x] = f;
      printf ("Data: %f\r\n", Sun1.angles[x]);
   }
   /* next, take the total sum of all the bytes except the address byte */
   int totSum = 0;
   /* need to sum from command (2nd) byte to last data byte (2nd to last of array) */
   for(int x = 1; x < angleRespLength - 1; x++){
      totSum += (int)sun_recv_buffer[x];
   }
   /* next, need to parse totSum down to its least significant byte, which can be accomplished by */
   /* comparing it to 255 */
   totSum = (totSum & 255);
   /* then compare it to the checkSum byte, which is the last byte */
   if(totSum != (int)sun_recv_buffer[angleRespLength - 1]){
	  Sun1.angles[0] = -1000.0;
	  Sun1.angles[1] = -1000.0;
	  Sun1.angles[2] = -1000.0;
      *isValid = 0;
      *error = 14;
      return;
   }
   /* lastly, if we're getting values for angles (floatsToRead is 3) then the 4th read value needs to be the error (2nd to last) byte */
   *error = sun_recv_buffer[angleRespLength - 2];
   /* check if the error is acceptable */
   if(*error == 0){
      /* if it is acceptable, then the validity flag is raised (is 1) */
      *isValid = 1;
   }else{
      /* otherwise, it is not (is 0) */
      *isValid = 0;
   }
//   printf ("Valid: %d\r\n", *isValid);
   return;
}
/* getSunAngles() will issue the angles commmand to the sun sensor, read in the response, perform some checks */
/* and then call readFloats to interpret and check the data */
/* it needs the pointer to the sun structure */
void getSunAngles(sun_t * Sun){
   /* issue command */
   #if ARDUINO_CODE
      for(int i = 0; i < 4; i++){
         Serial1.write(anglesComm[i]);
      }
      delay(10);
   #else
      int error;
      size_t n = 0;
      error = UART_send(&LPUART3_rtos_handle, (uint8_t *)anglesComm, sizeof(anglesComm));
      error = UART_receive(&LPUART3_rtos_handle, (uint8_t *)sun_recv_buffer, angleRespLength, &n);

      if(error == kStatus_LPUART_Error ){
         *(Sun->angles) = -2000.0;
         *(Sun->angles + 1) = -2000.0;
         *(Sun->angles + 2) = -2000.0;
         Sun->error = 16;
         Sun->isValid = 0;
         printf("error in transmission\n");
         return;
      }
   #endif
   /* read response */
   #if ARDUINO_CODE
      for(int i = 0; i < angleRespLength; i++){
         sun_recv_buffer[i] = Serial1.read();
      }
   #else
      // nothing
   #endif
   /* check response */
   if(anglesComm[1] == sun_recv_buffer[1]){
      readFloats(Sun->angles, &(Sun->error), &(Sun->isValid));
   }else{
      *(Sun->angles) = -1000.0;
      *(Sun->angles + 1) = -1000.0;
      *(Sun->angles + 2) = -1000.0;
      Sun->error = 15;
      Sun->isValid = 0;
      return;
   }
   return;
}
