#pragma warning (disable : 4100 4047 4024)

#include "ReadWrite.h"
#include "Events.h"
#include "Data.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
	UNREFERENCED_PARAMETER(pRegistryPath);
	pDriverObject->DriverUnload = UnloadDriver;
	DbgPrintEx(0, 0, "Driver Entry -> Hello Kernel World");
	PsSetLoadImageNotifyRoutine(ImageLoadCallback);

	RtlInitUnicodeString(&dev, L"\\device\\ReadWrite");
	RtlInitUnicodeString(&dos, L"\\dosDevices\\ReadWrite");

	IoCreateDevice(pDriverObject, 0, &dev, FILE_DEVICE_UNKNOWN, FILE_DEVICE_SECURE_OPEN, FALSE, &pDeviceObject); // Get more data about this function
	return (STATUS_SUCCESS);
}

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject)
{
	UNREFERENCED_PARAMETER(pDriverObject);
	DbgPrintEx(0, 0, "Driver Unload -> Goodbye Kernel World");
	PsRemoveLoadImageNotifyRoutine(ImageLoadCallback);
	return (STATUS_SUCCESS);
}