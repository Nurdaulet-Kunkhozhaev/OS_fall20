#include <stdio.h>
#include <unistd.h>

int main() {
    int n = 10;

    if (!fork())
        printf("Hello from child [%d - %d]\n", getpid(), n);
    else
        printf("Hello from parent [%d - %d]\n", getpid(), n);
    return 0;
}

// Output is shuffled because processes are executed in parallel