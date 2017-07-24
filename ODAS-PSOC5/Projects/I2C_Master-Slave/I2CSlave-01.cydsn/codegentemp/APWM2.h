/*******************************************************************************
* File Name: APWM2.h  
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

#if !defined(CY_PINS_APWM2_H) /* Pins APWM2_H */
#define CY_PINS_APWM2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM2__PORT == 15 && ((APWM2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM2_Write(uint8 value);
void    APWM2_SetDriveMode(uint8 mode);
uint8   APWM2_ReadDataReg(void);
uint8   APWM2_Read(void);
void    APWM2_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM2_SetDriveMode() function.
     *  @{
     */
        #define APWM2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM2_DM_RES_UP          PIN_DM_RES_UP
        #define APWM2_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM2_DM_OD_LO           PIN_DM_OD_LO
        #define APWM2_DM_OD_HI           PIN_DM_OD_HI
        #define APWM2_DM_STRONG          PIN_DM_STRONG
        #define APWM2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM2_MASK               APWM2__MASK
#define APWM2_SHIFT              APWM2__SHIFT
#define APWM2_WIDTH              1u

/* Interrupt constants */
#if defined(APWM2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM2_SetInterruptMode() function.
     *  @{
     */
        #define APWM2_INTR_NONE      (uint16)(0x0000u)
        #define APWM2_INTR_RISING    (uint16)(0x0001u)
        #define APWM2_INTR_FALLING   (uint16)(0x0002u)
        #define APWM2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM2_INTR_MASK      (0x01u) 
#endif /* (APWM2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM2_PS                     (* (reg8 *) APWM2__PS)
/* Data Register */
#define APWM2_DR                     (* (reg8 *) APWM2__DR)
/* Port Number */
#define APWM2_PRT_NUM                (* (reg8 *) APWM2__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM2_AG                     (* (reg8 *) APWM2__AG)                       
/* Analog MUX bux enable */
#define APWM2_AMUX                   (* (reg8 *) APWM2__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM2_BIE                    (* (reg8 *) APWM2__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM2_BIT_MASK               (* (reg8 *) APWM2__BIT_MASK)
/* Bypass Enable */
#define APWM2_BYP                    (* (reg8 *) APWM2__BYP)
/* Port wide control signals */                                                   
#define APWM2_CTL                    (* (reg8 *) APWM2__CTL)
/* Drive Modes */
#define APWM2_DM0                    (* (reg8 *) APWM2__DM0) 
#define APWM2_DM1                    (* (reg8 *) APWM2__DM1)
#define APWM2_DM2                    (* (reg8 *) APWM2__DM2) 
/* Input Buffer Disable Override */
#define APWM2_INP_DIS                (* (reg8 *) APWM2__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM2_LCD_COM_SEG            (* (reg8 *) APWM2__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM2_LCD_EN                 (* (reg8 *) APWM2__LCD_EN)
/* Slew Rate Control */
#define APWM2_SLW                    (* (reg8 *) APWM2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM2_PRTDSI__CAPS_SEL       (* (reg8 *) APWM2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM2_PRTDSI__OE_SEL0        (* (reg8 *) APWM2__PRTDSI__OE_SEL0) 
#define APWM2_PRTDSI__OE_SEL1        (* (reg8 *) APWM2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM2_PRTDSI__OUT_SEL0       (* (reg8 *) APWM2__PRTDSI__OUT_SEL0) 
#define APWM2_PRTDSI__OUT_SEL1       (* (reg8 *) APWM2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM2_PRTDSI__SYNC_OUT       (* (reg8 *) APWM2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM2__SIO_CFG)
    #define APWM2_SIO_HYST_EN        (* (reg8 *) APWM2__SIO_HYST_EN)
    #define APWM2_SIO_REG_HIFREQ     (* (reg8 *) APWM2__SIO_REG_HIFREQ)
    #define APWM2_SIO_CFG            (* (reg8 *) APWM2__SIO_CFG)
    #define APWM2_SIO_DIFF           (* (reg8 *) APWM2__SIO_DIFF)
#endif /* (APWM2__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM2__INTSTAT)
    #define APWM2_INTSTAT            (* (reg8 *) APWM2__INTSTAT)
    #define APWM2_SNAP               (* (reg8 *) APWM2__SNAP)
    
	#define APWM2_0_INTTYPE_REG 		(* (reg8 *) APWM2__0__INTTYPE)
#endif /* (APWM2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM2_H */


/* [] END OF FILE */
