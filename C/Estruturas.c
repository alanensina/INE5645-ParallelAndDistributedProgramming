#include <stdio.h>
#include <stdlib.h>
#include "./structs.h" // Estrutura foi definida no header
#include "./func.h"

int main(){

    // Atribuição simples de struct
    reta r1;
    r1.pt1_x = 0;
    r1.pt1_y = 0;
    r1.pt2_x = 10;
    r1.pt2_y = 10;

    // Atribuição por ponteiros com alocação de memória de struct
    reta *r2 = (reta *) malloc(sizeof(reta));
    r2 -> pt1_x = 10;
    r2 -> pt1_y = 10;
    r2 -> pt2_x = 20;
    r2 -> pt2_y = 20;
    free(r2);

    plot(r1);

    return 0;
};

void plot(reta r){
    printf("A reta inicia em X: %d e Y: %d\n", r.pt1_x, r.pt1_y);
    printf("E finaliza em X: %d e Y: %d\n", r.pt2_x, r.pt2_y);
};