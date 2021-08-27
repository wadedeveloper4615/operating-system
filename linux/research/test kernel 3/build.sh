#!/bin/bash
rm *.bin *.img *.lst *.o *.txt
nasm -f bin -O0 fat12.asm -l fat12.lst -o fat12.bin
mkfs.msdos -C floppy.img 1440
dd if=fat12.bin of=floppy.img conv=notrunc
