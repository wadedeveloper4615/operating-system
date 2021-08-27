CFLAGS = -m32 -Wno-int-conversion -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdlib -ffreestanding -I./include -std=gnu99 -g -ggdb
LFLAGS = -m32 -ffreestanding -O2 -nostdlib -g -ggdb

CC=x86_64-w64-mingw32-gcc
ASM=nasm
LINK=x86_64-w64-mingw32-gcc
OBJDUMP=x86_64-w64-mingw32-objdump
OBJCOPY=x86_64-w64-mingw32-objcopy
DISASM=ndisasm

# Setup C/ASM SOURCES(Don't change the order of the following source file names! bad things can happen!)
SOURCES=src/kernel/kernel.c src/kernel/screen.c src/kernel/ports.c src/kernel/mem.c src/kernel/string.c src/kernel/io.c src/kernel/gdt.c src/kernel/idt.c \
     src/kernel/tss.c src/kernel/cpuid.c src/kernel/pmm.c

ASM_SOURCES=src/kernel/kernel_entry.asm src/kernel/interrupt_helper.asm src/kernel/irq_helper.asm src/kernel/paging_helper.asm

OBJECTS= $(ASM_SOURCES:.asm=.o) $(SOURCES:.c=.o)

all: $(SOURCES) prep kernel

hdd:
	-dd if=/dev/zero of=fat32hda.img bs=1k count=100000 > /dev/zero
	-mkfs -t vfat -i 1024 -b 1024 -F fat32hda.img > /dev/zero

prep:
	mkdir -p debug
	mkdir -p bin
	mkdir -p release
	mkdir -p isodir/boot/grub

kernel: bin/ntldr
	cp bin/ntldr isodir/boot/ntldr
	cp src/kernel/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o release/jarvis.iso isodir

bin/ntldr: $(OBJECTS)
	${LINK} -o bin/kernel.exe ${LFLAGS} -T src/kernel/linker.ld $^
	-${OBJDUMP} -M i386,intel -D bin/kernel.exe >debug/kernel.exe.dump.txt 2>&1
	${OBJCOPY} -O binary bin/kernel.exe $@
	-${DISASM} -b 32 $@ >debug/ntldr.dump.txt 2>&1

%.o: %.asm
	${ASM} $< -f win32 -o $@

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	find . -type f -name '*.o' -delete

	rm -rf isodir
	rm -rf debug
	rm -rf bin
	rm -rf release
