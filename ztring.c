#include <string.h>

#include "ztring.h"

const size_t ZTR_HEADER_SIZE = sizeof(struct ztr_header);

char *ztr_new(const char *input)
{
    const size_t input_length = strlen(input);
    const size_t length = input_length + ZTR_HEADER_SIZE + 1;

    struct ztr_header *ztr = calloc(length, sizeof(char));
    if (ztr == NULL) {
        return NULL;
    }

    ztr->allocated = length;
    ztr->length = input_length;

    memcpy(ztr->buffer, input, input_length);

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
