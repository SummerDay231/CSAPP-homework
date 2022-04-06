/* $begin show-bytes */
#include <stdio.h>
/* $end show-bytes */
#include <stdlib.h>
#include <string.h>
/* $begin show-bytes */

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

int main()
{
    int x = 0x87654321;
    int a = 0x000000FF;
    show_int(x&a);
    int b = 0xFFFFFF00;
    show_int(x^b);
    int c = 0x000000FF;
    show_int(x|c);
    return 0;
}