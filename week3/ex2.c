#include <stdio.h>

void bubble_sort(int n, int* ptr)
{
    int i, j, temp;

    for (i = 0; i < n; i++) {

        for (j = i + 1; j < n; j++) {

            if (*(ptr + j) < *(ptr + i)) {

                temp = *(ptr + i);
                *(ptr + i) = *(ptr + j);
                *(ptr + j) = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        printf("%d ", *(ptr + i));
}

int main()
{
    int n, i;

    printf("Length of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }

    bubble_sort(n, arr);

    return 0;
}
