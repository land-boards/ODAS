/*******************************************************************************
* File Name: APWM7.h  
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

#if !defined(CY_PINS_APWM7_H) /* Pins APWM7_H */
#define CY_PINS_APWM7_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM7_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM7__PORT == 15 && ((APWM7__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM7_Write(uint8 value);
void    APWM7_SetDriveMode(uint8 mode);
uint8   APWM7_ReadDataReg(void);
uint8   APWM7_Read(void);
void    APWM7_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM7_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM7_SetDriveMode() function.
     *  @{
     */
        #define APWM7_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM7_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM7_DM_RES_UP          PIN_DM_RES_UP
        #define APWM7_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM7_DM_OD_LO           PIN_DM_OD_LO
        #define APWM7_DM_OD_HI           PIN_DM_OD_HI
        #define APWM7_DM_STRONG          PIN_DM_STRONG
        #define APWM7_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM7_MASK               APWM7__MASK
#define APWM7_SHIFT              APWM7__SHIFT
#define APWM7_WIDTH              1u

/* Interrupt constants */
#if defined(APWM7__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM7_SetInterruptMode() function.
     *  @{
     */
        #define APWM7_INTR_NONE      (uint16)(0x0000u)
        #define APWM7_INTR_RISING    (uint16)(0x0001u)
        #define APWM7_INTR_FALLING   (uint16)(0x0002u)
        #define APWM7_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM7_INTR_MASK      (0x01u) 
#endif /* (APWM7__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM7_PS                     (* (reg8 *) APWM7__PS)
/* Data Register */
#define APWM7_DR                     (* (reg8 *) APWM7__DR)
/* Port Number */
#define APWM7_PRT_NUM                (* (reg8 *) APWM7__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM7_AG                     (* (reg8 *) APWM7__AG)                       
/* Analog MUX bux enable */
#define APWM7_AMUX                   (* (reg8 *) APWM7__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM7_BIE                    (* (reg8 *) APWM7__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM7_BIT_MASK               (* (reg8 *) APWM7__BIT_MASK)
/* Bypass Enable */
#define APWM7_BYP                    (* (reg8 *) APWM7__BYP)
/* Port wide control signals */                                                   
#define APWM7_CTL                    (* (reg8 *) APWM7__CTL)
/* Drive Modes */
#define APWM7_DM0                    (* (reg8 *) APWM7__DM0) 
#define APWM7_DM1                    (* (reg8 *) APWM7__DM1)
#define APWM7_DM2                    (* (reg8 *) APWM7__DM2) 
/* Input Buffer Disable Override */
#define APWM7_INP_DIS                (* (reg8 *) APWM7__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM7_LCD_COM_SEG            (* (reg8 *) APWM7__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM7_LCD_EN                 (* (reg8 *) APWM7__LCD_EN)
/* Slew Rate Control */
#define APWM7_SLW                    (* (reg8 *) APWM7__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM7_PRTDSI__CAPS_SEL       (* (reg8 *) APWM7__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM7_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM7__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM7_PRTDSI__OE_SEL0        (* (reg8 *) APWM7__PRTDSI__OE_SEL0) 
#define APWM7_PRTDSI__OE_SEL1        (* (reg8 *) APWM7__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM7_PRTDSI__OUT_SEL0       (* (reg8 *) APWM7__PRTDSI__OUT_SEL0) 
#define APWM7_PRTDSI__OUT_SEL1       (* (reg8 *) APWM7__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM7_PRTDSI__SYNC_OUT       (* (reg8 *) APWM7__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM7__SIO_CFG)
    #define APWM7_SIO_HYST_EN        (* (reg8 *) APWM7__SIO_HYST_EN)
    #define APWM7_SIO_REG_HIFREQ     (* (reg8 *) APWM7__SIO_REG_HIFREQ)
    #define APWM7_SIO_CFG            (* (reg8 *) APWM7__SIO_CFG)
    #define APWM7_SIO_DIFF           (* (reg8 *) APWM7__SIO_DIFF)
#endif /* (APWM7__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM7__INTSTAT)
    #define APWM7_INTSTAT            (* (reg8 *) APWM7__INTSTAT)
    #define APWM7_SNAP               (* (reg8 *) APWM7__SNAP)
    
	#define APWM7_0_INTTYPE_REG 		(* (reg8 *) APWM7__0__INTTYPE)
#endif /* (APWM7__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM7_H */


/* [] END OF FILE */
