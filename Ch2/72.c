#include <stdio.h>
#include <string.h>

void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes-(int)sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}

int main()
{
    size_t a = 3;
    int b = -10000;
    printf("%d",  b > (int)a);
    return 0;
}