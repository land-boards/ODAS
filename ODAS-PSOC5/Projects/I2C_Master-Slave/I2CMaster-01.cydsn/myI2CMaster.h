#if !defined(MYI2CMASTER_H)
#define MYI2CMASTER_H

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
#include "serialIO.h"

// Set the read/write buffer lengths to be 5 bytes

#define RD_BUFFER_SIZE		(5u)
#define WR_BUFFER_SIZE		(5u)

/* I2C Slave address */
#define I2C_SLAVE_ADDRESS	(0x50)

enum I2C_COMMANDS {
    NULL_CMD,
    SLAVE_LED_OFF,
    SLAVE_LED_ON,
    PWM_CHANNEL_MASK_VALUE,
    ALL_PWM_CHANNELS_LOW,
    ALL_PWM_CHANNELS_HIGH,
    USE_PWM_CHANNELS_MASK,
    ALL_PWM_CHANNELS_ACTIVE,
    RETURN_ERROR_STATUS,
    };

extern uint8 wrBuf[];
extern uint8 rdBuf[];

extern void sendBuffToI2C(uint8);
extern void getBuffFromI2C(uint8);
extern void initI2CMaster(void);

#endif

/* [] END OF FILE */
