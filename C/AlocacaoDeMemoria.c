#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *arr;
    int ln;
    scanf("%d", &ln); // O scanner irá pegar quantas posições colocaremos no array
    arr = (int*) malloc(ln * sizeof(int)); // Inicializa o array alocando para cada posição do array um bloco de 8 bytes que é o de um inteiro

    for(int i = 0 ; i < ln ; i++){
        arr[i] = i;
        printf("\nar[%d]: %d", i, arr[i]);
    }
    printf("\n");

    free(arr); // Libera a memória que estava alocada no arr

    return 0;
}