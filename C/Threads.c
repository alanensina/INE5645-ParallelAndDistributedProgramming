#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREAD 10

void *funcao(void *arg){
    int *pvalor;

    pvalor = arg;

    printf("Thread %d iniciada. \n", *pvalor);
    printf("Thread %d executando... \n", *pvalor);
    printf("Thread %d finalizada... \n", *pvalor);
}

int main(){
    pthread_t threads[NUM_THREAD];
    int i, arg[NUM_THREAD];

    for(i = 0 ; i < NUM_THREAD ; i++){
        arg[i] = i + 1;
        pthread_create(&threads[i], NULL, funcao, (void *)&arg[i]);
    }

    for(i = 0 ; i < NUM_THREAD ; i++){
        pthread_join(threads[i], NULL);
    }

    printf("\n");

    return 0;
}