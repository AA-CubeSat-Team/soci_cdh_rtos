/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v6.0
processor: MIMXRT1052xxxxB
package_id: MIMXRT1052DVL6B
mcu_data: ksdk2_0
processor_version: 6.0.1
board: IMXRT1050-EVKB
functionalGroups:
- name: BOARD_InitPeripherals
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system_54b53072540eeeb8f8e9343e71f28176'
- global_system_definitions: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'msg'
- type_id: 'msg_6e2baaf3b97dbeef01c0043275f9a0e7'
- global_messages: []
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * SEMC_1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'SEMC_1'
- type: 'semc'
- mode: 'basic'
- type_id: 'semc_d3a530ecfc3f527ce59c92b1deb0f7ea'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'SEMC'
- config_sets:
  - fsl_semc:
    - clockConfig:
      - clockSource: 'kSEMC_ClkSrcPeri'
      - clockSourceFreq: 'BOARD_BootClockRUN'
    - semc_config_t:
      - dqsMode: 'kSEMC_Loopbackdqspad'
      - cmdTimeoutCycles: '0'
      - busTimeoutCycles: '0'
    - semc_sdram_config_t:
      - csxPinMux: 'kSEMC_MUXCSX0'
      - semcSdramCs: 'kSEMC_SDRAM_CS0'
      - address: '0x80000000'
      - memsize_kbytes: '32'
      - portSize: 'kSEMC_PortSize16Bit'
      - burstLen: 'kSEMC_Sdram_BurstLen1'
      - columnAddrBitNum: 'kSEMC_SdramColunm_9bit'
      - casLatency: 'kSEMC_LatencyThree'
      - tPrecharge2Act_Ns: '18'
      - tAct2ReadWrite_Ns: '18'
      - tRefreshRecovery_Ns: '127'
      - tWriteRecovery_Ns: '12'
      - tCkeOff_Ns: '42'
      - tAct2Prechage_Ns: '42'
      - tSelfRefRecovery_Ns: '67'
      - tRefresh2Refresh_Ns: '60'
      - tAct2Act_Ns: '60'
      - tPrescalePeriod_Ns: '160'
      - tIdleTimeout_Ns: '0'
      - refreshPeriod_nsPerRow: '64'
      - refreshUrgThreshold: '64'
      - refreshBurstLen: '1'
    - quick_selection: 'SEMC_Type'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const semc_config_t SEMC_1_config = {
  .dqsMode = kSEMC_Loopbackdqspad,
  .cmdTimeoutCycles = 0,
  .busTimeoutCycles = 0
};
const semc_sdram_config_t SEMC_1_SDRAM_config = {
  .csxPinMux = kSEMC_MUXCSX0,
  .address = 2147483648,
  .memsize_kbytes = 32,
  .portSize = kSEMC_PortSize16Bit,
  .burstLen = kSEMC_Sdram_BurstLen1,
  .columnAddrBitNum = kSEMC_SdramColunm_9bit,
  .casLatency = kSEMC_LatencyThree,
  .tPrecharge2Act_Ns = 18,
  .tAct2ReadWrite_Ns = 18,
  .tRefreshRecovery_Ns = 127,
  .tWriteRecovery_Ns = 12,
  .tCkeOff_Ns = 42,
  .tAct2Prechage_Ns = 42,
  .tSelfRefRecovery_Ns = 67,
  .tRefresh2Refresh_Ns = 60,
  .tAct2Act_Ns = 60,
  .tPrescalePeriod_Ns = 160,
  .refreshPeriod_nsPerRow = 64,
  .refreshUrgThreshold = 64,
  .refreshBurstLen = 1
};

void SEMC_1_init(void) {
  /* Initialize SEMC peripheral. */
  SEMC_Init(SEMC_1_PERIPHERAL, &SEMC_1_config);
  /* Initialize SEMC SDRAM. */
  SEMC_ConfigureSDRAM(SEMC_1_PERIPHERAL, kSEMC_SDRAM_CS0, &SEMC_1_SDRAM_config, 75000000);
}

