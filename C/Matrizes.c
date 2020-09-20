#include <stdio.h>
#include "./func.h"

int main(){

    int matriz[2][2];

    for (int i = 0; i < 2 ; i++){
        for(int j = 0; j < 2 ; j++){
            matriz[i][j] = i; 
        }
    }

    show(matriz);

    return 0;
}

int show(int matriz[][2]){

for (int i = 0; i < 2 ; i++){
        for(int j = 0; j < 2 ; j++){
            printf("|%d|", matriz[i][j]);
        }
        printf("\n");
    }
}