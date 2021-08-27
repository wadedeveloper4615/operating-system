#!/bin/bash
rm *.bin *.img *.lst *.o *.txt
nasm -f bin -l fat.lst -o bootsect.bin bootsect.asm
mkfs.msdos -C floppy.img 1440
dd if=bootsect.bin of=bootsect.img conv=notrunc