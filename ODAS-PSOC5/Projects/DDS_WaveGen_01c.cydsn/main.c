/* ========================================
 *
 * 
 *
 * ========================================
*/

#include "project.h"
#include <dds.h>
#include <WaveGen.h>

//===========================================
// Global variables
//===========================================

//==============================================================================
// 1/2 Buffer passed, data request issued
//==============================================================================
volatile CYBIT flag_DrqReady = 0; 
CY_ISR(myDrqInt)                
{
    flag_DrqReady = 1;
}

//===========================================
// Function prototypes
//===========================================
//uint8 SetFrequency( double freq );

void Init()
{
    CyGlobalIntEnable;

    BUF_Start();                // initialie DMA and VDAC
    
    DDS_Clock_Freq = 32.0E+3; // set actual DDS sampling clock frequency
    
    DDS_Start();
    DDS_SetFrequency( 500 );   // set output frequency
    
    isrDrq_StartEx(myDrqInt);   // start isrDrq interrupt
}

//===========================================
// main()
//===========================================
int main(void)
{
    
    Init();

    for(;;)
    {
       if (flag_DrqReady)
        {
            flag_DrqReady=0;
            
            //uint16 offset = (Count7_1_ReadCounter() == 0)? 0 : BUF_NumRefHigh;
            //DDS_FillBuffer(offset, BUF_NumRefHigh ); // fill 1/2 buffer (first or second half)   
            
            DDS_FillHalfBuffer();   // fill just completed half-buffer with data
        }
      }
}

/* [] END OF FILE */
