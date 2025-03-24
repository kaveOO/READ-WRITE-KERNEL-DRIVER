#include <iostream>
#include "KernelInterface.hpp"
#include "Offsets.hpp"

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\ReadWrite");

	ULONG Address = Driver.GetClientAddress();
	ULONG ProcessId = Driver.GetProcessId();
	std::cout << "ProcessId right here -> " << ProcessId << std::endl;

	while (true)
	{
		uint32_t localPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(ProcessId, Address + Offsets::dwLocalPlayerPawn, sizeof(uint32_t));


		Driver.WriteVirtualMemory(ProcessId, localPlayerAddress + Offsets::m_flFlashDuration, 0.0f, sizeof(0.0f));
		//float test = Driver.ReadVirtualMemory<float>(ProcessId, localPlayerAddress + Offsets::m_flFlashDuration, sizeof(test));


	}
}