
/*
	chztbby::RebirthGuard/ntstruct.h
*/

#ifndef NTSTRUCT_H
#define NTSTRUCT_H

#include <windows.h>
#include <winternl.h>

#define SEC_NO_CHANGE 0x00400000
#define STATUS_INVALID_PAGE_PROTECTION 0xC0000045
#define STATUS_WORKING_SET_QUOTA 0xC00000A1
#define ViewUnmap 2
#define LDR_DLL_NOTIFICATION_REASON_LOADED 1
#define	MemoryBasicInformation 0
#define	MemoryWorkingSetExList 4
#define ProcessQuotaLimits 1
#define ThreadQuerySetWin32StartAddress 9
#define	ThreadHideFromDebugger 0x11
#define SE_AUDIT_PRIVILEGE 0x21
#define VM_LOCK_1 0x0001

NTSTATUS NTAPI NtCreateSection(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES, PLARGE_INTEGER, ULONG, ULONG, HANDLE);
NTSTATUS NTAPI NtMapViewOfSection(HANDLE, HANDLE, PVOID*, ULONG_PTR, SIZE_T, PLARGE_INTEGER, PSIZE_T, DWORD, ULONG, ULONG);
NTSTATUS NTAPI NtUnmapViewOfSection(HANDLE, PVOID);
NTSTATUS NTAPI NtProtectVirtualMemory(HANDLE, PVOID*, PSIZE_T, ULONG, PULONG);
NTSTATUS NTAPI NtQueryVirtualMemory(HANDLE, PVOID, DWORD, PVOID, SIZE_T, PSIZE_T);
NTSTATUS NTAPI NtLockVirtualMemory(HANDLE, PVOID, PSIZE_T, ULONG);
NTSTATUS NTAPI NtReadVirtualMemory(HANDLE, PVOID, PVOID, SIZE_T, PSIZE_T);
NTSTATUS NTAPI NtWriteVirtualMemory(HANDLE, PVOID, PVOID, SIZE_T, PSIZE_T);
NTSTATUS NTAPI NtAllocateVirtualMemory(HANDLE, PVOID*, ULONG_PTR, PSIZE_T, ULONG, ULONG);
NTSTATUS NTAPI NtFreeVirtualMemory(HANDLE, PVOID*, PSIZE_T, ULONG);
NTSTATUS NTAPI NtResumeProcess(HANDLE);
NTSTATUS NTAPI NtSetInformationProcess(HANDLE, DWORD, PVOID, ULONG);
NTSTATUS NTAPI NtSetInformationThread(HANDLE, DWORD, PVOID, ULONG);
NTSTATUS NTAPI RtlAcquirePrivilege(PULONG, ULONG, ULONG, PVOID*);
NTSTATUS NTAPI RtlReleasePrivilege(PVOID);
NTSTATUS NTAPI RtlUserThreadStart(PTHREAD_START_ROUTINE, PVOID);
NTSTATUS NTAPI NtCreateThreadEx(PHANDLE, ACCESS_MASK, PVOID, HANDLE, PVOID, PVOID, ULONG, SIZE_T, SIZE_T, SIZE_T, PVOID);
NTSTATUS NTAPI NtTerminateProcess(HANDLE, NTSTATUS);
NTSTATUS NTAPI NtTerminateThread(HANDLE, NTSTATUS);
NTSTATUS NTAPI RtlAddVectoredExceptionHandler(ULONG, PVECTORED_EXCEPTION_HANDLER);
NTSTATUS NTAPI LdrRegisterDllNotification(ULONG, PVOID, PVOID, PVOID);
NTSTATUS NTAPI LdrLoadDll(PWCHAR, ULONG, PUNICODE_STRING, PHANDLE);

typedef struct _LDR_DLL_LOADED_NOTIFICATION_DATA
{
	ULONG Flags;
	PCUNICODE_STRING FullDllName;
	PCUNICODE_STRING BaseDllName;
	PVOID DllBase;
	ULONG SizeOfImage;
} LDR_DLL_LOADED_NOTIFICATION_DATA, * PLDR_DLL_LOADED_NOTIFICATION_DATA;

typedef struct _LDR_DLL_UNLOADED_NOTIFICATION_DATA
{
	ULONG Flags;
	PCUNICODE_STRING FullDllName;
	PCUNICODE_STRING BaseDllName;
	PVOID DllBase;
	ULONG SizeOfImage;
} LDR_DLL_UNLOADED_NOTIFICATION_DATA, * PLDR_DLL_UNLOADED_NOTIFICATION_DATA;

typedef union _LDR_DLL_NOTIFICATION_DATA
{
	LDR_DLL_LOADED_NOTIFICATION_DATA Loaded;
	LDR_DLL_UNLOADED_NOTIFICATION_DATA Unloaded;
} LDR_DLL_NOTIFICATION_DATA, * PLDR_DLL_NOTIFICATION_DATA;

typedef struct _PEB_LDR_DATA_
{
	ULONG Length;
	BOOLEAN Initialized;
	PVOID SsHandle;
	LIST_ENTRY InLoadOrderModuleList;
	LIST_ENTRY InMemoryOrderModuleList;
	LIST_ENTRY InInitializationOrderModuleList;
} PEB_LDR_DATA_, * PPEB_LDR_DATA_;


#endif