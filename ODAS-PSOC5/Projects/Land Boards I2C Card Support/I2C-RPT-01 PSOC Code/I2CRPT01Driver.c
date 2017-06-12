/* ========================================
 * I2CRPT01Driver.c
 * Copyright AAC, LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF AAC.
 *
 * http://land-boards.com/blwiki/index.php?title=I2C-RPT
 *
 * ========================================
*/

#include <project.h>
#include "I2CRPT01Driver.h"
#include "SerialIO.h"
#include "stringConvs.h"

//#define VERBOSEMODE
#undef VERBOSEMODE

uint8 myWrBuffer[1];

void setI2CChannel(uint8_t chNum)
{
    uint8 stat;
    char myString[5];
#ifdef VERBOSEMODE
    printLine("setI2CChannel() - reached function");
#endif
    stat = I2C_MasterClearStatus();
    if (stat != 0)
    {
        printString("I2C_MasterClearStatus returned status of - ");
        byteToString(stat,myString);
        printLine(myString);
    }
//    printLine("setI2CChannel() - calling master Send Start");
    stat = I2C_MasterSendStart(PCA9544A_ADDRESS,I2C_WRITE_XFER_MODE);
    if (I2C_MSTR_NO_ERROR == stat)
    {
        stat = I2C_MasterWriteByte(0x04|chNum);
        if (stat != I2C_MSTR_NO_ERROR)
        {
            printString("I2C_MasterWriteByte returned status of - ");
            byteToString(stat,myString);
            printLine(myString);
        }
    }
    else
    {
        printString("I2C_MasterSendStart returned status of - ");
        byteToString(stat,myString);
        printLine(myString);
    }
    I2C_MasterSendStop();
#ifdef VERBOSEMODE
    printLine("setI2CChannel() - complete");
#endif
}

/* [] END OF FILE */
