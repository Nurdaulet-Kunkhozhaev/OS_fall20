#include <unistd.h>

/*
 * With 3 forks finally 8 processes are created
 * With 5 forks - 32 processes
 * This is because fork causes processes to double
 */

int main() {
    int i;
    for(i = 0; i < 5; i++) {
        fork();
    }

    sleep(5);
    return 0;
}
