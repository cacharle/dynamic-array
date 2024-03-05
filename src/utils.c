#include <stdlib.h>

void *xmalloc(size_t size)
{
    void *p = malloc(size);
    if (p == NULL)
        abort();
    return p;
}

void *xrealloc(void *origin, size_t size)
{
    void *p = realloc(origin, size);
    if (p == NULL)
        abort();
    return p;
}
