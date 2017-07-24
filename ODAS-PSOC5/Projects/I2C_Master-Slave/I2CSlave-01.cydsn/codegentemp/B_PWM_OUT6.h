/*******************************************************************************
* File Name: B_PWM_OUT6.h  
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

#if !defined(CY_PINS_B_PWM_OUT6_H) /* Pins B_PWM_OUT6_H */
#define CY_PINS_B_PWM_OUT6_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "B_PWM_OUT6_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 B_PWM_OUT6__PORT == 15 && ((B_PWM_OUT6__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    B_PWM_OUT6_Write(uint8 value);
void    B_PWM_OUT6_SetDriveMode(uint8 mode);
uint8   B_PWM_OUT6_ReadDataReg(void);
uint8   B_PWM_OUT6_Read(void);
void    B_PWM_OUT6_SetInterruptMode(uint16 position, uint16 mode);
uint8   B_PWM_OUT6_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the B_PWM_OUT6_SetDriveMode() function.
     *  @{
     */
        #define B_PWM_OUT6_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define B_PWM_OUT6_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define B_PWM_OUT6_DM_RES_UP          PIN_DM_RES_UP
        #define B_PWM_OUT6_DM_RES_DWN         PIN_DM_RES_DWN
        #define B_PWM_OUT6_DM_OD_LO           PIN_DM_OD_LO
        #define B_PWM_OUT6_DM_OD_HI           PIN_DM_OD_HI
        #define B_PWM_OUT6_DM_STRONG          PIN_DM_STRONG
        #define B_PWM_OUT6_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define B_PWM_OUT6_MASK               B_PWM_OUT6__MASK
#define B_PWM_OUT6_SHIFT              B_PWM_OUT6__SHIFT
#define B_PWM_OUT6_WIDTH              1u

/* Interrupt constants */
#if defined(B_PWM_OUT6__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in B_PWM_OUT6_SetInterruptMode() function.
     *  @{
     */
        #define B_PWM_OUT6_INTR_NONE      (uint16)(0x0000u)
        #define B_PWM_OUT6_INTR_RISING    (uint16)(0x0001u)
        #define B_PWM_OUT6_INTR_FALLING   (uint16)(0x0002u)
        #define B_PWM_OUT6_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define B_PWM_OUT6_INTR_MASK      (0x01u) 
#endif /* (B_PWM_OUT6__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define B_PWM_OUT6_PS                     (* (reg8 *) B_PWM_OUT6__PS)
/* Data Register */
#define B_PWM_OUT6_DR                     (* (reg8 *) B_PWM_OUT6__DR)
/* Port Number */
#define B_PWM_OUT6_PRT_NUM                (* (reg8 *) B_PWM_OUT6__PRT) 
/* Connect to Analog Globals */                                                  
#define B_PWM_OUT6_AG                     (* (reg8 *) B_PWM_OUT6__AG)                       
/* Analog MUX bux enable */
#define B_PWM_OUT6_AMUX                   (* (reg8 *) B_PWM_OUT6__AMUX) 
/* Bidirectional Enable */                                                        
#define B_PWM_OUT6_BIE                    (* (reg8 *) B_PWM_OUT6__BIE)
/* Bit-mask for Aliased Register Access */
#define B_PWM_OUT6_BIT_MASK               (* (reg8 *) B_PWM_OUT6__BIT_MASK)
/* Bypass Enable */
#define B_PWM_OUT6_BYP                    (* (reg8 *) B_PWM_OUT6__BYP)
/* Port wide control signals */                                                   
#define B_PWM_OUT6_CTL                    (* (reg8 *) B_PWM_OUT6__CTL)
/* Drive Modes */
#define B_PWM_OUT6_DM0                    (* (reg8 *) B_PWM_OUT6__DM0) 
#define B_PWM_OUT6_DM1                    (* (reg8 *) B_PWM_OUT6__DM1)
#define B_PWM_OUT6_DM2                    (* (reg8 *) B_PWM_OUT6__DM2) 
/* Input Buffer Disable Override */
#define B_PWM_OUT6_INP_DIS                (* (reg8 *) B_PWM_OUT6__INP_DIS)
/* LCD Common or Segment Drive */
#define B_PWM_OUT6_LCD_COM_SEG            (* (reg8 *) B_PWM_OUT6__LCD_COM_SEG)
/* Enable Segment LCD */
#define B_PWM_OUT6_LCD_EN                 (* (reg8 *) B_PWM_OUT6__LCD_EN)
/* Slew Rate Control */
#define B_PWM_OUT6_SLW                    (* (reg8 *) B_PWM_OUT6__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define B_PWM_OUT6_PRTDSI__CAPS_SEL       (* (reg8 *) B_PWM_OUT6__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define B_PWM_OUT6_PRTDSI__DBL_SYNC_IN    (* (reg8 *) B_PWM_OUT6__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define B_PWM_OUT6_PRTDSI__OE_SEL0        (* (reg8 *) B_PWM_OUT6__PRTDSI__OE_SEL0) 
#define B_PWM_OUT6_PRTDSI__OE_SEL1        (* (reg8 *) B_PWM_OUT6__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define B_PWM_OUT6_PRTDSI__OUT_SEL0       (* (reg8 *) B_PWM_OUT6__PRTDSI__OUT_SEL0) 
#define B_PWM_OUT6_PRTDSI__OUT_SEL1       (* (reg8 *) B_PWM_OUT6__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define B_PWM_OUT6_PRTDSI__SYNC_OUT       (* (reg8 *) B_PWM_OUT6__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(B_PWM_OUT6__SIO_CFG)
    #define B_PWM_OUT6_SIO_HYST_EN        (* (reg8 *) B_PWM_OUT6__SIO_HYST_EN)
    #define B_PWM_OUT6_SIO_REG_HIFREQ     (* (reg8 *) B_PWM_OUT6__SIO_REG_HIFREQ)
    #define B_PWM_OUT6_SIO_CFG            (* (reg8 *) B_PWM_OUT6__SIO_CFG)
    #define B_PWM_OUT6_SIO_DIFF           (* (reg8 *) B_PWM_OUT6__SIO_DIFF)
#endif /* (B_PWM_OUT6__SIO_CFG) */

/* Interrupt Registers */
#if defined(B_PWM_OUT6__INTSTAT)
    #define B_PWM_OUT6_INTSTAT            (* (reg8 *) B_PWM_OUT6__INTSTAT)
    #define B_PWM_OUT6_SNAP               (* (reg8 *) B_PWM_OUT6__SNAP)
    
	#define B_PWM_OUT6_0_INTTYPE_REG 		(* (reg8 *) B_PWM_OUT6__0__INTTYPE)
#endif /* (B_PWM_OUT6__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_B_PWM_OUT6_H */


/* [] END OF FILE */
