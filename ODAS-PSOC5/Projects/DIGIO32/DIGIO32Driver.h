#if !defined(DIGIO32DRIVER_H)
#define DIGIO32DRIVER_H

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

#include <project.h>

#define MCP23017BASE            0x20
#define NUMBER_OF_DIGIO32_CARDS 3
    
enum DIGIOCARD {BRD3, BRD4, BRD5};
enum MCPCHIP {MCPCHIP0, MCPCHIP1};
enum ABPORT {APORT, BPORT};
 
#define MCP23017_IODIRA_REGADR   0x00
#define MCP23017_IODIRB_REGADR   0x01
#define MCP23017_IPOLA_REGADR    0x02
#define MCP23017_IPOLB_REGADR    0x03
#define MCP23017_GPINTENA_REGADR 0x04
#define MCP23017_GPINTENB_REGADR 0x05
#define MCP23017_DEFVALA_REGADR  0x06
#define MCP23017_DEFVALB_REGADR  0x07
#define MCP23017_INTCONA_REGADR  0x08
#define MCP23017_INTCONB_REGADR  0x09
#define MCP23017_IOCONA_REGADR   0x0a
#define MCP23017_IOCONB_REGADR   0x0b
#define MCP23017_GPPUA_REGADR    0x0c
#define MCP23017_GPPUB_REGADR    0x0d
#define MCP23017_INTFA_REGADR    0x0e
#define MCP23017_INTFB_REGADR    0x0f
#define MCP23017_INTCAPA_REGADR  0x10
#define MCP23017_INTCAPB_REGADR  0x11
#define MCP23017_GPIOA_REGADR    0x12
#define MCP23017_GPIOB_REGADR    0x13
#define MCP23017_OLATA_REGADR    0x14
#define MCP23017_OLATB_REGADR    0x15

#define MCP23017_IODIR_DEFVAL    0xff       // Initially set all channels to inputs
#define MCP23017_IPOL_DEFVAL     0x00       // Input polarity = invert jumpers
#define MCP23017_GPINTEN_DEFVAL  0x00       // Disable GPIO for interrupt on change
#define MCP23017_INTCON_DEFVAL   0x00       // Int for change from previous pin
#define MCP23017_IOCON_DEFVAL    0x00       // Disable sequential,  active-low
#define MCP23017_GPPU_DEFVAL     0xf0

void initDIGIO32Cards();
void setDIGIO32InOut(uint8, uint8, uint8, uint8);
uint8 readRegisterDIGIO32Card(uint8, uint8, uint8);
void writeRegisterDIGIO32Card(uint8, uint8, uint8, uint8);
uint8 readDIGIO32Card(uint8, uint8, uint8);
void writeDIGIO32Card(uint8, uint8, uint8, uint8);
void bounceDIGIOLines();
void digitalWriteDIGIO32Card(uint8, uint8);


/* [] END OF FILE */

#endif