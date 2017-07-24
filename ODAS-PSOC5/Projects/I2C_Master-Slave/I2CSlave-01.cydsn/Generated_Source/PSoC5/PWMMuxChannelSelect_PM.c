/*******************************************************************************
* File Name: PWMMuxChannelSelect_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "PWMMuxChannelSelect.h"

/* Check for removal by optimization */
#if !defined(PWMMuxChannelSelect_Sync_ctrl_reg__REMOVED)

static PWMMuxChannelSelect_BACKUP_STRUCT  PWMMuxChannelSelect_backup = {0u};

    
/*******************************************************************************
* Function Name: PWMMuxChannelSelect_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWMMuxChannelSelect_SaveConfig(void) 
{
    PWMMuxChannelSelect_backup.controlState = PWMMuxChannelSelect_Control;
}


/*******************************************************************************
* Function Name: PWMMuxChannelSelect_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void PWMMuxChannelSelect_RestoreConfig(void) 
{
     PWMMuxChannelSelect_Control = PWMMuxChannelSelect_backup.controlState;
}


/*******************************************************************************
* Function Name: PWMMuxChannelSelect_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWMMuxChannelSelect_Sleep(void) 
{
    PWMMuxChannelSelect_SaveConfig();
}


/*******************************************************************************
* Function Name: PWMMuxChannelSelect_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void PWMMuxChannelSelect_Wakeup(void)  
{
    PWMMuxChannelSelect_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
