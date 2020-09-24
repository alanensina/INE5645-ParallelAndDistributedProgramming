#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "./func.h"

int main(int argc, char * argv[]) {
  verificaPrimosParalelamente(argv);
  return 0;
}