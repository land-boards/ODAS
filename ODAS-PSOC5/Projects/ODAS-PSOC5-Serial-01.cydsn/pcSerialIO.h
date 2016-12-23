/* ========================================
 *
 * Copyright Land Boards, LLC, 2016
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "proEnv.h"
#if !defined(PCSERIALIO_H)
#define PCSERIALIO_H

#include "project.h"

void initSerial(void);
void outSingleChar(char8);
void writeLineNoLF(char *);
void writeLine(char *);
char8 getSingleChar(void);
uint8 readLine(char *);

#endif  /* PCSERIALIO_H */

/* [] END OF FILE */
