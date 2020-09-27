int cores;
int tam;

typedef struct {
    int min;
    int max;
    int* vetor;
} Data;

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

  for (int i = 1; i < tam; i++) {
    validarNumero(array[i]);
  }
  free(array);
}

void * processar(void * data) {
  struct Data *my_data = (struct Data*) data;

  for (int x = my_data->min; x < my_data->max; x++) {
    validarNumero(my_data->vetor[x]);
  }

  free(my_data);
}

void verificaPrimosParalelamente(char * argv[]) {
  tam = atoi(argv[1]);
  cores = atoi(argv[2]);
  pthread_t threads[cores];
  int * array;
  int intervalo = tam/cores;

  array = (int * ) malloc(tam * sizeof(int));
  populaArray(array);

  printf("Números primos no intervalo de 1 a %d:\n", tam);

  for (int i = 0; i < cores; i++) {

    Data *dados = (Data *) malloc(sizeof(Data));
    dados -> vetor = array;
    dados -> min = array[intervalo * i];
    dados -> max = array[intervalo * (i + 1)];
    pthread_create( & threads[i], NULL, processar, &dados);
  }

  for (int j = 0; j < cores; j++) {
    pthread_join(threads[j], NULL);
  }
}