#include <kernel.h> 
#include <ports.h>
#include <io.h> 
#include <mem.h> 
#include <gdt.h>
#include <idt.h>
#include <tss.h>
#include <cpuid.h>
#include <pmm.h>

uint32_t page_directory[1024] __attribute__((aligned(4096)));
uint32_t first_page_table[1024] __attribute__((aligned(4096)));

extern void loadPageDirectory(unsigned int*);
extern void enablePaging();

void __cdecl kernel_main() {
    InitializeVideo();
    clrscr();
    detectHardware();
    kprintf("Welcome to Jarvis OS v%s\n","0.01 Alpha");
	kprintf("A 32 bit protected mode OS\n");
    gdt_init();
    idt_init();
    tss_init(5, 0x10, 0);
    kprintf("GDT, IDT, and TSS initialized\n");
    pmm_init(1096 * M);
    kprintf("Physical Memory Manager initialized\n");
    //set each entry to not present
    int i;
    for(i = 0; i < 1024; i++)
    {
        // This sets the following flags to the pages:
        //   Supervisor: Only kernel-mode can access them
        //   Write Enabled: It can be both read from and written to
        //   Not Present: The page table is not present
        page_directory[i] = 0x00000002;
    }
     
    //we will fill all 1024 entries in the table, mapping 4 megabytes
    for(i = 0; i < 1024; i++)
    {
        // As the address is page aligned, it will always leave 12 bits zeroed.
        // Those bits are used by the attributes ;)
        first_page_table[i] = (i * 0x1000) | 3; // attributes: supervisor level, read/write, present.
    }
    page_directory[0] = ((unsigned int)first_page_table) | 3;
    loadPageDirectory(page_directory);
    enablePaging();
    kprintf("Primitive Paging initialized\n");
}
