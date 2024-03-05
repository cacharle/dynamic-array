#ifndef __DA_H__
#define __DA_H__

#include <stdlib.h>

typedef struct
{
    size_t capacity;
    size_t length;
    int   *array;
} dynarray;

dynarray *dynarray_new(void);
dynarray *dynarray_from(int *, size_t);
void      dynarray_destroy(dynarray *);
void      dynarray_resize(dynarray *, size_t);
void      dynarray_push(dynarray *, int);
int       dynarray_pop(dynarray *);
void      dynarray_print(dynarray *);

#endif
