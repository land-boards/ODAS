/*******************************************************************************
* File Name: APWM12.h  
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

#if !defined(CY_PINS_APWM12_H) /* Pins APWM12_H */
#define CY_PINS_APWM12_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM12_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM12__PORT == 15 && ((APWM12__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM12_Write(uint8 value);
void    APWM12_SetDriveMode(uint8 mode);
uint8   APWM12_ReadDataReg(void);
uint8   APWM12_Read(void);
void    APWM12_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM12_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM12_SetDriveMode() function.
     *  @{
     */
        #define APWM12_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM12_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM12_DM_RES_UP          PIN_DM_RES_UP
        #define APWM12_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM12_DM_OD_LO           PIN_DM_OD_LO
        #define APWM12_DM_OD_HI           PIN_DM_OD_HI
        #define APWM12_DM_STRONG          PIN_DM_STRONG
        #define APWM12_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM12_MASK               APWM12__MASK
#define APWM12_SHIFT              APWM12__SHIFT
#define APWM12_WIDTH              1u

/* Interrupt constants */
#if defined(APWM12__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM12_SetInterruptMode() function.
     *  @{
     */
        #define APWM12_INTR_NONE      (uint16)(0x0000u)
        #define APWM12_INTR_RISING    (uint16)(0x0001u)
        #define APWM12_INTR_FALLING   (uint16)(0x0002u)
        #define APWM12_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM12_INTR_MASK      (0x01u) 
#endif /* (APWM12__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM12_PS                     (* (reg8 *) APWM12__PS)
/* Data Register */
#define APWM12_DR                     (* (reg8 *) APWM12__DR)
/* Port Number */
#define APWM12_PRT_NUM                (* (reg8 *) APWM12__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM12_AG                     (* (reg8 *) APWM12__AG)                       
/* Analog MUX bux enable */
#define APWM12_AMUX                   (* (reg8 *) APWM12__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM12_BIE                    (* (reg8 *) APWM12__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM12_BIT_MASK               (* (reg8 *) APWM12__BIT_MASK)
/* Bypass Enable */
#define APWM12_BYP                    (* (reg8 *) APWM12__BYP)
/* Port wide control signals */                                                   
#define APWM12_CTL                    (* (reg8 *) APWM12__CTL)
/* Drive Modes */
#define APWM12_DM0                    (* (reg8 *) APWM12__DM0) 
#define APWM12_DM1                    (* (reg8 *) APWM12__DM1)
#define APWM12_DM2                    (* (reg8 *) APWM12__DM2) 
/* Input Buffer Disable Override */
#define APWM12_INP_DIS                (* (reg8 *) APWM12__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM12_LCD_COM_SEG            (* (reg8 *) APWM12__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM12_LCD_EN                 (* (reg8 *) APWM12__LCD_EN)
/* Slew Rate Control */
#define APWM12_SLW                    (* (reg8 *) APWM12__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM12_PRTDSI__CAPS_SEL       (* (reg8 *) APWM12__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM12_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM12__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM12_PRTDSI__OE_SEL0        (* (reg8 *) APWM12__PRTDSI__OE_SEL0) 
#define APWM12_PRTDSI__OE_SEL1        (* (reg8 *) APWM12__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM12_PRTDSI__OUT_SEL0       (* (reg8 *) APWM12__PRTDSI__OUT_SEL0) 
#define APWM12_PRTDSI__OUT_SEL1       (* (reg8 *) APWM12__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM12_PRTDSI__SYNC_OUT       (* (reg8 *) APWM12__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM12__SIO_CFG)
    #define APWM12_SIO_HYST_EN        (* (reg8 *) APWM12__SIO_HYST_EN)
    #define APWM12_SIO_REG_HIFREQ     (* (reg8 *) APWM12__SIO_REG_HIFREQ)
    #define APWM12_SIO_CFG            (* (reg8 *) APWM12__SIO_CFG)
    #define APWM12_SIO_DIFF           (* (reg8 *) APWM12__SIO_DIFF)
#endif /* (APWM12__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM12__INTSTAT)
    #define APWM12_INTSTAT            (* (reg8 *) APWM12__INTSTAT)
    #define APWM12_SNAP               (* (reg8 *) APWM12__SNAP)
    
	#define APWM12_0_INTTYPE_REG 		(* (reg8 *) APWM12__0__INTTYPE)
#endif /* (APWM12__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM12_H */


/* [] END OF FILE */
