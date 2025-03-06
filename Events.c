#pragma warning (disable : 4047)

#include "Events.h"
#include "Data.h"

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING ImageName, HANDLE PID, PIMAGE_INFO ImageInfo)
{
	//DbgPrintEx(0, 0, "Image loaded -> %ls \n", ImageName->Buffer); // Commented this to avoid having all Images From Kernel System :D
	if (wcsstr(ImageName->Buffer, L"\\AssaultCube 1.3.0.2\\bin_win32\\ogg.dll"))
	{
		DbgPrintEx(0, 0, "Assault Cube ogg.dll found !\n");
		assaultCubeDLLAddress = ImageInfo->ImageBase;
		DbgPrintEx(0, 0, "PID of Assault Cube ogg.dll -> %d\n", PID);
	}
	return (STATUS_SUCCESS);
}
