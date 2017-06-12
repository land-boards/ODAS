/* ========================================
 * PROTO16Driver.c
 * Copyright Land Boards, LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Land Boards, LLC.
 *
 * Driver for three DIGO32-I2C Cards.
 *  http://land-boards.com/blwiki/index.php?title=PROTO16-I2C
 *
 * File has four types of functions:
 *      Arduino-ish (bit) oriented
 *      Byte oriented
 *      I2C Low Level Driver oriented
 *
 * ========================================
*/

#include <project.h>
#include "PROTO16Driver.h"
#include "serialIO.h"
#include "stringConvs.h"
#include "debugOutput.h"
#include "testMenu.h"

uint8 myWrBuffer[2];
extern uint8 verboseFlag;

//////////////////////////////////////////////////////////////////////////////
// initDIGIO32_PROTO16Card(void) - Initializes the registers on the PROTO16 card.
// Can be called before and after a test.
// Directly accesses the bits in the cards.
//////////////////////////////////////////////////////////////////////////////

void initPROTO16Card(void)
{
    if (verboseFlag == VERBOSEMODE)
        printLine("initPROTO16() - reached function");
    init_MCP23017(MCP23017OFFSET_PROTO16);
    if (verboseFlag == VERBOSEMODE)
        printLine("Initialized the PROTO16 Card");
}

//////////////////////////////////////////////////////////////////////////////
// void pinModePROTO16(bit, mode) - Set a bit to INPUT, INPUT_PULLUP, or OUTPUT
// Arduino-style function.
// bit is 0-127 (128 bits total),
// bit 0BBCHPPP
//  0 = ZERO
//  BB = Board (0-3)
//  C = Chip (0,1)
//  H = Half of chip
//  PPP = Bit choice
// val is OUTPUT_MODE,INPUT_MODE
// Uses readRegisterDIGIO32Card and writeRegisterDIGIO32Card functions to access the cards.
//////////////////////////////////////////////////////////////////////////////

void pinModePROTO16(uint8 bit, uint8 val)
{
//    debugPrintStringLong("pinModePROTO16(): bit value is: ",bit);
//    debugPrintStringLong("pinModePROTO16(): val value is: ",val);
    pinMode_MCP23017(MCP23017OFFSET_PROTO16,bit,val);
}

//////////////////////////////////////////////////////////////////////////////
// void digitalWritePROTO16(uint8 bit, uint8 val) - write val to a single bit
// Arduino-style function.
// bit is 0-127 (128 bits total)
// bit 0BBCHPPP
//  0 = ZERO
//  BB = Board (0-3)
//  C = Chip (0,1)
//  H = Half of chip
//  PPP = Bit choice
// val is 0,1
// Uses readOLATByte_xDIGIO32Cards and writeByte_xDIGIO32Card functions to access the cards.
//////////////////////////////////////////////////////////////////////////////

void digitalWritePROTO16(uint8 bit, uint8 val)
{
    digitalWrite_MCP23017(MCP23017OFFSET_PROTO16,bit,val);
}

//////////////////////////////////////////////////////////////////////////////
// void digitalReadPROTO16(uint8 bit) - returns back a single bit
// Arduino-style function.
// Uses readBytePROTO16Card functions to access the cards.
//////////////////////////////////////////////////////////////////////////////

uint8_t digitalReadPROTO16(uint8 bit)
{
    uint8_t rdVal8;
    rdVal8 = digitalRead_MCP23017(MCP23017OFFSET_PROTO16,bit);
//    debugPrintStringLong("digitalReadPROTO16(): rdVal8 value is : ",rdVal8);
    return rdVal8;
}

//////////////////////////////////////////////////////////////////////////////
// void pinModeByBytePROTO16(uint8 a0b1, uint8 polarity) - 
// Set an entire 8 bit port to read/write
// card = 0-3
// chip = 0,1
// a0b1 = 0,1
// polarity = OUTPUT_MODE,INPUT_MODE
//////////////////////////////////////////////////////////////////////////////

void pinModeByBytePROTO16(uint8 a0b1, uint8 polarity)
{
    pinModeByByte_MCP23017(MCP23017OFFSET_PROTO16,a0b1,polarity);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readBytePROTO16Card(uint8 card, uint8 chip, uint8 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint8 readBytePROTO16Card(uint8 a0b1)
{
    return read8_MCP23017(MCP23017OFFSET_PROTO16,a0b1);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readOLATBytePROTO16Card(uint8 card, uint8 chip, uint8 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint8 readOLATBytePROTO16Card(uint8 a0b1)
{
    return readBack8_MCP23017(MCP23017OFFSET_PROTO16,a0b1);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readOLATShortPROTO16Card(uint8 card, uint8 chip, uint8 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint16 readOLATShortPROTO16Card(void)
{
    uint16_t retVal;
    retVal = readBack8_MCP23017(MCP23017OFFSET_PROTO16,1);
    retVal <<= 8;
    retVal |= readBack8_MCP23017(MCP23017OFFSET_PROTO16,0);
    return retVal;
}

//////////////////////////////////////////////////////////////////////////////
// void writeBytePROTO16Card(uint8 card, uint8 chip, uint8 a0b1, uint8 outData)
//////////////////////////////////////////////////////////////////////////////

void writeBytePROTO16Card(uint8 a0b1, uint8 outData)
{
    write8_MCP23017(MCP23017OFFSET_PROTO16,a0b1,outData);
}

//////////////////////////////////////////////////////////////////////////////
// void writeShortPROTO16Card(uint8 card, uint8 chip, uint16 outData)
//////////////////////////////////////////////////////////////////////////////

void writeShortPROTO16Card(uint16 outData)
{
    write8_MCP23017(MCP23017OFFSET_PROTO16,1,((outData>>8)&0xff));
    write8_MCP23017(MCP23017OFFSET_PROTO16,0,outData&0xff);
}

//////////////// Chip Level Register Access Functions ////////////////////////

/* [] END OF FILE */
