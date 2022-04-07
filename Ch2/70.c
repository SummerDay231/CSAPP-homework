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

int fits_bits(int x, int n) {
    int max = (1 << n-1) - 1;
    int min = -(1 << (n-1));
    return x <= max && x >= min;
}

int main()
{
    int x, n;
    scanf("%d%d", &x, &n);
    show_int(fits_bits(x, n));
    return 0;
}