// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.2
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
//
// ==============================================================

// AXILiteS
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read)
//        bit 7  - auto_restart (Read/Write)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0  - Channel 0 (ap_done)
//        bit 1  - Channel 1 (ap_ready)
//        others - reserved
// 0x10 : Data signal of ap_return
//        bit 31~0 - ap_return[31:0] (Read)
// 0x18 : Data signal of input_r
//        bit 31~0 - input_r[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of weights
//        bit 31~0 - weights[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of bias
//        bit 31~0 - bias[31:0] (Read/Write)
// 0x2c : reserved
// 0x30 : Data signal of output_r
//        bit 31~0 - output_r[31:0] (Read/Write)
// 0x34 : reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XHLS_IP_AXILITES_ADDR_AP_CTRL       0x00
#define XHLS_IP_AXILITES_ADDR_GIE           0x04
#define XHLS_IP_AXILITES_ADDR_IER           0x08
#define XHLS_IP_AXILITES_ADDR_ISR           0x0c
#define XHLS_IP_AXILITES_ADDR_AP_RETURN     0x10
#define XHLS_IP_AXILITES_BITS_AP_RETURN     32
#define XHLS_IP_AXILITES_ADDR_INPUT_A_DATA  0x18
#define XHLS_IP_AXILITES_BITS_INPUT_A_DATA  32
#define XHLS_IP_AXILITES_ADDR_INPUT_B_DATA  0x20
#define XHLS_IP_AXILITES_BITS_INPUT_B_DATA  32
#define XHLS_IP_AXILITES_ADDR_INPUT_C_DATA  0x28
#define XHLS_IP_AXILITES_BITS_INPUT_C_DATA  32
#define XHLS_IP_AXILITES_ADDR_INPUT_D_DATA 	0x30
#define XHLS_IP_AXILITES_BITS_INPUT_D_DATA 	32
#define XHLS_IP_AXILITES_ADDR_INPUT_E_DATA 	0x38
#define XHLS_IP_AXILITES_BITS_INPUT_E_DATA 	32
#define XHLS_IP_AXILITES_ADDR_INPUT_F_DATA 	0x40
#define XHLS_IP_AXILITES_BITS_INPUT_F_DATA 	32

