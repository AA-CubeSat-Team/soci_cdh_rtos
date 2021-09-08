
#include "sun_wrap.h"

uint8_t unFiltVoltsComm[4] = {0x60, 0x01, 0x01, 0x02};
uint8_t filtVoltsComm[4] = {0x60, 0x03, 0x01, 0x04};
uint8_t anglesComm[4] = {0x60, 0x04, 0x01, 0x05};

/* lengths of voltage responses and angle response */
const int voltRespLength = 20;
const int angleRespLength = 17;

#if !ARDUINO_CODE
   /* delay times in ticks needed */
   const TickType_t xDelay3ms = pdMS_TO_TICKS(3);
   const TickType_t xDelay7ms = pdMS_TO_TICKS(7);
   /* this is the minimum possible time between commands - the typical time is 50 ms, I might want to change this */
   const TickType_t xDelay20ms = pdMS_TO_TICKS(20);
#endif
status_t error;
uint8_t sun_recv_buffer[20];
// sun sensor struct
sun_t Sun1;



/* converts the response bytes into floats, but saves them as doubles */
/* since the data is stored as a double */
/* takes a pointer to the data that will be written over (e.g. angles) */
/* and the number of floats to read */
void readFloats(double* data, int floatsToRead){
//   /* read in floatsToRead num of "floats" */
//   for (int x = 0; x < floatsToRead; x++){
//      /* initialize some variables that will be used to calculate the value of a "float" later */
//      double sign = 1.0;
//      double exp = -127.0;
//      double frac = 1.0;
//      /* next, I need to take 4 data bytes from recv_buffer that correspond to the data */
//      int bytes[4] = {recv_buffer[4*x+6], recv_buffer[4*x+5], recv_buffer[4*x+4], recv_buffer[4*x+3]};
//      /* The sun sensor sends from LSB to MSB so I need to reverse the order of the bytes */
//      /* the most significant bit corresponds to the sign */
//      /* the sign defaults to 1 if the most significant bit is 0, but if it is 1, then the sign is -1 */
//      if (bytes[0] > 127){
//        sign = -1.0;
//        /* need to subtract off the most significant bit so I can start working on the exponent */
//        bytes[0] -= 128;
//      }
//      /* the next 8 bits comprise the exponent bit. these are the remaining bits of byte3 and the first of byte2 */
//      exp += 2*(double)bytes[0];
//      /* if the first bit of the next byte is 1, then 2^0 needs to be added to exp */
//      if (bytes[1] > 127){
//        exp += 1.0;
//        bytes[1] -= 128;
//      }
//      /* the remaining bits make up the fraction. */
//      frac += (double)bytes[1]*pow(2.0, -7.0)+(double)bytes[2]*pow(2.0, -15.0)+(double)bytes[3]*pow(2.0, -23.0);
//      /* putting sign, exp, and frac together and assigning it to the data array */
//      *(data + x) = sign*pow(2.0, exp)*frac;
//      }

   // new section
   for (int x = 0; x < floatsToRead; x++){
      uint8_t bytes[4] = {sun_recv_buffer[4*x+3], sun_recv_buffer[4*x+4], sun_recv_buffer[4*x+5], sun_recv_buffer[4*x+6]};
      memcpy((data + x), &bytes, sizeof(float));
   }

      
   /* next, take the total sum of all the bytes except the address byte */
   int totSum = 0;
   /* need to sum from command (2nd) byte to last data byte (2nd to last of array) */
   if(floatsToRead == 4){
      for(int x = 1; x < voltRespLength - 1; x++){
         totSum += (int)sun_recv_buffer[x];
      }
   }else{
      for(int x = 1; x < angleRespLength - 1; x++){
         totSum += (int)sun_recv_buffer[x];
      }
   }
   /* next, need to pare totSum down to its least significant byte, which can be accomplished by */
   /* comparing it to 255 */
   totSum = (totSum & 255);
   /* then compare it to the checkSum byte, which is the last byte */
   if(totSum != (int)sun_recv_buffer[angleRespLength - 1] && floatsToRead == 3){
      *data = -1000.0;
      *(data + 1) = -1000.0;
      *(data + 2) = -1000.0;
      *(data + 3) = -1000.0;
      return;
   }else if(totSum != (int)sun_recv_buffer[voltRespLength - 1] && floatsToRead == 4){
      *data = -1000.0;
      *(data + 1) = -1000.0;
      *(data + 2) = -1000.0;
      *(data + 3) = -1000.0;
      return;
   }
   /* lastly, if we're getting values for angles (floatsToRead is 3) then the 4th read value needs to be the error (2nd to last) byte */
   if (floatsToRead == 3){
      *(data + 3) = (double)sun_recv_buffer[angleRespLength - 2];
   }
   return;
}

