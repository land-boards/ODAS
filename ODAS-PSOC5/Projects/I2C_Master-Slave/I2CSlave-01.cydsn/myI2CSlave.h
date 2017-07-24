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

/* Set the write buffer length to be 5 bytes */
#define RD_BUFFER_SIZE		(5u)
#define WR_BUFFER_SIZE		(5u)
/* I2C Slave address */
//#define I2C_SLAVE_ADDRESS	(0x50)

enum I2C_COMMANDS {
    NULL_CMD,
    SLAVE_LED_OFF,
    SLAVE_LED_ON,
    PWM_CHANNEL_MASK_VALUE,
    ALL_PWM_CHANNELS_LOW,
    ALL_PWM_CHANNELS_HIGH,
    USE_PWM_CHANNELS_MASK,
    ALL_PWM_CHANNELS_ACTIVE,
    SLAVE_VERBOSE_MODE,
    SLAVE_NON_VERBOSE_MODE,
    RETURN_ERROR_STATUS,
    };

/* Allocate 5 bytes to store data to/from I2C slave */
extern uint8 rdBuf[];
extern uint8 wrBuf[];
extern uint8 verboseFlag;

void initI2CBuffs();
void waitForMasterToWrite();
void waitForMasterToRead();
void fastBlink(void);

/* [] END OF FILE */
