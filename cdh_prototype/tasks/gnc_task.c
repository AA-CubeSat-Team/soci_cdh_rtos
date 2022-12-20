// Name: Jay Lee, Tristan Barr
// Notes: simple GNC build integrated
// TO-DO list: Make sure GNC task runs every 250 ms

#include "peripherals.h"
#include "gyro_wrap.h"
#include "gnc_task.h"
#include "act_wrap.h"
#include "sen_wrap.h"
#include "idle_task.h"
#include "sun_wrap.h"
#include "fsl_debug_console.h"
#include "com_protocol_helper.h"

//GNC BUILD include
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "FSW_Lib0.h"                  /* Model's header file */
#include "rtwtypes.h"
#include "zero_crossing_types.h"

// timer test
#include "timer_test.h"


extern bool g_senActive, g_rwaActive, g_mtqActive;

// counter for telemetry struct filling
int data_iter;

// TO DO: Double check if we need to disable interrupts and save FPU context
// Question: rt_OneStep looks unfinished, are the comments correct to what we need to do?

void rt_OneStep(void)
{
  static boolean_T OverrunFlags[2] = { 0, 0 };

  static boolean_T eventFlags[2] = { 0, 0 };/* Model has 2 rates */

  static int_T taskCounter[2] = { 0, 0 };


  /* Disable interrupts here */

  /* Check base rate for overrun */
  if (OverrunFlags[0]) {
    rtmSetErrorStatus(rtM, "Overrun");
    return;
  }

  OverrunFlags[0] = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */

  /*
   * For a bare-board target (i.e., no operating system), the
   * following code checks whether any subrate overruns,
   * and also sets the rates that need to run this time step.
   */
  if (taskCounter[1] == 0) {
    if (eventFlags[1]) {
      OverrunFlags[0] = false;
      OverrunFlags[1] = true;

      /* Sampling too fast */
      rtmSetErrorStatus(rtM, "Overrun");
      return;
    }

    eventFlags[1] = true;
  }

  taskCounter[1]++;
  if (taskCounter[1] == 20) {
    taskCounter[1]= 0;
  }

  /* Set model inputs associated with base rate here */

  /* Step the model for base rate */
  FSW_Lib0_step0();

  /* Get model outputs here */

  /* Indicate task for base rate complete */
  OverrunFlags[0] = false;

  /* If task 1 is running, don't run any lower priority task */
  if (OverrunFlags[1]) {
    return;
  }

  /* Step the model for subrate */
  if (eventFlags[1]) {
    OverrunFlags[1] = true;

    /* Set model inputs associated with subrates here */

    /* Step the model for subrate 1 */
    FSW_Lib0_step1();

    /* Get model outputs here */

    /* Indicate task complete for subrate */
    OverrunFlags[1] = false;
    eventFlags[1] = false;
  }

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}

//TODO: need to go over the operation of GNC and the wrappers to lay out the functions in this task
void gnc_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 250 ); //delay 250 ms
	TickType_t xLastWakeTime = xTaskGetTickCount();
	PRINTF("initialize gnc.\r\n");

	TickType_t timerDelay = WAIT_TIME_MINUTES * ONE_MINUTE;
    while (timerDelay > 0) {
    	// Delay for the maximum number of ticks
    	vTaskDelay(ONE_MINUTE); // 65535

    	// Subtract the number of ticks delayed from the total delay time
    	timerDelay -= ONE_MINUTE;
    }
//	SPI_GPIO_init();
#if GNC_ENABLE

	// set to first index of struct array
	data_iter = 0;

	/* gnc, sens, act initialization */

	initPWM (&mtq, &LPI2C1_masterHandle);

	startGyro (&Gyro1, &LPI2C1_masterHandle, &LPI2C1_masterTransfer);
//	startGyro (&Gyro2, &LPI2C1_masterHandle, &LPI2C1_masterTransfer);
//	startGyro (&Gyro3, &LPI2C1_masterHandle, &LPI2C1_masterTransfer);

	quickStartMag (&Mag1, &LPI2C1_masterHandle);
