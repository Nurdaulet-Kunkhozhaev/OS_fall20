#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
    char input[100];

    while (1) {
        fgets(input, 100, stdin);

        if (!fork()) {
            system(input);
            return 0;
        }
    }
}