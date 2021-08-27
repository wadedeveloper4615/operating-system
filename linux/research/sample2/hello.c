#include <stdio.h>

extern unsigned int test (unsigned int, unsigned int);

int main(void){
    printf("%d\n", test (85,5));    /* you are calling div here, not _test */
    return 0;
}