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

int saturating_add(int x, int y) {
    int w = sizeof(int) << 3;
    int result = x + y, INT_MAX = (1 << (w-1)) - 1, INT_MIN = 1 << (w-1);
    int p_of = x>0 && y>0 && result <= 0, n_of = x<0 && y<0 && result >= 0, of = p_of || n_of;
    int p_mask = p_of << (w-1) >> (w-1), n_mask = n_of << (w-1) >> (w-1), re_mask = (!of) << (w-1) >> (w-1);
    return (result & re_mask) | (p_mask & INT_MAX) | (n_mask & INT_MIN);
}

int main()
{
    show_int(saturating_add(0x80000000+15, -16));
    return 0;
}