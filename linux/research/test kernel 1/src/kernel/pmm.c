#include <pmm.h>
#include <mem.h>
#include <io.h>

uint8_t * bitmap = (uint8_t*)(&end);
uint8_t * mem_start;
uint32_t total_blocks;
uint32_t bitmap_size;

void pmm_init(uint32_t mem_size) {
    total_blocks = mem_size / BLOCK_SIZE;
    // For the given memory size, how many bytes is needed for the bitmap? (mem_size nees to be multiple of BLOCK_SIZE = 4096)
    bitmap_size = total_blocks / BLOCKS_PER_BUCKET;
    if(bitmap_size * BLOCKS_PER_BUCKET < total_blocks)
        bitmap_size++;

    // Clear bitmap
    memset(bitmap, 0, bitmap_size);

    // Start of all blcoks
    mem_start = (uint8_t*)BLOCK_ALIGN(((uint32_t)(bitmap + bitmap_size)));

    kprintf("mem size:     %u mb\n", mem_size / (1024 * 1024));
    kprintf("total_blocks: %u\n", total_blocks);
    kprintf("bitmap addr:  0x%p\n", bitmap);
    kprintf("bitmap_size:  %u\n", bitmap_size);
    kprintf("mem_start:    0x%p\n", mem_start);
}
