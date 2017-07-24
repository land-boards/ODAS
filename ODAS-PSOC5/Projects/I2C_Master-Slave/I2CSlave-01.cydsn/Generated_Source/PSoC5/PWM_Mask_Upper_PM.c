/*******************************************************************************
* File Name: PWM_Mask_Upper_PM.c
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

#include "PWM_Mask_Upper.h"

/* Check for removal by optimization */
#if !defined(PWM_Mask_Upper_Sync_ctrl_reg__REMOVED)

static PWM_Mask_Upper_BACKUP_STRUCT  PWM_Mask_Upper_backup = {0u};

    
/*******************************************************************************
* Function Name: PWM_Mask_Upper_SaveConfig
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
void PWM_Mask_Upper_SaveConfig(void) 
{
    PWM_Mask_Upper_backup.controlState = PWM_Mask_Upper_Control;
}


/*******************************************************************************
* Function Name: PWM_Mask_Upper_RestoreConfig
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
void PWM_Mask_Upper_RestoreConfig(void) 
{
     PWM_Mask_Upper_Control = PWM_Mask_Upper_backup.controlState;
}


/*******************************************************************************
* Function Name: PWM_Mask_Upper_Sleep
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
void PWM_Mask_Upper_Sleep(void) 
{
    PWM_Mask_Upper_SaveConfig();
}


/*******************************************************************************
* Function Name: PWM_Mask_Upper_Wakeup
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
void PWM_Mask_Upper_Wakeup(void)  
{
    PWM_Mask_Upper_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
