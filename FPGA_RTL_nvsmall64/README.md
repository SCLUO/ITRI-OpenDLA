## FPGA\_RTL\_nvsmall64 
----------

Revised and flat RTL design of [NVDLA small version](http://nvdla.org/), which has 64 MAC cores, 128-KB convolution buffer. 

### Modified RTL codes compared to the original NVDLA nv\_small\_64

1. Modified for support uint8 data format :
   +  NV\_NVDLA\_cmac.v
   +  NV\_NVDLA\_CMAC_core.v    
   +  NV\_NVDLA\_CMAC_CORE_mac.v
2. Modified for support FPGA BUS Interface :
   +  NV\_NVDLA\_apb2csb.v
   +  NV\_nvdla\_apb.v





