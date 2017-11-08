#include <speck.h>
#include <ztring.h>

void spec_ztr_new(void)
{
    /* arrange */
    char *input = "Hello World!";

    /* act */
    char *ztr = ztr_new(input);

    /* assert */
    sp_assert_equal_s(ztr, input);

    /* cleanup */
    ztr_free(ztr);
}

void spec_ztr_length(void)
{
    /* arrange */
    char *input = "Hello World!";
    char *ztr = ztr_new(input);

    /* act */
    size_t length = ztr_length(ztr);

    /* assert */
    sp_assert_equal_i(length, 12);

    /* cleanup */
    ztr_free(ztr);
}
