/*******************************************************************************
* File Name: APWM6.h  
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

#if !defined(CY_PINS_APWM6_H) /* Pins APWM6_H */
#define CY_PINS_APWM6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM6_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM6__PORT == 15 && ((APWM6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM6_Write(uint8 value);
void    APWM6_SetDriveMode(uint8 mode);
uint8   APWM6_ReadDataReg(void);
uint8   APWM6_Read(void);
void    APWM6_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM6_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM6_SetDriveMode() function.
     *  @{
     */
        #define APWM6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM6_DM_RES_UP          PIN_DM_RES_UP
        #define APWM6_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM6_DM_OD_LO           PIN_DM_OD_LO
        #define APWM6_DM_OD_HI           PIN_DM_OD_HI
        #define APWM6_DM_STRONG          PIN_DM_STRONG
        #define APWM6_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM6_MASK               APWM6__MASK
#define APWM6_SHIFT              APWM6__SHIFT
#define APWM6_WIDTH              1u

/* Interrupt constants */
#if defined(APWM6__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM6_SetInterruptMode() function.
     *  @{
     */
        #define APWM6_INTR_NONE      (uint16)(0x0000u)
        #define APWM6_INTR_RISING    (uint16)(0x0001u)
        #define APWM6_INTR_FALLING   (uint16)(0x0002u)
        #define APWM6_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM6_INTR_MASK      (0x01u) 
#endif /* (APWM6__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM6_PS                     (* (reg8 *) APWM6__PS)
/* Data Register */
#define APWM6_DR                     (* (reg8 *) APWM6__DR)
/* Port Number */
#define APWM6_PRT_NUM                (* (reg8 *) APWM6__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM6_AG                     (* (reg8 *) APWM6__AG)                       
/* Analog MUX bux enable */
#define APWM6_AMUX                   (* (reg8 *) APWM6__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM6_BIE                    (* (reg8 *) APWM6__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM6_BIT_MASK               (* (reg8 *) APWM6__BIT_MASK)
/* Bypass Enable */
#define APWM6_BYP                    (* (reg8 *) APWM6__BYP)
/* Port wide control signals */                                                   
#define APWM6_CTL                    (* (reg8 *) APWM6__CTL)
/* Drive Modes */
#define APWM6_DM0                    (* (reg8 *) APWM6__DM0) 
#define APWM6_DM1                    (* (reg8 *) APWM6__DM1)
#define APWM6_DM2                    (* (reg8 *) APWM6__DM2) 
/* Input Buffer Disable Override */
#define APWM6_INP_DIS                (* (reg8 *) APWM6__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM6_LCD_COM_SEG            (* (reg8 *) APWM6__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM6_LCD_EN                 (* (reg8 *) APWM6__LCD_EN)
/* Slew Rate Control */
#define APWM6_SLW                    (* (reg8 *) APWM6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM6_PRTDSI__CAPS_SEL       (* (reg8 *) APWM6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM6_PRTDSI__OE_SEL0        (* (reg8 *) APWM6__PRTDSI__OE_SEL0) 
#define APWM6_PRTDSI__OE_SEL1        (* (reg8 *) APWM6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM6_PRTDSI__OUT_SEL0       (* (reg8 *) APWM6__PRTDSI__OUT_SEL0) 
#define APWM6_PRTDSI__OUT_SEL1       (* (reg8 *) APWM6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM6_PRTDSI__SYNC_OUT       (* (reg8 *) APWM6__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM6__SIO_CFG)
    #define APWM6_SIO_HYST_EN        (* (reg8 *) APWM6__SIO_HYST_EN)
    #define APWM6_SIO_REG_HIFREQ     (* (reg8 *) APWM6__SIO_REG_HIFREQ)
    #define APWM6_SIO_CFG            (* (reg8 *) APWM6__SIO_CFG)
    #define APWM6_SIO_DIFF           (* (reg8 *) APWM6__SIO_DIFF)
#endif /* (APWM6__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM6__INTSTAT)
    #define APWM6_INTSTAT            (* (reg8 *) APWM6__INTSTAT)
    #define APWM6_SNAP               (* (reg8 *) APWM6__SNAP)
    
	#define APWM6_0_INTTYPE_REG 		(* (reg8 *) APWM6__0__INTTYPE)
#endif /* (APWM6__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM6_H */


/* [] END OF FILE */
