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
//uint8 wrDataBuffer[] = {0xf0,0,0,0,0,0x02,0xf0,0,0,0};
uint8 wrDataBuffer[] = {0xf0,0,0,0,0,0,0,0,0,0};

#define MCP23008_GPIOREGADR 0x09
#define MCP23008_OLATREGADR 0x0a

//////////////////////////////////////////////////////////////////////////////
// initDIGIO8Card(void) - 
//////////////////////////////////////////////////////////////////////////////

void initDIGIO8Card(void)
{
    I2C_MasterWriteBuf(0x20, wrDataBuffer, 10, I2C_MODE_COMPLETE_XFER);
}

//////////////////////////////////////////////////////////////////////////////
// writeDIGIO8Card(uint8_t outData) - 
//////////////////////////////////////////////////////////////////////////////


void writeDIGIO8Card(uint8 outData)
{
    myWrBuffer[0]= MCP23008_OLATREGADR;
    myWrBuffer[1] = outData;
    Control_Reg_1_Write(myWrBuffer[1]);
    I2C_MasterWriteBuf(0x20, myWrBuffer, 2, I2C_MODE_COMPLETE_XFER);
}

//////////////////////////////////////////////////////////////////////////////
// readDIGIO8Card(void)
//////////////////////////////////////////////////////////////////////////////

uint8 readDIGIO8Card(void)
{
    uint8_t rdBuff;
    myWrBuffer[0] = MCP23008_GPIOREGADR;
    I2C_MasterWriteBuf(0x20, myWrBuffer, 1, I2C_MODE_COMPLETE_XFER);
    rdBuff = I2C_MasterReadByte(I2C_ACK_DATA);
    return rdBuff>>4;
}

/* [] END OF FILE */
