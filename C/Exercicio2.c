#include <stdio.h>
#include "./func.h"
#define X 10
#define Y 5

int main(){
    printf("Resultado: %d\n", mult(X,Y));
    return 0;
}

int mult(int x, int y){
    return x * y;
}