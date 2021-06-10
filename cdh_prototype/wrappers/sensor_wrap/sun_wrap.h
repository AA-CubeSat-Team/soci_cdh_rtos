#define ARDUINO_CODE 0
/* #include <math.h> */
#if ARDUINO_CODE
   #include <Arduino.h>
   #include <hardwareSerial.h>
#else
   #include "peripherals.h"
   #include "fsL_lpuart.h"
   #include "fsl_lpuart_freertos.h"
   #include "task.h"
#endif

/* make a receiver buffer, needs room for at most voltRespLength bytes*/
/* c gets salty at me if I try to make it of length voltRespLength but */
/* it gets even saltier if I try to replace voltRespLength as a #define */
/* so I'm just putting it as 20 */

/*!
 * @brief Structure contains information about one gyroscope
 *
 */
typedef struct _Sun
{
  double angles[4];           /* measured alpha and beta angles*/
  double unFiltVolts[4];      /* measured unfiltered voltages*/
  double filtVolts[4];        /* measured filtered voltages*/
} sun_t;

extern sun_t Sun1;                /* sun sensor 1*/

void readFloats(double* data, int floatsToRead);
void getSunAngles(sun_t * Sun);
void getFiltVolts(sun_t * Sun);
void getUnfiltVolts(sun_t * Sun);
void sunSenUARTInit();
