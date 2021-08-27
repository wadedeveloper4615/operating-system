#include "mem.h"

int memcmp(uint8_t * data1, uint8_t * data2, int n) {
    while(n--) {
        if(*data1 != *data2)
            return 0;
        data1++;
        data2++;
    }
    return 1;
}

void *memcpy(void *dst, void const *src, int n) {
    char * ret = dst;
    char * p = dst;
    const char * q = src;
    while (n--)
        *p++ = *q++;
    return ret;
}

void *memset(void *dst,char val, int n) {
    char *temp = dst;
    for(;n != 0; n--) *temp++ = val;
    return dst;
}
