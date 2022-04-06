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

int leftmost_one(unsigned x) {
    int pos = !!(x >> 16) * 16; // leftmost_one is in 16-31 or 0-15
    pos += !!(x >> (pos + 8)) * 8;
    pos += !!(x >> (pos + 4)) * 4;
    pos += !!(x >> (pos + 2)) * 2;
    pos += !!(x >> (pos + 1));
    return (1 << pos) & x;
}

int main()
{
    show_int(leftmost_one(0x00006600));
    return 0;
}