nasm bootsect.asm -f bin -g -o bootsect.bin 
ndisasm -b 32 bootsect.bin > bootsect.bin.disasm.txt

gcc -g -ffreestanding -Wall -Wextra -fno-exceptions -m32 -std=c11 -c kernel.c -o kernel.o
gcc -g -ffreestanding -Wall -Wextra -fno-exceptions -m32 -std=c11 -nostdlib -Wl,-Ttext=0x1000,-nostdlib,-s,-r kernel.o -o kernel.exe

objcopy -O binary kernel.exe kernel.bin
objdump -D kernel.exe > kernel.dump.txt
ndisasm -b 32 kernel.bin > kernel.disasm.txt

COPY /B bootsect.bin + kernel.bin os-image.bin
ndisasm -b 32 os-image.bin > os-image.disasm.txt

qemu-system-i386 -fda os-image.bin