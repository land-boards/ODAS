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

#include "project.h"
#include "proEnv.h"
#include "mytypes.h"
#include "ARM_Monitor.h"
#include "stringConvs.h"
#include "accessMemory.h"
#include <strings.h>
#ifdef DEBUG_ON_PC
#include "pcSerialIO.h"
char myStringInMemory[0x100];
#else
#include "serialIO.h"
#endif

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

////////////////////////////////////////////////////////////////
// void dumpMem(uint32)
////////////////////////////////////////////////////////////////

void dumpMem(uint32 dumpStart)
{
    char numberString[9];
    uint32 dumpLongAddress;
    uint32 dumpByteAddress;
    uint32 lineOffRow;
    uint32 lineOff;
    //writeLine("dumpMem: got here");
    dumpLongAddress = dumpStart;
    dumpByteAddress = dumpStart;
    //writeLine("dumpMem: looping");
   writeLine("Enter to continue, any other key to stop");
   while(1)
    {
        for (lineOffRow = 0; lineOffRow < 16;  lineOffRow++) 
        {
            longToString(dumpLongAddress,&numberString[0]);
            writeLineNoLF(numberString);
            writeLineNoLF(" ");
            for (lineOff = 0; lineOff < 4; lineOff++)
            {
                longToString(readLong(dumpLongAddress+(4*lineOff)),&numberString[0]);
                writeLineNoLF(numberString);
                writeLineNoLF(" ");
            }
            dumpLongAddress += 16;
            for (lineOff = 0; lineOff < 16; lineOff++)
            {
                char rdChar = readByte(dumpByteAddress+lineOff);
                if ((rdChar < 0x20) || (rdChar >= 0x7e))
                    rdChar = '.';
                outSingleChar(rdChar);
            }
            dumpByteAddress += 16;
            writeLine(" ");
        }
        if (getSingleChar() != 0x0d)
            return;
    }
}

////////////////////////////////////////////////////////////////
// void readMemByte(uint32 readAddress)
////////////////////////////////////////////////////////////////

void readMemByte(uint32 readAddress)
{
    char numberString[9];
    writeLine(" ");
    while(1)
    {
        uint8 valRead = readByte(readAddress);
        longToString(readAddress,&numberString[0]);
        writeLineNoLF(numberString);
        writeLineNoLF(" ");
        //writeLine("readMem: got here");
        byteToString(valRead,&numberString[0]);
        writeLine(numberString);
        if (getSingleChar() != 0x0d)
            return;
        readAddress += 1;
    }
}

////////////////////////////////////////////////////////////////
// void readMemShort(uint32 readAddress)
////////////////////////////////////////////////////////////////

void readMemShort(uint32 readAddress)
{
    char numberString[9];
    writeLine(" ");
    while(1)
    {
        longToString(readAddress,&numberString[0]);
        writeLineNoLF(numberString);
        writeLineNoLF(" ");
        uint16 valRead = readShort(readAddress);
        //writeLine("readMem: got here");
        shortToString(valRead,&numberString[0]);
        writeLine(numberString);
        if (getSingleChar() != 0x0d)
            return;
        readAddress += 2;
    }
}

////////////////////////////////////////////////////////////////
// void readMemLong(uint32 readAddress)
////////////////////////////////////////////////////////////////

void readMemLong(uint32 readAddress)
{
    char numberString[9];
    writeLine(" ");
    while(1)
    {
        longToString(readAddress,&numberString[0]);
        writeLineNoLF(numberString);
        writeLineNoLF(" ");
        uint32 valRead = readLong(readAddress);
        //writeLine("readMem: got here");
        longToString(valRead,&numberString[0]);
        writeLine(numberString);
        if (getSingleChar() != 0x0d)
            return;
        readAddress += 4;
    }
}

////////////////////////////////////////////////////////////////
// void writeMemLong(uint32 writeAddress, uint32 writeData)
////////////////////////////////////////////////////////////////

void writeMemLong(uint32 writeAddress, uint32 writeData)
{
    char numberString[9];
    writeLineNoLF("writeMem: writing - address=");
    longToString(writeAddress,&numberString[0]);
    writeLineNoLF(numberString);
    writeLineNoLF(", data=");
    longToString(writeData,&numberString[0]);
    writeLine(numberString);
    writeLong(writeAddress,writeData);
}

////////////////////////////////////////////////////////////////
// void writeMemShort(uint32 writeAddress, uint32 writeData)
////////////////////////////////////////////////////////////////

