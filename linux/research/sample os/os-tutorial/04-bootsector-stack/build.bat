nasm -f bin boot_sect_stack.asm -o boot_sect_stack.bin
qemu-system-i386 boot_sect_stack.bin