#include <stdio.h>

int tsub_ok(int x,int y){
    int sub = x-y;
    return !((x>0&&y<0&&sub<0)||(x<0&&y>0&&sub>0));
}