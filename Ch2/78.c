#include <stdio.h>
#include <limits.h>

int divide_power2(int x,int k){
    int sig = x&INT_MIN;
    (sig&&(x=x+(1<<k)-1));
    return x>>k;
}