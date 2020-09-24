#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "./func.h"

int main(int argc, char* argv[]){

    int *array;
    array = (int*) malloc(TAM * sizeof(int));
    populaArray(array);
    verificaPrimosParalelamente(array, atoi(argv[1]));

    free(array);
    return 0;
}