/* getUnfiltVolts() will issue the unfiltered cell voltage commmand to the sun sensor, read in the response, perform some checks */
/* and then call readFloats to interpret data */
/* it needs the pointer to the unfiltered cell voltages */
void getUnfiltVolts(sun_t * Sun){
   /* issue command to sun sensor */
   #if ARDUINO_CODE
      for(int i = 0; i < 4; i++){
         Serial1.write(unFiltVoltsComm[i]);
      }
      /* wait until response can be sent */
      delay(3);
   #else
      error = LPUART_RTOS_Send(&uart3_handle, unFiltVoltsComm, 4);
      /* if there was an error with RTOS functions, assign an error code */
      if(error != kStatus_Success){
        *(Sun->unFiltVolts) = -2000.0;
        *(Sun->unFiltVolts + 1) = -2000.0;
        *(Sun->unFiltVolts + 2) = -2000.0;
        *(Sun->unFiltVolts + 3) = -2000.0;
         return;
      }
      vTaskDelay(xDelay3ms);
   #endif
   /* read in response to receiver buffer */
   #if ARDUINO_CODE
      for(int i = 0; i < voltRespLength; i++){
         sun_recv_buffer[i] = Serial1.read();
      }
   #else
      size_t numRecvBytes = 0;
      error = LPUART_RTOS_Receive(&uart3_handle, sun_recv_buffer, 4, &numRecvBytes);
      if(error != kStatus_Success){
         *(Sun->unFiltVolts) = -2000.0;
         *(Sun->unFiltVolts + 1) = -2000.0;
         *(Sun->unFiltVolts + 2) = -2000.0;
         *(Sun->unFiltVolts + 3) = -2000.0;
         return;
      }
   #endif
   /* check that the command byte (the 2nd byte) sent corresponds to the command byte received */
   if(unFiltVoltsComm[1] == sun_recv_buffer[1]){
      /* if it's correct, call readFloats and read in 4 floats */
      readFloats(Sun->unFiltVolts, 4);
   }else{
      /* if it's incorrect, assign an error value */
      *(Sun->unFiltVolts) = -1000.0;
      *(Sun->unFiltVolts + 1) = -1000.0;
      *(Sun->unFiltVolts + 2) = -1000.0;
      *(Sun->unFiltVolts + 3) = -1000.0;
      return;
   }
   return;
}

/* similar to getUnfiltVolts() */
void getFiltVolts(sun_t * Sun){
   /* issue command */
   #if ARDUINO_CODE
      for(int i = 0; i < 4; i++){
         Serial1.write(filtVoltsComm[i]);
      }
      delay(3);
   #else
      error = LPUART_RTOS_Send(&uart3_handle, filtVoltsComm, 4);
      if(error != kStatus_Success){
         *(Sun->filtVolts) = -2000.0;
         *(Sun->filtVolts + 1) = -2000.0;
         *(Sun->filtVolts + 2) = -2000.0;
         *(Sun->filtVolts + 3) = -2000.0;
         return;
      }
      vTaskDelay(xDelay3ms);
   #endif
   /* read response */
   #if ARDUINO_CODE
      for(int i = 0; i < voltRespLength; i++){
         sun_recv_buffer[i] = Serial1.read();
      }
   #else
      size_t numRecvBytes = 0;
      error = LPUART_RTOS_Receive(&uart3_handle, sun_recv_buffer, 4, &numRecvBytes);
      if(error != kStatus_Success){
         *(Sun->filtVolts) = -2000.0;
         *(Sun->filtVolts + 1) = -2000.0;
         *(Sun->filtVolts + 2) = -2000.0;
         *(Sun->filtVolts + 3) = -2000.0;
         return;
      }
   #endif
   /* check response */
   if(filtVoltsComm[1] == sun_recv_buffer[1]){
      readFloats(Sun->filtVolts, 4);
   }else{
      *(Sun->filtVolts) = -1000.0;
      *(Sun->filtVolts + 1) = -1000.0;
      *(Sun->filtVolts + 2) = -1000.0;
      *(Sun->filtVolts + 3) = -1000.0;
      return;
   }
   return;
}

/* similar to getUnfiltVolts() */
void getSunAngles(sun_t * Sun){
   /* issue command */
	printf("start get angles");
   #if ARDUINO_CODE
      for(int i = 0; i < 4; i++){
         Serial1.write(anglesComm[i]);
      }
      delay(7);
   #else
      error = LPUART_RTOS_Send(&uart3_handle, anglesComm, 4);
      printf("finish sent");
      if(error != kStatus_Success){
         *(Sun->angles) = -2000.0;
         *(Sun->angles + 1) = -2000.0;
         *(Sun->angles + 2) = -2000.0;
         *(Sun->angles + 3) = -2000.0;
         return;
      }
//      vTaskDelay(xDelay7ms);
   #endif
   /* read response */
   #if ARDUINO_CODE
      for(int i = 0; i < angleRespLength; i++){
         sun_recv_buffer[i] = Serial1.read();
      }
   #else
      size_t numRecvBytes = 0;
      printf("begin receive");
      error = LPUART_RTOS_Receive(&uart3_handle, sun_recv_buffer, 4, &numRecvBytes);
      printf("finish receive");
      printf("%d", sun_recv_buffer[0]);
      printf("%d", sun_recv_buffer[1]);
      printf("%d", sun_recv_buffer[2]);
      printf("%d", sun_recv_buffer[3]);
      if(error != kStatus_Success){
         *(Sun->angles) = -2000.0;
         *(Sun->angles + 1) = -2000.0;
         *(Sun->angles + 2) = -2000.0;
         *(Sun->angles + 3) = -2000.0;
         return;
      }
   #endif
   /* check response */
   if(anglesComm[1] == sun_recv_buffer[1]){
      readFloats(Sun->angles, 3);
   }else{
      *(Sun->angles) = -1000.0;
      *(Sun->angles + 1) = -1000.0;
      *(Sun->angles + 2) = -1000.0;
      *(Sun->angles + 3) = -1000.0;
      return;
   }
   return;
}

/* only useful for freeRTOS code */
void sunSenUARTInit(){
#if ARDUINO_CODE
      /* do nothing */
#else
      /* initialize LPUART instance */
//      LPuart4_init();
#endif
   return;
}

