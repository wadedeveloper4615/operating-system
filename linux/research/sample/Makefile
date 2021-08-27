CFLAGS = -Os
LFLAGS = -Wl,-s,--print-map

all: hello32.exe hello64.exe

hello32.exe: hello32.o
	-i686-w64-mingw32-gcc ${LFLAGS} $< -o $@ >hello32.map 2>&1
	-i686-w64-mingw32-objdump -D hello32.exe >hello32.exe.dump 2>&1

hello64.exe: hello64.o
	-x86_64-w64-mingw32-gcc ${LFLAGS} $< -o $@ >hello64.map 2>&1
	-x86_64-w64-mingw32-objdump -D hello64.exe >hello64.exe.dump 2>&1

hello32.o: hello.c
	i686-w64-mingw32-gcc ${CFLAGS} -c $< -o $@

hello64.o: hello.c
	x86_64-w64-mingw32-gcc ${CFLAGS} -c $< -o $@

clean:
	rm -rf *.exe *.o *.dump
