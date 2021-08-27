nasm -f bin boot_sect_main.asm -o boot_sect_main.bin
qemu-system-i386 boot_sect_main.bin