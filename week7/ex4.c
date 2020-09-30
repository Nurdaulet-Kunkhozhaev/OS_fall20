#include <stdio.h>
#include <mem.h>

void *realloc2(void *ptr, size_t size) {
    void* new_ptr = malloc(size);

    if (ptr == NULL)
        return new_ptr;

    if (!size) {
        free(ptr);
        return NULL;
    }

    memmove(new_ptr, ptr, size);
    free(ptr);
    return new_ptr;
}

#define N 1
#define M 3

int main() {
    int *a = malloc(N*sizeof(int));
    a = realloc2(a, M*sizeof(int));
    return 0;
}

