/* ========================================
 *
 
 *
 * ========================================
*/

#include "WaveGen.h"
#include <project.h>
//#include <stdlib.h>



//uint8 * pBuffer = VDAC_Buffer;  //ok  
uint8 * pBuffer = &(VDAC_Buffer[0]);  //correct  

uint8_t DMA_Chan;
uint8_t DMA_TD[2]; 

// local variables 
//uint16 Num_of_Imp = `$INSTANCE_NAME`_Num_of_Imp; 				// Читаем коэффициент умножения импульсов 
//uint32 counter_overflow = `$INSTANCE_NAME`_counter_overflow;	// время максимальногоожидания прихода сигнала

uint8 aInitialized = 0; // initialized
uint8 aEnabled = 0;     // started (enabled)?


//==============================================================================
// DMA Configuration
//==============================================================================

void BUF_DMAConfig(void)
{
    
    // Variable declarations for DMA2
    //uint8_t DMA_Chan;
    //uint8_t DMA_TD[2];
    
    #define TRANSFER_COUNT1 (BUF_NumRefHigh)
    #define TRANSFER_COUNT2 (BUF_NumSamples - BUF_NumRefHigh)
    
    #define DMA_BYTES_PER_BURST     (1u)
    #define DMA_REQUEST_PER_BURST   (1u)
    //#define DMA_SRC_BASE (&Buffer[0]) - correct 
    //#define DMA_SRC_BASE (&Buffer[200])
    #define DMA_SRC_BASE_ (pBuffer) // todo
    #define DMA_DST_BASE (CYDEV_PERIPH_BASE)
    
    DMA_Chan = DMA2_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, HI16(DMA_SRC_BASE_), HI16(DMA_DST_BASE));
    DMA_TD[0] = CyDmaTdAllocate();
	DMA_TD[1] = CyDmaTdAllocate();
     
    CyDmaTdSetConfiguration(DMA_TD[0], TRANSFER_COUNT1, DMA_TD[1], TD_INC_SRC_ADR | DMA2__TD_TERMOUT_EN);
    CyDmaTdSetConfiguration(DMA_TD[1], TRANSFER_COUNT2, DMA_TD[0], TD_INC_SRC_ADR | DMA2__TD_TERMOUT_EN);
    
    // either ControlReg or VDAC8
    CyDmaTdSetAddress(DMA_TD[0], LO16((uint32)&VDAC_Buffer[0])              , LO16((uint32)VDAC_Data_PTR));
	CyDmaTdSetAddress(DMA_TD[1], LO16((uint32)&VDAC_Buffer[TRANSFER_COUNT1]), LO16((uint32)VDAC_Data_PTR));

    // moved to _Enable()
    //CyDmaChSetInitialTd(DMA_Chan, DMA_TD[0]);
    //CyDmaChEnable(DMA_Chan, 1);    // Enable DMA2 channel 
}    

//==============================================================================
// Initialize component
//==============================================================================

void BUF_Initialize() 
{
    //if (aInitialized) return;
    
    BUF_DMAConfig();
    VDAC_1_Start();        // 
    
    //aInitialized = true;
}

//==============================================================================
// Resume DMA transfer
//==============================================================================

void BUF_Enable() 
{
    //if (!aInitialized) return;
    //if (aEnabled)      return; // comment in SW single shot
    
    CyDmaChSetInitialTd(DMA_Chan, DMA_TD[0]);
        
    CyDmaChEnable(DMA_Chan, 1);// Enable DMA channel

    //aEnabled = true;
}

//==============================================================================
// Initialize and start component
//==============================================================================

void BUF_Start(void) 
{
    BUF_Initialize();
    BUF_Enable();
}

//==============================================================================
// Stop component
// _Start() will begin from 0
//==============================================================================
/*
void BUF_Stop(void) 
{

    if (!aInitialized) return;
    

    aEnabled = false;
    
    // Stop and reset to start position->
    // To clear unwanted transfer requests (DRQ), issue a CPU terminate chain request
    CyDmaChSetRequest(DMA_Chan, CPU_TERM_CHAIN); //CY_DMA_CPU_TERM_CHAIN 
    
    CyDmaClearPendingDrq(DMA_Chan);
    //CyDmaChDisable(DMA_Chan);// Disable DMA channel
    
    //`$INSTANCE_NAME`_ControlReg_Reset_Write(1);
    
    
    // stop DMA where it is
    //CyDmaChDisable(DMA_Chan);// Disable DMA channel
    ///CyDmaChFree(DMA_Chan);
    ///CyDmaClearPendingDrq(DMA_Chan); // enable to start from 0, disable to continue
    
    
    //VDAC only->
    //#if (!WaveGen_1_OUTP_DIGITAL_BUS)
    //   // `$INSTANCE_NAME`_VDAC_Stop();        // Goes into HiZ state
    //                                           // keeps last voltage 
    //#endif
    
    Count7_1_Stop(); // disable counter
    
}
*/

//==============================================================================
// Pause DMA transfer
//==============================================================================
/*
void BUF_Disable() 
{
    if (!aInitialized) return;
    if (!aEnabled)     return;
    
    aEnabled = false;
    
    CyDmaChDisable(DMA_Chan);// Disable DMA channel
    
   // `$INSTANCE_NAME`_ControlReg_Reset_Write(1);
    
    //VDAC only->
    //#if (!WaveGen_1_OUTP_DIGITAL_BUS)
    //   // `$INSTANCE_NAME`_VDAC_Stop();        // Goes into HiZ state 
    //#endif
    
}
*/

//==============================================================================
// reset DMA to start
//==============================================================================
/*
void  BUF_Reset()                
{
            
            //not required->
            // To clear unwanted transfer requests (DRQ), issue a CPU terminate chain request
            //CyDmaChSetRequest(DMA_Chan, CPU_TERM_CHAIN);

            // Enable the DMA channel, This enable kills the spurious DMA transaction if there is one
            // and disables the channel, must re-enable
            //CyDmaChEnable(DMA_Chan, 1);
            
            //CyDmaClearPendingDrq(DMA_Chan);
            
            // re-enable the DMA channel
            //CyDmaChEnable(DMA_Chan, 1);

            //CyDmaChSetInitialTd(DMA_Chan, DMA_TD[0]);           // prior to re-enabling the DMA channel.
            //CyDmaChEnable(DMA_Chan, 1);// Enable DMA channel
            
    
    //CyDmaChDisable(DMA_Chan);// Disable DMA channel
    //CyDmaChFree(DMA_Chan);
    //CyDmaClearPendingDrq(DMA_Chan);

}
*/

//==============================================================================
// Stop component
//==============================================================================
/*
uint8 BUF_GetEnabled() 
{
    return aEnabled;
}
*/    

/* [] END OF FILE */
