/* ========================================
 * DIGIO32Driver.c
 * Copyright COMPANY, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF COMPANY.
 *
 * Driver for four DIGO32-I2C Cards.
 *  http://land-boards.com/blwiki/index.php?title=DIGIO32-I2C
 *
 * File has four types of functions:
 *      Arduino-ish (bit) oriented
 *      Byte oriented
 *      All (4) DIGIO32 Cards oriented
 *      I2C Low Level Driver oriented
 *
 * ========================================
*/

#include <project.h>
#include "DIGIO32Driver.h"
#include "serialIO.h"
#include "stringConvs.h"
#include "debugOutput.h"

#define VERBOSEMODE
//#undef VERBOSEMODE

uint8 myWrBuffer[2];

//////////////////////////////////////////////////////////////////////////////
// initDIGIO32_4xCards(void) - Initializes the registers on the DIGIO32 card.
// Can be called before and after a test.
// Directly accesses the bits in the cards.
//////////////////////////////////////////////////////////////////////////////

void initDIGIO32_4xCards(void)
{
    uint8 card;
    uint8 chip;
#ifdef VERBOSEMODE
//    printLine("initDIGIO32_4xCards() - reached function");
#endif
    for (card=0; card < NUMBER_OF_DIGIO32_CARDS; card++)
    {
        for (chip=0; chip < 2; chip++)      // Two MCP23017 chips per card
        {
//            debugPrintStringLong("Initializing card: ",card);
//            debugPrintStringLong("Initializing chip: ",chip);
            writeRegisterDIGIO32Card(card,chip,MCP23017_IOCONA_REGADR,MCP23017_IOCON_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_IOCONB_REGADR,MCP23017_IOCON_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_IODIRA_REGADR,MCP23017_IODIR_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_IODIRB_REGADR,MCP23017_IODIR_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_GPINTENA_REGADR,MCP23017_GPINTEN_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_GPINTENB_REGADR,MCP23017_GPINTEN_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_INTCONA_REGADR,MCP23017_INTCON_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_INTCONB_REGADR,MCP23017_INTCON_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_GPPUA_REGADR,MCP23017_GPPU_DEFVAL);
            writeRegisterDIGIO32Card(card,chip,MCP23017_GPPUB_REGADR,MCP23017_GPPU_DEFVAL);
            readRegisterDIGIO32Card(card,chip,MCP23017_INTCAPA_REGADR);
            readRegisterDIGIO32Card(card,chip,MCP23017_INTCAPB_REGADR);
        }
    }
printLine("Initialized the DIGIO32 Cards");
}

//////////////////////////////////////////////////////////////////////////////
// void pinMode_4xDIGIO32Cards(bit, mode) - Set a bit to INPUT or OUTPUT
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

void pinMode_4xDIGIO32Cards(uint8 bit, uint8 val)
{
    uint8_t board;
    uint8_t chip;
    uint8_t abVal;
    uint8_t changeBit;
    uint8_t regVal;
    board = (bit>>5) & 0x03;
    chip  = (bit>>4) & 0x01;
    abVal = (bit>>3) & 0x01;
    changeBit = 1 << (bit & 0x7);
//    debugPrintStringLong("pinMode_4xDIGIO32Cards(): board value is: ",board);
//    debugPrintStringLong("pinMode_4xDIGIO32Cards(): chip value is: ",chip);
//    debugPrintStringLong("pinMode_4xDIGIO32Cards(): abVal value is: ",abVal);
//    debugPrintStringLong("pinMode_4xDIGIO32Cards(): changeBit value is: ",changeBit);
    if (abVal == 0)
    {
        regVal = readRegisterDIGIO32Card(board, chip, MCP23017_IODIRA_REGADR);
//        debugPrintStringLong("pinMode_4xDIGIO32Cards(): MCP23017_IODIRA_REGADR (before) is: ", (uint32) regVal);
        if (val == OUTPUT_MODE)
            regVal &= ~changeBit;
        else    // INPUT_MODE
            regVal |= changeBit;
//        debugPrintStringLong("pinMode_4xDIGIO32Cards(): MCP23017_IODIRA_REGADR (after) is: ", (uint32) regVal);
        writeRegisterDIGIO32Card(board, chip, MCP23017_IODIRA_REGADR, regVal);
    }
    else
    {
        regVal = readRegisterDIGIO32Card(board, chip, MCP23017_IODIRB_REGADR);
//        debugPrintStringLong("pinMode_4xDIGIO32Cards(): MCP23017_IODIRB_REGADR is: ", (uint32) regVal);
        if (val == OUTPUT_MODE)
            regVal &= ~changeBit;
        else    // INPUT_MODE
            regVal |= changeBit;
//        debugPrintStringLong("pinMode_4xDIGIO32Cards(): MCP23017_IODIRB_REGADR (after) is: ", (uint32) regVal);
        writeRegisterDIGIO32Card(board, chip, MCP23017_IODIRB_REGADR, regVal);
    }
}

