#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "./func.h"

int main(int argc, char* argv[]){

    int threads = atoi(argv[1]);

    int *array;
    array = (int*) malloc(TAM * sizeof(int));
    populaArray(array);
    verificaPrimosParalelamente(array, threads);

    free(array);
    return 0;
}