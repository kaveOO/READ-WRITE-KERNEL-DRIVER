#pragma warning (disable : 4047 4311)

#include "Events.h"
#include "Data.h"

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING ImageName, HANDLE PID, PIMAGE_INFO ImageInfo)
{
	//DbgPrintEx(0, 0, "Image loaded -> %ls \n", ImageName->Buffer); // Commented this to avoid having all Images From Kernel System :D
	if (wcsstr(ImageName->Buffer, L"\\SteamLibrary\\steamapps\\common\\Counter-Strike Global Offensive\\game\\csgo\\bin\\win64\\client.dll"))
	{
		DbgPrintEx(0, 0, "Cs2DLLAddress found !\n");
		Cs2DLLAddress = ImageInfo->ImageBase;
		ProcessId = (ULONG)PID;
	}
	return (STATUS_SUCCESS);
}
