nasm -f bin boot_sect_hello.asm -o boot_sect_hello.bin
qemu-system-i386 boot_sect_hello.bin
