#define DECLSPEC_ALIGN(x) __attribute__((aligned(x)))

typedef unsigned long ULONG;
typedef long DWORD;
typedef unsigned short USHORT;
typedef unsigned char UCHAR;
typedef void *PVOID;
typedef void VOID;

typedef struct _KIDTENTRY {
    USHORT Offset;
    USHORT Selector;
    USHORT Access;
    USHORT ExtendedOffset;
} KIDTENTRY, *PKIDTENTRY;

typedef struct _DESCRIPTOR {
    USHORT Pad;
    USHORT Limit;
    ULONG Base;
} KDESCRIPTOR, *PKDESCRIPTOR;

extern DWORD cmdline;
KIDTENTRY DECLSPEC_ALIGN(4) i386Idt[32];
KDESCRIPTOR i386IdtDescriptor = {0, 255, (ULONG)i386Idt};

static void InitIdtVector(UCHAR Vector, PVOID ServiceHandler, USHORT Access) {
}

void __cdecl InitIdt(void){	
}

VOID __cdecl DiskStopFloppyMotor(VOID){
}

void __cdecl BootMain(char *CmdLine){
}
