struct timeval t1, t2;

void validarNumero(int num) {

  if (num == 1 || num == 2 || num == 3 || num == 5 || num == 7) {
    printf("%d é um número primo!     Thread número: %d\n", num,  omp_get_thread_num());
    return;
  }

  if ((num % 2 == 0) || (num % 3 == 0) || (num % 5 == 0) || (num % 7 == 0)) {
    return;
  }

  printf("%d é um número primo!     Thread número: %d\n", num,  omp_get_thread_num());
}

void printarTempoDeExecucao(){
  double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);
  printf("Tempo total de execução = %f\n", t_total);
}

void verificaPrimos(char * argv[]) {
  
  gettimeofday(&t1, NULL);
  #pragma omp parallel for
  for(int i = 0 ; i <= atoi(argv[1]); i++){
    validarNumero(i);
  }
  gettimeofday(&t2, NULL);

  printf("----------------------------------------------------------\n");
  printarTempoDeExecucao();
  printf("----------------------------------------------------------\n");
}