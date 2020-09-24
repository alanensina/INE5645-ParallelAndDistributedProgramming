#define TAM 10000

void populaArray(int array[]){
    for(int i = 0 ; i < TAM ; i++){
        array[i] = i;
    }
}

void verificaPrimosSequencial(int array[]){

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

void verificaPrimosParalelamente(int array[], int threads){
   
    
}