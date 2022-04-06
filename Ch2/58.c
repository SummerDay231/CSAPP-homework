#include <stdio.h>

typedef unsigned char *byte_pointer;


int is_little_endian() {
    int x = 0xFC;
    byte_pointer start = (byte_pointer) &x;
    if ((int) *start == 0xFC) {
        printf("Yes");
    }
    return 0;
}

int main() {
    is_little_endian();
}