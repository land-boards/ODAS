#if !defined(DIGIO32DRIVER_H)
#define DIGIO32DRIVER_H

/* ========================================
 *
 * Copyright YOUR Land Boards, LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Land Boards, LLC.
 *
 * ========================================
*/

#include <project.h>
#include "serialIO.h"
#include "stringConvs.h"
#include "debugOutput.h"
#include "testMenu.h"
#include "MCP23017.h"

enum DIGIO32_CHIP_OFFSETS {MCPCHIP0,MCPCHIP1};

void initDIGIO32(uint8);

// Arduino-ish functions
void pinModeDIGIO32(uint8 bit, uint8 val);
void digitalWriteDIGIO32(uint8, uint8);
uint8 digitalReadDIGIO32(uint8);

// Byte/Short/Long control/access functions
void pinModeByByteDIGIO32(uint8,uint8,uint8);
uint8 readByteDIGIO32(uint8,uint8);
uint8 readOLATByteDIGIO32(uint8,uint8);
uint16_t readOLATShortDIGIO32(uint8_t);
uint32_t readOLATLongDIGIO32(uint8);
void writeByteDIGIO32(uint8,uint8,uint8);
void writeShortDIGIO32(uint8, uint16);
void writeLongDIGIO32(uint8, uint32);

#endif
