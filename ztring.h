#ifndef ZTRING_H
#define ZTRING_H

#include <stdlib.h>

struct __attribute__((__packed__)) ztr_header {
    size_t allocated;
    size_t length;
    char buffer[];
};

char *ztr_new(const char *input);

void ztr_free(char *ztr);

size_t ztr_length(const char *ztr);

#endif
