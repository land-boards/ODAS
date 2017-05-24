/* ========================================
 *
 * Copyright AAC LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF AAC LLC.
 *
 * ========================================
*/

#include <project.h>
#include "DIGIO32Driver.h"
#include "SerialIO.h"
#include "stringConvs.h"

//////////////////////////////////////////////////////////////////////////////
// blinkDIGIOLine(void) - 
//////////////////////////////////////////////////////////////////////////////

void blinkDIGIOLine(void)
{
    printLine("Blinking LED - Hit any key to exit");
    writeRegisterDIGIO32Card(0,0,MCP23017_IODIRA_REGADR,0xFE);
    for(;;)
    {
        digitalWriteDIGIO32Card(0,1);
        CyDelay(500);
        digitalWriteDIGIO32Card(0,0);
        CyDelay(500);
        if (checkReceiveChar() != 0)
        {
            getSingleChar();
            writeRegisterDIGIO32Card(0,0,MCP23017_IODIRA_REGADR,MCP23017_IODIR_DEFVAL);
            return;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
// void bounceDIGIOLines(void) - Bounce a one across all 128 digital outputs.
//////////////////////////////////////////////////////////////////////////////

#define BOUNCEDELAY 100

void bounceDIGIOLines(void)
{
    uint8_t card;
    uint32_t bit;
#ifdef VERBOSEMODE
    printLine("bounceDIGIOLines() - reached function");
#endif
    initDIGIO32Cards();
    for (card = 0; card < 4; card++)
    {
        writeRegisterDIGIO32Card(card,0,MCP23017_IODIRA_REGADR,0x00);
        writeRegisterDIGIO32Card(card,0,MCP23017_IODIRB_REGADR,0x00);
        writeRegisterDIGIO32Card(card,1,MCP23017_IODIRA_REGADR,0x00);
        writeRegisterDIGIO32Card(card,1,MCP23017_IODIRB_REGADR,0x00);
    }
    for (bit = 0; bit < 128; bit++)
    {
        digitalWriteDIGIO32Card(bit,1);
        CyDelay(BOUNCEDELAY);
        digitalWriteDIGIO32Card(bit,0);
    }
    for (card = 0; card < 4; card++)
    {
        writeRegisterDIGIO32Card(card,0,MCP23017_IODIRA_REGADR,MCP23017_IODIR_DEFVAL);
        writeRegisterDIGIO32Card(card,0,MCP23017_IODIRB_REGADR,MCP23017_IODIR_DEFVAL);
        writeRegisterDIGIO32Card(card,1,MCP23017_IODIRA_REGADR,MCP23017_IODIR_DEFVAL);
        writeRegisterDIGIO32Card(card,1,MCP23017_IODIRB_REGADR,MCP23017_IODIR_DEFVAL);
    }
#ifdef VERBOSEMODE
    printLine("bounceDIGIOLines() - exiting function");
#endif
}

/* [] END OF FILE */
