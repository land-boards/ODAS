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
#include "ARM_Monitor.h"
#include "serialIO.h"
extern char myStringInMemory[];

////////////////////////////////////////////////////////////////
//
////////////////////////////////////////////////////////////////

void blinkLED(uint8 blinkTime)
{
    LED_Write(1);
    CyDelay(blinkTime);
    LED_Write(0);
}

////////////////////////////////////////////////////////////////
// int main(void)
////////////////////////////////////////////////////////////////

int main(void)
{   
    CyGlobalIntEnable; /* Enable all interrupts by the processor. */
    initSerial();

    blinkLED(250);
    myStringInMemory[0] = 0x12;
    while(1)
    {
        ARM_Monitor();
    }
}

/* [] END OF FILE */
