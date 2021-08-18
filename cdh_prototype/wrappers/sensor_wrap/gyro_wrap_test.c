#define SPOOF	1
#include "gyro_wrap_test.h"
#include "fsl_debug_console.h"
void test_initGyro() {
  PRINTF("Testing initGyro...\n");
	initGyro(&Gyro1, &i2c1_m_rtos_handle);
  if (Gyro1.gyroInitialized) {
	  PRINTF("Gyro initialized\n");
	  PRINTF("Pass\n");
  } else {
	  PRINTF("Gryo failed to be initialized\n");
	  PRINTF("Fail\n");
  }
  PRINTF("********************\n");
}

void test_readRegsGyro() {
	PRINTF("Testing raedRegs...\n");
#if SPOOF
  uint8_t referenceRawData[6] = {0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110};
  uint8_t readRawData[6];
  initGyro(&Gyro1, &i2c1_m_rtos_handle);
  readRegsGyro(GYRO_OUT_X_MSB, &readRawData[0], 6, &Gyro1);
  PRINTF("Reference raw data  Read raw data Result\n");

  for (int i = 0; i < 6; i++) {
	  PRINTF("%x	%x	",referenceRawData[i], readRawData[i]);
    if (referenceRawData[i] == readRawData[i]) {
    	PRINTF("Pass\n");
    } else {
    	PRINTF("Fail\n");
    }
  }
  PRINTF("********************\n");
#else
  uint8_t referenceRawData[15] = {0, 0, 0, 0, 8, 0xD7, 0, 0,
                                  0, 0, 1, 0, 0, 0,    0};
  uint8_t readRawData[15];
  initGyro(&Gyro1, &i2c1_m_rtos_handle);
  readRegsGyro(0x07, &readRawData[0], 15, &Gyro1);
  PRINTF("Reference raw data  Read raw data Result\n");

  for (int i = 0; i < 15; i++) {
	  PRINTF("%x	%x	",referenceRawData[i], readRawData[i]);
    if (referenceRawData[i] == readRawData[i]) {
    	PRINTF("Pass\n");
    } else {
    	PRINTF("Fail\n");
    }
  }
  PRINTF("********************\n");
#endif
}

void test_writeRegGyro() {

	PRINTF("Testing writeRegGyro...\n");
  uint8_t referenceValue = 2;
  PRINTF("Reference value:	%d\n", referenceValue);
	initGyro(&Gyro1, &i2c1_m_rtos_handle);
  writeRegGyro(GYRO_CTRL_REG1, referenceValue, &Gyro1);
  uint8_t readValue;
  readRegsGyro(GYRO_CTRL_REG1, &readValue, 1, &Gyro1);
  PRINTF("Read value: %hhd	", readValue);
  if (readValue == referenceValue) {
	  PRINTF("Pass\n");
  } else {
    PRINTF("Fail\n");
  }
  PRINTF("********************\n");
}

void test_startGyro() {
	PRINTF("Test startGyro...\n");
	PRINTF("Reference CTRL_REG0:	%x\n", GYRO_FSR_NUM);
	PRINTF("Reference CTRL_REG1:	%x\n", (GYRO_ODR_NUM << 2) | 0b10);

	initGyro(&Gyro1, &i2c1_m_rtos_handle);
	startGyro(&Gyro1);

  uint8_t readCtrlReg0;
  readRegsGyro(GYRO_CTRL_REG0, &readCtrlReg0, 1, &Gyro1);
  PRINTF("Read CTRL_REG0:	%x	", readCtrlReg0);
  if (readCtrlReg0 == GYRO_FSR_NUM) {
	  PRINTF("Pass\n");
  } else {
	  PRINTF("Fail\n");
  }

  uint8_t readCtrlReg1;
  readRegsGyro(GYRO_CTRL_REG1, &readCtrlReg1, 1, &Gyro1);
  PRINTF("Read CTRL_REG1:	%x	", readCtrlReg1);
  if (readCtrlReg1 == ((GYRO_ODR_NUM << 2) | 0b10)) {
	  PRINTF("Pass\n");
  } else {
	  PRINTF("Fail\n");
  }
  PRINTF("********************\n");
}

void test_restGyro() {
#if SPOOF
	PRINTF("Test restGyro...\n");
	initGyro(&Gyro1, &i2c1_m_rtos_handle);
  startGyro(&Gyro1);
  PRINTF("Start the Gyro\n");
  resetGyro(&Gyro1);
  PRINTF("Rest the gyro\n");

  uint8_t referenceRawData[6] = {0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110};
  uint8_t readRawData[6];
  readRegsGyro(GYRO_OUT_X_MSB, &readRawData[0], 6, &Gyro1);

  PRINTF("Reference raw data  Read raw data Result\n");

  for (int i = 0; i < 6; i++) {
	  PRINTF("%x	%x	",referenceRawData[i], readRawData[i]);
    if (referenceRawData[i] == readRawData[i]) {
    	PRINTF("Pass\n");
    } else {
    	PRINTF("Fail\n");
    }
  }
#else
	PRINTF("Test restGyro...\n");
	initGyro(&Gyro1, &i2c1_m_rtos_handle);
  startGyro(&Gyro1);
  PRINTF("Start the Gyro\n");
  resetGyro(&Gyro1);
  PRINTF("Rest the gyro\n");

  uint8_t referenceRawData[15] = {0, 0, 0, 0, 8, 0xD7, 0, 0,
                                  0, 0, 1, 0, 0, 0,    0};
  uint8_t readRawData[15];
  readRegsGyro(0x07, &readRawData[0], 15, &Gyro1);

  PRINTF("Reference raw data  Read raw data Result\n");

  for (int i = 0; i < 15; i++) {
	  PRINTF("%x	%x	",referenceRawData[i], readRawData[i]);
    if (referenceRawData[i] == readRawData[i]) {
    	PRINTF("Pass\n");
    } else {
    	PRINTF("Fail\n");
    }
  }
#endif
}


#define PRINT_READINGS 1

void print_float(float a) {
	if (a < 0) {
		PRINTF("-");
		a = -a;
	}
	long x = (long) a;
	PRINTF("%ld.",x);
	PRINTF("%ld	",(long) (a*10000000) - x*10000000);
}

void gyro_wrap_test_setup()
{
  PRINTF("Tests begin\n");
  PRINTF("********************\n");
//
  test_initGyro();
  test_readRegsGyro();
  test_writeRegGyro();
  test_startGyro();
  test_restGyro();

	quickStartGyro(&Gyro1, &i2c1_m_rtos_handle);
}
void gyro_wrap_test_loop()
{
#if PRINT_READINGS
	readGyroData(&Gyro1);
	for (int i = 0; i < 3; i++) {
		print_float(Gyro1.gyroXYZ[i]);
	}
	PRINTF("\n");
#endif
}
