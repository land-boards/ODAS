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

// Prototypes

void initDIGIO8Card(void);
void writeDIGIO8Card(uint8 outData);
uint8 readDIGIO8Card(void);

uint8 ledVal;

void toggleOnBoardLED(void)
{
    LED_Write(1);
    CyDelay(10);
    LED_Write(0);
    CyDelay(10);
}

int main()
{
    uint8 myReadVal=0x55;
    CyGlobalIntEnable; /* Enable global interrupts. */
    initDIGIO8Card();
    CyDelay(500);
    for(;;)
    {
        myReadVal = readDIGIO8Card();
        //toggleOnBoardLED();
        Control_Reg_1_Write(myReadVal);
        //toggleOnBoardLED();
        writeDIGIO8Card(myReadVal);
        myReadVal ^= 0x0f;
        //toggleOnBoardLED();
    }
}
