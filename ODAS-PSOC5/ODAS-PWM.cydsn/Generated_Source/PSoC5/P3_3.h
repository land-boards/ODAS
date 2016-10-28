/*******************************************************************************
* File Name: P3_3.h  
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

#if !defined(CY_PINS_P3_3_H) /* Pins P3_3_H */
#define CY_PINS_P3_3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "P3_3_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 P3_3__PORT == 15 && ((P3_3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    P3_3_Write(uint8 value) ;
void    P3_3_SetDriveMode(uint8 mode) ;
uint8   P3_3_ReadDataReg(void) ;
uint8   P3_3_Read(void) ;
uint8   P3_3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define P3_3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define P3_3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define P3_3_DM_RES_UP          PIN_DM_RES_UP
#define P3_3_DM_RES_DWN         PIN_DM_RES_DWN
#define P3_3_DM_OD_LO           PIN_DM_OD_LO
#define P3_3_DM_OD_HI           PIN_DM_OD_HI
#define P3_3_DM_STRONG          PIN_DM_STRONG
#define P3_3_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define P3_3_MASK               P3_3__MASK
#define P3_3_SHIFT              P3_3__SHIFT
#define P3_3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P3_3_PS                     (* (reg8 *) P3_3__PS)
/* Data Register */
#define P3_3_DR                     (* (reg8 *) P3_3__DR)
/* Port Number */
#define P3_3_PRT_NUM                (* (reg8 *) P3_3__PRT) 
/* Connect to Analog Globals */                                                  
#define P3_3_AG                     (* (reg8 *) P3_3__AG)                       
/* Analog MUX bux enable */
#define P3_3_AMUX                   (* (reg8 *) P3_3__AMUX) 
/* Bidirectional Enable */                                                        
#define P3_3_BIE                    (* (reg8 *) P3_3__BIE)
/* Bit-mask for Aliased Register Access */
#define P3_3_BIT_MASK               (* (reg8 *) P3_3__BIT_MASK)
/* Bypass Enable */
#define P3_3_BYP                    (* (reg8 *) P3_3__BYP)
/* Port wide control signals */                                                   
#define P3_3_CTL                    (* (reg8 *) P3_3__CTL)
/* Drive Modes */
#define P3_3_DM0                    (* (reg8 *) P3_3__DM0) 
#define P3_3_DM1                    (* (reg8 *) P3_3__DM1)
#define P3_3_DM2                    (* (reg8 *) P3_3__DM2) 
/* Input Buffer Disable Override */
#define P3_3_INP_DIS                (* (reg8 *) P3_3__INP_DIS)
/* LCD Common or Segment Drive */
#define P3_3_LCD_COM_SEG            (* (reg8 *) P3_3__LCD_COM_SEG)
/* Enable Segment LCD */
#define P3_3_LCD_EN                 (* (reg8 *) P3_3__LCD_EN)
/* Slew Rate Control */
#define P3_3_SLW                    (* (reg8 *) P3_3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define P3_3_PRTDSI__CAPS_SEL       (* (reg8 *) P3_3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define P3_3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) P3_3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define P3_3_PRTDSI__OE_SEL0        (* (reg8 *) P3_3__PRTDSI__OE_SEL0) 
#define P3_3_PRTDSI__OE_SEL1        (* (reg8 *) P3_3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define P3_3_PRTDSI__OUT_SEL0       (* (reg8 *) P3_3__PRTDSI__OUT_SEL0) 
#define P3_3_PRTDSI__OUT_SEL1       (* (reg8 *) P3_3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define P3_3_PRTDSI__SYNC_OUT       (* (reg8 *) P3_3__PRTDSI__SYNC_OUT) 


#if defined(P3_3__INTSTAT)  /* Interrupt Registers */

    #define P3_3_INTSTAT                (* (reg8 *) P3_3__INTSTAT)
    #define P3_3_SNAP                   (* (reg8 *) P3_3__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_P3_3_H */


/* [] END OF FILE */
