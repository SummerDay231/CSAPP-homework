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

int any_odd_one(unsigned x) {
    unsigned mask = 0xAAAAAAAA; // 0x55555555 otherwise
    return !!(x & mask);
}

int main()
{
    show_int(any_odd_one(0x00000002));
    return 0;
}