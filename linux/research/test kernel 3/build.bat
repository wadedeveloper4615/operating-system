rm *.bin *.img *.lst
nasm -f bin -O0 fat12.asm -l fat12.lst -o fat12.bin
C:\projects\tools\MinGW64\bin\gcc -x assembler-with-cpp -o fat.o  -D__ASM__ -c fat.S
C:\projects\tools\MinGW64\bin\objcopy -O binary fat.o fat.bin
C:\projects\tools\MinGW64\bin\objdump -M i386,intel -D fat.o > fat.lst
rem mkfs.msdos -C floppy.img 1440
rem dd if=fat12.bin of=floppy.img conv=notrunc
