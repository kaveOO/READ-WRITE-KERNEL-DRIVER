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
};