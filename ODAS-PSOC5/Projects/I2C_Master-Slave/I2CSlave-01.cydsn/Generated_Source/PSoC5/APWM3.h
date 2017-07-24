/*******************************************************************************
* File Name: APWM3.h  
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

#if !defined(CY_PINS_APWM3_H) /* Pins APWM3_H */
#define CY_PINS_APWM3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "APWM3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 APWM3__PORT == 15 && ((APWM3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    APWM3_Write(uint8 value);
void    APWM3_SetDriveMode(uint8 mode);
uint8   APWM3_ReadDataReg(void);
uint8   APWM3_Read(void);
void    APWM3_SetInterruptMode(uint16 position, uint16 mode);
uint8   APWM3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the APWM3_SetDriveMode() function.
     *  @{
     */
        #define APWM3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define APWM3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define APWM3_DM_RES_UP          PIN_DM_RES_UP
        #define APWM3_DM_RES_DWN         PIN_DM_RES_DWN
        #define APWM3_DM_OD_LO           PIN_DM_OD_LO
        #define APWM3_DM_OD_HI           PIN_DM_OD_HI
        #define APWM3_DM_STRONG          PIN_DM_STRONG
        #define APWM3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define APWM3_MASK               APWM3__MASK
#define APWM3_SHIFT              APWM3__SHIFT
#define APWM3_WIDTH              1u

/* Interrupt constants */
#if defined(APWM3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in APWM3_SetInterruptMode() function.
     *  @{
     */
        #define APWM3_INTR_NONE      (uint16)(0x0000u)
        #define APWM3_INTR_RISING    (uint16)(0x0001u)
        #define APWM3_INTR_FALLING   (uint16)(0x0002u)
        #define APWM3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define APWM3_INTR_MASK      (0x01u) 
#endif /* (APWM3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define APWM3_PS                     (* (reg8 *) APWM3__PS)
/* Data Register */
#define APWM3_DR                     (* (reg8 *) APWM3__DR)
/* Port Number */
#define APWM3_PRT_NUM                (* (reg8 *) APWM3__PRT) 
/* Connect to Analog Globals */                                                  
#define APWM3_AG                     (* (reg8 *) APWM3__AG)                       
/* Analog MUX bux enable */
#define APWM3_AMUX                   (* (reg8 *) APWM3__AMUX) 
/* Bidirectional Enable */                                                        
#define APWM3_BIE                    (* (reg8 *) APWM3__BIE)
/* Bit-mask for Aliased Register Access */
#define APWM3_BIT_MASK               (* (reg8 *) APWM3__BIT_MASK)
/* Bypass Enable */
#define APWM3_BYP                    (* (reg8 *) APWM3__BYP)
/* Port wide control signals */                                                   
#define APWM3_CTL                    (* (reg8 *) APWM3__CTL)
/* Drive Modes */
#define APWM3_DM0                    (* (reg8 *) APWM3__DM0) 
#define APWM3_DM1                    (* (reg8 *) APWM3__DM1)
#define APWM3_DM2                    (* (reg8 *) APWM3__DM2) 
/* Input Buffer Disable Override */
#define APWM3_INP_DIS                (* (reg8 *) APWM3__INP_DIS)
/* LCD Common or Segment Drive */
#define APWM3_LCD_COM_SEG            (* (reg8 *) APWM3__LCD_COM_SEG)
/* Enable Segment LCD */
#define APWM3_LCD_EN                 (* (reg8 *) APWM3__LCD_EN)
/* Slew Rate Control */
#define APWM3_SLW                    (* (reg8 *) APWM3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define APWM3_PRTDSI__CAPS_SEL       (* (reg8 *) APWM3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define APWM3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) APWM3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define APWM3_PRTDSI__OE_SEL0        (* (reg8 *) APWM3__PRTDSI__OE_SEL0) 
#define APWM3_PRTDSI__OE_SEL1        (* (reg8 *) APWM3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define APWM3_PRTDSI__OUT_SEL0       (* (reg8 *) APWM3__PRTDSI__OUT_SEL0) 
#define APWM3_PRTDSI__OUT_SEL1       (* (reg8 *) APWM3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define APWM3_PRTDSI__SYNC_OUT       (* (reg8 *) APWM3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(APWM3__SIO_CFG)
    #define APWM3_SIO_HYST_EN        (* (reg8 *) APWM3__SIO_HYST_EN)
    #define APWM3_SIO_REG_HIFREQ     (* (reg8 *) APWM3__SIO_REG_HIFREQ)
    #define APWM3_SIO_CFG            (* (reg8 *) APWM3__SIO_CFG)
    #define APWM3_SIO_DIFF           (* (reg8 *) APWM3__SIO_DIFF)
#endif /* (APWM3__SIO_CFG) */

/* Interrupt Registers */
#if defined(APWM3__INTSTAT)
    #define APWM3_INTSTAT            (* (reg8 *) APWM3__INTSTAT)
    #define APWM3_SNAP               (* (reg8 *) APWM3__SNAP)
    
	#define APWM3_0_INTTYPE_REG 		(* (reg8 *) APWM3__0__INTTYPE)
#endif /* (APWM3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_APWM3_H */


/* [] END OF FILE */
