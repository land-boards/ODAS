/*******************************************************************************
* File Name: APWM11.h  
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

#if !defined(CY_PINS_APWM11_H) /* Pins APWM11_H */
#define CY_PINS_APWM11_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM11_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM11__PORT == 15 && ((APWM11__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM11_Write(uint8 value);
void    APWM11_SetDriveMode(uint8 mode);
uint8   APWM11_ReadDataReg(void);
uint8   APWM11_Read(void);
void    APWM11_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM11_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM11_SetDriveMode() function.
     *  @{
     */
        #define APWM11_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM11_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM11_DM_RES_UP          PIN_DM_RES_UP
        #define APWM11_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM11_DM_OD_LO           PIN_DM_OD_LO
        #define APWM11_DM_OD_HI           PIN_DM_OD_HI
        #define APWM11_DM_STRONG          PIN_DM_STRONG
        #define APWM11_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM11_MASK               APWM11__MASK
#define APWM11_SHIFT              APWM11__SHIFT
#define APWM11_WIDTH              1u

/* Interrupt constants */
#if defined(APWM11__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM11_SetInterruptMode() function.
     *  @{
     */
        #define APWM11_INTR_NONE      (uint16)(0x0000u)
        #define APWM11_INTR_RISING    (uint16)(0x0001u)
        #define APWM11_INTR_FALLING   (uint16)(0x0002u)
        #define APWM11_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM11_INTR_MASK      (0x01u) 
#endif /* (APWM11__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM11_PS                     (* (reg8 *) APWM11__PS)
/* Data Register */
#define APWM11_DR                     (* (reg8 *) APWM11__DR)
/* Port Number */
#define APWM11_PRT_NUM                (* (reg8 *) APWM11__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM11_AG                     (* (reg8 *) APWM11__AG)                       
/* Analog MUX bux enable */
#define APWM11_AMUX                   (* (reg8 *) APWM11__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM11_BIE                    (* (reg8 *) APWM11__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM11_BIT_MASK               (* (reg8 *) APWM11__BIT_MASK)
/* Bypass Enable */
#define APWM11_BYP                    (* (reg8 *) APWM11__BYP)
/* Port wide control signals */                                                   
#define APWM11_CTL                    (* (reg8 *) APWM11__CTL)
/* Drive Modes */
#define APWM11_DM0                    (* (reg8 *) APWM11__DM0) 
#define APWM11_DM1                    (* (reg8 *) APWM11__DM1)
#define APWM11_DM2                    (* (reg8 *) APWM11__DM2) 
/* Input Buffer Disable Override */
#define APWM11_INP_DIS                (* (reg8 *) APWM11__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM11_LCD_COM_SEG            (* (reg8 *) APWM11__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM11_LCD_EN                 (* (reg8 *) APWM11__LCD_EN)
/* Slew Rate Control */
#define APWM11_SLW                    (* (reg8 *) APWM11__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM11_PRTDSI__CAPS_SEL       (* (reg8 *) APWM11__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM11_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM11__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM11_PRTDSI__OE_SEL0        (* (reg8 *) APWM11__PRTDSI__OE_SEL0) 
#define APWM11_PRTDSI__OE_SEL1        (* (reg8 *) APWM11__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM11_PRTDSI__OUT_SEL0       (* (reg8 *) APWM11__PRTDSI__OUT_SEL0) 
#define APWM11_PRTDSI__OUT_SEL1       (* (reg8 *) APWM11__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM11_PRTDSI__SYNC_OUT       (* (reg8 *) APWM11__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM11__SIO_CFG)
    #define APWM11_SIO_HYST_EN        (* (reg8 *) APWM11__SIO_HYST_EN)
    #define APWM11_SIO_REG_HIFREQ     (* (reg8 *) APWM11__SIO_REG_HIFREQ)
    #define APWM11_SIO_CFG            (* (reg8 *) APWM11__SIO_CFG)
    #define APWM11_SIO_DIFF           (* (reg8 *) APWM11__SIO_DIFF)
#endif /* (APWM11__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM11__INTSTAT)
    #define APWM11_INTSTAT            (* (reg8 *) APWM11__INTSTAT)
    #define APWM11_SNAP               (* (reg8 *) APWM11__SNAP)
    
	#define APWM11_0_INTTYPE_REG 		(* (reg8 *) APWM11__0__INTTYPE)
#endif /* (APWM11__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM11_H */


/* [] END OF FILE */
