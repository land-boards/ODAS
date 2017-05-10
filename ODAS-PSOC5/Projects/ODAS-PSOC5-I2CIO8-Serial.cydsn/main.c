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

#include <project.h>
#include <strings.h>
#include <stdio.h>
#include "serialIO.h"

// Prototypes

void initDIGIO8Card(void);
void writeDIGIO8Card(uint8 outData);
uint8 readDIGIO8Card(void);
//void initSerial(void);
//char8 getSingleChar(void);
//void outSingleChar(char8 txChar);

uint8 ledVal;

void toggleOnBoardLED(void)
{
    LED_Write(1);
    CyDelay(50);
    LED_Write(0);
    CyDelay(50);
}

int main()
{
    uint8 myReadVal=0x55;
    CyGlobalIntEnable; /* Enable global interrupts. */
    initSerial();
    initDIGIO8Card();
    CyDelay(500);
    for(;;)
    {
        myReadVal = readDIGIO8Card();
        writeDIGIO8Card(myReadVal);
        myReadVal ^= 0x0f;
        toggleOnBoardLED();
        if (checkReceiveChar())
        {
            char8 myChar = getSingleChar();
            outSingleChar(myChar);
            Control_Reg_1_Write(myChar);
        }
    }
}