//	quickStartMag (&Mag2, &LPI2C1_masterHandle);
//	quickStartMag (&Mag3, &LPI2C1_masterHandle);

	quickStartPhd (&Phd1, &LPI2C1_masterHandle);

	// Question: Is feedback only used for flatsat?
	initFeedback (&Feed, &LPI2C1_masterHandle);

	// Question: Set Ramp time here or keep default value??
	// -> We talked about this, we can just see how the wheels react without having a set ramp time

	rw0.reqClcMode = 0;
	rw1.reqClcMode = 0;
	rw2.reqClcMode = 0;
	rw3.reqClcMode = 0;
	commandRw (7, &rw0, RWA0);
	commandRw (7, &rw1, RWA1);
	commandRw (7, &rw2, RWA2);
	commandRw (7, &rw3, RWA3);

	/* Initialize model */
	// Question: Is this the only initialization needed?

	FSW_Lib0_initialize();

#endif
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		PRINTF("GNC task loop\r\n");

		// Question: do we call rt_OneStep before getting new sensor reads
		// AND after getting new sensor reads?
//		rt_OneStep();


#if GNC_ENABLE
		xLastWakeTime = xTaskGetTickCount();
		printf("\nGNC TASK START.\r\n");

		/* read sensors and actuator measurements to sensor_bus */
		if (g_senActive) {

			// Question: Sun sensor has 3 possible angle readings, sun_meas_ss_deg only has 2 array indices,
			// do we discard the third reading?

			getSunAngles(&Sun1);
			rtU.sensor_meas.sun_meas_ss_deg[0] = Sun1.angles[0];
			rtU.sensor_meas.sun_meas_ss_deg[1] = Sun1.angles[1];
			rtU.sensor_meas.sun_meas_valid = 0/*Sun1.isValid*/;

			// Question: Is this how the Mag data is input to the struct?

			readMagData (&Mag1);
//			readMagData (&Mag2);
//			readMagData (&Mag3);
			rtU.sensor_meas.mag_mag_uT[0] = Mag1.magXYZ[0];
			rtU.sensor_meas.mag_mag_uT[1] = Mag1.magXYZ[1];
			rtU.sensor_meas.mag_mag_uT[2] = Mag1.magXYZ[2];
			rtU.sensor_meas.mag_mag_uT[3] = Mag1.magXYZ[0];
			rtU.sensor_meas.mag_mag_uT[4] = Mag1.magXYZ[1];
			rtU.sensor_meas.mag_mag_uT[5] = Mag1.magXYZ[2];
			rtU.sensor_meas.mag_mag_uT[6] = Mag1.magXYZ[0];
			rtU.sensor_meas.mag_mag_uT[7] = Mag1.magXYZ[1];
			rtU.sensor_meas.mag_mag_uT[8] = Mag1.magXYZ[2];
			rtU.sensor_meas.mag_meas_valid[0] = 1;
			rtU.sensor_meas.mag_meas_valid[1] = 1;
			rtU.sensor_meas.mag_meas_valid[2] = 1;

			readPhdData (&Phd1);
			rtU.sensor_meas.photodiodes_uA[0] = Phd1.current[0];
			rtU.sensor_meas.photodiodes_uA[1] = Phd1.current[1];
			rtU.sensor_meas.photodiodes_uA[2] = Phd1.current[2];
			rtU.sensor_meas.photodiodes_uA[3] = Phd1.current[3];
			rtU.sensor_meas.photodiodes_uA[4] = Phd1.current[4];

			// Question: Is this how gyro reads are to be input to struct?

			readGyroData (&Gyro1);
//			readGyroData (&Gyro2);
//			readGyroData (&Gyro3);
			rtU.sensor_meas.gyro_gyro_radps[0] = Gyro1.gyroXYZ[0];
			rtU.sensor_meas.gyro_gyro_radps[1] = Gyro1.gyroXYZ[1];
			rtU.sensor_meas.gyro_gyro_radps[2] = Gyro1.gyroXYZ[2];
			rtU.sensor_meas.gyro_gyro_radps[3] = Gyro1.gyroXYZ[0];
			rtU.sensor_meas.gyro_gyro_radps[4] = Gyro1.gyroXYZ[1];
			rtU.sensor_meas.gyro_gyro_radps[5] = Gyro1.gyroXYZ[2];
			rtU.sensor_meas.gyro_gyro_radps[6] = Gyro1.gyroXYZ[0];
			rtU.sensor_meas.gyro_gyro_radps[7] = Gyro1.gyroXYZ[1];
			rtU.sensor_meas.gyro_gyro_radps[8] = Gyro1.gyroXYZ[2];

			// ToDo: Write error check for gyro to say data valid

			rtU.sensor_meas.gyro_meas_valid[0] = 1;
			rtU.sensor_meas.gyro_meas_valid[1] = 1;
			rtU.sensor_meas.gyro_meas_valid[2] = 1;

		}

		if (g_rwaActive) {

			commandRw (4, &rw0, RWA0);
			commandRw (4, &rw1, RWA1);
			commandRw (4, &rw2, RWA2);
			commandRw (4, &rw3, RWA3);
			rtU.actuator_meas_p.rwa_rpm[0] = rw0.currSpeed;
			rtU.actuator_meas_p.rwa_rpm[1] = rw1.currSpeed;
			rtU.actuator_meas_p.rwa_rpm[2] = rw2.currSpeed;
			rtU.actuator_meas_p.rwa_rpm[3] = rw3.currSpeed;

			// Todo: make a valid bit in the rwa struct based on error check function

			rtU.actuator_meas_p.rwa_valid[0] = 1;
			rtU.actuator_meas_p.rwa_valid[1] = 1;
			rtU.actuator_meas_p.rwa_valid[2] = 1;
			rtU.actuator_meas_p.rwa_valid[3] = 1;
		}


		if (g_mtqActive) {

			// Question: We don't actually get any data from mtq's, and there are
			// 5 mtq_valid indices in the struct but only 3 mtq's?

			rtU.actuator_meas_p.mtq_valid[0] = 1;
			rtU.actuator_meas_p.mtq_valid[1] = 1;
			rtU.actuator_meas_p.mtq_valid[2] = 1;
			rtU.actuator_meas_p.mtq_valid[3] = 1;
			rtU.actuator_meas_p.mtq_valid[4] = 1;
		}

		/* call GNC rt_OneStep() */
		 rt_OneStep();

		/* write to actuators */
		if (g_rwaActive) {
			rw0.reqSpeed = rtY.fsw_out_l.rwa_cmd_rpm[0];
			rw1.reqSpeed = rtY.fsw_out_l.rwa_cmd_rpm[1];
			rw2.reqSpeed = rtY.fsw_out_l.rwa_cmd_rpm[2];
			rw3.reqSpeed = rtY.fsw_out_l.rwa_cmd_rpm[3];
			commandRw (6, &rw0, RWA0);
			commandRw (6, &rw1, RWA1);
			commandRw (6, &rw2, RWA2);
			commandRw (6, &rw3, RWA3);
		}
		if (g_mtqActive) {

			// Question: Only 3 mtq's, but 5 indices in the struct. Need 3 moments to command a single mtq
			// are all 3 moments stored in 1 index, or ?

			if () {

			}

			float x = rtY.fsw_out_l.mtq_cmd_Am2[0] - rtY.fsw_out_l.mtq_cmd_Am2[1];
			float y = rtY.fsw_out_l.mtq_cmd_Am2[2] - rtY.fsw_out_l.mtq_cmd_Am2[3];
			float z = rtY.fsw_out_l.mtq_cmd_Am2[4];
			setMoments (x, y, z, &mtq);

		}

		// Question: Is this what you had in mind for storing telemetry data?
		// It's an array of the last (max_telemDownlink) FSW_telem's gathered

		// Udate newest telemetry data to proper index in array
//		GNC_payload[data_iter] = rtY.fsw_telem;
//		(data_iter == max_telemDownlink - 1)? data_iter = 0: data_iter += 1;

		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#else
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
