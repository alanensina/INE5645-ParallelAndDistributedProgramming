#include <stdio.h>
#include "./func.h"

int main(){

    int x = 10;
    int* ptr;
    ptr = &x; // ptr recebe o endereço de memória de x

    int y = *ptr; // y irá receber o valor apontado pelo ptr, ou seja 10.
    printf("x = %d - ptr: %p - y: %d\n", x, ptr, y);
    printf("Endereço do ponteiro de x: %p\n", &x);
    printf("Endereço do ponteiro de y: %p\n", &y);
    printf("Endereço do ponteiro de ptr: %p\n", &ptr);

    int z = 20;
    printf("Endereço do ponteiro de z: %p\n", &z);
    swap(&x, &z); // Passagem de parâmetros referenciando dois ponteiros
    printf("x = %d - z = %d\n", x, z);

    return 0;
}

void swap(int *px, int *pz){
    int tmp = *px;
    *px = *pz;
    *pz = tmp;
}