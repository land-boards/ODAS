/*******************************************************************************
* File Name: P1_61.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_P1_61_H) /* Pins P1_61_H */
#define CY_PINS_P1_61_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "P1_61_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 P1_61__PORT == 15 && ((P1_61__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    P1_61_Write(uint8 value);
void    P1_61_SetDriveMode(uint8 mode);
uint8   P1_61_ReadDataReg(void);
uint8   P1_61_Read(void);
void    P1_61_SetInterruptMode(uint16 position, uint16 mode);
uint8   P1_61_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the P1_61_SetDriveMode() function.
     *  @{
     */
        #define P1_61_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define P1_61_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define P1_61_DM_RES_UP          PIN_DM_RES_UP
        #define P1_61_DM_RES_DWN         PIN_DM_RES_DWN
        #define P1_61_DM_OD_LO           PIN_DM_OD_LO
        #define P1_61_DM_OD_HI           PIN_DM_OD_HI
        #define P1_61_DM_STRONG          PIN_DM_STRONG
        #define P1_61_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define P1_61_MASK               P1_61__MASK
#define P1_61_SHIFT              P1_61__SHIFT
#define P1_61_WIDTH              1u

/* Interrupt constants */
#if defined(P1_61__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in P1_61_SetInterruptMode() function.
     *  @{
     */
        #define P1_61_INTR_NONE      (uint16)(0x0000u)
        #define P1_61_INTR_RISING    (uint16)(0x0001u)
        #define P1_61_INTR_FALLING   (uint16)(0x0002u)
        #define P1_61_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define P1_61_INTR_MASK      (0x01u) 
#endif /* (P1_61__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P1_61_PS                     (* (reg8 *) P1_61__PS)
/* Data Register */
#define P1_61_DR                     (* (reg8 *) P1_61__DR)
/* Port Number */
#define P1_61_PRT_NUM                (* (reg8 *) P1_61__PRT) 
/* Connect to Analog Globals */                                                  
#define P1_61_AG                     (* (reg8 *) P1_61__AG)                       
/* Analog MUX bux enable */
#define P1_61_AMUX                   (* (reg8 *) P1_61__AMUX) 
/* Bidirectional Enable */                                                        
#define P1_61_BIE                    (* (reg8 *) P1_61__BIE)
/* Bit-mask for Aliased Register Access */
#define P1_61_BIT_MASK               (* (reg8 *) P1_61__BIT_MASK)
/* Bypass Enable */
#define P1_61_BYP                    (* (reg8 *) P1_61__BYP)
/* Port wide control signals */                                                   
#define P1_61_CTL                    (* (reg8 *) P1_61__CTL)
/* Drive Modes */
#define P1_61_DM0                    (* (reg8 *) P1_61__DM0) 
#define P1_61_DM1                    (* (reg8 *) P1_61__DM1)
#define P1_61_DM2                    (* (reg8 *) P1_61__DM2) 
/* Input Buffer Disable Override */
#define P1_61_INP_DIS                (* (reg8 *) P1_61__INP_DIS)
/* LCD Common or Segment Drive */
#define P1_61_LCD_COM_SEG            (* (reg8 *) P1_61__LCD_COM_SEG)
/* Enable Segment LCD */
#define P1_61_LCD_EN                 (* (reg8 *) P1_61__LCD_EN)
/* Slew Rate Control */
#define P1_61_SLW                    (* (reg8 *) P1_61__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define P1_61_PRTDSI__CAPS_SEL       (* (reg8 *) P1_61__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define P1_61_PRTDSI__DBL_SYNC_IN    (* (reg8 *) P1_61__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define P1_61_PRTDSI__OE_SEL0        (* (reg8 *) P1_61__PRTDSI__OE_SEL0) 
#define P1_61_PRTDSI__OE_SEL1        (* (reg8 *) P1_61__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define P1_61_PRTDSI__OUT_SEL0       (* (reg8 *) P1_61__PRTDSI__OUT_SEL0) 
#define P1_61_PRTDSI__OUT_SEL1       (* (reg8 *) P1_61__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define P1_61_PRTDSI__SYNC_OUT       (* (reg8 *) P1_61__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(P1_61__SIO_CFG)
    #define P1_61_SIO_HYST_EN        (* (reg8 *) P1_61__SIO_HYST_EN)
    #define P1_61_SIO_REG_HIFREQ     (* (reg8 *) P1_61__SIO_REG_HIFREQ)
    #define P1_61_SIO_CFG            (* (reg8 *) P1_61__SIO_CFG)
    #define P1_61_SIO_DIFF           (* (reg8 *) P1_61__SIO_DIFF)
#endif /* (P1_61__SIO_CFG) */

/* Interrupt Registers */
#if defined(P1_61__INTSTAT)
    #define P1_61_INTSTAT            (* (reg8 *) P1_61__INTSTAT)
    #define P1_61_SNAP               (* (reg8 *) P1_61__SNAP)
    
	#define P1_61_0_INTTYPE_REG 		(* (reg8 *) P1_61__0__INTTYPE)
#endif /* (P1_61__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_P1_61_H */


/* [] END OF FILE */
