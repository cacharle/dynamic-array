#include "dynarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void *xmalloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL)
        abort();
    return p;
}

static void *xrealloc(void *origin, size_t size)
{
    void *p = realloc(origin, size);
    if (p == NULL)
        abort();
    return p;
}

dynarray *dynarray_new(void)
{
    dynarray *da = xmalloc(sizeof(dynarray));
    da->capacity = 0;
    da->length = 0;
    da->array = NULL;
    return da;
}

dynarray *dynarray_from(int *xs, size_t length)
{
    dynarray *da = dynarray_new();
    da->array = xmalloc(sizeof(int) * length);
    memcpy(da->array, xs, sizeof(int) * length);
    da->length = length;
    da->capacity = length;
    return da;
}

void dynarray_destroy(dynarray *da)
{
    if (da->array != NULL)
        free(da->array);
    free(da);
}

void dynarray_resize(dynarray *da, size_t capacity)
{
    da->capacity = capacity;
    da->array = xrealloc(da->array, capacity);
}

static const size_t GROWTH_FACTOR = 2;

static void dynarray_grow(dynarray *da)
{
    if (da->capacity == 0)
        da->capacity = 1;
    dynarray_resize(da, da->capacity * GROWTH_FACTOR);
}

void dynarray_push(dynarray *da, int element)
{
    if (da->length >= da->capacity)
        dynarray_grow(da);
    da->array[da->length] = element;
    da->length++;
}

int dynarray_pop(dynarray *da)
{
    if (da->length == 0)
        abort();
    da->length--;
    return da->array[da->length];
}

void dynarray_print(dynarray *da)
{
    for (size_t i = 0; i < da->length; i++)
    {
        printf("%d", da->array[i]);
        if (i != da->length - 1)
            putchar(',');
    }
    putchar('\n');
}
