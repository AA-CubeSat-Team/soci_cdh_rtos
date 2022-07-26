// Name: Jay Lee, Tristan Barr
// Notes: simple GNC build integrated
// TO-DO list: Make sure GNC task runs every 250 ms

#include "peripherals.h"
#include "gnc_task.h"
#include "idle_task.h"
#include "fsl_debug_console.h"
#include "com_protocol_helper.h"

#include "act_wrap/act_feedback.h"
#include "act_wrap/mtq_wrap.h"
#include "act_wrap/rwa_wrap.h"
#include "sensor_wrap/gyro_wrap.h"
#include "sensor_wrap/mag_wrap.h"
#include "sensor_wrap/phd_wrap.h"
#include "sensor_wrap/sun_wrap.h"

//GNC BUILD include
#include <stddef.h>
#include <stdio.h>                     /* This ert_main.c example uses printf/fflush */
#include "FSW_Lib_ert_rtw/FSW_Lib.h"                  /* Model's header file */
#include "FSW_Lib_ert_rtw/rtwtypes.h"
//#include "zero_crossing_types.h"

extern bool g_senActive, g_rwaActive, g_mtqActive;

// counter for telemetry struct filling
int data_iter;

//TODO: need to go over the operation of GNC and the wrappers to lay out the functions in this task
void gnc_task(void *pvParameters)
{
	const TickType_t xDelayms = pdMS_TO_TICKS( 250 ); //delay 250 ms
	TickType_t xLastWakeTime = xTaskGetTickCount();
	PRINTF("initialize gnc.\r\n");

#if GNC_ENABLE

	// set to first index of struct array
	data_iter = 0;

	/* gnc, sens, act initialization */

	initPWM (&mtq, &LPI2C1_masterHandle);

	startGyro (&Gyro1, &LPI2C1_masterHandle, &LPI2C1_masterTransfer, 1);
#if !FLATSAT
	startGyro (&Gyro2, &LPI2C1_masterHandle, &LPI2C1_masterTransfer, 2);
	startGyro (&Gyro3, &LPI2C1_masterHandle, &LPI2C1_masterTransfer, 3);
#endif
	quickStartMag (&Mag1, &LPI2C1_masterHandle, 1);
#if !FLATSAT
	quickStartMag (&Mag2, &LPI2C1_masterHandle, 2);
	quickStartMag (&Mag3, &LPI2C1_masterHandle, 3);
#endif
//	quickStartPhd (&Phd1, &LPI2C2_masterHandle);

#if FLATSAT
	initFeedback (&Feed, &LPI2C1_masterHandle);
#endif
	// Question: Set Ramp time here or keep default value??
	// -> We talked about this, we can just see how the wheels react without having a set ramp time
	// Answer: I think it's safer to set them. 10ms is the minimum
#if !FLATSAT
	rw0.reqClcMode = 0;
	rw1.reqClcMode = 0;
	rw2.reqClcMode = 0;
	rw3.reqClcMode = 0;
	rw0.rampTime = 10;
	rw1.rampTime = 10;
	rw2.rampTime = 10;
	rw3.rampTime = 10;
	commandRW (RW_CMD_STARTUP, &rw0, RWA0);
	commandRW (RW_CMD_STARTUP, &rw1, RWA1);
	commandRW (RW_CMD_STARTUP, &rw2, RWA2);
	commandRW (RW_CMD_STARTUP, &rw3, RWA3);
#endif
	/* Initialize model */
	// Question: Is this the only initialization needed?
	// Answer: just added all the orbit params for setting up flatsat tests

#if FLATSAT
	rtU.orbit_tle[0] = 21;
	rtU.orbit_tle[1] = 7.911950074430089E3;
	rtU.orbit_tle[2] = 1.7033E-4;
	rtU.orbit_tle[3] = 97.550799999999995;
	rtU.orbit_tle[4] = 2.513052E2;
	rtU.orbit_tle[5] = 0.0017553;
	rtU.orbit_tle[6] = 52.9833;
	rtU.orbit_tle[7] = 3.072997E2;
	rtU.orbit_tle[8] = 15.06695111;

	rtU.telecom[0] = 0;
	rtU.telecom[1] = 0;
	rtU.telecom[2] = 0;
	rtU.telecom[3] = 1;
	rtU.telecom[4] = 1;
	rtU.telecom[5] = 0;

	rtU.MET_utc_s = 683592486.4307597;
	rtU.MET_soar_utc_s = rtU.MET_utc_s + 10;

	rtU.quat_soar_cmd[0] = 0.200869388727445;
	rtU.quat_soar_cmd[1] = -0.603600311719593;
	rtU.quat_soar_cmd[2] = 0.740781711514794;
	rtU.quat_soar_cmd[3] = -0.215779072779279;

	rtU.target_latlonalt[0] = 5;
	rtU.target_latlonalt[1] = 105;
	rtU.target_latlonalt[2] = 0;
	rtU.triad_override = 0;

	float rwas[4] = {1000, -1000, 1000, -1000};
#endif

	FSW_Lib_initialize();

#endif
	vTaskDelayUntil(&xLastWakeTime, xDelayms);
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		PRINTF("GNC task loop\r\n");

		// Question: do we call rt_OneStep before getting new sensor reads
		// AND after getting new sensor reads?
		// Answer: only after reading from sensors
		rtU.MET_utc_s = rtU.MET_utc_s + .250;

		g_senActive = 1;
		g_rwaActive = 1;
		g_mtqActive = 1;


#if GNC_ENABLE

		/* read sensors and actuator measurements to sensor_bus */
		if (g_senActive) {

			// Question: Sun sensor has 3 possible angle readings, sun_meas_ss_deg only has 2 array indices,
			// do we discard the third reading?
			// Answer: The third value is a valid flag

			getSunAngles(&Sun1);
			rtU.sun_meas_ss_deg[0] = Sun1.angles[0];
			rtU.sun_meas_ss_deg[1] = Sun1.angles[1];
			rtU.sun_meas_valid = Sun1.isValid;

			readMagData (&Mag1);
#if FLATSAT
			rtU.mag_mag_uT[0] = Mag1.magXYZ[0];
			rtU.mag_mag_uT[1] = Mag1.magXYZ[1];
			rtU.mag_mag_uT[2] = Mag1.magXYZ[2];
			rtU.mag_mag_uT[3] = Mag1.magXYZ[0];
			rtU.mag_mag_uT[4] = Mag1.magXYZ[1];
			rtU.mag_mag_uT[5] = Mag1.magXYZ[2];
			rtU.mag_mag_uT[6] = Mag1.magXYZ[0];
			rtU.mag_mag_uT[7] = Mag1.magXYZ[1];
			rtU.mag_mag_uT[8] = Mag1.magXYZ[2];
			rtU.mag_meas_valid[0] = 1;
			rtU.mag_meas_valid[1] = 1;
			rtU.mag_meas_valid[2] = 1;
#else
			readMagData (&Mag2);
			readMagData (&Mag3);
			rtU.mag_mag_uT[0] = Mag1.magXYZ[0];
			rtU.mag_mag_uT[1] = Mag1.magXYZ[1];
			rtU.mag_mag_uT[2] = Mag1.magXYZ[2];
			rtU.mag_mag_uT[3] = Mag2.magXYZ[0];
			rtU.mag_mag_uT[4] = Mag2.magXYZ[1];
			rtU.mag_mag_uT[5] = Mag2.magXYZ[2];
			rtU.mag_mag_uT[6] = Mag3.magXYZ[0];
			rtU.mag_mag_uT[7] = Mag3.magXYZ[1];
			rtU.mag_mag_uT[8] = Mag3.magXYZ[2];
			rtU.mag_meas_valid[0] = (Mag1.errorFlag == 0);
			rtU.mag_meas_valid[1] = (Mag2.errorFlag == 0);
			rtU.mag_meas_valid[2] = (Mag3.errorFlag == 0);
#endif

//			readPhdData (&Phd1,  &LPI2C2_masterHandle);
			rtU.photodiodes_uA[0] = Phd1.current[0];
			rtU.photodiodes_uA[1] = Phd1.current[1];
			rtU.photodiodes_uA[2] = Phd1.current[2];
			rtU.photodiodes_uA[3] = Phd1.current[3];
			rtU.photodiodes_uA[4] = Phd1.current[4];
//			rtU.phd_meas_valid[0] = (Phd1.errorFlag == 0);
//			rtU.phd_meas_valid[1] = (Phd1.errorFlag == 0);
//			rtU.phd_meas_valid[2] = (Phd1.errorFlag == 0);
//			rtU.phd_meas_valid[3] = (Phd1.errorFlag == 0);
//			rtU.phd_meas_valid[4] = 0;

			readGyroData (&Gyro1);
#if FLATSAT
			rtU.gyro_gyro_radps[0] = Gyro1.gyroXYZ[0];
			rtU.gyro_gyro_radps[1] = Gyro1.gyroXYZ[1];
			rtU.gyro_gyro_radps[2] = Gyro1.gyroXYZ[2];
			rtU.gyro_gyro_radps[3] = Gyro1.gyroXYZ[0];
			rtU.gyro_gyro_radps[4] = Gyro1.gyroXYZ[1];
			rtU.gyro_gyro_radps[5] = Gyro1.gyroXYZ[2];
			rtU.gyro_gyro_radps[6] = Gyro1.gyroXYZ[0];
			rtU.gyro_gyro_radps[7] = Gyro1.gyroXYZ[1];
			rtU.gyro_gyro_radps[8] = Gyro1.gyroXYZ[2];
			rtU.gyro_meas_valid[0] = 1;
			rtU.gyro_meas_valid[1] = 1;
			rtU.gyro_meas_valid[2] = 1;
#else
			readGyroData (&Gyro2);
			readGyroData (&Gyro3);
			rtU.gyro_gyro_radps[0] = Gyro1.gyroXYZ[0];
			rtU.gyro_gyro_radps[1] = Gyro1.gyroXYZ[1];
			rtU.gyro_gyro_radps[2] = Gyro1.gyroXYZ[2];
			rtU.gyro_gyro_radps[3] = Gyro1.gyroXYZ[0];
			rtU.gyro_gyro_radps[4] = Gyro1.gyroXYZ[1];
			rtU.gyro_gyro_radps[5] = Gyro1.gyroXYZ[2];
			rtU.gyro_gyro_radps[6] = Gyro1.gyroXYZ[0];
			rtU.gyro_gyro_radps[7] = Gyro1.gyroXYZ[1];
			rtU.gyro_gyro_radps[8] = Gyro1.gyroXYZ[2];

			rtU.gyro_meas_valid[0] = (Gyro1.errorFlag == 0);
			rtU.gyro_meas_valid[1] = (Gyro2.errorFlag == 0);
			rtU.gyro_meas_valid[2] = (Gyro3.errorFlag == 0);
#endif
		}

		if (g_rwaActive) {
#if FLATSAT
			rtU.rwa_rpm[0] = rtY.rwa_cmd_rpm[0];
			rtU.rwa_rpm[1] = rtY.rwa_cmd_rpm[1];
			rtU.rwa_rpm[2] = rtY.rwa_cmd_rpm[2];
			rtU.rwa_rpm[3] = rtY.rwa_cmd_rpm[3];
			rtU.rwa_valid[0] = 1;
			rtU.rwa_valid[1] = 1;
			rtU.rwa_valid[2] = 1;
			rtU.rwa_valid[3] = 1;

			printf ("RWA Speeds: %f, %f, %f, %f\r\n", rw0.currSpeed_double, rw1.currSpeed, rw2.currSpeed, rw3.currSpeed);
			printf ("RTU inputs: %f, %f, %f, %f\r\n", rtU.rwa_rpm[0], rtU.rwa_rpm[1], rtU.rwa_rpm[2], rtU.rwa_rpm[3]);
#else
			commandRW (RW_CMD_READ_SPEED, &rw0, RWA0);
			commandRW (RW_CMD_READ_SPEED, &rw1, RWA1);
			commandRW (RW_CMD_READ_SPEED, &rw2, RWA2);
			commandRW (RW_CMD_READ_SPEED, &rw3, RWA3);
			rtU.rwa_rpm[0] = rw0.currSpeed;
			rtU.rwa_rpm[1] = rw1.currSpeed;
			rtU.rwa_rpm[2] = rw2.currSpeed;
			rtU.rwa_rpm[3] = rw3.currSpeed;
			rtU.rwa_valid[0] = (rw0.state != 0);
			rtU.rwa_valid[1] = (rw1.state != 0);
			rtU.rwa_valid[2] = (rw2.state != 0);
			rtU.rwa_valid[3] = (rw3.state != 0);
#endif
		}

		if (g_mtqActive) {

			// Question: We don't actually get any data from mtq's, and there are
			// 5 mtq_valid indices in the struct but only 3 mtq's?
			// Answer: I didn't know about the current monitering feature when writing the mtq wrapper
			rtU.mtq_valid[0] = 1;
			rtU.mtq_valid[1] = 1;
			rtU.mtq_valid[2] = 1;
			rtU.mtq_valid[3] = 1;
			rtU.mtq_valid[4] = 1;
		}

		/* call GNC rt_OneStep() */
//		 rt_OneStep();

		/* write to actuators */
		if (g_rwaActive) {
			rw0.reqSpeed = rtY.rwa_cmd_rpm[0];
			rw1.reqSpeed = rtY.rwa_cmd_rpm[1];
			rw2.reqSpeed = rtY.rwa_cmd_rpm[2];
			rw3.reqSpeed = rtY.rwa_cmd_rpm[3];
#if !FLATSAT
			commandRW (RW_CMD_SET_SPEED, &rw0, RWA0);
			commandRW (RW_CMD_SET_SPEED, &rw1, RWA1);
			commandRW (RW_CMD_SET_SPEED, &rw2, RWA2);
			commandRW (RW_CMD_SET_SPEED, &rw3, RWA3);
#endif
		}

		if (g_mtqActive) {
			float x = rtY.mtq_cmd_Am2[0] - rtY.mtq_cmd_Am2[1];
			float y = rtY.mtq_cmd_Am2[2] - rtY.mtq_cmd_Am2[3];
			float z = rtY.mtq_cmd_Am2[4];
#if !FLATSAT
			setMoments (x, y, z, &mtq);
#endif
		}

#if FLATSAT // Options for flatsat debug optputs
		float mtqs[3] = {rtY.mtq_cmd_Am2[0] - rtY.mtq_cmd_Am2[1], rtY.mtq_cmd_Am2[2] - rtY.mtq_cmd_Am2[3], rtY.mtq_cmd_Am2[4]};
		rwas[0] = rtY.rwa_cmd_rpm[0];
		rwas[1] = rtY.rwa_cmd_rpm[1];
		rwas[2] = rtY.rwa_cmd_rpm[2];
		rwas[3] = rtY.rwa_cmd_rpm[3];

		setFeedback(mtqs, rwas, rtY.gnc_mode, &Feed);
		writeFeedback(&Feed);

		// Udate newest telemetry data to proper index in array
//		GNC_payload[data_iter] = rtY.fsw_telem;
//		(data_iter == max_telemDownlink - 1)? data_iter = 0: data_iter += 1;

//		printf ("Time we updated: %f\r\n", rtU.MET_utc_s);
//		printf ("ace_err = %.10f\r\n", rtY.ace_err);
//
//		printf ("r_eci_m = %f, %f, %f\r\n", rtY.r_eci_m[0] / 1000, rtY.r_eci_m[1] / 1000, rtY.r_eci_m[2] / 1000);
//
//		printf ("cmd_quat: %f, %f, %f, %f\r\n", rtY.cmd_quat[0], rtY.cmd_quat[1], rtY.cmd_quat[2], rtY.cmd_quat[3]);
//		printf ("sc_quat: %f, %f, %f, %f\r\n", rtY.sc_quat[0], rtY.sc_quat[1], rtY.sc_quat[2], rtY.sc_quat[3]);
//
//		printf ("Gyro values: %f, %f, %f\r\n", Gyro1.gyroXYZ[0], Gyro1.gyroXYZ[1], Gyro1.gyroXYZ[2]);
//		printf ("RWA Commands: %f, %f, %f, %f\r\n", rtY.rwa_cmd_rpm[0], rtY.rwa_cmd_rpm[1], rtY.rwa_cmd_rpm[2], rtY.rwa_cmd_rpm[3]);
//		printf ("Rotation rate %f, %f, %f\r\n", rtY.sc_body_rates_radps[0], rtY.sc_body_rates_radps[1], rtY.sc_body_rates_radps[2]);
//		printf ("GNC mode %d\r\n", rtY.gnc_mode);
//		printf ("test val = %f, %f, %f\r\n", rtY.r_eci_m[0], rtY.r_eci_m[1], rtY.r_eci_m[2]);
//		printf ("Mag measurements: %f, %f, %f\r\n", Mag1.magXYZ[0], Mag1.magXYZ[1], Mag1.magXYZ[2]);
#endif

		// Question: Is this what you had in mind for storing telemetry data?
		// It's an array of the last (max_telemDownlink) FSW_telem's gathered

		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#else
		vTaskDelayUntil(&xLastWakeTime, xDelayms);
	}
#endif
}
