del *.o 
del *.iso 
del *.exe 
del *.txt 
nasm -f elf32 -O0 entry.asm -o entry.o
C:\compiler\bin\i686-elf-gcc -m32 -nostdlib -ffreestanding kernel.c -c -o kernel.o
C:\compiler\bin\i686-elf-gcc -m32 -ffreestanding -O2 -nostdlib -T linker.ld entry.o kernel.o -o oskernel
C:\compiler\bin\i686-elf-objdump -M i386,intel -D oskernel >oskernel.dump.txt 2>&1
