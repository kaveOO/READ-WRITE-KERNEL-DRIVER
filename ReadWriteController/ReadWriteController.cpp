#include <iostream>
#include "KernelInterface.hpp"
#include "Offsets.hpp"

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\ReadWrite");

	//ULONG Address = Driver.GetClientAddress();
	ULONG ProcessId = Driver.GetProcessId();
	std::cout << "ProcessId right here -> " << ProcessId << std::endl;

	uint64_t clientBaseAddr = 0x7ffd94100000;
	uint64_t fullAddr = clientBaseAddr + Offsets::dwLocalPlayerPawn;

	std::cout << std::hex << fullAddr << std::dec << std::endl;

	while (true)
	{
		//std::cout << std::hex << Offsets::dwLocalPlayerPawn << std::endl;
		//uint64_t localPlayerAddress = Driver.ReadVirtualMemory<uint64_t>(ProcessId, full_address + Offsets::dwLocalPlayerPawn, sizeof(uint32_t));

		//uint64_t playerPos = full_address + Offsets::dwLocalPlayerPawn;

		//std::cout << playerPos << std::endl;
		//std::cout << Offsets::m_flFlashDuration << std::endl;

		//float flash = 0.0f;

		std::cout << fullAddr + 0x140C << std::endl;

		//float flash = Driver.ReadVirtualMemory<float>(ProcessId, fullAddr + 0x140C, sizeof(float));

		//float flash;
		//DWORD Bytes;

		//if (!ReadProcessMemory(hProcess, (LPCVOID)(playerPos + 0x140C), &flash, sizeof(float), 0));
		//{
		//	std::cout << "Error when reading" << std::endl;
		//}

		//std::cout << flash << std::endl;

		//std::cout << playerPos + 0x140C << std::endl;

		//float flash = Driver.ReadVirtualMemory<float>(ProcessId, playerPos + 0x140C, sizeof(float));
		//std::cout << flash << std::endl;

		//if (Driver.WriteVirtualMemory<float>(ProcessId, playerPos + 0x140C, 0.0f, sizeof(0.0f)))
		//{
		//	std::cout << "Successfully changed the flash value !" << std::endl;
		//}
		//else
		//{
		//	std::cout << "Failed to change flash value" << std::endl;
		//}
	}
}