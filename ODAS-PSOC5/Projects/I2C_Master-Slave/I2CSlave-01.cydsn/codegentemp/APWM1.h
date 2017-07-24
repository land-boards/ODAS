/*******************************************************************************
* File Name: APWM1.h  
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

#if !defined(CY_PINS_APWM1_H) /* Pins APWM1_H */
#define CY_PINS_APWM1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM1__PORT == 15 && ((APWM1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM1_Write(uint8 value);
void    APWM1_SetDriveMode(uint8 mode);
uint8   APWM1_ReadDataReg(void);
uint8   APWM1_Read(void);
void    APWM1_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM1_SetDriveMode() function.
     *  @{
     */
        #define APWM1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM1_DM_RES_UP          PIN_DM_RES_UP
        #define APWM1_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM1_DM_OD_LO           PIN_DM_OD_LO
        #define APWM1_DM_OD_HI           PIN_DM_OD_HI
        #define APWM1_DM_STRONG          PIN_DM_STRONG
        #define APWM1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM1_MASK               APWM1__MASK
#define APWM1_SHIFT              APWM1__SHIFT
#define APWM1_WIDTH              1u

/* Interrupt constants */
#if defined(APWM1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM1_SetInterruptMode() function.
     *  @{
     */
        #define APWM1_INTR_NONE      (uint16)(0x0000u)
        #define APWM1_INTR_RISING    (uint16)(0x0001u)
        #define APWM1_INTR_FALLING   (uint16)(0x0002u)
        #define APWM1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM1_INTR_MASK      (0x01u) 
#endif /* (APWM1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM1_PS                     (* (reg8 *) APWM1__PS)
/* Data Register */
#define APWM1_DR                     (* (reg8 *) APWM1__DR)
/* Port Number */
#define APWM1_PRT_NUM                (* (reg8 *) APWM1__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM1_AG                     (* (reg8 *) APWM1__AG)                       
/* Analog MUX bux enable */
#define APWM1_AMUX                   (* (reg8 *) APWM1__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM1_BIE                    (* (reg8 *) APWM1__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM1_BIT_MASK               (* (reg8 *) APWM1__BIT_MASK)
/* Bypass Enable */
#define APWM1_BYP                    (* (reg8 *) APWM1__BYP)
/* Port wide control signals */                                                   
#define APWM1_CTL                    (* (reg8 *) APWM1__CTL)
/* Drive Modes */
#define APWM1_DM0                    (* (reg8 *) APWM1__DM0) 
#define APWM1_DM1                    (* (reg8 *) APWM1__DM1)
#define APWM1_DM2                    (* (reg8 *) APWM1__DM2) 
/* Input Buffer Disable Override */
#define APWM1_INP_DIS                (* (reg8 *) APWM1__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM1_LCD_COM_SEG            (* (reg8 *) APWM1__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM1_LCD_EN                 (* (reg8 *) APWM1__LCD_EN)
/* Slew Rate Control */
#define APWM1_SLW                    (* (reg8 *) APWM1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM1_PRTDSI__CAPS_SEL       (* (reg8 *) APWM1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM1_PRTDSI__OE_SEL0        (* (reg8 *) APWM1__PRTDSI__OE_SEL0) 
#define APWM1_PRTDSI__OE_SEL1        (* (reg8 *) APWM1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM1_PRTDSI__OUT_SEL0       (* (reg8 *) APWM1__PRTDSI__OUT_SEL0) 
#define APWM1_PRTDSI__OUT_SEL1       (* (reg8 *) APWM1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM1_PRTDSI__SYNC_OUT       (* (reg8 *) APWM1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM1__SIO_CFG)
    #define APWM1_SIO_HYST_EN        (* (reg8 *) APWM1__SIO_HYST_EN)
    #define APWM1_SIO_REG_HIFREQ     (* (reg8 *) APWM1__SIO_REG_HIFREQ)
    #define APWM1_SIO_CFG            (* (reg8 *) APWM1__SIO_CFG)
    #define APWM1_SIO_DIFF           (* (reg8 *) APWM1__SIO_DIFF)
#endif /* (APWM1__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM1__INTSTAT)
    #define APWM1_INTSTAT            (* (reg8 *) APWM1__INTSTAT)
    #define APWM1_SNAP               (* (reg8 *) APWM1__SNAP)
    
	#define APWM1_0_INTTYPE_REG 		(* (reg8 *) APWM1__0__INTTYPE)
#endif /* (APWM1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM1_H */


/* [] END OF FILE */
