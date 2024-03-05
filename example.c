#include "dynarray.h"
#include <stdio.h>

int main(void)
{
    dynarray *da = dynarray_new();
    printf("capacity=%zu, length=%zu\n", da->capacity, da->length);
    dynarray_push(da, 42);
    dynarray_print(da);
    printf("capacity=%zu, length=%zu\n", da->capacity, da->length);
    dynarray_push(da, 1);
    dynarray_push(da, 123);
    dynarray_push(da, 41);
    dynarray_push(da, 48);
    dynarray_print(da);
    printf("capacity=%zu, length=%zu\n", da->capacity, da->length);
    return 0;
}
