/* ========================================
 *
 * Copyright Land Boards, LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Land Boards, LLC.
 *
 * ========================================
*/

#include "DIGIO32Example.h"

//////////////////////////////////////////////////////////////////////////////
// blinkDIGIOLine(void) - Blink the bit on one of the card.
//////////////////////////////////////////////////////////////////////////////

void blinkDIGIOLine(uint8 bit)
{
    printString("Blinking Bit ");
    printLine("- Hit any key to exit");
    pinMode_MCP23017(0,0,OUTPUT_MODE);
    for(;;)
    {
        digitalWrite_MCP23017((bit>>4)&0x7,bit&0x0f,1);
        CyDelay(500);
        digitalWrite_MCP23017((bit>>4)&0x7,bit&0x0f,0);
        CyDelay(500);
        if (checkReceiveChar() != 0)
        {
            getSingleChar();
        pinModeDIGIO32(bit, INPUT_MODE);    // assume bit needs to be set back to input
            return;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////
// void bounceDIGIOLines(void) - Bounce a one across all DIGIO32 outputs.
//////////////////////////////////////////////////////////////////////////////

#define BOUNCEDELAY 250

void bounceDIGIOLines(void)
{
    uint8_t bit;
    uint8_t chip;
    printLine("Bouncing a HIGH across all DIGIO32 lines");
    initDIGIOCards();
    for (chip = 0; chip < NUMBER_OF_DIGIO32_CARDS<<1; chip++)
    {
        write16_MCP23017(chip,0);
        pinModeByByte_MCP23017(chip,0,OUTPUT_MODE);
        pinModeByByte_MCP23017(chip,1,OUTPUT_MODE);
    }
    write8_MCP23017(0,0,0);
    write8_MCP23017(0,1,0);
    for (bit = 0; bit < DIGIO32_BITS_3CARDS; bit++)
    {
        digitalWrite_MCP23017((bit>>4)&0x7,bit&0x0f,1);
        CyDelay(BOUNCEDELAY);
        digitalWrite_MCP23017((bit>>4)&0x7,bit&0x0f,0);
        printString(".");
        if ((bit&0x1f) == 0x1f)
            printLine("");
    }
    for (chip = 0; chip < NUMBER_OF_DIGIO32_CARDS<<1; chip++)
    {
        pinModeByByte_MCP23017(chip,0,INPUT_MODE);
        pinModeByByte_MCP23017(chip,1,INPUT_MODE);
    }
    printLine("Finished bouncing a HIGH");
}

/* [] END OF FILE */
