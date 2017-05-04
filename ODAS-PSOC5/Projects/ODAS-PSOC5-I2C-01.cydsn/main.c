/* ========================================
 *
 * Copyright Land Boards, LLC, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>

uint8 wrDataBuffer[] = {0,0,0,0,0,0,0,0,0,0};
#define MCP23008_OLATADR 0x0a
#define MCP23017_OLATADR 0x014
#define MCP23008_BUFLEN 10
#define MCP23017_BUFLEN 11

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_Start();
    I2C_MasterWriteBuf(0x20, wrDataBuffer, MCP23008_BUFLEN, I2C_MODE_COMPLETE_XFER);
    CyDelay(500);

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    wrDataBuffer[0]= MCP23008_OLATADR;    // OLATA register address
    for(;;)
    {
        wrDataBuffer[1] = 0x0;  // set the output to ZERO
        I2C_MasterWriteBuf(0x20, wrDataBuffer, 2, I2C_MODE_COMPLETE_XFER);
        CyDelay(500);
        wrDataBuffer[1] = 0x1;  // set the output to ONE
        I2C_MasterWriteBuf(0x20, wrDataBuffer, 2, I2C_MODE_COMPLETE_XFER);
        CyDelay(500);
    }
}


//////////////////////////////////////////////////////////////////////////////
// I2CWriteByte - Function to make it easier to write to a single location
//////////////////////////////////////////////////////////////////////////////

int I2CWriteByte(uint8 I2C_addr, uint8 mcpRegister, uint8 outValue)
{
    wrDataBuffer[0] = mcpRegister;
    wrDataBuffer[1] = outValue;
    I2C_MasterWriteBuf(I2C_addr, wrDataBuffer, 2, I2C_MODE_COMPLETE_XFER);
//    WriteLED(!ReadLED());
    while(I2C_MasterStatus() != I2C_MSTAT_WR_CMPLT);
    return(1);
}

//////////////////////////////////////////////////////////////////////////////
// I2CReadByte - Function to make it easier to read a byte from a single location
//////////////////////////////////////////////////////////////////////////////

uint8 I2CReadByte(uint8 I2C_addr, uint8 mcpRegister)
{
    uint8 rdBuff;
    wrDataBuffer[0] = mcpRegister;
    I2C_MasterWriteBuf(I2C_addr, wrDataBuffer, 1, I2C_MODE_COMPLETE_XFER);
    rdBuff = I2C_MasterReadByte(I2C_ACK_DATA);
    return(rdBuff);
}
