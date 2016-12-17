/*******************************************************************************
* File Name: RP_GPIO_26.h  
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

#if !defined(CY_PINS_RP_GPIO_26_H) /* Pins RP_GPIO_26_H */
#define CY_PINS_RP_GPIO_26_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RP_GPIO_26_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RP_GPIO_26__PORT == 15 && ((RP_GPIO_26__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    RP_GPIO_26_Write(uint8 value) ;
void    RP_GPIO_26_SetDriveMode(uint8 mode) ;
uint8   RP_GPIO_26_ReadDataReg(void) ;
uint8   RP_GPIO_26_Read(void) ;
uint8   RP_GPIO_26_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define RP_GPIO_26_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define RP_GPIO_26_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define RP_GPIO_26_DM_RES_UP          PIN_DM_RES_UP
#define RP_GPIO_26_DM_RES_DWN         PIN_DM_RES_DWN
#define RP_GPIO_26_DM_OD_LO           PIN_DM_OD_LO
#define RP_GPIO_26_DM_OD_HI           PIN_DM_OD_HI
#define RP_GPIO_26_DM_STRONG          PIN_DM_STRONG
#define RP_GPIO_26_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define RP_GPIO_26_MASK               RP_GPIO_26__MASK
#define RP_GPIO_26_SHIFT              RP_GPIO_26__SHIFT
#define RP_GPIO_26_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RP_GPIO_26_PS                     (* (reg8 *) RP_GPIO_26__PS)
/* Data Register */
#define RP_GPIO_26_DR                     (* (reg8 *) RP_GPIO_26__DR)
/* Port Number */
#define RP_GPIO_26_PRT_NUM                (* (reg8 *) RP_GPIO_26__PRT) 
/* Connect to Analog Globals */                                                  
#define RP_GPIO_26_AG                     (* (reg8 *) RP_GPIO_26__AG)                       
/* Analog MUX bux enable */
#define RP_GPIO_26_AMUX                   (* (reg8 *) RP_GPIO_26__AMUX) 
/* Bidirectional Enable */                                                        
#define RP_GPIO_26_BIE                    (* (reg8 *) RP_GPIO_26__BIE)
/* Bit-mask for Aliased Register Access */
#define RP_GPIO_26_BIT_MASK               (* (reg8 *) RP_GPIO_26__BIT_MASK)
/* Bypass Enable */
#define RP_GPIO_26_BYP                    (* (reg8 *) RP_GPIO_26__BYP)
/* Port wide control signals */                                                   
#define RP_GPIO_26_CTL                    (* (reg8 *) RP_GPIO_26__CTL)
/* Drive Modes */
#define RP_GPIO_26_DM0                    (* (reg8 *) RP_GPIO_26__DM0) 
#define RP_GPIO_26_DM1                    (* (reg8 *) RP_GPIO_26__DM1)
#define RP_GPIO_26_DM2                    (* (reg8 *) RP_GPIO_26__DM2) 
/* Input Buffer Disable Override */
#define RP_GPIO_26_INP_DIS                (* (reg8 *) RP_GPIO_26__INP_DIS)
/* LCD Common or Segment Drive */
#define RP_GPIO_26_LCD_COM_SEG            (* (reg8 *) RP_GPIO_26__LCD_COM_SEG)
/* Enable Segment LCD */
#define RP_GPIO_26_LCD_EN                 (* (reg8 *) RP_GPIO_26__LCD_EN)
/* Slew Rate Control */
#define RP_GPIO_26_SLW                    (* (reg8 *) RP_GPIO_26__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RP_GPIO_26_PRTDSI__CAPS_SEL       (* (reg8 *) RP_GPIO_26__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RP_GPIO_26_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RP_GPIO_26__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RP_GPIO_26_PRTDSI__OE_SEL0        (* (reg8 *) RP_GPIO_26__PRTDSI__OE_SEL0) 
#define RP_GPIO_26_PRTDSI__OE_SEL1        (* (reg8 *) RP_GPIO_26__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RP_GPIO_26_PRTDSI__OUT_SEL0       (* (reg8 *) RP_GPIO_26__PRTDSI__OUT_SEL0) 
#define RP_GPIO_26_PRTDSI__OUT_SEL1       (* (reg8 *) RP_GPIO_26__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RP_GPIO_26_PRTDSI__SYNC_OUT       (* (reg8 *) RP_GPIO_26__PRTDSI__SYNC_OUT) 


#if defined(RP_GPIO_26__INTSTAT)  /* Interrupt Registers */

    #define RP_GPIO_26_INTSTAT                (* (reg8 *) RP_GPIO_26__INTSTAT)
    #define RP_GPIO_26_SNAP                   (* (reg8 *) RP_GPIO_26__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RP_GPIO_26_H */


/* [] END OF FILE */
