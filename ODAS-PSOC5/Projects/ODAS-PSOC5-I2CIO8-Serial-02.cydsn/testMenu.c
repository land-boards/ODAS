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
#include "DIGIO32Driver.h"
#include "TestMenu.h"
#include "TestCard.h"
#include "SerialIO.h"
#include "stringConvs.h"

char myStringInMemory[0x100];

////////////////////////////////////////////////////////////////
// void testMenu(void)
////////////////////////////////////////////////////////////////

void testMenu(void)
{
    char8 rxBufferPtr[80];
    writeLine("*** PSOC Test Station v0.1 (? for a list of commands) ***");
    outSingleChar('>');
    outSingleChar(' ');
    rxBufferPtr[0] = getSingleChar();
    outSingleChar(rxBufferPtr[0]);
    switch (rxBufferPtr[0])
    {
      case '?':
      case 'H':
      case 'h':
        writeLine(" - Help");
        writeLine("PSOC Test Station Commands");
        writeLine("? = Display this help screen");
        writeLine("R = Run Test");
        writeLine("X = Reset Test Station");
        break;
      case 'R':
      case 'r':
        writeLine(" - Running Tests");
        testCard();
        CyDelay(2000);
        writeLine("Completed Tests");
        break;
      case 'X':
      case 'x':
        writeLine(" - Resetting Test Station");
        initDIGIO32Cards();
        writeLine("Restored Test Station to Defaults");
        break;
      case 0x0a:    // LF
        break;
      case 0x0d:    // CR
        break;
      default:
        writeLine("Unrecognized command, ? to list commands");
        break;
    }
}

////////////////////////////////////////////////////////////////
// countParms()
// Syntax of a line is
// X[aaaa][,dddd]]
// X = command
// aaaa is a hex value
// Returns the count of parameters on a line
////////////////////////////////////////////////////////////////

uint8 countParms(char * stringToParse)
{
    if (findInString(stringToParse,',') == -1)
        return(1);
    else
        return(2);
}

////////////////////////////////////////////////////////////////
// uint32 extractParm(char * stringToParse, uint8 parmNumber)
////////////////////////////////////////////////////////////////

uint32 extractParm(char * stringToParse, uint8 parmNumber)
{
    //writeLine("extractParm: got here");
    char numberString[5];
    //writeLine("extractParm: copy string");
    //writeLine(stringToParse);
    if (parmNumber == 0)
    {
        strcpy(numberString,stringToParse);
        uint8 lineoff=0;
        while ((numberString[lineoff] != ',') && (numberString[lineoff] != 0))
            lineoff++;
        numberString[lineoff] = 0;
    }
    else if (parmNumber == 1)
    {
        uint8 parmOffset;
        parmOffset = findInString(stringToParse,',');
        parmOffset += 1;
        strcpy(numberString,&stringToParse[parmOffset]);
    }
    //writeLineNoLF("extractParm: done returning value:");
    //writeLine(numberString);
    return(stringToLong(numberString));
}

////////////////////////////////////////////////////////////////
// int8 checkParmCount(char * rxBuff, uint8 expectedParmCount)
////////////////////////////////////////////////////////////////

int8 checkParmCount(char * rxBuff, uint8 expectedParmCount)
{
    //writeLine("checkParmCount: got here");
    if (countParms(rxBuff) != expectedParmCount)
    {
        writeLineNoLF("checkParmCount: Parameter error: ");
        writeLine(rxBuff);
        return -1;
    }
    return 0;
}

/* [] END OF FILE */
