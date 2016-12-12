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

#define FREQ        99
#define STARTA      1
#define PWM_WIDTH   48
#define PWM_STEP    4

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

void loadNewPWM(unsigned char pwmPct)
{
    while ((Status_Reg_1_Read() & 0x1) == 0x1);
    EndPWMA_Write(STARTA+pwmPct-1);
    while ((Status_Reg_1_Read() & 0x2) == 0x0);
    while ((Status_Reg_1_Read() & 0x2) == 0x2);
    EndPWMB_Write(pwmPct+STARTA+(FREQ/2));    
    while ((Status_Reg_1_Read() & 0x1) == 0x0);
}

////////////////////////////////////////////////////////////////
// toggleLED()  Does not work in Rev X1
////////////////////////////////////////////////////////////////

void toggleLED(void)
{
    Control_Reg_1_Write(Control_Reg_1_Read() | 0x02);
    CyDelay(250);
    Control_Reg_1_Write(Control_Reg_1_Read() & 0xfd);    
}

////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////

int main(void)
{
	CyGlobalIntEnable; /* Enable global interrupts. */
    toggleLED();
	Freq_Write(FREQ);
	StartPWMA_Write(STARTA);
	StartPWMB_Write(STARTA+(FREQ/2));
	EndPWMA_Write(STARTA+PWM_WIDTH-1);
	EndPWMB_Write(PWM_WIDTH+STARTA+(FREQ/2));
	
    unsigned char srInit = Status_Reg_1_Read() & 0x4;
	for(;;)
	{
        if ((Status_Reg_1_Read()& 0x4) != srInit)
        {
            toggleLED();
            if ((Status_Reg_1_Read()&4) == 4)
            {
                Control_Reg_1_Write(0);
                //Clock_2_StopBlock();
                srInit = 4;
            }
            else
            {
                Control_Reg_1_Write(1);  
                //Clock_2_Start();
                srInit = 0;
            }
        }
//		unsigned char valPWM;
//        while ((Status_Reg_1_Read() & 0x4) == 0x4);
//        Control_Reg_1_Write(0);
//        while ((Status_Reg_1_Read() & 0x4) == 0x0);
//        Control_Reg_1_Write(1);
//	    Clock_2_Start();
//		for (valPWM = 0; valPWM <= PWM_WIDTH; valPWM+=4)
//		{
//			loadNewPWM(valPWM);
//		}
//        CyDelay(100);
//		Clock_2_StopBlock();
//        CyDelay(100);
	}
}

/* [] END OF FILE */
