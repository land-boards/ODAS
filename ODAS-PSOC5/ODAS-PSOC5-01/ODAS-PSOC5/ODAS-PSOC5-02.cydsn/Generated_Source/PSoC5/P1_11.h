/*******************************************************************************
* File Name: P1_11.h  
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

#if !defined(CY_PINS_P1_11_H) /* Pins P1_11_H */
#define CY_PINS_P1_11_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "P1_11_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 P1_11__PORT == 15 && ((P1_11__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    P1_11_Write(uint8 value);
void    P1_11_SetDriveMode(uint8 mode);
uint8   P1_11_ReadDataReg(void);
uint8   P1_11_Read(void);
void    P1_11_SetInterruptMode(uint16 position, uint16 mode);
uint8   P1_11_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the P1_11_SetDriveMode() function.
     *  @{
     */
        #define P1_11_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define P1_11_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define P1_11_DM_RES_UP          PIN_DM_RES_UP
        #define P1_11_DM_RES_DWN         PIN_DM_RES_DWN
        #define P1_11_DM_OD_LO           PIN_DM_OD_LO
        #define P1_11_DM_OD_HI           PIN_DM_OD_HI
        #define P1_11_DM_STRONG          PIN_DM_STRONG
        #define P1_11_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define P1_11_MASK               P1_11__MASK
#define P1_11_SHIFT              P1_11__SHIFT
#define P1_11_WIDTH              1u

/* Interrupt constants */
#if defined(P1_11__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in P1_11_SetInterruptMode() function.
     *  @{
     */
        #define P1_11_INTR_NONE      (uint16)(0x0000u)
        #define P1_11_INTR_RISING    (uint16)(0x0001u)
        #define P1_11_INTR_FALLING   (uint16)(0x0002u)
        #define P1_11_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define P1_11_INTR_MASK      (0x01u) 
#endif /* (P1_11__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define P1_11_PS                     (* (reg8 *) P1_11__PS)
/* Data Register */
#define P1_11_DR                     (* (reg8 *) P1_11__DR)
/* Port Number */
#define P1_11_PRT_NUM                (* (reg8 *) P1_11__PRT) 
/* Connect to Analog Globals */                                                  
#define P1_11_AG                     (* (reg8 *) P1_11__AG)                       
/* Analog MUX bux enable */
#define P1_11_AMUX                   (* (reg8 *) P1_11__AMUX) 
/* Bidirectional Enable */                                                        
#define P1_11_BIE                    (* (reg8 *) P1_11__BIE)
/* Bit-mask for Aliased Register Access */
#define P1_11_BIT_MASK               (* (reg8 *) P1_11__BIT_MASK)
/* Bypass Enable */
#define P1_11_BYP                    (* (reg8 *) P1_11__BYP)
/* Port wide control signals */                                                   
#define P1_11_CTL                    (* (reg8 *) P1_11__CTL)
/* Drive Modes */
#define P1_11_DM0                    (* (reg8 *) P1_11__DM0) 
#define P1_11_DM1                    (* (reg8 *) P1_11__DM1)
#define P1_11_DM2                    (* (reg8 *) P1_11__DM2) 
/* Input Buffer Disable Override */
#define P1_11_INP_DIS                (* (reg8 *) P1_11__INP_DIS)
/* LCD Common or Segment Drive */
#define P1_11_LCD_COM_SEG            (* (reg8 *) P1_11__LCD_COM_SEG)
/* Enable Segment LCD */
#define P1_11_LCD_EN                 (* (reg8 *) P1_11__LCD_EN)
/* Slew Rate Control */
#define P1_11_SLW                    (* (reg8 *) P1_11__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define P1_11_PRTDSI__CAPS_SEL       (* (reg8 *) P1_11__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define P1_11_PRTDSI__DBL_SYNC_IN    (* (reg8 *) P1_11__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define P1_11_PRTDSI__OE_SEL0        (* (reg8 *) P1_11__PRTDSI__OE_SEL0) 
#define P1_11_PRTDSI__OE_SEL1        (* (reg8 *) P1_11__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define P1_11_PRTDSI__OUT_SEL0       (* (reg8 *) P1_11__PRTDSI__OUT_SEL0) 
#define P1_11_PRTDSI__OUT_SEL1       (* (reg8 *) P1_11__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define P1_11_PRTDSI__SYNC_OUT       (* (reg8 *) P1_11__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(P1_11__SIO_CFG)
    #define P1_11_SIO_HYST_EN        (* (reg8 *) P1_11__SIO_HYST_EN)
    #define P1_11_SIO_REG_HIFREQ     (* (reg8 *) P1_11__SIO_REG_HIFREQ)
    #define P1_11_SIO_CFG            (* (reg8 *) P1_11__SIO_CFG)
    #define P1_11_SIO_DIFF           (* (reg8 *) P1_11__SIO_DIFF)
#endif /* (P1_11__SIO_CFG) */

/* Interrupt Registers */
#if defined(P1_11__INTSTAT)
    #define P1_11_INTSTAT            (* (reg8 *) P1_11__INTSTAT)
    #define P1_11_SNAP               (* (reg8 *) P1_11__SNAP)
    
	#define P1_11_0_INTTYPE_REG 		(* (reg8 *) P1_11__0__INTTYPE)
#endif /* (P1_11__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_P1_11_H */


/* [] END OF FILE */
