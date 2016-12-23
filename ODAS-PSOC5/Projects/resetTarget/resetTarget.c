/*******************************************************************************
* File Name: resetTarget.c
* Version 3.0
*
* Description:
*  This file provides the source code for "Step1: Enter Programming Mode" in Programming flow.
*  It also has the routine to exit programming mode.
*  This step is provided as separate .c, .h file as the procedure to enter target programming 
*  mode has strict timing requirements.
*
* Note:
*  Refer to the PSoC 5LP Programming specifications for details on timing requirements.
*******************************************************************************/

/********************************************************************************
*   Header file Inclusion
********************************************************************************/
#include <stdio.h>
#include <wiringPi.h>
#include "DeviceAcquire.h"

/* "Swd_PhysicalLayer.h" file contains the bit banging routines for SWD protocol.
   "Swd_PacketLayer.h" file contains the packet definitions for the SWD protocol."  */
#include "Swd_PhysicalLayer.h"
#include "Swd_PacketLayer.h"

/*******************************************************************************
* Function Name: SetXresHigh
********************************************************************************
*
* Summary:
*  Sets the XRES pin high
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_OUTPUT_HIGH in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetXresHigh()
{
    XRES_OUTPUT_HIGH;
    XRES_OUTPUT_HIGH;
}

/*******************************************************************************
* Function Name: SetXresLow
********************************************************************************
*
* Summary:
*  Sets the XRES pin low
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Note:
*  The function definition is the same as the macro definition XRES_OUTPUT_LOW in
*  Swd_PhysicalLayer.h.
*
*******************************************************************************/
inline void SetXresLow()
{
    XRES_OUTPUT_LOW;
    XRES_OUTPUT_LOW;
}

void main()
{
    /* Generate active low rest pulse for 100 uS */
    SetXresLow();
    delayMicroseconds(99);
    SetXresHigh();
    delayMicroseconds(10);

    /* Make XRES High-Z after generating the reset pulse */  
    SetXresHizInput();
}
