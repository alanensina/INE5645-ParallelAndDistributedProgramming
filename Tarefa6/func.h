char texto[] = "I have been to London, seen seven wonders I know to trip is just to fall \
I used to rock it, sometimes I had roll it \
I always knew what it was for \
There can be no denying, that the wind will shake them down \
And the flat world is flying, and there is a new plague on the land \
Traversed the planet, when heaven sent me \
I saw the kings who rule them all \
Still by the firelight and purple moonlight I hear the rested rivers call \
And the wind is crying, from a love that won it grow cold \
My lover, she is lying, on the dark side of the globe \
You got me rocking when I ought to be a-rolling \
Darling, tell me, darling, which way to go \
You keep me rocking, baby, then you keep me stolen \
Do not want you tell me, darling, which way to go, that is right \
Oh how I wonder, oh how I worry, and I would dearly like to know \
I have all this wonder, of earthly plunder, will it leave us anything to show \
And our time is flying, see the candle burning low \
Is the new world rising, from the shambles of the old \
If we could just, if we could just, if we could just \
If we could just, if we could just join hands \
That is all it takes, that is all it takes \
That is all it takes, that is all it takes \0";

char palavra1[] = "London";
char palavra2[] = "that";
char palavra3[] = "when";
char palavra4[] = "is";

int palavra1_repeticoes = 0;
int palavra2_repeticoes = 0;
int palavra3_repeticoes = 0;
int palavra4_repeticoes = 0;

struct timeval t1, t2;

void incrementaRepeticao(int palavra){

  switch(palavra){
    case 1:
      palavra1_repeticoes++;
      break;

    case 2:
      palavra2_repeticoes++;
      break;

    case 3:
      palavra3_repeticoes++;
      break;

    case 4:
      palavra4_repeticoes++;
      break;

    default:
      break;
  }
}

void checaPalavra(char palavra[], int iPalavra){
  int flag = 0;
  int i = 0;
  int tamanho = strlen(palavra);

  while(texto[i] != '\0'){
   
   for(int x = 0 ; x < tamanho ; x++){
     if(texto[i] == palavra[x]){
       flag = 1;
       i++;
       continue;
     } else {
       flag = 0;
       break;
     }
   }

    if(flag == 1){
      incrementaRepeticao(iPalavra);
      flag = 0;
    }

    i++;
  }
}

void printarPalavra(char palavra[]){
  int i = 0;

  while(palavra[i] != '\0'){ 
        printf("%c", palavra[i++]);
  }
}

void printarResultado(){
  int i = 1;

  printf("Resultado final:\n");
  printf("\n");

  while(i <= 4){

    if(i == 1){
      printarPalavra(palavra1);
      printf(": %d\n", palavra1_repeticoes);
    }

    if(i == 2){
      printarPalavra(palavra2);
      printf(": %d\n", palavra2_repeticoes);
    }

    if(i == 3){
      printarPalavra(palavra3);
      printf(": %d\n", palavra3_repeticoes);
    }

    if(i == 4){
      printarPalavra(palavra4);
      printf(": %d\n", palavra4_repeticoes);
    }
    
    i++;
  }
}

void printarTempoDeExecucao(){
  double t_total = (t2.tv_sec - t1.tv_sec) + ((t2.tv_usec - t1.tv_usec)/1000000.0);
  printf("\n");
  printf("----------------------------------------------------------\n");
  printf("Tempo total de execução = %f\n", t_total);
  printf("----------------------------------------------------------\n");
}

void contarPalavrasSequencialmente(){
  
  gettimeofday(&t1, NULL);
  for(int i = 1 ; i <= 4 ; i++){
    if(i == 1){
      checaPalavra(palavra1, i);
    }
    if(i == 2){
      checaPalavra(palavra2, i);
    }
    if(i == 3){
      checaPalavra(palavra3, i);
    }
    if(i == 4){
      checaPalavra(palavra4, i);
    }
  }
  gettimeofday(&t2, NULL);

  printarResultado();
  printarTempoDeExecucao();
}

void contarPalavrasParalelamente(){
  
  gettimeofday(&t1, NULL);

  omp_set_num_threads(4);

  #pragma omp parallel for 
  for(int i = 1 ; i <= 4 ; i++){
    if(i == 1){
      checaPalavra(palavra1, i);
    }
    if(i == 2){
      checaPalavra(palavra2, i);
    }
    if(i == 3){
      checaPalavra(palavra3, i);
    }
    if(i == 4){
      checaPalavra(palavra4, i);
    }
  }
  gettimeofday(&t2, NULL);

  printarResultado();
  printarTempoDeExecucao();
}