#include <stdio.h>

int uadd_ok(unsigned x, unsigned y) {
    unsigned result = x + y;
    return x < result;
}

int main()
{
    unsigned x, y;
    scanf("%u%u", &x, &y);
    printf("%d", uadd_ok(x, y));
    return 0;
}