#include <stdio.h>

int main(){

    int x = 10;
    int y = 20;

    for(int i = 0; i < x; i++){
        printf("Y = %d\n", y);
        y++;
    }

    printf("--------------------\n");

    // Exemplo de for "eterno"
    for(;;){
        printf("X = %d\n", x);
        
        if(x >= 50){
            break;
        }

        x++; 
    }

    printf("Finalizou o programa!\n");

    return 0;
}