#pragma once
#include <ntstatus.h>
#include <ntstrsafe.h>

size_t CaculateHexStringLength(size_t bytesCount);
void ConvertBytesArrayToHexString(char* bytes, size_t bytesCount, char* outputString, size_t outputStringLength);

void WriteSometing();