#ifndef PMM_H
#define PMM_H

#include <stdint.h>

#define K 1024
#define M (1024*K)
#define G (1024*M)
#define BLOCK_SIZE 4096
#define BLOCKS_PER_BUCKET 8
// Define some bit manipulating operations
#define SETBIT(i) bitmap[i / BLOCKS_PER_BUCKET] = bitmap[i / BLOCKS_PER_BUCKET] | (1 << (i % BLOCKS_PER_BUCKET))
#define CLEARBIT(i) bitmap[i / BLOCKS_PER_BUCKET] = bitmap[i / BLOCKS_PER_BUCKET] & (~(1 << (i % BLOCKS_PER_BUCKET)))
#define ISSET(i) ((bitmap[i / BLOCKS_PER_BUCKET] >> (i % BLOCKS_PER_BUCKET)) & 0x1)
#define GET_BUCKET32(i) (*((uint32_t*) &bitmap[i / 32]))

#define BLOCK_ALIGN(addr) (((addr) & 0xFFFFF000) + 0x1000)
 
// Defined in link.ld, end of kernel executable, aka. all the memory you can use
extern uint32_t end;
extern uint8_t * bitmap;
extern uint8_t * mem_start;
extern uint32_t total_blocks;
extern uint32_t bitmap_size;

void pmm_init(uint32_t mem_size);

#endif