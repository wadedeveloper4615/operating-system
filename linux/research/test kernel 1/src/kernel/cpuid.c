#include <cpuid.h>


void __cpuid(int CPUInfo[4], int InfoType) {
    __asm__ __volatile__("cpuid" : "=a" (CPUInfo[0]), "=b" (CPUInfo[1]), "=c" (CPUInfo[2]), "=d" (CPUInfo[3]) : "a" (InfoType));
}

void __cpuidex(int CPUInfo[4], int InfoType, int ECXValue) {
    __asm__ __volatile__("cpuid" : "=a" (CPUInfo[0]), "=b" (CPUInfo[1]), "=c" (CPUInfo[2]), "=d" (CPUInfo[3]) : "a" (InfoType), "c" (ECXValue));
}

void detectCPU(){
    int CpuInformation[4] = {-1};
    ULONG NumberOfIds;

    /* Check if the processor first supports ID 1 */
    __cpuid(CpuInformation, 0);

    NumberOfIds = CpuInformation[0];

    if (NumberOfIds == 0) {
        kprintf("JarvisOS requires the CPUID instruction to return more than one supported ID.\n");
    }

    if (NumberOfIds >= 1) {
        int ProcessorFamily;

        /* Get information */
        __cpuid(CpuInformation, 1);

        ProcessorFamily = (CpuInformation[0] >> 8) & 0xF;

        /* If it's Family 4 or lower, bugcheck */
        if (ProcessorFamily < 5) {
            kprintf("Processor is too old (family %u < 5)\n",ProcessorFamily);
        } else {
            kprintf("Processor is acceptable (family %u > 5)\n",ProcessorFamily);
        }
        kprintf("JarvisOS requires a Pentium-level processor or newer.\n",ProcessorFamily);
    }
}

void detectHardware(){
    detectCPU();
}