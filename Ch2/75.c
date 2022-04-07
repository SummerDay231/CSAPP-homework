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

unsigned unsigned_high_prod(unsigned x, unsigned y);

int main()
{
    int x = 0x40000000, y = 0x40000000;
    show_int(signed_high_prod(x, y));
    return 0;
}