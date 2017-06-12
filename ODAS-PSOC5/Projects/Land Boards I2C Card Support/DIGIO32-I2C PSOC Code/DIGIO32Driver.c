/* ========================================
 * DIGIO32Driver.c
 * Copyright COMPANY, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF COMPANY.
 *
 * Driver for DIGO32-I2C Card.
 *  http://land-boards.com/blwiki/index.php?title=DIGIO32-I2C
 *
 * File has four types of functions:
 *      Arduino-ish (bit) oriented
 *      Byte oriented
 *
 * ========================================
*/

#include "DIGIO32Driver.h"

uint8 myWrBuffer[2];
extern uint8 verboseFlag;

//////////////////////////////////////////////////////////////////////////////
// initDIGIO32(boardNumber) - Initializes the registers on the DIGIO32 card.
// boardNumber - Board number (0-3)
// Can be called before and after a test.
// Directly accesses the bits in the cards.
//////////////////////////////////////////////////////////////////////////////

void initDIGIO32(uint8 boardNumber)
{
    if (verboseFlag == VERBOSEMODE)
        printLine("initDIGIO32_3xCards() - reached function");
    if (verboseFlag == VERBOSEMODE)
        debugPrintStringLong("Initializing boards: ",boardNumber);
    init_MCP23017(boardNumber<<1);
    init_MCP23017((boardNumber<<1)+1);
    if (verboseFlag == VERBOSEMODE)
        printLine("Initialized the DIGIO32 Cards");
}

//////////////////////////////////////////////////////////////////////////////
// void pinModeDIGIO32(bit, mode) - Set a bit to INPUT or OUTPUT
// Arduino-style function.
// bit is 0-127 (128 bits total),
// bit 0CCCHPPP
//  0 = ZERO
//  C = Chip (0-5)
//  H = Half of chip
//  PPP = Bit choice
// val is OUTPUT_MODE,INPUT_MODE
// Uses pinMode_MCP23017 function to access the cards.
//////////////////////////////////////////////////////////////////////////////

void pinModeDIGIO32(uint8 bit, uint8 val)
{
    uint8_t chip = (bit>>4)&0x7;
    pinMode_MCP23017(chip,bit,val);
}

//////////////////////////////////////////////////////////////////////////////
// void digitalWriteDIGIO32(uint8 bit, uint8 val) - write val to a single bit
// Arduino-style function.
// bit is 0-127 (128 bits total)
// bit 0BBCHPPP
//  0 = ZERO
//  BB = Board (0-3)
//  C = Chip (0,1)
//  H = Half of chip
//  PPP = Bit choice
// val is 0,1
// Uses digitalWrite_MCP23017 function to access the cards.
//////////////////////////////////////////////////////////////////////////////

void digitalWriteDIGIO32(uint8 bit, uint8 val)
{
    uint8_t chip = (bit>>4)&0x7;
    digitalWrite_MCP23017(chip,bit,val);
}

//////////////////////////////////////////////////////////////////////////////
// void digitalReadDIGIO32(uint8 bit) - returns back a single bit
// Arduino-style function.
// Uses digitalRead_MCP23017 functions to access the cards.
//////////////////////////////////////////////////////////////////////////////

uint8_t digitalReadDIGIO32(uint8 bit)
{
    uint8_t chip = (bit>>4)&0x7;
    return digitalRead_MCP23017(chip,bit);
}

//////////////////////////////////////////////////////////////////////////////
// void pinModeByByteDIGIO32(uint8 card, uint8 chip, uint8 a0b1, uint8 polarity) - 
// Set an entire 8 bit port to read/write
// chipOffset = 0-7
// a0b1 = 0,1
// polarity = OUTPUT_MODE,INPUT_MODE
//////////////////////////////////////////////////////////////////////////////

void pinModeByByteDIGIO32(uint8 chipOff, uint8 a0b1, uint8 polarity)
{
    pinModeByByte_MCP23017(chipOff, a0b1, polarity);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readByteDIGIO32(uint8 card, uint8 chip, uint8 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint8 readByteDIGIO32(uint8 chipOff, uint8 a0b1)
{
    return read8_MCP23017(chipOff,a0b1);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readOLATByteDIGIO32(uint8 card, uint8 chip, uint8 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint8 readOLATByteDIGIO32(uint8 chipOff, uint8 a0b1)
{
    return readBack8_MCP23017(chipOff,a0b1);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readOLATShortDIGIO32(uint8 card, uint8 chip, uint16 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint16_t readOLATShortDIGIO32(uint8_t chipOff)
{
    uint16_t retVal;
    retVal = readBack8_MCP23017(chipOff,1);
    retVal <<= 8;
    retVal |= readBack8_MCP23017(chipOff,0);
    return retVal;
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readOLATLongDIGIO32(uint8 card, uint8 chip, uint16 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint32_t readOLATLongDIGIO32(uint8 chipOff)
{
    uint32_t retVal;
    retVal = readBack8_MCP23017(chipOff+1,1);
    retVal <<= 8;
    retVal |= readBack8_MCP23017(chipOff+1,0);
    retVal <<= 8;
    retVal |= readBack8_MCP23017(chipOff,1);
    retVal <<= 8;
    retVal |= readBack8_MCP23017(chipOff,0);
    return retVal;
}

//////////////////////////////////////////////////////////////////////////////
// void writeByteDIGIO32(uint8 card, uint8 chip, uint8 a0b1, uint8 outData)
//////////////////////////////////////////////////////////////////////////////

void writeByteDIGIO32(uint8 chipOff, uint8 a0b1, uint8 outData)
{
    write8_MCP23017(chipOff,a0b1,outData);
}

//////////////////////////////////////////////////////////////////////////////
// void writeShortDIGIO32(uint8 card, uint8 chip, uint8 a0b1, uint16 outData)
//////////////////////////////////////////////////////////////////////////////

void writeShortDIGIO32(uint8 chipOff, uint16 outData)
{
    write8_MCP23017(chipOff,0,outData&0xff);
    write8_MCP23017(chipOff,1,((outData>>8)&0xff));
}

//////////////////////////////////////////////////////////////////////////////
// void writeLongDIGIO32(uint8 card, uint8 chip, uint8 a0b1, uint32 outData)
//////////////////////////////////////////////////////////////////////////////

void writeLongDIGIO32(uint8 chipOff, uint32 outData)
{
    write8_MCP23017(chipOff,0,outData&0xff);
    write8_MCP23017(chipOff,1,((outData>>8)&0xff));
    write8_MCP23017(chipOff+1,0,((outData>>16)&0xff));
    write8_MCP23017(chipOff+1,1,((outData>>24) & 0xff));
}

/* [] END OF FILE */

