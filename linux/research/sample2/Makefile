CFLAGS = -Os
LFLAGS =

all: hello.exe 

hello.exe: hello.o div.o
	-i686-w64-mingw32-gcc -m32 -o hello.exe div.o hello.o

hello.o: hello.c
	i686-w64-mingw32-gcc -m32 -c -o hello.o hello.c

div.o: div.asm
	nasm -f win32 -o div.o div.asm

clean:
	rm -rf *.exe *.o *.dump *.txt *.map
