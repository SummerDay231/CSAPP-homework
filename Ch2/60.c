/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
	printf(" %.2x", start[i]);    //line:data:show_bytes_printf
    printf("\n");
}

void show_unsigned(unsigned x) {
    show_bytes((byte_pointer) &x, sizeof(unsigned)); //line:data:show_bytes_amp1
}

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    return (x & ~(0xFF << (i*8))) | (b << (i*8));
}

int main()
{
    show_unsigned(replace_byte(0x12345678, 0, 0xAB));
    return 0;
}