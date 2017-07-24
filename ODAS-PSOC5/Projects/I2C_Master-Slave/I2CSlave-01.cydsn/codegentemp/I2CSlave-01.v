// ======================================================================
// I2CSlave-01.v generated from TopDesign.cysch
// 07/03/2017 at 13:37
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 5
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_VOLANS 6
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 7
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 8
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 9
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 10
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_FM0P 4
`define CYDEV_CHIP_FAMILY_FM3 5
`define CYDEV_CHIP_FAMILY_FM4 6
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 7
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 8
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 9
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 10
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 11
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 12
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 14
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 15
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 16
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 17
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 18
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_5B 19
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 20
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 24
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 25
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 19
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// I2C_v3_50(Address_Decode=1, BusSpeed_kHz=400, ClockInputVisibility=false, CtlModeReplacementString=SyncCtl, EnableWakeup=false, ExternalBuffer=false, Externi2cIntrHandler=false, ExternTmoutIntrHandler=false, FF=true, Hex=true, I2C_Mode=1, I2cBusPort=0, Implementation=1, InternalUdbClockToleranceMinus=5, InternalUdbClockTolerancePlus=50, NotSlaveClockMinusTolerance=25, NotSlaveClockPlusTolerance=5, PrescalerEnabled=false, PrescalerPeriod=3, Psoc3ffSelected=false, Psoc5AffSelected=false, Psoc5lpffSelected=true, RemoveI2cff=false, RemoveI2cUdb=true, RemoveIntClock=true, RemoveTimeoutTimer=true, SclTimeoutEnabled=false, SdaTimeoutEnabled=false, Slave_Address=80, SlaveClockMinusTolerance=5, SlaveClockPlusTolerance=50, TimeoutEnabled=false, TimeoutImplementation=0, TimeOutms=25, TimeoutPeriodff=39999, TimeoutPeriodUdb=39999, UDB_MSTR=false, UDB_MULTI_MASTER_SLAVE=false, UDB_SLV=false, UdbInternalClock=false, UdbRequiredClock=6400, UdbSlaveFixedPlacementEnable=false, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=I2C_v3_50, CY_CONST_CONFIG=true, CY_CONTROL_FILE=I2C_Slave_DefaultPlacement.ctl, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=I2C_1, CY_INSTANCE_SHORT_NAME=I2C_1, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=I2C_1, )
module I2C_v3_50_0 (
    sda,
    scl,
    clock,
    reset,
    bclk,
    iclk,
    scl_i,
    sda_i,
    scl_o,
    sda_o,
    itclk);
    inout       sda;
    inout       scl;
    input       clock;
    input       reset;
    output      bclk;
    output      iclk;
    input       scl_i;
    input       sda_i;
    output      scl_o;
    output      sda_o;
    output      itclk;


          wire  sda_x_wire;
          wire  sda_yfb;
          wire  udb_clk;
          wire  Net_975;
          wire  Net_974;
          wire  Net_973;
          wire  bus_clk;
          wire  Net_972;
          wire  Net_968;
          wire  scl_yfb;
          wire  Net_969;
          wire  Net_971;
          wire  Net_970;
          wire  timeout_clk;
          wire  Net_697;
          wire  Net_1045;
          wire [1:0] Net_1109;
          wire [5:0] Net_643;
          wire  scl_x_wire;

	// Vmux_sda_out (cy_virtualmux_v1_0)
	assign sda_x_wire = Net_643[1];


	cy_isr_v1_0
		#(.int_type(2'b00))
		I2C_IRQ
		 (.int_signal(Net_697));


    cy_psoc3_i2c_v1_0 I2C_FF (
        .clock(bus_clk),
        .scl_in(Net_1109[0]),
        .sda_in(Net_1109[1]),
        .scl_out(Net_643[0]),
        .sda_out(Net_643[1]),
        .interrupt(Net_643[2]));
    defparam I2C_FF.use_wakeup = 0;

	// Vmux_interrupt (cy_virtualmux_v1_0)
	assign Net_697 = Net_643[2];

	// Vmux_scl_out (cy_virtualmux_v1_0)
	assign scl_x_wire = Net_643[0];

    OneTerminal OneTerminal_1 (
        .o(Net_969));

    OneTerminal OneTerminal_2 (
        .o(Net_968));

	// Vmux_clock (cy_virtualmux_v1_0)
	assign udb_clk = clock;


	cy_clock_v1_0
		#(.id("c821e721-680c-4376-b857-e4a6ce23cab9/5ece924d-20ba-480e-9102-bc082dcdd926"),
		  .source_clock_id("75C2148C-3656-4d8a-846D-0CAE99AB6FF7"),
		  .divisor(0),
		  .period("0"),
		  .is_direct(1),
		  .is_digital(1))
		BusClock
		 (.clock_out(bus_clk));



    assign bclk = Net_973 | bus_clk;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_973));


    assign iclk = Net_974 | udb_clk;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_974));

	// Vmux_scl_in (cy_virtualmux_v1_0)
	assign Net_1109[0] = scl_yfb;

	// Vmux_sda_in (cy_virtualmux_v1_0)
	assign Net_1109[1] = sda_yfb;

	wire [0:0] tmpOE__Bufoe_scl_net;

	cy_bufoe
		Bufoe_scl
		 (.x(scl_x_wire),
		  .y(scl),
		  .oe(tmpOE__Bufoe_scl_net),
		  .yfb(scl_yfb));

	assign tmpOE__Bufoe_scl_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{Net_969} : {Net_969};

	wire [0:0] tmpOE__Bufoe_sda_net;

	cy_bufoe
		Bufoe_sda
		 (.x(sda_x_wire),
		  .y(sda),
		  .oe(tmpOE__Bufoe_sda_net),
		  .yfb(sda_yfb));

	assign tmpOE__Bufoe_sda_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{Net_968} : {Net_968};

	// Vmux_timeout_clock (cy_virtualmux_v1_0)
	assign timeout_clk = clock;


    assign itclk = Net_975 | timeout_clk;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_975));


    assign scl_o = scl_x_wire;

    assign sda_o = sda_x_wire;


endmodule

// Component: mux_v1_10
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10\mux_v1_10.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\mux_v1_10\mux_v1_10.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// Component: CyControlReg_v1_80
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\CyControlReg_v1_80\CyControlReg_v1_80.v"
`endif

// Component: and_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\and_v1_0\and_v1_0.v"
`endif

