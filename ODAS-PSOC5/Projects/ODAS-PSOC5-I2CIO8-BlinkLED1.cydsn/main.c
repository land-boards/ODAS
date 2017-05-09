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

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_Start();
    initDIGIO8Card();
    CyDelay(500);
    for(;;)
    {
        LED_Write(0);
        writeDIGIO8Card(0x05);
        CyDelay(500);
        LED_Write(1);
        writeDIGIO8Card(0x0a);
        CyDelay(500);
    }
}
