#pragma warning (disable : 4047)

#include "Events.h"
#include "Data.h"

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING ImageName, HANDLE PID, PIMAGE_INFO ImageInfo)
{
	DbgPrintEx(0, 0, "Image loaded -> %ls \n", ImageName->Buffer);
	if (wcsstr(ImageName->Buffer, L"\\vfcompat.dll"))
	{
		DbgPrintEx(0, 0, "vfcompat.dll found !\n");
		vfcompatDLLAddress = ImageInfo->ImageBase;
		DbgPrintEx(0, 0, "PID of vfcompat -> %d\n", PID);
	}
	return (STATUS_SUCCESS);
}

