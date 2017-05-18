# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\DGilliland\Documents\GitHub\ODAS\ODAS-PSOC5\Projects\ODAS-PSOC5-LEDS-01.cydsn\ODAS-PSOC5-LEDS-01.cyprj
# Date: Wed, 17 May 2017 17:58:53 GMT
#set_units -time ns
create_clock -name {CyXTAL} -period 62.5 -waveform {0 31.25} [list [get_pins {ClockBlock/xtal}]]
create_clock -name {CyILO} -period 1000000 -waveform {0 500000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyPLL_OUT} -period 31.25 -waveform {0 15.625} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 31.25 -waveform {0 15.625} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/clk_sync}] -edges {1 8000001 16000001} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_clock -name {CyIMO} -period 333.33333333333331 -waveform {0 166.666666666667} [list [get_pins {ClockBlock/imo}]]


# Component constraints for C:\Users\DGilliland\Documents\GitHub\ODAS\ODAS-PSOC5\Projects\ODAS-PSOC5-LEDS-01.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\DGilliland\Documents\GitHub\ODAS\ODAS-PSOC5\Projects\ODAS-PSOC5-LEDS-01.cydsn\ODAS-PSOC5-LEDS-01.cyprj
# Date: Wed, 17 May 2017 17:58:48 GMT
