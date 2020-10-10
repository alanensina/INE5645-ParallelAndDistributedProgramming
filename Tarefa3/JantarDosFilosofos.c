#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#include "./func.h"

int main() {
  int i;
  pthread_t thread_id[N]; 

  sem_init(&sem,0,1);

  for(i=0;i<N;i++){
    sem_init(&S[i],0,0);
  }

  for(i=0;i<N;i++){
    pthread_create(&thread_id[i], NULL, filosofo, &nfilosofo[i]);
    printf("Filósofo %d esta pensando.\n",i+1);
  }

  for(i=0;i<N;i++){
    pthread_join(thread_id[i],NULL);
  }
  
  return 0;
}