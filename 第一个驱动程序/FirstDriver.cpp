#include <ntddk.h>
#include <wdm.h>

void SampleUnload(_In_ PDRIVER_OBJECT DriverObject)
{
	UNREFERENCED_PARAMETER(DriverObject);
	KdPrint(("Sample driver Unload called\n"));
}

extern "C"
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject, _In_ PUNICODE_STRING RegistryPath)
{
	UNREFERENCED_PARAMETER(RegistryPath);
	DriverObject->DriverUnload = SampleUnload;
	KdPrint(("Sample driver initialized successfully\n"));
	OSVERSIONINFOW VersionInfo;
	VersionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOW);
	RtlGetVersion(&VersionInfo);
	KdPrint(("Major Version: %d\n", VersionInfo.dwMajorVersion));
	KdPrint(("Minor Version: %d\n", VersionInfo.dwMinorVersion));
	KdPrint(("Build Number: %d\n", VersionInfo.dwBuildNumber));;
	KdPrint(("Platform ID: %d\n", VersionInfo.dwPlatformId));
	return STATUS_SUCCESS;
}