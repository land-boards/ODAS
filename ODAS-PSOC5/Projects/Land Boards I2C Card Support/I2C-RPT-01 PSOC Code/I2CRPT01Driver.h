#if !defined(I2CRPT01DRIVER_H)
#define I2CRPT01DRIVER_H

/* ========================================
 *
 * Copyright Land Boards LLC, 2017
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Land Boards LLC.
 *
 * ========================================
*/

#include <project.h>

#define PCA9544A_ADDRESS 0x70
#define PCA9544A_CTRLREG 0x00

void setI2CChannel(uint8_t);

#endif
