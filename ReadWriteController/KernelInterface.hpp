#pragma once

#include "Communication.hpp"

class KernelInterface
{
	public:
		HANDLE hDriver;
	KernelInterface(LPCSTR RegistryPath)
	{
		hDriver = CreateFileA(RegistryPath,
					GENERIC_READ | GENERIC_WRITE,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					0,
					OPEN_EXISTING,
					0,
					0);
	}

	DWORD GetClientAddress()
	{
		if (hDriver == INVALID_HANDLE_VALUE)
		{
			return (0);
		}

		ULONG Address;
		DWORD Bytes;

		if (DeviceIoControl(hDriver, IOCTL_GET_CLIENT_ADDRESS, &Address, sizeof(Address), &Address, sizeof(Address), &Bytes, NULL))
		{
			return (Address);
		}
		return (0);
	}

	DWORD GetProcessId()
	{
		if (hDriver == INVALID_HANDLE_VALUE)
		{
			return (0);
		}

		ULONG ProcessId;
		DWORD Bytes;

		if (DeviceIoControl(hDriver, IOCTL_REQUEST_PROCESSID, &ProcessId, sizeof(ProcessId), &ProcessId, sizeof(ProcessId), &Bytes, NULL))
		{
			return (ProcessId);
		}
		return (0);
	}

	template <typename type>
	type ReadVirtualMemory(ULONG ProcessId, ULONG ReadAddress, SIZE_T Size)
	{
		type Buffer = 0;
		KernelReadRequest ReadRequest;

		ReadRequest.ProcessId = ProcessId;
		ReadRequest.Address = ReadAddress;
		ReadRequest.PBuffer = &Buffer;
		ReadRequest.Size = Size;

		if (DeviceIoControl(hDriver, IOCTL_READ_REQUEST, &ReadRequest, sizeof(ReadRequest), &ReadRequest, sizeof(ReadRequest), 0, 0))
		{
			return Buffer;
		}
		return Buffer;
	}

	template <typename type>
	type WriteVirtualMemory(ULONG ProcessId, ULONG WriteAddress, type WriteValue, SIZE_T Size)
	{
		if (hDriver == INVALID_HANDLE_VALUE) // Returning false right here cause we are Writing so we have no value to retrieve !
		{
			return false;
		}

		DWORD Bytes;
		KernelWriteRequest WriteRequest;

		WriteRequest.ProcessId = ProcessId;
		WriteRequest.Address = WriteAddress;
		WriteRequest.PBuffer = &WriteValue;
		WriteRequest.Size = Size;

		if (DeviceIoControl(hDriver, IOCTL_WRITE_REQUEST, &WriteRequest, sizeof(WriteRequest), 0, 0, &Bytes, NULL))
		{
			return true;
		}
		return false;
	}
};