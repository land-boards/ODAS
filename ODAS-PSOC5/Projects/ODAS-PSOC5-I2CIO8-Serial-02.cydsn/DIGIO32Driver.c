/* ========================================
 * DIGIO8Driver.c
 * Copyright Land Boards LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Land Boards, LLC.
 *
 * ========================================
*/

#include <project.h>
#include "DIGIO32Driver.h"
#include "SerialIO.h"
#include "stringConvs.h"

#define VERBOSEMODE

uint8 myWrBuffer[2];

//////////////////////////////////////////////////////////////////////////////
// initDIGIO32Cards(void) - 
//////////////////////////////////////////////////////////////////////////////

void initDIGIO32Cards(void)
{
    uint8 card;
    uint8 chip;
#ifdef VERBOSEMODE
    writeLine("initDIGIO32Cards() - reached function");
#endif
    I2C_Start();    // Kick off the I2C interface
    for (card=0; card < NUMBER_OF_DIGIO32_CARDS; card++)
    {
        for (chip=0; chip < 2; chip++)      // Two MCP23017 chips per card
        {
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
#ifdef VERBOSEMODE
    writeLine("initDIGIO32Cards() - exiting function");
#endif
}

//////////////////////////////////////////////////////////////////////////////
// void setDIGIO32InOut(uint8 card, uint8 chip, uint8 a0b1, uint8 polarity) - 
//////////////////////////////////////////////////////////////////////////////

void setDIGIO32InOut(uint8 card, uint8 chip, uint8 a0b1, uint8 polarity)
{
    if (a0b1 == APORT)
        writeRegisterDIGIO32Card(card, chip, MCP23017_IODIRA_REGADR, polarity);
    else
        writeRegisterDIGIO32Card(card, chip, MCP23017_IODIRB_REGADR, polarity);
}

//////////////////////////////////////////////////////////////////////////////
// uint8 readRegisterDIGIO32Card(ctrlAdr) - 
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
// writeRegisterDIGIO32Card(ctrlAdr, ctrlVal) - 
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

//////////////////////////////////////////////////////////////////////////////
// readDIGIO32Card(void)
//////////////////////////////////////////////////////////////////////////////

uint8 readDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1)
{
    uint8 rdBuff;
    if (a0b1 ==0)
        rdBuff = readRegisterDIGIO32Card(card,chip,MCP23017_GPIOA_REGADR);
    else
        rdBuff = readRegisterDIGIO32Card(card,chip,MCP23017_GPIOB_REGADR);
    return rdBuff>>4;
}

//////////////////////////////////////////////////////////////////////////////
// writeDIGIO32Card(uint8_t outData) - 
//////////////////////////////////////////////////////////////////////////////

void writeDIGIO32Card(uint8 card, uint8 chip, uint8 a0b1, uint8 outData)
{
    if (a0b1 ==0)
         writeRegisterDIGIO32Card(card,chip,MCP23017_OLATA_REGADR,outData);
    else
         writeRegisterDIGIO32Card(card,chip,MCP23017_OLATB_REGADR,outData);
}


/* [] END OF FILE */
