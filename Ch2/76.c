#include <stdio.h>

void *calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) return NULL;
    int mult = nmemb * size;
    if (nmemb = mult / size) {
        void *p = malloc(nmemb * size);
        if (p)
            memset(p, 0, nmemb * size);
        return p;
    }
    return NULL;
}