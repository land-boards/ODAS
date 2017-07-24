/*******************************************************************************
* File Name: main.c
*
* Version: 1.0
*
* Description:
*  I2C Slave Example 
*  
* Parameters used:
*  I2C Slave
*   Implementation		Fixed function
*   Data rate			400kbps
*   SDA SCL config     	Open drain, drives low
*   Pull-up resistors	2.2k each 
*
********************************************************************************
* Copyright 2012, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>
#include "serialIO.h"
#include "myI2CSlave.h"

/*******************************************************************************
* Function Name: main
********************************************************************************
*
* Summary:
*  Main function performs following functions:
*   1. Starts used components.
*   2. Reads slave data buffer.
*   3. Blinks LED
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
	/* Start I2C Master */
	I2C_1_Start();
    UART_1_Start();
    verboseFlag = SLAVE_NON_VERBOSE_MODE;

	/* Enable Global Interrupts - needed for I2C operation */
	CyGlobalIntEnable;
    initI2CBuffs();
    
    printLine("Slave is alive");
	for(;;)
    {
        waitForMasterToWrite();
        switch (wrBuf[0])       // buffer written from the host
        {
            case NULL_CMD:
                rdBuf[0] = 'Z';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printLine("NULL_CMD");
                break;
            case SLAVE_LED_OFF:             // Turn off the LED on the card
                LED_Write(0);
                rdBuf[0] = 'K';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printString("LED_OFF ");
                break;
            case SLAVE_LED_ON:              // Turn on the LED on the card
                LED_Write(1);
                rdBuf[0] = 'K';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printLine("LED_ON");
                break;
            case PWM_CHANNEL_MASK_VALUE:            // Set the output channel mask
                PWM_Mask_Upper_Write(wrBuf[1]);     // Upper bits of the mask
                PWM_Mask_Lower_Write(wrBuf[2]);     // Lower bits of the mask
                rdBuf[0] = 'K';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                {
                    printString("CH MASK: 0x");
                    printLong(wrBuf[1]);
                    printString("CH MASK: 0x");
                    printLong(wrBuf[2]);
                }
                break;
            case ALL_PWM_CHANNELS_ACTIVE:   // Drive all PWM channels actively
                Mux_Control_Write(0);
                rdBuf[0] = 'K';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printLine("ALL_PWM_ACTIVE");
                break;
            case USE_PWM_CHANNELS_MASK:     // Turn on individual PWM channels
                Mux_Control_Write(1);
                rdBuf[0] = 'K';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printLine("USE_PWM_MASK");
                break;
            case ALL_PWM_CHANNELS_LOW:      // Turn all PWM channels off
                Mux_Control_Write(2);
                rdBuf[0] = 'K';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printLine("ALL_PWM_LOW");
                break;
            case ALL_PWM_CHANNELS_HIGH:     // Turn all PWM channels on
                Mux_Control_Write(3);
                rdBuf[0] = 'K';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printLine("ALL_PWM_HIGH");
                break;
            case RETURN_ERROR_STATUS:       // Return an Error as status
                rdBuf[0] = 'E';
                if (verboseFlag == SLAVE_VERBOSE_MODE)
                    printLine("RTN_ERR");
                break;
            case SLAVE_NON_VERBOSE_MODE:
                rdBuf[0] = 'K';
                verboseFlag = SLAVE_NON_VERBOSE_MODE;
                printLine("NON_VERBOSE_MODE");
                break;
            case SLAVE_VERBOSE_MODE:
                rdBuf[0] = 'K';
                verboseFlag = SLAVE_VERBOSE_MODE;
                printLine("VERBOSE_MODE");
                break;
            default:
                rdBuf[0] = 'E';
                break;
        }
        wrBuf[0] = NULL_CMD;
        waitForMasterToRead();
//        printSingleChar('p');
	} /* End forever loop */
} /* End main */

/* [] END OF FILE */
