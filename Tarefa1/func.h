int cores;
int tam;

void populaArray(int array[]) {
  for (int i = 0; i < tam; i++) {
    array[i] = i;
  }
}

void validarNumero(int num) {

  if (num == 1 || num == 2 || num == 3 || num == 5 || num == 7) {
    printf("%d\n", num);
    return;
  }

  if ((num % 2 == 0) || (num % 3 == 0) || (num % 5 == 0) || (num % 7 == 0)) {
    return;
  }

  printf("%d\n", num);
}

void verificaPrimosSequencial(int faixa) {
  tam = faixa;
  int * array;
  array = (int * ) malloc(faixa * sizeof(int));
  populaArray(array);

  printf("Números primos no intervalo de 1 a %d:\n", tam);

  for (int i = 0; i < tam; i++) {
    validarNumero(array[i]);
  }
  free(array);
}

void * processar(void * array) {
  int * arr = (int * ) array;

  for (int x = 0; x < tam; x++) { //TODO: verificar como quebrar a granularidade em cada thread
    validarNumero(arr[x]);
  }
}

void verificaPrimosParalelamente(char * argv[]) {
  tam = atoi(argv[1]);
  int * array;
  array = (int * ) malloc(tam * sizeof(int));
  populaArray(array);

  cores = atoi(argv[2]);
  pthread_t threads[cores];

  for (int i = 0; i < cores; i++) {
    pthread_create( & threads[i], NULL, processar, (void * ) array);
  }

  for (int j = 0; j < cores; j++) {
    pthread_join(threads[j], NULL);
  }
}