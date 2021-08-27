del *.o
del *.bin
del *.exe
del *.txt

nasm bootsect.asm -f bin -o bootsect.bin 
nasm -fwin32 boot.asm -o boot.o
gcc -m32 -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -Wall -Wextra
gcc -m32 -T linker.ld -o os.exe -ffreestanding -nostdlib boot.o kernel.o -Wl,-M > link.map.txt
objcopy -O binary os.exe kernel.bin

objdump -D boot.o > boot.dump.txt
objdump -D kernel.o > kernel.dump.txt
objdump -D os.exe > os.dump.txt
ndisasm -b 32 kernel.bin > kernel.disasm.txt
ndisasm -b 32 bootsect.bin > bootsect.disasm.txt

COPY /B bootsect.bin + kernel.bin os-image.bin
ndisasm -b 32 os-image.bin > os-image.disasm.txt

qemu-system-i386 -fda os-image.bin