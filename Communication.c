#include "Communication.h"
#include "Data.h"

NTSTATUS IoControl(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);
	NTSTATUS Status = STATUS_UNSUCCESSFUL;
	ULONG ByteIO = 0;

	PIO_STACK_LOCATION stack = IoGetCurrentIrpStackLocation(Irp);

	ULONG ControlCode = stack->Parameters.DeviceIoControl.IoControlCode;

	if (ControlCode == IOCTL_GET_CLIENT_ADDRESS)
	{
		PULONG Output = (PULONG)Irp->AssociatedIrp.SystemBuffer;
		*Output = assaultCubeDLLAddress;

		DbgPrintEx(0, 0, "Client Address requested !\n");
		Status = STATUS_SUCCESS;
		ByteIO = sizeof(*Output);
	}
	else
	{
		ByteIO = 0;
	}
	Irp->IoStatus.Status = Status;
	Irp->IoStatus.Information = ByteIO;
	IofCompleteRequest(Irp, IO_NO_INCREMENT);

	return (Status);
}

NTSTATUS CreateCall(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);
	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;

	DbgPrintEx(0, 0, "Created Call function has been called !");

	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return (STATUS_SUCCESS);
}

NTSTATUS CloseCall(PDEVICE_OBJECT DeviceObject, PIRP Irp)
{
	UNREFERENCED_PARAMETER(DeviceObject);
	Irp->IoStatus.Status = STATUS_SUCCESS;
	Irp->IoStatus.Information = 0;

	DbgPrintEx(0, 0, "Close Call function has been called !");

	IoCompleteRequest(Irp, IO_NO_INCREMENT);
	return (STATUS_SUCCESS);
}