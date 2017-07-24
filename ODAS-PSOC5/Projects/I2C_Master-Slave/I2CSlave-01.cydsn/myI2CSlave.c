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

#include "myI2CSlave.h"

uint8 verboseFlag;

uint8 rdBuf[RD_BUFFER_SIZE];
uint8 wrBuf[WR_BUFFER_SIZE];

void initI2CBuffs(void)
{
    rdBuf[0] = 0;   // Buffers are globals
    rdBuf[1] = 0;
    rdBuf[2] = 0;
    rdBuf[3] = 0;
    rdBuf[4] = 0;

    wrBuf[0] = NULL_CMD;
    wrBuf[1] = 0;
    wrBuf[2] = 0;
    wrBuf[3] = 0;
    wrBuf[4] = 0;

    // Initialize the read/write buffers
    I2C_1_SlaveSetAddress(0x50);
    I2C_1_SlaveInitReadBuf(rdBuf,RD_BUFFER_SIZE);       // Buffer to be read by the master
    I2C_1_SlaveInitWriteBuf(wrBuf,WR_BUFFER_SIZE);      // Buffer from the master
    I2C_1_SlaveClearReadStatus();
    I2C_1_SlaveClearWriteStatus();
}

void waitForMasterToWrite(void)
{
    while ((I2C_1_SlaveStatus() & I2C_1_SSTAT_WR_BUSY) != I2C_1_SSTAT_WR_BUSY);         // Wait for write to go busy
    while ((I2C_1_SlaveStatus() & I2C_1_SSTAT_WR_BUSY) == I2C_1_SSTAT_WR_BUSY);         // Stall while write is busy
    while ((I2C_1_SlaveStatus() & I2C_1_SSTAT_WR_CMPLT) != I2C_1_SSTAT_WR_CMPLT);       // Wait for write to complete
    I2C_1_SlaveClearWriteBuf();
}

void waitForMasterToRead(void)
{
    while ((I2C_1_SlaveStatus() & I2C_1_SSTAT_RD_BUSY) == I2C_1_SSTAT_RD_CMPLT);
    while ((I2C_1_SlaveStatus() & I2C_1_SSTAT_RD_BUSY) != I2C_1_SSTAT_RD_BUSY); // Wait for the read
    while ((I2C_1_SlaveStatus() & I2C_1_SSTAT_RD_BUSY) == I2C_1_SSTAT_RD_BUSY);
    while ((I2C_1_SlaveStatus() & I2C_1_SSTAT_RD_CMPLT) != I2C_1_SSTAT_RD_CMPLT);   // Wait for packet to be read
    I2C_1_SlaveClearReadStatus();
    I2C_1_SlaveClearReadBuf();
}

void fastBlink(void)
{
    LED_Write(1);
    CyDelay(50);
    LED_Write(0);
}

/* [] END OF FILE */
