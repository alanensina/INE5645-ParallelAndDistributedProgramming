#define TAM 10000

int cores;

void populaArray(int array[]){
    for(int i = 0 ; i < TAM ; i++){
        array[i] = i;
    }
}

void validarNumero(int num){
   
    if(num == 1 || num == 2 || num == 3 ||num == 5 || num == 7){
            printf("%d\n", num);
            return;
        }

        if((num % 2 == 0) || (num % 3 == 0) || (num % 5 == 0) || (num % 7 == 0)){
            return;
        }

        printf("%d\n", num);
}

void verificaPrimosSequencial(int array[]){

    printf("Números primos no intervalo de 1 a %d:\n", TAM);

    for(int i = 0; i < TAM ; i++){
        validarNumero(array[i]);
    }
}

void *processar(void *array){
    int *arr = (int *) array;

    for(int x = 0 ; x < TAM ; x++){ //TODO: verificar como quebrar a granularidade em cada thread
        validarNumero(arr[x]);
    }
}

void verificaPrimosParalelamente(int array[], int processadores){
    pthread_t threads[processadores];
    cores = processadores;

    for(int i = 0 ; i < processadores ; i++){
        pthread_create(&threads[i], NULL, processar, (void *)array);
    }

    for(int j = 0 ; j < processadores ; j++){
        pthread_join(threads[j], NULL);
    }
}