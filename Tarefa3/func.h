#define N 5
#define PENSAR 0
#define FOME 1
#define COMER 2
#define ESQUERDA (nfilosofo+4)%N 
#define DIREITA (nfilosofo+1)%N

sem_t sem;
sem_t S[N];

int estado[N];
int nfilosofo[N]={0,1,2,3,4};

void *filosofo(void *num){   
   while(1){
      int *i = num;
      sleep(1);
      pegarGarfo(*i);
      sleep(1);
      liberarGarfo(*i);
   }
}

void pegarGarfo(int nfilosofo){
   sem_wait(&sem);
   estado[nfilosofo] = FOME;
   printf("Filósofo %d está com fome.\n", nfilosofo+1);
   verificar(nfilosofo);
   sem_post(&sem);
   sem_wait(&S[nfilosofo]);
   sleep(1);
}

void liberarGarfo(int nfilosofo){
   sem_wait(&sem);
   estado[nfilosofo]=PENSAR;
   printf("Filósofo %d liberou os garfos %d e %d.\n", nfilosofo+1, ESQUERDA+1, nfilosofo+1);
   printf("Filósofo %d começou a pensar.\n", nfilosofo+1);
   verificar(ESQUERDA);
   verificar(DIREITA);
   sem_post(&sem);
}

void verificar(int nfilosofo){
   if(estado[nfilosofo] == FOME && estado[ESQUERDA] != COMER && estado[DIREITA] != COMER){
      estado[nfilosofo]=COMER;
      sleep(2);
      printf("Filósofo %d pegou os garfos %d e %d.\n", nfilosofo+1, ESQUERDA+1, nfilosofo+1);
      printf("Filósofo %d começou a comer.\n", nfilosofo+1);
      sem_post(&S[nfilosofo]);
   }
}