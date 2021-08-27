#ifndef CPUID_H
#define CPUID_H

#include <stdint.h>
#include <io.h> 
#include <screen.h>

void __cpuid(int CPUInfo[4], int InfoType);
void __cpuidex(int CPUInfo[4], int InfoType, int ECXValue);
void detectCPU();
void detectHardware();

#endif
