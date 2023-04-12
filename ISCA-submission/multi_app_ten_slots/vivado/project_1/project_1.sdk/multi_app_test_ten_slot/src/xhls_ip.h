// ==============================================================
// File generated by Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC
// Version: 2017.2
// Copyright (C) 1986-2017 Xilinx, Inc. All Rights Reserved.
//
// ==============================================================

#ifndef XHLS_IP_H
#define XHLS_IP_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xhls_ip_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#else
typedef struct {
    u16 DeviceId;
    u32 Axilites_BaseAddress;
} XHls_ip_Config;
#endif

typedef struct {
    u32 Axilites_BaseAddress;
    u32 IsReady;
} XHls_ip;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XHls_ip_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XHls_ip_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XHls_ip_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XHls_ip_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XHls_ip_Initialize(XHls_ip *InstancePtr, u16 DeviceId);
XHls_ip_Config* XHls_ip_LookupConfig(u16 DeviceId);
int XHls_ip_CfgInitialize(XHls_ip *InstancePtr, XHls_ip_Config *ConfigPtr);
#else
int XHls_ip_Initialize(XHls_ip *InstancePtr, const char* InstanceName);
int XHls_ip_Release(XHls_ip *InstancePtr);
#endif

void XHls_ip_Start(XHls_ip *InstancePtr);
u32 XHls_ip_IsDone(XHls_ip *InstancePtr);
u32 XHls_ip_IsIdle(XHls_ip *InstancePtr);
u32 XHls_ip_IsReady(XHls_ip *InstancePtr);
void XHls_ip_EnableAutoRestart(XHls_ip *InstancePtr);
void XHls_ip_DisableAutoRestart(XHls_ip *InstancePtr);
u32 XHls_ip_Get_return(XHls_ip *InstancePtr);

void XHls_ip_Set_input_a(XHls_ip *InstancePtr, u32 Data);
u32 XHls_ip_Get_input_a(XHls_ip *InstancePtr);
void XHls_ip_Set_input_b(XHls_ip *InstancePtr, u32 Data);
u32 XHls_ip_Get_input_b(XHls_ip *InstancePtr);
void XHls_ip_Set_input_c(XHls_ip *InstancePtr, u32 Data);
u32 XHls_ip_Get_input_c(XHls_ip *InstancePtr);
void XHls_ip_Set_input_d(XHls_ip *InstancePtr, u32 Data);
u32 XHls_ip_Get_input_d(XHls_ip *InstancePtr);
void XHls_ip_Set_input_e(XHls_ip *InstancePtr, u32 Data);
u32 XHls_ip_Get_input_e(XHls_ip *InstancePtr);
void XHls_ip_Set_input_f(XHls_ip *InstancePtr, u32 Data);
u32 XHls_ip_Get_input_f(XHls_ip *InstancePtr);

void XHls_ip_InterruptGlobalEnable(XHls_ip *InstancePtr);
void XHls_ip_InterruptGlobalDisable(XHls_ip *InstancePtr);
void XHls_ip_InterruptEnable(XHls_ip *InstancePtr, u32 Mask);
void XHls_ip_InterruptDisable(XHls_ip *InstancePtr, u32 Mask);
void XHls_ip_InterruptClear(XHls_ip *InstancePtr, u32 Mask);
u32 XHls_ip_InterruptGetEnabled(XHls_ip *InstancePtr);
u32 XHls_ip_InterruptGetStatus(XHls_ip *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif