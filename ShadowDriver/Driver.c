/*++

Module Name:

    driver.c

Abstract:

    This file contains the driver entry points and callbacks.

Environment:

    Kernel-mode Driver Framework

--*/

#include "driver.h"
#include "driver.tmh"
#include "fwpsk.h"

#ifdef ALLOC_PRAGMA
#pragma alloc_text (INIT, DriverEntry)
#pragma alloc_text (PAGE, ShadowDriverEvtDeviceAdd)
#pragma alloc_text (PAGE, ShadowDriverEvtDriverContextCleanup)
#endif

WDFDEVICE wdfDevice;
NTSTATUS CreateWdfDevice(WDFDRIVER driver)
{
    //WDF Device Code
    PWDFDEVICE_INIT deviceInit;
    PDEVICE_OBJECT deviceObject;
    NTSTATUS status;

    //�����豸��ʼ���ṹ
    deviceInit = WdfControlDeviceInitAllocate(
        driver,
        &SDDL_DEVOBJ_KERNEL_ONLY
    );

    //��ʼ��WDF�豸����
    WdfDeviceInitSetCharacteristics(
        deviceInit,
        FILE_DEVICE_SECURE_OPEN,
        FALSE
    );

    //����WDF�豸
    status = WdfDeviceCreate(&deviceInit, WDF_NO_OBJECT_ATTRIBUTES, &wdfDevice);

    if (status == STATUS_SUCCESS)
    {
        WdfControlFinishInitializing(wdfDevice);
        deviceObject = WdfDeviceWdmGetDeviceObject(wdfDevice);
    }

    return status;
}

// {61776EB9-EE7E-46C3-9A23-2A8C4C647AE3}
static const GUID calloutGuid =
{ 0x61776eb9, 0xee7e, 0x46c3, { 0x9a, 0x23, 0x2a, 0x8c, 0x4c, 0x64, 0x7a, 0xe3 } };

const FWPS_CALLOUT0 Callout =
{
    { 0x61776eb9, 0xee7e, 0x46c3, { 0x9a, 0x23, 0x2a, 0x8c, 0x4c, 0x64, 0x7a, 0xe3 } },
    0,
    ClassifyFn,
    NotifyFn,
    FlowDeleteFn
};

UINT32 CalloutId;
NTSTATUS RegisterCalloutFuntions(PDEVICE_OBJECT deviceObject)
{
    NTSTATUS status;

    status = FwpsCalloutRegister0(deviceObject, &Callout, &CalloutId);
}

NTSTATUS
DriverEntry(
    _In_ PDRIVER_OBJECT  DriverObject,
    _In_ PUNICODE_STRING RegistryPath
    )
/*++

Routine Description:
    DriverEntry initializes the driver and is the first routine called by the
    system after the driver is loaded. DriverEntry specifies the other entry
    points in the function driver, such as EvtDevice and DriverUnload.

Parameters Description:

    DriverObject - represents the instance of the function driver that is loaded
    into memory. DriverEntry must initialize members of DriverObject before it
    returns to the caller. DriverObject is allocated by the system before the
    driver is loaded, and it is released by the system after the system unloads
    the function driver from memory.

    RegistryPath - represents the driver specific path in the Registry.
    The function driver can use the path to store driver related data between
    reboots. The path does not store hardware instance specific data.

Return Value:

    STATUS_SUCCESS if successful,
    STATUS_UNSUCCESSFUL otherwise.

--*/
{
    WDF_DRIVER_CONFIG config;
    NTSTATUS status;
    WDF_OBJECT_ATTRIBUTES attributes;
    WDFDRIVER wdfDriver;

    //
    // Initialize WPP Tracing
    //
    WPP_INIT_TRACING(DriverObject, RegistryPath);

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    //
    // Register a cleanup callback so that we can call WPP_CLEANUP when
    // the framework driver object is deleted during driver unload.
    //
    WDF_OBJECT_ATTRIBUTES_INIT(&attributes);
    attributes.EvtCleanupCallback = ShadowDriverEvtDriverContextCleanup;

    WDF_DRIVER_CONFIG_INIT(&config,
                           ShadowDriverEvtDeviceAdd
                           );

    //�Լ��Ĵ���
    DriverObject->DriverUnload = Unload;


    status = InitializeFilterEngine();

    status = InitializeCalloutDriver();

    //����WDF ������
    status = WdfDriverCreate(DriverObject,
                             RegistryPath,
                             &attributes,
                             &config,
                             &wdfDriver
                             );

    DbgPrintEx(DPFLTR_IHVVIDEO_ID, DPFLTR_INFO_LEVEL, "First message.\n");
    DbgPrintEx(DPFLTR_IHVAUDIO_ID, 7, "Second message.\n");
    DbgPrintEx(DPFLTR_IHVBUS_ID, DPFLTR_MASK | 0x10, "Third message.\n");
    DbgPrint("Fourth message.\n");

    if (!NT_SUCCESS(status)) {
        TraceEvents(TRACE_LEVEL_ERROR, TRACE_DRIVER, "WdfDriverCreate failed %!STATUS!", status);
        WPP_CLEANUP(DriverObject);
        return status;
    }

    status = CreateWdfDevice(wdfDriver);

    if (!NT_SUCCESS(status)) {
        TraceEvents(TRACE_LEVEL_ERROR, TRACE_DRIVER, "WdfDriverCreate failed %!STATUS!", status);
        WPP_CLEANUP(DriverObject);
        return status;
    }

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

    return status;
}

VOID Unload(PDRIVER_OBJECT DriverObject)
{

}

NTSTATUS
ShadowDriverEvtDeviceAdd(
    _In_    WDFDRIVER       Driver,
    _Inout_ PWDFDEVICE_INIT DeviceInit
    )
/*++
Routine Description:

    EvtDeviceAdd is called by the framework in response to AddDevice
    call from the PnP manager. We create and initialize a device object to
    represent a new instance of the device.

Arguments:

    Driver - Handle to a framework driver object created in DriverEntry

    DeviceInit - Pointer to a framework-allocated WDFDEVICE_INIT structure.

Return Value:

    NTSTATUS

--*/
{
    NTSTATUS status;

    UNREFERENCED_PARAMETER(Driver);

    PAGED_CODE();

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    status = ShadowDriverCreateDevice(DeviceInit);

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Exit");

    return status;
}

VOID
ShadowDriverEvtDriverContextCleanup(
    _In_ WDFOBJECT DriverObject
    )
/*++
Routine Description:

    Free all the resources allocated in DriverEntry.

Arguments:

    DriverObject - handle to a WDF Driver object.

Return Value:

    VOID.

--*/
{
    UNREFERENCED_PARAMETER(DriverObject);

    PAGED_CODE();

    TraceEvents(TRACE_LEVEL_INFORMATION, TRACE_DRIVER, "%!FUNC! Entry");

    //
    // Stop WPP Tracing
    //
    WPP_CLEANUP(WdfDriverWdmGetDriverObject((WDFDRIVER)DriverObject));
}
