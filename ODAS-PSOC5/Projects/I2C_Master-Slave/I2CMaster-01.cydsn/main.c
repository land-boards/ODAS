/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  This is source code for I2C Master.
*
* Parameters used:
*  I2C Master
*   Implementation      Fixed function
*   Data rate           400kbps
*   SDA SCL pin config  Open drain, drives low
*   Pull-up resistors   2.2k each
*
* Data is sent via a I2C Master.
*
*******************************************************************************/

#include <project.h>
#include "serialIO.h"
#include "myI2CMaster.h"

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  main function performs following functions:
*   1. Starts all used components.
*   2. Toggles an LED on the slave card
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
int main()
{

    /* Enable global interrupts - required for I2C */
    CyGlobalIntEnable;
    LED_Write(0);
    I2CM_Start();
    UART_1_Start();
    printLine("Master Code Running");
    I2CM_MasterClearStatus();

    for(;;)
    {
        rdBuf[0] = 'W';
        if (wrBuf[0] == SLAVE_LED_ON)
            wrBuf[0] = SLAVE_LED_OFF;
        else
            wrBuf[0] = SLAVE_LED_ON;
        sendBuffToI2C(0x50);    // Send a buffer to the I2C interface
        CyDelay(6);             // Wait 10 msecs before checking for a reply
        LED_Write(1);
        getBuffFromI2C(0x50);   // Get a buffer from the I2C interface
        LED_Write(0);
        CyDelay(250);           // Wait mSecs
    }
}

/* [] END OF FILE */
