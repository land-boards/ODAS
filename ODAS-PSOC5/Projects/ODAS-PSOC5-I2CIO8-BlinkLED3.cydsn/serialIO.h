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

#if !defined(SERIALIO_H)
#define SERIALIO_H

#include "project.h"
    
#define MAXLINELENGTH 80

void initSerial(void);
void outSingleChar(char8);
void writeLineNoLF(char *);
void writeLine(char *);
char8 getSingleChar(void);
uint8 readLine(char *);
uint8 checkReceiveChar(void);

#endif  /* SERIALIO_H */

/* [] END OF FILE */
