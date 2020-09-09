#include <stdio.h>
#include <stdlib.h>

int main(){
    char input[100] = "input";

    while (sizeof(input)/sizeof(char) != 0) {
        scanf("%s", input);
        system(input);
    }
}