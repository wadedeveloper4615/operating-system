REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c function.c -o function.o
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c functioncalls.c -o functioncalls.o
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c localvars.c -o localvars.o
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c pointers.c -o pointers.o

REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c function.c
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -Wall -pedantic-errors function.c -o function.exe -nostdlib -Wl,-Ttext=0x20000,-nostdlib
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\ld.exe" -o function.exe function.o
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -d function.o
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -d function.exe
REM "C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objcopy" -O binary function.exe function.bin
REM ndisasm -b 32 function.bin > function.disasm.txt

del *.o
del *.txt
del *.bin

"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c test.c     
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objcopy" -O binary -j .text test.o test.bin
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D test.o 
ndisasm -b 32 test.bin > test.disasm.txt

"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c function.c     
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objcopy" -O binary -j .text function.o function.bin
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D function.o 
ndisasm -b 32 test.bin > function.disasm.txt

"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c functioncalls.c     
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objcopy" -O binary -j .text functioncalls.o functioncalls.bin
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D functioncalls.o 
ndisasm -b 32 functioncalls.bin > functioncalls.disasm.txt

"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c localvars.c     
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objcopy" -O binary -j .text localvars.o localvars.bin
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D localvars.o 
ndisasm -b 32 localvars.bin > localvars.disasm.txt

"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\gcc" -ffreestanding -c pointers.c     
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objcopy" -O binary -j .text pointers.o pointers.bin
"C:\Program Files (x86)\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\objdump" -D pointers.o 
ndisasm -b 32 pointers.bin > pointers.disasm.txt
