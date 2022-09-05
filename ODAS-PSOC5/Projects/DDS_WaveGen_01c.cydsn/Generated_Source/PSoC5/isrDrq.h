/*******************************************************************************
* File Name: isrDrq.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_isrDrq_H)
#define CY_ISR_isrDrq_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void isrDrq_Start(void);
void isrDrq_StartEx(cyisraddress address);
void isrDrq_Stop(void);

CY_ISR_PROTO(isrDrq_Interrupt);

void isrDrq_SetVector(cyisraddress address);
cyisraddress isrDrq_GetVector(void);

void isrDrq_SetPriority(uint8 priority);
uint8 isrDrq_GetPriority(void);

void isrDrq_Enable(void);
uint8 isrDrq_GetState(void);
void isrDrq_Disable(void);

void isrDrq_SetPending(void);
void isrDrq_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the isrDrq ISR. */
#define isrDrq_INTC_VECTOR            ((reg32 *) isrDrq__INTC_VECT)

/* Address of the isrDrq ISR priority. */
#define isrDrq_INTC_PRIOR             ((reg8 *) isrDrq__INTC_PRIOR_REG)

/* Priority of the isrDrq interrupt. */
#define isrDrq_INTC_PRIOR_NUMBER      isrDrq__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable isrDrq interrupt. */
#define isrDrq_INTC_SET_EN            ((reg32 *) isrDrq__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the isrDrq interrupt. */
#define isrDrq_INTC_CLR_EN            ((reg32 *) isrDrq__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the isrDrq interrupt state to pending. */
#define isrDrq_INTC_SET_PD            ((reg32 *) isrDrq__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the isrDrq interrupt. */
#define isrDrq_INTC_CLR_PD            ((reg32 *) isrDrq__INTC_CLR_PD_REG)


#endif /* CY_ISR_isrDrq_H */


/* [] END OF FILE */
