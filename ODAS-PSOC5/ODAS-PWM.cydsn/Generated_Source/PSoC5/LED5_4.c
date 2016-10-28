/*******************************************************************************
* File Name: LED5_4.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "LED5_4.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 LED5_4__PORT == 15 && ((LED5_4__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: LED5_4_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void LED5_4_Write(uint8 value) 
{
    uint8 staticBits = (LED5_4_DR & (uint8)(~LED5_4_MASK));
    LED5_4_DR = staticBits | ((uint8)(value << LED5_4_SHIFT) & LED5_4_MASK);
}


/*******************************************************************************
* Function Name: LED5_4_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LED5_4_DM_STRONG     Strong Drive 
*  LED5_4_DM_OD_HI      Open Drain, Drives High 
*  LED5_4_DM_OD_LO      Open Drain, Drives Low 
*  LED5_4_DM_RES_UP     Resistive Pull Up 
*  LED5_4_DM_RES_DWN    Resistive Pull Down 
*  LED5_4_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LED5_4_DM_DIG_HIZ    High Impedance Digital 
*  LED5_4_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LED5_4_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(LED5_4_0, mode);
}


/*******************************************************************************
* Function Name: LED5_4_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro LED5_4_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LED5_4_Read(void) 
{
    return (LED5_4_PS & LED5_4_MASK) >> LED5_4_SHIFT;
}


/*******************************************************************************
* Function Name: LED5_4_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 LED5_4_ReadDataReg(void) 
{
    return (LED5_4_DR & LED5_4_MASK) >> LED5_4_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LED5_4_INTSTAT) 

    /*******************************************************************************
    * Function Name: LED5_4_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 LED5_4_ClearInterrupt(void) 
    {
        return (LED5_4_INTSTAT & LED5_4_MASK) >> LED5_4_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
