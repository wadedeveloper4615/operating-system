del *.txt
del *.o
del *.exe
gcc -g -c entry.S  -o entry.o
gcc -g -c freldr.c -o freldr.o
gcc -nostdlib -Wl,--enable-auto-image-base,--disable-auto-import -Wl,--disable-stdcall-fixup,--gc-sections -Wl,-T,linker.ld -Wl,--image-base,0x10000 -Wl,--subsystem,native:5.01 -Wl,-entry,_RealEntryPoint  -Wl,--exclude-all-symbols,--file-alignment,0x200,--section-alignment,0x200 -o freeldr_pe.exe entry.o freldr.o
strip.exe --remove-section=.rossym freeldr_pe.exe 
strip.exe --strip-all freeldr_pe.exe
objdump -Mi386,intel -D entry.o > entry.o.txt
objdump -Mi386,intel -D freldr.o > freldr.o.txt
objdump -Mi386,intel -D freeldr_pe.exe > freldr.exe.txt
