#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>


#define DATASIZE (1024 * 1024)

int64_t bshuf_trans_bit_elem(const void* in, void* out, const size_t size, const size_t elem_size);

uint8_t outdata[DATASIZE];

long int GetTickCount() {
        struct timeval tv;
        gettimeofday(&tv, NULL);
        return tv.tv_sec * 1000000 + tv.tv_usec;
}


int main() {
    uint8_t* buf = (uint8_t *)malloc(sizeof(uint8_t) * DATASIZE);
    long int start, end;

    start = GetTickCount();
    bshuf_trans_bit_elem (buf, outdata, DATASIZE, 1);
    end = GetTickCount();

    printf("time cost :%f ms\n", (double)(end - start));

    free(buf);
    return 0;
}

