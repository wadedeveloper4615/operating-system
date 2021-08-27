#ifndef MEM_H
#define MEM_H

#include <stdint.h>

int memcmp(uint8_t * data1, uint8_t * data2, int n);
void *memcpy(void *dst, void const *src, int n);
void *memset(void *dst,char val, int n);

#endif
