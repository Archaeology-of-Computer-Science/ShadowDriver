#include "ShadowUtilities.h"
#include <wdm.h>
#include <stdlib.h>

void WriteSometing()
{
	DbgPrintEx(DPFLTR_IHVVIDEO_ID, DPFLTR_INFO_LEVEL, "WriteSomething\n");
}

void* __cdecl malloc(
	_In_ size_t _Size
)
{
	return ExAllocatePoolWithTag(NonPagedPool, _Size, 'fake');
}

void __cdecl free(
	_Pre_maybenull_ _Post_invalid_ void* _Block
)
{
	if (_Block != NULL)
	{
		ExFreePoolWithTag(_Block, 'fake');
	}
}

