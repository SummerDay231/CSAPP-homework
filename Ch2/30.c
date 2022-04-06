#include <stdio.h>

int tadd_ok(int x, int y) {
    int result = x + y;
    return !((x>0&&y>0&&result<=0)||(x<0&&y<0&&result>=0));
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", tadd_ok(x, y));
    return 0;
}