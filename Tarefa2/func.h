int cores;
int tam;
struct timeval t1, t2;


typedef struct {
  int min, max;
}
Data;

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

void printarTempoDeExecucao(){
  double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);
  printf("Tempo total = %f\n", t_total);
}

void verificaPrimosSequencial(int faixa) {

  printf("----------------------------------------------------------\n");
  printf("Números primos no intervalo de 1 a %d:\n", tam);
  printf("----------------------------------------------------------\n");

  gettimeofday(&t1, NULL);
  for (int i = 1; i <= faixa; i++) {
    validarNumero(i);
  }
  gettimeofday(&t2, NULL);

  printf("----------------------------------------------------------\n");
  printarTempoDeExecucao();
  printf("----------------------------------------------------------\n");
}

void * processar(void * data) {
  printf("----------------------------------------------------------\n");
  printf("Iniciando processamento da thread com ID: %ld\n", pthread_self());
  printf("----------------------------------------------------------\n");

  Data * my_data = (Data * ) data;

  for (int x = my_data -> min; x <= my_data -> max; x++) {
    validarNumero(x);
  }

  free(data);
}

void verificaPrimosParalelamente(char * argv[]) {
  tam = atoi(argv[1]);
  cores = atoi(argv[2]);
  pthread_t threads[cores];
  int * array;
  int intervalo = tam / cores;

  array = (int * ) malloc(tam * sizeof(int));
  populaArray(array);

  printf("----------------------------------------------------------\n");
  printf("Números primos no intervalo de 1 a %d:\n", tam);
  printf("----------------------------------------------------------\n");

  gettimeofday(&t1, NULL);
  for (int i = 0; i < cores; i++) {

    Data * dados = (Data * ) malloc(sizeof(Data));

    if (i == 0) {
      dados -> min = array[intervalo * i];
      dados -> max = array[intervalo * (i + 1)];
    }

    if (i != 0 && i < cores && i != cores - 1) {
      dados -> min = array[(i * intervalo) + 1];
      dados -> max = array[((i * intervalo) + 1) + intervalo - 1];
    }

    if (i == cores - 1) {
      dados -> min = array[(i * intervalo) + 1];
      dados -> max = array[tam - 1] + 1;
    }
    pthread_create( & threads[i], NULL, processar, (void * ) dados);
  }
  gettimeofday(&t2, NULL);

  for (int j = 0; j < cores; j++) {
    pthread_join(threads[j], NULL);
  }

  free(array);

  printf("----------------------------------------------------------\n");
  printarTempoDeExecucao();
  printf("----------------------------------------------------------\n");
}