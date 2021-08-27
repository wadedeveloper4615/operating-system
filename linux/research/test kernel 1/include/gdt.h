#ifndef GDT_H
#define GDT_H

#include <stdint.h>
#include <kernel.h>

typedef struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t  base_middle;
    uint8_t  access;
    uint8_t  granularity;
    uint8_t  base_high;
} __attribute__((packed)) gdt_entry_t;

typedef struct gdt_ptr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) gdt_ptr_t;

#define NUM_DESCRIPTORS 8

extern gdt_entry_t gdt_entries[NUM_DESCRIPTORS];
extern gdt_ptr_t   gdt_ptr;

void gdt_set_entry(int index, uint32_t base, uint32_t limit, uint8_t access, uint8_t gran);
void gdt_init();

#endif
