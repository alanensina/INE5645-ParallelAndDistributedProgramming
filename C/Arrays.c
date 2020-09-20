#include <stdio.h>

int main(){

    int vetor[8];

    for(int x = 0 ; x < 8 ; x++){
        vetor[x] = x;
    }

    int *y = vetor; // Nesse caso apontamos para a posição zero do vetor

    for(int x = 0 ; x < 8 ; x++){
        printf("y: %d\n", y[x]);
    }

    /*
    Exemplo de Segmentation fault
    Ocorre pois estamos tentando acessar um posicinamento da memória além do que foi declarado,
    no caso de s, o ponteiro só foi declarado e não foi inicializado, 
    logo ele possui uma posição só na memória. Sendo assim quando x = 1 
    ocorrerá o erro de Segmentation fault (core dumped)
    
    int *s;
    for(int x = 0 ; x < 8 ; x++){
        s[x] = x;
    }

    */

    return 0;
}