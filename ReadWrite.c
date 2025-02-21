#pragma warning (disable : 4100)

#include "ReadWrite.h"

NTSTATUS DriverEntry(PDRIVER_OBJECT pDriverObject, PUNICODE_STRING pRegistryPath)
{
	pDriverObject->DriverUnload = UnloadDriver;
	DbgPrintEx(0, 0, "Driver Entry -> Hello Kernel World");
	return (STATUS_SUCCESS);
}

NTSTATUS UnloadDriver(PDRIVER_OBJECT pDriverObject)
{
	DbgPrintEx(0, 0, "Driver Unload -> Goodbye Kernel World");
	return (STATUS_SUCCESS);
}