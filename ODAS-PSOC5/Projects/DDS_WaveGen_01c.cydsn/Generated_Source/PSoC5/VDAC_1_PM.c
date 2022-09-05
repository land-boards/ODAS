/*******************************************************************************
* File Name: VDAC_1_PM.c  
* Version 1.90
*
* Description:
*  This file provides the power management source code to API for the
*  VDAC8.  
*
* Note:
*  None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "VDAC_1.h"

static VDAC_1_backupStruct VDAC_1_backup;


/*******************************************************************************
* Function Name: VDAC_1_SaveConfig
********************************************************************************
* Summary:
*  Save the current user configuration
*
* Parameters:  
*  void  
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC_1_SaveConfig(void) 
{
    if (!((VDAC_1_CR1 & VDAC_1_SRC_MASK) == VDAC_1_SRC_UDB))
    {
        VDAC_1_backup.data_value = VDAC_1_Data;
    }
}


/*******************************************************************************
* Function Name: VDAC_1_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
*******************************************************************************/
void VDAC_1_RestoreConfig(void) 
{
    if (!((VDAC_1_CR1 & VDAC_1_SRC_MASK) == VDAC_1_SRC_UDB))
    {
        if((VDAC_1_Strobe & VDAC_1_STRB_MASK) == VDAC_1_STRB_EN)
        {
            VDAC_1_Strobe &= (uint8)(~VDAC_1_STRB_MASK);
            VDAC_1_Data = VDAC_1_backup.data_value;
            VDAC_1_Strobe |= VDAC_1_STRB_EN;
        }
        else
        {
            VDAC_1_Data = VDAC_1_backup.data_value;
        }
    }
}


/*******************************************************************************
* Function Name: VDAC_1_Sleep
********************************************************************************
* Summary:
*  Stop and Save the user configuration
*
* Parameters:  
*  void:  
*
* Return: 
*  void
*
* Global variables:
*  VDAC_1_backup.enableState:  Is modified depending on the enable 
*  state  of the block before entering sleep mode.
*
*******************************************************************************/
void VDAC_1_Sleep(void) 
{
    /* Save VDAC8's enable state */    
    if(VDAC_1_ACT_PWR_EN == (VDAC_1_PWRMGR & VDAC_1_ACT_PWR_EN))
    {
        /* VDAC8 is enabled */
        VDAC_1_backup.enableState = 1u;
    }
    else
    {
        /* VDAC8 is disabled */
        VDAC_1_backup.enableState = 0u;
    }
    
    VDAC_1_Stop();
    VDAC_1_SaveConfig();
}


/*******************************************************************************
* Function Name: VDAC_1_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  VDAC_1_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void VDAC_1_Wakeup(void) 
{
    VDAC_1_RestoreConfig();
    
    if(VDAC_1_backup.enableState == 1u)
    {
        /* Enable VDAC8's operation */
        VDAC_1_Enable();

        /* Restore the data register */
        VDAC_1_SetValue(VDAC_1_Data);
    } /* Do nothing if VDAC8 was disabled before */    
}


/* [] END OF FILE */
