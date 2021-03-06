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

int lower_one_mask(int n) {
    return (((1 << (n-1)) - 1) << 1) + 1;
}

int main()
{
    int n;
    scanf("%d", &n);
    show_int(lower_one_mask(n));
    return 0;
}