#include <stdio.h>

int main() {
    int size;
    printf("What is array size?\n");
    scanf("%d", &size);

    int *a = malloc(size*sizeof(int));
    int i = 0;
    for (; i<size; i++)
        a[i] = i;

    printf("Your array is:\n");
    for (i = 0; i<size; i++)
        printf("%d ", a[i]);
    free(a);
    return(0);
}