// Component: B_UART_v2_50
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_UART_v2_50\B_UART_v2_50.v"
`endif

// UART_v2_50(Address1=0, Address2=0, BaudRate=9600, BreakBitsRX=13, BreakBitsTX=13, BreakDetect=false, CRCoutputsEn=false, Enable_RX=1, Enable_RXIntInterrupt=0, Enable_TX=1, Enable_TXIntInterrupt=0, EnableHWAddress=0, EnIntRXInterrupt=false, EnIntTXInterrupt=false, FlowControl=0, HalfDuplexEn=false, HwTXEnSignal=true, InternalClock=true, InternalClockToleranceMinus=3.93736842105263, InternalClockTolerancePlus=3.93736842105263, InternalClockUsed=1, InterruptOnAddDetect=0, InterruptOnAddressMatch=0, InterruptOnBreak=0, InterruptOnByteRcvd=1, InterruptOnOverrunError=0, InterruptOnParityError=0, InterruptOnStopError=0, InterruptOnTXComplete=false, InterruptOnTXFifoEmpty=false, InterruptOnTXFifoFull=false, InterruptOnTXFifoNotFull=false, IntOnAddressDetect=false, IntOnAddressMatch=false, IntOnBreak=false, IntOnByteRcvd=true, IntOnOverrunError=false, IntOnParityError=false, IntOnStopError=false, NumDataBits=8, NumStopBits=1, OverSamplingRate=8, ParityType=0, ParityTypeSw=false, RequiredClock=76800, RXAddressMode=0, RXBufferSize=4, RxBuffRegSizeReplacementString=uint8, RXEnable=true, TXBitClkGenDP=true, TXBufferSize=4, TxBuffRegSizeReplacementString=uint8, TXEnable=true, Use23Polling=true, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=UART_v2_50, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=UART_1, CY_INSTANCE_SHORT_NAME=UART_1, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=50, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=UART_1, )
module UART_v2_50_1 (
    cts_n,
    tx,
    rts_n,
    tx_en,
    clock,
    reset,
    rx,
    tx_interrupt,
    rx_interrupt,
    tx_data,
    tx_clk,
    rx_data,
    rx_clk);
    input       cts_n;
    output      tx;
    output      rts_n;
    output      tx_en;
    input       clock;
    input       reset;
    input       rx;
    output      tx_interrupt;
    output      rx_interrupt;
    output      tx_data;
    output      tx_clk;
    output      rx_data;
    output      rx_clk;

    parameter Address1 = 0;
    parameter Address2 = 0;
    parameter EnIntRXInterrupt = 0;
    parameter EnIntTXInterrupt = 0;
    parameter FlowControl = 0;
    parameter HalfDuplexEn = 0;
    parameter HwTXEnSignal = 1;
    parameter NumDataBits = 8;
    parameter NumStopBits = 1;
    parameter ParityType = 0;
    parameter RXEnable = 1;
    parameter TXEnable = 1;

          wire  Net_289;
          wire  Net_61;
          wire  Net_9;


	cy_clock_v1_0
		#(.id("b0162966-0060-4af5-82d1-fcb491ad7619/be0a0e37-ad17-42ca-b5a1-1a654d736358"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("13020833333.3333"),
		  .is_direct(0),
		  .is_digital(1))
		IntClock
		 (.clock_out(Net_9));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_61 = Net_9;

    B_UART_v2_50 BUART (
        .cts_n(cts_n),
        .tx(tx),
        .rts_n(rts_n),
        .tx_en(tx_en),
        .clock(Net_61),
        .reset(reset),
        .rx(rx),
        .tx_interrupt(tx_interrupt),
        .rx_interrupt(rx_interrupt),
        .tx_data(tx_data),
        .tx_clk(tx_clk),
        .rx_data(rx_data),
        .rx_clk(rx_clk));
    defparam BUART.Address1 = 0;
    defparam BUART.Address2 = 0;
    defparam BUART.BreakBitsRX = 13;
    defparam BUART.BreakBitsTX = 13;
    defparam BUART.BreakDetect = 0;
    defparam BUART.CRCoutputsEn = 0;
    defparam BUART.FlowControl = 0;
    defparam BUART.HalfDuplexEn = 0;
    defparam BUART.HwTXEnSignal = 1;
    defparam BUART.NumDataBits = 8;
    defparam BUART.NumStopBits = 1;
    defparam BUART.OverSampleCount = 8;
    defparam BUART.ParityType = 0;
    defparam BUART.ParityTypeSw = 0;
    defparam BUART.RXAddressMode = 0;
    defparam BUART.RXEnable = 1;
    defparam BUART.RXStatusIntEnable = 1;
    defparam BUART.TXBitClkGenDP = 1;
    defparam BUART.TXEnable = 1;
    defparam BUART.Use23Polling = 1;



endmodule

// top
module top ;

          wire  Net_588;
          wire  Net_587;
          wire  Net_586;
          wire  Net_585;
          wire  Net_584;
          wire  Net_583;
          wire  Net_582;
          wire  Net_580;
          wire  Net_579;
          wire  Net_578;
          wire  Net_577;
          wire  Net_576;
          wire  Net_470;
          wire  Net_464;
          wire  Net_459;
          wire  Net_453;
          wire  Net_447;
          wire  Net_441;
          wire  Net_433;
          wire  Net_427;
          wire  Net_421;
          wire  Net_416;
          wire  Net_404;
          wire  Net_410;
          wire  Net_378;
          wire  Net_367;
          wire  Net_361;
          wire  Net_355;
          wire  Net_282;
          wire  Net_273;
          wire  Net_264;
          wire  Net_255;
          wire  Net_246;
          wire  Net_237;
          wire  Net_542;
          wire  Net_541;
          wire  Net_540;
          wire  Net_539;
          wire  Net_538;
          wire  Net_537;
          wire  Net_536;
          wire  Net_535;
          wire  Net_534;
          wire  Net_533;
          wire  Net_562;
          wire  Net_561;
          wire  Net_560;
          wire  Net_559;
          wire  Net_558;
          wire  Net_557;
          wire  Net_556;
          wire  Net_555;
          wire  Net_554;
          wire  Net_553;
          wire  Net_552;
          wire  Net_551;
          wire  Net_550;
          wire  Net_549;
          wire  Net_548;
          wire  Net_547;
          wire  Net_546;
          wire  Net_545;
          wire  Net_544;
          wire  Net_543;
          wire  Net_226;
          wire  Net_384;
          wire  Net_373;
          wire  Net_85;
          wire  Net_84;
          wire  Net_83;
          wire  Net_82;
          wire  Net_81;
          wire  Net_80;
          wire  Net_79;
          wire  Net_78;
          wire  Net_77;
          wire  Net_76;
          wire  Net_75;
          wire  Net_581;
          wire  Net_469;
          wire  Net_463;
          wire  Net_467;
          wire  Net_466;
          wire  Net_462;
          wire  Net_461;
          wire  Net_456;
          wire  Net_455;
          wire  Net_450;
          wire  Net_449;
          wire  Net_444;
          wire  Net_443;
          wire  Net_437;
          wire  Net_436;
          wire  Net_440;
          wire  Net_446;
          wire  Net_452;
          wire  Net_458;
          wire  Net_432;
          wire  Net_426;
          wire  Net_420;
          wire  Net_430;
          wire  Net_429;
          wire  Net_424;
          wire  Net_423;
          wire  Net_419;
          wire  Net_418;
          wire  Net_413;
          wire  Net_412;
          wire  Net_407;
          wire  Net_406;
          wire  Net_401;
          wire  Net_400;
          wire  Net_394;
          wire  Net_393;
          wire  Net_397;
          wire  Net_403;
          wire  Net_409;
          wire  Net_415;
          wire  Net_520;
          wire  Net_398;
          wire  Net_383;
          wire  Net_377;
          wire  Net_381;
          wire  Net_380;
          wire  Net_376;
          wire  Net_375;
          wire  Net_370;
          wire  Net_369;
          wire  Net_364;
          wire  Net_363;
          wire  Net_358;
          wire  Net_357;
          wire  Net_351;
          wire  Net_350;
          wire  Net_354;
          wire  Net_360;
          wire  Net_366;
          wire  Net_372;
          wire  Net_345;
          wire  Net_343;
          wire  Net_341;
          wire  Net_276;
          wire [1:0] MUX_CTL;
          wire  Net_275;
          wire  Net_267;
          wire  Net_266;
          wire  Net_258;
          wire  Net_257;
          wire [12:0] MSK;
          wire  Net_249;
          wire  Net_248;
          wire  Net_240;
          wire  Net_239;
          wire  Net_231;
          wire  Net_230;
          wire  Net_97;
          wire  Net_96;
          wire  Net_331;
          wire  Net_333;
          wire  Net_335;
          wire  Net_339;
          wire  Net_340;

	wire [0:0] tmpOE__SDA_1_net;
	wire [0:0] tmpFB_0__SDA_1_net;
	wire [0:0] tmpINTERRUPT_0__SDA_1_net;
	electrical [0:0] tmpSIOVREF__SDA_1_net;

	cy_psoc3_pins_v1_10
		#(.id("5cf35d20-2564-47bb-805b-76a554e7683f"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SDA_1
		 (.oe(tmpOE__SDA_1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SDA_1_net[0:0]}),
		  .io({Net_75}),
		  .siovref(tmpSIOVREF__SDA_1_net),
		  .interrupt({tmpINTERRUPT_0__SDA_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SDA_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__SCL_1_net;
	wire [0:0] tmpFB_0__SCL_1_net;
	wire [0:0] tmpINTERRUPT_0__SCL_1_net;
	electrical [0:0] tmpSIOVREF__SCL_1_net;

	cy_psoc3_pins_v1_10
		#(.id("0ab564fc-04f4-4a20-bfed-0f4d81df314c"),
		  .drive_mode(3'b100),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("B"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		SCL_1
		 (.oe(tmpOE__SCL_1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__SCL_1_net[0:0]}),
		  .io({Net_76}),
		  .siovref(tmpSIOVREF__SCL_1_net),
		  .interrupt({tmpINTERRUPT_0__SCL_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__SCL_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    I2C_v3_50_0 I2C_1 (
        .sda(Net_75),
        .scl(Net_76),
        .clock(1'b0),
        .reset(1'b0),
        .bclk(Net_79),
        .iclk(Net_80),
        .scl_i(1'b0),
        .sda_i(1'b0),
        .scl_o(Net_83),
        .sda_o(Net_84),
        .itclk(Net_85));

	wire [0:0] tmpOE__LED_net;
	wire [0:0] tmpFB_0__LED_net;
	wire [0:0] tmpIO_0__LED_net;
	wire [0:0] tmpINTERRUPT_0__LED_net;
	electrical [0:0] tmpSIOVREF__LED_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		LED
		 (.oe(tmpOE__LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__LED_net[0:0]}),
		  .io({tmpIO_0__LED_net[0:0]}),
		  .siovref(tmpSIOVREF__LED_net),
		  .interrupt({tmpINTERRUPT_0__LED_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- Mux start --
    if (1)
    begin : mux_11
        reg  tmp__mux_11_reg;
        always @(Net_340 or Net_372 or Net_369 or Net_370 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_11_reg = Net_340;
                2'b01 :  tmp__mux_11_reg = Net_372;
                2'b10 :  tmp__mux_11_reg = Net_369;
                2'b11 :  tmp__mux_11_reg = Net_370;
            endcase
        end
        assign Net_373 = tmp__mux_11_reg;
    end
    // -- Mux end --

    // -- Mux start --
    if (1)
    begin : mux_13
        reg  tmp__mux_13_reg;
        always @(Net_340 or Net_383 or Net_380 or Net_381 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_13_reg = Net_340;
                2'b01 :  tmp__mux_13_reg = Net_383;
                2'b10 :  tmp__mux_13_reg = Net_380;
                2'b11 :  tmp__mux_13_reg = Net_381;
            endcase
        end
        assign Net_384 = tmp__mux_13_reg;
    end
    // -- Mux end --

	wire [0:0] tmpOE__APWM1_net;
	wire [0:0] tmpFB_0__APWM1_net;
	wire [0:0] tmpIO_0__APWM1_net;
	wire [0:0] tmpINTERRUPT_0__APWM1_net;
	electrical [0:0] tmpSIOVREF__APWM1_net;

	cy_psoc3_pins_v1_10
		#(.id("6c8e352e-fa34-4ca4-a4ad-e239a6a3542b"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM1
		 (.oe(tmpOE__APWM1_net),
		  .y({Net_226}),
		  .fb({tmpFB_0__APWM1_net[0:0]}),
		  .io({tmpIO_0__APWM1_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM1_net),
		  .interrupt({tmpINTERRUPT_0__APWM1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_96 = 1'h0;

    assign Net_97 = 1'h1;

    CyControlReg_v1_80 PWM_Mask_Upper (
        .control_1(Net_543),
        .control_2(Net_544),
        .control_3(Net_545),
        .control_0(Net_546),
        .control_4(Net_547),
        .control_5(Net_548),
        .control_6(Net_549),
        .control_7(Net_550),
        .clock(1'b0),
        .reset(1'b0),
        .control_bus(MSK[12:8]));
    defparam PWM_Mask_Upper.Bit0Mode = 0;
    defparam PWM_Mask_Upper.Bit1Mode = 0;
    defparam PWM_Mask_Upper.Bit2Mode = 0;
    defparam PWM_Mask_Upper.Bit3Mode = 0;
    defparam PWM_Mask_Upper.Bit4Mode = 0;
    defparam PWM_Mask_Upper.Bit5Mode = 0;
    defparam PWM_Mask_Upper.Bit6Mode = 0;
    defparam PWM_Mask_Upper.Bit7Mode = 0;
    defparam PWM_Mask_Upper.BitValue = 0;
    defparam PWM_Mask_Upper.BusDisplay = 1;
    defparam PWM_Mask_Upper.ExtrReset = 0;
    defparam PWM_Mask_Upper.NumOutputs = 5;

    CyControlReg_v1_80 Mux_Control (
        .control_1(Net_553),
        .control_2(Net_554),
        .control_3(Net_555),
        .control_0(Net_556),
        .control_4(Net_557),
        .control_5(Net_558),
        .control_6(Net_559),
        .control_7(Net_560),
        .clock(1'b0),
        .reset(1'b0),
        .control_bus(MUX_CTL[1:0]));
    defparam Mux_Control.Bit0Mode = 0;
    defparam Mux_Control.Bit1Mode = 0;
    defparam Mux_Control.Bit2Mode = 0;
    defparam Mux_Control.Bit3Mode = 0;
    defparam Mux_Control.Bit4Mode = 0;
    defparam Mux_Control.Bit5Mode = 0;
    defparam Mux_Control.Bit6Mode = 0;
    defparam Mux_Control.Bit7Mode = 0;
    defparam Mux_Control.BitValue = 2;
    defparam Mux_Control.BusDisplay = 1;
    defparam Mux_Control.ExtrReset = 0;
    defparam Mux_Control.NumOutputs = 2;

    CyControlReg_v1_80 PWM_Mask_Lower (
        .control_1(Net_533),
        .control_2(Net_534),
        .control_3(Net_535),
        .control_0(Net_536),
        .control_4(Net_537),
        .control_5(Net_538),
        .control_6(Net_539),
        .control_7(Net_540),
        .clock(1'b0),
        .reset(1'b0),
        .control_bus(MSK[7:0]));
    defparam PWM_Mask_Lower.Bit0Mode = 0;
    defparam PWM_Mask_Lower.Bit1Mode = 0;
    defparam PWM_Mask_Lower.Bit2Mode = 0;
    defparam PWM_Mask_Lower.Bit3Mode = 0;
    defparam PWM_Mask_Lower.Bit4Mode = 0;
    defparam PWM_Mask_Lower.Bit5Mode = 0;
    defparam PWM_Mask_Lower.Bit6Mode = 0;
    defparam PWM_Mask_Lower.Bit7Mode = 0;
    defparam PWM_Mask_Lower.BitValue = 0;
    defparam PWM_Mask_Lower.BusDisplay = 1;
    defparam PWM_Mask_Lower.ExtrReset = 0;
    defparam PWM_Mask_Lower.NumOutputs = 8;

	wire [0:0] tmpOE__B_PWM_IN_net;
	wire [0:0] tmpIO_0__B_PWM_IN_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_IN_net;
	electrical [0:0] tmpSIOVREF__B_PWM_IN_net;

	cy_psoc3_pins_v1_10
		#(.id("5f6ad732-667d-4a7e-aeb3-b73939e8947d"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_IN
		 (.oe(tmpOE__B_PWM_IN_net),
		  .y({1'b0}),
		  .fb({Net_520}),
		  .io({tmpIO_0__B_PWM_IN_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_IN_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_IN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_IN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM2_net;
	wire [0:0] tmpFB_0__APWM2_net;
	wire [0:0] tmpIO_0__APWM2_net;
	wire [0:0] tmpINTERRUPT_0__APWM2_net;
	electrical [0:0] tmpSIOVREF__APWM2_net;

	cy_psoc3_pins_v1_10
		#(.id("d2622dff-7e98-4174-8bdc-0b37eb846e2d"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM2
		 (.oe(tmpOE__APWM2_net),
		  .y({Net_237}),
		  .fb({tmpFB_0__APWM2_net[0:0]}),
		  .io({tmpIO_0__APWM2_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM2_net),
		  .interrupt({tmpINTERRUPT_0__APWM2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM3_net;
	wire [0:0] tmpFB_0__APWM3_net;
	wire [0:0] tmpIO_0__APWM3_net;
	wire [0:0] tmpINTERRUPT_0__APWM3_net;
	electrical [0:0] tmpSIOVREF__APWM3_net;

	cy_psoc3_pins_v1_10
		#(.id("b80f6df3-52a2-4d89-b0de-648c46f8b1a4"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM3
		 (.oe(tmpOE__APWM3_net),
		  .y({Net_246}),
		  .fb({tmpFB_0__APWM3_net[0:0]}),
		  .io({tmpIO_0__APWM3_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM3_net),
		  .interrupt({tmpINTERRUPT_0__APWM3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM4_net;
	wire [0:0] tmpFB_0__APWM4_net;
	wire [0:0] tmpIO_0__APWM4_net;
	wire [0:0] tmpINTERRUPT_0__APWM4_net;
	electrical [0:0] tmpSIOVREF__APWM4_net;

	cy_psoc3_pins_v1_10
		#(.id("ef34932e-0a76-42cf-82c4-1d73f0c5e460"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM4
		 (.oe(tmpOE__APWM4_net),
		  .y({Net_255}),
		  .fb({tmpFB_0__APWM4_net[0:0]}),
		  .io({tmpIO_0__APWM4_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM4_net),
		  .interrupt({tmpINTERRUPT_0__APWM4_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM5_net;
	wire [0:0] tmpFB_0__APWM5_net;
	wire [0:0] tmpIO_0__APWM5_net;
	wire [0:0] tmpINTERRUPT_0__APWM5_net;
	electrical [0:0] tmpSIOVREF__APWM5_net;

	cy_psoc3_pins_v1_10
		#(.id("5e509328-c09c-4577-95b7-512e95a46591"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM5
		 (.oe(tmpOE__APWM5_net),
		  .y({Net_264}),
		  .fb({tmpFB_0__APWM5_net[0:0]}),
		  .io({tmpIO_0__APWM5_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM5_net),
		  .interrupt({tmpINTERRUPT_0__APWM5_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM5_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM6_net;
	wire [0:0] tmpFB_0__APWM6_net;
	wire [0:0] tmpIO_0__APWM6_net;
	wire [0:0] tmpINTERRUPT_0__APWM6_net;
	electrical [0:0] tmpSIOVREF__APWM6_net;

	cy_psoc3_pins_v1_10
		#(.id("d440b47b-32ff-4741-b879-b738b83b7381"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM6
		 (.oe(tmpOE__APWM6_net),
		  .y({Net_273}),
		  .fb({tmpFB_0__APWM6_net[0:0]}),
		  .io({tmpIO_0__APWM6_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM6_net),
		  .interrupt({tmpINTERRUPT_0__APWM6_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM6_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM7_net;
	wire [0:0] tmpFB_0__APWM7_net;
	wire [0:0] tmpIO_0__APWM7_net;
	wire [0:0] tmpINTERRUPT_0__APWM7_net;
	electrical [0:0] tmpSIOVREF__APWM7_net;

	cy_psoc3_pins_v1_10
		#(.id("5f4bb07f-a09f-4e8c-a49a-b741e928f47f"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM7
		 (.oe(tmpOE__APWM7_net),
		  .y({Net_282}),
		  .fb({tmpFB_0__APWM7_net[0:0]}),
		  .io({tmpIO_0__APWM7_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM7_net),
		  .interrupt({tmpINTERRUPT_0__APWM7_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM7_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM8_net;
	wire [0:0] tmpFB_0__APWM8_net;
	wire [0:0] tmpIO_0__APWM8_net;
	wire [0:0] tmpINTERRUPT_0__APWM8_net;
	electrical [0:0] tmpSIOVREF__APWM8_net;

	cy_psoc3_pins_v1_10
		#(.id("c76e5193-c3cb-4c05-a08d-cb43c15cc4ad"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM8
		 (.oe(tmpOE__APWM8_net),
		  .y({Net_355}),
		  .fb({tmpFB_0__APWM8_net[0:0]}),
		  .io({tmpIO_0__APWM8_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM8_net),
		  .interrupt({tmpINTERRUPT_0__APWM8_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM8_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM9_net;
	wire [0:0] tmpFB_0__APWM9_net;
	wire [0:0] tmpIO_0__APWM9_net;
	wire [0:0] tmpINTERRUPT_0__APWM9_net;
	electrical [0:0] tmpSIOVREF__APWM9_net;

	cy_psoc3_pins_v1_10
		#(.id("2196bd5e-69d4-4c12-bc87-5c977c61b7c8"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM9
		 (.oe(tmpOE__APWM9_net),
		  .y({Net_361}),
		  .fb({tmpFB_0__APWM9_net[0:0]}),
		  .io({tmpIO_0__APWM9_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM9_net),
		  .interrupt({tmpINTERRUPT_0__APWM9_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM9_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM10_net;
	wire [0:0] tmpFB_0__APWM10_net;
	wire [0:0] tmpIO_0__APWM10_net;
	wire [0:0] tmpINTERRUPT_0__APWM10_net;
	electrical [0:0] tmpSIOVREF__APWM10_net;

	cy_psoc3_pins_v1_10
		#(.id("ec73eb14-7407-4799-871d-a738a6f4c3f9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM10
		 (.oe(tmpOE__APWM10_net),
		  .y({Net_367}),
		  .fb({tmpFB_0__APWM10_net[0:0]}),
		  .io({tmpIO_0__APWM10_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM10_net),
		  .interrupt({tmpINTERRUPT_0__APWM10_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM10_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM11_net;
	wire [0:0] tmpFB_0__APWM11_net;
	wire [0:0] tmpIO_0__APWM11_net;
	wire [0:0] tmpINTERRUPT_0__APWM11_net;
	electrical [0:0] tmpSIOVREF__APWM11_net;

	cy_psoc3_pins_v1_10
		#(.id("857ef2f8-8350-4cd5-ad7b-5e4bb4c8d5b2"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM11
		 (.oe(tmpOE__APWM11_net),
		  .y({Net_373}),
		  .fb({tmpFB_0__APWM11_net[0:0]}),
		  .io({tmpIO_0__APWM11_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM11_net),
		  .interrupt({tmpINTERRUPT_0__APWM11_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM11_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM12_net;
	wire [0:0] tmpFB_0__APWM12_net;
	wire [0:0] tmpIO_0__APWM12_net;
	wire [0:0] tmpINTERRUPT_0__APWM12_net;
	electrical [0:0] tmpSIOVREF__APWM12_net;

	cy_psoc3_pins_v1_10
		#(.id("0d84ae3d-5c34-4a23-9909-2e1f69448dc0"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM12
		 (.oe(tmpOE__APWM12_net),
		  .y({Net_378}),
		  .fb({tmpFB_0__APWM12_net[0:0]}),
		  .io({tmpIO_0__APWM12_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM12_net),
		  .interrupt({tmpINTERRUPT_0__APWM12_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM12_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__APWM13_net;
	wire [0:0] tmpFB_0__APWM13_net;
	wire [0:0] tmpIO_0__APWM13_net;
	wire [0:0] tmpINTERRUPT_0__APWM13_net;
	electrical [0:0] tmpSIOVREF__APWM13_net;

	cy_psoc3_pins_v1_10
		#(.id("bbfb5831-7c14-4849-9a3b-717715e61578"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		APWM13
		 (.oe(tmpOE__APWM13_net),
		  .y({Net_384}),
		  .fb({tmpFB_0__APWM13_net[0:0]}),
		  .io({tmpIO_0__APWM13_net[0:0]}),
		  .siovref(tmpSIOVREF__APWM13_net),
		  .interrupt({tmpINTERRUPT_0__APWM13_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__APWM13_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT3_net;
	wire [0:0] tmpFB_0__B_PWM_OUT3_net;
	wire [0:0] tmpIO_0__B_PWM_OUT3_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT3_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT3_net;

	cy_psoc3_pins_v1_10
		#(.id("0f3182f0-5761-4adc-90a1-2237f01039a9"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT3
		 (.oe(tmpOE__B_PWM_OUT3_net),
		  .y({Net_410}),
		  .fb({tmpFB_0__B_PWM_OUT3_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT3_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT3_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT2_net;
	wire [0:0] tmpFB_0__B_PWM_OUT2_net;
	wire [0:0] tmpIO_0__B_PWM_OUT2_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT2_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT2_net;

	cy_psoc3_pins_v1_10
		#(.id("3cd1720b-b661-46d2-9faa-4913cc6ebca4"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT2
		 (.oe(tmpOE__B_PWM_OUT2_net),
		  .y({Net_404}),
		  .fb({tmpFB_0__B_PWM_OUT2_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT2_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT2_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT1_net;
	wire [0:0] tmpFB_0__B_PWM_OUT1_net;
	wire [0:0] tmpIO_0__B_PWM_OUT1_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT1_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT1_net;

	cy_psoc3_pins_v1_10
		#(.id("9ce5c6f3-49aa-46af-8be6-d4502d57afef"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT1
		 (.oe(tmpOE__B_PWM_OUT1_net),
		  .y({Net_398}),
		  .fb({tmpFB_0__B_PWM_OUT1_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT1_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT1_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT4_net;
	wire [0:0] tmpFB_0__B_PWM_OUT4_net;
	wire [0:0] tmpIO_0__B_PWM_OUT4_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT4_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT4_net;

	cy_psoc3_pins_v1_10
		#(.id("bf87edc0-ff90-46bf-b62d-28e75551745a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT4
		 (.oe(tmpOE__B_PWM_OUT4_net),
		  .y({Net_416}),
		  .fb({tmpFB_0__B_PWM_OUT4_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT4_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT4_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT4_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT5_net;
	wire [0:0] tmpFB_0__B_PWM_OUT5_net;
	wire [0:0] tmpIO_0__B_PWM_OUT5_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT5_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT5_net;

	cy_psoc3_pins_v1_10
		#(.id("f70a4882-e9cc-4dba-a3b1-b1f03c1c0d60"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT5
		 (.oe(tmpOE__B_PWM_OUT5_net),
		  .y({Net_421}),
		  .fb({tmpFB_0__B_PWM_OUT5_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT5_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT5_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT5_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT5_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT6_net;
	wire [0:0] tmpFB_0__B_PWM_OUT6_net;
	wire [0:0] tmpIO_0__B_PWM_OUT6_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT6_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT6_net;

	cy_psoc3_pins_v1_10
		#(.id("332cb636-6530-412e-a2bc-a66f01d23d17"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT6
		 (.oe(tmpOE__B_PWM_OUT6_net),
		  .y({Net_427}),
		  .fb({tmpFB_0__B_PWM_OUT6_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT6_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT6_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT6_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT6_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT7_net;
	wire [0:0] tmpFB_0__B_PWM_OUT7_net;
	wire [0:0] tmpIO_0__B_PWM_OUT7_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT7_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT7_net;

	cy_psoc3_pins_v1_10
		#(.id("c54ae377-f6cf-4cc9-9bf6-e92ccd2278f2"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT7
		 (.oe(tmpOE__B_PWM_OUT7_net),
		  .y({Net_433}),
		  .fb({tmpFB_0__B_PWM_OUT7_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT7_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT7_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT7_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT7_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT8_net;
	wire [0:0] tmpFB_0__B_PWM_OUT8_net;
	wire [0:0] tmpIO_0__B_PWM_OUT8_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT8_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT8_net;

	cy_psoc3_pins_v1_10
		#(.id("18733a0b-9982-464d-a569-f3f3e58c5496"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT8
		 (.oe(tmpOE__B_PWM_OUT8_net),
		  .y({Net_441}),
		  .fb({tmpFB_0__B_PWM_OUT8_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT8_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT8_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT8_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT8_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT9_net;
	wire [0:0] tmpFB_0__B_PWM_OUT9_net;
	wire [0:0] tmpIO_0__B_PWM_OUT9_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT9_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT9_net;

	cy_psoc3_pins_v1_10
		#(.id("f1ebda9e-62cd-4a93-b0cd-cb590ae0e2da"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT9
		 (.oe(tmpOE__B_PWM_OUT9_net),
		  .y({Net_447}),
		  .fb({tmpFB_0__B_PWM_OUT9_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT9_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT9_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT9_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT9_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT10_net;
	wire [0:0] tmpFB_0__B_PWM_OUT10_net;
	wire [0:0] tmpIO_0__B_PWM_OUT10_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT10_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT10_net;

	cy_psoc3_pins_v1_10
		#(.id("95493592-1ba6-4188-bf4a-d00243315853"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT10
		 (.oe(tmpOE__B_PWM_OUT10_net),
		  .y({Net_453}),
		  .fb({tmpFB_0__B_PWM_OUT10_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT10_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT10_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT10_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT10_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT11_net;
	wire [0:0] tmpFB_0__B_PWM_OUT11_net;
	wire [0:0] tmpIO_0__B_PWM_OUT11_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT11_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT11_net;

	cy_psoc3_pins_v1_10
		#(.id("2a99124f-81fc-49a5-ac33-14c26492f130"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT11
		 (.oe(tmpOE__B_PWM_OUT11_net),
		  .y({Net_459}),
		  .fb({tmpFB_0__B_PWM_OUT11_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT11_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT11_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT11_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT11_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT12_net;
	wire [0:0] tmpFB_0__B_PWM_OUT12_net;
	wire [0:0] tmpIO_0__B_PWM_OUT12_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT12_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT12_net;

	cy_psoc3_pins_v1_10
		#(.id("6602f768-a9e8-4f14-af0f-510c9359b194"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT12
		 (.oe(tmpOE__B_PWM_OUT12_net),
		  .y({Net_464}),
		  .fb({tmpFB_0__B_PWM_OUT12_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT12_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT12_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT12_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT12_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__B_PWM_OUT13_net;
	wire [0:0] tmpFB_0__B_PWM_OUT13_net;
	wire [0:0] tmpIO_0__B_PWM_OUT13_net;
	wire [0:0] tmpINTERRUPT_0__B_PWM_OUT13_net;
	electrical [0:0] tmpSIOVREF__B_PWM_OUT13_net;

	cy_psoc3_pins_v1_10
		#(.id("fe352810-a882-4672-b3ff-512376e10c97"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		B_PWM_OUT13
		 (.oe(tmpOE__B_PWM_OUT13_net),
		  .y({Net_470}),
		  .fb({tmpFB_0__B_PWM_OUT13_net[0:0]}),
		  .io({tmpIO_0__B_PWM_OUT13_net[0:0]}),
		  .siovref(tmpSIOVREF__B_PWM_OUT13_net),
		  .interrupt({tmpINTERRUPT_0__B_PWM_OUT13_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__B_PWM_OUT13_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


    assign Net_339 = Net_340 & MSK[3];

    assign Net_375 = 1'h0;

    assign Net_249 = 1'h1;

    assign Net_248 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_2
        reg  tmp__mux_2_reg;
        always @(Net_340 or Net_335 or Net_239 or Net_240 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_2_reg = Net_340;
                2'b01 :  tmp__mux_2_reg = Net_335;
                2'b10 :  tmp__mux_2_reg = Net_239;
                2'b11 :  tmp__mux_2_reg = Net_240;
            endcase
        end
        assign Net_246 = tmp__mux_2_reg;
    end
    // -- Mux end --

    assign Net_376 = 1'h1;


    assign Net_335 = Net_340 & MSK[2];

    // -- Mux start --
    if (1)
    begin : mux_12
        reg  tmp__mux_12_reg;
        always @(Net_340 or Net_377 or Net_375 or Net_376 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_12_reg = Net_340;
                2'b01 :  tmp__mux_12_reg = Net_377;
                2'b10 :  tmp__mux_12_reg = Net_375;
                2'b11 :  tmp__mux_12_reg = Net_376;
            endcase
        end
        assign Net_378 = tmp__mux_12_reg;
    end
    // -- Mux end --

    assign Net_240 = 1'h1;

    assign Net_239 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_1
        reg  tmp__mux_1_reg;
        always @(Net_340 or Net_333 or Net_230 or Net_231 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_1_reg = Net_340;
                2'b01 :  tmp__mux_1_reg = Net_333;
                2'b10 :  tmp__mux_1_reg = Net_230;
                2'b11 :  tmp__mux_1_reg = Net_231;
            endcase
        end
        assign Net_237 = tmp__mux_1_reg;
    end
    // -- Mux end --

    assign Net_380 = 1'h0;


    assign Net_333 = Net_340 & MSK[1];

    assign Net_381 = 1'h1;

    assign Net_231 = 1'h1;

    assign Net_230 = 1'h0;

	wire [0:0] tmpOE__A_PWM_IN_net;
	wire [0:0] tmpIO_0__A_PWM_IN_net;
	wire [0:0] tmpINTERRUPT_0__A_PWM_IN_net;
	electrical [0:0] tmpSIOVREF__A_PWM_IN_net;

	cy_psoc3_pins_v1_10
		#(.id("9e3c7fd9-21ea-4016-875e-02accf36a611"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		A_PWM_IN
		 (.oe(tmpOE__A_PWM_IN_net),
		  .y({1'b0}),
		  .fb({Net_340}),
		  .io({tmpIO_0__A_PWM_IN_net[0:0]}),
		  .siovref(tmpSIOVREF__A_PWM_IN_net),
		  .interrupt({tmpINTERRUPT_0__A_PWM_IN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__A_PWM_IN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    // -- Mux start --
    if (1)
    begin : mux_10
        reg  tmp__mux_10_reg;
        always @(Net_340 or Net_366 or Net_363 or Net_364 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_10_reg = Net_340;
                2'b01 :  tmp__mux_10_reg = Net_366;
                2'b10 :  tmp__mux_10_reg = Net_363;
                2'b11 :  tmp__mux_10_reg = Net_364;
            endcase
        end
        assign Net_367 = tmp__mux_10_reg;
    end
    // -- Mux end --


    assign Net_343 = Net_340 & MSK[5];

    assign Net_369 = 1'h0;

    assign Net_267 = 1'h1;

    assign Net_266 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_5
        reg  tmp__mux_5_reg;
        always @(Net_340 or Net_341 or Net_257 or Net_258 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_5_reg = Net_340;
                2'b01 :  tmp__mux_5_reg = Net_341;
                2'b10 :  tmp__mux_5_reg = Net_257;
                2'b11 :  tmp__mux_5_reg = Net_258;
            endcase
        end
        assign Net_264 = tmp__mux_5_reg;
    end
    // -- Mux end --

    assign Net_370 = 1'h1;


    assign Net_341 = Net_340 & MSK[4];


    assign Net_372 = Net_340 & MSK[10];

    assign Net_258 = 1'h1;

    assign Net_257 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_4
        reg  tmp__mux_4_reg;
        always @(Net_340 or Net_339 or Net_248 or Net_249 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_4_reg = Net_340;
                2'b01 :  tmp__mux_4_reg = Net_339;
                2'b10 :  tmp__mux_4_reg = Net_248;
                2'b11 :  tmp__mux_4_reg = Net_249;
            endcase
        end
        assign Net_255 = tmp__mux_4_reg;
    end
    // -- Mux end --

    // -- Mux start --
    if (1)
    begin : mux_3
        reg  tmp__mux_3_reg;
        always @(Net_340 or Net_331 or Net_96 or Net_97 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_3_reg = Net_340;
                2'b01 :  tmp__mux_3_reg = Net_331;
                2'b10 :  tmp__mux_3_reg = Net_96;
                2'b11 :  tmp__mux_3_reg = Net_97;
            endcase
        end
        assign Net_226 = tmp__mux_3_reg;
    end
    // -- Mux end --


    assign Net_331 = Net_340 & MSK[0];


    assign Net_383 = Net_340 & MSK[12];

    // -- Mux start --
    if (1)
    begin : mux_6
        reg  tmp__mux_6_reg;
        always @(Net_340 or Net_343 or Net_266 or Net_267 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_6_reg = Net_340;
                2'b01 :  tmp__mux_6_reg = Net_343;
                2'b10 :  tmp__mux_6_reg = Net_266;
                2'b11 :  tmp__mux_6_reg = Net_267;
            endcase
        end
        assign Net_273 = tmp__mux_6_reg;
    end
    // -- Mux end --

    assign Net_275 = 1'h0;

    assign Net_276 = 1'h1;


    assign Net_366 = Net_340 & MSK[9];


    assign Net_345 = Net_340 & MSK[6];

    assign Net_364 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_7
        reg  tmp__mux_7_reg;
        always @(Net_340 or Net_345 or Net_275 or Net_276 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_7_reg = Net_340;
                2'b01 :  tmp__mux_7_reg = Net_345;
                2'b10 :  tmp__mux_7_reg = Net_275;
                2'b11 :  tmp__mux_7_reg = Net_276;
            endcase
        end
        assign Net_282 = tmp__mux_7_reg;
    end
    // -- Mux end --


    assign Net_360 = Net_340 & MSK[8];

    assign Net_358 = 1'h1;

    assign Net_363 = 1'h0;

    assign Net_357 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_9
        reg  tmp__mux_9_reg;
        always @(Net_340 or Net_360 or Net_357 or Net_358 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_9_reg = Net_340;
                2'b01 :  tmp__mux_9_reg = Net_360;
                2'b10 :  tmp__mux_9_reg = Net_357;
                2'b11 :  tmp__mux_9_reg = Net_358;
            endcase
        end
        assign Net_361 = tmp__mux_9_reg;
    end
    // -- Mux end --

    // -- Mux start --
    if (1)
    begin : mux_8
        reg  tmp__mux_8_reg;
        always @(Net_340 or Net_354 or Net_350 or Net_351 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_8_reg = Net_340;
                2'b01 :  tmp__mux_8_reg = Net_354;
                2'b10 :  tmp__mux_8_reg = Net_350;
                2'b11 :  tmp__mux_8_reg = Net_351;
            endcase
        end
        assign Net_355 = tmp__mux_8_reg;
    end
    // -- Mux end --


    assign Net_354 = Net_340 & MSK[7];

    assign Net_351 = 1'h1;

    assign Net_350 = 1'h0;


    assign Net_377 = Net_340 & MSK[11];


    assign Net_463 = Net_520 & MSK[11];


    assign Net_469 = Net_520 & MSK[12];

    assign Net_467 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_15
        reg  tmp__mux_15_reg;
        always @(Net_520 or Net_397 or Net_393 or Net_394 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_15_reg = Net_520;
                2'b01 :  tmp__mux_15_reg = Net_397;
                2'b10 :  tmp__mux_15_reg = Net_393;
                2'b11 :  tmp__mux_15_reg = Net_394;
            endcase
        end
        assign Net_398 = tmp__mux_15_reg;
    end
    // -- Mux end --

    assign Net_466 = 1'h0;

    assign Net_462 = 1'h1;

    assign Net_461 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_16
        reg  tmp__mux_16_reg;
        always @(Net_520 or Net_403 or Net_400 or Net_401 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_16_reg = Net_520;
                2'b01 :  tmp__mux_16_reg = Net_403;
                2'b10 :  tmp__mux_16_reg = Net_400;
                2'b11 :  tmp__mux_16_reg = Net_401;
            endcase
        end
        assign Net_404 = tmp__mux_16_reg;
    end
    // -- Mux end --


    assign Net_458 = Net_520 & MSK[10];

    assign Net_456 = 1'h1;

    assign Net_455 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_17
        reg  tmp__mux_17_reg;
        always @(Net_520 or Net_409 or Net_406 or Net_407 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_17_reg = Net_520;
                2'b01 :  tmp__mux_17_reg = Net_409;
                2'b10 :  tmp__mux_17_reg = Net_406;
                2'b11 :  tmp__mux_17_reg = Net_407;
            endcase
        end
        assign Net_410 = tmp__mux_17_reg;
    end
    // -- Mux end --


    assign Net_452 = Net_520 & MSK[9];

    assign Net_450 = 1'h1;

    assign Net_449 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_18
        reg  tmp__mux_18_reg;
        always @(Net_520 or Net_415 or Net_412 or Net_413 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_18_reg = Net_520;
                2'b01 :  tmp__mux_18_reg = Net_415;
                2'b10 :  tmp__mux_18_reg = Net_412;
                2'b11 :  tmp__mux_18_reg = Net_413;
            endcase
        end
        assign Net_416 = tmp__mux_18_reg;
    end
    // -- Mux end --


    assign Net_446 = Net_520 & MSK[8];

    assign Net_444 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_19
        reg  tmp__mux_19_reg;
        always @(Net_520 or Net_420 or Net_418 or Net_419 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_19_reg = Net_520;
                2'b01 :  tmp__mux_19_reg = Net_420;
                2'b10 :  tmp__mux_19_reg = Net_418;
                2'b11 :  tmp__mux_19_reg = Net_419;
            endcase
        end
        assign Net_421 = tmp__mux_19_reg;
    end
    // -- Mux end --

    assign Net_443 = 1'h0;


    assign Net_440 = Net_520 & MSK[7];

    assign Net_437 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_20
        reg  tmp__mux_20_reg;
        always @(Net_520 or Net_426 or Net_423 or Net_424 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_20_reg = Net_520;
                2'b01 :  tmp__mux_20_reg = Net_426;
                2'b10 :  tmp__mux_20_reg = Net_423;
                2'b11 :  tmp__mux_20_reg = Net_424;
            endcase
        end
        assign Net_427 = tmp__mux_20_reg;
    end
    // -- Mux end --

    assign Net_436 = 1'h0;


    assign Net_420 = Net_520 & MSK[4];


    assign Net_432 = Net_520 & MSK[6];

    // -- Mux start --
    if (1)
    begin : mux_21
        reg  tmp__mux_21_reg;
        always @(Net_520 or Net_432 or Net_429 or Net_430 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_21_reg = Net_520;
                2'b01 :  tmp__mux_21_reg = Net_432;
                2'b10 :  tmp__mux_21_reg = Net_429;
                2'b11 :  tmp__mux_21_reg = Net_430;
            endcase
        end
        assign Net_433 = tmp__mux_21_reg;
    end
    // -- Mux end --

    assign Net_430 = 1'h1;

    assign Net_429 = 1'h0;


    assign Net_426 = Net_520 & MSK[5];

    assign Net_424 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_22
        reg  tmp__mux_22_reg;
        always @(Net_520 or Net_440 or Net_436 or Net_437 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_22_reg = Net_520;
                2'b01 :  tmp__mux_22_reg = Net_440;
                2'b10 :  tmp__mux_22_reg = Net_436;
                2'b11 :  tmp__mux_22_reg = Net_437;
            endcase
        end
        assign Net_441 = tmp__mux_22_reg;
    end
    // -- Mux end --

    assign Net_423 = 1'h0;

    assign Net_419 = 1'h1;

    assign Net_418 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_23
        reg  tmp__mux_23_reg;
        always @(Net_520 or Net_446 or Net_443 or Net_444 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_23_reg = Net_520;
                2'b01 :  tmp__mux_23_reg = Net_446;
                2'b10 :  tmp__mux_23_reg = Net_443;
                2'b11 :  tmp__mux_23_reg = Net_444;
            endcase
        end
        assign Net_447 = tmp__mux_23_reg;
    end
    // -- Mux end --


    assign Net_415 = Net_520 & MSK[3];

    assign Net_413 = 1'h1;

    assign Net_412 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_24
        reg  tmp__mux_24_reg;
        always @(Net_520 or Net_452 or Net_449 or Net_450 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_24_reg = Net_520;
                2'b01 :  tmp__mux_24_reg = Net_452;
                2'b10 :  tmp__mux_24_reg = Net_449;
                2'b11 :  tmp__mux_24_reg = Net_450;
            endcase
        end
        assign Net_453 = tmp__mux_24_reg;
    end
    // -- Mux end --


    assign Net_409 = Net_520 & MSK[2];

    assign Net_407 = 1'h1;

    assign Net_406 = 1'h0;

    // -- Mux start --
    if (1)
    begin : mux_25
        reg  tmp__mux_25_reg;
        always @(Net_520 or Net_458 or Net_455 or Net_456 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_25_reg = Net_520;
                2'b01 :  tmp__mux_25_reg = Net_458;
                2'b10 :  tmp__mux_25_reg = Net_455;
                2'b11 :  tmp__mux_25_reg = Net_456;
            endcase
        end
        assign Net_459 = tmp__mux_25_reg;
    end
    // -- Mux end --


    assign Net_403 = Net_520 & MSK[1];

    assign Net_401 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_26
        reg  tmp__mux_26_reg;
        always @(Net_520 or Net_463 or Net_461 or Net_462 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_26_reg = Net_520;
                2'b01 :  tmp__mux_26_reg = Net_463;
                2'b10 :  tmp__mux_26_reg = Net_461;
                2'b11 :  tmp__mux_26_reg = Net_462;
            endcase
        end
        assign Net_464 = tmp__mux_26_reg;
    end
    // -- Mux end --

    assign Net_400 = 1'h0;


    assign Net_397 = Net_520 & MSK[0];

    assign Net_394 = 1'h1;

    // -- Mux start --
    if (1)
    begin : mux_27
        reg  tmp__mux_27_reg;
        always @(Net_520 or Net_469 or Net_466 or Net_467 or MUX_CTL)
        begin
            case (MUX_CTL[1:0])
                2'b00 :  tmp__mux_27_reg = Net_520;
                2'b01 :  tmp__mux_27_reg = Net_469;
                2'b10 :  tmp__mux_27_reg = Net_466;
                2'b11 :  tmp__mux_27_reg = Net_467;
            endcase
        end
        assign Net_470 = tmp__mux_27_reg;
    end
    // -- Mux end --

    assign Net_393 = 1'h0;

    UART_v2_50_1 UART_1 (
        .cts_n(1'b0),
        .tx(Net_577),
        .rts_n(Net_578),
        .tx_en(Net_579),
        .clock(1'b0),
        .reset(Net_581),
        .rx(Net_582),
        .tx_interrupt(Net_583),
        .rx_interrupt(Net_584),
        .tx_data(Net_585),
        .tx_clk(Net_586),
        .rx_data(Net_587),
        .rx_clk(Net_588));
    defparam UART_1.Address1 = 0;
    defparam UART_1.Address2 = 0;
    defparam UART_1.EnIntRXInterrupt = 0;
    defparam UART_1.EnIntTXInterrupt = 0;
    defparam UART_1.FlowControl = 0;
    defparam UART_1.HalfDuplexEn = 0;
    defparam UART_1.HwTXEnSignal = 1;
    defparam UART_1.NumDataBits = 8;
    defparam UART_1.NumStopBits = 1;
    defparam UART_1.ParityType = 0;
    defparam UART_1.RXEnable = 1;
    defparam UART_1.TXEnable = 1;

	wire [0:0] tmpOE__Rx_1_net;
	wire [0:0] tmpIO_0__Rx_1_net;
	wire [0:0] tmpINTERRUPT_0__Rx_1_net;
	electrical [0:0] tmpSIOVREF__Rx_1_net;

	cy_psoc3_pins_v1_10
		#(.id("1425177d-0d0e-4468-8bcc-e638e5509a9b"),
		  .drive_mode(3'b001),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Rx_1
		 (.oe(tmpOE__Rx_1_net),
		  .y({1'b0}),
		  .fb({Net_582}),
		  .io({tmpIO_0__Rx_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Rx_1_net),
		  .interrupt({tmpINTERRUPT_0__Rx_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Rx_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Tx_1_net;
	wire [0:0] tmpFB_0__Tx_1_net;
	wire [0:0] tmpIO_0__Tx_1_net;
	wire [0:0] tmpINTERRUPT_0__Tx_1_net;
	electrical [0:0] tmpSIOVREF__Tx_1_net;

	cy_psoc3_pins_v1_10
		#(.id("ed092b9b-d398-4703-be89-cebf998501f6"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b1),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Tx_1
		 (.oe(tmpOE__Tx_1_net),
		  .y({Net_577}),
		  .fb({tmpFB_0__Tx_1_net[0:0]}),
		  .io({tmpIO_0__Tx_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Tx_1_net),
		  .interrupt({tmpINTERRUPT_0__Tx_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Tx_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    assign Net_581 = 1'h0;



endmodule

