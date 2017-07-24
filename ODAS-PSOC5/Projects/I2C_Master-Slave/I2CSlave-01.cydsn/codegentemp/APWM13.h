/*******************************************************************************
* File Name: APWM13.h  
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

#if !defined(CY_PINS_APWM13_H) /* Pins APWM13_H */
#define CY_PINS_APWM13_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM13_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM13__PORT == 15 && ((APWM13__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM13_Write(uint8 value);
void    APWM13_SetDriveMode(uint8 mode);
uint8   APWM13_ReadDataReg(void);
uint8   APWM13_Read(void);
void    APWM13_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM13_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM13_SetDriveMode() function.
     *  @{
     */
        #define APWM13_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM13_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM13_DM_RES_UP          PIN_DM_RES_UP
        #define APWM13_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM13_DM_OD_LO           PIN_DM_OD_LO
        #define APWM13_DM_OD_HI           PIN_DM_OD_HI
        #define APWM13_DM_STRONG          PIN_DM_STRONG
        #define APWM13_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM13_MASK               APWM13__MASK
#define APWM13_SHIFT              APWM13__SHIFT
#define APWM13_WIDTH              1u

/* Interrupt constants */
#if defined(APWM13__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM13_SetInterruptMode() function.
     *  @{
     */
        #define APWM13_INTR_NONE      (uint16)(0x0000u)
        #define APWM13_INTR_RISING    (uint16)(0x0001u)
        #define APWM13_INTR_FALLING   (uint16)(0x0002u)
        #define APWM13_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM13_INTR_MASK      (0x01u) 
#endif /* (APWM13__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM13_PS                     (* (reg8 *) APWM13__PS)
/* Data Register */
#define APWM13_DR                     (* (reg8 *) APWM13__DR)
/* Port Number */
#define APWM13_PRT_NUM                (* (reg8 *) APWM13__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM13_AG                     (* (reg8 *) APWM13__AG)                       
/* Analog MUX bux enable */
#define APWM13_AMUX                   (* (reg8 *) APWM13__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM13_BIE                    (* (reg8 *) APWM13__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM13_BIT_MASK               (* (reg8 *) APWM13__BIT_MASK)
/* Bypass Enable */
#define APWM13_BYP                    (* (reg8 *) APWM13__BYP)
/* Port wide control signals */                                                   
#define APWM13_CTL                    (* (reg8 *) APWM13__CTL)
/* Drive Modes */
#define APWM13_DM0                    (* (reg8 *) APWM13__DM0) 
#define APWM13_DM1                    (* (reg8 *) APWM13__DM1)
#define APWM13_DM2                    (* (reg8 *) APWM13__DM2) 
/* Input Buffer Disable Override */
#define APWM13_INP_DIS                (* (reg8 *) APWM13__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM13_LCD_COM_SEG            (* (reg8 *) APWM13__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM13_LCD_EN                 (* (reg8 *) APWM13__LCD_EN)
/* Slew Rate Control */
#define APWM13_SLW                    (* (reg8 *) APWM13__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM13_PRTDSI__CAPS_SEL       (* (reg8 *) APWM13__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM13_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM13__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM13_PRTDSI__OE_SEL0        (* (reg8 *) APWM13__PRTDSI__OE_SEL0) 
#define APWM13_PRTDSI__OE_SEL1        (* (reg8 *) APWM13__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM13_PRTDSI__OUT_SEL0       (* (reg8 *) APWM13__PRTDSI__OUT_SEL0) 
#define APWM13_PRTDSI__OUT_SEL1       (* (reg8 *) APWM13__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM13_PRTDSI__SYNC_OUT       (* (reg8 *) APWM13__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM13__SIO_CFG)
    #define APWM13_SIO_HYST_EN        (* (reg8 *) APWM13__SIO_HYST_EN)
    #define APWM13_SIO_REG_HIFREQ     (* (reg8 *) APWM13__SIO_REG_HIFREQ)
    #define APWM13_SIO_CFG            (* (reg8 *) APWM13__SIO_CFG)
    #define APWM13_SIO_DIFF           (* (reg8 *) APWM13__SIO_DIFF)
#endif /* (APWM13__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM13__INTSTAT)
    #define APWM13_INTSTAT            (* (reg8 *) APWM13__INTSTAT)
    #define APWM13_SNAP               (* (reg8 *) APWM13__SNAP)
    
	#define APWM13_0_INTTYPE_REG 		(* (reg8 *) APWM13__0__INTTYPE)
#endif /* (APWM13__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM13_H */


/* [] END OF FILE */
