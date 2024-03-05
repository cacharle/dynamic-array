#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

#ifndef DYNARRAY_TYPE
#error "DYNARRAY_TYPE not defined"
#endif

#define T DYNARRAY_TYPE

// TODO: understand why this works
#define TOKEN_CONCAT_(T1, T2) T1##T2
#define TOKEN_CONCAT(T1, T2) TOKEN_CONCAT_(T1, T2)

#define DT TOKEN_CONCAT(dynarray_, T)

typedef struct
{
    size_t capacity;
    size_t length;
    T     *array;
} DT;

#define DYNARRAY_NEW TOKEN_CONCAT(dynarray_new_, T)
DT *DYNARRAY_NEW(void)
{
    DT *da = xmalloc(sizeof(DT));
    da->capacity = 0;
    da->length = 0;
    da->array = NULL;
    return da;
}

DT *TOKEN_CONCAT(dynarray_from_, T)(T *xs, size_t length)
{
    DT *da = DYNARRAY_NEW();
    da->array = xmalloc(sizeof(int) * length);
    memcpy(da->array, xs, sizeof(int) * length);
    da->length = length;
    da->capacity = length;
    return da;
}

void TOKEN_CONCAT(dynarray_destroy_, T)(DT *da)
{
    if (da->array != NULL)
        free(da->array);
    free(da);
}

#define DYNARRAY_RESIZE TOKEN_CONCAT(dynarray_resize_, T)
void DYNARRAY_RESIZE(DT *da, size_t capacity)
{
    da->capacity = capacity;
    da->array = xrealloc(da->array, capacity);
}

#define GROWTH_FACTOR 2

#define DYNARRAY_GROW TOKEN_CONCAT(dynarray_grow_, T)
static void DYNARRAY_GROW(DT *da)
{
    if (da->capacity == 0)
        da->capacity = 1;
    DYNARRAY_RESIZE(da, da->capacity * GROWTH_FACTOR);
}

void TOKEN_CONCAT(dynarray_push_, T)(DT *da, T element)
{
    if (da->length >= da->capacity)
        DYNARRAY_GROW(da);
    da->array[da->length] = element;
    da->length++;
}

T TOKEN_CONCAT(dynarray_pop_, T)(DT *da)
{
    if (da->length == 0)
        abort();
    da->length--;
    return da->array[da->length];
}

void TOKEN_CONCAT(dynarray_print_, T)(const char *format, DT *da)
{
    for (size_t i = 0; i < da->length; i++)
    {
        printf(format, da->array[i]);
        if (i != da->length - 1)
            puts(", ");
    }
    putchar('\n');
}

#undef T
#undef DYNARRAY_TYPE
#undef DYNARRAY_NEW
#undef DYNARRAY_RESIZE
#undef DYNARRAY_GROW
