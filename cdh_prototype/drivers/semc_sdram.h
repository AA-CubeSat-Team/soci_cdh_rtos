status_t BOARD_InitSEMC(void);
void SEMC_SDRAMReadWrite32Bit(void);
void SEMC_SDRAMReadWrite16Bit(void);
void SEMC_SDRAMReadWrite8Bit(void);
void SEMC_SDRAM_Read(int startByte, int datalen, size_t byteSize);
void SEMC_SDRAM_Write(int startByte, int datalen, size_t byteSize);

/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define EXAMPLE_SEMC               SEMC
#define EXAMPLE_SEMC_START_ADDRESS (0x80000000U)
#define EXAMPLE_SEMC_CLK_FREQ      CLOCK_GetFreq(kCLOCK_SemcClk)

#define SEMC_EXAMPLE_DATALEN    (0x1000U)
#define SEMC_EXAMPLE_WRITETIMES (1000U)

extern uint8_t sdram_writeBuffer[SEMC_EXAMPLE_DATALEN];
extern uint8_t sdram_readBuffer[SEMC_EXAMPLE_DATALEN];
extern uint8_t *sdram; /* SDRAM start address. */
