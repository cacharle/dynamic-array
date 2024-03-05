#define DYNARRAY_TYPE int
#include "dynarray.h"
#include <criterion/criterion.h>
#include <signal.h>

Test(dynarray, new)
{
    dynarray_int *da = dynarray_new_int();
    cr_assert_not_null(da);
    cr_assert_eq(da->capacity, 0);
    cr_assert_eq(da->length, 0);
    cr_assert_null(da->array);
}

Test(dynarray, from)
{
    int           xs[] = {1, 2, 3};
    dynarray_int *da = dynarray_from_int(xs, 3);
    cr_assert_not_null(da);
    cr_assert_not_null(da->array);
    cr_assert_eq(da->length, 3);
    cr_assert_geq(da->capacity, 3);
    cr_assert_eq(da->array[0], 1);
    cr_assert_eq(da->array[1], 2);
    cr_assert_eq(da->array[2], 3);
}

Test(dynarray, destroy)
{
    dynarray_int *da = dynarray_new_int();
    dynarray_destroy_int(da);
}

Test(dynarray, resize)
{
    dynarray_int *da = dynarray_new_int();
    cr_assert_eq(da->length, 0);
    cr_assert_null(da->array);
    dynarray_resize_int(da, 10);
    cr_assert_eq(da->capacity, 10);
    cr_assert_eq(da->length, 0);
    cr_assert_not_null(da->array);
}

Test(dynarray, push)
{
    dynarray_int *da = dynarray_new_int();
    cr_assert_eq(da->length, 0);
    dynarray_push_int(da, 42);
    cr_assert_eq(da->length, 1);
    cr_assert_geq(da->capacity, 1);
    cr_assert_eq(da->array[0], 42);
    dynarray_push_int(da, 43);
    cr_assert_eq(da->length, 2);
    cr_assert_geq(da->capacity, 2);
    cr_assert_eq(da->array[1], 43);
    dynarray_push_int(da, 44);
    cr_assert_eq(da->length, 3);
    cr_assert_geq(da->capacity, 3);
    cr_assert_eq(da->array[2], 44);
}

Test(dynarray, pop)
{
    dynarray_int *da = dynarray_new_int();
    dynarray_push_int(da, 42);
    dynarray_push_int(da, 43);
    dynarray_push_int(da, 44);
    int x = -1;
    cr_assert_eq(da->length, 3);
    x = dynarray_pop_int(da);
    cr_assert_eq(da->length, 2);
    cr_assert_eq(x, 44);
    x = dynarray_pop_int(da);
    cr_assert_eq(da->length, 1);
    cr_assert_eq(x, 43);
    x = dynarray_pop_int(da);
    cr_assert_eq(da->length, 0);
    cr_assert_eq(x, 42);
}

Test(dynarray, pop_crash, .signal = SIGABRT)
{
    dynarray_int *da = dynarray_new_int();
    dynarray_pop_int(da);
}
