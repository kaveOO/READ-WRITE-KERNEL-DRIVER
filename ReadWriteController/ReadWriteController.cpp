#include <iostream>
#include "KernelInterface.hpp"
#include "Offsets.hpp"
#include <tchar.h>
#include <TlHelp32.h>

int main()
{
	KernelInterface Driver = KernelInterface("\\\\.\\ReadWrite");

	//ULONG Address = Driver.GetClientAddress();
	//std::cout << "Client address right here -> " << Address << std::endl; 

	//ULONG ProcessId = Driver.GetProcessId();
	//std::cout << "ProcessId right here -> " << ProcessId << std::endl;

	//while (true)
	//{
	//	uint32_t localPlayerAddress = Driver.ReadVirtualMemory<uint32_t>(ProcessId, Address + Offsets::dwLocalPlayerPawn, sizeof(uint32_t));
	//	Driver.WriteVirtualMemory(ProcessId, localPlayerAddress + Offsets::m_flFlashDuration, 0.f, sizeof(0.f));
	//}

	// READ THIS !
	// Above this I'm using my Driver function to Read/Write memory in the game but of course theses methods are not usables because
	// made to bypass Anti-Cheats because I have to work hard to bypass theses programs and I will never share my work on this !

	// IF YOU HAVE ANY QUESTIONS RELATED TO KERNEL DEVELOPMENT YOU CAN ASK ME 
	// DON'T ASK ME TO BYPASS ANTI-CHEATS 
	


	// FUCK COPY PASTERS
	// FUCK COPY PASTERS
	// FUCK COPY PASTERS

    SetConsoleTitleA("made by kaveO <3");

    ULONG ProcessId = Driver.GetProcessId();
    if (ProcessId == 0)
    {
        std::cerr << "Failed to get process ID !" << std::endl;
    }

    MODULEENTRY32 moduleEntry;
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessId);
    if (snapshot == INVALID_HANDLE_VALUE)
    {
        std::cerr << "Failed to create snapshot for CS2 process !" << std::endl;
        return 1;
    }

    moduleEntry.dwSize = sizeof(MODULEENTRY32);
    uint64_t clientBaseAddr = 0;
    if (Module32First(snapshot, &moduleEntry))
    {
        do
        {
            if (_tcscmp(moduleEntry.szModule, _T("client.dll")) == 0)
            {
                clientBaseAddr = reinterpret_cast<uint64_t>(moduleEntry.modBaseAddr);
                break;
            }
        } while (Module32Next(snapshot, &moduleEntry));
    }
    CloseHandle(snapshot);

    if (clientBaseAddr == 0)
    {
        std::cerr << "Failed to find client.dll base address !" << std::endl;
        return 1;
    }

    HANDLE CS2 = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessId);
    if (CS2 == NULL)
    {
        std::cout << "Failed to open HANDLE on CS2 process !" << std::endl;
        return 1;
    }

    uint64_t localPlayerPtr = 0;
    while (true)
    {
        LPVOID localPlayerAddr = reinterpret_cast<LPVOID>(clientBaseAddr + Offsets::dwLocalPlayerPawn);
        if (!ReadProcessMemory(CS2, localPlayerAddr, &localPlayerPtr, sizeof(localPlayerPtr), nullptr))
        {
            std::cerr << "Failed to find localPlayerPtr with Read !" << std::endl;
            Sleep(100);
            continue;
        }
        if (localPlayerPtr == 0)
        {
            std::cerr << "localPlayerPtr pointer is null !" << std::endl;
            Sleep(100);
            continue;
        }

        LPVOID flashAddr = reinterpret_cast<LPVOID>(localPlayerPtr + Offsets::m_flFlashDuration);
        std::cout << "Attempting to write to flash address -> " << flashAddr << std::endl;

        float flashDuration = 0.0f;
        if (!WriteProcessMemory(CS2, flashAddr, &flashDuration, sizeof(flashDuration), nullptr))
        {
            std::cerr << "WriteProcessMemory failed, error -> " << GetLastError() << std::endl;
        }
        else
        {
            std::cout << "Successfully wrote flash duration as -> " << flashDuration << std::endl;
        }
        Sleep(100);
    }
    CloseHandle(CS2);
    return 0;
}