/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "myI2CMaster.h"

uint8 wrBuf[WR_BUFFER_SIZE];
uint8 rdBuf[RD_BUFFER_SIZE];

//////////////////////////////////////////////////////////////////////////////////////////////////
// void initI2CMaster() - Initialize the I2C Master
//////////////////////////////////////////////////////////////////////////////////////////////////

void initI2CMaster(void)
{
    // Initialize the read/write buffers
    I2CM_MasterClearWriteBuf();     // Buffer to be written from the master
    I2CM_MasterClearReadBuf();      // Buffer to be read from the master

    wrBuf[0] = SLAVE_LED_ON;
    wrBuf[1] = 0;
    wrBuf[2] = 0;
    wrBuf[3] = 0;
    wrBuf[4] = 0;
    rdBuf[0] = NULL_CMD;
    rdBuf[1] = 0;
    rdBuf[2] = 0;
    rdBuf[3] = 0;
    rdBuf[4] = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// void sendBuffToI2C(void) - 
//////////////////////////////////////////////////////////////////////////////////////////////////

void sendBuffToI2C(uint8 slaveAddr)
{
    uint8 temp;
    do
    {
        temp = I2CM_MasterWriteBuf(slaveAddr, (uint8 *)wrBuf, WR_BUFFER_SIZE, I2CM_MODE_COMPLETE_XFER);
    }
    while (temp != I2CM_MSTR_NO_ERROR);
    while(I2CM_MasterStatus() & I2CM_MSTAT_XFER_INP);       // Wait for the data transfer to complete
    temp = I2CM_MasterClearStatus();
    if(temp & I2CM_MSTAT_ERR_XFER)  // If there is an error while transferring data */
    {
        if (temp & I2CM_MSTAT_XFER_HALT)
            printLine("Transfer has been halted.");
        if (temp & I2CM_MSTAT_ERR_SHORT_XFER)
            printLine("Short Transfer Error");
        if (temp & I2CM_MSTAT_ERR_ADDR_NAK)
            printLine("Slave did not ack the address");
        if (temp & I2CM_MSTAT_ERR_ARB_LOST)
            printLine("I2C Master lost arbitration");
    }
    else /* Write completed without error */
    {
//            printSingleChar('K');
    }
}


//////////////////////////////////////////////////////////////////////////////////////////////////
// void sendBuffToI2C(void) - 
//////////////////////////////////////////////////////////////////////////////////////////////////

void getBuffFromI2C(uint8 slaveAddr)
{
    uint8 temp;
    I2CM_MasterReadBuf(slaveAddr, (uint8 *)rdBuf, RD_BUFFER_SIZE, I2CM_MODE_COMPLETE_XFER);
    while ((I2CM_MasterStatus() & I2CM_MSTAT_RD_CMPLT) != I2CM_MSTAT_RD_CMPLT);         // wait for read to be complete
    temp = I2CM_MasterClearStatus();
    if(temp & I2CM_MSTAT_ERR_XFER)  // If there is an error while transferring data */
    {
        if (temp & I2CM_MSTAT_XFER_INP)
            printLine("Transfer in progress");
        if (temp & I2CM_MSTAT_XFER_HALT)
            printLine("Transfer has been halted.");
        if (temp & I2CM_MSTAT_ERR_SHORT_XFER)
            printLine("Short Transfer Error");
        if (temp & I2CM_MSTAT_ERR_ADDR_NAK)
            printLine("Slave did not ack the address");
        if (temp & I2CM_MSTAT_ERR_ARB_LOST)
            printLine("I2C Master lost arbitration");
    }
    else /* Write completed without error */
    {
        printSingleChar(rdBuf[0]);
//            printSingleChar('k');
    }
}


/* [] END OF FILE */
