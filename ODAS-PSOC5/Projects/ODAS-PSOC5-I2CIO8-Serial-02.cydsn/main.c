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
#include "DIGIO8Driver.h"
#include "DIGIO32Driver.h"
#include "TestCard.h"
#include "TestMenu.h"

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
    CyGlobalIntEnable; /* Enable global interrupts. */
    initSerial();
    initDIGIO8Card();
    CyDelay(500);
    for(;;)
    {
        testMenu();
    }
}
