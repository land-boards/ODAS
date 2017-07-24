/*******************************************************************************
* File Name: APWM9.h  
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

#if !defined(CY_PINS_APWM9_H) /* Pins APWM9_H */
#define CY_PINS_APWM9_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM9_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM9__PORT == 15 && ((APWM9__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM9_Write(uint8 value);
void    APWM9_SetDriveMode(uint8 mode);
uint8   APWM9_ReadDataReg(void);
uint8   APWM9_Read(void);
void    APWM9_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM9_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM9_SetDriveMode() function.
     *  @{
     */
        #define APWM9_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM9_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM9_DM_RES_UP          PIN_DM_RES_UP
        #define APWM9_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM9_DM_OD_LO           PIN_DM_OD_LO
        #define APWM9_DM_OD_HI           PIN_DM_OD_HI
        #define APWM9_DM_STRONG          PIN_DM_STRONG
        #define APWM9_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM9_MASK               APWM9__MASK
#define APWM9_SHIFT              APWM9__SHIFT
#define APWM9_WIDTH              1u

/* Interrupt constants */
#if defined(APWM9__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM9_SetInterruptMode() function.
     *  @{
     */
        #define APWM9_INTR_NONE      (uint16)(0x0000u)
        #define APWM9_INTR_RISING    (uint16)(0x0001u)
        #define APWM9_INTR_FALLING   (uint16)(0x0002u)
        #define APWM9_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM9_INTR_MASK      (0x01u) 
#endif /* (APWM9__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM9_PS                     (* (reg8 *) APWM9__PS)
/* Data Register */
#define APWM9_DR                     (* (reg8 *) APWM9__DR)
/* Port Number */
#define APWM9_PRT_NUM                (* (reg8 *) APWM9__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM9_AG                     (* (reg8 *) APWM9__AG)                       
/* Analog MUX bux enable */
#define APWM9_AMUX                   (* (reg8 *) APWM9__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM9_BIE                    (* (reg8 *) APWM9__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM9_BIT_MASK               (* (reg8 *) APWM9__BIT_MASK)
/* Bypass Enable */
#define APWM9_BYP                    (* (reg8 *) APWM9__BYP)
/* Port wide control signals */                                                   
#define APWM9_CTL                    (* (reg8 *) APWM9__CTL)
/* Drive Modes */
#define APWM9_DM0                    (* (reg8 *) APWM9__DM0) 
#define APWM9_DM1                    (* (reg8 *) APWM9__DM1)
#define APWM9_DM2                    (* (reg8 *) APWM9__DM2) 
/* Input Buffer Disable Override */
#define APWM9_INP_DIS                (* (reg8 *) APWM9__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM9_LCD_COM_SEG            (* (reg8 *) APWM9__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM9_LCD_EN                 (* (reg8 *) APWM9__LCD_EN)
/* Slew Rate Control */
#define APWM9_SLW                    (* (reg8 *) APWM9__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM9_PRTDSI__CAPS_SEL       (* (reg8 *) APWM9__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM9_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM9__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM9_PRTDSI__OE_SEL0        (* (reg8 *) APWM9__PRTDSI__OE_SEL0) 
#define APWM9_PRTDSI__OE_SEL1        (* (reg8 *) APWM9__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM9_PRTDSI__OUT_SEL0       (* (reg8 *) APWM9__PRTDSI__OUT_SEL0) 
#define APWM9_PRTDSI__OUT_SEL1       (* (reg8 *) APWM9__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM9_PRTDSI__SYNC_OUT       (* (reg8 *) APWM9__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM9__SIO_CFG)
    #define APWM9_SIO_HYST_EN        (* (reg8 *) APWM9__SIO_HYST_EN)
    #define APWM9_SIO_REG_HIFREQ     (* (reg8 *) APWM9__SIO_REG_HIFREQ)
    #define APWM9_SIO_CFG            (* (reg8 *) APWM9__SIO_CFG)
    #define APWM9_SIO_DIFF           (* (reg8 *) APWM9__SIO_DIFF)
#endif /* (APWM9__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM9__INTSTAT)
    #define APWM9_INTSTAT            (* (reg8 *) APWM9__INTSTAT)
    #define APWM9_SNAP               (* (reg8 *) APWM9__SNAP)
    
	#define APWM9_0_INTTYPE_REG 		(* (reg8 *) APWM9__0__INTTYPE)
#endif /* (APWM9__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM9_H */


/* [] END OF FILE */
