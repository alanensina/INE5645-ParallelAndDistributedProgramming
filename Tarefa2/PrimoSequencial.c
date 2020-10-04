#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "./func.h"
#include <sys/time.h>

int main(int argc, char * argv[]) {
  verificaPrimosSequencial(atoi(argv[1]));
  return 0;
}