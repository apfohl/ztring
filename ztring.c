#include <string.h>

#include "ztring.h"

#include <stdio.h>

const size_t ZTR_HEADER_SIZE = sizeof(struct ztr_header);

char *ztr_new(const char *input)
{
    if (!input) {
        return NULL;
    }

    const size_t length = strlen(input);

    return ztr_new_length(input, length);
}

char *ztr_new_length(const char *input, size_t length)
{
    if (!input) {
        return NULL;
    }

    const size_t allocation_length = length + ZTR_HEADER_SIZE + 1;

    struct ztr_header *ztr = calloc(allocation_length, sizeof(char));
    if (!ztr) {
        return NULL;
    }

    ztr->allocated = allocation_length;
    ztr->length = length;

    memcpy(ztr->buffer, input, length);

    ztr->buffer[ztr->length] = '\0';

    return ztr->buffer;
}

void ztr_free(char *ztr)
{
    if (ztr) {
        char *ptr = ztr - ZTR_HEADER_SIZE;
        free(ptr);
    }
}

size_t ztr_length(const char *ztr)
{
    if (ztr != NULL) {
        struct ztr_header *ptr = (struct ztr_header *)(ztr - ZTR_HEADER_SIZE);

        return ptr->length;
    }

    return 0;
}
