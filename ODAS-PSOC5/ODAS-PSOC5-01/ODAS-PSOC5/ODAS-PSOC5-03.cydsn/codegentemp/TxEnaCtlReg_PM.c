/*******************************************************************************
* File Name: TxEnaCtlReg_PM.c
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

#include "TxEnaCtlReg.h"

/* Check for removal by optimization */
#if !defined(TxEnaCtlReg_Sync_ctrl_reg__REMOVED)

static TxEnaCtlReg_BACKUP_STRUCT  TxEnaCtlReg_backup = {0u};

    
/*******************************************************************************
* Function Name: TxEnaCtlReg_SaveConfig
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
void TxEnaCtlReg_SaveConfig(void) 
{
    TxEnaCtlReg_backup.controlState = TxEnaCtlReg_Control;
}


/*******************************************************************************
* Function Name: TxEnaCtlReg_RestoreConfig
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
void TxEnaCtlReg_RestoreConfig(void) 
{
     TxEnaCtlReg_Control = TxEnaCtlReg_backup.controlState;
}


/*******************************************************************************
* Function Name: TxEnaCtlReg_Sleep
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
void TxEnaCtlReg_Sleep(void) 
{
    TxEnaCtlReg_SaveConfig();
}


/*******************************************************************************
* Function Name: TxEnaCtlReg_Wakeup
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
void TxEnaCtlReg_Wakeup(void)  
{
    TxEnaCtlReg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