void writeMemShort(uint32 writeAddress, uint16 writeData)
{
    char numberString[9];
    writeLineNoLF("writeMem: writing - address=");
    longToString(writeAddress,&numberString[0]);
    writeLineNoLF(numberString);
    writeLineNoLF(", data=");
    longToString(writeData,&numberString[0]);
    writeLine(numberString);
    writeLong(writeAddress,writeData);
}

////////////////////////////////////////////////////////////////
// void writeMemByte(uint32 writeAddress, uint32 writeData)
////////////////////////////////////////////////////////////////

void writeMemByte(uint32 writeAddress, uint8 writeData)
{
    char numberString[9];
    writeLineNoLF("writeMem: writing - address=");
    longToString(writeAddress,&numberString[0]);
    writeLineNoLF(numberString);
    writeLineNoLF(", data=");
    longToString(writeData,&numberString[0]);
    writeLine(numberString);
    writeLong(writeAddress,writeData);
}



void goCommand(uint32 goAddress)
{
    writeLine(&myStringInMemory[0]);
}

void disassemble(uint32 disassembleAddress)
{
    myStringInMemory[0] = 0x34;
}

    
////////////////////////////////////////////////////////////////
// void ARM_Monitor(void)
////////////////////////////////////////////////////////////////

void ARM_Monitor(void)
{
    char8 rxBufferPtr[80];
    writeLine("ARM PsOC Monitor v0.0.2 (? for a list of commands)");
    readLine(rxBufferPtr);
    switch (rxBufferPtr[0])
    {
      case '?':
      case 'H':
      case 'h':
        writeLine("RSADDR - Read/Modify byte/short/long data at address");
        writeLine("WSADDR,DATA - Write byte/short/long address with data");
        writeLine("Daddress - Dump starting at address");
        writeLine("Gaddress - Go start executing at address");
        writeLine("Aaddress - disAssemble code at address");
        break;
      case 'D':
      case 'd':
        if (checkParmCount(rxBufferPtr,1) == -1)
            break;
        else
            dumpMem(extractParm(&rxBufferPtr[1],0));
        break;
      case 'R':
      case 'r':
        if (checkParmCount(&rxBufferPtr[2],1) == -1)
            break;
        else
        {
            if ((rxBufferPtr[1]=='B') || (rxBufferPtr[1]=='b'))
                readMemByte(extractParm(&rxBufferPtr[2],0));
            else if ((rxBufferPtr[1]=='S') || (rxBufferPtr[1]=='s'))
                readMemShort(extractParm(&rxBufferPtr[2],0));
            else if ((rxBufferPtr[1]=='L') || (rxBufferPtr[1]=='l'))
                readMemLong(extractParm(&rxBufferPtr[2],0));
            else
                writeLine("RSADDR - Read Byte/Short/Long data at ADDRess");
        }
        break;
      case 'W':
      case 'w':
        if (checkParmCount(rxBufferPtr,2) == -1)
            break;
        else
        {
            writeLine("got write command");
            if ((rxBufferPtr[1]=='B') || (rxBufferPtr[1]=='b'))
                writeMemByte(extractParm(&rxBufferPtr[2],0),extractParm(rxBufferPtr,1));
            else if ((rxBufferPtr[1]=='S') || (rxBufferPtr[1]=='s'))
                writeMemShort(extractParm(&rxBufferPtr[2],0),extractParm(rxBufferPtr,1));
            else if ((rxBufferPtr[1]=='L') || (rxBufferPtr[1]=='l'))
                writeMemLong(extractParm(&rxBufferPtr[2],0),extractParm(rxBufferPtr,1));
            else
                writeLine("WSADDR,DATA - Write Byte/Short/Long ADDRess with DATA");
        }
        break;
      case 'G':
      case 'g':
        if (checkParmCount(rxBufferPtr,1) == -1)
            break;
        else
            goCommand(extractParm(rxBufferPtr,0));
        break;
      case 'A':
      case 'a':
        if (checkParmCount(rxBufferPtr,1) == -1)
            break;
        else
            disassemble(extractParm(rxBufferPtr,0));
        break;
      default:
        writeLine("Unrecognized command, ? to list commands");
        break;
    }
//        if (rxBufferPtr[0] == 'R')
//           writeLine("Read");
//        Control_Reg_1_Write(buffLen);         /* Number of character */
//        blinkLED(5);
//        writeLine(rxBufferPtr);
   
}

/* [] END OF FILE */
