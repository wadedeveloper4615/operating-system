nasm -f bin boot_sect_segmentation.asm -o boot_sect_segmentation.bin
qemu-system-i386 boot_sect_segmentation.bin