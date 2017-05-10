/* ========================================
 *
 * Copyright Land Boards LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Land Boards LLC.
 *
 * ========================================
*/
#include <project.h>
#include "DIGIO32Driver.h"
#include "TestCard.h"
#include "TestMenu.h"
#include "SerialIO.h"
#include "stringConvs.h"

#define VERBOSEMODE

//////////////////////////////////////////////////////////////////////////////
// void testCard(void)
//////////////////////////////////////////////////////////////////////////////

void testCard(void)
{
//    initDIGIO32Cards();
//    initGPIOPins();
//    initDIGIO32Cards();
}

//////////////////////////////////////////////////////////////////////////////
// void initGPIOPins(void)
//////////////////////////////////////////////////////////////////////////////

void initGPIOPins(void)
{
#ifdef VERBOSEMODE
    writeLine("initGPIOPins() - reached function");
#endif
    initDIGIO32Cards();
    writeRegisterDIGIO32Card(BRD3,MCPCHIP0,MCP23017_IODIRA_REGADR,0);
    writeRegisterDIGIO32Card(BRD3,MCPCHIP0,MCP23017_IODIRB_REGADR,0);
    writeRegisterDIGIO32Card(BRD3,MCPCHIP1,MCP23017_IODIRA_REGADR,0);
    writeRegisterDIGIO32Card(BRD3,MCPCHIP1,MCP23017_IODIRB_REGADR,0);
    writeRegisterDIGIO32Card(BRD4,MCPCHIP0,MCP23017_IODIRA_REGADR,0);
    writeRegisterDIGIO32Card(BRD4,MCPCHIP0,MCP23017_IODIRB_REGADR,0);
    writeRegisterDIGIO32Card(BRD4,MCPCHIP1,MCP23017_IODIRA_REGADR,0);
    writeRegisterDIGIO32Card(BRD4,MCPCHIP1,MCP23017_IODIRB_REGADR,0);
    writeRegisterDIGIO32Card(BRD5,MCPCHIP0,MCP23017_IODIRA_REGADR,0);
    writeRegisterDIGIO32Card(BRD5,MCPCHIP0,MCP23017_IODIRB_REGADR,0);
    writeRegisterDIGIO32Card(BRD5,MCPCHIP1,MCP23017_IODIRA_REGADR,0);
    writeRegisterDIGIO32Card(BRD5,MCPCHIP1,MCP23017_IODIRB_REGADR,0);
#ifdef VERBOSEMODE
    writeLine("initGPIOPins() - completed function");
#endif
}

/* [] END OF FILE */
