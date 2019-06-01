#include <Wire.h>

// commands
#define ON     1
#define OFF    0
#define SAVE  -1

// REG INDICES

//Temperature float
#define TEMP_HH     0x0
#define TEMP_HL 	0x1
#define TEMP_LH 	0x2
#define TEMP_LL  	0x3

// VOLTAGE float
#define V_HH      	0x4
#define V_HL        0x5
#define V_LH        0x6
#define V_LL        0x7

// COMMANDS
#define COM 		0x8
#define EPS			0x9
#define GNC			0xA

// temperature 20.1232 celsius
// voltage 10.343
unsigned char REG[10] =  {0x41, 0xA0, 0xFC, 0x1C, 
	0x41, 0x25, 0x7C, 0xEE,
	ON, ON, ON}; 
int ACTIVE_INDEX;
