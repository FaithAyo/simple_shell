#include <stdio.h>
#include <stdlib.h>

char *cf_strncpy(char *dest, const char *src, size_t n)
{
    char *dest_start = dest;

    while (*src != '\0' && n > 0) {
        *dest = *src;
        ++dest;
        ++src;
        --n;
    }

    while (n > 0) {
        *dest = '\0';
        ++dest;
        --n;
    }

    return dest_start;
}

