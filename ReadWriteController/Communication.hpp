#pragma once

#include <Windows.h>

#define IOCTL_GET_CLIENT_ADDRESS	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x666, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define IOCTL_READ_REQUEST			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x667, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
#define IOCTL_WRITE_REQUEST			CTL_CODE(FILE_DEVICE_UNKNOWN, 0x668, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

typedef struct KernelReadRequest
{
	ULONG ProcessId;
	ULONG Address;
	PVOID PBuffer;
	ULONG Size;

} KernelReadRequest, * PKernelReadRequest;

typedef struct KernelWriteRequest
{
	ULONG ProcessId;
	ULONG Address;
	PVOID PBuffer;
	ULONG Size;

} KernelWriteRequest, * PKernelWriteRequest;