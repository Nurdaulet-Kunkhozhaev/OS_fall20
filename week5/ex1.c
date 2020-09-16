#include <pthread.h>
#include <stdio.h>

#define N 10

void * thread(void * args) {
    printf("Thread %d is executed\n", *(int*)args);
}

// This is a fixed version with threads executed in order thanks to pthread_join()
// Without it threads will be executed in non-determined order so that lines of output
// will be shuffled
int main() {
    int i;
    for (i = 1; i <= N; i++) {
        pthread_t tid;
        int thread_number = i;
        void * args = &thread_number;

        printf("Thread %d is created\n", thread_number);
        pthread_create(&tid, NULL, &thread, args);
        pthread_join(tid, NULL);
    }
}