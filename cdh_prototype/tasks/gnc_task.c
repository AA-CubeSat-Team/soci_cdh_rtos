#define GYRO_WRAP_TEST	0

#include "wrappers/sensor_wrap/gyro_wrap_test.h"
#include "wrappers/sensor_wrap/gyro_wrap.h"
#include "wrappers/sensor_wrap/mag_wrap.h"
#include "wrappers/sensor_wrap/sun_wrap.h"
#include "wrappers/sensor_wrap/phd_wrap.h"
#include "gnc_task.h"
//#include "FSW_Lib_types.h"
#include "act_wrap.h"
#include "sen_wrap.h"


//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib_types.h>
//#include <gnc_build/FSW_Lib_ert_rtw/FSW_Lib.h>


//extern bool g_sunSensActive, g_magSensActive, g_phdSensActive, g_mtqSensActive, g_rwaActive;

//TODO: need to go over the operation of GNC and the wrappers to lay out the functions in this task
void gnc_task(void *pvParameters)
{
#if GYRO_WRAP_TEST
	gyro_wrap_test_setup();
#else
	const TickType_t xDelayms = pdMS_TO_TICKS( 500 ); //delay 500 ms
	TickType_t xLastWakeTime = xTaskGetTickCount();
#if GNC_ENABLE
	PRINTF("\ninitialize gnc.\r\n");
	/* gnc, sens, act initialization */
//	startGyro(Gyro, gyroHandle, transfer);
//	 FSW_Lib_initialize(); //GNC board initialization
//	quickStartGyro(&Gyro1, &i2c1_m_rtos_handle);
//	quickStartMag(&Mag1, &i2c1_m_rtos_handle);
	quickStartPhd(&Phd1, &i2c1_m_rtos_handle);
#endif
#endif

	for (;;) {
#if GYRO_WRAP_TEST
		gyro_wrap_test_loop();
#else
//		xLastWakeTime = xTaskGetTickCount();
//		PRINTF("\nGNC TASK START.\r\n");

		/* read sensors and actuator measurements to sensor_bus */
//		if(g_sunSensActive){
//			sens_readSun();
//		}
//		else{
//			PRINTF("sun sensor not active\r\n");
//		}

//		if(g_magSensActive){
//			sens_readMag();
//		}
//		else{
//			PRINTF("magnetometer not active\r\n");
//		}

//		if(g_phdSensActive){
//			sens_readPhd();
//		}
//		else{
//			PRINTF("photodiode not active\r\n");
//		}
//		sens_readSun();
//		sens_readMag();
		readPhdData(&Phd1);
//		sens_readGyr();
//		readActMeas();
//		readGyroData(&Gyro1);
//		vTaskDelayUntil(&xLastWakeTime, xDelayms);
//		readMagData(&Mag1);
		/* call GNC rt_OneStep() */
		// TODO: enable rt_OneStep(); after include
		// rt_OneStep();
//		gnc_sendCommand();
//		PRINTF("GYRO:   ");
//		for (int i = 0; i < 3; i++) {
//			print_float(Gyro1.gyroXYZ[i]);
//		}
//		PRINTF("\n");
//		PRINTF("MAG:   ");
//		for (int i = 0; i < 3; i++) {
//			print_float(Mag1.magXYZ[i]);
//		}
//		PRINTF("\n");
		PRINTF("\n");
		PRINTF("Phd:   ");
		for (int i = 0; i < 5; i++) {
			print_float(Phd1.current[i]);
		}
		PRINTF("\n");
#endif
	}
#if !GYRO_WRAP_TEST
//	vTaskDelayUntil(&xLastWakeTime, xDelayms);
#endif
}

