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

#include "project.h"

#define FREQ        100
#define STARTA      1
#define PWM_WIDTH   1
#define PWM_STEP    4

////////////////////////////////////////////////////////////////
// toggleLED()  Does not work in Rev X1
////////////////////////////////////////////////////////////////

void toggleLED(void)
{
    Control_Reg_1_Write(Control_Reg_1_Read() | 0x02);
    Control_Reg_1_Write(Control_Reg_1_Read() & 0xfd);    
}

uint8 pwmTable[] = {4,8,12,16,20,24,28,32,36,40,44,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,40,36,32,28,24,20,16,12,8,4,0};

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

enum stateVals_t {STARTUP, TXENA, BURSTIP, BURSTDONE, BURSTWAITFORRESET, BURSTGOTRESET} myState;

int main(void)
{
    uint8 lastStatRegValue;
    uint8 currentStatusRegValue;
    uint8 diffBits;
    uint8 burstNumber = 0;
    
	CyGlobalIntEnable; /* Enable global interrupts. */
    
    Control_Reg_1_Write(1);
	Freq_Write(FREQ-1);
	StartPWMA_Write(STARTA);
	EndPWMA_Write(STARTA+1);
	StartPWMB_Write(STARTA+((FREQ)/2));
	EndPWMB_Write(PWM_WIDTH+STARTA+((FREQ)/2));
    lastStatRegValue = Status_Reg_1_Read() & 0x03;
	
    myState = STARTUP;
    
while(1)
	{
        switch (myState)
        {
            case STARTUP:
                toggleLED();
                myState = TXENA;
                burstNumber = 0;
            	EndPWMA_Write(STARTA+pwmTable[0]);
                EndPWMB_Write(pwmTable[0]+STARTA+(FREQ/2));
                Control_Reg_1_Write(0);       // Un-reset
                break;
            case TXENA:
                myState = BURSTIP;
                TxEnaCtlReg_Write(0x00);
                CyDelayUs(2);
                TxEnaCtlReg_Write(0x0f);
                CyDelayUs(2);
                TxEnaCtlReg_Write(0x00);
                break;
            case BURSTIP:
                currentStatusRegValue = Status_Reg_1_Read() & 0x03;
                if (currentStatusRegValue != lastStatRegValue)
                    {
                        diffBits = currentStatusRegValue ^ lastStatRegValue;
                        if (((diffBits & 0x2) == 0x2) && ((currentStatusRegValue & 0x2) == 2))  // PhB
                        {
                           // toggleLED();
            	            EndPWMA_Write(STARTA+pwmTable[burstNumber]-1);
                            burstNumber += 1;
                            if (burstNumber >= 40)
                                myState = BURSTDONE;
                        }
                        if (((diffBits & 0x1) == 0x1) && ((currentStatusRegValue & 0x1) == 1))  // PhA
                        {
                            EndPWMB_Write(pwmTable[burstNumber]+STARTA+(FREQ/2));
                        }
                        lastStatRegValue = currentStatusRegValue;
                    }
                break;
            case BURSTDONE:
                Control_Reg_1_Write(Control_Reg_1_Read() | 0x01);   // Set reset line
                TxEnaCtlReg_Write(0x00);                            // Shut off TxEnables
                myState = BURSTWAITFORRESET;
                Control_Reg_2_Write(1);
                break;
            case BURSTWAITFORRESET:
                if ((Status_Reg_1_Read() & 0x4) == 0x0)
                {
                    burstNumber = 0;
                    Control_Reg_1_Write(Control_Reg_1_Read() | 0x01);   // Set reset line
                    toggleLED();
                    CyDelay(10);
                    myState = BURSTGOTRESET;
                }
                break;
            case BURSTGOTRESET:
                while ((Status_Reg_1_Read() & 0x4) == 0x0);
                myState = STARTUP;
                break;
         }

	}
}

/* [] END OF FILE */
