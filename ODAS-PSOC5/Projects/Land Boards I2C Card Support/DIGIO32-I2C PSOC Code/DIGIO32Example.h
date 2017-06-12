#if !defined(DIGIO32EXAMPLE_H)
#define DIGIO32EXAMPLE_H
/* ========================================
 *
 * Copyright Land Boards LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include <project.h>
#include "DIGIO32Driver.h"
#include "SerialIO.h"
#include "stringConvs.h"

// Prototypes
void bounceDIGIOLines(void);
void blinkDIGIOLine(uint8);

// Global variables which are defined outside this module
extern uint8 repeatFlag;

#endif

/* [] END OF FILE */
