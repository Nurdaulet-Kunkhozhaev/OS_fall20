#include <stdio.h>
#include <sys/types.h>
#include <stdbool.h>

int main() {
    int processes = 5, resources = 3;
    char input_str[] = "input_dl.txt";
    char output_str[] = "output_dl.txt";

    FILE *input  = fopen(input_str, "r");
    FILE *output = fopen(output_str, "w");

    int A[resources], E[resources], C[processes][resources], R[processes][resources];

    int i = 0;
    for (i = 0 ; i < resources; i++) {
        fscanf(input, "%d", &E[i]);
    }

    for (i = 0 ; i < resources; i++) {
        fscanf(input, "%d", &A[i]);
    }

    for (i = 0 ; i < processes; i++) {
        int j;
        for (j = 0 ; j < resources; j++) {
            fscanf(input, "%d", &C[i][j]);
        }
    }

    for (i = 0 ; i < processes; i++) {
        int j;
        for (j = 0 ; j < resources; j++) {
            fscanf(input, "%d", &R[i][j]);
        }
    }

    int n = processes;
    bool released[processes];
    for (i = 0 ; i < processes; i++) {
        released[i] = false;
    }

    while (processes) {
        bool anything_changed = false;
        for (i = 0 ; i < processes; i++) {
            if (released[i])
                continue;

            int j;
            bool can_be_released = true;
            for (j = 0 ; j < resources; j++) {
                if (A[j] < R[i][j] - C[i][j]) {
                    can_be_released = false;
                    break;
                }
            }

            if (!can_be_released)
                continue;

            anything_changed = true;
            for (j = 0 ; j < processes; j++)
                A[j] += C[i][j];
            released[i] = true;
            n--;
        }

        if (!anything_changed)
            break;
    }

    bool all_released = true;
    for (i = 0 ; i < processes; i++) {
        if (!released[i]) {
            all_released = false;
        }
    }

    if (all_released) {
        fprintf(output, "NO DEADLOCK");
    } else {
        fprintf(output, "DEADLOCK IN PROCESSES:\n");
        for (i = 0 ; i < processes; i++) {
            if (!released[i]) {
                fprintf(output, "%d\n", i + 1);
            }
        }
    }
    return 0;
}
