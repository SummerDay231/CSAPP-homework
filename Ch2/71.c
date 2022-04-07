#include <stdio.h>

typedef unsigned packed_t;
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

int xbyte(packed_t word, int bytenum) {
    return (int)word << ((3-bytenum)<<3) >> 24;
}

int main()
{
    show_int(xbyte(0xABCD5678, 0));
    return 0;
}