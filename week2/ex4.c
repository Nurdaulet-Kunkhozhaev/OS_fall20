#include <stdio.h>

void swap_integers(int *first_var, int *second_var) {
    int temp_var = *first_var;
    *first_var = *second_var;
    *second_var = temp_var;
}

int main() {
    int first_var, second_var;
    
    printf("Input integers: ");
    scanf("%d %d", &first_var, &second_var);

    swap_integers(&first_var, &second_var);
    printf("Result: %d %d", first_var, second_var);
    return 0;
}
