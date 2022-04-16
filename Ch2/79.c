#include <stdio.h>
#include <limits.h>

int divide_power2(int x,int k){
    int sig = x&INT_MIN;
    (sig&&(x=x+(1<<k)-1));
    return x>>k;
}

int mul3div4(int x) {
    return divide_power2(x, 2) * 3;
}