#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) << 3;
    unsigned mask = ~(0xFFFFFFFF << (w-k));
    return xsra & mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    // 0000...abcd -> ssss...abcd
    int w = sizeof(int) << 3;
    int mask = (-(!!(x & 0x80000000))) << (w-k);
    return xsrl | mask;
}

int main()
{
    show_int(sra(0x0FFFFFFF, 8));
    return 0;
}