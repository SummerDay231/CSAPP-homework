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

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short)); //line:data:show_bytes_amp1
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long)); //line:data:show_bytes_amp2
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double)); //line:data:show_bytes_amp3
}
/* $end show-bytes */

/* $begin test-show-bytes */
void test_show_bytes(int val) {
    short sval = val;
    long lval = (long) val;
    double dval = (double) val;
    show_short(sval);
    show_long(lval);
    show_double(dval);
}
/* $end test-show-bytes */

int main(int argc, char *argv[])
{
    int val = 12345;

    if (argc > 1) {
        if (argc > 1) {
            val = strtol(argv[1], NULL, 0);
        }
        printf("calling test_show_bytes\n");
        test_show_bytes(val);
    }
    return 0;
}