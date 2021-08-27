#ifndef _PCBIOS_H_
#define _PCBIOS_H_

#ifdef __ASM__
#define EFLAGS_CF HEX(01)
#define EFLAGS_ZF HEX(40)
#define EFLAGS_SF HEX(80)
#endif

/* Layout of the REGS structure */
#define REGS_EAX 0
#define REGS_EBX 4
#define REGS_ECX 8
#define REGS_EDX 12
#define REGS_ESI 16
#define REGS_EDI 20
#define REGS_EBP 24
#define REGS_DS 28
#define REGS_ES 30
#define REGS_FS 32
#define REGS_GS 34
#define REGS_EFLAGS 36
#define REGS_SIZE 40

#endif /* _PCBIOS_H_ */
