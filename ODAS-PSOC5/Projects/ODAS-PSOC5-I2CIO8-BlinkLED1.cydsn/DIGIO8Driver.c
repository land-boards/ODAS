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

uint8 myWrBuffer[2];
 
#define MCP23008_IODIR_REGADR    0x00
#define MCP23008_IPOL_REGADR     0x01
#define MCP23008_GPINTEN_REGADR  0x02
#define MCP23008_DEFVAL_REGADR   0x03
#define MCP23008_INTCON_REGADR   0x04
#define MCP23008_IOCON_REGADR    0x05
#define MCP23008_GPPU_REGADR     0x06
#define MCP23008_INTF_REGADR     0x07
#define MCP23008_INTCAP_REGADR   0x08
#define MCP23008_GPIO_REGADR     0x09
#define MCP23008_OLAT_REGADR     0x0a

#define MCP23008_IODIR_DEFVAL    0xf0
#define MCP23008_IOCON_DEFVAL    0x00

//////////////////////////////////////////////////////////////////////////////
// initDIGIO8Card(void) - 
//////////////////////////////////////////////////////////////////////////////

void initDIGIO8Card(void)
{
    myWrBuffer[0] = MCP23008_IOCON_REGADR;
    myWrBuffer[1] = MCP23008_IOCON_DEFVAL;
    I2C_MasterWriteBuf(0x20, myWrBuffer, 2, I2C_MODE_COMPLETE_XFER);
    // LEDs are outputs, jumpers are inputs
    myWrBuffer[0] = MCP23008_IODIR_REGADR;
    myWrBuffer[1] = MCP23008_IODIR_DEFVAL;
    I2C_MasterWriteBuf(0x20, myWrBuffer, 2, I2C_MODE_COMPLETE_XFER);
}

//////////////////////////////////////////////////////////////////////////////
// writeDIGIO8Card(uint8_t outData) - 
//////////////////////////////////////////////////////////////////////////////

void writeDIGIO8Card(uint8 outData)
{
    myWrBuffer[0]= MCP23008_OLAT_REGADR;
    myWrBuffer[1] = outData;
    I2C_MasterWriteBuf(0x20, myWrBuffer, 2, I2C_MODE_COMPLETE_XFER);
}

//////////////////////////////////////////////////////////////////////////////
// readDIGIO8Card(void)
//////////////////////////////////////////////////////////////////////////////

uint8 rdBuff[4];

uint8 readDIGIO8Card(void)
{
    uint8 myWrBuffer[2];
    myWrBuffer[0] = MCP23008_GPIO_REGADR;
    I2C_MasterWriteBuf(0x20, myWrBuffer, 1, I2C_MODE_COMPLETE_XFER);
    rdBuff[0] = I2C_MasterReadByte(I2C_ACK_DATA);
    return rdBuff[0]>>4;
}

/* [] END OF FILE */
