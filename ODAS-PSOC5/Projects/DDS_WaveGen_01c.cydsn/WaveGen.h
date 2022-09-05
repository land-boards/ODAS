/* ========================================
 *
 
 *
 * ========================================
*/


#include <project.h>
#include <cytypes.h> // uint8
      
    
//#define true  1 // but not True
//#define false 0 // but not False
    
#define BUF_NumSamples   256            // buffer legth
#define BUF_NumRefHigh   128            // first 1/2 buffer length

    
uint8_t VDAC_Buffer[BUF_NumSamples];
uint8 * pBuffer;  // pointer to VDAC_Buffer

/***************************************
*              Registers        
***************************************/    

#define VDAC_Data_PTR    VDAC_1_Data_PTR             
    
    
  



/***************************************
*        Function Prototypes
***************************************/

void  BUF_Start();                 // start
//void  _Stop();                  // stop
//void  _Disable();               // pause
//void  _Enable();                // resume
//void  _Reset();                // reset wave to start

void  BUF_DMAConfig(void);           // 




/* [] END OF FILE */

