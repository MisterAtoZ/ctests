#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define COUNT 640*1024*1024

int main() {
    printf("malloc, memset and write\n");
    /*here we allocate 640*Mb*8 = 5Gb */
    int64_t *buf = (int64_t *)malloc(COUNT * sizeof(int64_t));
    memset(buf,'\0',COUNT * sizeof(int64_t));
    
    for(int i=0;  i< COUNT; i++) {
        buf[i] = 0x0000000000000001;
    }
    
    return 0;
}
