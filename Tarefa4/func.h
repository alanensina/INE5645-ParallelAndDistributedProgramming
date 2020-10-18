int saldo, valorSaque, valorDeposito;
pthread_mutex_t m;
pthread_t thid1, thid2;

typedef struct {
  int operacao;
}
Operacao;

void informaSaldo() {
  printf("Seu saldo atual é de %d\n", saldo);
}

void deposita() {
  for (int i = 0; i < 100; i++) {
    sleep(1);

    pthread_mutex_lock( & m);

    printf("Realizando depósito...\n");
    saldo = saldo + valorDeposito;
    printf("Depósito realizado com sucesso!\n");
    informaSaldo();

    pthread_mutex_unlock( & m);
  }
}

void retira() {

  for (int i = 0; i < 100; i++) {

    sleep(1);

    pthread_mutex_lock( & m);

    if (saldo >= valorSaque) {
      printf("Realizando saque...\n");
      saldo = saldo - valorSaque;
      printf("Saque realizado com sucesso!\n");
      informaSaldo();
    } else {
      printf("Saldo insuficiente para saque!\n");
    }

    pthread_mutex_unlock( & m);
  }
}

void * realizaTransacao(void * operacao) {

  Operacao * op = (Operacao * ) operacao;

  if (op -> operacao == 1) {
    retira();
  } else {
    deposita();
  }

}

void inicializa(char * argv[]) {
  saldo = atoi(argv[1]);
  valorSaque = atoi(argv[2]);
  valorDeposito = atoi(argv[3]);
  pthread_mutex_init( & m, NULL);

  Operacao * op1 = (Operacao * ) malloc(sizeof(Operacao));
  Operacao * op2 = (Operacao * ) malloc(sizeof(Operacao));
  op1 -> operacao = 1;
  op2 -> operacao = 2;

  pthread_create( & thid1, NULL, realizaTransacao, (void * ) op1);
  pthread_create( & thid2, NULL, realizaTransacao, (void * ) op2);
  pthread_join(thid1, NULL);
  pthread_join(thid2, NULL);

  free(op1);
  free(op2);

  printf("Depósitos e saques finalizados com sucesso.\n");
  informaSaldo();
}