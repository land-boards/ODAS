/* ========================================
 * serialIO.c
 * Copyright AAC, LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF AAC.
 *
 * ========================================
*/

#include "project.h"
#undef DEBUG_ON_PC
#include "serialIO.h"
#include "stringConvs.h"

////////////////////////////////////////////////////////////////
// void initSerial(void)
////////////////////////////////////////////////////////////////

void initSerial(void)
{
    UART_1_Start();
}

////////////////////////////////////////////////////////////////
// printSingleChar(char)
////////////////////////////////////////////////////////////////

void printSingleChar(char8 txChar)
{
    uint8 txStat;
    do
    {
        txStat = UART_1_ReadTxStatus();
    }
    while (txStat & UART_1_TX_STS_FIFO_FULL);
    UART_1_PutChar(txChar);
}

////////////////////////////////////////////////////////////////
// void printString(char * lineBuffer)
////////////////////////////////////////////////////////////////

void printString(char * lineBuffer)
{
    char * linePtr;
    linePtr = lineBuffer;
    while (*linePtr != 0)
        printSingleChar(*linePtr++);
}

////////////////////////////////////////////////////////////////
// void printLine(char *)
////////////////////////////////////////////////////////////////

void printLine(char * lineBuffer)
{
   printString(lineBuffer);
   printSingleChar(0x0d);
   printSingleChar(0x0a);
}

////////////////////////////////////////////////////////////////
// void writeLong(uint32)
////////////////////////////////////////////////////////////////

void printLong(uint32 uLVal)
{
    char myWBuff[9];
    longToString(uLVal,myWBuff);
    printString(myWBuff);
}

////////////////////////////////////////////////////////////////
// void printBit(uint8_t)
////////////////////////////////////////////////////////////////

void printBit(uint8_t uBVal)
{
    char outChar[2];
    char myWBuff[9];
    longToString((uint32_t)uBVal,myWBuff);
    outChar[0] = myWBuff[7];
    outChar[1] = 0;
    printString(outChar);
}

////////////////////////////////////////////////////////////////
// char8 getSingleChar(void)
////////////////////////////////////////////////////////////////

char8 getSingleChar(void)
{
    uint8 rxStat;
    char8 rxChar;       /* Data received from the Serial port */
    while(1)
    {
        rxStat = UART_1_ReadRxStatus(); 
        if (rxStat & UART_1_RX_STS_FIFO_NOTEMPTY)
        {
            rxChar = UART_1_GetChar();
            return rxChar;
        }
    }
}

////////////////////////////////////////////////////////////////
// uint8 checkReceiveChar(void) - returns True if character present
////////////////////////////////////////////////////////////////

enum CHAR_PRESENT checkReceiveChar(void)
{
    uint8 rxStat = UART_1_ReadRxStatus();
    if (rxStat & UART_1_RX_STS_FIFO_NOTEMPTY)
        return CHAR_IS_PRESENT;
    return NO_CHAR_PRESENT;
}

////////////////////////////////////////////////////////////////
// uint8 readLine(char * lineBuffer)
////////////////////////////////////////////////////////////////

uint8 readLine(char * lineBuffer)
{
    uint8 byteCount=0;
    char * linePtr;
    uint8 rxStat;
    char8 rxChar;       /* Data received from the Serial port */
    uint8 endOfLine = 0;
    linePtr = lineBuffer;
    do
    {
        rxStat = UART_1_ReadRxStatus(); 
        if (rxStat & UART_1_RX_STS_FIFO_NOTEMPTY)
        {
            rxChar = UART_1_GetChar();
            if (rxChar == 0x0a || rxChar == 0x0d)
            {
                printSingleChar(rxChar);
                endOfLine = 1;
                *linePtr = 0;
                byteCount++;
                return byteCount;
            }
            else if ((rxChar == 0x08) ||(rxChar == 0x7f))
            {
                if (byteCount > 0)
                {
                    printSingleChar(0x08);
                    printSingleChar(' ');
                    printSingleChar(0x08);
                    linePtr--;
                    byteCount--;
                }
            }
            else if (byteCount > MAXLINELENGTH-2)
            {
                endOfLine = 1;
                *linePtr = 0;
            }
            else
            {
                printSingleChar(rxChar);
                *linePtr = rxChar;
                linePtr++;
                byteCount++;
            }
        }    
    }
    while(endOfLine == 0);
    return byteCount;
}

/* [] END OF FILE */