/***********************************************************************************************************************
 * LPSPI_1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPSPI_1'
- type: 'lpspi'
- mode: 'polling'
- type_id: 'lpspi_6e21a1e0a09f0a012d683c4f91752db8'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPSPI1'
- config_sets:
  - main:
    - mode: 'kLPSPI_Master'
    - clockSource: 'LpspiClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - master:
      - baudRate: '500000'
      - bitsPerFrame: '8'
      - cpol: 'kLPSPI_ClockPolarityActiveHigh'
      - cpha: 'kLPSPI_ClockPhaseFirstEdge'
      - direction: 'kLPSPI_MsbFirst'
      - pcsToSckDelayInNanoSec: '1000'
      - lastSckToPcsDelayInNanoSec: '1000'
      - betweenTransferDelayInNanoSec: '1000'
      - whichPcs: 'kLPSPI_Pcs0'
      - pcsActiveHighOrLow: 'kLPSPI_PcsActiveLow'
      - pinCfg: 'kLPSPI_SdiInSdoOut'
      - dataOutConfig: 'kLpspiDataOutRetained'
    - quick_selection: 'qs_master'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpspi_master_config_t LPSPI_1_config = {
  .baudRate = 500000,
  .bitsPerFrame = 8,
  .cpol = kLPSPI_ClockPolarityActiveHigh,
  .cpha = kLPSPI_ClockPhaseFirstEdge,
  .direction = kLPSPI_MsbFirst,
  .pcsToSckDelayInNanoSec = 1000,
  .lastSckToPcsDelayInNanoSec = 1000,
  .betweenTransferDelayInNanoSec = 1000,
  .whichPcs = kLPSPI_Pcs0,
  .pcsActiveHighOrLow = kLPSPI_PcsActiveLow,
  .pinCfg = kLPSPI_SdiInSdoOut,
  .dataOutConfig = kLpspiDataOutRetained
};



// NON-RTOS!!



void LPSPI_1_init(void) {
  LPSPI_MasterInit(LPSPI_1_PERIPHERAL, &LPSPI_1_config, LPSPI_1_CLOCK_FREQ);
}

/***********************************************************************************************************************
 * LPUART_1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPUART_1'
- type: 'lpuart'
- mode: 'polling'
- type_id: 'lpuart_bebe3e12b6ec22bbd14199038f2bf459'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPUART8'
- config_sets:
  - lpuartConfig_t:
    - lpuartConfig:
      - clockSource: 'LpuartClock'
      - lpuartSrcClkFreq: 'BOARD_BootClockRUN'
      - baudRate_Bps: '115200'
      - parityMode: 'kLPUART_ParityDisabled'
      - dataBitsCount: 'kLPUART_EightDataBits'
      - isMsb: 'false'
      - stopBitCount: 'kLPUART_OneStopBit'
      - txFifoWatermark: '0'
      - rxFifoWatermark: '1'
      - enableRxRTS: 'false'
      - enableTxCTS: 'false'
      - txCtsSource: 'kLPUART_CtsSourcePin'
      - txCtsConfig: 'kLPUART_CtsSampleAtStart'
      - rxIdleType: 'kLPUART_IdleTypeStartBit'
      - rxIdleConfig: 'kLPUART_IdleCharacter1'
      - enableTx: 'true'
      - enableRx: 'true'
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpuart_config_t LPUART_1_config = {
  .baudRate_Bps = 115200,
  .parityMode = kLPUART_ParityDisabled,
  .dataBitsCount = kLPUART_EightDataBits,
  .isMsb = false,
  .stopBitCount = kLPUART_OneStopBit,
  .txFifoWatermark = 0,
  .rxFifoWatermark = 1,
  .enableRxRTS = false,
  .enableTxCTS = false,
  .txCtsSource = kLPUART_CtsSourcePin,
  .txCtsConfig = kLPUART_CtsSampleAtStart,
  .rxIdleType = kLPUART_IdleTypeStartBit,
  .rxIdleConfig = kLPUART_IdleCharacter1,
  .enableTx = true,
  .enableRx = true
};

void LPUART_1_init(void) {
  LPUART_Init(LPUART_1_PERIPHERAL, &LPUART_1_config, LPUART_1_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * LPUART_2 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPUART_2'
- type: 'lpuart'
- mode: 'polling'
- type_id: 'lpuart_bebe3e12b6ec22bbd14199038f2bf459'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPUART3'
- config_sets:
  - lpuartConfig_t:
    - lpuartConfig:
      - clockSource: 'LpuartClock'
      - lpuartSrcClkFreq: 'BOARD_BootClockRUN'
      - baudRate_Bps: '115200'
      - parityMode: 'kLPUART_ParityDisabled'
      - dataBitsCount: 'kLPUART_EightDataBits'
      - isMsb: 'false'
      - stopBitCount: 'kLPUART_OneStopBit'
      - txFifoWatermark: '0'
      - rxFifoWatermark: '1'
      - enableRxRTS: 'false'
      - enableTxCTS: 'false'
      - txCtsSource: 'kLPUART_CtsSourcePin'
      - txCtsConfig: 'kLPUART_CtsSampleAtStart'
      - rxIdleType: 'kLPUART_IdleTypeStartBit'
      - rxIdleConfig: 'kLPUART_IdleCharacter1'
      - enableTx: 'true'
      - enableRx: 'true'
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpuart_config_t LPUART_2_config = {
  .baudRate_Bps = 115200,
  .parityMode = kLPUART_ParityDisabled,
  .dataBitsCount = kLPUART_EightDataBits,
  .isMsb = false,
  .stopBitCount = kLPUART_OneStopBit,
  .txFifoWatermark = 0,
  .rxFifoWatermark = 1,
  .enableRxRTS = false,
  .enableTxCTS = false,
  .txCtsSource = kLPUART_CtsSourcePin,
  .txCtsConfig = kLPUART_CtsSampleAtStart,
  .rxIdleType = kLPUART_IdleTypeStartBit,
  .rxIdleConfig = kLPUART_IdleCharacter1,
  .enableTx = true,
  .enableRx = true
};

void LPUART_2_init(void) {
  LPUART_Init(LPUART_2_PERIPHERAL, &LPUART_2_config, LPUART_2_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * LPUART_3 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPUART_3'
- type: 'lpuart'
- mode: 'polling'
- type_id: 'lpuart_bebe3e12b6ec22bbd14199038f2bf459'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPUART2'
- config_sets:
  - lpuartConfig_t:
    - lpuartConfig:
      - clockSource: 'LpuartClock'
      - lpuartSrcClkFreq: 'BOARD_BootClockRUN'
      - baudRate_Bps: '115200'
      - parityMode: 'kLPUART_ParityDisabled'
      - dataBitsCount: 'kLPUART_EightDataBits'
      - isMsb: 'false'
      - stopBitCount: 'kLPUART_OneStopBit'
      - txFifoWatermark: '0'
      - rxFifoWatermark: '1'
      - enableRxRTS: 'false'
      - enableTxCTS: 'false'
      - txCtsSource: 'kLPUART_CtsSourcePin'
      - txCtsConfig: 'kLPUART_CtsSampleAtStart'
      - rxIdleType: 'kLPUART_IdleTypeStartBit'
      - rxIdleConfig: 'kLPUART_IdleCharacter1'
      - enableTx: 'true'
      - enableRx: 'true'
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpuart_config_t LPUART_3_config = {
  .baudRate_Bps = 115200,
  .parityMode = kLPUART_ParityDisabled,
  .dataBitsCount = kLPUART_EightDataBits,
  .isMsb = false,
  .stopBitCount = kLPUART_OneStopBit,
  .txFifoWatermark = 0,
  .rxFifoWatermark = 1,
  .enableRxRTS = false,
  .enableTxCTS = false,
  .txCtsSource = kLPUART_CtsSourcePin,
  .txCtsConfig = kLPUART_CtsSampleAtStart,
  .rxIdleType = kLPUART_IdleTypeStartBit,
  .rxIdleConfig = kLPUART_IdleCharacter1,
  .enableTx = true,
  .enableRx = true
};

void LPUART_3_init(void) {
  LPUART_Init(LPUART_3_PERIPHERAL, &LPUART_3_config, LPUART_3_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * LPI2C_1 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPI2C_1'
- type: 'lpi2c'
- mode: 'master'
- type_id: 'lpi2c_db68d4f4f06a22e25ab51fe9bd6db4d2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPI2C1'
- config_sets:
  - main:
    - clockSource: 'Lpi2cClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - interrupt:
      - IRQn: 'LPI2C1_IRQn'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - quick_selection: 'qs_interrupt'
  - master:
    - mode: 'transfer'
    - config:
      - enableMaster: 'true'
      - enableDoze: 'true'
      - debugEnable: 'false'
      - ignoreAck: 'false'
      - pinConfig: 'kLPI2C_2PinOpenDrain'
      - baudRate_Hz: '100000'
      - busIdleTimeout_ns: '0'
      - pinLowTimeout_ns: '0'
      - sdaGlitchFilterWidth_ns: '0'
      - sclGlitchFilterWidth_ns: '0'
      - hostRequest:
        - enable: 'false'
        - source: 'kLPI2C_HostRequestExternalPin'
        - polarity: 'kLPI2C_HostRequestPinActiveHigh'
    - transfer:
      - blocking: 'false'
      - flags: ''
      - slaveAddress: '0'
      - direction: 'kLPI2C_Write'
      - subaddress: '0'
      - subaddressSize: '1'
      - dataSize: '1'
      - callback:
        - name: ''
        - userData: ''
    - quick_selection: 'qs_master_transfer'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpi2c_master_config_t LPI2C_1_masterConfig = {
  .enableMaster = true,
  .enableDoze = true,
  .debugEnable = false,
  .ignoreAck = false,
  .pinConfig = kLPI2C_2PinOpenDrain,
  .baudRate_Hz = 100000,
  .busIdleTimeout_ns = 0,
  .pinLowTimeout_ns = 0,
  .sdaGlitchFilterWidth_ns = 0,
  .sclGlitchFilterWidth_ns = 0,
  .hostRequest = {
    .enable = false,
    .source = kLPI2C_HostRequestExternalPin,
    .polarity = kLPI2C_HostRequestPinActiveHigh
  }
};
lpi2c_master_transfer_t LPI2C_1_masterTransfer = {
  .flags = kLPI2C_TransferDefaultFlag,
  .slaveAddress = 0,
  .direction = kLPI2C_Write,
  .subaddress = 0,
  .subaddressSize = 1,
  .data = LPI2C_1_masterBuffer,
  .dataSize = 1
};
lpi2c_master_handle_t LPI2C_1_masterHandle;
uint8_t LPI2C_1_masterBuffer[LPI2C_1_MASTER_BUFFER_SIZE];

void LPI2C_1_init(void) {
  LPI2C_MasterInit(LPI2C_1_PERIPHERAL, &LPI2C_1_masterConfig, LPI2C_1_CLOCK_FREQ);
  LPI2C_MasterTransferCreateHandle(LPI2C_1_PERIPHERAL, &LPI2C_1_masterHandle, NULL, NULL);
}

/***********************************************************************************************************************
 * LPI2C_2 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPI2C_2'
- type: 'lpi2c'
- mode: 'master'
- type_id: 'lpi2c_db68d4f4f06a22e25ab51fe9bd6db4d2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPI2C2'
- config_sets:
  - main:
    - clockSource: 'Lpi2cClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - interrupt:
      - IRQn: 'LPI2C2_IRQn'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - quick_selection: 'qs_interrupt'
  - master:
    - mode: 'transfer'
    - config:
      - enableMaster: 'true'
      - enableDoze: 'true'
      - debugEnable: 'false'
      - ignoreAck: 'false'
      - pinConfig: 'kLPI2C_2PinOpenDrain'
      - baudRate_Hz: '100000'
      - busIdleTimeout_ns: '0'
      - pinLowTimeout_ns: '0'
      - sdaGlitchFilterWidth_ns: '0'
      - sclGlitchFilterWidth_ns: '0'
      - hostRequest:
        - enable: 'false'
        - source: 'kLPI2C_HostRequestExternalPin'
        - polarity: 'kLPI2C_HostRequestPinActiveHigh'
    - transfer:
      - blocking: 'false'
      - flags: ''
      - slaveAddress: '0'
      - direction: 'kLPI2C_Write'
      - subaddress: '0'
      - subaddressSize: '1'
      - dataSize: '1'
      - callback:
        - name: ''
        - userData: ''
    - quick_selection: 'qs_master_transfer'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpi2c_master_config_t LPI2C_2_masterConfig = {
  .enableMaster = true,
  .enableDoze = true,
  .debugEnable = false,
  .ignoreAck = false,
  .pinConfig = kLPI2C_2PinOpenDrain,
  .baudRate_Hz = 100000,
  .busIdleTimeout_ns = 0,
  .pinLowTimeout_ns = 0,
  .sdaGlitchFilterWidth_ns = 0,
  .sclGlitchFilterWidth_ns = 0,
  .hostRequest = {
    .enable = false,
    .source = kLPI2C_HostRequestExternalPin,
    .polarity = kLPI2C_HostRequestPinActiveHigh
  }
};
lpi2c_master_transfer_t LPI2C_2_masterTransfer = {
  .flags = kLPI2C_TransferDefaultFlag,
  .slaveAddress = 0,
  .direction = kLPI2C_Write,
  .subaddress = 0,
  .subaddressSize = 1,
  .data = LPI2C_2_masterBuffer,
  .dataSize = 1
};
lpi2c_master_handle_t LPI2C_2_masterHandle;
uint8_t LPI2C_2_masterBuffer[LPI2C_2_MASTER_BUFFER_SIZE];

void LPI2C_2_init(void) {
  LPI2C_MasterInit(LPI2C_2_PERIPHERAL, &LPI2C_2_masterConfig, LPI2C_2_CLOCK_FREQ);
  LPI2C_MasterTransferCreateHandle(LPI2C_2_PERIPHERAL, &LPI2C_2_masterHandle, NULL, NULL);
}

/***********************************************************************************************************************
 * LPUART_4 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPUART_4'
- type: 'lpuart'
- mode: 'polling'
- type_id: 'lpuart_bebe3e12b6ec22bbd14199038f2bf459'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPUART1'
- config_sets:
  - lpuartConfig_t:
    - lpuartConfig:
      - clockSource: 'LpuartClock'
      - lpuartSrcClkFreq: 'BOARD_BootClockRUN'
      - baudRate_Bps: '115200'
      - parityMode: 'kLPUART_ParityDisabled'
      - dataBitsCount: 'kLPUART_EightDataBits'
      - isMsb: 'false'
      - stopBitCount: 'kLPUART_OneStopBit'
      - txFifoWatermark: '0'
      - rxFifoWatermark: '1'
      - enableRxRTS: 'false'
      - enableTxCTS: 'false'
      - txCtsSource: 'kLPUART_CtsSourcePin'
      - txCtsConfig: 'kLPUART_CtsSampleAtStart'
      - rxIdleType: 'kLPUART_IdleTypeStartBit'
      - rxIdleConfig: 'kLPUART_IdleCharacter1'
      - enableTx: 'true'
      - enableRx: 'true'
    - quick_selection: 'QuickSelection1'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpuart_config_t LPUART_4_config = {
  .baudRate_Bps = 115200,
  .parityMode = kLPUART_ParityDisabled,
  .dataBitsCount = kLPUART_EightDataBits,
  .isMsb = false,
  .stopBitCount = kLPUART_OneStopBit,
  .txFifoWatermark = 0,
  .rxFifoWatermark = 1,
  .enableRxRTS = false,
  .enableTxCTS = false,
  .txCtsSource = kLPUART_CtsSourcePin,
  .txCtsConfig = kLPUART_CtsSampleAtStart,
  .rxIdleType = kLPUART_IdleTypeStartBit,
  .rxIdleConfig = kLPUART_IdleCharacter1,
  .enableTx = true,
  .enableRx = true
};

void LPUART_4_init(void) {
  LPUART_Init(LPUART_4_PERIPHERAL, &LPUART_4_config, LPUART_4_CLOCK_SOURCE);
}

/***********************************************************************************************************************
 * LPI2C_3 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPI2C_3'
- type: 'lpi2c'
- mode: 'master'
- type_id: 'lpi2c_db68d4f4f06a22e25ab51fe9bd6db4d2'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPI2C3'
- config_sets:
  - main:
    - clockSource: 'Lpi2cClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - interrupt:
      - IRQn: 'LPI2C3_IRQn'
      - enable_priority: 'false'
      - priority: '0'
      - enable_custom_name: 'false'
    - quick_selection: 'qs_interrupt'
  - master:
    - mode: 'transfer'
    - config:
      - enableMaster: 'true'
      - enableDoze: 'true'
      - debugEnable: 'false'
      - ignoreAck: 'false'
      - pinConfig: 'kLPI2C_2PinOpenDrain'
      - baudRate_Hz: '100000'
      - busIdleTimeout_ns: '0'
      - pinLowTimeout_ns: '0'
      - sdaGlitchFilterWidth_ns: '0'
      - sclGlitchFilterWidth_ns: '0'
      - hostRequest:
        - enable: 'false'
        - source: 'kLPI2C_HostRequestExternalPin'
        - polarity: 'kLPI2C_HostRequestPinActiveHigh'
    - transfer:
      - blocking: 'false'
      - flags: ''
      - slaveAddress: '0'
      - direction: 'kLPI2C_Write'
      - subaddress: '0'
      - subaddressSize: '1'
      - dataSize: '1'
      - callback:
        - name: ''
        - userData: ''
    - quick_selection: 'qs_master_transfer'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpi2c_master_config_t LPI2C_3_masterConfig = {
  .enableMaster = true,
  .enableDoze = true,
  .debugEnable = false,
  .ignoreAck = false,
  .pinConfig = kLPI2C_2PinOpenDrain,
  .baudRate_Hz = 100000,
  .busIdleTimeout_ns = 0,
  .pinLowTimeout_ns = 0,
  .sdaGlitchFilterWidth_ns = 0,
  .sclGlitchFilterWidth_ns = 0,
  .hostRequest = {
    .enable = false,
    .source = kLPI2C_HostRequestExternalPin,
    .polarity = kLPI2C_HostRequestPinActiveHigh
  }
};
lpi2c_master_transfer_t LPI2C_3_masterTransfer = {
  .flags = kLPI2C_TransferDefaultFlag,
  .slaveAddress = 0,
  .direction = kLPI2C_Write,
  .subaddress = 0,
  .subaddressSize = 1,
  .data = LPI2C_3_masterBuffer,
  .dataSize = 1
};
lpi2c_master_handle_t LPI2C_3_masterHandle;
uint8_t LPI2C_3_masterBuffer[LPI2C_3_MASTER_BUFFER_SIZE];

void LPI2C_3_init(void) {
  LPI2C_MasterInit(LPI2C_3_PERIPHERAL, &LPI2C_3_masterConfig, LPI2C_3_CLOCK_FREQ);
  LPI2C_MasterTransferCreateHandle(LPI2C_3_PERIPHERAL, &LPI2C_3_masterHandle, NULL, NULL);
}

/***********************************************************************************************************************
 * LPSPI_2 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'LPSPI_2'
- type: 'lpspi'
- mode: 'polling'
- type_id: 'lpspi_6e21a1e0a09f0a012d683c4f91752db8'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'LPSPI3'
- config_sets:
  - main:
    - mode: 'kLPSPI_Master'
    - clockSource: 'LpspiClock'
    - clockSourceFreq: 'BOARD_BootClockRUN'
    - master:
      - baudRate: '500000'
      - bitsPerFrame: '8'
      - cpol: 'kLPSPI_ClockPolarityActiveHigh'
      - cpha: 'kLPSPI_ClockPhaseFirstEdge'
      - direction: 'kLPSPI_MsbFirst'
      - pcsToSckDelayInNanoSec: '1000'
      - lastSckToPcsDelayInNanoSec: '1000'
      - betweenTransferDelayInNanoSec: '1000'
      - whichPcs: 'kLPSPI_Pcs0'
      - pcsActiveHighOrLow: 'kLPSPI_PcsActiveLow'
      - pinCfg: 'kLPSPI_SdiInSdoOut'
      - dataOutConfig: 'kLpspiDataOutRetained'
    - quick_selection: 'qs_master'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const lpspi_master_config_t LPSPI_2_config = {
  .baudRate = 500000,
  .bitsPerFrame = 8,
  .cpol = kLPSPI_ClockPolarityActiveHigh,
  .cpha = kLPSPI_ClockPhaseFirstEdge,
  .direction = kLPSPI_MsbFirst,
  .pcsToSckDelayInNanoSec = 1000,
  .lastSckToPcsDelayInNanoSec = 1000,
  .betweenTransferDelayInNanoSec = 1000,
  .whichPcs = kLPSPI_Pcs0,
  .pcsActiveHighOrLow = kLPSPI_PcsActiveLow,
  .pinCfg = kLPSPI_SdiInSdoOut,
  .dataOutConfig = kLpspiDataOutRetained
};

void LPSPI_2_init(void) {
  LPSPI_MasterInit(LPSPI_2_PERIPHERAL, &LPSPI_2_config, LPSPI_2_CLOCK_FREQ);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  SEMC_1_init();
  LPSPI_1_init();
  LPUART_1_init();
  LPUART_2_init();
  LPUART_3_init();
  LPI2C_1_init();
  LPI2C_2_init();
  LPUART_4_init();
  LPI2C_3_init();
  LPSPI_2_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}