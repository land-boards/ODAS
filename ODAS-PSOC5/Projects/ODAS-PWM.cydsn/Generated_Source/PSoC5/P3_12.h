/*******************************************************************************
* File Name: P3_12.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_P3_12_H) /* Pins P3_12_H */
#define CY_PINS_P3_12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "P3_12_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 P3_12__PORT == 15 && ((P3_12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    P3_12_Write(uint8 value) ;
void    P3_12_SetDriveMode(uint8 mode) ;
uint8   P3_12_ReadDataReg(void) ;
uint8   P3_12_Read(void) ;
uint8   P3_12_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P3_12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define P3_12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define P3_12_DM_RES_UP          PIN_DM_RES_UP
#define P3_12_DM_RES_DWN         PIN_DM_RES_DWN
#define P3_12_DM_OD_LO           PIN_DM_OD_LO
#define P3_12_DM_OD_HI           PIN_DM_OD_HI
#define P3_12_DM_STRONG          PIN_DM_STRONG
#define P3_12_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define P3_12_MASK               P3_12__MASK
#define P3_12_SHIFT              P3_12__SHIFT
#define P3_12_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P3_12_PS                     (* (reg8 *) P3_12__PS)
/* Data Register */
#define P3_12_DR                     (* (reg8 *) P3_12__DR)
/* Port Number */
#define P3_12_PRT_NUM                (* (reg8 *) P3_12__PRT) 
/* Connect to Analog Globals */                                                  
#define P3_12_AG                     (* (reg8 *) P3_12__AG)                       
/* Analog MUX bux enable */
#define P3_12_AMUX                   (* (reg8 *) P3_12__AMUX) 
/* Bidirectional Enable */                                                        
#define P3_12_BIE                    (* (reg8 *) P3_12__BIE)
/* Bit-mask for Aliased Register Access */
#define P3_12_BIT_MASK               (* (reg8 *) P3_12__BIT_MASK)
/* Bypass Enable */
#define P3_12_BYP                    (* (reg8 *) P3_12__BYP)
/* Port wide control signals */                                                   
#define P3_12_CTL                    (* (reg8 *) P3_12__CTL)
/* Drive Modes */
#define P3_12_DM0                    (* (reg8 *) P3_12__DM0) 
#define P3_12_DM1                    (* (reg8 *) P3_12__DM1)
#define P3_12_DM2                    (* (reg8 *) P3_12__DM2) 
/* Input Buffer Disable Override */
#define P3_12_INP_DIS                (* (reg8 *) P3_12__INP_DIS)
/* LCD Common or Segment Drive */
#define P3_12_LCD_COM_SEG            (* (reg8 *) P3_12__LCD_COM_SEG)
/* Enable Segment LCD */
#define P3_12_LCD_EN                 (* (reg8 *) P3_12__LCD_EN)
/* Slew Rate Control */
#define P3_12_SLW                    (* (reg8 *) P3_12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define P3_12_PRTDSI__CAPS_SEL       (* (reg8 *) P3_12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define P3_12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) P3_12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define P3_12_PRTDSI__OE_SEL0        (* (reg8 *) P3_12__PRTDSI__OE_SEL0) 
#define P3_12_PRTDSI__OE_SEL1        (* (reg8 *) P3_12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define P3_12_PRTDSI__OUT_SEL0       (* (reg8 *) P3_12__PRTDSI__OUT_SEL0) 
#define P3_12_PRTDSI__OUT_SEL1       (* (reg8 *) P3_12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define P3_12_PRTDSI__SYNC_OUT       (* (reg8 *) P3_12__PRTDSI__SYNC_OUT) 


#if defined(P3_12__INTSTAT)  /* Interrupt Registers */

    #define P3_12_INTSTAT                (* (reg8 *) P3_12__INTSTAT)
    #define P3_12_SNAP                   (* (reg8 *) P3_12__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_P3_12_H */


/* [] END OF FILE */
