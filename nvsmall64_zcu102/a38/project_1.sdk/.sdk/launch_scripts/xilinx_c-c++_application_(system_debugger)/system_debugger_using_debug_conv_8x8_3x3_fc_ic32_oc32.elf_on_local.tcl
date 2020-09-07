connect -url tcp:127.0.0.1:3121
source F:/Xilinx/SDK/2018.3/scripts/sdk/util/zynqmp_utils.tcl
targets -set -nocase -filter {name =~"APU*" && jtag_cable_name =~ "Digilent JTAG-SMT2NC 210308A1CB53"} -index 1
loadhw -hw E:/a38/project_1.sdk/zcu102_base_trd_wrapper_hw_platform_0/system.hdf -mem-ranges [list {0x80000000 0xbfffffff} {0x400000000 0x5ffffffff} {0x1000000000 0x7fffffffff}]
configparams force-mem-access 1
targets -set -nocase -filter {name =~"*A53*0" && jtag_cable_name =~ "Digilent JTAG-SMT2NC 210308A1CB53"} -index 1
rst -processor
dow E:/a38/project_1.sdk/conv_8x8_3x3_fc_ic32_oc32/Debug/conv_8x8_3x3_fc_ic32_oc32.elf
configparams force-mem-access 0
targets -set -nocase -filter {name =~"*A53*0" && jtag_cable_name =~ "Digilent JTAG-SMT2NC 210308A1CB53"} -index 1
con
