#include <stdio.h>
#include <stdlib.h>
#include "./func.h"
#define TAM 10000

int main(){

    int *array;
    array = (int*) malloc(TAM * sizeof(int));
    populaArray(array);
    verificaPrimos(array);

    free(array);
    return 0;
}

void populaArray(int array[]){
    for(int i = 0 ; i < TAM ; i++){
        array[i] = i;
    }
}

void verificaPrimos(int array[]){

    printf("Números primos no intervalo de 1 a %d:\n", TAM);

    for(int i = 0; i < TAM ; i++){

        if(array[i] == 1 || array[i] == 2 || array[i] == 3 || array[i] == 5 || array[i] == 7){
            printf("%d\n", i);
            continue;
        }

        if((array[i] % 2 == 0) || (array[i] % 3 == 0) || (array[i] % 5 == 0) || (array[i] % 7 == 0)){
            continue;
        }

        printf("%d\n", i);
    }
}