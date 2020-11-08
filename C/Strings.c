#include <stdio.h>
#include <string.h>

int main(){

    int i = 0;
    char *str = "Hello world!\n";

    while(str[i] != '\0'){ // Imprime cada caracter até encontrar o último elemento da string que sempre será '\0'
        printf("%c", str[i++]);
    }

    printf("\n");

    char *string = "TESTE";
    char buff[20];
    printf("Digite uma palavra:\n");
    scanf("%s", buff);

    printf("Você digitou: %s, com tamanho: %ld \n", buff, strlen(buff));

    return 0;
}