del *.o
del *.obj
del *.tmp
del *.bin
del *.exe
del *.txt
nasm bootsect.asm -f bin -g -o bootsect.bin 
nasm kernel_entry.asm -f win32 -o kernel_entry.o
"C:\projects\tools\MinGW64\bin\gcc" -m32 test.c -o test.exe -nostdlib -Wl,-Ttext=0x1000,-nostdlib
REM "C:\projects\tools\MinGW64\bin\gcc" -m32 -ffreestanding -nostdlib -o kernel.o -c kernel.c
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\ld" kernel_entry.o kernel.o -o kernel.tmp -T kernel.ld
REM "C:\projects\tools\MinGW64\bin\gcc" -m32  kernel_entry.o kernel.o -Ttext 0x1000 -s -r -o kernel.tmp
"C:\projects\tools\MinGW64\bin\objcopy" -O binary -j .text test.exe kernel.bin
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objcopy" -O binary kernel.tmp kernel.bin
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D kernel.tmp
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D kernel.o 
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D kernel_entry.o 
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D crt0.o
ndisasm -b 32 kernel.bin > kernel.disasm.txt
COPY /B bootsect.bin + kernel.bin os-image.bin
ndisasm -b 32 os-image.bin > os-image.disasm.txt
REM ndisasm -b 32 test.exe > test.disasm.txt
qemu-system-i386 -fda os-image.bin
