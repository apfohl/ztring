#include <speck.h>
#include <ztring.h>

void spec_ztr_new(void)
{
    char *input = "Hello World!";
    char *ztr = ztr_new(input);
    size_t length = ztr_length(ztr);

    sp_assert_equal_s(ztr, input);
    sp_assert_equal_i(length, 12);

    ztr_free(ztr);
}

void spec_ztr_new_input_null(void)
{
    char *ztr = ztr_new(NULL);

    sp_assert(ztr == NULL);
}

void spec_ztr_new_length(void)
{
    char *input = "Hello World!";
    char *ztr = ztr_new_length(input, 5);
    size_t length = ztr_length(ztr);

    sp_assert_equal_s(ztr, "Hello");
    sp_assert_equal_i(length, 5);

    ztr_free(ztr);
}

void spec_ztr_new_length_input_null(void)
{
    char *ztr = ztr_new_length(NULL, 0);

    sp_assert(ztr == NULL);
}

void spec_ztr_new_length_input_empty(void)
{
    char *ztr = ztr_new_length("", 0);
    size_t length = ztr_length(ztr);

    sp_assert_equal_s(ztr, "");
    sp_assert_equal_i(length, 0);

    ztr_free(ztr);
}

void spec_ztr_new_length_calloc_null(void)
{
    size_t length = sizeof(struct ztr_header) + 2;
    char *ztr = ztr_new_length("", -length);

    sp_assert(ztr == NULL);
}

void spec_ztr_length(void)
{
    char *input = "Hello World!";
    char *ztr = ztr_new(input);
    size_t length = ztr_length(ztr);

    sp_assert_equal_i(length, 12);

    ztr_free(ztr);
}

void spec_ztr_length_null_input(void)
{
    char *ztr = NULL;

    size_t length = ztr_length(ztr);

    sp_assert_equal_i(length, 0);
}