//////////////////////////////////////////////////////////////////////////////
// void digitalWrite_4xDIGIO32Cards(uint8 bit, uint8 val) - write val to a single bit
// Arduino-style function.
// bit is 0-127 (128 bits total)
// bit 0BBCHPPP
//  0 = ZERO
//  BB = Board (0-3)
//  C = Chip (0,1)
//  H = Half of chip
//  PPP = Bit choice
// val is 0,1
// Uses readOLATByteDIGIO32Card and writeByteDIGIO32Card functions to access the cards.
//////////////////////////////////////////////////////////////////////////////

void digitalWrite_4xDIGIO32Cards(uint8 bit, uint8 val)
{
    uint8_t board;
    uint8_t chip;
    uint8_t abVal;
    uint8_t port;
    uint8_t rVal;
    board = (bit>>5) & 0x03;
    chip = (bit>>4) & 0x01;
    abVal = (bit>>3) & 0x01;
    port = bit & 0x7;
//    debugPrintStringLong("digitalWrite_4xDIGIO32Cards(): board value is: ",board);
//    debugPrintStringLong("digitalWrite_4xDIGIO32Cards(): chip value is: ",chip);
//    debugPrintStringLong("digitalWrite_4xDIGIO32Cards(): abVal value is: ",abVal);
//    debugPrintStringLong("digitalWrite_4xDIGIO32Cards(): port value is: ",port);
    rVal = readOLATByteDIGIO32Card(board,chip,abVal);
//    debugPrintStringLong("digitalWrite_4xDIGIO32Cards(): rVal (before) value is: ",rVal);
    if (val == 0)
        rVal &= ~(1<<port);
    else
        rVal |= (1<<port);
//    debugPrintStringLong("digitalWrite_4xDIGIO32Cards(): rVal (after) value is: ",rVal);
    writeByteDIGIO32Card(board,chip,abVal,rVal);
}

//////////////////////////////////////////////////////////////////////////////
// void digitalRead_4xDIGIO32Cards(uint8 bit) - returns back a single bit
// Arduino-style function.
// Uses readByteDIGIO32Card functions to access the cards.
//////////////////////////////////////////////////////////////////////////////

uint8_t digitalRead_4xDIGIO32Cards(uint8 bit)
{
    uint8_t board;
    uint8_t chip;
    uint8_t abVal;
    uint8_t port;
    uint8_t readVal;
    board = (bit>>5) & 0x03;
    chip = (bit>>4) & 0x01;
    abVal = (bit>>3) & 0x01;
    readVal = readByteDIGIO32Card(board, chip, abVal);
    port = bit & 0x7;
    return((readVal >> port)&0x1);
}

//////////////////////////////////////////////////////////////////////////////
// void pinModeByByte_4xDIGIO32Cards(uint8 card, uint8 chip, uint8 a0b1, uint8 polarity) - 
// Set an entire 8 bit port to read/write
// card = 0-3
// chip = 0,1
// a0b1 = 0,1
// polarity = OUTPUT_MODE,INPUT_MODE
//////////////////////////////////////////////////////////////////////////////

