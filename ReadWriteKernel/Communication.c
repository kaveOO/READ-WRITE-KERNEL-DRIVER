#include "Communication.h"
#include "Data.h"
#include "Memory.h"

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
		*Output = Cs2DLLAddress;

		DbgPrintEx(0, 0, "Client Address requested !\n");
		Status = STATUS_SUCCESS;
		ByteIO = sizeof(*Output);
	}
	else if (ControlCode == IOCTL_REQUEST_PROCESSID)
	{
		PULONG Output = (PULONG)Irp->AssociatedIrp.SystemBuffer;
		*Output = ProcessId;

		DbgPrintEx(0, 0, "ProcessId requested !\n");
		Status = STATUS_SUCCESS;
		ByteIO = sizeof(*Output);
	}
	else if (ControlCode == IOCTL_READ_REQUEST)
	{
		PKernelReadRequest ReadInput = (PKernelReadRequest)Irp->AssociatedIrp.SystemBuffer;
		PEPROCESS Process;

		if (NT_SUCCESS(PsLookupProcessByProcessId(ReadInput->ProcessId, &Process)))
		{
			KernelReadVirtualMemory(Process, ReadInput->Address, ReadInput->PBuffer, ReadInput->Size);
			Status = STATUS_SUCCESS;
			ByteIO = sizeof(KernelReadRequest);
		}
	}
	else if (ControlCode == IOCTL_WRITE_REQUEST)
	{
		PKernelWriteRequest WriteInput = (PKernelWriteRequest)Irp->AssociatedIrp.SystemBuffer;
		PEPROCESS Process;

		if (NT_SUCCESS(PsLookupProcessByProcessId(WriteInput->ProcessId, &Process)))
		{
			KernelWriteVirtualMemory(Process, WriteInput->PBuffer, WriteInput->Address, WriteInput->Size);
			Status = STATUS_SUCCESS;
			ByteIO = sizeof(KernelWriteRequest);
		}
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