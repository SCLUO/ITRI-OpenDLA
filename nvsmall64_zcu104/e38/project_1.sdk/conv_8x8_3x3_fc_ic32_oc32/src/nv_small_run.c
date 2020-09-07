
#include "xparameters.h"
#include "xil_io.h"
#include "xstatus.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "opendla.h"


/************************** Constant Definitions *****************************/
/* The following constant maps to the name of the hardware instances that
 * were created in the Vivado system design. */
#define NVDLA_BASE_ADDRESS             0xA0030000
#define PS_DDR0_BASE_ADDRESS           0x00000000
#define PS_DDR1_BASE_ADDRESS           0x800000000
#define base_addr                      0x40000000


int nv_small_run(void)
{
    unsigned int memory_value;
	    
    /*
    printf("***********************\n");
    printf("Begin NVDLA NV_SMALL Register Setting\n");
    printf("***********************\n");
    */
    //mem_load(base_addr + 0x0, "CONV_SDP_0_input.dat");
    //mem_load(base_addr + 0x40000, "CONV_SDP_0_weight.dat");
    reg_write(NVDLA_CDMA_S_POINTER_0, 0x0);
    reg_write(NVDLA_SDP_S_POINTER_0, 0x0);
    reg_write(NVDLA_CSC_S_POINTER_0, 0x0);
    reg_write(NVDLA_CMAC_B_S_POINTER_0, 0x0);
    reg_write(NVDLA_CACC_S_POINTER_0, 0x0);
    reg_write(NVDLA_CMAC_A_S_POINTER_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LO_SLOPE_SCALE_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LO_SLOPE_SHIFT_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_ACCESS_DATA_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LE_START_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LE_SLOPE_SCALE_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_INFO_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LE_SLOPE_SHIFT_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LO_END_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LO_START_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_ACCESS_CFG_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_CFG_0, 0x0);
    reg_write(NVDLA_SDP_S_LUT_LE_END_0, 0x0);
    reg_write(NVDLA_CDMA_D_RESERVED_X_CFG_0, 0x0);
    reg_write(NVDLA_CDMA_D_BANK_0, 0x70007);
    reg_write(NVDLA_CSC_D_DILATION_EXT_0, 0x0);
    reg_write(NVDLA_CDMA_D_ZERO_PADDING_0, 0x0);
    reg_write(NVDLA_CSC_D_ATOMICS_0, 0x23L);
    reg_write(NVDLA_CSC_D_RELEASE_0, 0x7);
    reg_write(NVDLA_SDP_D_DP_EW_MUL_CVT_TRUNCATE_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_PERF_ENABLE_0, 0x0);
    reg_write(NVDLA_SDP_D_DST_LINE_STRIDE_0, 0x30L);
    reg_write(NVDLA_SDP_D_DP_BS_ALU_CFG_0, 0x0);
    reg_write(NVDLA_CSC_D_DATAIN_SIZE_EXT_0_0, 0x70007L);
    reg_write(NVDLA_CACC_D_DATAOUT_SIZE_1_0, 0x1f);
    reg_write(NVDLA_CDMA_D_RESERVED_Y_CFG_0, 0x0);
    reg_write(NVDLA_CSC_D_CONV_STRIDE_EXT_0, 0x0);
    reg_write(NVDLA_SDP_D_DATA_CUBE_HEIGHT_0, 0x5L);
    reg_write(NVDLA_SDP_D_DST_SURFACE_STRIDE_0, 0x120L);
    reg_write(NVDLA_CDMA_D_DAIN_ADDR_LOW_0_0, base_addr + 0x0);
    reg_write(NVDLA_SDP_D_DP_EW_ALU_SRC_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_BS_ALU_SRC_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_BS_MUL_SRC_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_EW_MUL_CFG_0, 0x2);
    reg_write(NVDLA_CSC_D_DATAOUT_SIZE_0_0, 0x50005L);
    reg_write(NVDLA_CDMA_D_WGS_ADDR_HIGH_0, 0x0);
    reg_write(NVDLA_CACC_D_CYA_0, 0x0);
    reg_write(NVDLA_CDMA_D_BATCH_STRIDE_0, 0x0);
    reg_write(NVDLA_CDMA_D_CVT_SCALE_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_EW_TRUNCATE_VALUE_0, 0x0);
    reg_write(NVDLA_CDMA_D_CONV_STRIDE_0, 0x0);
    reg_write(NVDLA_CDMA_D_DAIN_ADDR_HIGH_0_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_EW_CFG_0, 0x53);
    reg_write(NVDLA_CACC_D_CLIP_CFG_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_BS_CFG_0, 0x73);
    reg_write(NVDLA_CSC_D_WEIGHT_SIZE_EXT_0_0, 0x20002);
    reg_write(NVDLA_CDMA_D_WEIGHT_SIZE_0_0, 0x11fL);
    reg_write(NVDLA_CSC_D_PRA_CFG_0, 0x0);
    reg_write(NVDLA_CDMA_D_WMB_BYTES_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_EW_ALU_CFG_0, 0x2);
    reg_write(NVDLA_CDMA_D_MEAN_GLOBAL_0_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_BN_MUL_SRC_VALUE_0, 0x0);
    reg_write(NVDLA_CACC_D_BATCH_NUMBER_0, 0x0);
    reg_write(NVDLA_CSC_D_BANK_0, 0x70007);
    reg_write(NVDLA_CDMA_D_MEAN_FORMAT_0, 0x0);
    reg_write(NVDLA_CSC_D_ENTRY_PER_SLICE_0, 0x1f);
    reg_write(NVDLA_CSC_D_WMB_BYTES_0, 0x0);
    reg_write(NVDLA_SDP_D_DST_BASE_ADDR_HIGH_0, 0x0);
    reg_write(NVDLA_CACC_D_DATAOUT_MAP_0, 0x10001);
    reg_write(NVDLA_CDMA_D_DAIN_ADDR_LOW_1_0, base_addr + 0x80000000);
    reg_write(NVDLA_CDMA_D_DATAIN_SIZE_0_0, 0x70007L);
    reg_write(NVDLA_SDP_D_CVT_SHIFT_0, 0x0);
    reg_write(NVDLA_CSC_D_CYA_0, 0x0);
    reg_write(NVDLA_CDMA_D_ENTRY_PER_SLICE_0, 0x1f);
    reg_write(NVDLA_CACC_D_DATAOUT_ADDR_0, 0x0);
    reg_write(NVDLA_CACC_D_SURF_STRIDE_0, 0x200L);
    reg_write(NVDLA_SDP_D_DP_BN_CFG_0, 0x53);
    reg_write(NVDLA_SDP_D_DST_BATCH_STRIDE_0, 0x0);
    reg_write(NVDLA_CDMA_D_SURF_STRIDE_0, 0x200L);
    reg_write(NVDLA_SDP_D_DP_EW_MUL_CVT_SCALE_VALUE_0, 0x0);
    reg_write(NVDLA_CSC_D_MISC_CFG_0, 0x0);
    reg_write(NVDLA_CSC_D_DATAOUT_SIZE_1_0, 0x1f);
    reg_write(NVDLA_CDMA_D_LINE_UV_STRIDE_0, 0x0);
    reg_write(NVDLA_CDMA_D_CVT_OFFSET_0, 0x0);
    reg_write(NVDLA_CDMA_D_WMB_ADDR_LOW_0, base_addr + 0x80000000);
    reg_write(NVDLA_CSC_D_WEIGHT_SIZE_EXT_1_0, 0x1f001fL);
    reg_write(NVDLA_CSC_D_BATCH_NUMBER_0, 0x0);
    reg_write(NVDLA_CDMA_D_WEIGHT_ADDR_HIGH_0, 0x0);
    reg_write(NVDLA_CDMA_D_WEIGHT_RAM_TYPE_0, 0x1);
    reg_write(NVDLA_CDMA_D_DAIN_ADDR_HIGH_1_0, 0x0);
    reg_write(NVDLA_CDMA_D_LINE_STRIDE_0, 0x40L);
    reg_write(NVDLA_SDP_D_DST_DMA_CFG_0, 0x1);
    reg_write(NVDLA_CDMA_D_MEAN_GLOBAL_1_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_EW_ALU_CVT_OFFSET_VALUE_0, 0x0);
    reg_write(NVDLA_CDMA_D_WEIGHT_ADDR_LOW_0, base_addr + 0x40000);
    reg_write(NVDLA_SDP_D_DP_EW_ALU_CVT_SCALE_VALUE_0, 0x0);
    reg_write(NVDLA_CDMA_D_DATAIN_FORMAT_0, 0xc00);
    reg_write(NVDLA_CDMA_D_WEIGHT_SIZE_1_0, 0x1f);
    reg_write(NVDLA_CSC_D_WEIGHT_FORMAT_0, 0x0);
    reg_write(NVDLA_CDMA_D_DATAIN_SIZE_1_0, 0x1fL);
    reg_write(NVDLA_CDMA_D_WGS_ADDR_LOW_0, base_addr + 0x80000000);
    reg_write(NVDLA_CDMA_D_DAIN_RAM_TYPE_0, 0x1);
    reg_write(NVDLA_SDP_D_DP_BN_MUL_CFG_0, 0x0);
    reg_write(NVDLA_CDMA_D_CYA_0, 0x0);
    reg_write(NVDLA_CACC_D_MISC_CFG_0, 0x0);
    reg_write(NVDLA_CSC_D_WEIGHT_BYTES_0, 0x2400);
    reg_write(NVDLA_CDMA_D_PERF_ENABLE_0, 0x0);
    reg_write(NVDLA_CDMA_D_NAN_FLUSH_TO_ZERO_0, 0x0);
    reg_write(NVDLA_CDMA_D_DAIN_MAP_0, 0x10001);
    reg_write(NVDLA_CSC_D_DATAIN_SIZE_EXT_1_0, 0x1fL);
    reg_write(NVDLA_SDP_D_DP_BS_MUL_CFG_0, 0x0);
    reg_write(NVDLA_CDMA_D_WMB_ADDR_HIGH_0, 0x0);
    reg_write(NVDLA_CDMA_D_PIXEL_OFFSET_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_EW_MUL_CVT_OFFSET_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_DST_BASE_ADDR_LOW_0, base_addr + 0x80000);
    reg_write(NVDLA_SDP_D_DP_EW_ALU_CVT_TRUNCATE_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_BN_ALU_CFG_0, 0x0);
    reg_write(NVDLA_CDMA_D_FETCH_GRAIN_0, 0x0);
    reg_write(NVDLA_SDP_D_CVT_OFFSET_0, 0x0);
    reg_write(NVDLA_SDP_D_DATA_CUBE_WIDTH_0, 0x5L);
    reg_write(NVDLA_CACC_D_LINE_STRIDE_0, 0x40L);
    reg_write(NVDLA_SDP_D_DP_EW_MUL_SRC_VALUE_0, 0x0);
    reg_write(NVDLA_CDMA_D_WEIGHT_BYTES_0, 0x2400);
    reg_write(NVDLA_CMAC_B_D_MISC_CFG_0, 0x0);
    reg_write(NVDLA_CACC_D_DATAOUT_SIZE_0_0, 0x50005L);
    reg_write(NVDLA_CMAC_A_D_MISC_CFG_0, 0x0);
    reg_write(NVDLA_SDP_D_DATA_CUBE_CHANNEL_0, 0x1f);
    reg_write(NVDLA_SDP_D_DATA_FORMAT_0, 0x0);
    reg_write(NVDLA_CDMA_S_ARBITER_0, 0x3000f);
    reg_write(NVDLA_SDP_D_FEATURE_MODE_CFG_0, 0x1);
    reg_write(NVDLA_CDMA_D_CVT_CFG_0, 0x0);
    reg_write(NVDLA_CDMA_D_WEIGHT_FORMAT_0, 0x0);
    reg_write(NVDLA_CDMA_D_ZERO_PADDING_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_DP_BN_ALU_SRC_VALUE_0, 0x0);
    reg_write(NVDLA_SDP_D_CVT_SCALE_0, 0x1);
    reg_write(NVDLA_CDMA_D_BATCH_NUMBER_0, 0x0);
    reg_write(NVDLA_CDMA_D_MISC_CFG_0, 0x0);
    reg_write(NVDLA_CSC_D_ZERO_PADDING_VALUE_0, 0x0);
    reg_write(NVDLA_CSC_D_DATAIN_FORMAT_0, 0x0);
    reg_write(NVDLA_CDMA_D_DATAIN_SIZE_EXT_0_0, 0x70007L);
    // for test
    //poll_reg_equal(NVDLA_CDMA_D_DATAIN_SIZE_EXT_0_0, 0x70007L);
    //poll_field_not_equal(NVDLA_CDMA_D_DATAIN_SIZE_EXT_0_0, 0x0ffff, 0x70007L);
    //printf("NVDLA_CDMA_D_DATAIN_SIZE_EXT_0_0 (0x%08x@0x%02x):\n", memory_value, NVDLA_BASE_ADDRESS + NVDLA_SDP_RDMA_D_BS_BATCH_STRIDE_0);
    reg_write(NVDLA_CSC_D_ZERO_PADDING_0, 0x0);
    reg_write(NVDLA_CSC_D_POST_Y_EXTENSION_0, 0x0);
    poll_reg_equal(NVDLA_CDMA_S_CBUF_FLUSH_STATUS_0, 0x1);
    reg_write(NVDLA_CDMA_D_OP_ENABLE_0, 0x1);
    reg_write(NVDLA_CACC_D_OP_ENABLE_0, 0x1);
    //sync_notify(NVDLA_CACC, CONV_SDP_0_NVDLA_CACC_D_OP_ENABLE_0);
    //sync_wait(NVDLA_CMAC_A, CONV_SDP_0_NVDLA_CACC_D_OP_ENABLE_0);
    reg_write(NVDLA_CMAC_A_D_OP_ENABLE_0, 0x1);
    //sync_notify(NVDLA_CMAC_A, CONV_SDP_0_NVDLA_CMAC_A_D_OP_ENABLE_0);
    //sync_wait(NVDLA_CMAC_B, CONV_SDP_0_NVDLA_CACC_D_OP_ENABLE_0);
    reg_write(NVDLA_CMAC_B_D_OP_ENABLE_0, 0x1);
    //sync_notify(NVDLA_CMAC_B, CONV_SDP_0_NVDLA_CMAC_B_D_OP_ENABLE_0);
    //sync_wait(NVDLA_CSC, CONV_SDP_0_NVDLA_CMAC_A_D_OP_ENABLE_0);
    //sync_wait(NVDLA_CSC, CONV_SDP_0_NVDLA_CMAC_B_D_OP_ENABLE_0);
    reg_write(NVDLA_CSC_D_OP_ENABLE_0, 0x1);
    reg_write(NVDLA_SDP_D_OP_ENABLE_0, 0x1);
    //intr_notify(SDP_0, 0x1);
    //intr_notify(CACC_0, 0x2);
    //intr_notify(CDMA_DAT_0, 0x3);
    //intr_notify(CDMA_WT_0, 0x4);
    //check_file(0x1, base_addr + 0x80000, 0x480, "CONV_SDP_0_output.dat");
    //check_nothing(0x2);
    //check_nothing(0x4);
    //check_nothing(0x3);








    printf("***********************\n");
    printf("Finish NVDLA NV_SMALL Register Setting\n");
    printf("***********************\n");


/*	    
	    //get value
    	memory_value= memory_get(NVDLA_BASE_ADDRESS, NVDLA_SDP_RDMA_D_BS_BATCH_STRIDE_0);
    	printf("NVDLA_SDP_RDMA_D_BS_BATCH_STRIDE_0 (0x%08x@0x%02x):\n", memory_value, NVDLA_BASE_ADDRESS + NVDLA_SDP_RDMA_D_BS_BATCH_STRIDE_0);
*/




}
