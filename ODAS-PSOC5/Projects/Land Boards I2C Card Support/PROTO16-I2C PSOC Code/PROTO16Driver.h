#if !defined(PROTO16DRIVER_H)
#define PROTO16DRIVER_H

/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>
#include "MCP23017.h"
#include "i2cAddressMap.h"

#define PROTO16_BITS 16
    
void initPROTO16Card(void); // Initialize the ports

// Arduino-ish functions
void digitalWritePROTO16(uint8, uint8);
uint8 digitalReadPROTO16(uint8);
void pinModePROTO16(uint8 bit, uint8 val);

// Byte control/access functions
void pinModeByBytePROTO16(uint8, uint8);
uint8 readBytePROTO16Card(uint8);
uint8 readOLATBytePROTO16Card(uint8);
uint16 readOLATShortPROTO16Card(void);
void writeBytePROTO16Card(uint8, uint8);
void writeShortPROTO16Card(uint16);

// I2C Low Level Hardware access functions
uint8 readRegisterPROTO16Card(uint8);
void writeRegisterPROTO16Card(uint8, uint8);

#endif