void pinModeByByte_4xDIGIO32Cards(uint8 card, uint8 chip, uint8 a0b1, uint8 polarity)
{
    if (a0b1 == APORT)
        writeRegisterDIGIO32Card(card, chip, MCP23017_IODIRA_REGADR, polarity);
    else
        writeRegisterDIGIO32Card(card, chip, MCP23017_IODIRB_REGADR, polarity);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readByteDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint8 readByteDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1)
{
    uint8 rdBuff;
    if (a0b1 ==0)
        rdBuff = readRegisterDIGIO32Card(card,chip,MCP23017_GPIOA_REGADR);
    else
        rdBuff = readRegisterDIGIO32Card(card,chip,MCP23017_GPIOB_REGADR);
    return rdBuff;
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readOLATByteDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1)
//////////////////////////////////////////////////////////////////////////////

uint8 readOLATByteDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1)
{
    uint8 rdBuff;
    if (a0b1 ==0)
        rdBuff = readRegisterDIGIO32Card(card,chip,MCP23017_OLATA_REGADR);
    else
        rdBuff = readRegisterDIGIO32Card(card,chip,MCP23017_OLATB_REGADR);
    return rdBuff;
}

//////////////////////////////////////////////////////////////////////////////
// void writeByteDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1, uint8 outData)
//////////////////////////////////////////////////////////////////////////////

void writeByteDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1, uint8 outData)
{
    if (a0b1 ==0)
         writeRegisterDIGIO32Card(card,chip,MCP23017_OLATA_REGADR,outData);
    else
         writeRegisterDIGIO32Card(card,chip,MCP23017_OLATB_REGADR,outData);
}

//////////////// Chip Level Register Access Functions ////////////////////////

//////////////////////////////////////////////////////////////////////////////
// uint8 readRegisterDIGIO32Card(ctrlAdr) - Reads 8-bit port from a MCP23017
//////////////////////////////////////////////////////////////////////////////

uint8 readRegisterDIGIO32Card(uint8 card, uint8 chip, uint8 ctrlAdr)
{
    uint8 rdBuff;
    uint8 i2cAddress = MCP23017BASE + ((card<<1) + chip);
    I2C_MasterClearStatus();
    I2C_MasterSendStart(i2cAddress,I2C_WRITE_XFER_MODE);
    I2C_MasterWriteByte(ctrlAdr);
    I2C_MasterSendStop();
//    while ((I2C_MasterStatus() & I2C_MSTAT_WR_CMPLT) == 0);
    I2C_MasterSendStart(i2cAddress,I2C_READ_XFER_MODE);
    rdBuff = I2C_MasterReadByte(I2C_NAK_DATA);
    I2C_MasterSendStop();
//    while ((I2C_MasterStatus() & I2C_MSTAT_RD_CMPLT) == 0);
    I2C_MasterClearStatus();
    return rdBuff;
}

//////////////////////////////////////////////////////////////////////////////
// void writeRegisterDIGIO32Card(uint8 card, uint8 chip, uint8 ctrlAdr, uint8 ctrlVal)
//////////////////////////////////////////////////////////////////////////////

void writeRegisterDIGIO32Card(uint8 card, uint8 chip, uint8 ctrlAdr, uint8 ctrlVal)
{
    uint8 i2cAddress = MCP23017BASE + ((card<<1) + chip);
    I2C_MasterClearStatus();
    myWrBuffer[0] = ctrlAdr;
    myWrBuffer[1] = ctrlVal;
    I2C_MasterWriteBuf(i2cAddress, myWrBuffer, 2, I2C_MODE_COMPLETE_XFER);
    while (0u == (I2C_MasterStatus() & I2C_MSTAT_WR_CMPLT));
    I2C_MasterClearStatus();
}

/* [] END OF FILE */

