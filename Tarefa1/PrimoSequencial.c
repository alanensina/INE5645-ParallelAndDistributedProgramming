#include <stdio.h>
#include <stdlib.h>
#include "./func.h"

int main(){

    int *array;
    array = (int*) malloc(TAM * sizeof(int));
    populaArray(array);
    verificaPrimosSequencial(array);

    free(array);
    return 0;
}