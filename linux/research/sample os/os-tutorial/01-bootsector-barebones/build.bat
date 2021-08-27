nasm -f bin boot_sect_simple.asm -o boot_sect_simple.bin
qemu-system-i386 boot_sect_simple.bin
