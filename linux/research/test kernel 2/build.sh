#!/bin/bash
rm *.o *.iso *.exe *.txt isodir/boot/ntldr
nasm -f elf32 -O0 entry.asm -o entry.o
/mnt/c/cross/opt/cross/bin/i386-elf-gcc -m32 -nostdlib -ffreestanding kernel.c -c -o kernel.o
/mnt/c/cross/opt/cross/bin/i386-elf-gcc -m32 -ffreestanding -O2 -nostdlib -T linker.ld entry.o kernel.o -o oskernel
/mnt/c/cross/opt/cross/bin/i386-elf-objdump -M i386,intel -D oskernel >oskernel.dump.txt 2>&1
