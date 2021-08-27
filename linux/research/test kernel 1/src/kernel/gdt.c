#include "gdt.h" 

gdt_entry_t gdt_entries[NUM_DESCRIPTORS];
gdt_ptr_t   gdt_ptr;

void gdt_set_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran) {
    gdt_entry_t * this = &gdt_entries[index];
    this->base_low = base & 0xFFFF;
    this->base_middle = (base >> 16) & 0xFF;
    this->base_high = (base >> 24 & 0xFF);
    this->limit_low = limit & 0xFFFF;
    this->granularity = (limit >> 16) & 0x0F;
    this->access = access;
    this->granularity = this->granularity | (gran & 0xF0);
}

void gdt_init() {
    gdt_ptr.limit = sizeof(gdt_entries) - 1;
    gdt_ptr.base = (uint32_t)gdt_entries;
    gdt_set_entry(0, 0, 0,          0,    0);    //starts at 0x00
    gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); //starts at 0x10 32bit OS CODE
    gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); //starts at 0x18 32bit OS DATA
    gdt_set_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); //starts at 0x20 32bit USER CODE
    gdt_set_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); //starts at 0x28 32bit USER CODE
    asm(
        "lgdt %0\n" 
        "movw $0x10, %%ax\n"
        "movw %%ax, %%ds\n"
        "movw %%ax, %%es\n"
        "movw %%ax, %%fs\n"
        "movw %%ax, %%gs\n"
        "movw %%ax, %%ss\n"        
        "ljmp $0x08, $.i386_lgdt_jump\n"
        ".i386_lgdt_jump:\n"
        : 
        :"m"(gdt_ptr));
}
