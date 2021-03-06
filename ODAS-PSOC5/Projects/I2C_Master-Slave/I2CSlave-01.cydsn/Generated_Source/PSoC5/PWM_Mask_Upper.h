/*******************************************************************************
* File Name: PWM_Mask_Upper.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_PWM_Mask_Upper_H) /* CY_CONTROL_REG_PWM_Mask_Upper_H */
#define CY_CONTROL_REG_PWM_Mask_Upper_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} PWM_Mask_Upper_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    PWM_Mask_Upper_Write(uint8 control) ;
uint8   PWM_Mask_Upper_Read(void) ;

void PWM_Mask_Upper_SaveConfig(void) ;
void PWM_Mask_Upper_RestoreConfig(void) ;
void PWM_Mask_Upper_Sleep(void) ; 
void PWM_Mask_Upper_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define PWM_Mask_Upper_Control        (* (reg8 *) PWM_Mask_Upper_Sync_ctrl_reg__CONTROL_REG )
#define PWM_Mask_Upper_Control_PTR    (  (reg8 *) PWM_Mask_Upper_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_PWM_Mask_Upper_H */


/* [] END OF FILE */
