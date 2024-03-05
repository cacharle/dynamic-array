#include <stdio.h>

#define DYNARRAY_TYPE int
#include "dynarray.h"
#define DYNARRAY_TYPE float
#include "dynarray.h"

int main(void)
{
    dynarray_int *da = dynarray_new_int();
    dynarray_push_int(da, 42);
    dynarray_push_int(da, 43);
    dynarray_push_int(da, 44);
    dynarray_float *daf = dynarray_new_float();
    dynarray_push_float(daf, 42.42);
    dynarray_push_float(daf, 43.42);
    dynarray_push_float(daf, 44.42);

    for (size_t i = 0; i < da->length; i++)
        printf("%d,", da->array[i]);
    putchar('\n');
    for (size_t i = 0; i < daf->length; i++)
        printf("%f,", daf->array[i]);
    putchar('\n');

    // printf("capacity=%zu, length=%zu\n", da->capacity, da->length);
    // dynarray_push(da, 42);
    // dynarray_print(da);
    // printf("capacity=%zu, length=%zu\n", da->capacity, da->length);
    // dynarray_push(da, 1);
    // dynarray_push(da, 123);
    // dynarray_push(da, 41);
    // dynarray_push(da, 48);
    // dynarray_print(da);
    // printf("capacity=%zu, length=%zu\n", da->capacity, da->length);
    return 0;
}
