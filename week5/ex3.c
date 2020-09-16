#include <pthread.h>
#include <stdio.h>

#define MAX_SIZE 100

int cur_buff_size = 0;

void* consumer(void *arg){
    int i = 0;
    while(1) {
        while (cur_buff_size == 0);

        if(cur_buff_size > 0){
            i++;
            cur_buff_size--;
        }
    }
}

void* producer(void *arg){
    int i=0;
    while(1) {
        while(cur_buff_size == MAX_SIZE);

        if (cur_buff_size < MAX_SIZE) {
            i++;
            cur_buff_size++;
        }
    }
}

int main(){
    pthread_t tproducer, tconsumer;

    pthread_create(&tproducer,NULL,&producer,NULL);
    pthread_create(&tconsumer,NULL,&consumer,NULL);
    pthread_join(tproducer,NULL);
    return 0;
}
