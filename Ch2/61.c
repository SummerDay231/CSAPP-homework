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

int main()
{
    int x = 0x010000FE;
    int w = sizeof(int) << 3;
    int a = !(~x);
    int b = !x;
    int c = !(~(x << (w-8) >> (w-8)));
    int d = !(x >> (w-8));
    //show_int(x << (w-8) >> (w-8));
    printf("%d", d);
    return 0;
}