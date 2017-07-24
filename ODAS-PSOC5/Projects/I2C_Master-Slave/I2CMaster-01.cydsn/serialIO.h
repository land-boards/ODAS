/* ========================================
 *
 * Copyright Land Boards, LLC, 2017
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

enum CHAR_PRESENT {NO_CHAR_PRESENT, CHAR_IS_PRESENT};

void initSerial(void);
void printSingleChar(char8);
void printString(char *);
void printLine(char *);
char8 getSingleChar(void);
uint8 readLine(char *);
enum CHAR_PRESENT checkReceiveChar(void);
void printLong(uint32);
void printBit(uint8_t);

#endif  /* SERIALIO_H */

/* [] END OF FILE */
