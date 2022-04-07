#include <stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes_reverse(byte_pointer start, size_t len) {
    size_t i;
    for (i = len; i != 0; --i)
	    printf(" %.2x", start[i-1]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_int(int x) {
    show_bytes_reverse((byte_pointer) &x, sizeof(int)); //line:data:show_bytes_amp1
}

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(x) << 3;
    unsigned left = x << n;
    unsigned right = x >> (w-n);
    return left | right;
}

int main()
{
    show_int(rotate_left(0x12345678, 20));
    return 0;
}