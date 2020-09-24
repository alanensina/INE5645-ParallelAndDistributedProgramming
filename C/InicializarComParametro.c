#include <stdio.h>

int main(int argc, char* argv[]){

    if(argc > 1){
        for(int i = 1 ; i < argc ; i++){
            printf("argv: %s\n", argv[i]);
        }
    } else{
         printf("Não houve argumentos passados na compilação");
    }

    return 0;
}